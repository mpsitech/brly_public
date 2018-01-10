/**
  * \file BrlyRMFlightMLocation.cpp
  * database access for table TblBrlyRMFlightMLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMFlightMLocation.h"

/******************************************************************************
 class BrlyRMFlightMLocation
 ******************************************************************************/

BrlyRMFlightMLocation::BrlyRMFlightMLocation(
			const ubigint ref
			, const uint x1VisStart
			, const uint x1VisStop
			, const ubigint refBrlyMFlight
			, const ubigint refBrlyMLocation
			, const uint xVisStart
			, const uint xVisStop
		) {

	this->ref = ref;
	this->x1VisStart = x1VisStart;
	this->x1VisStop = x1VisStop;
	this->refBrlyMFlight = refBrlyMFlight;
	this->refBrlyMLocation = refBrlyMLocation;
	this->xVisStart = xVisStart;
	this->xVisStop = xVisStop;
};

bool BrlyRMFlightMLocation::operator==(
			const BrlyRMFlightMLocation& comp
		) {
	return false;
};

bool BrlyRMFlightMLocation::operator!=(
			const BrlyRMFlightMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMFlightMLocation
 ******************************************************************************/

ListBrlyRMFlightMLocation::ListBrlyRMFlightMLocation() {
};

ListBrlyRMFlightMLocation::ListBrlyRMFlightMLocation(
			const ListBrlyRMFlightMLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMFlightMLocation(*(src.nodes[i]));
};

ListBrlyRMFlightMLocation::~ListBrlyRMFlightMLocation() {
	clear();
};

void ListBrlyRMFlightMLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMFlightMLocation::size() const {
	return(nodes.size());
};

void ListBrlyRMFlightMLocation::append(
			BrlyRMFlightMLocation* rec
		) {
	nodes.push_back(rec);
};

BrlyRMFlightMLocation* ListBrlyRMFlightMLocation::operator[](
			const uint ix
		) {
	BrlyRMFlightMLocation* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMFlightMLocation& ListBrlyRMFlightMLocation::operator=(
			const ListBrlyRMFlightMLocation& src
		) {
	BrlyRMFlightMLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMFlightMLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMFlightMLocation::operator==(
			const ListBrlyRMFlightMLocation& comp
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

bool ListBrlyRMFlightMLocation::operator!=(
			const ListBrlyRMFlightMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMFlightMLocation
 ******************************************************************************/

TblBrlyRMFlightMLocation::TblBrlyRMFlightMLocation() {
};

TblBrlyRMFlightMLocation::~TblBrlyRMFlightMLocation() {
};

bool TblBrlyRMFlightMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyRMFlightMLocation** rec
		) {
	return false;
};

ubigint TblBrlyRMFlightMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	return 0;
};

void TblBrlyRMFlightMLocation::insertRec(
			BrlyRMFlightMLocation* rec
		) {
};

ubigint TblBrlyRMFlightMLocation::insertNewRec(
			BrlyRMFlightMLocation** rec
			, const uint x1VisStart
			, const uint x1VisStop
			, const ubigint refBrlyMFlight
			, const ubigint refBrlyMLocation
			, const uint xVisStart
			, const uint xVisStop
		) {
	ubigint retval = 0;
	BrlyRMFlightMLocation* _rec = NULL;

	_rec = new BrlyRMFlightMLocation(0, x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMFlightMLocation::appendNewRecToRst(
			ListBrlyRMFlightMLocation& rst
			, BrlyRMFlightMLocation** rec
			, const uint x1VisStart
			, const uint x1VisStop
			, const ubigint refBrlyMFlight
			, const ubigint refBrlyMLocation
			, const uint xVisStart
			, const uint xVisStop
		) {
	ubigint retval = 0;
	BrlyRMFlightMLocation* _rec = NULL;

	retval = insertNewRec(&_rec, x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMFlightMLocation::insertRst(
			ListBrlyRMFlightMLocation& rst
			, bool transact
		) {
};

void TblBrlyRMFlightMLocation::updateRec(
			BrlyRMFlightMLocation* rec
		) {
};

void TblBrlyRMFlightMLocation::updateRst(
			ListBrlyRMFlightMLocation& rst
			, bool transact
		) {
};

void TblBrlyRMFlightMLocation::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMFlightMLocation::loadRecByRef(
			ubigint ref
			, BrlyRMFlightMLocation** rec
		) {
	return false;
};

ubigint TblBrlyRMFlightMLocation::loadRstByFlt(
			ubigint refBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	return 0;
};

ubigint TblBrlyRMFlightMLocation::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	return 0;
};

ubigint TblBrlyRMFlightMLocation::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	ubigint numload = 0;
	BrlyRMFlightMLocation* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMFlightMLocation
 ******************************************************************************/

MyTblBrlyRMFlightMLocation::MyTblBrlyRMFlightMLocation() : TblBrlyRMFlightMLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMFlightMLocation::~MyTblBrlyRMFlightMLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMFlightMLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMFlightMLocation (x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMFlightMLocation SET x1VisStart = ?, x1VisStop = ?, refBrlyMFlight = ?, refBrlyMLocation = ?, xVisStart = ?, xVisStop = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMFlightMLocation WHERE ref = ?", false);
};

bool MyTblBrlyRMFlightMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyRMFlightMLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMFlightMLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMFlightMLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMFlightMLocation();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1VisStart = atol((char*) dbrow[1]); else _rec->x1VisStart = 0;
		if (dbrow[2]) _rec->x1VisStop = atol((char*) dbrow[2]); else _rec->x1VisStop = 0;
		if (dbrow[3]) _rec->refBrlyMFlight = atoll((char*) dbrow[3]); else _rec->refBrlyMFlight = 0;
		if (dbrow[4]) _rec->refBrlyMLocation = atoll((char*) dbrow[4]); else _rec->refBrlyMLocation = 0;
		if (dbrow[5]) _rec->xVisStart = atol((char*) dbrow[5]); else _rec->xVisStart = 0;
		if (dbrow[6]) _rec->xVisStop = atol((char*) dbrow[6]); else _rec->xVisStop = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMFlightMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMFlightMLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMFlightMLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMFlightMLocation();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1VisStart = atol((char*) dbrow[1]); else rec->x1VisStart = 0;
			if (dbrow[2]) rec->x1VisStop = atol((char*) dbrow[2]); else rec->x1VisStop = 0;
			if (dbrow[3]) rec->refBrlyMFlight = atoll((char*) dbrow[3]); else rec->refBrlyMFlight = 0;
			if (dbrow[4]) rec->refBrlyMLocation = atoll((char*) dbrow[4]); else rec->refBrlyMLocation = 0;
			if (dbrow[5]) rec->xVisStart = atol((char*) dbrow[5]); else rec->xVisStart = 0;
			if (dbrow[6]) rec->xVisStop = atol((char*) dbrow[6]); else rec->xVisStop = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMFlightMLocation::insertRec(
			BrlyRMFlightMLocation* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1VisStart,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1VisStop,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMFlight,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMLocation,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->xVisStart,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->xVisStop,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMFlightMLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMFlightMLocation / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMFlightMLocation::insertRst(
			ListBrlyRMFlightMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMFlightMLocation::updateRec(
			BrlyRMFlightMLocation* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1VisStart,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1VisStop,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMFlight,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMLocation,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->xVisStart,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->xVisStop,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMFlightMLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMFlightMLocation / stmtUpdateRec)\n");
};

void MyTblBrlyRMFlightMLocation::updateRst(
			ListBrlyRMFlightMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMFlightMLocation::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMFlightMLocation / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMFlightMLocation / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMFlightMLocation::loadRecByRef(
			ubigint ref
			, BrlyRMFlightMLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMFlightMLocation WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMFlightMLocation::loadRstByFlt(
			ubigint refBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	return loadRstBySQL("SELECT ref, x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop FROM TblBrlyRMFlightMLocation WHERE refBrlyMFlight = " + to_string(refBrlyMFlight) + " ORDER BY x1VisStart ASC", append, rst);
};

ubigint MyTblBrlyRMFlightMLocation::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	return loadRstBySQL("SELECT ref, x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop FROM TblBrlyRMFlightMLocation WHERE refBrlyMLocation = " + to_string(refBrlyMLocation) + " ORDER BY x1VisStart ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMFlightMLocation
 ******************************************************************************/

PgTblBrlyRMFlightMLocation::PgTblBrlyRMFlightMLocation() : TblBrlyRMFlightMLocation(), PgTable() {
};

PgTblBrlyRMFlightMLocation::~PgTblBrlyRMFlightMLocation() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMFlightMLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMFlightMLocation_insertRec", "INSERT INTO TblBrlyRMFlightMLocation (x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMFlightMLocation_updateRec", "UPDATE TblBrlyRMFlightMLocation SET x1VisStart = $1, x1VisStop = $2, refBrlyMFlight = $3, refBrlyMLocation = $4, xVisStart = $5, xVisStop = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMFlightMLocation_removeRecByRef", "DELETE FROM TblBrlyRMFlightMLocation WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMFlightMLocation_loadRecByRef", "SELECT ref, x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop FROM TblBrlyRMFlightMLocation WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMFlightMLocation_loadRstByFlt", "SELECT ref, x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop FROM TblBrlyRMFlightMLocation WHERE refBrlyMFlight = $1 ORDER BY x1VisStart ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMFlightMLocation_loadRstByLoc", "SELECT ref, x1VisStart, x1VisStop, refBrlyMFlight, refBrlyMLocation, xVisStart, xVisStop FROM TblBrlyRMFlightMLocation WHERE refBrlyMLocation = $1 ORDER BY x1VisStart ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMFlightMLocation::loadRec(
			PGresult* res
			, BrlyRMFlightMLocation** rec
		) {
	char* ptr;

	BrlyRMFlightMLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMFlightMLocation();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1visstart"),
			PQfnumber(res, "x1visstop"),
			PQfnumber(res, "refbrlymflight"),
			PQfnumber(res, "refbrlymlocation"),
			PQfnumber(res, "xvisstart"),
			PQfnumber(res, "xvisstop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1VisStart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1VisStop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refBrlyMFlight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->xVisStart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->xVisStop = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMFlightMLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMFlightMLocation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1visstart"),
			PQfnumber(res, "x1visstop"),
			PQfnumber(res, "refbrlymflight"),
			PQfnumber(res, "refbrlymlocation"),
			PQfnumber(res, "xvisstart"),
			PQfnumber(res, "xvisstop")
		};

		while (numread < numrow) {
			rec = new BrlyRMFlightMLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1VisStart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1VisStop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refBrlyMFlight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->xVisStart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->xVisStop = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMFlightMLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMFlightMLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMFlightMLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMFlightMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyRMFlightMLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMFlightMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMFlightMLocation::insertRec(
			BrlyRMFlightMLocation* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1VisStart = htonl(rec->x1VisStart);
	uint _x1VisStop = htonl(rec->x1VisStop);
	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	ubigint _refBrlyMLocation = htonl64(rec->refBrlyMLocation);
	uint _xVisStart = htonl(rec->xVisStart);
	uint _xVisStop = htonl(rec->xVisStop);

	const char* vals[] = {
		(char*) &_x1VisStart,
		(char*) &_x1VisStop,
		(char*) &_refBrlyMFlight,
		(char*) &_refBrlyMLocation,
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

	res = PQexecPrepared(dbs, "TblBrlyRMFlightMLocation_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMFlightMLocation::insertRst(
			ListBrlyRMFlightMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMFlightMLocation::updateRec(
			BrlyRMFlightMLocation* rec
		) {
	PGresult* res;

	uint _x1VisStart = htonl(rec->x1VisStart);
	uint _x1VisStop = htonl(rec->x1VisStop);
	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	ubigint _refBrlyMLocation = htonl64(rec->refBrlyMLocation);
	uint _xVisStart = htonl(rec->xVisStart);
	uint _xVisStop = htonl(rec->xVisStop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1VisStart,
		(char*) &_x1VisStop,
		(char*) &_refBrlyMFlight,
		(char*) &_refBrlyMLocation,
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

	res = PQexecPrepared(dbs, "TblBrlyRMFlightMLocation_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMFlightMLocation::updateRst(
			ListBrlyRMFlightMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMFlightMLocation::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMFlightMLocation_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMFlightMLocation_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMFlightMLocation::loadRecByRef(
			ubigint ref
			, BrlyRMFlightMLocation** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMFlightMLocation_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMFlightMLocation::loadRstByFlt(
			ubigint refBrlyMFlight
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	ubigint _refBrlyMFlight = htonl64(refBrlyMFlight);

	const char* vals[] = {
		(char*) &_refBrlyMFlight
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMFlightMLocation_loadRstByFlt", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMFlightMLocation::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMFlightMLocation& rst
		) {
	ubigint _refBrlyMLocation = htonl64(refBrlyMLocation);

	const char* vals[] = {
		(char*) &_refBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMFlightMLocation_loadRstByLoc", 1, vals, l, f, append, rst);
};

