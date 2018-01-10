/**
  * \file BrlyJAVKeylistKey.cpp
  * database access for table TblBrlyJAVKeylistKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyJAVKeylistKey.h"

/******************************************************************************
 class BrlyJAVKeylistKey
 ******************************************************************************/

BrlyJAVKeylistKey::BrlyJAVKeylistKey(
			const ubigint ref
			, const ubigint refBrlyAVKeylistKey
			, const uint x1IxBrlyVLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refBrlyAVKeylistKey = refBrlyAVKeylistKey;
	this->x1IxBrlyVLocale = x1IxBrlyVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool BrlyJAVKeylistKey::operator==(
			const BrlyJAVKeylistKey& comp
		) {
	return false;
};

bool BrlyJAVKeylistKey::operator!=(
			const BrlyJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyJAVKeylistKey
 ******************************************************************************/

ListBrlyJAVKeylistKey::ListBrlyJAVKeylistKey() {
};

ListBrlyJAVKeylistKey::ListBrlyJAVKeylistKey(
			const ListBrlyJAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyJAVKeylistKey(*(src.nodes[i]));
};

ListBrlyJAVKeylistKey::~ListBrlyJAVKeylistKey() {
	clear();
};

void ListBrlyJAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyJAVKeylistKey::size() const {
	return(nodes.size());
};

void ListBrlyJAVKeylistKey::append(
			BrlyJAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

BrlyJAVKeylistKey* ListBrlyJAVKeylistKey::operator[](
			const uint ix
		) {
	BrlyJAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyJAVKeylistKey& ListBrlyJAVKeylistKey::operator=(
			const ListBrlyJAVKeylistKey& src
		) {
	BrlyJAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyJAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyJAVKeylistKey::operator==(
			const ListBrlyJAVKeylistKey& comp
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

bool ListBrlyJAVKeylistKey::operator!=(
			const ListBrlyJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyJAVKeylistKey
 ******************************************************************************/

TblBrlyJAVKeylistKey::TblBrlyJAVKeylistKey() {
};

TblBrlyJAVKeylistKey::~TblBrlyJAVKeylistKey() {
};

bool TblBrlyJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, BrlyJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblBrlyJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	return 0;
};

void TblBrlyJAVKeylistKey::insertRec(
			BrlyJAVKeylistKey* rec
		) {
};

ubigint TblBrlyJAVKeylistKey::insertNewRec(
			BrlyJAVKeylistKey** rec
			, const ubigint refBrlyAVKeylistKey
			, const uint x1IxBrlyVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyJAVKeylistKey* _rec = NULL;

	_rec = new BrlyJAVKeylistKey(0, refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyJAVKeylistKey::appendNewRecToRst(
			ListBrlyJAVKeylistKey& rst
			, BrlyJAVKeylistKey** rec
			, const ubigint refBrlyAVKeylistKey
			, const uint x1IxBrlyVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyJAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyJAVKeylistKey::insertRst(
			ListBrlyJAVKeylistKey& rst
			, bool transact
		) {
};

void TblBrlyJAVKeylistKey::updateRec(
			BrlyJAVKeylistKey* rec
		) {
};

void TblBrlyJAVKeylistKey::updateRst(
			ListBrlyJAVKeylistKey& rst
			, bool transact
		) {
};

void TblBrlyJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyJAVKeylistKey::loadRecByRef(
			ubigint ref
			, BrlyJAVKeylistKey** rec
		) {
	return false;
};

bool TblBrlyJAVKeylistKey::loadRecByKlkLcl(
			ubigint refBrlyAVKeylistKey
			, uint x1IxBrlyVLocale
			, BrlyJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblBrlyJAVKeylistKey::loadRefsByKlk(
			ubigint refBrlyAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyJAVKeylistKey::loadRstByKlk(
			ubigint refBrlyAVKeylistKey
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	return 0;
};

bool TblBrlyJAVKeylistKey::loadTitByKlkLcl(
			ubigint refBrlyAVKeylistKey
			, uint x1IxBrlyVLocale
			, string& Title
		) {
	return false;
};

ubigint TblBrlyJAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	ubigint numload = 0;
	BrlyJAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyJAVKeylistKey
 ******************************************************************************/

MyTblBrlyJAVKeylistKey::MyTblBrlyJAVKeylistKey() : TblBrlyJAVKeylistKey(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyJAVKeylistKey::~MyTblBrlyJAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyJAVKeylistKey (refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyJAVKeylistKey SET refBrlyAVKeylistKey = ?, x1IxBrlyVLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyJAVKeylistKey WHERE ref = ?", false);
};

bool MyTblBrlyJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, BrlyJAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyJAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyJAVKeylistKey / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyJAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyAVKeylistKey = atoll((char*) dbrow[1]); else _rec->refBrlyAVKeylistKey = 0;
		if (dbrow[2]) _rec->x1IxBrlyVLocale = atol((char*) dbrow[2]); else _rec->x1IxBrlyVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyJAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyJAVKeylistKey / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyJAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyAVKeylistKey = atoll((char*) dbrow[1]); else rec->refBrlyAVKeylistKey = 0;
			if (dbrow[2]) rec->x1IxBrlyVLocale = atol((char*) dbrow[2]); else rec->x1IxBrlyVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyJAVKeylistKey::insertRec(
			BrlyJAVKeylistKey* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJAVKeylistKey / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJAVKeylistKey / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyJAVKeylistKey::insertRst(
			ListBrlyJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyJAVKeylistKey::updateRec(
			BrlyJAVKeylistKey* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJAVKeylistKey / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJAVKeylistKey / stmtUpdateRec)\n");
};

void MyTblBrlyJAVKeylistKey::updateRst(
			ListBrlyJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJAVKeylistKey / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJAVKeylistKey / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyJAVKeylistKey::loadRecByRef(
			ubigint ref
			, BrlyJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyJAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyJAVKeylistKey::loadRecByKlkLcl(
			ubigint refBrlyAVKeylistKey
			, uint x1IxBrlyVLocale
			, BrlyJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment FROM TblBrlyJAVKeylistKey WHERE refBrlyAVKeylistKey = " + to_string(refBrlyAVKeylistKey) + " AND x1IxBrlyVLocale = " + to_string(x1IxBrlyVLocale) + "", rec);
};

ubigint MyTblBrlyJAVKeylistKey::loadRefsByKlk(
			ubigint refBrlyAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyJAVKeylistKey WHERE refBrlyAVKeylistKey = " + to_string(refBrlyAVKeylistKey) + "", append, refs);
};

ubigint MyTblBrlyJAVKeylistKey::loadRstByKlk(
			ubigint refBrlyAVKeylistKey
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment FROM TblBrlyJAVKeylistKey WHERE refBrlyAVKeylistKey = " + to_string(refBrlyAVKeylistKey) + " ORDER BY x1IxBrlyVLocale ASC", append, rst);
};

bool MyTblBrlyJAVKeylistKey::loadTitByKlkLcl(
			ubigint refBrlyAVKeylistKey
			, uint x1IxBrlyVLocale
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblBrlyJAVKeylistKey WHERE refBrlyAVKeylistKey = " + to_string(refBrlyAVKeylistKey) + " AND x1IxBrlyVLocale = " + to_string(x1IxBrlyVLocale) + "", Title);
};

/******************************************************************************
 class PgTblBrlyJAVKeylistKey
 ******************************************************************************/

PgTblBrlyJAVKeylistKey::PgTblBrlyJAVKeylistKey() : TblBrlyJAVKeylistKey(), PgTable() {
};

PgTblBrlyJAVKeylistKey::~PgTblBrlyJAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyJAVKeylistKey::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyJAVKeylistKey_insertRec", "INSERT INTO TblBrlyJAVKeylistKey (refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJAVKeylistKey_updateRec", "UPDATE TblBrlyJAVKeylistKey SET refBrlyAVKeylistKey = $1, x1IxBrlyVLocale = $2, Title = $3, Comment = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJAVKeylistKey_removeRecByRef", "DELETE FROM TblBrlyJAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyJAVKeylistKey_loadRecByRef", "SELECT ref, refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment FROM TblBrlyJAVKeylistKey WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyJAVKeylistKey_loadRecByKlkLcl", "SELECT ref, refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment FROM TblBrlyJAVKeylistKey WHERE refBrlyAVKeylistKey = $1 AND x1IxBrlyVLocale = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJAVKeylistKey_loadRefsByKlk", "SELECT ref FROM TblBrlyJAVKeylistKey WHERE refBrlyAVKeylistKey = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJAVKeylistKey_loadRstByKlk", "SELECT ref, refBrlyAVKeylistKey, x1IxBrlyVLocale, Title, Comment FROM TblBrlyJAVKeylistKey WHERE refBrlyAVKeylistKey = $1 ORDER BY x1IxBrlyVLocale ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJAVKeylistKey_loadTitByKlkLcl", "SELECT Title FROM TblBrlyJAVKeylistKey WHERE refBrlyAVKeylistKey = $1 AND x1IxBrlyVLocale = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyJAVKeylistKey::loadRec(
			PGresult* res
			, BrlyJAVKeylistKey** rec
		) {
	char* ptr;

	BrlyJAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyJAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlyavkeylistkey"),
			PQfnumber(res, "x1ixbrlyvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyAVKeylistKey = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxBrlyVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyJAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyJAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlyavkeylistkey"),
			PQfnumber(res, "x1ixbrlyvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new BrlyJAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyAVKeylistKey = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxBrlyVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyJAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJAVKeylistKey / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyJAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJAVKeylistKey / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, BrlyJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyJAVKeylistKey::insertRec(
			BrlyJAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyAVKeylistKey = htonl64(rec->refBrlyAVKeylistKey);
	uint _x1IxBrlyVLocale = htonl(rec->x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_refBrlyAVKeylistKey,
		(char*) &_x1IxBrlyVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyJAVKeylistKey_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJAVKeylistKey_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyJAVKeylistKey::insertRst(
			ListBrlyJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyJAVKeylistKey::updateRec(
			BrlyJAVKeylistKey* rec
		) {
	PGresult* res;

	ubigint _refBrlyAVKeylistKey = htonl64(rec->refBrlyAVKeylistKey);
	uint _x1IxBrlyVLocale = htonl(rec->x1IxBrlyVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyAVKeylistKey,
		(char*) &_x1IxBrlyVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyJAVKeylistKey_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJAVKeylistKey_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyJAVKeylistKey::updateRst(
			ListBrlyJAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyJAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyJAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJAVKeylistKey_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyJAVKeylistKey::loadRecByRef(
			ubigint ref
			, BrlyJAVKeylistKey** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyJAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyJAVKeylistKey::loadRecByKlkLcl(
			ubigint refBrlyAVKeylistKey
			, uint x1IxBrlyVLocale
			, BrlyJAVKeylistKey** rec
		) {
	ubigint _refBrlyAVKeylistKey = htonl64(refBrlyAVKeylistKey);
	uint _x1IxBrlyVLocale = htonl(x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_refBrlyAVKeylistKey,
		(char*) &_x1IxBrlyVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblBrlyJAVKeylistKey_loadRecByKlkLcl", 2, vals, l, f, rec);
};

ubigint PgTblBrlyJAVKeylistKey::loadRefsByKlk(
			ubigint refBrlyAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyAVKeylistKey = htonl64(refBrlyAVKeylistKey);

	const char* vals[] = {
		(char*) &_refBrlyAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyJAVKeylistKey_loadRefsByKlk", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyJAVKeylistKey::loadRstByKlk(
			ubigint refBrlyAVKeylistKey
			, const bool append
			, ListBrlyJAVKeylistKey& rst
		) {
	ubigint _refBrlyAVKeylistKey = htonl64(refBrlyAVKeylistKey);

	const char* vals[] = {
		(char*) &_refBrlyAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyJAVKeylistKey_loadRstByKlk", 1, vals, l, f, append, rst);
};

bool PgTblBrlyJAVKeylistKey::loadTitByKlkLcl(
			ubigint refBrlyAVKeylistKey
			, uint x1IxBrlyVLocale
			, string& Title
		) {
	ubigint _refBrlyAVKeylistKey = htonl64(refBrlyAVKeylistKey);
	uint _x1IxBrlyVLocale = htonl(x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_refBrlyAVKeylistKey,
		(char*) &_x1IxBrlyVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblBrlyJAVKeylistKey_loadTitByKlkLcl", 2, vals, l, f, Title);
};

