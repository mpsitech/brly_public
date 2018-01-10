/**
  * \file PnlBrlyUsrRec.js
  * web client functionality for panel PnlBrlyUsrRec
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "scrJrefDetail");
	scrJrefAAccess = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "scrJrefAAccess");
	scrJref1NSession = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "scrJref1NSession");
	scrJrefMNUsergroup = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "scrJrefMNUsergroup");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppBrlyUsrRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppBrlyUsrRec", "initdoneAAccess", "false");
	setSi(srcdoc, "StatAppBrlyUsrRec", "initdone1NSession", "false");
	setSi(srcdoc, "StatAppBrlyUsrRec", "initdoneMNUsergroup", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAAccess = 30;
	height1NSession = 30;
	heightMNUsergroup = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppBrlyUsrRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppBrlyUsrRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyUsrRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppBrlyUsrRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppBrlyUsrRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyUsrRec", "initdoneDetail") == "true");
	var initdoneAAccess = (retrieveSi(srcdoc, "StatAppBrlyUsrRec", "initdoneAAccess") == "true");
	var initdone1NSession = (retrieveSi(srcdoc, "StatAppBrlyUsrRec", "initdone1NSession") == "true");
	var initdoneMNUsergroup = (retrieveSi(srcdoc, "StatAppBrlyUsrRec", "initdoneMNUsergroup") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlBrlyUsrDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAAccess) {
		lhsdoc.getElementById("AAccess").src = "./PnlBrlyUsrAAccess.html?scrJref=" + scrJrefAAccess;
	} else if (!initdone1NSession) {
		rhsdoc.getElementById("1NSession").src = "./PnlBrlyUsr1NSession.html?scrJref=" + scrJref1NSession;
	} else if (!initdoneMNUsergroup) {
		rhsdoc.getElementById("MNUsergroup").src = "./PnlBrlyUsrMNUsergroup.html?scrJref=" + scrJrefMNUsergroup;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "AAccess")) lhsrhsdoc = lhsdoc;
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
		else if (short == "AAccess") heightAAccess = height;
		else if (short == "1NSession") height1NSession = height;
		else if (short == "MNUsergroup") heightMNUsergroup = height;
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

	doc.getElementById("Rec_side").src = "./PnlBrlyUsrRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyUsrRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 137);
	doc.getElementById("tdSide").setAttribute("height", "137");
	doc.getElementById("Rec_side").setAttribute("height", "137");
	doc.getElementById("Rec_cont").setAttribute("height", "137");

	doc.getElementById("Rec_side").src = "./PnlBrlyUsrRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyUsrRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "AAccess")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "AAccess") heightAAccess = height;
	else if (pnlshort == "1NSession") height1NSession = height;
	else if (pnlshort == "MNUsergroup") heightMNUsergroup = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAAccess+13 + 5;
	heightRhs = height1NSession+13 + heightMNUsergroup+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyUsrRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyUsrRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		minimize();
	} else if (srefIxBrlyVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrBrlyUsrRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyUsrRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyUsrRec", "TxtRef"));

};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "srefIxBrlyVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyUsrRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyUsrRecData", "ContInfBrlyUsrRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyUsrRecData", "StatAppBrlyUsrRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyUsrRecData", "StatShrBrlyUsrRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyUsrRecData", "TagBrlyUsrRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxBrlyVExpstate, newSrefIxBrlyVExpstate;

	_scrJref = retrieveValue(dom, "//brly:*/brly:scrJref");
	srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "srefIxBrlyVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngBrlyUsrRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "srefIxBrlyVExpstate");

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
			} else if (_scrJref == scrJrefAAccess) {
				lhsdoc.getElementById("AAccess").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NSession) {
				rhsdoc.getElementById("1NSession").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNUsergroup) {
				rhsdoc.getElementById("MNUsergroup").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngBrlyUsrRecData") {
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

			} else if (blk.nodeName == "DpchEngBrlyUsrRecData") {
				srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "srefIxBrlyVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyUsrRec", "srefIxBrlyVExpstate");

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

