/**
  * \file BrlyRMConnectionMSegment.cpp
  * database access for table TblBrlyRMConnectionMSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMConnectionMSegment.h"

/******************************************************************************
 class BrlyRMConnectionMSegment
 ******************************************************************************/

BrlyRMConnectionMSegment::BrlyRMConnectionMSegment(
			const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint refBrlyMConnection
			, const ubigint refBrlyMSegment
		) {

	this->ref = ref;
	this->x1Start = x1Start;
	this->x1Stop = x1Stop;
	this->x2Legphi0 = x2Legphi0;
	this->x2Legphi1 = x2Legphi1;
	this->refBrlyMConnection = refBrlyMConnection;
	this->refBrlyMSegment = refBrlyMSegment;
};

bool BrlyRMConnectionMSegment::operator==(
			const BrlyRMConnectionMSegment& comp
		) {
	return false;
};

bool BrlyRMConnectionMSegment::operator!=(
			const BrlyRMConnectionMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMConnectionMSegment
 ******************************************************************************/

ListBrlyRMConnectionMSegment::ListBrlyRMConnectionMSegment() {
};

ListBrlyRMConnectionMSegment::ListBrlyRMConnectionMSegment(
			const ListBrlyRMConnectionMSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMConnectionMSegment(*(src.nodes[i]));
};

ListBrlyRMConnectionMSegment::~ListBrlyRMConnectionMSegment() {
	clear();
};

void ListBrlyRMConnectionMSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMConnectionMSegment::size() const {
	return(nodes.size());
};

void ListBrlyRMConnectionMSegment::append(
			BrlyRMConnectionMSegment* rec
		) {
	nodes.push_back(rec);
};

BrlyRMConnectionMSegment* ListBrlyRMConnectionMSegment::operator[](
			const uint ix
		) {
	BrlyRMConnectionMSegment* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMConnectionMSegment& ListBrlyRMConnectionMSegment::operator=(
			const ListBrlyRMConnectionMSegment& src
		) {
	BrlyRMConnectionMSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMConnectionMSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMConnectionMSegment::operator==(
			const ListBrlyRMConnectionMSegment& comp
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

bool ListBrlyRMConnectionMSegment::operator!=(
			const ListBrlyRMConnectionMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMConnectionMSegment
 ******************************************************************************/

TblBrlyRMConnectionMSegment::TblBrlyRMConnectionMSegment() {
};

TblBrlyRMConnectionMSegment::~TblBrlyRMConnectionMSegment() {
};

bool TblBrlyRMConnectionMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMConnectionMSegment** rec
		) {
	return false;
};

ubigint TblBrlyRMConnectionMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	return 0;
};

void TblBrlyRMConnectionMSegment::insertRec(
			BrlyRMConnectionMSegment* rec
		) {
};

ubigint TblBrlyRMConnectionMSegment::insertNewRec(
			BrlyRMConnectionMSegment** rec
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint refBrlyMConnection
			, const ubigint refBrlyMSegment
		) {
	ubigint retval = 0;
	BrlyRMConnectionMSegment* _rec = NULL;

	_rec = new BrlyRMConnectionMSegment(0, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMConnectionMSegment::appendNewRecToRst(
			ListBrlyRMConnectionMSegment& rst
			, BrlyRMConnectionMSegment** rec
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint refBrlyMConnection
			, const ubigint refBrlyMSegment
		) {
	ubigint retval = 0;
	BrlyRMConnectionMSegment* _rec = NULL;

	retval = insertNewRec(&_rec, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMConnectionMSegment::insertRst(
			ListBrlyRMConnectionMSegment& rst
			, bool transact
		) {
};

void TblBrlyRMConnectionMSegment::updateRec(
			BrlyRMConnectionMSegment* rec
		) {
};

void TblBrlyRMConnectionMSegment::updateRst(
			ListBrlyRMConnectionMSegment& rst
			, bool transact
		) {
};

void TblBrlyRMConnectionMSegment::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMConnectionMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMConnectionMSegment** rec
		) {
	return false;
};

ubigint TblBrlyRMConnectionMSegment::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	return 0;
};

ubigint TblBrlyRMConnectionMSegment::loadRstBySeg(
			ubigint refBrlyMSegment
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	return 0;
};

ubigint TblBrlyRMConnectionMSegment::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	ubigint numload = 0;
	BrlyRMConnectionMSegment* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMConnectionMSegment
 ******************************************************************************/

MyTblBrlyRMConnectionMSegment::MyTblBrlyRMConnectionMSegment() : TblBrlyRMConnectionMSegment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMConnectionMSegment::~MyTblBrlyRMConnectionMSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMConnectionMSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMConnectionMSegment (x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMConnectionMSegment SET x1Start = ?, x1Stop = ?, x2Legphi0 = ?, x2Legphi1 = ?, refBrlyMConnection = ?, refBrlyMSegment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMConnectionMSegment WHERE ref = ?", false);
};

bool MyTblBrlyRMConnectionMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMConnectionMSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMConnectionMSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMConnectionMSegment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMConnectionMSegment();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Start = atol((char*) dbrow[1]); else _rec->x1Start = 0;
		if (dbrow[2]) _rec->x1Stop = atol((char*) dbrow[2]); else _rec->x1Stop = 0;
		if (dbrow[3]) _rec->x2Legphi0 = atof((char*) dbrow[3]); else _rec->x2Legphi0 = 0.0;
		if (dbrow[4]) _rec->x2Legphi1 = atof((char*) dbrow[4]); else _rec->x2Legphi1 = 0.0;
		if (dbrow[5]) _rec->refBrlyMConnection = atoll((char*) dbrow[5]); else _rec->refBrlyMConnection = 0;
		if (dbrow[6]) _rec->refBrlyMSegment = atoll((char*) dbrow[6]); else _rec->refBrlyMSegment = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMConnectionMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMConnectionMSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMConnectionMSegment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMConnectionMSegment();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Start = atol((char*) dbrow[1]); else rec->x1Start = 0;
			if (dbrow[2]) rec->x1Stop = atol((char*) dbrow[2]); else rec->x1Stop = 0;
			if (dbrow[3]) rec->x2Legphi0 = atof((char*) dbrow[3]); else rec->x2Legphi0 = 0.0;
			if (dbrow[4]) rec->x2Legphi1 = atof((char*) dbrow[4]); else rec->x2Legphi1 = 0.0;
			if (dbrow[5]) rec->refBrlyMConnection = atoll((char*) dbrow[5]); else rec->refBrlyMConnection = 0;
			if (dbrow[6]) rec->refBrlyMSegment = atoll((char*) dbrow[6]); else rec->refBrlyMSegment = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMConnectionMSegment::insertRec(
			BrlyRMConnectionMSegment* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x2Legphi0,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x2Legphi1,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMConnection,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMSegment,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMConnectionMSegment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMConnectionMSegment / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMConnectionMSegment::insertRst(
			ListBrlyRMConnectionMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMConnectionMSegment::updateRec(
			BrlyRMConnectionMSegment* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x2Legphi0,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x2Legphi1,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMConnection,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMSegment,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMConnectionMSegment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMConnectionMSegment / stmtUpdateRec)\n");
};

void MyTblBrlyRMConnectionMSegment::updateRst(
			ListBrlyRMConnectionMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMConnectionMSegment::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMConnectionMSegment / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMConnectionMSegment / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMConnectionMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMConnectionMSegment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMConnectionMSegment WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMConnectionMSegment::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment FROM TblBrlyRMConnectionMSegment WHERE refBrlyMConnection = " + to_string(refBrlyMConnection) + " ORDER BY x1Start ASC", append, rst);
};

ubigint MyTblBrlyRMConnectionMSegment::loadRstBySeg(
			ubigint refBrlyMSegment
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment FROM TblBrlyRMConnectionMSegment WHERE refBrlyMSegment = " + to_string(refBrlyMSegment) + " ORDER BY x1Start ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMConnectionMSegment
 ******************************************************************************/

PgTblBrlyRMConnectionMSegment::PgTblBrlyRMConnectionMSegment() : TblBrlyRMConnectionMSegment(), PgTable() {
};

PgTblBrlyRMConnectionMSegment::~PgTblBrlyRMConnectionMSegment() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMConnectionMSegment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMConnectionMSegment_insertRec", "INSERT INTO TblBrlyRMConnectionMSegment (x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMConnectionMSegment_updateRec", "UPDATE TblBrlyRMConnectionMSegment SET x1Start = $1, x1Stop = $2, x2Legphi0 = $3, x2Legphi1 = $4, refBrlyMConnection = $5, refBrlyMSegment = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMConnectionMSegment_removeRecByRef", "DELETE FROM TblBrlyRMConnectionMSegment WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMConnectionMSegment_loadRecByRef", "SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment FROM TblBrlyRMConnectionMSegment WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMConnectionMSegment_loadRstByCon", "SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment FROM TblBrlyRMConnectionMSegment WHERE refBrlyMConnection = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMConnectionMSegment_loadRstBySeg", "SELECT ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, refBrlyMConnection, refBrlyMSegment FROM TblBrlyRMConnectionMSegment WHERE refBrlyMSegment = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMConnectionMSegment::loadRec(
			PGresult* res
			, BrlyRMConnectionMSegment** rec
		) {
	char* ptr;

	BrlyRMConnectionMSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMConnectionMSegment();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2legphi0"),
			PQfnumber(res, "x2legphi1"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "refbrlymsegment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2Legphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2Legphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refBrlyMConnection = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refBrlyMSegment = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMConnectionMSegment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMConnectionMSegment* rec;

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
			PQfnumber(res, "refbrlymsegment")
		};

		while (numread < numrow) {
			rec = new BrlyRMConnectionMSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2Legphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2Legphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refBrlyMConnection = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refBrlyMSegment = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMConnectionMSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMConnectionMSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMSegment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMConnectionMSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMSegment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMConnectionMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMConnectionMSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMConnectionMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMConnectionMSegment::insertRec(
			BrlyRMConnectionMSegment* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2Legphi0 = to_string(rec->x2Legphi0);
	string _x2Legphi1 = to_string(rec->x2Legphi1);
	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	ubigint _refBrlyMSegment = htonl64(rec->refBrlyMSegment);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2Legphi0.c_str(),
		_x2Legphi1.c_str(),
		(char*) &_refBrlyMConnection,
		(char*) &_refBrlyMSegment
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

	res = PQexecPrepared(dbs, "TblBrlyRMConnectionMSegment_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMSegment_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMConnectionMSegment::insertRst(
			ListBrlyRMConnectionMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMConnectionMSegment::updateRec(
			BrlyRMConnectionMSegment* rec
		) {
	PGresult* res;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2Legphi0 = to_string(rec->x2Legphi0);
	string _x2Legphi1 = to_string(rec->x2Legphi1);
	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	ubigint _refBrlyMSegment = htonl64(rec->refBrlyMSegment);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2Legphi0.c_str(),
		_x2Legphi1.c_str(),
		(char*) &_refBrlyMConnection,
		(char*) &_refBrlyMSegment,
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

	res = PQexecPrepared(dbs, "TblBrlyRMConnectionMSegment_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMSegment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMConnectionMSegment::updateRst(
			ListBrlyRMConnectionMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMConnectionMSegment::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMConnectionMSegment_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMConnectionMSegment_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMConnectionMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMConnectionMSegment** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMConnectionMSegment_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMConnectionMSegment::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	ubigint _refBrlyMConnection = htonl64(refBrlyMConnection);

	const char* vals[] = {
		(char*) &_refBrlyMConnection
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMConnectionMSegment_loadRstByCon", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMConnectionMSegment::loadRstBySeg(
			ubigint refBrlyMSegment
			, const bool append
			, ListBrlyRMConnectionMSegment& rst
		) {
	ubigint _refBrlyMSegment = htonl64(refBrlyMSegment);

	const char* vals[] = {
		(char*) &_refBrlyMSegment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMConnectionMSegment_loadRstBySeg", 1, vals, l, f, append, rst);
};

