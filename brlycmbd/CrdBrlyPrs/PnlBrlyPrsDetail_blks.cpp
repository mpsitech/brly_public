/**
  * \file PnlBrlyPrsDetail_blks.cpp
  * job handler for job PnlBrlyPrsDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class PnlBrlyPrsDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyPrsDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butjlneditclick") return BUTJLNEDITCLICK;

	return(0);
};

string PnlBrlyPrsDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTJLNEDITCLICK) return("ButJlnEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyPrsDetail::ContIac
 ******************************************************************************/

PnlBrlyPrsDetail::ContIac::ContIac(
			const string& TxfTit
			, const string& TxfFnm
			, const uint numFPupJln
			, const vector<uint>& numsFLstDrv
			, const uint numFPupSex
			, const string& TxfTel
			, const string& TxfEml
			, const string& TxfSal
		) : Block() {
	this->TxfTit = TxfTit;
	this->TxfFnm = TxfFnm;
	this->numFPupJln = numFPupJln;
	this->numsFLstDrv = numsFLstDrv;
	this->numFPupSex = numFPupSex;
	this->TxfTel = TxfTel;
	this->TxfEml = TxfEml;
	this->TxfSal = TxfSal;

	mask = {TXFTIT, TXFFNM, NUMFPUPJLN, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
};

bool PnlBrlyPrsDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyPrsDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyPrsDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTit", TxfTit)) add(TXFTIT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFnm", TxfFnm)) add(TXFFNM);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupJln", numFPupJln)) add(NUMFPUPJLN);
		if (extractUintvecAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numsFLstDrv", numsFLstDrv)) add(NUMSFLSTDRV);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupSex", numFPupSex)) add(NUMFPUPSEX);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfTel", TxfTel)) add(TXFTEL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEml", TxfEml)) add(TXFEML);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSal", TxfSal)) add(TXFSAL);
	};

	return basefound;
};

void PnlBrlyPrsDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfTit", TxfTit);
		writeStringAttr(wr, itemtag, "sref", "TxfFnm", TxfFnm);
		writeUintAttr(wr, itemtag, "sref", "numFPupJln", numFPupJln);
		writeUintvecAttr(wr, itemtag, "sref", "numsFLstDrv", numsFLstDrv);
		writeUintAttr(wr, itemtag, "sref", "numFPupSex", numFPupSex);
		writeStringAttr(wr, itemtag, "sref", "TxfTel", TxfTel);
		writeStringAttr(wr, itemtag, "sref", "TxfEml", TxfEml);
		writeStringAttr(wr, itemtag, "sref", "TxfSal", TxfSal);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyPrsDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfTit == comp->TxfTit) insert(items, TXFTIT);
	if (TxfFnm == comp->TxfFnm) insert(items, TXFFNM);
	if (numFPupJln == comp->numFPupJln) insert(items, NUMFPUPJLN);
	if (compareUintvec(numsFLstDrv, comp->numsFLstDrv)) insert(items, NUMSFLSTDRV);
	if (numFPupSex == comp->numFPupSex) insert(items, NUMFPUPSEX);
	if (TxfTel == comp->TxfTel) insert(items, TXFTEL);
	if (TxfEml == comp->TxfEml) insert(items, TXFEML);
	if (TxfSal == comp->TxfSal) insert(items, TXFSAL);

	return(items);
};

set<uint> PnlBrlyPrsDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFTIT, TXFFNM, NUMFPUPJLN, NUMSFLSTDRV, NUMFPUPSEX, TXFTEL, TXFEML, TXFSAL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyPrsDetail::ContInf
 ******************************************************************************/

PnlBrlyPrsDetail::ContInf::ContInf(
			const string& TxtLnm
			, const string& TxtDrv
		) : Block() {
	this->TxtLnm = TxtLnm;
	this->TxtDrv = TxtDrv;

	mask = {TXTLNM, TXTDRV};
};

void PnlBrlyPrsDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtLnm", TxtLnm);
		writeStringAttr(wr, itemtag, "sref", "TxtDrv", TxtDrv);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyPrsDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtLnm == comp->TxtLnm) insert(items, TXTLNM);
	if (TxtDrv == comp->TxtDrv) insert(items, TXTDRV);

	return(items);
};

set<uint> PnlBrlyPrsDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTLNM, TXTDRV};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyPrsDetail::StatApp
 ******************************************************************************/

void PnlBrlyPrsDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool LstDrvAlt
			, const uint LstDrvNumFirstdisp
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "LstDrvAlt", LstDrvAlt);
		writeUintAttr(wr, itemtag, "sref", "LstDrvNumFirstdisp", LstDrvNumFirstdisp);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyPrsDetail::StatShr
 ******************************************************************************/

PnlBrlyPrsDetail::StatShr::StatShr(
			const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxfTitActive
			, const bool TxfFnmActive
			, const bool PupJlnActive
			, const bool ButJlnEditAvail
			, const bool TxtLnmActive
			, const bool LstDrvActive
			, const bool PupSexActive
			, const bool TxfTelActive
			, const bool TxfEmlActive
			, const bool TxfSalActive
		) : Block() {
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxfTitActive = TxfTitActive;
	this->TxfFnmActive = TxfFnmActive;
	this->PupJlnActive = PupJlnActive;
	this->ButJlnEditAvail = ButJlnEditAvail;
	this->TxtLnmActive = TxtLnmActive;
	this->LstDrvActive = LstDrvActive;
	this->PupSexActive = PupSexActive;
	this->TxfTelActive = TxfTelActive;
	this->TxfEmlActive = TxfEmlActive;
	this->TxfSalActive = TxfSalActive;

	mask = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJLNACTIVE, BUTJLNEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE};
};

void PnlBrlyPrsDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTitActive", TxfTitActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFnmActive", TxfFnmActive);
		writeBoolAttr(wr, itemtag, "sref", "PupJlnActive", PupJlnActive);
		writeBoolAttr(wr, itemtag, "sref", "ButJlnEditAvail", ButJlnEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtLnmActive", TxtLnmActive);
		writeBoolAttr(wr, itemtag, "sref", "LstDrvActive", LstDrvActive);
		writeBoolAttr(wr, itemtag, "sref", "PupSexActive", PupSexActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfTelActive", TxfTelActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfEmlActive", TxfEmlActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfSalActive", TxfSalActive);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyPrsDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxfTitActive == comp->TxfTitActive) insert(items, TXFTITACTIVE);
	if (TxfFnmActive == comp->TxfFnmActive) insert(items, TXFFNMACTIVE);
	if (PupJlnActive == comp->PupJlnActive) insert(items, PUPJLNACTIVE);
	if (ButJlnEditAvail == comp->ButJlnEditAvail) insert(items, BUTJLNEDITAVAIL);
	if (TxtLnmActive == comp->TxtLnmActive) insert(items, TXTLNMACTIVE);
	if (LstDrvActive == comp->LstDrvActive) insert(items, LSTDRVACTIVE);
	if (PupSexActive == comp->PupSexActive) insert(items, PUPSEXACTIVE);
	if (TxfTelActive == comp->TxfTelActive) insert(items, TXFTELACTIVE);
	if (TxfEmlActive == comp->TxfEmlActive) insert(items, TXFEMLACTIVE);
	if (TxfSalActive == comp->TxfSalActive) insert(items, TXFSALACTIVE);

	return(items);
};

set<uint> PnlBrlyPrsDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTSAVEAVAIL, BUTSAVEACTIVE, TXFTITACTIVE, TXFFNMACTIVE, PUPJLNACTIVE, BUTJLNEDITAVAIL, TXTLNMACTIVE, LSTDRVACTIVE, PUPSEXACTIVE, TXFTELACTIVE, TXFEMLACTIVE, TXFSALACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyPrsDetail::Tag
 ******************************************************************************/

void PnlBrlyPrsDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyPrsDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyPrsDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Title");
			writeStringAttr(wr, itemtag, "sref", "CptFnm", "first name");
			writeStringAttr(wr, itemtag, "sref", "CptLnm", "last name");
			writeStringAttr(wr, itemtag, "sref", "CptDrv", "derivates");
			writeStringAttr(wr, itemtag, "sref", "CptSex", "sex");
			writeStringAttr(wr, itemtag, "sref", "CptTel", "phone");
			writeStringAttr(wr, itemtag, "sref", "CptEml", "e-mail");
			writeStringAttr(wr, itemtag, "sref", "CptSal", "salutation");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptTit", "Title");
			writeStringAttr(wr, itemtag, "sref", "CptFnm", "Vorname");
			writeStringAttr(wr, itemtag, "sref", "CptLnm", "Nachname");
			writeStringAttr(wr, itemtag, "sref", "CptDrv", "Abwandlungen");
			writeStringAttr(wr, itemtag, "sref", "CptSex", "sex");
			writeStringAttr(wr, itemtag, "sref", "CptTel", "Telefon");
			writeStringAttr(wr, itemtag, "sref", "CptEml", "E-Mail");
			writeStringAttr(wr, itemtag, "sref", "CptSal", "Briefanrede");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyPrsDetail::DpchAppData
 ******************************************************************************/

PnlBrlyPrsDetail::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYPRSDETAILDATA) {
};

string PnlBrlyPrsDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyPrsDetail::DpchAppData::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyPrsDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
	} else {
		contiac = ContIac();
	};
};

/******************************************************************************
 class PnlBrlyPrsDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyPrsDetail::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYPRSDETAILDO) {
	ixVDo = 0;
};

string PnlBrlyPrsDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyPrsDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyPrsDetailDo");
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
 class PnlBrlyPrsDetail::DpchEngData
 ******************************************************************************/

PnlBrlyPrsDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFLstDrv
			, Feed* feedFPupJln
			, Feed* feedFPupSex
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYPRSDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFLSTDRV, FEEDFPUPJLN, FEEDFPUPSEX, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFLSTDRV) && feedFLstDrv) this->feedFLstDrv = *feedFLstDrv;
	if (find(this->mask, FEEDFPUPJLN) && feedFPupJln) this->feedFPupJln = *feedFPupJln;
	if (find(this->mask, FEEDFPUPSEX) && feedFPupSex) this->feedFPupSex = *feedFPupSex;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyPrsDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFLSTDRV)) ss.push_back("feedFLstDrv");
	if (has(FEEDFPUPJLN)) ss.push_back("feedFPupJln");
	if (has(FEEDFPUPSEX)) ss.push_back("feedFPupSex");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyPrsDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFLSTDRV)) {feedFLstDrv = src->feedFLstDrv; add(FEEDFLSTDRV);};
	if (src->has(FEEDFPUPJLN)) {feedFPupJln = src->feedFPupJln; add(FEEDFPUPJLN);};
	if (src->has(FEEDFPUPSEX)) {feedFPupSex = src->feedFPupSex; add(FEEDFPUPSEX);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyPrsDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyPrsDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFLSTDRV)) feedFLstDrv.writeXML(wr);
		if (has(FEEDFPUPJLN)) feedFPupJln.writeXML(wr);
		if (has(FEEDFPUPSEX)) feedFPupSex.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

