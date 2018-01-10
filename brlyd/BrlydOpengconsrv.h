/**
  * \file BrlydOpengconsrv.h
  * op engine connection server for Brly daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDOPENGCONSRV_H
#define BRLYDOPENGCONSRV_H

#ifndef _WIN32
	#include <arpa/inet.h>
#endif

/**
  * BrlydOpengconsrv
  */
namespace BrlydOpengconsrv {
	MHD_Daemon* start(XchgBrly* xchg);
	void stop(MHD_Daemon* d);

	int MhdAccept(void* cls, const sockaddr* addr, socklen_t addrlen);
	int MhdCallback(void* cls, MHD_Connection* connection, const char* url, const char* method, const char* version, const char* upload_data, size_t* upload_data_size, void** con_cls);
	int MhdPostrecv(void* con_cls, MHD_ValueKind kind, const char* key, const char* filename, const char* content_type, const char* transfer_encoding, const char* data, uint64_t off, size_t size);
	void MhdComplete(void* cls, MHD_Connection* connection, void** con_cls, MHD_RequestTerminationCode toe);

	uint readDpch(XchgBrlyd* xchg, ReqopengconBrly* req);
	void writeDpchAck(ReqopengconBrly* req);
	void writeDpchReg(XchgBrlyd* xchg, ReqopengconBrly* req, const ubigint nref);
};

#endif

