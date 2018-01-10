/**
  * \file BrlyMSegment.cpp
  * database access for table TblBrlyMSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMSegment.h"

#include "BrlyMSegment_vecs.cpp"

/******************************************************************************
 class BrlyMSegment
 ******************************************************************************/

BrlyMSegment::BrlyMSegment(
			const ubigint ref
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const double deltaphi
			, const double alt0
			, const double alt1
			, const double theta0
			, const double theta1
			, const double phi0
			, const double phi1
			, const uint start
			, const uint stop
			, const bool Calcdone
		) {

	this->ref = ref;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->refNum = refNum;
	this->deltaphi = deltaphi;
	this->alt0 = alt0;
	this->alt1 = alt1;
	this->theta0 = theta0;
	this->theta1 = theta1;
	this->phi0 = phi0;
	this->phi1 = phi1;
	this->start = start;
	this->stop = stop;
	this->Calcdone = Calcdone;
};

bool BrlyMSegment::operator==(
			const BrlyMSegment& comp
		) {
	return false;
};

bool BrlyMSegment::operator!=(
			const BrlyMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMSegment
 ******************************************************************************/

ListBrlyMSegment::ListBrlyMSegment() {
};

ListBrlyMSegment::ListBrlyMSegment(
			const ListBrlyMSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMSegment(*(src.nodes[i]));
};

ListBrlyMSegment::~ListBrlyMSegment() {
	clear();
};

void ListBrlyMSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMSegment::size() const {
	return(nodes.size());
};

void ListBrlyMSegment::append(
			BrlyMSegment* rec
		) {
	nodes.push_back(rec);
};

BrlyMSegment* ListBrlyMSegment::operator[](
			const uint ix
		) {
	BrlyMSegment* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMSegment& ListBrlyMSegment::operator=(
			const ListBrlyMSegment& src
		) {
	BrlyMSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMSegment::operator==(
			const ListBrlyMSegment& comp
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

bool ListBrlyMSegment::operator!=(
			const ListBrlyMSegment& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMSegment
 ******************************************************************************/

TblBrlyMSegment::TblBrlyMSegment() {
};

TblBrlyMSegment::~TblBrlyMSegment() {
};

bool TblBrlyMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyMSegment** rec
		) {
	return false;
};

ubigint TblBrlyMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMSegment& rst
		) {
	return 0;
};

void TblBrlyMSegment::insertRec(
			BrlyMSegment* rec
		) {
};

ubigint TblBrlyMSegment::insertNewRec(
			BrlyMSegment** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const double deltaphi
			, const double alt0
			, const double alt1
			, const double theta0
			, const double theta1
			, const double phi0
			, const double phi1
			, const uint start
			, const uint stop
			, const bool Calcdone
		) {
	ubigint retval = 0;
	BrlyMSegment* _rec = NULL;

	_rec = new BrlyMSegment(0, refIxVTbl, refUref, refNum, deltaphi, alt0, alt1, theta0, theta1, phi0, phi1, start, stop, Calcdone);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMSegment::appendNewRecToRst(
			ListBrlyMSegment& rst
			, BrlyMSegment** rec
			, const uint refIxVTbl
			, const ubigint refUref
			, const uint refNum
			, const double deltaphi
			, const double alt0
			, const double alt1
			, const double theta0
			, const double theta1
			, const double phi0
			, const double phi1
			, const uint start
			, const uint stop
			, const bool Calcdone
		) {
	ubigint retval = 0;
	BrlyMSegment* _rec = NULL;

	retval = insertNewRec(&_rec, refIxVTbl, refUref, refNum, deltaphi, alt0, alt1, theta0, theta1, phi0, phi1, start, stop, Calcdone);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMSegment::insertRst(
			ListBrlyMSegment& rst
			, bool transact
		) {
};

void TblBrlyMSegment::updateRec(
			BrlyMSegment* rec
		) {
};

void TblBrlyMSegment::updateRst(
			ListBrlyMSegment& rst
			, bool transact
		) {
};

void TblBrlyMSegment::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMSegment::loadRecByRef(
			ubigint ref
			, BrlyMSegment** rec
		) {
	return false;
};

ubigint TblBrlyMSegment::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListBrlyMSegment& rst
		) {
	return 0;
};

ubigint TblBrlyMSegment::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMSegment& rst
		) {
	ubigint numload = 0;
	BrlyMSegment* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMSegment
 ******************************************************************************/

MyTblBrlyMSegment::MyTblBrlyMSegment() : TblBrlyMSegment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMSegment::~MyTblBrlyMSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMSegment (refIxVTbl, refUref, refNum, deltaphi, alt0, alt1, theta0, theta1, phi0, phi1, start, stop, Calcdone) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMSegment SET refIxVTbl = ?, refUref = ?, refNum = ?, deltaphi = ?, alt0 = ?, alt1 = ?, theta0 = ?, theta1 = ?, phi0 = ?, phi1 = ?, start = ?, stop = ?, Calcdone = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMSegment WHERE ref = ?", false);
};

bool MyTblBrlyMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyMSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMSegment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyMSegment();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refIxVTbl = atol((char*) dbrow[1]); else _rec->refIxVTbl = 0;
		if (dbrow[2]) _rec->refUref = atoll((char*) dbrow[2]); else _rec->refUref = 0;
		if (dbrow[3]) _rec->refNum = atol((char*) dbrow[3]); else _rec->refNum = 0;
		if (dbrow[4]) _rec->deltaphi = atof((char*) dbrow[4]); else _rec->deltaphi = 0.0;
		if (dbrow[5]) _rec->alt0 = atof((char*) dbrow[5]); else _rec->alt0 = 0.0;
		if (dbrow[6]) _rec->alt1 = atof((char*) dbrow[6]); else _rec->alt1 = 0.0;
		if (dbrow[7]) _rec->theta0 = atof((char*) dbrow[7]); else _rec->theta0 = 0.0;
		if (dbrow[8]) _rec->theta1 = atof((char*) dbrow[8]); else _rec->theta1 = 0.0;
		if (dbrow[9]) _rec->phi0 = atof((char*) dbrow[9]); else _rec->phi0 = 0.0;
		if (dbrow[10]) _rec->phi1 = atof((char*) dbrow[10]); else _rec->phi1 = 0.0;
		if (dbrow[11]) _rec->start = atol((char*) dbrow[11]); else _rec->start = 0;
		if (dbrow[12]) _rec->stop = atol((char*) dbrow[12]); else _rec->stop = 0;
		if (dbrow[13]) _rec->Calcdone = (atoi((char*) dbrow[13]) != 0); else _rec->Calcdone = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMSegment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyMSegment();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refIxVTbl = atol((char*) dbrow[1]); else rec->refIxVTbl = 0;
			if (dbrow[2]) rec->refUref = atoll((char*) dbrow[2]); else rec->refUref = 0;
			if (dbrow[3]) rec->refNum = atol((char*) dbrow[3]); else rec->refNum = 0;
			if (dbrow[4]) rec->deltaphi = atof((char*) dbrow[4]); else rec->deltaphi = 0.0;
			if (dbrow[5]) rec->alt0 = atof((char*) dbrow[5]); else rec->alt0 = 0.0;
			if (dbrow[6]) rec->alt1 = atof((char*) dbrow[6]); else rec->alt1 = 0.0;
			if (dbrow[7]) rec->theta0 = atof((char*) dbrow[7]); else rec->theta0 = 0.0;
			if (dbrow[8]) rec->theta1 = atof((char*) dbrow[8]); else rec->theta1 = 0.0;
			if (dbrow[9]) rec->phi0 = atof((char*) dbrow[9]); else rec->phi0 = 0.0;
			if (dbrow[10]) rec->phi1 = atof((char*) dbrow[10]); else rec->phi1 = 0.0;
			if (dbrow[11]) rec->start = atol((char*) dbrow[11]); else rec->start = 0;
			if (dbrow[12]) rec->stop = atol((char*) dbrow[12]); else rec->stop = 0;
			if (dbrow[13]) rec->Calcdone = (atoi((char*) dbrow[13]) != 0); else rec->Calcdone = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMSegment::insertRec(
			BrlyMSegment* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	tinyint Calcdone = rec->Calcdone;

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refNum,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->deltaphi,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->alt0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->alt1,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->theta0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->theta1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->phi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->phi1,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->start,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->stop,&(l[11]),&(n[11]),&(e[11])),
		bindTinyint(&Calcdone,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMSegment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMSegment / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMSegment::insertRst(
			ListBrlyMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMSegment::updateRec(
			BrlyMSegment* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	tinyint Calcdone = rec->Calcdone;

	MYSQL_BIND bind[] = {
		bindUint(&rec->refIxVTbl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refUref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->refNum,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->deltaphi,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->alt0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->alt1,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->theta0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->theta1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->phi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->phi1,&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->start,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->stop,&(l[11]),&(n[11]),&(e[11])),
		bindTinyint(&Calcdone,&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->ref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMSegment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMSegment / stmtUpdateRec)\n");
};

void MyTblBrlyMSegment::updateRst(
			ListBrlyMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMSegment::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMSegment / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMSegment / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMSegment::loadRecByRef(
			ubigint ref
			, BrlyMSegment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMSegment WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyMSegment::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListBrlyMSegment& rst
		) {
	return loadRstBySQL("SELECT ref, refIxVTbl, refUref, refNum, deltaphi, alt0, alt1, theta0, theta1, phi0, phi1, start, stop, Calcdone FROM TblBrlyMSegment WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY refNum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyMSegment
 ******************************************************************************/

PgTblBrlyMSegment::PgTblBrlyMSegment() : TblBrlyMSegment(), PgTable() {
};

PgTblBrlyMSegment::~PgTblBrlyMSegment() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMSegment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMSegment_insertRec", "INSERT INTO TblBrlyMSegment (refIxVTbl, refUref, refNum, deltaphi, alt0, alt1, theta0, theta1, phi0, phi1, start, stop, Calcdone) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING ref", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMSegment_updateRec", "UPDATE TblBrlyMSegment SET refIxVTbl = $1, refUref = $2, refNum = $3, deltaphi = $4, alt0 = $5, alt1 = $6, theta0 = $7, theta1 = $8, phi0 = $9, phi1 = $10, start = $11, stop = $12, Calcdone = $13 WHERE ref = $14", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMSegment_removeRecByRef", "DELETE FROM TblBrlyMSegment WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMSegment_loadRecByRef", "SELECT ref, refIxVTbl, refUref, refNum, deltaphi, alt0, alt1, theta0, theta1, phi0, phi1, start, stop, Calcdone FROM TblBrlyMSegment WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMSegment_loadRstByRetReu", "SELECT ref, refIxVTbl, refUref, refNum, deltaphi, alt0, alt1, theta0, theta1, phi0, phi1, start, stop, Calcdone FROM TblBrlyMSegment WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY refNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMSegment::loadRec(
			PGresult* res
			, BrlyMSegment** rec
		) {
	char* ptr;

	BrlyMSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMSegment();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refnum"),
			PQfnumber(res, "deltaphi"),
			PQfnumber(res, "alt0"),
			PQfnumber(res, "alt1"),
			PQfnumber(res, "theta0"),
			PQfnumber(res, "theta1"),
			PQfnumber(res, "phi0"),
			PQfnumber(res, "phi1"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "calcdone")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->deltaphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->alt0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->alt1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->theta0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->theta1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->phi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->phi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Calcdone = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMSegment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMSegment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "refnum"),
			PQfnumber(res, "deltaphi"),
			PQfnumber(res, "alt0"),
			PQfnumber(res, "alt1"),
			PQfnumber(res, "theta0"),
			PQfnumber(res, "theta1"),
			PQfnumber(res, "phi0"),
			PQfnumber(res, "phi1"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "calcdone")
		};

		while (numread < numrow) {
			rec = new BrlyMSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->deltaphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->alt0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->alt1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->theta0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->theta1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->phi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->phi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Calcdone = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSegment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSegment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyMSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMSegment::insertRec(
			BrlyMSegment* rec
		) {
	PGresult* res;
	char* ptr;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _refNum = htonl(rec->refNum);
	string _deltaphi = to_string(rec->deltaphi);
	string _alt0 = to_string(rec->alt0);
	string _alt1 = to_string(rec->alt1);
	string _theta0 = to_string(rec->theta0);
	string _theta1 = to_string(rec->theta1);
	string _phi0 = to_string(rec->phi0);
	string _phi1 = to_string(rec->phi1);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	smallint _Calcdone = htons((smallint) rec->Calcdone);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refNum,
		_deltaphi.c_str(),
		_alt0.c_str(),
		_alt1.c_str(),
		_theta0.c_str(),
		_theta1.c_str(),
		_phi0.c_str(),
		_phi1.c_str(),
		(char*) &_start,
		(char*) &_stop,
		(char*) &_Calcdone
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMSegment_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSegment_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMSegment::insertRst(
			ListBrlyMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMSegment::updateRec(
			BrlyMSegment* rec
		) {
	PGresult* res;

	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _refNum = htonl(rec->refNum);
	string _deltaphi = to_string(rec->deltaphi);
	string _alt0 = to_string(rec->alt0);
	string _alt1 = to_string(rec->alt1);
	string _theta0 = to_string(rec->theta0);
	string _theta1 = to_string(rec->theta1);
	string _phi0 = to_string(rec->phi0);
	string _phi1 = to_string(rec->phi1);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	smallint _Calcdone = htons((smallint) rec->Calcdone);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		(char*) &_refNum,
		_deltaphi.c_str(),
		_alt0.c_str(),
		_alt1.c_str(),
		_theta0.c_str(),
		_theta1.c_str(),
		_phi0.c_str(),
		_phi1.c_str(),
		(char*) &_start,
		(char*) &_stop,
		(char*) &_Calcdone,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMSegment_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSegment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMSegment::updateRst(
			ListBrlyMSegment& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMSegment::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMSegment_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMSegment_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMSegment::loadRecByRef(
			ubigint ref
			, BrlyMSegment** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMSegment_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyMSegment::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListBrlyMSegment& rst
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblBrlyMSegment_loadRstByRetReu", 2, vals, l, f, append, rst);
};

