/**
  * \file BrlyMTimetable.cpp
  * database access for table TblBrlyMTimetable (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMTimetable.h"

/******************************************************************************
 class BrlyMTimetable
 ******************************************************************************/

BrlyMTimetable::BrlyMTimetable(
			const ubigint ref
			, const ubigint refBrlyMFile
			, const string srefBrlyKAlliance
			, const string Title
			, const uint startd
			, const uint stopd
		) {

	this->ref = ref;
	this->refBrlyMFile = refBrlyMFile;
	this->srefBrlyKAlliance = srefBrlyKAlliance;
	this->Title = Title;
	this->startd = startd;
	this->stopd = stopd;
};

bool BrlyMTimetable::operator==(
			const BrlyMTimetable& comp
		) {
	return false;
};

bool BrlyMTimetable::operator!=(
			const BrlyMTimetable& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMTimetable
 ******************************************************************************/

ListBrlyMTimetable::ListBrlyMTimetable() {
};

ListBrlyMTimetable::ListBrlyMTimetable(
			const ListBrlyMTimetable& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMTimetable(*(src.nodes[i]));
};

ListBrlyMTimetable::~ListBrlyMTimetable() {
	clear();
};

void ListBrlyMTimetable::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMTimetable::size() const {
	return(nodes.size());
};

void ListBrlyMTimetable::append(
			BrlyMTimetable* rec
		) {
	nodes.push_back(rec);
};

BrlyMTimetable* ListBrlyMTimetable::operator[](
			const uint ix
		) {
	BrlyMTimetable* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMTimetable& ListBrlyMTimetable::operator=(
			const ListBrlyMTimetable& src
		) {
	BrlyMTimetable* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMTimetable(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMTimetable::operator==(
			const ListBrlyMTimetable& comp
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

bool ListBrlyMTimetable::operator!=(
			const ListBrlyMTimetable& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMTimetable
 ******************************************************************************/

TblBrlyMTimetable::TblBrlyMTimetable() {
};

TblBrlyMTimetable::~TblBrlyMTimetable() {
};

bool TblBrlyMTimetable::loadRecBySQL(
			const string& sqlstr
			, BrlyMTimetable** rec
		) {
	return false;
};

ubigint TblBrlyMTimetable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMTimetable& rst
		) {
	return 0;
};

void TblBrlyMTimetable::insertRec(
			BrlyMTimetable* rec
		) {
};

ubigint TblBrlyMTimetable::insertNewRec(
			BrlyMTimetable** rec
			, const ubigint refBrlyMFile
			, const string srefBrlyKAlliance
			, const string Title
			, const uint startd
			, const uint stopd
		) {
	ubigint retval = 0;
	BrlyMTimetable* _rec = NULL;

	_rec = new BrlyMTimetable(0, refBrlyMFile, srefBrlyKAlliance, Title, startd, stopd);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMTimetable::appendNewRecToRst(
			ListBrlyMTimetable& rst
			, BrlyMTimetable** rec
			, const ubigint refBrlyMFile
			, const string srefBrlyKAlliance
			, const string Title
			, const uint startd
			, const uint stopd
		) {
	ubigint retval = 0;
	BrlyMTimetable* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMFile, srefBrlyKAlliance, Title, startd, stopd);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMTimetable::insertRst(
			ListBrlyMTimetable& rst
			, bool transact
		) {
};

void TblBrlyMTimetable::updateRec(
			BrlyMTimetable* rec
		) {
};

void TblBrlyMTimetable::updateRst(
			ListBrlyMTimetable& rst
			, bool transact
		) {
};

void TblBrlyMTimetable::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMTimetable::loadRecByRef(
			ubigint ref
			, BrlyMTimetable** rec
		) {
	return false;
};

bool TblBrlyMTimetable::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblBrlyMTimetable::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMTimetable& rst
		) {
	ubigint numload = 0;
	BrlyMTimetable* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMTimetable
 ******************************************************************************/

MyTblBrlyMTimetable::MyTblBrlyMTimetable() : TblBrlyMTimetable(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMTimetable::~MyTblBrlyMTimetable() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMTimetable::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMTimetable (refBrlyMFile, srefBrlyKAlliance, Title, startd, stopd) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMTimetable SET refBrlyMFile = ?, srefBrlyKAlliance = ?, Title = ?, startd = ?, stopd = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMTimetable WHERE ref = ?", false);
};

bool MyTblBrlyMTimetable::loadRecBySQL(
			const string& sqlstr
			, BrlyMTimetable** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMTimetable* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMTimetable / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMTimetable();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMFile = atoll((char*) dbrow[1]); else _rec->refBrlyMFile = 0;
		if (dbrow[2]) _rec->srefBrlyKAlliance.assign(dbrow[2], dblengths[2]); else _rec->srefBrlyKAlliance = "";
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->startd = atol((char*) dbrow[4]); else _rec->startd = 0;
		if (dbrow[5]) _rec->stopd = atol((char*) dbrow[5]); else _rec->stopd = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMTimetable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMTimetable& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMTimetable* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMTimetable / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMTimetable();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMFile = atoll((char*) dbrow[1]); else rec->refBrlyMFile = 0;
			if (dbrow[2]) rec->srefBrlyKAlliance.assign(dbrow[2], dblengths[2]); else rec->srefBrlyKAlliance = "";
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->startd = atol((char*) dbrow[4]); else rec->startd = 0;
			if (dbrow[5]) rec->stopd = atol((char*) dbrow[5]); else rec->stopd = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMTimetable::insertRec(
			BrlyMTimetable* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[1] = rec->srefBrlyKAlliance.length();
	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMFile,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->srefBrlyKAlliance.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->startd,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->stopd,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMTimetable / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMTimetable / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMTimetable::insertRst(
			ListBrlyMTimetable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMTimetable::updateRec(
			BrlyMTimetable* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[1] = rec->srefBrlyKAlliance.length();
	l[2] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMFile,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->srefBrlyKAlliance.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->startd,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->stopd,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMTimetable / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMTimetable / stmtUpdateRec)\n");
};

void MyTblBrlyMTimetable::updateRst(
			ListBrlyMTimetable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMTimetable::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMTimetable / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMTimetable / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMTimetable::loadRecByRef(
			ubigint ref
			, BrlyMTimetable** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMTimetable WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMTimetable::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblBrlyMTimetable WHERE ref = " + to_string(ref) + "", Title);
};

/******************************************************************************
 class PgTblBrlyMTimetable
 ******************************************************************************/

PgTblBrlyMTimetable::PgTblBrlyMTimetable() : TblBrlyMTimetable(), PgTable() {
};

PgTblBrlyMTimetable::~PgTblBrlyMTimetable() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMTimetable::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMTimetable_insertRec", "INSERT INTO TblBrlyMTimetable (refBrlyMFile, srefBrlyKAlliance, Title, startd, stopd) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMTimetable_updateRec", "UPDATE TblBrlyMTimetable SET refBrlyMFile = $1, srefBrlyKAlliance = $2, Title = $3, startd = $4, stopd = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMTimetable_removeRecByRef", "DELETE FROM TblBrlyMTimetable WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMTimetable_loadRecByRef", "SELECT ref, refBrlyMFile, srefBrlyKAlliance, Title, startd, stopd FROM TblBrlyMTimetable WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMTimetable_loadTitByRef", "SELECT Title FROM TblBrlyMTimetable WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMTimetable::loadRec(
			PGresult* res
			, BrlyMTimetable** rec
		) {
	char* ptr;

	BrlyMTimetable* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMTimetable();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymfile"),
			PQfnumber(res, "srefbrlykalliance"),
			PQfnumber(res, "title"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "stopd")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->srefBrlyKAlliance.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->stopd = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMTimetable::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMTimetable& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMTimetable* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymfile"),
			PQfnumber(res, "srefbrlykalliance"),
			PQfnumber(res, "title"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "stopd")
		};

		while (numread < numrow) {
			rec = new BrlyMTimetable();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->srefBrlyKAlliance.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->stopd = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMTimetable::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMTimetable** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMTimetable / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyMTimetable::loadRecBySQL(
			const string& sqlstr
			, BrlyMTimetable** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMTimetable::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMTimetable& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMTimetable::insertRec(
			BrlyMTimetable* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMFile = htonl64(rec->refBrlyMFile);
	uint _startd = htonl(rec->startd);
	uint _stopd = htonl(rec->stopd);

	const char* vals[] = {
		(char*) &_refBrlyMFile,
		rec->srefBrlyKAlliance.c_str(),
		rec->Title.c_str(),
		(char*) &_startd,
		(char*) &_stopd
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMTimetable_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMTimetable_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMTimetable::insertRst(
			ListBrlyMTimetable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMTimetable::updateRec(
			BrlyMTimetable* rec
		) {
	PGresult* res;

	ubigint _refBrlyMFile = htonl64(rec->refBrlyMFile);
	uint _startd = htonl(rec->startd);
	uint _stopd = htonl(rec->stopd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMFile,
		rec->srefBrlyKAlliance.c_str(),
		rec->Title.c_str(),
		(char*) &_startd,
		(char*) &_stopd,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMTimetable_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMTimetable_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMTimetable::updateRst(
			ListBrlyMTimetable& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMTimetable::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMTimetable_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMTimetable_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMTimetable::loadRecByRef(
			ubigint ref
			, BrlyMTimetable** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMTimetable_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMTimetable::loadTitByRef(
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

	return loadStringByStmt("TblBrlyMTimetable_loadTitByRef", 1, vals, l, f, Title);
};

