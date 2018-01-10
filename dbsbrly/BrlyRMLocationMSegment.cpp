/**
  * \file BrlyRMLocationMSegment.cpp
  * database access for table TblBrlyRMLocationMSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMLocationMSegment.h"

/******************************************************************************
 class BrlyRMLocationMSegment
 ******************************************************************************/

BrlyRMLocationMSegment::BrlyRMLocationMSegment(
			const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const double x2VisSegphi0
			, const double x2VisSegphi1
			, const ubigint refBrlyMLocation
			, const ubigint refBrlyMSegment
			, const double segphi
			, const double segtheta
		) {

	this->ref = ref;
	this->x1Start = x1Start;
	this->x1Stop = x1Stop;
	this->x2VisSegphi0 = x2VisSegphi0;
	this->x2VisSegphi1 = x2VisSegphi1;
	this->refBrlyMLocation = refBrlyMLocation;
	this->refBrlyMSegment = refBrlyMSegment;
	this->segphi = segphi;
	this->segtheta = segtheta;
};

bool BrlyRMLocationMSegment::operator==(
			const BrlyRMLocationMSegment& comp
		) {
	return false;
};

bool BrlyRMLocationMSegment::operator!=(
			const BrlyRMLocationMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMLocationMSegment
 ******************************************************************************/

ListBrlyRMLocationMSegment::ListBrlyRMLocationMSegment() {
};

ListBrlyRMLocationMSegment::ListBrlyRMLocationMSegment(
			const ListBrlyRMLocationMSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMLocationMSegment(*(src.nodes[i]));
};

ListBrlyRMLocationMSegment::~ListBrlyRMLocationMSegment() {
	clear();
};

void ListBrlyRMLocationMSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMLocationMSegment::size() const {
	return(nodes.size());
};

void ListBrlyRMLocationMSegment::append(
			BrlyRMLocationMSegment* rec
		) {
	nodes.push_back(rec);
};

BrlyRMLocationMSegment* ListBrlyRMLocationMSegment::operator[](
			const uint ix
		) {
	BrlyRMLocationMSegment* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMLocationMSegment& ListBrlyRMLocationMSegment::operator=(
			const ListBrlyRMLocationMSegment& src
		) {
	BrlyRMLocationMSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMLocationMSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMLocationMSegment::operator==(
			const ListBrlyRMLocationMSegment& comp
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

bool ListBrlyRMLocationMSegment::operator!=(
			const ListBrlyRMLocationMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMLocationMSegment
 ******************************************************************************/

TblBrlyRMLocationMSegment::TblBrlyRMLocationMSegment() {
};

TblBrlyRMLocationMSegment::~TblBrlyRMLocationMSegment() {
};

bool TblBrlyRMLocationMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLocationMSegment** rec
		) {
	return false;
};

ubigint TblBrlyRMLocationMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	return 0;
};

void TblBrlyRMLocationMSegment::insertRec(
			BrlyRMLocationMSegment* rec
		) {
};

ubigint TblBrlyRMLocationMSegment::insertNewRec(
			BrlyRMLocationMSegment** rec
			, const uint x1Start
			, const uint x1Stop
			, const double x2VisSegphi0
			, const double x2VisSegphi1
			, const ubigint refBrlyMLocation
			, const ubigint refBrlyMSegment
			, const double segphi
			, const double segtheta
		) {
	ubigint retval = 0;
	BrlyRMLocationMSegment* _rec = NULL;

	_rec = new BrlyRMLocationMSegment(0, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMLocationMSegment::appendNewRecToRst(
			ListBrlyRMLocationMSegment& rst
			, BrlyRMLocationMSegment** rec
			, const uint x1Start
			, const uint x1Stop
			, const double x2VisSegphi0
			, const double x2VisSegphi1
			, const ubigint refBrlyMLocation
			, const ubigint refBrlyMSegment
			, const double segphi
			, const double segtheta
		) {
	ubigint retval = 0;
	BrlyRMLocationMSegment* _rec = NULL;

	retval = insertNewRec(&_rec, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMLocationMSegment::insertRst(
			ListBrlyRMLocationMSegment& rst
			, bool transact
		) {
};

void TblBrlyRMLocationMSegment::updateRec(
			BrlyRMLocationMSegment* rec
		) {
};

void TblBrlyRMLocationMSegment::updateRst(
			ListBrlyRMLocationMSegment& rst
			, bool transact
		) {
};

void TblBrlyRMLocationMSegment::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMLocationMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMLocationMSegment** rec
		) {
	return false;
};

ubigint TblBrlyRMLocationMSegment::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	return 0;
};

ubigint TblBrlyRMLocationMSegment::loadRstBySeg(
			ubigint refBrlyMSegment
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	return 0;
};

ubigint TblBrlyRMLocationMSegment::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	ubigint numload = 0;
	BrlyRMLocationMSegment* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMLocationMSegment
 ******************************************************************************/

MyTblBrlyRMLocationMSegment::MyTblBrlyRMLocationMSegment() : TblBrlyRMLocationMSegment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMLocationMSegment::~MyTblBrlyRMLocationMSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMLocationMSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMLocationMSegment (x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMLocationMSegment SET x1Start = ?, x1Stop = ?, x2VisSegphi0 = ?, x2VisSegphi1 = ?, refBrlyMLocation = ?, refBrlyMSegment = ?, segphi = ?, segtheta = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMLocationMSegment WHERE ref = ?", false);
};

bool MyTblBrlyRMLocationMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLocationMSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMLocationMSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMLocationMSegment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMLocationMSegment();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Start = atol((char*) dbrow[1]); else _rec->x1Start = 0;
		if (dbrow[2]) _rec->x1Stop = atol((char*) dbrow[2]); else _rec->x1Stop = 0;
		if (dbrow[3]) _rec->x2VisSegphi0 = atof((char*) dbrow[3]); else _rec->x2VisSegphi0 = 0.0;
		if (dbrow[4]) _rec->x2VisSegphi1 = atof((char*) dbrow[4]); else _rec->x2VisSegphi1 = 0.0;
		if (dbrow[5]) _rec->refBrlyMLocation = atoll((char*) dbrow[5]); else _rec->refBrlyMLocation = 0;
		if (dbrow[6]) _rec->refBrlyMSegment = atoll((char*) dbrow[6]); else _rec->refBrlyMSegment = 0;
		if (dbrow[7]) _rec->segphi = atof((char*) dbrow[7]); else _rec->segphi = 0.0;
		if (dbrow[8]) _rec->segtheta = atof((char*) dbrow[8]); else _rec->segtheta = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMLocationMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMLocationMSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMLocationMSegment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMLocationMSegment();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Start = atol((char*) dbrow[1]); else rec->x1Start = 0;
			if (dbrow[2]) rec->x1Stop = atol((char*) dbrow[2]); else rec->x1Stop = 0;
			if (dbrow[3]) rec->x2VisSegphi0 = atof((char*) dbrow[3]); else rec->x2VisSegphi0 = 0.0;
			if (dbrow[4]) rec->x2VisSegphi1 = atof((char*) dbrow[4]); else rec->x2VisSegphi1 = 0.0;
			if (dbrow[5]) rec->refBrlyMLocation = atoll((char*) dbrow[5]); else rec->refBrlyMLocation = 0;
			if (dbrow[6]) rec->refBrlyMSegment = atoll((char*) dbrow[6]); else rec->refBrlyMSegment = 0;
			if (dbrow[7]) rec->segphi = atof((char*) dbrow[7]); else rec->segphi = 0.0;
			if (dbrow[8]) rec->segtheta = atof((char*) dbrow[8]); else rec->segtheta = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMLocationMSegment::insertRec(
			BrlyRMLocationMSegment* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x2VisSegphi0,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x2VisSegphi1,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMLocation,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMSegment,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->segphi,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->segtheta,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLocationMSegment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLocationMSegment / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMLocationMSegment::insertRst(
			ListBrlyRMLocationMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMLocationMSegment::updateRec(
			BrlyRMLocationMSegment* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x2VisSegphi0,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x2VisSegphi1,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMLocation,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMSegment,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->segphi,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->segtheta,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLocationMSegment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLocationMSegment / stmtUpdateRec)\n");
};

void MyTblBrlyRMLocationMSegment::updateRst(
			ListBrlyRMLocationMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMLocationMSegment::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLocationMSegment / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLocationMSegment / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMLocationMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMLocationMSegment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMLocationMSegment WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMLocationMSegment::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta FROM TblBrlyRMLocationMSegment WHERE refBrlyMLocation = " + to_string(refBrlyMLocation) + "", append, rst);
};

ubigint MyTblBrlyRMLocationMSegment::loadRstBySeg(
			ubigint refBrlyMSegment
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta FROM TblBrlyRMLocationMSegment WHERE refBrlyMSegment = " + to_string(refBrlyMSegment) + " ORDER BY segphi ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMLocationMSegment
 ******************************************************************************/

PgTblBrlyRMLocationMSegment::PgTblBrlyRMLocationMSegment() : TblBrlyRMLocationMSegment(), PgTable() {
};

PgTblBrlyRMLocationMSegment::~PgTblBrlyRMLocationMSegment() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMLocationMSegment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMLocationMSegment_insertRec", "INSERT INTO TblBrlyRMLocationMSegment (x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLocationMSegment_updateRec", "UPDATE TblBrlyRMLocationMSegment SET x1Start = $1, x1Stop = $2, x2VisSegphi0 = $3, x2VisSegphi1 = $4, refBrlyMLocation = $5, refBrlyMSegment = $6, segphi = $7, segtheta = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLocationMSegment_removeRecByRef", "DELETE FROM TblBrlyRMLocationMSegment WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMLocationMSegment_loadRecByRef", "SELECT ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta FROM TblBrlyRMLocationMSegment WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMLocationMSegment_loadRstByLoc", "SELECT ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta FROM TblBrlyRMLocationMSegment WHERE refBrlyMLocation = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLocationMSegment_loadRstBySeg", "SELECT ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, refBrlyMLocation, refBrlyMSegment, segphi, segtheta FROM TblBrlyRMLocationMSegment WHERE refBrlyMSegment = $1 ORDER BY segphi ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMLocationMSegment::loadRec(
			PGresult* res
			, BrlyRMLocationMSegment** rec
		) {
	char* ptr;

	BrlyRMLocationMSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMLocationMSegment();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2vissegphi0"),
			PQfnumber(res, "x2vissegphi1"),
			PQfnumber(res, "refbrlymlocation"),
			PQfnumber(res, "refbrlymsegment"),
			PQfnumber(res, "segphi"),
			PQfnumber(res, "segtheta")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2VisSegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2VisSegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refBrlyMSegment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->segphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->segtheta = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMLocationMSegment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMLocationMSegment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2vissegphi0"),
			PQfnumber(res, "x2vissegphi1"),
			PQfnumber(res, "refbrlymlocation"),
			PQfnumber(res, "refbrlymsegment"),
			PQfnumber(res, "segphi"),
			PQfnumber(res, "segtheta")
		};

		while (numread < numrow) {
			rec = new BrlyRMLocationMSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2VisSegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2VisSegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refBrlyMSegment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->segphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->segtheta = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMLocationMSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMLocationMSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLocationMSegment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMLocationMSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLocationMSegment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMLocationMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLocationMSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMLocationMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMLocationMSegment::insertRec(
			BrlyRMLocationMSegment* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2VisSegphi0 = to_string(rec->x2VisSegphi0);
	string _x2VisSegphi1 = to_string(rec->x2VisSegphi1);
	ubigint _refBrlyMLocation = htonl64(rec->refBrlyMLocation);
	ubigint _refBrlyMSegment = htonl64(rec->refBrlyMSegment);
	string _segphi = to_string(rec->segphi);
	string _segtheta = to_string(rec->segtheta);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2VisSegphi0.c_str(),
		_x2VisSegphi1.c_str(),
		(char*) &_refBrlyMLocation,
		(char*) &_refBrlyMSegment,
		_segphi.c_str(),
		_segtheta.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyRMLocationMSegment_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLocationMSegment_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMLocationMSegment::insertRst(
			ListBrlyRMLocationMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMLocationMSegment::updateRec(
			BrlyRMLocationMSegment* rec
		) {
	PGresult* res;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2VisSegphi0 = to_string(rec->x2VisSegphi0);
	string _x2VisSegphi1 = to_string(rec->x2VisSegphi1);
	ubigint _refBrlyMLocation = htonl64(rec->refBrlyMLocation);
	ubigint _refBrlyMSegment = htonl64(rec->refBrlyMSegment);
	string _segphi = to_string(rec->segphi);
	string _segtheta = to_string(rec->segtheta);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2VisSegphi0.c_str(),
		_x2VisSegphi1.c_str(),
		(char*) &_refBrlyMLocation,
		(char*) &_refBrlyMSegment,
		_segphi.c_str(),
		_segtheta.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMLocationMSegment_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLocationMSegment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMLocationMSegment::updateRst(
			ListBrlyRMLocationMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMLocationMSegment::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMLocationMSegment_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLocationMSegment_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMLocationMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMLocationMSegment** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMLocationMSegment_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMLocationMSegment::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	ubigint _refBrlyMLocation = htonl64(refBrlyMLocation);

	const char* vals[] = {
		(char*) &_refBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMLocationMSegment_loadRstByLoc", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMLocationMSegment::loadRstBySeg(
			ubigint refBrlyMSegment
			, const bool append
			, ListBrlyRMLocationMSegment& rst
		) {
	ubigint _refBrlyMSegment = htonl64(refBrlyMSegment);

	const char* vals[] = {
		(char*) &_refBrlyMSegment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMLocationMSegment_loadRstBySeg", 1, vals, l, f, append, rst);
};

