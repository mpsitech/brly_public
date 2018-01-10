/**
  * \file PnlBrlyLocDetail.js
  * web client functionality for panel PnlBrlyLocDetail
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppBrlyLocDetail", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyLocDetail", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlBrlyLocDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyLocDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyLocDetail", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyLocDetail", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlBrlyLocDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyLocDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyLocDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptSrf"));
	initCpt(contcontdoc, "CptIca", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptIca"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptTit"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrBrlyLocDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptReg", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptReg"));
	initCpt(contcontdoc, "CptAlt", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptAlt"));
	initCpt(contcontdoc, "CptThe", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptThe"));
	initCpt(contcontdoc, "CptPhi", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptPhi"));
	initCpt(contcontdoc, "CptTz", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptTz"));
	initCpt(contcontdoc, "CptAph", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptAph"));
	initCpt(contcontdoc, "CptCdn", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptCdn"));
	initCpt(contcontdoc, "CptEqpOpr", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptEqpOpr"));
	initCpt(contcontdoc, "CptEqpPty", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptEqpPty"));
	initCpt(contcontdoc, "CptEqpEty", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptEqpEty"));
	initCpt(contcontdoc, "CptEqpFib", retrieveTi(srcdoc, "TagBrlyLocDetail", "CptEqpFib"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyLocDetail", "srefIxBrlyVExpstate");

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
	var height = 424; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxtSrfActive") == "true");

	var TxfIcaActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxfIcaActive") == "true");

	var TxfTitActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxfTitActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "PupTypActive") == "true");

	var TxtRegActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxtRegActive") == "true");

	var TxfAltActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxfAltActive") == "true");

	var TxfTheActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxfTheActive") == "true");

	var TxfPhiActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxfPhiActive") == "true");

	var TxfTzActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxfTzActive") == "true");

	var TxfAphActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxfAphActive") == "true");

	var ChkCdnActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ChkCdnActive") == "true");

	var ButEqpNewAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ButEqpNewAvail") == "true");
	var ButEqpDeleteAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ButEqpDeleteAvail") == "true");

	var TxtEqpOprAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxtEqpOprAvail") == "true");
	var TxtEqpOprActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxtEqpOprActive") == "true");
	var ButEqpOprViewAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ButEqpOprViewAvail") == "true");
	var ButEqpOprViewActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ButEqpOprViewActive") == "true");

	var TxtEqpPtyAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxtEqpPtyAvail") == "true");
	var TxtEqpPtyActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxtEqpPtyActive") == "true");
	var ButEqpPtyViewAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ButEqpPtyViewAvail") == "true");
	var ButEqpPtyViewActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ButEqpPtyViewActive") == "true");

	var PupEqpEtyAlt = (retrieveSi(srcdoc, "StatAppBrlyLocDetail", "PupEqpEtyAlt") == "true");
	var TxfEqpEtyValid = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "TxfEqpEtyValid") == "true");
	var PupEqpEtyAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "PupEqpEtyAvail") == "true");
	var PupEqpEtyActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "PupEqpEtyActive") == "true");
	var ButEqpEtyEditAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ButEqpEtyEditAvail") == "true");

	var ChkEqpFibAvail = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ChkEqpFibAvail") == "true");
	var ChkEqpFibActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ChkEqpFibActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrBrlyLocDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfBrlyLocDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfIca", "xs", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "TxfIca"), TxfIcaActive, false, true);

	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "TxfTit"), TxfTitActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacBrlyLocDetail", "numFPupTyp");

	refreshTxt(contcontdoc, "TxtReg", retrieveCi(srcdoc, "ContInfBrlyLocDetail", "TxtReg"));

	refreshTxf(contcontdoc, "TxfAlt", "s", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "TxfAlt"), TxfAltActive, false, true);

	refreshTxf(contcontdoc, "TxfThe", "s", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "TxfThe"), TxfTheActive, false, true);

	refreshTxf(contcontdoc, "TxfPhi", "s", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "TxfPhi"), TxfPhiActive, false, true);

	refreshTxf(contcontdoc, "TxfTz", "", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "TxfTz"), TxfTzActive, false, true);

	refreshTxf(contcontdoc, "TxfAph", "s", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "TxfAph"), TxfAphActive, false, true);

	refreshChk(contcontdoc, "ChkCdn", (retrieveCi(srcdoc, "ContIacBrlyLocDetail", "ChkCdn") == "true"), ChkCdnActive);

	if ((ButEqpNewAvail == !contcontdoc.getElementById("ButEqpNew")) || (ButEqpDeleteAvail == !contcontdoc.getElementById("ButEqpDelete"))) {
		mytd = contcontdoc.getElementById("dynEqp");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgEqp", retrieveTi(srcdoc, "TagBrlyLocDetail", "HdgEqp")));
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

		refreshTxt(contcontdoc, "TxtEqpOpr", retrieveCi(srcdoc, "ContInfBrlyLocDetail", "TxtEqpOpr"));

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

		refreshTxt(contcontdoc, "TxtEqpPty", retrieveCi(srcdoc, "ContInfBrlyLocDetail", "TxtEqpPty"));

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

		if (PupEqpEtyAlt) refreshTxf(contcontdoc, "TxfEqpEty", "", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "TxfEqpEty"), PupEqpEtyActive, false, TxfEqpEtyValid);
		else refreshPup(contcontdoc, srcdoc, "PupEqpEty", "", "FeedFPupEqpEty", retrieveCi(srcdoc, "ContIacBrlyLocDetail", "numFPupEqpEty"), true, false);

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
		refreshChk(contcontdoc, "ChkEqpFib", (retrieveCi(srcdoc, "ContIacBrlyLocDetail", "ChkEqpFib") == "true"), ChkEqpFibActive);

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
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyLocDetail", "srefIxBrlyVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppBrlyLocDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppBrlyLocDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyLocDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyLocDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyLocDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacBrlyLocDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocDetailData", scrJref, "ContIacBrlyLocDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacBrlyLocDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocDetailData", scrJref, "ContIacBrlyLocDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacBrlyLocDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocDetailData", scrJref, "ContIacBrlyLocDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacBrlyLocDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocDetailData", scrJref, "ContIacBrlyLocDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyLocDetailData", "ContIacBrlyLocDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyLocDetailData", "ContInfBrlyLocDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyLocDetailData", "FeedFPupEqpEty", srcdoc)) mask.push("feedFPupEqpEty");
	if (updateSrcblock(dom, "DpchEngBrlyLocDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngBrlyLocDetailData", "StatAppBrlyLocDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyLocDetailData", "StatShrBrlyLocDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyLocDetailData", "TagBrlyLocDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyLocDetailData") {
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
			if (blk.nodeName == "DpchEngBrlyLocDetailData") {
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

			} else if (blk.nodeName == "DpchEngBrlyLocDetailData") {
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

