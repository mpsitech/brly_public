/**
  * \file BrlydAppsrv.cpp
  * application server for Brly daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brlyd.h"

#include "BrlydAppsrv.h"

/******************************************************************************
 namespace BrlydAppsrv
 ******************************************************************************/

MHD_Daemon* BrlydAppsrv::start(
			XchgBrlyd* xchg
		) {
//	return MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, xchg->stgbrlyd.appsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_THREAD_POOL_SIZE, 16, MHD_OPTION_END);
	return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, xchg->stgbrlyd.appsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
};

void BrlydAppsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int BrlydAppsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int BrlydAppsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgBrly* xchg = (XchgBrly*) cls;

  MHD_Response* response;
	int retval = MHD_YES;

	ReqBrly* req;
	uint ixVBasetype = ReqBrly::VecVBasetype::NONE;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string mimetype;
	size_t ptr;

	uint ixBrlyVDpch;

	ubigint jrefNotify;

	DcolBrly* dcol;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s, s2;

	bool valid;

	if (*con_cls == NULL) {
		// new request
		s = string(url);

		if (strcmp(method, "GET") == 0) {
			// cout << "have GET request, url is '" << s << "'" << endl;

			if (s.find("/web/") != string::npos) {
				// cout << "request for '" << s.substr(4) << "' by html transfer" << endl;

				// ex. "/web/CrdBrlyNav/CrdBrlyNav.html" ; note that eventual parameters such as "?scrJref=abcd1234efgh5678" are not included in url

				// inhibit requests to ../ directories
				if (s.find("../") == string::npos) {

					// check if file exists
					s2 = xchg->stgbrlypath.webpath + s.substr(4);
					if (access(s2.c_str(), R_OK) == 0) {
						ixVBasetype = ReqBrly::VecVBasetype::WEB;
						// cout << "MhdCallback() WEB request for '" << s2 << "'" << endl;
					};
				};

			} else if (s.find("/notify") != string::npos) {
				// always "/notify/abcd1234efgh5678/..."
				ixVBasetype = ReqBrly::VecVBasetype::NOTIFY;

			} else if (s.find("/poll") != string::npos) {
				// always "/poll/abcd1234efgh5678/..."
				ixVBasetype = ReqBrly::VecVBasetype::POLL;

			} else if (s.find("/download/") != string::npos) {
				// ex. "/download/abcd1234efgh5678/..."
				ixVBasetype = ReqBrly::VecVBasetype::DOWNLOAD;
			};

		} else if (strcmp(method, "POST") == 0) {
			if (s.find("/dpch") != string::npos) {
				// always "/dpch"
				ixVBasetype = ReqBrly::VecVBasetype::REGULAR;

			} else if (s.find("/upload/") != string::npos) {
				// ex. "/upload/abcd1234efgh5678"
				ixVBasetype = ReqBrly::VecVBasetype::UPLOAD;
			};
		};

		if (ixVBasetype == ReqBrly::VecVBasetype::NONE) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
			//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else {
			addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

			if (addr->sa_family == AF_INET) {
#ifdef _WIN32
				ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
				inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
				ip = ipstr;
#endif
			};

			req = new ReqBrly(ixVBasetype, ReqBrly::VecVState::RECEIVE, ip);

			*con_cls = req;

			if (req->ixVBasetype == ReqBrly::VecVBasetype::WEB) {
				// --- open file and initiate transmission
				req->filename = xchg->stgbrlypath.webpath + s.substr(4);

				req->file = new fstream();
				req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

				// get file length
				req->file->seekg(0, ios::end);
				req->filelen = req->file->tellg();
				req->file->seekg(0, ios::beg);

				if (req->filelen == 0) {
					// empty files require special handling
					response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);

				} else {
					response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);

					// determine MIME type from file extension
					ptr = req->filename.rfind('.');
					if (ptr != string::npos) mimetype = VecBrlyVMimetype::getTitle(VecBrlyVMimetype::getIx(req->filename.substr(ptr+1)));
					if (mimetype.length() == 0) mimetype = VecBrlyVMimetype::getTitle(VecBrlyVMimetype::TXT);
					MHD_add_response_header(response, "Content-Type", mimetype.c_str());					

					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
				// --- prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::NOTIFY) {
				// --- notify on dispatch in dispatch collector
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/notify/")+8));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					jrefNotify = xchg->getRefPreset(VecBrlyVPreset::PREBRLYJREFNOTIFY, req->jref);

					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) {
						dcol = xchg->addDcol(req->jref);
						if (dcol) jrefNotify = req->jref;
					};

					valid = dcol;
				};

				if (valid) {
					req->ixBrlyVLocale = dcol->ixBrlyVLocale;

					if (dcol->dpchs.empty()) {
						if (dcol->hot) {
							// send default reply immediately
							req->dpcheng = new DpchEngBrlyAck(req->jref);

							dcol->hot = false;
							dcol->unlockAccess("BrlydAppsrv", "MhdCallback[1]");

						} else if (jrefNotify != dcol->jref) {
							// ask client to resort to POLL mode
							req->dpcheng = new DpchEngBrlySuspend(req->jref);

							dcol->unlockAccess("BrlydAppsrv", "MhdCallback[2]");

						} else {
							// wait for next notification to arrive in dispatch collector
							
							// default req->dpcheng to be overwritten
							req->dpcheng = new DpchEngBrlyAck(req->jref);
							dcol->req = req;

							// note: when dcol with req != NULL is deleted, req->cReady will be broadcast
							Mutex::lock(&(req->mcReady), "req->mcReady", "BrlydAppsrv", "MhdCallback[1]");
							dcol->unlockAccess("BrlydAppsrv", "MhdCallback[3]");
							Cond::timedwait(&(req->cReady), &(req->mcReady), 15000000, "req->cReady", "BrlydAppsrv", "MhdCallback");
							// cout << "got one after timedwait" << endl;
							Mutex::unlock(&(req->mcReady), "req->mcReady", "BrlydAppsrv", "MhdCallback[1]");

							dcol = xchg->getDcolByJref(req->jref);
							if (dcol) {
								// note: the destructor of dcol is called after dcol is removed from the list from which it can be found by getDcolByJref()
								dcol->req = NULL;
								dcol->unlockAccess("BrlydAppsrv", "MhdCallback[4]");

							} else {
								delete req->dpcheng;
								req->dpcheng = new DpchEngBrlyConfirm(false, req->jref);
							};
						};

						writeDpchEng(xchg, req);
						req->ixVState = ReqBrly::VecVState::REPLY;

						// send reply ; note that the result of Cond::timedwait() doesn't matter
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;

						dcol->hot = true;
						dcol->unlockAccess("BrlydAppsrv", "MhdCallback[5]");

						writeDpchEng(xchg, req);
						req->ixVState = ReqBrly::VecVState::REPLY;

						// send first dispatch available in dispatch collector
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::POLL) {
				// --- send first dispatch available in dispatch collector
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/poll/")+6));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixBrlyVLocale = dcol->ixBrlyVLocale;
					dcol->hot = false;

					if (dcol->dpchs.empty()) {
						// send default reply
						req->dpcheng = new DpchEngBrlyAck(req->jref);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;
					};

					dcol->unlockAccess("BrlydAppsrv", "MhdCallback[6]");

					writeDpchEng(xchg, req);
					req->ixVState = ReqBrly::VecVState::REPLY;

					// send reply
					response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::UPLOAD) {
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/upload/")+8));

				// generate file in tmp directory, and open it
				req->filename = xchg->stgbrlypath.tmppath + "/" + Tmp::newfile(xchg->stgbrlypath.tmppath, "");

				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DOWNLOAD) {
				// --- pass request to jobprc, to ask for filename in tmp directory ; then proceed sending - same procedure as for HTML
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/download/")+10));
				valid = validateIp(xchg, req);

				if (valid) {
					validateJrefNotify(xchg, req);

					xchg->addReq(req);

					// wait for reply
					Mutex::lock(&(req->mcReady), "req->mcReady", "BrlydAppsrv", "MhdCallback[2]");
					Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "BrlydAppsrv", "MhdCallback[1]");
					Mutex::unlock(&(req->mcReady), "req->mcReady", "BrlydAppsrv", "MhdCallback[2]");

					// cout << "preparing '" << req->filename << "' for download transfer" << endl;

					valid = (access(req->filename.c_str(), R_OK) == 0);
				};

				if (valid) {
					req->file = new fstream();
					req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

					// get file length
					req->file->seekg(0, ios::end);
					req->filelen = req->file->tellg();
					req->file->seekg(0, ios::beg);

					if (req->filelen == 0) {
						// empty files require special handling
						response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active/old request (GET: should not go through here ; POST: REGULAR, UPLOAD)
		req = (ReqBrly*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

			} else {
				// POST done
				if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
					// --- read dispatch, pass on to job processor, and wait for reply to be transmitted
					// cout << "MhdCallback() REGULAR request complete" << endl;
					valid = req->request;
					
					if (valid) {
						//cout << req->request << endl;
						ixBrlyVDpch = readDpchApp(xchg, req);
						valid = req->dpchapp;
					};

					if (valid) {
						req->jref = req->dpchapp->jref;
						valid = validateIp(xchg, req);

						if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPROOTBRLYLOGIN) req->jref = xchg->jrefRoot;
					};

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply
						Mutex::lock(&(req->mcReady), "req->mcReady", "BrlydAppsrv", "MhdCallback[3]");
						if (req->ixVState != ReqBrly::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "BrlydAppsrv", "MhdCallback[2]");
						Mutex::unlock(&(req->mcReady), "req->mcReady", "BrlydAppsrv", "MhdCallback[3]");

						if (req->dpcheng) {
							writeDpchEng(xchg, req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};
					
					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};

				} else if (req->ixVBasetype == ReqBrly::VecVBasetype::UPLOAD) {
					// --- pass notification concerning uploaded file to job processor, and wait for acknowledgement
					valid = validateIp(xchg, req);

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply (usually empty)
						Mutex::lock(&(req->mcReady), "req->mcReady", "BrlydAppsrv", "MhdCallback[4]");
						Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "BrlydAppsrv", "MhdCallback[3]");
						Mutex::unlock(&(req->mcReady), "req->mcReady", "BrlydAppsrv", "MhdCallback[4]");

						if (req->reply) {
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};
				};
			};
		};
	};

	return retval;
};

#ifdef _WIN32
int BrlydAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, int max
		) {
#else
ssize_t BrlydAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, size_t max
		) {
#endif
	ReqBrly* req = (ReqBrly*) con_cls;

	int64_t spos = pos;
	int64_t len;

	if (req) {
		// determine length remaining
		req->file->seekg(0, ios::end);
		len = req->file->tellg();
		if (len != -1) {

			if (len > spos) {
				req->file->seekg(spos);
				req->file->read(buf, max);

				// check for errors
				if (req->file->bad()) return 0;

				if (len < (max+spos))
					return (len-spos);
				else
					return max;
			};
		};
	};

	return 0;
};

int BrlydAppsrv::MhdPostrecv(
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
	ReqBrly* req = (ReqBrly*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
		// --- copy data into req->request (append if required)
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

	} else if (req->ixVBasetype == ReqBrly::VecVBasetype::UPLOAD) {
		// --- write data into file
		if (strcmp(key, "file") != 0) return MHD_NO;

		if (size > 0) {
			req->file = new fstream();

			req->file->open(req->filename.c_str(), fstream::app | fstream::out | fstream::binary);
			req->file->write(data, size);
			req->file->close();

			delete(req->file);
			req->file = NULL;
		};

	} else {
		return MHD_NO;
	};

	return MHD_YES;
};

void BrlydAppsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqBrly* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqBrly*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

bool BrlydAppsrv::validateIp(
			XchgBrlyd* xchg
			, ReqBrly* req
		) {
	bool retval = true;

	string ip;

	if (req->jref != 0) {
		ip = xchg->getTxtvalPreset(VecBrlyVPreset::PREBRLYIP, req->jref);
		if (ip != req->ip) retval = false;
	};

	return retval;
};

bool BrlydAppsrv::validateJrefNotify(
			XchgBrlyd* xchg
			, ReqBrly* req
		) {
	bool retval = false;

	ubigint jrefNotify;

	DcolBrly* dcol = NULL;

	jrefNotify = xchg->getRefPreset(VecBrlyVPreset::PREBRLYJREFNOTIFY, req->jref);

	dcol = xchg->getDcolByJref(req->jref);

	if (dcol) {
		retval = (jrefNotify == dcol->jref);
		if (!retval) xchg->triggerIxRefCall(NULL, VecBrlyVCall::CALLBRLYREFPRESET, dcol->jref, VecBrlyVPreset::PREBRLYJREFNOTIFY, dcol->jref);

		dcol->unlockAccess("BrlydAppsrv", "validateJrefNotify");
	};

	return retval;
};

uint BrlydAppsrv::readDpchApp(
			XchgBrlyd* xchg
			, ReqBrly* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixBrlyVDpch = VecBrlyVDpch::getIx(extractRoot(doc));

	if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYALERT) {
		req->dpchapp = new DpchAppBrlyAlert();
		((DpchAppBrlyAlert*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCON1NRELAYDATA) {
		req->dpchapp = new PnlBrlyCon1NRelay::DpchAppData();
		((PnlBrlyCon1NRelay::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCON1NRELAYDO) {
		req->dpchapp = new PnlBrlyCon1NRelay::DpchAppDo();
		((PnlBrlyCon1NRelay::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONCONMNEQUIPMENTDATA) {
		req->dpchapp = new PnlBrlyConConMNEquipment::DpchAppData();
		((PnlBrlyConConMNEquipment::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONCONMNEQUIPMENTDO) {
		req->dpchapp = new PnlBrlyConConMNEquipment::DpchAppDo();
		((PnlBrlyConConMNEquipment::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONDETAILDATA) {
		req->dpchapp = new PnlBrlyConDetail::DpchAppData();
		((PnlBrlyConDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONDETAILDO) {
		req->dpchapp = new PnlBrlyConDetail::DpchAppDo();
		((PnlBrlyConDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONDO) {
		req->dpchapp = new CrdBrlyCon::DpchAppDo();
		((CrdBrlyCon::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONLISTDATA) {
		req->dpchapp = new PnlBrlyConList::DpchAppData();
		((PnlBrlyConList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONLISTDO) {
		req->dpchapp = new PnlBrlyConList::DpchAppDo();
		((PnlBrlyConList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONMAPDATA) {
		req->dpchapp = new PnlBrlyConMap::DpchAppData();
		((PnlBrlyConMap::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONMAPDO) {
		req->dpchapp = new PnlBrlyConMap::DpchAppDo();
		((PnlBrlyConMap::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONMNFLIGHTDATA) {
		req->dpchapp = new PnlBrlyConMNFlight::DpchAppData();
		((PnlBrlyConMNFlight::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONMNFLIGHTDO) {
		req->dpchapp = new PnlBrlyConMNFlight::DpchAppDo();
		((PnlBrlyConMNFlight::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONMNSEGMENTDATA) {
		req->dpchapp = new PnlBrlyConMNSegment::DpchAppData();
		((PnlBrlyConMNSegment::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONMNSEGMENTDO) {
		req->dpchapp = new PnlBrlyConMNSegment::DpchAppDo();
		((PnlBrlyConMNSegment::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONPREDATA) {
		req->dpchapp = new PnlBrlyConPre::DpchAppData();
		((PnlBrlyConPre::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONRECDO) {
		req->dpchapp = new PnlBrlyConRec::DpchAppDo();
		((PnlBrlyConRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONREF1NSEGMENTDATA) {
		req->dpchapp = new PnlBrlyConRef1NSegment::DpchAppData();
		((PnlBrlyConRef1NSegment::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYCONREF1NSEGMENTDO) {
		req->dpchapp = new PnlBrlyConRef1NSegment::DpchAppDo();
		((PnlBrlyConRef1NSegment::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFILDETAILDATA) {
		req->dpchapp = new PnlBrlyFilDetail::DpchAppData();
		((PnlBrlyFilDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFILDETAILDO) {
		req->dpchapp = new PnlBrlyFilDetail::DpchAppDo();
		((PnlBrlyFilDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFILDO) {
		req->dpchapp = new CrdBrlyFil::DpchAppDo();
		((CrdBrlyFil::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFILLISTDATA) {
		req->dpchapp = new PnlBrlyFilList::DpchAppData();
		((PnlBrlyFilList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFILLISTDO) {
		req->dpchapp = new PnlBrlyFilList::DpchAppDo();
		((PnlBrlyFilList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFILRECDO) {
		req->dpchapp = new PnlBrlyFilRec::DpchAppDo();
		((PnlBrlyFilRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLT1NCONNECTIONDATA) {
		req->dpchapp = new PnlBrlyFlt1NConnection::DpchAppData();
		((PnlBrlyFlt1NConnection::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLT1NCONNECTIONDO) {
		req->dpchapp = new PnlBrlyFlt1NConnection::DpchAppDo();
		((PnlBrlyFlt1NConnection::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTDETAILDATA) {
		req->dpchapp = new PnlBrlyFltDetail::DpchAppData();
		((PnlBrlyFltDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTDETAILDO) {
		req->dpchapp = new PnlBrlyFltDetail::DpchAppDo();
		((PnlBrlyFltDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTDO) {
		req->dpchapp = new CrdBrlyFlt::DpchAppDo();
		((CrdBrlyFlt::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTEQP1NNODEDATA) {
		req->dpchapp = new PnlBrlyFltEqp1NNode::DpchAppData();
		((PnlBrlyFltEqp1NNode::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTEQP1NNODEDO) {
		req->dpchapp = new PnlBrlyFltEqp1NNode::DpchAppDo();
		((PnlBrlyFltEqp1NNode::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTEQPMNCONNECTIONDATA) {
		req->dpchapp = new PnlBrlyFltEqpMNConnection::DpchAppData();
		((PnlBrlyFltEqpMNConnection::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTEQPMNCONNECTIONDO) {
		req->dpchapp = new PnlBrlyFltEqpMNConnection::DpchAppDo();
		((PnlBrlyFltEqpMNConnection::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTFAFAWAYPOINTDATA) {
		req->dpchapp = new PnlBrlyFltFafAWaypoint::DpchAppData();
		((PnlBrlyFltFafAWaypoint::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTFAFAWAYPOINTDO) {
		req->dpchapp = new PnlBrlyFltFafAWaypoint::DpchAppDo();
		((PnlBrlyFltFafAWaypoint::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTLISTDATA) {
		req->dpchapp = new PnlBrlyFltList::DpchAppData();
		((PnlBrlyFltList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTLISTDO) {
		req->dpchapp = new PnlBrlyFltList::DpchAppDo();
		((PnlBrlyFltList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTMNCONNECTIONDATA) {
		req->dpchapp = new PnlBrlyFltMNConnection::DpchAppData();
		((PnlBrlyFltMNConnection::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTMNCONNECTIONDO) {
		req->dpchapp = new PnlBrlyFltMNConnection::DpchAppDo();
		((PnlBrlyFltMNConnection::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTMNLOCATIONDATA) {
		req->dpchapp = new PnlBrlyFltMNLocation::DpchAppData();
		((PnlBrlyFltMNLocation::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTMNLOCATIONDO) {
		req->dpchapp = new PnlBrlyFltMNLocation::DpchAppDo();
		((PnlBrlyFltMNLocation::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTORGMNFLIGHTDATA) {
		req->dpchapp = new PnlBrlyFltOrgMNFlight::DpchAppData();
		((PnlBrlyFltOrgMNFlight::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTORGMNFLIGHTDO) {
		req->dpchapp = new PnlBrlyFltOrgMNFlight::DpchAppDo();
		((PnlBrlyFltOrgMNFlight::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTPREDATA) {
		req->dpchapp = new PnlBrlyFltPre::DpchAppData();
		((PnlBrlyFltPre::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTRECDO) {
		req->dpchapp = new PnlBrlyFltRec::DpchAppDo();
		((PnlBrlyFltRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTREF1NSEGMENTDATA) {
		req->dpchapp = new PnlBrlyFltRef1NSegment::DpchAppData();
		((PnlBrlyFltRef1NSegment::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYFLTREF1NSEGMENTDO) {
		req->dpchapp = new PnlBrlyFltRef1NSegment::DpchAppDo();
		((PnlBrlyFltRef1NSegment::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYINIT) {
		req->dpchapp = new DpchAppBrlyInit();
		((DpchAppBrlyInit*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEG1NFLIGHTDATA) {
		req->dpchapp = new PnlBrlyLeg1NFlight::DpchAppData();
		((PnlBrlyLeg1NFlight::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEG1NFLIGHTDO) {
		req->dpchapp = new PnlBrlyLeg1NFlight::DpchAppDo();
		((PnlBrlyLeg1NFlight::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGCOR1NCONNECTIONDATA) {
		req->dpchapp = new PnlBrlyLegCor1NConnection::DpchAppData();
		((PnlBrlyLegCor1NConnection::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGCOR1NCONNECTIONDO) {
		req->dpchapp = new PnlBrlyLegCor1NConnection::DpchAppDo();
		((PnlBrlyLegCor1NConnection::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGDETAILDATA) {
		req->dpchapp = new PnlBrlyLegDetail::DpchAppData();
		((PnlBrlyLegDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGDETAILDO) {
		req->dpchapp = new PnlBrlyLegDetail::DpchAppDo();
		((PnlBrlyLegDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGDO) {
		req->dpchapp = new CrdBrlyLeg::DpchAppDo();
		((CrdBrlyLeg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGLISTDATA) {
		req->dpchapp = new PnlBrlyLegList::DpchAppData();
		((PnlBrlyLegList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGLISTDO) {
		req->dpchapp = new PnlBrlyLegList::DpchAppDo();
		((PnlBrlyLegList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGMAPDATA) {
		req->dpchapp = new PnlBrlyLegMap::DpchAppData();
		((PnlBrlyLegMap::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGMAPDO) {
		req->dpchapp = new PnlBrlyLegMap::DpchAppDo();
		((PnlBrlyLegMap::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGMNLOCATIONDATA) {
		req->dpchapp = new PnlBrlyLegMNLocation::DpchAppData();
		((PnlBrlyLegMNLocation::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGMNLOCATIONDO) {
		req->dpchapp = new PnlBrlyLegMNLocation::DpchAppDo();
		((PnlBrlyLegMNLocation::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGORGMNLEGDATA) {
		req->dpchapp = new PnlBrlyLegOrgMNLeg::DpchAppData();
		((PnlBrlyLegOrgMNLeg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGORGMNLEGDO) {
		req->dpchapp = new PnlBrlyLegOrgMNLeg::DpchAppDo();
		((PnlBrlyLegOrgMNLeg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGPREDATA) {
		req->dpchapp = new PnlBrlyLegPre::DpchAppData();
		((PnlBrlyLegPre::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLEGRECDO) {
		req->dpchapp = new PnlBrlyLegRec::DpchAppDo();
		((PnlBrlyLegRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCBGN1NLEGDATA) {
		req->dpchapp = new PnlBrlyLocBgn1NLeg::DpchAppData();
		((PnlBrlyLocBgn1NLeg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCBGN1NLEGDO) {
		req->dpchapp = new PnlBrlyLocBgn1NLeg::DpchAppDo();
		((PnlBrlyLocBgn1NLeg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCDETAILDATA) {
		req->dpchapp = new PnlBrlyLocDetail::DpchAppData();
		((PnlBrlyLocDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCDETAILDO) {
		req->dpchapp = new PnlBrlyLocDetail::DpchAppDo();
		((PnlBrlyLocDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCDO) {
		req->dpchapp = new CrdBrlyLoc::DpchAppDo();
		((CrdBrlyLoc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCEND1NLEGDATA) {
		req->dpchapp = new PnlBrlyLocEnd1NLeg::DpchAppData();
		((PnlBrlyLocEnd1NLeg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCEND1NLEGDO) {
		req->dpchapp = new PnlBrlyLocEnd1NLeg::DpchAppDo();
		((PnlBrlyLocEnd1NLeg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCEQP1NNODEDATA) {
		req->dpchapp = new PnlBrlyLocEqp1NNode::DpchAppData();
		((PnlBrlyLocEqp1NNode::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCEQP1NNODEDO) {
		req->dpchapp = new PnlBrlyLocEqp1NNode::DpchAppDo();
		((PnlBrlyLocEqp1NNode::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCEQPMNCONNECTIONDATA) {
		req->dpchapp = new PnlBrlyLocEqpMNConnection::DpchAppData();
		((PnlBrlyLocEqpMNConnection::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCEQPMNCONNECTIONDO) {
		req->dpchapp = new PnlBrlyLocEqpMNConnection::DpchAppDo();
		((PnlBrlyLocEqpMNConnection::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCLISTDATA) {
		req->dpchapp = new PnlBrlyLocList::DpchAppData();
		((PnlBrlyLocList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCLISTDO) {
		req->dpchapp = new PnlBrlyLocList::DpchAppDo();
		((PnlBrlyLocList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCMAPDATA) {
		req->dpchapp = new PnlBrlyLocMap::DpchAppData();
		((PnlBrlyLocMap::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCMAPDO) {
		req->dpchapp = new PnlBrlyLocMap::DpchAppDo();
		((PnlBrlyLocMap::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCMNFLIGHTDATA) {
		req->dpchapp = new PnlBrlyLocMNFlight::DpchAppData();
		((PnlBrlyLocMNFlight::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCMNFLIGHTDO) {
		req->dpchapp = new PnlBrlyLocMNFlight::DpchAppDo();
		((PnlBrlyLocMNFlight::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCMNLEGDATA) {
		req->dpchapp = new PnlBrlyLocMNLeg::DpchAppData();
		((PnlBrlyLocMNLeg::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCMNLEGDO) {
		req->dpchapp = new PnlBrlyLocMNLeg::DpchAppDo();
		((PnlBrlyLocMNLeg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCMNSEGMENTDATA) {
		req->dpchapp = new PnlBrlyLocMNSegment::DpchAppData();
		((PnlBrlyLocMNSegment::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCMNSEGMENTDO) {
		req->dpchapp = new PnlBrlyLocMNSegment::DpchAppDo();
		((PnlBrlyLocMNSegment::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCPROXORGMNLOCATIONDATA) {
		req->dpchapp = new PnlBrlyLocProxOrgMNLocation::DpchAppData();
		((PnlBrlyLocProxOrgMNLocation::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCPROXORGMNLOCATIONDO) {
		req->dpchapp = new PnlBrlyLocProxOrgMNLocation::DpchAppDo();
		((PnlBrlyLocProxOrgMNLocation::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCRECDO) {
		req->dpchapp = new PnlBrlyLocRec::DpchAppDo();
		((PnlBrlyLocRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCVISORGMNLOCATIONDATA) {
		req->dpchapp = new PnlBrlyLocVisOrgMNLocation::DpchAppData();
		((PnlBrlyLocVisOrgMNLocation::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYLOCVISORGMNLOCATIONDO) {
		req->dpchapp = new PnlBrlyLocVisOrgMNLocation::DpchAppDo();
		((PnlBrlyLocVisOrgMNLocation::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVADMINDATA) {
		req->dpchapp = new PnlBrlyNavAdmin::DpchAppData();
		((PnlBrlyNavAdmin::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVADMINDO) {
		req->dpchapp = new PnlBrlyNavAdmin::DpchAppDo();
		((PnlBrlyNavAdmin::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVBASEDATA) {
		req->dpchapp = new PnlBrlyNavBase::DpchAppData();
		((PnlBrlyNavBase::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVBASEDO) {
		req->dpchapp = new PnlBrlyNavBase::DpchAppDo();
		((PnlBrlyNavBase::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVCONNECTDATA) {
		req->dpchapp = new PnlBrlyNavConnect::DpchAppData();
		((PnlBrlyNavConnect::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVCONNECTDO) {
		req->dpchapp = new PnlBrlyNavConnect::DpchAppDo();
		((PnlBrlyNavConnect::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYNAVDO) {
		req->dpchapp = new CrdBrlyNav::DpchAppDo();
		((CrdBrlyNav::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYOPR1NEQUIPMENTDATA) {
		req->dpchapp = new PnlBrlyOpr1NEquipment::DpchAppData();
		((PnlBrlyOpr1NEquipment::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYOPR1NEQUIPMENTDO) {
		req->dpchapp = new PnlBrlyOpr1NEquipment::DpchAppDo();
		((PnlBrlyOpr1NEquipment::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYOPRDETAILDATA) {
		req->dpchapp = new PnlBrlyOprDetail::DpchAppData();
		((PnlBrlyOprDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYOPRDETAILDO) {
		req->dpchapp = new PnlBrlyOprDetail::DpchAppDo();
		((PnlBrlyOprDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYOPRDO) {
		req->dpchapp = new CrdBrlyOpr::DpchAppDo();
		((CrdBrlyOpr::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYOPRLISTDATA) {
		req->dpchapp = new PnlBrlyOprList::DpchAppData();
		((PnlBrlyOprList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYOPRLISTDO) {
		req->dpchapp = new PnlBrlyOprList::DpchAppDo();
		((PnlBrlyOprList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYOPRRECDO) {
		req->dpchapp = new PnlBrlyOprRec::DpchAppDo();
		((PnlBrlyOprRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSADETAILDATA) {
		req->dpchapp = new PnlBrlyPrsADetail::DpchAppData();
		((PnlBrlyPrsADetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSADETAILDO) {
		req->dpchapp = new PnlBrlyPrsADetail::DpchAppDo();
		((PnlBrlyPrsADetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSDETAILDATA) {
		req->dpchapp = new PnlBrlyPrsDetail::DpchAppData();
		((PnlBrlyPrsDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSDETAILDO) {
		req->dpchapp = new PnlBrlyPrsDetail::DpchAppDo();
		((PnlBrlyPrsDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSDO) {
		req->dpchapp = new CrdBrlyPrs::DpchAppDo();
		((CrdBrlyPrs::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSLISTDATA) {
		req->dpchapp = new PnlBrlyPrsList::DpchAppData();
		((PnlBrlyPrsList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSLISTDO) {
		req->dpchapp = new PnlBrlyPrsList::DpchAppDo();
		((PnlBrlyPrsList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPRSRECDO) {
		req->dpchapp = new PnlBrlyPrsRec::DpchAppDo();
		((PnlBrlyPrsRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTY1NEQUIPMENTDATA) {
		req->dpchapp = new PnlBrlyPty1NEquipment::DpchAppData();
		((PnlBrlyPty1NEquipment::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTY1NEQUIPMENTDO) {
		req->dpchapp = new PnlBrlyPty1NEquipment::DpchAppDo();
		((PnlBrlyPty1NEquipment::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTYDETAILDATA) {
		req->dpchapp = new PnlBrlyPtyDetail::DpchAppData();
		((PnlBrlyPtyDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTYDETAILDO) {
		req->dpchapp = new PnlBrlyPtyDetail::DpchAppDo();
		((PnlBrlyPtyDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTYDO) {
		req->dpchapp = new CrdBrlyPty::DpchAppDo();
		((CrdBrlyPty::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTYLISTDATA) {
		req->dpchapp = new PnlBrlyPtyList::DpchAppData();
		((PnlBrlyPtyList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTYLISTDO) {
		req->dpchapp = new PnlBrlyPtyList::DpchAppDo();
		((PnlBrlyPtyList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYPTYRECDO) {
		req->dpchapp = new PnlBrlyPtyRec::DpchAppDo();
		((PnlBrlyPtyRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREG1NLOCATIONDATA) {
		req->dpchapp = new PnlBrlyReg1NLocation::DpchAppData();
		((PnlBrlyReg1NLocation::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREG1NLOCATIONDO) {
		req->dpchapp = new PnlBrlyReg1NLocation::DpchAppDo();
		((PnlBrlyReg1NLocation::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGADSTSWITCHDATA) {
		req->dpchapp = new PnlBrlyRegADstswitch::DpchAppData();
		((PnlBrlyRegADstswitch::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGADSTSWITCHDO) {
		req->dpchapp = new PnlBrlyRegADstswitch::DpchAppDo();
		((PnlBrlyRegADstswitch::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGDETAILDATA) {
		req->dpchapp = new PnlBrlyRegDetail::DpchAppData();
		((PnlBrlyRegDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGDETAILDO) {
		req->dpchapp = new PnlBrlyRegDetail::DpchAppDo();
		((PnlBrlyRegDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGDO) {
		req->dpchapp = new CrdBrlyReg::DpchAppDo();
		((CrdBrlyReg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGLISTDATA) {
		req->dpchapp = new PnlBrlyRegList::DpchAppData();
		((PnlBrlyRegList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGLISTDO) {
		req->dpchapp = new PnlBrlyRegList::DpchAppDo();
		((PnlBrlyRegList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGRECDO) {
		req->dpchapp = new PnlBrlyRegRec::DpchAppDo();
		((PnlBrlyRegRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGSUP1NREGIONDATA) {
		req->dpchapp = new PnlBrlyRegSup1NRegion::DpchAppData();
		((PnlBrlyRegSup1NRegion::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYREGSUP1NREGIONDO) {
		req->dpchapp = new PnlBrlyRegSup1NRegion::DpchAppDo();
		((PnlBrlyRegSup1NRegion::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRESUME) {
		req->dpchapp = new DpchAppBrlyResume();
		((DpchAppBrlyResume*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLY1NNODEDATA) {
		req->dpchapp = new PnlBrlyRly1NNode::DpchAppData();
		((PnlBrlyRly1NNode::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLY1NNODEDO) {
		req->dpchapp = new PnlBrlyRly1NNode::DpchAppDo();
		((PnlBrlyRly1NNode::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYDETAILDATA) {
		req->dpchapp = new PnlBrlyRlyDetail::DpchAppData();
		((PnlBrlyRlyDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYDETAILDO) {
		req->dpchapp = new PnlBrlyRlyDetail::DpchAppDo();
		((PnlBrlyRlyDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYDO) {
		req->dpchapp = new CrdBrlyRly::DpchAppDo();
		((CrdBrlyRly::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYLISTDATA) {
		req->dpchapp = new PnlBrlyRlyList::DpchAppData();
		((PnlBrlyRlyList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYLISTDO) {
		req->dpchapp = new PnlBrlyRlyList::DpchAppDo();
		((PnlBrlyRlyList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYRLYRECDO) {
		req->dpchapp = new PnlBrlyRlyRec::DpchAppDo();
		((PnlBrlyRlyRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGDETAILDATA) {
		req->dpchapp = new PnlBrlySegDetail::DpchAppData();
		((PnlBrlySegDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGDETAILDO) {
		req->dpchapp = new PnlBrlySegDetail::DpchAppDo();
		((PnlBrlySegDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGDO) {
		req->dpchapp = new CrdBrlySeg::DpchAppDo();
		((CrdBrlySeg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGLISTDATA) {
		req->dpchapp = new PnlBrlySegList::DpchAppData();
		((PnlBrlySegList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGLISTDO) {
		req->dpchapp = new PnlBrlySegList::DpchAppDo();
		((PnlBrlySegList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGMNCONNECTIONDATA) {
		req->dpchapp = new PnlBrlySegMNConnection::DpchAppData();
		((PnlBrlySegMNConnection::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGMNCONNECTIONDO) {
		req->dpchapp = new PnlBrlySegMNConnection::DpchAppDo();
		((PnlBrlySegMNConnection::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGMNLOCATIONDATA) {
		req->dpchapp = new PnlBrlySegMNLocation::DpchAppData();
		((PnlBrlySegMNLocation::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGMNLOCATIONDO) {
		req->dpchapp = new PnlBrlySegMNLocation::DpchAppDo();
		((PnlBrlySegMNLocation::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGORGMNSEGMENTDATA) {
		req->dpchapp = new PnlBrlySegOrgMNSegment::DpchAppData();
		((PnlBrlySegOrgMNSegment::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGORGMNSEGMENTDO) {
		req->dpchapp = new PnlBrlySegOrgMNSegment::DpchAppDo();
		((PnlBrlySegOrgMNSegment::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGPREDATA) {
		req->dpchapp = new PnlBrlySegPre::DpchAppData();
		((PnlBrlySegPre::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYSEGRECDO) {
		req->dpchapp = new PnlBrlySegRec::DpchAppDo();
		((PnlBrlySegRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTB1NFLIGHTDATA) {
		req->dpchapp = new PnlBrlyTtb1NFlight::DpchAppData();
		((PnlBrlyTtb1NFlight::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTB1NFLIGHTDO) {
		req->dpchapp = new PnlBrlyTtb1NFlight::DpchAppDo();
		((PnlBrlyTtb1NFlight::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBDETAILDATA) {
		req->dpchapp = new PnlBrlyTtbDetail::DpchAppData();
		((PnlBrlyTtbDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBDETAILDO) {
		req->dpchapp = new PnlBrlyTtbDetail::DpchAppDo();
		((PnlBrlyTtbDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBDO) {
		req->dpchapp = new CrdBrlyTtb::DpchAppDo();
		((CrdBrlyTtb::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBLISTDATA) {
		req->dpchapp = new PnlBrlyTtbList::DpchAppData();
		((PnlBrlyTtbList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBLISTDO) {
		req->dpchapp = new PnlBrlyTtbList::DpchAppDo();
		((PnlBrlyTtbList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBRECDO) {
		req->dpchapp = new PnlBrlyTtbRec::DpchAppDo();
		((PnlBrlyTtbRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBREF1NFILEDATA) {
		req->dpchapp = new PnlBrlyTtbRef1NFile::DpchAppData();
		((PnlBrlyTtbRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYTTBREF1NFILEDO) {
		req->dpchapp = new PnlBrlyTtbRef1NFile::DpchAppDo();
		((PnlBrlyTtbRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGAACCESSDATA) {
		req->dpchapp = new PnlBrlyUsgAAccess::DpchAppData();
		((PnlBrlyUsgAAccess::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGAACCESSDO) {
		req->dpchapp = new PnlBrlyUsgAAccess::DpchAppDo();
		((PnlBrlyUsgAAccess::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGDETAILDATA) {
		req->dpchapp = new PnlBrlyUsgDetail::DpchAppData();
		((PnlBrlyUsgDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGDETAILDO) {
		req->dpchapp = new PnlBrlyUsgDetail::DpchAppDo();
		((PnlBrlyUsgDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGDO) {
		req->dpchapp = new CrdBrlyUsg::DpchAppDo();
		((CrdBrlyUsg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGLISTDATA) {
		req->dpchapp = new PnlBrlyUsgList::DpchAppData();
		((PnlBrlyUsgList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGLISTDO) {
		req->dpchapp = new PnlBrlyUsgList::DpchAppDo();
		((PnlBrlyUsgList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGMNUSERDATA) {
		req->dpchapp = new PnlBrlyUsgMNUser::DpchAppData();
		((PnlBrlyUsgMNUser::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGMNUSERDO) {
		req->dpchapp = new PnlBrlyUsgMNUser::DpchAppDo();
		((PnlBrlyUsgMNUser::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSGRECDO) {
		req->dpchapp = new PnlBrlyUsgRec::DpchAppDo();
		((PnlBrlyUsgRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSR1NSESSIONDATA) {
		req->dpchapp = new PnlBrlyUsr1NSession::DpchAppData();
		((PnlBrlyUsr1NSession::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSR1NSESSIONDO) {
		req->dpchapp = new PnlBrlyUsr1NSession::DpchAppDo();
		((PnlBrlyUsr1NSession::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRAACCESSDATA) {
		req->dpchapp = new PnlBrlyUsrAAccess::DpchAppData();
		((PnlBrlyUsrAAccess::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRAACCESSDO) {
		req->dpchapp = new PnlBrlyUsrAAccess::DpchAppDo();
		((PnlBrlyUsrAAccess::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRDETAILDATA) {
		req->dpchapp = new PnlBrlyUsrDetail::DpchAppData();
		((PnlBrlyUsrDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRDETAILDO) {
		req->dpchapp = new PnlBrlyUsrDetail::DpchAppDo();
		((PnlBrlyUsrDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRDO) {
		req->dpchapp = new CrdBrlyUsr::DpchAppDo();
		((CrdBrlyUsr::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRLISTDATA) {
		req->dpchapp = new PnlBrlyUsrList::DpchAppData();
		((PnlBrlyUsrList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRLISTDO) {
		req->dpchapp = new PnlBrlyUsrList::DpchAppDo();
		((PnlBrlyUsrList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRMNUSERGROUPDATA) {
		req->dpchapp = new PnlBrlyUsrMNUsergroup::DpchAppData();
		((PnlBrlyUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRMNUSERGROUPDO) {
		req->dpchapp = new PnlBrlyUsrMNUsergroup::DpchAppDo();
		((PnlBrlyUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPBRLYUSRRECDO) {
		req->dpchapp = new PnlBrlyUsrRec::DpchAppDo();
		((PnlBrlyUsrRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYCONNEWDATA) {
		req->dpchapp = new DlgBrlyConNew::DpchAppData();
		((DlgBrlyConNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYCONNEWDO) {
		req->dpchapp = new DlgBrlyConNew::DpchAppDo();
		((DlgBrlyConNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYLEGNEWDATA) {
		req->dpchapp = new DlgBrlyLegNew::DpchAppData();
		((DlgBrlyLegNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYLEGNEWDO) {
		req->dpchapp = new DlgBrlyLegNew::DpchAppDo();
		((DlgBrlyLegNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYNAVLOAINIDATA) {
		req->dpchapp = new DlgBrlyNavLoaini::DpchAppData();
		((DlgBrlyNavLoaini::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYNAVLOAINIDO) {
		req->dpchapp = new DlgBrlyNavLoaini::DpchAppDo();
		((DlgBrlyNavLoaini::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBIMPFLTDATA) {
		req->dpchapp = new DlgBrlyTtbImpflt::DpchAppData();
		((DlgBrlyTtbImpflt::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBIMPFLTDO) {
		req->dpchapp = new DlgBrlyTtbImpflt::DpchAppDo();
		((DlgBrlyTtbImpflt::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBNEWDATA) {
		req->dpchapp = new DlgBrlyTtbNew::DpchAppData();
		((DlgBrlyTtbNew::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBNEWDO) {
		req->dpchapp = new DlgBrlyTtbNew::DpchAppDo();
		((DlgBrlyTtbNew::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDATA) {
		req->dpchapp = new DlgBrlyTtbTrlorig::DpchAppData();
		((DlgBrlyTtbTrlorig::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPDLGBRLYTTBTRLORIGDO) {
		req->dpchapp = new DlgBrlyTtbTrlorig::DpchAppDo();
		((DlgBrlyTtbTrlorig::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixBrlyVDpch == VecBrlyVDpch::DPCHAPPROOTBRLYLOGIN) {
		req->dpchapp = new RootBrly::DpchAppLogin();
		((RootBrly::DpchAppLogin*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixBrlyVDpch;
};

void BrlydAppsrv::writeDpchEng(
			XchgBrlyd* xchg
			, ReqBrly* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);

	if (req->dpcheng) {
		req->dpcheng->writeXML(req->ixBrlyVLocale, &(xchg->mScr), xchg->scr, xchg->descr, wr);
	} else {
		DpchEngBrlyConfirm dpchconfirm(false, req->jref, "");
		dpchconfirm.writeXML(req->ixBrlyVLocale, &(xchg->mScr), xchg->scr, xchg->descr, wr);
	};

	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

