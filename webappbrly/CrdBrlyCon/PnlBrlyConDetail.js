/**
  * \file PnlBrlyConDetail.js
  * web client functionality for panel PnlBrlyConDetail
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppBrlyConDetail", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyConDetail", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlBrlyConDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyConDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyConDetail", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyConDetail", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlBrlyConDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlBrlyConDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyConDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptFlt", retrieveTi(srcdoc, "TagBrlyConDetail", "CptFlt"));
	initCpt(contcontdoc, "CptCor", retrieveTi(srcdoc, "TagBrlyConDetail", "CptCor"));
	initCpt(contcontdoc, "CptSta", retrieveTi(srcdoc, "TagBrlyConDetail", "CptSta"));
	initCpt(contcontdoc, "CptSto", retrieveTi(srcdoc, "TagBrlyConDetail", "CptSto"));
	initCpt(contcontdoc, "CptMod", retrieveTi(srcdoc, "TagBrlyConDetail", "CptMod"));
	refreshPup(contcontdoc, srcdoc, "PupMod", "", "FeedFPupMod", retrieveCi(srcdoc, "ContIacBrlyConDetail", "numFPupMod"), retrieveSi(srcdoc, "StatShrBrlyConDetail", "PupModActive"), false);
	initCpt(contcontdoc, "CptTtb", retrieveTi(srcdoc, "TagBrlyConDetail", "CptTtb"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyConDetail", "srefIxBrlyVExpstate");

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
	var height = 256; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtFltActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "TxtFltActive") == "true");
	var ButFltViewAvail = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "ButFltViewAvail") == "true");
	var ButFltViewActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "ButFltViewActive") == "true");

	var TxtCorActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "TxtCorActive") == "true");

	var TxfStaActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "TxfStaActive") == "true");

	var TxfStoActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "TxfStoActive") == "true");

	var PupModActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "PupModActive") == "true");

	var TxtTtbActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "TxtTtbActive") == "true");
	var ButTtbViewAvail = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "ButTtbViewAvail") == "true");
	var ButTtbViewActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "ButTtbViewActive") == "true");

	var LstEtyAlt = (retrieveSi(srcdoc, "StatAppBrlyConDetail", "LstEtyAlt") == "true");
	var TxfEtyValid = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "TxfEtyValid") == "true");
	var LstEtyActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "LstEtyActive") == "true");
	var ButEtyEditAvail = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "ButEtyEditAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrBrlyConDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButFltViewAvail == !contcontdoc.getElementById("ButFltView"))) {
		mytd = contcontdoc.getElementById("rdynFlt");
		clearElem(mytd);

		first = true;

		if (ButFltViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFltView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtFlt", retrieveCi(srcdoc, "ContInfBrlyConDetail", "TxtFlt"));

	if (ButFltViewAvail) refreshButicon(contcontdoc, "ButFltView", "icon/view", ButFltViewActive, false);

	refreshTxt(contcontdoc, "TxtCor", retrieveCi(srcdoc, "ContInfBrlyConDetail", "TxtCor"));

	refreshTxf(contcontdoc, "TxfSta", "", retrieveCi(srcdoc, "ContIacBrlyConDetail", "TxfSta"), TxfStaActive, false, true);

	refreshTxf(contcontdoc, "TxfSto", "", retrieveCi(srcdoc, "ContIacBrlyConDetail", "TxfSto"), TxfStoActive, false, true);

	contcontdoc.getElementById("PupMod").value = retrieveCi(srcdoc, "ContIacBrlyConDetail", "numFPupMod");

	if ((ButTtbViewAvail == !contcontdoc.getElementById("ButTtbView"))) {
		mytd = contcontdoc.getElementById("rdynTtb");
		clearElem(mytd);

		first = true;

		if (ButTtbViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTtbView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtTtb", retrieveCi(srcdoc, "ContInfBrlyConDetail", "TxtTtb"));

	if (ButTtbViewAvail) refreshButicon(contcontdoc, "ButTtbView", "icon/view", ButTtbViewActive, false);

	height -= setCtlAvail(contcontdoc, "Ety2", !LstEtyAlt, 71);
	if ( (LstEtyAlt == !contcontdoc.getElementById("ButEtyExpand")) || (!LstEtyAlt == !contcontdoc.getElementById("ButEtyCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynEty");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptEty", retrieveTi(srcdoc, "TagBrlyConDetail", "CptEty")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstEtyAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButEtyExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButEtyCollapse", "icon/collapse"));
	};

	if ( (LstEtyAlt == !contcontdoc.getElementById("TxfEty")) || (!LstEtyAlt == !contcontdoc.getElementById("LstEty")) ) {
		mytd = contcontdoc.getElementById("dynEty");
		clearElem(mytd);

		if (LstEtyAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxf(contcontdoc, "TxfEty", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstEty", "./PnlBrlyConDetail_LstEty.xml", false));
		};

	} else {
		if (!LstEtyAlt) refreshLst(contcontdoc.getElementById("LstEty").contentWindow.document, srcdoc, 1, false, true, "FeedFLstEty",
					parseInt(retrieveSi(srcdoc, "StatAppBrlyConDetail", "LstEtyNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacBrlyConDetail", "numsFLstEty")));
	};

	if (LstEtyAlt) refreshTxf(contcontdoc, "TxfEty", "", retrieveCi(srcdoc, "ContIacBrlyConDetail", "TxfEty"), LstEtyActive, false, TxfEtyValid);

	if ((ButEtyEditAvail == !contcontdoc.getElementById("ButEtyEdit"))) {
		mytd = contcontdoc.getElementById("rdynEty");
		clearElem(mytd);

		first = true;

		if (ButEtyEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButEtyEdit", "icon/edit"));
		};
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
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyConDetail", "srefIxBrlyVExpstate");

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
	setSi(srcdoc, "StatAppBrlyConDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppBrlyConDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyConDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyConDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyConDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyConDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacBrlyConDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyConDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacBrlyConDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacBrlyConDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacBrlyConDetail", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacBrlyConDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacBrlyConDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConDetailData", scrJref, "ContIacBrlyConDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppBrlyConDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppBrlyConDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacBrlyConDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacBrlyConDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacBrlyConDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConDetailData", scrJref, "ContIacBrlyConDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacBrlyConDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConDetailData", scrJref, "ContIacBrlyConDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacBrlyConDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConDetailData", scrJref, "ContIacBrlyConDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyConDetailData", "ContIacBrlyConDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyConDetailData", "ContInfBrlyConDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyConDetailData", "FeedFLstEty", srcdoc)) mask.push("feedFLstEty");
	if (updateSrcblock(dom, "DpchEngBrlyConDetailData", "FeedFPupMod", srcdoc)) mask.push("feedFPupMod");
	if (updateSrcblock(dom, "DpchEngBrlyConDetailData", "StatAppBrlyConDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyConDetailData", "StatShrBrlyConDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyConDetailData", "TagBrlyConDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyConDetailData") {
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
			if (blk.nodeName == "DpchEngBrlyConDetailData") {
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

			} else if (blk.nodeName == "DpchEngBrlyConDetailData") {
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

