/**
  * \file DlgBrlyTtbNew.js
  * web client functionality for dialog DlgBrlyTtbNew
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgBrlyTtbNew", "Cpt"));

	initCpt(contdoc, "DetCptAli", retrieveTi(srcdoc, "TagDlgBrlyTtbNew", "DetCptAli"));
	initCpt(contdoc, "DetCptTit", retrieveTi(srcdoc, "TagDlgBrlyTtbNew", "DetCptTit"));
	initCpt(contdoc, "DetCptSta", retrieveTi(srcdoc, "TagDlgBrlyTtbNew", "DetCptSta"));
	initCpt(contdoc, "DetCptSto", retrieveTi(srcdoc, "TagDlgBrlyTtbNew", "DetCptSto"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgBrlyTtbNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgBrlyTtbNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshPup(contdoc, srcdoc, "DetPupAli", "", "FeedFDetPupAli", retrieveCi(srcdoc, "ContIacDlgBrlyTtbNew", "numFDetPupAli"), true, false);

	refreshTxf(contdoc, "DetTxfTit", "", retrieveCi(srcdoc, "ContIacDlgBrlyTtbNew", "DetTxfTit"), true, false, true);

	refreshTxf(contdoc, "DetTxfSta", "", retrieveCi(srcdoc, "ContIacDlgBrlyTtbNew", "DetTxfSta"), true, false, true);

	refreshTxf(contdoc, "DetTxfSto", "", retrieveCi(srcdoc, "ContIacDlgBrlyTtbNew", "DetTxfSto"), true, false, true);

	refreshBut(ftrdoc, "ButCnc", ButCncActive, false);
	refreshBut(ftrdoc, "ButCre", ButCreActive, false);
	// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgBrlyTtbNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgBrlyTtbNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyTtbNewData", scrJref, "ContIacDlgBrlyTtbNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgBrlyTtbNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyTtbNewData", scrJref, "ContIacDlgBrlyTtbNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgBrlyTtbNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyTtbNewData", scrJref, "ContIacDlgBrlyTtbNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbNewData", "ContIacDlgBrlyTtbNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbNewData", "ContInfDlgBrlyTtbNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbNewData", "FeedFDetPupAli", srcdoc)) mask.push("feedFDetPupAli");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbNewData", "StatAppDlgBrlyTtbNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbNewData", "StatShrDlgBrlyTtbNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbNewData", "TagDlgBrlyTtbNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgBrlyTtbNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgBrlyTtbNewData") {
		handleDpchEngDlgBrlyTtbNewData(dom);
	};
};

function handleDpchEngDlgBrlyTtbNewData(dom) {
	// IP handleDpchEngDlgBrlyTtbNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgBrlyTtbNewData") {
				mergeDpchEngData(dom);
				init();
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

			} else if (blk.nodeName == "DpchEngBrlyAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//brly:DpchEngBrlyAlert/brly:scrJref"),
							retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:ContInfBrlyAlert"),
							retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgBrlyTtbNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

