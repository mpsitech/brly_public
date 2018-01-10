/**
  * \file IexBrlyFlt.cpp
  * import/export handler for database DbsBrly (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "IexBrlyFlt.h"

#include "IexBrlyFlt_blks.cpp"

/******************************************************************************
 class IexBrlyFlt
 ******************************************************************************/

IexBrlyFlt::IexBrlyFlt(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::IEXBRLYFLT, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);
};

IexBrlyFlt::~IexBrlyFlt() {
	// remove job reference from job list
	if (jref != 0) xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void IexBrlyFlt::reset() {
	imeimfaflight.clear();

	lineno = 0;
	impcnt = 0;
};

void IexBrlyFlt::import(
			DbsBrly* dbsbrly
		) {
	ImeitemIMFaflight* faf = NULL;
	ImeitemIAMFaflightWaypoint* fafAwpt = NULL;

	uint num1;

	// IP import --- IBEGIN
	ubigint ref, ref2;

	map<string, ubigint> refsLoc;
	map<string, ubigint> refsLeg;
	map<string, ubigint>::iterator it;

	ListBrlyMFlight flts;
	BrlyMFlight* flt = NULL;
	// IP import --- IEND

	// IP import.traverse --- RBEGIN

	// -- ImeIMFaflight
	for (unsigned int ix0=0;ix0<imeimfaflight.nodes.size();ix0++) {
		faf = imeimfaflight.nodes[ix0];

		if (faf->ixBrlyVIop == VecBrlyVIop::INS) {
			//faf->refBrlyMFlight: CUSTSQL

			ref = 0;
			it = refsLeg.find(faf->iLeg);

			if (it == refsLeg.end()) {
				if (faf->iLeg.length() == 7) {
					ref = 0;
					it = refsLoc.find(faf->iLeg.substr(0, 3));
					if (it == refsLoc.end()) {
						if (dbsbrly->tblbrlymlocation->loadRefBySrf(faf->iLeg.substr(0, 3), ref)) refsLoc[faf->iLeg.substr(0, 3)] = ref;
					} else {
						ref = it->second;
					};

					ref2 = 0;
					it = refsLoc.find(faf->iLeg.substr(4));
					if (it == refsLoc.end()) {
						if (dbsbrly->tblbrlymlocation->loadRefBySrf(faf->iLeg.substr(4), ref2)) refsLoc[faf->iLeg.substr(4)] = ref2;
					} else {
						ref2 = it->second;
					};

					if (dbsbrly->tblbrlymleg->loadRefByTypBloElo(VecBrlyVMLegBasetype::RTE, ref, ref2, ref)) {
						refsLeg[faf->iLeg] = ref;
					} else {
						ref = 0;
					};
				};

			} else {
				ref = it->second;
			};

if (ref == 0) cout << "unable to find leg '" << faf->iLeg << "'" << endl;

			if (ref != 0) {
				dbsbrly->tblbrlymflight->loadRstBySQL("SELECT * FROM TblBrlyMFlight WHERE refBrlyMLeg = " + to_string(ref) + " AND start > " + to_string(faf->actualdeparturetime-6*3600)
							+ " AND start < " + to_string(faf->actualdeparturetime+6*3600), false, flts);

if (flts.nodes.size() == 0) cout << faf->faFlightID << ": empty flts." << endl;

				for (unsigned int i=0;i<flts.nodes.size();i++) {
					flt = flts.nodes[i];

					if (flt->sref.find(faf->hintRefBrlyMFlight + " ") == 0) {
						faf->refBrlyMFlight = flt->ref;
						break;
					};
				};
			};

			//faf->faFlightID: VOID
			//faf->ident: VOID
			//faf->aircrafttype: VOID
			//faf->filed_ete: VOID
			//faf->filed_time: VOID
			//faf->filed_departuretime: VOID
			//faf->filed_airspeed_kts: VOID
			//faf->filed_airspeed_mach: VOID
			//faf->filed_altitude: VOID
			//faf->route: VOID
			//faf->actualdeparturetime: VOID
			//faf->estimatedarrivaltime: VOID
			//faf->actualarrivaltime: VOID
			//faf->diverted: VOID
			//faf->origin: VOID
			//faf->destination: VOID
			//faf->originName: VOID
			//faf->originCity: VOID
			//faf->destinationName: VOID
			//faf->destinationCity: VOID

			if (faf->refBrlyMFlight != 0) {
				dbsbrly->tblbrlymfaflight->insertRec(faf);
				impcnt++;

				flt->refBrlyMFaflight = faf->ref;
				dbsbrly->tblbrlymflight->updateRec(flt);
			};

		} else if (faf->ixBrlyVIop == VecBrlyVIop::RETR) {
			dbsbrly->loadRefBySQL("SELECT ref FROM TblBrlyMFaflight WHERE faFlightID = '" + faf->faFlightID + "'", faf->ref);

			// skip record content as it is not used
		};

		if (faf->ref != 0) {
			for (unsigned int ix1=0;ix1<faf->imeiamfaflightwaypoint.nodes.size();ix1++) {
				fafAwpt = faf->imeiamfaflightwaypoint.nodes[ix1];

				fafAwpt->fafRefBrlyMFaflight = faf->ref;
				fafAwpt->fafNum = (ix1+1);
				//fafAwpt->timestamp: VOID
				//fafAwpt->latitude: VOID
				//fafAwpt->longitude: VOID
				//fafAwpt->groundspeed: VOID
				//fafAwpt->altitude: VOID
				//fafAwpt->altitudeStatus: VOID
				//fafAwpt->updateType: VOID
				//fafAwpt->altitudeChange: VOID

				dbsbrly->tblbrlyamfaflightwaypoint->insertRec(fafAwpt);
				impcnt++;
			};
		};
	};
	// IP import.traverse --- REND

	// IP import.ppr --- INSERT
};

void IexBrlyFlt::collect(
			DbsBrly* dbsbrly
			, const map<uint,uint>& icsBrlyVIop
		) {
	ImeitemIMFaflight* faf = NULL;
	ImeitemIAMFaflightWaypoint* fafAwpt = NULL;

	uint ixBrlyVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP collect.traverse --- BEGIN

	// -- ImeIMFaflight
	for (unsigned int ix0=0;ix0<imeimfaflight.nodes.size();ix0++) {
		faf = imeimfaflight.nodes[ix0];

		if (faf->ref != 0) {
			//faf->srefIxBrlyVIop: IOP
			//faf->iLeg: IARG
			//faf->hintRefBrlyMFlight: STUB
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIAMFAFLIGHTWAYPOINT, ixBrlyVIop)) {
			dbsbrly->tblbrlyamfaflightwaypoint->loadRefsByFaf(faf->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) faf->imeiamfaflightwaypoint.nodes.push_back(new ImeitemIAMFaflightWaypoint(dbsbrly, refs[i]));
		};

		for (unsigned int ix1=0;ix1<faf->imeiamfaflightwaypoint.nodes.size();ix1++) {
			fafAwpt = faf->imeiamfaflightwaypoint.nodes[ix1];

			if (fafAwpt->ref != 0) {
			};
		};
	};
	// IP collect.traverse --- END

	// IP collect.ppr --- INSERT

	delete stcch;
};

bool IexBrlyFlt::readTxt(
			Txtrd& txtrd
		) {
	bool parseok = true;

	while (txtrd.readLine()) {
		if (txtrd.comment) {
		} else if (txtrd.header && (txtrd.il == 0)) {
			if (txtrd.ixVToken == VecVIme::IMEIMFAFLIGHT) {
				parseok = imeimfaflight.readTxt(txtrd); if (!parseok) break;
			} else {
				parseok = false; break;
			};
		} else {
			parseok = false; break;
		};
	};

	lineno = txtrd.linecnt;

	return parseok;
};

void IexBrlyFlt::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	bool basefound;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "IexBrlyFlt");

	if (basefound) {
		// look for XML sub-blocks
		imeimfaflight.readXML(docctx, basexpath);
	} else {
		imeimfaflight = ImeIMFaflight();
	};
};

bool IexBrlyFlt::readTxtFile(
			const string& fullpath
		) {
	bool retval;

	Txtrd rd(VecVIme::getIx);

	rd.openFile(fullpath);

	retval = readTxt(rd);

	rd.closeFile();

	return retval;
};

bool IexBrlyFlt::readXMLFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/");

	closeParsed(doc, docctx);

	return true;
};

void IexBrlyFlt::writeTxt(
			fstream& outfile
		) {
	imeimfaflight.writeTxt(outfile);
};

void IexBrlyFlt::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexBrlyFlt");
		imeimfaflight.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

void IexBrlyFlt::writeTxtFile(
			const string& fullpath
		) {
	fstream txtfile;

	txtfile.open(fullpath.c_str(), ios::out);

	writeTxt(txtfile);
	
	txtfile.close();
};

void IexBrlyFlt::writeXMLFile(
			const string& fullpath
			, const bool shorttags
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr, shorttags);
	closewriteFile(wr);
};

map<uint,uint> IexBrlyFlt::icsBrlyVIopInsAll() {
	return {{(uint)VecVIme::IMEIMFAFLIGHT,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAMFAFLIGHTWAYPOINT,VecBrlyVIop::INS}};
};

uint IexBrlyFlt::getIxBrlyVIop(
			const map<uint,uint>& icsBrlyVIop
			, const uint ixVIme
			, uint& ixBrlyVIop
		) {
	ixBrlyVIop = 0;

	auto it = icsBrlyVIop.find(ixVIme);
	if (it != icsBrlyVIop.end()) ixBrlyVIop = it->second;

	return ixBrlyVIop;
};

void IexBrlyFlt::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};
	};
};

void IexBrlyFlt::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
};


