/**
  * \file BrlyVisRMLocationMLocation.cpp
  * database access for table TblBrlyVisRMLocationMLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyVisRMLocationMLocation.h"

/******************************************************************************
 class BrlyVisRMLocationMLocation
 ******************************************************************************/

BrlyVisRMLocationMLocation::BrlyVisRMLocationMLocation(
			const ubigint ref
			, const ubigint dstRefBrlyMLocation
			, const ubigint orgRefBrlyMLocation
		) {

	this->ref = ref;
	this->dstRefBrlyMLocation = dstRefBrlyMLocation;
	this->orgRefBrlyMLocation = orgRefBrlyMLocation;
};

bool BrlyVisRMLocationMLocation::operator==(
			const BrlyVisRMLocationMLocation& comp
		) {
	return false;
};

bool BrlyVisRMLocationMLocation::operator!=(
			const BrlyVisRMLocationMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyVisRMLocationMLocation
 ******************************************************************************/

ListBrlyVisRMLocationMLocation::ListBrlyVisRMLocationMLocation() {
};

ListBrlyVisRMLocationMLocation::ListBrlyVisRMLocationMLocation(
			const ListBrlyVisRMLocationMLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyVisRMLocationMLocation(*(src.nodes[i]));
};

ListBrlyVisRMLocationMLocation::~ListBrlyVisRMLocationMLocation() {
	clear();
};

void ListBrlyVisRMLocationMLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyVisRMLocationMLocation::size() const {
	return(nodes.size());
};

void ListBrlyVisRMLocationMLocation::append(
			BrlyVisRMLocationMLocation* rec
		) {
	nodes.push_back(rec);
};

BrlyVisRMLocationMLocation* ListBrlyVisRMLocationMLocation::operator[](
			const uint ix
		) {
	BrlyVisRMLocationMLocation* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyVisRMLocationMLocation& ListBrlyVisRMLocationMLocation::operator=(
			const ListBrlyVisRMLocationMLocation& src
		) {
	BrlyVisRMLocationMLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyVisRMLocationMLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyVisRMLocationMLocation::operator==(
			const ListBrlyVisRMLocationMLocation& comp
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

bool ListBrlyVisRMLocationMLocation::operator!=(
			const ListBrlyVisRMLocationMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyVisRMLocationMLocation
 ******************************************************************************/

TblBrlyVisRMLocationMLocation::TblBrlyVisRMLocationMLocation() {
};

TblBrlyVisRMLocationMLocation::~TblBrlyVisRMLocationMLocation() {
};

bool TblBrlyVisRMLocationMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyVisRMLocationMLocation** rec
		) {
	return false;
};

ubigint TblBrlyVisRMLocationMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyVisRMLocationMLocation& rst
		) {
	return 0;
};

void TblBrlyVisRMLocationMLocation::insertRec(
			BrlyVisRMLocationMLocation* rec
		) {
};

ubigint TblBrlyVisRMLocationMLocation::insertNewRec(
			BrlyVisRMLocationMLocation** rec
			, const ubigint dstRefBrlyMLocation
			, const ubigint orgRefBrlyMLocation
		) {
	ubigint retval = 0;
	BrlyVisRMLocationMLocation* _rec = NULL;

	_rec = new BrlyVisRMLocationMLocation(0, dstRefBrlyMLocation, orgRefBrlyMLocation);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyVisRMLocationMLocation::appendNewRecToRst(
			ListBrlyVisRMLocationMLocation& rst
			, BrlyVisRMLocationMLocation** rec
			, const ubigint dstRefBrlyMLocation
			, const ubigint orgRefBrlyMLocation
		) {
	ubigint retval = 0;
	BrlyVisRMLocationMLocation* _rec = NULL;

	retval = insertNewRec(&_rec, dstRefBrlyMLocation, orgRefBrlyMLocation);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyVisRMLocationMLocation::insertRst(
			ListBrlyVisRMLocationMLocation& rst
			, bool transact
		) {
};

void TblBrlyVisRMLocationMLocation::updateRec(
			BrlyVisRMLocationMLocation* rec
		) {
};

void TblBrlyVisRMLocationMLocation::updateRst(
			ListBrlyVisRMLocationMLocation& rst
			, bool transact
		) {
};

void TblBrlyVisRMLocationMLocation::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyVisRMLocationMLocation::loadRecByRef(
			ubigint ref
			, BrlyVisRMLocationMLocation** rec
		) {
	return false;
};

ubigint TblBrlyVisRMLocationMLocation::loadDlosByOlo(
			ubigint orgRefBrlyMLocation
			, const bool append
			, vector<ubigint>& dstRefBrlyMLocations
		) {
	return 0;
};

ubigint TblBrlyVisRMLocationMLocation::loadOlosByDlo(
			ubigint dstRefBrlyMLocation
			, const bool append
			, vector<ubigint>& orgRefBrlyMLocations
		) {
	return 0;
};

ubigint TblBrlyVisRMLocationMLocation::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyVisRMLocationMLocation& rst
		) {
	ubigint numload = 0;
	BrlyVisRMLocationMLocation* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyVisRMLocationMLocation
 ******************************************************************************/

MyTblBrlyVisRMLocationMLocation::MyTblBrlyVisRMLocationMLocation() : TblBrlyVisRMLocationMLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyVisRMLocationMLocation::~MyTblBrlyVisRMLocationMLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyVisRMLocationMLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyVisRMLocationMLocation (dstRefBrlyMLocation, orgRefBrlyMLocation) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyVisRMLocationMLocation SET dstRefBrlyMLocation = ?, orgRefBrlyMLocation = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyVisRMLocationMLocation WHERE ref = ?", false);
};

bool MyTblBrlyVisRMLocationMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyVisRMLocationMLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyVisRMLocationMLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyVisRMLocationMLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyVisRMLocationMLocation();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->dstRefBrlyMLocation = atoll((char*) dbrow[1]); else _rec->dstRefBrlyMLocation = 0;
		if (dbrow[2]) _rec->orgRefBrlyMLocation = atoll((char*) dbrow[2]); else _rec->orgRefBrlyMLocation = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyVisRMLocationMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyVisRMLocationMLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyVisRMLocationMLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyVisRMLocationMLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyVisRMLocationMLocation();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->dstRefBrlyMLocation = atoll((char*) dbrow[1]); else rec->dstRefBrlyMLocation = 0;
			if (dbrow[2]) rec->orgRefBrlyMLocation = atoll((char*) dbrow[2]); else rec->orgRefBrlyMLocation = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyVisRMLocationMLocation::insertRec(
			BrlyVisRMLocationMLocation* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->dstRefBrlyMLocation,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->orgRefBrlyMLocation,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyVisRMLocationMLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyVisRMLocationMLocation / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyVisRMLocationMLocation::insertRst(
			ListBrlyVisRMLocationMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyVisRMLocationMLocation::updateRec(
			BrlyVisRMLocationMLocation* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->dstRefBrlyMLocation,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->orgRefBrlyMLocation,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyVisRMLocationMLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyVisRMLocationMLocation / stmtUpdateRec)\n");
};

void MyTblBrlyVisRMLocationMLocation::updateRst(
			ListBrlyVisRMLocationMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyVisRMLocationMLocation::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyVisRMLocationMLocation / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyVisRMLocationMLocation / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyVisRMLocationMLocation::loadRecByRef(
			ubigint ref
			, BrlyVisRMLocationMLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyVisRMLocationMLocation WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyVisRMLocationMLocation::loadDlosByOlo(
			ubigint orgRefBrlyMLocation
			, const bool append
			, vector<ubigint>& dstRefBrlyMLocations
		) {
	return loadRefsBySQL("SELECT dstRefBrlyMLocation FROM TblBrlyVisRMLocationMLocation WHERE orgRefBrlyMLocation = " + to_string(orgRefBrlyMLocation) + "", append, dstRefBrlyMLocations);
};

ubigint MyTblBrlyVisRMLocationMLocation::loadOlosByDlo(
			ubigint dstRefBrlyMLocation
			, const bool append
			, vector<ubigint>& orgRefBrlyMLocations
		) {
	return loadRefsBySQL("SELECT orgRefBrlyMLocation FROM TblBrlyVisRMLocationMLocation WHERE dstRefBrlyMLocation = " + to_string(dstRefBrlyMLocation) + "", append, orgRefBrlyMLocations);
};

/******************************************************************************
 class PgTblBrlyVisRMLocationMLocation
 ******************************************************************************/

PgTblBrlyVisRMLocationMLocation::PgTblBrlyVisRMLocationMLocation() : TblBrlyVisRMLocationMLocation(), PgTable() {
};

PgTblBrlyVisRMLocationMLocation::~PgTblBrlyVisRMLocationMLocation() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyVisRMLocationMLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyVisRMLocationMLocation_insertRec", "INSERT INTO TblBrlyVisRMLocationMLocation (dstRefBrlyMLocation, orgRefBrlyMLocation) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyVisRMLocationMLocation_updateRec", "UPDATE TblBrlyVisRMLocationMLocation SET dstRefBrlyMLocation = $1, orgRefBrlyMLocation = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyVisRMLocationMLocation_removeRecByRef", "DELETE FROM TblBrlyVisRMLocationMLocation WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyVisRMLocationMLocation_loadRecByRef", "SELECT ref, dstRefBrlyMLocation, orgRefBrlyMLocation FROM TblBrlyVisRMLocationMLocation WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyVisRMLocationMLocation_loadDlosByOlo", "SELECT dstRefBrlyMLocation FROM TblBrlyVisRMLocationMLocation WHERE orgRefBrlyMLocation = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyVisRMLocationMLocation_loadOlosByDlo", "SELECT orgRefBrlyMLocation FROM TblBrlyVisRMLocationMLocation WHERE dstRefBrlyMLocation = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyVisRMLocationMLocation::loadRec(
			PGresult* res
			, BrlyVisRMLocationMLocation** rec
		) {
	char* ptr;

	BrlyVisRMLocationMLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyVisRMLocationMLocation();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "dstrefbrlymlocation"),
			PQfnumber(res, "orgrefbrlymlocation")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->dstRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->orgRefBrlyMLocation = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyVisRMLocationMLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyVisRMLocationMLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyVisRMLocationMLocation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "dstrefbrlymlocation"),
			PQfnumber(res, "orgrefbrlymlocation")
		};

		while (numread < numrow) {
			rec = new BrlyVisRMLocationMLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->dstRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->orgRefBrlyMLocation = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyVisRMLocationMLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyVisRMLocationMLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyVisRMLocationMLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyVisRMLocationMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyVisRMLocationMLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyVisRMLocationMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyVisRMLocationMLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyVisRMLocationMLocation::insertRec(
			BrlyVisRMLocationMLocation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _dstRefBrlyMLocation = htonl64(rec->dstRefBrlyMLocation);
	ubigint _orgRefBrlyMLocation = htonl64(rec->orgRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_dstRefBrlyMLocation,
		(char*) &_orgRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblBrlyVisRMLocationMLocation_insertRec", 2, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyVisRMLocationMLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyVisRMLocationMLocation::insertRst(
			ListBrlyVisRMLocationMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyVisRMLocationMLocation::updateRec(
			BrlyVisRMLocationMLocation* rec
		) {
	PGresult* res;

	ubigint _dstRefBrlyMLocation = htonl64(rec->dstRefBrlyMLocation);
	ubigint _orgRefBrlyMLocation = htonl64(rec->orgRefBrlyMLocation);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_dstRefBrlyMLocation,
		(char*) &_orgRefBrlyMLocation,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyVisRMLocationMLocation_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyVisRMLocationMLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyVisRMLocationMLocation::updateRst(
			ListBrlyVisRMLocationMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyVisRMLocationMLocation::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyVisRMLocationMLocation_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyVisRMLocationMLocation_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyVisRMLocationMLocation::loadRecByRef(
			ubigint ref
			, BrlyVisRMLocationMLocation** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyVisRMLocationMLocation_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyVisRMLocationMLocation::loadDlosByOlo(
			ubigint orgRefBrlyMLocation
			, const bool append
			, vector<ubigint>& dstRefBrlyMLocations
		) {
	ubigint _orgRefBrlyMLocation = htonl64(orgRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_orgRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyVisRMLocationMLocation_loadDlosByOlo", 1, vals, l, f, append, dstRefBrlyMLocations);
};

ubigint PgTblBrlyVisRMLocationMLocation::loadOlosByDlo(
			ubigint dstRefBrlyMLocation
			, const bool append
			, vector<ubigint>& orgRefBrlyMLocations
		) {
	ubigint _dstRefBrlyMLocation = htonl64(dstRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_dstRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyVisRMLocationMLocation_loadOlosByDlo", 1, vals, l, f, append, orgRefBrlyMLocations);
};

