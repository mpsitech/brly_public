/**
  * \file CrdBrlyNav.js
  * web client functionality for card CrdBrlyNav
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppBrlyNav", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppBrlyNav", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppBrlyNav", "initdoneHeadbar") == "true");
	var initdoneAdmin = (retrieveSi(srcdoc, "StatAppBrlyNav", "initdoneAdmin") == "true");
	var initdoneBase = (retrieveSi(srcdoc, "StatAppBrlyNav", "initdoneBase") == "true");
	var initdoneConnect = (retrieveSi(srcdoc, "StatAppBrlyNav", "initdoneConnect") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlBrlyNavHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdoneAdmin) {
		doc.getElementById("Admin").src = "./PnlBrlyNavAdmin.html?scrJref=" + scrJrefAdmin;
	} else if (!initdoneBase) {
		doc.getElementById("Base").src = "./PnlBrlyNavBase.html?scrJref=" + scrJrefBase;
	} else if (!initdoneConnect) {
		doc.getElementById("Connect").src = "./PnlBrlyNavConnect.html?scrJref=" + scrJrefConnect;
	} else {
		doc.initdone = true;
		window.onfocus = resumeNotify;

		refresh();

		restartNotify();
	};
};

function setPnlAvail(short, avail) {
	var oldAvail = (doc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) {
			doc.getElementById("spc" + short).setAttribute("class", "show");
			doc.getElementById("tr" + short).setAttribute("class", "show");
		} else {
			doc.getElementById(short).contentWindow.minimize();
			doc.getElementById("spc" + short).setAttribute("class", "hide");
			doc.getElementById("tr" + short).setAttribute("class", "hide");
		};
	};
};

function getHeight() {
	var height = 25;

	if (doc.getElementById("trAdmin").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAdmin").getAttribute("height")) + 8;
	if (doc.getElementById("trBase").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdBase").getAttribute("height")) + 8;
	if (doc.getElementById("trConnect").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdConnect").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppBrlyNav", "shortMenu");

	if (doc.getElementById("divMenu")) {
		if (shortMenu == short)
			hideMenu(shortMenu);
		else {
			hideMenu(shortMenu);
			showMenu(short, left, width, height);
		};

	} else {
		showMenu(short, left, width, height);
	};
};

function showMenu(short, left, width, height) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppBrlyNav", "shortMenu", short);
	setSi(srcdoc, "StatAppBrlyNav", "widthMenu", "" + (width-3));

	if (short == "App") {
		headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuappact");
	} else {
		headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menuact");
	};
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menulineact");

	var body = doc.getElementById("body");
	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "menu");
	mydiv.setAttribute("id", "divMenu");
	mydiv.setAttribute("style", "left:" + left + "px;");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Menu");
	myif.setAttribute("src", "./Men" + short + ".html");
	myif.setAttribute("width", "" + width);
	myif.setAttribute("height", "" + height);
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideMenu(short) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppBrlyNav", "shortMenu", "");

	if (short == "App") {
		headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	} else {
		headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	};
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	var MspApp2Avail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MspApp2Avail") == "true");
	var MitAppLoiAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitAppLoiAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppBrlyNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagBrlyNav", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagBrlyNav", "MrlAppHlp"));
	setTextContent(mendoc, mendoc.getElementById("MitAppLoi"), retrieveTi(srcdoc, "TagBrlyNav", "MitAppLoi"));

	height -= setMitMspAvail("MspApp2", MspApp2Avail, 1);
	height -= setMitMspAvail("MitAppLoi", MitAppLoiAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenSes() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppBrlyNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxSesSes1"), retrieveCi(srcdoc, "ContInfBrlyNav", "MtxSesSes1"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes2"), retrieveCi(srcdoc, "ContInfBrlyNav", "MtxSesSes2"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes3"), retrieveCi(srcdoc, "ContInfBrlyNav", "MtxSesSes3"));
	setTextContent(mendoc, mendoc.getElementById("MitSesTrm"), retrieveTi(srcdoc, "TagBrlyNav", "MitSesTrm"));
};

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MspCrd1Avail") == "true");
	MitCrdUsgAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdUsgAvail") == "true");
	MitCrdUsrAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdUsrAvail") == "true");
	MitCrdPrsAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdPrsAvail") == "true");
	MitCrdFilAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdFilAvail") == "true");
	MitCrdOprAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdOprAvail") == "true");
	MitCrdPtyAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdPtyAvail") == "true");
	MspCrd2Avail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MspCrd2Avail") == "true");
	MitCrdRegAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdRegAvail") == "true");
	MitCrdLocAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdLocAvail") == "true");
	MitCrdLegAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdLegAvail") == "true");
	MitCrdTtbAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdTtbAvail") == "true");
	MitCrdFltAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdFltAvail") == "true");
	MspCrd3Avail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MspCrd3Avail") == "true");
	MitCrdConAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "MitCrdConAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppBrlyNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitCrdUsg"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdUsg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdUsr"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdUsr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrs"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdPrs"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFil"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdFil"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdOpr"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdOpr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPty"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdPty"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdReg"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdReg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdLoc"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdLoc"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdLeg"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdLeg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdTtb"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdTtb"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFlt"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdFlt"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdCon"), retrieveTi(srcdoc, "TagBrlyNav", "MitCrdCon"));

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdUsg", MitCrdUsgAvail, 20);
	height -= setMitMspAvail("MitCrdUsr", MitCrdUsrAvail, 20);
	height -= setMitMspAvail("MitCrdPrs", MitCrdPrsAvail, 20);
	height -= setMitMspAvail("MitCrdFil", MitCrdFilAvail, 20);
	height -= setMitMspAvail("MitCrdOpr", MitCrdOprAvail, 20);
	height -= setMitMspAvail("MitCrdPty", MitCrdPtyAvail, 20);
	height -= setMitMspAvail("MspCrd2", MspCrd2Avail, 1);
	height -= setMitMspAvail("MitCrdReg", MitCrdRegAvail, 20);
	height -= setMitMspAvail("MitCrdLoc", MitCrdLocAvail, 20);
	height -= setMitMspAvail("MitCrdLeg", MitCrdLegAvail, 20);
	height -= setMitMspAvail("MitCrdTtb", MitCrdTtbAvail, 20);
	height -= setMitMspAvail("MitCrdFlt", MitCrdFltAvail, 20);
	height -= setMitMspAvail("MspCrd3", MspCrd3Avail, 1);
	height -= setMitMspAvail("MitCrdCon", MitCrdConAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function setMitMspAvail(short, avail, dh) {
	var mendoc = doc.getElementById("Menu").contentDocument;

	if (!avail) mendoc.getElementById("tr" + short).setAttribute("class", "hide");

	if (avail) return 0;
	else return dh;
};

function setMitActive(short, active) {
	var mendoc = doc.getElementById("Menu").contentDocument;
	var mit = mendoc.getElementById(short);

	if (active) {
		mit.setAttribute("class", "item");
		mit.setAttribute("onclick", "handle" + short + "Click()");
	} else {
		mit.setAttribute("class", "itemdis");
		mit.setAttribute("onclick", "");
	};
};

// --- detached panel functionality
function detachPnl(sref, _scrJref) {
	if ((scrJrefPnld != "") && (scrJrefPnld != _scrJref)) attachPnl();

	scrJrefPnld = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divPnldshld");
	mydiv.setAttribute("class", "pnldshld");
	mydiv.setAttribute("style", "height:" + (getHeight()-35) + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "pnld");
	mydiv.setAttribute("id", "divPnld");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Pnld");
	myif.setAttribute("src", "./" + sref + "_d.html?scrJref=" + _scrJref);
	myif.setAttribute("width", "891"); /// PRELIMINARY
	myif.setAttribute("height", "586");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function maximizePnl() {
	/// TBD
};

function attachPnl() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divPnldshld"));
	body.removeChild(doc.getElementById("divPnld"));

	scrJrefPnld = "";
};

// --- dialog functionality
function showDlg(sref, _scrJref)  {
	if ((scrJrefDlg != "") && (scrJrefDlg != _scrJref)) hideDlg();

	scrJrefDlg = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divDlgshld");
	mydiv.setAttribute("class", "dlgshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "dlg");
	mydiv.setAttribute("id", "divDlg");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Dlg");
	myif.setAttribute("src", "./" + sref + ".html?scrJref=" + _scrJref);
	myif.setAttribute("width", "691");
	if ((sref == "DlgBrlyNavLoaini")) myif.setAttribute("height", "585");
	else myif.setAttribute("height", "555");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideDlg() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divDlgshld"));
	body.removeChild(doc.getElementById("divDlg"));

	scrJrefDlg = "";
};

// --- alert functionality
function showAlr(_scrJref, blkcontinf, blkfeedfmcb)  {
	// update information
	scrJrefAlr = _scrJref;

	replaceSrcblock(blkcontinf, "ContInfBrlyAlert", srcdoc);
	replaceSrcblock(blkfeedfmcb, "FeedFMcbAlert", srcdoc);

	// show alert
	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divAlrshld");
	mydiv.setAttribute("class", "alrshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "alr");
	mydiv.setAttribute("id", "divAlr");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Alr");
	myif.setAttribute("src", "../iframe/alr.xml");
	myif.setAttribute("width", "501");
	myif.setAttribute("height", "60");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideAlr(numFMcb) {
	var str = serializeDpchAppAlert(scrJrefAlr, numFMcb);
	sendReq(str, doc, handleDpchAppDoReply);

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divAlrshld"));
	body.removeChild(doc.getElementById("divAlr"));

	scrJrefAlr = "";
};

function initAlr() {
	var alrdoc = doc.getElementById("Alr").contentDocument;

	var height = 30+2+3+25;

	setTextContent(alrdoc, alrdoc.getElementById("TxtCpt"), retrieveCi(srcdoc, "ContInfBrlyAlert", "TxtCpt"));

	height += fillAlrTxtMsgFromCont(alrdoc, srcdoc, "ContInfBrlyAlert");

	doc.getElementById("Alr").setAttribute("height", "" + height);

	fillAlrMcbFromFeed(alrdoc, srcdoc, "FeedFMcbAlert");
};

// --- expand state management
function changeHeight(pnlshort, height) {
	var divPnldshld = doc.getElementById("divPnldshld");
	var divDlgshld = doc.getElementById("divDlgshld");
	var divAlrshld = doc.getElementById("divAlrshld");

	if (pnlshort == "Admin") {
		doc.getElementById("tdAdmin").setAttribute("height", "" + height);
		doc.getElementById("Admin").setAttribute("height", "" + height);
	} else if (pnlshort == "Base") {
		doc.getElementById("tdBase").setAttribute("height", "" + height);
		doc.getElementById("Base").setAttribute("height", "" + height);
	} else if (pnlshort == "Connect") {
		doc.getElementById("tdConnect").setAttribute("height", "" + height);
		doc.getElementById("Connect").setAttribute("height", "" + height);
	};

	if (divPnldshld) divPnldshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divDlgshld) divDlgshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divAlrshld) divAlrshld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgloaini = retrieveSi(srcdoc, "StatShrBrlyNav", "scrJrefDlgloaini");
	var pnladminAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "pnladminAvail") == "true");
	var pnlbaseAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "pnlbaseAvail") == "true");
	var pnlconnectAvail = (retrieveSi(srcdoc, "StatShrBrlyNav", "pnlconnectAvail") == "true");

	if (scrJrefDlgloaini != "") {
		if (scrJrefDlg != scrJrefDlgloaini) showDlg("DlgBrlyNavLoaini", scrJrefDlgloaini);
	} else if (scrJrefDlg != "") hideDlg();

	setPnlAvail("Admin", pnladminAvail);
	setPnlAvail("Base", pnlbaseAvail);
	setPnlAvail("Connect", pnlconnectAvail);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleUnload() {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyNavDo", scrJref, "close");
	sendReq(str, doc);
};

function handleMitClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMitCrdopenClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, consref) {
	window.open(retrieveCi(srcdoc, "ContInfBrlyNav", consref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyNavData", "ContInfBrlyNav", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyNavData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngBrlyNavData", "StatAppBrlyNav", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyNavData", "StatShrBrlyNav", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyNavData", "TagBrlyNav", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngBrlyNavData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrBrlyNav", "scrJrefHeadbar");
				scrJrefAdmin = retrieveSi(srcdoc, "StatShrBrlyNav", "scrJrefAdmin");
				scrJrefBase = retrieveSi(srcdoc, "StatShrBrlyNav", "scrJrefBase");
				scrJrefConnect = retrieveSi(srcdoc, "StatShrBrlyNav", "scrJrefConnect");

				scrJrefPnld = "";

				scrJrefDlg = "";

				scrJrefAlr = "";

				// load sub-panels one by one
				checkInitdone();
			};
		};
	};
};

function handleDpchAppDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//brly:*");

		if (blk) {
			if (blk.nodeName == "DpchEngBrlyConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngBrlyAlert") {
				// show alert with new content
				showAlr(retrieveValue(dom, "//brly:DpchEngBrlyAlert/brly:scrJref"),
						retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:ContInfBrlyAlert"),
						retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:FeedFMcbAlert"));

			} else if (blk.nodeName == "DpchEngBrlyNavData") {
				mergeDpchEngData(dom);
				refresh();
			};

			restartNotify();
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
				showAlr(retrieveValue(dom, "//brly:DpchEngBrlyAlert/brly:scrJref"),
						retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:ContInfBrlyAlert"),
						retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:FeedFMcbAlert"));
			};

			restartNotify();
		};
	};
};

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

	window.open("../CrdBrlyStart/CrdBrlyStart.html?do=Logout", "_self");
};

function restartNotify() {
	var srefIxBrlyVReqitmode = retrieveSi(srcdoc, "StatAppBrlyNav", "srefIxBrlyVReqitmode");

	if (srefIxBrlyVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxBrlyVReqitmode = "notify";
		setSi(srcdoc, "StatAppBrlyNav", "srefIxBrlyVReqitmode", srefIxBrlyVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxBrlyVReqitmode = retrieveSi(srcdoc, "StatAppBrlyNav", "srefIxBrlyVReqitmode");

	if (srefIxBrlyVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		var str = serializeDpchApp("DpchAppBrlyResume", scrJref);
		sendReq(str, doc, handleDpchAppResumeReply);
	};
};

function handleDpchAppResumeReply() {
	var dom, blk;

	if ((doc.req.readyState == 4) && (doc.req.status == 404)) {
		terminate();

	} else if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");

		if (blk) if (blk.nodeName == "DpchEngBrlyAck") restartNotify();
	};
};

function iteratePoll() {
	iterateReqit();
};

function iterateReqit(ev) {
	var accepted, _scrJref, mask;

	var news = false;
	var iterate = true;

	var srefIxBrlyVReqitmode = retrieveSi(srcdoc, "StatAppBrlyNav", "srefIxBrlyVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppBrlyNav", "latency"));

	if (doc.reqit && ev) {
		if (doc.reqit.readyState != 4) {
			iterate = false;

		} else if ((doc.reqit.readyState == 4) && (doc.reqit.status == 404)) {
			iterate = false;

			terminate();

		} else if (doc.reqit.readyState == 4) {
			dom = doc.reqit.responseXML;

			// check dispatch type
			blk = retrieveBlock(dom, "//brly:*");

			if (blk) {
				if (blk.nodeName == "DpchEngBrlyAck") {
					// no news
					// alert("no news");

				} else if (blk.nodeName == "DpchEngBrlySuspend") {
					// change to "poll" mode
					news = true;

					srefIxBrlyVReqitmode = "poll";
					setSi(srcdoc, "StatAppBrlyNav", "srefIxBrlyVReqitmode", srefIxBrlyVReqitmode);

				} else {
					// request with content
					news = true;

					_scrJref = retrieveValue(dom, "//brly:*/brly:scrJref");

					if (blk.nodeName == "DpchEngBrlyAlert") {
						// card-based treatment even for scrJref corresponding to panel / dialog
						showAlr(retrieveValue(dom, "//brly:DpchEngBrlyAlert/brly:scrJref"),
								retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:ContInfBrlyAlert"),
								retrieveBlock(dom, "//brly:DpchEngBrlyAlert/brly:FeedFMcbAlert"));

					} else {
						if (_scrJref == scrJref) {
							if (blk.nodeName == "DpchEngBrlyConfirm") {
								accepted = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:accepted");

								if (accepted == "false") {
									// arrives on card close
									iterate = false;
									terminate();
								};

							} else if (blk.nodeName == "DpchEngBrlyNavData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else if (_scrJref == scrJrefPnld) {
							doc.getElementById("Pnld").contentWindow.handleDpchEng(dom, blk.nodeName);

						} else if (_scrJref == scrJrefDlg) {
							doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, blk.nodeName);

						} else if (_scrJref == scrJrefAdmin) {
							doc.getElementById("Admin").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefBase) {
							doc.getElementById("Base").contentWindow.handleDpchEng(dom, blk.nodeName);
						} else if (_scrJref == scrJrefConnect) {
							doc.getElementById("Connect").contentWindow.handleDpchEng(dom, blk.nodeName);

						} else {
							// alert("got a '" + blk.nodeName + "' from job with scrJref " + _scrJref);
						};
					};
				};
			};
		};
	};

	if ((srefIxBrlyVReqitmode == "notify") && iterate) {
		// send notify request
		if (!doc.reqit) doc.reqit = new XMLHttpRequest();
		doc.reqit.onreadystatechange = iterateReqit;
		doc.reqit.open("GET", "/notify/" + scrJref, true);
		doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		doc.reqit.send("");

	} else if ((srefIxBrlyVReqitmode == "poll") && iterate) {
		if (!ev || (news && ev)) {
			// send poll request
			if (!doc.reqit) doc.reqit = new XMLHttpRequest();
			doc.reqit.onreadystatechange = iterateReqit;
			doc.reqit.open("GET", "/poll/" + scrJref, true);
			doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			doc.reqit.send("");

		} else {
			// wait
			doc.timeout = setTimeout(iteratePoll, latency*1000);
		};
	};
};

