/**
  * \file PnlBrlyStartLogin.js
  * web client functionality for Brly login panel
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function refresh(srefIxBrlyVLocale) {
	var pup = doc.getElementById("PupLocale");
	var opt;

	clearElem(pup);

	if (srefIxBrlyVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Login");

		opt = doc.createElement("option");
		opt.setAttribute("value", "enus");
		setTextContent(doc, opt, "English (United States)");
		pup.appendChild(opt);
		opt = doc.createElement("option");
		opt.setAttribute("value", "dech");
		setTextContent(doc, opt, "German (Switzerland)");
		pup.appendChild(opt);

		setTextContent(doc, doc.getElementById("CptUsername"), "User name");
		setTextContent(doc, doc.getElementById("CptPassword"), "Password");
		setTextContent(doc, doc.getElementById("ButReset"), "Reset");
		setTextContent(doc, doc.getElementById("ButLogin"), "Login");
	} else if (srefIxBrlyVLocale == "dech") {
		setTextContent(doc, doc.getElementById("Cpt"), "Anmeldung");

		opt = doc.createElement("option");
		opt.setAttribute("value", "enus");
		setTextContent(doc, opt, "Englisch (Vereinigte Staaten)");
		pup.appendChild(opt);
		opt = doc.createElement("option");
		opt.setAttribute("value", "dech");
		setTextContent(doc, opt, "Deutsch (Schweiz)");
		pup.appendChild(opt);

		setTextContent(doc, doc.getElementById("CptUsername"), "Benutzername");
		setTextContent(doc, doc.getElementById("CptPassword"), "Passwort");
		setTextContent(doc, doc.getElementById("ButReset"), "Zur\\u00fccksetzen");
		setTextContent(doc, doc.getElementById("ButLogin"), "Anmelden");
	};

	pup.value = srefIxBrlyVLocale;
};

function handleLoad() {
	doc = document;

	// set captions according to card locale
	refresh(getCrdwnd().getLocale());
};

function handlePupLocaleChange() {
	srefIxBrlyVLocale = doc.getElementById("PupLocale").value;
	refresh(srefIxBrlyVLocale);

	// notify card to change cookie
	getCrdwnd().setLocale(srefIxBrlyVLocale);
};

function handleTxfPasswordKey(evt) {
	if (evt.keyCode == 13) {
		handleButLoginClick();
		return false;
	};

	return true;
};

function handleButResetClick() {
	doc.getElementById("TxfUsername").value = "";
	doc.getElementById("TxfPassword").value = "";
};

function handleButLoginClick() {
	var str = serializeDpchAppLogin(doc.getElementById("TxfPassword").value, doc.getElementById("TxfUsername").value, getCrdwnd().getLocale());
	sendReq(str, doc, handleDpchAppLoginReply);
};

function handleDpchAppLoginReply() {
	var dom;

	var accepted, scrJref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		accepted = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:accepted");
		scrJref = retrieveValue(dom, "//brly:DpchEngBrlyConfirm/brly:scrJref");

		if (accepted == "true") {
			var str = serializeDpchApp("DpchAppBrlyInit", scrJref);
			sendReq(str, doc, handleDpchAppInitReply);

		} else {
			getCrdwnd().setCont("Fail");
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//brly:*");
		if (blk) {
			if (blk.nodeName == "DpchEngSessBrlyData") {
				var scrJrefCrdnav = retrieveValue(dom, "//brly:DpchEngSessBrlyData/brly:StatShrSessBrly/brly:Si[@sref='scrJrefCrdnav']");

				if (scrJrefCrdnav == "") getCrdwnd().setCont("Fail");
				else window.open("/web/CrdBrlyNav/CrdBrlyNav.html?scrJref=" + scrJrefCrdnav, "_parent");
			};
		};
	};
};

function serializeDpchAppLogin(password, username, srefIxBrlyVLocale) {
	var dpch, elem, txt;
	var ser;
	var str;

	dpch = doc.createElement("DpchAppRootBrlyLogin");

	elem = doc.createElement("password");
	txt = doc.createTextNode(password);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("username");
	txt = doc.createTextNode(username);
	elem.appendChild(txt);
	dpch.appendChild(elem);

	elem = doc.createElement("srefIxBrlyVLocale");
	txt = doc.createTextNode(srefIxBrlyVLocale);
	elem.appendChild(txt);
	dpch.appendChild(elem);	

	ser = new XMLSerializer();

	str = ser.serializeToString(dpch);

	return(str);
};

