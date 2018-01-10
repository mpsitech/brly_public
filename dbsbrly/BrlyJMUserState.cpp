/**
  * \file BrlyJMUserState.cpp
  * database access for table TblBrlyJMUserState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyJMUserState.h"

/******************************************************************************
 class BrlyJMUserState
 ******************************************************************************/

BrlyJMUserState::BrlyJMUserState(
			const ubigint ref
			, const ubigint refBrlyMUser
			, const uint x1Startd
			, const uint ixVState
		) {

	this->ref = ref;
	this->refBrlyMUser = refBrlyMUser;
	this->x1Startd = x1Startd;
	this->ixVState = ixVState;
};

bool BrlyJMUserState::operator==(
			const BrlyJMUserState& comp
		) {
	return false;
};

bool BrlyJMUserState::operator!=(
			const BrlyJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyJMUserState
 ******************************************************************************/

ListBrlyJMUserState::ListBrlyJMUserState() {
};

ListBrlyJMUserState::ListBrlyJMUserState(
			const ListBrlyJMUserState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyJMUserState(*(src.nodes[i]));
};

ListBrlyJMUserState::~ListBrlyJMUserState() {
	clear();
};

void ListBrlyJMUserState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyJMUserState::size() const {
	return(nodes.size());
};

void ListBrlyJMUserState::append(
			BrlyJMUserState* rec
		) {
	nodes.push_back(rec);
};

BrlyJMUserState* ListBrlyJMUserState::operator[](
			const uint ix
		) {
	BrlyJMUserState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyJMUserState& ListBrlyJMUserState::operator=(
			const ListBrlyJMUserState& src
		) {
	BrlyJMUserState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyJMUserState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyJMUserState::operator==(
			const ListBrlyJMUserState& comp
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

bool ListBrlyJMUserState::operator!=(
			const ListBrlyJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyJMUserState
 ******************************************************************************/

TblBrlyJMUserState::TblBrlyJMUserState() {
};

TblBrlyJMUserState::~TblBrlyJMUserState() {
};

bool TblBrlyJMUserState::loadRecBySQL(
			const string& sqlstr
			, BrlyJMUserState** rec
		) {
	return false;
};

ubigint TblBrlyJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	return 0;
};

void TblBrlyJMUserState::insertRec(
			BrlyJMUserState* rec
		) {
};

ubigint TblBrlyJMUserState::insertNewRec(
			BrlyJMUserState** rec
			, const ubigint refBrlyMUser
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	BrlyJMUserState* _rec = NULL;

	_rec = new BrlyJMUserState(0, refBrlyMUser, x1Startd, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyJMUserState::appendNewRecToRst(
			ListBrlyJMUserState& rst
			, BrlyJMUserState** rec
			, const ubigint refBrlyMUser
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	BrlyJMUserState* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUser, x1Startd, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyJMUserState::insertRst(
			ListBrlyJMUserState& rst
			, bool transact
		) {
};

void TblBrlyJMUserState::updateRec(
			BrlyJMUserState* rec
		) {
};

void TblBrlyJMUserState::updateRst(
			ListBrlyJMUserState& rst
			, bool transact
		) {
};

void TblBrlyJMUserState::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyJMUserState::loadRecByRef(
			ubigint ref
			, BrlyJMUserState** rec
		) {
	return false;
};

bool TblBrlyJMUserState::loadRecByUsrSta(
			ubigint refBrlyMUser
			, uint x1Startd
			, BrlyJMUserState** rec
		) {
	return false;
};

ubigint TblBrlyJMUserState::loadRefsByUsr(
			ubigint refBrlyMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyJMUserState::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	return 0;
};

ubigint TblBrlyJMUserState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	ubigint numload = 0;
	BrlyJMUserState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyJMUserState
 ******************************************************************************/

MyTblBrlyJMUserState::MyTblBrlyJMUserState() : TblBrlyJMUserState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyJMUserState::~MyTblBrlyJMUserState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyJMUserState (refBrlyMUser, x1Startd, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyJMUserState SET refBrlyMUser = ?, x1Startd = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyJMUserState WHERE ref = ?", false);
};

bool MyTblBrlyJMUserState::loadRecBySQL(
			const string& sqlstr
			, BrlyJMUserState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyJMUserState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyJMUserState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyJMUserState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUser = atoll((char*) dbrow[1]); else _rec->refBrlyMUser = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyJMUserState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyJMUserState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyJMUserState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUser = atoll((char*) dbrow[1]); else rec->refBrlyMUser = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyJMUserState::insertRec(
			BrlyJMUserState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMUserState / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMUserState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyJMUserState::insertRst(
			ListBrlyJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyJMUserState::updateRec(
			BrlyJMUserState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMUserState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMUserState / stmtUpdateRec)\n");
};

void MyTblBrlyJMUserState::updateRst(
			ListBrlyJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyJMUserState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMUserState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMUserState / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyJMUserState::loadRecByRef(
			ubigint ref
			, BrlyJMUserState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyJMUserState WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyJMUserState::loadRecByUsrSta(
			ubigint refBrlyMUser
			, uint x1Startd
			, BrlyJMUserState** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMUser, x1Startd, ixVState FROM TblBrlyJMUserState WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblBrlyJMUserState::loadRefsByUsr(
			ubigint refBrlyMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyJMUserState WHERE refBrlyMUser = " + to_string(refBrlyMUser) + "", append, refs);
};

ubigint MyTblBrlyJMUserState::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUser, x1Startd, ixVState FROM TblBrlyJMUserState WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " ORDER BY x1Startd ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyJMUserState
 ******************************************************************************/

PgTblBrlyJMUserState::PgTblBrlyJMUserState() : TblBrlyJMUserState(), PgTable() {
};

PgTblBrlyJMUserState::~PgTblBrlyJMUserState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyJMUserState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyJMUserState_insertRec", "INSERT INTO TblBrlyJMUserState (refBrlyMUser, x1Startd, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMUserState_updateRec", "UPDATE TblBrlyJMUserState SET refBrlyMUser = $1, x1Startd = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMUserState_removeRecByRef", "DELETE FROM TblBrlyJMUserState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyJMUserState_loadRecByRef", "SELECT ref, refBrlyMUser, x1Startd, ixVState FROM TblBrlyJMUserState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyJMUserState_loadRecByUsrSta", "SELECT ref, refBrlyMUser, x1Startd, ixVState FROM TblBrlyJMUserState WHERE refBrlyMUser = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMUserState_loadRefsByUsr", "SELECT ref FROM TblBrlyJMUserState WHERE refBrlyMUser = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMUserState_loadRstByUsr", "SELECT ref, refBrlyMUser, x1Startd, ixVState FROM TblBrlyJMUserState WHERE refBrlyMUser = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyJMUserState::loadRec(
			PGresult* res
			, BrlyJMUserState** rec
		) {
	char* ptr;

	BrlyJMUserState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyJMUserState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyJMUserState::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyJMUserState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new BrlyJMUserState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyJMUserState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyJMUserState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMUserState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMUserState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMUserState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyJMUserState::loadRecBySQL(
			const string& sqlstr
			, BrlyJMUserState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyJMUserState::insertRec(
			BrlyJMUserState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_x1Startd,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyJMUserState_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMUserState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyJMUserState::insertRst(
			ListBrlyJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyJMUserState::updateRec(
			BrlyJMUserState* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_x1Startd,
		(char*) &_ixVState,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyJMUserState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMUserState_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyJMUserState::updateRst(
			ListBrlyJMUserState& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyJMUserState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyJMUserState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMUserState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyJMUserState::loadRecByRef(
			ubigint ref
			, BrlyJMUserState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyJMUserState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyJMUserState::loadRecByUsrSta(
			ubigint refBrlyMUser
			, uint x1Startd
			, BrlyJMUserState** rec
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblBrlyJMUserState_loadRecByUsrSta", 2, vals, l, f, rec);
};

ubigint PgTblBrlyJMUserState::loadRefsByUsr(
			ubigint refBrlyMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);

	const char* vals[] = {
		(char*) &_refBrlyMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyJMUserState_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyJMUserState::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyJMUserState& rst
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);

	const char* vals[] = {
		(char*) &_refBrlyMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyJMUserState_loadRstByUsr", 1, vals, l, f, append, rst);
};

