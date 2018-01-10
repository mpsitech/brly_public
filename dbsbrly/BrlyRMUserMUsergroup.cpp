/**
  * \file BrlyRMUserMUsergroup.cpp
  * database access for table TblBrlyRMUserMUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMUserMUsergroup.h"

/******************************************************************************
 class BrlyRMUserMUsergroup
 ******************************************************************************/

BrlyRMUserMUsergroup::BrlyRMUserMUsergroup(
			const ubigint ref
			, const ubigint refBrlyMUser
			, const ubigint refBrlyMUsergroup
			, const uint ixBrlyVUserlevel
		) {

	this->ref = ref;
	this->refBrlyMUser = refBrlyMUser;
	this->refBrlyMUsergroup = refBrlyMUsergroup;
	this->ixBrlyVUserlevel = ixBrlyVUserlevel;
};

bool BrlyRMUserMUsergroup::operator==(
			const BrlyRMUserMUsergroup& comp
		) {
	return false;
};

bool BrlyRMUserMUsergroup::operator!=(
			const BrlyRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMUserMUsergroup
 ******************************************************************************/

ListBrlyRMUserMUsergroup::ListBrlyRMUserMUsergroup() {
};

ListBrlyRMUserMUsergroup::ListBrlyRMUserMUsergroup(
			const ListBrlyRMUserMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMUserMUsergroup(*(src.nodes[i]));
};

ListBrlyRMUserMUsergroup::~ListBrlyRMUserMUsergroup() {
	clear();
};

void ListBrlyRMUserMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMUserMUsergroup::size() const {
	return(nodes.size());
};

void ListBrlyRMUserMUsergroup::append(
			BrlyRMUserMUsergroup* rec
		) {
	nodes.push_back(rec);
};

BrlyRMUserMUsergroup* ListBrlyRMUserMUsergroup::operator[](
			const uint ix
		) {
	BrlyRMUserMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMUserMUsergroup& ListBrlyRMUserMUsergroup::operator=(
			const ListBrlyRMUserMUsergroup& src
		) {
	BrlyRMUserMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMUserMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMUserMUsergroup::operator==(
			const ListBrlyRMUserMUsergroup& comp
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

bool ListBrlyRMUserMUsergroup::operator!=(
			const ListBrlyRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMUserMUsergroup
 ******************************************************************************/

TblBrlyRMUserMUsergroup::TblBrlyRMUserMUsergroup() {
};

TblBrlyRMUserMUsergroup::~TblBrlyRMUserMUsergroup() {
};

bool TblBrlyRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblBrlyRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	return 0;
};

void TblBrlyRMUserMUsergroup::insertRec(
			BrlyRMUserMUsergroup* rec
		) {
};

ubigint TblBrlyRMUserMUsergroup::insertNewRec(
			BrlyRMUserMUsergroup** rec
			, const ubigint refBrlyMUser
			, const ubigint refBrlyMUsergroup
			, const uint ixBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyRMUserMUsergroup* _rec = NULL;

	_rec = new BrlyRMUserMUsergroup(0, refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMUserMUsergroup::appendNewRecToRst(
			ListBrlyRMUserMUsergroup& rst
			, BrlyRMUserMUsergroup** rec
			, const ubigint refBrlyMUser
			, const ubigint refBrlyMUsergroup
			, const uint ixBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyRMUserMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMUserMUsergroup::insertRst(
			ListBrlyRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblBrlyRMUserMUsergroup::updateRec(
			BrlyRMUserMUsergroup* rec
		) {
};

void TblBrlyRMUserMUsergroup::updateRst(
			ListBrlyRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblBrlyRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, BrlyRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblBrlyRMUserMUsergroup::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblBrlyRMUserMUsergroup::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblBrlyRMUserMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	ubigint numload = 0;
	BrlyRMUserMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMUserMUsergroup
 ******************************************************************************/

MyTblBrlyRMUserMUsergroup::MyTblBrlyRMUserMUsergroup() : TblBrlyRMUserMUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMUserMUsergroup::~MyTblBrlyRMUserMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMUserMUsergroup (refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMUserMUsergroup SET refBrlyMUser = ?, refBrlyMUsergroup = ?, ixBrlyVUserlevel = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMUserMUsergroup WHERE ref = ?", false);
};

bool MyTblBrlyRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyRMUserMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMUserMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMUserMUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMUserMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUser = atoll((char*) dbrow[1]); else _rec->refBrlyMUser = 0;
		if (dbrow[2]) _rec->refBrlyMUsergroup = atoll((char*) dbrow[2]); else _rec->refBrlyMUsergroup = 0;
		if (dbrow[3]) _rec->ixBrlyVUserlevel = atol((char*) dbrow[3]); else _rec->ixBrlyVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMUserMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMUserMUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMUserMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUser = atoll((char*) dbrow[1]); else rec->refBrlyMUser = 0;
			if (dbrow[2]) rec->refBrlyMUsergroup = atoll((char*) dbrow[2]); else rec->refBrlyMUsergroup = 0;
			if (dbrow[3]) rec->ixBrlyVUserlevel = atol((char*) dbrow[3]); else rec->ixBrlyVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMUserMUsergroup::insertRec(
			BrlyRMUserMUsergroup* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refBrlyMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMUserMUsergroup / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMUserMUsergroup / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMUserMUsergroup::insertRst(
			ListBrlyRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMUserMUsergroup::updateRec(
			BrlyRMUserMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refBrlyMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMUserMUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMUserMUsergroup / stmtUpdateRec)\n");
};

void MyTblBrlyRMUserMUsergroup::updateRst(
			ListBrlyRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMUserMUsergroup / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMUserMUsergroup / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, BrlyRMUserMUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMUserMUsergroup WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMUserMUsergroup::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel FROM TblBrlyRMUserMUsergroup WHERE refBrlyMUsergroup = " + to_string(refBrlyMUsergroup) + "", append, rst);
};

ubigint MyTblBrlyRMUserMUsergroup::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel FROM TblBrlyRMUserMUsergroup WHERE refBrlyMUser = " + to_string(refBrlyMUser) + "", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMUserMUsergroup
 ******************************************************************************/

PgTblBrlyRMUserMUsergroup::PgTblBrlyRMUserMUsergroup() : TblBrlyRMUserMUsergroup(), PgTable() {
};

PgTblBrlyRMUserMUsergroup::~PgTblBrlyRMUserMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMUserMUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMUserMUsergroup_insertRec", "INSERT INTO TblBrlyRMUserMUsergroup (refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMUserMUsergroup_updateRec", "UPDATE TblBrlyRMUserMUsergroup SET refBrlyMUser = $1, refBrlyMUsergroup = $2, ixBrlyVUserlevel = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMUserMUsergroup_removeRecByRef", "DELETE FROM TblBrlyRMUserMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMUserMUsergroup_loadRecByRef", "SELECT ref, refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel FROM TblBrlyRMUserMUsergroup WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMUserMUsergroup_loadRstByUsg", "SELECT ref, refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel FROM TblBrlyRMUserMUsergroup WHERE refBrlyMUsergroup = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMUserMUsergroup_loadRstByUsr", "SELECT ref, refBrlyMUser, refBrlyMUsergroup, ixBrlyVUserlevel FROM TblBrlyRMUserMUsergroup WHERE refBrlyMUser = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMUserMUsergroup::loadRec(
			PGresult* res
			, BrlyRMUserMUsergroup** rec
		) {
	char* ptr;

	BrlyRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMUserMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refBrlyMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixBrlyVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMUserMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMUserMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		while (numread < numrow) {
			rec = new BrlyRMUserMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refBrlyMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixBrlyVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMUserMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUserMUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMUserMUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUserMUsergroup / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMUserMUsergroup::insertRec(
			BrlyRMUserMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_refBrlyMUsergroup,
		(char*) &_ixBrlyVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMUserMUsergroup_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUserMUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMUserMUsergroup::insertRst(
			ListBrlyRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMUserMUsergroup::updateRec(
			BrlyRMUserMUsergroup* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_refBrlyMUsergroup,
		(char*) &_ixBrlyVUserlevel,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMUserMUsergroup_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUserMUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMUserMUsergroup::updateRst(
			ListBrlyRMUserMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMUserMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMUserMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUserMUsergroup_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, BrlyRMUserMUsergroup** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMUserMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMUserMUsergroup::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	ubigint _refBrlyMUsergroup = htonl64(refBrlyMUsergroup);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMUserMUsergroup_loadRstByUsg", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMUserMUsergroup::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyRMUserMUsergroup& rst
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);

	const char* vals[] = {
		(char*) &_refBrlyMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMUserMUsergroup_loadRstByUsr", 1, vals, l, f, append, rst);
};

