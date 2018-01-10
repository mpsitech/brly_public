/**
  * \file PnlBrlyPrsDetail.js
  * web client functionality for panel PnlBrlyPrsDetail
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppBrlyPrsDetail", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyPrsDetail", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlBrlyPrsDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyPrsDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyPrsDetail", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyPrsDetail", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlBrlyPrsDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyPrsDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyPrsDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagBrlyPrsDetail", "CptTit"));
	initCpt(contcontdoc, "CptFnm", retrieveTi(srcdoc, "TagBrlyPrsDetail", "CptFnm"));
	initCpt(contcontdoc, "CptLnm", retrieveTi(srcdoc, "TagBrlyPrsDetail", "CptLnm"));
	initCpt(contcontdoc, "CptSex", retrieveTi(srcdoc, "TagBrlyPrsDetail", "CptSex"));
	refreshPup(contcontdoc, srcdoc, "PupSex", "", "FeedFPupSex", retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numFPupSex"), retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "PupSexActive"), false);
	initCpt(contcontdoc, "CptTel", retrieveTi(srcdoc, "TagBrlyPrsDetail", "CptTel"));
	initCpt(contcontdoc, "CptEml", retrieveTi(srcdoc, "TagBrlyPrsDetail", "CptEml"));
	initCpt(contcontdoc, "CptSal", retrieveTi(srcdoc, "TagBrlyPrsDetail", "CptSal"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyPrsDetail", "srefIxBrlyVExpstate");

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
	var height = 313; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxfTitActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "TxfTitActive") == "true");

	var TxfFnmActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "TxfFnmActive") == "true");

	var PupJlnActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "PupJlnActive") == "true");
	var ButJlnEditAvail = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "ButJlnEditAvail") == "true");

	var TxtLnmActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "TxtLnmActive") == "true");

	var LstDrvAlt = (retrieveSi(srcdoc, "StatAppBrlyPrsDetail", "LstDrvAlt") == "true");
	var LstDrvActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "LstDrvActive") == "true");

	var PupSexActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "PupSexActive") == "true");

	var TxfTelActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "TxfTelActive") == "true");

	var TxfEmlActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "TxfEmlActive") == "true");

	var TxfSalActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "TxfSalActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrBrlyPrsDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "TxfTit", "s", retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "TxfTit"), TxfTitActive, false, true);

	refreshTxf(contcontdoc, "TxfFnm", "s", retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "TxfFnm"), TxfFnmActive, false, true);

	if ((ButJlnEditAvail == !contcontdoc.getElementById("ButJlnEdit"))) {
		mytd = contcontdoc.getElementById("rdynJln");
		clearElem(mytd);

		first = true;

		if (ButJlnEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJlnEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJln", "s", "FeedFPupJln", retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numFPupJln"), PupJlnActive, false);

	refreshTxt(contcontdoc, "TxtLnm", retrieveCi(srcdoc, "ContInfBrlyPrsDetail", "TxtLnm"));

	height -= setCtlAvail(contcontdoc, "Drv2", !LstDrvAlt, 71);
	if ( (LstDrvAlt == !contcontdoc.getElementById("ButDrvExpand")) || (!LstDrvAlt == !contcontdoc.getElementById("ButDrvCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynDrv");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptDrv", retrieveTi(srcdoc, "TagBrlyPrsDetail", "CptDrv")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstDrvAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDrvExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButDrvCollapse", "icon/collapse"));
	};

	if ( (LstDrvAlt == !contcontdoc.getElementById("TxtDrv")) || (!LstDrvAlt == !contcontdoc.getElementById("LstDrv")) ) {
		mytd = contcontdoc.getElementById("dynDrv");
		clearElem(mytd);

		if (LstDrvAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtDrv", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstDrv", "./PnlBrlyPrsDetail_LstDrv.xml", false));
		};

	} else {
		if (!LstDrvAlt) refreshLst(contcontdoc.getElementById("LstDrv").contentWindow.document, srcdoc, 1, false, true, "FeedFLstDrv",
					parseInt(retrieveSi(srcdoc, "StatAppBrlyPrsDetail", "LstDrvNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numsFLstDrv")));
	};

	if (LstDrvAlt) refreshTxt(contcontdoc, "TxtDrv", retrieveCi(srcdoc, "ContInfBrlyPrsDetail", "TxtDrv"));

	contcontdoc.getElementById("PupSex").value = retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numFPupSex");

	refreshTxf(contcontdoc, "TxfTel", "", retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "TxfTel"), TxfTelActive, false, true);

	refreshTxf(contcontdoc, "TxfEml", "", retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "TxfEml"), TxfEmlActive, false, true);

	refreshTxf(contcontdoc, "TxfSal", "", retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "TxfSal"), TxfSalActive, false, true);

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
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyPrsDetail", "srefIxBrlyVExpstate");

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
	setSi(srcdoc, "StatAppBrlyPrsDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppBrlyPrsDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyPrsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyPrsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyPrsDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyPrsDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacBrlyPrsDetail", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacBrlyPrsDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyPrsDetailData", scrJref, "ContIacBrlyPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppBrlyPrsDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppBrlyPrsDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacBrlyPrsDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacBrlyPrsDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyPrsDetailData", scrJref, "ContIacBrlyPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacBrlyPrsDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyPrsDetailData", scrJref, "ContIacBrlyPrsDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacBrlyPrsDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyPrsDetailData", scrJref, "ContIacBrlyPrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyPrsDetailData", "ContIacBrlyPrsDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyPrsDetailData", "ContInfBrlyPrsDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyPrsDetailData", "FeedFLstDrv", srcdoc)) mask.push("feedFLstDrv");
	if (updateSrcblock(dom, "DpchEngBrlyPrsDetailData", "FeedFPupJln", srcdoc)) mask.push("feedFPupJln");
	if (updateSrcblock(dom, "DpchEngBrlyPrsDetailData", "FeedFPupSex", srcdoc)) mask.push("feedFPupSex");
	if (updateSrcblock(dom, "DpchEngBrlyPrsDetailData", "StatAppBrlyPrsDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyPrsDetailData", "StatShrBrlyPrsDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyPrsDetailData", "TagBrlyPrsDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyPrsDetailData") {
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
			if (blk.nodeName == "DpchEngBrlyPrsDetailData") {
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

			} else if (blk.nodeName == "DpchEngBrlyPrsDetailData") {
				mergeDpchEngData(dom);
				refresh();
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

