/**
  * \file BrlyORMConnectionMEquipment.cpp
  * database access for table TblBrlyORMConnectionMEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyORMConnectionMEquipment.h"

/******************************************************************************
 class BrlyORMConnectionMEquipment
 ******************************************************************************/

BrlyORMConnectionMEquipment::BrlyORMConnectionMEquipment(
			const ubigint ref
			, const ubigint refBrlyMConnection
			, const uint x1Start
			, const uint ixBrlyVOolop
			, const ubigint pr1RefLR
			, const ubigint pr2RefLR
		) {

	this->ref = ref;
	this->refBrlyMConnection = refBrlyMConnection;
	this->x1Start = x1Start;
	this->ixBrlyVOolop = ixBrlyVOolop;
	this->pr1RefLR = pr1RefLR;
	this->pr2RefLR = pr2RefLR;
};

bool BrlyORMConnectionMEquipment::operator==(
			const BrlyORMConnectionMEquipment& comp
		) {
	return false;
};

bool BrlyORMConnectionMEquipment::operator!=(
			const BrlyORMConnectionMEquipment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyORMConnectionMEquipment
 ******************************************************************************/

ListBrlyORMConnectionMEquipment::ListBrlyORMConnectionMEquipment() {
};

ListBrlyORMConnectionMEquipment::ListBrlyORMConnectionMEquipment(
			const ListBrlyORMConnectionMEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyORMConnectionMEquipment(*(src.nodes[i]));
};

ListBrlyORMConnectionMEquipment::~ListBrlyORMConnectionMEquipment() {
	clear();
};

void ListBrlyORMConnectionMEquipment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyORMConnectionMEquipment::size() const {
	return(nodes.size());
};

void ListBrlyORMConnectionMEquipment::append(
			BrlyORMConnectionMEquipment* rec
		) {
	nodes.push_back(rec);
};

BrlyORMConnectionMEquipment* ListBrlyORMConnectionMEquipment::operator[](
			const uint ix
		) {
	BrlyORMConnectionMEquipment* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyORMConnectionMEquipment& ListBrlyORMConnectionMEquipment::operator=(
			const ListBrlyORMConnectionMEquipment& src
		) {
	BrlyORMConnectionMEquipment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyORMConnectionMEquipment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyORMConnectionMEquipment::operator==(
			const ListBrlyORMConnectionMEquipment& comp
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

bool ListBrlyORMConnectionMEquipment::operator!=(
			const ListBrlyORMConnectionMEquipment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyORMConnectionMEquipment
 ******************************************************************************/

TblBrlyORMConnectionMEquipment::TblBrlyORMConnectionMEquipment() {
};

TblBrlyORMConnectionMEquipment::~TblBrlyORMConnectionMEquipment() {
};

bool TblBrlyORMConnectionMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyORMConnectionMEquipment** rec
		) {
	return false;
};

ubigint TblBrlyORMConnectionMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	return 0;
};

void TblBrlyORMConnectionMEquipment::insertRec(
			BrlyORMConnectionMEquipment* rec
		) {
};

ubigint TblBrlyORMConnectionMEquipment::insertNewRec(
			BrlyORMConnectionMEquipment** rec
			, const ubigint refBrlyMConnection
			, const uint x1Start
			, const uint ixBrlyVOolop
			, const ubigint pr1RefLR
			, const ubigint pr2RefLR
		) {
	ubigint retval = 0;
	BrlyORMConnectionMEquipment* _rec = NULL;

	_rec = new BrlyORMConnectionMEquipment(0, refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyORMConnectionMEquipment::appendNewRecToRst(
			ListBrlyORMConnectionMEquipment& rst
			, BrlyORMConnectionMEquipment** rec
			, const ubigint refBrlyMConnection
			, const uint x1Start
			, const uint ixBrlyVOolop
			, const ubigint pr1RefLR
			, const ubigint pr2RefLR
		) {
	ubigint retval = 0;
	BrlyORMConnectionMEquipment* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyORMConnectionMEquipment::insertRst(
			ListBrlyORMConnectionMEquipment& rst
			, bool transact
		) {
};

void TblBrlyORMConnectionMEquipment::updateRec(
			BrlyORMConnectionMEquipment* rec
		) {
};

void TblBrlyORMConnectionMEquipment::updateRst(
			ListBrlyORMConnectionMEquipment& rst
			, bool transact
		) {
};

void TblBrlyORMConnectionMEquipment::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyORMConnectionMEquipment::loadRecByRef(
			ubigint ref
			, BrlyORMConnectionMEquipment** rec
		) {
	return false;
};

bool TblBrlyORMConnectionMEquipment::loadRecByP1lP2lLop(
			ubigint pr1RefLR
			, ubigint pr2RefLR
			, uint ixBrlyVOolop
			, BrlyORMConnectionMEquipment** rec
		) {
	return false;
};

ubigint TblBrlyORMConnectionMEquipment::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	return 0;
};

ubigint TblBrlyORMConnectionMEquipment::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	ubigint numload = 0;
	BrlyORMConnectionMEquipment* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyORMConnectionMEquipment
 ******************************************************************************/

MyTblBrlyORMConnectionMEquipment::MyTblBrlyORMConnectionMEquipment() : TblBrlyORMConnectionMEquipment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyORMConnectionMEquipment::~MyTblBrlyORMConnectionMEquipment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyORMConnectionMEquipment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyORMConnectionMEquipment (refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyORMConnectionMEquipment SET refBrlyMConnection = ?, x1Start = ?, ixBrlyVOolop = ?, pr1RefLR = ?, pr2RefLR = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyORMConnectionMEquipment WHERE ref = ?", false);
};

bool MyTblBrlyORMConnectionMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyORMConnectionMEquipment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyORMConnectionMEquipment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyORMConnectionMEquipment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyORMConnectionMEquipment();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMConnection = atoll((char*) dbrow[1]); else _rec->refBrlyMConnection = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixBrlyVOolop = atol((char*) dbrow[3]); else _rec->ixBrlyVOolop = 0;
		if (dbrow[4]) _rec->pr1RefLR = atoll((char*) dbrow[4]); else _rec->pr1RefLR = 0;
		if (dbrow[5]) _rec->pr2RefLR = atoll((char*) dbrow[5]); else _rec->pr2RefLR = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyORMConnectionMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyORMConnectionMEquipment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyORMConnectionMEquipment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyORMConnectionMEquipment();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMConnection = atoll((char*) dbrow[1]); else rec->refBrlyMConnection = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixBrlyVOolop = atol((char*) dbrow[3]); else rec->ixBrlyVOolop = 0;
			if (dbrow[4]) rec->pr1RefLR = atoll((char*) dbrow[4]); else rec->pr1RefLR = 0;
			if (dbrow[5]) rec->pr2RefLR = atoll((char*) dbrow[5]); else rec->pr2RefLR = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyORMConnectionMEquipment::insertRec(
			BrlyORMConnectionMEquipment* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMConnection,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixBrlyVOolop,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->pr1RefLR,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->pr2RefLR,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyORMConnectionMEquipment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyORMConnectionMEquipment / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyORMConnectionMEquipment::insertRst(
			ListBrlyORMConnectionMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyORMConnectionMEquipment::updateRec(
			BrlyORMConnectionMEquipment* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMConnection,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixBrlyVOolop,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->pr1RefLR,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->pr2RefLR,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyORMConnectionMEquipment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyORMConnectionMEquipment / stmtUpdateRec)\n");
};

void MyTblBrlyORMConnectionMEquipment::updateRst(
			ListBrlyORMConnectionMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyORMConnectionMEquipment::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyORMConnectionMEquipment / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyORMConnectionMEquipment / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyORMConnectionMEquipment::loadRecByRef(
			ubigint ref
			, BrlyORMConnectionMEquipment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyORMConnectionMEquipment WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyORMConnectionMEquipment::loadRecByP1lP2lLop(
			ubigint pr1RefLR
			, ubigint pr2RefLR
			, uint ixBrlyVOolop
			, BrlyORMConnectionMEquipment** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR FROM TblBrlyORMConnectionMEquipment WHERE pr1RefLR = " + to_string(pr1RefLR) + " AND pr2RefLR = " + to_string(pr2RefLR) + " AND ixBrlyVOolop = " + to_string(ixBrlyVOolop) + "", rec);
};

ubigint MyTblBrlyORMConnectionMEquipment::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR FROM TblBrlyORMConnectionMEquipment WHERE refBrlyMConnection = " + to_string(refBrlyMConnection) + " ORDER BY x1Start ASC, ixBrlyVOolop ASC, ref ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyORMConnectionMEquipment
 ******************************************************************************/

PgTblBrlyORMConnectionMEquipment::PgTblBrlyORMConnectionMEquipment() : TblBrlyORMConnectionMEquipment(), PgTable() {
};

PgTblBrlyORMConnectionMEquipment::~PgTblBrlyORMConnectionMEquipment() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyORMConnectionMEquipment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyORMConnectionMEquipment_insertRec", "INSERT INTO TblBrlyORMConnectionMEquipment (refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyORMConnectionMEquipment_updateRec", "UPDATE TblBrlyORMConnectionMEquipment SET refBrlyMConnection = $1, x1Start = $2, ixBrlyVOolop = $3, pr1RefLR = $4, pr2RefLR = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyORMConnectionMEquipment_removeRecByRef", "DELETE FROM TblBrlyORMConnectionMEquipment WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyORMConnectionMEquipment_loadRecByRef", "SELECT ref, refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR FROM TblBrlyORMConnectionMEquipment WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyORMConnectionMEquipment_loadRecByP1lP2lLop", "SELECT ref, refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR FROM TblBrlyORMConnectionMEquipment WHERE pr1RefLR = $1 AND pr2RefLR = $2 AND ixBrlyVOolop = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyORMConnectionMEquipment_loadRstByCon", "SELECT ref, refBrlyMConnection, x1Start, ixBrlyVOolop, pr1RefLR, pr2RefLR FROM TblBrlyORMConnectionMEquipment WHERE refBrlyMConnection = $1 ORDER BY x1Start ASC, ixBrlyVOolop ASC, ref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyORMConnectionMEquipment::loadRec(
			PGresult* res
			, BrlyORMConnectionMEquipment** rec
		) {
	char* ptr;

	BrlyORMConnectionMEquipment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyORMConnectionMEquipment();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixbrlyvoolop"),
			PQfnumber(res, "pr1reflr"),
			PQfnumber(res, "pr2reflr")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMConnection = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixBrlyVOolop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->pr1RefLR = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->pr2RefLR = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyORMConnectionMEquipment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyORMConnectionMEquipment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixbrlyvoolop"),
			PQfnumber(res, "pr1reflr"),
			PQfnumber(res, "pr2reflr")
		};

		while (numread < numrow) {
			rec = new BrlyORMConnectionMEquipment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMConnection = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixBrlyVOolop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->pr1RefLR = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->pr2RefLR = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyORMConnectionMEquipment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyORMConnectionMEquipment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyORMConnectionMEquipment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyORMConnectionMEquipment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyORMConnectionMEquipment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyORMConnectionMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyORMConnectionMEquipment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyORMConnectionMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyORMConnectionMEquipment::insertRec(
			BrlyORMConnectionMEquipment* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixBrlyVOolop = htonl(rec->ixBrlyVOolop);
	ubigint _pr1RefLR = htonl64(rec->pr1RefLR);
	ubigint _pr2RefLR = htonl64(rec->pr2RefLR);

	const char* vals[] = {
		(char*) &_refBrlyMConnection,
		(char*) &_x1Start,
		(char*) &_ixBrlyVOolop,
		(char*) &_pr1RefLR,
		(char*) &_pr2RefLR
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyORMConnectionMEquipment_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyORMConnectionMEquipment_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyORMConnectionMEquipment::insertRst(
			ListBrlyORMConnectionMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyORMConnectionMEquipment::updateRec(
			BrlyORMConnectionMEquipment* rec
		) {
	PGresult* res;

	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixBrlyVOolop = htonl(rec->ixBrlyVOolop);
	ubigint _pr1RefLR = htonl64(rec->pr1RefLR);
	ubigint _pr2RefLR = htonl64(rec->pr2RefLR);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMConnection,
		(char*) &_x1Start,
		(char*) &_ixBrlyVOolop,
		(char*) &_pr1RefLR,
		(char*) &_pr2RefLR,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyORMConnectionMEquipment_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyORMConnectionMEquipment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyORMConnectionMEquipment::updateRst(
			ListBrlyORMConnectionMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyORMConnectionMEquipment::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyORMConnectionMEquipment_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyORMConnectionMEquipment_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyORMConnectionMEquipment::loadRecByRef(
			ubigint ref
			, BrlyORMConnectionMEquipment** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyORMConnectionMEquipment_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyORMConnectionMEquipment::loadRecByP1lP2lLop(
			ubigint pr1RefLR
			, ubigint pr2RefLR
			, uint ixBrlyVOolop
			, BrlyORMConnectionMEquipment** rec
		) {
	ubigint _pr1RefLR = htonl64(pr1RefLR);
	ubigint _pr2RefLR = htonl64(pr2RefLR);
	uint _ixBrlyVOolop = htonl(ixBrlyVOolop);

	const char* vals[] = {
		(char*) &_pr1RefLR,
		(char*) &_pr2RefLR,
		(char*) &_ixBrlyVOolop
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblBrlyORMConnectionMEquipment_loadRecByP1lP2lLop", 3, vals, l, f, rec);
};

ubigint PgTblBrlyORMConnectionMEquipment::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyORMConnectionMEquipment& rst
		) {
	ubigint _refBrlyMConnection = htonl64(refBrlyMConnection);

	const char* vals[] = {
		(char*) &_refBrlyMConnection
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyORMConnectionMEquipment_loadRstByCon", 1, vals, l, f, append, rst);
};

