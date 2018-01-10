/**
  * \file PnlBrlyLegRec.js
  * web client functionality for panel PnlBrlyLegRec
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function updateScrJrefs() {
	scrJrefPre = retrieveSi(srcdoc, "StatShrBrlyLegRec", "scrJrefPre");
	scrJrefDetail = retrieveSi(srcdoc, "StatShrBrlyLegRec", "scrJrefDetail");
	scrJrefMap = retrieveSi(srcdoc, "StatShrBrlyLegRec", "scrJrefMap");
	scrJrefCor1NConnection = retrieveSi(srcdoc, "StatShrBrlyLegRec", "scrJrefCor1NConnection");
	scrJref1NFlight = retrieveSi(srcdoc, "StatShrBrlyLegRec", "scrJref1NFlight");
	scrJrefMNLocation = retrieveSi(srcdoc, "StatShrBrlyLegRec", "scrJrefMNLocation");
	scrJrefOrgMNLeg = retrieveSi(srcdoc, "StatShrBrlyLegRec", "scrJrefOrgMNLeg");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppBrlyLegRec", "initdonePre", "false");
	setSi(srcdoc, "StatAppBrlyLegRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppBrlyLegRec", "initdoneMap", "false");
	setSi(srcdoc, "StatAppBrlyLegRec", "initdoneCor1NConnection", "false");
	setSi(srcdoc, "StatAppBrlyLegRec", "initdone1NFlight", "false");
	setSi(srcdoc, "StatAppBrlyLegRec", "initdoneMNLocation", "false");
	setSi(srcdoc, "StatAppBrlyLegRec", "initdoneOrgMNLeg", "false");
};

function resetHeights() {
	heightPre = 30;
	heightDetail = 30;
	heightMap = 30;
	heightCor1NConnection = 30;
	height1NFlight = 30;
	heightMNLocation = 30;
	heightOrgMNLeg = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppBrlyLegRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdone1NRelease") == "true");

	var initdonePre = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdonePre") == "true");
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdoneDetail") == "true");
	var initdoneMap = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdoneMap") == "true");
	var initdoneCor1NConnection = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdoneCor1NConnection") == "true");
	var initdone1NFlight = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdone1NFlight") == "true");
	var initdoneMNLocation = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdoneMNLocation") == "true");
	var initdoneOrgMNLeg = (retrieveSi(srcdoc, "StatAppBrlyLegRec", "initdoneOrgMNLeg") == "true");

	if (!initdonePre) {
		lhsdoc.getElementById("Pre").src = "./PnlBrlyLegPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlBrlyLegDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneMap) {
		lhsdoc.getElementById("Map").src = "./PnlBrlyLegMap.html?scrJref=" + scrJrefMap;
	} else if (!initdoneCor1NConnection) {
		rhsdoc.getElementById("Cor1NConnection").src = "./PnlBrlyLegCor1NConnection.html?scrJref=" + scrJrefCor1NConnection;
	} else if (!initdone1NFlight) {
		rhsdoc.getElementById("1NFlight").src = "./PnlBrlyLeg1NFlight.html?scrJref=" + scrJref1NFlight;
	} else if (!initdoneMNLocation) {
		rhsdoc.getElementById("MNLocation").src = "./PnlBrlyLegMNLocation.html?scrJref=" + scrJrefMNLocation;
	} else if (!initdoneOrgMNLeg) {
		rhsdoc.getElementById("OrgMNLeg").src = "./PnlBrlyLegOrgMNLeg.html?scrJref=" + scrJrefOrgMNLeg;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
	if (scrJrefPnl == scrJrefMap) lhsdoc.getElementById("Map").contentWindow.handleLoad();
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Pre") || (short == "Detail") || (short == "Map")) lhsrhsdoc = lhsdoc;
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
		else if (short == "Map") heightMap = height;
		else if (short == "Cor1NConnection") heightCor1NConnection = height;
		else if (short == "1NFlight") height1NFlight = height;
		else if (short == "MNLocation") heightMNLocation = height;
		else if (short == "OrgMNLeg") heightOrgMNLeg = height;
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

	doc.getElementById("Rec_side").src = "./PnlBrlyLegRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyLegRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 223);
	doc.getElementById("tdSide").setAttribute("height", "223");
	doc.getElementById("Rec_side").setAttribute("height", "223");
	doc.getElementById("Rec_cont").setAttribute("height", "223");

	doc.getElementById("Rec_side").src = "./PnlBrlyLegRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyLegRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Pre") || (pnlshort == "Detail") || (pnlshort == "Map")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Pre") heightPre = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "Map") heightMap = height;
	else if (pnlshort == "Cor1NConnection") heightCor1NConnection = height;
	else if (pnlshort == "1NFlight") height1NFlight = height;
	else if (pnlshort == "MNLocation") heightMNLocation = height;
	else if (pnlshort == "OrgMNLeg") heightOrgMNLeg = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightPre+13 + heightDetail+13 + heightMap+13 + 5;
	heightRhs = heightCor1NConnection+13 + height1NFlight+13 + heightMNLocation+13 + heightOrgMNLeg+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyLegRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyLegRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLegRec", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		minimize();
	} else if (srefIxBrlyVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrBrlyLegRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyLegRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlcor1nconnectionAvail = (retrieveSi(srcdoc, "StatShrBrlyLegRec", "pnlcor1nconnectionAvail") == "true");
	var pnl1nflightAvail = (retrieveSi(srcdoc, "StatShrBrlyLegRec", "pnl1nflightAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyLegRec", "TxtRef"));

	if (setPnlAvail("Cor1NConnection", pnlcor1nconnectionAvail)) updh = true;
	if (setPnlAvail("1NFlight", pnl1nflightAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLegRec", "srefIxBrlyVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyLegRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyLegRecData", "ContInfBrlyLegRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyLegRecData", "StatAppBrlyLegRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyLegRecData", "StatShrBrlyLegRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyLegRecData", "TagBrlyLegRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxBrlyVExpstate, newSrefIxBrlyVExpstate;

	_scrJref = retrieveValue(dom, "//brly:*/brly:scrJref");
	srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLegRec", "srefIxBrlyVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngBrlyLegRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLegRec", "srefIxBrlyVExpstate");

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
			} else if (_scrJref == scrJrefMap) {
				lhsdoc.getElementById("Map").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefCor1NConnection) {
				rhsdoc.getElementById("Cor1NConnection").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NFlight) {
				rhsdoc.getElementById("1NFlight").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNLocation) {
				rhsdoc.getElementById("MNLocation").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefOrgMNLeg) {
				rhsdoc.getElementById("OrgMNLeg").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngBrlyLegRecData") {
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

			} else if (blk.nodeName == "DpchEngBrlyLegRecData") {
				srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLegRec", "srefIxBrlyVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLegRec", "srefIxBrlyVExpstate");

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

