/**
  * \file PnlBrlyNavHeadbar.js
  * web client functionality for panel PnlBrlyNavHeadbar
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// --- view initialization
function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var width = 995;

	var appw = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenAppCptwidth"));
	contdoc.getElementById("colMenApp").setAttribute("width", "" + appw);
	width -= appw+1;

	var sesw = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenSesCptwidth"));
	contdoc.getElementById("colMenSes").setAttribute("width", "" + sesw);
	width -= sesw+1;

	var crdw = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenCrdCptwidth"));
	contdoc.getElementById("colMenCrd").setAttribute("width", "" + crdw);
	width -= crdw+1;

	contdoc.getElementById("colFill").setAttribute("width", "" + width);

	var MenCrdAvail = (retrieveSi(srcdoc, "StatShrBrlyNavHeadbar", "MenCrdAvail") == "true");
	if (!MenCrdAvail) contdoc.getElementById("tdMenCrd").setAttribute("class", "hide");

	// captions
	setTextContent(contdoc, contdoc.getElementById("MenApp"), retrieveTi(srcdoc, "TagBrlyNavHeadbar", "MenApp") + "\\u00a0");
	setTextContent(contdoc, contdoc.getElementById("MenSes"), "\\u00a0" + retrieveTi(srcdoc, "TagBrlyNavHeadbar", "MenSes") + "\\u00a0");
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagBrlyNavHeadbar", "MenCrd") + "\\u00a0");
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Headbar_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleMenAppClick() {
	var width;
	width = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenAppWidth"));

	getCrdwnd().toggleMenu("App", 3, width, 63);
};

function handleMenSesClick() {
	var appw;
	var width;

	appw = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenAppCptwidth"));
	width = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenSesWidth"));

	getCrdwnd().toggleMenu("Ses", 3+appw+1, width, 83);
};

function handleMenCrdClick() {
	var appw, sesw;
	var width;

	appw = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenAppCptwidth"));
	sesw = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenSesCptwidth"));
	width = parseInt(retrieveSi(srcdoc, "StgInfBrlyNavHeadbar", "MenCrdWidth"));

	getCrdwnd().toggleMenu("Crd", 3+appw+1+sesw+1, width, 244);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyNavHeadbarData", "StatShrBrlyNavHeadbar", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyNavHeadbarData", "StgInfBrlyNavHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngBrlyNavHeadbarData", "TagBrlyNavHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngBrlyNavHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};

