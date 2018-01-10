/**
  * \file DlgBrlyLegNew.js
  * web client functionality for dialog DlgBrlyLegNew
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptTyp", retrieveTi(srcdoc, "TagDlgBrlyLegNewDet", "CptTyp"));
	refreshPup(contdoc, srcdoc, "PupTyp", "", "FeedFDetPupTyp", retrieveCi(srcdoc, "ContIacDlgBrlyLegNewDet", "numFPupTyp"), true, false);
	initCpt(contdoc, "CptBgn", retrieveTi(srcdoc, "TagDlgBrlyLegNewDet", "CptBgn"));
	initCpt(contdoc, "CptEnd", retrieveTi(srcdoc, "TagDlgBrlyLegNewDet", "CptEnd"));
	initBut(contdoc, "ButCre", retrieveTi(srcdoc, "TagDlgBrlyLegNewDet", "ButCre"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgBrlyLegNew", "initdone", "true");

	refreshDet();
};

function initInc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initInc --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgBrlyLegNewInc", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgBrlyLegNewInc", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgBrlyLegNewInc", "ButSto"));
	// IP initInc --- END

	setSi(srcdoc, "StatAppDlgBrlyLegNew", "initdone", "true");

	refreshInc();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgBrlyLegNew", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgBrlyLegNew", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgBrlyLegNew", "numFDse"));

	var num;
	var active, sref, Title;

	var myspan, myrect;

	for (num=1 ; num<=2 ; num++) {
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

	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgBrlyLegNewDet", "ButCreActive") == "true");

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	contdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacDlgBrlyLegNewDet", "numFPupTyp");

	refreshTxf(contdoc, "TxfBgn", "", retrieveCi(srcdoc, "ContIacDlgBrlyLegNewDet", "TxfBgn"), true, false, true);

	refreshTxf(contdoc, "TxfEnd", "", retrieveCi(srcdoc, "ContIacDlgBrlyLegNewDet", "TxfEnd"), true, false, true);

	refreshBut(contdoc, "ButCre", ButCreActive, false);

	// IP refreshDet --- END
};

function refreshInc() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshInc.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgBrlyLegNewInc", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgBrlyLegNewInc", "ButStoActive") == "true");

	// IP refreshInc.vars --- END

	// IP refreshInc --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgBrlyLegNewInc", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshInc --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgBrlyLegNew", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgBrlyLegNew", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgBrlyLegNew" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Inc") {
			refreshInc();
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

// --- specific event handlers for app controls of dialog item Inc

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgBrlyLegNewDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgBrlyLegNew", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgBrlyLegNew", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgBrlyLegNew", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyLegNewData", scrJref, "ContIacDlgBrlyLegNew");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handlePupChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgBrlyLegNew" + ditshort, "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyLegNewData", scrJref, "ContIacDlgBrlyLegNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgBrlyLegNew" + ditshort, ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyLegNewData", scrJref, "ContIacDlgBrlyLegNew" + ditshort);
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgBrlyLegNew" + ditshort, ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyLegNewData", scrJref, "ContIacDlgBrlyLegNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "ContIacDlgBrlyLegNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "ContIacDlgBrlyLegNewDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "ContInfDlgBrlyLegNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "ContInfDlgBrlyLegNewInc", srcdoc)) mask.push("continfinc");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "FeedFDetPupTyp", srcdoc)) mask.push("feedFDetPupTyp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "StatAppDlgBrlyLegNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "StatShrDlgBrlyLegNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "StatShrDlgBrlyLegNewDet", srcdoc)) mask.push("statshrdet");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "StatShrDlgBrlyLegNewInc", srcdoc)) mask.push("statshrinc");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "TagDlgBrlyLegNew", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "TagDlgBrlyLegNewDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgBrlyLegNewData", "TagDlgBrlyLegNewInc", srcdoc)) mask.push("taginc");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgBrlyLegNewData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgBrlyLegNewData") {
		handleDpchEngDlgBrlyLegNewData(dom);
	};
};

function handleDpchEngDlgBrlyLegNewData(dom) {
	// IP handleDpchEngDlgBrlyLegNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgBrlyLegNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgBrlyLegNewData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

