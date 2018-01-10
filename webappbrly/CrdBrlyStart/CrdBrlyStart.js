/**
  * \file CrdBrlyStart.js
  * web client functionality for Brly start page
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

function setCont(pnlshort) {
	if (pnlshort == "Login") {
		doc.getElementById("tdCont").setAttribute("height", "128");
		doc.getElementById("Cont").setAttribute("height", "120");
	} else if (pnlshort == "Fail") {
		doc.getElementById("tdCont").setAttribute("height", "103");
		doc.getElementById("Cont").setAttribute("height", "95");
	} else if (pnlshort == "Logout") {
		doc.getElementById("tdCont").setAttribute("height", "103");
		doc.getElementById("Cont").setAttribute("height", "95");
	};

	doc.getElementById("Cont").src = "./PnlBrlyStart" + pnlshort + ".html";
};

function getLocale() {
	return(doc.srefIxBrlyVLocale);
};

function setLocale(srefIxBrlyVLocale) {
	doc.srefIxBrlyVLocale = srefIxBrlyVLocale;

	// store locale to cookie
	var expdate = new Date();
	var exptime = expdate.getTime() + (30*24*3600*1000);
	expdate.setTime(exptime);

	doc.cookie = "srefIxBrlyVLocale=" + srefIxBrlyVLocale + ";expires=" + expdate.toGMTString();
};

function handleLoad() {
	var cookiestr;
	var strptr;
	var pnlshort;

	doc = document;

	// set locale according to cookie (default: enus)
	doc.srefIxBrlyVLocale = "enus";

	if (doc.cookie) {
		cookiestr = doc.cookie;

		strptr = cookiestr.search("srefIxBrlyVLocale");
		if (strptr != -1) {
			cookiestr = cookiestr.substring(strptr);
			if (cookiestr.search(";") == -1)
				doc.srefIxBrlyVLocale = cookiestr.substring(cookiestr.search("=")+1);
			else
				doc.srefIxBrlyVLocale = cookiestr.substring(cookiestr.search("=")+1, cookiestr.search(";"));

			// set cookie again, to postpone expiry date
			setLocale(doc.srefIxBrlyVLocale);
		};
	};

	// determine panel to display from URL
	if (window.location.search.indexOf("do=") == -1) {
		pnlshort = "Login";

	} else {
		pnlshort = window.location.search.substr(window.location.search.indexOf("do=")+3);
		if ( (pnlshort != "Fail") && (pnlshort != "Logout") ) pnlshort = "Login";
	};

	setCont(pnlshort);
};

