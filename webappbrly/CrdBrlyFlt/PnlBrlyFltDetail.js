/**
  * \file PnlBrlyFltDetail.js
  * web client functionality for panel PnlBrlyFltDetail
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppBrlyFltDetail", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyFltDetail", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlBrlyFltDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyFltDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyFltDetail", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyFltDetail", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlBrlyFltDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyFltDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyFltDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTtb", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptTtb"));
	initCpt(contcontdoc, "CptLeg", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptLeg"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptSto"));
	initCpt(contcontdoc, "CptXsa", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptXsa"));
	initCpt(contcontdoc, "CptXso", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptXso"));
	initCpt(contcontdoc, "CptCdn", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptCdn"));
	initCpt(contcontdoc, "CptSdn", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptSdn"));
	initCpt(contcontdoc, "CptFafFid", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafFid"));
	initCpt(contcontdoc, "CptFafIdt", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafIdt"));
	initCpt(contcontdoc, "CptFafAct", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafAct"));
	initCpt(contcontdoc, "CptFafFet", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafFet"));
	initCpt(contcontdoc, "CptFafFti", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafFti"));
	initCpt(contcontdoc, "CptFafFdt", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafFdt"));
	initCpt(contcontdoc, "CptFafFsk", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafFsk"));
	initCpt(contcontdoc, "CptFafFsm", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafFsm"));
	initCpt(contcontdoc, "CptFafFat", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafFat"));
	initCpt(contcontdoc, "CptFafRte", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafRte"));
	initCpt(contcontdoc, "CptFafAdt", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafAdt"));
	initCpt(contcontdoc, "CptFafEat", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafEat"));
	initCpt(contcontdoc, "CptFafAat", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafAat"));
	initCpt(contcontdoc, "CptFafDvt", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafDvt"));
	initCpt(contcontdoc, "CptFafOrg", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafOrg"));
	initCpt(contcontdoc, "CptFafDst", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafDst"));
	initCpt(contcontdoc, "CptFafOnm", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafOnm"));
	initCpt(contcontdoc, "CptFafOct", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafOct"));
	initCpt(contcontdoc, "CptFafDnm", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafDnm"));
	initCpt(contcontdoc, "CptFafDct", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptFafDct"));
	initCpt(contcontdoc, "CptEqpOpr", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptEqpOpr"));
	initCpt(contcontdoc, "CptEqpPty", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptEqpPty"));
	initCpt(contcontdoc, "CptEqpEty", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptEqpEty"));
	initCpt(contcontdoc, "CptEqpFib", retrieveTi(srcdoc, "TagBrlyFltDetail", "CptEqpFib"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyFltDetail", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		initA();
	} else if (srefIxBrlyVExpstate == "regd") {
		initBD(true);
	} else if (srefIxBrlyVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	var height = 956; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxtSrfActive") == "true");

	var TxtTtbActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxtTtbActive") == "true");
	var ButTtbViewAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButTtbViewAvail") == "true");
	var ButTtbViewActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButTtbViewActive") == "true");

	var TxtLegActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxtLegActive") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfStoActive") == "true");

	var TxfXsaActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfXsaActive") == "true");

	var TxfXsoActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfXsoActive") == "true");

	var ChkCdnActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ChkCdnActive") == "true");

	var ChkSdnActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ChkSdnActive") == "true");

	var ButFafNewAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButFafNewAvail") == "true");
	var ButFafDeleteAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButFafDeleteAvail") == "true");

	var TxfFafFidAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFidAvail") == "true");
	var TxfFafFidActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFidActive") == "true");

	var TxfFafIdtAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafIdtAvail") == "true");
	var TxfFafIdtActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafIdtActive") == "true");

	var TxfFafActAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafActAvail") == "true");
	var TxfFafActActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafActActive") == "true");

	var TxfFafFetAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFetAvail") == "true");
	var TxfFafFetActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFetActive") == "true");

	var TxfFafFtiAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFtiAvail") == "true");
	var TxfFafFtiActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFtiActive") == "true");

	var TxfFafFdtAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFdtAvail") == "true");
	var TxfFafFdtActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFdtActive") == "true");

	var TxfFafFskAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFskAvail") == "true");
	var TxfFafFskActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFskActive") == "true");

	var TxfFafFsmAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFsmAvail") == "true");
	var TxfFafFsmActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFsmActive") == "true");

	var TxfFafFatAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFatAvail") == "true");
	var TxfFafFatActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafFatActive") == "true");

	var TxfFafRteAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafRteAvail") == "true");
	var TxfFafRteActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafRteActive") == "true");

	var TxfFafAdtAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafAdtAvail") == "true");
	var TxfFafAdtActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafAdtActive") == "true");

	var TxfFafEatAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafEatAvail") == "true");
	var TxfFafEatActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafEatActive") == "true");

	var TxfFafAatAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafAatAvail") == "true");
	var TxfFafAatActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafAatActive") == "true");

	var TxfFafDvtAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafDvtAvail") == "true");
	var TxfFafDvtActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafDvtActive") == "true");

	var TxfFafOrgAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafOrgAvail") == "true");
	var TxfFafOrgActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafOrgActive") == "true");

	var TxfFafDstAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafDstAvail") == "true");
	var TxfFafDstActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafDstActive") == "true");

	var TxfFafOnmAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafOnmAvail") == "true");
	var TxfFafOnmActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafOnmActive") == "true");

	var TxfFafOctAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafOctAvail") == "true");
	var TxfFafOctActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafOctActive") == "true");

	var TxfFafDnmAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafDnmAvail") == "true");
	var TxfFafDnmActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafDnmActive") == "true");

	var TxfFafDctAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafDctAvail") == "true");
	var TxfFafDctActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfFafDctActive") == "true");

	var ButEqpNewAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButEqpNewAvail") == "true");
	var ButEqpDeleteAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButEqpDeleteAvail") == "true");

	var TxtEqpOprAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxtEqpOprAvail") == "true");
	var TxtEqpOprActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxtEqpOprActive") == "true");
	var ButEqpOprViewAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButEqpOprViewAvail") == "true");
	var ButEqpOprViewActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButEqpOprViewActive") == "true");

	var TxtEqpPtyAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxtEqpPtyAvail") == "true");
	var TxtEqpPtyActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxtEqpPtyActive") == "true");
	var ButEqpPtyViewAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButEqpPtyViewAvail") == "true");
	var ButEqpPtyViewActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButEqpPtyViewActive") == "true");

	var PupEqpEtyAlt = (retrieveSi(srcdoc, "StatAppBrlyFltDetail", "PupEqpEtyAlt") == "true");
	var TxfEqpEtyValid = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "TxfEqpEtyValid") == "true");
	var PupEqpEtyAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "PupEqpEtyAvail") == "true");
	var PupEqpEtyActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "PupEqpEtyActive") == "true");
	var ButEqpEtyEditAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButEqpEtyEditAvail") == "true");

	var ChkEqpFibAvail = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ChkEqpFibAvail") == "true");
	var ChkEqpFibActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ChkEqpFibActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrBrlyFltDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfBrlyFltDetail", "TxtSrf"));

	if ((ButTtbViewAvail == !contcontdoc.getElementById("ButTtbView"))) {
		mytd = contcontdoc.getElementById("rdynTtb");
		clearElem(mytd);

		first = true;

		if (ButTtbViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTtbView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtTtb", retrieveCi(srcdoc, "ContInfBrlyFltDetail", "TxtTtb"));

	if (ButTtbViewAvail) refreshButicon(contcontdoc, "ButTtbView", "icon/view", ButTtbViewActive, false);

	refreshTxt(contcontdoc, "TxtLeg", retrieveCi(srcdoc, "ContInfBrlyFltDetail", "TxtLeg"));

	refreshTxf(contcontdoc, "TxfSta", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfSto"), TxfStoActive, false, true);

	refreshTxf(contcontdoc, "TxfXsa", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfXsa"), TxfXsaActive, false, true);

	refreshTxf(contcontdoc, "TxfXso", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfXso"), TxfXsoActive, false, true);

	refreshChk(contcontdoc, "ChkCdn", (retrieveCi(srcdoc, "ContIacBrlyFltDetail", "ChkCdn") == "true"), ChkCdnActive);

	refreshChk(contcontdoc, "ChkSdn", (retrieveCi(srcdoc, "ContIacBrlyFltDetail", "ChkSdn") == "true"), ChkSdnActive);

	if ((ButFafNewAvail == !contcontdoc.getElementById("ButFafNew")) || (ButFafDeleteAvail == !contcontdoc.getElementById("ButFafDelete"))) {
		mytd = contcontdoc.getElementById("dynFaf");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgFaf", retrieveTi(srcdoc, "TagBrlyFltDetail", "HdgFaf")));
		mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

		first = true;

		if (ButFafNewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFafNew", "icon/new"));
		};

		if (ButFafDeleteAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFafDelete", "icon/delete"));
		};
	};

	height -= setCtlAvail(contcontdoc, "FafFid", TxfFafFidAvail, 25);
	if (TxfFafFidAvail) {
		refreshTxf(contcontdoc, "TxfFafFid", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafFid"), TxfFafFidActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafIdt", TxfFafIdtAvail, 25);
	if (TxfFafIdtAvail) {
		refreshTxf(contcontdoc, "TxfFafIdt", "xs", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafIdt"), TxfFafIdtActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafAct", TxfFafActAvail, 25);
	if (TxfFafActAvail) {
		refreshTxf(contcontdoc, "TxfFafAct", "xs", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafAct"), TxfFafActActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafFet", TxfFafFetAvail, 25);
	if (TxfFafFetAvail) {
		refreshTxf(contcontdoc, "TxfFafFet", "xs", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafFet"), TxfFafFetActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafFti", TxfFafFtiAvail, 25);
	if (TxfFafFtiAvail) {
		refreshTxf(contcontdoc, "TxfFafFti", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafFti"), TxfFafFtiActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafFdt", TxfFafFdtAvail, 25);
	if (TxfFafFdtAvail) {
		refreshTxf(contcontdoc, "TxfFafFdt", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafFdt"), TxfFafFdtActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafFsk", TxfFafFskAvail, 25);
	if (TxfFafFskAvail) {
		refreshTxf(contcontdoc, "TxfFafFsk", "s", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafFsk"), TxfFafFskActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafFsm", TxfFafFsmAvail, 25);
	if (TxfFafFsmAvail) {
		refreshTxf(contcontdoc, "TxfFafFsm", "s", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafFsm"), TxfFafFsmActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafFat", TxfFafFatAvail, 25);
	if (TxfFafFatAvail) {
		refreshTxf(contcontdoc, "TxfFafFat", "s", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafFat"), TxfFafFatActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafRte", TxfFafRteAvail, 75);
	if (TxfFafRteAvail) {
		refreshTxft(contcontdoc, "TxfFafRte", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafRte"), TxfFafRteActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafAdt", TxfFafAdtAvail, 25);
	if (TxfFafAdtAvail) {
		refreshTxf(contcontdoc, "TxfFafAdt", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafAdt"), TxfFafAdtActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafEat", TxfFafEatAvail, 25);
	if (TxfFafEatAvail) {
		refreshTxf(contcontdoc, "TxfFafEat", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafEat"), TxfFafEatActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafAat", TxfFafAatAvail, 25);
	if (TxfFafAatAvail) {
		refreshTxf(contcontdoc, "TxfFafAat", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafAat"), TxfFafAatActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafDvt", TxfFafDvtAvail, 25);
	if (TxfFafDvtAvail) {
		refreshTxf(contcontdoc, "TxfFafDvt", "xs", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafDvt"), TxfFafDvtActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafOrg", TxfFafOrgAvail, 25);
	if (TxfFafOrgAvail) {
		refreshTxf(contcontdoc, "TxfFafOrg", "xs", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafOrg"), TxfFafOrgActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafDst", TxfFafDstAvail, 25);
	if (TxfFafDstAvail) {
		refreshTxf(contcontdoc, "TxfFafDst", "xs", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafDst"), TxfFafDstActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafOnm", TxfFafOnmAvail, 25);
	if (TxfFafOnmAvail) {
		refreshTxf(contcontdoc, "TxfFafOnm", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafOnm"), TxfFafOnmActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafOct", TxfFafOctAvail, 25);
	if (TxfFafOctAvail) {
		refreshTxf(contcontdoc, "TxfFafOct", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafOct"), TxfFafOctActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafDnm", TxfFafDnmAvail, 25);
	if (TxfFafDnmAvail) {
		refreshTxf(contcontdoc, "TxfFafDnm", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafDnm"), TxfFafDnmActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "FafDct", TxfFafDctAvail, 25);
	if (TxfFafDctAvail) {
		refreshTxf(contcontdoc, "TxfFafDct", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfFafDct"), TxfFafDctActive, false, true);

	};

	if ((ButEqpNewAvail == !contcontdoc.getElementById("ButEqpNew")) || (ButEqpDeleteAvail == !contcontdoc.getElementById("ButEqpDelete"))) {
		mytd = contcontdoc.getElementById("dynEqp");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgEqp", retrieveTi(srcdoc, "TagBrlyFltDetail", "HdgEqp")));
		mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

		first = true;

		if (ButEqpNewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButEqpNew", "icon/new"));
		};

		if (ButEqpDeleteAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButEqpDelete", "icon/delete"));
		};
	};

	height -= setCtlAvail(contcontdoc, "EqpOpr", TxtEqpOprAvail, 25);
	if (TxtEqpOprAvail) {
		if ((ButEqpOprViewAvail == !contcontdoc.getElementById("ButEqpOprView"))) {
			mytd = contcontdoc.getElementById("rdynEqpOpr");
			clearElem(mytd);

			first = true;

			if (ButEqpOprViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButEqpOprView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtEqpOpr", retrieveCi(srcdoc, "ContInfBrlyFltDetail", "TxtEqpOpr"));

		if (ButEqpOprViewAvail) refreshButicon(contcontdoc, "ButEqpOprView", "icon/view", ButEqpOprViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "EqpPty", TxtEqpPtyAvail, 25);
	if (TxtEqpPtyAvail) {
		if ((ButEqpPtyViewAvail == !contcontdoc.getElementById("ButEqpPtyView"))) {
			mytd = contcontdoc.getElementById("rdynEqpPty");
			clearElem(mytd);

			first = true;

			if (ButEqpPtyViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButEqpPtyView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtEqpPty", retrieveCi(srcdoc, "ContInfBrlyFltDetail", "TxtEqpPty"));

		if (ButEqpPtyViewAvail) refreshButicon(contcontdoc, "ButEqpPtyView", "icon/view", ButEqpPtyViewActive, false);

	};

	height -= setCtlAvail(contcontdoc, "EqpEty", PupEqpEtyAvail, 25);
	if (PupEqpEtyAvail) {
		if ( (PupEqpEtyAlt == !contcontdoc.getElementById("TxfEqpEty")) || (!PupEqpEtyAlt == !contcontdoc.getElementById("PupEqpEty")) ) {
			mytd = contcontdoc.getElementById("dynEqpEty");
			clearElem(mytd);

			if (PupEqpEtyAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfEqpEty", ""));
			else mytd.appendChild(makeSelectPup(contcontdoc, "PupEqpEty", ""));
		};

		if (PupEqpEtyAlt) refreshTxf(contcontdoc, "TxfEqpEty", "", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "TxfEqpEty"), PupEqpEtyActive, false, TxfEqpEtyValid);
		else refreshPup(contcontdoc, srcdoc, "PupEqpEty", "", "FeedFPupEqpEty", retrieveCi(srcdoc, "ContIacBrlyFltDetail", "numFPupEqpEty"), true, false);

		if ((ButEqpEtyEditAvail == !contcontdoc.getElementById("ButEqpEtyEdit"))) {
			mytd = contcontdoc.getElementById("rdynEqpEty");
			clearElem(mytd);

			first = true;

			if (ButEqpEtyEditAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButEqpEtyEdit", "icon/edit"));
			};
		};

	};

	height -= setCtlAvail(contcontdoc, "EqpFib", ChkEqpFibAvail, 25);
	if (ChkEqpFibAvail) {
		refreshChk(contcontdoc, "ChkEqpFib", (retrieveCi(srcdoc, "ContIacBrlyFltDetail", "ChkEqpFib") == "true"), ChkEqpFibActive);

	};

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyFltDetail", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		refreshA();
	} else if (srefIxBrlyVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxBrlyVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppBrlyFltDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppBrlyFltDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyFltDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyFltDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyFltDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacBrlyFltDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyFltDetailData", scrJref, "ContIacBrlyFltDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacBrlyFltDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyFltDetailData", scrJref, "ContIacBrlyFltDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacBrlyFltDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyFltDetailData", scrJref, "ContIacBrlyFltDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacBrlyFltDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyFltDetailData", scrJref, "ContIacBrlyFltDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacBrlyFltDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyFltDetailData", scrJref, "ContIacBrlyFltDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyFltDetailData", "ContIacBrlyFltDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyFltDetailData", "ContInfBrlyFltDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyFltDetailData", "FeedFPupEqpEty", srcdoc)) mask.push("feedFPupEqpEty");
	if (updateSrcblock(dom, "DpchEngBrlyFltDetailData", "StatAppBrlyFltDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyFltDetailData", "StatShrBrlyFltDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyFltDetailData", "TagBrlyFltDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyFltDetailData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngBrlyFltDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//brly:*");

		if (blk) {
			if (blk.nodeName == "DpchEngBrlyConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngBrlyFltDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");

		if (blk) {
			if (blk.nodeName == "DpchEngBrlyConfirm") {
				accepted = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:accepted");
				_scrJref = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:scrJref");
				sref = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngBrlyAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//brly:DpchEngBrlyAlert/brly:scrJref"),
						retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:ContInfBrlyAlert"),
						retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:FeedFMcbAlert"));
			};
		};
	};
};

function handleDpchAppDoDlgopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");

		if (blk) {
			if (blk.nodeName == "DpchEngBrlyConfirm") {
				accepted = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:accepted");
				_scrJref = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:scrJref");
				sref = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:sref");

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};

