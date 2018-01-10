/**
  * \file BrlyJMRegion.cpp
  * database access for table TblBrlyJMRegion (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyJMRegion.h"

/******************************************************************************
 class BrlyJMRegion
 ******************************************************************************/

BrlyJMRegion::BrlyJMRegion(
			const ubigint ref
			, const ubigint refBrlyMRegion
			, const uint x1Startd
			, const uint x1Stopd
			, const uint ixVDst
			, const double toffset
		) {

	this->ref = ref;
	this->refBrlyMRegion = refBrlyMRegion;
	this->x1Startd = x1Startd;
	this->x1Stopd = x1Stopd;
	this->ixVDst = ixVDst;
	this->toffset = toffset;
};

bool BrlyJMRegion::operator==(
			const BrlyJMRegion& comp
		) {
	return false;
};

bool BrlyJMRegion::operator!=(
			const BrlyJMRegion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyJMRegion
 ******************************************************************************/

ListBrlyJMRegion::ListBrlyJMRegion() {
};

ListBrlyJMRegion::ListBrlyJMRegion(
			const ListBrlyJMRegion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyJMRegion(*(src.nodes[i]));
};

ListBrlyJMRegion::~ListBrlyJMRegion() {
	clear();
};

void ListBrlyJMRegion::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyJMRegion::size() const {
	return(nodes.size());
};

void ListBrlyJMRegion::append(
			BrlyJMRegion* rec
		) {
	nodes.push_back(rec);
};

BrlyJMRegion* ListBrlyJMRegion::operator[](
			const uint ix
		) {
	BrlyJMRegion* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyJMRegion& ListBrlyJMRegion::operator=(
			const ListBrlyJMRegion& src
		) {
	BrlyJMRegion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyJMRegion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyJMRegion::operator==(
			const ListBrlyJMRegion& comp
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

bool ListBrlyJMRegion::operator!=(
			const ListBrlyJMRegion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyJMRegion
 ******************************************************************************/

TblBrlyJMRegion::TblBrlyJMRegion() {
};

TblBrlyJMRegion::~TblBrlyJMRegion() {
};

bool TblBrlyJMRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegion** rec
		) {
	return false;
};

ubigint TblBrlyJMRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	return 0;
};

void TblBrlyJMRegion::insertRec(
			BrlyJMRegion* rec
		) {
};

ubigint TblBrlyJMRegion::insertNewRec(
			BrlyJMRegion** rec
			, const ubigint refBrlyMRegion
			, const uint x1Startd
			, const uint x1Stopd
			, const uint ixVDst
			, const double toffset
		) {
	ubigint retval = 0;
	BrlyJMRegion* _rec = NULL;

	_rec = new BrlyJMRegion(0, refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyJMRegion::appendNewRecToRst(
			ListBrlyJMRegion& rst
			, BrlyJMRegion** rec
			, const ubigint refBrlyMRegion
			, const uint x1Startd
			, const uint x1Stopd
			, const uint ixVDst
			, const double toffset
		) {
	ubigint retval = 0;
	BrlyJMRegion* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyJMRegion::insertRst(
			ListBrlyJMRegion& rst
			, bool transact
		) {
};

void TblBrlyJMRegion::updateRec(
			BrlyJMRegion* rec
		) {
};

void TblBrlyJMRegion::updateRst(
			ListBrlyJMRegion& rst
			, bool transact
		) {
};

void TblBrlyJMRegion::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyJMRegion::loadRecByRef(
			ubigint ref
			, BrlyJMRegion** rec
		) {
	return false;
};

bool TblBrlyJMRegion::loadRecByRegStaSto(
			ubigint refBrlyMRegion
			, uint x1Startd
			, uint x1Stopd
			, BrlyJMRegion** rec
		) {
	return false;
};

ubigint TblBrlyJMRegion::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyJMRegion::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	return 0;
};

ubigint TblBrlyJMRegion::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	ubigint numload = 0;
	BrlyJMRegion* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyJMRegion
 ******************************************************************************/

MyTblBrlyJMRegion::MyTblBrlyJMRegion() : TblBrlyJMRegion(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyJMRegion::~MyTblBrlyJMRegion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyJMRegion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyJMRegion (refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyJMRegion SET refBrlyMRegion = ?, x1Startd = ?, x1Stopd = ?, ixVDst = ?, toffset = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyJMRegion WHERE ref = ?", false);
};

bool MyTblBrlyJMRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyJMRegion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyJMRegion / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyJMRegion();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMRegion = atoll((char*) dbrow[1]); else _rec->refBrlyMRegion = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->x1Stopd = atol((char*) dbrow[3]); else _rec->x1Stopd = 0;
		if (dbrow[4]) _rec->ixVDst = atol((char*) dbrow[4]); else _rec->ixVDst = 0;
		if (dbrow[5]) _rec->toffset = atof((char*) dbrow[5]); else _rec->toffset = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyJMRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyJMRegion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyJMRegion / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyJMRegion();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMRegion = atoll((char*) dbrow[1]); else rec->refBrlyMRegion = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->x1Stopd = atol((char*) dbrow[3]); else rec->x1Stopd = 0;
			if (dbrow[4]) rec->ixVDst = atol((char*) dbrow[4]); else rec->ixVDst = 0;
			if (dbrow[5]) rec->toffset = atof((char*) dbrow[5]); else rec->toffset = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyJMRegion::insertRec(
			BrlyJMRegion* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1Stopd,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVDst,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->toffset,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMRegion / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMRegion / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyJMRegion::insertRst(
			ListBrlyJMRegion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyJMRegion::updateRec(
			BrlyJMRegion* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1Stopd,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVDst,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->toffset,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMRegion / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMRegion / stmtUpdateRec)\n");
};

void MyTblBrlyJMRegion::updateRst(
			ListBrlyJMRegion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyJMRegion::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyJMRegion / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyJMRegion / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyJMRegion::loadRecByRef(
			ubigint ref
			, BrlyJMRegion** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyJMRegion WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyJMRegion::loadRecByRegStaSto(
			ubigint refBrlyMRegion
			, uint x1Startd
			, uint x1Stopd
			, BrlyJMRegion** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset FROM TblBrlyJMRegion WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " AND x1Startd <= " + to_string(x1Startd) + " AND x1Stopd >= " + to_string(x1Stopd) + "", rec);
};

ubigint MyTblBrlyJMRegion::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyJMRegion WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + "", append, refs);
};

ubigint MyTblBrlyJMRegion::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset FROM TblBrlyJMRegion WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " ORDER BY x1Startd ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyJMRegion
 ******************************************************************************/

PgTblBrlyJMRegion::PgTblBrlyJMRegion() : TblBrlyJMRegion(), PgTable() {
};

PgTblBrlyJMRegion::~PgTblBrlyJMRegion() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyJMRegion::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyJMRegion_insertRec", "INSERT INTO TblBrlyJMRegion (refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMRegion_updateRec", "UPDATE TblBrlyJMRegion SET refBrlyMRegion = $1, x1Startd = $2, x1Stopd = $3, ixVDst = $4, toffset = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMRegion_removeRecByRef", "DELETE FROM TblBrlyJMRegion WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyJMRegion_loadRecByRef", "SELECT ref, refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset FROM TblBrlyJMRegion WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyJMRegion_loadRecByRegStaSto", "SELECT ref, refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset FROM TblBrlyJMRegion WHERE refBrlyMRegion = $1 AND x1Startd <= $2 AND x1Stopd >= $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMRegion_loadRefsByReg", "SELECT ref FROM TblBrlyJMRegion WHERE refBrlyMRegion = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyJMRegion_loadRstByReg", "SELECT ref, refBrlyMRegion, x1Startd, x1Stopd, ixVDst, toffset FROM TblBrlyJMRegion WHERE refBrlyMRegion = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyJMRegion::loadRec(
			PGresult* res
			, BrlyJMRegion** rec
		) {
	char* ptr;

	BrlyJMRegion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyJMRegion();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "ixvdst"),
			PQfnumber(res, "toffset")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMRegion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1Stopd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVDst = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->toffset = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyJMRegion::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyJMRegion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "x1stopd"),
			PQfnumber(res, "ixvdst"),
			PQfnumber(res, "toffset")
		};

		while (numread < numrow) {
			rec = new BrlyJMRegion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMRegion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1Stopd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVDst = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->toffset = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyJMRegion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyJMRegion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegion / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMRegion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegion / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyJMRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyJMRegion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyJMRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyJMRegion::insertRec(
			BrlyJMRegion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	uint _ixVDst = htonl(rec->ixVDst);
	string _toffset = to_string(rec->toffset);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_ixVDst,
		_toffset.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyJMRegion_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegion_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyJMRegion::insertRst(
			ListBrlyJMRegion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyJMRegion::updateRec(
			BrlyJMRegion* rec
		) {
	PGresult* res;

	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _x1Stopd = htonl(rec->x1Stopd);
	uint _ixVDst = htonl(rec->ixVDst);
	string _toffset = to_string(rec->toffset);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1Startd,
		(char*) &_x1Stopd,
		(char*) &_ixVDst,
		_toffset.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyJMRegion_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegion_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyJMRegion::updateRst(
			ListBrlyJMRegion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyJMRegion::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyJMRegion_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyJMRegion_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyJMRegion::loadRecByRef(
			ubigint ref
			, BrlyJMRegion** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyJMRegion_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyJMRegion::loadRecByRegStaSto(
			ubigint refBrlyMRegion
			, uint x1Startd
			, uint x1Stopd
			, BrlyJMRegion** rec
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);
	uint _x1Startd = htonl(x1Startd);
	uint _x1Stopd = htonl(x1Stopd);

	const char* vals[] = {
		(char*) &_refBrlyMRegion,
		(char*) &_x1Startd,
		(char*) &_x1Stopd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblBrlyJMRegion_loadRecByRegStaSto", 3, vals, l, f, rec);
};

ubigint PgTblBrlyJMRegion::loadRefsByReg(
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

	return loadRefsByStmt("TblBrlyJMRegion_loadRefsByReg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyJMRegion::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyJMRegion& rst
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);

	const char* vals[] = {
		(char*) &_refBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyJMRegion_loadRstByReg", 1, vals, l, f, append, rst);
};

