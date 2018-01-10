/**
  * \file IexBrlyFlt_blks.cpp
  * import/export handler for database DbsBrly (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class IexBrlyFlt::VecVIme
 ******************************************************************************/

uint IexBrlyFlt::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimfaflight") return IMEIMFAFLIGHT;
	else if (s == "imeiamfaflightwaypoint") return IMEIAMFAFLIGHTWAYPOINT;

	return(0);
};

string IexBrlyFlt::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMFAFLIGHT) return("ImeIMFaflight");
	else if (ix == IMEIAMFAFLIGHTWAYPOINT) return("ImeIAMFaflightWaypoint");

	return("");
};

/******************************************************************************
 class IexBrlyFlt::ImeitemIAMFaflightWaypoint
 ******************************************************************************/

IexBrlyFlt::ImeitemIAMFaflightWaypoint::ImeitemIAMFaflightWaypoint(
			const uint timestamp
			, const double latitude
			, const double longitude
			, const usmallint groundspeed
			, const usmallint altitude
			, const string& altitudeStatus
			, const string& updateType
			, const string& altitudeChange
		) : BrlyAMFaflightWaypoint() {
	lineno = 0;
	ixWIelValid = 0;

	this->timestamp = timestamp;
	this->latitude = latitude;
	this->longitude = longitude;
	this->groundspeed = groundspeed;
	this->altitude = altitude;
	this->altitudeStatus = altitudeStatus;
	this->updateType = updateType;
	this->altitudeChange = altitudeChange;
};

IexBrlyFlt::ImeitemIAMFaflightWaypoint::ImeitemIAMFaflightWaypoint(
			DbsBrly* dbsbrly
			, const ubigint ref
		) : ImeitemIAMFaflightWaypoint() {
	BrlyAMFaflightWaypoint* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlyamfaflightwaypoint->loadRecByRef(ref, &rec)) {
		fafRefBrlyMFaflight = rec->fafRefBrlyMFaflight;
		fafNum = rec->fafNum;
		timestamp = rec->timestamp;
		latitude = rec->latitude;
		longitude = rec->longitude;
		groundspeed = rec->groundspeed;
		altitude = rec->altitude;
		altitudeStatus = rec->altitudeStatus;
		updateType = rec->updateType;
		altitudeChange = rec->altitudeChange;

		delete rec;
	};
};

bool IexBrlyFlt::ImeitemIAMFaflightWaypoint::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) timestamp = atol(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) latitude = atof(txtrd.fields[1].c_str());
	if (txtrd.fields.size() > 2) longitude = atof(txtrd.fields[2].c_str());
	if (txtrd.fields.size() > 3) groundspeed = atoi(txtrd.fields[3].c_str());
	if (txtrd.fields.size() > 4) altitude = atoi(txtrd.fields[4].c_str());
	if (txtrd.fields.size() > 5) altitudeStatus = txtrd.fields[5];
	if (txtrd.fields.size() > 6) updateType = txtrd.fields[6];
	if (txtrd.fields.size() > 7) altitudeChange = txtrd.fields[7];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexBrlyFlt::ImeitemIAMFaflightWaypoint::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUintUclc(docctx, basexpath, "timestamp", "tms", timestamp)) ixWIelValid += ImeIAMFaflightWaypoint::VecWIel::TIMESTAMP;
		if (extractDoubleUclc(docctx, basexpath, "latitude", "lat", latitude)) ixWIelValid += ImeIAMFaflightWaypoint::VecWIel::LATITUDE;
		if (extractDoubleUclc(docctx, basexpath, "longitude", "lon", longitude)) ixWIelValid += ImeIAMFaflightWaypoint::VecWIel::LONGITUDE;
		if (extractUsmallintUclc(docctx, basexpath, "groundspeed", "gsp", groundspeed)) ixWIelValid += ImeIAMFaflightWaypoint::VecWIel::GROUNDSPEED;
		if (extractUsmallintUclc(docctx, basexpath, "altitude", "alt", altitude)) ixWIelValid += ImeIAMFaflightWaypoint::VecWIel::ALTITUDE;
		if (extractStringUclc(docctx, basexpath, "altitudeStatus", "ast", altitudeStatus)) ixWIelValid += ImeIAMFaflightWaypoint::VecWIel::ALTITUDESTATUS;
		if (extractStringUclc(docctx, basexpath, "updateType", "uty", updateType)) ixWIelValid += ImeIAMFaflightWaypoint::VecWIel::UPDATETYPE;
		if (extractStringUclc(docctx, basexpath, "altitudeChange", "ach", altitudeChange)) ixWIelValid += ImeIAMFaflightWaypoint::VecWIel::ALTITUDECHANGE;
	};
};

void IexBrlyFlt::ImeitemIAMFaflightWaypoint::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << timestamp << "\t" << latitude << "\t" << longitude << "\t" << groundspeed << "\t" << altitude << "\t" << altitudeStatus << "\t" << updateType << "\t" << altitudeChange << endl;
};

void IexBrlyFlt::ImeitemIAMFaflightWaypoint::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tms","lat","lon","gsp","alt","ast","uty","ach"};
	else tags = {"ImeitemIAMFaflightWaypoint","timestamp","latitude","longitude","groundspeed","altitude","altitudeStatus","updateType","altitudeChange"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], timestamp);
		writeDouble(wr, tags[2], latitude);
		writeDouble(wr, tags[3], longitude);
		writeUsmallint(wr, tags[4], groundspeed);
		writeUsmallint(wr, tags[5], altitude);
		writeString(wr, tags[6], altitudeStatus);
		writeString(wr, tags[7], updateType);
		writeString(wr, tags[8], altitudeChange);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyFlt::ImeIAMFaflightWaypoint::VecWIel
 ******************************************************************************/

uint IexBrlyFlt::ImeIAMFaflightWaypoint::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "timestamp") ix |= TIMESTAMP;
		else if (ss[i] == "latitude") ix |= LATITUDE;
		else if (ss[i] == "longitude") ix |= LONGITUDE;
		else if (ss[i] == "groundspeed") ix |= GROUNDSPEED;
		else if (ss[i] == "altitude") ix |= ALTITUDE;
		else if (ss[i] == "altitudestatus") ix |= ALTITUDESTATUS;
		else if (ss[i] == "updatetype") ix |= UPDATETYPE;
		else if (ss[i] == "altitudechange") ix |= ALTITUDECHANGE;
	};

	return(ix);
};

void IexBrlyFlt::ImeIAMFaflightWaypoint::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*ALTITUDECHANGE);i*=2) if (ix & i) ics.insert(i);
};

string IexBrlyFlt::ImeIAMFaflightWaypoint::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TIMESTAMP) ss.push_back("timestamp");
	if (ix & LATITUDE) ss.push_back("latitude");
	if (ix & LONGITUDE) ss.push_back("longitude");
	if (ix & GROUNDSPEED) ss.push_back("groundspeed");
	if (ix & ALTITUDE) ss.push_back("altitude");
	if (ix & ALTITUDESTATUS) ss.push_back("altitudeStatus");
	if (ix & UPDATETYPE) ss.push_back("updateType");
	if (ix & ALTITUDECHANGE) ss.push_back("altitudeChange");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyFlt::ImeIAMFaflightWaypoint
 ******************************************************************************/

IexBrlyFlt::ImeIAMFaflightWaypoint::ImeIAMFaflightWaypoint() {
};

IexBrlyFlt::ImeIAMFaflightWaypoint::~ImeIAMFaflightWaypoint() {
	clear();
};

void IexBrlyFlt::ImeIAMFaflightWaypoint::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexBrlyFlt::ImeIAMFaflightWaypoint::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyFlt::ImeitemIAMFaflightWaypoint* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header || (txtrd.il < 1)) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 1)) {
			ii = new IexBrlyFlt::ImeitemIAMFaflightWaypoint();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexBrlyFlt::ImeIAMFaflightWaypoint::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyFlt::ImeitemIAMFaflightWaypoint* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMFaflightWaypoint");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMFaflightWaypoint", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMFaflightWaypoint";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyFlt::ImeitemIAMFaflightWaypoint();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyFlt::ImeIAMFaflightWaypoint::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMFaflightWaypoint." << StrMod::replaceChar(ImeIAMFaflightWaypoint::VecWIel::getSrefs(255), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexBrlyFlt::ImeIAMFaflightWaypoint::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMFaflightWaypoint");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyFlt::ImeitemIMFaflight
 ******************************************************************************/

IexBrlyFlt::ImeitemIMFaflight::ImeitemIMFaflight(
			const uint ixBrlyVIop
			, const string& iLeg
			, const string& hintRefBrlyMFlight
			, const string& faFlightID
			, const string& ident
			, const string& aircrafttype
			, const string& filed_ete
			, const uint filed_time
			, const uint filed_departuretime
			, const usmallint filed_airspeed_kts
			, const double filed_airspeed_mach
			, const usmallint filed_altitude
			, const string& route
			, const uint actualdeparturetime
			, const uint estimatedarrivaltime
			, const uint actualarrivaltime
			, const string& diverted
			, const string& origin
			, const string& destination
			, const string& originName
			, const string& originCity
			, const string& destinationName
			, const string& destinationCity
		) : BrlyMFaflight() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixBrlyVIop = ixBrlyVIop;
	this->iLeg = iLeg;
	this->hintRefBrlyMFlight = hintRefBrlyMFlight;
	this->faFlightID = faFlightID;
	this->ident = ident;
	this->aircrafttype = aircrafttype;
	this->filed_ete = filed_ete;
	this->filed_time = filed_time;
	this->filed_departuretime = filed_departuretime;
	this->filed_airspeed_kts = filed_airspeed_kts;
	this->filed_airspeed_mach = filed_airspeed_mach;
	this->filed_altitude = filed_altitude;
	this->route = route;
	this->actualdeparturetime = actualdeparturetime;
	this->estimatedarrivaltime = estimatedarrivaltime;
	this->actualarrivaltime = actualarrivaltime;
	this->diverted = diverted;
	this->origin = origin;
	this->destination = destination;
	this->originName = originName;
	this->originCity = originCity;
	this->destinationName = destinationName;
	this->destinationCity = destinationCity;
};

IexBrlyFlt::ImeitemIMFaflight::ImeitemIMFaflight(
			DbsBrly* dbsbrly
			, const uint ixBrlyVIop
			, const ubigint ref
		) : ImeitemIMFaflight(ixBrlyVIop) {
	BrlyMFaflight* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymfaflight->loadRecByRef(ref, &rec)) {
		refBrlyMFlight = rec->refBrlyMFlight;
		faFlightID = rec->faFlightID;
		ident = rec->ident;
		aircrafttype = rec->aircrafttype;
		filed_ete = rec->filed_ete;
		filed_time = rec->filed_time;
		filed_departuretime = rec->filed_departuretime;
		filed_airspeed_kts = rec->filed_airspeed_kts;
		filed_airspeed_mach = rec->filed_airspeed_mach;
		filed_altitude = rec->filed_altitude;
		route = rec->route;
		actualdeparturetime = rec->actualdeparturetime;
		estimatedarrivaltime = rec->estimatedarrivaltime;
		actualarrivaltime = rec->actualarrivaltime;
		diverted = rec->diverted;
		origin = rec->origin;
		destination = rec->destination;
		originName = rec->originName;
		originCity = rec->originCity;
		destinationName = rec->destinationName;
		destinationCity = rec->destinationCity;

		delete rec;
	};
};

bool IexBrlyFlt::ImeitemIMFaflight::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) ixBrlyVIop = VecBrlyVIop::getIx(txtrd.fields[0]);
	if (txtrd.fields.size() > 1) iLeg = txtrd.fields[1];
	if (txtrd.fields.size() > 2) hintRefBrlyMFlight = txtrd.fields[2];
	if (txtrd.fields.size() > 3) faFlightID = txtrd.fields[3];
	if (txtrd.fields.size() > 4) ident = txtrd.fields[4];
	if (txtrd.fields.size() > 5) aircrafttype = txtrd.fields[5];
	if (txtrd.fields.size() > 6) filed_ete = txtrd.fields[6];
	if (txtrd.fields.size() > 7) filed_time = atol(txtrd.fields[7].c_str());
	if (txtrd.fields.size() > 8) filed_departuretime = atol(txtrd.fields[8].c_str());
	if (txtrd.fields.size() > 9) filed_airspeed_kts = atoi(txtrd.fields[9].c_str());
	if (txtrd.fields.size() > 10) filed_airspeed_mach = atof(txtrd.fields[10].c_str());
	if (txtrd.fields.size() > 11) filed_altitude = atoi(txtrd.fields[11].c_str());
	if (txtrd.fields.size() > 12) route = txtrd.fields[12];
	if (txtrd.fields.size() > 13) actualdeparturetime = atol(txtrd.fields[13].c_str());
	if (txtrd.fields.size() > 14) estimatedarrivaltime = atol(txtrd.fields[14].c_str());
	if (txtrd.fields.size() > 15) actualarrivaltime = atol(txtrd.fields[15].c_str());
	if (txtrd.fields.size() > 16) diverted = txtrd.fields[16];
	if (txtrd.fields.size() > 17) origin = txtrd.fields[17];
	if (txtrd.fields.size() > 18) destination = txtrd.fields[18];
	if (txtrd.fields.size() > 19) originName = txtrd.fields[19];
	if (txtrd.fields.size() > 20) originCity = txtrd.fields[20];
	if (txtrd.fields.size() > 21) destinationName = txtrd.fields[21];
	if (txtrd.fields.size() > 22) destinationCity = txtrd.fields[22];

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header && (txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMFAFLIGHTWAYPOINT)) {
			if (!imeiamfaflightwaypoint.readTxt(txtrd)) return false;

		} else if (txtrd.header || txtrd.data) {
			txtrd.skip = true;
			break;

		} else {
			return false;
		};
	};

	return true;
};

void IexBrlyFlt::ImeitemIMFaflight::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	string srefIxBrlyVIop;

	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "srefIxBrlyVIop", "iop", srefIxBrlyVIop)) {
			ixBrlyVIop = VecBrlyVIop::getIx(srefIxBrlyVIop);
			ixWIelValid += ImeIMFaflight::VecWIel::SREFIXBRLYVIOP;
		};
		if (extractStringUclc(docctx, basexpath, "iLeg", "leg", iLeg)) ixWIelValid += ImeIMFaflight::VecWIel::ILEG;
		if (extractStringUclc(docctx, basexpath, "hintRefBrlyMFlight", "flt", hintRefBrlyMFlight)) ixWIelValid += ImeIMFaflight::VecWIel::HINTREFBRLYMFLIGHT;
		if (extractStringUclc(docctx, basexpath, "faFlightID", "fid", faFlightID)) ixWIelValid += ImeIMFaflight::VecWIel::FAFLIGHTID;
		if (extractStringUclc(docctx, basexpath, "ident", "idt", ident)) ixWIelValid += ImeIMFaflight::VecWIel::IDENT;
		if (extractStringUclc(docctx, basexpath, "aircrafttype", "act", aircrafttype)) ixWIelValid += ImeIMFaflight::VecWIel::AIRCRAFTTYPE;
		if (extractStringUclc(docctx, basexpath, "filed_ete", "fet", filed_ete)) ixWIelValid += ImeIMFaflight::VecWIel::FILED_ETE;
		if (extractUintUclc(docctx, basexpath, "filed_time", "fti", filed_time)) ixWIelValid += ImeIMFaflight::VecWIel::FILED_TIME;
		if (extractUintUclc(docctx, basexpath, "filed_departuretime", "fdt", filed_departuretime)) ixWIelValid += ImeIMFaflight::VecWIel::FILED_DEPARTURETIME;
		if (extractUsmallintUclc(docctx, basexpath, "filed_airspeed_kts", "fsk", filed_airspeed_kts)) ixWIelValid += ImeIMFaflight::VecWIel::FILED_AIRSPEED_KTS;
		if (extractDoubleUclc(docctx, basexpath, "filed_airspeed_mach", "fsm", filed_airspeed_mach)) ixWIelValid += ImeIMFaflight::VecWIel::FILED_AIRSPEED_MACH;
		if (extractUsmallintUclc(docctx, basexpath, "filed_altitude", "fat", filed_altitude)) ixWIelValid += ImeIMFaflight::VecWIel::FILED_ALTITUDE;
		if (extractStringUclc(docctx, basexpath, "route", "rte", route)) ixWIelValid += ImeIMFaflight::VecWIel::ROUTE;
		if (extractUintUclc(docctx, basexpath, "actualdeparturetime", "adt", actualdeparturetime)) ixWIelValid += ImeIMFaflight::VecWIel::ACTUALDEPARTURETIME;
		if (extractUintUclc(docctx, basexpath, "estimatedarrivaltime", "eat", estimatedarrivaltime)) ixWIelValid += ImeIMFaflight::VecWIel::ESTIMATEDARRIVALTIME;
		if (extractUintUclc(docctx, basexpath, "actualarrivaltime", "aat", actualarrivaltime)) ixWIelValid += ImeIMFaflight::VecWIel::ACTUALARRIVALTIME;
		if (extractStringUclc(docctx, basexpath, "diverted", "dvt", diverted)) ixWIelValid += ImeIMFaflight::VecWIel::DIVERTED;
		if (extractStringUclc(docctx, basexpath, "origin", "org", origin)) ixWIelValid += ImeIMFaflight::VecWIel::ORIGIN;
		if (extractStringUclc(docctx, basexpath, "destination", "dst", destination)) ixWIelValid += ImeIMFaflight::VecWIel::DESTINATION;
		if (extractStringUclc(docctx, basexpath, "originName", "onm", originName)) ixWIelValid += ImeIMFaflight::VecWIel::ORIGINNAME;
		if (extractStringUclc(docctx, basexpath, "originCity", "oct", originCity)) ixWIelValid += ImeIMFaflight::VecWIel::ORIGINCITY;
		if (extractStringUclc(docctx, basexpath, "destinationName", "dnm", destinationName)) ixWIelValid += ImeIMFaflight::VecWIel::DESTINATIONNAME;
		if (extractStringUclc(docctx, basexpath, "destinationCity", "dct", destinationCity)) ixWIelValid += ImeIMFaflight::VecWIel::DESTINATIONCITY;
		imeiamfaflightwaypoint.readXML(docctx, basexpath);
	};
};

void IexBrlyFlt::ImeitemIMFaflight::writeTxt(
			fstream& outfile
		) {
	outfile << VecBrlyVIop::getSref(ixBrlyVIop) << "\t" << iLeg << "\t" << hintRefBrlyMFlight << "\t" << faFlightID << "\t" << ident << "\t" << aircrafttype << "\t" << filed_ete << "\t" << filed_time << "\t" << filed_departuretime << "\t" << filed_airspeed_kts << "\t" << filed_airspeed_mach << "\t" << filed_altitude << "\t" << route << "\t" << actualdeparturetime << "\t" << estimatedarrivaltime << "\t" << actualarrivaltime << "\t" << diverted << "\t" << origin << "\t" << destination << "\t" << originName << "\t" << originCity << "\t" << destinationName << "\t" << destinationCity << endl;
	imeiamfaflightwaypoint.writeTxt(outfile);
};

void IexBrlyFlt::ImeitemIMFaflight::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","leg","flt","fid","idt","act","fet","fti","fdt","fsk","fsm","fat","rte","adt","eat","aat","dvt","org","dst","onm","oct","dnm","dct"};
	else tags = {"ImeitemIMFaflight","srefIxBrlyVIop","iLeg","hintRefBrlyMFlight","faFlightID","ident","aircrafttype","filed_ete","filed_time","filed_departuretime","filed_airspeed_kts","filed_airspeed_mach","filed_altitude","route","actualdeparturetime","estimatedarrivaltime","actualarrivaltime","diverted","origin","destination","originName","originCity","destinationName","destinationCity"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecBrlyVIop::getSref(ixBrlyVIop));
		writeString(wr, tags[2], iLeg);
		writeString(wr, tags[3], hintRefBrlyMFlight);
		writeString(wr, tags[4], faFlightID);
		writeString(wr, tags[5], ident);
		writeString(wr, tags[6], aircrafttype);
		writeString(wr, tags[7], filed_ete);
		writeUint(wr, tags[8], filed_time);
		writeUint(wr, tags[9], filed_departuretime);
		writeUsmallint(wr, tags[10], filed_airspeed_kts);
		writeDouble(wr, tags[11], filed_airspeed_mach);
		writeUsmallint(wr, tags[12], filed_altitude);
		writeString(wr, tags[13], route);
		writeUint(wr, tags[14], actualdeparturetime);
		writeUint(wr, tags[15], estimatedarrivaltime);
		writeUint(wr, tags[16], actualarrivaltime);
		writeString(wr, tags[17], diverted);
		writeString(wr, tags[18], origin);
		writeString(wr, tags[19], destination);
		writeString(wr, tags[20], originName);
		writeString(wr, tags[21], originCity);
		writeString(wr, tags[22], destinationName);
		writeString(wr, tags[23], destinationCity);
		imeiamfaflightwaypoint.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyFlt::ImeIMFaflight::VecWIel
 ******************************************************************************/

uint IexBrlyFlt::ImeIMFaflight::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "srefixbrlyviop") ix |= SREFIXBRLYVIOP;
		else if (ss[i] == "ileg") ix |= ILEG;
		else if (ss[i] == "hintrefbrlymflight") ix |= HINTREFBRLYMFLIGHT;
		else if (ss[i] == "faflightid") ix |= FAFLIGHTID;
		else if (ss[i] == "ident") ix |= IDENT;
		else if (ss[i] == "aircrafttype") ix |= AIRCRAFTTYPE;
		else if (ss[i] == "filed_ete") ix |= FILED_ETE;
		else if (ss[i] == "filed_time") ix |= FILED_TIME;
		else if (ss[i] == "filed_departuretime") ix |= FILED_DEPARTURETIME;
		else if (ss[i] == "filed_airspeed_kts") ix |= FILED_AIRSPEED_KTS;
		else if (ss[i] == "filed_airspeed_mach") ix |= FILED_AIRSPEED_MACH;
		else if (ss[i] == "filed_altitude") ix |= FILED_ALTITUDE;
		else if (ss[i] == "route") ix |= ROUTE;
		else if (ss[i] == "actualdeparturetime") ix |= ACTUALDEPARTURETIME;
		else if (ss[i] == "estimatedarrivaltime") ix |= ESTIMATEDARRIVALTIME;
		else if (ss[i] == "actualarrivaltime") ix |= ACTUALARRIVALTIME;
		else if (ss[i] == "diverted") ix |= DIVERTED;
		else if (ss[i] == "origin") ix |= ORIGIN;
		else if (ss[i] == "destination") ix |= DESTINATION;
		else if (ss[i] == "originname") ix |= ORIGINNAME;
		else if (ss[i] == "origincity") ix |= ORIGINCITY;
		else if (ss[i] == "destinationname") ix |= DESTINATIONNAME;
		else if (ss[i] == "destinationcity") ix |= DESTINATIONCITY;
	};

	return(ix);
};

void IexBrlyFlt::ImeIMFaflight::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*DESTINATIONCITY);i*=2) if (ix & i) ics.insert(i);
};

string IexBrlyFlt::ImeIMFaflight::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXBRLYVIOP) ss.push_back("srefIxBrlyVIop");
	if (ix & ILEG) ss.push_back("iLeg");
	if (ix & HINTREFBRLYMFLIGHT) ss.push_back("hintRefBrlyMFlight");
	if (ix & FAFLIGHTID) ss.push_back("faFlightID");
	if (ix & IDENT) ss.push_back("ident");
	if (ix & AIRCRAFTTYPE) ss.push_back("aircrafttype");
	if (ix & FILED_ETE) ss.push_back("filed_ete");
	if (ix & FILED_TIME) ss.push_back("filed_time");
	if (ix & FILED_DEPARTURETIME) ss.push_back("filed_departuretime");
	if (ix & FILED_AIRSPEED_KTS) ss.push_back("filed_airspeed_kts");
	if (ix & FILED_AIRSPEED_MACH) ss.push_back("filed_airspeed_mach");
	if (ix & FILED_ALTITUDE) ss.push_back("filed_altitude");
	if (ix & ROUTE) ss.push_back("route");
	if (ix & ACTUALDEPARTURETIME) ss.push_back("actualdeparturetime");
	if (ix & ESTIMATEDARRIVALTIME) ss.push_back("estimatedarrivaltime");
	if (ix & ACTUALARRIVALTIME) ss.push_back("actualarrivaltime");
	if (ix & DIVERTED) ss.push_back("diverted");
	if (ix & ORIGIN) ss.push_back("origin");
	if (ix & DESTINATION) ss.push_back("destination");
	if (ix & ORIGINNAME) ss.push_back("originName");
	if (ix & ORIGINCITY) ss.push_back("originCity");
	if (ix & DESTINATIONNAME) ss.push_back("destinationName");
	if (ix & DESTINATIONCITY) ss.push_back("destinationCity");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyFlt::ImeIMFaflight
 ******************************************************************************/

IexBrlyFlt::ImeIMFaflight::ImeIMFaflight() {
};

IexBrlyFlt::ImeIMFaflight::~ImeIMFaflight() {
	clear();
};

void IexBrlyFlt::ImeIMFaflight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexBrlyFlt::ImeIMFaflight::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyFlt::ImeitemIMFaflight* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexBrlyFlt::ImeitemIMFaflight();

			if (ii->readTxt(txtrd)) {
				nodes.push_back(ii);
			} else {
				delete ii;
				return false;
			};

		} else {
			return false;
		};
	};

	return true;
};

void IexBrlyFlt::ImeIMFaflight::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyFlt::ImeitemIMFaflight* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFaflight");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFaflight", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFaflight";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyFlt::ImeitemIMFaflight();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyFlt::ImeIMFaflight::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFaflight." << StrMod::replaceChar(ImeIMFaflight::VecWIel::getSrefs(8388607), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexBrlyFlt::ImeIMFaflight::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFaflight");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

