/**
  * \file BrlyMConnection.cpp
  * database access for table TblBrlyMConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMConnection.h"

#include "BrlyMConnection_vecs.cpp"

/******************************************************************************
 class BrlyMConnection
 ******************************************************************************/

BrlyMConnection::BrlyMConnection(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refBrlyMFlight
			, const ubigint corRefBrlyMLeg
			, const uint start
			, const uint stop
			, const uint ixVModel
			, const ubigint refBrlyMTimetable
			, const string srefsBrlyKEqptype
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refBrlyMFlight = refBrlyMFlight;
	this->corRefBrlyMLeg = corRefBrlyMLeg;
	this->start = start;
	this->stop = stop;
	this->ixVModel = ixVModel;
	this->refBrlyMTimetable = refBrlyMTimetable;
	this->srefsBrlyKEqptype = srefsBrlyKEqptype;
};

bool BrlyMConnection::operator==(
			const BrlyMConnection& comp
		) {
	return false;
};

bool BrlyMConnection::operator!=(
			const BrlyMConnection& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMConnection
 ******************************************************************************/

ListBrlyMConnection::ListBrlyMConnection() {
};

ListBrlyMConnection::ListBrlyMConnection(
			const ListBrlyMConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMConnection(*(src.nodes[i]));
};

ListBrlyMConnection::~ListBrlyMConnection() {
	clear();
};

void ListBrlyMConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMConnection::size() const {
	return(nodes.size());
};

void ListBrlyMConnection::append(
			BrlyMConnection* rec
		) {
	nodes.push_back(rec);
};

BrlyMConnection* ListBrlyMConnection::operator[](
			const uint ix
		) {
	BrlyMConnection* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMConnection& ListBrlyMConnection::operator=(
			const ListBrlyMConnection& src
		) {
	BrlyMConnection* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMConnection(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMConnection::operator==(
			const ListBrlyMConnection& comp
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

bool ListBrlyMConnection::operator!=(
			const ListBrlyMConnection& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMConnection
 ******************************************************************************/

TblBrlyMConnection::TblBrlyMConnection() {
};

TblBrlyMConnection::~TblBrlyMConnection() {
};

bool TblBrlyMConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyMConnection** rec
		) {
	return false;
};

ubigint TblBrlyMConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMConnection& rst
		) {
	return 0;
};

void TblBrlyMConnection::insertRec(
			BrlyMConnection* rec
		) {
};

ubigint TblBrlyMConnection::insertNewRec(
			BrlyMConnection** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refBrlyMFlight
			, const ubigint corRefBrlyMLeg
			, const uint start
			, const uint stop
			, const uint ixVModel
			, const ubigint refBrlyMTimetable
			, const string srefsBrlyKEqptype
		) {
	ubigint retval = 0;
	BrlyMConnection* _rec = NULL;

	_rec = new BrlyMConnection(0, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel, refBrlyMTimetable, srefsBrlyKEqptype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMConnection::appendNewRecToRst(
			ListBrlyMConnection& rst
			, BrlyMConnection** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refBrlyMFlight
			, const ubigint corRefBrlyMLeg
			, const uint start
			, const uint stop
			, const uint ixVModel
			, const ubigint refBrlyMTimetable
			, const string srefsBrlyKEqptype
		) {
	ubigint retval = 0;
	BrlyMConnection* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel, refBrlyMTimetable, srefsBrlyKEqptype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMConnection::insertRst(
			ListBrlyMConnection& rst
			, bool transact
		) {
};

void TblBrlyMConnection::updateRec(
			BrlyMConnection* rec
		) {
};

void TblBrlyMConnection::updateRst(
			ListBrlyMConnection& rst
			, bool transact
		) {
};

void TblBrlyMConnection::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMConnection::loadRecByRef(
			ubigint ref
			, BrlyMConnection** rec
		) {
	return false;
};

ubigint TblBrlyMConnection::loadRefsByLeg(
			const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMConnection::loadRstByLeg(
			const bool append
			, ListBrlyMConnection& rst
		) {
	return 0;
};

ubigint TblBrlyMConnection::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMConnection& rst
		) {
	ubigint numload = 0;
	BrlyMConnection* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMConnection
 ******************************************************************************/

MyTblBrlyMConnection::MyTblBrlyMConnection() : TblBrlyMConnection(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMConnection::~MyTblBrlyMConnection() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMConnection::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMConnection (grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel, refBrlyMTimetable, srefsBrlyKEqptype) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMConnection SET grp = ?, own = ?, refBrlyMFlight = ?, corRefBrlyMLeg = ?, start = ?, stop = ?, ixVModel = ?, refBrlyMTimetable = ?, srefsBrlyKEqptype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMConnection WHERE ref = ?", false);
};

bool MyTblBrlyMConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyMConnection** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMConnection* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMConnection / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMConnection();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refBrlyMFlight = atoll((char*) dbrow[3]); else _rec->refBrlyMFlight = 0;
		if (dbrow[4]) _rec->corRefBrlyMLeg = atoll((char*) dbrow[4]); else _rec->corRefBrlyMLeg = 0;
		if (dbrow[5]) _rec->start = atol((char*) dbrow[5]); else _rec->start = 0;
		if (dbrow[6]) _rec->stop = atol((char*) dbrow[6]); else _rec->stop = 0;
		if (dbrow[7]) _rec->ixVModel = atol((char*) dbrow[7]); else _rec->ixVModel = 0;
		if (dbrow[8]) _rec->refBrlyMTimetable = atoll((char*) dbrow[8]); else _rec->refBrlyMTimetable = 0;
		if (dbrow[9]) _rec->srefsBrlyKEqptype.assign(dbrow[9], dblengths[9]); else _rec->srefsBrlyKEqptype = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMConnection& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMConnection* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMConnection / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMConnection();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refBrlyMFlight = atoll((char*) dbrow[3]); else rec->refBrlyMFlight = 0;
			if (dbrow[4]) rec->corRefBrlyMLeg = atoll((char*) dbrow[4]); else rec->corRefBrlyMLeg = 0;
			if (dbrow[5]) rec->start = atol((char*) dbrow[5]); else rec->start = 0;
			if (dbrow[6]) rec->stop = atol((char*) dbrow[6]); else rec->stop = 0;
			if (dbrow[7]) rec->ixVModel = atol((char*) dbrow[7]); else rec->ixVModel = 0;
			if (dbrow[8]) rec->refBrlyMTimetable = atoll((char*) dbrow[8]); else rec->refBrlyMTimetable = 0;
			if (dbrow[9]) rec->srefsBrlyKEqptype.assign(dbrow[9], dblengths[9]); else rec->srefsBrlyKEqptype = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMConnection::insertRec(
			BrlyMConnection* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[8] = rec->srefsBrlyKEqptype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMFlight,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->corRefBrlyMLeg,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->stop,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVModel,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refBrlyMTimetable,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srefsBrlyKEqptype.c_str()),&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMConnection / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMConnection / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMConnection::insertRst(
			ListBrlyMConnection& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMConnection::updateRec(
			BrlyMConnection* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[8] = rec->srefsBrlyKEqptype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMFlight,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->corRefBrlyMLeg,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->stop,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVModel,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refBrlyMTimetable,&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->srefsBrlyKEqptype.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->ref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMConnection / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMConnection / stmtUpdateRec)\n");
};

void MyTblBrlyMConnection::updateRst(
			ListBrlyMConnection& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMConnection::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMConnection / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMConnection / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMConnection::loadRecByRef(
			ubigint ref
			, BrlyMConnection** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMConnection WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyMConnection::loadRefsByLeg(
			const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMConnection WHERE refBrlyMLeg =  ORDER BY start ASC", append, refs);
};

ubigint MyTblBrlyMConnection::loadRstByLeg(
			const bool append
			, ListBrlyMConnection& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel, refBrlyMTimetable, srefsBrlyKEqptype FROM TblBrlyMConnection WHERE refBrlyMLeg =  ORDER BY start ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyMConnection
 ******************************************************************************/

PgTblBrlyMConnection::PgTblBrlyMConnection() : TblBrlyMConnection(), PgTable() {
};

PgTblBrlyMConnection::~PgTblBrlyMConnection() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMConnection::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMConnection_insertRec", "INSERT INTO TblBrlyMConnection (grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel, refBrlyMTimetable, srefsBrlyKEqptype) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING ref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMConnection_updateRec", "UPDATE TblBrlyMConnection SET grp = $1, own = $2, refBrlyMFlight = $3, corRefBrlyMLeg = $4, start = $5, stop = $6, ixVModel = $7, refBrlyMTimetable = $8, srefsBrlyKEqptype = $9 WHERE ref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMConnection_removeRecByRef", "DELETE FROM TblBrlyMConnection WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMConnection_loadRecByRef", "SELECT ref, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel, refBrlyMTimetable, srefsBrlyKEqptype FROM TblBrlyMConnection WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMConnection_loadRefsByLeg", "SELECT ref FROM TblBrlyMConnection WHERE refBrlyMLeg = $1 ORDER BY start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMConnection_loadRstByLeg", "SELECT ref, grp, own, refBrlyMFlight, corRefBrlyMLeg, start, stop, ixVModel, refBrlyMTimetable, srefsBrlyKEqptype FROM TblBrlyMConnection WHERE refBrlyMLeg = $1 ORDER BY start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMConnection::loadRec(
			PGresult* res
			, BrlyMConnection** rec
		) {
	char* ptr;

	BrlyMConnection* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMConnection();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refbrlymflight"),
			PQfnumber(res, "correfbrlymleg"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ixvmodel"),
			PQfnumber(res, "refbrlymtimetable"),
			PQfnumber(res, "srefsbrlykeqptype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refBrlyMFlight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->corRefBrlyMLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVModel = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refBrlyMTimetable = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->srefsBrlyKEqptype.assign(ptr, PQgetlength(res, 0, fnum[9]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMConnection::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMConnection& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMConnection* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refbrlymflight"),
			PQfnumber(res, "correfbrlymleg"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ixvmodel"),
			PQfnumber(res, "refbrlymtimetable"),
			PQfnumber(res, "srefsbrlykeqptype")
		};

		while (numread < numrow) {
			rec = new BrlyMConnection();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refBrlyMFlight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->corRefBrlyMLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVModel = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refBrlyMTimetable = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->srefsBrlyKEqptype.assign(ptr, PQgetlength(res, numread, fnum[9]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMConnection::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMConnection** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMConnection / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMConnection::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMConnection& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMConnection / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyMConnection** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMConnection& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMConnection::insertRec(
			BrlyMConnection* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	ubigint _corRefBrlyMLeg = htonl64(rec->corRefBrlyMLeg);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	uint _ixVModel = htonl(rec->ixVModel);
	ubigint _refBrlyMTimetable = htonl64(rec->refBrlyMTimetable);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refBrlyMFlight,
		(char*) &_corRefBrlyMLeg,
		(char*) &_start,
		(char*) &_stop,
		(char*) &_ixVModel,
		(char*) &_refBrlyMTimetable,
		rec->srefsBrlyKEqptype.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyMConnection_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMConnection_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMConnection::insertRst(
			ListBrlyMConnection& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMConnection::updateRec(
			BrlyMConnection* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refBrlyMFlight = htonl64(rec->refBrlyMFlight);
	ubigint _corRefBrlyMLeg = htonl64(rec->corRefBrlyMLeg);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	uint _ixVModel = htonl(rec->ixVModel);
	ubigint _refBrlyMTimetable = htonl64(rec->refBrlyMTimetable);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refBrlyMFlight,
		(char*) &_corRefBrlyMLeg,
		(char*) &_start,
		(char*) &_stop,
		(char*) &_ixVModel,
		(char*) &_refBrlyMTimetable,
		rec->srefsBrlyKEqptype.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMConnection_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMConnection_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMConnection::updateRst(
			ListBrlyMConnection& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMConnection::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMConnection_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMConnection_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMConnection::loadRecByRef(
			ubigint ref
			, BrlyMConnection** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMConnection_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyMConnection::loadRefsByLeg(
			const bool append
			, vector<ubigint>& refs
		) {

	const char* vals[] = {
	};
	const int l[] = {
	};
	const int f[] = {};

	return loadRefsByStmt("TblBrlyMConnection_loadRefsByLeg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMConnection::loadRstByLeg(
			const bool append
			, ListBrlyMConnection& rst
		) {

	const char* vals[] = {
	};
	const int l[] = {
	};
	const int f[] = {};

	return loadRstByStmt("TblBrlyMConnection_loadRstByLeg", 1, vals, l, f, append, rst);
};

