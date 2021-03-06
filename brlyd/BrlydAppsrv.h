/**
  * \file BrlydAppsrv.h
  * application server for Brly daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDAPPSRV_H
#define BRLYDAPPSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

#include "RootBrly.h"

/**
  * BrlydAppsrv
  */
namespace BrlydAppsrv {
	MHD_Daemon* start(XchgBrlyd* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
#ifdef _WIN32
	int MhdFilesend(void* con_cls, uint64_t pos, char* buf, int max);
#else
	ssize_t MhdFilesend(void* con_cls, uint64_t pos, char* buf, size_t max);
#endif
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	bool validateIp(XchgBrlyd* xchg, ReqBrly* req);
	bool validateJrefNotify(XchgBrlyd* xchg, ReqBrly* req);
	uint readDpchApp(XchgBrlyd* xchg, ReqBrly* req);
	void writeDpchEng(XchgBrlyd* xchg, ReqBrly* req);
};

#endif

