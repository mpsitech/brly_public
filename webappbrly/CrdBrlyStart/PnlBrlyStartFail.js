/**
  * \file PnlBrlyStartFail.js
  * web client functionality for Brly login failure panel
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function refresh(srefIxBrlyVLocale) {
	if (srefIxBrlyVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Error");
		setTextContent(doc, doc.getElementById("CptMessage"), "Login failed.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Back");
	} else if (srefIxBrlyVLocale == "dech") {
		setTextContent(doc, doc.getElementById("Cpt"), "Fehler");
		setTextContent(doc, doc.getElementById("CptMessage"), "Anmeldung fehlgeschlagen.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Zur\\u00fcck");
	};
};

function handleLoad() {
	doc = document;

	// set captions according to card locale
	refresh(getCrdwnd().getLocale());
};

function handleButLoginClick() {
	getCrdwnd().setCont("Login");
};

