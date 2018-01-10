/**
  * \file BrlyHistRMUserUniversal.cpp
  * database access for table TblBrlyHistRMUserUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyHistRMUserUniversal.h"

/******************************************************************************
 class BrlyHistRMUserUniversal
 ******************************************************************************/

BrlyHistRMUserUniversal::BrlyHistRMUserUniversal(
			const ubigint ref
			, const ubigint refBrlyMUser
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVCard
			, const uint ixBrlyVPreset
			, const uint preIxBrlyVMaintable
			, const ubigint preUref
			, const uint start
		) {

	this->ref = ref;
	this->refBrlyMUser = refBrlyMUser;
	this->unvIxBrlyVMaintable = unvIxBrlyVMaintable;
	this->unvUref = unvUref;
	this->ixBrlyVCard = ixBrlyVCard;
	this->ixBrlyVPreset = ixBrlyVPreset;
	this->preIxBrlyVMaintable = preIxBrlyVMaintable;
	this->preUref = preUref;
	this->start = start;
};

bool BrlyHistRMUserUniversal::operator==(
			const BrlyHistRMUserUniversal& comp
		) {
	return false;
};

bool BrlyHistRMUserUniversal::operator!=(
			const BrlyHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyHistRMUserUniversal
 ******************************************************************************/

ListBrlyHistRMUserUniversal::ListBrlyHistRMUserUniversal() {
};

ListBrlyHistRMUserUniversal::ListBrlyHistRMUserUniversal(
			const ListBrlyHistRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyHistRMUserUniversal(*(src.nodes[i]));
};

ListBrlyHistRMUserUniversal::~ListBrlyHistRMUserUniversal() {
	clear();
};

void ListBrlyHistRMUserUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyHistRMUserUniversal::size() const {
	return(nodes.size());
};

void ListBrlyHistRMUserUniversal::append(
			BrlyHistRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

BrlyHistRMUserUniversal* ListBrlyHistRMUserUniversal::operator[](
			const uint ix
		) {
	BrlyHistRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyHistRMUserUniversal& ListBrlyHistRMUserUniversal::operator=(
			const ListBrlyHistRMUserUniversal& src
		) {
	BrlyHistRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyHistRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyHistRMUserUniversal::operator==(
			const ListBrlyHistRMUserUniversal& comp
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

bool ListBrlyHistRMUserUniversal::operator!=(
			const ListBrlyHistRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyHistRMUserUniversal
 ******************************************************************************/

TblBrlyHistRMUserUniversal::TblBrlyHistRMUserUniversal() {
};

TblBrlyHistRMUserUniversal::~TblBrlyHistRMUserUniversal() {
};

bool TblBrlyHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblBrlyHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	return 0;
};

void TblBrlyHistRMUserUniversal::insertRec(
			BrlyHistRMUserUniversal* rec
		) {
};

ubigint TblBrlyHistRMUserUniversal::insertNewRec(
			BrlyHistRMUserUniversal** rec
			, const ubigint refBrlyMUser
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVCard
			, const uint ixBrlyVPreset
			, const uint preIxBrlyVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	BrlyHistRMUserUniversal* _rec = NULL;

	_rec = new BrlyHistRMUserUniversal(0, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, ixBrlyVPreset, preIxBrlyVMaintable, preUref, start);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyHistRMUserUniversal::appendNewRecToRst(
			ListBrlyHistRMUserUniversal& rst
			, BrlyHistRMUserUniversal** rec
			, const ubigint refBrlyMUser
			, const uint unvIxBrlyVMaintable
			, const ubigint unvUref
			, const uint ixBrlyVCard
			, const uint ixBrlyVPreset
			, const uint preIxBrlyVMaintable
			, const ubigint preUref
			, const uint start
		) {
	ubigint retval = 0;
	BrlyHistRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, ixBrlyVPreset, preIxBrlyVMaintable, preUref, start);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyHistRMUserUniversal::insertRst(
			ListBrlyHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblBrlyHistRMUserUniversal::updateRec(
			BrlyHistRMUserUniversal* rec
		) {
};

void TblBrlyHistRMUserUniversal::updateRst(
			ListBrlyHistRMUserUniversal& rst
			, bool transact
		) {
};

void TblBrlyHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, BrlyHistRMUserUniversal** rec
		) {
	return false;
};

ubigint TblBrlyHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refBrlyMUser
			, uint ixBrlyVCard
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	return 0;
};

bool TblBrlyHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return false;
};

ubigint TblBrlyHistRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	ubigint numload = 0;
	BrlyHistRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyHistRMUserUniversal
 ******************************************************************************/

MyTblBrlyHistRMUserUniversal::MyTblBrlyHistRMUserUniversal() : TblBrlyHistRMUserUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyHistRMUserUniversal::~MyTblBrlyHistRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyHistRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyHistRMUserUniversal (refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, ixBrlyVPreset, preIxBrlyVMaintable, preUref, start) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyHistRMUserUniversal SET refBrlyMUser = ?, unvIxBrlyVMaintable = ?, unvUref = ?, ixBrlyVCard = ?, ixBrlyVPreset = ?, preIxBrlyVMaintable = ?, preUref = ?, start = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyHistRMUserUniversal WHERE ref = ?", false);
};

bool MyTblBrlyHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyHistRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyHistRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyHistRMUserUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyHistRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMUser = atoll((char*) dbrow[1]); else _rec->refBrlyMUser = 0;
		if (dbrow[2]) _rec->unvIxBrlyVMaintable = atol((char*) dbrow[2]); else _rec->unvIxBrlyVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixBrlyVCard = atol((char*) dbrow[4]); else _rec->ixBrlyVCard = 0;
		if (dbrow[5]) _rec->ixBrlyVPreset = atol((char*) dbrow[5]); else _rec->ixBrlyVPreset = 0;
		if (dbrow[6]) _rec->preIxBrlyVMaintable = atol((char*) dbrow[6]); else _rec->preIxBrlyVMaintable = 0;
		if (dbrow[7]) _rec->preUref = atoll((char*) dbrow[7]); else _rec->preUref = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyHistRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyHistRMUserUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyHistRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMUser = atoll((char*) dbrow[1]); else rec->refBrlyMUser = 0;
			if (dbrow[2]) rec->unvIxBrlyVMaintable = atol((char*) dbrow[2]); else rec->unvIxBrlyVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixBrlyVCard = atol((char*) dbrow[4]); else rec->ixBrlyVCard = 0;
			if (dbrow[5]) rec->ixBrlyVPreset = atol((char*) dbrow[5]); else rec->ixBrlyVPreset = 0;
			if (dbrow[6]) rec->preIxBrlyVMaintable = atol((char*) dbrow[6]); else rec->preIxBrlyVMaintable = 0;
			if (dbrow[7]) rec->preUref = atoll((char*) dbrow[7]); else rec->preUref = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyHistRMUserUniversal::insertRec(
			BrlyHistRMUserUniversal* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxBrlyVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxBrlyVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyHistRMUserUniversal / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyHistRMUserUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyHistRMUserUniversal::insertRst(
			ListBrlyHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyHistRMUserUniversal::updateRec(
			BrlyHistRMUserUniversal* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxBrlyVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixBrlyVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyVPreset,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->preIxBrlyVMaintable,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->preUref,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyHistRMUserUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyHistRMUserUniversal / stmtUpdateRec)\n");
};

void MyTblBrlyHistRMUserUniversal::updateRst(
			ListBrlyHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyHistRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyHistRMUserUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyHistRMUserUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, BrlyHistRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyHistRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refBrlyMUser
			, uint ixBrlyVCard
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, ixBrlyVPreset, preIxBrlyVMaintable, preUref, start FROM TblBrlyHistRMUserUniversal WHERE refBrlyMUser = " + to_string(refBrlyMUser) + " AND ixBrlyVCard = " + to_string(ixBrlyVCard) + " ORDER BY start DESC", append, rst);
};

bool MyTblBrlyHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	return loadRefBySQL("SELECT unvUref FROM TblBrlyHistRMUserUniversal WHERE ref = " + to_string(ref) + "", unvUref);
};

/******************************************************************************
 class PgTblBrlyHistRMUserUniversal
 ******************************************************************************/

PgTblBrlyHistRMUserUniversal::PgTblBrlyHistRMUserUniversal() : TblBrlyHistRMUserUniversal(), PgTable() {
};

PgTblBrlyHistRMUserUniversal::~PgTblBrlyHistRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyHistRMUserUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyHistRMUserUniversal_insertRec", "INSERT INTO TblBrlyHistRMUserUniversal (refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, ixBrlyVPreset, preIxBrlyVMaintable, preUref, start) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyHistRMUserUniversal_updateRec", "UPDATE TblBrlyHistRMUserUniversal SET refBrlyMUser = $1, unvIxBrlyVMaintable = $2, unvUref = $3, ixBrlyVCard = $4, ixBrlyVPreset = $5, preIxBrlyVMaintable = $6, preUref = $7, start = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyHistRMUserUniversal_removeRecByRef", "DELETE FROM TblBrlyHistRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyHistRMUserUniversal_loadRecByRef", "SELECT ref, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, ixBrlyVPreset, preIxBrlyVMaintable, preUref, start FROM TblBrlyHistRMUserUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyHistRMUserUniversal_loadRstByUsrCrd", "SELECT ref, refBrlyMUser, unvIxBrlyVMaintable, unvUref, ixBrlyVCard, ixBrlyVPreset, preIxBrlyVMaintable, preUref, start FROM TblBrlyHistRMUserUniversal WHERE refBrlyMUser = $1 AND ixBrlyVCard = $2 ORDER BY start DESC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyHistRMUserUniversal_loadUnuByRef", "SELECT unvUref FROM TblBrlyHistRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyHistRMUserUniversal::loadRec(
			PGresult* res
			, BrlyHistRMUserUniversal** rec
		) {
	char* ptr;

	BrlyHistRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyHistRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "unvixbrlyvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixbrlyvcard"),
			PQfnumber(res, "ixbrlyvpreset"),
			PQfnumber(res, "preixbrlyvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxBrlyVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixBrlyVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixBrlyVPreset = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->preIxBrlyVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->preUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->start = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyHistRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyHistRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymuser"),
			PQfnumber(res, "unvixbrlyvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixbrlyvcard"),
			PQfnumber(res, "ixbrlyvpreset"),
			PQfnumber(res, "preixbrlyvmaintable"),
			PQfnumber(res, "preuref"),
			PQfnumber(res, "start")
		};

		while (numread < numrow) {
			rec = new BrlyHistRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxBrlyVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixBrlyVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixBrlyVPreset = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->preIxBrlyVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->preUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->start = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyHistRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyHistRMUserUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyHistRMUserUniversal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyHistRMUserUniversal / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyHistRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, BrlyHistRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyHistRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyHistRMUserUniversal::insertRec(
			BrlyHistRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _unvIxBrlyVMaintable = htonl(rec->unvIxBrlyVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixBrlyVCard = htonl(rec->ixBrlyVCard);
	uint _ixBrlyVPreset = htonl(rec->ixBrlyVPreset);
	uint _preIxBrlyVMaintable = htonl(rec->preIxBrlyVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_unvIxBrlyVMaintable,
		(char*) &_unvUref,
		(char*) &_ixBrlyVCard,
		(char*) &_ixBrlyVPreset,
		(char*) &_preIxBrlyVMaintable,
		(char*) &_preUref,
		(char*) &_start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyHistRMUserUniversal_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyHistRMUserUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyHistRMUserUniversal::insertRst(
			ListBrlyHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyHistRMUserUniversal::updateRec(
			BrlyHistRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refBrlyMUser = htonl64(rec->refBrlyMUser);
	uint _unvIxBrlyVMaintable = htonl(rec->unvIxBrlyVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixBrlyVCard = htonl(rec->ixBrlyVCard);
	uint _ixBrlyVPreset = htonl(rec->ixBrlyVPreset);
	uint _preIxBrlyVMaintable = htonl(rec->preIxBrlyVMaintable);
	ubigint _preUref = htonl64(rec->preUref);
	uint _start = htonl(rec->start);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_unvIxBrlyVMaintable,
		(char*) &_unvUref,
		(char*) &_ixBrlyVCard,
		(char*) &_ixBrlyVPreset,
		(char*) &_preIxBrlyVMaintable,
		(char*) &_preUref,
		(char*) &_start,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyHistRMUserUniversal_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyHistRMUserUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyHistRMUserUniversal::updateRst(
			ListBrlyHistRMUserUniversal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyHistRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyHistRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyHistRMUserUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyHistRMUserUniversal::loadRecByRef(
			ubigint ref
			, BrlyHistRMUserUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyHistRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyHistRMUserUniversal::loadRstByUsrCrd(
			ubigint refBrlyMUser
			, uint ixBrlyVCard
			, const bool append
			, ListBrlyHistRMUserUniversal& rst
		) {
	ubigint _refBrlyMUser = htonl64(refBrlyMUser);
	uint _ixBrlyVCard = htonl(ixBrlyVCard);

	const char* vals[] = {
		(char*) &_refBrlyMUser,
		(char*) &_ixBrlyVCard
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblBrlyHistRMUserUniversal_loadRstByUsrCrd", 2, vals, l, f, append, rst);
};

bool PgTblBrlyHistRMUserUniversal::loadUnuByRef(
			ubigint ref
			, ubigint& unvUref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblBrlyHistRMUserUniversal_loadUnuByRef", 1, vals, l, f, unvUref);
};

