/**
  * \file BrlyLRMConnectionMEquipment.cpp
  * database access for table TblBrlyLRMConnectionMEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyLRMConnectionMEquipment.h"

/******************************************************************************
 class BrlyLRMConnectionMEquipment
 ******************************************************************************/

BrlyLRMConnectionMEquipment::BrlyLRMConnectionMEquipment(
			const ubigint ref
			, const uint conIxBrlyVLat
			, const ubigint conRefBrlyMConnection
			, const uint conNum
			, const ubigint refBrlyMEquipment
		) {

	this->ref = ref;
	this->conIxBrlyVLat = conIxBrlyVLat;
	this->conRefBrlyMConnection = conRefBrlyMConnection;
	this->conNum = conNum;
	this->refBrlyMEquipment = refBrlyMEquipment;
};

bool BrlyLRMConnectionMEquipment::operator==(
			const BrlyLRMConnectionMEquipment& comp
		) {
	return false;
};

bool BrlyLRMConnectionMEquipment::operator!=(
			const BrlyLRMConnectionMEquipment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyLRMConnectionMEquipment
 ******************************************************************************/

ListBrlyLRMConnectionMEquipment::ListBrlyLRMConnectionMEquipment() {
};

ListBrlyLRMConnectionMEquipment::ListBrlyLRMConnectionMEquipment(
			const ListBrlyLRMConnectionMEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyLRMConnectionMEquipment(*(src.nodes[i]));
};

ListBrlyLRMConnectionMEquipment::~ListBrlyLRMConnectionMEquipment() {
	clear();
};

void ListBrlyLRMConnectionMEquipment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyLRMConnectionMEquipment::size() const {
	return(nodes.size());
};

void ListBrlyLRMConnectionMEquipment::append(
			BrlyLRMConnectionMEquipment* rec
		) {
	nodes.push_back(rec);
};

BrlyLRMConnectionMEquipment* ListBrlyLRMConnectionMEquipment::operator[](
			const uint ix
		) {
	BrlyLRMConnectionMEquipment* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyLRMConnectionMEquipment& ListBrlyLRMConnectionMEquipment::operator=(
			const ListBrlyLRMConnectionMEquipment& src
		) {
	BrlyLRMConnectionMEquipment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyLRMConnectionMEquipment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyLRMConnectionMEquipment::operator==(
			const ListBrlyLRMConnectionMEquipment& comp
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

bool ListBrlyLRMConnectionMEquipment::operator!=(
			const ListBrlyLRMConnectionMEquipment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyLRMConnectionMEquipment
 ******************************************************************************/

TblBrlyLRMConnectionMEquipment::TblBrlyLRMConnectionMEquipment() {
};

TblBrlyLRMConnectionMEquipment::~TblBrlyLRMConnectionMEquipment() {
};

bool TblBrlyLRMConnectionMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyLRMConnectionMEquipment** rec
		) {
	return false;
};

ubigint TblBrlyLRMConnectionMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	return 0;
};

void TblBrlyLRMConnectionMEquipment::insertRec(
			BrlyLRMConnectionMEquipment* rec
		) {
};

ubigint TblBrlyLRMConnectionMEquipment::insertNewRec(
			BrlyLRMConnectionMEquipment** rec
			, const uint conIxBrlyVLat
			, const ubigint conRefBrlyMConnection
			, const uint conNum
			, const ubigint refBrlyMEquipment
		) {
	ubigint retval = 0;
	BrlyLRMConnectionMEquipment* _rec = NULL;

	_rec = new BrlyLRMConnectionMEquipment(0, conIxBrlyVLat, conRefBrlyMConnection, conNum, refBrlyMEquipment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyLRMConnectionMEquipment::appendNewRecToRst(
			ListBrlyLRMConnectionMEquipment& rst
			, BrlyLRMConnectionMEquipment** rec
			, const uint conIxBrlyVLat
			, const ubigint conRefBrlyMConnection
			, const uint conNum
			, const ubigint refBrlyMEquipment
		) {
	ubigint retval = 0;
	BrlyLRMConnectionMEquipment* _rec = NULL;

	retval = insertNewRec(&_rec, conIxBrlyVLat, conRefBrlyMConnection, conNum, refBrlyMEquipment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyLRMConnectionMEquipment::insertRst(
			ListBrlyLRMConnectionMEquipment& rst
			, bool transact
		) {
};

void TblBrlyLRMConnectionMEquipment::updateRec(
			BrlyLRMConnectionMEquipment* rec
		) {
};

void TblBrlyLRMConnectionMEquipment::updateRst(
			ListBrlyLRMConnectionMEquipment& rst
			, bool transact
		) {
};

void TblBrlyLRMConnectionMEquipment::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyLRMConnectionMEquipment::loadRecByRef(
			ubigint ref
			, BrlyLRMConnectionMEquipment** rec
		) {
	return false;
};

ubigint TblBrlyLRMConnectionMEquipment::loadConsByEqp(
			ubigint refBrlyMEquipment
			, const bool append
			, vector<ubigint>& conRefBrlyMConnections
		) {
	return 0;
};

ubigint TblBrlyLRMConnectionMEquipment::loadEqpsByCon(
			ubigint conRefBrlyMConnection
			, const bool append
			, vector<ubigint>& refBrlyMEquipments
		) {
	return 0;
};

ubigint TblBrlyLRMConnectionMEquipment::loadRefsByConLat(
			ubigint conRefBrlyMConnection
			, uint conIxBrlyVLat
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyLRMConnectionMEquipment::loadRstByCon(
			ubigint conRefBrlyMConnection
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	return 0;
};

ubigint TblBrlyLRMConnectionMEquipment::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	ubigint numload = 0;
	BrlyLRMConnectionMEquipment* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyLRMConnectionMEquipment
 ******************************************************************************/

MyTblBrlyLRMConnectionMEquipment::MyTblBrlyLRMConnectionMEquipment() : TblBrlyLRMConnectionMEquipment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyLRMConnectionMEquipment::~MyTblBrlyLRMConnectionMEquipment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyLRMConnectionMEquipment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyLRMConnectionMEquipment (conIxBrlyVLat, conRefBrlyMConnection, conNum, refBrlyMEquipment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyLRMConnectionMEquipment SET conIxBrlyVLat = ?, conRefBrlyMConnection = ?, conNum = ?, refBrlyMEquipment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyLRMConnectionMEquipment WHERE ref = ?", false);
};

bool MyTblBrlyLRMConnectionMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyLRMConnectionMEquipment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyLRMConnectionMEquipment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyLRMConnectionMEquipment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyLRMConnectionMEquipment();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->conIxBrlyVLat = atol((char*) dbrow[1]); else _rec->conIxBrlyVLat = 0;
		if (dbrow[2]) _rec->conRefBrlyMConnection = atoll((char*) dbrow[2]); else _rec->conRefBrlyMConnection = 0;
		if (dbrow[3]) _rec->conNum = atol((char*) dbrow[3]); else _rec->conNum = 0;
		if (dbrow[4]) _rec->refBrlyMEquipment = atoll((char*) dbrow[4]); else _rec->refBrlyMEquipment = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyLRMConnectionMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyLRMConnectionMEquipment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyLRMConnectionMEquipment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyLRMConnectionMEquipment();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->conIxBrlyVLat = atol((char*) dbrow[1]); else rec->conIxBrlyVLat = 0;
			if (dbrow[2]) rec->conRefBrlyMConnection = atoll((char*) dbrow[2]); else rec->conRefBrlyMConnection = 0;
			if (dbrow[3]) rec->conNum = atol((char*) dbrow[3]); else rec->conNum = 0;
			if (dbrow[4]) rec->refBrlyMEquipment = atoll((char*) dbrow[4]); else rec->refBrlyMEquipment = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyLRMConnectionMEquipment::insertRec(
			BrlyLRMConnectionMEquipment* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUint(&rec->conIxBrlyVLat,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->conRefBrlyMConnection,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->conNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyLRMConnectionMEquipment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyLRMConnectionMEquipment / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyLRMConnectionMEquipment::insertRst(
			ListBrlyLRMConnectionMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyLRMConnectionMEquipment::updateRec(
			BrlyLRMConnectionMEquipment* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUint(&rec->conIxBrlyVLat,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->conRefBrlyMConnection,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->conNum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyLRMConnectionMEquipment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyLRMConnectionMEquipment / stmtUpdateRec)\n");
};

void MyTblBrlyLRMConnectionMEquipment::updateRst(
			ListBrlyLRMConnectionMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyLRMConnectionMEquipment::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyLRMConnectionMEquipment / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyLRMConnectionMEquipment / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyLRMConnectionMEquipment::loadRecByRef(
			ubigint ref
			, BrlyLRMConnectionMEquipment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyLRMConnectionMEquipment WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyLRMConnectionMEquipment::loadConsByEqp(
			ubigint refBrlyMEquipment
			, const bool append
			, vector<ubigint>& conRefBrlyMConnections
		) {
	return loadRefsBySQL("SELECT conRefBrlyMConnection FROM TblBrlyLRMConnectionMEquipment WHERE refBrlyMEquipment = " + to_string(refBrlyMEquipment) + "", append, conRefBrlyMConnections);
};

ubigint MyTblBrlyLRMConnectionMEquipment::loadEqpsByCon(
			ubigint conRefBrlyMConnection
			, const bool append
			, vector<ubigint>& refBrlyMEquipments
		) {
	return loadRefsBySQL("SELECT refBrlyMEquipment FROM TblBrlyLRMConnectionMEquipment WHERE conRefBrlyMConnection = " + to_string(conRefBrlyMConnection) + " ORDER BY conNum ASC", append, refBrlyMEquipments);
};

ubigint MyTblBrlyLRMConnectionMEquipment::loadRefsByConLat(
			ubigint conRefBrlyMConnection
			, uint conIxBrlyVLat
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyLRMConnectionMEquipment WHERE conRefBrlyMConnection = " + to_string(conRefBrlyMConnection) + " AND conIxBrlyVLat = " + to_string(conIxBrlyVLat) + " ORDER BY conNum ASC", append, refs);
};

ubigint MyTblBrlyLRMConnectionMEquipment::loadRstByCon(
			ubigint conRefBrlyMConnection
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	return loadRstBySQL("SELECT ref, conIxBrlyVLat, conRefBrlyMConnection, conNum, refBrlyMEquipment FROM TblBrlyLRMConnectionMEquipment WHERE conRefBrlyMConnection = " + to_string(conRefBrlyMConnection) + " ORDER BY conNum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyLRMConnectionMEquipment
 ******************************************************************************/

PgTblBrlyLRMConnectionMEquipment::PgTblBrlyLRMConnectionMEquipment() : TblBrlyLRMConnectionMEquipment(), PgTable() {
};

PgTblBrlyLRMConnectionMEquipment::~PgTblBrlyLRMConnectionMEquipment() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyLRMConnectionMEquipment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyLRMConnectionMEquipment_insertRec", "INSERT INTO TblBrlyLRMConnectionMEquipment (conIxBrlyVLat, conRefBrlyMConnection, conNum, refBrlyMEquipment) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyLRMConnectionMEquipment_updateRec", "UPDATE TblBrlyLRMConnectionMEquipment SET conIxBrlyVLat = $1, conRefBrlyMConnection = $2, conNum = $3, refBrlyMEquipment = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyLRMConnectionMEquipment_removeRecByRef", "DELETE FROM TblBrlyLRMConnectionMEquipment WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyLRMConnectionMEquipment_loadRecByRef", "SELECT ref, conIxBrlyVLat, conRefBrlyMConnection, conNum, refBrlyMEquipment FROM TblBrlyLRMConnectionMEquipment WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyLRMConnectionMEquipment_loadConsByEqp", "SELECT conRefBrlyMConnection FROM TblBrlyLRMConnectionMEquipment WHERE refBrlyMEquipment = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyLRMConnectionMEquipment_loadEqpsByCon", "SELECT refBrlyMEquipment FROM TblBrlyLRMConnectionMEquipment WHERE conRefBrlyMConnection = $1 ORDER BY conNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyLRMConnectionMEquipment_loadRefsByConLat", "SELECT ref FROM TblBrlyLRMConnectionMEquipment WHERE conRefBrlyMConnection = $1 AND conIxBrlyVLat = $2 ORDER BY conNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyLRMConnectionMEquipment_loadRstByCon", "SELECT ref, conIxBrlyVLat, conRefBrlyMConnection, conNum, refBrlyMEquipment FROM TblBrlyLRMConnectionMEquipment WHERE conRefBrlyMConnection = $1 ORDER BY conNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyLRMConnectionMEquipment::loadRec(
			PGresult* res
			, BrlyLRMConnectionMEquipment** rec
		) {
	char* ptr;

	BrlyLRMConnectionMEquipment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyLRMConnectionMEquipment();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "conixbrlyvlat"),
			PQfnumber(res, "conrefbrlymconnection"),
			PQfnumber(res, "connum"),
			PQfnumber(res, "refbrlymequipment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->conIxBrlyVLat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->conRefBrlyMConnection = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->conNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refBrlyMEquipment = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyLRMConnectionMEquipment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyLRMConnectionMEquipment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "conixbrlyvlat"),
			PQfnumber(res, "conrefbrlymconnection"),
			PQfnumber(res, "connum"),
			PQfnumber(res, "refbrlymequipment")
		};

		while (numread < numrow) {
			rec = new BrlyLRMConnectionMEquipment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->conIxBrlyVLat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->conRefBrlyMConnection = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->conNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refBrlyMEquipment = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyLRMConnectionMEquipment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyLRMConnectionMEquipment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyLRMConnectionMEquipment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyLRMConnectionMEquipment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyLRMConnectionMEquipment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyLRMConnectionMEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyLRMConnectionMEquipment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyLRMConnectionMEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyLRMConnectionMEquipment::insertRec(
			BrlyLRMConnectionMEquipment* rec
		) {
	PGresult* res;
	char* ptr;

	uint _conIxBrlyVLat = htonl(rec->conIxBrlyVLat);
	ubigint _conRefBrlyMConnection = htonl64(rec->conRefBrlyMConnection);
	uint _conNum = htonl(rec->conNum);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);

	const char* vals[] = {
		(char*) &_conIxBrlyVLat,
		(char*) &_conRefBrlyMConnection,
		(char*) &_conNum,
		(char*) &_refBrlyMEquipment
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyLRMConnectionMEquipment_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyLRMConnectionMEquipment_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyLRMConnectionMEquipment::insertRst(
			ListBrlyLRMConnectionMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyLRMConnectionMEquipment::updateRec(
			BrlyLRMConnectionMEquipment* rec
		) {
	PGresult* res;

	uint _conIxBrlyVLat = htonl(rec->conIxBrlyVLat);
	ubigint _conRefBrlyMConnection = htonl64(rec->conRefBrlyMConnection);
	uint _conNum = htonl(rec->conNum);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_conIxBrlyVLat,
		(char*) &_conRefBrlyMConnection,
		(char*) &_conNum,
		(char*) &_refBrlyMEquipment,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyLRMConnectionMEquipment_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyLRMConnectionMEquipment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyLRMConnectionMEquipment::updateRst(
			ListBrlyLRMConnectionMEquipment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyLRMConnectionMEquipment::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyLRMConnectionMEquipment_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyLRMConnectionMEquipment_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyLRMConnectionMEquipment::loadRecByRef(
			ubigint ref
			, BrlyLRMConnectionMEquipment** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyLRMConnectionMEquipment_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyLRMConnectionMEquipment::loadConsByEqp(
			ubigint refBrlyMEquipment
			, const bool append
			, vector<ubigint>& conRefBrlyMConnections
		) {
	ubigint _refBrlyMEquipment = htonl64(refBrlyMEquipment);

	const char* vals[] = {
		(char*) &_refBrlyMEquipment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyLRMConnectionMEquipment_loadConsByEqp", 1, vals, l, f, append, conRefBrlyMConnections);
};

ubigint PgTblBrlyLRMConnectionMEquipment::loadEqpsByCon(
			ubigint conRefBrlyMConnection
			, const bool append
			, vector<ubigint>& refBrlyMEquipments
		) {
	ubigint _conRefBrlyMConnection = htonl64(conRefBrlyMConnection);

	const char* vals[] = {
		(char*) &_conRefBrlyMConnection
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyLRMConnectionMEquipment_loadEqpsByCon", 1, vals, l, f, append, refBrlyMEquipments);
};

ubigint PgTblBrlyLRMConnectionMEquipment::loadRefsByConLat(
			ubigint conRefBrlyMConnection
			, uint conIxBrlyVLat
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _conRefBrlyMConnection = htonl64(conRefBrlyMConnection);
	uint _conIxBrlyVLat = htonl(conIxBrlyVLat);

	const char* vals[] = {
		(char*) &_conRefBrlyMConnection,
		(char*) &_conIxBrlyVLat
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblBrlyLRMConnectionMEquipment_loadRefsByConLat", 2, vals, l, f, append, refs);
};

ubigint PgTblBrlyLRMConnectionMEquipment::loadRstByCon(
			ubigint conRefBrlyMConnection
			, const bool append
			, ListBrlyLRMConnectionMEquipment& rst
		) {
	ubigint _conRefBrlyMConnection = htonl64(conRefBrlyMConnection);

	const char* vals[] = {
		(char*) &_conRefBrlyMConnection
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyLRMConnectionMEquipment_loadRstByCon", 1, vals, l, f, append, rst);
};

