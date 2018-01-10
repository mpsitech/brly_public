/**
  * \file BrlyProxRMLocationMLocation.cpp
  * database access for table TblBrlyProxRMLocationMLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyProxRMLocationMLocation.h"

/******************************************************************************
 class BrlyProxRMLocationMLocation
 ******************************************************************************/

BrlyProxRMLocationMLocation::BrlyProxRMLocationMLocation(
			const ubigint ref
			, const ubigint dstRefBrlyMLocation
			, const ubigint orgRefBrlyMLocation
			, const double deltaphi
		) {

	this->ref = ref;
	this->dstRefBrlyMLocation = dstRefBrlyMLocation;
	this->orgRefBrlyMLocation = orgRefBrlyMLocation;
	this->deltaphi = deltaphi;
};

bool BrlyProxRMLocationMLocation::operator==(
			const BrlyProxRMLocationMLocation& comp
		) {
	return false;
};

bool BrlyProxRMLocationMLocation::operator!=(
			const BrlyProxRMLocationMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyProxRMLocationMLocation
 ******************************************************************************/

ListBrlyProxRMLocationMLocation::ListBrlyProxRMLocationMLocation() {
};

ListBrlyProxRMLocationMLocation::ListBrlyProxRMLocationMLocation(
			const ListBrlyProxRMLocationMLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyProxRMLocationMLocation(*(src.nodes[i]));
};

ListBrlyProxRMLocationMLocation::~ListBrlyProxRMLocationMLocation() {
	clear();
};

void ListBrlyProxRMLocationMLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyProxRMLocationMLocation::size() const {
	return(nodes.size());
};

void ListBrlyProxRMLocationMLocation::append(
			BrlyProxRMLocationMLocation* rec
		) {
	nodes.push_back(rec);
};

BrlyProxRMLocationMLocation* ListBrlyProxRMLocationMLocation::operator[](
			const uint ix
		) {
	BrlyProxRMLocationMLocation* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyProxRMLocationMLocation& ListBrlyProxRMLocationMLocation::operator=(
			const ListBrlyProxRMLocationMLocation& src
		) {
	BrlyProxRMLocationMLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyProxRMLocationMLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyProxRMLocationMLocation::operator==(
			const ListBrlyProxRMLocationMLocation& comp
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

bool ListBrlyProxRMLocationMLocation::operator!=(
			const ListBrlyProxRMLocationMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyProxRMLocationMLocation
 ******************************************************************************/

TblBrlyProxRMLocationMLocation::TblBrlyProxRMLocationMLocation() {
};

TblBrlyProxRMLocationMLocation::~TblBrlyProxRMLocationMLocation() {
};

bool TblBrlyProxRMLocationMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyProxRMLocationMLocation** rec
		) {
	return false;
};

ubigint TblBrlyProxRMLocationMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	return 0;
};

void TblBrlyProxRMLocationMLocation::insertRec(
			BrlyProxRMLocationMLocation* rec
		) {
};

ubigint TblBrlyProxRMLocationMLocation::insertNewRec(
			BrlyProxRMLocationMLocation** rec
			, const ubigint dstRefBrlyMLocation
			, const ubigint orgRefBrlyMLocation
			, const double deltaphi
		) {
	ubigint retval = 0;
	BrlyProxRMLocationMLocation* _rec = NULL;

	_rec = new BrlyProxRMLocationMLocation(0, dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyProxRMLocationMLocation::appendNewRecToRst(
			ListBrlyProxRMLocationMLocation& rst
			, BrlyProxRMLocationMLocation** rec
			, const ubigint dstRefBrlyMLocation
			, const ubigint orgRefBrlyMLocation
			, const double deltaphi
		) {
	ubigint retval = 0;
	BrlyProxRMLocationMLocation* _rec = NULL;

	retval = insertNewRec(&_rec, dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyProxRMLocationMLocation::insertRst(
			ListBrlyProxRMLocationMLocation& rst
			, bool transact
		) {
};

void TblBrlyProxRMLocationMLocation::updateRec(
			BrlyProxRMLocationMLocation* rec
		) {
};

void TblBrlyProxRMLocationMLocation::updateRst(
			ListBrlyProxRMLocationMLocation& rst
			, bool transact
		) {
};

void TblBrlyProxRMLocationMLocation::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyProxRMLocationMLocation::loadRecByRef(
			ubigint ref
			, BrlyProxRMLocationMLocation** rec
		) {
	return false;
};

ubigint TblBrlyProxRMLocationMLocation::loadRstByDlo(
			ubigint dstRefBrlyMLocation
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	return 0;
};

ubigint TblBrlyProxRMLocationMLocation::loadRstByOlo(
			ubigint orgRefBrlyMLocation
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	return 0;
};

ubigint TblBrlyProxRMLocationMLocation::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	ubigint numload = 0;
	BrlyProxRMLocationMLocation* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyProxRMLocationMLocation
 ******************************************************************************/

MyTblBrlyProxRMLocationMLocation::MyTblBrlyProxRMLocationMLocation() : TblBrlyProxRMLocationMLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyProxRMLocationMLocation::~MyTblBrlyProxRMLocationMLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyProxRMLocationMLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyProxRMLocationMLocation (dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyProxRMLocationMLocation SET dstRefBrlyMLocation = ?, orgRefBrlyMLocation = ?, deltaphi = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyProxRMLocationMLocation WHERE ref = ?", false);
};

bool MyTblBrlyProxRMLocationMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyProxRMLocationMLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyProxRMLocationMLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyProxRMLocationMLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyProxRMLocationMLocation();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->dstRefBrlyMLocation = atoll((char*) dbrow[1]); else _rec->dstRefBrlyMLocation = 0;
		if (dbrow[2]) _rec->orgRefBrlyMLocation = atoll((char*) dbrow[2]); else _rec->orgRefBrlyMLocation = 0;
		if (dbrow[3]) _rec->deltaphi = atof((char*) dbrow[3]); else _rec->deltaphi = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyProxRMLocationMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyProxRMLocationMLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyProxRMLocationMLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyProxRMLocationMLocation();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->dstRefBrlyMLocation = atoll((char*) dbrow[1]); else rec->dstRefBrlyMLocation = 0;
			if (dbrow[2]) rec->orgRefBrlyMLocation = atoll((char*) dbrow[2]); else rec->orgRefBrlyMLocation = 0;
			if (dbrow[3]) rec->deltaphi = atof((char*) dbrow[3]); else rec->deltaphi = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyProxRMLocationMLocation::insertRec(
			BrlyProxRMLocationMLocation* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->dstRefBrlyMLocation,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->orgRefBrlyMLocation,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->deltaphi,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyProxRMLocationMLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyProxRMLocationMLocation / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyProxRMLocationMLocation::insertRst(
			ListBrlyProxRMLocationMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyProxRMLocationMLocation::updateRec(
			BrlyProxRMLocationMLocation* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->dstRefBrlyMLocation,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->orgRefBrlyMLocation,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->deltaphi,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyProxRMLocationMLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyProxRMLocationMLocation / stmtUpdateRec)\n");
};

void MyTblBrlyProxRMLocationMLocation::updateRst(
			ListBrlyProxRMLocationMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyProxRMLocationMLocation::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyProxRMLocationMLocation / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyProxRMLocationMLocation / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyProxRMLocationMLocation::loadRecByRef(
			ubigint ref
			, BrlyProxRMLocationMLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyProxRMLocationMLocation WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyProxRMLocationMLocation::loadRstByDlo(
			ubigint dstRefBrlyMLocation
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	return loadRstBySQL("SELECT ref, dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi FROM TblBrlyProxRMLocationMLocation WHERE dstRefBrlyMLocation = " + to_string(dstRefBrlyMLocation) + "", append, rst);
};

ubigint MyTblBrlyProxRMLocationMLocation::loadRstByOlo(
			ubigint orgRefBrlyMLocation
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	return loadRstBySQL("SELECT ref, dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi FROM TblBrlyProxRMLocationMLocation WHERE orgRefBrlyMLocation = " + to_string(orgRefBrlyMLocation) + "", append, rst);
};

/******************************************************************************
 class PgTblBrlyProxRMLocationMLocation
 ******************************************************************************/

PgTblBrlyProxRMLocationMLocation::PgTblBrlyProxRMLocationMLocation() : TblBrlyProxRMLocationMLocation(), PgTable() {
};

PgTblBrlyProxRMLocationMLocation::~PgTblBrlyProxRMLocationMLocation() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyProxRMLocationMLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyProxRMLocationMLocation_insertRec", "INSERT INTO TblBrlyProxRMLocationMLocation (dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyProxRMLocationMLocation_updateRec", "UPDATE TblBrlyProxRMLocationMLocation SET dstRefBrlyMLocation = $1, orgRefBrlyMLocation = $2, deltaphi = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyProxRMLocationMLocation_removeRecByRef", "DELETE FROM TblBrlyProxRMLocationMLocation WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyProxRMLocationMLocation_loadRecByRef", "SELECT ref, dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi FROM TblBrlyProxRMLocationMLocation WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyProxRMLocationMLocation_loadRstByDlo", "SELECT ref, dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi FROM TblBrlyProxRMLocationMLocation WHERE dstRefBrlyMLocation = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyProxRMLocationMLocation_loadRstByOlo", "SELECT ref, dstRefBrlyMLocation, orgRefBrlyMLocation, deltaphi FROM TblBrlyProxRMLocationMLocation WHERE orgRefBrlyMLocation = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyProxRMLocationMLocation::loadRec(
			PGresult* res
			, BrlyProxRMLocationMLocation** rec
		) {
	char* ptr;

	BrlyProxRMLocationMLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyProxRMLocationMLocation();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "dstrefbrlymlocation"),
			PQfnumber(res, "orgrefbrlymlocation"),
			PQfnumber(res, "deltaphi")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->dstRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->orgRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->deltaphi = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyProxRMLocationMLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyProxRMLocationMLocation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "dstrefbrlymlocation"),
			PQfnumber(res, "orgrefbrlymlocation"),
			PQfnumber(res, "deltaphi")
		};

		while (numread < numrow) {
			rec = new BrlyProxRMLocationMLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->dstRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->orgRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->deltaphi = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyProxRMLocationMLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyProxRMLocationMLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyProxRMLocationMLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyProxRMLocationMLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyProxRMLocationMLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyProxRMLocationMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyProxRMLocationMLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyProxRMLocationMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyProxRMLocationMLocation::insertRec(
			BrlyProxRMLocationMLocation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _dstRefBrlyMLocation = htonl64(rec->dstRefBrlyMLocation);
	ubigint _orgRefBrlyMLocation = htonl64(rec->orgRefBrlyMLocation);
	string _deltaphi = to_string(rec->deltaphi);

	const char* vals[] = {
		(char*) &_dstRefBrlyMLocation,
		(char*) &_orgRefBrlyMLocation,
		_deltaphi.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyProxRMLocationMLocation_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyProxRMLocationMLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyProxRMLocationMLocation::insertRst(
			ListBrlyProxRMLocationMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyProxRMLocationMLocation::updateRec(
			BrlyProxRMLocationMLocation* rec
		) {
	PGresult* res;

	ubigint _dstRefBrlyMLocation = htonl64(rec->dstRefBrlyMLocation);
	ubigint _orgRefBrlyMLocation = htonl64(rec->orgRefBrlyMLocation);
	string _deltaphi = to_string(rec->deltaphi);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_dstRefBrlyMLocation,
		(char*) &_orgRefBrlyMLocation,
		_deltaphi.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyProxRMLocationMLocation_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyProxRMLocationMLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyProxRMLocationMLocation::updateRst(
			ListBrlyProxRMLocationMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyProxRMLocationMLocation::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyProxRMLocationMLocation_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyProxRMLocationMLocation_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyProxRMLocationMLocation::loadRecByRef(
			ubigint ref
			, BrlyProxRMLocationMLocation** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyProxRMLocationMLocation_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyProxRMLocationMLocation::loadRstByDlo(
			ubigint dstRefBrlyMLocation
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	ubigint _dstRefBrlyMLocation = htonl64(dstRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_dstRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyProxRMLocationMLocation_loadRstByDlo", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyProxRMLocationMLocation::loadRstByOlo(
			ubigint orgRefBrlyMLocation
			, const bool append
			, ListBrlyProxRMLocationMLocation& rst
		) {
	ubigint _orgRefBrlyMLocation = htonl64(orgRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_orgRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyProxRMLocationMLocation_loadRstByOlo", 1, vals, l, f, append, rst);
};

