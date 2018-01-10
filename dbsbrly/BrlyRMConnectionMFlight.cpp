/**
  * \file BrlyRMConnectionMFlight.cpp
  * database access for table TblBrlyRMConnectionMFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMConnectionMFlight.h"

/******************************************************************************
 class BrlyRMConnectionMFlight
 ******************************************************************************/

BrlyRMConnectionMFlight::BrlyRMConnectionMFlight(
			const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint refBrlyMConnection
			, const ubigint refBrlyMFlight
		) {

	this->ref = ref;
	this->x1Start = x1Start;
	this->x1Stop = x1Stop;
	this->x2Legphi0 = x2Legphi0;
	this->x2Legphi1 = x2Legphi1;
	this->refBrlyMConnection = refBrlyMConnection;
	this->refBrlyMFlight = refBrlyMFlight;
};

bool BrlyRMConnectionMFlight::operator==(
			const BrlyRMConnectionMFlight& comp
		) {
	return false;
};

bool BrlyRMConnectionMFlight::operator!=(
			const BrlyRMConnectionMFlight& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMConnectionMFlight
 ******************************************************************************/

ListBrlyRMConnectionMFlight::ListBrlyRMConnectionMFlight() {
};

ListBrlyRMConnectionMFlight::ListBrlyRMConnectionMFlight(
			const ListBrlyRMConnectionMFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMConnectionMFlight(*(src.nodes[i]));
};

ListBrlyRMConnectionMFlight::~ListBrlyRMConnectionMFlight() {
	clear();
};

void ListBrlyRMConnectionMFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMConnectionMFlight::size() const {
	return(nodes.size());
};

void ListBrlyRMConnectionMFlight::append(
			BrlyRMConnectionMFlight* rec
		) {
	nodes.push_back(rec);
};

BrlyRMConnectionMFlight* ListBrlyRMConnectionMFlight::operator[](
			const uint ix
		) {
	BrlyRMConnectionMFlight* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMConnectionMFlight& ListBrlyRMConnectionMFlight::operator=(
			const ListBrlyRMConnectionMFlight& src
		) {
	BrlyRMConnectionMFlight* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMConnectionMFlight(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMConnectionMFlight::operator==(
			const ListBrlyRMConnectionMFlight& comp
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

bool ListBrlyRMConnectionMFlight::operator!=(
			const ListBrlyRMConnectionMFlight& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMConnectionMFlight
 ******************************************************************************/

TblBrlyRMConnectionMFlight::TblBrlyRMConnectionMFlight() {
};

TblBrlyRMConnectionMFlight::~TblBrlyRMConnectionMFlight() {
};

bool TblBrlyRMConnectionMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyRMConnectionMFlight** rec
		) {
	return false;
};

ubigint TblBrlyRMConnectionMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	return 0;
};

void TblBrlyRMConnectionMFlight::insertRec(
			BrlyRMConnectionMFlight* rec
		) {
};

ubigint TblBrlyRMConnectionMFlight::insertNewRec(
			BrlyRMConnectionMFlight** rec
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint refBrlyMConnection
			, const ubigint refBrlyMFlight
		) {
	ubigint retval = 0;
	BrlyRMConnectionMFlight* _rec = NULL;

	_rec = new BrlyRMConnectionMFlight(0, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMConnectionMFlight::appendNewRecToRst(
			ListBrlyRMConnectionMFlight& rst
			, BrlyRMConnectionMFlight** rec
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint refBrlyMConnection
			, const ubigint refBrlyMFlight
		) {
	ubigint retval = 0;
	BrlyRMConnectionMFlight* _rec = NULL;

	retval = insertNewRec(&_rec, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMConnectionMFlight::insertRst(
			ListBrlyRMConnectionMFlight& rst
			, bool transact
		) {
};

void TblBrlyRMConnectionMFlight::updateRec(
			BrlyRMConnectionMFlight* rec
		) {
};

void TblBrlyRMConnectionMFlight::updateRst(
			ListBrlyRMConnectionMFlight& rst
			, bool transact
		) {
};

void TblBrlyRMConnectionMFlight::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMConnectionMFlight::loadRecByRef(
			ubigint ref
			, BrlyRMConnectionMFlight** rec
		) {
	return false;
};

ubigint TblBrlyRMConnectionMFlight::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	return 0;
};

ubigint TblBrlyRMConnectionMFlight::loadRstByFlt(
			ubigint refBrlyMFlight
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	return 0;
};

ubigint TblBrlyRMConnectionMFlight::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	ubigint numload = 0;
	BrlyRMConnectionMFlight* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMConnectionMFlight
 ******************************************************************************/

MyTblBrlyRMConnectionMFlight::MyTblBrlyRMConnectionMFlight() : TblBrlyRMConnectionMFlight(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMConnectionMFlight::~MyTblBrlyRMConnectionMFlight() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMConnectionMFlight::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMConnectionMFlight (x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMConnectionMFlight SET x1Start = ?, x1Stop = ?, x2Legphi0 = ?, x2Legphi1 = ?, refBrlyMConnection = ?, refBrlyMFlight = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMConnectionMFlight WHERE ref = ?", false);
};

bool MyTblBrlyRMConnectionMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyRMConnectionMFlight** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMConnectionMFlight* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMConnectionMFlight / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMConnectionMFlight();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Start = atol((char*) dbrow[1]); else _rec->x1Start = 0;
		if (dbrow[2]) _rec->x1Stop = atol((char*) dbrow[2]); else _rec->x1Stop = 0;
		if (dbrow[3]) _rec->x2Legphi0 = atof((char*) dbrow[3]); else _rec->x2Legphi0 = 0.0;
		if (dbrow[4]) _rec->x2Legphi1 = atof((char*) dbrow[4]); else _rec->x2Legphi1 = 0.0;
		if (dbrow[5]) _rec->refBrlyMConnection = atoll((char*) dbrow[5]); else _rec->refBrlyMConnection = 0;
		if (dbrow[6]) _rec->refBrlyMFlight = atoll((char*) dbrow[6]); else _rec->refBrlyMFlight = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMConnectionMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMConnectionMFlight* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMConnectionMFlight / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMConnectionMFlight();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Start = atol((char*) dbrow[1]); else rec->x1Start = 0;
			if (dbrow[2]) rec->x1Stop = atol((char*) dbrow[2]); else rec->x1Stop = 0;
			if (dbrow[3]) rec->x2Legphi0 = atof((char*) dbrow[3]); else rec->x2Legphi0 = 0.0;
			if (dbrow[4]) rec->x2Legphi1 = atof((char*) dbrow[4]); else rec->x2Legphi1 = 0.0;
			if (dbrow[5]) rec->refBrlyMConnection = atoll((char*) dbrow[5]); else rec->refBrlyMConnection = 0;
			if (dbrow[6]) rec->refBrlyMFlight = atoll((char*) dbrow[6]); else rec->refBrlyMFlight = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMConnectionMFlight::insertRec(
			BrlyRMConnectionMFlight* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x2Legphi0,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x2Legphi1,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMConnection,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMFlight,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMConnectionMFlight / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMConnectionMFlight / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMConnectionMFlight::insertRst(
			ListBrlyRMConnectionMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMConnectionMFlight::updateRec(
			BrlyRMConnectionMFlight* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x2Legphi0,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x2Legphi1,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMConnection,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMFlight,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMConnectionMFlight / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMConnectionMFlight / stmtUpdateRec)\n");
};

void MyTblBrlyRMConnectionMFlight::updateRst(
			ListBrlyRMConnectionMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMConnectionMFlight::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMConnectionMFlight / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMConnectionMFlight / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMConnectionMFlight::loadRecByRef(
			ubigint ref
			, BrlyRMConnectionMFlight** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMConnectionMFlight WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMConnectionMFlight::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight FROM TblBrlyRMConnectionMFlight WHERE refBrlyMConnection = " + to_string(refBrlyMConnection) + " ORDER BY x1Start ASC", append, rst);
};

ubigint MyTblBrlyRMConnectionMFlight::loadRstByFlt(
			ubigint refBrlyMFlight
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight FROM TblBrlyRMConnectionMFlight WHERE refBrlyMFlight = " + to_string(refBrlyMFlight) + " ORDER BY x1Start ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMConnectionMFlight
 ******************************************************************************/

PgTblBrlyRMConnectionMFlight::PgTblBrlyRMConnectionMFlight() : TblBrlyRMConnectionMFlight(), PgTable() {
};

PgTblBrlyRMConnectionMFlight::~PgTblBrlyRMConnectionMFlight() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMConnectionMFlight::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMConnectionMFlight_insertRec", "INSERT INTO TblBrlyRMConnectionMFlight (x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMConnectionMFlight_updateRec", "UPDATE TblBrlyRMConnectionMFlight SET x1Start = $1, x1Stop = $2, x2Legphi0 = $3, x2Legphi1 = $4, refBrlyMConnection = $5, refBrlyMFlight = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMConnectionMFlight_removeRecByRef", "DELETE FROM TblBrlyRMConnectionMFlight WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMConnectionMFlight_loadRecByRef", "SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight FROM TblBrlyRMConnectionMFlight WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMConnectionMFlight_loadRstByCon", "SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight FROM TblBrlyRMConnectionMFlight WHERE refBrlyMConnection = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMConnectionMFlight_loadRstByFlt", "SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMFlight FROM TblBrlyRMConnectionMFlight WHERE refBrlyMFlight = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMConnectionMFlight::loadRec(
			PGresult* res
			, BrlyRMConnectionMFlight** rec
		) {
	char* ptr;

	BrlyRMConnectionMFlight* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMConnectionMFlight();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2legphi0"),
			PQfnumber(res, "x2legphi1"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "refbrlymflight")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2Legphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2Legphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refBrlyMConnection = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refBrlyMFlight = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMConnectionMFlight::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMConnectionMFlight* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2legphi0"),
			PQfnumber(res, "x2legphi1"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "refbrlymflight")
		};

		while (numread < numrow) {
			rec = new BrlyRMConnectionMFlight();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2Legphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2Legphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refBrlyMConnection = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refBrlyMFlight = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMConnectionMFlight::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMConnectionMFlight** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMFlight / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMConnectionMFlight::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMFlight / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMConnectionMFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyRMConnectionMFlight** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMConnectionMFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMConnectionMFlight::insertRec(
			BrlyRMConnectionMFlight* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2Legphi0 = to_string(rec->x2Legphi0);
	string _x2Legphi1 = to_string(rec->x2Legphi1);
	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2Legphi0.c_str(),
		_x2Legphi1.c_str(),
		(char*) &_refBrlyMConnection,
		(char*) &_refBrlyMFlight
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMConnectionMFlight_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMFlight_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMConnectionMFlight::insertRst(
			ListBrlyRMConnectionMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMConnectionMFlight::updateRec(
			BrlyRMConnectionMFlight* rec
		) {
	PGresult* res;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2Legphi0 = to_string(rec->x2Legphi0);
	string _x2Legphi1 = to_string(rec->x2Legphi1);
	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2Legphi0.c_str(),
		_x2Legphi1.c_str(),
		(char*) &_refBrlyMConnection,
		(char*) &_refBrlyMFlight,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMConnectionMFlight_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMFlight_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMConnectionMFlight::updateRst(
			ListBrlyRMConnectionMFlight& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMConnectionMFlight::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMConnectionMFlight_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMFlight_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMConnectionMFlight::loadRecByRef(
			ubigint ref
			, BrlyRMConnectionMFlight** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMConnectionMFlight_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMConnectionMFlight::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	ubigint _refBrlyMConnection = htonl64(refBrlyMConnection);

	const char* vals[] = {
		(char*) &_refBrlyMConnection
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMConnectionMFlight_loadRstByCon", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMConnectionMFlight::loadRstByFlt(
			ubigint refBrlyMFlight
			, const bool append
			, ListBrlyRMConnectionMFlight& rst
		) {
	ubigint _refBrlyMFlight = htonl64(refBrlyMFlight);

	const char* vals[] = {
		(char*) &_refBrlyMFlight
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMConnectionMFlight_loadRstByFlt", 1, vals, l, f, append, rst);
};

