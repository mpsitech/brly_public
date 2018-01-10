/**
  * \file BrlyMSession.cpp
  * database access for table TblBrlyMSession (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMSession.h"

/******************************************************************************
 class BrlyMSession
 ******************************************************************************/

BrlyMSession::BrlyMSession(
			const ubigint ref
			, const ubigint refBrlyMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {

	this->ref = ref;
	this->refBrlyMUser = refBrlyMUser;
	this->start = start;
	this->stop = stop;
	this->Ip = Ip;
};

bool BrlyMSession::operator==(
			const BrlyMSession& comp
		) {
	return false;
};

bool BrlyMSession::operator!=(
			const BrlyMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMSession
 ******************************************************************************/

ListBrlyMSession::ListBrlyMSession() {
};

ListBrlyMSession::ListBrlyMSession(
			const ListBrlyMSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMSession(*(src.nodes[i]));
};

ListBrlyMSession::~ListBrlyMSession() {
	clear();
};

void ListBrlyMSession::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMSession::size() const {
	return(nodes.size());
};

void ListBrlyMSession::append(
			BrlyMSession* rec
		) {
	nodes.push_back(rec);
};

BrlyMSession* ListBrlyMSession::operator[](
			const uint ix
		) {
	BrlyMSession* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMSession& ListBrlyMSession::operator=(
			const ListBrlyMSession& src
		) {
	BrlyMSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMSession::operator==(
			const ListBrlyMSession& comp
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

bool ListBrlyMSession::operator!=(
			const ListBrlyMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMSession
 ******************************************************************************/

TblBrlyMSession::TblBrlyMSession() {
};

TblBrlyMSession::~TblBrlyMSession() {
};

bool TblBrlyMSession::loadRecBySQL(
			const string& sqlstr
			, BrlyMSession** rec
		) {
	return false;
};

ubigint TblBrlyMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMSession& rst
		) {
	return 0;
};

void TblBrlyMSession::insertRec(
			BrlyMSession* rec
		) {
};

ubigint TblBrlyMSession::insertNewRec(
			BrlyMSession** rec
			, const ubigint refBrlyMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	BrlyMSession* _rec = NULL;

	_rec = new BrlyMSession(0, refBrlyMUser, start, stop, Ip);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMSession::appendNewRecToRst(
			ListBrlyMSession& rst
			, BrlyMSession** rec
			, const ubigint refBrlyMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	BrlyMSession* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUser, start, stop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMSession::insertRst(
			ListBrlyMSession& rst
			, bool transact
		) {
};

void TblBrlyMSession::updateRec(
			BrlyMSession* rec
		) {
};

void TblBrlyMSession::updateRst(
			ListBrlyMSession& rst
			, bool transact
		) {
};

void TblBrlyMSession::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMSession::loadRecByRef(
			ubigint ref
			, BrlyMSession** rec
		) {
	return false;
};

ubigint TblBrlyMSession::loadRefsByUsr(
			ubigint refBrlyMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMSession::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyMSession& rst
		) {
	return 0;
};

ubigint TblBrlyMSession::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMSession& rst
		) {
	ubigint numload = 0;
	BrlyMSession* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMSession
 ******************************************************************************/

MyTblBrlyMSession::MyTblBrlyMSession() : TblBrlyMSession(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMSession::~MyTblBrlyMSession() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMSession (refBrlyMUser, start, stop, Ip) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMSession SET refBrlyMUser = ?, start = ?, stop = ?, Ip = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMSession WHERE ref = ?", false);
};

bool MyTblBrlyMSession::loadRecBySQL(
			const string& sqlstr
			, BrlyMSession** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMSession* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMSession / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMSession();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUser = atoll((char*) dbrow[1]); else _rec->refBrlyMUser = 0;
		if (dbrow[2]) _rec->start = atol((char*) dbrow[2]); else _rec->start = 0;
		if (dbrow[3]) _rec->stop = atol((char*) dbrow[3]); else _rec->stop = 0;
		if (dbrow[4]) _rec->Ip.assign(dbrow[4], dblengths[4]); else _rec->Ip = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMSession& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMSession* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMSession / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMSession();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUser = atoll((char*) dbrow[1]); else rec->refBrlyMUser = 0;
			if (dbrow[2]) rec->start = atol((char*) dbrow[2]); else rec->start = 0;
			if (dbrow[3]) rec->stop = atol((char*) dbrow[3]); else rec->stop = 0;
			if (dbrow[4]) rec->Ip.assign(dbrow[4], dblengths[4]); else rec->Ip = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMSession::insertRec(
			BrlyMSession* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMSession / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMSession / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMSession::insertRst(
			ListBrlyMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMSession::updateRec(
			BrlyMSession* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMSession / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMSession / stmtUpdateRec)\n");
};

void MyTblBrlyMSession::updateRst(
			ListBrlyMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMSession::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMSession / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMSession / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMSession::loadRecByRef(
			ubigint ref
			, BrlyMSession** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMSession WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyMSession::loadRefsByUsr(
			ubigint refBrlyMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMSession WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " ORDER BY start ASC", append, refs);
};

ubigint MyTblBrlyMSession::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyMSession& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUser, start, stop, Ip FROM TblBrlyMSession WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " ORDER BY start ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyMSession
 ******************************************************************************/

PgTblBrlyMSession::PgTblBrlyMSession() : TblBrlyMSession(), PgTable() {
};

PgTblBrlyMSession::~PgTblBrlyMSession() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMSession::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMSession_insertRec", "INSERT INTO TblBrlyMSession (refBrlyMUser, start, stop, Ip) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMSession_updateRec", "UPDATE TblBrlyMSession SET refBrlyMUser = $1, start = $2, stop = $3, Ip = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMSession_removeRecByRef", "DELETE FROM TblBrlyMSession WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMSession_loadRecByRef", "SELECT ref, refBrlyMUser, start, stop, Ip FROM TblBrlyMSession WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMSession_loadRefsByUsr", "SELECT ref FROM TblBrlyMSession WHERE refBrlyMUser = $1 ORDER BY start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMSession_loadRstByUsr", "SELECT ref, refBrlyMUser, start, stop, Ip FROM TblBrlyMSession WHERE refBrlyMUser = $1 ORDER BY start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMSession::loadRec(
			PGresult* res
			, BrlyMSession** rec
		) {
	char* ptr;

	BrlyMSession* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMSession();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Ip.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMSession::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMSession& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMSession* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		while (numread < numrow) {
			rec = new BrlyMSession();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Ip.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMSession::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMSession** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSession / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMSession::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMSession& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSession / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMSession::loadRecBySQL(
			const string& sqlstr
			, BrlyMSession** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMSession& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMSession::insertRec(
			BrlyMSession* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyMSession_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSession_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMSession::insertRst(
			ListBrlyMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMSession::updateRec(
			BrlyMSession* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMSession_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSession_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMSession::updateRst(
			ListBrlyMSession& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMSession::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMSession_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSession_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMSession::loadRecByRef(
			ubigint ref
			, BrlyMSession** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMSession_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyMSession::loadRefsByUsr(
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

	return loadRefsByStmt("TblBrlyMSession_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMSession::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyMSession& rst
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);

	const char* vals[] = {
		(char*) &_refBrlyMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMSession_loadRstByUsr", 1, vals, l, f, append, rst);
};

