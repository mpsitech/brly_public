/**
  * \file PnlBrlyFltDetail_blks.cpp
  * job handler for job PnlBrlyFltDetail (implementation of blocks)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

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

	if (TxfSta == comp->TxfSta) insert(items, TXFSTA);
	if (TxfSto == comp->TxfSto) insert(items, TXFSTO);
	if (TxfXsa == comp->TxfXsa) insert(items, TXFXSA);
	if (TxfXso == comp->TxfXso) insert(items, TXFXSO);
	if (ChkCdn == comp->ChkCdn) insert(items, CHKCDN);
	if (ChkSdn == comp->ChkSdn) insert(items, CHKSDN);
	if (TxfFafFid == comp->TxfFafFid) insert(items, TXFFAFFID);
	if (TxfFafIdt == comp->TxfFafIdt) insert(items, TXFFAFIDT);
	if (TxfFafAct == comp->TxfFafAct) insert(items, TXFFAFACT);
	if (TxfFafFet == comp->TxfFafFet) insert(items, TXFFAFFET);
	if (TxfFafFti == comp->TxfFafFti) insert(items, TXFFAFFTI);
	if (TxfFafFdt == comp->TxfFafFdt) insert(items, TXFFAFFDT);
	if (TxfFafFsk == comp->TxfFafFsk) insert(items, TXFFAFFSK);
	if (TxfFafFsm == comp->TxfFafFsm) insert(items, TXFFAFFSM);
	if (TxfFafFat == comp->TxfFafFat) insert(items, TXFFAFFAT);
	if (TxfFafRte == comp->TxfFafRte) insert(items, TXFFAFRTE);
	if (TxfFafAdt == comp->TxfFafAdt) insert(items, TXFFAFADT);
	if (TxfFafEat == comp->TxfFafEat) insert(items, TXFFAFEAT);
	if (TxfFafAat == comp->TxfFafAat) insert(items, TXFFAFAAT);
	if (TxfFafDvt == comp->TxfFafDvt) insert(items, TXFFAFDVT);
	if (TxfFafOrg == comp->TxfFafOrg) insert(items, TXFFAFORG);
	if (TxfFafDst == comp->TxfFafDst) insert(items, TXFFAFDST);
	if (TxfFafOnm == comp->TxfFafOnm) insert(items, TXFFAFONM);
	if (TxfFafOct == comp->TxfFafOct) insert(items, TXFFAFOCT);
	if (TxfFafDnm == comp->TxfFafDnm) insert(items, TXFFAFDNM);
	if (TxfFafDct == comp->TxfFafDct) insert(items, TXFFAFDCT);
	if (numFPupEqpEty == comp->numFPupEqpEty) insert(items, NUMFPUPEQPETY);
	if (TxfEqpEty == comp->TxfEqpEty) insert(items, TXFEQPETY);
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

void PnlBrlyFltDetail::ContInf::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyFltDetail";

	string itemtag;
	if (shorttags) itemtag = "Ci";
	else itemtag = "ContitemInfBrlyFltDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtSrf", TxtSrf);
		writeStringAttr(wr, itemtag, "sref", "TxtTtb", TxtTtb);
		writeStringAttr(wr, itemtag, "sref", "TxtLeg", TxtLeg);
		writeStringAttr(wr, itemtag, "sref", "TxtEqpOpr", TxtEqpOpr);
		writeStringAttr(wr, itemtag, "sref", "TxtEqpPty", TxtEqpPty);
	xmlTextWriterEndElement(wr);
};

set<uint> PnlBrlyFltDetail::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtSrf == comp->TxtSrf) insert(items, TXTSRF);
	if (TxtTtb == comp->TxtTtb) insert(items, TXTTTB);
	if (TxtLeg == comp->TxtLeg) insert(items, TXTLEG);
	if (TxtEqpOpr == comp->TxtEqpOpr) insert(items, TXTEQPOPR);
	if (TxtEqpPty == comp->TxtEqpPty) insert(items, TXTEQPPTY);

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

void PnlBrlyFltDetail::StatApp::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
			, const uint ixBrlyVExpstate
			, const bool PupEqpEtyAlt
		) {
	if (difftag.length() == 0) difftag = "StatAppBrlyFltDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemAppBrlyFltDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxBrlyVExpstate", VecBrlyVExpstate::getSref(ixBrlyVExpstate));
		writeBoolAttr(wr, itemtag, "sref", "PupEqpEtyAlt", PupEqpEtyAlt);
	xmlTextWriterEndElement(wr);
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

void PnlBrlyFltDetail::StatShr::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StatShrBrlyFltDetail";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StatitemShrBrlyFltDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "TxfEqpEtyValid", TxfEqpEtyValid);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveAvail", ButSaveAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButSaveActive", ButSaveActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtSrfActive", TxtSrfActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtTtbActive", TxtTtbActive);
		writeBoolAttr(wr, itemtag, "sref", "ButTtbViewAvail", ButTtbViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButTtbViewActive", ButTtbViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtLegActive", TxtLegActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStaActive", TxfStaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfStoActive", TxfStoActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfXsaActive", TxfXsaActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfXsoActive", TxfXsoActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkCdnActive", ChkCdnActive);
		writeBoolAttr(wr, itemtag, "sref", "ChkSdnActive", ChkSdnActive);
		writeBoolAttr(wr, itemtag, "sref", "ButFafNewAvail", ButFafNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButFafDeleteAvail", ButFafDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFidAvail", TxfFafFidAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFidActive", TxfFafFidActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafIdtAvail", TxfFafIdtAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafIdtActive", TxfFafIdtActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafActAvail", TxfFafActAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafActActive", TxfFafActActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFetAvail", TxfFafFetAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFetActive", TxfFafFetActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFtiAvail", TxfFafFtiAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFtiActive", TxfFafFtiActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFdtAvail", TxfFafFdtAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFdtActive", TxfFafFdtActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFskAvail", TxfFafFskAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFskActive", TxfFafFskActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFsmAvail", TxfFafFsmAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFsmActive", TxfFafFsmActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFatAvail", TxfFafFatAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafFatActive", TxfFafFatActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafRteAvail", TxfFafRteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafRteActive", TxfFafRteActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafAdtAvail", TxfFafAdtAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafAdtActive", TxfFafAdtActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafEatAvail", TxfFafEatAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafEatActive", TxfFafEatActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafAatAvail", TxfFafAatAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafAatActive", TxfFafAatActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafDvtAvail", TxfFafDvtAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafDvtActive", TxfFafDvtActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafOrgAvail", TxfFafOrgAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafOrgActive", TxfFafOrgActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafDstAvail", TxfFafDstAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafDstActive", TxfFafDstActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafOnmAvail", TxfFafOnmAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafOnmActive", TxfFafOnmActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafOctAvail", TxfFafOctAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafOctActive", TxfFafOctActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafDnmAvail", TxfFafDnmAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafDnmActive", TxfFafDnmActive);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafDctAvail", TxfFafDctAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxfFafDctActive", TxfFafDctActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpNewAvail", ButEqpNewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpDeleteAvail", ButEqpDeleteAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtEqpOprAvail", TxtEqpOprAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtEqpOprActive", TxtEqpOprActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpOprViewAvail", ButEqpOprViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpOprViewActive", ButEqpOprViewActive);
		writeBoolAttr(wr, itemtag, "sref", "TxtEqpPtyAvail", TxtEqpPtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "TxtEqpPtyActive", TxtEqpPtyActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpPtyViewAvail", ButEqpPtyViewAvail);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpPtyViewActive", ButEqpPtyViewActive);
		writeBoolAttr(wr, itemtag, "sref", "PupEqpEtyAvail", PupEqpEtyAvail);
		writeBoolAttr(wr, itemtag, "sref", "PupEqpEtyActive", PupEqpEtyActive);
		writeBoolAttr(wr, itemtag, "sref", "ButEqpEtyEditAvail", ButEqpEtyEditAvail);
		writeBoolAttr(wr, itemtag, "sref", "ChkEqpFibAvail", ChkEqpFibAvail);
		writeBoolAttr(wr, itemtag, "sref", "ChkEqpFibActive", ChkEqpFibActive);
	xmlTextWriterEndElement(wr);
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

void PnlBrlyFltDetail::Tag::writeXML(
			const uint ixBrlyVLocale
			, xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "TagBrlyFltDetail";

	string itemtag;
	if (shorttags) itemtag = "Ti";
	else itemtag = "TagitemBrlyFltDetail";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "identifier");
			writeStringAttr(wr, itemtag, "sref", "CptTtb", "timetable");
			writeStringAttr(wr, itemtag, "sref", "CptLeg", "leg");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "departure time");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "arrival time");
			writeStringAttr(wr, itemtag, "sref", "CptXsa", "xStart");
			writeStringAttr(wr, itemtag, "sref", "CptXso", "xStop");
			writeStringAttr(wr, itemtag, "sref", "CptCdn", "calculated");
			writeStringAttr(wr, itemtag, "sref", "CptSdn", "segmented");
			writeStringAttr(wr, itemtag, "sref", "HdgFaf", "FlightAware flight");
			writeStringAttr(wr, itemtag, "sref", "CptFafFid", "faFlightID");
			writeStringAttr(wr, itemtag, "sref", "CptFafIdt", "ident");
			writeStringAttr(wr, itemtag, "sref", "CptFafAct", "aircrafttype");
			writeStringAttr(wr, itemtag, "sref", "CptFafFet", "filed_ete");
			writeStringAttr(wr, itemtag, "sref", "CptFafFti", "filed_time");
			writeStringAttr(wr, itemtag, "sref", "CptFafFdt", "filed_departuretime");
			writeStringAttr(wr, itemtag, "sref", "CptFafFsk", "filed_airspeed_kts");
			writeStringAttr(wr, itemtag, "sref", "CptFafFsm", "filed_airspeed_mach");
			writeStringAttr(wr, itemtag, "sref", "CptFafFat", "filed_altitude");
			writeStringAttr(wr, itemtag, "sref", "CptFafRte", "route");
			writeStringAttr(wr, itemtag, "sref", "CptFafAdt", "actualdeparturetime");
			writeStringAttr(wr, itemtag, "sref", "CptFafEat", "estimatedarrivaltime");
			writeStringAttr(wr, itemtag, "sref", "CptFafAat", "actualarrivaltime");
			writeStringAttr(wr, itemtag, "sref", "CptFafDvt", "diverted");
			writeStringAttr(wr, itemtag, "sref", "CptFafOrg", "origin");
			writeStringAttr(wr, itemtag, "sref", "CptFafDst", "destination");
			writeStringAttr(wr, itemtag, "sref", "CptFafOnm", "originName");
			writeStringAttr(wr, itemtag, "sref", "CptFafOct", "originCity");
			writeStringAttr(wr, itemtag, "sref", "CptFafDnm", "destinationName");
			writeStringAttr(wr, itemtag, "sref", "CptFafDct", "destinationCity");
			writeStringAttr(wr, itemtag, "sref", "HdgEqp", "Equipment");
			writeStringAttr(wr, itemtag, "sref", "CptEqpOpr", "operator");
			writeStringAttr(wr, itemtag, "sref", "CptEqpPty", "plane type");
			writeStringAttr(wr, itemtag, "sref", "CptEqpEty", "equipment type");
			writeStringAttr(wr, itemtag, "sref", "CptEqpFib", "Fiber");
		} else if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
			writeStringAttr(wr, itemtag, "sref", "CptSrf", "Bezeichner");
			writeStringAttr(wr, itemtag, "sref", "CptTtb", "Flugplan");
			writeStringAttr(wr, itemtag, "sref", "CptLeg", "Strecke");
			writeStringAttr(wr, itemtag, "sref", "CptSta", "Abflugszeit");
			writeStringAttr(wr, itemtag, "sref", "CptSto", "Ankunftszeit");
			writeStringAttr(wr, itemtag, "sref", "CptXsa", "xStart");
			writeStringAttr(wr, itemtag, "sref", "CptXso", "xStop");
			writeStringAttr(wr, itemtag, "sref", "CptCdn", "berechnet");
			writeStringAttr(wr, itemtag, "sref", "CptSdn", "segmentiert");
			writeStringAttr(wr, itemtag, "sref", "HdgFaf", "FlightAware Flug");
			writeStringAttr(wr, itemtag, "sref", "CptFafFid", "faFlightID");
			writeStringAttr(wr, itemtag, "sref", "CptFafIdt", "ident");
			writeStringAttr(wr, itemtag, "sref", "CptFafAct", "aircrafttype");
			writeStringAttr(wr, itemtag, "sref", "CptFafFet", "filed_ete");
			writeStringAttr(wr, itemtag, "sref", "CptFafFti", "filed_time");
			writeStringAttr(wr, itemtag, "sref", "CptFafFdt", "filed_departuretime");
			writeStringAttr(wr, itemtag, "sref", "CptFafFsk", "filed_airspeed_kts");
			writeStringAttr(wr, itemtag, "sref", "CptFafFsm", "filed_airspeed_mach");
			writeStringAttr(wr, itemtag, "sref", "CptFafFat", "filed_altitude");
			writeStringAttr(wr, itemtag, "sref", "CptFafRte", "route");
			writeStringAttr(wr, itemtag, "sref", "CptFafAdt", "actualdeparturetime");
			writeStringAttr(wr, itemtag, "sref", "CptFafEat", "estimatedarrivaltime");
			writeStringAttr(wr, itemtag, "sref", "CptFafAat", "actualarrivaltime");
			writeStringAttr(wr, itemtag, "sref", "CptFafDvt", "diverted");
			writeStringAttr(wr, itemtag, "sref", "CptFafOrg", "origin");
			writeStringAttr(wr, itemtag, "sref", "CptFafDst", "destination");
			writeStringAttr(wr, itemtag, "sref", "CptFafOnm", "originName");
			writeStringAttr(wr, itemtag, "sref", "CptFafOct", "originCity");
			writeStringAttr(wr, itemtag, "sref", "CptFafDnm", "destinationName");
			writeStringAttr(wr, itemtag, "sref", "CptFafDct", "destinationCity");
			writeStringAttr(wr, itemtag, "sref", "HdgEqp", "Ger\\u00e4t");
			writeStringAttr(wr, itemtag, "sref", "CptEqpOpr", "Betreiber");
			writeStringAttr(wr, itemtag, "sref", "CptEqpPty", "Flugzeugtyp");
			writeStringAttr(wr, itemtag, "sref", "CptEqpEty", "Ger\\u00e4tetyp");
			writeStringAttr(wr, itemtag, "sref", "CptEqpFib", "Fiber");
		};
		writeStringAttr(wr, itemtag, "sref", "Cpt", StrMod::cap(VecBrlyVTag::getTitle(VecBrlyVTag::DETAIL, ixBrlyVLocale)));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlBrlyFltDetail::DpchAppData
 ******************************************************************************/

PnlBrlyFltDetail::DpchAppData::DpchAppData() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTDETAILDATA) {
};

string PnlBrlyFltDetail::DpchAppData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltDetail::DpchAppData::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyFltDetailData");
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
 class PnlBrlyFltDetail::DpchAppDo
 ******************************************************************************/

PnlBrlyFltDetail::DpchAppDo::DpchAppDo() : DpchAppBrly(VecBrlyVDpch::DPCHAPPBRLYFLTDETAILDO) {
	ixVDo = 0;
};

string PnlBrlyFltDetail::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltDetail::DpchAppDo::readXML(
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
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppBrlyFltDetailDo");
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
 class PnlBrlyFltDetail::DpchEngData
 ******************************************************************************/

PnlBrlyFltDetail::DpchEngData::DpchEngData(
			const ubigint jref
			, ContIac* contiac
			, ContInf* continf
			, Feed* feedFPupEqpEty
			, StatShr* statshr
			, const set<uint>& mask
		) : DpchEngBrly(VecBrlyVDpch::DPCHENGBRLYFLTDETAILDATA, jref) {
	if (find(mask, ALL)) this->mask = {JREF, CONTIAC, CONTINF, FEEDFPUPEQPETY, STATAPP, STATSHR, TAG};
	else this->mask = mask;

	if (find(this->mask, CONTIAC) && contiac) this->contiac = *contiac;
	if (find(this->mask, CONTINF) && continf) this->continf = *continf;
	if (find(this->mask, FEEDFPUPEQPETY) && feedFPupEqpEty) this->feedFPupEqpEty = *feedFPupEqpEty;
	if (find(this->mask, STATSHR) && statshr) this->statshr = *statshr;
};

string PnlBrlyFltDetail::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(JREF)) ss.push_back("jref");
	if (has(CONTIAC)) ss.push_back("contiac");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(FEEDFPUPEQPETY)) ss.push_back("feedFPupEqpEty");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlBrlyFltDetail::DpchEngData::merge(
			DpchEngBrly* dpcheng
		) {
	DpchEngData* src = (DpchEngData*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTIAC)) {contiac = src->contiac; add(CONTIAC);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFPUPEQPETY)) {feedFPupEqpEty = src->feedFPupEqpEty; add(FEEDFPUPEQPETY);};
	if (src->has(STATAPP)) add(STATAPP);
	if (src->has(STATSHR)) {statshr = src->statshr; add(STATSHR);};
	if (src->has(TAG)) add(TAG);
};

void PnlBrlyFltDetail::DpchEngData::writeXML(
			const uint ixBrlyVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngBrlyFltDetailData");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTIAC)) contiac.writeXML(wr);
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFPUPEQPETY)) feedFPupEqpEty.writeXML(wr);
		if (has(STATAPP)) StatApp::writeXML(wr);
		if (has(STATSHR)) statshr.writeXML(wr);
		if (has(TAG)) Tag::writeXML(ixBrlyVLocale, wr);
	xmlTextWriterEndElement(wr);
};

