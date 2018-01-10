/**
  * \file BrlyMRelay.cpp
  * database access for table TblBrlyMRelay (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMRelay.h"

#include "BrlyMRelay_vecs.cpp"

/******************************************************************************
 class BrlyMRelay
 ******************************************************************************/

BrlyMRelay::BrlyMRelay(
			const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const ubigint refBrlyMConnection
			, const uint ixVDir
			, const bool Connected
			, const usmallint Nhop
		) {

	this->ref = ref;
	this->x1Start = x1Start;
	this->x1Stop = x1Stop;
	this->refBrlyMConnection = refBrlyMConnection;
	this->ixVDir = ixVDir;
	this->Connected = Connected;
	this->Nhop = Nhop;
};

bool BrlyMRelay::operator==(
			const BrlyMRelay& comp
		) {
	return false;
};

bool BrlyMRelay::operator!=(
			const BrlyMRelay& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMRelay
 ******************************************************************************/

ListBrlyMRelay::ListBrlyMRelay() {
};

ListBrlyMRelay::ListBrlyMRelay(
			const ListBrlyMRelay& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMRelay(*(src.nodes[i]));
};

ListBrlyMRelay::~ListBrlyMRelay() {
	clear();
};

void ListBrlyMRelay::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMRelay::size() const {
	return(nodes.size());
};

void ListBrlyMRelay::append(
			BrlyMRelay* rec
		) {
	nodes.push_back(rec);
};

BrlyMRelay* ListBrlyMRelay::operator[](
			const uint ix
		) {
	BrlyMRelay* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMRelay& ListBrlyMRelay::operator=(
			const ListBrlyMRelay& src
		) {
	BrlyMRelay* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMRelay(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMRelay::operator==(
			const ListBrlyMRelay& comp
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

bool ListBrlyMRelay::operator!=(
			const ListBrlyMRelay& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMRelay
 ******************************************************************************/

TblBrlyMRelay::TblBrlyMRelay() {
};

TblBrlyMRelay::~TblBrlyMRelay() {
};

bool TblBrlyMRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyMRelay** rec
		) {
	return false;
};

ubigint TblBrlyMRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMRelay& rst
		) {
	return 0;
};

void TblBrlyMRelay::insertRec(
			BrlyMRelay* rec
		) {
};

ubigint TblBrlyMRelay::insertNewRec(
			BrlyMRelay** rec
			, const uint x1Start
			, const uint x1Stop
			, const ubigint refBrlyMConnection
			, const uint ixVDir
			, const bool Connected
			, const usmallint Nhop
		) {
	ubigint retval = 0;
	BrlyMRelay* _rec = NULL;

	_rec = new BrlyMRelay(0, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected, Nhop);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMRelay::appendNewRecToRst(
			ListBrlyMRelay& rst
			, BrlyMRelay** rec
			, const uint x1Start
			, const uint x1Stop
			, const ubigint refBrlyMConnection
			, const uint ixVDir
			, const bool Connected
			, const usmallint Nhop
		) {
	ubigint retval = 0;
	BrlyMRelay* _rec = NULL;

	retval = insertNewRec(&_rec, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected, Nhop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMRelay::insertRst(
			ListBrlyMRelay& rst
			, bool transact
		) {
};

void TblBrlyMRelay::updateRec(
			BrlyMRelay* rec
		) {
};

void TblBrlyMRelay::updateRst(
			ListBrlyMRelay& rst
			, bool transact
		) {
};

void TblBrlyMRelay::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMRelay::loadRecByRef(
			ubigint ref
			, BrlyMRelay** rec
		) {
	return false;
};

ubigint TblBrlyMRelay::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyMRelay& rst
		) {
	return 0;
};

ubigint TblBrlyMRelay::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMRelay& rst
		) {
	ubigint numload = 0;
	BrlyMRelay* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMRelay
 ******************************************************************************/

MyTblBrlyMRelay::MyTblBrlyMRelay() : TblBrlyMRelay(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMRelay::~MyTblBrlyMRelay() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMRelay::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMRelay (x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected, Nhop) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMRelay SET x1Start = ?, x1Stop = ?, refBrlyMConnection = ?, ixVDir = ?, Connected = ?, Nhop = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMRelay WHERE ref = ?", false);
};

bool MyTblBrlyMRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyMRelay** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMRelay* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMRelay / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyMRelay();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Start = atol((char*) dbrow[1]); else _rec->x1Start = 0;
		if (dbrow[2]) _rec->x1Stop = atol((char*) dbrow[2]); else _rec->x1Stop = 0;
		if (dbrow[3]) _rec->refBrlyMConnection = atoll((char*) dbrow[3]); else _rec->refBrlyMConnection = 0;
		if (dbrow[4]) _rec->ixVDir = atol((char*) dbrow[4]); else _rec->ixVDir = 0;
		if (dbrow[5]) _rec->Connected = (atoi((char*) dbrow[5]) != 0); else _rec->Connected = false;
		if (dbrow[6]) _rec->Nhop = atoi((char*) dbrow[6]); else _rec->Nhop = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMRelay& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMRelay* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMRelay / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyMRelay();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Start = atol((char*) dbrow[1]); else rec->x1Start = 0;
			if (dbrow[2]) rec->x1Stop = atol((char*) dbrow[2]); else rec->x1Stop = 0;
			if (dbrow[3]) rec->refBrlyMConnection = atoll((char*) dbrow[3]); else rec->refBrlyMConnection = 0;
			if (dbrow[4]) rec->ixVDir = atol((char*) dbrow[4]); else rec->ixVDir = 0;
			if (dbrow[5]) rec->Connected = (atoi((char*) dbrow[5]) != 0); else rec->Connected = false;
			if (dbrow[6]) rec->Nhop = atoi((char*) dbrow[6]); else rec->Nhop = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMRelay::insertRec(
			BrlyMRelay* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	tinyint Connected = rec->Connected;

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMConnection,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVDir,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Connected,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Nhop,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMRelay / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMRelay / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMRelay::insertRst(
			ListBrlyMRelay& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMRelay::updateRec(
			BrlyMRelay* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	tinyint Connected = rec->Connected;

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMConnection,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVDir,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Connected,&(l[4]),&(n[4]),&(e[4])),
		bindUsmallint(&rec->Nhop,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMRelay / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMRelay / stmtUpdateRec)\n");
};

void MyTblBrlyMRelay::updateRst(
			ListBrlyMRelay& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMRelay::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMRelay / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMRelay / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMRelay::loadRecByRef(
			ubigint ref
			, BrlyMRelay** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMRelay WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyMRelay::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyMRelay& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected, Nhop FROM TblBrlyMRelay WHERE refBrlyMConnection = " + to_string(refBrlyMConnection) + " ORDER BY x1Start ASC, ixVDir ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyMRelay
 ******************************************************************************/

PgTblBrlyMRelay::PgTblBrlyMRelay() : TblBrlyMRelay(), PgTable() {
};

PgTblBrlyMRelay::~PgTblBrlyMRelay() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMRelay::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMRelay_insertRec", "INSERT INTO TblBrlyMRelay (x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected, Nhop) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMRelay_updateRec", "UPDATE TblBrlyMRelay SET x1Start = $1, x1Stop = $2, refBrlyMConnection = $3, ixVDir = $4, Connected = $5, Nhop = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMRelay_removeRecByRef", "DELETE FROM TblBrlyMRelay WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMRelay_loadRecByRef", "SELECT ref, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected, Nhop FROM TblBrlyMRelay WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMRelay_loadRstByCon", "SELECT ref, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected, Nhop FROM TblBrlyMRelay WHERE refBrlyMConnection = $1 ORDER BY x1Start ASC, ixVDir ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMRelay::loadRec(
			PGresult* res
			, BrlyMRelay** rec
		) {
	char* ptr;

	BrlyMRelay* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMRelay();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "connected"),
			PQfnumber(res, "nhop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refBrlyMConnection = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVDir = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Connected = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Nhop = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMRelay::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMRelay& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMRelay* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "connected"),
			PQfnumber(res, "nhop")
		};

		while (numread < numrow) {
			rec = new BrlyMRelay();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refBrlyMConnection = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVDir = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Connected = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Nhop = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMRelay::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMRelay** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRelay / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMRelay::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMRelay& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRelay / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyMRelay** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMRelay& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMRelay::insertRec(
			BrlyMRelay* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	uint _ixVDir = htonl(rec->ixVDir);
	smallint _Connected = htons((smallint) rec->Connected);
	usmallint _Nhop = htons(rec->Nhop);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		(char*) &_refBrlyMConnection,
		(char*) &_ixVDir,
		(char*) &_Connected,
		(char*) &_Nhop
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMRelay_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRelay_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMRelay::insertRst(
			ListBrlyMRelay& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMRelay::updateRec(
			BrlyMRelay* rec
		) {
	PGresult* res;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	uint _ixVDir = htonl(rec->ixVDir);
	smallint _Connected = htons((smallint) rec->Connected);
	usmallint _Nhop = htons(rec->Nhop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		(char*) &_refBrlyMConnection,
		(char*) &_ixVDir,
		(char*) &_Connected,
		(char*) &_Nhop,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMRelay_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRelay_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMRelay::updateRst(
			ListBrlyMRelay& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMRelay::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMRelay_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRelay_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMRelay::loadRecByRef(
			ubigint ref
			, BrlyMRelay** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMRelay_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyMRelay::loadRstByCon(
			ubigint refBrlyMConnection
			, const bool append
			, ListBrlyMRelay& rst
		) {
	ubigint _refBrlyMConnection = htonl64(refBrlyMConnection);

	const char* vals[] = {
		(char*) &_refBrlyMConnection
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMRelay_loadRstByCon", 1, vals, l, f, append, rst);
};

