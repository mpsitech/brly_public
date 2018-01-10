/**
  * \file CrdBrlyNav_blks.cpp
  * job handler for job CrdBrlyNav (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class CrdBrlyNav::VecVDo
 ******************************************************************************/

uint CrdBrlyNav::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "close") return CLOSE;
	else if (s == "mitappabtclick") return MITAPPABTCLICK;
	else if (s == "mitsestrmclick") return MITSESTRMCLICK;
	else if (s == "mitcrdusgclick") return MITCRDUSGCLICK;
	else if (s == "mitcrdusrclick") return MITCRDUSRCLICK;
	else if (s == "mitcrdprsclick") return MITCRDPRSCLICK;
	else if (s == "mitcrdfilclick") return MITCRDFILCLICK;
	else if (s == "mitcrdoprclick") return MITCRDOPRCLICK;
	else if (s == "mitcrdptyclick") return MITCRDPTYCLICK;
	else if (s == "mitcrdregclick") return MITCRDREGCLICK;
	else if (s == "mitcrdlocclick") return MITCRDLOCCLICK;
	else if (s == "mitcrdlegclick") return MITCRDLEGCLICK;
	else if (s == "mitcrdttbclick") return MITCRDTTBCLICK;
	else if (s == "mitcrdfltclick") return MITCRDFLTCLICK;
	else if (s == "mitcrdconclick") return MITCRDCONCLICK;
	else if (s == "mitapploiclick") return MITAPPLOICLICK;

	return(0);
};

string CrdBrlyNav::VecVDo::getSref(
			const uint ix
		) {
	if (ix == CLOSE) return("close");
	else if (ix == MITAPPABTCLICK) return("MitAppAbtClick");
	else if (ix == MITSESTRMCLICK) return("MitSesTrmClick");
	else if (ix == MITCRDUSGCLICK) return("MitCrdUsgClick");
	else if (ix == MITCRDUSRCLICK) return("MitCrdUsrClick");
	else if (ix == MITCRDPRSCLICK) return("MitCrdPrsClick");
	else if (ix == MITCRDFILCLICK) return("MitCrdFilClick");
	else if (ix == MITCRDOPRCLICK) return("MitCrdOprClick");
	else if (ix == MITCRDPTYCLICK) return("MitCrdPtyClick");
	else if (ix == MITCRDREGCLICK) return("MitCrdRegClick");
	else if (ix == MITCRDLOCCLICK) return("MitCrdLocClick");
	else if (ix == MITCRDLEGCLICK) return("MitCrdLegClick");
	else if (ix == MITCRDTTBCLICK) return("MitCrdTtbClick");
	else if (ix == MITCRDFLTCLICK) return("MitCrdFltClick");
	else if (ix == MITCRDCONCLICK) return("MitCrdConClick");
	else if (ix == MITAPPLOICLICK) return("MitAppLoiClick");

	return("");
};

/******************************************************************************
 class CrdBrlyNav::VecVSge
 ******************************************************************************/

uint CrdBrlyNav::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	else if (s == "alrbrlyabt") return ALRBRLYABT;
	else if (s == "close") return CLOSE;

	return(0);
};

string CrdBrlyNav::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	else if (ix == ALRBRLYABT) return("alrbrlyabt");
	else if (ix == CLOSE) return("close");

	return("");
};

void CrdBrlyNav::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class CrdBrlyNav::ContInf
 ******************************************************************************/

CrdBrlyNav::ContInf::ContInf(
			const uint numFSge
			, const string& MrlAppHlp
			, const string& MtxSesSes1
			, const string& MtxSesSes2
			, const string& MtxSesSes3
		) : Block() {
	this->numFSge = numFSge;
	this->MrlAppHlp = MrlAppHlp;
	this->MtxSesSes1 = MtxSesSes1;
	this->MtxSesSes2 = MtxSesSes2;
	this->MtxSesSes3 = MtxSesSes3;

	mask = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
};

void CrdBrlyNav::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyNav";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUintAttr(wr, itemtag, "sref", "numFSge", numFSge);
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", MrlAppHlp);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes1", MtxSesSes1);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes2", MtxSesSes2);
		writeStringAttr(wr, itemtag, "sref", "MtxSesSes3", MtxSesSes3);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdBrlyNav::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (numFSge == comp->numFSge) insert(items, NUMFSGE);
	if (MrlAppHlp == comp->MrlAppHlp) insert(items, MRLAPPHLP);
	if (MtxSesSes1 == comp->MtxSesSes1) insert(items, MTXSESSES1);
	if (MtxSesSes2 == comp->MtxSesSes2) insert(items, MTXSESSES2);
	if (MtxSesSes3 == comp->MtxSesSes3) insert(items, MTXSESSES3);

	return(items);
};

set<uint> CrdBrlyNav::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {NUMFSGE, MRLAPPHLP, MTXSESSES1, MTXSESSES2, MTXSESSES3};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyNav::StatApp
 ******************************************************************************/

void CrdBrlyNav::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVReqitmode
			, const usmallint latency
			, const string& shortMenu
			, const uint widthMenu
			, const bool initdoneHeadbar
			, const bool initdoneAdmin
			, const bool initdoneBase
			, const bool initdoneConnect
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVReqitmode", VecBrlyVReqitmode::getSref(ixBrlyVReqitmode));
		writeUsmallintAttr(wr, itemtag, "sref", "latency", latency);
		writeStringAttr(wr, itemtag, "sref", "shortMenu", shortMenu);
		writeUintAttr(wr, itemtag, "sref", "widthMenu", widthMenu);
		writeBoolAttr(wr, itemtag, "sref", "initdoneHeadbar", initdoneHeadbar);
		writeBoolAttr(wr, itemtag, "sref", "initdoneAdmin", initdoneAdmin);
		writeBoolAttr(wr, itemtag, "sref", "initdoneBase", initdoneBase);
		writeBoolAttr(wr, itemtag, "sref", "initdoneConnect", initdoneConnect);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyNav::StatShr
 ******************************************************************************/

CrdBrlyNav::StatShr::StatShr(
			const ubigint jrefDlgloaini
			, const ubigint jrefHeadbar
			, const ubigint jrefAdmin
			, const bool pnladminAvail
			, const ubigint jrefBase
			, const bool pnlbaseAvail
			, const ubigint jrefConnect
			, const bool pnlconnectAvail
			, const bool MspCrd1Avail
			, const bool MitCrdUsgAvail
			, const bool MitCrdUsrAvail
			, const bool MitCrdPrsAvail
			, const bool MitCrdFilAvail
			, const bool MitCrdOprAvail
			, const bool MitCrdPtyAvail
			, const bool MspCrd2Avail
			, const bool MitCrdRegAvail
			, const bool MitCrdLocAvail
			, const bool MitCrdLegAvail
			, const bool MitCrdTtbAvail
			, const bool MitCrdFltAvail
			, const bool MspCrd3Avail
			, const bool MitCrdConAvail
			, const bool MspApp2Avail
			, const bool MitAppLoiAvail
		) : Block() {
	this->jrefDlgloaini = jrefDlgloaini;
	this->jrefHeadbar = jrefHeadbar;
	this->jrefAdmin = jrefAdmin;
	this->pnladminAvail = pnladminAvail;
	this->jrefBase = jrefBase;
	this->pnlbaseAvail = pnlbaseAvail;
	this->jrefConnect = jrefConnect;
	this->pnlconnectAvail = pnlconnectAvail;
	this->MspCrd1Avail = MspCrd1Avail;
	this->MitCrdUsgAvail = MitCrdUsgAvail;
	this->MitCrdUsrAvail = MitCrdUsrAvail;
	this->MitCrdPrsAvail = MitCrdPrsAvail;
	this->MitCrdFilAvail = MitCrdFilAvail;
	this->MitCrdOprAvail = MitCrdOprAvail;
	this->MitCrdPtyAvail = MitCrdPtyAvail;
	this->MspCrd2Avail = MspCrd2Avail;
	this->MitCrdRegAvail = MitCrdRegAvail;
	this->MitCrdLocAvail = MitCrdLocAvail;
	this->MitCrdLegAvail = MitCrdLegAvail;
	this->MitCrdTtbAvail = MitCrdTtbAvail;
	this->MitCrdFltAvail = MitCrdFltAvail;
	this->MspCrd3Avail = MspCrd3Avail;
	this->MitCrdConAvail = MitCrdConAvail;
	this->MspApp2Avail = MspApp2Avail;
	this->MitAppLoiAvail = MitAppLoiAvail;

	mask = {JREFDLGLOAINI, JREFHEADBAR, JREFADMIN, PNLADMINAVAIL, JREFBASE, PNLBASEAVAIL, JREFCONNECT, PNLCONNECTAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MITCRDOPRAVAIL, MITCRDPTYAVAIL, MSPCRD2AVAIL, MITCRDREGAVAIL, MITCRDLOCAVAIL, MITCRDLEGAVAIL, MITCRDTTBAVAIL, MITCRDFLTAVAIL, MSPCRD3AVAIL, MITCRDCONAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
};

void CrdBrlyNav::StatShr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyNav";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "scrJrefDlgloaini", Scr::scramble(mScr, scr, descr, jrefDlgloaini));
		writeStringAttr(wr, itemtag, "sref", "scrJrefHeadbar", Scr::scramble(mScr, scr, descr, jrefHeadbar));
		writeStringAttr(wr, itemtag, "sref", "scrJrefAdmin", Scr::scramble(mScr, scr, descr, jrefAdmin));
		writeBoolAttr(wr, itemtag, "sref", "pnladminAvail", pnladminAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefBase", Scr::scramble(mScr, scr, descr, jrefBase));
		writeBoolAttr(wr, itemtag, "sref", "pnlbaseAvail", pnlbaseAvail);
		writeStringAttr(wr, itemtag, "sref", "scrJrefConnect", Scr::scramble(mScr, scr, descr, jrefConnect));
		writeBoolAttr(wr, itemtag, "sref", "pnlconnectAvail", pnlconnectAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd1Avail", MspCrd1Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsgAvail", MitCrdUsgAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdUsrAvail", MitCrdUsrAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPrsAvail", MitCrdPrsAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFilAvail", MitCrdFilAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdOprAvail", MitCrdOprAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdPtyAvail", MitCrdPtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd2Avail", MspCrd2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdRegAvail", MitCrdRegAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLocAvail", MitCrdLocAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdLegAvail", MitCrdLegAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdTtbAvail", MitCrdTtbAvail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdFltAvail", MitCrdFltAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspCrd3Avail", MspCrd3Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitCrdConAvail", MitCrdConAvail);
		writeBoolAttr(wr, itemtag, "sref", "MspApp2Avail", MspApp2Avail);
		writeBoolAttr(wr, itemtag, "sref", "MitAppLoiAvail", MitAppLoiAvail);
	xmlTextWriterEndElement(wr);
};

set<uint> CrdBrlyNav::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (jrefDlgloaini == comp->jrefDlgloaini) insert(items, JREFDLGLOAINI);
	if (jrefHeadbar == comp->jrefHeadbar) insert(items, JREFHEADBAR);
	if (jrefAdmin == comp->jrefAdmin) insert(items, JREFADMIN);
	if (pnladminAvail == comp->pnladminAvail) insert(items, PNLADMINAVAIL);
	if (jrefBase == comp->jrefBase) insert(items, JREFBASE);
	if (pnlbaseAvail == comp->pnlbaseAvail) insert(items, PNLBASEAVAIL);
	if (jrefConnect == comp->jrefConnect) insert(items, JREFCONNECT);
	if (pnlconnectAvail == comp->pnlconnectAvail) insert(items, PNLCONNECTAVAIL);
	if (MspCrd1Avail == comp->MspCrd1Avail) insert(items, MSPCRD1AVAIL);
	if (MitCrdUsgAvail == comp->MitCrdUsgAvail) insert(items, MITCRDUSGAVAIL);
	if (MitCrdUsrAvail == comp->MitCrdUsrAvail) insert(items, MITCRDUSRAVAIL);
	if (MitCrdPrsAvail == comp->MitCrdPrsAvail) insert(items, MITCRDPRSAVAIL);
	if (MitCrdFilAvail == comp->MitCrdFilAvail) insert(items, MITCRDFILAVAIL);
	if (MitCrdOprAvail == comp->MitCrdOprAvail) insert(items, MITCRDOPRAVAIL);
	if (MitCrdPtyAvail == comp->MitCrdPtyAvail) insert(items, MITCRDPTYAVAIL);
	if (MspCrd2Avail == comp->MspCrd2Avail) insert(items, MSPCRD2AVAIL);
	if (MitCrdRegAvail == comp->MitCrdRegAvail) insert(items, MITCRDREGAVAIL);
	if (MitCrdLocAvail == comp->MitCrdLocAvail) insert(items, MITCRDLOCAVAIL);
	if (MitCrdLegAvail == comp->MitCrdLegAvail) insert(items, MITCRDLEGAVAIL);
	if (MitCrdTtbAvail == comp->MitCrdTtbAvail) insert(items, MITCRDTTBAVAIL);
	if (MitCrdFltAvail == comp->MitCrdFltAvail) insert(items, MITCRDFLTAVAIL);
	if (MspCrd3Avail == comp->MspCrd3Avail) insert(items, MSPCRD3AVAIL);
	if (MitCrdConAvail == comp->MitCrdConAvail) insert(items, MITCRDCONAVAIL);
	if (MspApp2Avail == comp->MspApp2Avail) insert(items, MSPAPP2AVAIL);
	if (MitAppLoiAvail == comp->MitAppLoiAvail) insert(items, MITAPPLOIAVAIL);

	return(items);
};

set<uint> CrdBrlyNav::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JREFDLGLOAINI, JREFHEADBAR, JREFADMIN, PNLADMINAVAIL, JREFBASE, PNLBASEAVAIL, JREFCONNECT, PNLCONNECTAVAIL, MSPCRD1AVAIL, MITCRDUSGAVAIL, MITCRDUSRAVAIL, MITCRDPRSAVAIL, MITCRDFILAVAIL, MITCRDOPRAVAIL, MITCRDPTYAVAIL, MSPCRD2AVAIL, MITCRDREGAVAIL, MITCRDLOCAVAIL, MITCRDLEGAVAIL, MITCRDTTBAVAIL, MITCRDFLTAVAIL, MSPCRD3AVAIL, MITCRDCONAVAIL, MSPAPP2AVAIL, MITAPPLOIAVAIL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class CrdBrlyNav::Tag
 ******************************************************************************/

void CrdBrlyNav::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyNav";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyNav";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "User groups ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Users ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Persons ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Files ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOpr", "Operators ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPty", "Plane types ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdReg", "Regions ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLoc", "Locations ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLeg", "Legs ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTtb", "Timetables ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFlt", "Flights ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCon", "Connections ...");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsg", "Benutzergruppen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdUsr", "Benutzer ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPrs", "Personen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFil", "Dateien ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdOpr", "Betreiber ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdPty", "Flugzeugtypen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdReg", "Regionen ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLoc", "Orte ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdLeg", "Strecken ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdTtb", "Flugpl\\u00e4ne ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdFlt", "Fl\\u00fcge ...");
			writeStringAttr(wr, itemtag, "sref", "MitCrdCon", "Verbindungen ...");
		};
		writeStringAttr(wr, itemtag, "sref", "MitAppAbt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::ABOUT, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MrlAppHlp", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::HELP, ixBrlyVLocale)) + " ...");
		writeStringAttr(wr, itemtag, "sref", "MitSesTrm", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::CLSESS, ixBrlyVLocale)));
		writeStringAttr(wr, itemtag, "sref", "MitAppLoi", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::LOAINI, ixBrlyVLocale)) + " ...");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class CrdBrlyNav::DpchAppDo
 ******************************************************************************/

CrdBrlyNav::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYNAVDO) {
	ixVDo = 0;
};

string CrdBrlyNav::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyNav::DpchAppDo::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;
	string srefIxVDo;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyNavDo");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxVDo", "", srefIxVDo)) {
			ixVDo = VecVDo::getIx(srefIxVDo);
			add(IXVDO);
		};
	} else {
	};
};

/******************************************************************************
 class CrdBrlyNav::DpchEngData
 ******************************************************************************/

CrdBrlyNav::DpchEngData::DpchEngData(
			const ubigint jref
			, ContInf* continf
			, Feed* feedFSge
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYNAVDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFSGE, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFSGE) && feedFSge) this->feedFSge = *feedFSge;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string CrdBrlyNav::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFSGE)) ss.push_back("feedFSge");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void CrdBrlyNav::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFSGE)) {feedFSge = src->feedFSge; add(FEEDFSGE);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void CrdBrlyNav::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyNavData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFSGE)) feedFSge.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(mScr, scr, descr, wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

