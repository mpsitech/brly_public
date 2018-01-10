/**
  * \file PnlBrlySegDetail.js
  * web client functionality for panel PnlBrlySegDetail
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppBrlySegDetail", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlySegDetail", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlBrlySegDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlySegDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlySegDetail", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlySegDetail", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlBrlySegDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlySegDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlySegDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagBrlySegDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacBrlySegDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptDph", retrieveTi(srcdoc, "TagBrlySegDetail", "CptDph"));
	initCpt(contcontdoc, "CptAl0", retrieveTi(srcdoc, "TagBrlySegDetail", "CptAl0"));
	initCpt(contcontdoc, "CptAl1", retrieveTi(srcdoc, "TagBrlySegDetail", "CptAl1"));
	initCpt(contcontdoc, "CptTh0", retrieveTi(srcdoc, "TagBrlySegDetail", "CptTh0"));
	initCpt(contcontdoc, "CptTh1", retrieveTi(srcdoc, "TagBrlySegDetail", "CptTh1"));
	initCpt(contcontdoc, "CptPh0", retrieveTi(srcdoc, "TagBrlySegDetail", "CptPh0"));
	initCpt(contcontdoc, "CptPh1", retrieveTi(srcdoc, "TagBrlySegDetail", "CptPh1"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagBrlySegDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagBrlySegDetail", "CptSto"));
	initCpt(contcontdoc, "CptCdn", retrieveTi(srcdoc, "TagBrlySegDetail", "CptCdn"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlySegDetail", "srefIxBrlyVExpstate");

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
	var height = 285; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtReuActive = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "ButReuViewActive") == "true");

	var TxfDphActive = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfDphActive") == "true");

	var TxfAl0Active = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfAl0Active") == "true");

	var TxfAl1Active = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfAl1Active") == "true");

	var TxfTh0Active = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfTh0Active") == "true");

	var TxfTh1Active = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfTh1Active") == "true");

	var TxfPh0Active = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfPh0Active") == "true");

	var TxfPh1Active = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfPh1Active") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "TxfStoActive") == "true");

	var ChkCdnActive = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "ChkCdnActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrBrlySegDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButReuViewAvail == !contcontdoc.getElementById("ButReuView"))) {
		mytd = contcontdoc.getElementById("rdynReu");
		clearElem(mytd);

		first = true;

		if (ButReuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButReuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfBrlySegDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacBrlySegDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	refreshTxf(contcontdoc, "TxfDph", "s", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfDph"), TxfDphActive, false, true);

	refreshTxf(contcontdoc, "TxfAl0", "s", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfAl0"), TxfAl0Active, false, true);

	refreshTxf(contcontdoc, "TxfAl1", "s", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfAl1"), TxfAl1Active, false, true);

	refreshTxf(contcontdoc, "TxfTh0", "s", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfTh0"), TxfTh0Active, false, true);

	refreshTxf(contcontdoc, "TxfTh1", "s", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfTh1"), TxfTh1Active, false, true);

	refreshTxf(contcontdoc, "TxfPh0", "s", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfPh0"), TxfPh0Active, false, true);

	refreshTxf(contcontdoc, "TxfPh1", "s", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfPh1"), TxfPh1Active, false, true);

	refreshTxf(contcontdoc, "TxfSta", "", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "", retrieveCi(srcdoc, "ContIacBrlySegDetail", "TxfSto"), TxfStoActive, false, true);

	refreshChk(contcontdoc, "ChkCdn", (retrieveCi(srcdoc, "ContIacBrlySegDetail", "ChkCdn") == "true"), ChkCdnActive);

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
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlySegDetail", "srefIxBrlyVExpstate");

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

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlySegDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlySegDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacBrlySegDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlySegDetailData", scrJref, "ContIacBrlySegDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacBrlySegDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlySegDetailData", scrJref, "ContIacBrlySegDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacBrlySegDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlySegDetailData", scrJref, "ContIacBrlySegDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacBrlySegDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlySegDetailData", scrJref, "ContIacBrlySegDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlySegDetailData", "ContIacBrlySegDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlySegDetailData", "ContInfBrlySegDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlySegDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngBrlySegDetailData", "StatAppBrlySegDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlySegDetailData", "StatShrBrlySegDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlySegDetailData", "TagBrlySegDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlySegDetailData") {
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
			if (blk.nodeName == "DpchEngBrlySegDetailData") {
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

			} else if (blk.nodeName == "DpchEngBrlySegDetailData") {
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

