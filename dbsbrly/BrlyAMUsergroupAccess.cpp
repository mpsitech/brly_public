/**
  * \file BrlyAMUsergroupAccess.cpp
  * database access for table TblBrlyAMUsergroupAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyAMUsergroupAccess.h"

/******************************************************************************
 class BrlyAMUsergroupAccess
 ******************************************************************************/

BrlyAMUsergroupAccess::BrlyAMUsergroupAccess(
			const ubigint ref
			, const ubigint refBrlyMUsergroup
			, const uint x1IxBrlyVCard
			, const uint ixBrlyWUiaccess
		) {

	this->ref = ref;
	this->refBrlyMUsergroup = refBrlyMUsergroup;
	this->x1IxBrlyVCard = x1IxBrlyVCard;
	this->ixBrlyWUiaccess = ixBrlyWUiaccess;
};

bool BrlyAMUsergroupAccess::operator==(
			const BrlyAMUsergroupAccess& comp
		) {
	return false;
};

bool BrlyAMUsergroupAccess::operator!=(
			const BrlyAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAMUsergroupAccess
 ******************************************************************************/

ListBrlyAMUsergroupAccess::ListBrlyAMUsergroupAccess() {
};

ListBrlyAMUsergroupAccess::ListBrlyAMUsergroupAccess(
			const ListBrlyAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyAMUsergroupAccess(*(src.nodes[i]));
};

ListBrlyAMUsergroupAccess::~ListBrlyAMUsergroupAccess() {
	clear();
};

void ListBrlyAMUsergroupAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListBrlyAMUsergroupAccess::append(
			BrlyAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

BrlyAMUsergroupAccess* ListBrlyAMUsergroupAccess::operator[](
			const uint ix
		) {
	BrlyAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAMUsergroupAccess& ListBrlyAMUsergroupAccess::operator=(
			const ListBrlyAMUsergroupAccess& src
		) {
	BrlyAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAMUsergroupAccess::operator==(
			const ListBrlyAMUsergroupAccess& comp
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

bool ListBrlyAMUsergroupAccess::operator!=(
			const ListBrlyAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAMUsergroupAccess
 ******************************************************************************/

TblBrlyAMUsergroupAccess::TblBrlyAMUsergroupAccess() {
};

TblBrlyAMUsergroupAccess::~TblBrlyAMUsergroupAccess() {
};

bool TblBrlyAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblBrlyAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	return 0;
};

void TblBrlyAMUsergroupAccess::insertRec(
			BrlyAMUsergroupAccess* rec
		) {
};

ubigint TblBrlyAMUsergroupAccess::insertNewRec(
			BrlyAMUsergroupAccess** rec
			, const ubigint refBrlyMUsergroup
			, const uint x1IxBrlyVCard
			, const uint ixBrlyWUiaccess
		) {
	ubigint retval = 0;
	BrlyAMUsergroupAccess* _rec = NULL;

	_rec = new BrlyAMUsergroupAccess(0, refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAMUsergroupAccess::appendNewRecToRst(
			ListBrlyAMUsergroupAccess& rst
			, BrlyAMUsergroupAccess** rec
			, const ubigint refBrlyMUsergroup
			, const uint x1IxBrlyVCard
			, const uint ixBrlyWUiaccess
		) {
	ubigint retval = 0;
	BrlyAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAMUsergroupAccess::insertRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblBrlyAMUsergroupAccess::updateRec(
			BrlyAMUsergroupAccess* rec
		) {
};

void TblBrlyAMUsergroupAccess::updateRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblBrlyAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUsergroupAccess** rec
		) {
	return false;
};

bool TblBrlyAMUsergroupAccess::loadRecByUsgCrd(
			ubigint refBrlyMUsergroup
			, uint x1IxBrlyVCard
			, BrlyAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblBrlyAMUsergroupAccess::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyAMUsergroupAccess::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	return 0;
};

ubigint TblBrlyAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	BrlyAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyAMUsergroupAccess
 ******************************************************************************/

MyTblBrlyAMUsergroupAccess::MyTblBrlyAMUsergroupAccess() : TblBrlyAMUsergroupAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAMUsergroupAccess::~MyTblBrlyAMUsergroupAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAMUsergroupAccess (refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAMUsergroupAccess SET refBrlyMUsergroup = ?, x1IxBrlyVCard = ?, ixBrlyWUiaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAMUsergroupAccess WHERE ref = ?", false);
};

bool MyTblBrlyAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUsergroupAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAMUsergroupAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAMUsergroupAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyAMUsergroupAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUsergroup = atoll((char*) dbrow[1]); else _rec->refBrlyMUsergroup = 0;
		if (dbrow[2]) _rec->x1IxBrlyVCard = atol((char*) dbrow[2]); else _rec->x1IxBrlyVCard = 0;
		if (dbrow[3]) _rec->ixBrlyWUiaccess = atol((char*) dbrow[3]); else _rec->ixBrlyWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAMUsergroupAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAMUsergroupAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyAMUsergroupAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUsergroup = atoll((char*) dbrow[1]); else rec->refBrlyMUsergroup = 0;
			if (dbrow[2]) rec->x1IxBrlyVCard = atol((char*) dbrow[2]); else rec->x1IxBrlyVCard = 0;
			if (dbrow[3]) rec->ixBrlyWUiaccess = atol((char*) dbrow[3]); else rec->ixBrlyWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyAMUsergroupAccess::insertRec(
			BrlyAMUsergroupAccess* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixBrlyWUiaccess,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMUsergroupAccess / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMUsergroupAccess / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyAMUsergroupAccess::insertRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAMUsergroupAccess::updateRec(
			BrlyAMUsergroupAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixBrlyWUiaccess,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMUsergroupAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMUsergroupAccess / stmtUpdateRec)\n");
};

void MyTblBrlyAMUsergroupAccess::updateRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMUsergroupAccess / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMUsergroupAccess / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUsergroupAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyAMUsergroupAccess WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyAMUsergroupAccess::loadRecByUsgCrd(
			ubigint refBrlyMUsergroup
			, uint x1IxBrlyVCard
			, BrlyAMUsergroupAccess** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = " + to_string(refBrlyMUsergroup) + " AND x1IxBrlyVCard = " + to_string(x1IxBrlyVCard) + "", rec);
};

ubigint MyTblBrlyAMUsergroupAccess::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = " + to_string(refBrlyMUsergroup) + "", append, refs);
};

ubigint MyTblBrlyAMUsergroupAccess::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = " + to_string(refBrlyMUsergroup) + " ORDER BY x1IxBrlyVCard ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyAMUsergroupAccess
 ******************************************************************************/

PgTblBrlyAMUsergroupAccess::PgTblBrlyAMUsergroupAccess() : TblBrlyAMUsergroupAccess(), PgTable() {
};

PgTblBrlyAMUsergroupAccess::~PgTblBrlyAMUsergroupAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAMUsergroupAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyAMUsergroupAccess_insertRec", "INSERT INTO TblBrlyAMUsergroupAccess (refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMUsergroupAccess_updateRec", "UPDATE TblBrlyAMUsergroupAccess SET refBrlyMUsergroup = $1, x1IxBrlyVCard = $2, ixBrlyWUiaccess = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMUsergroupAccess_removeRecByRef", "DELETE FROM TblBrlyAMUsergroupAccess WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyAMUsergroupAccess_loadRecByRef", "SELECT ref, refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUsergroupAccess WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyAMUsergroupAccess_loadRecByUsgCrd", "SELECT ref, refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = $1 AND x1IxBrlyVCard = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMUsergroupAccess_loadRefsByUsg", "SELECT ref FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMUsergroupAccess_loadRstByUsg", "SELECT ref, refBrlyMUsergroup, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUsergroupAccess WHERE refBrlyMUsergroup = $1 ORDER BY x1IxBrlyVCard ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyAMUsergroupAccess::loadRec(
			PGresult* res
			, BrlyAMUsergroupAccess** rec
		) {
	char* ptr;

	BrlyAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAMUsergroupAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "x1ixbrlyvcard"),
			PQfnumber(res, "ixbrlywuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxBrlyVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixBrlyWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAMUsergroupAccess::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAMUsergroupAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "x1ixbrlyvcard"),
			PQfnumber(res, "ixbrlywuiaccess")
		};

		while (numread < numrow) {
			rec = new BrlyAMUsergroupAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxBrlyVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixBrlyWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAMUsergroupAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUsergroupAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMUsergroupAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUsergroupAccess / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyAMUsergroupAccess::insertRec(
			BrlyAMUsergroupAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _x1IxBrlyVCard = htonl(rec->x1IxBrlyVCard);
	uint _ixBrlyWUiaccess = htonl(rec->ixBrlyWUiaccess);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup,
		(char*) &_x1IxBrlyVCard,
		(char*) &_ixBrlyWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMUsergroupAccess_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUsergroupAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyAMUsergroupAccess::insertRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAMUsergroupAccess::updateRec(
			BrlyAMUsergroupAccess* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _x1IxBrlyVCard = htonl(rec->x1IxBrlyVCard);
	uint _ixBrlyWUiaccess = htonl(rec->ixBrlyWUiaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup,
		(char*) &_x1IxBrlyVCard,
		(char*) &_ixBrlyWUiaccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMUsergroupAccess_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUsergroupAccess_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyAMUsergroupAccess::updateRst(
			ListBrlyAMUsergroupAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAMUsergroupAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAMUsergroupAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUsergroupAccess_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUsergroupAccess** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyAMUsergroupAccess_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyAMUsergroupAccess::loadRecByUsgCrd(
			ubigint refBrlyMUsergroup
			, uint x1IxBrlyVCard
			, BrlyAMUsergroupAccess** rec
		) {
	ubigint _refBrlyMUsergroup = htonl64(refBrlyMUsergroup);
	uint _x1IxBrlyVCard = htonl(x1IxBrlyVCard);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup,
		(char*) &_x1IxBrlyVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblBrlyAMUsergroupAccess_loadRecByUsgCrd", 2, vals, l, f, rec);
};

ubigint PgTblBrlyAMUsergroupAccess::loadRefsByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMUsergroup = htonl64(refBrlyMUsergroup);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyAMUsergroupAccess_loadRefsByUsg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyAMUsergroupAccess::loadRstByUsg(
			ubigint refBrlyMUsergroup
			, const bool append
			, ListBrlyAMUsergroupAccess& rst
		) {
	ubigint _refBrlyMUsergroup = htonl64(refBrlyMUsergroup);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyAMUsergroupAccess_loadRstByUsg", 1, vals, l, f, append, rst);
};

