/**
  * \file BrlyopdOpprc.cpp
  * operation processor for Brly operation daemon brlyopd (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brlyopd.h"

#include "BrlyopdOpprc.h"

/******************************************************************************
 namespace BrlyopdOpprc
 ******************************************************************************/

void* BrlyopdOpprc::run(
			void* arg
		) {
	XchgBrlyopd* xchg = (XchgBrlyopd*) arg;

	ReqopBrly* req = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// open database connection
	DbsBrly dbsbrly;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsbrly.init(xchg->stgbrlydatabase.ixDbsVDbstype, xchg->stgbrlydatabase.dbspath, xchg->stgbrlydatabase.dbsname, xchg->stgbrlydatabase.ip
						, xchg->stgbrlydatabase.port, xchg->stgbrlydatabase.username, xchg->stgbrlydatabase.password);
			break;
		} catch (DbsException e) {
			contry--;
			if (contry == 0) throw;
		};
	};

	// main loop: wait for ops in execution list
	while (true) {
		// a req is already here
		req = xchg->pullFirstReq();

		while (req == NULL) {
			// no req is here ; wait for it
			Mutex::lock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "BrlyopdOpprc", "run");
			Cond::wait(&(xchg->cOpprcs), &(xchg->mcOpprcs), "xchg->cOpprcs", "BrlyopdOpprc", "run");

			req = xchg->pullFirstReq();

			Mutex::unlock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "BrlyopdOpprc", "run");
		};

		// re-signal condition to avoid using broadcast
		Cond::signal(&(xchg->cOpprcs), &(xchg->mcOpprcs), "xchg->cOpprcs", "xchg->mcOpprcs", "BrlyopdOpprc", "run");

		// perform op corresponding to req's invoc
		if (req->dpchinv) {
			// perform op
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLEG) {
				req->dpchret = BrlyBaseLegleg::run(xchg, &dbsbrly, (DpchInvBrlyBaseLegleg*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELEGLOC) {
				req->dpchret = BrlyBaseLegloc::run(xchg, &dbsbrly, (DpchInvBrlyBaseLegloc*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYBASELOCLOC) {
				req->dpchret = BrlyBaseLocloc::run(xchg, &dbsbrly, (DpchInvBrlyBaseLocloc*) req->dpchinv);
			};
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPCOLLECT) {
				req->dpchret = BrlyDnsmapCollect::run(xchg, &dbsbrly, (DpchInvBrlyDnsmapCollect*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPFRAME) {
				req->dpchret = BrlyDnsmapFrame::run(xchg, &dbsbrly, (DpchInvBrlyDnsmapFrame*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDNSMAPVIDEO) {
				req->dpchret = BrlyDnsmapVideo::run(xchg, &dbsbrly, (DpchInvBrlyDnsmapVideo*) req->dpchinv);
			};
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONFLT) {
				req->dpchret = BrlyDynConflt::run(xchg, &dbsbrly, (DpchInvBrlyDynConflt*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNCONSEG) {
				req->dpchret = BrlyDynConseg::run(xchg, &dbsbrly, (DpchInvBrlyDynConseg*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNEQPLIST) {
				req->dpchret = BrlyDynEqplist::run(xchg, &dbsbrly, (DpchInvBrlyDynEqplist*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTFLTLOC) {
				req->dpchret = BrlyDynFltfltloc::run(xchg, &dbsbrly, (DpchInvBrlyDynFltfltloc*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNFLTSEG) {
				req->dpchret = BrlyDynFltseg::run(xchg, &dbsbrly, (DpchInvBrlyDynFltseg*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNRLY) {
				req->dpchret = BrlyDynRly::run(xchg, &dbsbrly, (DpchInvBrlyDynRly*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYDYNSEGLOCSEG) {
				req->dpchret = BrlyDynSeglocseg::run(xchg, &dbsbrly, (DpchInvBrlyDynSeglocseg*) req->dpchinv);
			};
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENCONMAP) {
				req->dpchret = BrlyMapgenConmap::run(xchg, &dbsbrly, (DpchInvBrlyMapgenConmap*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLEGMAP) {
				req->dpchret = BrlyMapgenLegmap::run(xchg, &dbsbrly, (DpchInvBrlyMapgenLegmap*) req->dpchinv);
			} else if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYMAPGENLOCMAP) {
				req->dpchret = BrlyMapgenLocmap::run(xchg, &dbsbrly, (DpchInvBrlyMapgenLocmap*) req->dpchinv);
			};
			if (req->dpchinv->ixBrlyVDpch == VecBrlyVDpch::DPCHINVBRLYTTIMPRAWSTAR) {
				req->dpchret = BrlyTtimpRawstar::run(xchg, &dbsbrly, (DpchInvBrlyTtimpRawstar*) req->dpchinv);
			};

			if (req->dpchret) {
				req->dpchret->scrOref = req->dpchinv->scrOref;
				req->dpchret->scrJref = req->dpchinv->scrJref;
			};
		};

		Mutex::lock(&(req->mcReady), "req->mcReady", "BrlyopdOpprc", "run");
		req->ixVState = ReqopBrly::VecVState::REPLY;
		Mutex::unlock(&(req->mcReady), "req->mcReady", "BrlyopdOpprc", "run");

		Cond::signal(&(req->cReady), &(req->mcReady), "req->cReady", "req->mcReady", "BrlyopdOpprc", "run");
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void BrlyopdOpprc::cleanup(
			void* arg
		) {
	XchgBrlyopd* xchg = (XchgBrlyopd*) arg;

	Mutex::unlock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "BrlyopdOpprc", "cleanup");
};

