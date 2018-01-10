/**
  * \file PnlBrlyStartLogout.js
  * web client functionality for Brly logout panel
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function refresh(srefIxBrlyVLocale) {
	if (srefIxBrlyVLocale == "enus") {
		setTextContent(doc, doc.getElementById("Cpt"), "Logout");
		setTextContent(doc, doc.getElementById("CptMessage"), "Your session has been terminated.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Login screen");
	} else if (srefIxBrlyVLocale == "dech") {
		setTextContent(doc, doc.getElementById("Cpt"), "Abmeldung");
		setTextContent(doc, doc.getElementById("CptMessage"), "Ihre Sitzung wurde beendet.");
		setTextContent(doc, doc.getElementById("ButLogin"), "Anmeldefenster");
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

