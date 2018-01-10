/**
  * \file DbsBrly.h
  * C++ wrapper for database DbsBrly (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef DBSBRLY_H
#define DBSBRLY_H

#define BRLY_VERSION "0.2.2"
#define BRLY_VERSION_MAJOR 0
#define BRLY_VERSION_MINOR 2
#define BRLY_VERSION_SUB 2

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include "BrlyAccRMUserUniversal.h"
#include "BrlyAMFaflightWaypoint.h"
#include "BrlyAMPersonDetail.h"
#include "BrlyAMRegionDstswitch.h"
#include "BrlyAMUserAccess.h"
#include "BrlyAMUsergroupAccess.h"
#include "BrlyAVControlPar.h"
#include "BrlyAVKeylistKey.h"
#include "BrlyAVValuelistVal.h"
#include "BrlyCFile.h"
#include "BrlyCLeg.h"
#include "BrlyHistRMUserUniversal.h"
#include "BrlyJAVKeylistKey.h"
#include "BrlyJMPersonLastname.h"
#include "BrlyJMRegion.h"
#include "BrlyJMRegionTitle.h"
#include "BrlyJMUserState.h"
#include "BrlyLRMConnectionMEquipment.h"
#include "BrlyMConnection.h"
#include "BrlyMEquipment.h"
#include "BrlyMFaflight.h"
#include "BrlyMFile.h"
#include "BrlyMFlight.h"
#include "BrlyMLeg.h"
#include "BrlyMLocation.h"
#include "BrlyMNode.h"
#include "BrlyMOperator.h"
#include "BrlyMPerson.h"
#include "BrlyMPlntype.h"
#include "BrlyMRegion.h"
#include "BrlyMRelay.h"
#include "BrlyMSegment.h"
#include "BrlyMSession.h"
#include "BrlyMTimetable.h"
#include "BrlyMUser.h"
#include "BrlyMUsergroup.h"
#include "BrlyORMConnectionMEquipment.h"
#include "BrlyProxRMLocationMLocation.h"
#include "BrlyRMConnectionMFlight.h"
#include "BrlyRMConnectionMSegment.h"
#include "BrlyRMFlightMFlight.h"
#include "BrlyRMFlightMLocation.h"
#include "BrlyRMLegMLeg.h"
#include "BrlyRMLegMLocation.h"
#include "BrlyRMLocationMSegment.h"
#include "BrlyRMSegmentMSegment.h"
#include "BrlyRMUsergroupUniversal.h"
#include "BrlyRMUserMUsergroup.h"
#include "BrlyVisRMLocationMLocation.h"

#include "BrlyQCon1NRelay.h"
#include "BrlyQConConMNEquipment.h"
#include "BrlyQConList.h"
#include "BrlyQConMapFlight.h"
#include "BrlyQConMapLeg.h"
#include "BrlyQConMapLocation.h"
#include "BrlyQConMapNode.h"
#include "BrlyQConMapRelay.h"
#include "BrlyQConMNFlight.h"
#include "BrlyQConMNSegment.h"
#include "BrlyQConRef1NSegment.h"
#include "BrlyQFilList.h"
#include "BrlyQFlt1NConnection.h"
#include "BrlyQFltEqp1NNode.h"
#include "BrlyQFltEqpMNConnection.h"
#include "BrlyQFltFafAWaypoint.h"
#include "BrlyQFltList.h"
#include "BrlyQFltMNConnection.h"
#include "BrlyQFltMNLocation.h"
#include "BrlyQFltOrgMNFlight.h"
#include "BrlyQFltRef1NSegment.h"
#include "BrlyQLeg1NFlight.h"
#include "BrlyQLegCor1NConnection.h"
#include "BrlyQLegList.h"
#include "BrlyQLegMapLeg.h"
#include "BrlyQLegMapLocation.h"
#include "BrlyQLegMNLocation.h"
#include "BrlyQLegOrgMNLeg.h"
#include "BrlyQLocBgn1NLeg.h"
#include "BrlyQLocEnd1NLeg.h"
#include "BrlyQLocEqp1NNode.h"
#include "BrlyQLocEqpMNConnection.h"
#include "BrlyQLocList.h"
#include "BrlyQLocMapLeg.h"
#include "BrlyQLocMapProxLocation.h"
#include "BrlyQLocMapVisLocation.h"
#include "BrlyQLocMNFlight.h"
#include "BrlyQLocMNLeg.h"
#include "BrlyQLocMNSegment.h"
#include "BrlyQLocProxOrgMNLocation.h"
#include "BrlyQLocVisOrgMNLocation.h"
#include "BrlyQOpr1NEquipment.h"
#include "BrlyQOprList.h"
#include "BrlyQPreselect.h"
#include "BrlyQPrsADetail.h"
#include "BrlyQPrsList.h"
#include "BrlyQPty1NEquipment.h"
#include "BrlyQPtyList.h"
#include "BrlyQReg1NLocation.h"
#include "BrlyQRegADstswitch.h"
#include "BrlyQRegList.h"
#include "BrlyQRegSup1NRegion.h"
#include "BrlyQRly1NNode.h"
#include "BrlyQRlyList.h"
#include "BrlyQSegList.h"
#include "BrlyQSegMNConnection.h"
#include "BrlyQSegMNLocation.h"
#include "BrlyQSegOrgMNSegment.h"
#include "BrlyQSelect.h"
#include "BrlyQTtb1NFlight.h"
#include "BrlyQTtbList.h"
#include "BrlyQTtbRef1NFile.h"
#include "BrlyQUsgAAccess.h"
#include "BrlyQUsgList.h"
#include "BrlyQUsgMNUser.h"
#include "BrlyQUsr1NSession.h"
#include "BrlyQUsrAAccess.h"
#include "BrlyQUsrList.h"
#include "BrlyQUsrMNUsergroup.h"

#define VecBrlyVAccess DbsBrly::VecVAccess
#define VecBrlyVCard DbsBrly::VecVCard
#define VecBrlyVControl DbsBrly::VecVControl
#define VecBrlyVKeylist DbsBrly::VecVKeylist
#define VecBrlyVLat DbsBrly::VecVLat
#define VecBrlyVLocale DbsBrly::VecVLocale
#define VecBrlyVMaintable DbsBrly::VecVMaintable
#define VecBrlyVOolop DbsBrly::VecVOolop
#define VecBrlyVPreset DbsBrly::VecVPreset
#define VecBrlyVUserlevel DbsBrly::VecVUserlevel
#define VecBrlyVValuelist DbsBrly::VecVValuelist
#define VecBrlyWUiaccess DbsBrly::VecWUiaccess

/**
  * DbsBrly
  */
class DbsBrly {

public:
	/**
		* VecVAccess (full: VecBrlyVAccess)
		*/
	class VecVAccess {

	public:
		static const uint FULL = 1;
		static const uint NONE = 2;
		static const uint VIEW = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVCard (full: VecBrlyVCard)
		*/
	class VecVCard {

	public:
		static const uint CRDBRLYNAV = 1;
		static const uint CRDBRLYUSG = 2;
		static const uint CRDBRLYUSR = 3;
		static const uint CRDBRLYPRS = 4;
		static const uint CRDBRLYFIL = 5;
		static const uint CRDBRLYOPR = 6;
		static const uint CRDBRLYPTY = 7;
		static const uint CRDBRLYREG = 8;
		static const uint CRDBRLYLOC = 9;
		static const uint CRDBRLYLEG = 10;
		static const uint CRDBRLYTTB = 11;
		static const uint CRDBRLYFLT = 12;
		static const uint CRDBRLYSEG = 13;
		static const uint CRDBRLYCON = 14;
		static const uint CRDBRLYRLY = 15;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVControl (full: VecBrlyVControl)
		*/
	class VecVControl {

	public:
		static const uint PNLBRLYUSGLIST_TCOSRF = 1;
		static const uint PNLBRLYUSGAACCESS_TCOCRD = 2;
		static const uint PNLBRLYUSGAACCESS_TCOUAC = 3;
		static const uint PNLBRLYUSGMNUSER_TCOMREF = 4;
		static const uint PNLBRLYUSGMNUSER_TCOULV = 5;
		static const uint PNLBRLYUSRLIST_TCOPRS = 6;
		static const uint PNLBRLYUSRLIST_TCOSRF = 7;
		static const uint PNLBRLYUSRLIST_TCOUSG = 8;
		static const uint PNLBRLYUSRLIST_TCOSTE = 9;
		static const uint PNLBRLYUSRLIST_TCOLCL = 10;
		static const uint PNLBRLYUSRLIST_TCOULV = 11;
		static const uint PNLBRLYUSRAACCESS_TCOCRD = 12;
		static const uint PNLBRLYUSRAACCESS_TCOUAC = 13;
		static const uint PNLBRLYUSR1NSESSION_TCOREF = 14;
		static const uint PNLBRLYUSRMNUSERGROUP_TCOMREF = 15;
		static const uint PNLBRLYUSRMNUSERGROUP_TCOULV = 16;
		static const uint PNLBRLYPRSLIST_TCOTIT = 17;
		static const uint PNLBRLYPRSLIST_TCOFNM = 18;
		static const uint PNLBRLYPRSLIST_TCOLNM = 19;
		static const uint PNLBRLYPRSLIST_TCOGRP = 20;
		static const uint PNLBRLYPRSLIST_TCOOWN = 21;
		static const uint PNLBRLYPRSLIST_TCOSEX = 22;
		static const uint PNLBRLYPRSLIST_TCOTEL = 23;
		static const uint PNLBRLYPRSLIST_TCOEML = 24;
		static const uint PNLBRLYPRSADETAIL_TCOTYP = 25;
		static const uint PNLBRLYPRSADETAIL_TCOVAL = 26;
		static const uint PNLBRLYFILLIST_TCOFNM = 27;
		static const uint PNLBRLYFILLIST_TCORET = 28;
		static const uint PNLBRLYFILLIST_TCOREU = 29;
		static const uint PNLBRLYFILLIST_TCOCNT = 30;
		static const uint PNLBRLYFILLIST_TCOMIM = 31;
		static const uint PNLBRLYFILLIST_TCOSIZ = 32;
		static const uint PNLBRLYOPRLIST_TCOSRF = 33;
		static const uint PNLBRLYOPRLIST_TCOICA = 34;
		static const uint PNLBRLYOPRLIST_TCOTIT = 35;
		static const uint PNLBRLYOPR1NEQUIPMENT_TCOREF = 36;
		static const uint PNLBRLYPTYLIST_TCOSRF = 37;
		static const uint PNLBRLYPTYLIST_TCOTIT = 38;
		static const uint PNLBRLYPTYLIST_TCOETY = 39;
		static const uint PNLBRLYPTYLIST_TCOCAP = 40;
		static const uint PNLBRLYPTY1NEQUIPMENT_TCOREF = 41;
		static const uint PNLBRLYREGLIST_TCOSRF = 42;
		static const uint PNLBRLYREGLIST_TCOTIT = 43;
		static const uint PNLBRLYREGLIST_TCOSUP = 44;
		static const uint PNLBRLYREGLIST_TCODST = 45;
		static const uint PNLBRLYREGLIST_TCOTOF = 46;
		static const uint PNLBRLYREGADSTSWITCH_TCOSTD = 47;
		static const uint PNLBRLYREGADSTSWITCH_TCOSTT = 48;
		static const uint PNLBRLYREG1NLOCATION_TCOREF = 49;
		static const uint PNLBRLYREGSUP1NREGION_TCOREF = 50;
		static const uint PNLBRLYLOCLIST_TCOSRF = 51;
		static const uint PNLBRLYLOCLIST_TCOICA = 52;
		static const uint PNLBRLYLOCLIST_TCOTIT = 53;
		static const uint PNLBRLYLOCLIST_TCOTYP = 54;
		static const uint PNLBRLYLOCLIST_TCOREG = 55;
		static const uint PNLBRLYLOCLIST_TCOEQP = 56;
		static const uint PNLBRLYLOCLIST_TCOALT = 57;
		static const uint PNLBRLYLOCLIST_TCOTHE = 58;
		static const uint PNLBRLYLOCLIST_TCOPHI = 59;
		static const uint PNLBRLYLOCBGN1NLEG_TCOREF = 60;
		static const uint PNLBRLYLOCEND1NLEG_TCOREF = 61;
		static const uint PNLBRLYLOCEQP1NNODE_TCOREF = 62;
		static const uint PNLBRLYLOCMNSEGMENT_TCOMREF = 63;
		static const uint PNLBRLYLOCMNSEGMENT_TCOSTA = 64;
		static const uint PNLBRLYLOCMNSEGMENT_TCOSTO = 65;
		static const uint PNLBRLYLOCMNSEGMENT_TCOSP0 = 66;
		static const uint PNLBRLYLOCMNSEGMENT_TCOSP1 = 67;
		static const uint PNLBRLYLOCMNSEGMENT_TCOSPH = 68;
		static const uint PNLBRLYLOCMNSEGMENT_TCOSTH = 69;
		static const uint PNLBRLYLOCPROXORGMNLOCATION_TCOMREF = 70;
		static const uint PNLBRLYLOCPROXORGMNLOCATION_TCODPH = 71;
		static const uint PNLBRLYLOCVISORGMNLOCATION_TCOMREF = 72;
		static const uint PNLBRLYLOCMNLEG_TCOMREF = 73;
		static const uint PNLBRLYLOCMNLEG_TCOLP0 = 74;
		static const uint PNLBRLYLOCMNLEG_TCOLP1 = 75;
		static const uint PNLBRLYLOCMNLEG_TCOLPH = 76;
		static const uint PNLBRLYLOCMNLEG_TCOLTH = 77;
		static const uint PNLBRLYLOCMNLEG_TCOXP0 = 78;
		static const uint PNLBRLYLOCMNLEG_TCOXP1 = 79;
		static const uint PNLBRLYLOCMNFLIGHT_TCOMREF = 80;
		static const uint PNLBRLYLOCMNFLIGHT_TCOSTA = 81;
		static const uint PNLBRLYLOCMNFLIGHT_TCOSTO = 82;
		static const uint PNLBRLYLOCMNFLIGHT_TCOXSA = 83;
		static const uint PNLBRLYLOCMNFLIGHT_TCOXSO = 84;
		static const uint PNLBRLYLOCEQPMNCONNECTION_TCOMREF = 85;
		static const uint PNLBRLYLEGLIST_TCOBLO = 86;
		static const uint PNLBRLYLEGLIST_TCOELO = 87;
		static const uint PNLBRLYLEGLIST_TCOTYP = 88;
		static const uint PNLBRLYLEGLIST_TCOALT = 89;
		static const uint PNLBRLYLEGCOR1NCONNECTION_TCOREF = 90;
		static const uint PNLBRLYLEG1NFLIGHT_TCOREF = 91;
		static const uint PNLBRLYLEGMNLOCATION_TCOMREF = 92;
		static const uint PNLBRLYLEGMNLOCATION_TCOLP0 = 93;
		static const uint PNLBRLYLEGMNLOCATION_TCOLP1 = 94;
		static const uint PNLBRLYLEGMNLOCATION_TCOLPH = 95;
		static const uint PNLBRLYLEGMNLOCATION_TCOLTH = 96;
		static const uint PNLBRLYLEGMNLOCATION_TCOXP0 = 97;
		static const uint PNLBRLYLEGMNLOCATION_TCOXP1 = 98;
		static const uint PNLBRLYLEGORGMNLEG_TCOMREF = 99;
		static const uint PNLBRLYLEGORGMNLEG_TCODP0 = 100;
		static const uint PNLBRLYLEGORGMNLEG_TCODP1 = 101;
		static const uint PNLBRLYLEGORGMNLEG_TCOOP0 = 102;
		static const uint PNLBRLYLEGORGMNLEG_TCOOP1 = 103;
		static const uint PNLBRLYLEGORGMNLEG_TCOXD0 = 104;
		static const uint PNLBRLYLEGORGMNLEG_TCOXD1 = 105;
		static const uint PNLBRLYLEGORGMNLEG_TCOXO0 = 106;
		static const uint PNLBRLYLEGORGMNLEG_TCOXO1 = 107;
		static const uint PNLBRLYTTBLIST_TCOTIT = 108;
		static const uint PNLBRLYTTBLIST_TCOFIL = 109;
		static const uint PNLBRLYTTBLIST_TCOALI = 110;
		static const uint PNLBRLYTTBLIST_TCOSTA = 111;
		static const uint PNLBRLYTTBLIST_TCOSTO = 112;
		static const uint PNLBRLYTTB1NFLIGHT_TCOREF = 113;
		static const uint PNLBRLYTTBREF1NFILE_TCOREF = 114;
		static const uint PNLBRLYFLTLIST_TCOSRF = 115;
		static const uint PNLBRLYFLTLIST_TCOEQP = 116;
		static const uint PNLBRLYFLTLIST_TCOLEG = 117;
		static const uint PNLBRLYFLTLIST_TCOSTA = 118;
		static const uint PNLBRLYFLTLIST_TCOSTO = 119;
		static const uint PNLBRLYFLTFAFAWAYPOINT_TCOTMS = 120;
		static const uint PNLBRLYFLTFAFAWAYPOINT_TCOLAT = 121;
		static const uint PNLBRLYFLTFAFAWAYPOINT_TCOLON = 122;
		static const uint PNLBRLYFLTFAFAWAYPOINT_TCOGSP = 123;
		static const uint PNLBRLYFLTFAFAWAYPOINT_TCOALT = 124;
		static const uint PNLBRLYFLTFAFAWAYPOINT_TCOAST = 125;
		static const uint PNLBRLYFLTFAFAWAYPOINT_TCOUTY = 126;
		static const uint PNLBRLYFLTFAFAWAYPOINT_TCOACH = 127;
		static const uint PNLBRLYFLT1NCONNECTION_TCOREF = 128;
		static const uint PNLBRLYFLTREF1NSEGMENT_TCOREF = 129;
		static const uint PNLBRLYFLTEQP1NNODE_TCOREF = 130;
		static const uint PNLBRLYFLTMNLOCATION_TCOMREF = 131;
		static const uint PNLBRLYFLTMNLOCATION_TCOSTA = 132;
		static const uint PNLBRLYFLTMNLOCATION_TCOSTO = 133;
		static const uint PNLBRLYFLTMNLOCATION_TCOXSA = 134;
		static const uint PNLBRLYFLTMNLOCATION_TCOXSO = 135;
		static const uint PNLBRLYFLTMNCONNECTION_TCOMREF = 136;
		static const uint PNLBRLYFLTMNCONNECTION_TCOSTA = 137;
		static const uint PNLBRLYFLTMNCONNECTION_TCOSTO = 138;
		static const uint PNLBRLYFLTMNCONNECTION_TCOLP0 = 139;
		static const uint PNLBRLYFLTMNCONNECTION_TCOLP1 = 140;
		static const uint PNLBRLYFLTORGMNFLIGHT_TCOMREF = 141;
		static const uint PNLBRLYFLTORGMNFLIGHT_TCOSTA = 142;
		static const uint PNLBRLYFLTORGMNFLIGHT_TCOSTO = 143;
		static const uint PNLBRLYFLTORGMNFLIGHT_TCOXSA = 144;
		static const uint PNLBRLYFLTORGMNFLIGHT_TCOXSO = 145;
		static const uint PNLBRLYFLTEQPMNCONNECTION_TCOMREF = 146;
		static const uint PNLBRLYSEGLIST_TCORET = 147;
		static const uint PNLBRLYSEGLIST_TCOREU = 148;
		static const uint PNLBRLYSEGLIST_TCOAL0 = 149;
		static const uint PNLBRLYSEGLIST_TCOAL1 = 150;
		static const uint PNLBRLYSEGLIST_TCOTH0 = 151;
		static const uint PNLBRLYSEGLIST_TCOTH1 = 152;
		static const uint PNLBRLYSEGLIST_TCOPH0 = 153;
		static const uint PNLBRLYSEGLIST_TCOPH1 = 154;
		static const uint PNLBRLYSEGLIST_TCOSTA = 155;
		static const uint PNLBRLYSEGLIST_TCOSTO = 156;
		static const uint PNLBRLYSEGMNCONNECTION_TCOMREF = 157;
		static const uint PNLBRLYSEGMNCONNECTION_TCOSTA = 158;
		static const uint PNLBRLYSEGMNCONNECTION_TCOSTO = 159;
		static const uint PNLBRLYSEGMNCONNECTION_TCOLP0 = 160;
		static const uint PNLBRLYSEGMNCONNECTION_TCOLP1 = 161;
		static const uint PNLBRLYSEGMNLOCATION_TCOMREF = 162;
		static const uint PNLBRLYSEGMNLOCATION_TCOSTA = 163;
		static const uint PNLBRLYSEGMNLOCATION_TCOSTO = 164;
		static const uint PNLBRLYSEGMNLOCATION_TCOSP0 = 165;
		static const uint PNLBRLYSEGMNLOCATION_TCOSP1 = 166;
		static const uint PNLBRLYSEGMNLOCATION_TCOSPH = 167;
		static const uint PNLBRLYSEGMNLOCATION_TCOSTH = 168;
		static const uint PNLBRLYSEGORGMNSEGMENT_TCOMREF = 169;
		static const uint PNLBRLYSEGORGMNSEGMENT_TCOSTA = 170;
		static const uint PNLBRLYSEGORGMNSEGMENT_TCOSTO = 171;
		static const uint PNLBRLYSEGORGMNSEGMENT_TCODP0 = 172;
		static const uint PNLBRLYSEGORGMNSEGMENT_TCODP1 = 173;
		static const uint PNLBRLYSEGORGMNSEGMENT_TCOOP0 = 174;
		static const uint PNLBRLYSEGORGMNSEGMENT_TCOOP1 = 175;
		static const uint PNLBRLYCONLIST_TCOFLT = 176;
		static const uint PNLBRLYCONLIST_TCOCOR = 177;
		static const uint PNLBRLYCONLIST_TCOSTA = 178;
		static const uint PNLBRLYCONLIST_TCOSTO = 179;
		static const uint PNLBRLYCONLIST_TCOMOD = 180;
		static const uint PNLBRLYCON1NRELAY_TCOREF = 181;
		static const uint PNLBRLYCONREF1NSEGMENT_TCOREF = 182;
		static const uint PNLBRLYCONMNSEGMENT_TCOMREF = 183;
		static const uint PNLBRLYCONMNSEGMENT_TCOSTA = 184;
		static const uint PNLBRLYCONMNSEGMENT_TCOSTO = 185;
		static const uint PNLBRLYCONMNSEGMENT_TCOLP0 = 186;
		static const uint PNLBRLYCONMNSEGMENT_TCOLP1 = 187;
		static const uint PNLBRLYCONMNFLIGHT_TCOMREF = 188;
		static const uint PNLBRLYCONMNFLIGHT_TCOSTA = 189;
		static const uint PNLBRLYCONMNFLIGHT_TCOSTO = 190;
		static const uint PNLBRLYCONMNFLIGHT_TCOLP0 = 191;
		static const uint PNLBRLYCONMNFLIGHT_TCOLP1 = 192;
		static const uint PNLBRLYCONCONMNEQUIPMENT_TCOMREF = 193;
		static const uint PNLBRLYRLYLIST_TCOSTA = 194;
		static const uint PNLBRLYRLYLIST_TCOSTO = 195;
		static const uint PNLBRLYRLYLIST_TCOCON = 196;
		static const uint PNLBRLYRLYLIST_TCODIR = 197;
		static const uint PNLBRLYRLYLIST_TCOCTD = 198;
		static const uint PNLBRLYRLY1NNODE_TCOREF = 199;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVKeylist (full: VecBrlyVKeylist)
		*/
	class VecVKeylist {

	public:
		static const uint KLSTBRLYKALLIANCE = 1;
		static const uint KLSTBRLYKAMPERSONDETAILTYPE = 2;
		static const uint KLSTBRLYKEQPTYPE = 3;
		static const uint KLSTBRLYKMFILECONTENT = 4;
		static const uint KLSTBRLYKMFILEMIMETYPE = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);
	};

	/**
		* VecVLat (full: VecBrlyVLat)
		*/
	class VecVLat {

	public:
		static const uint DLO = 1;
		static const uint INI = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVLocale (full: VecBrlyVLocale)
		*/
	class VecVLocale {

	public:
		static const uint ENUS = 1;
		static const uint DECH = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVMaintable (full: VecBrlyVMaintable)
		*/
	class VecVMaintable {

	public:
		static const uint VOID = 1;
		static const uint TBLBRLYMCONNECTION = 2;
		static const uint TBLBRLYMEQUIPMENT = 3;
		static const uint TBLBRLYMFAFLIGHT = 4;
		static const uint TBLBRLYMFILE = 5;
		static const uint TBLBRLYMFLIGHT = 6;
		static const uint TBLBRLYMLEG = 7;
		static const uint TBLBRLYMLOCATION = 8;
		static const uint TBLBRLYMNODE = 9;
		static const uint TBLBRLYMOPERATOR = 10;
		static const uint TBLBRLYMPERSON = 11;
		static const uint TBLBRLYMPLNTYPE = 12;
		static const uint TBLBRLYMREGION = 13;
		static const uint TBLBRLYMRELAY = 14;
		static const uint TBLBRLYMSEGMENT = 15;
		static const uint TBLBRLYMSESSION = 16;
		static const uint TBLBRLYMTIMETABLE = 17;
		static const uint TBLBRLYMUSER = 18;
		static const uint TBLBRLYMUSERGROUP = 19;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVOolop (full: VecBrlyVOolop)
		*/
	class VecVOolop {

	public:
		static const uint INA = 1;
		static const uint INB = 2;
		static const uint RMV = 3;
		static const uint SWP = 4;
		static const uint TOA = 5;
		static const uint TOB = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVPreset (full: VecBrlyVPreset)
		*/
	class VecVPreset {

	public:
		static const uint VOID = 1;
		static const uint PREBRLYADM = 2;
		static const uint PREBRLYCONCONMNEQUIPMENT_OPR_X1 = 3;
		static const uint PREBRLYCONLIST_COR = 4;
		static const uint PREBRLYCONLIST_FLT = 5;
		static const uint PREBRLYCONLIST_STA = 6;
		static const uint PREBRLYCONMNFLIGHT_X1 = 7;
		static const uint PREBRLYCONMNFLIGHT_X2 = 8;
		static const uint PREBRLYCONMNSEGMENT_X1 = 9;
		static const uint PREBRLYCONMNSEGMENT_X2 = 10;
		static const uint PREBRLYFILLIST_FNM = 11;
		static const uint PREBRLYFILLIST_RET = 12;
		static const uint PREBRLYFILLIST_REU = 13;
		static const uint PREBRLYFLTDSTMNFLIGHT_X1 = 14;
		static const uint PREBRLYFLTLIST_EQP = 15;
		static const uint PREBRLYFLTLIST_LEG = 16;
		static const uint PREBRLYFLTLIST_SRF = 17;
		static const uint PREBRLYFLTLIST_STA = 18;
		static const uint PREBRLYFLTLIST_STO = 19;
		static const uint PREBRLYFLTMNCONNECTION_X1 = 20;
		static const uint PREBRLYFLTMNCONNECTION_X2 = 21;
		static const uint PREBRLYFLTMNLOCATION_X1 = 22;
		static const uint PREBRLYFLTORGMNFLIGHT_X1 = 23;
		static const uint PREBRLYGRP = 24;
		static const uint PREBRLYIP = 25;
		static const uint PREBRLYIXACC = 26;
		static const uint PREBRLYIXLCL = 27;
		static const uint PREBRLYIXORD = 28;
		static const uint PREBRLYIXPRE = 29;
		static const uint PREBRLYIXUACCON = 30;
		static const uint PREBRLYIXUACFIL = 31;
		static const uint PREBRLYIXUACFLT = 32;
		static const uint PREBRLYIXUACLEG = 33;
		static const uint PREBRLYIXUACLOC = 34;
		static const uint PREBRLYIXUACOPR = 35;
		static const uint PREBRLYIXUACPRS = 36;
		static const uint PREBRLYIXUACPTY = 37;
		static const uint PREBRLYIXUACREG = 38;
		static const uint PREBRLYIXUACRLY = 39;
		static const uint PREBRLYIXUACSEG = 40;
		static const uint PREBRLYIXUACTTB = 41;
		static const uint PREBRLYIXUACUSG = 42;
		static const uint PREBRLYIXUACUSR = 43;
		static const uint PREBRLYJREFNOTIFY = 44;
		static const uint PREBRLYJREFSESS = 45;
		static const uint PREBRLYLEGDSTMNLEG_X1 = 46;
		static const uint PREBRLYLEGLIST_BLO = 47;
		static const uint PREBRLYLEGLIST_ELO = 48;
		static const uint PREBRLYLEGLIST_TYP = 49;
		static const uint PREBRLYLEGMNLOCATION_X1 = 50;
		static const uint PREBRLYLEGORGMNLEG_X1 = 51;
		static const uint PREBRLYLOCLIST_EQP = 52;
		static const uint PREBRLYLOCLIST_ICA = 53;
		static const uint PREBRLYLOCLIST_REG = 54;
		static const uint PREBRLYLOCLIST_SRF = 55;
		static const uint PREBRLYLOCLIST_TIT = 56;
		static const uint PREBRLYLOCLIST_TYP = 57;
		static const uint PREBRLYLOCMNFLIGHT_X1 = 58;
		static const uint PREBRLYLOCMNLEG_X1 = 59;
		static const uint PREBRLYLOCMNSEGMENT_X1 = 60;
		static const uint PREBRLYLOCMNSEGMENT_X2 = 61;
		static const uint PREBRLYOPRLIST_ICA = 62;
		static const uint PREBRLYOPRLIST_SRF = 63;
		static const uint PREBRLYOPRLIST_TIT = 64;
		static const uint PREBRLYOWN = 65;
		static const uint PREBRLYPHI = 66;
		static const uint PREBRLYPRSADETAIL_X1 = 67;
		static const uint PREBRLYPRSLIST_GRP = 68;
		static const uint PREBRLYPRSLIST_LNM = 69;
		static const uint PREBRLYPRSLIST_OWN = 70;
		static const uint PREBRLYPTYLIST_SRF = 71;
		static const uint PREBRLYPTYLIST_TIT = 72;
		static const uint PREBRLYREFAPT = 73;
		static const uint PREBRLYREFCON = 74;
		static const uint PREBRLYREFCOR = 75;
		static const uint PREBRLYREFEQP = 76;
		static const uint PREBRLYREFFAF = 77;
		static const uint PREBRLYREFFIL = 78;
		static const uint PREBRLYREFFLT = 79;
		static const uint PREBRLYREFLEG = 80;
		static const uint PREBRLYREFLOC = 81;
		static const uint PREBRLYREFNDE = 82;
		static const uint PREBRLYREFOPR = 83;
		static const uint PREBRLYREFPLN = 84;
		static const uint PREBRLYREFPRS = 85;
		static const uint PREBRLYREFPTY = 86;
		static const uint PREBRLYREFREG = 87;
		static const uint PREBRLYREFRIP = 88;
		static const uint PREBRLYREFRLY = 89;
		static const uint PREBRLYREFRTE = 90;
		static const uint PREBRLYREFSEG = 91;
		static const uint PREBRLYREFSEL = 92;
		static const uint PREBRLYREFSES = 93;
		static const uint PREBRLYREFTTB = 94;
		static const uint PREBRLYREFUSG = 95;
		static const uint PREBRLYREFUSR = 96;
		static const uint PREBRLYREGLIST_SRF = 97;
		static const uint PREBRLYREGLIST_SUP = 98;
		static const uint PREBRLYREGLIST_TIT = 99;
		static const uint PREBRLYRLYLIST_CON = 100;
		static const uint PREBRLYRLYLIST_DIR = 101;
		static const uint PREBRLYRLYLIST_STA = 102;
		static const uint PREBRLYRLYLIST_STO = 103;
		static const uint PREBRLYSEGDSTMNSEGMENT_X1 = 104;
		static const uint PREBRLYSEGDSTMNSEGMENT_X2 = 105;
		static const uint PREBRLYSEGLIST_RET = 106;
		static const uint PREBRLYSEGLIST_REU = 107;
		static const uint PREBRLYSEGLIST_STA = 108;
		static const uint PREBRLYSEGLIST_STO = 109;
		static const uint PREBRLYSEGMNCONNECTION_X1 = 110;
		static const uint PREBRLYSEGMNCONNECTION_X2 = 111;
		static const uint PREBRLYSEGMNLOCATION_X1 = 112;
		static const uint PREBRLYSEGMNLOCATION_X2 = 113;
		static const uint PREBRLYSEGORGMNSEGMENT_X1 = 114;
		static const uint PREBRLYSEGORGMNSEGMENT_X2 = 115;
		static const uint PREBRLYSESS = 116;
		static const uint PREBRLYSYSDATE = 117;
		static const uint PREBRLYSYSSTAMP = 118;
		static const uint PREBRLYSYSTIME = 119;
		static const uint PREBRLYTIME = 120;
		static const uint PREBRLYTTBLIST_FIL = 121;
		static const uint PREBRLYTTBLIST_TIT = 122;
		static const uint PREBRLYUSGAACCESS_X1 = 123;
		static const uint PREBRLYUSGLIST_SRF = 124;
		static const uint PREBRLYUSRAACCESS_X1 = 125;
		static const uint PREBRLYUSRLIST_PRS = 126;
		static const uint PREBRLYUSRLIST_SRF = 127;
		static const uint PREBRLYUSRLIST_STE = 128;
		static const uint PREBRLYUSRLIST_USG = 129;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);
	};

	/**
		* VecVUserlevel (full: VecBrlyVUserlevel)
		*/
	class VecVUserlevel {

	public:
		static const uint ADM = 1;
		static const uint GADM = 2;
		static const uint REG = 3;
		static const uint VTOR = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecVValuelist (full: VecBrlyVValuelist)
		*/
	class VecVValuelist {

	public:
		static const uint VLSTBRLYUMPERSONTITLE = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);
	};

	/**
		* VecWUiaccess (full: VecBrlyWUiaccess)
		*/
	class VecWUiaccess {

	public:
		static const uint EDIT = 1;
		static const uint EXEC = 2;
		static const uint VIEW = 4;

		static uint getIx(const string& srefs);
		static void getIcs(const uint ix, set<uint>& ics);
		static string getSrefs(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

public:
	DbsBrly();
	~DbsBrly();

	void init(const uint _ixDbsVDbstype, const string& _dbspath, const string& _dbsname, const string& _ip, const uint _port, const string& _username, const string& _password);
	void term();

	void initMy();
	void termMy();
	void initPg();
	void termPg();

public:
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string username;
	string password;
	string ip;
	int port;

	bool initdone;

	MYSQL* dbsMy;
	PGconn* dbsPg;

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

	void beginMy();
	bool commitMy();
	void rollbackMy();
	void beginPg();
	bool commitPg();
	void rollbackPg();

	bool loadUintBySQL(const string& sqlstr, uint& val);		//!< execute a SQL query returning a single uint (arbitrary tables)
	bool loadStringBySQL(const string& sqlstr, string& val);//!< execute a SQL query returning a single string (arbitrary tables)

	bool loadRefBySQL(const string& sqlstr, ubigint& ref);	//!< execute a SQL query returning a single reference (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	ubigint loadRefsBySQL(const string& sqlstr, const bool append, vector<ubigint>& refs);

	bool loadUintBySQLMy(const string& sqlstr, uint& val);
	bool loadStringBySQLMy(const string& sqlstr, string& val);

	bool loadRefBySQLMy(const string& sqlstr, ubigint& ref);
	ubigint loadRefsBySQLMy(const string& sqlstr, const bool append, vector<ubigint>& refs);

	bool loadUintBySQLPg(const string& sqlstr, uint& val);
	bool loadStringBySQLPg(const string& sqlstr, string& val);

	bool loadRefBySQLPg(const string& sqlstr, ubigint& ref);
	ubigint loadRefsBySQLPg(const string& sqlstr, const bool append, vector<ubigint>& refs);

	void executeQuery(const string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const string& sqlstrmy, const string& sqlstrpg);
	void executeFile(const string& fullpath);								//!< SQL file batch execution

public:
	uint getIxWSubsetByRefBrlyMEquipment(const ubigint ref);
	uint getIxWSubsetByBrlyMEquipment(BrlyMEquipment* rec);

	uint getIxWSubsetByRefBrlyMLeg(const ubigint ref);
	uint getIxWSubsetByBrlyMLeg(BrlyMLeg* rec);

	uint getIxWSubsetByRefBrlyMLocation(const ubigint ref);
	uint getIxWSubsetByBrlyMLocation(BrlyMLocation* rec);

	uint getIxWSubsetByRefBrlyMRegion(const ubigint ref);
	uint getIxWSubsetByBrlyMRegion(BrlyMRegion* rec);

	void fillFeedFromKlst(const uint klsIxBrlyVKeylist, const uint ixBrlyVLocale, Feed& feed);
	void fillFeedFromKlstByMtbUref(const uint klsIxBrlyVKeylist, const uint x1IxBrlyVMaintable, const ubigint x1Uref, const uint ixBrlyVLocale, Feed& feed);

	string getKlstTitleBySref(const uint klsIxBrlyVKeylist, const string& sref, const uint ixBrlyVLocale = 0);
	string getKlstTitleByMtbUrefSref(const uint klsIxBrlyVKeylist, const uint x1IxBrlyVMaintable, const ubigint x1Uref, const string& sref, const uint ixBrlyVLocale = 0);

	void fillFeedFromVlst(const uint vlsIxBrlyVValuelist, const uint x1IxBrlyVLocale, Feed& feed);

public:
	TblBrlyAccRMUserUniversal* tblbrlyaccrmuseruniversal;
	TblBrlyAMFaflightWaypoint* tblbrlyamfaflightwaypoint;
	TblBrlyAMPersonDetail* tblbrlyampersondetail;
	TblBrlyAMRegionDstswitch* tblbrlyamregiondstswitch;
	TblBrlyAMUserAccess* tblbrlyamuseraccess;
	TblBrlyAMUsergroupAccess* tblbrlyamusergroupaccess;
	TblBrlyAVControlPar* tblbrlyavcontrolpar;
	TblBrlyAVKeylistKey* tblbrlyavkeylistkey;
	TblBrlyAVValuelistVal* tblbrlyavvaluelistval;
	TblBrlyCFile* tblbrlycfile;
	TblBrlyCLeg* tblbrlycleg;
	TblBrlyHistRMUserUniversal* tblbrlyhistrmuseruniversal;
	TblBrlyJAVKeylistKey* tblbrlyjavkeylistkey;
	TblBrlyJMPersonLastname* tblbrlyjmpersonlastname;
	TblBrlyJMRegion* tblbrlyjmregion;
	TblBrlyJMRegionTitle* tblbrlyjmregiontitle;
	TblBrlyJMUserState* tblbrlyjmuserstate;
	TblBrlyLRMConnectionMEquipment* tblbrlylrmconnectionmequipment;
	TblBrlyMConnection* tblbrlymconnection;
	TblBrlyMEquipment* tblbrlymequipment;
	TblBrlyMFaflight* tblbrlymfaflight;
	TblBrlyMFile* tblbrlymfile;
	TblBrlyMFlight* tblbrlymflight;
	TblBrlyMLeg* tblbrlymleg;
	TblBrlyMLocation* tblbrlymlocation;
	TblBrlyMNode* tblbrlymnode;
	TblBrlyMOperator* tblbrlymoperator;
	TblBrlyMPerson* tblbrlymperson;
	TblBrlyMPlntype* tblbrlymplntype;
	TblBrlyMRegion* tblbrlymregion;
	TblBrlyMRelay* tblbrlymrelay;
	TblBrlyMSegment* tblbrlymsegment;
	TblBrlyMSession* tblbrlymsession;
	TblBrlyMTimetable* tblbrlymtimetable;
	TblBrlyMUser* tblbrlymuser;
	TblBrlyMUsergroup* tblbrlymusergroup;
	TblBrlyORMConnectionMEquipment* tblbrlyormconnectionmequipment;
	TblBrlyProxRMLocationMLocation* tblbrlyproxrmlocationmlocation;
	TblBrlyRMConnectionMFlight* tblbrlyrmconnectionmflight;
	TblBrlyRMConnectionMSegment* tblbrlyrmconnectionmsegment;
	TblBrlyRMFlightMFlight* tblbrlyrmflightmflight;
	TblBrlyRMFlightMLocation* tblbrlyrmflightmlocation;
	TblBrlyRMLegMLeg* tblbrlyrmlegmleg;
	TblBrlyRMLegMLocation* tblbrlyrmlegmlocation;
	TblBrlyRMLocationMSegment* tblbrlyrmlocationmsegment;
	TblBrlyRMSegmentMSegment* tblbrlyrmsegmentmsegment;
	TblBrlyRMUsergroupUniversal* tblbrlyrmusergroupuniversal;
	TblBrlyRMUserMUsergroup* tblbrlyrmusermusergroup;
	TblBrlyVisRMLocationMLocation* tblbrlyvisrmlocationmlocation;

	TblBrlyQCon1NRelay* tblbrlyqcon1nrelay;
	TblBrlyQConConMNEquipment* tblbrlyqconconmnequipment;
	TblBrlyQConList* tblbrlyqconlist;
	TblBrlyQConMapFlight* tblbrlyqconmapflight;
	TblBrlyQConMapLeg* tblbrlyqconmapleg;
	TblBrlyQConMapLocation* tblbrlyqconmaplocation;
	TblBrlyQConMapNode* tblbrlyqconmapnode;
	TblBrlyQConMapRelay* tblbrlyqconmaprelay;
	TblBrlyQConMNFlight* tblbrlyqconmnflight;
	TblBrlyQConMNSegment* tblbrlyqconmnsegment;
	TblBrlyQConRef1NSegment* tblbrlyqconref1nsegment;
	TblBrlyQFilList* tblbrlyqfillist;
	TblBrlyQFlt1NConnection* tblbrlyqflt1nconnection;
	TblBrlyQFltEqp1NNode* tblbrlyqflteqp1nnode;
	TblBrlyQFltEqpMNConnection* tblbrlyqflteqpmnconnection;
	TblBrlyQFltFafAWaypoint* tblbrlyqfltfafawaypoint;
	TblBrlyQFltList* tblbrlyqfltlist;
	TblBrlyQFltMNConnection* tblbrlyqfltmnconnection;
	TblBrlyQFltMNLocation* tblbrlyqfltmnlocation;
	TblBrlyQFltOrgMNFlight* tblbrlyqfltorgmnflight;
	TblBrlyQFltRef1NSegment* tblbrlyqfltref1nsegment;
	TblBrlyQLeg1NFlight* tblbrlyqleg1nflight;
	TblBrlyQLegCor1NConnection* tblbrlyqlegcor1nconnection;
	TblBrlyQLegList* tblbrlyqleglist;
	TblBrlyQLegMapLeg* tblbrlyqlegmapleg;
	TblBrlyQLegMapLocation* tblbrlyqlegmaplocation;
	TblBrlyQLegMNLocation* tblbrlyqlegmnlocation;
	TblBrlyQLegOrgMNLeg* tblbrlyqlegorgmnleg;
	TblBrlyQLocBgn1NLeg* tblbrlyqlocbgn1nleg;
	TblBrlyQLocEnd1NLeg* tblbrlyqlocend1nleg;
	TblBrlyQLocEqp1NNode* tblbrlyqloceqp1nnode;
	TblBrlyQLocEqpMNConnection* tblbrlyqloceqpmnconnection;
	TblBrlyQLocList* tblbrlyqloclist;
	TblBrlyQLocMapLeg* tblbrlyqlocmapleg;
	TblBrlyQLocMapProxLocation* tblbrlyqlocmapproxlocation;
	TblBrlyQLocMapVisLocation* tblbrlyqlocmapvislocation;
	TblBrlyQLocMNFlight* tblbrlyqlocmnflight;
	TblBrlyQLocMNLeg* tblbrlyqlocmnleg;
	TblBrlyQLocMNSegment* tblbrlyqlocmnsegment;
	TblBrlyQLocProxOrgMNLocation* tblbrlyqlocproxorgmnlocation;
	TblBrlyQLocVisOrgMNLocation* tblbrlyqlocvisorgmnlocation;
	TblBrlyQOpr1NEquipment* tblbrlyqopr1nequipment;
	TblBrlyQOprList* tblbrlyqoprlist;
	TblBrlyQPreselect* tblbrlyqpreselect;
	TblBrlyQPrsADetail* tblbrlyqprsadetail;
	TblBrlyQPrsList* tblbrlyqprslist;
	TblBrlyQPty1NEquipment* tblbrlyqpty1nequipment;
	TblBrlyQPtyList* tblbrlyqptylist;
	TblBrlyQReg1NLocation* tblbrlyqreg1nlocation;
	TblBrlyQRegADstswitch* tblbrlyqregadstswitch;
	TblBrlyQRegList* tblbrlyqreglist;
	TblBrlyQRegSup1NRegion* tblbrlyqregsup1nregion;
	TblBrlyQRly1NNode* tblbrlyqrly1nnode;
	TblBrlyQRlyList* tblbrlyqrlylist;
	TblBrlyQSegList* tblbrlyqseglist;
	TblBrlyQSegMNConnection* tblbrlyqsegmnconnection;
	TblBrlyQSegMNLocation* tblbrlyqsegmnlocation;
	TblBrlyQSegOrgMNSegment* tblbrlyqsegorgmnsegment;
	TblBrlyQSelect* tblbrlyqselect;
	TblBrlyQTtb1NFlight* tblbrlyqttb1nflight;
	TblBrlyQTtbList* tblbrlyqttblist;
	TblBrlyQTtbRef1NFile* tblbrlyqttbref1nfile;
	TblBrlyQUsgAAccess* tblbrlyqusgaaccess;
	TblBrlyQUsgList* tblbrlyqusglist;
	TblBrlyQUsgMNUser* tblbrlyqusgmnuser;
	TblBrlyQUsr1NSession* tblbrlyqusr1nsession;
	TblBrlyQUsrAAccess* tblbrlyqusraaccess;
	TblBrlyQUsrList* tblbrlyqusrlist;
	TblBrlyQUsrMNUsergroup* tblbrlyqusrmnusergroup;
};
#endif

