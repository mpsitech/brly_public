/**
  * \file PnlBrlyLegDetail.js
  * web client functionality for panel PnlBrlyLegDetail
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppBrlyLegDetail", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyLegDetail", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlBrlyLegDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyLegDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyLegDetail", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyLegDetail", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlBrlyLegDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyLegDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyLegDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptBlo", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptBlo"));
	initCpt(contcontdoc, "CptElo", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptElo"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrBrlyLegDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptAlt", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptAlt"));
	initCpt(contcontdoc, "CptDph", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptDph"));
	initCpt(contcontdoc, "CptAph", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptAph"));
	initCpt(contcontdoc, "CptXal", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptXal"));
	initCpt(contcontdoc, "CptXp0", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptXp0"));
	initCpt(contcontdoc, "CptXp1", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptXp1"));
	initCpt(contcontdoc, "CptXap", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptXap"));
	initCpt(contcontdoc, "CptCdn", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptCdn"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyLegDetail", "srefIxBrlyVExpstate");

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
	var height = 388; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtBloActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxtBloActive") == "true");

	var TxtEloActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxtEloActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "PupTypActive") == "true");

	var LstCluAlt = (retrieveSi(srcdoc, "StatAppBrlyLegDetail", "LstCluAlt") == "true");
	var LstCluActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "LstCluActive") == "true");
	var ButCluViewAvail = !LstCluAlt;
	var ButCluViewActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "ButCluViewActive") == "true");
	var ButCluClusterAvail = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "ButCluClusterAvail") == "true");
	var ButCluUnclusterAvail = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "ButCluUnclusterAvail") == "true");

	var TxfAltActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxfAltActive") == "true");

	var TxfDphActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxfDphActive") == "true");

	var TxfAphActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxfAphActive") == "true");

	var TxfXalActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxfXalActive") == "true");

	var TxfXp0Active = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxfXp0Active") == "true");

	var TxfXp1Active = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxfXp1Active") == "true");

	var TxfXapActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "TxfXapActive") == "true");

	var ChkCdnActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "ChkCdnActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrBrlyLegDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtBlo", retrieveCi(srcdoc, "ContInfBrlyLegDetail", "TxtBlo"));

	refreshTxt(contcontdoc, "TxtElo", retrieveCi(srcdoc, "ContInfBrlyLegDetail", "TxtElo"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numFPupTyp");

	height -= setCtlAvail(contcontdoc, "Clu2", !LstCluAlt, 71);
	if ( (LstCluAlt == !contcontdoc.getElementById("ButCluExpand")) || (!LstCluAlt == !contcontdoc.getElementById("ButCluCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynClu");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptClu", retrieveTi(srcdoc, "TagBrlyLegDetail", "CptClu")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstCluAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCluExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButCluCollapse", "icon/collapse"));
	};

	if ( (LstCluAlt == !contcontdoc.getElementById("TxtClu")) || (!LstCluAlt == !contcontdoc.getElementById("LstClu")) ) {
		mytd = contcontdoc.getElementById("dynClu");
		clearElem(mytd);

		if (LstCluAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtClu", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstClu", "./PnlBrlyLegDetail_LstClu.xml", false));
		};

	} else {
		if (!LstCluAlt) refreshLst(contcontdoc.getElementById("LstClu").contentWindow.document, srcdoc, 1, false, false, "FeedFLstClu",
					parseInt(retrieveSi(srcdoc, "StatAppBrlyLegDetail", "LstCluNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numFLstClu"))]);
	};

	if (LstCluAlt) refreshTxt(contcontdoc, "TxtClu", retrieveCi(srcdoc, "ContInfBrlyLegDetail", "TxtClu"));

	if ((ButCluViewAvail == !contcontdoc.getElementById("ButCluView")) || (ButCluClusterAvail == !contcontdoc.getElementById("ButCluCluster")) || (ButCluUnclusterAvail == !contcontdoc.getElementById("ButCluUncluster"))) {
		mytd = contcontdoc.getElementById("rdynClu");
		clearElem(mytd);

		first = true;

		if (ButCluViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluView", "icon/view"));
		};

		if (ButCluClusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluCluster", "icon/cluster"));
		};

		if (ButCluUnclusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluUncluster", "icon/uncluster"));
		};
	};

	if (ButCluViewAvail) refreshButicon(contcontdoc, "ButCluView", "icon/view", ButCluViewActive, false);

	refreshTxf(contcontdoc, "TxfAlt", "s", retrieveCi(srcdoc, "ContIacBrlyLegDetail", "TxfAlt"), TxfAltActive, false, true);

	refreshTxf(contcontdoc, "TxfDph", "s", retrieveCi(srcdoc, "ContIacBrlyLegDetail", "TxfDph"), TxfDphActive, false, true);

	refreshTxf(contcontdoc, "TxfAph", "s", retrieveCi(srcdoc, "ContIacBrlyLegDetail", "TxfAph"), TxfAphActive, false, true);

	refreshTxf(contcontdoc, "TxfXal", "s", retrieveCi(srcdoc, "ContIacBrlyLegDetail", "TxfXal"), TxfXalActive, false, true);

	refreshTxf(contcontdoc, "TxfXp0", "s", retrieveCi(srcdoc, "ContIacBrlyLegDetail", "TxfXp0"), TxfXp0Active, false, true);

	refreshTxf(contcontdoc, "TxfXp1", "s", retrieveCi(srcdoc, "ContIacBrlyLegDetail", "TxfXp1"), TxfXp1Active, false, true);

	refreshTxf(contcontdoc, "TxfXap", "s", retrieveCi(srcdoc, "ContIacBrlyLegDetail", "TxfXap"), TxfXapActive, false, true);

	refreshChk(contcontdoc, "ChkCdn", (retrieveCi(srcdoc, "ContIacBrlyLegDetail", "ChkCdn") == "true"), ChkCdnActive);

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
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyLegDetail", "srefIxBrlyVExpstate");

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

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppBrlyLegDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppBrlyLegDetail", basectlsref + "Alt", "false");
	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyLegDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyLegDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacBrlyLegDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLegDetailData", scrJref, "ContIacBrlyLegDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyLegDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyLegDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numsF" + ctlsref));

		found = false;

		for (var i=0;i<oldNumsFLst.length;i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j=0;j<oldNumsFLst.length;j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i=0;i<oldNumsFLst.length;i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacBrlyLegDetail", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacBrlyLegDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLegDetailData", scrJref, "ContIacBrlyLegDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppBrlyLegDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppBrlyLegDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacBrlyLegDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacBrlyLegDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLegDetailData", scrJref, "ContIacBrlyLegDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacBrlyLegDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLegDetailData", scrJref, "ContIacBrlyLegDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacBrlyLegDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLegDetailData", scrJref, "ContIacBrlyLegDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyLegDetailData", "ContIacBrlyLegDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyLegDetailData", "ContInfBrlyLegDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyLegDetailData", "FeedFLstClu", srcdoc)) mask.push("feedFLstClu");
	if (updateSrcblock(dom, "DpchEngBrlyLegDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngBrlyLegDetailData", "StatAppBrlyLegDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyLegDetailData", "StatShrBrlyLegDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyLegDetailData", "TagBrlyLegDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyLegDetailData") {
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
			if (blk.nodeName == "DpchEngBrlyLegDetailData") {
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

			} else if (blk.nodeName == "DpchEngBrlyLegDetailData") {
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

