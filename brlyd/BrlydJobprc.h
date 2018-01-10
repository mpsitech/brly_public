/**
  * \file BrlydJobprc.h
  * job processor for Brly daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYDJOBPRC_H
#define BRLYDJOBPRC_H

/**
  * BrlydJobprc
  */
namespace BrlydJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgBrlyd* xchg, DbsBrly* dbsbrly, ReqBrly* req);
};

#endif

