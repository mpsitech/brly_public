/**
  * \file BrlyMPlntype.cpp
  * database access for table TblBrlyMPlntype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMPlntype.h"

/******************************************************************************
 class BrlyMPlntype
 ******************************************************************************/

BrlyMPlntype::BrlyMPlntype(
			const ubigint ref
			, const string sref
			, const string Title
			, const string srefBrlyKEqptype
			, const usmallint Capacity
		) {

	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->srefBrlyKEqptype = srefBrlyKEqptype;
	this->Capacity = Capacity;
};

bool BrlyMPlntype::operator==(
			const BrlyMPlntype& comp
		) {
	return false;
};

bool BrlyMPlntype::operator!=(
			const BrlyMPlntype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMPlntype
 ******************************************************************************/

ListBrlyMPlntype::ListBrlyMPlntype() {
};

ListBrlyMPlntype::ListBrlyMPlntype(
			const ListBrlyMPlntype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMPlntype(*(src.nodes[i]));
};

ListBrlyMPlntype::~ListBrlyMPlntype() {
	clear();
};

void ListBrlyMPlntype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMPlntype::size() const {
	return(nodes.size());
};

void ListBrlyMPlntype::append(
			BrlyMPlntype* rec
		) {
	nodes.push_back(rec);
};

BrlyMPlntype* ListBrlyMPlntype::operator[](
			const uint ix
		) {
	BrlyMPlntype* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMPlntype& ListBrlyMPlntype::operator=(
			const ListBrlyMPlntype& src
		) {
	BrlyMPlntype* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMPlntype(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMPlntype::operator==(
			const ListBrlyMPlntype& comp
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

bool ListBrlyMPlntype::operator!=(
			const ListBrlyMPlntype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMPlntype
 ******************************************************************************/

TblBrlyMPlntype::TblBrlyMPlntype() {
};

TblBrlyMPlntype::~TblBrlyMPlntype() {
};

bool TblBrlyMPlntype::loadRecBySQL(
			const string& sqlstr
			, BrlyMPlntype** rec
		) {
	return false;
};

ubigint TblBrlyMPlntype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMPlntype& rst
		) {
	return 0;
};

void TblBrlyMPlntype::insertRec(
			BrlyMPlntype* rec
		) {
};

ubigint TblBrlyMPlntype::insertNewRec(
			BrlyMPlntype** rec
			, const string sref
			, const string Title
			, const string srefBrlyKEqptype
			, const usmallint Capacity
		) {
	ubigint retval = 0;
	BrlyMPlntype* _rec = NULL;

	_rec = new BrlyMPlntype(0, sref, Title, srefBrlyKEqptype, Capacity);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMPlntype::appendNewRecToRst(
			ListBrlyMPlntype& rst
			, BrlyMPlntype** rec
			, const string sref
			, const string Title
			, const string srefBrlyKEqptype
			, const usmallint Capacity
		) {
	ubigint retval = 0;
	BrlyMPlntype* _rec = NULL;

	retval = insertNewRec(&_rec, sref, Title, srefBrlyKEqptype, Capacity);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMPlntype::insertRst(
			ListBrlyMPlntype& rst
			, bool transact
		) {
};

void TblBrlyMPlntype::updateRec(
			BrlyMPlntype* rec
		) {
};

void TblBrlyMPlntype::updateRst(
			ListBrlyMPlntype& rst
			, bool transact
		) {
};

void TblBrlyMPlntype::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMPlntype::loadRecByRef(
			ubigint ref
			, BrlyMPlntype** rec
		) {
	return false;
};

bool TblBrlyMPlntype::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblBrlyMPlntype::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblBrlyMPlntype::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMPlntype& rst
		) {
	ubigint numload = 0;
	BrlyMPlntype* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMPlntype
 ******************************************************************************/

MyTblBrlyMPlntype::MyTblBrlyMPlntype() : TblBrlyMPlntype(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMPlntype::~MyTblBrlyMPlntype() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMPlntype::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMPlntype (sref, Title, srefBrlyKEqptype, Capacity) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMPlntype SET sref = ?, Title = ?, srefBrlyKEqptype = ?, Capacity = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMPlntype WHERE ref = ?", false);
};

bool MyTblBrlyMPlntype::loadRecBySQL(
			const string& sqlstr
			, BrlyMPlntype** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMPlntype* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMPlntype / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMPlntype();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->sref.assign(dbrow[1], dblengths[1]); else _rec->sref = "";
		if (dbrow[2]) _rec->Title.assign(dbrow[2], dblengths[2]); else _rec->Title = "";
		if (dbrow[3]) _rec->srefBrlyKEqptype.assign(dbrow[3], dblengths[3]); else _rec->srefBrlyKEqptype = "";
		if (dbrow[4]) _rec->Capacity = atoi((char*) dbrow[4]); else _rec->Capacity = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMPlntype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMPlntype& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMPlntype* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMPlntype / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMPlntype();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->sref.assign(dbrow[1], dblengths[1]); else rec->sref = "";
			if (dbrow[2]) rec->Title.assign(dbrow[2], dblengths[2]); else rec->Title = "";
			if (dbrow[3]) rec->srefBrlyKEqptype.assign(dbrow[3], dblengths[3]); else rec->srefBrlyKEqptype = "";
			if (dbrow[4]) rec->Capacity = atoi((char*) dbrow[4]); else rec->Capacity = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMPlntype::insertRec(
			BrlyMPlntype* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[0] = rec->sref.length();
	l[1] = rec->Title.length();
	l[2] = rec->srefBrlyKEqptype.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefBrlyKEqptype.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->Capacity,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMPlntype / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMPlntype / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMPlntype::insertRst(
			ListBrlyMPlntype& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMPlntype::updateRec(
			BrlyMPlntype* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[0] = rec->sref.length();
	l[1] = rec->Title.length();
	l[2] = rec->srefBrlyKEqptype.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->Title.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefBrlyKEqptype.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUsmallint(&rec->Capacity,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMPlntype / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMPlntype / stmtUpdateRec)\n");
};

void MyTblBrlyMPlntype::updateRst(
			ListBrlyMPlntype& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMPlntype::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMPlntype / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMPlntype / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMPlntype::loadRecByRef(
			ubigint ref
			, BrlyMPlntype** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMPlntype WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMPlntype::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblBrlyMPlntype WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblBrlyMPlntype::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblBrlyMPlntype WHERE ref = " + to_string(ref) + "", Title);
};

/******************************************************************************
 class PgTblBrlyMPlntype
 ******************************************************************************/

PgTblBrlyMPlntype::PgTblBrlyMPlntype() : TblBrlyMPlntype(), PgTable() {
};

PgTblBrlyMPlntype::~PgTblBrlyMPlntype() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMPlntype::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMPlntype_insertRec", "INSERT INTO TblBrlyMPlntype (sref, Title, srefBrlyKEqptype, Capacity) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMPlntype_updateRec", "UPDATE TblBrlyMPlntype SET sref = $1, Title = $2, srefBrlyKEqptype = $3, Capacity = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMPlntype_removeRecByRef", "DELETE FROM TblBrlyMPlntype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMPlntype_loadRecByRef", "SELECT ref, sref, Title, srefBrlyKEqptype, Capacity FROM TblBrlyMPlntype WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMPlntype_loadSrfByRef", "SELECT sref FROM TblBrlyMPlntype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMPlntype_loadTitByRef", "SELECT Title FROM TblBrlyMPlntype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMPlntype::loadRec(
			PGresult* res
			, BrlyMPlntype** rec
		) {
	char* ptr;

	BrlyMPlntype* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMPlntype();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "srefbrlykeqptype"),
			PQfnumber(res, "capacity")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[1]));
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srefBrlyKEqptype.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Capacity = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMPlntype::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMPlntype& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMPlntype* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "srefbrlykeqptype"),
			PQfnumber(res, "capacity")
		};

		while (numread < numrow) {
			rec = new BrlyMPlntype();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[1]));
			ptr = PQgetvalue(res, numread, fnum[2]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srefBrlyKEqptype.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Capacity = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMPlntype::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMPlntype** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMPlntype / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyMPlntype::loadRecBySQL(
			const string& sqlstr
			, BrlyMPlntype** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMPlntype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMPlntype& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMPlntype::insertRec(
			BrlyMPlntype* rec
		) {
	PGresult* res;
	char* ptr;

	usmallint _Capacity = htons(rec->Capacity);

	const char* vals[] = {
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->srefBrlyKEqptype.c_str(),
		(char*) &_Capacity
	};
	const int l[] = {
		0,
		0,
		0,
		sizeof(usmallint)
	};
	const int f[] = {0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMPlntype_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMPlntype_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMPlntype::insertRst(
			ListBrlyMPlntype& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMPlntype::updateRec(
			BrlyMPlntype* rec
		) {
	PGresult* res;

	usmallint _Capacity = htons(rec->Capacity);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->srefBrlyKEqptype.c_str(),
		(char*) &_Capacity,
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		0,
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMPlntype_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMPlntype_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMPlntype::updateRst(
			ListBrlyMPlntype& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMPlntype::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMPlntype_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMPlntype_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMPlntype::loadRecByRef(
			ubigint ref
			, BrlyMPlntype** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMPlntype_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMPlntype::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblBrlyMPlntype_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblBrlyMPlntype::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblBrlyMPlntype_loadTitByRef", 1, vals, l, f, Title);
};

