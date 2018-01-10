/**
  * \file DbsBrly_vecs.cpp
  * C++ wrapper for database DbsBrly (implementation of vectors)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

/******************************************************************************
 class DbsBrly::VecVAccess
 ******************************************************************************/

uint DbsBrly::VecVAccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	else if (s == "none") return NONE;
	else if (s == "view") return VIEW;

	return(0);
};

string DbsBrly::VecVAccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	else if (ix == NONE) return("none");
	else if (ix == VIEW) return("view");

	return("");
};

string DbsBrly::VecVAccess::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == FULL) return("full");
		else if (ix == NONE) return("none");
		else if (ix == VIEW) return("view");
	} else if (ixBrlyVLocale == 2) {
		if (ix == FULL) return("voll");
		else if (ix == NONE) return("kein");
		else if (ix == VIEW) return("anschauen");
	};

	return("");
};

void DbsBrly::VecVAccess::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=3;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVCard
 ******************************************************************************/

uint DbsBrly::VecVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdbrlynav") return CRDBRLYNAV;
	else if (s == "crdbrlyusg") return CRDBRLYUSG;
	else if (s == "crdbrlyusr") return CRDBRLYUSR;
	else if (s == "crdbrlyprs") return CRDBRLYPRS;
	else if (s == "crdbrlyfil") return CRDBRLYFIL;
	else if (s == "crdbrlyopr") return CRDBRLYOPR;
	else if (s == "crdbrlypty") return CRDBRLYPTY;
	else if (s == "crdbrlyreg") return CRDBRLYREG;
	else if (s == "crdbrlyloc") return CRDBRLYLOC;
	else if (s == "crdbrlyleg") return CRDBRLYLEG;
	else if (s == "crdbrlyttb") return CRDBRLYTTB;
	else if (s == "crdbrlyflt") return CRDBRLYFLT;
	else if (s == "crdbrlyseg") return CRDBRLYSEG;
	else if (s == "crdbrlycon") return CRDBRLYCON;
	else if (s == "crdbrlyrly") return CRDBRLYRLY;

	return(0);
};

string DbsBrly::VecVCard::getSref(
			const uint ix
		) {
	if (ix == CRDBRLYNAV) return("CrdBrlyNav");
	else if (ix == CRDBRLYUSG) return("CrdBrlyUsg");
	else if (ix == CRDBRLYUSR) return("CrdBrlyUsr");
	else if (ix == CRDBRLYPRS) return("CrdBrlyPrs");
	else if (ix == CRDBRLYFIL) return("CrdBrlyFil");
	else if (ix == CRDBRLYOPR) return("CrdBrlyOpr");
	else if (ix == CRDBRLYPTY) return("CrdBrlyPty");
	else if (ix == CRDBRLYREG) return("CrdBrlyReg");
	else if (ix == CRDBRLYLOC) return("CrdBrlyLoc");
	else if (ix == CRDBRLYLEG) return("CrdBrlyLeg");
	else if (ix == CRDBRLYTTB) return("CrdBrlyTtb");
	else if (ix == CRDBRLYFLT) return("CrdBrlyFlt");
	else if (ix == CRDBRLYSEG) return("CrdBrlySeg");
	else if (ix == CRDBRLYCON) return("CrdBrlyCon");
	else if (ix == CRDBRLYRLY) return("CrdBrlyRly");

	return("");
};

string DbsBrly::VecVCard::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == CRDBRLYUSG) return("user groups");
		else if (ix == CRDBRLYUSR) return("users");
		else if (ix == CRDBRLYPRS) return("persons");
		else if (ix == CRDBRLYFIL) return("files");
		else if (ix == CRDBRLYOPR) return("operators");
		else if (ix == CRDBRLYPTY) return("plane types");
		else if (ix == CRDBRLYREG) return("regions");
		else if (ix == CRDBRLYLOC) return("locations");
		else if (ix == CRDBRLYLEG) return("legs");
		else if (ix == CRDBRLYTTB) return("timetables");
		else if (ix == CRDBRLYFLT) return("flights");
		else if (ix == CRDBRLYSEG) return("segments");
		else if (ix == CRDBRLYCON) return("connections");
		else if (ix == CRDBRLYRLY) return("relays");
		else return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == CRDBRLYUSG) return("Benutzergruppen");
		else if (ix == CRDBRLYUSR) return("Benutzer");
		else if (ix == CRDBRLYPRS) return("Personen");
		else if (ix == CRDBRLYFIL) return("Dateien");
		else if (ix == CRDBRLYOPR) return("Betreiber");
		else if (ix == CRDBRLYPTY) return("Flugzeugtypen");
		else if (ix == CRDBRLYREG) return("Regionen");
		else if (ix == CRDBRLYLOC) return("Orte");
		else if (ix == CRDBRLYLEG) return("Strecken");
		else if (ix == CRDBRLYTTB) return("Flugpl\\u00e4ne");
		else if (ix == CRDBRLYFLT) return("Fl\\u00fcge");
		else if (ix == CRDBRLYSEG) return("Segmente");
		else if (ix == CRDBRLYCON) return("Verbindungen");
		else if (ix == CRDBRLYRLY) return("Verbindungsketten");
		else return(getTitle(ix, 1));
	};

	return("");
};

void DbsBrly::VecVCard::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=15;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVControl
 ******************************************************************************/

uint DbsBrly::VecVControl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pnlbrlyusglist.tcosrf") return PNLBRLYUSGLIST_TCOSRF;
	else if (s == "pnlbrlyusgaaccess.tcocrd") return PNLBRLYUSGAACCESS_TCOCRD;
	else if (s == "pnlbrlyusgaaccess.tcouac") return PNLBRLYUSGAACCESS_TCOUAC;
	else if (s == "pnlbrlyusgmnuser.tcomref") return PNLBRLYUSGMNUSER_TCOMREF;
	else if (s == "pnlbrlyusgmnuser.tcoulv") return PNLBRLYUSGMNUSER_TCOULV;
	else if (s == "pnlbrlyusrlist.tcoprs") return PNLBRLYUSRLIST_TCOPRS;
	else if (s == "pnlbrlyusrlist.tcosrf") return PNLBRLYUSRLIST_TCOSRF;
	else if (s == "pnlbrlyusrlist.tcousg") return PNLBRLYUSRLIST_TCOUSG;
	else if (s == "pnlbrlyusrlist.tcoste") return PNLBRLYUSRLIST_TCOSTE;
	else if (s == "pnlbrlyusrlist.tcolcl") return PNLBRLYUSRLIST_TCOLCL;
	else if (s == "pnlbrlyusrlist.tcoulv") return PNLBRLYUSRLIST_TCOULV;
	else if (s == "pnlbrlyusraaccess.tcocrd") return PNLBRLYUSRAACCESS_TCOCRD;
	else if (s == "pnlbrlyusraaccess.tcouac") return PNLBRLYUSRAACCESS_TCOUAC;
	else if (s == "pnlbrlyusr1nsession.tcoref") return PNLBRLYUSR1NSESSION_TCOREF;
	else if (s == "pnlbrlyusrmnusergroup.tcomref") return PNLBRLYUSRMNUSERGROUP_TCOMREF;
	else if (s == "pnlbrlyusrmnusergroup.tcoulv") return PNLBRLYUSRMNUSERGROUP_TCOULV;
	else if (s == "pnlbrlyprslist.tcotit") return PNLBRLYPRSLIST_TCOTIT;
	else if (s == "pnlbrlyprslist.tcofnm") return PNLBRLYPRSLIST_TCOFNM;
	else if (s == "pnlbrlyprslist.tcolnm") return PNLBRLYPRSLIST_TCOLNM;
	else if (s == "pnlbrlyprslist.tcogrp") return PNLBRLYPRSLIST_TCOGRP;
	else if (s == "pnlbrlyprslist.tcoown") return PNLBRLYPRSLIST_TCOOWN;
	else if (s == "pnlbrlyprslist.tcosex") return PNLBRLYPRSLIST_TCOSEX;
	else if (s == "pnlbrlyprslist.tcotel") return PNLBRLYPRSLIST_TCOTEL;
	else if (s == "pnlbrlyprslist.tcoeml") return PNLBRLYPRSLIST_TCOEML;
	else if (s == "pnlbrlyprsadetail.tcotyp") return PNLBRLYPRSADETAIL_TCOTYP;
	else if (s == "pnlbrlyprsadetail.tcoval") return PNLBRLYPRSADETAIL_TCOVAL;
	else if (s == "pnlbrlyfillist.tcofnm") return PNLBRLYFILLIST_TCOFNM;
	else if (s == "pnlbrlyfillist.tcoret") return PNLBRLYFILLIST_TCORET;
	else if (s == "pnlbrlyfillist.tcoreu") return PNLBRLYFILLIST_TCOREU;
	else if (s == "pnlbrlyfillist.tcocnt") return PNLBRLYFILLIST_TCOCNT;
	else if (s == "pnlbrlyfillist.tcomim") return PNLBRLYFILLIST_TCOMIM;
	else if (s == "pnlbrlyfillist.tcosiz") return PNLBRLYFILLIST_TCOSIZ;
	else if (s == "pnlbrlyoprlist.tcosrf") return PNLBRLYOPRLIST_TCOSRF;
	else if (s == "pnlbrlyoprlist.tcoica") return PNLBRLYOPRLIST_TCOICA;
	else if (s == "pnlbrlyoprlist.tcotit") return PNLBRLYOPRLIST_TCOTIT;
	else if (s == "pnlbrlyopr1nequipment.tcoref") return PNLBRLYOPR1NEQUIPMENT_TCOREF;
	else if (s == "pnlbrlyptylist.tcosrf") return PNLBRLYPTYLIST_TCOSRF;
	else if (s == "pnlbrlyptylist.tcotit") return PNLBRLYPTYLIST_TCOTIT;
	else if (s == "pnlbrlyptylist.tcoety") return PNLBRLYPTYLIST_TCOETY;
	else if (s == "pnlbrlyptylist.tcocap") return PNLBRLYPTYLIST_TCOCAP;
	else if (s == "pnlbrlypty1nequipment.tcoref") return PNLBRLYPTY1NEQUIPMENT_TCOREF;
	else if (s == "pnlbrlyreglist.tcosrf") return PNLBRLYREGLIST_TCOSRF;
	else if (s == "pnlbrlyreglist.tcotit") return PNLBRLYREGLIST_TCOTIT;
	else if (s == "pnlbrlyreglist.tcosup") return PNLBRLYREGLIST_TCOSUP;
	else if (s == "pnlbrlyreglist.tcodst") return PNLBRLYREGLIST_TCODST;
	else if (s == "pnlbrlyreglist.tcotof") return PNLBRLYREGLIST_TCOTOF;
	else if (s == "pnlbrlyregadstswitch.tcostd") return PNLBRLYREGADSTSWITCH_TCOSTD;
	else if (s == "pnlbrlyregadstswitch.tcostt") return PNLBRLYREGADSTSWITCH_TCOSTT;
	else if (s == "pnlbrlyreg1nlocation.tcoref") return PNLBRLYREG1NLOCATION_TCOREF;
	else if (s == "pnlbrlyregsup1nregion.tcoref") return PNLBRLYREGSUP1NREGION_TCOREF;
	else if (s == "pnlbrlyloclist.tcosrf") return PNLBRLYLOCLIST_TCOSRF;
	else if (s == "pnlbrlyloclist.tcoica") return PNLBRLYLOCLIST_TCOICA;
	else if (s == "pnlbrlyloclist.tcotit") return PNLBRLYLOCLIST_TCOTIT;
	else if (s == "pnlbrlyloclist.tcotyp") return PNLBRLYLOCLIST_TCOTYP;
	else if (s == "pnlbrlyloclist.tcoreg") return PNLBRLYLOCLIST_TCOREG;
	else if (s == "pnlbrlyloclist.tcoeqp") return PNLBRLYLOCLIST_TCOEQP;
	else if (s == "pnlbrlyloclist.tcoalt") return PNLBRLYLOCLIST_TCOALT;
	else if (s == "pnlbrlyloclist.tcothe") return PNLBRLYLOCLIST_TCOTHE;
	else if (s == "pnlbrlyloclist.tcophi") return PNLBRLYLOCLIST_TCOPHI;
	else if (s == "pnlbrlylocbgn1nleg.tcoref") return PNLBRLYLOCBGN1NLEG_TCOREF;
	else if (s == "pnlbrlylocend1nleg.tcoref") return PNLBRLYLOCEND1NLEG_TCOREF;
	else if (s == "pnlbrlyloceqp1nnode.tcoref") return PNLBRLYLOCEQP1NNODE_TCOREF;
	else if (s == "pnlbrlylocmnsegment.tcomref") return PNLBRLYLOCMNSEGMENT_TCOMREF;
	else if (s == "pnlbrlylocmnsegment.tcosta") return PNLBRLYLOCMNSEGMENT_TCOSTA;
	else if (s == "pnlbrlylocmnsegment.tcosto") return PNLBRLYLOCMNSEGMENT_TCOSTO;
	else if (s == "pnlbrlylocmnsegment.tcosp0") return PNLBRLYLOCMNSEGMENT_TCOSP0;
	else if (s == "pnlbrlylocmnsegment.tcosp1") return PNLBRLYLOCMNSEGMENT_TCOSP1;
	else if (s == "pnlbrlylocmnsegment.tcosph") return PNLBRLYLOCMNSEGMENT_TCOSPH;
	else if (s == "pnlbrlylocmnsegment.tcosth") return PNLBRLYLOCMNSEGMENT_TCOSTH;
	else if (s == "pnlbrlylocproxorgmnlocation.tcomref") return PNLBRLYLOCPROXORGMNLOCATION_TCOMREF;
	else if (s == "pnlbrlylocproxorgmnlocation.tcodph") return PNLBRLYLOCPROXORGMNLOCATION_TCODPH;
	else if (s == "pnlbrlylocvisorgmnlocation.tcomref") return PNLBRLYLOCVISORGMNLOCATION_TCOMREF;
	else if (s == "pnlbrlylocmnleg.tcomref") return PNLBRLYLOCMNLEG_TCOMREF;
	else if (s == "pnlbrlylocmnleg.tcolp0") return PNLBRLYLOCMNLEG_TCOLP0;
	else if (s == "pnlbrlylocmnleg.tcolp1") return PNLBRLYLOCMNLEG_TCOLP1;
	else if (s == "pnlbrlylocmnleg.tcolph") return PNLBRLYLOCMNLEG_TCOLPH;
	else if (s == "pnlbrlylocmnleg.tcolth") return PNLBRLYLOCMNLEG_TCOLTH;
	else if (s == "pnlbrlylocmnleg.tcoxp0") return PNLBRLYLOCMNLEG_TCOXP0;
	else if (s == "pnlbrlylocmnleg.tcoxp1") return PNLBRLYLOCMNLEG_TCOXP1;
	else if (s == "pnlbrlylocmnflight.tcomref") return PNLBRLYLOCMNFLIGHT_TCOMREF;
	else if (s == "pnlbrlylocmnflight.tcosta") return PNLBRLYLOCMNFLIGHT_TCOSTA;
	else if (s == "pnlbrlylocmnflight.tcosto") return PNLBRLYLOCMNFLIGHT_TCOSTO;
	else if (s == "pnlbrlylocmnflight.tcoxsa") return PNLBRLYLOCMNFLIGHT_TCOXSA;
	else if (s == "pnlbrlylocmnflight.tcoxso") return PNLBRLYLOCMNFLIGHT_TCOXSO;
	else if (s == "pnlbrlyloceqpmnconnection.tcomref") return PNLBRLYLOCEQPMNCONNECTION_TCOMREF;
	else if (s == "pnlbrlyleglist.tcoblo") return PNLBRLYLEGLIST_TCOBLO;
	else if (s == "pnlbrlyleglist.tcoelo") return PNLBRLYLEGLIST_TCOELO;
	else if (s == "pnlbrlyleglist.tcotyp") return PNLBRLYLEGLIST_TCOTYP;
	else if (s == "pnlbrlyleglist.tcoalt") return PNLBRLYLEGLIST_TCOALT;
	else if (s == "pnlbrlylegcor1nconnection.tcoref") return PNLBRLYLEGCOR1NCONNECTION_TCOREF;
	else if (s == "pnlbrlyleg1nflight.tcoref") return PNLBRLYLEG1NFLIGHT_TCOREF;
	else if (s == "pnlbrlylegmnlocation.tcomref") return PNLBRLYLEGMNLOCATION_TCOMREF;
	else if (s == "pnlbrlylegmnlocation.tcolp0") return PNLBRLYLEGMNLOCATION_TCOLP0;
	else if (s == "pnlbrlylegmnlocation.tcolp1") return PNLBRLYLEGMNLOCATION_TCOLP1;
	else if (s == "pnlbrlylegmnlocation.tcolph") return PNLBRLYLEGMNLOCATION_TCOLPH;
	else if (s == "pnlbrlylegmnlocation.tcolth") return PNLBRLYLEGMNLOCATION_TCOLTH;
	else if (s == "pnlbrlylegmnlocation.tcoxp0") return PNLBRLYLEGMNLOCATION_TCOXP0;
	else if (s == "pnlbrlylegmnlocation.tcoxp1") return PNLBRLYLEGMNLOCATION_TCOXP1;
	else if (s == "pnlbrlylegorgmnleg.tcomref") return PNLBRLYLEGORGMNLEG_TCOMREF;
	else if (s == "pnlbrlylegorgmnleg.tcodp0") return PNLBRLYLEGORGMNLEG_TCODP0;
	else if (s == "pnlbrlylegorgmnleg.tcodp1") return PNLBRLYLEGORGMNLEG_TCODP1;
	else if (s == "pnlbrlylegorgmnleg.tcoop0") return PNLBRLYLEGORGMNLEG_TCOOP0;
	else if (s == "pnlbrlylegorgmnleg.tcoop1") return PNLBRLYLEGORGMNLEG_TCOOP1;
	else if (s == "pnlbrlylegorgmnleg.tcoxd0") return PNLBRLYLEGORGMNLEG_TCOXD0;
	else if (s == "pnlbrlylegorgmnleg.tcoxd1") return PNLBRLYLEGORGMNLEG_TCOXD1;
	else if (s == "pnlbrlylegorgmnleg.tcoxo0") return PNLBRLYLEGORGMNLEG_TCOXO0;
	else if (s == "pnlbrlylegorgmnleg.tcoxo1") return PNLBRLYLEGORGMNLEG_TCOXO1;
	else if (s == "pnlbrlyttblist.tcotit") return PNLBRLYTTBLIST_TCOTIT;
	else if (s == "pnlbrlyttblist.tcofil") return PNLBRLYTTBLIST_TCOFIL;
	else if (s == "pnlbrlyttblist.tcoali") return PNLBRLYTTBLIST_TCOALI;
	else if (s == "pnlbrlyttblist.tcosta") return PNLBRLYTTBLIST_TCOSTA;
	else if (s == "pnlbrlyttblist.tcosto") return PNLBRLYTTBLIST_TCOSTO;
	else if (s == "pnlbrlyttb1nflight.tcoref") return PNLBRLYTTB1NFLIGHT_TCOREF;
	else if (s == "pnlbrlyttbref1nfile.tcoref") return PNLBRLYTTBREF1NFILE_TCOREF;
	else if (s == "pnlbrlyfltlist.tcosrf") return PNLBRLYFLTLIST_TCOSRF;
	else if (s == "pnlbrlyfltlist.tcoeqp") return PNLBRLYFLTLIST_TCOEQP;
	else if (s == "pnlbrlyfltlist.tcoleg") return PNLBRLYFLTLIST_TCOLEG;
	else if (s == "pnlbrlyfltlist.tcosta") return PNLBRLYFLTLIST_TCOSTA;
	else if (s == "pnlbrlyfltlist.tcosto") return PNLBRLYFLTLIST_TCOSTO;
	else if (s == "pnlbrlyfltfafawaypoint.tcotms") return PNLBRLYFLTFAFAWAYPOINT_TCOTMS;
	else if (s == "pnlbrlyfltfafawaypoint.tcolat") return PNLBRLYFLTFAFAWAYPOINT_TCOLAT;
	else if (s == "pnlbrlyfltfafawaypoint.tcolon") return PNLBRLYFLTFAFAWAYPOINT_TCOLON;
	else if (s == "pnlbrlyfltfafawaypoint.tcogsp") return PNLBRLYFLTFAFAWAYPOINT_TCOGSP;
	else if (s == "pnlbrlyfltfafawaypoint.tcoalt") return PNLBRLYFLTFAFAWAYPOINT_TCOALT;
	else if (s == "pnlbrlyfltfafawaypoint.tcoast") return PNLBRLYFLTFAFAWAYPOINT_TCOAST;
	else if (s == "pnlbrlyfltfafawaypoint.tcouty") return PNLBRLYFLTFAFAWAYPOINT_TCOUTY;
	else if (s == "pnlbrlyfltfafawaypoint.tcoach") return PNLBRLYFLTFAFAWAYPOINT_TCOACH;
	else if (s == "pnlbrlyflt1nconnection.tcoref") return PNLBRLYFLT1NCONNECTION_TCOREF;
	else if (s == "pnlbrlyfltref1nsegment.tcoref") return PNLBRLYFLTREF1NSEGMENT_TCOREF;
	else if (s == "pnlbrlyflteqp1nnode.tcoref") return PNLBRLYFLTEQP1NNODE_TCOREF;
	else if (s == "pnlbrlyfltmnlocation.tcomref") return PNLBRLYFLTMNLOCATION_TCOMREF;
	else if (s == "pnlbrlyfltmnlocation.tcosta") return PNLBRLYFLTMNLOCATION_TCOSTA;
	else if (s == "pnlbrlyfltmnlocation.tcosto") return PNLBRLYFLTMNLOCATION_TCOSTO;
	else if (s == "pnlbrlyfltmnlocation.tcoxsa") return PNLBRLYFLTMNLOCATION_TCOXSA;
	else if (s == "pnlbrlyfltmnlocation.tcoxso") return PNLBRLYFLTMNLOCATION_TCOXSO;
	else if (s == "pnlbrlyfltmnconnection.tcomref") return PNLBRLYFLTMNCONNECTION_TCOMREF;
	else if (s == "pnlbrlyfltmnconnection.tcosta") return PNLBRLYFLTMNCONNECTION_TCOSTA;
	else if (s == "pnlbrlyfltmnconnection.tcosto") return PNLBRLYFLTMNCONNECTION_TCOSTO;
	else if (s == "pnlbrlyfltmnconnection.tcolp0") return PNLBRLYFLTMNCONNECTION_TCOLP0;
	else if (s == "pnlbrlyfltmnconnection.tcolp1") return PNLBRLYFLTMNCONNECTION_TCOLP1;
	else if (s == "pnlbrlyfltorgmnflight.tcomref") return PNLBRLYFLTORGMNFLIGHT_TCOMREF;
	else if (s == "pnlbrlyfltorgmnflight.tcosta") return PNLBRLYFLTORGMNFLIGHT_TCOSTA;
	else if (s == "pnlbrlyfltorgmnflight.tcosto") return PNLBRLYFLTORGMNFLIGHT_TCOSTO;
	else if (s == "pnlbrlyfltorgmnflight.tcoxsa") return PNLBRLYFLTORGMNFLIGHT_TCOXSA;
	else if (s == "pnlbrlyfltorgmnflight.tcoxso") return PNLBRLYFLTORGMNFLIGHT_TCOXSO;
	else if (s == "pnlbrlyflteqpmnconnection.tcomref") return PNLBRLYFLTEQPMNCONNECTION_TCOMREF;
	else if (s == "pnlbrlyseglist.tcoret") return PNLBRLYSEGLIST_TCORET;
	else if (s == "pnlbrlyseglist.tcoreu") return PNLBRLYSEGLIST_TCOREU;
	else if (s == "pnlbrlyseglist.tcoal0") return PNLBRLYSEGLIST_TCOAL0;
	else if (s == "pnlbrlyseglist.tcoal1") return PNLBRLYSEGLIST_TCOAL1;
	else if (s == "pnlbrlyseglist.tcoth0") return PNLBRLYSEGLIST_TCOTH0;
	else if (s == "pnlbrlyseglist.tcoth1") return PNLBRLYSEGLIST_TCOTH1;
	else if (s == "pnlbrlyseglist.tcoph0") return PNLBRLYSEGLIST_TCOPH0;
	else if (s == "pnlbrlyseglist.tcoph1") return PNLBRLYSEGLIST_TCOPH1;
	else if (s == "pnlbrlyseglist.tcosta") return PNLBRLYSEGLIST_TCOSTA;
	else if (s == "pnlbrlyseglist.tcosto") return PNLBRLYSEGLIST_TCOSTO;
	else if (s == "pnlbrlysegmnconnection.tcomref") return PNLBRLYSEGMNCONNECTION_TCOMREF;
	else if (s == "pnlbrlysegmnconnection.tcosta") return PNLBRLYSEGMNCONNECTION_TCOSTA;
	else if (s == "pnlbrlysegmnconnection.tcosto") return PNLBRLYSEGMNCONNECTION_TCOSTO;
	else if (s == "pnlbrlysegmnconnection.tcolp0") return PNLBRLYSEGMNCONNECTION_TCOLP0;
	else if (s == "pnlbrlysegmnconnection.tcolp1") return PNLBRLYSEGMNCONNECTION_TCOLP1;
	else if (s == "pnlbrlysegmnlocation.tcomref") return PNLBRLYSEGMNLOCATION_TCOMREF;
	else if (s == "pnlbrlysegmnlocation.tcosta") return PNLBRLYSEGMNLOCATION_TCOSTA;
	else if (s == "pnlbrlysegmnlocation.tcosto") return PNLBRLYSEGMNLOCATION_TCOSTO;
	else if (s == "pnlbrlysegmnlocation.tcosp0") return PNLBRLYSEGMNLOCATION_TCOSP0;
	else if (s == "pnlbrlysegmnlocation.tcosp1") return PNLBRLYSEGMNLOCATION_TCOSP1;
	else if (s == "pnlbrlysegmnlocation.tcosph") return PNLBRLYSEGMNLOCATION_TCOSPH;
	else if (s == "pnlbrlysegmnlocation.tcosth") return PNLBRLYSEGMNLOCATION_TCOSTH;
	else if (s == "pnlbrlysegorgmnsegment.tcomref") return PNLBRLYSEGORGMNSEGMENT_TCOMREF;
	else if (s == "pnlbrlysegorgmnsegment.tcosta") return PNLBRLYSEGORGMNSEGMENT_TCOSTA;
	else if (s == "pnlbrlysegorgmnsegment.tcosto") return PNLBRLYSEGORGMNSEGMENT_TCOSTO;
	else if (s == "pnlbrlysegorgmnsegment.tcodp0") return PNLBRLYSEGORGMNSEGMENT_TCODP0;
	else if (s == "pnlbrlysegorgmnsegment.tcodp1") return PNLBRLYSEGORGMNSEGMENT_TCODP1;
	else if (s == "pnlbrlysegorgmnsegment.tcoop0") return PNLBRLYSEGORGMNSEGMENT_TCOOP0;
	else if (s == "pnlbrlysegorgmnsegment.tcoop1") return PNLBRLYSEGORGMNSEGMENT_TCOOP1;
	else if (s == "pnlbrlyconlist.tcoflt") return PNLBRLYCONLIST_TCOFLT;
	else if (s == "pnlbrlyconlist.tcocor") return PNLBRLYCONLIST_TCOCOR;
	else if (s == "pnlbrlyconlist.tcosta") return PNLBRLYCONLIST_TCOSTA;
	else if (s == "pnlbrlyconlist.tcosto") return PNLBRLYCONLIST_TCOSTO;
	else if (s == "pnlbrlyconlist.tcomod") return PNLBRLYCONLIST_TCOMOD;
	else if (s == "pnlbrlycon1nrelay.tcoref") return PNLBRLYCON1NRELAY_TCOREF;
	else if (s == "pnlbrlyconref1nsegment.tcoref") return PNLBRLYCONREF1NSEGMENT_TCOREF;
	else if (s == "pnlbrlyconmnsegment.tcomref") return PNLBRLYCONMNSEGMENT_TCOMREF;
	else if (s == "pnlbrlyconmnsegment.tcosta") return PNLBRLYCONMNSEGMENT_TCOSTA;
	else if (s == "pnlbrlyconmnsegment.tcosto") return PNLBRLYCONMNSEGMENT_TCOSTO;
	else if (s == "pnlbrlyconmnsegment.tcolp0") return PNLBRLYCONMNSEGMENT_TCOLP0;
	else if (s == "pnlbrlyconmnsegment.tcolp1") return PNLBRLYCONMNSEGMENT_TCOLP1;
	else if (s == "pnlbrlyconmnflight.tcomref") return PNLBRLYCONMNFLIGHT_TCOMREF;
	else if (s == "pnlbrlyconmnflight.tcosta") return PNLBRLYCONMNFLIGHT_TCOSTA;
	else if (s == "pnlbrlyconmnflight.tcosto") return PNLBRLYCONMNFLIGHT_TCOSTO;
	else if (s == "pnlbrlyconmnflight.tcolp0") return PNLBRLYCONMNFLIGHT_TCOLP0;
	else if (s == "pnlbrlyconmnflight.tcolp1") return PNLBRLYCONMNFLIGHT_TCOLP1;
	else if (s == "pnlbrlyconconmnequipment.tcomref") return PNLBRLYCONCONMNEQUIPMENT_TCOMREF;
	else if (s == "pnlbrlyrlylist.tcosta") return PNLBRLYRLYLIST_TCOSTA;
	else if (s == "pnlbrlyrlylist.tcosto") return PNLBRLYRLYLIST_TCOSTO;
	else if (s == "pnlbrlyrlylist.tcocon") return PNLBRLYRLYLIST_TCOCON;
	else if (s == "pnlbrlyrlylist.tcodir") return PNLBRLYRLYLIST_TCODIR;
	else if (s == "pnlbrlyrlylist.tcoctd") return PNLBRLYRLYLIST_TCOCTD;
	else if (s == "pnlbrlyrly1nnode.tcoref") return PNLBRLYRLY1NNODE_TCOREF;

	return(0);
};

string DbsBrly::VecVControl::getSref(
			const uint ix
		) {
	if (ix == PNLBRLYUSGLIST_TCOSRF) return("PnlBrlyUsgList.TcoSrf");
	else if (ix == PNLBRLYUSGAACCESS_TCOCRD) return("PnlBrlyUsgAAccess.TcoCrd");
	else if (ix == PNLBRLYUSGAACCESS_TCOUAC) return("PnlBrlyUsgAAccess.TcoUac");
	else if (ix == PNLBRLYUSGMNUSER_TCOMREF) return("PnlBrlyUsgMNUser.TcoMref");
	else if (ix == PNLBRLYUSGMNUSER_TCOULV) return("PnlBrlyUsgMNUser.TcoUlv");
	else if (ix == PNLBRLYUSRLIST_TCOPRS) return("PnlBrlyUsrList.TcoPrs");
	else if (ix == PNLBRLYUSRLIST_TCOSRF) return("PnlBrlyUsrList.TcoSrf");
	else if (ix == PNLBRLYUSRLIST_TCOUSG) return("PnlBrlyUsrList.TcoUsg");
	else if (ix == PNLBRLYUSRLIST_TCOSTE) return("PnlBrlyUsrList.TcoSte");
	else if (ix == PNLBRLYUSRLIST_TCOLCL) return("PnlBrlyUsrList.TcoLcl");
	else if (ix == PNLBRLYUSRLIST_TCOULV) return("PnlBrlyUsrList.TcoUlv");
	else if (ix == PNLBRLYUSRAACCESS_TCOCRD) return("PnlBrlyUsrAAccess.TcoCrd");
	else if (ix == PNLBRLYUSRAACCESS_TCOUAC) return("PnlBrlyUsrAAccess.TcoUac");
	else if (ix == PNLBRLYUSR1NSESSION_TCOREF) return("PnlBrlyUsr1NSession.TcoRef");
	else if (ix == PNLBRLYUSRMNUSERGROUP_TCOMREF) return("PnlBrlyUsrMNUsergroup.TcoMref");
	else if (ix == PNLBRLYUSRMNUSERGROUP_TCOULV) return("PnlBrlyUsrMNUsergroup.TcoUlv");
	else if (ix == PNLBRLYPRSLIST_TCOTIT) return("PnlBrlyPrsList.TcoTit");
	else if (ix == PNLBRLYPRSLIST_TCOFNM) return("PnlBrlyPrsList.TcoFnm");
	else if (ix == PNLBRLYPRSLIST_TCOLNM) return("PnlBrlyPrsList.TcoLnm");
	else if (ix == PNLBRLYPRSLIST_TCOGRP) return("PnlBrlyPrsList.TcoGrp");
	else if (ix == PNLBRLYPRSLIST_TCOOWN) return("PnlBrlyPrsList.TcoOwn");
	else if (ix == PNLBRLYPRSLIST_TCOSEX) return("PnlBrlyPrsList.TcoSex");
	else if (ix == PNLBRLYPRSLIST_TCOTEL) return("PnlBrlyPrsList.TcoTel");
	else if (ix == PNLBRLYPRSLIST_TCOEML) return("PnlBrlyPrsList.TcoEml");
	else if (ix == PNLBRLYPRSADETAIL_TCOTYP) return("PnlBrlyPrsADetail.TcoTyp");
	else if (ix == PNLBRLYPRSADETAIL_TCOVAL) return("PnlBrlyPrsADetail.TcoVal");
	else if (ix == PNLBRLYFILLIST_TCOFNM) return("PnlBrlyFilList.TcoFnm");
	else if (ix == PNLBRLYFILLIST_TCORET) return("PnlBrlyFilList.TcoRet");
	else if (ix == PNLBRLYFILLIST_TCOREU) return("PnlBrlyFilList.TcoReu");
	else if (ix == PNLBRLYFILLIST_TCOCNT) return("PnlBrlyFilList.TcoCnt");
	else if (ix == PNLBRLYFILLIST_TCOMIM) return("PnlBrlyFilList.TcoMim");
	else if (ix == PNLBRLYFILLIST_TCOSIZ) return("PnlBrlyFilList.TcoSiz");
	else if (ix == PNLBRLYOPRLIST_TCOSRF) return("PnlBrlyOprList.TcoSrf");
	else if (ix == PNLBRLYOPRLIST_TCOICA) return("PnlBrlyOprList.TcoIca");
	else if (ix == PNLBRLYOPRLIST_TCOTIT) return("PnlBrlyOprList.TcoTit");
	else if (ix == PNLBRLYOPR1NEQUIPMENT_TCOREF) return("PnlBrlyOpr1NEquipment.TcoRef");
	else if (ix == PNLBRLYPTYLIST_TCOSRF) return("PnlBrlyPtyList.TcoSrf");
	else if (ix == PNLBRLYPTYLIST_TCOTIT) return("PnlBrlyPtyList.TcoTit");
	else if (ix == PNLBRLYPTYLIST_TCOETY) return("PnlBrlyPtyList.TcoEty");
	else if (ix == PNLBRLYPTYLIST_TCOCAP) return("PnlBrlyPtyList.TcoCap");
	else if (ix == PNLBRLYPTY1NEQUIPMENT_TCOREF) return("PnlBrlyPty1NEquipment.TcoRef");
	else if (ix == PNLBRLYREGLIST_TCOSRF) return("PnlBrlyRegList.TcoSrf");
	else if (ix == PNLBRLYREGLIST_TCOTIT) return("PnlBrlyRegList.TcoTit");
	else if (ix == PNLBRLYREGLIST_TCOSUP) return("PnlBrlyRegList.TcoSup");
	else if (ix == PNLBRLYREGLIST_TCODST) return("PnlBrlyRegList.TcoDst");
	else if (ix == PNLBRLYREGLIST_TCOTOF) return("PnlBrlyRegList.TcoTof");
	else if (ix == PNLBRLYREGADSTSWITCH_TCOSTD) return("PnlBrlyRegADstswitch.TcoStd");
	else if (ix == PNLBRLYREGADSTSWITCH_TCOSTT) return("PnlBrlyRegADstswitch.TcoStt");
	else if (ix == PNLBRLYREG1NLOCATION_TCOREF) return("PnlBrlyReg1NLocation.TcoRef");
	else if (ix == PNLBRLYREGSUP1NREGION_TCOREF) return("PnlBrlyRegSup1NRegion.TcoRef");
	else if (ix == PNLBRLYLOCLIST_TCOSRF) return("PnlBrlyLocList.TcoSrf");
	else if (ix == PNLBRLYLOCLIST_TCOICA) return("PnlBrlyLocList.TcoIca");
	else if (ix == PNLBRLYLOCLIST_TCOTIT) return("PnlBrlyLocList.TcoTit");
	else if (ix == PNLBRLYLOCLIST_TCOTYP) return("PnlBrlyLocList.TcoTyp");
	else if (ix == PNLBRLYLOCLIST_TCOREG) return("PnlBrlyLocList.TcoReg");
	else if (ix == PNLBRLYLOCLIST_TCOEQP) return("PnlBrlyLocList.TcoEqp");
	else if (ix == PNLBRLYLOCLIST_TCOALT) return("PnlBrlyLocList.TcoAlt");
	else if (ix == PNLBRLYLOCLIST_TCOTHE) return("PnlBrlyLocList.TcoThe");
	else if (ix == PNLBRLYLOCLIST_TCOPHI) return("PnlBrlyLocList.TcoPhi");
	else if (ix == PNLBRLYLOCBGN1NLEG_TCOREF) return("PnlBrlyLocBgn1NLeg.TcoRef");
	else if (ix == PNLBRLYLOCEND1NLEG_TCOREF) return("PnlBrlyLocEnd1NLeg.TcoRef");
	else if (ix == PNLBRLYLOCEQP1NNODE_TCOREF) return("PnlBrlyLocEqp1NNode.TcoRef");
	else if (ix == PNLBRLYLOCMNSEGMENT_TCOMREF) return("PnlBrlyLocMNSegment.TcoMref");
	else if (ix == PNLBRLYLOCMNSEGMENT_TCOSTA) return("PnlBrlyLocMNSegment.TcoSta");
	else if (ix == PNLBRLYLOCMNSEGMENT_TCOSTO) return("PnlBrlyLocMNSegment.TcoSto");
	else if (ix == PNLBRLYLOCMNSEGMENT_TCOSP0) return("PnlBrlyLocMNSegment.TcoSp0");
	else if (ix == PNLBRLYLOCMNSEGMENT_TCOSP1) return("PnlBrlyLocMNSegment.TcoSp1");
	else if (ix == PNLBRLYLOCMNSEGMENT_TCOSPH) return("PnlBrlyLocMNSegment.TcoSph");
	else if (ix == PNLBRLYLOCMNSEGMENT_TCOSTH) return("PnlBrlyLocMNSegment.TcoSth");
	else if (ix == PNLBRLYLOCPROXORGMNLOCATION_TCOMREF) return("PnlBrlyLocProxOrgMNLocation.TcoMref");
	else if (ix == PNLBRLYLOCPROXORGMNLOCATION_TCODPH) return("PnlBrlyLocProxOrgMNLocation.TcoDph");
	else if (ix == PNLBRLYLOCVISORGMNLOCATION_TCOMREF) return("PnlBrlyLocVisOrgMNLocation.TcoMref");
	else if (ix == PNLBRLYLOCMNLEG_TCOMREF) return("PnlBrlyLocMNLeg.TcoMref");
	else if (ix == PNLBRLYLOCMNLEG_TCOLP0) return("PnlBrlyLocMNLeg.TcoLp0");
	else if (ix == PNLBRLYLOCMNLEG_TCOLP1) return("PnlBrlyLocMNLeg.TcoLp1");
	else if (ix == PNLBRLYLOCMNLEG_TCOLPH) return("PnlBrlyLocMNLeg.TcoLph");
	else if (ix == PNLBRLYLOCMNLEG_TCOLTH) return("PnlBrlyLocMNLeg.TcoLth");
	else if (ix == PNLBRLYLOCMNLEG_TCOXP0) return("PnlBrlyLocMNLeg.TcoXp0");
	else if (ix == PNLBRLYLOCMNLEG_TCOXP1) return("PnlBrlyLocMNLeg.TcoXp1");
	else if (ix == PNLBRLYLOCMNFLIGHT_TCOMREF) return("PnlBrlyLocMNFlight.TcoMref");
	else if (ix == PNLBRLYLOCMNFLIGHT_TCOSTA) return("PnlBrlyLocMNFlight.TcoSta");
	else if (ix == PNLBRLYLOCMNFLIGHT_TCOSTO) return("PnlBrlyLocMNFlight.TcoSto");
	else if (ix == PNLBRLYLOCMNFLIGHT_TCOXSA) return("PnlBrlyLocMNFlight.TcoXsa");
	else if (ix == PNLBRLYLOCMNFLIGHT_TCOXSO) return("PnlBrlyLocMNFlight.TcoXso");
	else if (ix == PNLBRLYLOCEQPMNCONNECTION_TCOMREF) return("PnlBrlyLocEqpMNConnection.TcoMref");
	else if (ix == PNLBRLYLEGLIST_TCOBLO) return("PnlBrlyLegList.TcoBlo");
	else if (ix == PNLBRLYLEGLIST_TCOELO) return("PnlBrlyLegList.TcoElo");
	else if (ix == PNLBRLYLEGLIST_TCOTYP) return("PnlBrlyLegList.TcoTyp");
	else if (ix == PNLBRLYLEGLIST_TCOALT) return("PnlBrlyLegList.TcoAlt");
	else if (ix == PNLBRLYLEGCOR1NCONNECTION_TCOREF) return("PnlBrlyLegCor1NConnection.TcoRef");
	else if (ix == PNLBRLYLEG1NFLIGHT_TCOREF) return("PnlBrlyLeg1NFlight.TcoRef");
	else if (ix == PNLBRLYLEGMNLOCATION_TCOMREF) return("PnlBrlyLegMNLocation.TcoMref");
	else if (ix == PNLBRLYLEGMNLOCATION_TCOLP0) return("PnlBrlyLegMNLocation.TcoLp0");
	else if (ix == PNLBRLYLEGMNLOCATION_TCOLP1) return("PnlBrlyLegMNLocation.TcoLp1");
	else if (ix == PNLBRLYLEGMNLOCATION_TCOLPH) return("PnlBrlyLegMNLocation.TcoLph");
	else if (ix == PNLBRLYLEGMNLOCATION_TCOLTH) return("PnlBrlyLegMNLocation.TcoLth");
	else if (ix == PNLBRLYLEGMNLOCATION_TCOXP0) return("PnlBrlyLegMNLocation.TcoXp0");
	else if (ix == PNLBRLYLEGMNLOCATION_TCOXP1) return("PnlBrlyLegMNLocation.TcoXp1");
	else if (ix == PNLBRLYLEGORGMNLEG_TCOMREF) return("PnlBrlyLegOrgMNLeg.TcoMref");
	else if (ix == PNLBRLYLEGORGMNLEG_TCODP0) return("PnlBrlyLegOrgMNLeg.TcoDp0");
	else if (ix == PNLBRLYLEGORGMNLEG_TCODP1) return("PnlBrlyLegOrgMNLeg.TcoDp1");
	else if (ix == PNLBRLYLEGORGMNLEG_TCOOP0) return("PnlBrlyLegOrgMNLeg.TcoOp0");
	else if (ix == PNLBRLYLEGORGMNLEG_TCOOP1) return("PnlBrlyLegOrgMNLeg.TcoOp1");
	else if (ix == PNLBRLYLEGORGMNLEG_TCOXD0) return("PnlBrlyLegOrgMNLeg.TcoXd0");
	else if (ix == PNLBRLYLEGORGMNLEG_TCOXD1) return("PnlBrlyLegOrgMNLeg.TcoXd1");
	else if (ix == PNLBRLYLEGORGMNLEG_TCOXO0) return("PnlBrlyLegOrgMNLeg.TcoXo0");
	else if (ix == PNLBRLYLEGORGMNLEG_TCOXO1) return("PnlBrlyLegOrgMNLeg.TcoXo1");
	else if (ix == PNLBRLYTTBLIST_TCOTIT) return("PnlBrlyTtbList.TcoTit");
	else if (ix == PNLBRLYTTBLIST_TCOFIL) return("PnlBrlyTtbList.TcoFil");
	else if (ix == PNLBRLYTTBLIST_TCOALI) return("PnlBrlyTtbList.TcoAli");
	else if (ix == PNLBRLYTTBLIST_TCOSTA) return("PnlBrlyTtbList.TcoSta");
	else if (ix == PNLBRLYTTBLIST_TCOSTO) return("PnlBrlyTtbList.TcoSto");
	else if (ix == PNLBRLYTTB1NFLIGHT_TCOREF) return("PnlBrlyTtb1NFlight.TcoRef");
	else if (ix == PNLBRLYTTBREF1NFILE_TCOREF) return("PnlBrlyTtbRef1NFile.TcoRef");
	else if (ix == PNLBRLYFLTLIST_TCOSRF) return("PnlBrlyFltList.TcoSrf");
	else if (ix == PNLBRLYFLTLIST_TCOEQP) return("PnlBrlyFltList.TcoEqp");
	else if (ix == PNLBRLYFLTLIST_TCOLEG) return("PnlBrlyFltList.TcoLeg");
	else if (ix == PNLBRLYFLTLIST_TCOSTA) return("PnlBrlyFltList.TcoSta");
	else if (ix == PNLBRLYFLTLIST_TCOSTO) return("PnlBrlyFltList.TcoSto");
	else if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOTMS) return("PnlBrlyFltFafAWaypoint.TcoTms");
	else if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOLAT) return("PnlBrlyFltFafAWaypoint.TcoLat");
	else if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOLON) return("PnlBrlyFltFafAWaypoint.TcoLon");
	else if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOGSP) return("PnlBrlyFltFafAWaypoint.TcoGsp");
	else if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOALT) return("PnlBrlyFltFafAWaypoint.TcoAlt");
	else if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOAST) return("PnlBrlyFltFafAWaypoint.TcoAst");
	else if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOUTY) return("PnlBrlyFltFafAWaypoint.TcoUty");
	else if (ix == PNLBRLYFLTFAFAWAYPOINT_TCOACH) return("PnlBrlyFltFafAWaypoint.TcoAch");
	else if (ix == PNLBRLYFLT1NCONNECTION_TCOREF) return("PnlBrlyFlt1NConnection.TcoRef");
	else if (ix == PNLBRLYFLTREF1NSEGMENT_TCOREF) return("PnlBrlyFltRef1NSegment.TcoRef");
	else if (ix == PNLBRLYFLTEQP1NNODE_TCOREF) return("PnlBrlyFltEqp1NNode.TcoRef");
	else if (ix == PNLBRLYFLTMNLOCATION_TCOMREF) return("PnlBrlyFltMNLocation.TcoMref");
	else if (ix == PNLBRLYFLTMNLOCATION_TCOSTA) return("PnlBrlyFltMNLocation.TcoSta");
	else if (ix == PNLBRLYFLTMNLOCATION_TCOSTO) return("PnlBrlyFltMNLocation.TcoSto");
	else if (ix == PNLBRLYFLTMNLOCATION_TCOXSA) return("PnlBrlyFltMNLocation.TcoXsa");
	else if (ix == PNLBRLYFLTMNLOCATION_TCOXSO) return("PnlBrlyFltMNLocation.TcoXso");
	else if (ix == PNLBRLYFLTMNCONNECTION_TCOMREF) return("PnlBrlyFltMNConnection.TcoMref");
	else if (ix == PNLBRLYFLTMNCONNECTION_TCOSTA) return("PnlBrlyFltMNConnection.TcoSta");
	else if (ix == PNLBRLYFLTMNCONNECTION_TCOSTO) return("PnlBrlyFltMNConnection.TcoSto");
	else if (ix == PNLBRLYFLTMNCONNECTION_TCOLP0) return("PnlBrlyFltMNConnection.TcoLp0");
	else if (ix == PNLBRLYFLTMNCONNECTION_TCOLP1) return("PnlBrlyFltMNConnection.TcoLp1");
	else if (ix == PNLBRLYFLTORGMNFLIGHT_TCOMREF) return("PnlBrlyFltOrgMNFlight.TcoMref");
	else if (ix == PNLBRLYFLTORGMNFLIGHT_TCOSTA) return("PnlBrlyFltOrgMNFlight.TcoSta");
	else if (ix == PNLBRLYFLTORGMNFLIGHT_TCOSTO) return("PnlBrlyFltOrgMNFlight.TcoSto");
	else if (ix == PNLBRLYFLTORGMNFLIGHT_TCOXSA) return("PnlBrlyFltOrgMNFlight.TcoXsa");
	else if (ix == PNLBRLYFLTORGMNFLIGHT_TCOXSO) return("PnlBrlyFltOrgMNFlight.TcoXso");
	else if (ix == PNLBRLYFLTEQPMNCONNECTION_TCOMREF) return("PnlBrlyFltEqpMNConnection.TcoMref");
	else if (ix == PNLBRLYSEGLIST_TCORET) return("PnlBrlySegList.TcoRet");
	else if (ix == PNLBRLYSEGLIST_TCOREU) return("PnlBrlySegList.TcoReu");
	else if (ix == PNLBRLYSEGLIST_TCOAL0) return("PnlBrlySegList.TcoAl0");
	else if (ix == PNLBRLYSEGLIST_TCOAL1) return("PnlBrlySegList.TcoAl1");
	else if (ix == PNLBRLYSEGLIST_TCOTH0) return("PnlBrlySegList.TcoTh0");
	else if (ix == PNLBRLYSEGLIST_TCOTH1) return("PnlBrlySegList.TcoTh1");
	else if (ix == PNLBRLYSEGLIST_TCOPH0) return("PnlBrlySegList.TcoPh0");
	else if (ix == PNLBRLYSEGLIST_TCOPH1) return("PnlBrlySegList.TcoPh1");
	else if (ix == PNLBRLYSEGLIST_TCOSTA) return("PnlBrlySegList.TcoSta");
	else if (ix == PNLBRLYSEGLIST_TCOSTO) return("PnlBrlySegList.TcoSto");
	else if (ix == PNLBRLYSEGMNCONNECTION_TCOMREF) return("PnlBrlySegMNConnection.TcoMref");
	else if (ix == PNLBRLYSEGMNCONNECTION_TCOSTA) return("PnlBrlySegMNConnection.TcoSta");
	else if (ix == PNLBRLYSEGMNCONNECTION_TCOSTO) return("PnlBrlySegMNConnection.TcoSto");
	else if (ix == PNLBRLYSEGMNCONNECTION_TCOLP0) return("PnlBrlySegMNConnection.TcoLp0");
	else if (ix == PNLBRLYSEGMNCONNECTION_TCOLP1) return("PnlBrlySegMNConnection.TcoLp1");
	else if (ix == PNLBRLYSEGMNLOCATION_TCOMREF) return("PnlBrlySegMNLocation.TcoMref");
	else if (ix == PNLBRLYSEGMNLOCATION_TCOSTA) return("PnlBrlySegMNLocation.TcoSta");
	else if (ix == PNLBRLYSEGMNLOCATION_TCOSTO) return("PnlBrlySegMNLocation.TcoSto");
	else if (ix == PNLBRLYSEGMNLOCATION_TCOSP0) return("PnlBrlySegMNLocation.TcoSp0");
	else if (ix == PNLBRLYSEGMNLOCATION_TCOSP1) return("PnlBrlySegMNLocation.TcoSp1");
	else if (ix == PNLBRLYSEGMNLOCATION_TCOSPH) return("PnlBrlySegMNLocation.TcoSph");
	else if (ix == PNLBRLYSEGMNLOCATION_TCOSTH) return("PnlBrlySegMNLocation.TcoSth");
	else if (ix == PNLBRLYSEGORGMNSEGMENT_TCOMREF) return("PnlBrlySegOrgMNSegment.TcoMref");
	else if (ix == PNLBRLYSEGORGMNSEGMENT_TCOSTA) return("PnlBrlySegOrgMNSegment.TcoSta");
	else if (ix == PNLBRLYSEGORGMNSEGMENT_TCOSTO) return("PnlBrlySegOrgMNSegment.TcoSto");
	else if (ix == PNLBRLYSEGORGMNSEGMENT_TCODP0) return("PnlBrlySegOrgMNSegment.TcoDp0");
	else if (ix == PNLBRLYSEGORGMNSEGMENT_TCODP1) return("PnlBrlySegOrgMNSegment.TcoDp1");
	else if (ix == PNLBRLYSEGORGMNSEGMENT_TCOOP0) return("PnlBrlySegOrgMNSegment.TcoOp0");
	else if (ix == PNLBRLYSEGORGMNSEGMENT_TCOOP1) return("PnlBrlySegOrgMNSegment.TcoOp1");
	else if (ix == PNLBRLYCONLIST_TCOFLT) return("PnlBrlyConList.TcoFlt");
	else if (ix == PNLBRLYCONLIST_TCOCOR) return("PnlBrlyConList.TcoCor");
	else if (ix == PNLBRLYCONLIST_TCOSTA) return("PnlBrlyConList.TcoSta");
	else if (ix == PNLBRLYCONLIST_TCOSTO) return("PnlBrlyConList.TcoSto");
	else if (ix == PNLBRLYCONLIST_TCOMOD) return("PnlBrlyConList.TcoMod");
	else if (ix == PNLBRLYCON1NRELAY_TCOREF) return("PnlBrlyCon1NRelay.TcoRef");
	else if (ix == PNLBRLYCONREF1NSEGMENT_TCOREF) return("PnlBrlyConRef1NSegment.TcoRef");
	else if (ix == PNLBRLYCONMNSEGMENT_TCOMREF) return("PnlBrlyConMNSegment.TcoMref");
	else if (ix == PNLBRLYCONMNSEGMENT_TCOSTA) return("PnlBrlyConMNSegment.TcoSta");
	else if (ix == PNLBRLYCONMNSEGMENT_TCOSTO) return("PnlBrlyConMNSegment.TcoSto");
	else if (ix == PNLBRLYCONMNSEGMENT_TCOLP0) return("PnlBrlyConMNSegment.TcoLp0");
	else if (ix == PNLBRLYCONMNSEGMENT_TCOLP1) return("PnlBrlyConMNSegment.TcoLp1");
	else if (ix == PNLBRLYCONMNFLIGHT_TCOMREF) return("PnlBrlyConMNFlight.TcoMref");
	else if (ix == PNLBRLYCONMNFLIGHT_TCOSTA) return("PnlBrlyConMNFlight.TcoSta");
	else if (ix == PNLBRLYCONMNFLIGHT_TCOSTO) return("PnlBrlyConMNFlight.TcoSto");
	else if (ix == PNLBRLYCONMNFLIGHT_TCOLP0) return("PnlBrlyConMNFlight.TcoLp0");
	else if (ix == PNLBRLYCONMNFLIGHT_TCOLP1) return("PnlBrlyConMNFlight.TcoLp1");
	else if (ix == PNLBRLYCONCONMNEQUIPMENT_TCOMREF) return("PnlBrlyConConMNEquipment.TcoMref");
	else if (ix == PNLBRLYRLYLIST_TCOSTA) return("PnlBrlyRlyList.TcoSta");
	else if (ix == PNLBRLYRLYLIST_TCOSTO) return("PnlBrlyRlyList.TcoSto");
	else if (ix == PNLBRLYRLYLIST_TCOCON) return("PnlBrlyRlyList.TcoCon");
	else if (ix == PNLBRLYRLYLIST_TCODIR) return("PnlBrlyRlyList.TcoDir");
	else if (ix == PNLBRLYRLYLIST_TCOCTD) return("PnlBrlyRlyList.TcoCtd");
	else if (ix == PNLBRLYRLY1NNODE_TCOREF) return("PnlBrlyRly1NNode.TcoRef");

	return("");
};

/******************************************************************************
 class DbsBrly::VecVKeylist
 ******************************************************************************/

uint DbsBrly::VecVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstbrlykalliance") return KLSTBRLYKALLIANCE;
	else if (s == "klstbrlykampersondetailtype") return KLSTBRLYKAMPERSONDETAILTYPE;
	else if (s == "klstbrlykeqptype") return KLSTBRLYKEQPTYPE;
	else if (s == "klstbrlykmfilecontent") return KLSTBRLYKMFILECONTENT;
	else if (s == "klstbrlykmfilemimetype") return KLSTBRLYKMFILEMIMETYPE;

	return(0);
};

string DbsBrly::VecVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTBRLYKALLIANCE) return("KlstBrlyKAlliance");
	else if (ix == KLSTBRLYKAMPERSONDETAILTYPE) return("KlstBrlyKAMPersonDetailType");
	else if (ix == KLSTBRLYKEQPTYPE) return("KlstBrlyKEqptype");
	else if (ix == KLSTBRLYKMFILECONTENT) return("KlstBrlyKMFileContent");
	else if (ix == KLSTBRLYKMFILEMIMETYPE) return("KlstBrlyKMFileMimetype");

	return("");
};

string DbsBrly::VecVKeylist::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == KLSTBRLYKALLIANCE) return("airline alliance");
		else if (ix == KLSTBRLYKAMPERSONDETAILTYPE) return("type");
		else if (ix == KLSTBRLYKEQPTYPE) return("equipment type");
		else if (ix == KLSTBRLYKMFILECONTENT) return("content");
		else if (ix == KLSTBRLYKMFILEMIMETYPE) return("MIME type");
	} else if (ixBrlyVLocale == 2) {
		if (ix == KLSTBRLYKALLIANCE) return("Luftfahrtallianz");
		else if (ix == KLSTBRLYKAMPERSONDETAILTYPE) return("Typ");
		else if (ix == KLSTBRLYKEQPTYPE) return("Ger\\u00e4tetyp");
		else if (ix == KLSTBRLYKMFILECONTENT) return("Inhalt");
		else if (ix == KLSTBRLYKMFILEMIMETYPE) return("MIME-Typ");
	};

	return("");
};

/******************************************************************************
 class DbsBrly::VecVLat
 ******************************************************************************/

uint DbsBrly::VecVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	else if (s == "ini") return INI;

	return(0);
};

string DbsBrly::VecVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	else if (ix == INI) return("ini");

	return("");
};

/******************************************************************************
 class DbsBrly::VecVLocale
 ******************************************************************************/

uint DbsBrly::VecVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;
	else if (s == "dech") return DECH;

	return(0);
};

string DbsBrly::VecVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");
	else if (ix == DECH) return("dech");

	return("");
};

string DbsBrly::VecVLocale::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		else if (ix == DECH) return("German (Switzerland)");
	} else if (ixBrlyVLocale == 2) {
		if (ix == ENUS) return("Englisch (Vereinigte Staaten)");
		else if (ix == DECH) return("Deutsch (Schweiz)");
	};

	return("");
};

void DbsBrly::VecVLocale::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=2;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVMaintable
 ******************************************************************************/

uint DbsBrly::VecVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "tblbrlymconnection") return TBLBRLYMCONNECTION;
	else if (s == "tblbrlymequipment") return TBLBRLYMEQUIPMENT;
	else if (s == "tblbrlymfaflight") return TBLBRLYMFAFLIGHT;
	else if (s == "tblbrlymfile") return TBLBRLYMFILE;
	else if (s == "tblbrlymflight") return TBLBRLYMFLIGHT;
	else if (s == "tblbrlymleg") return TBLBRLYMLEG;
	else if (s == "tblbrlymlocation") return TBLBRLYMLOCATION;
	else if (s == "tblbrlymnode") return TBLBRLYMNODE;
	else if (s == "tblbrlymoperator") return TBLBRLYMOPERATOR;
	else if (s == "tblbrlymperson") return TBLBRLYMPERSON;
	else if (s == "tblbrlymplntype") return TBLBRLYMPLNTYPE;
	else if (s == "tblbrlymregion") return TBLBRLYMREGION;
	else if (s == "tblbrlymrelay") return TBLBRLYMRELAY;
	else if (s == "tblbrlymsegment") return TBLBRLYMSEGMENT;
	else if (s == "tblbrlymsession") return TBLBRLYMSESSION;
	else if (s == "tblbrlymtimetable") return TBLBRLYMTIMETABLE;
	else if (s == "tblbrlymuser") return TBLBRLYMUSER;
	else if (s == "tblbrlymusergroup") return TBLBRLYMUSERGROUP;

	return(0);
};

string DbsBrly::VecVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == TBLBRLYMCONNECTION) return("TblBrlyMConnection");
	else if (ix == TBLBRLYMEQUIPMENT) return("TblBrlyMEquipment");
	else if (ix == TBLBRLYMFAFLIGHT) return("TblBrlyMFaflight");
	else if (ix == TBLBRLYMFILE) return("TblBrlyMFile");
	else if (ix == TBLBRLYMFLIGHT) return("TblBrlyMFlight");
	else if (ix == TBLBRLYMLEG) return("TblBrlyMLeg");
	else if (ix == TBLBRLYMLOCATION) return("TblBrlyMLocation");
	else if (ix == TBLBRLYMNODE) return("TblBrlyMNode");
	else if (ix == TBLBRLYMOPERATOR) return("TblBrlyMOperator");
	else if (ix == TBLBRLYMPERSON) return("TblBrlyMPerson");
	else if (ix == TBLBRLYMPLNTYPE) return("TblBrlyMPlntype");
	else if (ix == TBLBRLYMREGION) return("TblBrlyMRegion");
	else if (ix == TBLBRLYMRELAY) return("TblBrlyMRelay");
	else if (ix == TBLBRLYMSEGMENT) return("TblBrlyMSegment");
	else if (ix == TBLBRLYMSESSION) return("TblBrlyMSession");
	else if (ix == TBLBRLYMTIMETABLE) return("TblBrlyMTimetable");
	else if (ix == TBLBRLYMUSER) return("TblBrlyMUser");
	else if (ix == TBLBRLYMUSERGROUP) return("TblBrlyMUsergroup");

	return("");
};

string DbsBrly::VecVMaintable::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == TBLBRLYMCONNECTION) return("connection");
		else if (ix == TBLBRLYMEQUIPMENT) return("equipment");
		else if (ix == TBLBRLYMFAFLIGHT) return("FlightAware flight");
		else if (ix == TBLBRLYMFILE) return("file");
		else if (ix == TBLBRLYMFLIGHT) return("flight");
		else if (ix == TBLBRLYMLEG) return("leg");
		else if (ix == TBLBRLYMLOCATION) return("location");
		else if (ix == TBLBRLYMNODE) return("node");
		else if (ix == TBLBRLYMOPERATOR) return("operator");
		else if (ix == TBLBRLYMPERSON) return("person");
		else if (ix == TBLBRLYMPLNTYPE) return("plane type");
		else if (ix == TBLBRLYMREGION) return("region");
		else if (ix == TBLBRLYMRELAY) return("relay");
		else if (ix == TBLBRLYMSEGMENT) return("segment");
		else if (ix == TBLBRLYMSESSION) return("session");
		else if (ix == TBLBRLYMTIMETABLE) return("timetable");
		else if (ix == TBLBRLYMUSER) return("user");
		else if (ix == TBLBRLYMUSERGROUP) return("user group");
	} else if (ixBrlyVLocale == 2) {
		if (ix == VOID) return("kein");
		else if (ix == TBLBRLYMCONNECTION) return("Verbindung");
		else if (ix == TBLBRLYMEQUIPMENT) return("Ger\\u00e4t");
		else if (ix == TBLBRLYMFAFLIGHT) return("FlightAware Flug");
		else if (ix == TBLBRLYMFILE) return("Datei");
		else if (ix == TBLBRLYMFLIGHT) return("Flug");
		else if (ix == TBLBRLYMLEG) return("Strecke");
		else if (ix == TBLBRLYMLOCATION) return("Ort");
		else if (ix == TBLBRLYMNODE) return("Knotenpunkt");
		else if (ix == TBLBRLYMOPERATOR) return("Betreiber");
		else if (ix == TBLBRLYMPERSON) return("Person");
		else if (ix == TBLBRLYMPLNTYPE) return("Flugzeugtyp");
		else if (ix == TBLBRLYMREGION) return("Region");
		else if (ix == TBLBRLYMRELAY) return("Verbindungskette");
		else if (ix == TBLBRLYMSEGMENT) return("Segment");
		else if (ix == TBLBRLYMSESSION) return("Siztung");
		else if (ix == TBLBRLYMTIMETABLE) return("Flugplan");
		else if (ix == TBLBRLYMUSER) return("Benutzer");
		else if (ix == TBLBRLYMUSERGROUP) return("Benutzergruppe");
	};

	return("");
};

void DbsBrly::VecVMaintable::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=19;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVOolop
 ******************************************************************************/

uint DbsBrly::VecVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	else if (s == "inb") return INB;
	else if (s == "rmv") return RMV;
	else if (s == "swp") return SWP;
	else if (s == "toa") return TOA;
	else if (s == "tob") return TOB;

	return(0);
};

string DbsBrly::VecVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	else if (ix == INB) return("inb");
	else if (ix == RMV) return("rmv");
	else if (ix == SWP) return("swp");
	else if (ix == TOA) return("toa");
	else if (ix == TOB) return("tob");

	return("");
};

/******************************************************************************
 class DbsBrly::VecVPreset
 ******************************************************************************/

uint DbsBrly::VecVPreset::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "prebrlyadm") return PREBRLYADM;
	else if (s == "prebrlyconconmnequipment.opr.x1") return PREBRLYCONCONMNEQUIPMENT_OPR_X1;
	else if (s == "prebrlyconlist.cor") return PREBRLYCONLIST_COR;
	else if (s == "prebrlyconlist.flt") return PREBRLYCONLIST_FLT;
	else if (s == "prebrlyconlist.sta") return PREBRLYCONLIST_STA;
	else if (s == "prebrlyconmnflight.x1") return PREBRLYCONMNFLIGHT_X1;
	else if (s == "prebrlyconmnflight.x2") return PREBRLYCONMNFLIGHT_X2;
	else if (s == "prebrlyconmnsegment.x1") return PREBRLYCONMNSEGMENT_X1;
	else if (s == "prebrlyconmnsegment.x2") return PREBRLYCONMNSEGMENT_X2;
	else if (s == "prebrlyfillist.fnm") return PREBRLYFILLIST_FNM;
	else if (s == "prebrlyfillist.ret") return PREBRLYFILLIST_RET;
	else if (s == "prebrlyfillist.reu") return PREBRLYFILLIST_REU;
	else if (s == "prebrlyfltdstmnflight.x1") return PREBRLYFLTDSTMNFLIGHT_X1;
	else if (s == "prebrlyfltlist.eqp") return PREBRLYFLTLIST_EQP;
	else if (s == "prebrlyfltlist.leg") return PREBRLYFLTLIST_LEG;
	else if (s == "prebrlyfltlist.srf") return PREBRLYFLTLIST_SRF;
	else if (s == "prebrlyfltlist.sta") return PREBRLYFLTLIST_STA;
	else if (s == "prebrlyfltlist.sto") return PREBRLYFLTLIST_STO;
	else if (s == "prebrlyfltmnconnection.x1") return PREBRLYFLTMNCONNECTION_X1;
	else if (s == "prebrlyfltmnconnection.x2") return PREBRLYFLTMNCONNECTION_X2;
	else if (s == "prebrlyfltmnlocation.x1") return PREBRLYFLTMNLOCATION_X1;
	else if (s == "prebrlyfltorgmnflight.x1") return PREBRLYFLTORGMNFLIGHT_X1;
	else if (s == "prebrlygrp") return PREBRLYGRP;
	else if (s == "prebrlyip") return PREBRLYIP;
	else if (s == "prebrlyixacc") return PREBRLYIXACC;
	else if (s == "prebrlyixlcl") return PREBRLYIXLCL;
	else if (s == "prebrlyixord") return PREBRLYIXORD;
	else if (s == "prebrlyixpre") return PREBRLYIXPRE;
	else if (s == "prebrlyixuaccon") return PREBRLYIXUACCON;
	else if (s == "prebrlyixuacfil") return PREBRLYIXUACFIL;
	else if (s == "prebrlyixuacflt") return PREBRLYIXUACFLT;
	else if (s == "prebrlyixuacleg") return PREBRLYIXUACLEG;
	else if (s == "prebrlyixuacloc") return PREBRLYIXUACLOC;
	else if (s == "prebrlyixuacopr") return PREBRLYIXUACOPR;
	else if (s == "prebrlyixuacprs") return PREBRLYIXUACPRS;
	else if (s == "prebrlyixuacpty") return PREBRLYIXUACPTY;
	else if (s == "prebrlyixuacreg") return PREBRLYIXUACREG;
	else if (s == "prebrlyixuacrly") return PREBRLYIXUACRLY;
	else if (s == "prebrlyixuacseg") return PREBRLYIXUACSEG;
	else if (s == "prebrlyixuacttb") return PREBRLYIXUACTTB;
	else if (s == "prebrlyixuacusg") return PREBRLYIXUACUSG;
	else if (s == "prebrlyixuacusr") return PREBRLYIXUACUSR;
	else if (s == "prebrlyjrefnotify") return PREBRLYJREFNOTIFY;
	else if (s == "prebrlyjrefsess") return PREBRLYJREFSESS;
	else if (s == "prebrlylegdstmnleg.x1") return PREBRLYLEGDSTMNLEG_X1;
	else if (s == "prebrlyleglist.blo") return PREBRLYLEGLIST_BLO;
	else if (s == "prebrlyleglist.elo") return PREBRLYLEGLIST_ELO;
	else if (s == "prebrlyleglist.typ") return PREBRLYLEGLIST_TYP;
	else if (s == "prebrlylegmnlocation.x1") return PREBRLYLEGMNLOCATION_X1;
	else if (s == "prebrlylegorgmnleg.x1") return PREBRLYLEGORGMNLEG_X1;
	else if (s == "prebrlyloclist.eqp") return PREBRLYLOCLIST_EQP;
	else if (s == "prebrlyloclist.ica") return PREBRLYLOCLIST_ICA;
	else if (s == "prebrlyloclist.reg") return PREBRLYLOCLIST_REG;
	else if (s == "prebrlyloclist.srf") return PREBRLYLOCLIST_SRF;
	else if (s == "prebrlyloclist.tit") return PREBRLYLOCLIST_TIT;
	else if (s == "prebrlyloclist.typ") return PREBRLYLOCLIST_TYP;
	else if (s == "prebrlylocmnflight.x1") return PREBRLYLOCMNFLIGHT_X1;
	else if (s == "prebrlylocmnleg.x1") return PREBRLYLOCMNLEG_X1;
	else if (s == "prebrlylocmnsegment.x1") return PREBRLYLOCMNSEGMENT_X1;
	else if (s == "prebrlylocmnsegment.x2") return PREBRLYLOCMNSEGMENT_X2;
	else if (s == "prebrlyoprlist.ica") return PREBRLYOPRLIST_ICA;
	else if (s == "prebrlyoprlist.srf") return PREBRLYOPRLIST_SRF;
	else if (s == "prebrlyoprlist.tit") return PREBRLYOPRLIST_TIT;
	else if (s == "prebrlyown") return PREBRLYOWN;
	else if (s == "prebrlyphi") return PREBRLYPHI;
	else if (s == "prebrlyprsadetail.x1") return PREBRLYPRSADETAIL_X1;
	else if (s == "prebrlyprslist.grp") return PREBRLYPRSLIST_GRP;
	else if (s == "prebrlyprslist.lnm") return PREBRLYPRSLIST_LNM;
	else if (s == "prebrlyprslist.own") return PREBRLYPRSLIST_OWN;
	else if (s == "prebrlyptylist.srf") return PREBRLYPTYLIST_SRF;
	else if (s == "prebrlyptylist.tit") return PREBRLYPTYLIST_TIT;
	else if (s == "prebrlyrefapt") return PREBRLYREFAPT;
	else if (s == "prebrlyrefcon") return PREBRLYREFCON;
	else if (s == "prebrlyrefcor") return PREBRLYREFCOR;
	else if (s == "prebrlyrefeqp") return PREBRLYREFEQP;
	else if (s == "prebrlyreffaf") return PREBRLYREFFAF;
	else if (s == "prebrlyreffil") return PREBRLYREFFIL;
	else if (s == "prebrlyrefflt") return PREBRLYREFFLT;
	else if (s == "prebrlyrefleg") return PREBRLYREFLEG;
	else if (s == "prebrlyrefloc") return PREBRLYREFLOC;
	else if (s == "prebrlyrefnde") return PREBRLYREFNDE;
	else if (s == "prebrlyrefopr") return PREBRLYREFOPR;
	else if (s == "prebrlyrefpln") return PREBRLYREFPLN;
	else if (s == "prebrlyrefprs") return PREBRLYREFPRS;
	else if (s == "prebrlyrefpty") return PREBRLYREFPTY;
	else if (s == "prebrlyrefreg") return PREBRLYREFREG;
	else if (s == "prebrlyrefrip") return PREBRLYREFRIP;
	else if (s == "prebrlyrefrly") return PREBRLYREFRLY;
	else if (s == "prebrlyrefrte") return PREBRLYREFRTE;
	else if (s == "prebrlyrefseg") return PREBRLYREFSEG;
	else if (s == "prebrlyrefsel") return PREBRLYREFSEL;
	else if (s == "prebrlyrefses") return PREBRLYREFSES;
	else if (s == "prebrlyrefttb") return PREBRLYREFTTB;
	else if (s == "prebrlyrefusg") return PREBRLYREFUSG;
	else if (s == "prebrlyrefusr") return PREBRLYREFUSR;
	else if (s == "prebrlyreglist.srf") return PREBRLYREGLIST_SRF;
	else if (s == "prebrlyreglist.sup") return PREBRLYREGLIST_SUP;
	else if (s == "prebrlyreglist.tit") return PREBRLYREGLIST_TIT;
	else if (s == "prebrlyrlylist.con") return PREBRLYRLYLIST_CON;
	else if (s == "prebrlyrlylist.dir") return PREBRLYRLYLIST_DIR;
	else if (s == "prebrlyrlylist.sta") return PREBRLYRLYLIST_STA;
	else if (s == "prebrlyrlylist.sto") return PREBRLYRLYLIST_STO;
	else if (s == "prebrlysegdstmnsegment.x1") return PREBRLYSEGDSTMNSEGMENT_X1;
	else if (s == "prebrlysegdstmnsegment.x2") return PREBRLYSEGDSTMNSEGMENT_X2;
	else if (s == "prebrlyseglist.ret") return PREBRLYSEGLIST_RET;
	else if (s == "prebrlyseglist.reu") return PREBRLYSEGLIST_REU;
	else if (s == "prebrlyseglist.sta") return PREBRLYSEGLIST_STA;
	else if (s == "prebrlyseglist.sto") return PREBRLYSEGLIST_STO;
	else if (s == "prebrlysegmnconnection.x1") return PREBRLYSEGMNCONNECTION_X1;
	else if (s == "prebrlysegmnconnection.x2") return PREBRLYSEGMNCONNECTION_X2;
	else if (s == "prebrlysegmnlocation.x1") return PREBRLYSEGMNLOCATION_X1;
	else if (s == "prebrlysegmnlocation.x2") return PREBRLYSEGMNLOCATION_X2;
	else if (s == "prebrlysegorgmnsegment.x1") return PREBRLYSEGORGMNSEGMENT_X1;
	else if (s == "prebrlysegorgmnsegment.x2") return PREBRLYSEGORGMNSEGMENT_X2;
	else if (s == "prebrlysess") return PREBRLYSESS;
	else if (s == "prebrlysysdate") return PREBRLYSYSDATE;
	else if (s == "prebrlysysstamp") return PREBRLYSYSSTAMP;
	else if (s == "prebrlysystime") return PREBRLYSYSTIME;
	else if (s == "prebrlytime") return PREBRLYTIME;
	else if (s == "prebrlyttblist.fil") return PREBRLYTTBLIST_FIL;
	else if (s == "prebrlyttblist.tit") return PREBRLYTTBLIST_TIT;
	else if (s == "prebrlyusgaaccess.x1") return PREBRLYUSGAACCESS_X1;
	else if (s == "prebrlyusglist.srf") return PREBRLYUSGLIST_SRF;
	else if (s == "prebrlyusraaccess.x1") return PREBRLYUSRAACCESS_X1;
	else if (s == "prebrlyusrlist.prs") return PREBRLYUSRLIST_PRS;
	else if (s == "prebrlyusrlist.srf") return PREBRLYUSRLIST_SRF;
	else if (s == "prebrlyusrlist.ste") return PREBRLYUSRLIST_STE;
	else if (s == "prebrlyusrlist.usg") return PREBRLYUSRLIST_USG;

	return(0);
};

string DbsBrly::VecVPreset::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == PREBRLYADM) return("PreBrlyAdm");
	else if (ix == PREBRLYCONCONMNEQUIPMENT_OPR_X1) return("PreBrlyConConMNEquipment.opr.x1");
	else if (ix == PREBRLYCONLIST_COR) return("PreBrlyConList.cor");
	else if (ix == PREBRLYCONLIST_FLT) return("PreBrlyConList.flt");
	else if (ix == PREBRLYCONLIST_STA) return("PreBrlyConList.sta");
	else if (ix == PREBRLYCONMNFLIGHT_X1) return("PreBrlyConMNFlight.x1");
	else if (ix == PREBRLYCONMNFLIGHT_X2) return("PreBrlyConMNFlight.x2");
	else if (ix == PREBRLYCONMNSEGMENT_X1) return("PreBrlyConMNSegment.x1");
	else if (ix == PREBRLYCONMNSEGMENT_X2) return("PreBrlyConMNSegment.x2");
	else if (ix == PREBRLYFILLIST_FNM) return("PreBrlyFilList.fnm");
	else if (ix == PREBRLYFILLIST_RET) return("PreBrlyFilList.ret");
	else if (ix == PREBRLYFILLIST_REU) return("PreBrlyFilList.reu");
	else if (ix == PREBRLYFLTDSTMNFLIGHT_X1) return("PreBrlyFltDstMNFlight.x1");
	else if (ix == PREBRLYFLTLIST_EQP) return("PreBrlyFltList.eqp");
	else if (ix == PREBRLYFLTLIST_LEG) return("PreBrlyFltList.leg");
	else if (ix == PREBRLYFLTLIST_SRF) return("PreBrlyFltList.srf");
	else if (ix == PREBRLYFLTLIST_STA) return("PreBrlyFltList.sta");
	else if (ix == PREBRLYFLTLIST_STO) return("PreBrlyFltList.sto");
	else if (ix == PREBRLYFLTMNCONNECTION_X1) return("PreBrlyFltMNConnection.x1");
	else if (ix == PREBRLYFLTMNCONNECTION_X2) return("PreBrlyFltMNConnection.x2");
	else if (ix == PREBRLYFLTMNLOCATION_X1) return("PreBrlyFltMNLocation.x1");
	else if (ix == PREBRLYFLTORGMNFLIGHT_X1) return("PreBrlyFltOrgMNFlight.x1");
	else if (ix == PREBRLYGRP) return("PreBrlyGrp");
	else if (ix == PREBRLYIP) return("PreBrlyIp");
	else if (ix == PREBRLYIXACC) return("PreBrlyIxAcc");
	else if (ix == PREBRLYIXLCL) return("PreBrlyIxLcl");
	else if (ix == PREBRLYIXORD) return("PreBrlyIxOrd");
	else if (ix == PREBRLYIXPRE) return("PreBrlyIxPre");
	else if (ix == PREBRLYIXUACCON) return("PreBrlyIxUacCon");
	else if (ix == PREBRLYIXUACFIL) return("PreBrlyIxUacFil");
	else if (ix == PREBRLYIXUACFLT) return("PreBrlyIxUacFlt");
	else if (ix == PREBRLYIXUACLEG) return("PreBrlyIxUacLeg");
	else if (ix == PREBRLYIXUACLOC) return("PreBrlyIxUacLoc");
	else if (ix == PREBRLYIXUACOPR) return("PreBrlyIxUacOpr");
	else if (ix == PREBRLYIXUACPRS) return("PreBrlyIxUacPrs");
	else if (ix == PREBRLYIXUACPTY) return("PreBrlyIxUacPty");
	else if (ix == PREBRLYIXUACREG) return("PreBrlyIxUacReg");
	else if (ix == PREBRLYIXUACRLY) return("PreBrlyIxUacRly");
	else if (ix == PREBRLYIXUACSEG) return("PreBrlyIxUacSeg");
	else if (ix == PREBRLYIXUACTTB) return("PreBrlyIxUacTtb");
	else if (ix == PREBRLYIXUACUSG) return("PreBrlyIxUacUsg");
	else if (ix == PREBRLYIXUACUSR) return("PreBrlyIxUacUsr");
	else if (ix == PREBRLYJREFNOTIFY) return("PreBrlyJrefNotify");
	else if (ix == PREBRLYJREFSESS) return("PreBrlyJrefSess");
	else if (ix == PREBRLYLEGDSTMNLEG_X1) return("PreBrlyLegDstMNLeg.x1");
	else if (ix == PREBRLYLEGLIST_BLO) return("PreBrlyLegList.blo");
	else if (ix == PREBRLYLEGLIST_ELO) return("PreBrlyLegList.elo");
	else if (ix == PREBRLYLEGLIST_TYP) return("PreBrlyLegList.typ");
	else if (ix == PREBRLYLEGMNLOCATION_X1) return("PreBrlyLegMNLocation.x1");
	else if (ix == PREBRLYLEGORGMNLEG_X1) return("PreBrlyLegOrgMNLeg.x1");
	else if (ix == PREBRLYLOCLIST_EQP) return("PreBrlyLocList.eqp");
	else if (ix == PREBRLYLOCLIST_ICA) return("PreBrlyLocList.ica");
	else if (ix == PREBRLYLOCLIST_REG) return("PreBrlyLocList.reg");
	else if (ix == PREBRLYLOCLIST_SRF) return("PreBrlyLocList.srf");
	else if (ix == PREBRLYLOCLIST_TIT) return("PreBrlyLocList.tit");
	else if (ix == PREBRLYLOCLIST_TYP) return("PreBrlyLocList.typ");
	else if (ix == PREBRLYLOCMNFLIGHT_X1) return("PreBrlyLocMNFlight.x1");
	else if (ix == PREBRLYLOCMNLEG_X1) return("PreBrlyLocMNLeg.x1");
	else if (ix == PREBRLYLOCMNSEGMENT_X1) return("PreBrlyLocMNSegment.x1");
	else if (ix == PREBRLYLOCMNSEGMENT_X2) return("PreBrlyLocMNSegment.x2");
	else if (ix == PREBRLYOPRLIST_ICA) return("PreBrlyOprList.ica");
	else if (ix == PREBRLYOPRLIST_SRF) return("PreBrlyOprList.srf");
	else if (ix == PREBRLYOPRLIST_TIT) return("PreBrlyOprList.tit");
	else if (ix == PREBRLYOWN) return("PreBrlyOwn");
	else if (ix == PREBRLYPHI) return("PreBrlyPhi");
	else if (ix == PREBRLYPRSADETAIL_X1) return("PreBrlyPrsADetail.x1");
	else if (ix == PREBRLYPRSLIST_GRP) return("PreBrlyPrsList.grp");
	else if (ix == PREBRLYPRSLIST_LNM) return("PreBrlyPrsList.lnm");
	else if (ix == PREBRLYPRSLIST_OWN) return("PreBrlyPrsList.own");
	else if (ix == PREBRLYPTYLIST_SRF) return("PreBrlyPtyList.srf");
	else if (ix == PREBRLYPTYLIST_TIT) return("PreBrlyPtyList.tit");
	else if (ix == PREBRLYREFAPT) return("PreBrlyRefApt");
	else if (ix == PREBRLYREFCON) return("PreBrlyRefCon");
	else if (ix == PREBRLYREFCOR) return("PreBrlyRefCor");
	else if (ix == PREBRLYREFEQP) return("PreBrlyRefEqp");
	else if (ix == PREBRLYREFFAF) return("PreBrlyRefFaf");
	else if (ix == PREBRLYREFFIL) return("PreBrlyRefFil");
	else if (ix == PREBRLYREFFLT) return("PreBrlyRefFlt");
	else if (ix == PREBRLYREFLEG) return("PreBrlyRefLeg");
	else if (ix == PREBRLYREFLOC) return("PreBrlyRefLoc");
	else if (ix == PREBRLYREFNDE) return("PreBrlyRefNde");
	else if (ix == PREBRLYREFOPR) return("PreBrlyRefOpr");
	else if (ix == PREBRLYREFPLN) return("PreBrlyRefPln");
	else if (ix == PREBRLYREFPRS) return("PreBrlyRefPrs");
	else if (ix == PREBRLYREFPTY) return("PreBrlyRefPty");
	else if (ix == PREBRLYREFREG) return("PreBrlyRefReg");
	else if (ix == PREBRLYREFRIP) return("PreBrlyRefRip");
	else if (ix == PREBRLYREFRLY) return("PreBrlyRefRly");
	else if (ix == PREBRLYREFRTE) return("PreBrlyRefRte");
	else if (ix == PREBRLYREFSEG) return("PreBrlyRefSeg");
	else if (ix == PREBRLYREFSEL) return("PreBrlyRefSel");
	else if (ix == PREBRLYREFSES) return("PreBrlyRefSes");
	else if (ix == PREBRLYREFTTB) return("PreBrlyRefTtb");
	else if (ix == PREBRLYREFUSG) return("PreBrlyRefUsg");
	else if (ix == PREBRLYREFUSR) return("PreBrlyRefUsr");
	else if (ix == PREBRLYREGLIST_SRF) return("PreBrlyRegList.srf");
	else if (ix == PREBRLYREGLIST_SUP) return("PreBrlyRegList.sup");
	else if (ix == PREBRLYREGLIST_TIT) return("PreBrlyRegList.tit");
	else if (ix == PREBRLYRLYLIST_CON) return("PreBrlyRlyList.con");
	else if (ix == PREBRLYRLYLIST_DIR) return("PreBrlyRlyList.dir");
	else if (ix == PREBRLYRLYLIST_STA) return("PreBrlyRlyList.sta");
	else if (ix == PREBRLYRLYLIST_STO) return("PreBrlyRlyList.sto");
	else if (ix == PREBRLYSEGDSTMNSEGMENT_X1) return("PreBrlySegDstMNSegment.x1");
	else if (ix == PREBRLYSEGDSTMNSEGMENT_X2) return("PreBrlySegDstMNSegment.x2");
	else if (ix == PREBRLYSEGLIST_RET) return("PreBrlySegList.ret");
	else if (ix == PREBRLYSEGLIST_REU) return("PreBrlySegList.reu");
	else if (ix == PREBRLYSEGLIST_STA) return("PreBrlySegList.sta");
	else if (ix == PREBRLYSEGLIST_STO) return("PreBrlySegList.sto");
	else if (ix == PREBRLYSEGMNCONNECTION_X1) return("PreBrlySegMNConnection.x1");
	else if (ix == PREBRLYSEGMNCONNECTION_X2) return("PreBrlySegMNConnection.x2");
	else if (ix == PREBRLYSEGMNLOCATION_X1) return("PreBrlySegMNLocation.x1");
	else if (ix == PREBRLYSEGMNLOCATION_X2) return("PreBrlySegMNLocation.x2");
	else if (ix == PREBRLYSEGORGMNSEGMENT_X1) return("PreBrlySegOrgMNSegment.x1");
	else if (ix == PREBRLYSEGORGMNSEGMENT_X2) return("PreBrlySegOrgMNSegment.x2");
	else if (ix == PREBRLYSESS) return("PreBrlySess");
	else if (ix == PREBRLYSYSDATE) return("PreBrlySysdate");
	else if (ix == PREBRLYSYSSTAMP) return("PreBrlySysstamp");
	else if (ix == PREBRLYSYSTIME) return("PreBrlySystime");
	else if (ix == PREBRLYTIME) return("PreBrlyTime");
	else if (ix == PREBRLYTTBLIST_FIL) return("PreBrlyTtbList.fil");
	else if (ix == PREBRLYTTBLIST_TIT) return("PreBrlyTtbList.tit");
	else if (ix == PREBRLYUSGAACCESS_X1) return("PreBrlyUsgAAccess.x1");
	else if (ix == PREBRLYUSGLIST_SRF) return("PreBrlyUsgList.srf");
	else if (ix == PREBRLYUSRAACCESS_X1) return("PreBrlyUsrAAccess.x1");
	else if (ix == PREBRLYUSRLIST_PRS) return("PreBrlyUsrList.prs");
	else if (ix == PREBRLYUSRLIST_SRF) return("PreBrlyUsrList.srf");
	else if (ix == PREBRLYUSRLIST_STE) return("PreBrlyUsrList.ste");
	else if (ix == PREBRLYUSRLIST_USG) return("PreBrlyUsrList.usg");

	return("");
};

string DbsBrly::VecVPreset::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == PREBRLYPHI) return("angular position [\\u00b0]");
		else if (ix == PREBRLYREFAPT) return("airport");
		else if (ix == PREBRLYREFCON) return("connection");
		else if (ix == PREBRLYREFCOR) return("corridor");
		else if (ix == PREBRLYREFEQP) return("equipment");
		else if (ix == PREBRLYREFFAF) return("FlightAware flight");
		else if (ix == PREBRLYREFFIL) return("file");
		else if (ix == PREBRLYREFFLT) return("flight");
		else if (ix == PREBRLYREFLEG) return("leg");
		else if (ix == PREBRLYREFLOC) return("location");
		else if (ix == PREBRLYREFNDE) return("node");
		else if (ix == PREBRLYREFOPR) return("operator");
		else if (ix == PREBRLYREFPLN) return("plane");
		else if (ix == PREBRLYREFPRS) return("person");
		else if (ix == PREBRLYREFPTY) return("plane type");
		else if (ix == PREBRLYREFREG) return("region");
		else if (ix == PREBRLYREFRIP) return("impartible region");
		else if (ix == PREBRLYREFRLY) return("relay");
		else if (ix == PREBRLYREFRTE) return("route");
		else if (ix == PREBRLYREFSEG) return("segment");
		else if (ix == PREBRLYREFSES) return("session");
		else if (ix == PREBRLYREFTTB) return("timetable");
		else if (ix == PREBRLYREFUSG) return("user group");
		else if (ix == PREBRLYREFUSR) return("user");
		else if (ix == PREBRLYTIME) return("time");
		else return(getSref(ix));
	} else if (ixBrlyVLocale == 2) {
		if (ix == VOID) return("kein");
		else if (ix == PREBRLYPHI) return("Winkelposition [\\u00b0]");
		else if (ix == PREBRLYREFAPT) return("Flughafen");
		else if (ix == PREBRLYREFCON) return("Verbindung");
		else if (ix == PREBRLYREFCOR) return("Korridor");
		else if (ix == PREBRLYREFEQP) return("Ger\\u00e4t");
		else if (ix == PREBRLYREFFAF) return("FlightAware Flug");
		else if (ix == PREBRLYREFFIL) return("Datei");
		else if (ix == PREBRLYREFFLT) return("Flug");
		else if (ix == PREBRLYREFLEG) return("Strecke");
		else if (ix == PREBRLYREFLOC) return("Ort");
		else if (ix == PREBRLYREFNDE) return("Knotenpunkt");
		else if (ix == PREBRLYREFOPR) return("Betreiber");
		else if (ix == PREBRLYREFPLN) return("Flugzeug");
		else if (ix == PREBRLYREFPRS) return("Person");
		else if (ix == PREBRLYREFPTY) return("Flugzeugtyp");
		else if (ix == PREBRLYREFREG) return("Region");
		else if (ix == PREBRLYREFRIP) return("unteilbare Region");
		else if (ix == PREBRLYREFRLY) return("Verbindungskette");
		else if (ix == PREBRLYREFRTE) return("Route");
		else if (ix == PREBRLYREFSEG) return("Segment");
		else if (ix == PREBRLYREFSES) return("Siztung");
		else if (ix == PREBRLYREFTTB) return("Flugplan");
		else if (ix == PREBRLYREFUSG) return("Benutzergruppe");
		else if (ix == PREBRLYREFUSR) return("Benutzer");
		else if (ix == PREBRLYTIME) return("Zeit");
		else return(getTitle(ix, 1));
	};

	return("");
};

/******************************************************************************
 class DbsBrly::VecVUserlevel
 ******************************************************************************/

uint DbsBrly::VecVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	else if (s == "gadm") return GADM;
	else if (s == "reg") return REG;
	else if (s == "vtor") return VTOR;

	return(0);
};

string DbsBrly::VecVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	else if (ix == GADM) return("gadm");
	else if (ix == REG) return("reg");
	else if (ix == VTOR) return("vtor");

	return("");
};

string DbsBrly::VecVUserlevel::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == ADM) return("administrator");
		else if (ix == GADM) return("user group administrator");
		else if (ix == REG) return("regular user");
		else if (ix == VTOR) return("visitor");
	} else if (ixBrlyVLocale == 2) {
		if (ix == ADM) return("Administrator");
		else if (ix == GADM) return("Gruppenadministrator");
		else if (ix == REG) return("regul\\u00e4rer Benutzer");
		else if (ix == VTOR) return("Besucher");
	};

	return("");
};

void DbsBrly::VecVUserlevel::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=4;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixBrlyVLocale));
};

/******************************************************************************
 class DbsBrly::VecVValuelist
 ******************************************************************************/

uint DbsBrly::VecVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstbrlyumpersontitle") return VLSTBRLYUMPERSONTITLE;

	return(0);
};

string DbsBrly::VecVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTBRLYUMPERSONTITLE) return("VlstBrlyUMPersonTitle");

	return("");
};

string DbsBrly::VecVValuelist::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == VLSTBRLYUMPERSONTITLE) return("title");
	} else if (ixBrlyVLocale == 2) {
		if (ix == VLSTBRLYUMPERSONTITLE) return("Anrede");
	};

	return("");
};

/******************************************************************************
 class DbsBrly::VecWUiaccess
 ******************************************************************************/

uint DbsBrly::VecWUiaccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i=0;i<ss.size();i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void DbsBrly::VecWUiaccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i=1;i<(2*VIEW);i*=2) if (ix & i) ics.insert(i);
};

string DbsBrly::VecWUiaccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsBrly::VecWUiaccess::getTitle(
			const uint ix
			, const uint ixBrlyVLocale
		) {
	if (ixBrlyVLocale == 1) {
		if (ix == EDIT) return("edit");
		else if (ix == EXEC) return("execute");
		else if (ix == VIEW) return("view");
	} else if (ixBrlyVLocale == 2) {
		if (ix == EDIT) return("\\u00e4ndern");
		else if (ix == EXEC) return("ausf\\u00fchren");
		else if (ix == VIEW) return("anschauen");
	};

	return("");
};

void DbsBrly::VecWUiaccess::fillFeed(
			const uint ixBrlyVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=VIEW;i*=2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixBrlyVLocale));
};

