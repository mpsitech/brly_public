/**
  * \file BrlyopdEngsrv.cpp
  * engine server for Brly operation daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brlyopd.h"

#include "BrlyopdEngsrv.h"

/******************************************************************************
 namespace BrlyopdEngsrv
 ******************************************************************************/

MHD_Daemon* BrlyopdEngsrv::start(
			XchgBrlyopd* xchg
		) {
	return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, xchg->stgbrlyopd.engsrvportbase + xchg->stgbrlyopd.engsrvportofs, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
};

void BrlyopdEngsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int BrlyopdEngsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int BrlyopdEngsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgBrlyopd* xchg = (XchgBrlyopd*) cls;

  MHD_Response* response;
	int retval = MHD_YES;

	ReqopBrly* req = NULL;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	uint ixBrlyVDpch;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s;

	if (*con_cls == NULL) {
		// new request
		addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

		if (addr->sa_family == AF_INET) {
#ifdef _WIN32
			ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
			inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
			ip = ipstr;
#endif
		};

		// only allow requests from engine
		if (ip == xchg->stgbrlyopd.engcliip) {
			s = string(url);

			if (strcmp(method, "POST") == 0) {
				if (s.find("/dpch") != string::npos) {
					req = new ReqopBrly(ReqopBrly::VecVState::RECEIVE);

					*con_cls = req;

					// prepare POST processor
					req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);
					retval = MHD_YES;
				};
			};
		};

		if (req == NULL) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);
		};

	} else {
		// active request
		req = (ReqopBrly*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

				retval = MHD_YES;

			} else {
				// POST done
				// cout << "MhdCallback() request complete" << endl;

				if (req->request) {
					//cout << req->request << endl;
					ixBrlyVDpch = readDpchInv(req);

					if (ixBrlyVDpch == VecBrlyVDpch::DPCHBRLYDQUIT) {
						writeDpchAck(req);
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

						// notify main thread by signalling termination condition
						Cond::signal(&(xchg->cTerm), &(xchg->mcTerm), "xchg->cTerm", "xchg->mcTerm", "BrlyopdEngsrv", "MhdCallback");

					} else {
						// expect inv dispatch, pass to opprc
						xchg->addReq(req);

						// wait for reply
						Mutex::lock(&(req->mcReady), "req->mcReady", "BrlyopdEngsrv", "MhdCallback");
						if (req->ixVState != ReqopBrly::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "BrlyopdEngsrv", "MhdCallback");
						Mutex::unlock(&(req->mcReady), "req->mcReady", "BrlyopdEngsrv", "MhdCallback");

						if (req->dpchret) {
							writeDpchRet(req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

				} else {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};
	};

	return retval;
};

int BrlyopdEngsrv::MhdPostrecv(
			void* con_cls
			, MHD_ValueKind kind
			, const char* key
			, const char* filename
			, const char* content_type
			, const char* transfer_encoding
			, const char* data
			, uint64_t off
			, size_t size
		) {
	ReqopBrly* req = (ReqopBrly*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	// copy data into req->request (append if required)
	if (strcmp(key, "xml") != 0) return MHD_NO;

	if (size > 0) {
		if (!req->request) {
			req->request = new char[size];
			memcpy(req->request, data, size);
			req->requestlen = size;

		} else {
			olddata = req->request;

			req->request = new char[req->requestlen + size];
			memcpy(req->request, olddata, req->requestlen);
			memcpy(&(req->request[req->requestlen]), data, size);
			req->requestlen = req->requestlen + size;

			delete[] olddata;
		};
	};

	return MHD_YES;
};

void BrlyopdEngsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqopBrly* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqopBrly*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

uint BrlyopdEngsrv::readDpchInv(
			ReqopBrly* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixBrlyVDpch = VecBrlyVDpch::getIx(extractRoot(doc));

	if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLY) {
		req->dpchinv = new DpchInvBrly();
		((DpchInvBrly*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLEG) {
		req->dpchinv = new DpchInvBrlyBaseLegleg();
		((DpchInvBrlyBaseLegleg*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLOC) {
		req->dpchinv = new DpchInvBrlyBaseLegloc();
		((DpchInvBrlyBaseLegloc*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELOCLOC) {
		req->dpchinv = new DpchInvBrlyBaseLocloc();
		((DpchInvBrlyBaseLocloc*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPCOLLECT) {
		req->dpchinv = new DpchInvBrlyDnsmapCollect();
		((DpchInvBrlyDnsmapCollect*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPFRAME) {
		req->dpchinv = new DpchInvBrlyDnsmapFrame();
		((DpchInvBrlyDnsmapFrame*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPVIDEO) {
		req->dpchinv = new DpchInvBrlyDnsmapVideo();
		((DpchInvBrlyDnsmapVideo*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONFLT) {
		req->dpchinv = new DpchInvBrlyDynConflt();
		((DpchInvBrlyDynConflt*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONSEG) {
		req->dpchinv = new DpchInvBrlyDynConseg();
		((DpchInvBrlyDynConseg*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNEQPLIST) {
		req->dpchinv = new DpchInvBrlyDynEqplist();
		((DpchInvBrlyDynEqplist*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTFLTLOC) {
		req->dpchinv = new DpchInvBrlyDynFltfltloc();
		((DpchInvBrlyDynFltfltloc*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTSEG) {
		req->dpchinv = new DpchInvBrlyDynFltseg();
		((DpchInvBrlyDynFltseg*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNRLY) {
		req->dpchinv = new DpchInvBrlyDynRly();
		((DpchInvBrlyDynRly*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNSEGLOCSEG) {
		req->dpchinv = new DpchInvBrlyDynSeglocseg();
		((DpchInvBrlyDynSeglocseg*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENCONMAP) {
		req->dpchinv = new DpchInvBrlyMapgenConmap();
		((DpchInvBrlyMapgenConmap*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLEGMAP) {
		req->dpchinv = new DpchInvBrlyMapgenLegmap();
		((DpchInvBrlyMapgenLegmap*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLOCMAP) {
		req->dpchinv = new DpchInvBrlyMapgenLocmap();
		((DpchInvBrlyMapgenLocmap*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYTTIMPRAWSTAR) {
		req->dpchinv = new DpchInvBrlyTtimpRawstar();
		((DpchInvBrlyTtimpRawstar*) (req->dpchinv))->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixBrlyVDpch;
};

void BrlyopdEngsrv::writeDpchAck(
			ReqopBrly* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		DpchBrlyopdAck::writeXML(wr);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

void BrlyopdEngsrv::writeDpchRet(
			ReqopBrly* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		req->dpchret->writeXML(wr);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

