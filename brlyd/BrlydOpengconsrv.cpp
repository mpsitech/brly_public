/**
  * \file BrlydOpengconsrv.cpp
  * op engine connection server for Brly daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brlyd.h"

#include "BrlydOpengconsrv.h"

/******************************************************************************
 namespace BrlydOpengconsrv
 ******************************************************************************/

MHD_Daemon* BrlydOpengconsrv::start(
			XchgBrlyd* xchg
		) {
//	return MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, xchg->stgbrlyd.opengsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_THREAD_POOL_SIZE, 16, MHD_OPTION_END);
	return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, xchg->stgbrlyd.opengsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
};

void BrlydOpengconsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int BrlydOpengconsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int BrlydOpengconsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgBrlyd* xchg = (XchgBrlyd*) cls;

  MHD_Response* response;
	int retval = MHD_YES;

	ReqopengconBrly* req = NULL;

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

		s = string(url);

		if (strcmp(method, "POST") == 0) {
			if (s.find("/dpch") != string::npos) {
				req = new ReqopengconBrly(ReqopengconBrly::VecVState::RECEIVE, ip);

				*con_cls = req;

				// prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);
				retval = MHD_YES;
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
		req = (ReqopengconBrly*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

				retval = MHD_YES;

			} else {
				// POST done
				// cout << "MhdCallback() REGULAR request complete" << endl;

				// read dispatch, pass on to job processor, and wait for reply to be transmitted
				if (req->request) {
					// cout << req->request << endl;
					ixBrlyVDpch = readDpch(xchg, req);

					// handle request and compose reply
					if (ixBrlyVDpch == VecBrlyVDpch::DPCHBRLYOPDREG) {
						// add NodeBrly
						NodeBrly* node = xchg->addNode(req->ip, ((DpchBrlyopdReg*) (req->dpchopd))->port, ((DpchBrlyopdReg*) (req->dpchopd))->opprcn, ((DpchBrlyopdReg*) (req->dpchopd))->ixBrlyVOpengtype);

						// log
						xchg->appendToLogfile("operation engine at [" + req->ip + "]:" + to_string(((DpchBrlyopdReg*) (req->dpchopd))->port) + " added");

						writeDpchReg(xchg, req, node->nref);

					} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHBRLYOPDUNREG) {
						// remove NodeBrlyd
						xchg->removeNodeByNref(((DpchBrlyopdUnreg*) (req->dpchopd))->nref);

						writeDpchAck(req);
					};
					
					if (req->reply) {
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					} else {
						response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
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

int BrlydOpengconsrv::MhdPostrecv(
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
	ReqopengconBrly* req = (ReqopengconBrly*) con_cls;

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

void BrlydOpengconsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqopengconBrly* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqopengconBrly*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

uint BrlydOpengconsrv::readDpch(
			XchgBrlyd* xchg
			, ReqopengconBrly* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixBrlyVDpch = VecBrlyVDpch::getIx(extractRoot(doc));

	if (ixBrlyVDpch == VecBrlyVDpch::DPCHBRLYOPDREG) {
		req->dpchopd = new DpchBrlyopdReg();
		((DpchBrlyopdReg*) (req->dpchopd))->readXML(docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHBRLYOPDUNREG) {
		req->dpchopd = new DpchBrlyopdUnreg();
		((DpchBrlyopdUnreg*) (req->dpchopd))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixBrlyVDpch;
};

void BrlydOpengconsrv::writeDpchAck(
			ReqopengconBrly* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		DpchBrlydAck::writeXML(wr);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

void BrlydOpengconsrv::writeDpchReg(
			XchgBrlyd* xchg
			, ReqopengconBrly* req
			, const ubigint nref
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		DpchBrlydReg::writeXML(&(xchg->mScr), xchg->scr, xchg->descr, wr, nref);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

