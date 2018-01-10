/**
  * \file PnlBrlyNavBase.js
  * web client functionality for panel PnlBrlyNavBase
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppBrlyNavBase", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyNavBase", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Base", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Base_side").setAttribute("height", "30");
	doc.getElementById("Base_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Base_side").src = "./PnlBrlyNavBase_aside.html";
	doc.getElementById("Base_cont").src = "./PnlBrlyNavBase_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyNavBase", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyNavBase", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Base_side").src = "./PnlBrlyNavBase_bside.html";
	doc.getElementById("Base_cont").src = "./PnlBrlyNavBase_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Base_side").contentDocument;
	contdoc = doc.getElementById("Base_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyNavBase", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Base_side").contentDocument;
	contdoc = doc.getElementById("Base_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Base_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Base_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyNavBase", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyNavBase", "srefIxBrlyVExpstate");

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
	var height = 586; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstRegAlt = (retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstRegAlt") == "true");
	var LstRegAvail = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "LstRegAvail") == "true");
	var ButRegViewAvail = !LstRegAlt;
	var ButRegViewActive = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "ButRegViewActive") == "true");

	var LstLocAlt = (retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstLocAlt") == "true");
	var LstLocAvail = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "LstLocAvail") == "true");
	var ButLocViewAvail = !LstLocAlt;
	var ButLocViewActive = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "ButLocViewActive") == "true");

	var LstLegAlt = (retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstLegAlt") == "true");
	var LstLegAvail = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "LstLegAvail") == "true");
	var ButLegViewAvail = !LstLegAlt;
	var ButLegViewActive = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "ButLegViewActive") == "true");

	var LstTtbAlt = (retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstTtbAlt") == "true");
	var LstTtbAvail = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "LstTtbAvail") == "true");
	var ButTtbViewAvail = !LstTtbAlt;
	var ButTtbViewActive = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "ButTtbViewActive") == "true");

	var LstFltAlt = (retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstFltAlt") == "true");
	var LstFltAvail = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "LstFltAvail") == "true");
	var ButFltViewAvail = !LstFltAlt;
	var ButFltViewActive = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "ButFltViewActive") == "true");

	var LstSegAlt = (retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstSegAlt") == "true");
	var LstSegAvail = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "LstSegAvail") == "true");
	var ButSegViewAvail = !LstSegAlt;
	var ButSegViewActive = (retrieveSi(srcdoc, "StatShrBrlyNavBase", "ButSegViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Reg", LstRegAvail, 96);
	height -= setCtlAvail(contcontdoc, "Reg2", LstRegAvail && !LstRegAlt, 71);
	if (LstRegAvail) {
		if ( (LstRegAlt == !contcontdoc.getElementById("ButRegExpand")) || (!LstRegAlt == !contcontdoc.getElementById("ButRegCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynReg");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptReg", retrieveTi(srcdoc, "TagBrlyNavBase", "CptReg")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstRegAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRegExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButRegCollapse", "icon/collapse"));
		};

		if (!LstRegAlt == !contcontdoc.getElementById("LstReg")) {
			mytd = contcontdoc.getElementById("rdynReg");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynReg");
			clearElem(mytd);

			if (LstRegAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstReg", "./PnlBrlyNavBase_LstReg.xml", true));
			};

		} else {
			if (!LstRegAlt) refreshLst(contcontdoc.getElementById("LstReg").contentWindow.document, srcdoc, 1, true, false, "FeedFLstReg",
						parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstRegNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numFLstReg"))]);
		};

		if ((ButRegViewAvail == !contcontdoc.getElementById("ButRegView")) || !contcontdoc.getElementById("ButRegNewcrd")) {
			if (LstRegAlt) mytd = contcontdoc.getElementById("dynReg");
			else mytd = contcontdoc.getElementById("rdynReg");
			clearElem(mytd);

			first = true;

			if (ButRegViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButRegView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButRegNewcrd", "icon/newcrd"));
		};

		if (ButRegViewAvail) refreshButicon(contcontdoc, "ButRegView", "icon/view", ButRegViewActive, false);

	} else setCtlAvail(contcontdoc, "Reg2", false, 0);

	height -= setCtlAvail(contcontdoc, "Loc", LstLocAvail, 96);
	height -= setCtlAvail(contcontdoc, "Loc2", LstLocAvail && !LstLocAlt, 71);
	if (LstLocAvail) {
		if ( (LstLocAlt == !contcontdoc.getElementById("ButLocExpand")) || (!LstLocAlt == !contcontdoc.getElementById("ButLocCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynLoc");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptLoc", retrieveTi(srcdoc, "TagBrlyNavBase", "CptLoc")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstLocAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButLocExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButLocCollapse", "icon/collapse"));
		};

		if (!LstLocAlt == !contcontdoc.getElementById("LstLoc")) {
			mytd = contcontdoc.getElementById("rdynLoc");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynLoc");
			clearElem(mytd);

			if (LstLocAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstLoc", "./PnlBrlyNavBase_LstLoc.xml", true));
			};

		} else {
			if (!LstLocAlt) refreshLst(contcontdoc.getElementById("LstLoc").contentWindow.document, srcdoc, 1, true, false, "FeedFLstLoc",
						parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstLocNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numFLstLoc"))]);
		};

		if ((ButLocViewAvail == !contcontdoc.getElementById("ButLocView")) || !contcontdoc.getElementById("ButLocNewcrd")) {
			if (LstLocAlt) mytd = contcontdoc.getElementById("dynLoc");
			else mytd = contcontdoc.getElementById("rdynLoc");
			clearElem(mytd);

			first = true;

			if (ButLocViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLocView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLocNewcrd", "icon/newcrd"));
		};

		if (ButLocViewAvail) refreshButicon(contcontdoc, "ButLocView", "icon/view", ButLocViewActive, false);

	} else setCtlAvail(contcontdoc, "Loc2", false, 0);

	height -= setCtlAvail(contcontdoc, "Leg", LstLegAvail, 96);
	height -= setCtlAvail(contcontdoc, "Leg2", LstLegAvail && !LstLegAlt, 71);
	if (LstLegAvail) {
		if ( (LstLegAlt == !contcontdoc.getElementById("ButLegExpand")) || (!LstLegAlt == !contcontdoc.getElementById("ButLegCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynLeg");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptLeg", retrieveTi(srcdoc, "TagBrlyNavBase", "CptLeg")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstLegAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButLegExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButLegCollapse", "icon/collapse"));
		};

		if (!LstLegAlt == !contcontdoc.getElementById("LstLeg")) {
			mytd = contcontdoc.getElementById("rdynLeg");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynLeg");
			clearElem(mytd);

			if (LstLegAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstLeg", "./PnlBrlyNavBase_LstLeg.xml", true));
			};

		} else {
			if (!LstLegAlt) refreshLst(contcontdoc.getElementById("LstLeg").contentWindow.document, srcdoc, 1, true, false, "FeedFLstLeg",
						parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstLegNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numFLstLeg"))]);
		};

		if ((ButLegViewAvail == !contcontdoc.getElementById("ButLegView")) || !contcontdoc.getElementById("ButLegNewcrd")) {
			if (LstLegAlt) mytd = contcontdoc.getElementById("dynLeg");
			else mytd = contcontdoc.getElementById("rdynLeg");
			clearElem(mytd);

			first = true;

			if (ButLegViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLegView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLegNewcrd", "icon/newcrd"));
		};

		if (ButLegViewAvail) refreshButicon(contcontdoc, "ButLegView", "icon/view", ButLegViewActive, false);

	} else setCtlAvail(contcontdoc, "Leg2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ttb", LstTtbAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ttb2", LstTtbAvail && !LstTtbAlt, 71);
	if (LstTtbAvail) {
		if ( (LstTtbAlt == !contcontdoc.getElementById("ButTtbExpand")) || (!LstTtbAlt == !contcontdoc.getElementById("ButTtbCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynTtb");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptTtb", retrieveTi(srcdoc, "TagBrlyNavBase", "CptTtb")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstTtbAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButTtbExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButTtbCollapse", "icon/collapse"));
		};

		if (!LstTtbAlt == !contcontdoc.getElementById("LstTtb")) {
			mytd = contcontdoc.getElementById("rdynTtb");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynTtb");
			clearElem(mytd);

			if (LstTtbAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstTtb", "./PnlBrlyNavBase_LstTtb.xml", true));
			};

		} else {
			if (!LstTtbAlt) refreshLst(contcontdoc.getElementById("LstTtb").contentWindow.document, srcdoc, 1, true, false, "FeedFLstTtb",
						parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstTtbNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numFLstTtb"))]);
		};

		if ((ButTtbViewAvail == !contcontdoc.getElementById("ButTtbView")) || !contcontdoc.getElementById("ButTtbNewcrd")) {
			if (LstTtbAlt) mytd = contcontdoc.getElementById("dynTtb");
			else mytd = contcontdoc.getElementById("rdynTtb");
			clearElem(mytd);

			first = true;

			if (ButTtbViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButTtbView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTtbNewcrd", "icon/newcrd"));
		};

		if (ButTtbViewAvail) refreshButicon(contcontdoc, "ButTtbView", "icon/view", ButTtbViewActive, false);

	} else setCtlAvail(contcontdoc, "Ttb2", false, 0);

	height -= setCtlAvail(contcontdoc, "Flt", LstFltAvail, 96);
	height -= setCtlAvail(contcontdoc, "Flt2", LstFltAvail && !LstFltAlt, 71);
	if (LstFltAvail) {
		if ( (LstFltAlt == !contcontdoc.getElementById("ButFltExpand")) || (!LstFltAlt == !contcontdoc.getElementById("ButFltCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFlt");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFlt", retrieveTi(srcdoc, "TagBrlyNavBase", "CptFlt")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFltAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFltExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFltCollapse", "icon/collapse"));
		};

		if (!LstFltAlt == !contcontdoc.getElementById("LstFlt")) {
			mytd = contcontdoc.getElementById("rdynFlt");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFlt");
			clearElem(mytd);

			if (LstFltAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFlt", "./PnlBrlyNavBase_LstFlt.xml", true));
			};

		} else {
			if (!LstFltAlt) refreshLst(contcontdoc.getElementById("LstFlt").contentWindow.document, srcdoc, 1, true, false, "FeedFLstFlt",
						parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstFltNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numFLstFlt"))]);
		};

		if ((ButFltViewAvail == !contcontdoc.getElementById("ButFltView")) || !contcontdoc.getElementById("ButFltNewcrd")) {
			if (LstFltAlt) mytd = contcontdoc.getElementById("dynFlt");
			else mytd = contcontdoc.getElementById("rdynFlt");
			clearElem(mytd);

			first = true;

			if (ButFltViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFltView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFltNewcrd", "icon/newcrd"));
		};

		if (ButFltViewAvail) refreshButicon(contcontdoc, "ButFltView", "icon/view", ButFltViewActive, false);

	} else setCtlAvail(contcontdoc, "Flt2", false, 0);

	height -= setCtlAvail(contcontdoc, "Seg", LstSegAvail, 96);
	height -= setCtlAvail(contcontdoc, "Seg2", LstSegAvail && !LstSegAlt, 71);
	if (LstSegAvail) {
		if ( (LstSegAlt == !contcontdoc.getElementById("ButSegExpand")) || (!LstSegAlt == !contcontdoc.getElementById("ButSegCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSeg");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSeg", retrieveTi(srcdoc, "TagBrlyNavBase", "CptSeg")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSegAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSegExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSegCollapse", "icon/collapse"));
		};

		if (!LstSegAlt == !contcontdoc.getElementById("LstSeg")) {
			mytd = contcontdoc.getElementById("rdynSeg");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSeg");
			clearElem(mytd);

			if (LstSegAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSeg", "./PnlBrlyNavBase_LstSeg.xml", true));
			};

		} else {
			if (!LstSegAlt) refreshLst(contcontdoc.getElementById("LstSeg").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSeg",
						parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", "LstSegNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numFLstSeg"))]);
		};

		if ((ButSegViewAvail == !contcontdoc.getElementById("ButSegView"))) {
			if (LstSegAlt) mytd = contcontdoc.getElementById("dynSeg");
			else mytd = contcontdoc.getElementById("rdynSeg");
			clearElem(mytd);

			first = true;

			if (ButSegViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSegView", "icon/view"));
			};
		};

		if (ButSegViewAvail) refreshButicon(contcontdoc, "ButSegView", "icon/view", ButSegViewActive, false);

	} else setCtlAvail(contcontdoc, "Seg2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Base", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Base_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Base_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Base_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyNavBase", "srefIxBrlyVExpstate");

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
	srcdoc = doc.getElementById("Base_src").contentDocument;

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
	setSi(srcdoc, "StatAppBrlyNavBase", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppBrlyNavBase", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyNavBaseDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyNavBaseDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacBrlyNavBase", "numsF" + ctlsref, toBase64(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacBrlyNavBase", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppBrlyNavBaseData", scrJref, "ContIacBrlyNavBase");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppBrlyNavBase", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppBrlyNavBase", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacBrlyNavBase", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "ContIacBrlyNavBase", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "FeedFLstFlt", srcdoc)) mask.push("feedFLstFlt");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "FeedFLstLeg", srcdoc)) mask.push("feedFLstLeg");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "FeedFLstLoc", srcdoc)) mask.push("feedFLstLoc");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "FeedFLstReg", srcdoc)) mask.push("feedFLstReg");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "FeedFLstSeg", srcdoc)) mask.push("feedFLstSeg");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "FeedFLstTtb", srcdoc)) mask.push("feedFLstTtb");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "StatAppBrlyNavBase", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "StatShrBrlyNavBase", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyNavBaseData", "TagBrlyNavBase", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyNavBaseData") {
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
			if (blk.nodeName == "DpchEngBrlyNavBaseData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Base");
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

			} else if (blk.nodeName == "DpchEngBrlyNavBaseData") {
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

