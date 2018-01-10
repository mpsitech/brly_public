/**
  * \file PnlBrlyNavConnect.js
  * web client functionality for panel PnlBrlyNavConnect
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppBrlyNavConnect", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyNavConnect", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Connect", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Connect_side").setAttribute("height", "30");
	doc.getElementById("Connect_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Connect_side").src = "./PnlBrlyNavConnect_aside.html";
	doc.getElementById("Connect_cont").src = "./PnlBrlyNavConnect_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyNavConnect", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyNavConnect", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Connect_side").src = "./PnlBrlyNavConnect_bside.html";
	doc.getElementById("Connect_cont").src = "./PnlBrlyNavConnect_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Connect_side").contentDocument;
	contdoc = doc.getElementById("Connect_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyNavConnect", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Connect_side").contentDocument;
	contdoc = doc.getElementById("Connect_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Connect_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Connect_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyNavConnect", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyNavConnect", "srefIxBrlyVExpstate");

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
	var height = 202; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstConAlt = (retrieveSi(srcdoc, "StatAppBrlyNavConnect", "LstConAlt") == "true");
	var LstConAvail = (retrieveSi(srcdoc, "StatShrBrlyNavConnect", "LstConAvail") == "true");
	var ButConViewAvail = !LstConAlt;
	var ButConViewActive = (retrieveSi(srcdoc, "StatShrBrlyNavConnect", "ButConViewActive") == "true");

	var LstRlyAlt = (retrieveSi(srcdoc, "StatAppBrlyNavConnect", "LstRlyAlt") == "true");
	var LstRlyAvail = (retrieveSi(srcdoc, "StatShrBrlyNavConnect", "LstRlyAvail") == "true");
	var ButRlyViewAvail = !LstRlyAlt;
	var ButRlyViewActive = (retrieveSi(srcdoc, "StatShrBrlyNavConnect", "ButRlyViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Con", LstConAvail, 96);
	height -= setCtlAvail(contcontdoc, "Con2", LstConAvail && !LstConAlt, 71);
	if (LstConAvail) {
		if ( (LstConAlt == !contcontdoc.getElementById("ButConExpand")) || (!LstConAlt == !contcontdoc.getElementById("ButConCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCon");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCon", retrieveTi(srcdoc, "TagBrlyNavConnect", "CptCon")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstConAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButConExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButConCollapse", "icon/collapse"));
		};

		if (!LstConAlt == !contcontdoc.getElementById("LstCon")) {
			mytd = contcontdoc.getElementById("rdynCon");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCon");
			clearElem(mytd);

			if (LstConAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCon", "./PnlBrlyNavConnect_LstCon.xml", true));
			};

		} else {
			if (!LstConAlt) refreshLst(contcontdoc.getElementById("LstCon").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCon",
						parseInt(retrieveSi(srcdoc, "StatAppBrlyNavConnect", "LstConNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavConnect", "numFLstCon"))]);
		};

		if ((ButConViewAvail == !contcontdoc.getElementById("ButConView")) || !contcontdoc.getElementById("ButConNewcrd")) {
			if (LstConAlt) mytd = contcontdoc.getElementById("dynCon");
			else mytd = contcontdoc.getElementById("rdynCon");
			clearElem(mytd);

			first = true;

			if (ButConViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButConView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButConNewcrd", "icon/newcrd"));
		};

		if (ButConViewAvail) refreshButicon(contcontdoc, "ButConView", "icon/view", ButConViewActive, false);

	} else setCtlAvail(contcontdoc, "Con2", false, 0);

	height -= setCtlAvail(contcontdoc, "Rly", LstRlyAvail, 96);
	height -= setCtlAvail(contcontdoc, "Rly2", LstRlyAvail && !LstRlyAlt, 71);
	if (LstRlyAvail) {
		if ( (LstRlyAlt == !contcontdoc.getElementById("ButRlyExpand")) || (!LstRlyAlt == !contcontdoc.getElementById("ButRlyCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynRly");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptRly", retrieveTi(srcdoc, "TagBrlyNavConnect", "CptRly")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstRlyAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRlyExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButRlyCollapse", "icon/collapse"));
		};

		if (!LstRlyAlt == !contcontdoc.getElementById("LstRly")) {
			mytd = contcontdoc.getElementById("rdynRly");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynRly");
			clearElem(mytd);

			if (LstRlyAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstRly", "./PnlBrlyNavConnect_LstRly.xml", true));
			};

		} else {
			if (!LstRlyAlt) refreshLst(contcontdoc.getElementById("LstRly").contentWindow.document, srcdoc, 1, true, false, "FeedFLstRly",
						parseInt(retrieveSi(srcdoc, "StatAppBrlyNavConnect", "LstRlyNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavConnect", "numFLstRly"))]);
		};

		if ((ButRlyViewAvail == !contcontdoc.getElementById("ButRlyView"))) {
			if (LstRlyAlt) mytd = contcontdoc.getElementById("dynRly");
			else mytd = contcontdoc.getElementById("rdynRly");
			clearElem(mytd);

			first = true;

			if (ButRlyViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButRlyView", "icon/view"));
			};
		};

		if (ButRlyViewAvail) refreshButicon(contcontdoc, "ButRlyView", "icon/view", ButRlyViewActive, false);

	} else setCtlAvail(contcontdoc, "Rly2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Connect", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Connect_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Connect_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Connect_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyNavConnect", "srefIxBrlyVExpstate");

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
	srcdoc = doc.getElementById("Connect_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppBrlyNavConnect", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppBrlyNavConnect", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyNavConnectDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyNavConnectDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyNavConnect", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacBrlyNavConnect", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyNavConnect", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacBrlyNavConnect", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacBrlyNavConnect", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacBrlyNavConnect", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacBrlyNavConnect", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacBrlyNavConnect", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyNavConnectData", scrJref, "ContIacBrlyNavConnect");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppBrlyNavConnect", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppBrlyNavConnect", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacBrlyNavConnect", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavConnect", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyNavConnectData", "ContIacBrlyNavConnect", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyNavConnectData", "FeedFLstCon", srcdoc)) mask.push("feedFLstCon");
	if (updateSrcblock(dom, "DpchEngBrlyNavConnectData", "FeedFLstRly", srcdoc)) mask.push("feedFLstRly");
	if (updateSrcblock(dom, "DpchEngBrlyNavConnectData", "StatAppBrlyNavConnect", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyNavConnectData", "StatShrBrlyNavConnect", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyNavConnectData", "TagBrlyNavConnect", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyNavConnectData") {
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
			if (blk.nodeName == "DpchEngBrlyNavConnectData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Connect");
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

			} else if (blk.nodeName == "DpchEngBrlyNavConnectData") {
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

