/**
  * \file BrlyRMUsergroupUniversal.cpp
  * database access for table TblBrlyRMUsergroupUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMUsergroupUniversal.h"

/******************************************************************************
 class BrlyRMUsergroupUniversal
 ******************************************************************************/

BrlyRMUsergroupUniversal::BrlyRMUsergroupUniversal(
			const ubigint ref
			, const ubigint refBrlyMUsergroup
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVAccess
		) {

	this->ref = ref;
	this->refBrlyMUsergroup = refBrlyMUsergroup;
	this->unvIxBrlyVMaintable = unvIxBrlyVMaintable;
	this->unvUref = unvUref;
	this->ixBrlyVAccess = ixBrlyVAccess;
};

bool BrlyRMUsergroupUniversal::operator==(
			const BrlyRMUsergroupUniversal& comp
		) {
	return false;
};

bool BrlyRMUsergroupUniversal::operator!=(
			const BrlyRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMUsergroupUniversal
 ******************************************************************************/

ListBrlyRMUsergroupUniversal::ListBrlyRMUsergroupUniversal() {
};

ListBrlyRMUsergroupUniversal::ListBrlyRMUsergroupUniversal(
			const ListBrlyRMUsergroupUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMUsergroupUniversal(*(src.nodes[i]));
};

ListBrlyRMUsergroupUniversal::~ListBrlyRMUsergroupUniversal() {
	clear();
};

void ListBrlyRMUsergroupUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMUsergroupUniversal::size() const {
	return(nodes.size());
};

void ListBrlyRMUsergroupUniversal::append(
			BrlyRMUsergroupUniversal* rec
		) {
	nodes.push_back(rec);
};

BrlyRMUsergroupUniversal* ListBrlyRMUsergroupUniversal::operator[](
			const uint ix
		) {
	BrlyRMUsergroupUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMUsergroupUniversal& ListBrlyRMUsergroupUniversal::operator=(
			const ListBrlyRMUsergroupUniversal& src
		) {
	BrlyRMUsergroupUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMUsergroupUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMUsergroupUniversal::operator==(
			const ListBrlyRMUsergroupUniversal& comp
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

bool ListBrlyRMUsergroupUniversal::operator!=(
			const ListBrlyRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMUsergroupUniversal
 ******************************************************************************/

TblBrlyRMUsergroupUniversal::TblBrlyRMUsergroupUniversal() {
};

TblBrlyRMUsergroupUniversal::~TblBrlyRMUsergroupUniversal() {
};

bool TblBrlyRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblBrlyRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMUsergroupUniversal& rst
		) {
	return 0;
};

void TblBrlyRMUsergroupUniversal::insertRec(
			BrlyRMUsergroupUniversal* rec
		) {
};

ubigint TblBrlyRMUsergroupUniversal::insertNewRec(
			BrlyRMUsergroupUniversal** rec
			, const ubigint refBrlyMUsergroup
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVAccess
		) {
	ubigint retval = 0;
	BrlyRMUsergroupUniversal* _rec = NULL;

	_rec = new BrlyRMUsergroupUniversal(0, refBrlyMUsergroup, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMUsergroupUniversal::appendNewRecToRst(
			ListBrlyRMUsergroupUniversal& rst
			, BrlyRMUsergroupUniversal** rec
			, const ubigint refBrlyMUsergroup
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVAccess
		) {
	ubigint retval = 0;
	BrlyRMUsergroupUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUsergroup, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMUsergroupUniversal::insertRst(
			ListBrlyRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblBrlyRMUsergroupUniversal::updateRec(
			BrlyRMUsergroupUniversal* rec
		) {
};

void TblBrlyRMUsergroupUniversal::updateRst(
			ListBrlyRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblBrlyRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, BrlyRMUsergroupUniversal** rec
		) {
	return false;
};

bool TblBrlyRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refBrlyMUsergroup
			, uint unvIxBrlyVMaintable
			, ubigint unvUref
			, BrlyRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblBrlyRMUsergroupUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMUsergroupUniversal& rst
		) {
	ubigint numload = 0;
	BrlyRMUsergroupUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMUsergroupUniversal
 ******************************************************************************/

MyTblBrlyRMUsergroupUniversal::MyTblBrlyRMUsergroupUniversal() : TblBrlyRMUsergroupUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMUsergroupUniversal::~MyTblBrlyRMUsergroupUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMUsergroupUniversal (refBrlyMUsergroup, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMUsergroupUniversal SET refBrlyMUsergroup = ?, unvIxBrlyVMaintable = ?, unvUref = ?, ixBrlyVAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMUsergroupUniversal WHERE ref = ?", false);
};

bool MyTblBrlyRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyRMUsergroupUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMUsergroupUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMUsergroupUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMUsergroupUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUsergroup = atoll((char*) dbrow[1]); else _rec->refBrlyMUsergroup = 0;
		if (dbrow[2]) _rec->unvIxBrlyVMaintable = atol((char*) dbrow[2]); else _rec->unvIxBrlyVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixBrlyVAccess = atol((char*) dbrow[4]); else _rec->ixBrlyVAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMUsergroupUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMUsergroupUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMUsergroupUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUsergroup = atoll((char*) dbrow[1]); else rec->refBrlyMUsergroup = 0;
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

void MyTblBrlyRMUsergroupUniversal::insertRec(
			BrlyRMUsergroupUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxBrlyVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyVAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMUsergroupUniversal / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMUsergroupUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMUsergroupUniversal::insertRst(
			ListBrlyRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMUsergroupUniversal::updateRec(
			BrlyRMUsergroupUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxBrlyVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyVAccess,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMUsergroupUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMUsergroupUniversal / stmtUpdateRec)\n");
};

void MyTblBrlyRMUsergroupUniversal::updateRst(
			ListBrlyRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMUsergroupUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMUsergroupUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, BrlyRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMUsergroupUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refBrlyMUsergroup
			, uint unvIxBrlyVMaintable
			, ubigint unvUref
			, BrlyRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refBrlyMUsergroup, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess FROM TblBrlyRMUsergroupUniversal WHERE refBrlyMUsergroup = " + to_string(refBrlyMUsergroup) + " AND unvIxBrlyVMaintable = " + to_string(unvIxBrlyVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

/******************************************************************************
 class PgTblBrlyRMUsergroupUniversal
 ******************************************************************************/

PgTblBrlyRMUsergroupUniversal::PgTblBrlyRMUsergroupUniversal() : TblBrlyRMUsergroupUniversal(), PgTable() {
};

PgTblBrlyRMUsergroupUniversal::~PgTblBrlyRMUsergroupUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMUsergroupUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMUsergroupUniversal_insertRec", "INSERT INTO TblBrlyRMUsergroupUniversal (refBrlyMUsergroup, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMUsergroupUniversal_updateRec", "UPDATE TblBrlyRMUsergroupUniversal SET refBrlyMUsergroup = $1, unvIxBrlyVMaintable = $2, unvUref = $3, ixBrlyVAccess = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMUsergroupUniversal_removeRecByRef", "DELETE FROM TblBrlyRMUsergroupUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMUsergroupUniversal_loadRecByRef", "SELECT ref, refBrlyMUsergroup, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess FROM TblBrlyRMUsergroupUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMUsergroupUniversal_loadRecByUsgMtbUnv", "SELECT ref, refBrlyMUsergroup, unvIxBrlyVMaintable, unvUref, ixBrlyVAccess FROM TblBrlyRMUsergroupUniversal WHERE refBrlyMUsergroup = $1 AND unvIxBrlyVMaintable = $2 AND unvUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMUsergroupUniversal::loadRec(
			PGresult* res
			, BrlyRMUsergroupUniversal** rec
		) {
	char* ptr;

	BrlyRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMUsergroupUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "unvixbrlyvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixbrlyvaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxBrlyVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixBrlyVAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMUsergroupUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMUsergroupUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "unvixbrlyvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixbrlyvaccess")
		};

		while (numread < numrow) {
			rec = new BrlyRMUsergroupUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUsergroup = atoll(ptr);
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

bool PgTblBrlyRMUsergroupUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUsergroupUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMUsergroupUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMUsergroupUniversal::insertRec(
			BrlyRMUsergroupUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _unvIxBrlyVMaintable = htonl(rec->unvIxBrlyVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixBrlyVAccess = htonl(rec->ixBrlyVAccess);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup,
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

	res = PQexecPrepared(dbs, "TblBrlyRMUsergroupUniversal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUsergroupUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMUsergroupUniversal::insertRst(
			ListBrlyRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMUsergroupUniversal::updateRec(
			BrlyRMUsergroupUniversal* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _unvIxBrlyVMaintable = htonl(rec->unvIxBrlyVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixBrlyVAccess = htonl(rec->ixBrlyVAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup,
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

	res = PQexecPrepared(dbs, "TblBrlyRMUsergroupUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUsergroupUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMUsergroupUniversal::updateRst(
			ListBrlyRMUsergroupUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMUsergroupUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMUsergroupUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMUsergroupUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, BrlyRMUsergroupUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMUsergroupUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refBrlyMUsergroup
			, uint unvIxBrlyVMaintable
			, ubigint unvUref
			, BrlyRMUsergroupUniversal** rec
		) {
	ubigint _refBrlyMUsergroup = htonl64(refBrlyMUsergroup);
	uint _unvIxBrlyVMaintable = htonl(unvIxBrlyVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refBrlyMUsergroup,
		(char*) &_unvIxBrlyVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblBrlyRMUsergroupUniversal_loadRecByUsgMtbUnv", 3, vals, l, f, rec);
};

