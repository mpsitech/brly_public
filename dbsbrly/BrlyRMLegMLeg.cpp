/**
  * \file BrlyRMLegMLeg.cpp
  * database access for table TblBrlyRMLegMLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMLegMLeg.h"

/******************************************************************************
 class BrlyRMLegMLeg
 ******************************************************************************/

BrlyRMLegMLeg::BrlyRMLegMLeg(
			const ubigint ref
			, const double x1VisDstLegphi0
			, const double x1VisDstLegphi1
			, const ubigint dstRefBrlyMLeg
			, const ubigint orgRefBrlyMLeg
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const double xVisDstLegphi0
			, const double xVisDstLegphi1
			, const double xVisOrgLegphi0
			, const double xVisOrgLegphi1
		) {

	this->ref = ref;
	this->x1VisDstLegphi0 = x1VisDstLegphi0;
	this->x1VisDstLegphi1 = x1VisDstLegphi1;
	this->dstRefBrlyMLeg = dstRefBrlyMLeg;
	this->orgRefBrlyMLeg = orgRefBrlyMLeg;
	this->VisOrgLegphi0 = VisOrgLegphi0;
	this->VisOrgLegphi1 = VisOrgLegphi1;
	this->xVisDstLegphi0 = xVisDstLegphi0;
	this->xVisDstLegphi1 = xVisDstLegphi1;
	this->xVisOrgLegphi0 = xVisOrgLegphi0;
	this->xVisOrgLegphi1 = xVisOrgLegphi1;
};

bool BrlyRMLegMLeg::operator==(
			const BrlyRMLegMLeg& comp
		) {
	return false;
};

bool BrlyRMLegMLeg::operator!=(
			const BrlyRMLegMLeg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMLegMLeg
 ******************************************************************************/

ListBrlyRMLegMLeg::ListBrlyRMLegMLeg() {
};

ListBrlyRMLegMLeg::ListBrlyRMLegMLeg(
			const ListBrlyRMLegMLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMLegMLeg(*(src.nodes[i]));
};

ListBrlyRMLegMLeg::~ListBrlyRMLegMLeg() {
	clear();
};

void ListBrlyRMLegMLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMLegMLeg::size() const {
	return(nodes.size());
};

void ListBrlyRMLegMLeg::append(
			BrlyRMLegMLeg* rec
		) {
	nodes.push_back(rec);
};

BrlyRMLegMLeg* ListBrlyRMLegMLeg::operator[](
			const uint ix
		) {
	BrlyRMLegMLeg* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMLegMLeg& ListBrlyRMLegMLeg::operator=(
			const ListBrlyRMLegMLeg& src
		) {
	BrlyRMLegMLeg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMLegMLeg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMLegMLeg::operator==(
			const ListBrlyRMLegMLeg& comp
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

bool ListBrlyRMLegMLeg::operator!=(
			const ListBrlyRMLegMLeg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMLegMLeg
 ******************************************************************************/

TblBrlyRMLegMLeg::TblBrlyRMLegMLeg() {
};

TblBrlyRMLegMLeg::~TblBrlyRMLegMLeg() {
};

bool TblBrlyRMLegMLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLegMLeg** rec
		) {
	return false;
};

ubigint TblBrlyRMLegMLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	return 0;
};

void TblBrlyRMLegMLeg::insertRec(
			BrlyRMLegMLeg* rec
		) {
};

ubigint TblBrlyRMLegMLeg::insertNewRec(
			BrlyRMLegMLeg** rec
			, const double x1VisDstLegphi0
			, const double x1VisDstLegphi1
			, const ubigint dstRefBrlyMLeg
			, const ubigint orgRefBrlyMLeg
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const double xVisDstLegphi0
			, const double xVisDstLegphi1
			, const double xVisOrgLegphi0
			, const double xVisOrgLegphi1
		) {
	ubigint retval = 0;
	BrlyRMLegMLeg* _rec = NULL;

	_rec = new BrlyRMLegMLeg(0, x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMLegMLeg::appendNewRecToRst(
			ListBrlyRMLegMLeg& rst
			, BrlyRMLegMLeg** rec
			, const double x1VisDstLegphi0
			, const double x1VisDstLegphi1
			, const ubigint dstRefBrlyMLeg
			, const ubigint orgRefBrlyMLeg
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const double xVisDstLegphi0
			, const double xVisDstLegphi1
			, const double xVisOrgLegphi0
			, const double xVisOrgLegphi1
		) {
	ubigint retval = 0;
	BrlyRMLegMLeg* _rec = NULL;

	retval = insertNewRec(&_rec, x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMLegMLeg::insertRst(
			ListBrlyRMLegMLeg& rst
			, bool transact
		) {
};

void TblBrlyRMLegMLeg::updateRec(
			BrlyRMLegMLeg* rec
		) {
};

void TblBrlyRMLegMLeg::updateRst(
			ListBrlyRMLegMLeg& rst
			, bool transact
		) {
};

void TblBrlyRMLegMLeg::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMLegMLeg::loadRecByRef(
			ubigint ref
			, BrlyRMLegMLeg** rec
		) {
	return false;
};

ubigint TblBrlyRMLegMLeg::loadRstByDlg(
			ubigint dstRefBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	return 0;
};

ubigint TblBrlyRMLegMLeg::loadRstByOlg(
			ubigint orgRefBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	return 0;
};

ubigint TblBrlyRMLegMLeg::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	ubigint numload = 0;
	BrlyRMLegMLeg* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMLegMLeg
 ******************************************************************************/

MyTblBrlyRMLegMLeg::MyTblBrlyRMLegMLeg() : TblBrlyRMLegMLeg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMLegMLeg::~MyTblBrlyRMLegMLeg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMLegMLeg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMLegMLeg (x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMLegMLeg SET x1VisDstLegphi0 = ?, x1VisDstLegphi1 = ?, dstRefBrlyMLeg = ?, orgRefBrlyMLeg = ?, VisOrgLegphi0 = ?, VisOrgLegphi1 = ?, xVisDstLegphi0 = ?, xVisDstLegphi1 = ?, xVisOrgLegphi0 = ?, xVisOrgLegphi1 = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMLegMLeg WHERE ref = ?", false);
};

bool MyTblBrlyRMLegMLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLegMLeg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMLegMLeg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMLegMLeg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMLegMLeg();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1VisDstLegphi0 = atof((char*) dbrow[1]); else _rec->x1VisDstLegphi0 = 0.0;
		if (dbrow[2]) _rec->x1VisDstLegphi1 = atof((char*) dbrow[2]); else _rec->x1VisDstLegphi1 = 0.0;
		if (dbrow[3]) _rec->dstRefBrlyMLeg = atoll((char*) dbrow[3]); else _rec->dstRefBrlyMLeg = 0;
		if (dbrow[4]) _rec->orgRefBrlyMLeg = atoll((char*) dbrow[4]); else _rec->orgRefBrlyMLeg = 0;
		if (dbrow[5]) _rec->VisOrgLegphi0 = atof((char*) dbrow[5]); else _rec->VisOrgLegphi0 = 0.0;
		if (dbrow[6]) _rec->VisOrgLegphi1 = atof((char*) dbrow[6]); else _rec->VisOrgLegphi1 = 0.0;
		if (dbrow[7]) _rec->xVisDstLegphi0 = atof((char*) dbrow[7]); else _rec->xVisDstLegphi0 = 0.0;
		if (dbrow[8]) _rec->xVisDstLegphi1 = atof((char*) dbrow[8]); else _rec->xVisDstLegphi1 = 0.0;
		if (dbrow[9]) _rec->xVisOrgLegphi0 = atof((char*) dbrow[9]); else _rec->xVisOrgLegphi0 = 0.0;
		if (dbrow[10]) _rec->xVisOrgLegphi1 = atof((char*) dbrow[10]); else _rec->xVisOrgLegphi1 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMLegMLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMLegMLeg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMLegMLeg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMLegMLeg();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1VisDstLegphi0 = atof((char*) dbrow[1]); else rec->x1VisDstLegphi0 = 0.0;
			if (dbrow[2]) rec->x1VisDstLegphi1 = atof((char*) dbrow[2]); else rec->x1VisDstLegphi1 = 0.0;
			if (dbrow[3]) rec->dstRefBrlyMLeg = atoll((char*) dbrow[3]); else rec->dstRefBrlyMLeg = 0;
			if (dbrow[4]) rec->orgRefBrlyMLeg = atoll((char*) dbrow[4]); else rec->orgRefBrlyMLeg = 0;
			if (dbrow[5]) rec->VisOrgLegphi0 = atof((char*) dbrow[5]); else rec->VisOrgLegphi0 = 0.0;
			if (dbrow[6]) rec->VisOrgLegphi1 = atof((char*) dbrow[6]); else rec->VisOrgLegphi1 = 0.0;
			if (dbrow[7]) rec->xVisDstLegphi0 = atof((char*) dbrow[7]); else rec->xVisDstLegphi0 = 0.0;
			if (dbrow[8]) rec->xVisDstLegphi1 = atof((char*) dbrow[8]); else rec->xVisDstLegphi1 = 0.0;
			if (dbrow[9]) rec->xVisOrgLegphi0 = atof((char*) dbrow[9]); else rec->xVisOrgLegphi0 = 0.0;
			if (dbrow[10]) rec->xVisOrgLegphi1 = atof((char*) dbrow[10]); else rec->xVisOrgLegphi1 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMLegMLeg::insertRec(
			BrlyRMLegMLeg* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1VisDstLegphi0,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1VisDstLegphi1,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->dstRefBrlyMLeg,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->orgRefBrlyMLeg,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->VisOrgLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->VisOrgLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->xVisDstLegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->xVisDstLegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->xVisOrgLegphi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->xVisOrgLegphi1,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLegMLeg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLegMLeg / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMLegMLeg::insertRst(
			ListBrlyRMLegMLeg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMLegMLeg::updateRec(
			BrlyRMLegMLeg* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1VisDstLegphi0,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1VisDstLegphi1,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->dstRefBrlyMLeg,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->orgRefBrlyMLeg,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->VisOrgLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->VisOrgLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->xVisDstLegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->xVisDstLegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->xVisOrgLegphi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->xVisOrgLegphi1,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->ref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLegMLeg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLegMLeg / stmtUpdateRec)\n");
};

void MyTblBrlyRMLegMLeg::updateRst(
			ListBrlyRMLegMLeg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMLegMLeg::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLegMLeg / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLegMLeg / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMLegMLeg::loadRecByRef(
			ubigint ref
			, BrlyRMLegMLeg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMLegMLeg WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMLegMLeg::loadRstByDlg(
			ubigint dstRefBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	return loadRstBySQL("SELECT ref, x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1 FROM TblBrlyRMLegMLeg WHERE dstRefBrlyMLeg = " + to_string(dstRefBrlyMLeg) + " ORDER BY x1VisDstLegphi0 ASC", append, rst);
};

ubigint MyTblBrlyRMLegMLeg::loadRstByOlg(
			ubigint orgRefBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	return loadRstBySQL("SELECT ref, x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1 FROM TblBrlyRMLegMLeg WHERE orgRefBrlyMLeg = " + to_string(orgRefBrlyMLeg) + "", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMLegMLeg
 ******************************************************************************/

PgTblBrlyRMLegMLeg::PgTblBrlyRMLegMLeg() : TblBrlyRMLegMLeg(), PgTable() {
};

PgTblBrlyRMLegMLeg::~PgTblBrlyRMLegMLeg() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMLegMLeg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMLegMLeg_insertRec", "INSERT INTO TblBrlyRMLegMLeg (x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING ref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLegMLeg_updateRec", "UPDATE TblBrlyRMLegMLeg SET x1VisDstLegphi0 = $1, x1VisDstLegphi1 = $2, dstRefBrlyMLeg = $3, orgRefBrlyMLeg = $4, VisOrgLegphi0 = $5, VisOrgLegphi1 = $6, xVisDstLegphi0 = $7, xVisDstLegphi1 = $8, xVisOrgLegphi0 = $9, xVisOrgLegphi1 = $10 WHERE ref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLegMLeg_removeRecByRef", "DELETE FROM TblBrlyRMLegMLeg WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMLegMLeg_loadRecByRef", "SELECT ref, x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1 FROM TblBrlyRMLegMLeg WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMLegMLeg_loadRstByDlg", "SELECT ref, x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1 FROM TblBrlyRMLegMLeg WHERE dstRefBrlyMLeg = $1 ORDER BY x1VisDstLegphi0 ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLegMLeg_loadRstByOlg", "SELECT ref, x1VisDstLegphi0, x1VisDstLegphi1, dstRefBrlyMLeg, orgRefBrlyMLeg, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1 FROM TblBrlyRMLegMLeg WHERE orgRefBrlyMLeg = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMLegMLeg::loadRec(
			PGresult* res
			, BrlyRMLegMLeg** rec
		) {
	char* ptr;

	BrlyRMLegMLeg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMLegMLeg();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1visdstlegphi0"),
			PQfnumber(res, "x1visdstlegphi1"),
			PQfnumber(res, "dstrefbrlymleg"),
			PQfnumber(res, "orgrefbrlymleg"),
			PQfnumber(res, "visorglegphi0"),
			PQfnumber(res, "visorglegphi1"),
			PQfnumber(res, "xvisdstlegphi0"),
			PQfnumber(res, "xvisdstlegphi1"),
			PQfnumber(res, "xvisorglegphi0"),
			PQfnumber(res, "xvisorglegphi1")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1VisDstLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1VisDstLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->dstRefBrlyMLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->orgRefBrlyMLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->VisOrgLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->VisOrgLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->xVisDstLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->xVisDstLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->xVisOrgLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->xVisOrgLegphi1 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMLegMLeg::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMLegMLeg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1visdstlegphi0"),
			PQfnumber(res, "x1visdstlegphi1"),
			PQfnumber(res, "dstrefbrlymleg"),
			PQfnumber(res, "orgrefbrlymleg"),
			PQfnumber(res, "visorglegphi0"),
			PQfnumber(res, "visorglegphi1"),
			PQfnumber(res, "xvisdstlegphi0"),
			PQfnumber(res, "xvisdstlegphi1"),
			PQfnumber(res, "xvisorglegphi0"),
			PQfnumber(res, "xvisorglegphi1")
		};

		while (numread < numrow) {
			rec = new BrlyRMLegMLeg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1VisDstLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1VisDstLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->dstRefBrlyMLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->orgRefBrlyMLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->VisOrgLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->VisOrgLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->xVisDstLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->xVisDstLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->xVisOrgLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->xVisOrgLegphi1 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMLegMLeg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMLegMLeg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLeg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMLegMLeg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLeg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMLegMLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLegMLeg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMLegMLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMLegMLeg::insertRec(
			BrlyRMLegMLeg* rec
		) {
	PGresult* res;
	char* ptr;

	string _x1VisDstLegphi0 = to_string(rec->x1VisDstLegphi0);
	string _x1VisDstLegphi1 = to_string(rec->x1VisDstLegphi1);
	ubigint _dstRefBrlyMLeg = htonl64(rec->dstRefBrlyMLeg);
	ubigint _orgRefBrlyMLeg = htonl64(rec->orgRefBrlyMLeg);
	string _VisOrgLegphi0 = to_string(rec->VisOrgLegphi0);
	string _VisOrgLegphi1 = to_string(rec->VisOrgLegphi1);
	string _xVisDstLegphi0 = to_string(rec->xVisDstLegphi0);
	string _xVisDstLegphi1 = to_string(rec->xVisDstLegphi1);
	string _xVisOrgLegphi0 = to_string(rec->xVisOrgLegphi0);
	string _xVisOrgLegphi1 = to_string(rec->xVisOrgLegphi1);

	const char* vals[] = {
		_x1VisDstLegphi0.c_str(),
		_x1VisDstLegphi1.c_str(),
		(char*) &_dstRefBrlyMLeg,
		(char*) &_orgRefBrlyMLeg,
		_VisOrgLegphi0.c_str(),
		_VisOrgLegphi1.c_str(),
		_xVisDstLegphi0.c_str(),
		_xVisDstLegphi1.c_str(),
		_xVisOrgLegphi0.c_str(),
		_xVisOrgLegphi1.c_str()
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyRMLegMLeg_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLeg_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMLegMLeg::insertRst(
			ListBrlyRMLegMLeg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMLegMLeg::updateRec(
			BrlyRMLegMLeg* rec
		) {
	PGresult* res;

	string _x1VisDstLegphi0 = to_string(rec->x1VisDstLegphi0);
	string _x1VisDstLegphi1 = to_string(rec->x1VisDstLegphi1);
	ubigint _dstRefBrlyMLeg = htonl64(rec->dstRefBrlyMLeg);
	ubigint _orgRefBrlyMLeg = htonl64(rec->orgRefBrlyMLeg);
	string _VisOrgLegphi0 = to_string(rec->VisOrgLegphi0);
	string _VisOrgLegphi1 = to_string(rec->VisOrgLegphi1);
	string _xVisDstLegphi0 = to_string(rec->xVisDstLegphi0);
	string _xVisDstLegphi1 = to_string(rec->xVisDstLegphi1);
	string _xVisOrgLegphi0 = to_string(rec->xVisOrgLegphi0);
	string _xVisOrgLegphi1 = to_string(rec->xVisOrgLegphi1);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		_x1VisDstLegphi0.c_str(),
		_x1VisDstLegphi1.c_str(),
		(char*) &_dstRefBrlyMLeg,
		(char*) &_orgRefBrlyMLeg,
		_VisOrgLegphi0.c_str(),
		_VisOrgLegphi1.c_str(),
		_xVisDstLegphi0.c_str(),
		_xVisDstLegphi1.c_str(),
		_xVisOrgLegphi0.c_str(),
		_xVisOrgLegphi1.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMLegMLeg_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLeg_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMLegMLeg::updateRst(
			ListBrlyRMLegMLeg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMLegMLeg::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMLegMLeg_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLeg_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMLegMLeg::loadRecByRef(
			ubigint ref
			, BrlyRMLegMLeg** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMLegMLeg_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMLegMLeg::loadRstByDlg(
			ubigint dstRefBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	ubigint _dstRefBrlyMLeg = htonl64(dstRefBrlyMLeg);

	const char* vals[] = {
		(char*) &_dstRefBrlyMLeg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMLegMLeg_loadRstByDlg", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMLegMLeg::loadRstByOlg(
			ubigint orgRefBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLeg& rst
		) {
	ubigint _orgRefBrlyMLeg = htonl64(orgRefBrlyMLeg);

	const char* vals[] = {
		(char*) &_orgRefBrlyMLeg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMLegMLeg_loadRstByOlg", 1, vals, l, f, append, rst);
};

