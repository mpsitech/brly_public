/**
  * \file PnlBrlyFltDetail.cpp
  * API code for job PnlBrlyFltDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "PnlBrlyFltDetail.h"

/******************************************************************************
 class PnlBrlyFltDetail::VecVDo
 ******************************************************************************/

uint PnlBrlyFltDetail::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butsaveclick") return BUTSAVECLICK;
	else if (s == "butttbviewclick") return BUTTTBVIEWCLICK;
	else if (s == "butfafnewclick") return BUTFAFNEWCLICK;
	else if (s == "butfafdeleteclick") return BUTFAFDELETECLICK;
	else if (s == "buteqpnewclick") return BUTEQPNEWCLICK;
	else if (s == "buteqpdeleteclick") return BUTEQPDELETECLICK;
	else if (s == "buteqpoprviewclick") return BUTEQPOPRVIEWCLICK;
	else if (s == "buteqpptyviewclick") return BUTEQPPTYVIEWCLICK;
	else if (s == "buteqpetyeditclick") return BUTEQPETYEDITCLICK;

	return(0);
};

string PnlBrlyFltDetail::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTSAVECLICK) return("ButSaveClick");
	else if (ix == BUTTTBVIEWCLICK) return("ButTtbViewClick");
	else if (ix == BUTFAFNEWCLICK) return("ButFafNewClick");
	else if (ix == BUTFAFDELETECLICK) return("ButFafDeleteClick");
	else if (ix == BUTEQPNEWCLICK) return("ButEqpNewClick");
	else if (ix == BUTEQPDELETECLICK) return("ButEqpDeleteClick");
	else if (ix == BUTEQPOPRVIEWCLICK) return("ButEqpOprViewClick");
	else if (ix == BUTEQPPTYVIEWCLICK) return("ButEqpPtyViewClick");
	else if (ix == BUTEQPETYEDITCLICK) return("ButEqpEtyEditClick");

	return("");
};

/******************************************************************************
 class PnlBrlyFltDetail::ContIac
 ******************************************************************************/

PnlBrlyFltDetail::ContIac::ContIac(
			const string& TxfSta
			, const string& TxfSto
			, const string& TxfXsa
			, const string& TxfXso
			, const bool ChkCdn
			, const bool ChkSdn
			, const string& TxfFafFid
			, const string& TxfFafIdt
			, const string& TxfFafAct
			, const string& TxfFafFet
			, const string& TxfFafFti
			, const string& TxfFafFdt
			, const string& TxfFafFsk
			, const string& TxfFafFsm
			, const string& TxfFafFat
			, const string& TxfFafRte
			, const string& TxfFafAdt
			, const string& TxfFafEat
			, const string& TxfFafAat
			, const string& TxfFafDvt
			, const string& TxfFafOrg
			, const string& TxfFafDst
			, const string& TxfFafOnm
			, const string& TxfFafOct
			, const string& TxfFafDnm
			, const string& TxfFafDct
			, const uint numFPupEqpEty
			, const string& TxfEqpEty
			, const bool ChkEqpFib
		) : Block() {
	this->TxfSta = TxfSta;
	this->TxfSto = TxfSto;
	this->TxfXsa = TxfXsa;
	this->TxfXso = TxfXso;
	this->ChkCdn = ChkCdn;
	this->ChkSdn = ChkSdn;
	this->TxfFafFid = TxfFafFid;
	this->TxfFafIdt = TxfFafIdt;
	this->TxfFafAct = TxfFafAct;
	this->TxfFafFet = TxfFafFet;
	this->TxfFafFti = TxfFafFti;
	this->TxfFafFdt = TxfFafFdt;
	this->TxfFafFsk = TxfFafFsk;
	this->TxfFafFsm = TxfFafFsm;
	this->TxfFafFat = TxfFafFat;
	this->TxfFafRte = TxfFafRte;
	this->TxfFafAdt = TxfFafAdt;
	this->TxfFafEat = TxfFafEat;
	this->TxfFafAat = TxfFafAat;
	this->TxfFafDvt = TxfFafDvt;
	this->TxfFafOrg = TxfFafOrg;
	this->TxfFafDst = TxfFafDst;
	this->TxfFafOnm = TxfFafOnm;
	this->TxfFafOct = TxfFafOct;
	this->TxfFafDnm = TxfFafDnm;
	this->TxfFafDct = TxfFafDct;
	this->numFPupEqpEty = numFPupEqpEty;
	this->TxfEqpEty = TxfEqpEty;
	this->ChkEqpFib = ChkEqpFib;

	mask = {TXFSTA, TXFSTO, TXFXSA, TXFXSO, CHKCDN, CHKSDN, TXFFAFFID, TXFFAFIDT, TXFFAFACT, TXFFAFFET, TXFFAFFTI, TXFFAFFDT, TXFFAFFSK, TXFFAFFSM, TXFFAFFAT, TXFFAFRTE, TXFFAFADT, TXFFAFEAT, TXFFAFAAT, TXFFAFDVT, TXFFAFORG, TXFFAFDST, TXFFAFONM, TXFFAFOCT, TXFFAFDNM, TXFFAFDCT, NUMFPUPEQPETY, TXFEQPETY, CHKEQPFIB};
};

bool PnlBrlyFltDetail::ContIac::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContIacBrlyFltDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemIacBrlyFltDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSta", TxfSta)) add(TXFSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfSto", TxfSto)) add(TXFSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXsa", TxfXsa)) add(TXFXSA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfXso", TxfXso)) add(TXFXSO);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkCdn", ChkCdn)) add(CHKCDN);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkSdn", ChkSdn)) add(CHKSDN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafFid", TxfFafFid)) add(TXFFAFFID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafIdt", TxfFafIdt)) add(TXFFAFIDT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafAct", TxfFafAct)) add(TXFFAFACT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafFet", TxfFafFet)) add(TXFFAFFET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafFti", TxfFafFti)) add(TXFFAFFTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafFdt", TxfFafFdt)) add(TXFFAFFDT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafFsk", TxfFafFsk)) add(TXFFAFFSK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafFsm", TxfFafFsm)) add(TXFFAFFSM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafFat", TxfFafFat)) add(TXFFAFFAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafRte", TxfFafRte)) add(TXFFAFRTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafAdt", TxfFafAdt)) add(TXFFAFADT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafEat", TxfFafEat)) add(TXFFAFEAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafAat", TxfFafAat)) add(TXFFAFAAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafDvt", TxfFafDvt)) add(TXFFAFDVT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafOrg", TxfFafOrg)) add(TXFFAFORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafDst", TxfFafDst)) add(TXFFAFDST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafOnm", TxfFafOnm)) add(TXFFAFONM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafOct", TxfFafOct)) add(TXFFAFOCT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafDnm", TxfFafDnm)) add(TXFFAFDNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfFafDct", TxfFafDct)) add(TXFFAFDCT);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "numFPupEqpEty", numFPupEqpEty)) add(NUMFPUPEQPETY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxfEqpEty", TxfEqpEty)) add(TXFEQPETY);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "ChkEqpFib", ChkEqpFib)) add(CHKEQPFIB);
	};

	return basefound;
};

void PnlBrlyFltDetail::ContIac::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContIacBrlyFltDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemIacBrlyFltDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxfSta", TxfSta);
		writeStringAttr(wr, itemtag, "sref", "TxfSto", TxfSto);
		writeStringAttr(wr, itemtag, "sref", "TxfXsa", TxfXsa);
		writeStringAttr(wr, itemtag, "sref", "TxfXso", TxfXso);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdn", ChkCdn);
		writeBoolAttr(wr, itemtag, "sref", "ChkSdn", ChkSdn);
		writeStringAttr(wr, itemtag, "sref", "TxfFafFid", TxfFafFid);
		writeStringAttr(wr, itemtag, "sref", "TxfFafIdt", TxfFafIdt);
		writeStringAttr(wr, itemtag, "sref", "TxfFafAct", TxfFafAct);
		writeStringAttr(wr, itemtag, "sref", "TxfFafFet", TxfFafFet);
		writeStringAttr(wr, itemtag, "sref", "TxfFafFti", TxfFafFti);
		writeStringAttr(wr, itemtag, "sref", "TxfFafFdt", TxfFafFdt);
		writeStringAttr(wr, itemtag, "sref", "TxfFafFsk", TxfFafFsk);
		writeStringAttr(wr, itemtag, "sref", "TxfFafFsm", TxfFafFsm);
		writeStringAttr(wr, itemtag, "sref", "TxfFafFat", TxfFafFat);
		writeStringAttr(wr, itemtag, "sref", "TxfFafRte", TxfFafRte);
		writeStringAttr(wr, itemtag, "sref", "TxfFafAdt", TxfFafAdt);
		writeStringAttr(wr, itemtag, "sref", "TxfFafEat", TxfFafEat);
		writeStringAttr(wr, itemtag, "sref", "TxfFafAat", TxfFafAat);
		writeStringAttr(wr, itemtag, "sref", "TxfFafDvt", TxfFafDvt);
		writeStringAttr(wr, itemtag, "sref", "TxfFafOrg", TxfFafOrg);
		writeStringAttr(wr, itemtag, "sref", "TxfFafDst", TxfFafDst);
		writeStringAttr(wr, itemtag, "sref", "TxfFafOnm", TxfFafOnm);
		writeStringAttr(wr, itemtag, "sref", "TxfFafOct", TxfFafOct);
		writeStringAttr(wr, itemtag, "sref", "TxfFafDnm", TxfFafDnm);
		writeStringAttr(wr, itemtag, "sref", "TxfFafDct", TxfFafDct);
		writeUintAttr(wr, itemtag, "sref", "numFPupEqpEty", numFPupEqpEty);
		writeStringAttr(wr, itemtag, "sref", "TxfEqpEty", TxfEqpEty);
		writeBoolAttr(wr, itemtag, "sref", "ChkEqpFib", ChkEqpFib);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltDetail::ContIac::comm(
			const ContIac* comp
		) {
	set<uint> items;

	if (TxfSta.compare(comp->TxfSta) == 0) insert(items, TXFSTA);
	if (TxfSto.compare(comp->TxfSto) == 0) insert(items, TXFSTO);
	if (TxfXsa.compare(comp->TxfXsa) == 0) insert(items, TXFXSA);
	if (TxfXso.compare(comp->TxfXso) == 0) insert(items, TXFXSO);
	if (ChkCdn == comp->ChkCdn) insert(items, CHKCDN);
	if (ChkSdn == comp->ChkSdn) insert(items, CHKSDN);
	if (TxfFafFid.compare(comp->TxfFafFid) == 0) insert(items, TXFFAFFID);
	if (TxfFafIdt.compare(comp->TxfFafIdt) == 0) insert(items, TXFFAFIDT);
	if (TxfFafAct.compare(comp->TxfFafAct) == 0) insert(items, TXFFAFACT);
	if (TxfFafFet.compare(comp->TxfFafFet) == 0) insert(items, TXFFAFFET);
	if (TxfFafFti.compare(comp->TxfFafFti) == 0) insert(items, TXFFAFFTI);
	if (TxfFafFdt.compare(comp->TxfFafFdt) == 0) insert(items, TXFFAFFDT);
	if (TxfFafFsk.compare(comp->TxfFafFsk) == 0) insert(items, TXFFAFFSK);
	if (TxfFafFsm.compare(comp->TxfFafFsm) == 0) insert(items, TXFFAFFSM);
	if (TxfFafFat.compare(comp->TxfFafFat) == 0) insert(items, TXFFAFFAT);
	if (TxfFafRte.compare(comp->TxfFafRte) == 0) insert(items, TXFFAFRTE);
	if (TxfFafAdt.compare(comp->TxfFafAdt) == 0) insert(items, TXFFAFADT);
	if (TxfFafEat.compare(comp->TxfFafEat) == 0) insert(items, TXFFAFEAT);
	if (TxfFafAat.compare(comp->TxfFafAat) == 0) insert(items, TXFFAFAAT);
	if (TxfFafDvt.compare(comp->TxfFafDvt) == 0) insert(items, TXFFAFDVT);
	if (TxfFafOrg.compare(comp->TxfFafOrg) == 0) insert(items, TXFFAFORG);
	if (TxfFafDst.compare(comp->TxfFafDst) == 0) insert(items, TXFFAFDST);
	if (TxfFafOnm.compare(comp->TxfFafOnm) == 0) insert(items, TXFFAFONM);
	if (TxfFafOct.compare(comp->TxfFafOct) == 0) insert(items, TXFFAFOCT);
	if (TxfFafDnm.compare(comp->TxfFafDnm) == 0) insert(items, TXFFAFDNM);
	if (TxfFafDct.compare(comp->TxfFafDct) == 0) insert(items, TXFFAFDCT);
	if (numFPupEqpEty == comp->numFPupEqpEty) insert(items, NUMFPUPEQPETY);
	if (TxfEqpEty.compare(comp->TxfEqpEty) == 0) insert(items, TXFEQPETY);
	if (ChkEqpFib == comp->ChkEqpFib) insert(items, CHKEQPFIB);

	return(items);
};

set<uint> PnlBrlyFltDetail::ContIac::diff(
			const ContIac* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFSTA, TXFSTO, TXFXSA, TXFXSO, CHKCDN, CHKSDN, TXFFAFFID, TXFFAFIDT, TXFFAFACT, TXFFAFFET, TXFFAFFTI, TXFFAFFDT, TXFFAFFSK, TXFFAFFSM, TXFFAFFAT, TXFFAFRTE, TXFFAFADT, TXFFAFEAT, TXFFAFAAT, TXFFAFDVT, TXFFAFORG, TXFFAFDST, TXFFAFONM, TXFFAFOCT, TXFFAFDNM, TXFFAFDCT, NUMFPUPEQPETY, TXFEQPETY, CHKEQPFIB};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltDetail::ContInf
 ******************************************************************************/

PnlBrlyFltDetail::ContInf::ContInf(
			const string& TxtSrf
			, const string& TxtTtb
			, const string& TxtLeg
			, const string& TxtEqpOpr
			, const string& TxtEqpPty
		) : Block() {
	this->TxtSrf = TxtSrf;
	this->TxtTtb = TxtTtb;
	this->TxtLeg = TxtLeg;
	this->TxtEqpOpr = TxtEqpOpr;
	this->TxtEqpPty = TxtEqpPty;

	mask = {TXTSRF, TXTTTB, TXTLEG, TXTEQPOPR, TXTEQPPTY};
};

bool PnlBrlyFltDetail::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfBrlyFltDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfBrlyFltDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtSrf", TxtSrf)) add(TXTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtTtb", TxtTtb)) add(TXTTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtLeg", TxtLeg)) add(TXTLEG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtEqpOpr", TxtEqpOpr)) add(TXTEQPOPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtEqpPty", TxtEqpPty)) add(TXTEQPPTY);
	};

	return basefound;
};

set<uint> PnlBrlyFltDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf.compare(comp->TxtSrf) == 0) insert(items, TXTSRF);
	if (TxtTtb.compare(comp->TxtTtb) == 0) insert(items, TXTTTB);
	if (TxtLeg.compare(comp->TxtLeg) == 0) insert(items, TXTLEG);
	if (TxtEqpOpr.compare(comp->TxtEqpOpr) == 0) insert(items, TXTEQPOPR);
	if (TxtEqpPty.compare(comp->TxtEqpPty) == 0) insert(items, TXTEQPPTY);

	return(items);
};

set<uint> PnlBrlyFltDetail::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTSRF, TXTTTB, TXTLEG, TXTEQPOPR, TXTEQPPTY};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltDetail::StatApp
 ******************************************************************************/

PnlBrlyFltDetail::StatApp::StatApp(
			const uint ixBrlyVExpstate
			, const bool PupEqpEtyAlt
		) : Block() {
	this->ixBrlyVExpstate = ixBrlyVExpstate;
	this->PupEqpEtyAlt = PupEqpEtyAlt;

	mask = {IXBRLYVEXPSTATE, PUPEQPETYALT};
};

bool PnlBrlyFltDetail::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxBrlyVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppBrlyFltDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppBrlyFltDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxBrlyVExpstate", srefIxBrlyVExpstate)) {
			ixBrlyVExpstate = VecBrlyVExpstate::getIx(srefIxBrlyVExpstate);
			add(IXBRLYVEXPSTATE);
		};
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupEqpEtyAlt", PupEqpEtyAlt)) add(PUPEQPETYALT);
	};

	return basefound;
};

set<uint> PnlBrlyFltDetail::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixBrlyVExpstate == comp->ixBrlyVExpstate) insert(items, IXBRLYVEXPSTATE);
	if (PupEqpEtyAlt == comp->PupEqpEtyAlt) insert(items, PUPEQPETYALT);

	return(items);
};

set<uint> PnlBrlyFltDetail::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXBRLYVEXPSTATE, PUPEQPETYALT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltDetail::StatShr
 ******************************************************************************/

PnlBrlyFltDetail::StatShr::StatShr(
			const bool TxfEqpEtyValid
			, const bool ButSaveAvail
			, const bool ButSaveActive
			, const bool TxtSrfActive
			, const bool TxtTtbActive
			, const bool ButTtbViewAvail
			, const bool ButTtbViewActive
			, const bool TxtLegActive
			, const bool TxfStaActive
			, const bool TxfStoActive
			, const bool TxfXsaActive
			, const bool TxfXsoActive
			, const bool ChkCdnActive
			, const bool ChkSdnActive
			, const bool ButFafNewAvail
			, const bool ButFafDeleteAvail
			, const bool TxfFafFidAvail
			, const bool TxfFafFidActive
			, const bool TxfFafIdtAvail
			, const bool TxfFafIdtActive
			, const bool TxfFafActAvail
			, const bool TxfFafActActive
			, const bool TxfFafFetAvail
			, const bool TxfFafFetActive
			, const bool TxfFafFtiAvail
			, const bool TxfFafFtiActive
			, const bool TxfFafFdtAvail
			, const bool TxfFafFdtActive
			, const bool TxfFafFskAvail
			, const bool TxfFafFskActive
			, const bool TxfFafFsmAvail
			, const bool TxfFafFsmActive
			, const bool TxfFafFatAvail
			, const bool TxfFafFatActive
			, const bool TxfFafRteAvail
			, const bool TxfFafRteActive
			, const bool TxfFafAdtAvail
			, const bool TxfFafAdtActive
			, const bool TxfFafEatAvail
			, const bool TxfFafEatActive
			, const bool TxfFafAatAvail
			, const bool TxfFafAatActive
			, const bool TxfFafDvtAvail
			, const bool TxfFafDvtActive
			, const bool TxfFafOrgAvail
			, const bool TxfFafOrgActive
			, const bool TxfFafDstAvail
			, const bool TxfFafDstActive
			, const bool TxfFafOnmAvail
			, const bool TxfFafOnmActive
			, const bool TxfFafOctAvail
			, const bool TxfFafOctActive
			, const bool TxfFafDnmAvail
			, const bool TxfFafDnmActive
			, const bool TxfFafDctAvail
			, const bool TxfFafDctActive
			, const bool ButEqpNewAvail
			, const bool ButEqpDeleteAvail
			, const bool TxtEqpOprAvail
			, const bool TxtEqpOprActive
			, const bool ButEqpOprViewAvail
			, const bool ButEqpOprViewActive
			, const bool TxtEqpPtyAvail
			, const bool TxtEqpPtyActive
			, const bool ButEqpPtyViewAvail
			, const bool ButEqpPtyViewActive
			, const bool PupEqpEtyAvail
			, const bool PupEqpEtyActive
			, const bool ButEqpEtyEditAvail
			, const bool ChkEqpFibAvail
			, const bool ChkEqpFibActive
		) : Block() {
	this->TxfEqpEtyValid = TxfEqpEtyValid;
	this->ButSaveAvail = ButSaveAvail;
	this->ButSaveActive = ButSaveActive;
	this->TxtSrfActive = TxtSrfActive;
	this->TxtTtbActive = TxtTtbActive;
	this->ButTtbViewAvail = ButTtbViewAvail;
	this->ButTtbViewActive = ButTtbViewActive;
	this->TxtLegActive = TxtLegActive;
	this->TxfStaActive = TxfStaActive;
	this->TxfStoActive = TxfStoActive;
	this->TxfXsaActive = TxfXsaActive;
	this->TxfXsoActive = TxfXsoActive;
	this->ChkCdnActive = ChkCdnActive;
	this->ChkSdnActive = ChkSdnActive;
	this->ButFafNewAvail = ButFafNewAvail;
	this->ButFafDeleteAvail = ButFafDeleteAvail;
	this->TxfFafFidAvail = TxfFafFidAvail;
	this->TxfFafFidActive = TxfFafFidActive;
	this->TxfFafIdtAvail = TxfFafIdtAvail;
	this->TxfFafIdtActive = TxfFafIdtActive;
	this->TxfFafActAvail = TxfFafActAvail;
	this->TxfFafActActive = TxfFafActActive;
	this->TxfFafFetAvail = TxfFafFetAvail;
	this->TxfFafFetActive = TxfFafFetActive;
	this->TxfFafFtiAvail = TxfFafFtiAvail;
	this->TxfFafFtiActive = TxfFafFtiActive;
	this->TxfFafFdtAvail = TxfFafFdtAvail;
	this->TxfFafFdtActive = TxfFafFdtActive;
	this->TxfFafFskAvail = TxfFafFskAvail;
	this->TxfFafFskActive = TxfFafFskActive;
	this->TxfFafFsmAvail = TxfFafFsmAvail;
	this->TxfFafFsmActive = TxfFafFsmActive;
	this->TxfFafFatAvail = TxfFafFatAvail;
	this->TxfFafFatActive = TxfFafFatActive;
	this->TxfFafRteAvail = TxfFafRteAvail;
	this->TxfFafRteActive = TxfFafRteActive;
	this->TxfFafAdtAvail = TxfFafAdtAvail;
	this->TxfFafAdtActive = TxfFafAdtActive;
	this->TxfFafEatAvail = TxfFafEatAvail;
	this->TxfFafEatActive = TxfFafEatActive;
	this->TxfFafAatAvail = TxfFafAatAvail;
	this->TxfFafAatActive = TxfFafAatActive;
	this->TxfFafDvtAvail = TxfFafDvtAvail;
	this->TxfFafDvtActive = TxfFafDvtActive;
	this->TxfFafOrgAvail = TxfFafOrgAvail;
	this->TxfFafOrgActive = TxfFafOrgActive;
	this->TxfFafDstAvail = TxfFafDstAvail;
	this->TxfFafDstActive = TxfFafDstActive;
	this->TxfFafOnmAvail = TxfFafOnmAvail;
	this->TxfFafOnmActive = TxfFafOnmActive;
	this->TxfFafOctAvail = TxfFafOctAvail;
	this->TxfFafOctActive = TxfFafOctActive;
	this->TxfFafDnmAvail = TxfFafDnmAvail;
	this->TxfFafDnmActive = TxfFafDnmActive;
	this->TxfFafDctAvail = TxfFafDctAvail;
	this->TxfFafDctActive = TxfFafDctActive;
	this->ButEqpNewAvail = ButEqpNewAvail;
	this->ButEqpDeleteAvail = ButEqpDeleteAvail;
	this->TxtEqpOprAvail = TxtEqpOprAvail;
	this->TxtEqpOprActive = TxtEqpOprActive;
	this->ButEqpOprViewAvail = ButEqpOprViewAvail;
	this->ButEqpOprViewActive = ButEqpOprViewActive;
	this->TxtEqpPtyAvail = TxtEqpPtyAvail;
	this->TxtEqpPtyActive = TxtEqpPtyActive;
	this->ButEqpPtyViewAvail = ButEqpPtyViewAvail;
	this->ButEqpPtyViewActive = ButEqpPtyViewActive;
	this->PupEqpEtyAvail = PupEqpEtyAvail;
	this->PupEqpEtyActive = PupEqpEtyActive;
	this->ButEqpEtyEditAvail = ButEqpEtyEditAvail;
	this->ChkEqpFibAvail = ChkEqpFibAvail;
	this->ChkEqpFibActive = ChkEqpFibActive;

	mask = {TXFEQPETYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTTTBACTIVE, BUTTTBVIEWAVAIL, BUTTTBVIEWACTIVE, TXTLEGACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFXSAACTIVE, TXFXSOACTIVE, CHKCDNACTIVE, CHKSDNACTIVE, BUTFAFNEWAVAIL, BUTFAFDELETEAVAIL, TXFFAFFIDAVAIL, TXFFAFFIDACTIVE, TXFFAFIDTAVAIL, TXFFAFIDTACTIVE, TXFFAFACTAVAIL, TXFFAFACTACTIVE, TXFFAFFETAVAIL, TXFFAFFETACTIVE, TXFFAFFTIAVAIL, TXFFAFFTIACTIVE, TXFFAFFDTAVAIL, TXFFAFFDTACTIVE, TXFFAFFSKAVAIL, TXFFAFFSKACTIVE, TXFFAFFSMAVAIL, TXFFAFFSMACTIVE, TXFFAFFATAVAIL, TXFFAFFATACTIVE, TXFFAFRTEAVAIL, TXFFAFRTEACTIVE, TXFFAFADTAVAIL, TXFFAFADTACTIVE, TXFFAFEATAVAIL, TXFFAFEATACTIVE, TXFFAFAATAVAIL, TXFFAFAATACTIVE, TXFFAFDVTAVAIL, TXFFAFDVTACTIVE, TXFFAFORGAVAIL, TXFFAFORGACTIVE, TXFFAFDSTAVAIL, TXFFAFDSTACTIVE, TXFFAFONMAVAIL, TXFFAFONMACTIVE, TXFFAFOCTAVAIL, TXFFAFOCTACTIVE, TXFFAFDNMAVAIL, TXFFAFDNMACTIVE, TXFFAFDCTAVAIL, TXFFAFDCTACTIVE, BUTEQPNEWAVAIL, BUTEQPDELETEAVAIL, TXTEQPOPRAVAIL, TXTEQPOPRACTIVE, BUTEQPOPRVIEWAVAIL, BUTEQPOPRVIEWACTIVE, TXTEQPPTYAVAIL, TXTEQPPTYACTIVE, BUTEQPPTYVIEWAVAIL, BUTEQPPTYVIEWACTIVE, PUPEQPETYAVAIL, PUPEQPETYACTIVE, BUTEQPETYEDITAVAIL, CHKEQPFIBAVAIL, CHKEQPFIBACTIVE};
};

bool PnlBrlyFltDetail::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrBrlyFltDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrBrlyFltDetail";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfEqpEtyValid", TxfEqpEtyValid)) add(TXFEQPETYVALID);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveAvail", ButSaveAvail)) add(BUTSAVEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButSaveActive", ButSaveActive)) add(BUTSAVEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtSrfActive", TxtSrfActive)) add(TXTSRFACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtTtbActive", TxtTtbActive)) add(TXTTTBACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTtbViewAvail", ButTtbViewAvail)) add(BUTTTBVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButTtbViewActive", ButTtbViewActive)) add(BUTTTBVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtLegActive", TxtLegActive)) add(TXTLEGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStaActive", TxfStaActive)) add(TXFSTAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfStoActive", TxfStoActive)) add(TXFSTOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXsaActive", TxfXsaActive)) add(TXFXSAACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfXsoActive", TxfXsoActive)) add(TXFXSOACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkCdnActive", ChkCdnActive)) add(CHKCDNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkSdnActive", ChkSdnActive)) add(CHKSDNACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFafNewAvail", ButFafNewAvail)) add(BUTFAFNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButFafDeleteAvail", ButFafDeleteAvail)) add(BUTFAFDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFidAvail", TxfFafFidAvail)) add(TXFFAFFIDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFidActive", TxfFafFidActive)) add(TXFFAFFIDACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafIdtAvail", TxfFafIdtAvail)) add(TXFFAFIDTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafIdtActive", TxfFafIdtActive)) add(TXFFAFIDTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafActAvail", TxfFafActAvail)) add(TXFFAFACTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafActActive", TxfFafActActive)) add(TXFFAFACTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFetAvail", TxfFafFetAvail)) add(TXFFAFFETAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFetActive", TxfFafFetActive)) add(TXFFAFFETACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFtiAvail", TxfFafFtiAvail)) add(TXFFAFFTIAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFtiActive", TxfFafFtiActive)) add(TXFFAFFTIACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFdtAvail", TxfFafFdtAvail)) add(TXFFAFFDTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFdtActive", TxfFafFdtActive)) add(TXFFAFFDTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFskAvail", TxfFafFskAvail)) add(TXFFAFFSKAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFskActive", TxfFafFskActive)) add(TXFFAFFSKACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFsmAvail", TxfFafFsmAvail)) add(TXFFAFFSMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFsmActive", TxfFafFsmActive)) add(TXFFAFFSMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFatAvail", TxfFafFatAvail)) add(TXFFAFFATAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafFatActive", TxfFafFatActive)) add(TXFFAFFATACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafRteAvail", TxfFafRteAvail)) add(TXFFAFRTEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafRteActive", TxfFafRteActive)) add(TXFFAFRTEACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafAdtAvail", TxfFafAdtAvail)) add(TXFFAFADTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafAdtActive", TxfFafAdtActive)) add(TXFFAFADTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafEatAvail", TxfFafEatAvail)) add(TXFFAFEATAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafEatActive", TxfFafEatActive)) add(TXFFAFEATACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafAatAvail", TxfFafAatAvail)) add(TXFFAFAATAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafAatActive", TxfFafAatActive)) add(TXFFAFAATACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafDvtAvail", TxfFafDvtAvail)) add(TXFFAFDVTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafDvtActive", TxfFafDvtActive)) add(TXFFAFDVTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafOrgAvail", TxfFafOrgAvail)) add(TXFFAFORGAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafOrgActive", TxfFafOrgActive)) add(TXFFAFORGACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafDstAvail", TxfFafDstAvail)) add(TXFFAFDSTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafDstActive", TxfFafDstActive)) add(TXFFAFDSTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafOnmAvail", TxfFafOnmAvail)) add(TXFFAFONMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafOnmActive", TxfFafOnmActive)) add(TXFFAFONMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafOctAvail", TxfFafOctAvail)) add(TXFFAFOCTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafOctActive", TxfFafOctActive)) add(TXFFAFOCTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafDnmAvail", TxfFafDnmAvail)) add(TXFFAFDNMAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafDnmActive", TxfFafDnmActive)) add(TXFFAFDNMACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafDctAvail", TxfFafDctAvail)) add(TXFFAFDCTAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxfFafDctActive", TxfFafDctActive)) add(TXFFAFDCTACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpNewAvail", ButEqpNewAvail)) add(BUTEQPNEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpDeleteAvail", ButEqpDeleteAvail)) add(BUTEQPDELETEAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEqpOprAvail", TxtEqpOprAvail)) add(TXTEQPOPRAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEqpOprActive", TxtEqpOprActive)) add(TXTEQPOPRACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpOprViewAvail", ButEqpOprViewAvail)) add(BUTEQPOPRVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpOprViewActive", ButEqpOprViewActive)) add(BUTEQPOPRVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEqpPtyAvail", TxtEqpPtyAvail)) add(TXTEQPPTYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtEqpPtyActive", TxtEqpPtyActive)) add(TXTEQPPTYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpPtyViewAvail", ButEqpPtyViewAvail)) add(BUTEQPPTYVIEWAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpPtyViewActive", ButEqpPtyViewActive)) add(BUTEQPPTYVIEWACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupEqpEtyAvail", PupEqpEtyAvail)) add(PUPEQPETYAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "PupEqpEtyActive", PupEqpEtyActive)) add(PUPEQPETYACTIVE);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButEqpEtyEditAvail", ButEqpEtyEditAvail)) add(BUTEQPETYEDITAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkEqpFibAvail", ChkEqpFibAvail)) add(CHKEQPFIBAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ChkEqpFibActive", ChkEqpFibActive)) add(CHKEQPFIBACTIVE);
	};

	return basefound;
};

set<uint> PnlBrlyFltDetail::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxfEqpEtyValid == comp->TxfEqpEtyValid) insert(items, TXFEQPETYVALID);
	if (ButSaveAvail == comp->ButSaveAvail) insert(items, BUTSAVEAVAIL);
	if (ButSaveActive == comp->ButSaveActive) insert(items, BUTSAVEACTIVE);
	if (TxtSrfActive == comp->TxtSrfActive) insert(items, TXTSRFACTIVE);
	if (TxtTtbActive == comp->TxtTtbActive) insert(items, TXTTTBACTIVE);
	if (ButTtbViewAvail == comp->ButTtbViewAvail) insert(items, BUTTTBVIEWAVAIL);
	if (ButTtbViewActive == comp->ButTtbViewActive) insert(items, BUTTTBVIEWACTIVE);
	if (TxtLegActive == comp->TxtLegActive) insert(items, TXTLEGACTIVE);
	if (TxfStaActive == comp->TxfStaActive) insert(items, TXFSTAACTIVE);
	if (TxfStoActive == comp->TxfStoActive) insert(items, TXFSTOACTIVE);
	if (TxfXsaActive == comp->TxfXsaActive) insert(items, TXFXSAACTIVE);
	if (TxfXsoActive == comp->TxfXsoActive) insert(items, TXFXSOACTIVE);
	if (ChkCdnActive == comp->ChkCdnActive) insert(items, CHKCDNACTIVE);
	if (ChkSdnActive == comp->ChkSdnActive) insert(items, CHKSDNACTIVE);
	if (ButFafNewAvail == comp->ButFafNewAvail) insert(items, BUTFAFNEWAVAIL);
	if (ButFafDeleteAvail == comp->ButFafDeleteAvail) insert(items, BUTFAFDELETEAVAIL);
	if (TxfFafFidAvail == comp->TxfFafFidAvail) insert(items, TXFFAFFIDAVAIL);
	if (TxfFafFidActive == comp->TxfFafFidActive) insert(items, TXFFAFFIDACTIVE);
	if (TxfFafIdtAvail == comp->TxfFafIdtAvail) insert(items, TXFFAFIDTAVAIL);
	if (TxfFafIdtActive == comp->TxfFafIdtActive) insert(items, TXFFAFIDTACTIVE);
	if (TxfFafActAvail == comp->TxfFafActAvail) insert(items, TXFFAFACTAVAIL);
	if (TxfFafActActive == comp->TxfFafActActive) insert(items, TXFFAFACTACTIVE);
	if (TxfFafFetAvail == comp->TxfFafFetAvail) insert(items, TXFFAFFETAVAIL);
	if (TxfFafFetActive == comp->TxfFafFetActive) insert(items, TXFFAFFETACTIVE);
	if (TxfFafFtiAvail == comp->TxfFafFtiAvail) insert(items, TXFFAFFTIAVAIL);
	if (TxfFafFtiActive == comp->TxfFafFtiActive) insert(items, TXFFAFFTIACTIVE);
	if (TxfFafFdtAvail == comp->TxfFafFdtAvail) insert(items, TXFFAFFDTAVAIL);
	if (TxfFafFdtActive == comp->TxfFafFdtActive) insert(items, TXFFAFFDTACTIVE);
	if (TxfFafFskAvail == comp->TxfFafFskAvail) insert(items, TXFFAFFSKAVAIL);
	if (TxfFafFskActive == comp->TxfFafFskActive) insert(items, TXFFAFFSKACTIVE);
	if (TxfFafFsmAvail == comp->TxfFafFsmAvail) insert(items, TXFFAFFSMAVAIL);
	if (TxfFafFsmActive == comp->TxfFafFsmActive) insert(items, TXFFAFFSMACTIVE);
	if (TxfFafFatAvail == comp->TxfFafFatAvail) insert(items, TXFFAFFATAVAIL);
	if (TxfFafFatActive == comp->TxfFafFatActive) insert(items, TXFFAFFATACTIVE);
	if (TxfFafRteAvail == comp->TxfFafRteAvail) insert(items, TXFFAFRTEAVAIL);
	if (TxfFafRteActive == comp->TxfFafRteActive) insert(items, TXFFAFRTEACTIVE);
	if (TxfFafAdtAvail == comp->TxfFafAdtAvail) insert(items, TXFFAFADTAVAIL);
	if (TxfFafAdtActive == comp->TxfFafAdtActive) insert(items, TXFFAFADTACTIVE);
	if (TxfFafEatAvail == comp->TxfFafEatAvail) insert(items, TXFFAFEATAVAIL);
	if (TxfFafEatActive == comp->TxfFafEatActive) insert(items, TXFFAFEATACTIVE);
	if (TxfFafAatAvail == comp->TxfFafAatAvail) insert(items, TXFFAFAATAVAIL);
	if (TxfFafAatActive == comp->TxfFafAatActive) insert(items, TXFFAFAATACTIVE);
	if (TxfFafDvtAvail == comp->TxfFafDvtAvail) insert(items, TXFFAFDVTAVAIL);
	if (TxfFafDvtActive == comp->TxfFafDvtActive) insert(items, TXFFAFDVTACTIVE);
	if (TxfFafOrgAvail == comp->TxfFafOrgAvail) insert(items, TXFFAFORGAVAIL);
	if (TxfFafOrgActive == comp->TxfFafOrgActive) insert(items, TXFFAFORGACTIVE);
	if (TxfFafDstAvail == comp->TxfFafDstAvail) insert(items, TXFFAFDSTAVAIL);
	if (TxfFafDstActive == comp->TxfFafDstActive) insert(items, TXFFAFDSTACTIVE);
	if (TxfFafOnmAvail == comp->TxfFafOnmAvail) insert(items, TXFFAFONMAVAIL);
	if (TxfFafOnmActive == comp->TxfFafOnmActive) insert(items, TXFFAFONMACTIVE);
	if (TxfFafOctAvail == comp->TxfFafOctAvail) insert(items, TXFFAFOCTAVAIL);
	if (TxfFafOctActive == comp->TxfFafOctActive) insert(items, TXFFAFOCTACTIVE);
	if (TxfFafDnmAvail == comp->TxfFafDnmAvail) insert(items, TXFFAFDNMAVAIL);
	if (TxfFafDnmActive == comp->TxfFafDnmActive) insert(items, TXFFAFDNMACTIVE);
	if (TxfFafDctAvail == comp->TxfFafDctAvail) insert(items, TXFFAFDCTAVAIL);
	if (TxfFafDctActive == comp->TxfFafDctActive) insert(items, TXFFAFDCTACTIVE);
	if (ButEqpNewAvail == comp->ButEqpNewAvail) insert(items, BUTEQPNEWAVAIL);
	if (ButEqpDeleteAvail == comp->ButEqpDeleteAvail) insert(items, BUTEQPDELETEAVAIL);
	if (TxtEqpOprAvail == comp->TxtEqpOprAvail) insert(items, TXTEQPOPRAVAIL);
	if (TxtEqpOprActive == comp->TxtEqpOprActive) insert(items, TXTEQPOPRACTIVE);
	if (ButEqpOprViewAvail == comp->ButEqpOprViewAvail) insert(items, BUTEQPOPRVIEWAVAIL);
	if (ButEqpOprViewActive == comp->ButEqpOprViewActive) insert(items, BUTEQPOPRVIEWACTIVE);
	if (TxtEqpPtyAvail == comp->TxtEqpPtyAvail) insert(items, TXTEQPPTYAVAIL);
	if (TxtEqpPtyActive == comp->TxtEqpPtyActive) insert(items, TXTEQPPTYACTIVE);
	if (ButEqpPtyViewAvail == comp->ButEqpPtyViewAvail) insert(items, BUTEQPPTYVIEWAVAIL);
	if (ButEqpPtyViewActive == comp->ButEqpPtyViewActive) insert(items, BUTEQPPTYVIEWACTIVE);
	if (PupEqpEtyAvail == comp->PupEqpEtyAvail) insert(items, PUPEQPETYAVAIL);
	if (PupEqpEtyActive == comp->PupEqpEtyActive) insert(items, PUPEQPETYACTIVE);
	if (ButEqpEtyEditAvail == comp->ButEqpEtyEditAvail) insert(items, BUTEQPETYEDITAVAIL);
	if (ChkEqpFibAvail == comp->ChkEqpFibAvail) insert(items, CHKEQPFIBAVAIL);
	if (ChkEqpFibActive == comp->ChkEqpFibActive) insert(items, CHKEQPFIBACTIVE);

	return(items);
};

set<uint> PnlBrlyFltDetail::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXFEQPETYVALID, BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXTTTBACTIVE, BUTTTBVIEWAVAIL, BUTTTBVIEWACTIVE, TXTLEGACTIVE, TXFSTAACTIVE, TXFSTOACTIVE, TXFXSAACTIVE, TXFXSOACTIVE, CHKCDNACTIVE, CHKSDNACTIVE, BUTFAFNEWAVAIL, BUTFAFDELETEAVAIL, TXFFAFFIDAVAIL, TXFFAFFIDACTIVE, TXFFAFIDTAVAIL, TXFFAFIDTACTIVE, TXFFAFACTAVAIL, TXFFAFACTACTIVE, TXFFAFFETAVAIL, TXFFAFFETACTIVE, TXFFAFFTIAVAIL, TXFFAFFTIACTIVE, TXFFAFFDTAVAIL, TXFFAFFDTACTIVE, TXFFAFFSKAVAIL, TXFFAFFSKACTIVE, TXFFAFFSMAVAIL, TXFFAFFSMACTIVE, TXFFAFFATAVAIL, TXFFAFFATACTIVE, TXFFAFRTEAVAIL, TXFFAFRTEACTIVE, TXFFAFADTAVAIL, TXFFAFADTACTIVE, TXFFAFEATAVAIL, TXFFAFEATACTIVE, TXFFAFAATAVAIL, TXFFAFAATACTIVE, TXFFAFDVTAVAIL, TXFFAFDVTACTIVE, TXFFAFORGAVAIL, TXFFAFORGACTIVE, TXFFAFDSTAVAIL, TXFFAFDSTACTIVE, TXFFAFONMAVAIL, TXFFAFONMACTIVE, TXFFAFOCTAVAIL, TXFFAFOCTACTIVE, TXFFAFDNMAVAIL, TXFFAFDNMACTIVE, TXFFAFDCTAVAIL, TXFFAFDCTACTIVE, BUTEQPNEWAVAIL, BUTEQPDELETEAVAIL, TXTEQPOPRAVAIL, TXTEQPOPRACTIVE, BUTEQPOPRVIEWAVAIL, BUTEQPOPRVIEWACTIVE, TXTEQPPTYAVAIL, TXTEQPPTYACTIVE, BUTEQPPTYVIEWAVAIL, BUTEQPPTYVIEWACTIVE, PUPEQPETYAVAIL, PUPEQPETYACTIVE, BUTEQPETYEDITAVAIL, CHKEQPFIBAVAIL, CHKEQPFIBACTIVE};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlBrlyFltDetail::Tag
 ******************************************************************************/

PnlBrlyFltDetail::Tag::Tag(
			const string& Cpt
			, const string& CptSrf
			, const string& CptTtb
			, const string& CptLeg
			, const string& CptSta
			, const string& CptSto
			, const string& CptXsa
			, const string& CptXso
			, const string& CptCdn
			, const string& CptSdn
			, const string& HdgFaf
			, const string& CptFafFid
			, const string& CptFafIdt
			, const string& CptFafAct
			, const string& CptFafFet
			, const string& CptFafFti
			, const string& CptFafFdt
			, const string& CptFafFsk
			, const string& CptFafFsm
			, const string& CptFafFat
			, const string& CptFafRte
			, const string& CptFafAdt
			, const string& CptFafEat
			, const string& CptFafAat
			, const string& CptFafDvt
			, const string& CptFafOrg
			, const string& CptFafDst
			, const string& CptFafOnm
			, const string& CptFafOct
			, const string& CptFafDnm
			, const string& CptFafDct
			, const string& HdgEqp
			, const string& CptEqpOpr
			, const string& CptEqpPty
			, const string& CptEqpEty
			, const string& CptEqpFib
		) : Block() {
	this->Cpt = Cpt;
	this->CptSrf = CptSrf;
	this->CptTtb = CptTtb;
	this->CptLeg = CptLeg;
	this->CptSta = CptSta;
	this->CptSto = CptSto;
	this->CptXsa = CptXsa;
	this->CptXso = CptXso;
	this->CptCdn = CptCdn;
	this->CptSdn = CptSdn;
	this->HdgFaf = HdgFaf;
	this->CptFafFid = CptFafFid;
	this->CptFafIdt = CptFafIdt;
	this->CptFafAct = CptFafAct;
	this->CptFafFet = CptFafFet;
	this->CptFafFti = CptFafFti;
	this->CptFafFdt = CptFafFdt;
	this->CptFafFsk = CptFafFsk;
	this->CptFafFsm = CptFafFsm;
	this->CptFafFat = CptFafFat;
	this->CptFafRte = CptFafRte;
	this->CptFafAdt = CptFafAdt;
	this->CptFafEat = CptFafEat;
	this->CptFafAat = CptFafAat;
	this->CptFafDvt = CptFafDvt;
	this->CptFafOrg = CptFafOrg;
	this->CptFafDst = CptFafDst;
	this->CptFafOnm = CptFafOnm;
	this->CptFafOct = CptFafOct;
	this->CptFafDnm = CptFafDnm;
	this->CptFafDct = CptFafDct;
	this->HdgEqp = HdgEqp;
	this->CptEqpOpr = CptEqpOpr;
	this->CptEqpPty = CptEqpPty;
	this->CptEqpEty = CptEqpEty;
	this->CptEqpFib = CptEqpFib;

	mask = {CPT, CPTSRF, CPTTTB, CPTLEG, CPTSTA, CPTSTO, CPTXSA, CPTXSO, CPTCDN, CPTSDN, HDGFAF, CPTFAFFID, CPTFAFIDT, CPTFAFACT, CPTFAFFET, CPTFAFFTI, CPTFAFFDT, CPTFAFFSK, CPTFAFFSM, CPTFAFFAT, CPTFAFRTE, CPTFAFADT, CPTFAFEAT, CPTFAFAAT, CPTFAFDVT, CPTFAFORG, CPTFAFDST, CPTFAFONM, CPTFAFOCT, CPTFAFDNM, CPTFAFDCT, HDGEQP, CPTEQPOPR, CPTEQPPTY, CPTEQPETY, CPTEQPFIB};
};

bool PnlBrlyFltDetail::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagBrlyFltDetail");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemBrlyFltDetail";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSrf", CptSrf)) add(CPTSRF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptTtb", CptTtb)) add(CPTTTB);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLeg", CptLeg)) add(CPTLEG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSta", CptSta)) add(CPTSTA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSto", CptSto)) add(CPTSTO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXsa", CptXsa)) add(CPTXSA);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptXso", CptXso)) add(CPTXSO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptCdn", CptCdn)) add(CPTCDN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptSdn", CptSdn)) add(CPTSDN);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgFaf", HdgFaf)) add(HDGFAF);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafFid", CptFafFid)) add(CPTFAFFID);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafIdt", CptFafIdt)) add(CPTFAFIDT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafAct", CptFafAct)) add(CPTFAFACT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafFet", CptFafFet)) add(CPTFAFFET);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafFti", CptFafFti)) add(CPTFAFFTI);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafFdt", CptFafFdt)) add(CPTFAFFDT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafFsk", CptFafFsk)) add(CPTFAFFSK);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafFsm", CptFafFsm)) add(CPTFAFFSM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafFat", CptFafFat)) add(CPTFAFFAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafRte", CptFafRte)) add(CPTFAFRTE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafAdt", CptFafAdt)) add(CPTFAFADT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafEat", CptFafEat)) add(CPTFAFEAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafAat", CptFafAat)) add(CPTFAFAAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafDvt", CptFafDvt)) add(CPTFAFDVT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafOrg", CptFafOrg)) add(CPTFAFORG);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafDst", CptFafDst)) add(CPTFAFDST);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafOnm", CptFafOnm)) add(CPTFAFONM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafOct", CptFafOct)) add(CPTFAFOCT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafDnm", CptFafDnm)) add(CPTFAFDNM);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptFafDct", CptFafDct)) add(CPTFAFDCT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "HdgEqp", HdgEqp)) add(HDGEQP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEqpOpr", CptEqpOpr)) add(CPTEQPOPR);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEqpPty", CptEqpPty)) add(CPTEQPPTY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEqpEty", CptEqpEty)) add(CPTEQPETY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptEqpFib", CptEqpFib)) add(CPTEQPFIB);
	};

	return basefound;
};

/******************************************************************************
 class PnlBrlyFltDetail::DpchAppData
 ******************************************************************************/

PnlBrlyFltDetail::DpchAppData::DpchAppData(
			const string& scrJref
			, ContIac* contiac
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTDETAILDATA, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, CONTIAC};
	else this->mask = mask;

		if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
};

string PnlBrlyFltDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltDetail::DpchAppData::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyFltDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(CONTIAC)) contiac.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyFltDetail::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTDETAILDO, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlBrlyFltDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltDetail::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppBrlyFltDetailDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltDetail::DpchEngData
 ******************************************************************************/

PnlBrlyFltDetail::DpchEngData::DpchEngData() : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFLTDETAILDATA) {
	feedFPupEqpEty.tag = "FeedFPupEqpEty";
};

string PnlBrlyFltDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPEQPETY)) ss.push_back("feedFPupEqpEty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltDetail::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngBrlyFltDetailData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (contiac.readXML(docctx, basexpath, true)) add(CONTIAC);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (feedFPupEqpEty.readXML(docctx, basexpath, true)) add(FEEDFPUPEQPETY);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		contiac = ContIac();
		continf = ContInf();
		feedFPupEqpEty.clear();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

