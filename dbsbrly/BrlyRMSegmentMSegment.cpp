/**
  * \file BrlyRMSegmentMSegment.cpp
  * database access for table TblBrlyRMSegmentMSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMSegmentMSegment.h"

/******************************************************************************
 class BrlyRMSegmentMSegment
 ******************************************************************************/

BrlyRMSegmentMSegment::BrlyRMSegmentMSegment(
			const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const double x2VisDstSegphi0
			, const double x2VisDstSegphi1
			, const ubigint dstRefBrlyMSegment
			, const ubigint orgRefBrlyMSegment
			, const double VisOrgSegphi0
			, const double VisOrgSegphi1
		) {

	this->ref = ref;
	this->x1Start = x1Start;
	this->x1Stop = x1Stop;
	this->x2VisDstSegphi0 = x2VisDstSegphi0;
	this->x2VisDstSegphi1 = x2VisDstSegphi1;
	this->dstRefBrlyMSegment = dstRefBrlyMSegment;
	this->orgRefBrlyMSegment = orgRefBrlyMSegment;
	this->VisOrgSegphi0 = VisOrgSegphi0;
	this->VisOrgSegphi1 = VisOrgSegphi1;
};

bool BrlyRMSegmentMSegment::operator==(
			const BrlyRMSegmentMSegment& comp
		) {
	return false;
};

bool BrlyRMSegmentMSegment::operator!=(
			const BrlyRMSegmentMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMSegmentMSegment
 ******************************************************************************/

ListBrlyRMSegmentMSegment::ListBrlyRMSegmentMSegment() {
};

ListBrlyRMSegmentMSegment::ListBrlyRMSegmentMSegment(
			const ListBrlyRMSegmentMSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMSegmentMSegment(*(src.nodes[i]));
};

ListBrlyRMSegmentMSegment::~ListBrlyRMSegmentMSegment() {
	clear();
};

void ListBrlyRMSegmentMSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMSegmentMSegment::size() const {
	return(nodes.size());
};

void ListBrlyRMSegmentMSegment::append(
			BrlyRMSegmentMSegment* rec
		) {
	nodes.push_back(rec);
};

BrlyRMSegmentMSegment* ListBrlyRMSegmentMSegment::operator[](
			const uint ix
		) {
	BrlyRMSegmentMSegment* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMSegmentMSegment& ListBrlyRMSegmentMSegment::operator=(
			const ListBrlyRMSegmentMSegment& src
		) {
	BrlyRMSegmentMSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMSegmentMSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMSegmentMSegment::operator==(
			const ListBrlyRMSegmentMSegment& comp
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

bool ListBrlyRMSegmentMSegment::operator!=(
			const ListBrlyRMSegmentMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMSegmentMSegment
 ******************************************************************************/

TblBrlyRMSegmentMSegment::TblBrlyRMSegmentMSegment() {
};

TblBrlyRMSegmentMSegment::~TblBrlyRMSegmentMSegment() {
};

bool TblBrlyRMSegmentMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMSegmentMSegment** rec
		) {
	return false;
};

ubigint TblBrlyRMSegmentMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	return 0;
};

void TblBrlyRMSegmentMSegment::insertRec(
			BrlyRMSegmentMSegment* rec
		) {
};

ubigint TblBrlyRMSegmentMSegment::insertNewRec(
			BrlyRMSegmentMSegment** rec
			, const uint x1Start
			, const uint x1Stop
			, const double x2VisDstSegphi0
			, const double x2VisDstSegphi1
			, const ubigint dstRefBrlyMSegment
			, const ubigint orgRefBrlyMSegment
			, const double VisOrgSegphi0
			, const double VisOrgSegphi1
		) {
	ubigint retval = 0;
	BrlyRMSegmentMSegment* _rec = NULL;

	_rec = new BrlyRMSegmentMSegment(0, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMSegmentMSegment::appendNewRecToRst(
			ListBrlyRMSegmentMSegment& rst
			, BrlyRMSegmentMSegment** rec
			, const uint x1Start
			, const uint x1Stop
			, const double x2VisDstSegphi0
			, const double x2VisDstSegphi1
			, const ubigint dstRefBrlyMSegment
			, const ubigint orgRefBrlyMSegment
			, const double VisOrgSegphi0
			, const double VisOrgSegphi1
		) {
	ubigint retval = 0;
	BrlyRMSegmentMSegment* _rec = NULL;

	retval = insertNewRec(&_rec, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMSegmentMSegment::insertRst(
			ListBrlyRMSegmentMSegment& rst
			, bool transact
		) {
};

void TblBrlyRMSegmentMSegment::updateRec(
			BrlyRMSegmentMSegment* rec
		) {
};

void TblBrlyRMSegmentMSegment::updateRst(
			ListBrlyRMSegmentMSegment& rst
			, bool transact
		) {
};

void TblBrlyRMSegmentMSegment::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMSegmentMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMSegmentMSegment** rec
		) {
	return false;
};

ubigint TblBrlyRMSegmentMSegment::loadRstByDsg(
			ubigint dstRefBrlyMSegment
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	return 0;
};

ubigint TblBrlyRMSegmentMSegment::loadRstByOsg(
			ubigint orgRefBrlyMSegment
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	return 0;
};

ubigint TblBrlyRMSegmentMSegment::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	ubigint numload = 0;
	BrlyRMSegmentMSegment* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMSegmentMSegment
 ******************************************************************************/

MyTblBrlyRMSegmentMSegment::MyTblBrlyRMSegmentMSegment() : TblBrlyRMSegmentMSegment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMSegmentMSegment::~MyTblBrlyRMSegmentMSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMSegmentMSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMSegmentMSegment (x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMSegmentMSegment SET x1Start = ?, x1Stop = ?, x2VisDstSegphi0 = ?, x2VisDstSegphi1 = ?, dstRefBrlyMSegment = ?, orgRefBrlyMSegment = ?, VisOrgSegphi0 = ?, VisOrgSegphi1 = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMSegmentMSegment WHERE ref = ?", false);
};

bool MyTblBrlyRMSegmentMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMSegmentMSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMSegmentMSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMSegmentMSegment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMSegmentMSegment();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1Start = atol((char*) dbrow[1]); else _rec->x1Start = 0;
		if (dbrow[2]) _rec->x1Stop = atol((char*) dbrow[2]); else _rec->x1Stop = 0;
		if (dbrow[3]) _rec->x2VisDstSegphi0 = atof((char*) dbrow[3]); else _rec->x2VisDstSegphi0 = 0.0;
		if (dbrow[4]) _rec->x2VisDstSegphi1 = atof((char*) dbrow[4]); else _rec->x2VisDstSegphi1 = 0.0;
		if (dbrow[5]) _rec->dstRefBrlyMSegment = atoll((char*) dbrow[5]); else _rec->dstRefBrlyMSegment = 0;
		if (dbrow[6]) _rec->orgRefBrlyMSegment = atoll((char*) dbrow[6]); else _rec->orgRefBrlyMSegment = 0;
		if (dbrow[7]) _rec->VisOrgSegphi0 = atof((char*) dbrow[7]); else _rec->VisOrgSegphi0 = 0.0;
		if (dbrow[8]) _rec->VisOrgSegphi1 = atof((char*) dbrow[8]); else _rec->VisOrgSegphi1 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMSegmentMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMSegmentMSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMSegmentMSegment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMSegmentMSegment();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1Start = atol((char*) dbrow[1]); else rec->x1Start = 0;
			if (dbrow[2]) rec->x1Stop = atol((char*) dbrow[2]); else rec->x1Stop = 0;
			if (dbrow[3]) rec->x2VisDstSegphi0 = atof((char*) dbrow[3]); else rec->x2VisDstSegphi0 = 0.0;
			if (dbrow[4]) rec->x2VisDstSegphi1 = atof((char*) dbrow[4]); else rec->x2VisDstSegphi1 = 0.0;
			if (dbrow[5]) rec->dstRefBrlyMSegment = atoll((char*) dbrow[5]); else rec->dstRefBrlyMSegment = 0;
			if (dbrow[6]) rec->orgRefBrlyMSegment = atoll((char*) dbrow[6]); else rec->orgRefBrlyMSegment = 0;
			if (dbrow[7]) rec->VisOrgSegphi0 = atof((char*) dbrow[7]); else rec->VisOrgSegphi0 = 0.0;
			if (dbrow[8]) rec->VisOrgSegphi1 = atof((char*) dbrow[8]); else rec->VisOrgSegphi1 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMSegmentMSegment::insertRec(
			BrlyRMSegmentMSegment* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x2VisDstSegphi0,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x2VisDstSegphi1,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->dstRefBrlyMSegment,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->orgRefBrlyMSegment,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->VisOrgSegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->VisOrgSegphi1,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMSegmentMSegment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMSegmentMSegment / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMSegmentMSegment::insertRst(
			ListBrlyRMSegmentMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMSegmentMSegment::updateRec(
			BrlyRMSegmentMSegment* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUint(&rec->x1Start,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Stop,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x2VisDstSegphi0,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->x2VisDstSegphi1,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->dstRefBrlyMSegment,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->orgRefBrlyMSegment,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->VisOrgSegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->VisOrgSegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMSegmentMSegment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMSegmentMSegment / stmtUpdateRec)\n");
};

void MyTblBrlyRMSegmentMSegment::updateRst(
			ListBrlyRMSegmentMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMSegmentMSegment::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMSegmentMSegment / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMSegmentMSegment / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMSegmentMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMSegmentMSegment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMSegmentMSegment WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMSegmentMSegment::loadRstByDsg(
			ubigint dstRefBrlyMSegment
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1 FROM TblBrlyRMSegmentMSegment WHERE dstRefBrlyMSegment = " + to_string(dstRefBrlyMSegment) + " ORDER BY x1VisDstSegphi0 ASC", append, rst);
};

ubigint MyTblBrlyRMSegmentMSegment::loadRstByOsg(
			ubigint orgRefBrlyMSegment
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1 FROM TblBrlyRMSegmentMSegment WHERE orgRefBrlyMSegment = " + to_string(orgRefBrlyMSegment) + "", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMSegmentMSegment
 ******************************************************************************/

PgTblBrlyRMSegmentMSegment::PgTblBrlyRMSegmentMSegment() : TblBrlyRMSegmentMSegment(), PgTable() {
};

PgTblBrlyRMSegmentMSegment::~PgTblBrlyRMSegmentMSegment() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMSegmentMSegment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMSegmentMSegment_insertRec", "INSERT INTO TblBrlyRMSegmentMSegment (x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMSegmentMSegment_updateRec", "UPDATE TblBrlyRMSegmentMSegment SET x1Start = $1, x1Stop = $2, x2VisDstSegphi0 = $3, x2VisDstSegphi1 = $4, dstRefBrlyMSegment = $5, orgRefBrlyMSegment = $6, VisOrgSegphi0 = $7, VisOrgSegphi1 = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMSegmentMSegment_removeRecByRef", "DELETE FROM TblBrlyRMSegmentMSegment WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMSegmentMSegment_loadRecByRef", "SELECT ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1 FROM TblBrlyRMSegmentMSegment WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMSegmentMSegment_loadRstByDsg", "SELECT ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1 FROM TblBrlyRMSegmentMSegment WHERE dstRefBrlyMSegment = $1 ORDER BY x1VisDstSegphi0 ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMSegmentMSegment_loadRstByOsg", "SELECT ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, dstRefBrlyMSegment, orgRefBrlyMSegment, VisOrgSegphi0, VisOrgSegphi1 FROM TblBrlyRMSegmentMSegment WHERE orgRefBrlyMSegment = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMSegmentMSegment::loadRec(
			PGresult* res
			, BrlyRMSegmentMSegment** rec
		) {
	char* ptr;

	BrlyRMSegmentMSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMSegmentMSegment();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2visdstsegphi0"),
			PQfnumber(res, "x2visdstsegphi1"),
			PQfnumber(res, "dstrefbrlymsegment"),
			PQfnumber(res, "orgrefbrlymsegment"),
			PQfnumber(res, "visorgsegphi0"),
			PQfnumber(res, "visorgsegphi1")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2VisDstSegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2VisDstSegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->dstRefBrlyMSegment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->orgRefBrlyMSegment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->VisOrgSegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->VisOrgSegphi1 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMSegmentMSegment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMSegmentMSegment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2visdstsegphi0"),
			PQfnumber(res, "x2visdstsegphi1"),
			PQfnumber(res, "dstrefbrlymsegment"),
			PQfnumber(res, "orgrefbrlymsegment"),
			PQfnumber(res, "visorgsegphi0"),
			PQfnumber(res, "visorgsegphi1")
		};

		while (numread < numrow) {
			rec = new BrlyRMSegmentMSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2VisDstSegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2VisDstSegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->dstRefBrlyMSegment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->orgRefBrlyMSegment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->VisOrgSegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->VisOrgSegphi1 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMSegmentMSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMSegmentMSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMSegmentMSegment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMSegmentMSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMSegmentMSegment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMSegmentMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyRMSegmentMSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMSegmentMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMSegmentMSegment::insertRec(
			BrlyRMSegmentMSegment* rec
		) {
	PGresult* res;
	char* ptr;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2VisDstSegphi0 = to_string(rec->x2VisDstSegphi0);
	string _x2VisDstSegphi1 = to_string(rec->x2VisDstSegphi1);
	ubigint _dstRefBrlyMSegment = htonl64(rec->dstRefBrlyMSegment);
	ubigint _orgRefBrlyMSegment = htonl64(rec->orgRefBrlyMSegment);
	string _VisOrgSegphi0 = to_string(rec->VisOrgSegphi0);
	string _VisOrgSegphi1 = to_string(rec->VisOrgSegphi1);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2VisDstSegphi0.c_str(),
		_x2VisDstSegphi1.c_str(),
		(char*) &_dstRefBrlyMSegment,
		(char*) &_orgRefBrlyMSegment,
		_VisOrgSegphi0.c_str(),
		_VisOrgSegphi1.c_str()
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

	res = PQexecPrepared(dbs, "TblBrlyRMSegmentMSegment_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMSegmentMSegment_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMSegmentMSegment::insertRst(
			ListBrlyRMSegmentMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMSegmentMSegment::updateRec(
			BrlyRMSegmentMSegment* rec
		) {
	PGresult* res;

	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2VisDstSegphi0 = to_string(rec->x2VisDstSegphi0);
	string _x2VisDstSegphi1 = to_string(rec->x2VisDstSegphi1);
	ubigint _dstRefBrlyMSegment = htonl64(rec->dstRefBrlyMSegment);
	ubigint _orgRefBrlyMSegment = htonl64(rec->orgRefBrlyMSegment);
	string _VisOrgSegphi0 = to_string(rec->VisOrgSegphi0);
	string _VisOrgSegphi1 = to_string(rec->VisOrgSegphi1);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2VisDstSegphi0.c_str(),
		_x2VisDstSegphi1.c_str(),
		(char*) &_dstRefBrlyMSegment,
		(char*) &_orgRefBrlyMSegment,
		_VisOrgSegphi0.c_str(),
		_VisOrgSegphi1.c_str(),
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

	res = PQexecPrepared(dbs, "TblBrlyRMSegmentMSegment_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMSegmentMSegment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMSegmentMSegment::updateRst(
			ListBrlyRMSegmentMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMSegmentMSegment::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMSegmentMSegment_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMSegmentMSegment_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMSegmentMSegment::loadRecByRef(
			ubigint ref
			, BrlyRMSegmentMSegment** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMSegmentMSegment_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMSegmentMSegment::loadRstByDsg(
			ubigint dstRefBrlyMSegment
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	ubigint _dstRefBrlyMSegment = htonl64(dstRefBrlyMSegment);

	const char* vals[] = {
		(char*) &_dstRefBrlyMSegment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMSegmentMSegment_loadRstByDsg", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMSegmentMSegment::loadRstByOsg(
			ubigint orgRefBrlyMSegment
			, const bool append
			, ListBrlyRMSegmentMSegment& rst
		) {
	ubigint _orgRefBrlyMSegment = htonl64(orgRefBrlyMSegment);

	const char* vals[] = {
		(char*) &_orgRefBrlyMSegment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMSegmentMSegment_loadRstByOsg", 1, vals, l, f, append, rst);
};

