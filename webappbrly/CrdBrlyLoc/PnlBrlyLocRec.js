/**
  * \file PnlBrlyLocRec.js
  * web client functionality for panel PnlBrlyLocRec
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefDetail");
	scrJrefMap = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefMap");
	scrJrefBgn1NLeg = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefBgn1NLeg");
	scrJrefEnd1NLeg = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefEnd1NLeg");
	scrJrefEqp1NNode = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefEqp1NNode");
	scrJrefMNSegment = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefMNSegment");
	scrJrefProxOrgMNLocation = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefProxOrgMNLocation");
	scrJrefVisOrgMNLocation = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefVisOrgMNLocation");
	scrJrefMNLeg = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefMNLeg");
	scrJrefMNFlight = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefMNFlight");
	scrJrefEqpMNConnection = retrieveSi(srcdoc, "StatShrBrlyLocRec", "scrJrefEqpMNConnection");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneMap", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneBgn1NLeg", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneEnd1NLeg", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneEqp1NNode", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneMNSegment", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneProxOrgMNLocation", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneVisOrgMNLocation", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneMNLeg", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneMNFlight", "false");
	setSi(srcdoc, "StatAppBrlyLocRec", "initdoneEqpMNConnection", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightMap = 30;
	heightBgn1NLeg = 30;
	heightEnd1NLeg = 30;
	heightEqp1NNode = 30;
	heightMNSegment = 30;
	heightProxOrgMNLocation = 30;
	heightVisOrgMNLocation = 30;
	heightMNLeg = 30;
	heightMNFlight = 30;
	heightEqpMNConnection = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppBrlyLocRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneDetail") == "true");
	var initdoneMap = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneMap") == "true");
	var initdoneBgn1NLeg = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneBgn1NLeg") == "true");
	var initdoneEnd1NLeg = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneEnd1NLeg") == "true");
	var initdoneEqp1NNode = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneEqp1NNode") == "true");
	var initdoneMNSegment = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneMNSegment") == "true");
	var initdoneProxOrgMNLocation = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneProxOrgMNLocation") == "true");
	var initdoneVisOrgMNLocation = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneVisOrgMNLocation") == "true");
	var initdoneMNLeg = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneMNLeg") == "true");
	var initdoneMNFlight = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneMNFlight") == "true");
	var initdoneEqpMNConnection = (retrieveSi(srcdoc, "StatAppBrlyLocRec", "initdoneEqpMNConnection") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlBrlyLocDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneMap) {
		lhsdoc.getElementById("Map").src = "./PnlBrlyLocMap.html?scrJref=" + scrJrefMap;
	} else if (!initdoneBgn1NLeg) {
		rhsdoc.getElementById("Bgn1NLeg").src = "./PnlBrlyLocBgn1NLeg.html?scrJref=" + scrJrefBgn1NLeg;
	} else if (!initdoneEnd1NLeg) {
		rhsdoc.getElementById("End1NLeg").src = "./PnlBrlyLocEnd1NLeg.html?scrJref=" + scrJrefEnd1NLeg;
	} else if (!initdoneEqp1NNode) {
		rhsdoc.getElementById("Eqp1NNode").src = "./PnlBrlyLocEqp1NNode.html?scrJref=" + scrJrefEqp1NNode;
	} else if (!initdoneMNSegment) {
		rhsdoc.getElementById("MNSegment").src = "./PnlBrlyLocMNSegment.html?scrJref=" + scrJrefMNSegment;
	} else if (!initdoneProxOrgMNLocation) {
		rhsdoc.getElementById("ProxOrgMNLocation").src = "./PnlBrlyLocProxOrgMNLocation.html?scrJref=" + scrJrefProxOrgMNLocation;
	} else if (!initdoneVisOrgMNLocation) {
		rhsdoc.getElementById("VisOrgMNLocation").src = "./PnlBrlyLocVisOrgMNLocation.html?scrJref=" + scrJrefVisOrgMNLocation;
	} else if (!initdoneMNLeg) {
		rhsdoc.getElementById("MNLeg").src = "./PnlBrlyLocMNLeg.html?scrJref=" + scrJrefMNLeg;
	} else if (!initdoneMNFlight) {
		rhsdoc.getElementById("MNFlight").src = "./PnlBrlyLocMNFlight.html?scrJref=" + scrJrefMNFlight;
	} else if (!initdoneEqpMNConnection) {
		rhsdoc.getElementById("EqpMNConnection").src = "./PnlBrlyLocEqpMNConnection.html?scrJref=" + scrJrefEqpMNConnection;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
	if (scrJrefPnl == scrJrefMap) lhsdoc.getElementById("Map").contentWindow.handleLoad();
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "Map")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "Map") heightMap = height;
		else if (short == "Bgn1NLeg") heightBgn1NLeg = height;
		else if (short == "End1NLeg") heightEnd1NLeg = height;
		else if (short == "Eqp1NNode") heightEqp1NNode = height;
		else if (short == "MNSegment") heightMNSegment = height;
		else if (short == "ProxOrgMNLocation") heightProxOrgMNLocation = height;
		else if (short == "VisOrgMNLocation") heightVisOrgMNLocation = height;
		else if (short == "MNLeg") heightMNLeg = height;
		else if (short == "MNFlight") heightMNFlight = height;
		else if (short == "EqpMNConnection") heightEqpMNConnection = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlBrlyLocRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyLocRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 438);
	doc.getElementById("tdSide").setAttribute("height", "438");
	doc.getElementById("Rec_side").setAttribute("height", "438");
	doc.getElementById("Rec_cont").setAttribute("height", "438");

	doc.getElementById("Rec_side").src = "./PnlBrlyLocRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyLocRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "Map")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "Map") heightMap = height;
	else if (pnlshort == "Bgn1NLeg") heightBgn1NLeg = height;
	else if (pnlshort == "End1NLeg") heightEnd1NLeg = height;
	else if (pnlshort == "Eqp1NNode") heightEqp1NNode = height;
	else if (pnlshort == "MNSegment") heightMNSegment = height;
	else if (pnlshort == "ProxOrgMNLocation") heightProxOrgMNLocation = height;
	else if (pnlshort == "VisOrgMNLocation") heightVisOrgMNLocation = height;
	else if (pnlshort == "MNLeg") heightMNLeg = height;
	else if (pnlshort == "MNFlight") heightMNFlight = height;
	else if (pnlshort == "EqpMNConnection") heightEqpMNConnection = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightMap+13 + 5;
	heightRhs = heightBgn1NLeg+13 + heightEnd1NLeg+13 + heightEqp1NNode+13 + heightMNSegment+13 + heightProxOrgMNLocation+13 + heightVisOrgMNLocation+13 + heightMNLeg+13 + heightMNFlight+13 + heightEqpMNConnection+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = null;
	lhsdoc = null;
	rhsdoc = null;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyLocRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyLocRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocRec", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		minimize();
	} else if (srefIxBrlyVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrBrlyLocRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyLocRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlbgn1nlegAvail = (retrieveSi(srcdoc, "StatShrBrlyLocRec", "pnlbgn1nlegAvail") == "true");
	var pnlend1nlegAvail = (retrieveSi(srcdoc, "StatShrBrlyLocRec", "pnlend1nlegAvail") == "true");
	var pnleqp1nnodeAvail = (retrieveSi(srcdoc, "StatShrBrlyLocRec", "pnleqp1nnodeAvail") == "true");
	var pnleqpmnconnectionAvail = (retrieveSi(srcdoc, "StatShrBrlyLocRec", "pnleqpmnconnectionAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyLocRec", "TxtRef"));

	if (setPnlAvail("Bgn1NLeg", pnlbgn1nlegAvail)) updh = true;
	if (setPnlAvail("End1NLeg", pnlend1nlegAvail)) updh = true;
	if (setPnlAvail("Eqp1NNode", pnleqp1nnodeAvail)) updh = true;
	if (setPnlAvail("EqpMNConnection", pnleqpmnconnectionAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocRec", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxBrlyVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyLocRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyLocRecData", "ContInfBrlyLocRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyLocRecData", "StatAppBrlyLocRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyLocRecData", "StatShrBrlyLocRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyLocRecData", "TagBrlyLocRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxBrlyVExpstate, newSrefIxBrlyVExpstate;

	_scrJref = retrieveValue(dom, "//brly:*/brly:scrJref");
	srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocRec", "srefIxBrlyVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngBrlyLocRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocRec", "srefIxBrlyVExpstate");

				if (newSrefIxBrlyVExpstate != srefIxBrlyVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxBrlyVExpstate == "mind") {
						minimize();
					} else if (newSrefIxBrlyVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxBrlyVExpstate != "mind") {
			if (_scrJref == scrJrefDetail) {
				lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMap) {
				lhsdoc.getElementById("Map").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefBgn1NLeg) {
				rhsdoc.getElementById("Bgn1NLeg").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefEnd1NLeg) {
				rhsdoc.getElementById("End1NLeg").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefEqp1NNode) {
				rhsdoc.getElementById("Eqp1NNode").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNSegment) {
				rhsdoc.getElementById("MNSegment").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefProxOrgMNLocation) {
				rhsdoc.getElementById("ProxOrgMNLocation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefVisOrgMNLocation) {
				rhsdoc.getElementById("VisOrgMNLocation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNLeg) {
				rhsdoc.getElementById("MNLeg").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNFlight) {
				rhsdoc.getElementById("MNFlight").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefEqpMNConnection) {
				rhsdoc.getElementById("EqpMNConnection").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngBrlyLocRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxBrlyVExpstate, newSrefIxBrlyVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//brly:*");

		if (blk) {
			if (blk.nodeName == "DpchEngBrlyConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngBrlyLocRecData") {
				srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocRec", "srefIxBrlyVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocRec", "srefIxBrlyVExpstate");

					if (newSrefIxBrlyVExpstate != srefIxBrlyVExpstate) {
						updateScrJrefs();

						if (newSrefIxBrlyVExpstate == "mind") {
							minimize();
						} else if (newSrefIxBrlyVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};

