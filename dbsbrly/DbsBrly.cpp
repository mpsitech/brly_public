/**
  * \file DbsBrly.cpp
  * C++ wrapper for database DbsBrly (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "DbsBrly.h"

#include "DbsBrly_vecs.cpp"

/******************************************************************************
 class DbsBrly
 ******************************************************************************/

DbsBrly::DbsBrly() {
	initdone = false;

	dbsMy = NULL;
	dbsPg = NULL;
};

DbsBrly::~DbsBrly() {
	term();
};

void DbsBrly::init(
			const uint _ixDbsVDbstype
			, const string& _dbspath
			, const string& _dbsname
			, const string& _ip
			, const uint _port
			, const string& _username
			, const string& _password
		) {
	ixDbsVDbstype = _ixDbsVDbstype;
	dbspath = _dbspath;
	dbsname = _dbsname;
	username = _username;
	password = _password;
	ip = _ip;
	port = _port;

	if (ixDbsVDbstype == VecDbsVDbstype::MY) initMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) initPg();

	initdone = true;
};

void DbsBrly::term() {
	if (initdone) {
		if (ixDbsVDbstype == VecDbsVDbstype::MY) termMy();
		else if (ixDbsVDbstype == VecDbsVDbstype::PG) termPg();

		initdone = false;
	};
};

void DbsBrly::initMy() {
	// connect to MySQL database
	dbsMy = mysql_init(NULL);

	mysql_options(dbsMy, MYSQL_READ_DEFAULT_GROUP, "MyccDatabase");
	if (!mysql_real_connect(dbsMy, ip.c_str(), username.c_str(), password.c_str(), dbsname.c_str(), 0, NULL, 0)) throw DbsException("DbsException / MySQL: connection failure");

	executeQuery("SET SESSION wait_timeout = 31536000");

	tblbrlyaccrmuseruniversal = new MyTblBrlyAccRMUserUniversal();
	((MyTblBrlyAccRMUserUniversal*) tblbrlyaccrmuseruniversal)->init(dbsMy);
	tblbrlyamfaflightwaypoint = new MyTblBrlyAMFaflightWaypoint();
	((MyTblBrlyAMFaflightWaypoint*) tblbrlyamfaflightwaypoint)->init(dbsMy);
	tblbrlyampersondetail = new MyTblBrlyAMPersonDetail();
	((MyTblBrlyAMPersonDetail*) tblbrlyampersondetail)->init(dbsMy);
	tblbrlyamregiondstswitch = new MyTblBrlyAMRegionDstswitch();
	((MyTblBrlyAMRegionDstswitch*) tblbrlyamregiondstswitch)->init(dbsMy);
	tblbrlyamuseraccess = new MyTblBrlyAMUserAccess();
	((MyTblBrlyAMUserAccess*) tblbrlyamuseraccess)->init(dbsMy);
	tblbrlyamusergroupaccess = new MyTblBrlyAMUsergroupAccess();
	((MyTblBrlyAMUsergroupAccess*) tblbrlyamusergroupaccess)->init(dbsMy);
	tblbrlyavcontrolpar = new MyTblBrlyAVControlPar();
	((MyTblBrlyAVControlPar*) tblbrlyavcontrolpar)->init(dbsMy);
	tblbrlyavkeylistkey = new MyTblBrlyAVKeylistKey();
	((MyTblBrlyAVKeylistKey*) tblbrlyavkeylistkey)->init(dbsMy);
	tblbrlyavvaluelistval = new MyTblBrlyAVValuelistVal();
	((MyTblBrlyAVValuelistVal*) tblbrlyavvaluelistval)->init(dbsMy);
	tblbrlycfile = new MyTblBrlyCFile();
	((MyTblBrlyCFile*) tblbrlycfile)->init(dbsMy);
	tblbrlycleg = new MyTblBrlyCLeg();
	((MyTblBrlyCLeg*) tblbrlycleg)->init(dbsMy);
	tblbrlyhistrmuseruniversal = new MyTblBrlyHistRMUserUniversal();
	((MyTblBrlyHistRMUserUniversal*) tblbrlyhistrmuseruniversal)->init(dbsMy);
	tblbrlyjavkeylistkey = new MyTblBrlyJAVKeylistKey();
	((MyTblBrlyJAVKeylistKey*) tblbrlyjavkeylistkey)->init(dbsMy);
	tblbrlyjmpersonlastname = new MyTblBrlyJMPersonLastname();
	((MyTblBrlyJMPersonLastname*) tblbrlyjmpersonlastname)->init(dbsMy);
	tblbrlyjmregion = new MyTblBrlyJMRegion();
	((MyTblBrlyJMRegion*) tblbrlyjmregion)->init(dbsMy);
	tblbrlyjmregiontitle = new MyTblBrlyJMRegionTitle();
	((MyTblBrlyJMRegionTitle*) tblbrlyjmregiontitle)->init(dbsMy);
	tblbrlyjmuserstate = new MyTblBrlyJMUserState();
	((MyTblBrlyJMUserState*) tblbrlyjmuserstate)->init(dbsMy);
	tblbrlylrmconnectionmequipment = new MyTblBrlyLRMConnectionMEquipment();
	((MyTblBrlyLRMConnectionMEquipment*) tblbrlylrmconnectionmequipment)->init(dbsMy);
	tblbrlymconnection = new MyTblBrlyMConnection();
	((MyTblBrlyMConnection*) tblbrlymconnection)->init(dbsMy);
	tblbrlymequipment = new MyTblBrlyMEquipment();
	((MyTblBrlyMEquipment*) tblbrlymequipment)->init(dbsMy);
	tblbrlymfaflight = new MyTblBrlyMFaflight();
	((MyTblBrlyMFaflight*) tblbrlymfaflight)->init(dbsMy);
	tblbrlymfile = new MyTblBrlyMFile();
	((MyTblBrlyMFile*) tblbrlymfile)->init(dbsMy);
	tblbrlymflight = new MyTblBrlyMFlight();
	((MyTblBrlyMFlight*) tblbrlymflight)->init(dbsMy);
	tblbrlymleg = new MyTblBrlyMLeg();
	((MyTblBrlyMLeg*) tblbrlymleg)->init(dbsMy);
	tblbrlymlocation = new MyTblBrlyMLocation();
	((MyTblBrlyMLocation*) tblbrlymlocation)->init(dbsMy);
	tblbrlymnode = new MyTblBrlyMNode();
	((MyTblBrlyMNode*) tblbrlymnode)->init(dbsMy);
	tblbrlymoperator = new MyTblBrlyMOperator();
	((MyTblBrlyMOperator*) tblbrlymoperator)->init(dbsMy);
	tblbrlymperson = new MyTblBrlyMPerson();
	((MyTblBrlyMPerson*) tblbrlymperson)->init(dbsMy);
	tblbrlymplntype = new MyTblBrlyMPlntype();
	((MyTblBrlyMPlntype*) tblbrlymplntype)->init(dbsMy);
	tblbrlymregion = new MyTblBrlyMRegion();
	((MyTblBrlyMRegion*) tblbrlymregion)->init(dbsMy);
	tblbrlymrelay = new MyTblBrlyMRelay();
	((MyTblBrlyMRelay*) tblbrlymrelay)->init(dbsMy);
	tblbrlymsegment = new MyTblBrlyMSegment();
	((MyTblBrlyMSegment*) tblbrlymsegment)->init(dbsMy);
	tblbrlymsession = new MyTblBrlyMSession();
	((MyTblBrlyMSession*) tblbrlymsession)->init(dbsMy);
	tblbrlymtimetable = new MyTblBrlyMTimetable();
	((MyTblBrlyMTimetable*) tblbrlymtimetable)->init(dbsMy);
	tblbrlymuser = new MyTblBrlyMUser();
	((MyTblBrlyMUser*) tblbrlymuser)->init(dbsMy);
	tblbrlymusergroup = new MyTblBrlyMUsergroup();
	((MyTblBrlyMUsergroup*) tblbrlymusergroup)->init(dbsMy);
	tblbrlyormconnectionmequipment = new MyTblBrlyORMConnectionMEquipment();
	((MyTblBrlyORMConnectionMEquipment*) tblbrlyormconnectionmequipment)->init(dbsMy);
	tblbrlyproxrmlocationmlocation = new MyTblBrlyProxRMLocationMLocation();
	((MyTblBrlyProxRMLocationMLocation*) tblbrlyproxrmlocationmlocation)->init(dbsMy);
	tblbrlyrmconnectionmflight = new MyTblBrlyRMConnectionMFlight();
	((MyTblBrlyRMConnectionMFlight*) tblbrlyrmconnectionmflight)->init(dbsMy);
	tblbrlyrmconnectionmsegment = new MyTblBrlyRMConnectionMSegment();
	((MyTblBrlyRMConnectionMSegment*) tblbrlyrmconnectionmsegment)->init(dbsMy);
	tblbrlyrmflightmflight = new MyTblBrlyRMFlightMFlight();
	((MyTblBrlyRMFlightMFlight*) tblbrlyrmflightmflight)->init(dbsMy);
	tblbrlyrmflightmlocation = new MyTblBrlyRMFlightMLocation();
	((MyTblBrlyRMFlightMLocation*) tblbrlyrmflightmlocation)->init(dbsMy);
	tblbrlyrmlegmleg = new MyTblBrlyRMLegMLeg();
	((MyTblBrlyRMLegMLeg*) tblbrlyrmlegmleg)->init(dbsMy);
	tblbrlyrmlegmlocation = new MyTblBrlyRMLegMLocation();
	((MyTblBrlyRMLegMLocation*) tblbrlyrmlegmlocation)->init(dbsMy);
	tblbrlyrmlocationmsegment = new MyTblBrlyRMLocationMSegment();
	((MyTblBrlyRMLocationMSegment*) tblbrlyrmlocationmsegment)->init(dbsMy);
	tblbrlyrmsegmentmsegment = new MyTblBrlyRMSegmentMSegment();
	((MyTblBrlyRMSegmentMSegment*) tblbrlyrmsegmentmsegment)->init(dbsMy);
	tblbrlyrmusergroupuniversal = new MyTblBrlyRMUsergroupUniversal();
	((MyTblBrlyRMUsergroupUniversal*) tblbrlyrmusergroupuniversal)->init(dbsMy);
	tblbrlyrmusermusergroup = new MyTblBrlyRMUserMUsergroup();
	((MyTblBrlyRMUserMUsergroup*) tblbrlyrmusermusergroup)->init(dbsMy);
	tblbrlyvisrmlocationmlocation = new MyTblBrlyVisRMLocationMLocation();
	((MyTblBrlyVisRMLocationMLocation*) tblbrlyvisrmlocationmlocation)->init(dbsMy);

	tblbrlyqcon1nrelay = new MyTblBrlyQCon1NRelay();
	((MyTblBrlyQCon1NRelay*) tblbrlyqcon1nrelay)->init(dbsMy);
	tblbrlyqconconmnequipment = new MyTblBrlyQConConMNEquipment();
	((MyTblBrlyQConConMNEquipment*) tblbrlyqconconmnequipment)->init(dbsMy);
	tblbrlyqconlist = new MyTblBrlyQConList();
	((MyTblBrlyQConList*) tblbrlyqconlist)->init(dbsMy);
	tblbrlyqconmapflight = new MyTblBrlyQConMapFlight();
	((MyTblBrlyQConMapFlight*) tblbrlyqconmapflight)->init(dbsMy);
	tblbrlyqconmapleg = new MyTblBrlyQConMapLeg();
	((MyTblBrlyQConMapLeg*) tblbrlyqconmapleg)->init(dbsMy);
	tblbrlyqconmaplocation = new MyTblBrlyQConMapLocation();
	((MyTblBrlyQConMapLocation*) tblbrlyqconmaplocation)->init(dbsMy);
	tblbrlyqconmapnode = new MyTblBrlyQConMapNode();
	((MyTblBrlyQConMapNode*) tblbrlyqconmapnode)->init(dbsMy);
	tblbrlyqconmaprelay = new MyTblBrlyQConMapRelay();
	((MyTblBrlyQConMapRelay*) tblbrlyqconmaprelay)->init(dbsMy);
	tblbrlyqconmnflight = new MyTblBrlyQConMNFlight();
	((MyTblBrlyQConMNFlight*) tblbrlyqconmnflight)->init(dbsMy);
	tblbrlyqconmnsegment = new MyTblBrlyQConMNSegment();
	((MyTblBrlyQConMNSegment*) tblbrlyqconmnsegment)->init(dbsMy);
	tblbrlyqconref1nsegment = new MyTblBrlyQConRef1NSegment();
	((MyTblBrlyQConRef1NSegment*) tblbrlyqconref1nsegment)->init(dbsMy);
	tblbrlyqfillist = new MyTblBrlyQFilList();
	((MyTblBrlyQFilList*) tblbrlyqfillist)->init(dbsMy);
	tblbrlyqflt1nconnection = new MyTblBrlyQFlt1NConnection();
	((MyTblBrlyQFlt1NConnection*) tblbrlyqflt1nconnection)->init(dbsMy);
	tblbrlyqflteqp1nnode = new MyTblBrlyQFltEqp1NNode();
	((MyTblBrlyQFltEqp1NNode*) tblbrlyqflteqp1nnode)->init(dbsMy);
	tblbrlyqflteqpmnconnection = new MyTblBrlyQFltEqpMNConnection();
	((MyTblBrlyQFltEqpMNConnection*) tblbrlyqflteqpmnconnection)->init(dbsMy);
	tblbrlyqfltfafawaypoint = new MyTblBrlyQFltFafAWaypoint();
	((MyTblBrlyQFltFafAWaypoint*) tblbrlyqfltfafawaypoint)->init(dbsMy);
	tblbrlyqfltlist = new MyTblBrlyQFltList();
	((MyTblBrlyQFltList*) tblbrlyqfltlist)->init(dbsMy);
	tblbrlyqfltmnconnection = new MyTblBrlyQFltMNConnection();
	((MyTblBrlyQFltMNConnection*) tblbrlyqfltmnconnection)->init(dbsMy);
	tblbrlyqfltmnlocation = new MyTblBrlyQFltMNLocation();
	((MyTblBrlyQFltMNLocation*) tblbrlyqfltmnlocation)->init(dbsMy);
	tblbrlyqfltorgmnflight = new MyTblBrlyQFltOrgMNFlight();
	((MyTblBrlyQFltOrgMNFlight*) tblbrlyqfltorgmnflight)->init(dbsMy);
	tblbrlyqfltref1nsegment = new MyTblBrlyQFltRef1NSegment();
	((MyTblBrlyQFltRef1NSegment*) tblbrlyqfltref1nsegment)->init(dbsMy);
	tblbrlyqleg1nflight = new MyTblBrlyQLeg1NFlight();
	((MyTblBrlyQLeg1NFlight*) tblbrlyqleg1nflight)->init(dbsMy);
	tblbrlyqlegcor1nconnection = new MyTblBrlyQLegCor1NConnection();
	((MyTblBrlyQLegCor1NConnection*) tblbrlyqlegcor1nconnection)->init(dbsMy);
	tblbrlyqleglist = new MyTblBrlyQLegList();
	((MyTblBrlyQLegList*) tblbrlyqleglist)->init(dbsMy);
	tblbrlyqlegmapleg = new MyTblBrlyQLegMapLeg();
	((MyTblBrlyQLegMapLeg*) tblbrlyqlegmapleg)->init(dbsMy);
	tblbrlyqlegmaplocation = new MyTblBrlyQLegMapLocation();
	((MyTblBrlyQLegMapLocation*) tblbrlyqlegmaplocation)->init(dbsMy);
	tblbrlyqlegmnlocation = new MyTblBrlyQLegMNLocation();
	((MyTblBrlyQLegMNLocation*) tblbrlyqlegmnlocation)->init(dbsMy);
	tblbrlyqlegorgmnleg = new MyTblBrlyQLegOrgMNLeg();
	((MyTblBrlyQLegOrgMNLeg*) tblbrlyqlegorgmnleg)->init(dbsMy);
	tblbrlyqlocbgn1nleg = new MyTblBrlyQLocBgn1NLeg();
	((MyTblBrlyQLocBgn1NLeg*) tblbrlyqlocbgn1nleg)->init(dbsMy);
	tblbrlyqlocend1nleg = new MyTblBrlyQLocEnd1NLeg();
	((MyTblBrlyQLocEnd1NLeg*) tblbrlyqlocend1nleg)->init(dbsMy);
	tblbrlyqloceqp1nnode = new MyTblBrlyQLocEqp1NNode();
	((MyTblBrlyQLocEqp1NNode*) tblbrlyqloceqp1nnode)->init(dbsMy);
	tblbrlyqloceqpmnconnection = new MyTblBrlyQLocEqpMNConnection();
	((MyTblBrlyQLocEqpMNConnection*) tblbrlyqloceqpmnconnection)->init(dbsMy);
	tblbrlyqloclist = new MyTblBrlyQLocList();
	((MyTblBrlyQLocList*) tblbrlyqloclist)->init(dbsMy);
	tblbrlyqlocmapleg = new MyTblBrlyQLocMapLeg();
	((MyTblBrlyQLocMapLeg*) tblbrlyqlocmapleg)->init(dbsMy);
	tblbrlyqlocmapproxlocation = new MyTblBrlyQLocMapProxLocation();
	((MyTblBrlyQLocMapProxLocation*) tblbrlyqlocmapproxlocation)->init(dbsMy);
	tblbrlyqlocmapvislocation = new MyTblBrlyQLocMapVisLocation();
	((MyTblBrlyQLocMapVisLocation*) tblbrlyqlocmapvislocation)->init(dbsMy);
	tblbrlyqlocmnflight = new MyTblBrlyQLocMNFlight();
	((MyTblBrlyQLocMNFlight*) tblbrlyqlocmnflight)->init(dbsMy);
	tblbrlyqlocmnleg = new MyTblBrlyQLocMNLeg();
	((MyTblBrlyQLocMNLeg*) tblbrlyqlocmnleg)->init(dbsMy);
	tblbrlyqlocmnsegment = new MyTblBrlyQLocMNSegment();
	((MyTblBrlyQLocMNSegment*) tblbrlyqlocmnsegment)->init(dbsMy);
	tblbrlyqlocproxorgmnlocation = new MyTblBrlyQLocProxOrgMNLocation();
	((MyTblBrlyQLocProxOrgMNLocation*) tblbrlyqlocproxorgmnlocation)->init(dbsMy);
	tblbrlyqlocvisorgmnlocation = new MyTblBrlyQLocVisOrgMNLocation();
	((MyTblBrlyQLocVisOrgMNLocation*) tblbrlyqlocvisorgmnlocation)->init(dbsMy);
	tblbrlyqopr1nequipment = new MyTblBrlyQOpr1NEquipment();
	((MyTblBrlyQOpr1NEquipment*) tblbrlyqopr1nequipment)->init(dbsMy);
	tblbrlyqoprlist = new MyTblBrlyQOprList();
	((MyTblBrlyQOprList*) tblbrlyqoprlist)->init(dbsMy);
	tblbrlyqpreselect = new MyTblBrlyQPreselect();
	((MyTblBrlyQPreselect*) tblbrlyqpreselect)->init(dbsMy);
	tblbrlyqprsadetail = new MyTblBrlyQPrsADetail();
	((MyTblBrlyQPrsADetail*) tblbrlyqprsadetail)->init(dbsMy);
	tblbrlyqprslist = new MyTblBrlyQPrsList();
	((MyTblBrlyQPrsList*) tblbrlyqprslist)->init(dbsMy);
	tblbrlyqpty1nequipment = new MyTblBrlyQPty1NEquipment();
	((MyTblBrlyQPty1NEquipment*) tblbrlyqpty1nequipment)->init(dbsMy);
	tblbrlyqptylist = new MyTblBrlyQPtyList();
	((MyTblBrlyQPtyList*) tblbrlyqptylist)->init(dbsMy);
	tblbrlyqreg1nlocation = new MyTblBrlyQReg1NLocation();
	((MyTblBrlyQReg1NLocation*) tblbrlyqreg1nlocation)->init(dbsMy);
	tblbrlyqregadstswitch = new MyTblBrlyQRegADstswitch();
	((MyTblBrlyQRegADstswitch*) tblbrlyqregadstswitch)->init(dbsMy);
	tblbrlyqreglist = new MyTblBrlyQRegList();
	((MyTblBrlyQRegList*) tblbrlyqreglist)->init(dbsMy);
	tblbrlyqregsup1nregion = new MyTblBrlyQRegSup1NRegion();
	((MyTblBrlyQRegSup1NRegion*) tblbrlyqregsup1nregion)->init(dbsMy);
	tblbrlyqrly1nnode = new MyTblBrlyQRly1NNode();
	((MyTblBrlyQRly1NNode*) tblbrlyqrly1nnode)->init(dbsMy);
	tblbrlyqrlylist = new MyTblBrlyQRlyList();
	((MyTblBrlyQRlyList*) tblbrlyqrlylist)->init(dbsMy);
	tblbrlyqseglist = new MyTblBrlyQSegList();
	((MyTblBrlyQSegList*) tblbrlyqseglist)->init(dbsMy);
	tblbrlyqsegmnconnection = new MyTblBrlyQSegMNConnection();
	((MyTblBrlyQSegMNConnection*) tblbrlyqsegmnconnection)->init(dbsMy);
	tblbrlyqsegmnlocation = new MyTblBrlyQSegMNLocation();
	((MyTblBrlyQSegMNLocation*) tblbrlyqsegmnlocation)->init(dbsMy);
	tblbrlyqsegorgmnsegment = new MyTblBrlyQSegOrgMNSegment();
	((MyTblBrlyQSegOrgMNSegment*) tblbrlyqsegorgmnsegment)->init(dbsMy);
	tblbrlyqselect = new MyTblBrlyQSelect();
	((MyTblBrlyQSelect*) tblbrlyqselect)->init(dbsMy);
	tblbrlyqttb1nflight = new MyTblBrlyQTtb1NFlight();
	((MyTblBrlyQTtb1NFlight*) tblbrlyqttb1nflight)->init(dbsMy);
	tblbrlyqttblist = new MyTblBrlyQTtbList();
	((MyTblBrlyQTtbList*) tblbrlyqttblist)->init(dbsMy);
	tblbrlyqttbref1nfile = new MyTblBrlyQTtbRef1NFile();
	((MyTblBrlyQTtbRef1NFile*) tblbrlyqttbref1nfile)->init(dbsMy);
	tblbrlyqusgaaccess = new MyTblBrlyQUsgAAccess();
	((MyTblBrlyQUsgAAccess*) tblbrlyqusgaaccess)->init(dbsMy);
	tblbrlyqusglist = new MyTblBrlyQUsgList();
	((MyTblBrlyQUsgList*) tblbrlyqusglist)->init(dbsMy);
	tblbrlyqusgmnuser = new MyTblBrlyQUsgMNUser();
	((MyTblBrlyQUsgMNUser*) tblbrlyqusgmnuser)->init(dbsMy);
	tblbrlyqusr1nsession = new MyTblBrlyQUsr1NSession();
	((MyTblBrlyQUsr1NSession*) tblbrlyqusr1nsession)->init(dbsMy);
	tblbrlyqusraaccess = new MyTblBrlyQUsrAAccess();
	((MyTblBrlyQUsrAAccess*) tblbrlyqusraaccess)->init(dbsMy);
	tblbrlyqusrlist = new MyTblBrlyQUsrList();
	((MyTblBrlyQUsrList*) tblbrlyqusrlist)->init(dbsMy);
	tblbrlyqusrmnusergroup = new MyTblBrlyQUsrMNUsergroup();
	((MyTblBrlyQUsrMNUsergroup*) tblbrlyqusrmnusergroup)->init(dbsMy);
};

void DbsBrly::termMy() {
	mysql_close(dbsMy);
	mysql_thread_end();
};

void DbsBrly::initPg() {
	// connect to PostgreSQL database
	dbsPg = PQsetdbLogin(ip.c_str(), to_string(port).c_str(), NULL, NULL, dbsname.c_str(), username.c_str(), password.c_str());

	if (PQstatus(dbsPg) == CONNECTION_BAD) throw DbsException("DbsException / PgSQL: connection failure");

	tblbrlyaccrmuseruniversal = new PgTblBrlyAccRMUserUniversal();
	((PgTblBrlyAccRMUserUniversal*) tblbrlyaccrmuseruniversal)->init(dbsPg);
	tblbrlyamfaflightwaypoint = new PgTblBrlyAMFaflightWaypoint();
	((PgTblBrlyAMFaflightWaypoint*) tblbrlyamfaflightwaypoint)->init(dbsPg);
	tblbrlyampersondetail = new PgTblBrlyAMPersonDetail();
	((PgTblBrlyAMPersonDetail*) tblbrlyampersondetail)->init(dbsPg);
	tblbrlyamregiondstswitch = new PgTblBrlyAMRegionDstswitch();
	((PgTblBrlyAMRegionDstswitch*) tblbrlyamregiondstswitch)->init(dbsPg);
	tblbrlyamuseraccess = new PgTblBrlyAMUserAccess();
	((PgTblBrlyAMUserAccess*) tblbrlyamuseraccess)->init(dbsPg);
	tblbrlyamusergroupaccess = new PgTblBrlyAMUsergroupAccess();
	((PgTblBrlyAMUsergroupAccess*) tblbrlyamusergroupaccess)->init(dbsPg);
	tblbrlyavcontrolpar = new PgTblBrlyAVControlPar();
	((PgTblBrlyAVControlPar*) tblbrlyavcontrolpar)->init(dbsPg);
	tblbrlyavkeylistkey = new PgTblBrlyAVKeylistKey();
	((PgTblBrlyAVKeylistKey*) tblbrlyavkeylistkey)->init(dbsPg);
	tblbrlyavvaluelistval = new PgTblBrlyAVValuelistVal();
	((PgTblBrlyAVValuelistVal*) tblbrlyavvaluelistval)->init(dbsPg);
	tblbrlycfile = new PgTblBrlyCFile();
	((PgTblBrlyCFile*) tblbrlycfile)->init(dbsPg);
	tblbrlycleg = new PgTblBrlyCLeg();
	((PgTblBrlyCLeg*) tblbrlycleg)->init(dbsPg);
	tblbrlyhistrmuseruniversal = new PgTblBrlyHistRMUserUniversal();
	((PgTblBrlyHistRMUserUniversal*) tblbrlyhistrmuseruniversal)->init(dbsPg);
	tblbrlyjavkeylistkey = new PgTblBrlyJAVKeylistKey();
	((PgTblBrlyJAVKeylistKey*) tblbrlyjavkeylistkey)->init(dbsPg);
	tblbrlyjmpersonlastname = new PgTblBrlyJMPersonLastname();
	((PgTblBrlyJMPersonLastname*) tblbrlyjmpersonlastname)->init(dbsPg);
	tblbrlyjmregion = new PgTblBrlyJMRegion();
	((PgTblBrlyJMRegion*) tblbrlyjmregion)->init(dbsPg);
	tblbrlyjmregiontitle = new PgTblBrlyJMRegionTitle();
	((PgTblBrlyJMRegionTitle*) tblbrlyjmregiontitle)->init(dbsPg);
	tblbrlyjmuserstate = new PgTblBrlyJMUserState();
	((PgTblBrlyJMUserState*) tblbrlyjmuserstate)->init(dbsPg);
	tblbrlylrmconnectionmequipment = new PgTblBrlyLRMConnectionMEquipment();
	((PgTblBrlyLRMConnectionMEquipment*) tblbrlylrmconnectionmequipment)->init(dbsPg);
	tblbrlymconnection = new PgTblBrlyMConnection();
	((PgTblBrlyMConnection*) tblbrlymconnection)->init(dbsPg);
	tblbrlymequipment = new PgTblBrlyMEquipment();
	((PgTblBrlyMEquipment*) tblbrlymequipment)->init(dbsPg);
	tblbrlymfaflight = new PgTblBrlyMFaflight();
	((PgTblBrlyMFaflight*) tblbrlymfaflight)->init(dbsPg);
	tblbrlymfile = new PgTblBrlyMFile();
	((PgTblBrlyMFile*) tblbrlymfile)->init(dbsPg);
	tblbrlymflight = new PgTblBrlyMFlight();
	((PgTblBrlyMFlight*) tblbrlymflight)->init(dbsPg);
	tblbrlymleg = new PgTblBrlyMLeg();
	((PgTblBrlyMLeg*) tblbrlymleg)->init(dbsPg);
	tblbrlymlocation = new PgTblBrlyMLocation();
	((PgTblBrlyMLocation*) tblbrlymlocation)->init(dbsPg);
	tblbrlymnode = new PgTblBrlyMNode();
	((PgTblBrlyMNode*) tblbrlymnode)->init(dbsPg);
	tblbrlymoperator = new PgTblBrlyMOperator();
	((PgTblBrlyMOperator*) tblbrlymoperator)->init(dbsPg);
	tblbrlymperson = new PgTblBrlyMPerson();
	((PgTblBrlyMPerson*) tblbrlymperson)->init(dbsPg);
	tblbrlymplntype = new PgTblBrlyMPlntype();
	((PgTblBrlyMPlntype*) tblbrlymplntype)->init(dbsPg);
	tblbrlymregion = new PgTblBrlyMRegion();
	((PgTblBrlyMRegion*) tblbrlymregion)->init(dbsPg);
	tblbrlymrelay = new PgTblBrlyMRelay();
	((PgTblBrlyMRelay*) tblbrlymrelay)->init(dbsPg);
	tblbrlymsegment = new PgTblBrlyMSegment();
	((PgTblBrlyMSegment*) tblbrlymsegment)->init(dbsPg);
	tblbrlymsession = new PgTblBrlyMSession();
	((PgTblBrlyMSession*) tblbrlymsession)->init(dbsPg);
	tblbrlymtimetable = new PgTblBrlyMTimetable();
	((PgTblBrlyMTimetable*) tblbrlymtimetable)->init(dbsPg);
	tblbrlymuser = new PgTblBrlyMUser();
	((PgTblBrlyMUser*) tblbrlymuser)->init(dbsPg);
	tblbrlymusergroup = new PgTblBrlyMUsergroup();
	((PgTblBrlyMUsergroup*) tblbrlymusergroup)->init(dbsPg);
	tblbrlyormconnectionmequipment = new PgTblBrlyORMConnectionMEquipment();
	((PgTblBrlyORMConnectionMEquipment*) tblbrlyormconnectionmequipment)->init(dbsPg);
	tblbrlyproxrmlocationmlocation = new PgTblBrlyProxRMLocationMLocation();
	((PgTblBrlyProxRMLocationMLocation*) tblbrlyproxrmlocationmlocation)->init(dbsPg);
	tblbrlyrmconnectionmflight = new PgTblBrlyRMConnectionMFlight();
	((PgTblBrlyRMConnectionMFlight*) tblbrlyrmconnectionmflight)->init(dbsPg);
	tblbrlyrmconnectionmsegment = new PgTblBrlyRMConnectionMSegment();
	((PgTblBrlyRMConnectionMSegment*) tblbrlyrmconnectionmsegment)->init(dbsPg);
	tblbrlyrmflightmflight = new PgTblBrlyRMFlightMFlight();
	((PgTblBrlyRMFlightMFlight*) tblbrlyrmflightmflight)->init(dbsPg);
	tblbrlyrmflightmlocation = new PgTblBrlyRMFlightMLocation();
	((PgTblBrlyRMFlightMLocation*) tblbrlyrmflightmlocation)->init(dbsPg);
	tblbrlyrmlegmleg = new PgTblBrlyRMLegMLeg();
	((PgTblBrlyRMLegMLeg*) tblbrlyrmlegmleg)->init(dbsPg);
	tblbrlyrmlegmlocation = new PgTblBrlyRMLegMLocation();
	((PgTblBrlyRMLegMLocation*) tblbrlyrmlegmlocation)->init(dbsPg);
	tblbrlyrmlocationmsegment = new PgTblBrlyRMLocationMSegment();
	((PgTblBrlyRMLocationMSegment*) tblbrlyrmlocationmsegment)->init(dbsPg);
	tblbrlyrmsegmentmsegment = new PgTblBrlyRMSegmentMSegment();
	((PgTblBrlyRMSegmentMSegment*) tblbrlyrmsegmentmsegment)->init(dbsPg);
	tblbrlyrmusergroupuniversal = new PgTblBrlyRMUsergroupUniversal();
	((PgTblBrlyRMUsergroupUniversal*) tblbrlyrmusergroupuniversal)->init(dbsPg);
	tblbrlyrmusermusergroup = new PgTblBrlyRMUserMUsergroup();
	((PgTblBrlyRMUserMUsergroup*) tblbrlyrmusermusergroup)->init(dbsPg);
	tblbrlyvisrmlocationmlocation = new PgTblBrlyVisRMLocationMLocation();
	((PgTblBrlyVisRMLocationMLocation*) tblbrlyvisrmlocationmlocation)->init(dbsPg);

	tblbrlyqcon1nrelay = new PgTblBrlyQCon1NRelay();
	((PgTblBrlyQCon1NRelay*) tblbrlyqcon1nrelay)->init(dbsPg);
	tblbrlyqconconmnequipment = new PgTblBrlyQConConMNEquipment();
	((PgTblBrlyQConConMNEquipment*) tblbrlyqconconmnequipment)->init(dbsPg);
	tblbrlyqconlist = new PgTblBrlyQConList();
	((PgTblBrlyQConList*) tblbrlyqconlist)->init(dbsPg);
	tblbrlyqconmapflight = new PgTblBrlyQConMapFlight();
	((PgTblBrlyQConMapFlight*) tblbrlyqconmapflight)->init(dbsPg);
	tblbrlyqconmapleg = new PgTblBrlyQConMapLeg();
	((PgTblBrlyQConMapLeg*) tblbrlyqconmapleg)->init(dbsPg);
	tblbrlyqconmaplocation = new PgTblBrlyQConMapLocation();
	((PgTblBrlyQConMapLocation*) tblbrlyqconmaplocation)->init(dbsPg);
	tblbrlyqconmapnode = new PgTblBrlyQConMapNode();
	((PgTblBrlyQConMapNode*) tblbrlyqconmapnode)->init(dbsPg);
	tblbrlyqconmaprelay = new PgTblBrlyQConMapRelay();
	((PgTblBrlyQConMapRelay*) tblbrlyqconmaprelay)->init(dbsPg);
	tblbrlyqconmnflight = new PgTblBrlyQConMNFlight();
	((PgTblBrlyQConMNFlight*) tblbrlyqconmnflight)->init(dbsPg);
	tblbrlyqconmnsegment = new PgTblBrlyQConMNSegment();
	((PgTblBrlyQConMNSegment*) tblbrlyqconmnsegment)->init(dbsPg);
	tblbrlyqconref1nsegment = new PgTblBrlyQConRef1NSegment();
	((PgTblBrlyQConRef1NSegment*) tblbrlyqconref1nsegment)->init(dbsPg);
	tblbrlyqfillist = new PgTblBrlyQFilList();
	((PgTblBrlyQFilList*) tblbrlyqfillist)->init(dbsPg);
	tblbrlyqflt1nconnection = new PgTblBrlyQFlt1NConnection();
	((PgTblBrlyQFlt1NConnection*) tblbrlyqflt1nconnection)->init(dbsPg);
	tblbrlyqflteqp1nnode = new PgTblBrlyQFltEqp1NNode();
	((PgTblBrlyQFltEqp1NNode*) tblbrlyqflteqp1nnode)->init(dbsPg);
	tblbrlyqflteqpmnconnection = new PgTblBrlyQFltEqpMNConnection();
	((PgTblBrlyQFltEqpMNConnection*) tblbrlyqflteqpmnconnection)->init(dbsPg);
	tblbrlyqfltfafawaypoint = new PgTblBrlyQFltFafAWaypoint();
	((PgTblBrlyQFltFafAWaypoint*) tblbrlyqfltfafawaypoint)->init(dbsPg);
	tblbrlyqfltlist = new PgTblBrlyQFltList();
	((PgTblBrlyQFltList*) tblbrlyqfltlist)->init(dbsPg);
	tblbrlyqfltmnconnection = new PgTblBrlyQFltMNConnection();
	((PgTblBrlyQFltMNConnection*) tblbrlyqfltmnconnection)->init(dbsPg);
	tblbrlyqfltmnlocation = new PgTblBrlyQFltMNLocation();
	((PgTblBrlyQFltMNLocation*) tblbrlyqfltmnlocation)->init(dbsPg);
	tblbrlyqfltorgmnflight = new PgTblBrlyQFltOrgMNFlight();
	((PgTblBrlyQFltOrgMNFlight*) tblbrlyqfltorgmnflight)->init(dbsPg);
	tblbrlyqfltref1nsegment = new PgTblBrlyQFltRef1NSegment();
	((PgTblBrlyQFltRef1NSegment*) tblbrlyqfltref1nsegment)->init(dbsPg);
	tblbrlyqleg1nflight = new PgTblBrlyQLeg1NFlight();
	((PgTblBrlyQLeg1NFlight*) tblbrlyqleg1nflight)->init(dbsPg);
	tblbrlyqlegcor1nconnection = new PgTblBrlyQLegCor1NConnection();
	((PgTblBrlyQLegCor1NConnection*) tblbrlyqlegcor1nconnection)->init(dbsPg);
	tblbrlyqleglist = new PgTblBrlyQLegList();
	((PgTblBrlyQLegList*) tblbrlyqleglist)->init(dbsPg);
	tblbrlyqlegmapleg = new PgTblBrlyQLegMapLeg();
	((PgTblBrlyQLegMapLeg*) tblbrlyqlegmapleg)->init(dbsPg);
	tblbrlyqlegmaplocation = new PgTblBrlyQLegMapLocation();
	((PgTblBrlyQLegMapLocation*) tblbrlyqlegmaplocation)->init(dbsPg);
	tblbrlyqlegmnlocation = new PgTblBrlyQLegMNLocation();
	((PgTblBrlyQLegMNLocation*) tblbrlyqlegmnlocation)->init(dbsPg);
	tblbrlyqlegorgmnleg = new PgTblBrlyQLegOrgMNLeg();
	((PgTblBrlyQLegOrgMNLeg*) tblbrlyqlegorgmnleg)->init(dbsPg);
	tblbrlyqlocbgn1nleg = new PgTblBrlyQLocBgn1NLeg();
	((PgTblBrlyQLocBgn1NLeg*) tblbrlyqlocbgn1nleg)->init(dbsPg);
	tblbrlyqlocend1nleg = new PgTblBrlyQLocEnd1NLeg();
	((PgTblBrlyQLocEnd1NLeg*) tblbrlyqlocend1nleg)->init(dbsPg);
	tblbrlyqloceqp1nnode = new PgTblBrlyQLocEqp1NNode();
	((PgTblBrlyQLocEqp1NNode*) tblbrlyqloceqp1nnode)->init(dbsPg);
	tblbrlyqloceqpmnconnection = new PgTblBrlyQLocEqpMNConnection();
	((PgTblBrlyQLocEqpMNConnection*) tblbrlyqloceqpmnconnection)->init(dbsPg);
	tblbrlyqloclist = new PgTblBrlyQLocList();
	((PgTblBrlyQLocList*) tblbrlyqloclist)->init(dbsPg);
	tblbrlyqlocmapleg = new PgTblBrlyQLocMapLeg();
	((PgTblBrlyQLocMapLeg*) tblbrlyqlocmapleg)->init(dbsPg);
	tblbrlyqlocmapproxlocation = new PgTblBrlyQLocMapProxLocation();
	((PgTblBrlyQLocMapProxLocation*) tblbrlyqlocmapproxlocation)->init(dbsPg);
	tblbrlyqlocmapvislocation = new PgTblBrlyQLocMapVisLocation();
	((PgTblBrlyQLocMapVisLocation*) tblbrlyqlocmapvislocation)->init(dbsPg);
	tblbrlyqlocmnflight = new PgTblBrlyQLocMNFlight();
	((PgTblBrlyQLocMNFlight*) tblbrlyqlocmnflight)->init(dbsPg);
	tblbrlyqlocmnleg = new PgTblBrlyQLocMNLeg();
	((PgTblBrlyQLocMNLeg*) tblbrlyqlocmnleg)->init(dbsPg);
	tblbrlyqlocmnsegment = new PgTblBrlyQLocMNSegment();
	((PgTblBrlyQLocMNSegment*) tblbrlyqlocmnsegment)->init(dbsPg);
	tblbrlyqlocproxorgmnlocation = new PgTblBrlyQLocProxOrgMNLocation();
	((PgTblBrlyQLocProxOrgMNLocation*) tblbrlyqlocproxorgmnlocation)->init(dbsPg);
	tblbrlyqlocvisorgmnlocation = new PgTblBrlyQLocVisOrgMNLocation();
	((PgTblBrlyQLocVisOrgMNLocation*) tblbrlyqlocvisorgmnlocation)->init(dbsPg);
	tblbrlyqopr1nequipment = new PgTblBrlyQOpr1NEquipment();
	((PgTblBrlyQOpr1NEquipment*) tblbrlyqopr1nequipment)->init(dbsPg);
	tblbrlyqoprlist = new PgTblBrlyQOprList();
	((PgTblBrlyQOprList*) tblbrlyqoprlist)->init(dbsPg);
	tblbrlyqpreselect = new PgTblBrlyQPreselect();
	((PgTblBrlyQPreselect*) tblbrlyqpreselect)->init(dbsPg);
	tblbrlyqprsadetail = new PgTblBrlyQPrsADetail();
	((PgTblBrlyQPrsADetail*) tblbrlyqprsadetail)->init(dbsPg);
	tblbrlyqprslist = new PgTblBrlyQPrsList();
	((PgTblBrlyQPrsList*) tblbrlyqprslist)->init(dbsPg);
	tblbrlyqpty1nequipment = new PgTblBrlyQPty1NEquipment();
	((PgTblBrlyQPty1NEquipment*) tblbrlyqpty1nequipment)->init(dbsPg);
	tblbrlyqptylist = new PgTblBrlyQPtyList();
	((PgTblBrlyQPtyList*) tblbrlyqptylist)->init(dbsPg);
	tblbrlyqreg1nlocation = new PgTblBrlyQReg1NLocation();
	((PgTblBrlyQReg1NLocation*) tblbrlyqreg1nlocation)->init(dbsPg);
	tblbrlyqregadstswitch = new PgTblBrlyQRegADstswitch();
	((PgTblBrlyQRegADstswitch*) tblbrlyqregadstswitch)->init(dbsPg);
	tblbrlyqreglist = new PgTblBrlyQRegList();
	((PgTblBrlyQRegList*) tblbrlyqreglist)->init(dbsPg);
	tblbrlyqregsup1nregion = new PgTblBrlyQRegSup1NRegion();
	((PgTblBrlyQRegSup1NRegion*) tblbrlyqregsup1nregion)->init(dbsPg);
	tblbrlyqrly1nnode = new PgTblBrlyQRly1NNode();
	((PgTblBrlyQRly1NNode*) tblbrlyqrly1nnode)->init(dbsPg);
	tblbrlyqrlylist = new PgTblBrlyQRlyList();
	((PgTblBrlyQRlyList*) tblbrlyqrlylist)->init(dbsPg);
	tblbrlyqseglist = new PgTblBrlyQSegList();
	((PgTblBrlyQSegList*) tblbrlyqseglist)->init(dbsPg);
	tblbrlyqsegmnconnection = new PgTblBrlyQSegMNConnection();
	((PgTblBrlyQSegMNConnection*) tblbrlyqsegmnconnection)->init(dbsPg);
	tblbrlyqsegmnlocation = new PgTblBrlyQSegMNLocation();
	((PgTblBrlyQSegMNLocation*) tblbrlyqsegmnlocation)->init(dbsPg);
	tblbrlyqsegorgmnsegment = new PgTblBrlyQSegOrgMNSegment();
	((PgTblBrlyQSegOrgMNSegment*) tblbrlyqsegorgmnsegment)->init(dbsPg);
	tblbrlyqselect = new PgTblBrlyQSelect();
	((PgTblBrlyQSelect*) tblbrlyqselect)->init(dbsPg);
	tblbrlyqttb1nflight = new PgTblBrlyQTtb1NFlight();
	((PgTblBrlyQTtb1NFlight*) tblbrlyqttb1nflight)->init(dbsPg);
	tblbrlyqttblist = new PgTblBrlyQTtbList();
	((PgTblBrlyQTtbList*) tblbrlyqttblist)->init(dbsPg);
	tblbrlyqttbref1nfile = new PgTblBrlyQTtbRef1NFile();
	((PgTblBrlyQTtbRef1NFile*) tblbrlyqttbref1nfile)->init(dbsPg);
	tblbrlyqusgaaccess = new PgTblBrlyQUsgAAccess();
	((PgTblBrlyQUsgAAccess*) tblbrlyqusgaaccess)->init(dbsPg);
	tblbrlyqusglist = new PgTblBrlyQUsgList();
	((PgTblBrlyQUsgList*) tblbrlyqusglist)->init(dbsPg);
	tblbrlyqusgmnuser = new PgTblBrlyQUsgMNUser();
	((PgTblBrlyQUsgMNUser*) tblbrlyqusgmnuser)->init(dbsPg);
	tblbrlyqusr1nsession = new PgTblBrlyQUsr1NSession();
	((PgTblBrlyQUsr1NSession*) tblbrlyqusr1nsession)->init(dbsPg);
	tblbrlyqusraaccess = new PgTblBrlyQUsrAAccess();
	((PgTblBrlyQUsrAAccess*) tblbrlyqusraaccess)->init(dbsPg);
	tblbrlyqusrlist = new PgTblBrlyQUsrList();
	((PgTblBrlyQUsrList*) tblbrlyqusrlist)->init(dbsPg);
	tblbrlyqusrmnusergroup = new PgTblBrlyQUsrMNUsergroup();
	((PgTblBrlyQUsrMNUsergroup*) tblbrlyqusrmnusergroup)->init(dbsPg);
};

void DbsBrly::termPg() {
	PQfinish(dbsPg);
};

void DbsBrly::begin() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) beginMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) beginPg();
};

bool DbsBrly::commit() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return commitMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return commitPg();

	return false;
};

void DbsBrly::rollback() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) rollbackMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) rollbackPg();
};

void DbsBrly::beginMy() {
	if (mysql_query(dbsMy, "BEGIN")) throw DbsException("DbsException / MySQL: failed to begin transaction\n");
};

bool DbsBrly::commitMy() {
	if (mysql_query(dbsMy, "COMMIT")) {
		rollbackMy();
		return false;
	};

	return true;
};

void DbsBrly::rollbackMy() {
	if (mysql_query(dbsMy, "ROLLBACK")) throw DbsException("DbsException / MySQL: failed to roll back transaction\n");
};

void DbsBrly::beginPg() {
	PGresult* res;

	res = PQexec(dbsPg, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: failed to begin transaction\n");

	PQclear(res);
};

bool DbsBrly::commitPg() {
	PGresult* res;

	res = PQexec(dbsPg, "COMMIT");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		rollbackPg();

		PQclear(res);
		return false;
	};

	PQclear(res);
	return true;
};

void DbsBrly::rollbackPg() {
	PGresult* res;

	res = PQexec(dbsPg, "ROLLBACK");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: failed to roll back transaction\n");

	PQclear(res);
};

bool DbsBrly::loadUintBySQL(
			const string& sqlstr
			, uint& val
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadUintBySQLMy(sqlstr, val);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadUintBySQLPg(sqlstr, val);

	return false;
};

bool DbsBrly::loadStringBySQL(
			const string& sqlstr
			, string& val
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadStringBySQLMy(sqlstr, val);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadStringBySQLPg(sqlstr, val);

	return false;
};

bool DbsBrly::loadRefBySQL(
			const string& sqlstr
			, ubigint& ref
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefBySQLMy(sqlstr, ref);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefBySQLPg(sqlstr, ref);

	return false;
};

ubigint DbsBrly::loadRefsBySQL(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefsBySQLMy(sqlstr, append, refs);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefsBySQLPg(sqlstr, append, refs);

	return 0;
};

bool DbsBrly::loadUintBySQLMy(
			const string& sqlstr
			, uint& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadUintBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		val = atol((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsBrly::loadStringBySQLMy(
			const string& sqlstr
			, string& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadStringBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);
		val.assign(dbrow[0], dblengths[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsBrly::loadRefBySQLMy(
			const string& sqlstr
			, ubigint& ref
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadRefBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		ref = atoll((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

ubigint DbsBrly::loadRefsBySQLMy(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadRefsBySQL)\n");

	numrow = mysql_num_rows(dbresult);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		dbrow = mysql_fetch_row(dbresult);
		refs.push_back(atoll((char*) dbrow[0]));
		numread++;
	};

	mysql_free_result(dbresult);
	
	return(numread);
};

bool DbsBrly::loadUintBySQLPg(
			const string& sqlstr
			, uint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atol(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsBrly::loadStringBySQLPg(
			const string& sqlstr
			, string& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;

	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val.assign(ptr, PQgetlength(res, 0, 0));

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsBrly::loadRefBySQLPg(
			const string& sqlstr
			, ubigint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

ubigint DbsBrly::loadRefsBySQLPg(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	PGresult* res; ubigint numrow; ubigint numread = 0; char* ptr;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	numrow = PQntuples(res);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		ptr = PQgetvalue(res, numread, 0); refs.push_back(atoll(ptr));
		numread++;
	};

	PQclear(res);

	return(numread);
};

void DbsBrly::executeQuery(
			const string& sqlstr
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		if (mysql_real_query(dbsMy, sqlstr.c_str(), strlen(sqlstr.c_str())))
			throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	} else if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		PGresult* res;

		res = PQexec(dbsPg, sqlstr.c_str());
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
			throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	};
};

void DbsBrly::executeQueryDiv(
			const string& sqlstrmy
			, const string& sqlstrpg
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) executeQuery(sqlstrmy);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) executeQuery(sqlstrpg);
};

void DbsBrly::executeFile(
			const string& fullpath
		) {
	string sqlstr = "";
	char c;
	
	ifstream sqlfile(fullpath.c_str());

	while (sqlfile.get(c)) {
		switch (c) {
			case '\n':
				break;
			case '\t':
				break;
			case ';':
				executeQuery(sqlstr);
				sqlstr = "";
				break;
			default:
				sqlstr = sqlstr + c;
				break;
		};
	};
	sqlfile.close();
};

uint DbsBrly::getIxWSubsetByRefBrlyMEquipment(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	BrlyMEquipment* rec = NULL;

	if (tblbrlymequipment->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByBrlyMEquipment(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsBrly::getIxWSubsetByBrlyMEquipment(
			BrlyMEquipment* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblBrlyMEquipment::VecWSubset::SBSBRLYBMEQUIPMENTPLN) == 0) {
		a = false; a = (rec->hkIxVTbl == VecBrlyVMEquipmentHkTbl::FLT);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblBrlyMEquipment::VecWSubset::SBSBRLYBMEQUIPMENTPLN;
		} else {
		};

		dneIxWSubset |= TblBrlyMEquipment::VecWSubset::SBSBRLYBMEQUIPMENTPLN;
		args.clear();
	};

	return ixWSubset;
};

uint DbsBrly::getIxWSubsetByRefBrlyMLeg(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	BrlyMLeg* rec = NULL;

	if (tblbrlymleg->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByBrlyMLeg(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsBrly::getIxWSubsetByBrlyMLeg(
			BrlyMLeg* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGCOR) == 0) {
		a = false; a = (rec->ixVBasetype == VecBrlyVMLegBasetype::CORR);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGCOR;
		} else {
			ixWSubset |= TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGRTE;
		};

		dneIxWSubset |= TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGCOR;
		dneIxWSubset |= TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGRTE;
		args.clear();
	};

	if ((dneIxWSubset & TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGRTE) == 0) {
		a = false; a = (rec->ixVBasetype == VecBrlyVMLegBasetype::RTE);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGRTE;
		} else {
			ixWSubset |= TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGCOR;
		};

		dneIxWSubset |= TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGRTE;
		dneIxWSubset |= TblBrlyMLeg::VecWSubset::SBSBRLYBMLEGCOR;
		args.clear();
	};

	return ixWSubset;
};

uint DbsBrly::getIxWSubsetByRefBrlyMLocation(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	BrlyMLocation* rec = NULL;

	if (tblbrlymlocation->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByBrlyMLocation(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsBrly::getIxWSubsetByBrlyMLocation(
			BrlyMLocation* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblBrlyMLocation::VecWSubset::SBSBRLYBMLOCATIONAPT) == 0) {
		a = false; a = (rec->ixVBasetype == VecBrlyVMLocationBasetype::APT);
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblBrlyMLocation::VecWSubset::SBSBRLYBMLOCATIONAPT;
		} else {
		};

		dneIxWSubset |= TblBrlyMLocation::VecWSubset::SBSBRLYBMLOCATIONAPT;
		args.clear();
	};

	return ixWSubset;
};

uint DbsBrly::getIxWSubsetByRefBrlyMRegion(
			const ubigint ref
		) {
	uint ixWSubset = 0;
	BrlyMRegion* rec = NULL;

	if (tblbrlymregion->loadRecByRef(ref, &rec)) {
		ixWSubset = getIxWSubsetByBrlyMRegion(rec);
		delete rec;
	};

	return ixWSubset;
};

uint DbsBrly::getIxWSubsetByBrlyMRegion(
			BrlyMRegion* rec
		) {
	uint ixWSubset = 0;
	uint dneIxWSubset = 0;

	vector<bool> args;
	bool a, b;

	if ((dneIxWSubset & TblBrlyMRegion::VecWSubset::SBSBRLYBMREGIONRIP) == 0) {
		a = false; {uint cnt = 0; loadUintBySQL("SELECT COUNT(ref) FROM TblBrlyMRegion WHERE supRefBrlyMRegion = " + to_string(rec->ref), cnt); a = (cnt == 0);}
		args.push_back(a);
		if (args.back()) {
			ixWSubset |= TblBrlyMRegion::VecWSubset::SBSBRLYBMREGIONRIP;
		} else {
		};

		dneIxWSubset |= TblBrlyMRegion::VecWSubset::SBSBRLYBMREGIONRIP;
		args.clear();
	};

	return ixWSubset;
};

void DbsBrly::fillFeedFromKlst(
			const uint klsIxBrlyVKeylist
			, const uint ixBrlyVLocale
			, Feed& feed
		) {
	ListBrlyAVKeylistKey klsAkeys;
	BrlyAVKeylistKey* klsAkey = NULL;

	tblbrlyavkeylistkey->loadRstByKls(klsIxBrlyVKeylist, false, klsAkeys);

	feed.clear();
	for (unsigned int i=0;i<klsAkeys.nodes.size();i++) {
		klsAkey = klsAkeys.nodes[i];

		tblbrlyjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixBrlyVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

void DbsBrly::fillFeedFromKlstByMtbUref(
			const uint klsIxBrlyVKeylist
			, const uint x1IxBrlyVMaintable
			, const ubigint x1Uref
			, const uint ixBrlyVLocale
			, Feed& feed
		) {
	ListBrlyAVKeylistKey klsAkeys;
	BrlyAVKeylistKey* klsAkey = NULL;

	tblbrlyavkeylistkey->loadRstByKlsMtbUrf(klsIxBrlyVKeylist, x1IxBrlyVMaintable, x1Uref, false, klsAkeys);

	feed.clear();
	for (unsigned int i=0;i<klsAkeys.nodes.size();i++) {
		klsAkey = klsAkeys.nodes[i];

		tblbrlyjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixBrlyVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

string DbsBrly::getKlstTitleBySref(
			const uint klsIxBrlyVKeylist
			, const string& sref
			, const uint ixBrlyVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblbrlyavkeylistkey->loadRefByKlsSrf(klsIxBrlyVKeylist, sref, refKlk))
		if (!tblbrlyjavkeylistkey->loadTitByKlkLcl(refKlk, ixBrlyVLocale, retval))
			tblbrlyavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

string DbsBrly::getKlstTitleByMtbUrefSref(
			const uint klsIxBrlyVKeylist
			, const uint x1IxBrlyVMaintable
			, const ubigint x1Uref
			, const string& sref
			, const uint ixBrlyVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblbrlyavkeylistkey->loadRefByKlsMtbUrfSrf(klsIxBrlyVKeylist, x1IxBrlyVMaintable, x1Uref, sref, refKlk))
		if (!tblbrlyjavkeylistkey->loadTitByKlkLcl(refKlk, ixBrlyVLocale, retval))
			tblbrlyavkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

void DbsBrly::fillFeedFromVlst(
			const uint vlsIxBrlyVValuelist
			, const uint x1IxBrlyVLocale
			, Feed& feed
		) {
	ListBrlyAVValuelistVal vlsAvals;
	BrlyAVValuelistVal* vlsAval = NULL;

	tblbrlyavvaluelistval->loadRstByVlsLcl(vlsIxBrlyVValuelist, x1IxBrlyVLocale, false, vlsAvals);

	feed.clear();
	for (unsigned int i=0;i<vlsAvals.nodes.size();i++) {
		vlsAval = vlsAvals.nodes[i];

		feed.appendTitles(vlsAval->Val);
	};
};

