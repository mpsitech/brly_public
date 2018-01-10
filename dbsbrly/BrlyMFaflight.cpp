/**
  * \file BrlyMFaflight.cpp
  * database access for table TblBrlyMFaflight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMFaflight.h"

/******************************************************************************
 class BrlyMFaflight
 ******************************************************************************/

BrlyMFaflight::BrlyMFaflight(
			const ubigint ref
			, const ubigint refBrlyMFlight
			, const string faFlightID
			, const string ident
			, const string aircrafttype
			, const string filed_ete
			, const uint filed_time
			, const uint filed_departuretime
			, const usmallint filed_airspeed_kts
			, const double filed_airspeed_mach
			, const usmallint filed_altitude
			, const string route
			, const uint actualdeparturetime
			, const uint estimatedarrivaltime
			, const uint actualarrivaltime
			, const string diverted
			, const string origin
			, const string destination
			, const string originName
			, const string originCity
			, const string destinationName
			, const string destinationCity
		) {

	this->ref = ref;
	this->refBrlyMFlight = refBrlyMFlight;
	this->faFlightID = faFlightID;
	this->ident = ident;
	this->aircrafttype = aircrafttype;
	this->filed_ete = filed_ete;
	this->filed_time = filed_time;
	this->filed_departuretime = filed_departuretime;
	this->filed_airspeed_kts = filed_airspeed_kts;
	this->filed_airspeed_mach = filed_airspeed_mach;
	this->filed_altitude = filed_altitude;
	this->route = route;
	this->actualdeparturetime = actualdeparturetime;
	this->estimatedarrivaltime = estimatedarrivaltime;
	this->actualarrivaltime = actualarrivaltime;
	this->diverted = diverted;
	this->origin = origin;
	this->destination = destination;
	this->originName = originName;
	this->originCity = originCity;
	this->destinationName = destinationName;
	this->destinationCity = destinationCity;
};

bool BrlyMFaflight::operator==(
			const BrlyMFaflight& comp
		) {
	return false;
};

bool BrlyMFaflight::operator!=(
			const BrlyMFaflight& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMFaflight
 ******************************************************************************/

ListBrlyMFaflight::ListBrlyMFaflight() {
};

ListBrlyMFaflight::ListBrlyMFaflight(
			const ListBrlyMFaflight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMFaflight(*(src.nodes[i]));
};

ListBrlyMFaflight::~ListBrlyMFaflight() {
	clear();
};

void ListBrlyMFaflight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMFaflight::size() const {
	return(nodes.size());
};

void ListBrlyMFaflight::append(
			BrlyMFaflight* rec
		) {
	nodes.push_back(rec);
};

BrlyMFaflight* ListBrlyMFaflight::operator[](
			const uint ix
		) {
	BrlyMFaflight* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMFaflight& ListBrlyMFaflight::operator=(
			const ListBrlyMFaflight& src
		) {
	BrlyMFaflight* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMFaflight(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMFaflight::operator==(
			const ListBrlyMFaflight& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListBrlyMFaflight::operator!=(
			const ListBrlyMFaflight& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMFaflight
 ******************************************************************************/

TblBrlyMFaflight::TblBrlyMFaflight() {
};

TblBrlyMFaflight::~TblBrlyMFaflight() {
};

bool TblBrlyMFaflight::loadRecBySQL(
			const string& sqlstr
			, BrlyMFaflight** rec
		) {
	return false;
};

ubigint TblBrlyMFaflight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFaflight& rst
		) {
	return 0;
};

void TblBrlyMFaflight::insertRec(
			BrlyMFaflight* rec
		) {
};

ubigint TblBrlyMFaflight::insertNewRec(
			BrlyMFaflight** rec
			, const ubigint refBrlyMFlight
			, const string faFlightID
			, const string ident
			, const string aircrafttype
			, const string filed_ete
			, const uint filed_time
			, const uint filed_departuretime
			, const usmallint filed_airspeed_kts
			, const double filed_airspeed_mach
			, const usmallint filed_altitude
			, const string route
			, const uint actualdeparturetime
			, const uint estimatedarrivaltime
			, const uint actualarrivaltime
			, const string diverted
			, const string origin
			, const string destination
			, const string originName
			, const string originCity
			, const string destinationName
			, const string destinationCity
		) {
	ubigint retval = 0;
	BrlyMFaflight* _rec = NULL;

	_rec = new BrlyMFaflight(0, refBrlyMFlight, faFlightID, ident, aircrafttype, filed_ete, filed_time, filed_departuretime, filed_airspeed_kts, filed_airspeed_mach, filed_altitude, route, actualdeparturetime, estimatedarrivaltime, actualarrivaltime, diverted, origin, destination, originName, originCity, destinationName, destinationCity);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMFaflight::appendNewRecToRst(
			ListBrlyMFaflight& rst
			, BrlyMFaflight** rec
			, const ubigint refBrlyMFlight
			, const string faFlightID
			, const string ident
			, const string aircrafttype
			, const string filed_ete
			, const uint filed_time
			, const uint filed_departuretime
			, const usmallint filed_airspeed_kts
			, const double filed_airspeed_mach
			, const usmallint filed_altitude
			, const string route
			, const uint actualdeparturetime
			, const uint estimatedarrivaltime
			, const uint actualarrivaltime
			, const string diverted
			, const string origin
			, const string destination
			, const string originName
			, const string originCity
			, const string destinationName
			, const string destinationCity
		) {
	ubigint retval = 0;
	BrlyMFaflight* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMFlight, faFlightID, ident, aircrafttype, filed_ete, filed_time, filed_departuretime, filed_airspeed_kts, filed_airspeed_mach, filed_altitude, route, actualdeparturetime, estimatedarrivaltime, actualarrivaltime, diverted, origin, destination, originName, originCity, destinationName, destinationCity);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMFaflight::insertRst(
			ListBrlyMFaflight& rst
			, bool transact
		) {
};

void TblBrlyMFaflight::updateRec(
			BrlyMFaflight* rec
		) {
};

void TblBrlyMFaflight::updateRst(
			ListBrlyMFaflight& rst
			, bool transact
		) {
};

void TblBrlyMFaflight::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMFaflight::loadRecByRef(
			ubigint ref
			, BrlyMFaflight** rec
		) {
	return false;
};

bool TblBrlyMFaflight::loadFidByRef(
			ubigint ref
			, string& faFlightID
		) {
	return false;
};

bool TblBrlyMFaflight::loadRecByFlt(
			ubigint refBrlyMFlight
			, BrlyMFaflight** rec
		) {
	return false;
};

ubigint TblBrlyMFaflight::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMFaflight& rst
		) {
	ubigint numload = 0;
	BrlyMFaflight* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMFaflight
 ******************************************************************************/

MyTblBrlyMFaflight::MyTblBrlyMFaflight() : TblBrlyMFaflight(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMFaflight::~MyTblBrlyMFaflight() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMFaflight::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMFaflight (refBrlyMFlight, faFlightID, ident, aircrafttype, filed_ete, filed_time, filed_departuretime, filed_airspeed_kts, filed_airspeed_mach, filed_altitude, route, actualdeparturetime, estimatedarrivaltime, actualarrivaltime, diverted, origin, destination, originName, originCity, destinationName, destinationCity) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMFaflight SET refBrlyMFlight = ?, faFlightID = ?, ident = ?, aircrafttype = ?, filed_ete = ?, filed_time = ?, filed_departuretime = ?, filed_airspeed_kts = ?, filed_airspeed_mach = ?, filed_altitude = ?, route = ?, actualdeparturetime = ?, estimatedarrivaltime = ?, actualarrivaltime = ?, diverted = ?, origin = ?, destination = ?, originName = ?, originCity = ?, destinationName = ?, destinationCity = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMFaflight WHERE ref = ?", false);
};

bool MyTblBrlyMFaflight::loadRecBySQL(
			const string& sqlstr
			, BrlyMFaflight** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMFaflight* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMFaflight / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMFaflight();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMFlight = atoll((char*) dbrow[1]); else _rec->refBrlyMFlight = 0;
		if (dbrow[2]) _rec->faFlightID.assign(dbrow[2], dblengths[2]); else _rec->faFlightID = "";
		if (dbrow[3]) _rec->ident.assign(dbrow[3], dblengths[3]); else _rec->ident = "";
		if (dbrow[4]) _rec->aircrafttype.assign(dbrow[4], dblengths[4]); else _rec->aircrafttype = "";
		if (dbrow[5]) _rec->filed_ete.assign(dbrow[5], dblengths[5]); else _rec->filed_ete = "";
		if (dbrow[6]) _rec->filed_time = atol((char*) dbrow[6]); else _rec->filed_time = 0;
		if (dbrow[7]) _rec->filed_departuretime = atol((char*) dbrow[7]); else _rec->filed_departuretime = 0;
		if (dbrow[8]) _rec->filed_airspeed_kts = atoi((char*) dbrow[8]); else _rec->filed_airspeed_kts = 0;
		if (dbrow[9]) _rec->filed_airspeed_mach = atof((char*) dbrow[9]); else _rec->filed_airspeed_mach = 0.0;
		if (dbrow[10]) _rec->filed_altitude = atoi((char*) dbrow[10]); else _rec->filed_altitude = 0;
		if (dbrow[11]) _rec->route.assign(dbrow[11], dblengths[11]); else _rec->route = "";
		if (dbrow[12]) _rec->actualdeparturetime = atol((char*) dbrow[12]); else _rec->actualdeparturetime = 0;
		if (dbrow[13]) _rec->estimatedarrivaltime = atol((char*) dbrow[13]); else _rec->estimatedarrivaltime = 0;
		if (dbrow[14]) _rec->actualarrivaltime = atol((char*) dbrow[14]); else _rec->actualarrivaltime = 0;
		if (dbrow[15]) _rec->diverted.assign(dbrow[15], dblengths[15]); else _rec->diverted = "";
		if (dbrow[16]) _rec->origin.assign(dbrow[16], dblengths[16]); else _rec->origin = "";
		if (dbrow[17]) _rec->destination.assign(dbrow[17], dblengths[17]); else _rec->destination = "";
		if (dbrow[18]) _rec->originName.assign(dbrow[18], dblengths[18]); else _rec->originName = "";
		if (dbrow[19]) _rec->originCity.assign(dbrow[19], dblengths[19]); else _rec->originCity = "";
		if (dbrow[20]) _rec->destinationName.assign(dbrow[20], dblengths[20]); else _rec->destinationName = "";
		if (dbrow[21]) _rec->destinationCity.assign(dbrow[21], dblengths[21]); else _rec->destinationCity = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMFaflight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFaflight& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMFaflight* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMFaflight / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMFaflight();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMFlight = atoll((char*) dbrow[1]); else rec->refBrlyMFlight = 0;
			if (dbrow[2]) rec->faFlightID.assign(dbrow[2], dblengths[2]); else rec->faFlightID = "";
			if (dbrow[3]) rec->ident.assign(dbrow[3], dblengths[3]); else rec->ident = "";
			if (dbrow[4]) rec->aircrafttype.assign(dbrow[4], dblengths[4]); else rec->aircrafttype = "";
			if (dbrow[5]) rec->filed_ete.assign(dbrow[5], dblengths[5]); else rec->filed_ete = "";
			if (dbrow[6]) rec->filed_time = atol((char*) dbrow[6]); else rec->filed_time = 0;
			if (dbrow[7]) rec->filed_departuretime = atol((char*) dbrow[7]); else rec->filed_departuretime = 0;
			if (dbrow[8]) rec->filed_airspeed_kts = atoi((char*) dbrow[8]); else rec->filed_airspeed_kts = 0;
			if (dbrow[9]) rec->filed_airspeed_mach = atof((char*) dbrow[9]); else rec->filed_airspeed_mach = 0.0;
			if (dbrow[10]) rec->filed_altitude = atoi((char*) dbrow[10]); else rec->filed_altitude = 0;
			if (dbrow[11]) rec->route.assign(dbrow[11], dblengths[11]); else rec->route = "";
			if (dbrow[12]) rec->actualdeparturetime = atol((char*) dbrow[12]); else rec->actualdeparturetime = 0;
			if (dbrow[13]) rec->estimatedarrivaltime = atol((char*) dbrow[13]); else rec->estimatedarrivaltime = 0;
			if (dbrow[14]) rec->actualarrivaltime = atol((char*) dbrow[14]); else rec->actualarrivaltime = 0;
			if (dbrow[15]) rec->diverted.assign(dbrow[15], dblengths[15]); else rec->diverted = "";
			if (dbrow[16]) rec->origin.assign(dbrow[16], dblengths[16]); else rec->origin = "";
			if (dbrow[17]) rec->destination.assign(dbrow[17], dblengths[17]); else rec->destination = "";
			if (dbrow[18]) rec->originName.assign(dbrow[18], dblengths[18]); else rec->originName = "";
			if (dbrow[19]) rec->originCity.assign(dbrow[19], dblengths[19]); else rec->originCity = "";
			if (dbrow[20]) rec->destinationName.assign(dbrow[20], dblengths[20]); else rec->destinationName = "";
			if (dbrow[21]) rec->destinationCity.assign(dbrow[21], dblengths[21]); else rec->destinationCity = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMFaflight::insertRec(
			BrlyMFaflight* rec
		) {
	unsigned long l[21]; my_bool n[21]; my_bool e[21];

	l[1] = rec->faFlightID.length();
	l[2] = rec->ident.length();
	l[3] = rec->aircrafttype.length();
	l[4] = rec->filed_ete.length();
	l[10] = rec->route.length();
	l[14] = rec->diverted.length();
	l[15] = rec->origin.length();
	l[16] = rec->destination.length();
	l[17] = rec->originName.length();
	l[18] = rec->originCity.length();
	l[19] = rec->destinationName.length();
	l[20] = rec->destinationCity.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMFlight,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->faFlightID.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->ident.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->aircrafttype.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->filed_ete.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->filed_time,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->filed_departuretime,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->filed_airspeed_kts,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->filed_airspeed_mach,&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->filed_altitude,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->route.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->actualdeparturetime,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->estimatedarrivaltime,&(l[12]),&(n[12]),&(e[12])),
		bindUint(&rec->actualarrivaltime,&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->diverted.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->origin.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->destination.c_str()),&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->originName.c_str()),&(l[17]),&(n[17]),&(e[17])),
		bindCstring((char*) (rec->originCity.c_str()),&(l[18]),&(n[18]),&(e[18])),
		bindCstring((char*) (rec->destinationName.c_str()),&(l[19]),&(n[19]),&(e[19])),
		bindCstring((char*) (rec->destinationCity.c_str()),&(l[20]),&(n[20]),&(e[20]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFaflight / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFaflight / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMFaflight::insertRst(
			ListBrlyMFaflight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMFaflight::updateRec(
			BrlyMFaflight* rec
		) {
	unsigned long l[22]; my_bool n[22]; my_bool e[22];

	l[1] = rec->faFlightID.length();
	l[2] = rec->ident.length();
	l[3] = rec->aircrafttype.length();
	l[4] = rec->filed_ete.length();
	l[10] = rec->route.length();
	l[14] = rec->diverted.length();
	l[15] = rec->origin.length();
	l[16] = rec->destination.length();
	l[17] = rec->originName.length();
	l[18] = rec->originCity.length();
	l[19] = rec->destinationName.length();
	l[20] = rec->destinationCity.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMFlight,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->faFlightID.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->ident.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->aircrafttype.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->filed_ete.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->filed_time,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->filed_departuretime,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->filed_airspeed_kts,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->filed_airspeed_mach,&(l[8]),&(n[8]),&(e[8])),
		bindUsmallint(&rec->filed_altitude,&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->route.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->actualdeparturetime,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->estimatedarrivaltime,&(l[12]),&(n[12]),&(e[12])),
		bindUint(&rec->actualarrivaltime,&(l[13]),&(n[13]),&(e[13])),
		bindCstring((char*) (rec->diverted.c_str()),&(l[14]),&(n[14]),&(e[14])),
		bindCstring((char*) (rec->origin.c_str()),&(l[15]),&(n[15]),&(e[15])),
		bindCstring((char*) (rec->destination.c_str()),&(l[16]),&(n[16]),&(e[16])),
		bindCstring((char*) (rec->originName.c_str()),&(l[17]),&(n[17]),&(e[17])),
		bindCstring((char*) (rec->originCity.c_str()),&(l[18]),&(n[18]),&(e[18])),
		bindCstring((char*) (rec->destinationName.c_str()),&(l[19]),&(n[19]),&(e[19])),
		bindCstring((char*) (rec->destinationCity.c_str()),&(l[20]),&(n[20]),&(e[20])),
		bindUbigint(&rec->ref,&(l[21]),&(n[21]),&(e[21]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFaflight / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFaflight / stmtUpdateRec)\n");
};

void MyTblBrlyMFaflight::updateRst(
			ListBrlyMFaflight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMFaflight::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFaflight / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFaflight / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMFaflight::loadRecByRef(
			ubigint ref
			, BrlyMFaflight** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMFaflight WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMFaflight::loadFidByRef(
			ubigint ref
			, string& faFlightID
		) {
	return loadStringBySQL("SELECT faFlightID FROM TblBrlyMFaflight WHERE ref = " + to_string(ref) + "", faFlightID);
};

bool MyTblBrlyMFaflight::loadRecByFlt(
			ubigint refBrlyMFlight
			, BrlyMFaflight** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMFlight, faFlightID, ident, aircrafttype, filed_ete, filed_time, filed_departuretime, filed_airspeed_kts, filed_airspeed_mach, filed_altitude, route, actualdeparturetime, estimatedarrivaltime, actualarrivaltime, diverted, origin, destination, originName, originCity, destinationName, destinationCity FROM TblBrlyMFaflight WHERE refBrlyMFlight = " + to_string(refBrlyMFlight) + "", rec);
};

/******************************************************************************
 class PgTblBrlyMFaflight
 ******************************************************************************/

PgTblBrlyMFaflight::PgTblBrlyMFaflight() : TblBrlyMFaflight(), PgTable() {
};

PgTblBrlyMFaflight::~PgTblBrlyMFaflight() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMFaflight::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMFaflight_insertRec", "INSERT INTO TblBrlyMFaflight (refBrlyMFlight, faFlightID, ident, aircrafttype, filed_ete, filed_time, filed_departuretime, filed_airspeed_kts, filed_airspeed_mach, filed_altitude, route, actualdeparturetime, estimatedarrivaltime, actualarrivaltime, diverted, origin, destination, originName, originCity, destinationName, destinationCity) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19,$20,$21) RETURNING ref", 21, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFaflight_updateRec", "UPDATE TblBrlyMFaflight SET refBrlyMFlight = $1, faFlightID = $2, ident = $3, aircrafttype = $4, filed_ete = $5, filed_time = $6, filed_departuretime = $7, filed_airspeed_kts = $8, filed_airspeed_mach = $9, filed_altitude = $10, route = $11, actualdeparturetime = $12, estimatedarrivaltime = $13, actualarrivaltime = $14, diverted = $15, origin = $16, destination = $17, originName = $18, originCity = $19, destinationName = $20, destinationCity = $21 WHERE ref = $22", 22, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFaflight_removeRecByRef", "DELETE FROM TblBrlyMFaflight WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMFaflight_loadRecByRef", "SELECT ref, refBrlyMFlight, faFlightID, ident, aircrafttype, filed_ete, filed_time, filed_departuretime, filed_airspeed_kts, filed_airspeed_mach, filed_altitude, route, actualdeparturetime, estimatedarrivaltime, actualarrivaltime, diverted, origin, destination, originName, originCity, destinationName, destinationCity FROM TblBrlyMFaflight WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMFaflight_loadFidByRef", "SELECT faFlightID FROM TblBrlyMFaflight WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFaflight_loadRecByFlt", "SELECT ref, refBrlyMFlight, faFlightID, ident, aircrafttype, filed_ete, filed_time, filed_departuretime, filed_airspeed_kts, filed_airspeed_mach, filed_altitude, route, actualdeparturetime, estimatedarrivaltime, actualarrivaltime, diverted, origin, destination, originName, originCity, destinationName, destinationCity FROM TblBrlyMFaflight WHERE refBrlyMFlight = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMFaflight::loadRec(
			PGresult* res
			, BrlyMFaflight** rec
		) {
	char* ptr;

	BrlyMFaflight* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMFaflight();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymflight"),
			PQfnumber(res, "faflightid"),
			PQfnumber(res, "ident"),
			PQfnumber(res, "aircrafttype"),
			PQfnumber(res, "filed_ete"),
			PQfnumber(res, "filed_time"),
			PQfnumber(res, "filed_departuretime"),
			PQfnumber(res, "filed_airspeed_kts"),
			PQfnumber(res, "filed_airspeed_mach"),
			PQfnumber(res, "filed_altitude"),
			PQfnumber(res, "route"),
			PQfnumber(res, "actualdeparturetime"),
			PQfnumber(res, "estimatedarrivaltime"),
			PQfnumber(res, "actualarrivaltime"),
			PQfnumber(res, "diverted"),
			PQfnumber(res, "origin"),
			PQfnumber(res, "destination"),
			PQfnumber(res, "originname"),
			PQfnumber(res, "origincity"),
			PQfnumber(res, "destinationname"),
			PQfnumber(res, "destinationcity")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMFlight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->faFlightID.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ident.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->aircrafttype.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->filed_ete.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->filed_time = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->filed_departuretime = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->filed_airspeed_kts = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->filed_airspeed_mach = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->filed_altitude = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->route.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->actualdeparturetime = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->estimatedarrivaltime = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->actualarrivaltime = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->diverted.assign(ptr, PQgetlength(res, 0, fnum[15]));
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->origin.assign(ptr, PQgetlength(res, 0, fnum[16]));
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->destination.assign(ptr, PQgetlength(res, 0, fnum[17]));
		ptr = PQgetvalue(res, 0, fnum[18]); _rec->originName.assign(ptr, PQgetlength(res, 0, fnum[18]));
		ptr = PQgetvalue(res, 0, fnum[19]); _rec->originCity.assign(ptr, PQgetlength(res, 0, fnum[19]));
		ptr = PQgetvalue(res, 0, fnum[20]); _rec->destinationName.assign(ptr, PQgetlength(res, 0, fnum[20]));
		ptr = PQgetvalue(res, 0, fnum[21]); _rec->destinationCity.assign(ptr, PQgetlength(res, 0, fnum[21]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMFaflight::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMFaflight& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMFaflight* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymflight"),
			PQfnumber(res, "faflightid"),
			PQfnumber(res, "ident"),
			PQfnumber(res, "aircrafttype"),
			PQfnumber(res, "filed_ete"),
			PQfnumber(res, "filed_time"),
			PQfnumber(res, "filed_departuretime"),
			PQfnumber(res, "filed_airspeed_kts"),
			PQfnumber(res, "filed_airspeed_mach"),
			PQfnumber(res, "filed_altitude"),
			PQfnumber(res, "route"),
			PQfnumber(res, "actualdeparturetime"),
			PQfnumber(res, "estimatedarrivaltime"),
			PQfnumber(res, "actualarrivaltime"),
			PQfnumber(res, "diverted"),
			PQfnumber(res, "origin"),
			PQfnumber(res, "destination"),
			PQfnumber(res, "originname"),
			PQfnumber(res, "origincity"),
			PQfnumber(res, "destinationname"),
			PQfnumber(res, "destinationcity")
		};

		while (numread < numrow) {
			rec = new BrlyMFaflight();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMFlight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->faFlightID.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ident.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->aircrafttype.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->filed_ete.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->filed_time = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->filed_departuretime = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->filed_airspeed_kts = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->filed_airspeed_mach = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->filed_altitude = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->route.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->actualdeparturetime = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->estimatedarrivaltime = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->actualarrivaltime = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->diverted.assign(ptr, PQgetlength(res, numread, fnum[15]));
			ptr = PQgetvalue(res, numread, fnum[16]); rec->origin.assign(ptr, PQgetlength(res, numread, fnum[16]));
			ptr = PQgetvalue(res, numread, fnum[17]); rec->destination.assign(ptr, PQgetlength(res, numread, fnum[17]));
			ptr = PQgetvalue(res, numread, fnum[18]); rec->originName.assign(ptr, PQgetlength(res, numread, fnum[18]));
			ptr = PQgetvalue(res, numread, fnum[19]); rec->originCity.assign(ptr, PQgetlength(res, numread, fnum[19]));
			ptr = PQgetvalue(res, numread, fnum[20]); rec->destinationName.assign(ptr, PQgetlength(res, numread, fnum[20]));
			ptr = PQgetvalue(res, numread, fnum[21]); rec->destinationCity.assign(ptr, PQgetlength(res, numread, fnum[21]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMFaflight::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMFaflight** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFaflight / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyMFaflight::loadRecBySQL(
			const string& sqlstr
			, BrlyMFaflight** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMFaflight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFaflight& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMFaflight::insertRec(
			BrlyMFaflight* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	uint _filed_time = htonl(rec->filed_time);
	uint _filed_departuretime = htonl(rec->filed_departuretime);
	usmallint _filed_airspeed_kts = htons(rec->filed_airspeed_kts);
	string _filed_airspeed_mach = to_string(rec->filed_airspeed_mach);
	usmallint _filed_altitude = htons(rec->filed_altitude);
	uint _actualdeparturetime = htonl(rec->actualdeparturetime);
	uint _estimatedarrivaltime = htonl(rec->estimatedarrivaltime);
	uint _actualarrivaltime = htonl(rec->actualarrivaltime);

	const char* vals[] = {
		(char*) &_refBrlyMFlight,
		rec->faFlightID.c_str(),
		rec->ident.c_str(),
		rec->aircrafttype.c_str(),
		rec->filed_ete.c_str(),
		(char*) &_filed_time,
		(char*) &_filed_departuretime,
		(char*) &_filed_airspeed_kts,
		_filed_airspeed_mach.c_str(),
		(char*) &_filed_altitude,
		rec->route.c_str(),
		(char*) &_actualdeparturetime,
		(char*) &_estimatedarrivaltime,
		(char*) &_actualarrivaltime,
		rec->diverted.c_str(),
		rec->origin.c_str(),
		rec->destination.c_str(),
		rec->originName.c_str(),
		rec->originCity.c_str(),
		rec->destinationName.c_str(),
		rec->destinationCity.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(usmallint),
		0,
		sizeof(usmallint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyMFaflight_insertRec", 21, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFaflight_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMFaflight::insertRst(
			ListBrlyMFaflight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMFaflight::updateRec(
			BrlyMFaflight* rec
		) {
	PGresult* res;

	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	uint _filed_time = htonl(rec->filed_time);
	uint _filed_departuretime = htonl(rec->filed_departuretime);
	usmallint _filed_airspeed_kts = htons(rec->filed_airspeed_kts);
	string _filed_airspeed_mach = to_string(rec->filed_airspeed_mach);
	usmallint _filed_altitude = htons(rec->filed_altitude);
	uint _actualdeparturetime = htonl(rec->actualdeparturetime);
	uint _estimatedarrivaltime = htonl(rec->estimatedarrivaltime);
	uint _actualarrivaltime = htonl(rec->actualarrivaltime);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMFlight,
		rec->faFlightID.c_str(),
		rec->ident.c_str(),
		rec->aircrafttype.c_str(),
		rec->filed_ete.c_str(),
		(char*) &_filed_time,
		(char*) &_filed_departuretime,
		(char*) &_filed_airspeed_kts,
		_filed_airspeed_mach.c_str(),
		(char*) &_filed_altitude,
		rec->route.c_str(),
		(char*) &_actualdeparturetime,
		(char*) &_estimatedarrivaltime,
		(char*) &_actualarrivaltime,
		rec->diverted.c_str(),
		rec->origin.c_str(),
		rec->destination.c_str(),
		rec->originName.c_str(),
		rec->originCity.c_str(),
		rec->destinationName.c_str(),
		rec->destinationCity.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(usmallint),
		0,
		sizeof(usmallint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMFaflight_updateRec", 22, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFaflight_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMFaflight::updateRst(
			ListBrlyMFaflight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMFaflight::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyMFaflight_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFaflight_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMFaflight::loadRecByRef(
			ubigint ref
			, BrlyMFaflight** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMFaflight_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMFaflight::loadFidByRef(
			ubigint ref
			, string& faFlightID
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblBrlyMFaflight_loadFidByRef", 1, vals, l, f, faFlightID);
};

bool PgTblBrlyMFaflight::loadRecByFlt(
			ubigint refBrlyMFlight
			, BrlyMFaflight** rec
		) {
	ubigint _refBrlyMFlight = htonl64(refBrlyMFlight);

	const char* vals[] = {
		(char*) &_refBrlyMFlight
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMFaflight_loadRecByFlt", 1, vals, l, f, rec);
};

