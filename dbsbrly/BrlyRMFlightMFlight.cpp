/**
  * \file BrlyRMFlightMFlight.cpp
  * database access for table TblBrlyRMFlightMFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMFlightMFlight.h"

/******************************************************************************
 class BrlyRMFlightMFlight
 ******************************************************************************/

BrlyRMFlightMFlight::BrlyRMFlightMFlight(
			const ubigint ref
			, const uint x1VisStart
			, const uint x1VisStop
			, const ubigint dstRefBrlyMFlight
			, const ubigint orgRefBrlyMFlight
			, const uint xVisStart
			, const uint xVisStop
		) {

	this->ref = ref;
	this->x1VisStart = x1VisStart;
	this->x1VisStop = x1VisStop;
	this->dstRefBrlyMFlight = dstRefBrlyMFlight;
	this->orgRefBrlyMFlight = orgRefBrlyMFlight;
	this->xVisStart = xVisStart;
	this->xVisStop = xVisStop;
};

bool BrlyRMFlightMFlight::operator==(
			const BrlyRMFlightMFlight& comp
		) {
	return false;
};

bool BrlyRMFlightMFlight::operator!=(
			const BrlyRMFlightMFlight& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMFlightMFlight
 ******************************************************************************/

ListBrlyRMFlightMFlight::ListBrlyRMFlightMFlight() {
};

ListBrlyRMFlightMFlight::ListBrlyRMFlightMFlight(
			const ListBrlyRMFlightMFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMFlightMFlight(*(src.nodes[i]));
};

ListBrlyRMFlightMFlight::~ListBrlyRMFlightMFlight() {
	clear();
};

void ListBrlyRMFlightMFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMFlightMFlight::size() const {
	return(nodes.size());
};

void ListBrlyRMFlightMFlight::append(
			BrlyRMFlightMFlight* rec
		) {
	nodes.push_back(rec);
};

BrlyRMFlightMFlight* ListBrlyRMFlightMFlight::operator[](
			const uint ix
		) {
	BrlyRMFlightMFlight* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMFlightMFlight& ListBrlyRMFlightMFlight::operator=(
			const ListBrlyRMFlightMFlight& src
		) {
	BrlyRMFlightMFlight* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMFlightMFlight(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMFlightMFlight::operator==(
			const ListBrlyRMFlightMFlight& comp
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

bool ListBrlyRMFlightMFlight::operator!=(
			const ListBrlyRMFlightMFlight& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMFlightMFlight
 ******************************************************************************/

TblBrlyRMFlightMFlight::TblBrlyRMFlightMFlight() {
};

TblBrlyRMFlightMFlight::~TblBrlyRMFlightMFlight() {
};

bool TblBrlyRMFlightMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyRMFlightMFlight** rec
		) {
	return false;
};

ubigint TblBrlyRMFlightMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	return 0;
};

void TblBrlyRMFlightMFlight::insertRec(
			BrlyRMFlightMFlight* rec
		) {
};

ubigint TblBrlyRMFlightMFlight::insertNewRec(
			BrlyRMFlightMFlight** rec
			, const uint x1VisStart
			, const uint x1VisStop
			, const ubigint dstRefBrlyMFlight
			, const ubigint orgRefBrlyMFlight
			, const uint xVisStart
			, const uint xVisStop
		) {
	ubigint retval = 0;
	BrlyRMFlightMFlight* _rec = NULL;

	_rec = new BrlyRMFlightMFlight(0, x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMFlightMFlight::appendNewRecToRst(
			ListBrlyRMFlightMFlight& rst
			, BrlyRMFlightMFlight** rec
			, const uint x1VisStart
			, const uint x1VisStop
			, const ubigint dstRefBrlyMFlight
			, const ubigint orgRefBrlyMFlight
			, const uint xVisStart
			, const uint xVisStop
		) {
	ubigint retval = 0;
	BrlyRMFlightMFlight* _rec = NULL;

	retval = insertNewRec(&_rec, x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMFlightMFlight::insertRst(
			ListBrlyRMFlightMFlight& rst
			, bool transact
		) {
};

void TblBrlyRMFlightMFlight::updateRec(
			BrlyRMFlightMFlight* rec
		) {
};

void TblBrlyRMFlightMFlight::updateRst(
			ListBrlyRMFlightMFlight& rst
			, bool transact
		) {
};

void TblBrlyRMFlightMFlight::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMFlightMFlight::loadRecByRef(
			ubigint ref
			, BrlyRMFlightMFlight** rec
		) {
	return false;
};

ubigint TblBrlyRMFlightMFlight::loadRstByDfl(
			ubigint dstRefBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	return 0;
};

ubigint TblBrlyRMFlightMFlight::loadRstByOfl(
			ubigint orgRefBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	return 0;
};

ubigint TblBrlyRMFlightMFlight::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	ubigint numload = 0;
	BrlyRMFlightMFlight* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMFlightMFlight
 ******************************************************************************/

MyTblBrlyRMFlightMFlight::MyTblBrlyRMFlightMFlight() : TblBrlyRMFlightMFlight(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMFlightMFlight::~MyTblBrlyRMFlightMFlight() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMFlightMFlight::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMFlightMFlight (x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMFlightMFlight SET x1VisStart = ?, x1VisStop = ?, dstRefBrlyMFlight = ?, orgRefBrlyMFlight = ?, xVisStart = ?, xVisStop = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMFlightMFlight WHERE ref = ?", false);
};

bool MyTblBrlyRMFlightMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyRMFlightMFlight** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMFlightMFlight* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMFlightMFlight / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMFlightMFlight();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1VisStart = atol((char*) dbrow[1]); else _rec->x1VisStart = 0;
		if (dbrow[2]) _rec->x1VisStop = atol((char*) dbrow[2]); else _rec->x1VisStop = 0;
		if (dbrow[3]) _rec->dstRefBrlyMFlight = atoll((char*) dbrow[3]); else _rec->dstRefBrlyMFlight = 0;
		if (dbrow[4]) _rec->orgRefBrlyMFlight = atoll((char*) dbrow[4]); else _rec->orgRefBrlyMFlight = 0;
		if (dbrow[5]) _rec->xVisStart = atol((char*) dbrow[5]); else _rec->xVisStart = 0;
		if (dbrow[6]) _rec->xVisStop = atol((char*) dbrow[6]); else _rec->xVisStop = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMFlightMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMFlightMFlight* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMFlightMFlight / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMFlightMFlight();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1VisStart = atol((char*) dbrow[1]); else rec->x1VisStart = 0;
			if (dbrow[2]) rec->x1VisStop = atol((char*) dbrow[2]); else rec->x1VisStop = 0;
			if (dbrow[3]) rec->dstRefBrlyMFlight = atoll((char*) dbrow[3]); else rec->dstRefBrlyMFlight = 0;
			if (dbrow[4]) rec->orgRefBrlyMFlight = atoll((char*) dbrow[4]); else rec->orgRefBrlyMFlight = 0;
			if (dbrow[5]) rec->xVisStart = atol((char*) dbrow[5]); else rec->xVisStart = 0;
			if (dbrow[6]) rec->xVisStop = atol((char*) dbrow[6]); else rec->xVisStop = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMFlightMFlight::insertRec(
			BrlyRMFlightMFlight* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1VisStart,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1VisStop,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->dstRefBrlyMFlight,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->orgRefBrlyMFlight,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->xVisStart,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->xVisStop,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMFlightMFlight / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMFlightMFlight / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMFlightMFlight::insertRst(
			ListBrlyRMFlightMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMFlightMFlight::updateRec(
			BrlyRMFlightMFlight* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1VisStart,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1VisStop,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->dstRefBrlyMFlight,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->orgRefBrlyMFlight,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->xVisStart,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->xVisStop,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMFlightMFlight / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMFlightMFlight / stmtUpdateRec)\n");
};

void MyTblBrlyRMFlightMFlight::updateRst(
			ListBrlyRMFlightMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMFlightMFlight::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMFlightMFlight / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMFlightMFlight / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMFlightMFlight::loadRecByRef(
			ubigint ref
			, BrlyRMFlightMFlight** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMFlightMFlight WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMFlightMFlight::loadRstByDfl(
			ubigint dstRefBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	return loadRstBySQL("SELECT ref, x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop FROM TblBrlyRMFlightMFlight WHERE dstRefBrlyMFlight = " + to_string(dstRefBrlyMFlight) + " ORDER BY x1VisStart ASC", append, rst);
};

ubigint MyTblBrlyRMFlightMFlight::loadRstByOfl(
			ubigint orgRefBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	return loadRstBySQL("SELECT ref, x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop FROM TblBrlyRMFlightMFlight WHERE orgRefBrlyMFlight = " + to_string(orgRefBrlyMFlight) + " ORDER BY x1VisStart ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMFlightMFlight
 ******************************************************************************/

PgTblBrlyRMFlightMFlight::PgTblBrlyRMFlightMFlight() : TblBrlyRMFlightMFlight(), PgTable() {
};

PgTblBrlyRMFlightMFlight::~PgTblBrlyRMFlightMFlight() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMFlightMFlight::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMFlightMFlight_insertRec", "INSERT INTO TblBrlyRMFlightMFlight (x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMFlightMFlight_updateRec", "UPDATE TblBrlyRMFlightMFlight SET x1VisStart = $1, x1VisStop = $2, dstRefBrlyMFlight = $3, orgRefBrlyMFlight = $4, xVisStart = $5, xVisStop = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMFlightMFlight_removeRecByRef", "DELETE FROM TblBrlyRMFlightMFlight WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMFlightMFlight_loadRecByRef", "SELECT ref, x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop FROM TblBrlyRMFlightMFlight WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMFlightMFlight_loadRstByDfl", "SELECT ref, x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop FROM TblBrlyRMFlightMFlight WHERE dstRefBrlyMFlight = $1 ORDER BY x1VisStart ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMFlightMFlight_loadRstByOfl", "SELECT ref, x1VisStart, x1VisStop, dstRefBrlyMFlight, orgRefBrlyMFlight, xVisStart, xVisStop FROM TblBrlyRMFlightMFlight WHERE orgRefBrlyMFlight = $1 ORDER BY x1VisStart ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMFlightMFlight::loadRec(
			PGresult* res
			, BrlyRMFlightMFlight** rec
		) {
	char* ptr;

	BrlyRMFlightMFlight* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMFlightMFlight();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1visstart"),
			PQfnumber(res, "x1visstop"),
			PQfnumber(res, "dstrefbrlymflight"),
			PQfnumber(res, "orgrefbrlymflight"),
			PQfnumber(res, "xvisstart"),
			PQfnumber(res, "xvisstop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1VisStart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1VisStop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->dstRefBrlyMFlight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->orgRefBrlyMFlight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->xVisStart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->xVisStop = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMFlightMFlight::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMFlightMFlight* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1visstart"),
			PQfnumber(res, "x1visstop"),
			PQfnumber(res, "dstrefbrlymflight"),
			PQfnumber(res, "orgrefbrlymflight"),
			PQfnumber(res, "xvisstart"),
			PQfnumber(res, "xvisstop")
		};

		while (numread < numrow) {
			rec = new BrlyRMFlightMFlight();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1VisStart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1VisStop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->dstRefBrlyMFlight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->orgRefBrlyMFlight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->xVisStart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->xVisStop = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMFlightMFlight::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMFlightMFlight** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMFlight / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMFlightMFlight::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMFlight / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMFlightMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyRMFlightMFlight** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMFlightMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMFlightMFlight::insertRec(
			BrlyRMFlightMFlight* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1VisStart = htonl(rec->x1VisStart);
	uint _x1VisStop = htonl(rec->x1VisStop);
	ubigint _dstRefBrlyMFlight = htonl64(rec->dstRefBrlyMFlight);
	ubigint _orgRefBrlyMFlight = htonl64(rec->orgRefBrlyMFlight);
	uint _xVisStart = htonl(rec->xVisStart);
	uint _xVisStop = htonl(rec->xVisStop);

	const char* vals[] = {
		(char*) &_x1VisStart,
		(char*) &_x1VisStop,
		(char*) &_dstRefBrlyMFlight,
		(char*) &_orgRefBrlyMFlight,
		(char*) &_xVisStart,
		(char*) &_xVisStop
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMFlightMFlight_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMFlight_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMFlightMFlight::insertRst(
			ListBrlyRMFlightMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMFlightMFlight::updateRec(
			BrlyRMFlightMFlight* rec
		) {
	PGresult* res;

	uint _x1VisStart = htonl(rec->x1VisStart);
	uint _x1VisStop = htonl(rec->x1VisStop);
	ubigint _dstRefBrlyMFlight = htonl64(rec->dstRefBrlyMFlight);
	ubigint _orgRefBrlyMFlight = htonl64(rec->orgRefBrlyMFlight);
	uint _xVisStart = htonl(rec->xVisStart);
	uint _xVisStop = htonl(rec->xVisStop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1VisStart,
		(char*) &_x1VisStop,
		(char*) &_dstRefBrlyMFlight,
		(char*) &_orgRefBrlyMFlight,
		(char*) &_xVisStart,
		(char*) &_xVisStop,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMFlightMFlight_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMFlight_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMFlightMFlight::updateRst(
			ListBrlyRMFlightMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMFlightMFlight::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMFlightMFlight_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMFlight_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMFlightMFlight::loadRecByRef(
			ubigint ref
			, BrlyRMFlightMFlight** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMFlightMFlight_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMFlightMFlight::loadRstByDfl(
			ubigint dstRefBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	ubigint _dstRefBrlyMFlight = htonl64(dstRefBrlyMFlight);

	const char* vals[] = {
		(char*) &_dstRefBrlyMFlight
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMFlightMFlight_loadRstByDfl", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMFlightMFlight::loadRstByOfl(
			ubigint orgRefBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMFlight& rst
		) {
	ubigint _orgRefBrlyMFlight = htonl64(orgRefBrlyMFlight);

	const char* vals[] = {
		(char*) &_orgRefBrlyMFlight
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMFlightMFlight_loadRstByOfl", 1, vals, l, f, append, rst);
};

