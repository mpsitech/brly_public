/**
  * \file IexBrlyTtb_blks.cpp
  * import/export handler for database DbsBrly (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class IexBrlyTtb::VecVIme
 ******************************************************************************/

uint IexBrlyTtb::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimflight") return IMEIMFLIGHT;
	else if (s == "imeimleg") return IMEIMLEG;

	return(0);
};

string IexBrlyTtb::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMFLIGHT) return("ImeIMFlight");
	else if (ix == IMEIMLEG) return("ImeIMLeg");

	return("");
};

/******************************************************************************
 class IexBrlyTtb::ImeitemIMFlight
 ******************************************************************************/

IexBrlyTtb::ImeitemIMFlight::ImeitemIMFlight(
			const string& hintRefBrlyMEquipment
			, const ubigint irefRefBrlyMLeg
			, const string& sref
			, const string& hintStart
			, const string& hintStop
			, const string& iDate
			, const string& iWeekday
		) : BrlyMFlight() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefBrlyMEquipment = hintRefBrlyMEquipment;
	this->irefRefBrlyMLeg = irefRefBrlyMLeg;
	this->sref = sref;
	this->hintStart = hintStart;
	this->hintStop = hintStop;
	this->iDate = iDate;
	this->iWeekday = iWeekday;
};

IexBrlyTtb::ImeitemIMFlight::ImeitemIMFlight(
			DbsBrly* dbsbrly
			, const ubigint ref
		) : ImeitemIMFlight() {
	BrlyMFlight* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymflight->loadRecByRef(ref, &rec)) {
		refBrlyMTimetable = rec->refBrlyMTimetable;
		refBrlyMEquipment = rec->refBrlyMEquipment;
		refBrlyMLeg = rec->refBrlyMLeg;
		sref = rec->sref;
		start = rec->start;
		stop = rec->stop;
		Calcdone = rec->Calcdone;

		delete rec;
	};
};

bool IexBrlyTtb::ImeitemIMFlight::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) hintRefBrlyMEquipment = txtrd.fields[0];
	if (txtrd.fields.size() > 1) irefRefBrlyMLeg = atoll(txtrd.fields[1].c_str());
	if (txtrd.fields.size() > 2) sref = txtrd.fields[2];
	if (txtrd.fields.size() > 3) hintStart = txtrd.fields[3];
	if (txtrd.fields.size() > 4) hintStop = txtrd.fields[4];
	if (txtrd.fields.size() > 5) iDate = txtrd.fields[5];
	if (txtrd.fields.size() > 6) iWeekday = txtrd.fields[6];

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

void IexBrlyTtb::ImeitemIMFlight::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractStringUclc(docctx, basexpath, "hintRefBrlyMEquipment", "eqp", hintRefBrlyMEquipment)) ixWIelValid += ImeIMFlight::VecWIel::HINTREFBRLYMEQUIPMENT;
		if (extractUbigintUclc(docctx, basexpath, "irefRefBrlyMLeg", "leg", irefRefBrlyMLeg)) ixWIelValid += ImeIMFlight::VecWIel::IREFREFBRLYMLEG;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMFlight::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "hintStart", "sta", hintStart)) ixWIelValid += ImeIMFlight::VecWIel::HINTSTART;
		if (extractStringUclc(docctx, basexpath, "hintStop", "sto", hintStop)) ixWIelValid += ImeIMFlight::VecWIel::HINTSTOP;
		if (extractStringUclc(docctx, basexpath, "iDate", "dte", iDate)) ixWIelValid += ImeIMFlight::VecWIel::IDATE;
		if (extractStringUclc(docctx, basexpath, "iWeekday", "wdy", iWeekday)) ixWIelValid += ImeIMFlight::VecWIel::IWEEKDAY;
	};
};

void IexBrlyTtb::ImeitemIMFlight::writeTxt(
			fstream& outfile
		) {
	outfile << hintRefBrlyMEquipment << "\t" << irefRefBrlyMLeg << "\t" << sref << "\t" << hintStart << "\t" << hintStop << "\t" << iDate << "\t" << iWeekday << endl;
};

void IexBrlyTtb::ImeitemIMFlight::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","eqp","leg","srf","sta","sto","dte","wdy"};
	else tags = {"ImeitemIMFlight","hintRefBrlyMEquipment","irefRefBrlyMLeg","sref","hintStart","hintStop","iDate","iWeekday"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefBrlyMEquipment);
		writeUbigint(wr, tags[2], irefRefBrlyMLeg);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], hintStart);
		writeString(wr, tags[5], hintStop);
		writeString(wr, tags[6], iDate);
		writeString(wr, tags[7], iWeekday);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyTtb::ImeIMFlight::VecWIel
 ******************************************************************************/

uint IexBrlyTtb::ImeIMFlight::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "hintrefbrlymequipment") ix |= HINTREFBRLYMEQUIPMENT;
		else if (ss[i] == "irefrefbrlymleg") ix |= IREFREFBRLYMLEG;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "hintstart") ix |= HINTSTART;
		else if (ss[i] == "hintstop") ix |= HINTSTOP;
		else if (ss[i] == "idate") ix |= IDATE;
		else if (ss[i] == "iweekday") ix |= IWEEKDAY;
	};

	return(ix);
};

void IexBrlyTtb::ImeIMFlight::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*IWEEKDAY);i*=2) if (ix & i) ics.insert(i);
};

string IexBrlyTtb::ImeIMFlight::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFBRLYMEQUIPMENT) ss.push_back("hintRefBrlyMEquipment");
	if (ix & IREFREFBRLYMLEG) ss.push_back("irefRefBrlyMLeg");
	if (ix & SREF) ss.push_back("sref");
	if (ix & HINTSTART) ss.push_back("hintStart");
	if (ix & HINTSTOP) ss.push_back("hintStop");
	if (ix & IDATE) ss.push_back("iDate");
	if (ix & IWEEKDAY) ss.push_back("iWeekday");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyTtb::ImeIMFlight
 ******************************************************************************/

IexBrlyTtb::ImeIMFlight::ImeIMFlight() {
};

IexBrlyTtb::ImeIMFlight::~ImeIMFlight() {
	clear();
};

void IexBrlyTtb::ImeIMFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexBrlyTtb::ImeIMFlight::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyTtb::ImeitemIMFlight* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexBrlyTtb::ImeitemIMFlight();

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

void IexBrlyTtb::ImeIMFlight::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyTtb::ImeitemIMFlight* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFlight");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFlight", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFlight";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyTtb::ImeitemIMFlight();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyTtb::ImeIMFlight::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFlight." << StrMod::replaceChar(ImeIMFlight::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexBrlyTtb::ImeIMFlight::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFlight");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexBrlyTtb::ImeitemIMLeg
 ******************************************************************************/

IexBrlyTtb::ImeitemIMLeg::ImeitemIMLeg(
			const ubigint iref
			, const string& srefBgnRefBrlyMLocation
			, const string& srefEndRefBrlyMLocation
		) : BrlyMLeg() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->srefBgnRefBrlyMLocation = srefBgnRefBrlyMLocation;
	this->srefEndRefBrlyMLocation = srefEndRefBrlyMLocation;
};

IexBrlyTtb::ImeitemIMLeg::ImeitemIMLeg(
			DbsBrly* dbsbrly
			, const ubigint ref
		) : ImeitemIMLeg() {
	BrlyMLeg* rec = NULL;

	this->ref = ref;

	if (dbsbrly->tblbrlymleg->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		bgnRefBrlyMLocation = rec->bgnRefBrlyMLocation;
		endRefBrlyMLocation = rec->endRefBrlyMLocation;
		alt = rec->alt;
		deltaphi = rec->deltaphi;
		alpha = rec->alpha;
		Calcdone = rec->Calcdone;

		delete rec;
	};
};

bool IexBrlyTtb::ImeitemIMLeg::readTxt(
			Txtrd& txtrd
		) {
	this->lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) iref = atoll(txtrd.fields[0].c_str());
	if (txtrd.fields.size() > 1) srefBgnRefBrlyMLocation = txtrd.fields[1];
	if (txtrd.fields.size() > 2) srefEndRefBrlyMLocation = txtrd.fields[2];

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

void IexBrlyTtb::ImeitemIMLeg::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	ixWIelValid = 0;

	if (checkXPath(docctx, basexpath)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMLeg::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefBgnRefBrlyMLocation", "bgn", srefBgnRefBrlyMLocation)) ixWIelValid += ImeIMLeg::VecWIel::SREFBGNREFBRLYMLOCATION;
		if (extractStringUclc(docctx, basexpath, "srefEndRefBrlyMLocation", "end", srefEndRefBrlyMLocation)) ixWIelValid += ImeIMLeg::VecWIel::SREFENDREFBRLYMLOCATION;
	};
};

void IexBrlyTtb::ImeitemIMLeg::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << srefBgnRefBrlyMLocation << "\t" << srefEndRefBrlyMLocation << endl;
};

void IexBrlyTtb::ImeitemIMLeg::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","bgn","end"};
	else tags = {"ImeitemIMLeg","iref","srefBgnRefBrlyMLocation","srefEndRefBrlyMLocation"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], srefBgnRefBrlyMLocation);
		writeString(wr, tags[3], srefEndRefBrlyMLocation);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexBrlyTtb::ImeIMLeg::VecWIel
 ******************************************************************************/

uint IexBrlyTtb::ImeIMLeg::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefbgnrefbrlymlocation") ix |= SREFBGNREFBRLYMLOCATION;
		else if (ss[i] == "srefendrefbrlymlocation") ix |= SREFENDREFBRLYMLOCATION;
	};

	return(ix);
};

void IexBrlyTtb::ImeIMLeg::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*SREFENDREFBRLYMLOCATION);i*=2) if (ix & i) ics.insert(i);
};

string IexBrlyTtb::ImeIMLeg::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFBGNREFBRLYMLOCATION) ss.push_back("srefBgnRefBrlyMLocation");
	if (ix & SREFENDREFBRLYMLOCATION) ss.push_back("srefEndRefBrlyMLocation");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexBrlyTtb::ImeIMLeg
 ******************************************************************************/

IexBrlyTtb::ImeIMLeg::ImeIMLeg() {
};

IexBrlyTtb::ImeIMLeg::~ImeIMLeg() {
	clear();
};

void IexBrlyTtb::ImeIMLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

bool IexBrlyTtb::ImeIMLeg::readTxt(
			Txtrd& txtrd
		) {
	IexBrlyTtb::ImeitemIMLeg* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		if (txtrd.comment) {

		} else if (txtrd.header) {
			txtrd.skip = true;
			break;

		} else if (txtrd.data && (txtrd.il == 0)) {
			ii = new IexBrlyTtb::ImeitemIMLeg();

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

void IexBrlyTtb::ImeIMLeg::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexBrlyTtb::ImeitemIMLeg* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMLeg");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMLeg", "Ii", "num", nums, _shorttags);

		for (unsigned int i=0;i<nums.size();i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMLeg";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexBrlyTtb::ImeitemIMLeg();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexBrlyTtb::ImeIMLeg::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMLeg." << StrMod::replaceChar(ImeIMLeg::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeTxt(outfile);
	};
};

void IexBrlyTtb::ImeIMLeg::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMLeg");
			for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

