/**
  * \file Brlyd_exe.cpp
  * Brly daemon main (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brlyd.h"

#include "Brlyd_exe.h"

/******************************************************************************
 class PrefBrlyd
 ******************************************************************************/

PrefBrlyd::PrefBrlyd(
			StgBrlyd* stgbrlyd
			, StgBrlyDatabase* stgbrlydatabase
			, StgBrlyFlightaware* stgbrlyflightaware
			, StgBrlyGeometry* stgbrlygeometry
			, StgBrlyMonitor* stgbrlymonitor
			, StgBrlyPath* stgbrlypath
			, const set<uint>& mask
		) : Block() {
	if (stgbrlyd) this->stgbrlyd = *stgbrlyd;
	if (stgbrlydatabase) this->stgbrlydatabase = *stgbrlydatabase;
	if (stgbrlyflightaware) this->stgbrlyflightaware = *stgbrlyflightaware;
	if (stgbrlygeometry) this->stgbrlygeometry = *stgbrlygeometry;
	if (stgbrlymonitor) this->stgbrlymonitor = *stgbrlymonitor;
	if (stgbrlypath) this->stgbrlypath = *stgbrlypath;

	if (find(mask, ALL)) this->mask = {STGBRLYD, STGBRLYDATABASE, STGBRLYFLIGHTAWARE, STGBRLYGEOMETRY, STGBRLYMONITOR, STGBRLYPATH};
	else this->mask = mask;
};

bool PrefBrlyd::all(
			const set<uint>& items
		) {
	if (!find(items, STGBRLYD)) return false;
	if (!find(items, STGBRLYDATABASE)) return false;
	if (!find(items, STGBRLYFLIGHTAWARE)) return false;
	if (!find(items, STGBRLYGEOMETRY)) return false;
	if (!find(items, STGBRLYMONITOR)) return false;
	if (!find(items, STGBRLYPATH)) return false;

	return true;
};

void PrefBrlyd::readXMLFromFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/", true);

	closeParsed(doc, docctx);
};

void PrefBrlyd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PrefBrlyd");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (stgbrlyd.readXML(docctx, basexpath, true)) add(STGBRLYD);
		if (stgbrlydatabase.readXML(docctx, basexpath, true)) add(STGBRLYDATABASE);
		if (stgbrlyflightaware.readXML(docctx, basexpath, true)) add(STGBRLYFLIGHTAWARE);
		if (stgbrlygeometry.readXML(docctx, basexpath, true)) add(STGBRLYGEOMETRY);
		if (stgbrlymonitor.readXML(docctx, basexpath, true)) add(STGBRLYMONITOR);
		if (stgbrlypath.readXML(docctx, basexpath, true)) add(STGBRLYPATH);
	} else {
		stgbrlyd = StgBrlyd();
		stgbrlydatabase = StgBrlyDatabase();
		stgbrlyflightaware = StgBrlyFlightaware();
		stgbrlygeometry = StgBrlyGeometry();
		stgbrlymonitor = StgBrlyMonitor();
		stgbrlypath = StgBrlyPath();
	};
};

void PrefBrlyd::writeXMLToFile(
			const string& fullpath
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr);
	closewriteFile(wr);
};

void PrefBrlyd::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "PrefBrlyd");
		if (has(STGBRLYD)) stgbrlyd.writeXML(wr);
		if (has(STGBRLYDATABASE)) stgbrlydatabase.writeXML(wr);
		if (has(STGBRLYFLIGHTAWARE)) stgbrlyflightaware.writeXML(wr);
		if (has(STGBRLYGEOMETRY)) stgbrlygeometry.writeXML(wr);
		if (has(STGBRLYMONITOR)) stgbrlymonitor.writeXML(wr);
		if (has(STGBRLYPATH)) stgbrlypath.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class Brlyd
 ******************************************************************************/

Brlyd::Brlyd(
			const string& exedir
			, const bool clearAll
			, const bool startMon
		) {
	xchg = NULL;
	
	root = NULL;

	opengconsrv = NULL;
	appsrv = NULL;

	initdone = false;
	init(exedir, clearAll, startMon);
};

Brlyd::~Brlyd() {
	term();
};

void Brlyd::init(
			const string& exedir
			, const bool clearAll
			, const bool startMon
		) {
	pthread_attr_t attr;

	srand(time(NULL));

	// 1. create exchange object
	xchg = new XchgBrlyd();
	xchg->exedir = exedir;

	// 2. load preferences
	loadPref();

	// 3. initialize exchange data objects
	initXchgdataJobprc();

	// 4. connect to database
	dbsbrly.init(xchg->stgbrlydatabase.ixDbsVDbstype, xchg->stgbrlydatabase.dbspath, xchg->stgbrlydatabase.dbsname, xchg->stgbrlydatabase.ip
			, xchg->stgbrlydatabase.port, xchg->stgbrlydatabase.username, xchg->stgbrlydatabase.password);

	// 5. start monitoring (optional)
	if (startMon) xchg->startMon();

	// 6. establish root job
	root = new RootBrly(xchg, &dbsbrly, clearAll);

	// 7. start op engine client thread
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	pthread_create(&opengcli, &attr, &BrlydOpengcli::run, (void*) xchg);

	// 8. start job processor threads
	for (unsigned int i=0;i<xchg->stgbrlyd.jobprcn;i++) {
		// thread
		jobprcs.push_back(0);
		pthread_create(&(jobprcs[i]), &attr, &BrlydJobprc::run, (void*) xchg);
	};

	pthread_attr_destroy(&attr);

	// 9. start op engine connect server
	opengconsrv = BrlydOpengconsrv::start(xchg);

	// 10. start web server
	appsrv = BrlydAppsrv::start(xchg);

	initdone = true;
};

void Brlyd::term() {
	if (initdone) {
		// 1. stop web server
		BrlydAppsrv::stop(appsrv);

		// 2. stop op engine connect server
		BrlydOpengconsrv::stop(opengconsrv);

		// 3. cURL to all nodes (BrlyopdEngsrv) with DpchBrlydQuit
		xchg->quitNodes();

		// 4. end job processor threads
		for (unsigned int i=0;i<jobprcs.size();i++) {
			//if (jobprcs[i]) {
				pthread_cancel(jobprcs[i]);
				pthread_join(jobprcs[i], NULL);
			//};
		};

		// 5. end op engine client thread
		pthread_cancel(opengcli);
		pthread_join(opengcli, NULL);

		// 6. delete root job
		delete root;
		root = NULL;

		// 7. clean-up exchange data objects
		termXchgdataJobprc();

		// 8. store preferences
		storePref();

		// 9. delete exchange object
		delete xchg;
	};
};

void Brlyd::loadPref() {
	PrefBrlyd pref;

	pref.readXMLFromFile(xchg->exedir + "/PrefBrlyd.xml");

	xchg->stgbrlyd = pref.stgbrlyd;
	xchg->stgbrlydatabase = pref.stgbrlydatabase;
	xchg->stgbrlyflightaware = pref.stgbrlyflightaware;
	xchg->stgbrlygeometry = pref.stgbrlygeometry;
	xchg->stgbrlymonitor = pref.stgbrlymonitor;
	xchg->stgbrlypath = pref.stgbrlypath;

	xchg->acvpath = xchg->stgbrlypath.acvpath;
	xchg->tmppath = xchg->stgbrlypath.tmppath;
	xchg->helpurl = xchg->stgbrlypath.helpurl;
};

void Brlyd::storePref() {
	PrefBrlyd pref(&(xchg->stgbrlyd), &(xchg->stgbrlydatabase), &(xchg->stgbrlyflightaware), &(xchg->stgbrlygeometry), &(xchg->stgbrlymonitor), &(xchg->stgbrlypath));

	pref.writeXMLToFile(xchg->exedir + "/PrefBrlyd.xml");
};

void Brlyd::initXchgdataJobprc() {
	// IP initXchgdataJobprc --- INSERT
};

void Brlyd::termXchgdataJobprc() {
	// IP termXchgdataJobprc --- INSERT
};

/******************************************************************************
 main program
 ******************************************************************************/

void showSubjobs(
			XchgBrlyd* xchg
			, JobBrly* job
			, bool clstns
			, bool ops
			, bool presets
			, bool dcolcont
			, bool stmgrcont
			, unsigned int indent
		) {
	string id;

	// http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
	string setgray = "\033[38;2;196;196;196m";
	string reset = "\033[0m";

	DcolBrly* dcol = NULL;
	StmgrBrly* stmgr = NULL;

	vector<uint> icsBrlyVCall;
	vector<uint> icsVJobmask;

	vector<uint> icsBrlyVPreset;
	vector<Arg> args;

	// indentation
	for (unsigned int i=0;i<indent;i++) id = id + "\t";

	// actual entry
	if (job->jrefsSub.empty()) cout << "\t" << id << "- ";
	else cout << "\t" << id << "+ ";
	cout << VecBrlyVJob::getSref(job->ixBrlyVJob);

	if (job->jrefMast == job->jref) cout << "/M";
	else if (job->jrefMast != 0) cout << "/S";

	cout << " (" << job->jref;

	dcol = xchg->getDcolByJref(job->jref, false);
	if (dcol) {
		cout << ", dcol";
		dcol->unlockAccess("", "showSubjobs");
	};

	stmgr = xchg->getStmgrByJref(job->jref);
	if (stmgr) {
		cout << ", stmgr";
		stmgr->unlockAccess("", "showSubjobs");
	};

	cout << ")" << endl;

	if (clstns) {
		// call listeners
		cout << setgray;

		xchg->getClstnsByJref(job->jref, false, icsBrlyVCall, icsVJobmask);
		for (unsigned int i=0;i<icsBrlyVCall.size();i++)
					cout << "\t\t" << id << VecBrlyVCall::getSref(icsBrlyVCall[i]) << " (" << Clstn::VecVJobmask::getSref(icsVJobmask[i]) << ")" << endl;

		xchg->getClstnsByJref(job->jref, true, icsBrlyVCall, icsVJobmask);
		for (unsigned int i=0;i<icsBrlyVCall.size();i++)
					cout << "\t\t" << id << "stmgr: " << VecBrlyVCall::getSref(icsBrlyVCall[i]) << endl;

		cout << reset;
	};

	if (ops) {
		// ops
		cout << setgray;

		Mutex::lock(&(job->mOps), "job(" + to_string(job->jref) + ")->mOps", "", "showSubjobs");

		for (auto it=job->ops.begin();it!=job->ops.end();it++)
					cout << "\t\t" << id << VecBrlyVDpch::getSref((*it)->ixVDpch).substr(4+3) << " (" << to_string((*it)->oref) << "): " << (*it)->squawk << endl;

		Mutex::unlock(&(job->mOps), "job(" + to_string(job->jref) + ")->mOps", "", "showSubjobs");

		cout << reset;
	};

	if (presets) {
		// presettings
		cout << setgray;

		xchg->getPresetsByJref(job->jref, icsBrlyVPreset, args);

		for (unsigned int i=0;i<icsBrlyVPreset.size();i++)
					cout << "\t\t" << id << VecBrlyVPreset::getSref(icsBrlyVPreset[i]) << ": " << args[i].writeText() << endl;

		cout << reset;
	};

	if (dcolcont) {
		// dispatch collector content
		dcol = xchg->getDcolByJref(job->jref, false);

		if (dcol) {
			cout << setgray;

			for (auto it=dcol->dpchs.begin();it!=dcol->dpchs.end();it++)
						cout << "\t\t" << id << VecBrlyVDpch::getSref((*it)->ixBrlyVDpch) << " (" << (*it)->jref << ")" << endl;

			dcol->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	if (stmgrcont) {
		// stub manager content
		stmgr = xchg->getStmgrByJref(job->jref);

		if (stmgr) {
			cout << setgray;

			for (auto it=stmgr->stcch->nodes.begin();it!=stmgr->stcch->nodes.end();it++)
						cout << "\t\t" << id << VecBrlyVStub::getSref(it->second->stref.ixVStub) << " (" << it->second->stref.ref << "): " << it->second->stub << endl;

			stmgr->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	// sub-entries
	JobBrly* subjob;
	for (auto it=job->jrefsSub.begin();it!=job->jrefsSub.end();it++) {
		subjob = xchg->getJobByJref(*it);
		if (subjob) showSubjobs(xchg, subjob, clstns, ops, presets, dcolcont, stmgrcont, indent+1);
	};
};

void handleSignal(
			int sig
		) {
	// deleting brlyd forces PrefBrlyd to be written
	if (brlyd) delete brlyd;

	exit(sig);
};

int main(
			const int argc
			, const char** argv
		) {
	char* buf = NULL;
	string exedir;
	size_t ptr;

	string s;
	bool nocp = false;
	bool clearAll = false;
	bool startMon = false;

	pthread_mutex_t mcDummy;
	pthread_cond_t cDummy;

	string cmd;

	string input;
	int iinput;

	string s_backup;

	XchgBrlyd* xchg;

	JobBrly* job;

	ReqBrly* req;

	brlyd = NULL;

	// ensure proper termination on signals such as ctrl-c
#ifndef _WIN32
	signal(SIGHUP, handleSignal);
#endif
	signal(SIGINT, handleSignal); // 2
	signal(SIGTERM, handleSignal); // 15

	// determine executable path
	buf = new char[4096];

	if (readlink("/proc/self/exe", buf, 4096) >= 1) {
		exedir = buf;

	} else {
		if (strlen(argv[0]) >= 1) {
			exedir = argv[0];

			if (exedir[0] != '/') {
				if (getcwd(buf, 4096)) {
					exedir = "/" + exedir;
					exedir = buf + exedir;
				};
			};
		};
	};

	delete[] buf;

	ptr = exedir.rfind('/');
	if ((ptr != string::npos) && (ptr > 0)) exedir = exedir.substr(0, ptr);

	// evaluate command-line options
	for (int i=1;i<argc;i++) {
		s = argv[i];

		if (s == "-nocp") nocp = true;
		else if (s == "-clearAll") clearAll = true;
		else if (s == "-startMon") startMon = true;
	};

	try {
		// calls brlyd.init()
		brlyd = new Brlyd(exedir, clearAll, startMon);
		xchg = brlyd->xchg;

		// welcome message
		cout << "Welcome to BeamRelay 0.2.2!" << endl;

		if (nocp) {
			// wait on a dummy condition
			Mutex::init(&mcDummy, false, "mcDummy", "", "main");
			Cond::init(&cDummy, "cDummy", "", "main");
			Mutex::lock(&mcDummy, "mcDummy", "", "main");
			Cond::wait(&cDummy, &mcDummy, "cDummy", "", "main");
			Mutex::unlock(&mcDummy, "mcDummy", "", "main");
			Mutex::destroy(&mcDummy, false, "mcDummy", "", "main");
			Cond::destroy(&cDummy, "cDummy", "", "main");

		} else {
			// main command loop
			while (cmd != "quit") {
				cout << "Brlyd >> ";
				cin >> cmd;

				if (cmd == "quit") {

				} else if (cmd == "cmdsetStd") {
					cout << "\tquit" << endl;

					cout << "\tstartMon" << endl;
					cout << "\tstopMon" << endl;

					cout << "\tshowNodes" << endl;

					cout << "\tshowJobs" << endl;
					cout << "\tshowSubjobs" << endl;

					cout << "\tgotoJob" << endl;
					cout << "\tgotoSupjob" << endl;

					cout << "\tshowClstns" << endl;
					cout << "\tshowOps" << endl;
					cout << "\tshowPresets" << endl;

					cout << "\tshowDcolContent" << endl;
					cout << "\tshowStmgrContent" << endl;

				} else if (cmd == "startMon") {
					xchg->startMon();

				} else if (cmd == "stopMon") {
					xchg->stopMon();

				} else if (cmd == "showNodes") {
					NodeBrly* node = NULL;

					Mutex::lock(&(xchg->mNodes), "xchg->mNodes", "", "main");

					for (auto it=xchg->nodes.begin();it!=xchg->nodes.end();it++) {
						node = it->second;
						cout << "\tnode " << node->nref << " at " << node->ip << ":" << node->port << " running " << node->opprcn << " op processors" << endl;
					};

					Mutex::unlock(&(xchg->mNodes), "xchg->mNodes", "", "main");

				} else if (cmd == "showJobs") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, false, false, 0);

				} else if (cmd == "showSubjobs") {
					job = xchg->getJobByJref(xchg->jrefCmd);
					if (job) showSubjobs(xchg, job, false, false, false, false, false, 0);

				} else if (cmd == "gotoJob") {
					cout << "\tjob reference: ";
					cin >> input;
					iinput = atoi(input.c_str());

					job = xchg->getJobByJref(iinput);

					if (job) xchg->jrefCmd = job->jref;
					else cout << "\tjob reference doesn't exist!" << endl;

				} else if (cmd == "gotoSupjob") {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						job = xchg->getJobByJref(job->jrefSup);

						if (job) xchg->jrefCmd = job->jref;
						else cout << "\talready at topmost job!" << endl;
					};

				} else if (cmd == "showClstns") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, true, false, false, false, false, 0);

				} else if (cmd == "showOps") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, true, false, false, false, 0);

				} else if (cmd == "showPresets") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, true, false, false, 0);

				} else if (cmd == "showDcolContent") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, true, false, 0);

				} else if (cmd == "showStmgrContent") {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, false, true, 0);

				} else {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						req = new ReqBrly(ReqBrly::VecVBasetype::CMD, ReqBrly::VecVState::RECEIVE);
						req->cmd = cmd;
						req->jref = xchg->jrefCmd;

						xchg->addReq(req);

						s_backup = "";

						while (req->ixVState != ReqBrly::VecVState::REPLY) {
							// wait for job processor to finish or to time out
							Mutex::lock(&(req->mcReady), "req->mcReady", "", "main");
							Cond::timedwait(&(req->cReady), &(req->mcReady), 1000000, "req->cReady", "", "main");
							Mutex::unlock(&(req->mcReady), "req->mcReady", "", "main");

							if (req->ixVState == ReqBrly::VecVState::WAITPRC) {
								cout << "\twaiting for processing" << endl;

							} else if (req->ixVState == ReqBrly::VecVState::PRC) {
								s = job->getSquawk(&(brlyd->dbsbrly));
								if (s != s_backup) {
									cout << "\t" << s << endl;
									s_backup = s;
								};
							};
						};

						delete req;
					};
				};
			};
		};

		delete brlyd;

	} catch (DbsException e) {
		cout << e.err << endl;
	};
	
	return(0);
};

