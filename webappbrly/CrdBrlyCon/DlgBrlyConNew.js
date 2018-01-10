/**
  * \file DlgBrlyConNew.js
  * web client functionality for dialog DlgBrlyConNew
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptFlt", retrieveTi(srcdoc, "TagDlgBrlyConNewDet", "CptFlt"));
	initCpt(contdoc, "CptMdl", retrieveTi(srcdoc, "TagDlgBrlyConNewDet", "CptMdl"));
	refreshPup(contdoc, srcdoc, "PupMdl", "", "FeedFDetPupMdl", retrieveCi(srcdoc, "ContIacDlgBrlyConNewDet", "numFPupMdl"), true, false);
	initCpt(contdoc, "CptTtb", retrieveTi(srcdoc, "TagDlgBrlyConNewDet", "CptTtb"));
	initCpt(contdoc, "CptEty", retrieveTi(srcdoc, "TagDlgBrlyConNewDet", "CptEty"));
	initBut(contdoc, "ButCre", retrieveTi(srcdoc, "TagDlgBrlyConNewDet", "ButCre"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgBrlyConNew", "initdone", "true");

	refreshDet();
};

function initCal() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initCal --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgBrlyConNewCal", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgBrlyConNewCal", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgBrlyConNewCal", "ButSto"));
	// IP initCal --- END

	setSi(srcdoc, "StatAppDlgBrlyConNew", "initdone", "true");

	refreshCal();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgBrlyConNew", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgBrlyConNew", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgBrlyConNew", "numFDse"));

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

	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgBrlyConNewDet", "ButCreActive") == "true");

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	refreshTxf(contdoc, "TxfFlt", "", retrieveCi(srcdoc, "ContIacDlgBrlyConNewDet", "TxfFlt"), true, false, true);

	contdoc.getElementById("PupMdl").value = retrieveCi(srcdoc, "ContIacDlgBrlyConNewDet", "numFPupMdl");

	refreshPup(contdoc, srcdoc, "PupTtb", "", "FeedFDetPupTtb", retrieveCi(srcdoc, "ContIacDlgBrlyConNewDet", "numFPupTtb"), true, false);

	refreshTxf(contdoc, "TxfEty", "", retrieveCi(srcdoc, "ContIacDlgBrlyConNewDet", "TxfEty"), true, false, true);

	refreshBut(contdoc, "ButCre", ButCreActive, false);

	// IP refreshDet --- END
};

function refreshCal() {
	if (!contdoc.getElementById("tbl")) return;

	// IP refreshCal.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgBrlyConNewCal", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgBrlyConNewCal", "ButStoActive") == "true");

	// IP refreshCal.vars --- END

	// IP refreshCal --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgBrlyConNewCal", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshCal --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgBrlyConNew", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgBrlyConNew", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgBrlyConNew" + shortDit + ".xml" 

	} else {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Cal") {
			refreshCal();
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

// --- specific event handlers for app controls of dialog item Cal

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgBrlyConNewDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgBrlyConNew", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgBrlyConNew", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgBrlyConNew", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyConNewData", scrJref, "ContIacDlgBrlyConNew");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handlePupChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgBrlyConNew" + ditshort, "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyConNewData", scrJref, "ContIacDlgBrlyConNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgBrlyConNew" + ditshort, ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyConNewData", scrJref, "ContIacDlgBrlyConNew" + ditshort);
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgBrlyConNew" + ditshort, ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgBrlyConNewData", scrJref, "ContIacDlgBrlyConNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "ContIacDlgBrlyConNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "ContIacDlgBrlyConNewDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "ContInfDlgBrlyConNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "ContInfDlgBrlyConNewCal", srcdoc)) mask.push("continfcal");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "FeedFDetPupMdl", srcdoc)) mask.push("feedFDetPupMdl");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "FeedFDetPupTtb", srcdoc)) mask.push("feedFDetPupTtb");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "StatAppDlgBrlyConNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "StatShrDlgBrlyConNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "StatShrDlgBrlyConNewCal", srcdoc)) mask.push("statshrcal");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "StatShrDlgBrlyConNewDet", srcdoc)) mask.push("statshrdet");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "TagDlgBrlyConNew", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "TagDlgBrlyConNewCal", srcdoc)) mask.push("tagcal");
	if (updateSrcblock(dom, "DpchEngDlgBrlyConNewData", "TagDlgBrlyConNewDet", srcdoc)) mask.push("tagdet");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgBrlyConNewData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgBrlyConNewData") {
		handleDpchEngDlgBrlyConNewData(dom);
	};
};

function handleDpchEngDlgBrlyConNewData(dom) {
	// IP handleDpchEngDlgBrlyConNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgBrlyConNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgBrlyConNewData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

