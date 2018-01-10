/**
  * \file BrlyMEquipment.cpp
  * database access for table TblBrlyMEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMEquipment.h"

#include "BrlyMEquipment_vecs.cpp"

/******************************************************************************
 class BrlyMEquipment
 ******************************************************************************/

BrlyMEquipment::BrlyMEquipment(
			const ubigint ref
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refBrlyMOperator
			, const ubigint refBrlyMPlntype
			, const string srefBrlyKEqptype
			, const bool Fiber
		) {

	this->ref = ref;
	this->hkIxVTbl = hkIxVTbl;
	this->hkUref = hkUref;
	this->refBrlyMOperator = refBrlyMOperator;
	this->refBrlyMPlntype = refBrlyMPlntype;
	this->srefBrlyKEqptype = srefBrlyKEqptype;
	this->Fiber = Fiber;
};

bool BrlyMEquipment::operator==(
			const BrlyMEquipment& comp
		) {
	return false;
};

bool BrlyMEquipment::operator!=(
			const BrlyMEquipment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMEquipment
 ******************************************************************************/

ListBrlyMEquipment::ListBrlyMEquipment() {
};

ListBrlyMEquipment::ListBrlyMEquipment(
			const ListBrlyMEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMEquipment(*(src.nodes[i]));
};

ListBrlyMEquipment::~ListBrlyMEquipment() {
	clear();
};

void ListBrlyMEquipment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMEquipment::size() const {
	return(nodes.size());
};

void ListBrlyMEquipment::append(
			BrlyMEquipment* rec
		) {
	nodes.push_back(rec);
};

BrlyMEquipment* ListBrlyMEquipment::operator[](
			const uint ix
		) {
	BrlyMEquipment* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMEquipment& ListBrlyMEquipment::operator=(
			const ListBrlyMEquipment& src
		) {
	BrlyMEquipment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMEquipment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMEquipment::operator==(
			const ListBrlyMEquipment& comp
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

bool ListBrlyMEquipment::operator!=(
			const ListBrlyMEquipment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMEquipment
 ******************************************************************************/

TblBrlyMEquipment::TblBrlyMEquipment() {
};

TblBrlyMEquipment::~TblBrlyMEquipment() {
};

bool TblBrlyMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyMEquipment** rec
		) {
	return false;
};

ubigint TblBrlyMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMEquipment& rst
		) {
	return 0;
};

void TblBrlyMEquipment::insertRec(
			BrlyMEquipment* rec
		) {
};

ubigint TblBrlyMEquipment::insertNewRec(
			BrlyMEquipment** rec
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refBrlyMOperator
			, const ubigint refBrlyMPlntype
			, const string srefBrlyKEqptype
			, const bool Fiber
		) {
	ubigint retval = 0;
	BrlyMEquipment* _rec = NULL;

	_rec = new BrlyMEquipment(0, hkIxVTbl, hkUref, refBrlyMOperator, refBrlyMPlntype, srefBrlyKEqptype, Fiber);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMEquipment::appendNewRecToRst(
			ListBrlyMEquipment& rst
			, BrlyMEquipment** rec
			, const uint hkIxVTbl
			, const ubigint hkUref
			, const ubigint refBrlyMOperator
			, const ubigint refBrlyMPlntype
			, const string srefBrlyKEqptype
			, const bool Fiber
		) {
	ubigint retval = 0;
	BrlyMEquipment* _rec = NULL;

	retval = insertNewRec(&_rec, hkIxVTbl, hkUref, refBrlyMOperator, refBrlyMPlntype, srefBrlyKEqptype, Fiber);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMEquipment::insertRst(
			ListBrlyMEquipment& rst
			, bool transact
		) {
};

void TblBrlyMEquipment::updateRec(
			BrlyMEquipment* rec
		) {
};

void TblBrlyMEquipment::updateRst(
			ListBrlyMEquipment& rst
			, bool transact
		) {
};

void TblBrlyMEquipment::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMEquipment::loadRecByRef(
			ubigint ref
			, BrlyMEquipment** rec
		) {
	return false;
};

bool TblBrlyMEquipment::loadRecByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, BrlyMEquipment** rec
		) {
	return false;
};

ubigint TblBrlyMEquipment::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMEquipment& rst
		) {
	ubigint numload = 0;
	BrlyMEquipment* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMEquipment
 ******************************************************************************/

MyTblBrlyMEquipment::MyTblBrlyMEquipment() : TblBrlyMEquipment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMEquipment::~MyTblBrlyMEquipment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMEquipment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMEquipment (hkIxVTbl, hkUref, refBrlyMOperator, refBrlyMPlntype, srefBrlyKEqptype, Fiber) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMEquipment SET hkIxVTbl = ?, hkUref = ?, refBrlyMOperator = ?, refBrlyMPlntype = ?, srefBrlyKEqptype = ?, Fiber = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMEquipment WHERE ref = ?", false);
};

bool MyTblBrlyMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyMEquipment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMEquipment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMEquipment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMEquipment();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->hkIxVTbl = atol((char*) dbrow[1]); else _rec->hkIxVTbl = 0;
		if (dbrow[2]) _rec->hkUref = atoll((char*) dbrow[2]); else _rec->hkUref = 0;
		if (dbrow[3]) _rec->refBrlyMOperator = atoll((char*) dbrow[3]); else _rec->refBrlyMOperator = 0;
		if (dbrow[4]) _rec->refBrlyMPlntype = atoll((char*) dbrow[4]); else _rec->refBrlyMPlntype = 0;
		if (dbrow[5]) _rec->srefBrlyKEqptype.assign(dbrow[5], dblengths[5]); else _rec->srefBrlyKEqptype = "";
		if (dbrow[6]) _rec->Fiber = (atoi((char*) dbrow[6]) != 0); else _rec->Fiber = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMEquipment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMEquipment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMEquipment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMEquipment();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->hkIxVTbl = atol((char*) dbrow[1]); else rec->hkIxVTbl = 0;
			if (dbrow[2]) rec->hkUref = atoll((char*) dbrow[2]); else rec->hkUref = 0;
			if (dbrow[3]) rec->refBrlyMOperator = atoll((char*) dbrow[3]); else rec->refBrlyMOperator = 0;
			if (dbrow[4]) rec->refBrlyMPlntype = atoll((char*) dbrow[4]); else rec->refBrlyMPlntype = 0;
			if (dbrow[5]) rec->srefBrlyKEqptype.assign(dbrow[5], dblengths[5]); else rec->srefBrlyKEqptype = "";
			if (dbrow[6]) rec->Fiber = (atoi((char*) dbrow[6]) != 0); else rec->Fiber = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMEquipment::insertRec(
			BrlyMEquipment* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->srefBrlyKEqptype.length();
	tinyint Fiber = rec->Fiber;

	MYSQL_BIND bind[] = {
		bindUint(&rec->hkIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->hkUref,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMOperator,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMPlntype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefBrlyKEqptype.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Fiber,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMEquipment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMEquipment / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMEquipment::insertRst(
			ListBrlyMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMEquipment::updateRec(
			BrlyMEquipment* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->srefBrlyKEqptype.length();
	tinyint Fiber = rec->Fiber;

	MYSQL_BIND bind[] = {
		bindUint(&rec->hkIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->hkUref,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMOperator,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMPlntype,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefBrlyKEqptype.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindTinyint(&Fiber,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMEquipment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMEquipment / stmtUpdateRec)\n");
};

void MyTblBrlyMEquipment::updateRst(
			ListBrlyMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMEquipment::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMEquipment / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMEquipment / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMEquipment::loadRecByRef(
			ubigint ref
			, BrlyMEquipment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMEquipment WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMEquipment::loadRecByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, BrlyMEquipment** rec
		) {
	return loadRecBySQL("SELECT ref, hkIxVTbl, hkUref, refBrlyMOperator, refBrlyMPlntype, srefBrlyKEqptype, Fiber FROM TblBrlyMEquipment WHERE hkIxVTbl = " + to_string(hkIxVTbl) + " AND hkUref = " + to_string(hkUref) + "", rec);
};

/******************************************************************************
 class PgTblBrlyMEquipment
 ******************************************************************************/

PgTblBrlyMEquipment::PgTblBrlyMEquipment() : TblBrlyMEquipment(), PgTable() {
};

PgTblBrlyMEquipment::~PgTblBrlyMEquipment() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMEquipment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMEquipment_insertRec", "INSERT INTO TblBrlyMEquipment (hkIxVTbl, hkUref, refBrlyMOperator, refBrlyMPlntype, srefBrlyKEqptype, Fiber) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMEquipment_updateRec", "UPDATE TblBrlyMEquipment SET hkIxVTbl = $1, hkUref = $2, refBrlyMOperator = $3, refBrlyMPlntype = $4, srefBrlyKEqptype = $5, Fiber = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMEquipment_removeRecByRef", "DELETE FROM TblBrlyMEquipment WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMEquipment_loadRecByRef", "SELECT ref, hkIxVTbl, hkUref, refBrlyMOperator, refBrlyMPlntype, srefBrlyKEqptype, Fiber FROM TblBrlyMEquipment WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMEquipment_loadRecByHktHku", "SELECT ref, hkIxVTbl, hkUref, refBrlyMOperator, refBrlyMPlntype, srefBrlyKEqptype, Fiber FROM TblBrlyMEquipment WHERE hkIxVTbl = $1 AND hkUref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMEquipment::loadRec(
			PGresult* res
			, BrlyMEquipment** rec
		) {
	char* ptr;

	BrlyMEquipment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMEquipment();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refbrlymoperator"),
			PQfnumber(res, "refbrlymplntype"),
			PQfnumber(res, "srefbrlykeqptype"),
			PQfnumber(res, "fiber")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->hkIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->hkUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refBrlyMOperator = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refBrlyMPlntype = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefBrlyKEqptype.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Fiber = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMEquipment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMEquipment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMEquipment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "hkixvtbl"),
			PQfnumber(res, "hkuref"),
			PQfnumber(res, "refbrlymoperator"),
			PQfnumber(res, "refbrlymplntype"),
			PQfnumber(res, "srefbrlykeqptype"),
			PQfnumber(res, "fiber")
		};

		while (numread < numrow) {
			rec = new BrlyMEquipment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->hkIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->hkUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refBrlyMOperator = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refBrlyMPlntype = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefBrlyKEqptype.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Fiber = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMEquipment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMEquipment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMEquipment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyMEquipment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMEquipment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMEquipment::insertRec(
			BrlyMEquipment* rec
		) {
	PGresult* res;
	char* ptr;

	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refBrlyMOperator = htonl64(rec->refBrlyMOperator);
	ubigint _refBrlyMPlntype = htonl64(rec->refBrlyMPlntype);
	smallint _Fiber = htons((smallint) rec->Fiber);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refBrlyMOperator,
		(char*) &_refBrlyMPlntype,
		rec->srefBrlyKEqptype.c_str(),
		(char*) &_Fiber
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMEquipment_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMEquipment_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMEquipment::insertRst(
			ListBrlyMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMEquipment::updateRec(
			BrlyMEquipment* rec
		) {
	PGresult* res;

	uint _hkIxVTbl = htonl(rec->hkIxVTbl);
	ubigint _hkUref = htonl64(rec->hkUref);
	ubigint _refBrlyMOperator = htonl64(rec->refBrlyMOperator);
	ubigint _refBrlyMPlntype = htonl64(rec->refBrlyMPlntype);
	smallint _Fiber = htons((smallint) rec->Fiber);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref,
		(char*) &_refBrlyMOperator,
		(char*) &_refBrlyMPlntype,
		rec->srefBrlyKEqptype.c_str(),
		(char*) &_Fiber,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMEquipment_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMEquipment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMEquipment::updateRst(
			ListBrlyMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMEquipment::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMEquipment_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMEquipment_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMEquipment::loadRecByRef(
			ubigint ref
			, BrlyMEquipment** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMEquipment_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMEquipment::loadRecByHktHku(
			uint hkIxVTbl
			, ubigint hkUref
			, BrlyMEquipment** rec
		) {
	uint _hkIxVTbl = htonl(hkIxVTbl);
	ubigint _hkUref = htonl64(hkUref);

	const char* vals[] = {
		(char*) &_hkIxVTbl,
		(char*) &_hkUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblBrlyMEquipment_loadRecByHktHku", 2, vals, l, f, rec);
};

