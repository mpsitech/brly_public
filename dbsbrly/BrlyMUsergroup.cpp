/**
  * \file BrlyMUsergroup.cpp
  * database access for table TblBrlyMUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMUsergroup.h"

/******************************************************************************
 class BrlyMUsergroup
 ******************************************************************************/

BrlyMUsergroup::BrlyMUsergroup(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->sref = sref;
	this->Comment = Comment;
};

bool BrlyMUsergroup::operator==(
			const BrlyMUsergroup& comp
		) {
	return false;
};

bool BrlyMUsergroup::operator!=(
			const BrlyMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMUsergroup
 ******************************************************************************/

ListBrlyMUsergroup::ListBrlyMUsergroup() {
};

ListBrlyMUsergroup::ListBrlyMUsergroup(
			const ListBrlyMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMUsergroup(*(src.nodes[i]));
};

ListBrlyMUsergroup::~ListBrlyMUsergroup() {
	clear();
};

void ListBrlyMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMUsergroup::size() const {
	return(nodes.size());
};

void ListBrlyMUsergroup::append(
			BrlyMUsergroup* rec
		) {
	nodes.push_back(rec);
};

BrlyMUsergroup* ListBrlyMUsergroup::operator[](
			const uint ix
		) {
	BrlyMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMUsergroup& ListBrlyMUsergroup::operator=(
			const ListBrlyMUsergroup& src
		) {
	BrlyMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMUsergroup::operator==(
			const ListBrlyMUsergroup& comp
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

bool ListBrlyMUsergroup::operator!=(
			const ListBrlyMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMUsergroup
 ******************************************************************************/

TblBrlyMUsergroup::TblBrlyMUsergroup() {
};

TblBrlyMUsergroup::~TblBrlyMUsergroup() {
};

bool TblBrlyMUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyMUsergroup** rec
		) {
	return false;
};

ubigint TblBrlyMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMUsergroup& rst
		) {
	return 0;
};

void TblBrlyMUsergroup::insertRec(
			BrlyMUsergroup* rec
		) {
};

ubigint TblBrlyMUsergroup::insertNewRec(
			BrlyMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyMUsergroup* _rec = NULL;

	_rec = new BrlyMUsergroup(0, grp, own, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMUsergroup::appendNewRecToRst(
			ListBrlyMUsergroup& rst
			, BrlyMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMUsergroup::insertRst(
			ListBrlyMUsergroup& rst
			, bool transact
		) {
};

void TblBrlyMUsergroup::updateRec(
			BrlyMUsergroup* rec
		) {
};

void TblBrlyMUsergroup::updateRst(
			ListBrlyMUsergroup& rst
			, bool transact
		) {
};

void TblBrlyMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMUsergroup::loadRecByRef(
			ubigint ref
			, BrlyMUsergroup** rec
		) {
	return false;
};

bool TblBrlyMUsergroup::loadRecBySrf(
			string sref
			, BrlyMUsergroup** rec
		) {
	return false;
};

bool TblBrlyMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

bool TblBrlyMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

ubigint TblBrlyMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMUsergroup& rst
		) {
	ubigint numload = 0;
	BrlyMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMUsergroup
 ******************************************************************************/

MyTblBrlyMUsergroup::MyTblBrlyMUsergroup() : TblBrlyMUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMUsergroup::~MyTblBrlyMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMUsergroup (grp, own, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMUsergroup SET grp = ?, own = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMUsergroup WHERE ref = ?", false);
};

bool MyTblBrlyMUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMUsergroup::insertRec(
			BrlyMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMUsergroup / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMUsergroup / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMUsergroup::insertRst(
			ListBrlyMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMUsergroup::updateRec(
			BrlyMUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMUsergroup / stmtUpdateRec)\n");
};

void MyTblBrlyMUsergroup::updateRst(
			ListBrlyMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMUsergroup / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMUsergroup / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMUsergroup::loadRecByRef(
			ubigint ref
			, BrlyMUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMUsergroup WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMUsergroup::loadRecBySrf(
			string sref
			, BrlyMUsergroup** rec
		) {
	return loadRecBySQL("SELECT ref, grp, own, sref, Comment FROM TblBrlyMUsergroup WHERE sref = '" + sref + "'", rec);
};

bool MyTblBrlyMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyMUsergroup WHERE sref = '" + sref + "'", ref);
};

bool MyTblBrlyMUsergroup::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblBrlyMUsergroup WHERE ref = " + to_string(ref) + "", sref);
};

/******************************************************************************
 class PgTblBrlyMUsergroup
 ******************************************************************************/

PgTblBrlyMUsergroup::PgTblBrlyMUsergroup() : TblBrlyMUsergroup(), PgTable() {
};

PgTblBrlyMUsergroup::~PgTblBrlyMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMUsergroup_insertRec", "INSERT INTO TblBrlyMUsergroup (grp, own, sref, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMUsergroup_updateRec", "UPDATE TblBrlyMUsergroup SET grp = $1, own = $2, sref = $3, Comment = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMUsergroup_removeRecByRef", "DELETE FROM TblBrlyMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMUsergroup_loadRecByRef", "SELECT ref, grp, own, sref, Comment FROM TblBrlyMUsergroup WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMUsergroup_loadRecBySrf", "SELECT ref, grp, own, sref, Comment FROM TblBrlyMUsergroup WHERE sref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMUsergroup_loadRefBySrf", "SELECT ref FROM TblBrlyMUsergroup WHERE sref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMUsergroup_loadSrfByRef", "SELECT sref FROM TblBrlyMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMUsergroup::loadRec(
			PGresult* res
			, BrlyMUsergroup** rec
		) {
	char* ptr;

	BrlyMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new BrlyMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyMUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMUsergroup::insertRec(
			BrlyMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyMUsergroup_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMUsergroup::insertRst(
			ListBrlyMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMUsergroup::updateRec(
			BrlyMUsergroup* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMUsergroup_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMUsergroup::updateRst(
			ListBrlyMUsergroup& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMUsergroup_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMUsergroup::loadRecByRef(
			ubigint ref
			, BrlyMUsergroup** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMUsergroup::loadRecBySrf(
			string sref
			, BrlyMUsergroup** rec
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRecByStmt("TblBrlyMUsergroup_loadRecBySrf", 1, vals, l, f, rec);
};

bool PgTblBrlyMUsergroup::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblBrlyMUsergroup_loadRefBySrf", 1, vals, l, f, ref);
};

bool PgTblBrlyMUsergroup::loadSrfByRef(
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

	return loadStringByStmt("TblBrlyMUsergroup_loadSrfByRef", 1, vals, l, f, sref);
};

