/**
  * \file BrlyRMLegMLocation.cpp
  * database access for table TblBrlyRMLegMLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyRMLegMLocation.h"

/******************************************************************************
 class BrlyRMLegMLocation
 ******************************************************************************/

BrlyRMLegMLocation::BrlyRMLegMLocation(
			const ubigint ref
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const ubigint refBrlyMLeg
			, const ubigint refBrlyMLocation
			, const double legphi
			, const double legtheta
			, const double xVisLegphi0
			, const double xVisLegphi1
		) {

	this->ref = ref;
	this->x1VisLegphi0 = x1VisLegphi0;
	this->x1VisLegphi1 = x1VisLegphi1;
	this->refBrlyMLeg = refBrlyMLeg;
	this->refBrlyMLocation = refBrlyMLocation;
	this->legphi = legphi;
	this->legtheta = legtheta;
	this->xVisLegphi0 = xVisLegphi0;
	this->xVisLegphi1 = xVisLegphi1;
};

bool BrlyRMLegMLocation::operator==(
			const BrlyRMLegMLocation& comp
		) {
	return false;
};

bool BrlyRMLegMLocation::operator!=(
			const BrlyRMLegMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyRMLegMLocation
 ******************************************************************************/

ListBrlyRMLegMLocation::ListBrlyRMLegMLocation() {
};

ListBrlyRMLegMLocation::ListBrlyRMLegMLocation(
			const ListBrlyRMLegMLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyRMLegMLocation(*(src.nodes[i]));
};

ListBrlyRMLegMLocation::~ListBrlyRMLegMLocation() {
	clear();
};

void ListBrlyRMLegMLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyRMLegMLocation::size() const {
	return(nodes.size());
};

void ListBrlyRMLegMLocation::append(
			BrlyRMLegMLocation* rec
		) {
	nodes.push_back(rec);
};

BrlyRMLegMLocation* ListBrlyRMLegMLocation::operator[](
			const uint ix
		) {
	BrlyRMLegMLocation* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyRMLegMLocation& ListBrlyRMLegMLocation::operator=(
			const ListBrlyRMLegMLocation& src
		) {
	BrlyRMLegMLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyRMLegMLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyRMLegMLocation::operator==(
			const ListBrlyRMLegMLocation& comp
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

bool ListBrlyRMLegMLocation::operator!=(
			const ListBrlyRMLegMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyRMLegMLocation
 ******************************************************************************/

TblBrlyRMLegMLocation::TblBrlyRMLegMLocation() {
};

TblBrlyRMLegMLocation::~TblBrlyRMLegMLocation() {
};

bool TblBrlyRMLegMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLegMLocation** rec
		) {
	return false;
};

ubigint TblBrlyRMLegMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	return 0;
};

void TblBrlyRMLegMLocation::insertRec(
			BrlyRMLegMLocation* rec
		) {
};

ubigint TblBrlyRMLegMLocation::insertNewRec(
			BrlyRMLegMLocation** rec
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const ubigint refBrlyMLeg
			, const ubigint refBrlyMLocation
			, const double legphi
			, const double legtheta
			, const double xVisLegphi0
			, const double xVisLegphi1
		) {
	ubigint retval = 0;
	BrlyRMLegMLocation* _rec = NULL;

	_rec = new BrlyRMLegMLocation(0, x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyRMLegMLocation::appendNewRecToRst(
			ListBrlyRMLegMLocation& rst
			, BrlyRMLegMLocation** rec
			, const double x1VisLegphi0
			, const double x1VisLegphi1
			, const ubigint refBrlyMLeg
			, const ubigint refBrlyMLocation
			, const double legphi
			, const double legtheta
			, const double xVisLegphi0
			, const double xVisLegphi1
		) {
	ubigint retval = 0;
	BrlyRMLegMLocation* _rec = NULL;

	retval = insertNewRec(&_rec, x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyRMLegMLocation::insertRst(
			ListBrlyRMLegMLocation& rst
			, bool transact
		) {
};

void TblBrlyRMLegMLocation::updateRec(
			BrlyRMLegMLocation* rec
		) {
};

void TblBrlyRMLegMLocation::updateRst(
			ListBrlyRMLegMLocation& rst
			, bool transact
		) {
};

void TblBrlyRMLegMLocation::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyRMLegMLocation::loadRecByRef(
			ubigint ref
			, BrlyRMLegMLocation** rec
		) {
	return false;
};

ubigint TblBrlyRMLegMLocation::loadRstByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	return 0;
};

ubigint TblBrlyRMLegMLocation::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	return 0;
};

ubigint TblBrlyRMLegMLocation::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	ubigint numload = 0;
	BrlyRMLegMLocation* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyRMLegMLocation
 ******************************************************************************/

MyTblBrlyRMLegMLocation::MyTblBrlyRMLegMLocation() : TblBrlyRMLegMLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyRMLegMLocation::~MyTblBrlyRMLegMLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyRMLegMLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyRMLegMLocation (x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyRMLegMLocation SET x1VisLegphi0 = ?, x1VisLegphi1 = ?, refBrlyMLeg = ?, refBrlyMLocation = ?, legphi = ?, legtheta = ?, xVisLegphi0 = ?, xVisLegphi1 = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyRMLegMLocation WHERE ref = ?", false);
};

bool MyTblBrlyRMLegMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLegMLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyRMLegMLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMLegMLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyRMLegMLocation();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1VisLegphi0 = atof((char*) dbrow[1]); else _rec->x1VisLegphi0 = 0.0;
		if (dbrow[2]) _rec->x1VisLegphi1 = atof((char*) dbrow[2]); else _rec->x1VisLegphi1 = 0.0;
		if (dbrow[3]) _rec->refBrlyMLeg = atoll((char*) dbrow[3]); else _rec->refBrlyMLeg = 0;
		if (dbrow[4]) _rec->refBrlyMLocation = atoll((char*) dbrow[4]); else _rec->refBrlyMLocation = 0;
		if (dbrow[5]) _rec->legphi = atof((char*) dbrow[5]); else _rec->legphi = 0.0;
		if (dbrow[6]) _rec->legtheta = atof((char*) dbrow[6]); else _rec->legtheta = 0.0;
		if (dbrow[7]) _rec->xVisLegphi0 = atof((char*) dbrow[7]); else _rec->xVisLegphi0 = 0.0;
		if (dbrow[8]) _rec->xVisLegphi1 = atof((char*) dbrow[8]); else _rec->xVisLegphi1 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyRMLegMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyRMLegMLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyRMLegMLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyRMLegMLocation();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1VisLegphi0 = atof((char*) dbrow[1]); else rec->x1VisLegphi0 = 0.0;
			if (dbrow[2]) rec->x1VisLegphi1 = atof((char*) dbrow[2]); else rec->x1VisLegphi1 = 0.0;
			if (dbrow[3]) rec->refBrlyMLeg = atoll((char*) dbrow[3]); else rec->refBrlyMLeg = 0;
			if (dbrow[4]) rec->refBrlyMLocation = atoll((char*) dbrow[4]); else rec->refBrlyMLocation = 0;
			if (dbrow[5]) rec->legphi = atof((char*) dbrow[5]); else rec->legphi = 0.0;
			if (dbrow[6]) rec->legtheta = atof((char*) dbrow[6]); else rec->legtheta = 0.0;
			if (dbrow[7]) rec->xVisLegphi0 = atof((char*) dbrow[7]); else rec->xVisLegphi0 = 0.0;
			if (dbrow[8]) rec->xVisLegphi1 = atof((char*) dbrow[8]); else rec->xVisLegphi1 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyRMLegMLocation::insertRec(
			BrlyRMLegMLocation* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1VisLegphi0,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1VisLegphi1,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMLeg,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMLocation,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->legphi,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->legtheta,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->xVisLegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->xVisLegphi1,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLegMLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLegMLocation / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyRMLegMLocation::insertRst(
			ListBrlyRMLegMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyRMLegMLocation::updateRec(
			BrlyRMLegMLocation* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindDouble(&rec->x1VisLegphi0,&(l[0]),&(n[0]),&(e[0])),
		bindDouble(&rec->x1VisLegphi1,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMLeg,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMLocation,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->legphi,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->legtheta,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->xVisLegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->xVisLegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLegMLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLegMLocation / stmtUpdateRec)\n");
};

void MyTblBrlyRMLegMLocation::updateRst(
			ListBrlyRMLegMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyRMLegMLocation::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyRMLegMLocation / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyRMLegMLocation / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyRMLegMLocation::loadRecByRef(
			ubigint ref
			, BrlyRMLegMLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyRMLegMLocation WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyRMLegMLocation::loadRstByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	return loadRstBySQL("SELECT ref, x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1 FROM TblBrlyRMLegMLocation WHERE refBrlyMLeg = " + to_string(refBrlyMLeg) + " ORDER BY legphi ASC", append, rst);
};

ubigint MyTblBrlyRMLegMLocation::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	return loadRstBySQL("SELECT ref, x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1 FROM TblBrlyRMLegMLocation WHERE refBrlyMLocation = " + to_string(refBrlyMLocation) + "", append, rst);
};

/******************************************************************************
 class PgTblBrlyRMLegMLocation
 ******************************************************************************/

PgTblBrlyRMLegMLocation::PgTblBrlyRMLegMLocation() : TblBrlyRMLegMLocation(), PgTable() {
};

PgTblBrlyRMLegMLocation::~PgTblBrlyRMLegMLocation() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyRMLegMLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyRMLegMLocation_insertRec", "INSERT INTO TblBrlyRMLegMLocation (x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLegMLocation_updateRec", "UPDATE TblBrlyRMLegMLocation SET x1VisLegphi0 = $1, x1VisLegphi1 = $2, refBrlyMLeg = $3, refBrlyMLocation = $4, legphi = $5, legtheta = $6, xVisLegphi0 = $7, xVisLegphi1 = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLegMLocation_removeRecByRef", "DELETE FROM TblBrlyRMLegMLocation WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyRMLegMLocation_loadRecByRef", "SELECT ref, x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1 FROM TblBrlyRMLegMLocation WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyRMLegMLocation_loadRstByLeg", "SELECT ref, x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1 FROM TblBrlyRMLegMLocation WHERE refBrlyMLeg = $1 ORDER BY legphi ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyRMLegMLocation_loadRstByLoc", "SELECT ref, x1VisLegphi0, x1VisLegphi1, refBrlyMLeg, refBrlyMLocation, legphi, legtheta, xVisLegphi0, xVisLegphi1 FROM TblBrlyRMLegMLocation WHERE refBrlyMLocation = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyRMLegMLocation::loadRec(
			PGresult* res
			, BrlyRMLegMLocation** rec
		) {
	char* ptr;

	BrlyRMLegMLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyRMLegMLocation();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1vislegphi0"),
			PQfnumber(res, "x1vislegphi1"),
			PQfnumber(res, "refbrlymleg"),
			PQfnumber(res, "refbrlymlocation"),
			PQfnumber(res, "legphi"),
			PQfnumber(res, "legtheta"),
			PQfnumber(res, "xvislegphi0"),
			PQfnumber(res, "xvislegphi1")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1VisLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1VisLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refBrlyMLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->legphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->legtheta = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->xVisLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->xVisLegphi1 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyRMLegMLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyRMLegMLocation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1vislegphi0"),
			PQfnumber(res, "x1vislegphi1"),
			PQfnumber(res, "refbrlymleg"),
			PQfnumber(res, "refbrlymlocation"),
			PQfnumber(res, "legphi"),
			PQfnumber(res, "legtheta"),
			PQfnumber(res, "xvislegphi0"),
			PQfnumber(res, "xvislegphi1")
		};

		while (numread < numrow) {
			rec = new BrlyRMLegMLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1VisLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1VisLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refBrlyMLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->legphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->legtheta = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->xVisLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->xVisLegphi1 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyRMLegMLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyRMLegMLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMLegMLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyRMLegMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyRMLegMLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyRMLegMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyRMLegMLocation::insertRec(
			BrlyRMLegMLocation* rec
		) {
	PGresult* res;
	char* ptr;

	string _x1VisLegphi0 = to_string(rec->x1VisLegphi0);
	string _x1VisLegphi1 = to_string(rec->x1VisLegphi1);
	ubigint _refBrlyMLeg = htonl64(rec->refBrlyMLeg);
	ubigint _refBrlyMLocation = htonl64(rec->refBrlyMLocation);
	string _legphi = to_string(rec->legphi);
	string _legtheta = to_string(rec->legtheta);
	string _xVisLegphi0 = to_string(rec->xVisLegphi0);
	string _xVisLegphi1 = to_string(rec->xVisLegphi1);

	const char* vals[] = {
		_x1VisLegphi0.c_str(),
		_x1VisLegphi1.c_str(),
		(char*) &_refBrlyMLeg,
		(char*) &_refBrlyMLocation,
		_legphi.c_str(),
		_legtheta.c_str(),
		_xVisLegphi0.c_str(),
		_xVisLegphi1.c_str()
	};
	const int l[] = {
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {0, 0, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyRMLegMLocation_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyRMLegMLocation::insertRst(
			ListBrlyRMLegMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyRMLegMLocation::updateRec(
			BrlyRMLegMLocation* rec
		) {
	PGresult* res;

	string _x1VisLegphi0 = to_string(rec->x1VisLegphi0);
	string _x1VisLegphi1 = to_string(rec->x1VisLegphi1);
	ubigint _refBrlyMLeg = htonl64(rec->refBrlyMLeg);
	ubigint _refBrlyMLocation = htonl64(rec->refBrlyMLocation);
	string _legphi = to_string(rec->legphi);
	string _legtheta = to_string(rec->legtheta);
	string _xVisLegphi0 = to_string(rec->xVisLegphi0);
	string _xVisLegphi1 = to_string(rec->xVisLegphi1);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		_x1VisLegphi0.c_str(),
		_x1VisLegphi1.c_str(),
		(char*) &_refBrlyMLeg,
		(char*) &_refBrlyMLocation,
		_legphi.c_str(),
		_legtheta.c_str(),
		_xVisLegphi0.c_str(),
		_xVisLegphi1.c_str(),
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
		sizeof(ubigint)
	};
	const int f[] = {0, 0, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyRMLegMLocation_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyRMLegMLocation::updateRst(
			ListBrlyRMLegMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyRMLegMLocation::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyRMLegMLocation_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyRMLegMLocation_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyRMLegMLocation::loadRecByRef(
			ubigint ref
			, BrlyRMLegMLocation** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyRMLegMLocation_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyRMLegMLocation::loadRstByLeg(
			ubigint refBrlyMLeg
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	ubigint _refBrlyMLeg = htonl64(refBrlyMLeg);

	const char* vals[] = {
		(char*) &_refBrlyMLeg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMLegMLocation_loadRstByLeg", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyRMLegMLocation::loadRstByLoc(
			ubigint refBrlyMLocation
			, const bool append
			, ListBrlyRMLegMLocation& rst
		) {
	ubigint _refBrlyMLocation = htonl64(refBrlyMLocation);

	const char* vals[] = {
		(char*) &_refBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyRMLegMLocation_loadRstByLoc", 1, vals, l, f, append, rst);
};

