/**
  * \file BrlyMFlight.cpp
  * database access for table TblBrlyMFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMFlight.h"

/******************************************************************************
 class BrlyMFlight
 ******************************************************************************/

BrlyMFlight::BrlyMFlight(
			const ubigint ref
			, const ubigint refBrlyMTimetable
			, const ubigint refBrlyMEquipment
			, const ubigint refBrlyMFaflight
			, const ubigint refBrlyMLeg
			, const string sref
			, const uint start
			, const uint stop
			, const uint xStart
			, const uint xStop
			, const bool Calcdone
			, const bool Segdone
		) {

	this->ref = ref;
	this->refBrlyMTimetable = refBrlyMTimetable;
	this->refBrlyMEquipment = refBrlyMEquipment;
	this->refBrlyMFaflight = refBrlyMFaflight;
	this->refBrlyMLeg = refBrlyMLeg;
	this->sref = sref;
	this->start = start;
	this->stop = stop;
	this->xStart = xStart;
	this->xStop = xStop;
	this->Calcdone = Calcdone;
	this->Segdone = Segdone;
};

bool BrlyMFlight::operator==(
			const BrlyMFlight& comp
		) {
	return false;
};

bool BrlyMFlight::operator!=(
			const BrlyMFlight& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMFlight
 ******************************************************************************/

ListBrlyMFlight::ListBrlyMFlight() {
};

ListBrlyMFlight::ListBrlyMFlight(
			const ListBrlyMFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMFlight(*(src.nodes[i]));
};

ListBrlyMFlight::~ListBrlyMFlight() {
	clear();
};

void ListBrlyMFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMFlight::size() const {
	return(nodes.size());
};

void ListBrlyMFlight::append(
			BrlyMFlight* rec
		) {
	nodes.push_back(rec);
};

BrlyMFlight* ListBrlyMFlight::operator[](
			const uint ix
		) {
	BrlyMFlight* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMFlight& ListBrlyMFlight::operator=(
			const ListBrlyMFlight& src
		) {
	BrlyMFlight* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMFlight(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMFlight::operator==(
			const ListBrlyMFlight& comp
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

bool ListBrlyMFlight::operator!=(
			const ListBrlyMFlight& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMFlight
 ******************************************************************************/

TblBrlyMFlight::TblBrlyMFlight() {
};

TblBrlyMFlight::~TblBrlyMFlight() {
};

bool TblBrlyMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyMFlight** rec
		) {
	return false;
};

ubigint TblBrlyMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFlight& rst
		) {
	return 0;
};

void TblBrlyMFlight::insertRec(
			BrlyMFlight* rec
		) {
};

ubigint TblBrlyMFlight::insertNewRec(
			BrlyMFlight** rec
			, const ubigint refBrlyMTimetable
			, const ubigint refBrlyMEquipment
			, const ubigint refBrlyMFaflight
			, const ubigint refBrlyMLeg
			, const string sref
			, const uint start
			, const uint stop
			, const uint xStart
			, const uint xStop
			, const bool Calcdone
			, const bool Segdone
		) {
	ubigint retval = 0;
	BrlyMFlight* _rec = NULL;

	_rec = new BrlyMFlight(0, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMFlight::appendNewRecToRst(
			ListBrlyMFlight& rst
			, BrlyMFlight** rec
			, const ubigint refBrlyMTimetable
			, const ubigint refBrlyMEquipment
			, const ubigint refBrlyMFaflight
			, const ubigint refBrlyMLeg
			, const string sref
			, const uint start
			, const uint stop
			, const uint xStart
			, const uint xStop
			, const bool Calcdone
			, const bool Segdone
		) {
	ubigint retval = 0;
	BrlyMFlight* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMFlight::insertRst(
			ListBrlyMFlight& rst
			, bool transact
		) {
};

void TblBrlyMFlight::updateRec(
			BrlyMFlight* rec
		) {
};

void TblBrlyMFlight::updateRst(
			ListBrlyMFlight& rst
			, bool transact
		) {
};

void TblBrlyMFlight::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMFlight::loadRecByRef(
			ubigint ref
			, BrlyMFlight** rec
		) {
	return false;
};

bool TblBrlyMFlight::loadRecByEqp(
			ubigint refBrlyMEquipment
			, BrlyMFlight** rec
		) {
	return false;
};

bool TblBrlyMFlight::loadRecByFaf(
			ubigint refBrlyMFaflight
			, BrlyMFlight** rec
		) {
	return false;
};

ubigint TblBrlyMFlight::loadRefsByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMFlight::loadRstByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, ListBrlyMFlight& rst
		) {
	return 0;
};

bool TblBrlyMFlight::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblBrlyMFlight::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMFlight& rst
		) {
	ubigint numload = 0;
	BrlyMFlight* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMFlight
 ******************************************************************************/

MyTblBrlyMFlight::MyTblBrlyMFlight() : TblBrlyMFlight(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMFlight::~MyTblBrlyMFlight() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMFlight::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMFlight (refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMFlight SET refBrlyMTimetable = ?, refBrlyMEquipment = ?, refBrlyMFaflight = ?, refBrlyMLeg = ?, sref = ?, start = ?, stop = ?, xStart = ?, xStop = ?, Calcdone = ?, Segdone = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMFlight WHERE ref = ?", false);
};

bool MyTblBrlyMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyMFlight** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMFlight* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMFlight / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMFlight();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMTimetable = atoll((char*) dbrow[1]); else _rec->refBrlyMTimetable = 0;
		if (dbrow[2]) _rec->refBrlyMEquipment = atoll((char*) dbrow[2]); else _rec->refBrlyMEquipment = 0;
		if (dbrow[3]) _rec->refBrlyMFaflight = atoll((char*) dbrow[3]); else _rec->refBrlyMFaflight = 0;
		if (dbrow[4]) _rec->refBrlyMLeg = atoll((char*) dbrow[4]); else _rec->refBrlyMLeg = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->start = atol((char*) dbrow[6]); else _rec->start = 0;
		if (dbrow[7]) _rec->stop = atol((char*) dbrow[7]); else _rec->stop = 0;
		if (dbrow[8]) _rec->xStart = atol((char*) dbrow[8]); else _rec->xStart = 0;
		if (dbrow[9]) _rec->xStop = atol((char*) dbrow[9]); else _rec->xStop = 0;
		if (dbrow[10]) _rec->Calcdone = (atoi((char*) dbrow[10]) != 0); else _rec->Calcdone = false;
		if (dbrow[11]) _rec->Segdone = (atoi((char*) dbrow[11]) != 0); else _rec->Segdone = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFlight& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMFlight* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMFlight / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMFlight();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMTimetable = atoll((char*) dbrow[1]); else rec->refBrlyMTimetable = 0;
			if (dbrow[2]) rec->refBrlyMEquipment = atoll((char*) dbrow[2]); else rec->refBrlyMEquipment = 0;
			if (dbrow[3]) rec->refBrlyMFaflight = atoll((char*) dbrow[3]); else rec->refBrlyMFaflight = 0;
			if (dbrow[4]) rec->refBrlyMLeg = atoll((char*) dbrow[4]); else rec->refBrlyMLeg = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->start = atol((char*) dbrow[6]); else rec->start = 0;
			if (dbrow[7]) rec->stop = atol((char*) dbrow[7]); else rec->stop = 0;
			if (dbrow[8]) rec->xStart = atol((char*) dbrow[8]); else rec->xStart = 0;
			if (dbrow[9]) rec->xStop = atol((char*) dbrow[9]); else rec->xStop = 0;
			if (dbrow[10]) rec->Calcdone = (atoi((char*) dbrow[10]) != 0); else rec->Calcdone = false;
			if (dbrow[11]) rec->Segdone = (atoi((char*) dbrow[11]) != 0); else rec->Segdone = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMFlight::insertRec(
			BrlyMFlight* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	l[4] = rec->sref.length();
	tinyint Calcdone = rec->Calcdone;
	tinyint Segdone = rec->Segdone;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMTimetable,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMFaflight,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMLeg,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->start,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->stop,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->xStart,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->xStop,&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Calcdone,&(l[9]),&(n[9]),&(e[9])),
		bindTinyint(&Segdone,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFlight / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFlight / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMFlight::insertRst(
			ListBrlyMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMFlight::updateRec(
			BrlyMFlight* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[4] = rec->sref.length();
	tinyint Calcdone = rec->Calcdone;
	tinyint Segdone = rec->Segdone;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMTimetable,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMFaflight,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMLeg,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->start,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->stop,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->xStart,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->xStop,&(l[8]),&(n[8]),&(e[8])),
		bindTinyint(&Calcdone,&(l[9]),&(n[9]),&(e[9])),
		bindTinyint(&Segdone,&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFlight / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFlight / stmtUpdateRec)\n");
};

void MyTblBrlyMFlight::updateRst(
			ListBrlyMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMFlight::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFlight / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFlight / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMFlight::loadRecByRef(
			ubigint ref
			, BrlyMFlight** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMFlight WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMFlight::loadRecByEqp(
			ubigint refBrlyMEquipment
			, BrlyMFlight** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone FROM TblBrlyMFlight WHERE refBrlyMEquipment = " + to_string(refBrlyMEquipment) + "", rec);
};

bool MyTblBrlyMFlight::loadRecByFaf(
			ubigint refBrlyMFaflight
			, BrlyMFlight** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone FROM TblBrlyMFlight WHERE refBrlyMFaflight = " + to_string(refBrlyMFaflight) + "", rec);
};

ubigint MyTblBrlyMFlight::loadRefsByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMFlight WHERE refBrlyMLeg = " + to_string(refBrlyMLeg) + " ORDER BY start ASC", append, refs);
};

ubigint MyTblBrlyMFlight::loadRstByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, ListBrlyMFlight& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone FROM TblBrlyMFlight WHERE refBrlyMLeg = " + to_string(refBrlyMLeg) + " ORDER BY start ASC", append, rst);
};

bool MyTblBrlyMFlight::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblBrlyMFlight WHERE ref = " + to_string(ref) + "", sref);
};

/******************************************************************************
 class PgTblBrlyMFlight
 ******************************************************************************/

PgTblBrlyMFlight::PgTblBrlyMFlight() : TblBrlyMFlight(), PgTable() {
};

PgTblBrlyMFlight::~PgTblBrlyMFlight() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMFlight::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMFlight_insertRec", "INSERT INTO TblBrlyMFlight (refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFlight_updateRec", "UPDATE TblBrlyMFlight SET refBrlyMTimetable = $1, refBrlyMEquipment = $2, refBrlyMFaflight = $3, refBrlyMLeg = $4, sref = $5, start = $6, stop = $7, xStart = $8, xStop = $9, Calcdone = $10, Segdone = $11 WHERE ref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFlight_removeRecByRef", "DELETE FROM TblBrlyMFlight WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMFlight_loadRecByRef", "SELECT ref, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone FROM TblBrlyMFlight WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMFlight_loadRecByEqp", "SELECT ref, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone FROM TblBrlyMFlight WHERE refBrlyMEquipment = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFlight_loadRecByFaf", "SELECT ref, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone FROM TblBrlyMFlight WHERE refBrlyMFaflight = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFlight_loadRefsByLeg", "SELECT ref FROM TblBrlyMFlight WHERE refBrlyMLeg = $1 ORDER BY start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFlight_loadRstByLeg", "SELECT ref, refBrlyMTimetable, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, sref, start, stop, xStart, xStop, Calcdone, Segdone FROM TblBrlyMFlight WHERE refBrlyMLeg = $1 ORDER BY start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFlight_loadSrfByRef", "SELECT sref FROM TblBrlyMFlight WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMFlight::loadRec(
			PGresult* res
			, BrlyMFlight** rec
		) {
	char* ptr;

	BrlyMFlight* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMFlight();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymtimetable"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "refbrlymfaflight"),
			PQfnumber(res, "refbrlymleg"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "xstart"),
			PQfnumber(res, "xstop"),
			PQfnumber(res, "calcdone"),
			PQfnumber(res, "segdone")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMTimetable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refBrlyMEquipment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refBrlyMFaflight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refBrlyMLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->xStart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->xStop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Calcdone = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Segdone = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMFlight::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMFlight& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMFlight* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymtimetable"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "refbrlymfaflight"),
			PQfnumber(res, "refbrlymleg"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "xstart"),
			PQfnumber(res, "xstop"),
			PQfnumber(res, "calcdone"),
			PQfnumber(res, "segdone")
		};

		while (numread < numrow) {
			rec = new BrlyMFlight();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMTimetable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refBrlyMEquipment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refBrlyMFaflight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refBrlyMLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->xStart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->xStop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Calcdone = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Segdone = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMFlight::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMFlight** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFlight / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMFlight::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMFlight& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFlight / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyMFlight** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFlight& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMFlight::insertRec(
			BrlyMFlight* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMTimetable = htonl64(rec->refBrlyMTimetable);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	ubigint _refBrlyMFaflight = htonl64(rec->refBrlyMFaflight);
	ubigint _refBrlyMLeg = htonl64(rec->refBrlyMLeg);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	uint _xStart = htonl(rec->xStart);
	uint _xStop = htonl(rec->xStop);
	smallint _Calcdone = htons((smallint) rec->Calcdone);
	smallint _Segdone = htons((smallint) rec->Segdone);

	const char* vals[] = {
		(char*) &_refBrlyMTimetable,
		(char*) &_refBrlyMEquipment,
		(char*) &_refBrlyMFaflight,
		(char*) &_refBrlyMLeg,
		rec->sref.c_str(),
		(char*) &_start,
		(char*) &_stop,
		(char*) &_xStart,
		(char*) &_xStop,
		(char*) &_Calcdone,
		(char*) &_Segdone
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMFlight_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFlight_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMFlight::insertRst(
			ListBrlyMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMFlight::updateRec(
			BrlyMFlight* rec
		) {
	PGresult* res;

	ubigint _refBrlyMTimetable = htonl64(rec->refBrlyMTimetable);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	ubigint _refBrlyMFaflight = htonl64(rec->refBrlyMFaflight);
	ubigint _refBrlyMLeg = htonl64(rec->refBrlyMLeg);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	uint _xStart = htonl(rec->xStart);
	uint _xStop = htonl(rec->xStop);
	smallint _Calcdone = htons((smallint) rec->Calcdone);
	smallint _Segdone = htons((smallint) rec->Segdone);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMTimetable,
		(char*) &_refBrlyMEquipment,
		(char*) &_refBrlyMFaflight,
		(char*) &_refBrlyMLeg,
		rec->sref.c_str(),
		(char*) &_start,
		(char*) &_stop,
		(char*) &_xStart,
		(char*) &_xStop,
		(char*) &_Calcdone,
		(char*) &_Segdone,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMFlight_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFlight_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMFlight::updateRst(
			ListBrlyMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMFlight::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMFlight_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFlight_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMFlight::loadRecByRef(
			ubigint ref
			, BrlyMFlight** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMFlight_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMFlight::loadRecByEqp(
			ubigint refBrlyMEquipment
			, BrlyMFlight** rec
		) {
	ubigint _refBrlyMEquipment = htonl64(refBrlyMEquipment);

	const char* vals[] = {
		(char*) &_refBrlyMEquipment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMFlight_loadRecByEqp", 1, vals, l, f, rec);
};

bool PgTblBrlyMFlight::loadRecByFaf(
			ubigint refBrlyMFaflight
			, BrlyMFlight** rec
		) {
	ubigint _refBrlyMFaflight = htonl64(refBrlyMFaflight);

	const char* vals[] = {
		(char*) &_refBrlyMFaflight
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMFlight_loadRecByFaf", 1, vals, l, f, rec);
};

ubigint PgTblBrlyMFlight::loadRefsByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMLeg = htonl64(refBrlyMLeg);

	const char* vals[] = {
		(char*) &_refBrlyMLeg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMFlight_loadRefsByLeg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMFlight::loadRstByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, ListBrlyMFlight& rst
		) {
	ubigint _refBrlyMLeg = htonl64(refBrlyMLeg);

	const char* vals[] = {
		(char*) &_refBrlyMLeg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMFlight_loadRstByLeg", 1, vals, l, f, append, rst);
};

bool PgTblBrlyMFlight::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblBrlyMFlight_loadSrfByRef", 1, vals, l, f, sref);
};

