/**
  * \file PnlBrlyLocMap.js
  * web client functionality for panel PnlBrlyLocMap
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	// change container heights
	getRecwnd().changeHeight("Map", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Map_side").setAttribute("height", "30");
	doc.getElementById("Map_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Map_side").src = "./PnlBrlyLocMap_aside.html";
	doc.getElementById("Map_cont").src = "./PnlBrlyLocMap_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Map_side").src = "./PnlBrlyLocMap_bside.html";
	doc.getElementById("Map_cont").src = "./PnlBrlyLocMap_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Map_side").contentDocument;
	contdoc = doc.getElementById("Map_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyLocMap", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Map_side").contentDocument;
	contdoc = doc.getElementById("Map_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Map_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Map_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyLocMap", "Cpt"));
	initBut(contcontdoc, "ButHome", retrieveTi(srcdoc, "TagBrlyLocMap", "ButHome"));
	initCpt(contcontdoc, "CptScl", retrieveTi(srcdoc, "TagBrlyLocMap", "CptScl"));
	initBut(contcontdoc, "ButRefresh", retrieveTi(srcdoc, "TagBrlyLocMap", "ButRefresh"));
	contcontdoc.getElementById("Dld").setAttribute("href", "/download/" + scrJref);
	setTextContent(contcontdoc, contcontdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagBrlyLocMap", "Dld"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocMap", "srefIxBrlyVExpstate");

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
	var height = 160; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN

	refreshSld(contcontdoc, "SldScl", false, false, parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", "SldSclMin")), parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", "SldSclMax")), parseFloat(retrieveCi(srcdoc, "ContIacBrlyLocMap", "SldScl")), true, false);

	// IP refreshBD --- END

	getRecwnd().changeHeight("Map", height+31, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Map_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Map_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Map_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocMap", "srefIxBrlyVExpstate");

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
	srcdoc = doc.getElementById("Map_src").contentDocument;

	var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButDetachClick() {
};

function handleButAttachClick() {
};

function handleTxfSclKey(evt) {
	// IP handleTxfSclKey --- INSERT
	return true;
};

function handleTxfSclChange() {
	// IP handleTxfSclChange --- INSERT
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyLocMapDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacBrlyLocMap", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacBrlyLocMap", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocMapData", scrJref, "ContIacBrlyLocMap");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacBrlyLocMap", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacBrlyLocMap", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocMapData", scrJref, "ContIacBrlyLocMap");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(false, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, false, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacBrlyLocMap", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocMapData", scrJref, "ContIacBrlyLocMap");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacBrlyLocMap", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocMapData", scrJref, "ContIacBrlyLocMap");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyLocMap", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacBrlyLocMap", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyLocMapData", scrJref, "ContIacBrlyLocMap");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "ContIacBrlyLocMap", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "ContInfBrlyLocMap", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "StatShrBrlyLocMap", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "TagBrlyLocMap", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "ListBrlyQLocMapLeg", srcdoc)) mask.push("rstleg");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "ListBrlyQLocMapProxLocation", srcdoc)) mask.push("rstproxlocation");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "ListBrlyQLocMapVisLocation", srcdoc)) mask.push("rstvislocation");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "StatShrQryBrlyLocMapLeg", srcdoc)) mask.push("statshrqryleg");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "StatShrQryBrlyLocMapProxLocation", srcdoc)) mask.push("statshrqryproxlocation");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "StatShrQryBrlyLocMapVisLocation", srcdoc)) mask.push("statshrqryvislocation");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "StgIacQryBrlyLocMapLeg", srcdoc)) mask.push("stgiacqryleg");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "StgIacQryBrlyLocMapProxLocation", srcdoc)) mask.push("stgiacqryproxlocation");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "StgIacQryBrlyLocMapVisLocation", srcdoc)) mask.push("stgiacqryvislocation");
	if (updateSrcblock(dom, "DpchEngBrlyLocMapData", "StgIacBrlyLocMap", srcdoc)) mask.push("stgiac");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyLocMapData") {
		var oldSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocMap", "srefIxBrlyVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocMap", "srefIxBrlyVExpstate");

			if (srefIxBrlyVExpstate != oldSrefIxBrlyVExpstate) {
				if (srefIxBrlyVExpstate == "mind") minimize();
				else if (srefIxBrlyVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngBrlyLocMapImage") {
		handleDpchEngBrlyLocMapImage(dom);
	};
};

function handleDpchEngBrlyLocMapImage(dom) {
	// IP handleDpchEngBrlyLocMapImage --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngBrlyLocMapData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Map");
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

			} else if (blk.nodeName == "DpchEngBrlyLocMapData") {
				var oldSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocMap", "srefIxBrlyVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyLocMap", "srefIxBrlyVExpstate");

					if (srefIxBrlyVExpstate != oldSrefIxBrlyVExpstate) {
						if (srefIxBrlyVExpstate == "mind") minimize();
						else if (srefIxBrlyVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			};
		};
	};
};

