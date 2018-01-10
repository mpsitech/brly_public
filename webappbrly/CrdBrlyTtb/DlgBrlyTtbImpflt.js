/**
  * \file DlgBrlyTtbImpflt.js
  * web client functionality for dialog DlgBrlyTtbImpflt
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initIfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initIfi --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltIfi", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltIfi", "Uld");
	// IP initIfi --- END

	setSi(srcdoc, "StatAppDlgBrlyTtbImpflt", "initdone", "true");

	refreshIfi();
};

function initImp() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initImp --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltImp", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltImp", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltImp", "ButSto"));
	// IP initImp --- END

	setSi(srcdoc, "StatAppDlgBrlyTtbImpflt", "initdone", "true");

	refreshImp();
};

function initPpr() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initPpr --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltPpr", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltPpr", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltPpr", "ButSto"));
	// IP initPpr --- END

	setSi(srcdoc, "StatAppDlgBrlyTtbImpflt", "initdone", "true");

	refreshPpr();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgBrlyTtbImpfltLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgBrlyTtbImpflt", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgBrlyTtbImpflt", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgBrlyTtbImpflt", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgBrlyTtbImpflt", "numFDse"));

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

function refreshIfi() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshIfi.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbImpfltIfi", "UldActive") == "true");

	// IP refreshIfi.vars --- END

	// IP refreshIfi --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshIfi --- END
};

function refreshImp() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshImp.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbImpfltImp", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbImpfltImp", "ButStoActive") == "true");

	// IP refreshImp.vars --- END

	// IP refreshImp --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgBrlyTtbImpfltImp", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshImp --- END
};

function refreshPpr() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshPpr.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbImpfltPpr", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbImpfltPpr", "ButStoActive") == "true");

	// IP refreshPpr.vars --- END

	// IP refreshPpr --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgBrlyTtbImpfltPpr", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshPpr --- END
};

function refreshLfi() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbImpfltLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN

	if (DldActive) {
		contdoc.getElementById("Dld").setAttribute("class", "but");
		contdoc.getElementById("Dld").setAttribute("href", "/download/" + scrJref);
		contdoc.getElementById("Dld").setAttribute("target", "_blank");
	} else {
		contdoc.getElementById("Dld").setAttribute("class", "butinact");
		contdoc.getElementById("Dld").setAttribute("href", "#");
		contdoc.getElementById("Dld").setAttribute("target", "_self");
	};

	// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgBrlyTtbImpflt", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgBrlyTtbImpflt", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgBrlyTtbImpflt" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Ifi") {
			refreshIfi();
		} else if (shortDit == "Imp") {
			refreshImp();
		} else if (shortDit == "Ppr") {
			refreshPpr();
		} else if (shortDit == "Lfi") {
			refreshLfi();
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

// --- specific event handlers for app controls of dialog item Ifi

// --- specific event handlers for app controls of dialog item Imp

// --- specific event handlers for app controls of dialog item Ppr

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgBrlyTtbImpfltDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgBrlyTtbImpflt", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgBrlyTtbImpflt", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgBrlyTtbImpflt", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyTtbImpfltData", scrJref, "ContIacDlgBrlyTtbImpflt");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "ContIacDlgBrlyTtbImpflt", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "ContInfDlgBrlyTtbImpflt", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "ContInfDlgBrlyTtbImpfltImp", srcdoc)) mask.push("continfimp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "ContInfDlgBrlyTtbImpfltPpr", srcdoc)) mask.push("continfppr");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "StatAppDlgBrlyTtbImpflt", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "StatShrDlgBrlyTtbImpflt", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "StatShrDlgBrlyTtbImpfltIfi", srcdoc)) mask.push("statshrifi");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "StatShrDlgBrlyTtbImpfltImp", srcdoc)) mask.push("statshrimp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "StatShrDlgBrlyTtbImpfltLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "StatShrDlgBrlyTtbImpfltPpr", srcdoc)) mask.push("statshrppr");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "TagDlgBrlyTtbImpflt", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "TagDlgBrlyTtbImpfltIfi", srcdoc)) mask.push("tagifi");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "TagDlgBrlyTtbImpfltImp", srcdoc)) mask.push("tagimp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "TagDlgBrlyTtbImpfltLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgBrlyTtbImpfltData", "TagDlgBrlyTtbImpfltPpr", srcdoc)) mask.push("tagppr");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgBrlyTtbImpfltData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgBrlyTtbImpfltData") {
		handleDpchEngDlgBrlyTtbImpfltData(dom);
	};
};

function handleDpchEngDlgBrlyTtbImpfltData(dom) {
	// IP handleDpchEngDlgBrlyTtbImpfltData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgBrlyTtbImpfltData") {
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

			} else if (blk.nodeName == "DpchEngDlgBrlyTtbImpfltData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

