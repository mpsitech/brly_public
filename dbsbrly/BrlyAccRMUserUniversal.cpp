/**
  * \file BrlyAccRMUserUniversal.cpp
  * database access for table TblBrlyAccRMUserUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyAccRMUserUniversal.h"

/******************************************************************************
 class BrlyAccRMUserUniversal
 ******************************************************************************/

BrlyAccRMUserUniversal::BrlyAccRMUserUniversal(
			const ubigint ref
			, const ubigint refBrlyMUser
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVAccess
		) {

	this->ref = ref;
	this->refBrlyMUser = refBrlyMUser;
	this->unvIxBrlyVMaintable = unvIxBrlyVMaintable;
	this->unvUref = unvUref;
	this->ixBrlyVAccess = ixBrlyVAccess;
};

bool BrlyAccRMUserUniversal::operator==(
			const BrlyAccRMUserUniversal& comp
		) {
	return false;
};

bool BrlyAccRMUserUniversal::operator!=(
			const BrlyAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAccRMUserUniversal
 ******************************************************************************/

ListBrlyAccRMUserUniversal::ListBrlyAccRMUserUniversal() {
};

ListBrlyAccRMUserUniversal::ListBrlyAccRMUserUniversal(
			const ListBrlyAccRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyAccRMUserUniversal(*(src.nodes[i]));
};

ListBrlyAccRMUserUniversal::~ListBrlyAccRMUserUniversal() {
	clear();
};

void ListBrlyAccRMUserUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAccRMUserUniversal::size() const {
	return(nodes.size());
};

void ListBrlyAccRMUserUniversal::append(
			BrlyAccRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

BrlyAccRMUserUniversal* ListBrlyAccRMUserUniversal::operator[](
			const uint ix
		) {
	BrlyAccRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAccRMUserUniversal& ListBrlyAccRMUserUniversal::operator=(
			const ListBrlyAccRMUserUniversal& src
		) {
	BrlyAccRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyAccRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAccRMUserUniversal::operator==(
			const ListBrlyAccRMUserUniversal& comp
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

bool ListBrlyAccRMUserUniversal::operator!=(
			const ListBrlyAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAccRMUserUniversal
 ******************************************************************************/

TblBrlyAccRMUserUniversal::TblBrlyAccRMUserUniversal() {
};

TblBrlyAccRMUserUniversal::~TblBrlyAccRMUserUniversal() {
};

bool TblBrlyAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblBrlyAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAccRMUserUniversal& rst
		) {
	return 0;
};

void TblBrlyAccRMUserUniversal::insertRec(
			BrlyAccRMUserUniversal* rec
		) {
};

ubigint TblBrlyAccRMUserUniversal::insertNewRec(
			BrlyAccRMUserUniversal** rec
			, const ubigint refBrlyMUser
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVAccess
		) {
	ubigint retval = 0;
	BrlyAccRMUserUniversal* _rec = NULL;

	_rec = new BrlyAccRMUserUniversal(0, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAccRMUserUniversal::appendNewRecToRst(
			ListBrlyAccRMUserUniversal& rst
			, BrlyAccRMUserUniversal** rec
			, const ubigint refBrlyMUser
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVAccess
		) {
	ubigint retval = 0;
	BrlyAccRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAccRMUserUniversal::insertRst(
			ListBrlyAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblBrlyAccRMUserUniversal::updateRec(
			BrlyAccRMUserUniversal* rec
		) {
};

void TblBrlyAccRMUserUniversal::updateRst(
			ListBrlyAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblBrlyAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, BrlyAccRMUserUniversal** rec
		) {
	return false;
};

bool TblBrlyAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refBrlyMUser
			, uint unvIxBrlyVMaintable
			, ubigint unvUref
			, BrlyAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblBrlyAccRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAccRMUserUniversal& rst
		) {
	ubigint numload = 0;
	BrlyAccRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyAccRMUserUniversal
 ******************************************************************************/

MyTblBrlyAccRMUserUniversal::MyTblBrlyAccRMUserUniversal() : TblBrlyAccRMUserUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAccRMUserUniversal::~MyTblBrlyAccRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAccRMUserUniversal (refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAccRMUserUniversal SET refBrlyMUser = ?, unvIxBrlyVMaintable = ?, unvUref = ?, ixBrlyVAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAccRMUserUniversal WHERE ref = ?", false);
};

bool MyTblBrlyAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyAccRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAccRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAccRMUserUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyAccRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUser = atoll((char*) dbrow[1]); else _rec->refBrlyMUser = 0;
		if (dbrow[2]) _rec->unvIxBrlyVMaintable = atol((char*) dbrow[2]); else _rec->unvIxBrlyVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixBrlyVAccess = atol((char*) dbrow[4]); else _rec->ixBrlyVAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAccRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAccRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAccRMUserUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyAccRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUser = atoll((char*) dbrow[1]); else rec->refBrlyMUser = 0;
			if (dbrow[2]) rec->unvIxBrlyVMaintable = atol((char*) dbrow[2]); else rec->unvIxBrlyVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixBrlyVAccess = atol((char*) dbrow[4]); else rec->ixBrlyVAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyAccRMUserUniversal::insertRec(
			BrlyAccRMUserUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxBrlyVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyVAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAccRMUserUniversal / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAccRMUserUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyAccRMUserUniversal::insertRst(
			ListBrlyAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAccRMUserUniversal::updateRec(
			BrlyAccRMUserUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxBrlyVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyVAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAccRMUserUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAccRMUserUniversal / stmtUpdateRec)\n");
};

void MyTblBrlyAccRMUserUniversal::updateRst(
			ListBrlyAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAccRMUserUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAccRMUserUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, BrlyAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyAccRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refBrlyMUser
			, uint unvIxBrlyVMaintable
			, ubigint unvUref
			, BrlyAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess FROM TblBrlyAccRMUserUniversal WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " AND unvIxBrlyVMaintable = " + to_string(unvIxBrlyVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

/******************************************************************************
 class PgTblBrlyAccRMUserUniversal
 ******************************************************************************/

PgTblBrlyAccRMUserUniversal::PgTblBrlyAccRMUserUniversal() : TblBrlyAccRMUserUniversal(), PgTable() {
};

PgTblBrlyAccRMUserUniversal::~PgTblBrlyAccRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAccRMUserUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyAccRMUserUniversal_insertRec", "INSERT INTO TblBrlyAccRMUserUniversal (refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAccRMUserUniversal_updateRec", "UPDATE TblBrlyAccRMUserUniversal SET refBrlyMUser = $1, unvIxBrlyVMaintable = $2, unvUref = $3, ixBrlyVAccess = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAccRMUserUniversal_removeRecByRef", "DELETE FROM TblBrlyAccRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyAccRMUserUniversal_loadRecByRef", "SELECT ref, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess FROM TblBrlyAccRMUserUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyAccRMUserUniversal_loadRecByUsrMtbUnv", "SELECT ref, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess FROM TblBrlyAccRMUserUniversal WHERE refBrlyMUser = $1 AND unvIxBrlyVMaintable = $2 AND unvUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyAccRMUserUniversal::loadRec(
			PGresult* res
			, BrlyAccRMUserUniversal** rec
		) {
	char* ptr;

	BrlyAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAccRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "unvixbrlyvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixbrlyvaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxBrlyVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixBrlyVAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAccRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAccRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAccRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "unvixbrlyvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixbrlyvaccess")
		};

		while (numread < numrow) {
			rec = new BrlyAccRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxBrlyVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixBrlyVAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAccRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAccRMUserUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAccRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyAccRMUserUniversal::insertRec(
			BrlyAccRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _unvIxBrlyVMaintable = htonl(rec->unvIxBrlyVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixBrlyVAccess = htonl(rec->ixBrlyVAccess);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_unvIxBrlyVMaintable,
		(char*) &_unvUref,
		(char*) &_ixBrlyVAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyAccRMUserUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAccRMUserUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyAccRMUserUniversal::insertRst(
			ListBrlyAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAccRMUserUniversal::updateRec(
			BrlyAccRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _unvIxBrlyVMaintable = htonl(rec->unvIxBrlyVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixBrlyVAccess = htonl(rec->ixBrlyVAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_unvIxBrlyVMaintable,
		(char*) &_unvUref,
		(char*) &_ixBrlyVAccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyAccRMUserUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAccRMUserUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyAccRMUserUniversal::updateRst(
			ListBrlyAccRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAccRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAccRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAccRMUserUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, BrlyAccRMUserUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyAccRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refBrlyMUser
			, uint unvIxBrlyVMaintable
			, ubigint unvUref
			, BrlyAccRMUserUniversal** rec
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);
	uint _unvIxBrlyVMaintable = htonl(unvIxBrlyVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_unvIxBrlyVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblBrlyAccRMUserUniversal_loadRecByUsrMtbUnv", 3, vals, l, f, rec);
};

