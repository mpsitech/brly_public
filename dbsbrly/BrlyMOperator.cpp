/**
  * \file BrlyMOperator.cpp
  * database access for table TblBrlyMOperator (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMOperator.h"

/******************************************************************************
 class BrlyMOperator
 ******************************************************************************/

BrlyMOperator::BrlyMOperator(
			const ubigint ref
			, const string sref
			, const string srefICAO
			, const string Title
		) {

	this->ref = ref;
	this->sref = sref;
	this->srefICAO = srefICAO;
	this->Title = Title;
};

bool BrlyMOperator::operator==(
			const BrlyMOperator& comp
		) {
	return false;
};

bool BrlyMOperator::operator!=(
			const BrlyMOperator& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMOperator
 ******************************************************************************/

ListBrlyMOperator::ListBrlyMOperator() {
};

ListBrlyMOperator::ListBrlyMOperator(
			const ListBrlyMOperator& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMOperator(*(src.nodes[i]));
};

ListBrlyMOperator::~ListBrlyMOperator() {
	clear();
};

void ListBrlyMOperator::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMOperator::size() const {
	return(nodes.size());
};

void ListBrlyMOperator::append(
			BrlyMOperator* rec
		) {
	nodes.push_back(rec);
};

BrlyMOperator* ListBrlyMOperator::operator[](
			const uint ix
		) {
	BrlyMOperator* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMOperator& ListBrlyMOperator::operator=(
			const ListBrlyMOperator& src
		) {
	BrlyMOperator* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMOperator(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMOperator::operator==(
			const ListBrlyMOperator& comp
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

bool ListBrlyMOperator::operator!=(
			const ListBrlyMOperator& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMOperator
 ******************************************************************************/

TblBrlyMOperator::TblBrlyMOperator() {
};

TblBrlyMOperator::~TblBrlyMOperator() {
};

bool TblBrlyMOperator::loadRecBySQL(
			const string& sqlstr
			, BrlyMOperator** rec
		) {
	return false;
};

ubigint TblBrlyMOperator::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMOperator& rst
		) {
	return 0;
};

void TblBrlyMOperator::insertRec(
			BrlyMOperator* rec
		) {
};

ubigint TblBrlyMOperator::insertNewRec(
			BrlyMOperator** rec
			, const string sref
			, const string srefICAO
			, const string Title
		) {
	ubigint retval = 0;
	BrlyMOperator* _rec = NULL;

	_rec = new BrlyMOperator(0, sref, srefICAO, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMOperator::appendNewRecToRst(
			ListBrlyMOperator& rst
			, BrlyMOperator** rec
			, const string sref
			, const string srefICAO
			, const string Title
		) {
	ubigint retval = 0;
	BrlyMOperator* _rec = NULL;

	retval = insertNewRec(&_rec, sref, srefICAO, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMOperator::insertRst(
			ListBrlyMOperator& rst
			, bool transact
		) {
};

void TblBrlyMOperator::updateRec(
			BrlyMOperator* rec
		) {
};

void TblBrlyMOperator::updateRst(
			ListBrlyMOperator& rst
			, bool transact
		) {
};

void TblBrlyMOperator::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMOperator::loadRecByRef(
			ubigint ref
			, BrlyMOperator** rec
		) {
	return false;
};

bool TblBrlyMOperator::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblBrlyMOperator::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblBrlyMOperator::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMOperator& rst
		) {
	ubigint numload = 0;
	BrlyMOperator* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMOperator
 ******************************************************************************/

MyTblBrlyMOperator::MyTblBrlyMOperator() : TblBrlyMOperator(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMOperator::~MyTblBrlyMOperator() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMOperator::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMOperator (sref, srefICAO, Title) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMOperator SET sref = ?, srefICAO = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMOperator WHERE ref = ?", false);
};

bool MyTblBrlyMOperator::loadRecBySQL(
			const string& sqlstr
			, BrlyMOperator** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMOperator* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMOperator / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMOperator();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->sref.assign(dbrow[1], dblengths[1]); else _rec->sref = "";
		if (dbrow[2]) _rec->srefICAO.assign(dbrow[2], dblengths[2]); else _rec->srefICAO = "";
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMOperator::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMOperator& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMOperator* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMOperator / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMOperator();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->sref.assign(dbrow[1], dblengths[1]); else rec->sref = "";
			if (dbrow[2]) rec->srefICAO.assign(dbrow[2], dblengths[2]); else rec->srefICAO = "";
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMOperator::insertRec(
			BrlyMOperator* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[0] = rec->sref.length();
	l[1] = rec->srefICAO.length();
	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->srefICAO.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMOperator / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMOperator / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMOperator::insertRst(
			ListBrlyMOperator& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMOperator::updateRec(
			BrlyMOperator* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[0] = rec->sref.length();
	l[1] = rec->srefICAO.length();
	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindCstring((char*) (rec->sref.c_str()),&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->srefICAO.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMOperator / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMOperator / stmtUpdateRec)\n");
};

void MyTblBrlyMOperator::updateRst(
			ListBrlyMOperator& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMOperator::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMOperator / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMOperator / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMOperator::loadRecByRef(
			ubigint ref
			, BrlyMOperator** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMOperator WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMOperator::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblBrlyMOperator WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblBrlyMOperator::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblBrlyMOperator WHERE ref = " + to_string(ref) + "", Title);
};

/******************************************************************************
 class PgTblBrlyMOperator
 ******************************************************************************/

PgTblBrlyMOperator::PgTblBrlyMOperator() : TblBrlyMOperator(), PgTable() {
};

PgTblBrlyMOperator::~PgTblBrlyMOperator() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMOperator::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMOperator_insertRec", "INSERT INTO TblBrlyMOperator (sref, srefICAO, Title) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMOperator_updateRec", "UPDATE TblBrlyMOperator SET sref = $1, srefICAO = $2, Title = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMOperator_removeRecByRef", "DELETE FROM TblBrlyMOperator WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMOperator_loadRecByRef", "SELECT ref, sref, srefICAO, Title FROM TblBrlyMOperator WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMOperator_loadSrfByRef", "SELECT sref FROM TblBrlyMOperator WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMOperator_loadTitByRef", "SELECT Title FROM TblBrlyMOperator WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMOperator::loadRec(
			PGresult* res
			, BrlyMOperator** rec
		) {
	char* ptr;

	BrlyMOperator* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMOperator();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "sreficao"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[1]));
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->srefICAO.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMOperator::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMOperator& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMOperator* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "sreficao"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new BrlyMOperator();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[1]));
			ptr = PQgetvalue(res, numread, fnum[2]); rec->srefICAO.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMOperator::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMOperator** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMOperator / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyMOperator::loadRecBySQL(
			const string& sqlstr
			, BrlyMOperator** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMOperator::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMOperator& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMOperator::insertRec(
			BrlyMOperator* rec
		) {
	PGresult* res;
	char* ptr;

	const char* vals[] = {
		rec->sref.c_str(),
		rec->srefICAO.c_str(),
		rec->Title.c_str()
	};
	const int l[] = {
		0,
		0,
		0
	};
	const int f[] = {0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyMOperator_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMOperator_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMOperator::insertRst(
			ListBrlyMOperator& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMOperator::updateRec(
			BrlyMOperator* rec
		) {
	PGresult* res;

	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		rec->sref.c_str(),
		rec->srefICAO.c_str(),
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMOperator_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMOperator_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMOperator::updateRst(
			ListBrlyMOperator& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMOperator::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMOperator_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMOperator_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMOperator::loadRecByRef(
			ubigint ref
			, BrlyMOperator** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMOperator_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMOperator::loadSrfByRef(
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

	return loadStringByStmt("TblBrlyMOperator_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblBrlyMOperator::loadTitByRef(
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

	return loadStringByStmt("TblBrlyMOperator_loadTitByRef", 1, vals, l, f, Title);
};

