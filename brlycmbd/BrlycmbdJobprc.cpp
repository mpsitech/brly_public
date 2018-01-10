/**
  * \file BrlycmbdJobprc.cpp
  * job processor for Brly combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brlycmbd.h"

#include "BrlycmbdJobprc.h"

/******************************************************************************
 namespace BrlycmbdJobprc
 ******************************************************************************/

void* BrlycmbdJobprc::run(
			void* arg
		) {
	XchgBrlycmbd* xchg = (XchgBrlycmbd*) arg;

	ReqBrly* req = NULL;
	JobBrly* job = NULL;

	ubigint eref;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// open database connection
	DbsBrly dbsbrly;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsbrly.init(xchg->stgbrlydatabase.ixDbsVDbstype, xchg->stgbrlydatabase.dbspath, xchg->stgbrlydatabase.dbsname, xchg->stgbrlydatabase.ip,
						xchg->stgbrlydatabase.port, xchg->stgbrlydatabase.username, xchg->stgbrlydatabase.password);
			break;
		} catch (DbsException e) {
			contry--;
			if (contry == 0) throw;
		};
	};

	// main loop: wait for requests
	while (true) {
		// req is already here
		req = xchg->pullFirstReq();

		while (req == NULL) {
			// no req here ; wait for it
			Mutex::lock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "BrlycmbdJobprc", "run");
			Cond::wait(&(xchg->cJobprcs), &(xchg->mcJobprcs), "xchg->cJobprcs", "BrlycmbdJobprc", "run");

			req = xchg->pullFirstReq();

			Mutex::unlock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "BrlycmbdJobprc", "run");
		};

		// re-signal condition to avoid using broadcast
		Cond::signal(&(xchg->cJobprcs), &(xchg->mcJobprcs), "xchg->cJobprcs", "xchg->mcJobprcs", "BrlycmbdJobprc", "run");

		// --- handle request
		if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
			xchg->mon.eventHandleReqCmd(req->jref, req->cmd);

			// pass on to job
			accessJob(xchg, &dbsbrly, req);

		} else if (req->ixVBasetype == ReqBrly::VecVBasetype::REGULAR) {
			if (req->dpchapp) {
				//cout << "BrlycmbdJobprc::run() REGULAR request: '" << VecBrlyVDpch::getSref(req->dpchapp->ixBrlyVDpch) << "'" << endl;
				eref = xchg->mon.eventHandleReqRegular(req->jref, VecBrlyVDpch::getSref(req->dpchapp->ixBrlyVDpch), req->dpchapp->getSrefsMask(), "");

				// pass on to job
				accessJob(xchg, &dbsbrly, req);
			};

			if (!req->dpcheng) req->dpcheng = new DpchEngBrlyAck(req->jref);
			xchg->mon.eventReplyReqRegular(eref, req->jref, VecBrlyVDpch::getSref(req->dpcheng->ixBrlyVDpch), req->dpcheng->getSrefsMask(), "");

		} else if (req->ixVBasetype == ReqBrly::VecVBasetype::UPLOAD) {
			//cout << "BrlycmbdJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;
			xchg->mon.eventHandleReqUpload(req->jref, req->filename);

			// pass on to job
			accessJob(xchg, &dbsbrly, req);

			// usually the job leaves req unchanged

		} else if (req->ixVBasetype == ReqBrly::VecVBasetype::DOWNLOAD) {
			eref = xchg->mon.eventHandleReqDownload(req->jref);

			// pass on to job
			accessJob(xchg, &dbsbrly, req);

			xchg->mon.eventReplyReqDownload(eref, req->jref, req->filename);

		} else if (req->ixVBasetype == ReqBrly::VecVBasetype::RET) {
			if (req->dpchret) {
				//cout << "BrlycmbdJobprc::run() RET request: '" << VecBrlyVDpch::getSref(req->dpchret->ixBrlyVDpch) << "'" << endl;

				job = xchg->getJobByJref(req->jref);
				if (job) job->removeOp(req->dpchret->oref);

				xchg->mon.eventHandleReqRet(req->jref, VecBrlyVDpch::getSref(req->dpchret->ixBrlyVDpch), "", req->dpchret->oref);

				accessJob(xchg, &dbsbrly, req);
			};

		} else if (req->ixVBasetype == ReqBrly::VecVBasetype::TIMER) {
			// pass on to job
			job = xchg->getJobByJref(req->jref);

			if (job) if (req->wref >= job->wrefMin) {
				xchg->mon.eventHandleReqTimer(req->jref, req->sref);
				accessJob(xchg, &dbsbrly, req);
			};

		} else if (req->ixVBasetype == ReqBrly::VecVBasetype::EXTCALL) {
			xchg->triggerCall(&dbsbrly, req->call);
		};

		if ((req->ixVBasetype == ReqBrly::VecVBasetype::RET) || (req->ixVBasetype == ReqBrly::VecVBasetype::TIMER) || (req->ixVBasetype == ReqBrly::VecVBasetype::EXTCALL)) {
			// ret, timer and extcall requests can be deleted here
			delete req;

		} else {
			// all other requests are being waited for for further processing
			if (!(req->retain)) req->setStateReply();
		};
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void BrlycmbdJobprc::cleanup(
			void* arg
		) {
	XchgBrlycmbd* xchg = (XchgBrlycmbd*) arg;

	Mutex::unlock(&(xchg->mcJobprcs), "xchg->mcJobprcs", "BrlycmbdJobprc", "cleanup");
};

void BrlycmbdJobprc::accessJob(
			XchgBrlycmbd* xchg
			, DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	JobBrly* job = NULL;
	
	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("BrlycmbdJobprc", "accessJob");

		req->ixBrlyVLocale = job->ixBrlyVLocale;
		job->handleRequest(dbsbrly, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("BrlycmbdJobprc", "accessJob");
	};
};

