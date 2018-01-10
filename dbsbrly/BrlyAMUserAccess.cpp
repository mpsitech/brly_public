/**
  * \file BrlyAMUserAccess.cpp
  * database access for table TblBrlyAMUserAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyAMUserAccess.h"

/******************************************************************************
 class BrlyAMUserAccess
 ******************************************************************************/

BrlyAMUserAccess::BrlyAMUserAccess(
			const ubigint ref
			, const ubigint refBrlyMUser
			, const uint x1IxBrlyVCard
			, const uint ixBrlyWUiaccess
		) {

	this->ref = ref;
	this->refBrlyMUser = refBrlyMUser;
	this->x1IxBrlyVCard = x1IxBrlyVCard;
	this->ixBrlyWUiaccess = ixBrlyWUiaccess;
};

bool BrlyAMUserAccess::operator==(
			const BrlyAMUserAccess& comp
		) {
	return false;
};

bool BrlyAMUserAccess::operator!=(
			const BrlyAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAMUserAccess
 ******************************************************************************/

ListBrlyAMUserAccess::ListBrlyAMUserAccess() {
};

ListBrlyAMUserAccess::ListBrlyAMUserAccess(
			const ListBrlyAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyAMUserAccess(*(src.nodes[i]));
};

ListBrlyAMUserAccess::~ListBrlyAMUserAccess() {
	clear();
};

void ListBrlyAMUserAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAMUserAccess::size() const {
	return(nodes.size());
};

void ListBrlyAMUserAccess::append(
			BrlyAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

BrlyAMUserAccess* ListBrlyAMUserAccess::operator[](
			const uint ix
		) {
	BrlyAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAMUserAccess& ListBrlyAMUserAccess::operator=(
			const ListBrlyAMUserAccess& src
		) {
	BrlyAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAMUserAccess::operator==(
			const ListBrlyAMUserAccess& comp
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

bool ListBrlyAMUserAccess::operator!=(
			const ListBrlyAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAMUserAccess
 ******************************************************************************/

TblBrlyAMUserAccess::TblBrlyAMUserAccess() {
};

TblBrlyAMUserAccess::~TblBrlyAMUserAccess() {
};

bool TblBrlyAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUserAccess** rec
		) {
	return false;
};

ubigint TblBrlyAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	return 0;
};

void TblBrlyAMUserAccess::insertRec(
			BrlyAMUserAccess* rec
		) {
};

ubigint TblBrlyAMUserAccess::insertNewRec(
			BrlyAMUserAccess** rec
			, const ubigint refBrlyMUser
			, const uint x1IxBrlyVCard
			, const uint ixBrlyWUiaccess
		) {
	ubigint retval = 0;
	BrlyAMUserAccess* _rec = NULL;

	_rec = new BrlyAMUserAccess(0, refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAMUserAccess::appendNewRecToRst(
			ListBrlyAMUserAccess& rst
			, BrlyAMUserAccess** rec
			, const ubigint refBrlyMUser
			, const uint x1IxBrlyVCard
			, const uint ixBrlyWUiaccess
		) {
	ubigint retval = 0;
	BrlyAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAMUserAccess::insertRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
};

void TblBrlyAMUserAccess::updateRec(
			BrlyAMUserAccess* rec
		) {
};

void TblBrlyAMUserAccess::updateRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
};

void TblBrlyAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAMUserAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUserAccess** rec
		) {
	return false;
};

bool TblBrlyAMUserAccess::loadRecByUsrCrd(
			ubigint refBrlyMUser
			, uint x1IxBrlyVCard
			, BrlyAMUserAccess** rec
		) {
	return false;
};

ubigint TblBrlyAMUserAccess::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	return 0;
};

ubigint TblBrlyAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	ubigint numload = 0;
	BrlyAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyAMUserAccess
 ******************************************************************************/

MyTblBrlyAMUserAccess::MyTblBrlyAMUserAccess() : TblBrlyAMUserAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAMUserAccess::~MyTblBrlyAMUserAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAMUserAccess (refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAMUserAccess SET refBrlyMUser = ?, x1IxBrlyVCard = ?, ixBrlyWUiaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAMUserAccess WHERE ref = ?", false);
};

bool MyTblBrlyAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUserAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAMUserAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAMUserAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyAMUserAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUser = atoll((char*) dbrow[1]); else _rec->refBrlyMUser = 0;
		if (dbrow[2]) _rec->x1IxBrlyVCard = atol((char*) dbrow[2]); else _rec->x1IxBrlyVCard = 0;
		if (dbrow[3]) _rec->ixBrlyWUiaccess = atol((char*) dbrow[3]); else _rec->ixBrlyWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAMUserAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAMUserAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyAMUserAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUser = atoll((char*) dbrow[1]); else rec->refBrlyMUser = 0;
			if (dbrow[2]) rec->x1IxBrlyVCard = atol((char*) dbrow[2]); else rec->x1IxBrlyVCard = 0;
			if (dbrow[3]) rec->ixBrlyWUiaccess = atol((char*) dbrow[3]); else rec->ixBrlyWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyAMUserAccess::insertRec(
			BrlyAMUserAccess* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixBrlyWUiaccess,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMUserAccess / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMUserAccess / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyAMUserAccess::insertRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAMUserAccess::updateRec(
			BrlyAMUserAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixBrlyWUiaccess,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMUserAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMUserAccess / stmtUpdateRec)\n");
};

void MyTblBrlyAMUserAccess::updateRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMUserAccess / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMUserAccess / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyAMUserAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUserAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyAMUserAccess WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyAMUserAccess::loadRecByUsrCrd(
			ubigint refBrlyMUser
			, uint x1IxBrlyVCard
			, BrlyAMUserAccess** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUserAccess WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " AND x1IxBrlyVCard = " + to_string(x1IxBrlyVCard) + "", rec);
};

ubigint MyTblBrlyAMUserAccess::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUserAccess WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " ORDER BY x1IxBrlyVCard ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyAMUserAccess
 ******************************************************************************/

PgTblBrlyAMUserAccess::PgTblBrlyAMUserAccess() : TblBrlyAMUserAccess(), PgTable() {
};

PgTblBrlyAMUserAccess::~PgTblBrlyAMUserAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAMUserAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyAMUserAccess_insertRec", "INSERT INTO TblBrlyAMUserAccess (refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMUserAccess_updateRec", "UPDATE TblBrlyAMUserAccess SET refBrlyMUser = $1, x1IxBrlyVCard = $2, ixBrlyWUiaccess = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMUserAccess_removeRecByRef", "DELETE FROM TblBrlyAMUserAccess WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyAMUserAccess_loadRecByRef", "SELECT ref, refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUserAccess WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyAMUserAccess_loadRecByUsrCrd", "SELECT ref, refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUserAccess WHERE refBrlyMUser = $1 AND x1IxBrlyVCard = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMUserAccess_loadRstByUsr", "SELECT ref, refBrlyMUser, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyAMUserAccess WHERE refBrlyMUser = $1 ORDER BY x1IxBrlyVCard ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyAMUserAccess::loadRec(
			PGresult* res
			, BrlyAMUserAccess** rec
		) {
	char* ptr;

	BrlyAMUserAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAMUserAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "x1ixbrlyvcard"),
			PQfnumber(res, "ixbrlywuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxBrlyVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixBrlyWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAMUserAccess::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAMUserAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "x1ixbrlyvcard"),
			PQfnumber(res, "ixbrlywuiaccess")
		};

		while (numread < numrow) {
			rec = new BrlyAMUserAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxBrlyVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixBrlyWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAMUserAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUserAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMUserAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUserAccess / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyAMUserAccess::insertRec(
			BrlyAMUserAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _x1IxBrlyVCard = htonl(rec->x1IxBrlyVCard);
	uint _ixBrlyWUiaccess = htonl(rec->ixBrlyWUiaccess);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_x1IxBrlyVCard,
		(char*) &_ixBrlyWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMUserAccess_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUserAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyAMUserAccess::insertRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAMUserAccess::updateRec(
			BrlyAMUserAccess* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _x1IxBrlyVCard = htonl(rec->x1IxBrlyVCard);
	uint _ixBrlyWUiaccess = htonl(rec->ixBrlyWUiaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
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

	res = PQexecPrepared(dbs, "TblBrlyAMUserAccess_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUserAccess_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyAMUserAccess::updateRst(
			ListBrlyAMUserAccess& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAMUserAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAMUserAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMUserAccess_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyAMUserAccess::loadRecByRef(
			ubigint ref
			, BrlyAMUserAccess** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyAMUserAccess_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyAMUserAccess::loadRecByUsrCrd(
			ubigint refBrlyMUser
			, uint x1IxBrlyVCard
			, BrlyAMUserAccess** rec
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);
	uint _x1IxBrlyVCard = htonl(x1IxBrlyVCard);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_x1IxBrlyVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblBrlyAMUserAccess_loadRecByUsrCrd", 2, vals, l, f, rec);
};

ubigint PgTblBrlyAMUserAccess::loadRstByUsr(
			ubigint refBrlyMUser
			, const bool append
			, ListBrlyAMUserAccess& rst
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);

	const char* vals[] = {
		(char*) &_refBrlyMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyAMUserAccess_loadRstByUsr", 1, vals, l, f, append, rst);
};

