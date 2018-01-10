/**
  * \file PnlBrlyConPre.js
  * web client functionality for panel PnlBrlyConPre
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppBrlyConPre", "srefIxBrlyVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppBrlyConPre", "srefIxBrlyVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Pre", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Pre_side").setAttribute("height", "30");
	doc.getElementById("Pre_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Pre_side").src = "./PnlBrlyConPre_aside.html";
	doc.getElementById("Pre_cont").src = "./PnlBrlyConPre_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppBrlyConPre", "srefIxBrlyVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppBrlyConPre", "srefIxBrlyVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Pre_side").src = "./PnlBrlyConPre_bside.html";
	doc.getElementById("Pre_cont").src = "./PnlBrlyConPre_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Pre_side").contentDocument;
	contdoc = doc.getElementById("Pre_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyConPre", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Pre_side").contentDocument;
	contdoc = doc.getElementById("Pre_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Pre_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Pre_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyConPre", "Cpt"));
	initCpt(contcontdoc, "CptTme", retrieveTi(srcdoc, "TagBrlyConPre", "CptTme"));
	initCpt(contcontdoc, "CptPhi", retrieveTi(srcdoc, "TagBrlyConPre", "CptPhi"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyConPre", "srefIxBrlyVExpstate");

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
	var height = 60; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshSld(contcontdoc, "SldTme", false, false, parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", "SldTmeMin")), parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", "SldTmeMax")), parseFloat(retrieveCi(srcdoc, "ContIacBrlyConPre", "SldTme")), true, false);

	refreshSld(contcontdoc, "SldPhi", false, false, parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", "SldPhiMin")), parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", "SldPhiMax")), parseFloat(retrieveCi(srcdoc, "ContIacBrlyConPre", "SldPhi")), true, false);

	// IP refreshBD --- END

	getRecwnd().changeHeight("Pre", height+31, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Pre_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Pre_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Pre_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatAppBrlyConPre", "srefIxBrlyVExpstate");

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
	srcdoc = doc.getElementById("Pre_src").contentDocument;

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

// --- generalized event handlers for shared controls

function handleSldJpleftMov(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Jpleftl").setAttribute("class", "sldlhlt");
	};
};

function handleSldJpleftMou(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Jpleftl").setAttribute("class", "sldl");
};

function handleSldJpleftClick(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, oldVal, val;

	var min, max, rast;

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacBrlyConPre", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Rast"));

	if (_rast) {
		if (log) val = oldVal / rast;
		else val = oldVal - rast;

		if (val < min) val = min;
		if (val > max) val = max;

	} else {
		pos = getSldPosFromEvtx(false, evt.clientX);
		val = getSldValFromPos(min, max, rast, pos);
	};

	pos = getSldPosFromVal(min, max, val);

	setSldPos(_doc, ctlsref, false, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacBrlyConPre", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConPreData", scrJref, "ContIacBrlyConPre");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleSldJprightMov(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Jprightl").setAttribute("class", "sldlhlt");
	};
};

function handleSldJprightMou(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Jprightl").setAttribute("class", "sldl");
};

function handleSldJprightClick(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, oldVal, val;

	var min, max, rast;

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacBrlyConPre", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Rast"));

	if (_rast) {
		if (log) val = oldVal * rast;
		else val = oldVal + rast;

		if (val < min) val = min;
		if (val > max) val = max;

	} else {
		pos = getSldPosFromEvtx(false, evt.clientX);
		val = getSldValFromPos(min, max, rast, pos);
	};

	pos = getSldPosFromVal(min, max, val);

	setSldPos(_doc, ctlsref, false, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacBrlyConPre", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConPreData", scrJref, "ContIacBrlyConPre");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleSldMov(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Bar").setAttribute("class", "sldlhlt");
};

function handleSldMou(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Bar").setAttribute("class", "sldl");
	};
};

function handleSldMdn(_doc, ctlsref) {
	_doc.getElementById("td" + ctlsref).setAttribute("onmousemove", "handle" + ctlsref + "Move(event)");
	_doc.getElementById("td" + ctlsref).setAttribute("onmouseup", "handle" + ctlsref + "Mup(event)");
};

function handleSldMove(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, val;

	var min, max, rast;

	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(false, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, false, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacBrlyConPre", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConPreData", scrJref, "ContIacBrlyConPre");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Rast"));
		else rast = 0.0;

		val = parseFloat(elem.value);
		if (isNaN(val)) val = 0.0;

		if (log) {
			val = alignSldLogval(min, max, rast, val);
			pos = getSldPosFromLogval(min, max, val);
		} else {
			val = alignSldVal(min, max, rast, val);
			pos = getSldPosFromVal(min, max, val);
		};

		setSldPos(_doc, ctlsref, false, pos);
		setSldVal(_doc, ctlsref, val, true, true);

		if (shr) {
			setCi(srcdoc, "ContIacBrlyConPre", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConPreData", scrJref, "ContIacBrlyConPre");
			sendReq(str, doc, handleDpchAppDataDoReply);

		} else {
			window["handle" + ctlsref + "Change"](val);
		};

		return false;
	};

	return true;
};

function handleSldValChange(_doc, ctlsref, shr, log, _rast) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConPre", ctlsref + "Rast"));
	else rast = 0.0;

	val = parseFloat(elem.value);
	if (isNaN(val)) val = 0.0;

	if (log) {
		val = alignSldLogval(min, max, rast, val);
		pos = getSldPosFromLogval(min, max, val);
	} else {
		val = alignSldVal(min, max, rast, val);
		pos = getSldPosFromVal(min, max, val);
	};

	setSldPos(_doc, ctlsref, false, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacBrlyConPre", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConPreData", scrJref, "ContIacBrlyConPre");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyConPreData", "ContIacBrlyConPre", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyConPreData", "StatAppBrlyConPre", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngBrlyConPreData", "StatShrBrlyConPre", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyConPreData", "TagBrlyConPre", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyConPreData") {
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
			if (blk.nodeName == "DpchEngBrlyConPreData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Pre");
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

			} else if (blk.nodeName == "DpchEngBrlyConPreData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

