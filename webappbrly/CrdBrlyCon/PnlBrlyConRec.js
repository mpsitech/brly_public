/**
  * \file PnlBrlyConRec.js
  * web client functionality for panel PnlBrlyConRec
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function updateScrJrefs() {
	scrJrefPre = retrieveSi(srcdoc, "StatShrBrlyConRec", "scrJrefPre");
	scrJrefDetail = retrieveSi(srcdoc, "StatShrBrlyConRec", "scrJrefDetail");
	scrJrefMap = retrieveSi(srcdoc, "StatShrBrlyConRec", "scrJrefMap");
	scrJref1NRelay = retrieveSi(srcdoc, "StatShrBrlyConRec", "scrJref1NRelay");
	scrJrefRef1NSegment = retrieveSi(srcdoc, "StatShrBrlyConRec", "scrJrefRef1NSegment");
	scrJrefMNSegment = retrieveSi(srcdoc, "StatShrBrlyConRec", "scrJrefMNSegment");
	scrJrefMNFlight = retrieveSi(srcdoc, "StatShrBrlyConRec", "scrJrefMNFlight");
	scrJrefConMNEquipment = retrieveSi(srcdoc, "StatShrBrlyConRec", "scrJrefConMNEquipment");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppBrlyConRec", "initdonePre", "false");
	setSi(srcdoc, "StatAppBrlyConRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppBrlyConRec", "initdoneMap", "false");
	setSi(srcdoc, "StatAppBrlyConRec", "initdone1NRelay", "false");
	setSi(srcdoc, "StatAppBrlyConRec", "initdoneRef1NSegment", "false");
	setSi(srcdoc, "StatAppBrlyConRec", "initdoneMNSegment", "false");
	setSi(srcdoc, "StatAppBrlyConRec", "initdoneMNFlight", "false");
	setSi(srcdoc, "StatAppBrlyConRec", "initdoneConMNEquipment", "false");
};

function resetHeights() {
	heightPre = 30;
	heightDetail = 30;
	heightMap = 30;
	height1NRelay = 30;
	heightRef1NSegment = 30;
	heightMNSegment = 30;
	heightMNFlight = 30;
	heightConMNEquipment = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppBrlyConRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppBrlyConRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdone1NRelease") == "true");

	var initdonePre = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdonePre") == "true");
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdoneDetail") == "true");
	var initdoneMap = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdoneMap") == "true");
	var initdone1NRelay = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdone1NRelay") == "true");
	var initdoneRef1NSegment = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdoneRef1NSegment") == "true");
	var initdoneMNSegment = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdoneMNSegment") == "true");
	var initdoneMNFlight = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdoneMNFlight") == "true");
	var initdoneConMNEquipment = (retrieveSi(srcdoc, "StatAppBrlyConRec", "initdoneConMNEquipment") == "true");

	if (!initdonePre) {
		lhsdoc.getElementById("Pre").src = "./PnlBrlyConPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlBrlyConDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneMap) {
		lhsdoc.getElementById("Map").src = "./PnlBrlyConMap.html?scrJref=" + scrJrefMap;
	} else if (!initdone1NRelay) {
		rhsdoc.getElementById("1NRelay").src = "./PnlBrlyCon1NRelay.html?scrJref=" + scrJref1NRelay;
	} else if (!initdoneRef1NSegment) {
		rhsdoc.getElementById("Ref1NSegment").src = "./PnlBrlyConRef1NSegment.html?scrJref=" + scrJrefRef1NSegment;
	} else if (!initdoneMNSegment) {
		rhsdoc.getElementById("MNSegment").src = "./PnlBrlyConMNSegment.html?scrJref=" + scrJrefMNSegment;
	} else if (!initdoneMNFlight) {
		rhsdoc.getElementById("MNFlight").src = "./PnlBrlyConMNFlight.html?scrJref=" + scrJrefMNFlight;
	} else if (!initdoneConMNEquipment) {
		rhsdoc.getElementById("ConMNEquipment").src = "./PnlBrlyConConMNEquipment.html?scrJref=" + scrJrefConMNEquipment;

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
		else if (short == "1NRelay") height1NRelay = height;
		else if (short == "Ref1NSegment") heightRef1NSegment = height;
		else if (short == "MNSegment") heightMNSegment = height;
		else if (short == "MNFlight") heightMNFlight = height;
		else if (short == "ConMNEquipment") heightConMNEquipment = height;
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

	doc.getElementById("Rec_side").src = "./PnlBrlyConRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyConRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 266);
	doc.getElementById("tdSide").setAttribute("height", "266");
	doc.getElementById("Rec_side").setAttribute("height", "266");
	doc.getElementById("Rec_cont").setAttribute("height", "266");

	doc.getElementById("Rec_side").src = "./PnlBrlyConRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlBrlyConRec_b.html";
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
	else if (pnlshort == "1NRelay") height1NRelay = height;
	else if (pnlshort == "Ref1NSegment") heightRef1NSegment = height;
	else if (pnlshort == "MNSegment") heightMNSegment = height;
	else if (pnlshort == "MNFlight") heightMNFlight = height;
	else if (pnlshort == "ConMNEquipment") heightConMNEquipment = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightPre+13 + heightDetail+13 + heightMap+13 + 5;
	heightRhs = height1NRelay+13 + heightRef1NSegment+13 + heightMNSegment+13 + heightMNFlight+13 + heightConMNEquipment+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyConRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagBrlyConRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConRec", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		minimize();
	} else if (srefIxBrlyVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrBrlyConRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyConRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfBrlyConRec", "TxtRef"));

};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConRec", "srefIxBrlyVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyConRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyConRecData", "ContInfBrlyConRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyConRecData", "StatAppBrlyConRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyConRecData", "StatShrBrlyConRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyConRecData", "TagBrlyConRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var _scrJref, mask;
	var srefIxBrlyVExpstate, newSrefIxBrlyVExpstate;

	_scrJref = retrieveValue(dom, "//brly:*/brly:scrJref");
	srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConRec", "srefIxBrlyVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngBrlyConRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConRec", "srefIxBrlyVExpstate");

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
			} else if (_scrJref == scrJref1NRelay) {
				rhsdoc.getElementById("1NRelay").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NSegment) {
				rhsdoc.getElementById("Ref1NSegment").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNSegment) {
				rhsdoc.getElementById("MNSegment").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNFlight) {
				rhsdoc.getElementById("MNFlight").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefConMNEquipment) {
				rhsdoc.getElementById("ConMNEquipment").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngBrlyConRecData") {
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

			} else if (blk.nodeName == "DpchEngBrlyConRecData") {
				srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConRec", "srefIxBrlyVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConRec", "srefIxBrlyVExpstate");

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

