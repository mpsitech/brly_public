/**
  * \file BrlyAMRegionDstswitch.cpp
  * database access for table TblBrlyAMRegionDstswitch (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyAMRegionDstswitch.h"

/******************************************************************************
 class BrlyAMRegionDstswitch
 ******************************************************************************/

BrlyAMRegionDstswitch::BrlyAMRegionDstswitch(
			const ubigint ref
			, const ubigint refBrlyMRegion
			, const uint startd
			, const uint startt
		) {

	this->ref = ref;
	this->refBrlyMRegion = refBrlyMRegion;
	this->startd = startd;
	this->startt = startt;
};

bool BrlyAMRegionDstswitch::operator==(
			const BrlyAMRegionDstswitch& comp
		) {
	return false;
};

bool BrlyAMRegionDstswitch::operator!=(
			const BrlyAMRegionDstswitch& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAMRegionDstswitch
 ******************************************************************************/

ListBrlyAMRegionDstswitch::ListBrlyAMRegionDstswitch() {
};

ListBrlyAMRegionDstswitch::ListBrlyAMRegionDstswitch(
			const ListBrlyAMRegionDstswitch& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyAMRegionDstswitch(*(src.nodes[i]));
};

ListBrlyAMRegionDstswitch::~ListBrlyAMRegionDstswitch() {
	clear();
};

void ListBrlyAMRegionDstswitch::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAMRegionDstswitch::size() const {
	return(nodes.size());
};

void ListBrlyAMRegionDstswitch::append(
			BrlyAMRegionDstswitch* rec
		) {
	nodes.push_back(rec);
};

BrlyAMRegionDstswitch* ListBrlyAMRegionDstswitch::operator[](
			const uint ix
		) {
	BrlyAMRegionDstswitch* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAMRegionDstswitch& ListBrlyAMRegionDstswitch::operator=(
			const ListBrlyAMRegionDstswitch& src
		) {
	BrlyAMRegionDstswitch* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyAMRegionDstswitch(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAMRegionDstswitch::operator==(
			const ListBrlyAMRegionDstswitch& comp
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

bool ListBrlyAMRegionDstswitch::operator!=(
			const ListBrlyAMRegionDstswitch& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAMRegionDstswitch
 ******************************************************************************/

TblBrlyAMRegionDstswitch::TblBrlyAMRegionDstswitch() {
};

TblBrlyAMRegionDstswitch::~TblBrlyAMRegionDstswitch() {
};

bool TblBrlyAMRegionDstswitch::loadRecBySQL(
			const string& sqlstr
			, BrlyAMRegionDstswitch** rec
		) {
	return false;
};

ubigint TblBrlyAMRegionDstswitch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	return 0;
};

void TblBrlyAMRegionDstswitch::insertRec(
			BrlyAMRegionDstswitch* rec
		) {
};

ubigint TblBrlyAMRegionDstswitch::insertNewRec(
			BrlyAMRegionDstswitch** rec
			, const ubigint refBrlyMRegion
			, const uint startd
			, const uint startt
		) {
	ubigint retval = 0;
	BrlyAMRegionDstswitch* _rec = NULL;

	_rec = new BrlyAMRegionDstswitch(0, refBrlyMRegion, startd, startt);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAMRegionDstswitch::appendNewRecToRst(
			ListBrlyAMRegionDstswitch& rst
			, BrlyAMRegionDstswitch** rec
			, const ubigint refBrlyMRegion
			, const uint startd
			, const uint startt
		) {
	ubigint retval = 0;
	BrlyAMRegionDstswitch* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMRegion, startd, startt);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAMRegionDstswitch::insertRst(
			ListBrlyAMRegionDstswitch& rst
			, bool transact
		) {
};

void TblBrlyAMRegionDstswitch::updateRec(
			BrlyAMRegionDstswitch* rec
		) {
};

void TblBrlyAMRegionDstswitch::updateRst(
			ListBrlyAMRegionDstswitch& rst
			, bool transact
		) {
};

void TblBrlyAMRegionDstswitch::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAMRegionDstswitch::loadRecByRef(
			ubigint ref
			, BrlyAMRegionDstswitch** rec
		) {
	return false;
};

ubigint TblBrlyAMRegionDstswitch::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyAMRegionDstswitch::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	return 0;
};

ubigint TblBrlyAMRegionDstswitch::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	ubigint numload = 0;
	BrlyAMRegionDstswitch* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyAMRegionDstswitch
 ******************************************************************************/

MyTblBrlyAMRegionDstswitch::MyTblBrlyAMRegionDstswitch() : TblBrlyAMRegionDstswitch(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAMRegionDstswitch::~MyTblBrlyAMRegionDstswitch() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAMRegionDstswitch::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAMRegionDstswitch (refBrlyMRegion, startd, startt) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAMRegionDstswitch SET refBrlyMRegion = ?, startd = ?, startt = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAMRegionDstswitch WHERE ref = ?", false);
};

bool MyTblBrlyAMRegionDstswitch::loadRecBySQL(
			const string& sqlstr
			, BrlyAMRegionDstswitch** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAMRegionDstswitch* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAMRegionDstswitch / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyAMRegionDstswitch();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMRegion = atoll((char*) dbrow[1]); else _rec->refBrlyMRegion = 0;
		if (dbrow[2]) _rec->startd = atol((char*) dbrow[2]); else _rec->startd = 0;
		if (dbrow[3]) _rec->startt = atol((char*) dbrow[3]); else _rec->startt = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAMRegionDstswitch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAMRegionDstswitch* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAMRegionDstswitch / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyAMRegionDstswitch();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMRegion = atoll((char*) dbrow[1]); else rec->refBrlyMRegion = 0;
			if (dbrow[2]) rec->startd = atol((char*) dbrow[2]); else rec->startd = 0;
			if (dbrow[3]) rec->startt = atol((char*) dbrow[3]); else rec->startt = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyAMRegionDstswitch::insertRec(
			BrlyAMRegionDstswitch* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->startt,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMRegionDstswitch / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMRegionDstswitch / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyAMRegionDstswitch::insertRst(
			ListBrlyAMRegionDstswitch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAMRegionDstswitch::updateRec(
			BrlyAMRegionDstswitch* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->startt,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMRegionDstswitch / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMRegionDstswitch / stmtUpdateRec)\n");
};

void MyTblBrlyAMRegionDstswitch::updateRst(
			ListBrlyAMRegionDstswitch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAMRegionDstswitch::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAMRegionDstswitch / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAMRegionDstswitch / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyAMRegionDstswitch::loadRecByRef(
			ubigint ref
			, BrlyAMRegionDstswitch** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyAMRegionDstswitch WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyAMRegionDstswitch::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyAMRegionDstswitch WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + "", append, refs);
};

ubigint MyTblBrlyAMRegionDstswitch::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMRegion, startd, startt FROM TblBrlyAMRegionDstswitch WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " ORDER BY startd ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyAMRegionDstswitch
 ******************************************************************************/

PgTblBrlyAMRegionDstswitch::PgTblBrlyAMRegionDstswitch() : TblBrlyAMRegionDstswitch(), PgTable() {
};

PgTblBrlyAMRegionDstswitch::~PgTblBrlyAMRegionDstswitch() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAMRegionDstswitch::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyAMRegionDstswitch_insertRec", "INSERT INTO TblBrlyAMRegionDstswitch (refBrlyMRegion, startd, startt) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMRegionDstswitch_updateRec", "UPDATE TblBrlyAMRegionDstswitch SET refBrlyMRegion = $1, startd = $2, startt = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMRegionDstswitch_removeRecByRef", "DELETE FROM TblBrlyAMRegionDstswitch WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyAMRegionDstswitch_loadRecByRef", "SELECT ref, refBrlyMRegion, startd, startt FROM TblBrlyAMRegionDstswitch WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyAMRegionDstswitch_loadRefsByReg", "SELECT ref FROM TblBrlyAMRegionDstswitch WHERE refBrlyMRegion = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAMRegionDstswitch_loadRstByReg", "SELECT ref, refBrlyMRegion, startd, startt FROM TblBrlyAMRegionDstswitch WHERE refBrlyMRegion = $1 ORDER BY startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyAMRegionDstswitch::loadRec(
			PGresult* res
			, BrlyAMRegionDstswitch** rec
		) {
	char* ptr;

	BrlyAMRegionDstswitch* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAMRegionDstswitch();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMRegion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->startt = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAMRegionDstswitch::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAMRegionDstswitch* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "startt")
		};

		while (numread < numrow) {
			rec = new BrlyAMRegionDstswitch();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMRegion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->startt = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAMRegionDstswitch::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAMRegionDstswitch** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMRegionDstswitch / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMRegionDstswitch::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMRegionDstswitch / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyAMRegionDstswitch::loadRecBySQL(
			const string& sqlstr
			, BrlyAMRegionDstswitch** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAMRegionDstswitch::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyAMRegionDstswitch::insertRec(
			BrlyAMRegionDstswitch* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_startd,
		(char*) &_startt
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMRegionDstswitch_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMRegionDstswitch_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyAMRegionDstswitch::insertRst(
			ListBrlyAMRegionDstswitch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAMRegionDstswitch::updateRec(
			BrlyAMRegionDstswitch* rec
		) {
	PGresult* res;

	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	uint _startd = htonl(rec->startd);
	uint _startt = htonl(rec->startt);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_startd,
		(char*) &_startt,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyAMRegionDstswitch_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMRegionDstswitch_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyAMRegionDstswitch::updateRst(
			ListBrlyAMRegionDstswitch& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAMRegionDstswitch::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAMRegionDstswitch_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAMRegionDstswitch_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyAMRegionDstswitch::loadRecByRef(
			ubigint ref
			, BrlyAMRegionDstswitch** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyAMRegionDstswitch_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyAMRegionDstswitch::loadRefsByReg(
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

	return loadRefsByStmt("TblBrlyAMRegionDstswitch_loadRefsByReg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyAMRegionDstswitch::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyAMRegionDstswitch& rst
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);

	const char* vals[] = {
		(char*) &_refBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyAMRegionDstswitch_loadRstByReg", 1, vals, l, f, append, rst);
};

