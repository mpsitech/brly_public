/**
  * \file BrlyAVControlPar.cpp
  * database access for table TblBrlyAVControlPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyAVControlPar.h"

/******************************************************************************
 class BrlyAVControlPar
 ******************************************************************************/

BrlyAVControlPar::BrlyAVControlPar(
			const ubigint ref
			, const uint ixBrlyVControl
			, const ubigint x1RefBrlyMUser
			, const uint x2IxBrlyVLocale
			, const string Par
			, const string Val
		) {

	this->ref = ref;
	this->ixBrlyVControl = ixBrlyVControl;
	this->x1RefBrlyMUser = x1RefBrlyMUser;
	this->x2IxBrlyVLocale = x2IxBrlyVLocale;
	this->Par = Par;
	this->Val = Val;
};

bool BrlyAVControlPar::operator==(
			const BrlyAVControlPar& comp
		) {
	return false;
};

bool BrlyAVControlPar::operator!=(
			const BrlyAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAVControlPar
 ******************************************************************************/

ListBrlyAVControlPar::ListBrlyAVControlPar() {
};

ListBrlyAVControlPar::ListBrlyAVControlPar(
			const ListBrlyAVControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyAVControlPar(*(src.nodes[i]));
};

ListBrlyAVControlPar::~ListBrlyAVControlPar() {
	clear();
};

void ListBrlyAVControlPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAVControlPar::size() const {
	return(nodes.size());
};

void ListBrlyAVControlPar::append(
			BrlyAVControlPar* rec
		) {
	nodes.push_back(rec);
};

BrlyAVControlPar* ListBrlyAVControlPar::operator[](
			const uint ix
		) {
	BrlyAVControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAVControlPar& ListBrlyAVControlPar::operator=(
			const ListBrlyAVControlPar& src
		) {
	BrlyAVControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyAVControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAVControlPar::operator==(
			const ListBrlyAVControlPar& comp
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

bool ListBrlyAVControlPar::operator!=(
			const ListBrlyAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAVControlPar
 ******************************************************************************/

TblBrlyAVControlPar::TblBrlyAVControlPar() {
};

TblBrlyAVControlPar::~TblBrlyAVControlPar() {
};

bool TblBrlyAVControlPar::loadRecBySQL(
			const string& sqlstr
			, BrlyAVControlPar** rec
		) {
	return false;
};

ubigint TblBrlyAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVControlPar& rst
		) {
	return 0;
};

void TblBrlyAVControlPar::insertRec(
			BrlyAVControlPar* rec
		) {
};

ubigint TblBrlyAVControlPar::insertNewRec(
			BrlyAVControlPar** rec
			, const uint ixBrlyVControl
			, const ubigint x1RefBrlyMUser
			, const uint x2IxBrlyVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	BrlyAVControlPar* _rec = NULL;

	_rec = new BrlyAVControlPar(0, ixBrlyVControl, x1RefBrlyMUser, x2IxBrlyVLocale, Par, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAVControlPar::appendNewRecToRst(
			ListBrlyAVControlPar& rst
			, BrlyAVControlPar** rec
			, const uint ixBrlyVControl
			, const ubigint x1RefBrlyMUser
			, const uint x2IxBrlyVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	BrlyAVControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, ixBrlyVControl, x1RefBrlyMUser, x2IxBrlyVLocale, Par, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAVControlPar::insertRst(
			ListBrlyAVControlPar& rst
			, bool transact
		) {
};

void TblBrlyAVControlPar::updateRec(
			BrlyAVControlPar* rec
		) {
};

void TblBrlyAVControlPar::updateRst(
			ListBrlyAVControlPar& rst
			, bool transact
		) {
};

void TblBrlyAVControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAVControlPar::loadRecByRef(
			ubigint ref
			, BrlyAVControlPar** rec
		) {
	return false;
};

bool TblBrlyAVControlPar::loadRefByCtlUsrPar(
			uint ixBrlyVControl
			, ubigint x1RefBrlyMUser
			, string Par
			, ubigint& ref
		) {
	return false;
};

bool TblBrlyAVControlPar::loadValByCtlUsrPar(
			uint ixBrlyVControl
			, ubigint x1RefBrlyMUser
			, string Par
			, string& Val
		) {
	return false;
};

ubigint TblBrlyAVControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAVControlPar& rst
		) {
	ubigint numload = 0;
	BrlyAVControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyAVControlPar
 ******************************************************************************/

MyTblBrlyAVControlPar::MyTblBrlyAVControlPar() : TblBrlyAVControlPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAVControlPar::~MyTblBrlyAVControlPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAVControlPar (ixBrlyVControl, x1RefBrlyMUser, x2IxBrlyVLocale, Par, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAVControlPar SET ixBrlyVControl = ?, x1RefBrlyMUser = ?, x2IxBrlyVLocale = ?, Par = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAVControlPar WHERE ref = ?", false);
};

bool MyTblBrlyAVControlPar::loadRecBySQL(
			const string& sqlstr
			, BrlyAVControlPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAVControlPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAVControlPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyAVControlPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixBrlyVControl = atol((char*) dbrow[1]); else _rec->ixBrlyVControl = 0;
		if (dbrow[2]) _rec->x1RefBrlyMUser = atoll((char*) dbrow[2]); else _rec->x1RefBrlyMUser = 0;
		if (dbrow[3]) _rec->x2IxBrlyVLocale = atol((char*) dbrow[3]); else _rec->x2IxBrlyVLocale = 0;
		if (dbrow[4]) _rec->Par.assign(dbrow[4], dblengths[4]); else _rec->Par = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVControlPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAVControlPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAVControlPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyAVControlPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixBrlyVControl = atol((char*) dbrow[1]); else rec->ixBrlyVControl = 0;
			if (dbrow[2]) rec->x1RefBrlyMUser = atoll((char*) dbrow[2]); else rec->x1RefBrlyMUser = 0;
			if (dbrow[3]) rec->x2IxBrlyVLocale = atol((char*) dbrow[3]); else rec->x2IxBrlyVLocale = 0;
			if (dbrow[4]) rec->Par.assign(dbrow[4], dblengths[4]); else rec->Par = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyAVControlPar::insertRec(
			BrlyAVControlPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixBrlyVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefBrlyMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxBrlyVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVControlPar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVControlPar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyAVControlPar::insertRst(
			ListBrlyAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAVControlPar::updateRec(
			BrlyAVControlPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixBrlyVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefBrlyMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxBrlyVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVControlPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVControlPar / stmtUpdateRec)\n");
};

void MyTblBrlyAVControlPar::updateRst(
			ListBrlyAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAVControlPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVControlPar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVControlPar / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyAVControlPar::loadRecByRef(
			ubigint ref
			, BrlyAVControlPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyAVControlPar WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyAVControlPar::loadRefByCtlUsrPar(
			uint ixBrlyVControl
			, ubigint x1RefBrlyMUser
			, string Par
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyAVControlPar WHERE ixBrlyVControl = " + to_string(ixBrlyVControl) + " AND x1RefBrlyMUser = " + to_string(x1RefBrlyMUser) + " AND Par = '" + Par + "'", ref);
};

bool MyTblBrlyAVControlPar::loadValByCtlUsrPar(
			uint ixBrlyVControl
			, ubigint x1RefBrlyMUser
			, string Par
			, string& Val
		) {
	return loadStringBySQL("SELECT Val FROM TblBrlyAVControlPar WHERE ixBrlyVControl = " + to_string(ixBrlyVControl) + " AND x1RefBrlyMUser = " + to_string(x1RefBrlyMUser) + " AND Par = '" + Par + "'", Val);
};

/******************************************************************************
 class PgTblBrlyAVControlPar
 ******************************************************************************/

PgTblBrlyAVControlPar::PgTblBrlyAVControlPar() : TblBrlyAVControlPar(), PgTable() {
};

PgTblBrlyAVControlPar::~PgTblBrlyAVControlPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAVControlPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyAVControlPar_insertRec", "INSERT INTO TblBrlyAVControlPar (ixBrlyVControl, x1RefBrlyMUser, x2IxBrlyVLocale, Par, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVControlPar_updateRec", "UPDATE TblBrlyAVControlPar SET ixBrlyVControl = $1, x1RefBrlyMUser = $2, x2IxBrlyVLocale = $3, Par = $4, Val = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVControlPar_removeRecByRef", "DELETE FROM TblBrlyAVControlPar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyAVControlPar_loadRecByRef", "SELECT ref, ixBrlyVControl, x1RefBrlyMUser, x2IxBrlyVLocale, Par, Val FROM TblBrlyAVControlPar WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyAVControlPar_loadRefByCtlUsrPar", "SELECT ref FROM TblBrlyAVControlPar WHERE ixBrlyVControl = $1 AND x1RefBrlyMUser = $2 AND Par = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVControlPar_loadValByCtlUsrPar", "SELECT Val FROM TblBrlyAVControlPar WHERE ixBrlyVControl = $1 AND x1RefBrlyMUser = $2 AND Par = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyAVControlPar::loadRec(
			PGresult* res
			, BrlyAVControlPar** rec
		) {
	char* ptr;

	BrlyAVControlPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAVControlPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixbrlyvcontrol"),
			PQfnumber(res, "x1refbrlymuser"),
			PQfnumber(res, "x2ixbrlyvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixBrlyVControl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefBrlyMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2IxBrlyVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Par.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAVControlPar::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAVControlPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAVControlPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixbrlyvcontrol"),
			PQfnumber(res, "x1refbrlymuser"),
			PQfnumber(res, "x2ixbrlyvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new BrlyAVControlPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixBrlyVControl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefBrlyMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2IxBrlyVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Par.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAVControlPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAVControlPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVControlPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblBrlyAVControlPar::loadRecBySQL(
			const string& sqlstr
			, BrlyAVControlPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVControlPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyAVControlPar::insertRec(
			BrlyAVControlPar* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixBrlyVControl = htonl(rec->ixBrlyVControl);
	ubigint _x1RefBrlyMUser = htonl64(rec->x1RefBrlyMUser);
	uint _x2IxBrlyVLocale = htonl(rec->x2IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_ixBrlyVControl,
		(char*) &_x1RefBrlyMUser,
		(char*) &_x2IxBrlyVLocale,
		rec->Par.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyAVControlPar_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVControlPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyAVControlPar::insertRst(
			ListBrlyAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAVControlPar::updateRec(
			BrlyAVControlPar* rec
		) {
	PGresult* res;

	uint _ixBrlyVControl = htonl(rec->ixBrlyVControl);
	ubigint _x1RefBrlyMUser = htonl64(rec->x1RefBrlyMUser);
	uint _x2IxBrlyVLocale = htonl(rec->x2IxBrlyVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixBrlyVControl,
		(char*) &_x1RefBrlyMUser,
		(char*) &_x2IxBrlyVLocale,
		rec->Par.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyAVControlPar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVControlPar_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyAVControlPar::updateRst(
			ListBrlyAVControlPar& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAVControlPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAVControlPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVControlPar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyAVControlPar::loadRecByRef(
			ubigint ref
			, BrlyAVControlPar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyAVControlPar_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyAVControlPar::loadRefByCtlUsrPar(
			uint ixBrlyVControl
			, ubigint x1RefBrlyMUser
			, string Par
			, ubigint& ref
		) {
	uint _ixBrlyVControl = htonl(ixBrlyVControl);
	ubigint _x1RefBrlyMUser = htonl64(x1RefBrlyMUser);

	const char* vals[] = {
		(char*) &_ixBrlyVControl,
		(char*) &_x1RefBrlyMUser,
		Par.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadRefByStmt("TblBrlyAVControlPar_loadRefByCtlUsrPar", 3, vals, l, f, ref);
};

bool PgTblBrlyAVControlPar::loadValByCtlUsrPar(
			uint ixBrlyVControl
			, ubigint x1RefBrlyMUser
			, string Par
			, string& Val
		) {
	uint _ixBrlyVControl = htonl(ixBrlyVControl);
	ubigint _x1RefBrlyMUser = htonl64(x1RefBrlyMUser);

	const char* vals[] = {
		(char*) &_ixBrlyVControl,
		(char*) &_x1RefBrlyMUser,
		Par.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,0};

	return loadStringByStmt("TblBrlyAVControlPar_loadValByCtlUsrPar", 3, vals, l, f, Val);
};

