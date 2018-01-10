/**
  * \file BrlyQFltFafAWaypoint.cpp
  * Dbs and XML wrapper for table TblBrlyQFltFafAWaypoint (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQFltFafAWaypoint.h"

/******************************************************************************
 class BrlyQFltFafAWaypoint
 ******************************************************************************/

BrlyQFltFafAWaypoint::BrlyQFltFafAWaypoint(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint fafNum
			, const uint timestamp
			, const string ftmTimestamp
			, const double latitude
			, const double longitude
			, const usmallint groundspeed
			, const usmallint altitude
			, const string altitudeStatus
			, const string updateType
			, const string altitudeChange
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->fafNum = fafNum;
	this->timestamp = timestamp;
	this->ftmTimestamp = ftmTimestamp;
	this->latitude = latitude;
	this->longitude = longitude;
	this->groundspeed = groundspeed;
	this->altitude = altitude;
	this->altitudeStatus = altitudeStatus;
	this->updateType = updateType;
	this->altitudeChange = altitudeChange;
};

void BrlyQFltFafAWaypoint::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQFltFafAWaypoint";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tms", ftmTimestamp);
		writeDouble(wr, "lat", latitude);
		writeDouble(wr, "lon", longitude);
		writeUint(wr, "gsp", groundspeed);
		writeUint(wr, "alt", altitude);
		writeString(wr, "ast", altitudeStatus);
		writeString(wr, "uty", updateType);
		writeString(wr, "ach", altitudeChange);
	} else {
		writeString(wr, "ftmTimestamp", ftmTimestamp);
		writeDouble(wr, "latitude", latitude);
		writeDouble(wr, "longitude", longitude);
		writeUint(wr, "groundspeed", groundspeed);
		writeUint(wr, "altitude", altitude);
		writeString(wr, "altitudeStatus", altitudeStatus);
		writeString(wr, "updateType", updateType);
		writeString(wr, "altitudeChange", altitudeChange);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQFltFafAWaypoint
 ******************************************************************************/

ListBrlyQFltFafAWaypoint::ListBrlyQFltFafAWaypoint() {
};

ListBrlyQFltFafAWaypoint::ListBrlyQFltFafAWaypoint(
			const ListBrlyQFltFafAWaypoint& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltFafAWaypoint(*(src.nodes[i]));
};

ListBrlyQFltFafAWaypoint::~ListBrlyQFltFafAWaypoint() {
	clear();
};

void ListBrlyQFltFafAWaypoint::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQFltFafAWaypoint::size() const {
	return(nodes.size());
};

void ListBrlyQFltFafAWaypoint::append(
			BrlyQFltFafAWaypoint* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQFltFafAWaypoint& ListBrlyQFltFafAWaypoint::operator=(
			const ListBrlyQFltFafAWaypoint& src
		) {
	BrlyQFltFafAWaypoint* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQFltFafAWaypoint(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQFltFafAWaypoint::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQFltFafAWaypoint";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQFltFafAWaypoint
 ******************************************************************************/

TblBrlyQFltFafAWaypoint::TblBrlyQFltFafAWaypoint() {
};

TblBrlyQFltFafAWaypoint::~TblBrlyQFltFafAWaypoint() {
};

bool TblBrlyQFltFafAWaypoint::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltFafAWaypoint** rec
		) {
	return false;
};

ubigint TblBrlyQFltFafAWaypoint::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltFafAWaypoint& rst
		) {
	return 0;
};

void TblBrlyQFltFafAWaypoint::insertRec(
			BrlyQFltFafAWaypoint* rec
		) {
};

ubigint TblBrlyQFltFafAWaypoint::insertNewRec(
			BrlyQFltFafAWaypoint** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint fafNum
			, const uint timestamp
			, const string ftmTimestamp
			, const double latitude
			, const double longitude
			, const usmallint groundspeed
			, const usmallint altitude
			, const string altitudeStatus
			, const string updateType
			, const string altitudeChange
		) {
	ubigint retval = 0;
	BrlyQFltFafAWaypoint* _rec = NULL;

	_rec = new BrlyQFltFafAWaypoint(0, jref, jnum, ref, fafNum, timestamp, ftmTimestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQFltFafAWaypoint::appendNewRecToRst(
			ListBrlyQFltFafAWaypoint& rst
			, BrlyQFltFafAWaypoint** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint fafNum
			, const uint timestamp
			, const string ftmTimestamp
			, const double latitude
			, const double longitude
			, const usmallint groundspeed
			, const usmallint altitude
			, const string altitudeStatus
			, const string updateType
			, const string altitudeChange
		) {
	ubigint retval = 0;
	BrlyQFltFafAWaypoint* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, fafNum, timestamp, ftmTimestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQFltFafAWaypoint::insertRst(
			ListBrlyQFltFafAWaypoint& rst
		) {
};

void TblBrlyQFltFafAWaypoint::updateRec(
			BrlyQFltFafAWaypoint* rec
		) {
};

void TblBrlyQFltFafAWaypoint::updateRst(
			ListBrlyQFltFafAWaypoint& rst
		) {
};

void TblBrlyQFltFafAWaypoint::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQFltFafAWaypoint::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQFltFafAWaypoint::loadRecByQref(
			ubigint qref
			, BrlyQFltFafAWaypoint** rec
		) {
	return false;
};

ubigint TblBrlyQFltFafAWaypoint::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltFafAWaypoint& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQFltFafAWaypoint
 ******************************************************************************/

MyTblBrlyQFltFafAWaypoint::MyTblBrlyQFltFafAWaypoint() : TblBrlyQFltFafAWaypoint(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQFltFafAWaypoint::~MyTblBrlyQFltFafAWaypoint() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQFltFafAWaypoint::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQFltFafAWaypoint (jref, jnum, ref, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQFltFafAWaypoint SET jref = ?, jnum = ?, ref = ?, fafNum = ?, timestamp = ?, latitude = ?, longitude = ?, groundspeed = ?, altitude = ?, altitudeStatus = ?, updateType = ?, altitudeChange = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQFltFafAWaypoint WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQFltFafAWaypoint WHERE jref = ?", false);
};

bool MyTblBrlyQFltFafAWaypoint::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltFafAWaypoint** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQFltFafAWaypoint* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltFafAWaypoint / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQFltFafAWaypoint();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->fafNum = atol((char*) dbrow[4]); else _rec->fafNum = 0;
		if (dbrow[5]) _rec->timestamp = atol((char*) dbrow[5]); else _rec->timestamp = 0;
		if (dbrow[6]) _rec->latitude = atof((char*) dbrow[6]); else _rec->latitude = 0.0;
		if (dbrow[7]) _rec->longitude = atof((char*) dbrow[7]); else _rec->longitude = 0.0;
		if (dbrow[8]) _rec->groundspeed = atoi((char*) dbrow[8]); else _rec->groundspeed = 0;
		if (dbrow[9]) _rec->altitude = atoi((char*) dbrow[9]); else _rec->altitude = 0;
		if (dbrow[10]) _rec->altitudeStatus.assign(dbrow[10], dblengths[10]); else _rec->altitudeStatus = "";
		if (dbrow[11]) _rec->updateType.assign(dbrow[11], dblengths[11]); else _rec->updateType = "";
		if (dbrow[12]) _rec->altitudeChange.assign(dbrow[12], dblengths[12]); else _rec->altitudeChange = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQFltFafAWaypoint::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltFafAWaypoint& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQFltFafAWaypoint* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltFafAWaypoint / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQFltFafAWaypoint();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->fafNum = atol((char*) dbrow[4]); else rec->fafNum = 0;
			if (dbrow[5]) rec->timestamp = atol((char*) dbrow[5]); else rec->timestamp = 0;
			if (dbrow[6]) rec->latitude = atof((char*) dbrow[6]); else rec->latitude = 0.0;
			if (dbrow[7]) rec->longitude = atof((char*) dbrow[7]); else rec->longitude = 0.0;
			if (dbrow[8]) rec->groundspeed = atoi((char*) dbrow[8]); else rec->groundspeed = 0;
			if (dbrow[9]) rec->altitude = atoi((char*) dbrow[9]); else rec->altitude = 0;
			if (dbrow[10]) rec->altitudeStatus.assign(dbrow[10], dblengths[10]); else rec->altitudeStatus = "";
			if (dbrow[11]) rec->updateType.assign(dbrow[11], dblengths[11]); else rec->updateType = "";
			if (dbrow[12]) rec->altitudeChange.assign(dbrow[12], dblengths[12]); else rec->altitudeChange = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQFltFafAWaypoint::insertRec(
			BrlyQFltFafAWaypoint* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[9] = rec->altitudeStatus.length();
	l[10] = rec->updateType.length();
	l[11] = rec->altitudeChange.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->fafNum,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->timestamp,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->latitude,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->longitude,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->groundspeed,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->altitude,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->altitudeStatus.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->updateType.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->altitudeChange.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltFafAWaypoint / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltFafAWaypoint / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQFltFafAWaypoint::insertRst(
			ListBrlyQFltFafAWaypoint& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQFltFafAWaypoint::updateRec(
			BrlyQFltFafAWaypoint* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[9] = rec->altitudeStatus.length();
	l[10] = rec->updateType.length();
	l[11] = rec->altitudeChange.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->fafNum,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->timestamp,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->latitude,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->longitude,&(l[6]),&(n[6]),&(e[6])),
		bindUsmallint(&rec->groundspeed,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->altitude,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->altitudeStatus.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->updateType.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->altitudeChange.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->qref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltFafAWaypoint / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltFafAWaypoint / stmtUpdateRec)\n");
};

void MyTblBrlyQFltFafAWaypoint::updateRst(
			ListBrlyQFltFafAWaypoint& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQFltFafAWaypoint::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltFafAWaypoint / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltFafAWaypoint / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQFltFafAWaypoint::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltFafAWaypoint / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltFafAWaypoint / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQFltFafAWaypoint::loadRecByQref(
			ubigint qref
			, BrlyQFltFafAWaypoint** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQFltFafAWaypoint WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQFltFafAWaypoint::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltFafAWaypoint& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQFltFafAWaypoint WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQFltFafAWaypoint
 ******************************************************************************/

PgTblBrlyQFltFafAWaypoint::PgTblBrlyQFltFafAWaypoint() : TblBrlyQFltFafAWaypoint(), PgTable() {
};

PgTblBrlyQFltFafAWaypoint::~PgTblBrlyQFltFafAWaypoint() {
};

void PgTblBrlyQFltFafAWaypoint::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQFltFafAWaypoint_insertRec", "INSERT INTO TblBrlyQFltFafAWaypoint (jref, jnum, ref, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING qref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltFafAWaypoint_updateRec", "UPDATE TblBrlyQFltFafAWaypoint SET jref = $1, jnum = $2, ref = $3, fafNum = $4, timestamp = $5, latitude = $6, longitude = $7, groundspeed = $8, altitude = $9, altitudeStatus = $10, updateType = $11, altitudeChange = $12 WHERE qref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltFafAWaypoint_removeRecByQref", "DELETE FROM TblBrlyQFltFafAWaypoint WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltFafAWaypoint_removeRstByJref", "DELETE FROM TblBrlyQFltFafAWaypoint WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQFltFafAWaypoint_loadRecByQref", "SELECT qref, jref, jnum, ref, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange FROM TblBrlyQFltFafAWaypoint WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltFafAWaypoint_loadRstByJref", "SELECT qref, jref, jnum, ref, fafNum, timestamp, latitude, longitude, groundspeed, altitude, altitudeStatus, updateType, altitudeChange FROM TblBrlyQFltFafAWaypoint WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQFltFafAWaypoint::loadRec(
			PGresult* res
			, BrlyQFltFafAWaypoint** rec
		) {
	char* ptr;

	BrlyQFltFafAWaypoint* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQFltFafAWaypoint();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "fafnum"),
			PQfnumber(res, "timestamp"),
			PQfnumber(res, "latitude"),
			PQfnumber(res, "longitude"),
			PQfnumber(res, "groundspeed"),
			PQfnumber(res, "altitude"),
			PQfnumber(res, "altitudestatus"),
			PQfnumber(res, "updatetype"),
			PQfnumber(res, "altitudechange")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->fafNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->timestamp = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->latitude = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->longitude = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->groundspeed = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->altitude = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->altitudeStatus.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->updateType.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->altitudeChange.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQFltFafAWaypoint::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQFltFafAWaypoint& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQFltFafAWaypoint* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "fafnum"),
			PQfnumber(res, "timestamp"),
			PQfnumber(res, "latitude"),
			PQfnumber(res, "longitude"),
			PQfnumber(res, "groundspeed"),
			PQfnumber(res, "altitude"),
			PQfnumber(res, "altitudestatus"),
			PQfnumber(res, "updatetype"),
			PQfnumber(res, "altitudechange")
		};

		while (numread < numrow) {
			rec = new BrlyQFltFafAWaypoint();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->fafNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->timestamp = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->latitude = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->longitude = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->groundspeed = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->altitude = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->altitudeStatus.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->updateType.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->altitudeChange.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQFltFafAWaypoint::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQFltFafAWaypoint** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltFafAWaypoint / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltFafAWaypoint::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQFltFafAWaypoint& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltFafAWaypoint / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQFltFafAWaypoint::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltFafAWaypoint** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltFafAWaypoint::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltFafAWaypoint& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQFltFafAWaypoint::insertRec(
			BrlyQFltFafAWaypoint* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _fafNum = htonl(rec->fafNum);
	uint _timestamp = htonl(rec->timestamp);
	string _latitude = to_string(rec->latitude);
	string _longitude = to_string(rec->longitude);
	usmallint _groundspeed = htons(rec->groundspeed);
	usmallint _altitude = htons(rec->altitude);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_fafNum,
		(char*) &_timestamp,
		_latitude.c_str(),
		_longitude.c_str(),
		(char*) &_groundspeed,
		(char*) &_altitude,
		rec->altitudeStatus.c_str(),
		rec->updateType.c_str(),
		rec->altitudeChange.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQFltFafAWaypoint_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltFafAWaypoint_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQFltFafAWaypoint::insertRst(
			ListBrlyQFltFafAWaypoint& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQFltFafAWaypoint::updateRec(
			BrlyQFltFafAWaypoint* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _fafNum = htonl(rec->fafNum);
	uint _timestamp = htonl(rec->timestamp);
	string _latitude = to_string(rec->latitude);
	string _longitude = to_string(rec->longitude);
	usmallint _groundspeed = htons(rec->groundspeed);
	usmallint _altitude = htons(rec->altitude);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_fafNum,
		(char*) &_timestamp,
		_latitude.c_str(),
		_longitude.c_str(),
		(char*) &_groundspeed,
		(char*) &_altitude,
		rec->altitudeStatus.c_str(),
		rec->updateType.c_str(),
		rec->altitudeChange.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(usmallint),
		sizeof(usmallint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltFafAWaypoint_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltFafAWaypoint_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQFltFafAWaypoint::updateRst(
			ListBrlyQFltFafAWaypoint& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQFltFafAWaypoint::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyQFltFafAWaypoint_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltFafAWaypoint_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQFltFafAWaypoint::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyQFltFafAWaypoint_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltFafAWaypoint_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQFltFafAWaypoint::loadRecByQref(
			ubigint qref
			, BrlyQFltFafAWaypoint** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQFltFafAWaypoint_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQFltFafAWaypoint::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltFafAWaypoint& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQFltFafAWaypoint_loadRstByJref", 1, vals, l, f, append, rst);
};

