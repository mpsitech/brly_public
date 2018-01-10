-- CREATE ROLE epsi LOGIN
-- 	ENCRYPTED PASSWORD 'md5f0bc6f83ba77933c9206cfbf7a4a8e2c'
-- 	NOSUPERUSER INHERIT NOCREATEDB NOCREATEROLE;
-- COMMENT ON ROLE epsi IS 'Epsi Software Universal Account';

CREATE DATABASE "DbsBrly"
	WITH ENCODING='UTF8'
	OWNER = epsi
	CONNECTION LIMIT = -1;

DROP TABLE IF EXISTS TblBrlyAccRMUserUniversal;
DROP TABLE IF EXISTS TblBrlyAMFaflightWaypoint;
DROP TABLE IF EXISTS TblBrlyAMPersonDetail;
DROP TABLE IF EXISTS TblBrlyAMRegionDstswitch;
DROP TABLE IF EXISTS TblBrlyAMUserAccess;
DROP TABLE IF EXISTS TblBrlyAMUsergroupAccess;
DROP TABLE IF EXISTS TblBrlyAVControlPar;
DROP TABLE IF EXISTS TblBrlyAVKeylistKey;
DROP TABLE IF EXISTS TblBrlyAVValuelistVal;
DROP SEQUENCE IF EXISTS TblBrlyCFile;
DROP SEQUENCE IF EXISTS TblBrlyCLeg;
DROP TABLE IF EXISTS TblBrlyHistRMUserUniversal;
DROP TABLE IF EXISTS TblBrlyJAVKeylistKey;
DROP TABLE IF EXISTS TblBrlyJMPersonLastname;
DROP TABLE IF EXISTS TblBrlyJMRegion;
DROP TABLE IF EXISTS TblBrlyJMRegionTitle;
DROP TABLE IF EXISTS TblBrlyJMUserState;
DROP TABLE IF EXISTS TblBrlyLRMConnectionMEquipment;
DROP TABLE IF EXISTS TblBrlyMConnection;
DROP TABLE IF EXISTS TblBrlyMEquipment;
DROP TABLE IF EXISTS TblBrlyMFaflight;
DROP TABLE IF EXISTS TblBrlyMFile;
DROP TABLE IF EXISTS TblBrlyMFlight;
DROP TABLE IF EXISTS TblBrlyMLeg;
DROP TABLE IF EXISTS TblBrlyMLocation;
DROP TABLE IF EXISTS TblBrlyMNode;
DROP TABLE IF EXISTS TblBrlyMOperator;
DROP TABLE IF EXISTS TblBrlyMPerson;
DROP TABLE IF EXISTS TblBrlyMPlntype;
DROP TABLE IF EXISTS TblBrlyMRegion;
DROP TABLE IF EXISTS TblBrlyMRelay;
DROP TABLE IF EXISTS TblBrlyMSegment;
DROP TABLE IF EXISTS TblBrlyMSession;
DROP TABLE IF EXISTS TblBrlyMTimetable;
DROP TABLE IF EXISTS TblBrlyMUser;
DROP TABLE IF EXISTS TblBrlyMUsergroup;
DROP TABLE IF EXISTS TblBrlyORMConnectionMEquipment;
DROP TABLE IF EXISTS TblBrlyProxRMLocationMLocation;
DROP TABLE IF EXISTS TblBrlyRMConnectionMFlight;
DROP TABLE IF EXISTS TblBrlyRMConnectionMSegment;
DROP TABLE IF EXISTS TblBrlyRMFlightMFlight;
DROP TABLE IF EXISTS TblBrlyRMFlightMLocation;
DROP TABLE IF EXISTS TblBrlyRMLegMLeg;
DROP TABLE IF EXISTS TblBrlyRMLegMLocation;
DROP TABLE IF EXISTS TblBrlyRMLocationMSegment;
DROP TABLE IF EXISTS TblBrlyRMSegmentMSegment;
DROP TABLE IF EXISTS TblBrlyRMUsergroupUniversal;
DROP TABLE IF EXISTS TblBrlyRMUserMUsergroup;
DROP TABLE IF EXISTS TblBrlyVisRMLocationMLocation;

DROP TABLE IF EXISTS TblBrlyQCon1NRelay;
DROP TABLE IF EXISTS TblBrlyQConConMNEquipment;
DROP TABLE IF EXISTS TblBrlyQConList;
DROP TABLE IF EXISTS TblBrlyQConMapFlight;
DROP TABLE IF EXISTS TblBrlyQConMapLeg;
DROP TABLE IF EXISTS TblBrlyQConMapLocation;
DROP TABLE IF EXISTS TblBrlyQConMapNode;
DROP TABLE IF EXISTS TblBrlyQConMapRelay;
DROP TABLE IF EXISTS TblBrlyQConMNFlight;
DROP TABLE IF EXISTS TblBrlyQConMNSegment;
DROP TABLE IF EXISTS TblBrlyQConRef1NSegment;
DROP TABLE IF EXISTS TblBrlyQFilList;
DROP TABLE IF EXISTS TblBrlyQFlt1NConnection;
DROP TABLE IF EXISTS TblBrlyQFltEqp1NNode;
DROP TABLE IF EXISTS TblBrlyQFltEqpMNConnection;
DROP TABLE IF EXISTS TblBrlyQFltFafAWaypoint;
DROP TABLE IF EXISTS TblBrlyQFltList;
DROP TABLE IF EXISTS TblBrlyQFltMNConnection;
DROP TABLE IF EXISTS TblBrlyQFltMNLocation;
DROP TABLE IF EXISTS TblBrlyQFltOrgMNFlight;
DROP TABLE IF EXISTS TblBrlyQFltRef1NSegment;
DROP TABLE IF EXISTS TblBrlyQLeg1NFlight;
DROP TABLE IF EXISTS TblBrlyQLegCor1NConnection;
DROP TABLE IF EXISTS TblBrlyQLegList;
DROP TABLE IF EXISTS TblBrlyQLegMapLeg;
DROP TABLE IF EXISTS TblBrlyQLegMapLocation;
DROP TABLE IF EXISTS TblBrlyQLegMNLocation;
DROP TABLE IF EXISTS TblBrlyQLegOrgMNLeg;
DROP TABLE IF EXISTS TblBrlyQLocBgn1NLeg;
DROP TABLE IF EXISTS TblBrlyQLocEnd1NLeg;
DROP TABLE IF EXISTS TblBrlyQLocEqp1NNode;
DROP TABLE IF EXISTS TblBrlyQLocEqpMNConnection;
DROP TABLE IF EXISTS TblBrlyQLocList;
DROP TABLE IF EXISTS TblBrlyQLocMapLeg;
DROP TABLE IF EXISTS TblBrlyQLocMapProxLocation;
DROP TABLE IF EXISTS TblBrlyQLocMapVisLocation;
DROP TABLE IF EXISTS TblBrlyQLocMNFlight;
DROP TABLE IF EXISTS TblBrlyQLocMNLeg;
DROP TABLE IF EXISTS TblBrlyQLocMNSegment;
DROP TABLE IF EXISTS TblBrlyQLocProxOrgMNLocation;
DROP TABLE IF EXISTS TblBrlyQLocVisOrgMNLocation;
DROP TABLE IF EXISTS TblBrlyQOpr1NEquipment;
DROP TABLE IF EXISTS TblBrlyQOprList;
DROP TABLE IF EXISTS TblBrlyQPreselect;
DROP TABLE IF EXISTS TblBrlyQPrsADetail;
DROP TABLE IF EXISTS TblBrlyQPrsList;
DROP TABLE IF EXISTS TblBrlyQPty1NEquipment;
DROP TABLE IF EXISTS TblBrlyQPtyList;
DROP TABLE IF EXISTS TblBrlyQReg1NLocation;
DROP TABLE IF EXISTS TblBrlyQRegADstswitch;
DROP TABLE IF EXISTS TblBrlyQRegList;
DROP TABLE IF EXISTS TblBrlyQRegSup1NRegion;
DROP TABLE IF EXISTS TblBrlyQRly1NNode;
DROP TABLE IF EXISTS TblBrlyQRlyList;
DROP TABLE IF EXISTS TblBrlyQSegList;
DROP TABLE IF EXISTS TblBrlyQSegMNConnection;
DROP TABLE IF EXISTS TblBrlyQSegMNLocation;
DROP TABLE IF EXISTS TblBrlyQSegOrgMNSegment;
DROP TABLE IF EXISTS TblBrlyQSelect;
DROP TABLE IF EXISTS TblBrlyQTtb1NFlight;
DROP TABLE IF EXISTS TblBrlyQTtbList;
DROP TABLE IF EXISTS TblBrlyQTtbRef1NFile;
DROP TABLE IF EXISTS TblBrlyQUsgAAccess;
DROP TABLE IF EXISTS TblBrlyQUsgList;
DROP TABLE IF EXISTS TblBrlyQUsgMNUser;
DROP TABLE IF EXISTS TblBrlyQUsr1NSession;
DROP TABLE IF EXISTS TblBrlyQUsrAAccess;
DROP TABLE IF EXISTS TblBrlyQUsrList;
DROP TABLE IF EXISTS TblBrlyQUsrMNUsergroup;

CREATE TABLE TblBrlyAccRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMUser BIGINT,
	unvIxBrlyVMaintable INT,
	unvUref BIGINT,
	ixBrlyVAccess INT
);
ALTER TABLE TblBrlyAccRMUserUniversal OWNER TO epsi;
CREATE INDEX TblBrlyAccRMUserUniversal_refBrlyMUser ON TblBrlyAccRMUserUniversal (refBrlyMUser);
CREATE INDEX TblBrlyAccRMUserUniversal_unvIxBrlyVMaintable ON TblBrlyAccRMUserUniversal (unvIxBrlyVMaintable);
CREATE INDEX TblBrlyAccRMUserUniversal_unvUref ON TblBrlyAccRMUserUniversal (unvUref);

CREATE TABLE TblBrlyAMFaflightWaypoint(
	ref BIGSERIAL PRIMARY KEY,
	fafRefBrlyMFaflight BIGINT,
	fafNum INT,
	timestamp INT,
	latitude DOUBLE PRECISION,
	longitude DOUBLE PRECISION,
	groundspeed SMALLINT,
	altitude SMALLINT,
	altitudeStatus VARCHAR(5),
	updateType VARCHAR(5),
	altitudeChange VARCHAR(5)
);
ALTER TABLE TblBrlyAMFaflightWaypoint OWNER TO epsi;
CREATE INDEX TblBrlyAMFaflightWaypoint_fafRefBrlyMFaflight ON TblBrlyAMFaflightWaypoint (fafRefBrlyMFaflight);
CREATE INDEX TblBrlyAMFaflightWaypoint_fafNum ON TblBrlyAMFaflightWaypoint (fafNum);

CREATE TABLE TblBrlyAMPersonDetail(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(256)
);
ALTER TABLE TblBrlyAMPersonDetail OWNER TO epsi;
CREATE INDEX TblBrlyAMPersonDetail_refBrlyMPerson ON TblBrlyAMPersonDetail (refBrlyMPerson);

CREATE TABLE TblBrlyAMRegionDstswitch(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMRegion BIGINT,
	startd INT,
	startt INT
);
ALTER TABLE TblBrlyAMRegionDstswitch OWNER TO epsi;
CREATE INDEX TblBrlyAMRegionDstswitch_refBrlyMRegion ON TblBrlyAMRegionDstswitch (refBrlyMRegion);
CREATE INDEX TblBrlyAMRegionDstswitch_startd ON TblBrlyAMRegionDstswitch (startd);

CREATE TABLE TblBrlyAMUserAccess(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMUser BIGINT,
	x1IxBrlyVCard INT,
	ixBrlyWUiaccess INT
);
ALTER TABLE TblBrlyAMUserAccess OWNER TO epsi;
CREATE INDEX TblBrlyAMUserAccess_refBrlyMUser ON TblBrlyAMUserAccess (refBrlyMUser);
CREATE INDEX TblBrlyAMUserAccess_x1IxBrlyVCard ON TblBrlyAMUserAccess (x1IxBrlyVCard);

CREATE TABLE TblBrlyAMUsergroupAccess(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMUsergroup BIGINT,
	x1IxBrlyVCard INT,
	ixBrlyWUiaccess INT
);
ALTER TABLE TblBrlyAMUsergroupAccess OWNER TO epsi;
CREATE INDEX TblBrlyAMUsergroupAccess_refBrlyMUsergroup ON TblBrlyAMUsergroupAccess (refBrlyMUsergroup);
CREATE INDEX TblBrlyAMUsergroupAccess_x1IxBrlyVCard ON TblBrlyAMUsergroupAccess (x1IxBrlyVCard);

CREATE TABLE TblBrlyAVControlPar(
	ref BIGSERIAL PRIMARY KEY,
	ixBrlyVControl INT,
	x1RefBrlyMUser BIGINT,
	x2IxBrlyVLocale INT,
	Par VARCHAR(256),
	Val VARCHAR(256)
);
ALTER TABLE TblBrlyAVControlPar OWNER TO epsi;
CREATE INDEX TblBrlyAVControlPar_ixBrlyVControl ON TblBrlyAVControlPar (ixBrlyVControl);
CREATE INDEX TblBrlyAVControlPar_x1RefBrlyMUser ON TblBrlyAVControlPar (x1RefBrlyMUser);
CREATE INDEX TblBrlyAVControlPar_x2IxBrlyVLocale ON TblBrlyAVControlPar (x2IxBrlyVLocale);
CREATE INDEX TblBrlyAVControlPar_Par ON TblBrlyAVControlPar (Par);

CREATE TABLE TblBrlyAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	klsIxBrlyVKeylist INT,
	klsNum INT,
	x1IxBrlyVMaintable INT,
	x1Uref BIGINT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(1024),
	Implied VARCHAR(1024),
	refJ BIGINT,
	Title VARCHAR(256),
	Comment TEXT
);
ALTER TABLE TblBrlyAVKeylistKey OWNER TO epsi;
CREATE INDEX TblBrlyAVKeylistKey_klsIxBrlyVKeylist ON TblBrlyAVKeylistKey (klsIxBrlyVKeylist);
CREATE INDEX TblBrlyAVKeylistKey_klsNum ON TblBrlyAVKeylistKey (klsNum);
CREATE INDEX TblBrlyAVKeylistKey_x1IxBrlyVMaintable ON TblBrlyAVKeylistKey (x1IxBrlyVMaintable);
CREATE INDEX TblBrlyAVKeylistKey_x1Uref ON TblBrlyAVKeylistKey (x1Uref);
CREATE INDEX TblBrlyAVKeylistKey_sref ON TblBrlyAVKeylistKey (sref);

CREATE TABLE TblBrlyAVValuelistVal(
	ref BIGSERIAL PRIMARY KEY,
	vlsIxBrlyVValuelist INT,
	vlsNum INT,
	x1IxBrlyVLocale INT,
	Val VARCHAR(256)
);
ALTER TABLE TblBrlyAVValuelistVal OWNER TO epsi;
CREATE INDEX TblBrlyAVValuelistVal_vlsIxBrlyVValuelist ON TblBrlyAVValuelistVal (vlsIxBrlyVValuelist);
CREATE INDEX TblBrlyAVValuelistVal_vlsNum ON TblBrlyAVValuelistVal (vlsNum);
CREATE INDEX TblBrlyAVValuelistVal_x1IxBrlyVLocale ON TblBrlyAVValuelistVal (x1IxBrlyVLocale);

CREATE SEQUENCE TblBrlyCFile INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblBrlyCFile OWNER TO epsi;

CREATE SEQUENCE TblBrlyCLeg INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblBrlyCLeg OWNER TO epsi;

CREATE TABLE TblBrlyHistRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMUser BIGINT,
	unvIxBrlyVMaintable INT,
	unvUref BIGINT,
	ixBrlyVCard INT,
	ixBrlyVPreset INT,
	preIxBrlyVMaintable INT,
	preUref BIGINT,
	start INT
);
ALTER TABLE TblBrlyHistRMUserUniversal OWNER TO epsi;
CREATE INDEX TblBrlyHistRMUserUniversal_refBrlyMUser ON TblBrlyHistRMUserUniversal (refBrlyMUser);
CREATE INDEX TblBrlyHistRMUserUniversal_unvIxBrlyVMaintable ON TblBrlyHistRMUserUniversal (unvIxBrlyVMaintable);
CREATE INDEX TblBrlyHistRMUserUniversal_unvUref ON TblBrlyHistRMUserUniversal (unvUref);
CREATE INDEX TblBrlyHistRMUserUniversal_ixBrlyVCard ON TblBrlyHistRMUserUniversal (ixBrlyVCard);
CREATE INDEX TblBrlyHistRMUserUniversal_ixBrlyVPreset ON TblBrlyHistRMUserUniversal (ixBrlyVPreset);
CREATE INDEX TblBrlyHistRMUserUniversal_preIxBrlyVMaintable ON TblBrlyHistRMUserUniversal (preIxBrlyVMaintable);
CREATE INDEX TblBrlyHistRMUserUniversal_preUref ON TblBrlyHistRMUserUniversal (preUref);

CREATE TABLE TblBrlyJAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyAVKeylistKey BIGINT,
	x1IxBrlyVLocale INT,
	Title VARCHAR(256),
	Comment TEXT
);
ALTER TABLE TblBrlyJAVKeylistKey OWNER TO epsi;
CREATE INDEX TblBrlyJAVKeylistKey_refBrlyAVKeylistKey ON TblBrlyJAVKeylistKey (refBrlyAVKeylistKey);
CREATE INDEX TblBrlyJAVKeylistKey_x1IxBrlyVLocale ON TblBrlyJAVKeylistKey (x1IxBrlyVLocale);

CREATE TABLE TblBrlyJMPersonLastname(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
ALTER TABLE TblBrlyJMPersonLastname OWNER TO epsi;
CREATE INDEX TblBrlyJMPersonLastname_refBrlyMPerson ON TblBrlyJMPersonLastname (refBrlyMPerson);
CREATE INDEX TblBrlyJMPersonLastname_x1Startd ON TblBrlyJMPersonLastname (x1Startd);
CREATE INDEX TblBrlyJMPersonLastname_Lastname ON TblBrlyJMPersonLastname (Lastname);

CREATE TABLE TblBrlyJMRegion(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMRegion BIGINT,
	x1Startd INT,
	x1Stopd INT,
	ixVDst INT,
	toffset DOUBLE PRECISION
);
ALTER TABLE TblBrlyJMRegion OWNER TO epsi;
CREATE INDEX TblBrlyJMRegion_refBrlyMRegion ON TblBrlyJMRegion (refBrlyMRegion);
CREATE INDEX TblBrlyJMRegion_x1Startd ON TblBrlyJMRegion (x1Startd);
CREATE INDEX TblBrlyJMRegion_x1Stopd ON TblBrlyJMRegion (x1Stopd);

CREATE TABLE TblBrlyJMRegionTitle(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMRegion BIGINT,
	x1IxBrlyVLocale INT,
	Title VARCHAR(50)
);
ALTER TABLE TblBrlyJMRegionTitle OWNER TO epsi;
CREATE INDEX TblBrlyJMRegionTitle_refBrlyMRegion ON TblBrlyJMRegionTitle (refBrlyMRegion);
CREATE INDEX TblBrlyJMRegionTitle_x1IxBrlyVLocale ON TblBrlyJMRegionTitle (x1IxBrlyVLocale);
CREATE INDEX TblBrlyJMRegionTitle_Title ON TblBrlyJMRegionTitle (Title);

CREATE TABLE TblBrlyJMUserState(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMUser BIGINT,
	x1Startd INT,
	ixVState INT
);
ALTER TABLE TblBrlyJMUserState OWNER TO epsi;
CREATE INDEX TblBrlyJMUserState_refBrlyMUser ON TblBrlyJMUserState (refBrlyMUser);
CREATE INDEX TblBrlyJMUserState_x1Startd ON TblBrlyJMUserState (x1Startd);

CREATE TABLE TblBrlyLRMConnectionMEquipment(
	ref BIGSERIAL PRIMARY KEY,
	conIxBrlyVLat INT,
	conRefBrlyMConnection BIGINT,
	conNum INT,
	refBrlyMEquipment BIGINT
);
ALTER TABLE TblBrlyLRMConnectionMEquipment OWNER TO epsi;
CREATE INDEX TblBrlyLRMConnectionMEquipment_conIxBrlyVLat ON TblBrlyLRMConnectionMEquipment (conIxBrlyVLat);
CREATE INDEX TblBrlyLRMConnectionMEquipment_conRefBrlyMConnection ON TblBrlyLRMConnectionMEquipment (conRefBrlyMConnection);
CREATE INDEX TblBrlyLRMConnectionMEquipment_conNum ON TblBrlyLRMConnectionMEquipment (conNum);
CREATE INDEX TblBrlyLRMConnectionMEquipment_refBrlyMEquipment ON TblBrlyLRMConnectionMEquipment (refBrlyMEquipment);

CREATE TABLE TblBrlyMConnection(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refBrlyMFlight BIGINT,
	corRefBrlyMLeg BIGINT,
	start INT,
	stop INT,
	ixVModel INT,
	refBrlyMTimetable BIGINT,
	srefsBrlyKEqptype VARCHAR(256)
);
ALTER TABLE TblBrlyMConnection OWNER TO epsi;
CREATE INDEX TblBrlyMConnection_grp ON TblBrlyMConnection (grp);
CREATE INDEX TblBrlyMConnection_own ON TblBrlyMConnection (own);
CREATE INDEX TblBrlyMConnection_refBrlyMFlight ON TblBrlyMConnection (refBrlyMFlight);
CREATE INDEX TblBrlyMConnection_corRefBrlyMLeg ON TblBrlyMConnection (corRefBrlyMLeg);
CREATE INDEX TblBrlyMConnection_start ON TblBrlyMConnection (start);

CREATE TABLE TblBrlyMEquipment(
	ref BIGSERIAL PRIMARY KEY,
	hkIxVTbl INT,
	hkUref BIGINT,
	refBrlyMOperator BIGINT,
	refBrlyMPlntype BIGINT,
	srefBrlyKEqptype VARCHAR(50),
	Fiber SMALLINT
);
ALTER TABLE TblBrlyMEquipment OWNER TO epsi;
CREATE INDEX TblBrlyMEquipment_hkIxVTbl ON TblBrlyMEquipment (hkIxVTbl);
CREATE INDEX TblBrlyMEquipment_hkUref ON TblBrlyMEquipment (hkUref);
CREATE INDEX TblBrlyMEquipment_refBrlyMOperator ON TblBrlyMEquipment (refBrlyMOperator);
CREATE INDEX TblBrlyMEquipment_refBrlyMPlntype ON TblBrlyMEquipment (refBrlyMPlntype);

CREATE TABLE TblBrlyMFaflight(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMFlight BIGINT,
	faFlightID VARCHAR(50),
	ident VARCHAR(10),
	aircrafttype VARCHAR(5),
	filed_ete VARCHAR(10),
	filed_time INT,
	filed_departuretime INT,
	filed_airspeed_kts SMALLINT,
	filed_airspeed_mach DOUBLE PRECISION,
	filed_altitude SMALLINT,
	route TEXT,
	actualdeparturetime INT,
	estimatedarrivaltime INT,
	actualarrivaltime INT,
	diverted VARCHAR(5),
	origin VARCHAR(5),
	destination VARCHAR(5),
	originName VARCHAR(50),
	originCity VARCHAR(50),
	destinationName VARCHAR(50),
	destinationCity VARCHAR(50)
);
ALTER TABLE TblBrlyMFaflight OWNER TO epsi;
CREATE INDEX TblBrlyMFaflight_refBrlyMFlight ON TblBrlyMFaflight (refBrlyMFlight);
CREATE INDEX TblBrlyMFaflight_faFlightID ON TblBrlyMFaflight (faFlightID);
CREATE INDEX TblBrlyMFaflight_ident ON TblBrlyMFaflight (ident);
CREATE INDEX TblBrlyMFaflight_filed_departuretime ON TblBrlyMFaflight (filed_departuretime);

CREATE TABLE TblBrlyMFile(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refBrlyCFile BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	Archived INT,
	Filename VARCHAR(50),
	Archivename VARCHAR(30),
	srefKMimetype VARCHAR(50),
	Size SMALLINT,
	Comment TEXT
);
ALTER TABLE TblBrlyMFile OWNER TO epsi;
CREATE INDEX TblBrlyMFile_grp ON TblBrlyMFile (grp);
CREATE INDEX TblBrlyMFile_own ON TblBrlyMFile (own);
CREATE INDEX TblBrlyMFile_refBrlyCFile ON TblBrlyMFile (refBrlyCFile);
CREATE INDEX TblBrlyMFile_refIxVTbl ON TblBrlyMFile (refIxVTbl);
CREATE INDEX TblBrlyMFile_refUref ON TblBrlyMFile (refUref);
CREATE INDEX TblBrlyMFile_Filename ON TblBrlyMFile (Filename);

CREATE TABLE TblBrlyMFlight(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMTimetable BIGINT,
	refBrlyMEquipment BIGINT,
	refBrlyMFaflight BIGINT,
	refBrlyMLeg BIGINT,
	sref VARCHAR(50),
	start INT,
	stop INT,
	xStart INT,
	xStop INT,
	Calcdone SMALLINT,
	Segdone SMALLINT
);
ALTER TABLE TblBrlyMFlight OWNER TO epsi;
CREATE INDEX TblBrlyMFlight_refBrlyMTimetable ON TblBrlyMFlight (refBrlyMTimetable);
CREATE INDEX TblBrlyMFlight_refBrlyMEquipment ON TblBrlyMFlight (refBrlyMEquipment);
CREATE INDEX TblBrlyMFlight_refBrlyMFaflight ON TblBrlyMFlight (refBrlyMFaflight);
CREATE INDEX TblBrlyMFlight_refBrlyMLeg ON TblBrlyMFlight (refBrlyMLeg);
CREATE INDEX TblBrlyMFlight_sref ON TblBrlyMFlight (sref);
CREATE INDEX TblBrlyMFlight_start ON TblBrlyMFlight (start);
CREATE INDEX TblBrlyMFlight_stop ON TblBrlyMFlight (stop);
CREATE INDEX TblBrlyMFlight_Calcdone ON TblBrlyMFlight (Calcdone);
CREATE INDEX TblBrlyMFlight_Segdone ON TblBrlyMFlight (Segdone);

CREATE TABLE TblBrlyMLeg(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixVBasetype INT,
	refBrlyCLeg BIGINT,
	bgnRefBrlyMLocation BIGINT,
	endRefBrlyMLocation BIGINT,
	alt DOUBLE PRECISION,
	deltaphi DOUBLE PRECISION,
	alpha DOUBLE PRECISION,
	xAlt DOUBLE PRECISION,
	xPhi0 DOUBLE PRECISION,
	xPhi1 DOUBLE PRECISION,
	xAlpha DOUBLE PRECISION,
	Calcdone SMALLINT
);
ALTER TABLE TblBrlyMLeg OWNER TO epsi;
CREATE INDEX TblBrlyMLeg_grp ON TblBrlyMLeg (grp);
CREATE INDEX TblBrlyMLeg_own ON TblBrlyMLeg (own);
CREATE INDEX TblBrlyMLeg_ixVBasetype ON TblBrlyMLeg (ixVBasetype);
CREATE INDEX TblBrlyMLeg_refBrlyCLeg ON TblBrlyMLeg (refBrlyCLeg);
CREATE INDEX TblBrlyMLeg_bgnRefBrlyMLocation ON TblBrlyMLeg (bgnRefBrlyMLocation);
CREATE INDEX TblBrlyMLeg_endRefBrlyMLocation ON TblBrlyMLeg (endRefBrlyMLocation);
CREATE INDEX TblBrlyMLeg_Calcdone ON TblBrlyMLeg (Calcdone);

CREATE TABLE TblBrlyMLocation(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	refBrlyMRegion BIGINT,
	refBrlyMEquipment BIGINT,
	sref VARCHAR(50),
	srefICAO VARCHAR(5),
	Title VARCHAR(50),
	alt DOUBLE PRECISION,
	theta DOUBLE PRECISION,
	phi DOUBLE PRECISION,
	tz VARCHAR(50),
	alpha DOUBLE PRECISION,
	Calcdone SMALLINT
);
ALTER TABLE TblBrlyMLocation OWNER TO epsi;
CREATE INDEX TblBrlyMLocation_ixVBasetype ON TblBrlyMLocation (ixVBasetype);
CREATE INDEX TblBrlyMLocation_refBrlyMRegion ON TblBrlyMLocation (refBrlyMRegion);
CREATE INDEX TblBrlyMLocation_refBrlyMEquipment ON TblBrlyMLocation (refBrlyMEquipment);
CREATE INDEX TblBrlyMLocation_sref ON TblBrlyMLocation (sref);
CREATE INDEX TblBrlyMLocation_srefICAO ON TblBrlyMLocation (srefICAO);
CREATE INDEX TblBrlyMLocation_Title ON TblBrlyMLocation (Title);
CREATE INDEX TblBrlyMLocation_Calcdone ON TblBrlyMLocation (Calcdone);

CREATE TABLE TblBrlyMNode(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMRelay BIGINT,
	supRefBrlyMNode BIGINT,
	supLvl SMALLINT,
	supNum INT,
	refBrlyMEquipment BIGINT
);
ALTER TABLE TblBrlyMNode OWNER TO epsi;
CREATE INDEX TblBrlyMNode_refBrlyMRelay ON TblBrlyMNode (refBrlyMRelay);
CREATE INDEX TblBrlyMNode_supRefBrlyMNode ON TblBrlyMNode (supRefBrlyMNode);
CREATE INDEX TblBrlyMNode_supLvl ON TblBrlyMNode (supLvl);
CREATE INDEX TblBrlyMNode_supNum ON TblBrlyMNode (supNum);
CREATE INDEX TblBrlyMNode_refBrlyMEquipment ON TblBrlyMNode (refBrlyMEquipment);

CREATE TABLE TblBrlyMOperator(
	ref BIGSERIAL PRIMARY KEY,
	sref VARCHAR(50),
	srefICAO VARCHAR(5),
	Title VARCHAR(50)
);
ALTER TABLE TblBrlyMOperator OWNER TO epsi;
CREATE INDEX TblBrlyMOperator_sref ON TblBrlyMOperator (sref);
CREATE INDEX TblBrlyMOperator_srefICAO ON TblBrlyMOperator (srefICAO);
CREATE INDEX TblBrlyMOperator_Title ON TblBrlyMOperator (Title);

CREATE TABLE TblBrlyMPerson(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixWDerivate INT,
	ixVSex INT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT,
	Lastname VARCHAR(50),
	telRefADetail BIGINT,
	telVal VARCHAR(256),
	emlRefADetail BIGINT,
	emlVal VARCHAR(256),
	Salutation VARCHAR(100)
);
ALTER TABLE TblBrlyMPerson OWNER TO epsi;
CREATE INDEX TblBrlyMPerson_grp ON TblBrlyMPerson (grp);
CREATE INDEX TblBrlyMPerson_own ON TblBrlyMPerson (own);
CREATE INDEX TblBrlyMPerson_ixWDerivate ON TblBrlyMPerson (ixWDerivate);
CREATE INDEX TblBrlyMPerson_Lastname ON TblBrlyMPerson (Lastname);

CREATE TABLE TblBrlyMPlntype(
	ref BIGSERIAL PRIMARY KEY,
	sref VARCHAR(50),
	Title VARCHAR(50),
	srefBrlyKEqptype VARCHAR(50),
	Capacity SMALLINT
);
ALTER TABLE TblBrlyMPlntype OWNER TO epsi;
CREATE INDEX TblBrlyMPlntype_sref ON TblBrlyMPlntype (sref);
CREATE INDEX TblBrlyMPlntype_Title ON TblBrlyMPlntype (Title);

CREATE TABLE TblBrlyMRegion(
	ref BIGSERIAL PRIMARY KEY,
	supRefBrlyMRegion BIGINT,
	supLvl SMALLINT,
	sref VARCHAR(50),
	refJTitle BIGINT,
	Title VARCHAR(50),
	refJ BIGINT,
	ixVDst INT,
	toffset DOUBLE PRECISION
);
ALTER TABLE TblBrlyMRegion OWNER TO epsi;
CREATE INDEX TblBrlyMRegion_supRefBrlyMRegion ON TblBrlyMRegion (supRefBrlyMRegion);
CREATE INDEX TblBrlyMRegion_supLvl ON TblBrlyMRegion (supLvl);
CREATE INDEX TblBrlyMRegion_sref ON TblBrlyMRegion (sref);
CREATE INDEX TblBrlyMRegion_Title ON TblBrlyMRegion (Title);

CREATE TABLE TblBrlyMRelay(
	ref BIGSERIAL PRIMARY KEY,
	x1Start INT,
	x1Stop INT,
	refBrlyMConnection BIGINT,
	ixVDir INT,
	Connected SMALLINT,
	Nhop SMALLINT
);
ALTER TABLE TblBrlyMRelay OWNER TO epsi;
CREATE INDEX TblBrlyMRelay_x1Start ON TblBrlyMRelay (x1Start);
CREATE INDEX TblBrlyMRelay_x1Stop ON TblBrlyMRelay (x1Stop);
CREATE INDEX TblBrlyMRelay_refBrlyMConnection ON TblBrlyMRelay (refBrlyMConnection);
CREATE INDEX TblBrlyMRelay_ixVDir ON TblBrlyMRelay (ixVDir);

CREATE TABLE TblBrlyMSegment(
	ref BIGSERIAL PRIMARY KEY,
	refIxVTbl INT,
	refUref BIGINT,
	refNum INT,
	deltaphi DOUBLE PRECISION,
	alt0 DOUBLE PRECISION,
	alt1 DOUBLE PRECISION,
	theta0 DOUBLE PRECISION,
	theta1 DOUBLE PRECISION,
	phi0 DOUBLE PRECISION,
	phi1 DOUBLE PRECISION,
	start INT,
	stop INT,
	Calcdone SMALLINT
);
ALTER TABLE TblBrlyMSegment OWNER TO epsi;
CREATE INDEX TblBrlyMSegment_refIxVTbl ON TblBrlyMSegment (refIxVTbl);
CREATE INDEX TblBrlyMSegment_refUref ON TblBrlyMSegment (refUref);
CREATE INDEX TblBrlyMSegment_refNum ON TblBrlyMSegment (refNum);
CREATE INDEX TblBrlyMSegment_start ON TblBrlyMSegment (start);
CREATE INDEX TblBrlyMSegment_stop ON TblBrlyMSegment (stop);
CREATE INDEX TblBrlyMSegment_Calcdone ON TblBrlyMSegment (Calcdone);

CREATE TABLE TblBrlyMSession(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
ALTER TABLE TblBrlyMSession OWNER TO epsi;
CREATE INDEX TblBrlyMSession_refBrlyMUser ON TblBrlyMSession (refBrlyMUser);
CREATE INDEX TblBrlyMSession_start ON TblBrlyMSession (start);

CREATE TABLE TblBrlyMTimetable(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMFile BIGINT,
	srefBrlyKAlliance VARCHAR(50),
	Title VARCHAR(50),
	startd INT,
	stopd INT
);
ALTER TABLE TblBrlyMTimetable OWNER TO epsi;
CREATE INDEX TblBrlyMTimetable_refBrlyMFile ON TblBrlyMTimetable (refBrlyMFile);
CREATE INDEX TblBrlyMTimetable_Title ON TblBrlyMTimetable (Title);

CREATE TABLE TblBrlyMUser(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refRUsergroup BIGINT,
	refBrlyMUsergroup BIGINT,
	refBrlyMPerson BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	ixBrlyVLocale INT,
	ixBrlyVUserlevel INT,
	Password VARCHAR(30)
);
ALTER TABLE TblBrlyMUser OWNER TO epsi;
CREATE INDEX TblBrlyMUser_grp ON TblBrlyMUser (grp);
CREATE INDEX TblBrlyMUser_own ON TblBrlyMUser (own);
CREATE INDEX TblBrlyMUser_refBrlyMUsergroup ON TblBrlyMUser (refBrlyMUsergroup);
CREATE INDEX TblBrlyMUser_refBrlyMPerson ON TblBrlyMUser (refBrlyMPerson);
CREATE INDEX TblBrlyMUser_sref ON TblBrlyMUser (sref);
CREATE INDEX TblBrlyMUser_ixVState ON TblBrlyMUser (ixVState);

CREATE TABLE TblBrlyMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblBrlyMUsergroup OWNER TO epsi;
CREATE INDEX TblBrlyMUsergroup_grp ON TblBrlyMUsergroup (grp);
CREATE INDEX TblBrlyMUsergroup_own ON TblBrlyMUsergroup (own);
CREATE INDEX TblBrlyMUsergroup_sref ON TblBrlyMUsergroup (sref);

CREATE TABLE TblBrlyORMConnectionMEquipment(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMConnection BIGINT,
	x1Start INT,
	ixBrlyVOolop INT,
	pr1RefLR BIGINT,
	pr2RefLR BIGINT
);
ALTER TABLE TblBrlyORMConnectionMEquipment OWNER TO epsi;
CREATE INDEX TblBrlyORMConnectionMEquipment_refBrlyMConnection ON TblBrlyORMConnectionMEquipment (refBrlyMConnection);
CREATE INDEX TblBrlyORMConnectionMEquipment_x1Start ON TblBrlyORMConnectionMEquipment (x1Start);
CREATE INDEX TblBrlyORMConnectionMEquipment_ixBrlyVOolop ON TblBrlyORMConnectionMEquipment (ixBrlyVOolop);
CREATE INDEX TblBrlyORMConnectionMEquipment_pr1RefLR ON TblBrlyORMConnectionMEquipment (pr1RefLR);
CREATE INDEX TblBrlyORMConnectionMEquipment_pr2RefLR ON TblBrlyORMConnectionMEquipment (pr2RefLR);

CREATE TABLE TblBrlyProxRMLocationMLocation(
	ref BIGSERIAL PRIMARY KEY,
	dstRefBrlyMLocation BIGINT,
	orgRefBrlyMLocation BIGINT,
	deltaphi DOUBLE PRECISION
);
ALTER TABLE TblBrlyProxRMLocationMLocation OWNER TO epsi;
CREATE INDEX TblBrlyProxRMLocationMLocation_dstRefBrlyMLocation ON TblBrlyProxRMLocationMLocation (dstRefBrlyMLocation);
CREATE INDEX TblBrlyProxRMLocationMLocation_orgRefBrlyMLocation ON TblBrlyProxRMLocationMLocation (orgRefBrlyMLocation);
CREATE INDEX TblBrlyProxRMLocationMLocation_deltaphi ON TblBrlyProxRMLocationMLocation (deltaphi);

CREATE TABLE TblBrlyRMConnectionMFlight(
	ref BIGSERIAL PRIMARY KEY,
	x1Start INT,
	x1Stop INT,
	x2Legphi0 DOUBLE PRECISION,
	x2Legphi1 DOUBLE PRECISION,
	refBrlyMConnection BIGINT,
	refBrlyMFlight BIGINT
);
ALTER TABLE TblBrlyRMConnectionMFlight OWNER TO epsi;
CREATE INDEX TblBrlyRMConnectionMFlight_x1Start ON TblBrlyRMConnectionMFlight (x1Start);
CREATE INDEX TblBrlyRMConnectionMFlight_x1Stop ON TblBrlyRMConnectionMFlight (x1Stop);
CREATE INDEX TblBrlyRMConnectionMFlight_x2Legphi0 ON TblBrlyRMConnectionMFlight (x2Legphi0);
CREATE INDEX TblBrlyRMConnectionMFlight_x2Legphi1 ON TblBrlyRMConnectionMFlight (x2Legphi1);
CREATE INDEX TblBrlyRMConnectionMFlight_refBrlyMConnection ON TblBrlyRMConnectionMFlight (refBrlyMConnection);
CREATE INDEX TblBrlyRMConnectionMFlight_refBrlyMFlight ON TblBrlyRMConnectionMFlight (refBrlyMFlight);

CREATE TABLE TblBrlyRMConnectionMSegment(
	ref BIGSERIAL PRIMARY KEY,
	x1Start INT,
	x1Stop INT,
	x2Legphi0 DOUBLE PRECISION,
	x2Legphi1 DOUBLE PRECISION,
	refBrlyMConnection BIGINT,
	refBrlyMSegment BIGINT
);
ALTER TABLE TblBrlyRMConnectionMSegment OWNER TO epsi;
CREATE INDEX TblBrlyRMConnectionMSegment_x1Start ON TblBrlyRMConnectionMSegment (x1Start);
CREATE INDEX TblBrlyRMConnectionMSegment_x1Stop ON TblBrlyRMConnectionMSegment (x1Stop);
CREATE INDEX TblBrlyRMConnectionMSegment_x2Legphi0 ON TblBrlyRMConnectionMSegment (x2Legphi0);
CREATE INDEX TblBrlyRMConnectionMSegment_x2Legphi1 ON TblBrlyRMConnectionMSegment (x2Legphi1);
CREATE INDEX TblBrlyRMConnectionMSegment_refBrlyMConnection ON TblBrlyRMConnectionMSegment (refBrlyMConnection);
CREATE INDEX TblBrlyRMConnectionMSegment_refBrlyMSegment ON TblBrlyRMConnectionMSegment (refBrlyMSegment);

CREATE TABLE TblBrlyRMFlightMFlight(
	ref BIGSERIAL PRIMARY KEY,
	x1VisStart INT,
	x1VisStop INT,
	dstRefBrlyMFlight BIGINT,
	orgRefBrlyMFlight BIGINT,
	xVisStart INT,
	xVisStop INT
);
ALTER TABLE TblBrlyRMFlightMFlight OWNER TO epsi;
CREATE INDEX TblBrlyRMFlightMFlight_x1VisStart ON TblBrlyRMFlightMFlight (x1VisStart);
CREATE INDEX TblBrlyRMFlightMFlight_x1VisStop ON TblBrlyRMFlightMFlight (x1VisStop);
CREATE INDEX TblBrlyRMFlightMFlight_dstRefBrlyMFlight ON TblBrlyRMFlightMFlight (dstRefBrlyMFlight);
CREATE INDEX TblBrlyRMFlightMFlight_orgRefBrlyMFlight ON TblBrlyRMFlightMFlight (orgRefBrlyMFlight);

CREATE TABLE TblBrlyRMFlightMLocation(
	ref BIGSERIAL PRIMARY KEY,
	x1VisStart INT,
	x1VisStop INT,
	refBrlyMFlight BIGINT,
	refBrlyMLocation BIGINT,
	xVisStart INT,
	xVisStop INT
);
ALTER TABLE TblBrlyRMFlightMLocation OWNER TO epsi;
CREATE INDEX TblBrlyRMFlightMLocation_x1VisStart ON TblBrlyRMFlightMLocation (x1VisStart);
CREATE INDEX TblBrlyRMFlightMLocation_x1VisStop ON TblBrlyRMFlightMLocation (x1VisStop);
CREATE INDEX TblBrlyRMFlightMLocation_refBrlyMFlight ON TblBrlyRMFlightMLocation (refBrlyMFlight);
CREATE INDEX TblBrlyRMFlightMLocation_refBrlyMLocation ON TblBrlyRMFlightMLocation (refBrlyMLocation);

CREATE TABLE TblBrlyRMLegMLeg(
	ref BIGSERIAL PRIMARY KEY,
	x1VisDstLegphi0 DOUBLE PRECISION,
	x1VisDstLegphi1 DOUBLE PRECISION,
	dstRefBrlyMLeg BIGINT,
	orgRefBrlyMLeg BIGINT,
	VisOrgLegphi0 DOUBLE PRECISION,
	VisOrgLegphi1 DOUBLE PRECISION,
	xVisDstLegphi0 DOUBLE PRECISION,
	xVisDstLegphi1 DOUBLE PRECISION,
	xVisOrgLegphi0 DOUBLE PRECISION,
	xVisOrgLegphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyRMLegMLeg OWNER TO epsi;
CREATE INDEX TblBrlyRMLegMLeg_x1VisDstLegphi0 ON TblBrlyRMLegMLeg (x1VisDstLegphi0);
CREATE INDEX TblBrlyRMLegMLeg_x1VisDstLegphi1 ON TblBrlyRMLegMLeg (x1VisDstLegphi1);
CREATE INDEX TblBrlyRMLegMLeg_dstRefBrlyMLeg ON TblBrlyRMLegMLeg (dstRefBrlyMLeg);
CREATE INDEX TblBrlyRMLegMLeg_orgRefBrlyMLeg ON TblBrlyRMLegMLeg (orgRefBrlyMLeg);

CREATE TABLE TblBrlyRMLegMLocation(
	ref BIGSERIAL PRIMARY KEY,
	x1VisLegphi0 DOUBLE PRECISION,
	x1VisLegphi1 DOUBLE PRECISION,
	refBrlyMLeg BIGINT,
	refBrlyMLocation BIGINT,
	legphi DOUBLE PRECISION,
	legtheta DOUBLE PRECISION,
	xVisLegphi0 DOUBLE PRECISION,
	xVisLegphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyRMLegMLocation OWNER TO epsi;
CREATE INDEX TblBrlyRMLegMLocation_x1VisLegphi0 ON TblBrlyRMLegMLocation (x1VisLegphi0);
CREATE INDEX TblBrlyRMLegMLocation_x1VisLegphi1 ON TblBrlyRMLegMLocation (x1VisLegphi1);
CREATE INDEX TblBrlyRMLegMLocation_refBrlyMLeg ON TblBrlyRMLegMLocation (refBrlyMLeg);
CREATE INDEX TblBrlyRMLegMLocation_refBrlyMLocation ON TblBrlyRMLegMLocation (refBrlyMLocation);
CREATE INDEX TblBrlyRMLegMLocation_legphi ON TblBrlyRMLegMLocation (legphi);

CREATE TABLE TblBrlyRMLocationMSegment(
	ref BIGSERIAL PRIMARY KEY,
	x1Start INT,
	x1Stop INT,
	x2VisSegphi0 DOUBLE PRECISION,
	x2VisSegphi1 DOUBLE PRECISION,
	refBrlyMLocation BIGINT,
	refBrlyMSegment BIGINT,
	segphi DOUBLE PRECISION,
	segtheta DOUBLE PRECISION
);
ALTER TABLE TblBrlyRMLocationMSegment OWNER TO epsi;
CREATE INDEX TblBrlyRMLocationMSegment_x1Start ON TblBrlyRMLocationMSegment (x1Start);
CREATE INDEX TblBrlyRMLocationMSegment_x1Stop ON TblBrlyRMLocationMSegment (x1Stop);
CREATE INDEX TblBrlyRMLocationMSegment_x2VisSegphi0 ON TblBrlyRMLocationMSegment (x2VisSegphi0);
CREATE INDEX TblBrlyRMLocationMSegment_x2VisSegphi1 ON TblBrlyRMLocationMSegment (x2VisSegphi1);
CREATE INDEX TblBrlyRMLocationMSegment_refBrlyMLocation ON TblBrlyRMLocationMSegment (refBrlyMLocation);
CREATE INDEX TblBrlyRMLocationMSegment_refBrlyMSegment ON TblBrlyRMLocationMSegment (refBrlyMSegment);
CREATE INDEX TblBrlyRMLocationMSegment_segphi ON TblBrlyRMLocationMSegment (segphi);

CREATE TABLE TblBrlyRMSegmentMSegment(
	ref BIGSERIAL PRIMARY KEY,
	x1Start INT,
	x1Stop INT,
	x2VisDstSegphi0 DOUBLE PRECISION,
	x2VisDstSegphi1 DOUBLE PRECISION,
	dstRefBrlyMSegment BIGINT,
	orgRefBrlyMSegment BIGINT,
	VisOrgSegphi0 DOUBLE PRECISION,
	VisOrgSegphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyRMSegmentMSegment OWNER TO epsi;
CREATE INDEX TblBrlyRMSegmentMSegment_x1Start ON TblBrlyRMSegmentMSegment (x1Start);
CREATE INDEX TblBrlyRMSegmentMSegment_x1Stop ON TblBrlyRMSegmentMSegment (x1Stop);
CREATE INDEX TblBrlyRMSegmentMSegment_x2VisDstSegphi0 ON TblBrlyRMSegmentMSegment (x2VisDstSegphi0);
CREATE INDEX TblBrlyRMSegmentMSegment_x2VisDstSegphi1 ON TblBrlyRMSegmentMSegment (x2VisDstSegphi1);
CREATE INDEX TblBrlyRMSegmentMSegment_dstRefBrlyMSegment ON TblBrlyRMSegmentMSegment (dstRefBrlyMSegment);
CREATE INDEX TblBrlyRMSegmentMSegment_orgRefBrlyMSegment ON TblBrlyRMSegmentMSegment (orgRefBrlyMSegment);

CREATE TABLE TblBrlyRMUsergroupUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMUsergroup BIGINT,
	unvIxBrlyVMaintable INT,
	unvUref BIGINT,
	ixBrlyVAccess INT
);
ALTER TABLE TblBrlyRMUsergroupUniversal OWNER TO epsi;
CREATE INDEX TblBrlyRMUsergroupUniversal_refBrlyMUsergroup ON TblBrlyRMUsergroupUniversal (refBrlyMUsergroup);
CREATE INDEX TblBrlyRMUsergroupUniversal_unvIxBrlyVMaintable ON TblBrlyRMUsergroupUniversal (unvIxBrlyVMaintable);
CREATE INDEX TblBrlyRMUsergroupUniversal_unvUref ON TblBrlyRMUsergroupUniversal (unvUref);

CREATE TABLE TblBrlyRMUserMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	refBrlyMUser BIGINT,
	refBrlyMUsergroup BIGINT,
	ixBrlyVUserlevel INT
);
ALTER TABLE TblBrlyRMUserMUsergroup OWNER TO epsi;
CREATE INDEX TblBrlyRMUserMUsergroup_refBrlyMUser ON TblBrlyRMUserMUsergroup (refBrlyMUser);
CREATE INDEX TblBrlyRMUserMUsergroup_refBrlyMUsergroup ON TblBrlyRMUserMUsergroup (refBrlyMUsergroup);

CREATE TABLE TblBrlyVisRMLocationMLocation(
	ref BIGSERIAL PRIMARY KEY,
	dstRefBrlyMLocation BIGINT,
	orgRefBrlyMLocation BIGINT
);
ALTER TABLE TblBrlyVisRMLocationMLocation OWNER TO epsi;
CREATE INDEX TblBrlyVisRMLocationMLocation_dstRefBrlyMLocation ON TblBrlyVisRMLocationMLocation (dstRefBrlyMLocation);
CREATE INDEX TblBrlyVisRMLocationMLocation_orgRefBrlyMLocation ON TblBrlyVisRMLocationMLocation (orgRefBrlyMLocation);

CREATE TABLE TblBrlyQCon1NRelay(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQCon1NRelay OWNER TO epsi;
CREATE INDEX TblBrlyQCon1NRelay_jref ON TblBrlyQCon1NRelay (jref);
CREATE INDEX TblBrlyQCon1NRelay_jnum ON TblBrlyQCon1NRelay (jnum);

CREATE TABLE TblBrlyQConConMNEquipment(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	conIxBrlyVLat INT,
	conNum INT
);
ALTER TABLE TblBrlyQConConMNEquipment OWNER TO epsi;
CREATE INDEX TblBrlyQConConMNEquipment_jref ON TblBrlyQConConMNEquipment (jref);
CREATE INDEX TblBrlyQConConMNEquipment_jnum ON TblBrlyQConConMNEquipment (jnum);

CREATE TABLE TblBrlyQConList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refBrlyMFlight BIGINT,
	corRefBrlyMLeg BIGINT,
	start INT,
	stop INT,
	ixVModel INT
);
ALTER TABLE TblBrlyQConList OWNER TO epsi;
CREATE INDEX TblBrlyQConList_jref ON TblBrlyQConList (jref);
CREATE INDEX TblBrlyQConList_jnum ON TblBrlyQConList (jnum);

CREATE TABLE TblBrlyQConMapFlight(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	x2Legphi0 DOUBLE PRECISION,
	x2Legphi1 DOUBLE PRECISION,
	mref BIGINT,
	mrefBrlyMEquipment BIGINT,
	mrefBrlyMLeg BIGINT,
	mstart INT,
	mstop INT,
	x0 DOUBLE PRECISION,
	y0 DOUBLE PRECISION,
	t0 INT,
	dx DOUBLE PRECISION,
	dy DOUBLE PRECISION,
	dt INT
);
ALTER TABLE TblBrlyQConMapFlight OWNER TO epsi;
CREATE INDEX TblBrlyQConMapFlight_jref ON TblBrlyQConMapFlight (jref);
CREATE INDEX TblBrlyQConMapFlight_jnum ON TblBrlyQConMapFlight (jnum);

CREATE TABLE TblBrlyQConMapLeg(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	VisOrgLegphi0 DOUBLE PRECISION,
	VisOrgLegphi1 DOUBLE PRECISION,
	mref BIGINT,
	mbgnRefBrlyMLocation BIGINT,
	mendRefBrlyMLocation BIGINT,
	mdeltaphi DOUBLE PRECISION,
	dx DOUBLE PRECISION,
	dy DOUBLE PRECISION,
	x0 DOUBLE PRECISION,
	y0 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQConMapLeg OWNER TO epsi;
CREATE INDEX TblBrlyQConMapLeg_jref ON TblBrlyQConMapLeg (jref);
CREATE INDEX TblBrlyQConMapLeg_jnum ON TblBrlyQConMapLeg (jnum);

CREATE TABLE TblBrlyQConMapLocation(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	legphi DOUBLE PRECISION,
	legtheta DOUBLE PRECISION,
	mref BIGINT,
	mrefBrlyMEquipment BIGINT,
	x DOUBLE PRECISION,
	y DOUBLE PRECISION
);
ALTER TABLE TblBrlyQConMapLocation OWNER TO epsi;
CREATE INDEX TblBrlyQConMapLocation_jref ON TblBrlyQConMapLocation (jref);
CREATE INDEX TblBrlyQConMapLocation_jnum ON TblBrlyQConMapLocation (jnum);

CREATE TABLE TblBrlyQConMapNode(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refBrlyMRelay BIGINT,
	supRefBrlyMNode BIGINT,
	refBrlyMEquipment BIGINT,
	jnumRly INT,
	x0 DOUBLE PRECISION,
	y0 DOUBLE PRECISION,
	u0 DOUBLE PRECISION,
	v0 DOUBLE PRECISION,
	t0 INT,
	dx DOUBLE PRECISION,
	dy DOUBLE PRECISION,
	du DOUBLE PRECISION,
	dv DOUBLE PRECISION,
	dt INT
);
ALTER TABLE TblBrlyQConMapNode OWNER TO epsi;
CREATE INDEX TblBrlyQConMapNode_jref ON TblBrlyQConMapNode (jref);
CREATE INDEX TblBrlyQConMapNode_jnum ON TblBrlyQConMapNode (jnum);

CREATE TABLE TblBrlyQConMapRelay(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	ixVDir INT,
	Connected SMALLINT,
	Nhop SMALLINT
);
ALTER TABLE TblBrlyQConMapRelay OWNER TO epsi;
CREATE INDEX TblBrlyQConMapRelay_jref ON TblBrlyQConMapRelay (jref);
CREATE INDEX TblBrlyQConMapRelay_jnum ON TblBrlyQConMapRelay (jnum);

CREATE TABLE TblBrlyQConMNFlight(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	x2Legphi0 DOUBLE PRECISION,
	x2Legphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQConMNFlight OWNER TO epsi;
CREATE INDEX TblBrlyQConMNFlight_jref ON TblBrlyQConMNFlight (jref);
CREATE INDEX TblBrlyQConMNFlight_jnum ON TblBrlyQConMNFlight (jnum);

CREATE TABLE TblBrlyQConMNSegment(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	x2Legphi0 DOUBLE PRECISION,
	x2Legphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQConMNSegment OWNER TO epsi;
CREATE INDEX TblBrlyQConMNSegment_jref ON TblBrlyQConMNSegment (jref);
CREATE INDEX TblBrlyQConMNSegment_jnum ON TblBrlyQConMNSegment (jnum);

CREATE TABLE TblBrlyQConRef1NSegment(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refNum INT
);
ALTER TABLE TblBrlyQConRef1NSegment OWNER TO epsi;
CREATE INDEX TblBrlyQConRef1NSegment_jref ON TblBrlyQConRef1NSegment (jref);
CREATE INDEX TblBrlyQConRef1NSegment_jnum ON TblBrlyQConRef1NSegment (jnum);

CREATE TABLE TblBrlyQFilList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Filename VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	srefKMimetype VARCHAR(50),
	Size SMALLINT
);
ALTER TABLE TblBrlyQFilList OWNER TO epsi;
CREATE INDEX TblBrlyQFilList_jref ON TblBrlyQFilList (jref);
CREATE INDEX TblBrlyQFilList_jnum ON TblBrlyQFilList (jnum);

CREATE TABLE TblBrlyQFlt1NConnection(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQFlt1NConnection OWNER TO epsi;
CREATE INDEX TblBrlyQFlt1NConnection_jref ON TblBrlyQFlt1NConnection (jref);
CREATE INDEX TblBrlyQFlt1NConnection_jnum ON TblBrlyQFlt1NConnection (jnum);

CREATE TABLE TblBrlyQFltEqp1NNode(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQFltEqp1NNode OWNER TO epsi;
CREATE INDEX TblBrlyQFltEqp1NNode_jref ON TblBrlyQFltEqp1NNode (jref);
CREATE INDEX TblBrlyQFltEqp1NNode_jnum ON TblBrlyQFltEqp1NNode (jnum);

CREATE TABLE TblBrlyQFltEqpMNConnection(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	conIxBrlyVLat INT
);
ALTER TABLE TblBrlyQFltEqpMNConnection OWNER TO epsi;
CREATE INDEX TblBrlyQFltEqpMNConnection_jref ON TblBrlyQFltEqpMNConnection (jref);
CREATE INDEX TblBrlyQFltEqpMNConnection_jnum ON TblBrlyQFltEqpMNConnection (jnum);

CREATE TABLE TblBrlyQFltFafAWaypoint(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	fafNum INT,
	timestamp INT,
	latitude DOUBLE PRECISION,
	longitude DOUBLE PRECISION,
	groundspeed SMALLINT,
	altitude SMALLINT,
	altitudeStatus VARCHAR(5),
	updateType VARCHAR(5),
	altitudeChange VARCHAR(5)
);
ALTER TABLE TblBrlyQFltFafAWaypoint OWNER TO epsi;
CREATE INDEX TblBrlyQFltFafAWaypoint_jref ON TblBrlyQFltFafAWaypoint (jref);
CREATE INDEX TblBrlyQFltFafAWaypoint_jnum ON TblBrlyQFltFafAWaypoint (jnum);

CREATE TABLE TblBrlyQFltList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refBrlyMEquipment BIGINT,
	refBrlyMFaflight BIGINT,
	refBrlyMLeg BIGINT,
	start INT,
	stop INT
);
ALTER TABLE TblBrlyQFltList OWNER TO epsi;
CREATE INDEX TblBrlyQFltList_jref ON TblBrlyQFltList (jref);
CREATE INDEX TblBrlyQFltList_jnum ON TblBrlyQFltList (jnum);

CREATE TABLE TblBrlyQFltMNConnection(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	x2Legphi0 DOUBLE PRECISION,
	x2Legphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQFltMNConnection OWNER TO epsi;
CREATE INDEX TblBrlyQFltMNConnection_jref ON TblBrlyQFltMNConnection (jref);
CREATE INDEX TblBrlyQFltMNConnection_jnum ON TblBrlyQFltMNConnection (jnum);

CREATE TABLE TblBrlyQFltMNLocation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1VisStart INT,
	x1VisStop INT,
	xVisStart INT,
	xVisStop INT
);
ALTER TABLE TblBrlyQFltMNLocation OWNER TO epsi;
CREATE INDEX TblBrlyQFltMNLocation_jref ON TblBrlyQFltMNLocation (jref);
CREATE INDEX TblBrlyQFltMNLocation_jnum ON TblBrlyQFltMNLocation (jnum);

CREATE TABLE TblBrlyQFltOrgMNFlight(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1VisStart INT,
	x1VisStop INT,
	xVisStart INT,
	xVisStop INT
);
ALTER TABLE TblBrlyQFltOrgMNFlight OWNER TO epsi;
CREATE INDEX TblBrlyQFltOrgMNFlight_jref ON TblBrlyQFltOrgMNFlight (jref);
CREATE INDEX TblBrlyQFltOrgMNFlight_jnum ON TblBrlyQFltOrgMNFlight (jnum);

CREATE TABLE TblBrlyQFltRef1NSegment(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refNum INT
);
ALTER TABLE TblBrlyQFltRef1NSegment OWNER TO epsi;
CREATE INDEX TblBrlyQFltRef1NSegment_jref ON TblBrlyQFltRef1NSegment (jref);
CREATE INDEX TblBrlyQFltRef1NSegment_jnum ON TblBrlyQFltRef1NSegment (jnum);

CREATE TABLE TblBrlyQLeg1NFlight(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQLeg1NFlight OWNER TO epsi;
CREATE INDEX TblBrlyQLeg1NFlight_jref ON TblBrlyQLeg1NFlight (jref);
CREATE INDEX TblBrlyQLeg1NFlight_jnum ON TblBrlyQLeg1NFlight (jnum);

CREATE TABLE TblBrlyQLegCor1NConnection(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQLegCor1NConnection OWNER TO epsi;
CREATE INDEX TblBrlyQLegCor1NConnection_jref ON TblBrlyQLegCor1NConnection (jref);
CREATE INDEX TblBrlyQLegCor1NConnection_jnum ON TblBrlyQLegCor1NConnection (jnum);

CREATE TABLE TblBrlyQLegList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	bgnRefBrlyMLocation BIGINT,
	endRefBrlyMLocation BIGINT,
	ixVBasetype INT,
	alt DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLegList OWNER TO epsi;
CREATE INDEX TblBrlyQLegList_jref ON TblBrlyQLegList (jref);
CREATE INDEX TblBrlyQLegList_jnum ON TblBrlyQLegList (jnum);

CREATE TABLE TblBrlyQLegMapLeg(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	VisOrgLegphi0 DOUBLE PRECISION,
	VisOrgLegphi1 DOUBLE PRECISION,
	mref BIGINT,
	mbgnRefBrlyMLocation BIGINT,
	mendRefBrlyMLocation BIGINT,
	dx DOUBLE PRECISION,
	dy DOUBLE PRECISION,
	x0 DOUBLE PRECISION,
	y0 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLegMapLeg OWNER TO epsi;
CREATE INDEX TblBrlyQLegMapLeg_jref ON TblBrlyQLegMapLeg (jref);
CREATE INDEX TblBrlyQLegMapLeg_jnum ON TblBrlyQLegMapLeg (jnum);

CREATE TABLE TblBrlyQLegMapLocation(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	legphi DOUBLE PRECISION,
	legtheta DOUBLE PRECISION,
	mref BIGINT,
	x DOUBLE PRECISION,
	y DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLegMapLocation OWNER TO epsi;
CREATE INDEX TblBrlyQLegMapLocation_jref ON TblBrlyQLegMapLocation (jref);
CREATE INDEX TblBrlyQLegMapLocation_jnum ON TblBrlyQLegMapLocation (jnum);

CREATE TABLE TblBrlyQLegMNLocation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1VisLegphi0 DOUBLE PRECISION,
	x1VisLegphi1 DOUBLE PRECISION,
	legphi DOUBLE PRECISION,
	legtheta DOUBLE PRECISION,
	xVisLegphi0 DOUBLE PRECISION,
	xVisLegphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLegMNLocation OWNER TO epsi;
CREATE INDEX TblBrlyQLegMNLocation_jref ON TblBrlyQLegMNLocation (jref);
CREATE INDEX TblBrlyQLegMNLocation_jnum ON TblBrlyQLegMNLocation (jnum);

CREATE TABLE TblBrlyQLegOrgMNLeg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1VisDstLegphi0 DOUBLE PRECISION,
	x1VisDstLegphi1 DOUBLE PRECISION,
	VisOrgLegphi0 DOUBLE PRECISION,
	VisOrgLegphi1 DOUBLE PRECISION,
	xVisDstLegphi0 DOUBLE PRECISION,
	xVisDstLegphi1 DOUBLE PRECISION,
	xVisOrgLegphi0 DOUBLE PRECISION,
	xVisOrgLegphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLegOrgMNLeg OWNER TO epsi;
CREATE INDEX TblBrlyQLegOrgMNLeg_jref ON TblBrlyQLegOrgMNLeg (jref);
CREATE INDEX TblBrlyQLegOrgMNLeg_jnum ON TblBrlyQLegOrgMNLeg (jnum);

CREATE TABLE TblBrlyQLocBgn1NLeg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQLocBgn1NLeg OWNER TO epsi;
CREATE INDEX TblBrlyQLocBgn1NLeg_jref ON TblBrlyQLocBgn1NLeg (jref);
CREATE INDEX TblBrlyQLocBgn1NLeg_jnum ON TblBrlyQLocBgn1NLeg (jnum);

CREATE TABLE TblBrlyQLocEnd1NLeg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQLocEnd1NLeg OWNER TO epsi;
CREATE INDEX TblBrlyQLocEnd1NLeg_jref ON TblBrlyQLocEnd1NLeg (jref);
CREATE INDEX TblBrlyQLocEnd1NLeg_jnum ON TblBrlyQLocEnd1NLeg (jnum);

CREATE TABLE TblBrlyQLocEqp1NNode(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQLocEqp1NNode OWNER TO epsi;
CREATE INDEX TblBrlyQLocEqp1NNode_jref ON TblBrlyQLocEqp1NNode (jref);
CREATE INDEX TblBrlyQLocEqp1NNode_jnum ON TblBrlyQLocEqp1NNode (jnum);

CREATE TABLE TblBrlyQLocEqpMNConnection(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	conIxBrlyVLat INT
);
ALTER TABLE TblBrlyQLocEqpMNConnection OWNER TO epsi;
CREATE INDEX TblBrlyQLocEqpMNConnection_jref ON TblBrlyQLocEqpMNConnection (jref);
CREATE INDEX TblBrlyQLocEqpMNConnection_jnum ON TblBrlyQLocEqpMNConnection (jnum);

CREATE TABLE TblBrlyQLocList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	srefICAO VARCHAR(5),
	Title VARCHAR(50),
	ixVBasetype INT,
	refBrlyMRegion BIGINT,
	refBrlyMEquipment BIGINT,
	alt DOUBLE PRECISION,
	theta DOUBLE PRECISION,
	phi DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLocList OWNER TO epsi;
CREATE INDEX TblBrlyQLocList_jref ON TblBrlyQLocList (jref);
CREATE INDEX TblBrlyQLocList_jnum ON TblBrlyQLocList (jnum);

CREATE TABLE TblBrlyQLocMapLeg(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1VisLegphi0 DOUBLE PRECISION,
	x1VisLegphi1 DOUBLE PRECISION,
	mref BIGINT,
	mbgnRefBrlyMLocation BIGINT,
	mendRefBrlyMLocation BIGINT,
	dx DOUBLE PRECISION,
	dy DOUBLE PRECISION,
	x0 DOUBLE PRECISION,
	y0 DOUBLE PRECISION,
	lam1 DOUBLE PRECISION,
	lam2 DOUBLE PRECISION,
	lam3 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLocMapLeg OWNER TO epsi;
CREATE INDEX TblBrlyQLocMapLeg_jref ON TblBrlyQLocMapLeg (jref);
CREATE INDEX TblBrlyQLocMapLeg_jnum ON TblBrlyQLocMapLeg (jnum);

CREATE TABLE TblBrlyQLocMapProxLocation(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mref BIGINT,
	mtheta DOUBLE PRECISION,
	mphi DOUBLE PRECISION,
	x DOUBLE PRECISION,
	y DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLocMapProxLocation OWNER TO epsi;
CREATE INDEX TblBrlyQLocMapProxLocation_jref ON TblBrlyQLocMapProxLocation (jref);
CREATE INDEX TblBrlyQLocMapProxLocation_jnum ON TblBrlyQLocMapProxLocation (jnum);

CREATE TABLE TblBrlyQLocMapVisLocation(
	qref BIGSERIAL PRIMARY KEY,
	qwr SMALLINT,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	mref BIGINT,
	mtheta DOUBLE PRECISION,
	mphi DOUBLE PRECISION,
	x DOUBLE PRECISION,
	y DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLocMapVisLocation OWNER TO epsi;
CREATE INDEX TblBrlyQLocMapVisLocation_jref ON TblBrlyQLocMapVisLocation (jref);
CREATE INDEX TblBrlyQLocMapVisLocation_jnum ON TblBrlyQLocMapVisLocation (jnum);

CREATE TABLE TblBrlyQLocMNFlight(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1VisStart INT,
	x1VisStop INT,
	xVisStart INT,
	xVisStop INT
);
ALTER TABLE TblBrlyQLocMNFlight OWNER TO epsi;
CREATE INDEX TblBrlyQLocMNFlight_jref ON TblBrlyQLocMNFlight (jref);
CREATE INDEX TblBrlyQLocMNFlight_jnum ON TblBrlyQLocMNFlight (jnum);

CREATE TABLE TblBrlyQLocMNLeg(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1VisLegphi0 DOUBLE PRECISION,
	x1VisLegphi1 DOUBLE PRECISION,
	legphi DOUBLE PRECISION,
	legtheta DOUBLE PRECISION,
	xVisLegphi0 DOUBLE PRECISION,
	xVisLegphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLocMNLeg OWNER TO epsi;
CREATE INDEX TblBrlyQLocMNLeg_jref ON TblBrlyQLocMNLeg (jref);
CREATE INDEX TblBrlyQLocMNLeg_jnum ON TblBrlyQLocMNLeg (jnum);

CREATE TABLE TblBrlyQLocMNSegment(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	x2VisSegphi0 DOUBLE PRECISION,
	x2VisSegphi1 DOUBLE PRECISION,
	segphi DOUBLE PRECISION,
	segtheta DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLocMNSegment OWNER TO epsi;
CREATE INDEX TblBrlyQLocMNSegment_jref ON TblBrlyQLocMNSegment (jref);
CREATE INDEX TblBrlyQLocMNSegment_jnum ON TblBrlyQLocMNSegment (jnum);

CREATE TABLE TblBrlyQLocProxOrgMNLocation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	deltaphi DOUBLE PRECISION
);
ALTER TABLE TblBrlyQLocProxOrgMNLocation OWNER TO epsi;
CREATE INDEX TblBrlyQLocProxOrgMNLocation_jref ON TblBrlyQLocProxOrgMNLocation (jref);
CREATE INDEX TblBrlyQLocProxOrgMNLocation_jnum ON TblBrlyQLocProxOrgMNLocation (jnum);

CREATE TABLE TblBrlyQLocVisOrgMNLocation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblBrlyQLocVisOrgMNLocation OWNER TO epsi;
CREATE INDEX TblBrlyQLocVisOrgMNLocation_jref ON TblBrlyQLocVisOrgMNLocation (jref);
CREATE INDEX TblBrlyQLocVisOrgMNLocation_jnum ON TblBrlyQLocVisOrgMNLocation (jnum);

CREATE TABLE TblBrlyQOpr1NEquipment(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQOpr1NEquipment OWNER TO epsi;
CREATE INDEX TblBrlyQOpr1NEquipment_jref ON TblBrlyQOpr1NEquipment (jref);
CREATE INDEX TblBrlyQOpr1NEquipment_jnum ON TblBrlyQOpr1NEquipment (jnum);

CREATE TABLE TblBrlyQOprList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	srefICAO VARCHAR(5),
	Title VARCHAR(50)
);
ALTER TABLE TblBrlyQOprList OWNER TO epsi;
CREATE INDEX TblBrlyQOprList_jref ON TblBrlyQOprList (jref);
CREATE INDEX TblBrlyQOprList_jnum ON TblBrlyQOprList (jnum);

CREATE TABLE TblBrlyQPreselect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQPreselect OWNER TO epsi;
CREATE INDEX TblBrlyQPreselect_jref ON TblBrlyQPreselect (jref);

CREATE TABLE TblBrlyQPrsADetail(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(256)
);
ALTER TABLE TblBrlyQPrsADetail OWNER TO epsi;
CREATE INDEX TblBrlyQPrsADetail_jref ON TblBrlyQPrsADetail (jref);
CREATE INDEX TblBrlyQPrsADetail_jnum ON TblBrlyQPrsADetail (jnum);

CREATE TABLE TblBrlyQPrsList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	grp BIGINT,
	own BIGINT,
	ixVSex INT,
	telVal VARCHAR(256),
	emlVal VARCHAR(256)
);
ALTER TABLE TblBrlyQPrsList OWNER TO epsi;
CREATE INDEX TblBrlyQPrsList_jref ON TblBrlyQPrsList (jref);
CREATE INDEX TblBrlyQPrsList_jnum ON TblBrlyQPrsList (jnum);

CREATE TABLE TblBrlyQPty1NEquipment(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQPty1NEquipment OWNER TO epsi;
CREATE INDEX TblBrlyQPty1NEquipment_jref ON TblBrlyQPty1NEquipment (jref);
CREATE INDEX TblBrlyQPty1NEquipment_jnum ON TblBrlyQPty1NEquipment (jnum);

CREATE TABLE TblBrlyQPtyList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	srefBrlyKEqptype VARCHAR(50),
	Capacity SMALLINT
);
ALTER TABLE TblBrlyQPtyList OWNER TO epsi;
CREATE INDEX TblBrlyQPtyList_jref ON TblBrlyQPtyList (jref);
CREATE INDEX TblBrlyQPtyList_jnum ON TblBrlyQPtyList (jnum);

CREATE TABLE TblBrlyQReg1NLocation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQReg1NLocation OWNER TO epsi;
CREATE INDEX TblBrlyQReg1NLocation_jref ON TblBrlyQReg1NLocation (jref);
CREATE INDEX TblBrlyQReg1NLocation_jnum ON TblBrlyQReg1NLocation (jnum);

CREATE TABLE TblBrlyQRegADstswitch(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	startd INT,
	startt INT
);
ALTER TABLE TblBrlyQRegADstswitch OWNER TO epsi;
CREATE INDEX TblBrlyQRegADstswitch_jref ON TblBrlyQRegADstswitch (jref);
CREATE INDEX TblBrlyQRegADstswitch_jnum ON TblBrlyQRegADstswitch (jnum);

CREATE TABLE TblBrlyQRegList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	supRefBrlyMRegion BIGINT,
	ixVDst INT,
	toffset DOUBLE PRECISION
);
ALTER TABLE TblBrlyQRegList OWNER TO epsi;
CREATE INDEX TblBrlyQRegList_jref ON TblBrlyQRegList (jref);
CREATE INDEX TblBrlyQRegList_jnum ON TblBrlyQRegList (jnum);

CREATE TABLE TblBrlyQRegSup1NRegion(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQRegSup1NRegion OWNER TO epsi;
CREATE INDEX TblBrlyQRegSup1NRegion_jref ON TblBrlyQRegSup1NRegion (jref);
CREATE INDEX TblBrlyQRegSup1NRegion_jnum ON TblBrlyQRegSup1NRegion (jnum);

CREATE TABLE TblBrlyQRly1NNode(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQRly1NNode OWNER TO epsi;
CREATE INDEX TblBrlyQRly1NNode_jref ON TblBrlyQRly1NNode (jref);
CREATE INDEX TblBrlyQRly1NNode_jnum ON TblBrlyQRly1NNode (jnum);

CREATE TABLE TblBrlyQRlyList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	refBrlyMConnection BIGINT,
	ixVDir INT,
	Connected SMALLINT
);
ALTER TABLE TblBrlyQRlyList OWNER TO epsi;
CREATE INDEX TblBrlyQRlyList_jref ON TblBrlyQRlyList (jref);
CREATE INDEX TblBrlyQRlyList_jnum ON TblBrlyQRlyList (jnum);

CREATE TABLE TblBrlyQSegList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	alt0 DOUBLE PRECISION,
	alt1 DOUBLE PRECISION,
	theta0 DOUBLE PRECISION,
	theta1 DOUBLE PRECISION,
	phi0 DOUBLE PRECISION,
	phi1 DOUBLE PRECISION,
	start INT,
	stop INT
);
ALTER TABLE TblBrlyQSegList OWNER TO epsi;
CREATE INDEX TblBrlyQSegList_jref ON TblBrlyQSegList (jref);
CREATE INDEX TblBrlyQSegList_jnum ON TblBrlyQSegList (jnum);

CREATE TABLE TblBrlyQSegMNConnection(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	x2Legphi0 DOUBLE PRECISION,
	x2Legphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQSegMNConnection OWNER TO epsi;
CREATE INDEX TblBrlyQSegMNConnection_jref ON TblBrlyQSegMNConnection (jref);
CREATE INDEX TblBrlyQSegMNConnection_jnum ON TblBrlyQSegMNConnection (jnum);

CREATE TABLE TblBrlyQSegMNLocation(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	x2VisSegphi0 DOUBLE PRECISION,
	x2VisSegphi1 DOUBLE PRECISION,
	segphi DOUBLE PRECISION,
	segtheta DOUBLE PRECISION
);
ALTER TABLE TblBrlyQSegMNLocation OWNER TO epsi;
CREATE INDEX TblBrlyQSegMNLocation_jref ON TblBrlyQSegMNLocation (jref);
CREATE INDEX TblBrlyQSegMNLocation_jnum ON TblBrlyQSegMNLocation (jnum);

CREATE TABLE TblBrlyQSegOrgMNSegment(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1Start INT,
	x1Stop INT,
	x2VisDstSegphi0 DOUBLE PRECISION,
	x2VisDstSegphi1 DOUBLE PRECISION,
	VisOrgSegphi0 DOUBLE PRECISION,
	VisOrgSegphi1 DOUBLE PRECISION
);
ALTER TABLE TblBrlyQSegOrgMNSegment OWNER TO epsi;
CREATE INDEX TblBrlyQSegOrgMNSegment_jref ON TblBrlyQSegOrgMNSegment (jref);
CREATE INDEX TblBrlyQSegOrgMNSegment_jnum ON TblBrlyQSegOrgMNSegment (jnum);

CREATE TABLE TblBrlyQSelect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQSelect OWNER TO epsi;
CREATE INDEX TblBrlyQSelect_jref ON TblBrlyQSelect (jref);
CREATE INDEX TblBrlyQSelect_ix ON TblBrlyQSelect (ix);

CREATE TABLE TblBrlyQTtb1NFlight(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQTtb1NFlight OWNER TO epsi;
CREATE INDEX TblBrlyQTtb1NFlight_jref ON TblBrlyQTtb1NFlight (jref);
CREATE INDEX TblBrlyQTtb1NFlight_jnum ON TblBrlyQTtb1NFlight (jnum);

CREATE TABLE TblBrlyQTtbList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(50),
	refBrlyMFile BIGINT,
	srefBrlyKAlliance VARCHAR(50),
	startd INT,
	stopd INT
);
ALTER TABLE TblBrlyQTtbList OWNER TO epsi;
CREATE INDEX TblBrlyQTtbList_jref ON TblBrlyQTtbList (jref);
CREATE INDEX TblBrlyQTtbList_jnum ON TblBrlyQTtbList (jnum);

CREATE TABLE TblBrlyQTtbRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQTtbRef1NFile OWNER TO epsi;
CREATE INDEX TblBrlyQTtbRef1NFile_jref ON TblBrlyQTtbRef1NFile (jref);
CREATE INDEX TblBrlyQTtbRef1NFile_jnum ON TblBrlyQTtbRef1NFile (jnum);

CREATE TABLE TblBrlyQUsgAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxBrlyVCard INT,
	ixBrlyWUiaccess INT
);
ALTER TABLE TblBrlyQUsgAAccess OWNER TO epsi;
CREATE INDEX TblBrlyQUsgAAccess_jref ON TblBrlyQUsgAAccess (jref);
CREATE INDEX TblBrlyQUsgAAccess_jnum ON TblBrlyQUsgAAccess (jnum);

CREATE TABLE TblBrlyQUsgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblBrlyQUsgList OWNER TO epsi;
CREATE INDEX TblBrlyQUsgList_jref ON TblBrlyQUsgList (jref);
CREATE INDEX TblBrlyQUsgList_jnum ON TblBrlyQUsgList (jnum);

CREATE TABLE TblBrlyQUsgMNUser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixBrlyVUserlevel INT
);
ALTER TABLE TblBrlyQUsgMNUser OWNER TO epsi;
CREATE INDEX TblBrlyQUsgMNUser_jref ON TblBrlyQUsgMNUser (jref);
CREATE INDEX TblBrlyQUsgMNUser_jnum ON TblBrlyQUsgMNUser (jnum);

CREATE TABLE TblBrlyQUsr1NSession(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblBrlyQUsr1NSession OWNER TO epsi;
CREATE INDEX TblBrlyQUsr1NSession_jref ON TblBrlyQUsr1NSession (jref);
CREATE INDEX TblBrlyQUsr1NSession_jnum ON TblBrlyQUsr1NSession (jnum);

CREATE TABLE TblBrlyQUsrAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxBrlyVCard INT,
	ixBrlyWUiaccess INT
);
ALTER TABLE TblBrlyQUsrAAccess OWNER TO epsi;
CREATE INDEX TblBrlyQUsrAAccess_jref ON TblBrlyQUsrAAccess (jref);
CREATE INDEX TblBrlyQUsrAAccess_jnum ON TblBrlyQUsrAAccess (jnum);

CREATE TABLE TblBrlyQUsrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refBrlyMPerson BIGINT,
	sref VARCHAR(50),
	refBrlyMUsergroup BIGINT,
	ixVState INT,
	ixBrlyVLocale INT,
	ixBrlyVUserlevel INT
);
ALTER TABLE TblBrlyQUsrList OWNER TO epsi;
CREATE INDEX TblBrlyQUsrList_jref ON TblBrlyQUsrList (jref);
CREATE INDEX TblBrlyQUsrList_jnum ON TblBrlyQUsrList (jnum);

CREATE TABLE TblBrlyQUsrMNUsergroup(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixBrlyVUserlevel INT
);
ALTER TABLE TblBrlyQUsrMNUsergroup OWNER TO epsi;
CREATE INDEX TblBrlyQUsrMNUsergroup_jref ON TblBrlyQUsrMNUsergroup (jref);
CREATE INDEX TblBrlyQUsrMNUsergroup_jnum ON TblBrlyQUsrMNUsergroup (jnum);

