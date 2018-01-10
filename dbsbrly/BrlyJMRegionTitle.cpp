/**
  * \file BrlyJMRegionTitle.cpp
  * database access for table TblBrlyJMRegionTitle (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyJMRegionTitle.h"

/******************************************************************************
 class BrlyJMRegionTitle
 ******************************************************************************/

BrlyJMRegionTitle::BrlyJMRegionTitle(
			const ubigint ref
			, const ubigint refBrlyMRegion
			, const uint x1IxBrlyVLocale
			, const string Title
		) {

	this->ref = ref;
	this->refBrlyMRegion = refBrlyMRegion;
	this->x1IxBrlyVLocale = x1IxBrlyVLocale;
	this->Title = Title;
};

bool BrlyJMRegionTitle::operator==(
			const BrlyJMRegionTitle& comp
		) {
	return false;
};

bool BrlyJMRegionTitle::operator!=(
			const BrlyJMRegionTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyJMRegionTitle
 ******************************************************************************/

ListBrlyJMRegionTitle::ListBrlyJMRegionTitle() {
};

ListBrlyJMRegionTitle::ListBrlyJMRegionTitle(
			const ListBrlyJMRegionTitle& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyJMRegionTitle(*(src.nodes[i]));
};

ListBrlyJMRegionTitle::~ListBrlyJMRegionTitle() {
	clear();
};

void ListBrlyJMRegionTitle::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyJMRegionTitle::size() const {
	return(nodes.size());
};

void ListBrlyJMRegionTitle::append(
			BrlyJMRegionTitle* rec
		) {
	nodes.push_back(rec);
};

BrlyJMRegionTitle* ListBrlyJMRegionTitle::operator[](
			const uint ix
		) {
	BrlyJMRegionTitle* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyJMRegionTitle& ListBrlyJMRegionTitle::operator=(
			const ListBrlyJMRegionTitle& src
		) {
	BrlyJMRegionTitle* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyJMRegionTitle(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyJMRegionTitle::operator==(
			const ListBrlyJMRegionTitle& comp
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

bool ListBrlyJMRegionTitle::operator!=(
			const ListBrlyJMRegionTitle& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyJMRegionTitle
 ******************************************************************************/

TblBrlyJMRegionTitle::TblBrlyJMRegionTitle() {
};

TblBrlyJMRegionTitle::~TblBrlyJMRegionTitle() {
};

bool TblBrlyJMRegionTitle::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegionTitle** rec
		) {
	return false;
};

ubigint TblBrlyJMRegionTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	return 0;
};

void TblBrlyJMRegionTitle::insertRec(
			BrlyJMRegionTitle* rec
		) {
};

ubigint TblBrlyJMRegionTitle::insertNewRec(
			BrlyJMRegionTitle** rec
			, const ubigint refBrlyMRegion
			, const uint x1IxBrlyVLocale
			, const string Title
		) {
	ubigint retval = 0;
	BrlyJMRegionTitle* _rec = NULL;

	_rec = new BrlyJMRegionTitle(0, refBrlyMRegion, x1IxBrlyVLocale, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyJMRegionTitle::appendNewRecToRst(
			ListBrlyJMRegionTitle& rst
			, BrlyJMRegionTitle** rec
			, const ubigint refBrlyMRegion
			, const uint x1IxBrlyVLocale
			, const string Title
		) {
	ubigint retval = 0;
	BrlyJMRegionTitle* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMRegion, x1IxBrlyVLocale, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyJMRegionTitle::insertRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
};

void TblBrlyJMRegionTitle::updateRec(
			BrlyJMRegionTitle* rec
		) {
};

void TblBrlyJMRegionTitle::updateRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
};

void TblBrlyJMRegionTitle::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyJMRegionTitle::loadRecByRef(
			ubigint ref
			, BrlyJMRegionTitle** rec
		) {
	return false;
};

bool TblBrlyJMRegionTitle::loadRecByRegLcl(
			ubigint refBrlyMRegion
			, uint x1IxBrlyVLocale
			, BrlyJMRegionTitle** rec
		) {
	return false;
};

ubigint TblBrlyJMRegionTitle::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyJMRegionTitle::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	return 0;
};

ubigint TblBrlyJMRegionTitle::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	ubigint numload = 0;
	BrlyJMRegionTitle* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyJMRegionTitle
 ******************************************************************************/

MyTblBrlyJMRegionTitle::MyTblBrlyJMRegionTitle() : TblBrlyJMRegionTitle(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyJMRegionTitle::~MyTblBrlyJMRegionTitle() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyJMRegionTitle::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyJMRegionTitle (refBrlyMRegion, x1IxBrlyVLocale, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyJMRegionTitle SET refBrlyMRegion = ?, x1IxBrlyVLocale = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyJMRegionTitle WHERE ref = ?", false);
};

bool MyTblBrlyJMRegionTitle::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegionTitle** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyJMRegionTitle* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyJMRegionTitle / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyJMRegionTitle();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMRegion = atoll((char*) dbrow[1]); else _rec->refBrlyMRegion = 0;
		if (dbrow[2]) _rec->x1IxBrlyVLocale = atol((char*) dbrow[2]); else _rec->x1IxBrlyVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyJMRegionTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyJMRegionTitle* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyJMRegionTitle / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyJMRegionTitle();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMRegion = atoll((char*) dbrow[1]); else rec->refBrlyMRegion = 0;
			if (dbrow[2]) rec->x1IxBrlyVLocale = atol((char*) dbrow[2]); else rec->x1IxBrlyVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyJMRegionTitle::insertRec(
			BrlyJMRegionTitle* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMRegionTitle / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMRegionTitle / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyJMRegionTitle::insertRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyJMRegionTitle::updateRec(
			BrlyJMRegionTitle* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxBrlyVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMRegionTitle / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMRegionTitle / stmtUpdateRec)\n");
};

void MyTblBrlyJMRegionTitle::updateRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyJMRegionTitle::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMRegionTitle / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMRegionTitle / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyJMRegionTitle::loadRecByRef(
			ubigint ref
			, BrlyJMRegionTitle** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyJMRegionTitle WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyJMRegionTitle::loadRecByRegLcl(
			ubigint refBrlyMRegion
			, uint x1IxBrlyVLocale
			, BrlyJMRegionTitle** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " AND x1IxBrlyVLocale = " + to_string(x1IxBrlyVLocale) + "", rec);
};

ubigint MyTblBrlyJMRegionTitle::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + "", append, refs);
};

ubigint MyTblBrlyJMRegionTitle::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " ORDER BY x1IxBrlyVLocale ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyJMRegionTitle
 ******************************************************************************/

PgTblBrlyJMRegionTitle::PgTblBrlyJMRegionTitle() : TblBrlyJMRegionTitle(), PgTable() {
};

PgTblBrlyJMRegionTitle::~PgTblBrlyJMRegionTitle() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyJMRegionTitle::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyJMRegionTitle_insertRec", "INSERT INTO TblBrlyJMRegionTitle (refBrlyMRegion, x1IxBrlyVLocale, Title) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMRegionTitle_updateRec", "UPDATE TblBrlyJMRegionTitle SET refBrlyMRegion = $1, x1IxBrlyVLocale = $2, Title = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMRegionTitle_removeRecByRef", "DELETE FROM TblBrlyJMRegionTitle WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyJMRegionTitle_loadRecByRef", "SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyJMRegionTitle_loadRecByRegLcl", "SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = $1 AND x1IxBrlyVLocale = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMRegionTitle_loadRefsByReg", "SELECT ref FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMRegionTitle_loadRstByReg", "SELECT ref, refBrlyMRegion, x1IxBrlyVLocale, Title FROM TblBrlyJMRegionTitle WHERE refBrlyMRegion = $1 ORDER BY x1IxBrlyVLocale ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyJMRegionTitle::loadRec(
			PGresult* res
			, BrlyJMRegionTitle** rec
		) {
	char* ptr;

	BrlyJMRegionTitle* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyJMRegionTitle();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "x1ixbrlyvlocale"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMRegion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxBrlyVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyJMRegionTitle::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyJMRegionTitle* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "x1ixbrlyvlocale"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new BrlyJMRegionTitle();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMRegion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxBrlyVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyJMRegionTitle::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyJMRegionTitle** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegionTitle / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMRegionTitle::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegionTitle / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyJMRegionTitle::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegionTitle** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMRegionTitle::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyJMRegionTitle::insertRec(
			BrlyJMRegionTitle* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	uint _x1IxBrlyVLocale = htonl(rec->x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1IxBrlyVLocale,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyJMRegionTitle_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegionTitle_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyJMRegionTitle::insertRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyJMRegionTitle::updateRec(
			BrlyJMRegionTitle* rec
		) {
	PGresult* res;

	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	uint _x1IxBrlyVLocale = htonl(rec->x1IxBrlyVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1IxBrlyVLocale,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyJMRegionTitle_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegionTitle_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyJMRegionTitle::updateRst(
			ListBrlyJMRegionTitle& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyJMRegionTitle::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyJMRegionTitle_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegionTitle_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyJMRegionTitle::loadRecByRef(
			ubigint ref
			, BrlyJMRegionTitle** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyJMRegionTitle_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyJMRegionTitle::loadRecByRegLcl(
			ubigint refBrlyMRegion
			, uint x1IxBrlyVLocale
			, BrlyJMRegionTitle** rec
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);
	uint _x1IxBrlyVLocale = htonl(x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1IxBrlyVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblBrlyJMRegionTitle_loadRecByRegLcl", 2, vals, l, f, rec);
};

ubigint PgTblBrlyJMRegionTitle::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);

	const char* vals[] = {
		(char*) &_refBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyJMRegionTitle_loadRefsByReg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyJMRegionTitle::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegionTitle& rst
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);

	const char* vals[] = {
		(char*) &_refBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyJMRegionTitle_loadRstByReg", 1, vals, l, f, append, rst);
};

