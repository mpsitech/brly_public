/**
  * \file DlgBrlyTtbTrlorig.js
  * web client functionality for dialog DlgBrlyTtbTrlorig
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptSrc", retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorigDet", "CptSrc"));
	refreshPup(contdoc, srcdoc, "PupSrc", "", "FeedFDetPupSrc", retrieveCi(srcdoc, "ContIacDlgBrlyTtbTrlorigDet", "numFPupSrc"), true, false);
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgBrlyTtbTrlorig", "initdone", "true");

	refreshDet();
};

function initRfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initRfi --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorigRfi", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorigRfi", "Uld");
	// IP initRfi --- END

	setSi(srcdoc, "StatAppDlgBrlyTtbTrlorig", "initdone", "true");

	refreshRfi();
};

function initTrl() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initTrl --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorigTrl", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorigTrl", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorigTrl", "ButSto"));
	// IP initTrl --- END

	setSi(srcdoc, "StatAppDlgBrlyTtbTrlorig", "initdone", "true");

	refreshTrl();
};

function initTfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initTfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorigTfi", "Dld"));
	// IP initTfi --- END

	setSi(srcdoc, "StatAppDlgBrlyTtbTrlorig", "initdone", "true");

	refreshTfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorig", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgBrlyTtbTrlorig", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgBrlyTtbTrlorig", "numFDse"));

	var num;
	var active, sref, Title;

	var myspan, myrect;

	for (num=1 ; num<=4 ; num++) {
		sref = retrieveValue(srcdoc, "//brly:FeedFDse/brly:Fi[@num='" + num + "']/brly:sref");
		Title = retrieveValue(srcdoc, "//brly:FeedFDse/brly:Fi[@num='" + num + "']/brly:tit1");

		myspan = hdrdoc.getElementById("Cpt" + sref);
		myrect = hdrdoc.getElementById("Dit" + sref);

		setTextContent(hdrdoc, myspan, Title);

		if (num == numFDse) {
			myspan.setAttribute("class", "hdr_ditsel");
			myrect.setAttribute("class", "hdr_ditsels");
		} else {
			myspan.setAttribute("class", "hdr_dit");
			myspan.setAttribute("onclick", "handleDseSelect(" + num + ")");
			myrect.setAttribute("class", "hdr_dits");
			myrect.setAttribute("onclick", "handleDseSelect(" + num + ")");
		};
	};
};

function refreshDet() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshDet.vars --- BEGIN

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	contdoc.getElementById("PupSrc").value = retrieveCi(srcdoc, "ContIacDlgBrlyTtbTrlorigDet", "numFPupSrc");

	// IP refreshDet --- END
};

function refreshRfi() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshRfi.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbTrlorigRfi", "UldActive") == "true");

	// IP refreshRfi.vars --- END

	// IP refreshRfi --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshRfi --- END
};

function refreshTrl() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshTrl.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbTrlorigTrl", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbTrlorigTrl", "ButStoActive") == "true");

	// IP refreshTrl.vars --- END

	// IP refreshTrl --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgBrlyTtbTrlorigTrl", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshTrl --- END
};

function refreshTfi() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshTfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbTrlorigTfi", "DldActive") == "true");

	// IP refreshTfi.vars --- END

	// IP refreshTfi --- BEGIN

	if (DldActive) {
		contdoc.getElementById("Dld").setAttribute("class", "but");
		contdoc.getElementById("Dld").setAttribute("href", "/download/" + scrJref);
		contdoc.getElementById("Dld").setAttribute("target", "_blank");
	} else {
		contdoc.getElementById("Dld").setAttribute("class", "butinact");
		contdoc.getElementById("Dld").setAttribute("href", "#");
		contdoc.getElementById("Dld").setAttribute("target", "_self");
	};

	// IP refreshTfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgBrlyTtbTrlorig", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbTrlorig", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgBrlyTtbTrlorig" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Rfi") {
			refreshRfi();
		} else if (shortDit == "Trl") {
			refreshTrl();
		} else if (shortDit == "Tfi") {
			refreshTfi();
		};
	};

	// IP refresh --- BEGIN
	refreshBut(ftrdoc, "ButDne", ButDneActive, false);
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

// --- specific event handlers for app controls of dialog item Det

// --- specific event handlers for app controls of dialog item Rfi

// --- specific event handlers for app controls of dialog item Trl

// --- specific event handlers for app controls of dialog item Tfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgBrlyTtbTrlorigDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgBrlyTtbTrlorig", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgBrlyTtbTrlorig", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgBrlyTtbTrlorig", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyTtbTrlorigData", scrJref, "ContIacDlgBrlyTtbTrlorig");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handlePupChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgBrlyTtbTrlorig" + ditshort, "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyTtbTrlorigData", scrJref, "ContIacDlgBrlyTtbTrlorig" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "ContIacDlgBrlyTtbTrlorig", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "ContIacDlgBrlyTtbTrlorigDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "ContInfDlgBrlyTtbTrlorig", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "ContInfDlgBrlyTtbTrlorigTrl", srcdoc)) mask.push("continftrl");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "FeedFDetPupSrc", srcdoc)) mask.push("feedFDetPupSrc");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "StatAppDlgBrlyTtbTrlorig", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "StatShrDlgBrlyTtbTrlorig", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "StatShrDlgBrlyTtbTrlorigRfi", srcdoc)) mask.push("statshrrfi");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "StatShrDlgBrlyTtbTrlorigTfi", srcdoc)) mask.push("statshrtfi");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "StatShrDlgBrlyTtbTrlorigTrl", srcdoc)) mask.push("statshrtrl");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "TagDlgBrlyTtbTrlorig", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "TagDlgBrlyTtbTrlorigDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "TagDlgBrlyTtbTrlorigRfi", srcdoc)) mask.push("tagrfi");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "TagDlgBrlyTtbTrlorigTfi", srcdoc)) mask.push("tagtfi");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbTrlorigData", "TagDlgBrlyTtbTrlorigTrl", srcdoc)) mask.push("tagtrl");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgBrlyTtbTrlorigData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgBrlyTtbTrlorigData") {
		handleDpchEngDlgBrlyTtbTrlorigData(dom);
	};
};

function handleDpchEngDlgBrlyTtbTrlorigData(dom) {
	// IP handleDpchEngDlgBrlyTtbTrlorigData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgBrlyTtbTrlorigData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;

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

			} else if (blk.nodeName == "DpchEngDlgBrlyTtbTrlorigData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

