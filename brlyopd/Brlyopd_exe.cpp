/**
  * \file Brlyopd_exe.cpp
  * Brly operation daemon brlyopd main (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brlyopd.h"

#include "Brlyopd_exe.h"

/******************************************************************************
 class PrefBrlyopd
 ******************************************************************************/

PrefBrlyopd::PrefBrlyopd(
			StgBrlyDatabase* stgbrlydatabase
			, StgBrlyFlightaware* stgbrlyflightaware
			, StgBrlyGeometry* stgbrlygeometry
			, StgBrlyMonitor* stgbrlymonitor
			, StgBrlyopd* stgbrlyopd
			, StgBrlyPath* stgbrlypath
			, const set<uint>& mask
		) : Block() {
	if (stgbrlydatabase) this->stgbrlydatabase = *stgbrlydatabase;
	if (stgbrlyflightaware) this->stgbrlyflightaware = *stgbrlyflightaware;
	if (stgbrlygeometry) this->stgbrlygeometry = *stgbrlygeometry;
	if (stgbrlymonitor) this->stgbrlymonitor = *stgbrlymonitor;
	if (stgbrlyopd) this->stgbrlyopd = *stgbrlyopd;
	if (stgbrlypath) this->stgbrlypath = *stgbrlypath;

	if (find(mask, ALL)) this->mask = {STGBRLYDATABASE, STGBRLYFLIGHTAWARE, STGBRLYGEOMETRY, STGBRLYMONITOR, STGBRLYOPD, STGBRLYPATH};
	else this->mask = mask;
};

bool PrefBrlyopd::all(
			const set<uint>& items
		) {
	if (!find(items, STGBRLYDATABASE)) return false;
	if (!find(items, STGBRLYFLIGHTAWARE)) return false;
	if (!find(items, STGBRLYGEOMETRY)) return false;
	if (!find(items, STGBRLYMONITOR)) return false;
	if (!find(items, STGBRLYOPD)) return false;
	if (!find(items, STGBRLYPATH)) return false;

	return true;
};

void PrefBrlyopd::readXMLFromFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/", true);

	closeParsed(doc, docctx);
};

void PrefBrlyopd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PrefBrlyopd");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (stgbrlydatabase.readXML(docctx, basexpath, true)) add(STGBRLYDATABASE);
		if (stgbrlyflightaware.readXML(docctx, basexpath, true)) add(STGBRLYFLIGHTAWARE);
		if (stgbrlygeometry.readXML(docctx, basexpath, true)) add(STGBRLYGEOMETRY);
		if (stgbrlymonitor.readXML(docctx, basexpath, true)) add(STGBRLYMONITOR);
		if (stgbrlyopd.readXML(docctx, basexpath, true)) add(STGBRLYOPD);
		if (stgbrlypath.readXML(docctx, basexpath, true)) add(STGBRLYPATH);
	} else {
		stgbrlydatabase = StgBrlyDatabase();
		stgbrlyflightaware = StgBrlyFlightaware();
		stgbrlygeometry = StgBrlyGeometry();
		stgbrlymonitor = StgBrlyMonitor();
		stgbrlyopd = StgBrlyopd();
		stgbrlypath = StgBrlyPath();
	};
};

void PrefBrlyopd::writeXMLToFile(
			const string& fullpath
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr);
	closewriteFile(wr);
};

void PrefBrlyopd::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "PrefBrlyopd");
		if (has(STGBRLYDATABASE)) stgbrlydatabase.writeXML(wr);
		if (has(STGBRLYFLIGHTAWARE)) stgbrlyflightaware.writeXML(wr);
		if (has(STGBRLYGEOMETRY)) stgbrlygeometry.writeXML(wr);
		if (has(STGBRLYMONITOR)) stgbrlymonitor.writeXML(wr);
		if (has(STGBRLYOPD)) stgbrlyopd.writeXML(wr);
		if (has(STGBRLYPATH)) stgbrlypath.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class Brlyopd
 ******************************************************************************/

Brlyopd::Brlyopd(
			const string& exedir
			, const usmallint engsrvportofs
		) {
	xchg = NULL;

	engsrv = NULL;

	curlrecv = NULL;
	curlrecvlen = 0;

	initdone = false;
	init(exedir, engsrvportofs);
};

Brlyopd::~Brlyopd() {
	term();
};

void Brlyopd::init(
			const string& exedir
			, const usmallint engsrvportofs
		) {
	pthread_attr_t attr;

	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	srand(time(NULL));

	// 1. create exchange object
	xchg = new XchgBrlyopd();
	xchg->exedir = exedir;

	// 3. load preferences
	loadPref();

	if (engsrvportofs != 0) xchg->stgbrlyopd.engsrvportofs = engsrvportofs;

	// 4. initialize exchange data objects
	initXchgdataOpprc();
	BrlyMapgen::initXchgdata(xchg);

	// 5. start op processor threads
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (unsigned int i=0;i<xchg->stgbrlyopd.opprcn;i++) {
		// thread
		opprcs.push_back(0);
		pthread_create(&(opprcs[i]), &attr, &BrlyopdOpprc::run, (void*) xchg);
	};

	pthread_attr_destroy(&attr);

	// 6. start engine server
	engsrv = BrlyopdEngsrv::start(xchg);

	// 7. cURL to BrlydOpengconsrv with DpchBrlyopdReg to retrieve scrNref (note that this might fail)

	Xmlio::startwriteBuffer(&wr, &xbuf);
		DpchBrlyopdReg::writeXML(wr, xchg->stgbrlyopd.engsrvportbase + xchg->stgbrlyopd.engsrvportofs, VecBrlyVOpengtype::BRLYOPD, xchg->stgbrlyopd.opprcn);
	Xmlio::closewriteBuffer(wr);

	if (CurlPostDpch("http://" + xchg->stgbrlyopd.engcliip + ":" + to_string(xchg->stgbrlyopd.engcliport) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
		// evaluate reply
		if (rplydpch == "dpchbrlydreg") {
			DpchBrlydReg* dpchbrlydreg = new DpchBrlydReg();
			dpchbrlydreg->readXML(docctx, "/", true);

			xchg->scrNref = dpchbrlydreg->scrNref;

			delete dpchbrlydreg;
		};

	} else {
		cout << "\terror connecting to engine!" << endl;
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	xmlBufferFree(xbuf);

	initdone = true;
};

void Brlyopd::term() {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	if (initdone) {
		// 1. cURL to BrlydOpengconsrv with DpchBrlyOpengUnreg ; note that this will fail in case the termination was initiated by the engine

		// POST content (DpchBrlyopdUnreg)
		Xmlio::startwriteBuffer(&wr, &xbuf);
			DpchBrlyopdUnreg::writeXML(wr, xchg->scrNref);
		Xmlio::closewriteBuffer(wr);

		if (CurlPostDpch("http://" + xchg->stgbrlyopd.engcliip + ":" + to_string(xchg->stgbrlyopd.engcliport) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
			// evaluate reply
			if (rplydpch == "dpchbrlydack") {
				// acknowledged
			};

		} else {
			// cout << "\terror disconnecting from engine!" << endl;
		};

		if (docctx) xmlXPathFreeContext(docctx);
		if (doc) xmlFreeDoc(doc);
		xmlBufferFree(xbuf);

		// 2. stop engine server
		BrlyopdEngsrv::stop(engsrv);

		// 3. end op processor threads
		for (unsigned int i=0;i<opprcs.size();i++) {
			//if (opprcs[i]) {
				pthread_cancel(opprcs[i]);
				pthread_join(opprcs[i], NULL);
			//};
		};

		// 4. clean-up exchange data objects
		BrlyMapgen::termXchgdata(xchg);
		termXchgdataOpprc();

		// 5. store preferences
		if (xchg->stgbrlyopd.engsrvportofs == 0) storePref();

		// 6. delete exchange object
		delete xchg;
	};
};

uint Brlyopd::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _inst
		) {
	Brlyopd* inst = (Brlyopd*) _inst;

	char* olddata;

	if (size > 0) {
		if (!inst->curlrecv) {
			inst->curlrecv = new char[size*blocksize];
			memcpy(inst->curlrecv, data, size*blocksize);
			inst->curlrecvlen = size*blocksize;

		} else {
			olddata = inst->curlrecv;

			inst->curlrecv = new char[inst->curlrecvlen + size*blocksize];
			memcpy(inst->curlrecv, olddata, inst->curlrecvlen);
			memcpy(&(inst->curlrecv[inst->curlrecvlen]), data, size*blocksize);
			inst->curlrecvlen = inst->curlrecvlen + size*blocksize;

			delete[] olddata;
		};
	};

  return(size*blocksize);
};

bool Brlyopd::CurlPostDpch(
			const string& url
			, xmlBuffer* xbuf
			, xmlDoc** rplydoc
			, xmlXPathContext** rplydocctx
			, string& rplydpch
		) {
	CURL* curl;
	CURLcode res;

	bool retval = false;

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		// receive buffer
		if (curlrecv) delete[] curlrecv;
		curlrecv = NULL;
		curlrecvlen = 0;

		// string to be sent is "xml=<xbuf>"
		size_t buflen = xbuf->use + 4;
		char* buf = new char[buflen];
		buf[0] = 'x'; buf[1] = 'm'; buf[2] = 'l'; buf[3] = '=';
		memcpy(&(buf[4]), xbuf->content, xbuf->use);

		// strip '\r' and '\n' characters
		for (size_t i=0;i<buflen;) {
			if ((buf[i] == '\r') || (buf[i] == '\n')) {
				memmove(&(buf[i]), &(buf[i+1]), buflen-i-1);
				buflen--;
			} else i++;
		};

		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buf);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, buflen);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);

		res = curl_easy_perform(curl);

		delete[] buf;

		curl_easy_cleanup(curl);

		// evaluate result
		if (curlrecv) {
			if (res == 0) {
				// check for root XML node
				Xmlio::parseBuffer(curlrecv, curlrecvlen, rplydoc, rplydocctx);
				rplydpch = StrMod::lc(Xmlio::extractRoot(*rplydoc));
				retval = true;
			};

			delete[] curlrecv;
			curlrecv = NULL;
			curlrecvlen = 0;
		};
	};

	return retval;
};

void Brlyopd::loadPref() {
	PrefBrlyopd pref;

	pref.readXMLFromFile(xchg->exedir + "/PrefBrlyopd.xml");

	xchg->stgbrlydatabase = pref.stgbrlydatabase;
	xchg->stgbrlyflightaware = pref.stgbrlyflightaware;
	xchg->stgbrlygeometry = pref.stgbrlygeometry;
	xchg->stgbrlymonitor = pref.stgbrlymonitor;
	xchg->stgbrlyopd = pref.stgbrlyopd;
	xchg->stgbrlypath = pref.stgbrlypath;

	xchg->acvpath = xchg->stgbrlypath.acvpath;
	xchg->tmppath = xchg->stgbrlypath.tmppath;
	xchg->helpurl = xchg->stgbrlypath.helpurl;
};

void Brlyopd::storePref() {
	PrefBrlyopd pref(&(xchg->stgbrlydatabase), &(xchg->stgbrlyflightaware), &(xchg->stgbrlygeometry), &(xchg->stgbrlymonitor), &(xchg->stgbrlyopd), &(xchg->stgbrlypath));

	pref.writeXMLToFile(xchg->exedir + "/PrefBrlyopd.xml");
};

void Brlyopd::initXchgdataOpprc() {
	// IP initXchgdataOpprc --- INSERT
};

void Brlyopd::termXchgdataOpprc() {
	// IP termXchgdataOpprc --- INSERT
};

/******************************************************************************
 main program
 ******************************************************************************/

void handleSignal(
			int sig
		) {
	// deleting brlyd forces PrefBrlyopd to be written
	if (brlyopd) delete brlyopd;

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
	usmallint engsrvportofs = 0;

	XchgBrlyopd* xchg;

	brlyopd = NULL;

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

	// evaluate command line options
	for (int i=1;i<argc;i++) {
		s = argv[i];

		if (s.find("-engsrvportofs=") == 0) engsrvportofs = atoi(s.substr(15).c_str());
	};

	try {
		// calls brlyopd.init()
		brlyopd = new Brlyopd(exedir, engsrvportofs);
		xchg = brlyopd->xchg;

		// wait on term condition (triggered on termination of brlyd and signals) 
		Mutex::lock(&(xchg->mcTerm), "xchg->mcTerm", "", "main");
		Cond::wait(&(xchg->cTerm), &(xchg->mcTerm), "xchg->cTerm", "", "main");
		Mutex::unlock(&(xchg->mcTerm), "xchg->mcTerm", "", "main");

		delete brlyopd;

	} catch (DbsException e) {
		cout << e.err << endl;
	};
	
	return(0);
};

