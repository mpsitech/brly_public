/**
  * \file BrlycmbdJobprc.h
  * job processor for Brly combined daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYCMBDJOBPRC_H
#define BRLYCMBDJOBPRC_H

/**
  * BrlycmbdJobprc
  */
namespace BrlycmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgBrlycmbd* xchg, DbsBrly* dbsbrly, ReqBrly* req);
};

#endif



