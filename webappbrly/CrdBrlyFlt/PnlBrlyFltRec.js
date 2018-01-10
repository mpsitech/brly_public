/**
  * \file PnlBrlyFltRec.js
  * web client functionality for panel PnlBrlyFltRec
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function updateScrJrefs() {
	scrJrefPre = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefPre");
	scrJrefDetail = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefDetail");
	scrJrefFafAWaypoint = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefFafAWaypoint");
	scrJref1NConnection = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJref1NConnection");
	scrJrefRef1NSegment = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefRef1NSegment");
	scrJrefEqp1NNode = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefEqp1NNode");
	scrJrefMNLocation = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefMNLocation");
	scrJrefMNConnection = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefMNConnection");
	scrJrefOrgMNFlight = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefOrgMNFlight");
	scrJrefEqpMNConnection = retrieveSi(srcdoc, "StatShrBrlyFltRec", "scrJrefEqpMNConnection");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppBrlyFltRec", "initdonePre", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdoneFafAWaypoint", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdone1NConnection", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdoneRef1NSegment", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdoneEqp1NNode", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdoneMNLocation", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdoneMNConnection", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdoneOrgMNFlight", "false");
	setSi(srcdoc, "StatAppBrlyFltRec", "initdoneEqpMNConnection", "false");
};

function resetHeights() {
	heightPre = 30;
	heightDetail = 30;
	heightFafAWaypoint = 30;
	height1NConnection = 30;
	heightRef1NSegment = 30;
	heightEqp1NNode = 30;
	heightMNLocation = 30;
	heightMNConnection = 30;
	heightOrgMNFlight = 30;
	heightEqpMNConnection = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppBrlyFltRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdone1NRelease") == "true");

	var initdonePre = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdonePre") == "true");
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneDetail") == "true");
	var initdoneFafAWaypoint = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneFafAWaypoint") == "true");
	var initdone1NConnection = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdone1NConnection") == "true");
	var initdoneRef1NSegment = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneRef1NSegment") == "true");
	var initdoneEqp1NNode = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneEqp1NNode") == "true");
	var initdoneMNLocation = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneMNLocation") == "true");
	var initdoneMNConnection = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneMNConnection") == "true");
	var initdoneOrgMNFlight = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneOrgMNFlight") == "true");
	var initdoneEqpMNConnection = (retrieveSi(srcdoc, "StatAppBrlyFltRec", "initdoneEqpMNConnection") == "true");

	if (!initdonePre) {
		lhsdoc.getElementById("Pre").src = "./PnlBrlyFltPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlBrlyFltDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneFafAWaypoint) {
		lhsdoc.getElementById("FafAWaypoint").src = "./PnlBrlyFltFafAWaypoint.html?scrJref=" + scrJrefFafAWaypoint;
	} else if (!initdone1NConnection) {
		rhsdoc.getElementById("1NConnection").src = "./PnlBrlyFlt1NConnection.html?scrJref=" + scrJref1NConnection;
	} else if (!initdoneRef1NSegment) {
		rhsdoc.getElementById("Ref1NSegment").src = "./PnlBrlyFltRef1NSegment.html?scrJref=" + scrJrefRef1NSegment;
	} else if (!initdoneEqp1NNode) {
		rhsdoc.getElementById("Eqp1NNode").src = "./PnlBrlyFltEqp1NNode.html?scrJref=" + scrJrefEqp1NNode;
	} else if (!initdoneMNLocation) {
		rhsdoc.getElementById("MNLocation").src = "./PnlBrlyFltMNLocation.html?scrJref=" + scrJrefMNLocation;
	} else if (!initdoneMNConnection) {
		rhsdoc.getElementById("MNConnection").src = "./PnlBrlyFltMNConnection.html?scrJref=" + scrJrefMNConnection;
	} else if (!initdoneOrgMNFlight) {
		rhsdoc.getElementById("OrgMNFlight").src = "./PnlBrlyFltOrgMNFlight.html?scrJref=" + scrJrefOrgMNFlight;
	} else if (!initdoneEqpMNConnection) {
		rhsdoc.getElementById("EqpMNConnection").src = "./PnlBrlyFltEqpMNConnection.html?scrJref=" + scrJrefEqpMNConnection;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Pre") || (short == "Detail") || (short == "FafAWaypoint")) lhsrhsdoc = lhsdoc;
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
		else if (short == "Pre") heightPre = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "FafAWaypoint") heightFafAWaypoint = height;
		else if (short == "1NConnection") height1NConnection = height;
		else if (short == "Ref1NSegment") heightRef1NSegment = height;
		else if (short == "Eqp1NNode") heightEqp1NNode = height;
		else if (short == "MNLocation") heightMNLocation = height;
		else if (short == "MNConnection") heightMNConnection = height;
		else if (short == "OrgMNFlight") heightOrgMNFlight = height;
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

	doc.getElementById("Rec_side").src = "./PnlBrlyFltRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyFltRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 352);
	doc.getElementById("tdSide").setAttribute("height", "352");
	doc.getElementById("Rec_side").setAttribute("height", "352");
	doc.getElementById("Rec_cont").setAttribute("height", "352");

	doc.getElementById("Rec_side").src = "./PnlBrlyFltRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyFltRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Pre") || (pnlshort == "Detail") || (pnlshort == "FafAWaypoint")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Pre") heightPre = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "FafAWaypoint") heightFafAWaypoint = height;
	else if (pnlshort == "1NConnection") height1NConnection = height;
	else if (pnlshort == "Ref1NSegment") heightRef1NSegment = height;
	else if (pnlshort == "Eqp1NNode") heightEqp1NNode = height;
	else if (pnlshort == "MNLocation") heightMNLocation = height;
	else if (pnlshort == "MNConnection") heightMNConnection = height;
	else if (pnlshort == "OrgMNFlight") heightOrgMNFlight = height;
	else if (pnlshort == "EqpMNConnection") heightEqpMNConnection = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightPre+13 + heightDetail+13 + heightFafAWaypoint+13 + 5;
	heightRhs = height1NConnection+13 + heightRef1NSegment+13 + heightEqp1NNode+13 + heightMNLocation+13 + heightMNConnection+13 + heightOrgMNFlight+13 + heightEqpMNConnection+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyFltRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyFltRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyFltRec", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		minimize();
	} else if (srefIxBrlyVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrBrlyFltRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyFltRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlfafawaypointAvail = (retrieveSi(srcdoc, "StatShrBrlyFltRec", "pnlfafawaypointAvail") == "true");
	var pnleqp1nnodeAvail = (retrieveSi(srcdoc, "StatShrBrlyFltRec", "pnleqp1nnodeAvail") == "true");
	var pnleqpmnconnectionAvail = (retrieveSi(srcdoc, "StatShrBrlyFltRec", "pnleqpmnconnectionAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyFltRec", "TxtRef"));

	if (setPnlAvail("FafAWaypoint", pnlfafawaypointAvail)) updh = true;
	if (setPnlAvail("Eqp1NNode", pnleqp1nnodeAvail)) updh = true;
	if (setPnlAvail("EqpMNConnection", pnleqpmnconnectionAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyFltRec", "srefIxBrlyVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyFltRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyFltRecData", "ContInfBrlyFltRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyFltRecData", "StatAppBrlyFltRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyFltRecData", "StatShrBrlyFltRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyFltRecData", "TagBrlyFltRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxBrlyVExpstate, newSrefIxBrlyVExpstate;

	_scrJref = retrieveValue(dom, "//brly:*/brly:scrJref");
	srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyFltRec", "srefIxBrlyVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngBrlyFltRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyFltRec", "srefIxBrlyVExpstate");

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
			if (_scrJref == scrJrefPre) {
				lhsdoc.getElementById("Pre").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefDetail) {
				lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefFafAWaypoint) {
				lhsdoc.getElementById("FafAWaypoint").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NConnection) {
				rhsdoc.getElementById("1NConnection").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NSegment) {
				rhsdoc.getElementById("Ref1NSegment").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefEqp1NNode) {
				rhsdoc.getElementById("Eqp1NNode").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNLocation) {
				rhsdoc.getElementById("MNLocation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNConnection) {
				rhsdoc.getElementById("MNConnection").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefOrgMNFlight) {
				rhsdoc.getElementById("OrgMNFlight").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngBrlyFltRecData") {
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

			} else if (blk.nodeName == "DpchEngBrlyFltRecData") {
				srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyFltRec", "srefIxBrlyVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyFltRec", "srefIxBrlyVExpstate");

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

