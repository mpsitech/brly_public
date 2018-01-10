/**
  * \file BrlydOpengcli.h
  * operation engine client for Brly daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDOPENGCLI_H
#define BRLYDOPENGCLI_H

#include "Brlyd.h"

/**
  * BrlydOpengcli
  */
namespace BrlydOpengcli {
	void* run(void* arg);
	void cleanup(void* arg);
};

/**
  * BrlydOpengcli_argsub
  */
struct BrlydOpengcli_argsub {
	XchgBrlyd* xchg;
	NodeBrly* node;
	DpchInvBrly* inv;
};

/**
  * BrlydOpengcli_sub
  */
namespace BrlydOpengcli_sub {
	void* run(void* _arg);

	uint CurlPostrecv(void* data, uint size, uint blocksize, void* _ret);

	uint readDpchRet(XchgBrlyd* xchg, ReqBrly* req);
	void writeDpchInv(XchgBrlyd* xchg, ReqBrly* req);
};

#endif

