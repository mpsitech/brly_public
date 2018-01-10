/**
  * \file PnlBrlyRlyDetail.js
  * web client functionality for panel PnlBrlyRlyDetail
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppBrlyRlyDetail", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyRlyDetail", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlBrlyRlyDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyRlyDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyRlyDetail", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyRlyDetail", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlBrlyRlyDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyRlyDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyRlyDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagBrlyRlyDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagBrlyRlyDetail", "CptSto"));
	initCpt(contcontdoc, "CptCon", retrieveTi(srcdoc, "TagBrlyRlyDetail", "CptCon"));
	initCpt(contcontdoc, "CptDir", retrieveTi(srcdoc, "TagBrlyRlyDetail", "CptDir"));
	refreshPup(contcontdoc, srcdoc, "PupDir", "", "FeedFPupDir", retrieveCi(srcdoc, "ContIacBrlyRlyDetail", "numFPupDir"), retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "PupDirActive"), false);
	initCpt(contcontdoc, "CptCtd", retrieveTi(srcdoc, "TagBrlyRlyDetail", "CptCtd"));
	initCpt(contcontdoc, "CptNhp", retrieveTi(srcdoc, "TagBrlyRlyDetail", "CptNhp"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyRlyDetail", "srefIxBrlyVExpstate");

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
	var height = 160; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxfStaActive = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "TxfStoActive") == "true");

	var TxtConActive = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "TxtConActive") == "true");
	var ButConViewAvail = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "ButConViewAvail") == "true");
	var ButConViewActive = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "ButConViewActive") == "true");

	var PupDirActive = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "PupDirActive") == "true");

	var ChkCtdActive = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "ChkCtdActive") == "true");

	var TxfNhpActive = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "TxfNhpActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrBrlyRlyDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "TxfSta", "", retrieveCi(srcdoc, "ContIacBrlyRlyDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "", retrieveCi(srcdoc, "ContIacBrlyRlyDetail", "TxfSto"), TxfStoActive, false, true);

	if ((ButConViewAvail == !contcontdoc.getElementById("ButConView"))) {
		mytd = contcontdoc.getElementById("rdynCon");
		clearElem(mytd);

		first = true;

		if (ButConViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButConView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtCon", retrieveCi(srcdoc, "ContInfBrlyRlyDetail", "TxtCon"));

	if (ButConViewAvail) refreshButicon(contcontdoc, "ButConView", "icon/view", ButConViewActive, false);

	contcontdoc.getElementById("PupDir").value = retrieveCi(srcdoc, "ContIacBrlyRlyDetail", "numFPupDir");

	refreshChk(contcontdoc, "ChkCtd", (retrieveCi(srcdoc, "ContIacBrlyRlyDetail", "ChkCtd") == "true"), ChkCtdActive);

	refreshTxf(contcontdoc, "TxfNhp", "s", retrieveCi(srcdoc, "ContIacBrlyRlyDetail", "TxfNhp"), TxfNhpActive, false, true);

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
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyRlyDetail", "srefIxBrlyVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyRlyDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyRlyDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacBrlyRlyDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyRlyDetailData", scrJref, "ContIacBrlyRlyDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacBrlyRlyDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyRlyDetailData", scrJref, "ContIacBrlyRlyDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacBrlyRlyDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyRlyDetailData", scrJref, "ContIacBrlyRlyDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacBrlyRlyDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyRlyDetailData", scrJref, "ContIacBrlyRlyDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyRlyDetailData", "ContIacBrlyRlyDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyRlyDetailData", "ContInfBrlyRlyDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyRlyDetailData", "FeedFPupDir", srcdoc)) mask.push("feedFPupDir");
	if (updateSrcblock(dom, "DpchEngBrlyRlyDetailData", "StatAppBrlyRlyDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyRlyDetailData", "StatShrBrlyRlyDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyRlyDetailData", "TagBrlyRlyDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyRlyDetailData") {
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
			if (blk.nodeName == "DpchEngBrlyRlyDetailData") {
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

			} else if (blk.nodeName == "DpchEngBrlyRlyDetailData") {
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

