// IP file --- KEEP
/**
  * \file PnlBrlyConMap.js
  * web client functionality for panel PnlBrlyConMap
  * \author Alexander Wirthmueller
  * \date created: 27 Jun 2015
  * \date modified: 29 Jun 2015
  */

// IP cust --- IBEGIN
function refreshLive(mask) {
	if (retrieveSi(srcdoc, "StatShrBrlyConMap", "srefIxBrlyVExpstate") != "regd") return;

	var cvsctx = contcontdoc.getElementById("mapcvs").getContext("2d");

	var d = doc.imgdat.data;

	var w = 400;
	var h = 300;

	var ix, ix2;
	if ( (mask.indexOf("red") != -1) && (mask.indexOf("green") != -1) && (mask.indexOf("blue") != -1) ) {
		if (doc.red.length == (w*h) ) {
			for (var i=0;i<h;i++) {
				for (var j=0;j<w;j++) {
					ix = i*w+j;
					ix2 = 4 * ix;

					d[ix2] = doc.red[ix];
					d[ix2+1] = doc.green[ix];
					d[ix2+2] = doc.blue[ix];
					d[ix2+3] = 255;
				};
			};
		};
	};

	cvsctx.putImageData(doc.imgdat, 0, 0);
};
// IP cust --- IEND

// --- expand state management
function minimize(updh) {
///
	// change container heights
	getRecwnd().changeHeight("Map", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Map_side").setAttribute("height", "30");
	doc.getElementById("Map_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Map_side").src = "./PnlBrlyConMap_aside.html";
	doc.getElementById("Map_cont").src = "./PnlBrlyConMap_a.html";
///
};

function regularize() {
///
	// change content (container heights in refreshB)
	doc.getElementById("Map_side").src = "./PnlBrlyConMap_bside.html";
	doc.getElementById("Map_cont").src = "./PnlBrlyConMap_b.html";
///
};

///
function detach() {
	getRecwnd().getCrdwnd().showPnld("Map", scrJref);
};

function attach() {
	getCrdwnd().hidePnld();
};
///

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Map_side").contentDocument;
	contdoc = doc.getElementById("Map_cont").contentDocument;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyConMap", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Map_side").contentDocument;
	contdoc = doc.getElementById("Map_cont").contentDocument;
// IP initB.hdrdoc --- BEGIN
	hdrdoc = contdoc.getElementById("Map_hdr").contentDocument;
// IP initB.hdrdoc --- END
	contcontdoc = contdoc.getElementById("Map_cont").contentDocument;

// IP initB --- RBEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyConMap", "Cpt"));

	doc.imgdat = contcontdoc.getElementById("mapcvs").getContext("2d").createImageData(400, 300);
// IP initB --- REND

	refreshB();
};

///
function initD() {
	if (!doc) return;

	hdrdoc = doc.getElementById("Map_hdr").contentDocument;
	contcontdoc = doc.getElementById("Map_cont").contentDocument;

// IP initD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagBrlyConMap", "Cpt"));
	initBut(contcontdoc, "ButHome", retrieveTi(srcdoc, "TagBrlyConMap", "ButHome"));
	initCpt(contcontdoc, "CptScl", retrieveTi(srcdoc, "TagBrlyConMap", "CptScl"));
	initBut(contcontdoc, "ButRefresh", retrieveTi(srcdoc, "TagBrlyConMap", "ButRefresh"));
	setTextContent(contcontdoc, contcontdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagBrlyConMap", "Dld"));
// IP initD --- END

	refreshD();
};
///

function init() {
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConMap", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		initA();
	} else if (srefIxBrlyVExpstate == "regd") {
		initB();
///
	} else if (srefIxBrlyVExpstate == "detd") {
		initD();
///
	};
};

function refreshA() {
};

function refreshB() {
	var height = 309; // full cont height

// IP refreshB.vars --- BEGIN

// IP refreshB.vars --- END

// IP refreshB --- RBEGIN
	refreshLive([]);
// IP refreshB --- REND

	getRecwnd().changeHeight("Map", height+31, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Map_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Map_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Map_cont").setAttribute("height", "" + height);
};

///
function refreshD() {
	
};
///

function refresh() {
///
	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConMap", "srefIxBrlyVExpstate");

	if (srefIxBrlyVExpstate == "mind") {
		refreshA();
	} else if (srefIxBrlyVExpstate == "regd") {
		refreshB();
///
	} else if (srefIxBrlyVExpstate == "detd") {
		refreshD();
///
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppBrlyConMapDo", scrJref, ctlsref + "Click");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacBrlyConMap", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacBrlyConMap", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConMapData", scrJref, "ContIacBrlyConMap");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacBrlyConMap", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacBrlyConMap", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConMapData", scrJref, "ContIacBrlyConMap");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(false, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, false, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacBrlyConMap", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConMapData", scrJref, "ContIacBrlyConMap");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacBrlyConMap", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConMapData", scrJref, "ContIacBrlyConMap");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrBrlyConMap", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacBrlyConMap", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppBrlyConMapData", scrJref, "ContIacBrlyConMap");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "ContIacBrlyConMap", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "ContInfBrlyConMap", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StatShrBrlyConMap", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "TagBrlyConMap", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "ListBrlyQConMapFlight", srcdoc)) mask.push("rstflight");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "ListBrlyQConMapLeg", srcdoc)) mask.push("rstleg");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "ListBrlyQConMapLocation", srcdoc)) mask.push("rstlocation");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "ListBrlyQConMapNode", srcdoc)) mask.push("rstnode");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "ListBrlyQConMapRelay", srcdoc)) mask.push("rstrelay");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StatShrQryBrlyConMapFlight", srcdoc)) mask.push("statshrqryflight");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StatShrQryBrlyConMapLeg", srcdoc)) mask.push("statshrqryleg");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StatShrQryBrlyConMapLocation", srcdoc)) mask.push("statshrqrylocation");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StatShrQryBrlyConMapNode", srcdoc)) mask.push("statshrqrynode");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StatShrQryBrlyConMapRelay", srcdoc)) mask.push("statshrqryrelay");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StgIacQryBrlyConMapFlight", srcdoc)) mask.push("stgiacqryflight");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StgIacQryBrlyConMapLeg", srcdoc)) mask.push("stgiacqryleg");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StgIacQryBrlyConMapLocation", srcdoc)) mask.push("stgiacqrylocation");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StgIacQryBrlyConMapNode", srcdoc)) mask.push("stgiacqrynode");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StgIacQryBrlyConMapRelay", srcdoc)) mask.push("stgiacqryrelay");
	if (updateSrcblock(dom, "DpchEngBrlyConMapData", "StgIacBrlyConMap", srcdoc)) mask.push("stgiac");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngBrlyConMapData") {
///
		var oldSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConMap", "srefIxBrlyVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConMap", "srefIxBrlyVExpstate");

			if (srefIxBrlyVExpstate != oldSrefIxBrlyVExpstate) {
				if (srefIxBrlyVExpstate == "mind") minimize();
				else if (srefIxVBrlyVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
///
	} else if (dpch == "DpchEngBrlyConMapLive") {
		handleDpchEngBrlyConMapLive(dom);
	};
};

function handleDpchEngBrlyConMapLive(dom) {
// IP handleDpchEngBrlyConMapLive --- IBEGIN
	var mask = [];

	var resnode;

	updateSrcblock(dom, "DpchEngBrlyConMapLive", "ListBrlyQConMapFlight", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "ListBrlyQConMapLeg", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "ListBrlyQConMapLocation", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "ListBrlyQConMapNode", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "ListBrlyQConMapRelay", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "StatShrQryBrlyConMapFlight", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "StatShrQryBrlyConMapLeg", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "StatShrQryBrlyConMapLocation", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "StatShrQryBrlyConMapNode", srcdoc);
	updateSrcblock(dom, "DpchEngBrlyConMapLive", "StatShrQryBrlyConMapRelay", srcdoc);

	resnode = getNode(dom, "//brly:DpchEngBrlyConMapLive/brly:red");
	if (resnode) {
		doc.red = parseUtinyintvec(resnode.textContent);
		mask.push("red");
	};

	resnode = getNode(dom, "//brly:DpchEngBrlyConMapLive/brly:green");
	if (resnode) {
		doc.green = parseUtinyintvec(resnode.textContent);
		mask.push("green");
	};

	resnode = getNode(dom, "//brly:DpchEngBrlyConMapLive/brly:blue");
	if (resnode) {
		doc.blue = parseUtinyintvec(resnode.textContent);
		mask.push("blue");
	};

	var srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConMap", "srefIxBrlyVExpstate");
	if (srefIxBrlyVExpstate == "regd") refreshLive(mask);
// IP handleDpchEngBrlyConMapLive --- IEND
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngBrlyConMapData") {
				mergeDpchEngData(dom);

				init();

///
				var recwnd = getRecwnd();
				if (recwnd) recwnd.setInitdone("Map");
///
			};
		};
	};
};

function handleDpchAppDataDoReply() {
///
	var dom, blk, mask;
	var oldSrefIxBrlyVExpstate, srefIxBrlyVExpstate;
///

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//brly:*");

		if (blk) {
			if (blk.nodeName == "DpchEngBrlyConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngBrlyConMapData") {
///
				oldSrefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConMap", "srefIxBrlyVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					srefIxBrlyVExpstate = retrieveSi(srcdoc, "StatShrBrlyConMap", "srefIxBrlyVExpstate");
					if (srefIxBrlyVExpstate != oldSrefIxBrlyVExpstate) {
						if (oldSrefIxBrlyVExpstate == "detd") {
							attach();
						} else {
							if (srefIxBrlyVExpstate == "mind") minimize(true);
							else if (srefIxBrlyVExpstate == "regd") regularize();
							else if (srefIxBrlyVExpstate == "detd") detach();
						};
					};
				} else {
					refresh();
				};
///
			};
		};
	};
};
