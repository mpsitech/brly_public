/**
  * \file VecBrlyVTag.cpp
  * vector VecBrlyVTag (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVTag.h"

/******************************************************************************
 namespace VecBrlyVTag
 ******************************************************************************/

uint VecBrlyVTag::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "about") return ABOUT;
	else if (s == "always") return ALWAYS;
	else if (s == "cancel") return CANCEL;
	else if (s == "close") return CLOSE;
	else if (s == "clsess") return CLSESS;
	else if (s == "clust") return CLUST;
	else if (s == "create") return CREATE;
	else if (s == "detail") return DETAIL;
	else if (s == "done") return DONE;
	else if (s == "download") return DOWNLOAD;
	else if (s == "emplong") return EMPLONG;
	else if (s == "empshort") return EMPSHORT;
	else if (s == "error") return ERROR;
	else if (s == "filename") return FILENAME;
	else if (s == "fls") return FLS;
	else if (s == "for") return FOR;
	else if (s == "general") return GENERAL;
	else if (s == "goto") return GOTO;
	else if (s == "grp") return GRP;
	else if (s == "help") return HELP;
	else if (s == "import") return IMPORT;
	else if (s == "loaini") return LOAINI;
	else if (s == "nav") return NAV;
	else if (s == "new") return NEW;
	else if (s == "no") return NO;
	else if (s == "ok") return OK;
	else if (s == "opscpllast") return OPSCPLLAST;
	else if (s == "opsprep") return OPSPREP;
	else if (s == "own") return OWN;
	else if (s == "progress") return PROGRESS;
	else if (s == "quest") return QUEST;
	else if (s == "run") return RUN;
	else if (s == "sess") return SESS;
	else if (s == "showlong") return SHOWLONG;
	else if (s == "showshort") return SHOWSHORT;
	else if (s == "stop") return STOP;
	else if (s == "tru") return TRU;
	else if (s == "upload") return UPLOAD;
	else if (s == "yes") return YES;

	return(0);
};

string VecBrlyVTag::getSref(
			const uint ix
		) {
	if (ix == ABOUT) return("about");
	else if (ix == ALWAYS) return("always");
	else if (ix == CANCEL) return("cancel");
	else if (ix == CLOSE) return("close");
	else if (ix == CLSESS) return("clsess");
	else if (ix == CLUST) return("clust");
	else if (ix == CREATE) return("create");
	else if (ix == DETAIL) return("detail");
	else if (ix == DONE) return("done");
	else if (ix == DOWNLOAD) return("download");
	else if (ix == EMPLONG) return("emplong");
	else if (ix == EMPSHORT) return("empshort");
	else if (ix == ERROR) return("error");
	else if (ix == FILENAME) return("filename");
	else if (ix == FLS) return("fls");
	else if (ix == FOR) return("for");
	else if (ix == GENERAL) return("general");
	else if (ix == GOTO) return("goto");
	else if (ix == GRP) return("grp");
	else if (ix == HELP) return("help");
	else if (ix == IMPORT) return("import");
	else if (ix == LOAINI) return("loaini");
	else if (ix == NAV) return("nav");
	else if (ix == NEW) return("new");
	else if (ix == NO) return("no");
	else if (ix == OK) return("ok");
	else if (ix == OPSCPLLAST) return("opscpllast");
	else if (ix == OPSPREP) return("opsprep");
	else if (ix == OWN) return("own");
	else if (ix == PROGRESS) return("progress");
	else if (ix == QUEST) return("quest");
	else if (ix == RUN) return("run");
	else if (ix == SESS) return("sess");
	else if (ix == SHOWLONG) return("showlong");
	else if (ix == SHOWSHORT) return("showshort");
	else if (ix == STOP) return("stop");
	else if (ix == TRU) return("tru");
	else if (ix == UPLOAD) return("upload");
	else if (ix == YES) return("yes");

	return("");
};

string VecBrlyVTag::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == ABOUT) return("About BeamRelay");
		else if (ix == ALWAYS) return("always");
		else if (ix == CANCEL) return("cancel");
		else if (ix == CLOSE) return("close");
		else if (ix == CLSESS) return("close session");
		else if (ix == CLUST) return("clustered with");
		else if (ix == CREATE) return("create");
		else if (ix == DETAIL) return("details");
		else if (ix == DONE) return("done");
		else if (ix == DOWNLOAD) return("download");
		else if (ix == EMPLONG) return("no entries");
		else if (ix == EMPSHORT) return("empty");
		else if (ix == ERROR) return("error");
		else if (ix == FILENAME) return("file name");
		else if (ix == FLS) return("No");
		else if (ix == FOR) return("for &pretit;");
		else if (ix == GENERAL) return("generally");
		else if (ix == GOTO) return("go to");
		else if (ix == GRP) return("group");
		else if (ix == HELP) return("BeamRelay help");
		else if (ix == IMPORT) return("import");
		else if (ix == LOAINI) return("load initialization data");
		else if (ix == NAV) return("navigation");
		else if (ix == NEW) return("new");
		else if (ix == NO) return("no");
		else if (ix == OK) return("OK");
		else if (ix == OPSCPLLAST) return("operations completed, last");
		else if (ix == OPSPREP) return("operations prepared");
		else if (ix == OWN) return("owner");
		else if (ix == PROGRESS) return("progress");
		else if (ix == QUEST) return("question");
		else if (ix == RUN) return("execute");
		else if (ix == SESS) return("session");
		else if (ix == SHOWLONG) return("showing &firstdisp; to &lastdisp; of &ntot;");
		else if (ix == SHOWSHORT) return("&firstdisp;-&lastdisp; of &ntot;");
		else if (ix == TRU) return("Yes");
		else if (ix == UPLOAD) return("upload");
		else if (ix == YES) return("yes");
		else return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == ABOUT) return("\\u00dcber BeamRelay");
		else if (ix == ALWAYS) return("immer");
		else if (ix == CANCEL) return("abbrechen");
		else if (ix == CLOSE) return("Schliessen");
		else if (ix == CLSESS) return("Sitzung beenden");
		else if (ix == CLUST) return("geb\\u00fcndelt mit");
		else if (ix == CREATE) return("erstellen");
		else if (ix == DETAIL) return("Details");
		else if (ix == DONE) return("fertig");
		else if (ix == DOWNLOAD) return("herunterladen");
		else if (ix == EMPLONG) return("keine Eintr\\u00e4ge");
		else if (ix == EMPSHORT) return("leer");
		else if (ix == ERROR) return("Fehler");
		else if (ix == FILENAME) return("Dateiname");
		else if (ix == FLS) return("Nein");
		else if (ix == FOR) return("f\\u00fcr &pretit;");
		else if (ix == GENERAL) return("allgemein");
		else if (ix == GOTO) return("gehe zu");
		else if (ix == GRP) return("Gruppe");
		else if (ix == HELP) return("BeamRelay Hilfe");
		else if (ix == IMPORT) return("importieren");
		else if (ix == LOAINI) return("Initialisierungsdaten laden");
		else if (ix == NAV) return("Navigation");
		else if (ix == NEW) return("neu");
		else if (ix == NO) return("nein");
		else if (ix == OK) return("OK");
		else if (ix == OPSCPLLAST) return("Operationen ausgef\\u00fchrt, letzte");
		else if (ix == OPSPREP) return("Operationen vorbereitet");
		else if (ix == OWN) return("Eigent\\u00fcmer");
		else if (ix == PROGRESS) return("Fortschritt");
		else if (ix == QUEST) return("Frage");
		else if (ix == RUN) return("ausf\\u00fchren");
		else if (ix == SESS) return("Sitzung");
		else if (ix == SHOWLONG) return("zeige &firstdisp; bis &lastdisp; von &ntot;");
		else if (ix == SHOWSHORT) return("&firstdisp;-&lastdisp; von &ntot;");
		else if (ix == TRU) return("Ja");
		else if (ix == UPLOAD) return("hochladen");
		else if (ix == YES) return("ja");
		else return(getTitle(ix, 1));
	};

	return("");
};

void VecBrlyVTag::appendToFeed(
			const uint ix
			, const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.appendIxSrefTitles(ix, getSref(ix), getTitle(ix, ixBrlyVLocale));
};

