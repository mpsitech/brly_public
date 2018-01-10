/**
  * \file BrlyAVValuelistVal.cpp
  * database access for table TblBrlyAVValuelistVal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyAVValuelistVal.h"

/******************************************************************************
 class BrlyAVValuelistVal
 ******************************************************************************/

BrlyAVValuelistVal::BrlyAVValuelistVal(
			const ubigint ref
			, const uint vlsIxBrlyVValuelist
			, const uint vlsNum
			, const uint x1IxBrlyVLocale
			, const string Val
		) {

	this->ref = ref;
	this->vlsIxBrlyVValuelist = vlsIxBrlyVValuelist;
	this->vlsNum = vlsNum;
	this->x1IxBrlyVLocale = x1IxBrlyVLocale;
	this->Val = Val;
};

bool BrlyAVValuelistVal::operator==(
			const BrlyAVValuelistVal& comp
		) {
	return false;
};

bool BrlyAVValuelistVal::operator!=(
			const BrlyAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAVValuelistVal
 ******************************************************************************/

ListBrlyAVValuelistVal::ListBrlyAVValuelistVal() {
};

ListBrlyAVValuelistVal::ListBrlyAVValuelistVal(
			const ListBrlyAVValuelistVal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyAVValuelistVal(*(src.nodes[i]));
};

ListBrlyAVValuelistVal::~ListBrlyAVValuelistVal() {
	clear();
};

void ListBrlyAVValuelistVal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAVValuelistVal::size() const {
	return(nodes.size());
};

void ListBrlyAVValuelistVal::append(
			BrlyAVValuelistVal* rec
		) {
	nodes.push_back(rec);
};

BrlyAVValuelistVal* ListBrlyAVValuelistVal::operator[](
			const uint ix
		) {
	BrlyAVValuelistVal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAVValuelistVal& ListBrlyAVValuelistVal::operator=(
			const ListBrlyAVValuelistVal& src
		) {
	BrlyAVValuelistVal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyAVValuelistVal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAVValuelistVal::operator==(
			const ListBrlyAVValuelistVal& comp
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

bool ListBrlyAVValuelistVal::operator!=(
			const ListBrlyAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAVValuelistVal
 ******************************************************************************/

TblBrlyAVValuelistVal::TblBrlyAVValuelistVal() {
};

TblBrlyAVValuelistVal::~TblBrlyAVValuelistVal() {
};

bool TblBrlyAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, BrlyAVValuelistVal** rec
		) {
	return false;
};

ubigint TblBrlyAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	return 0;
};

void TblBrlyAVValuelistVal::insertRec(
			BrlyAVValuelistVal* rec
		) {
};

ubigint TblBrlyAVValuelistVal::insertNewRec(
			BrlyAVValuelistVal** rec
			, const uint vlsIxBrlyVValuelist
			, const uint vlsNum
			, const uint x1IxBrlyVLocale
			, const string Val
		) {
	ubigint retval = 0;
	BrlyAVValuelistVal* _rec = NULL;

	_rec = new BrlyAVValuelistVal(0, vlsIxBrlyVValuelist, vlsNum, x1IxBrlyVLocale, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAVValuelistVal::appendNewRecToRst(
			ListBrlyAVValuelistVal& rst
			, BrlyAVValuelistVal** rec
			, const uint vlsIxBrlyVValuelist
			, const uint vlsNum
			, const uint x1IxBrlyVLocale
			, const string Val
		) {
	ubigint retval = 0;
	BrlyAVValuelistVal* _rec = NULL;

	retval = insertNewRec(&_rec, vlsIxBrlyVValuelist, vlsNum, x1IxBrlyVLocale, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAVValuelistVal::insertRst(
			ListBrlyAVValuelistVal& rst
			, bool transact
		) {
};

void TblBrlyAVValuelistVal::updateRec(
			BrlyAVValuelistVal* rec
		) {
};

void TblBrlyAVValuelistVal::updateRst(
			ListBrlyAVValuelistVal& rst
			, bool transact
		) {
};

void TblBrlyAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAVValuelistVal::loadRecByRef(
			ubigint ref
			, BrlyAVValuelistVal** rec
		) {
	return false;
};

ubigint TblBrlyAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxBrlyVValuelist
			, uint x1IxBrlyVLocale
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblBrlyAVValuelistVal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	ubigint numload = 0;
	BrlyAVValuelistVal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyAVValuelistVal
 ******************************************************************************/

MyTblBrlyAVValuelistVal::MyTblBrlyAVValuelistVal() : TblBrlyAVValuelistVal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAVValuelistVal::~MyTblBrlyAVValuelistVal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAVValuelistVal (vlsIxBrlyVValuelist, vlsNum, x1IxBrlyVLocale, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAVValuelistVal SET vlsIxBrlyVValuelist = ?, vlsNum = ?, x1IxBrlyVLocale = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAVValuelistVal WHERE ref = ?", false);
};

bool MyTblBrlyAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, BrlyAVValuelistVal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAVValuelistVal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAVValuelistVal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyAVValuelistVal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->vlsIxBrlyVValuelist = atol((char*) dbrow[1]); else _rec->vlsIxBrlyVValuelist = 0;
		if (dbrow[2]) _rec->vlsNum = atol((char*) dbrow[2]); else _rec->vlsNum = 0;
		if (dbrow[3]) _rec->x1IxBrlyVLocale = atol((char*) dbrow[3]); else _rec->x1IxBrlyVLocale = 0;
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAVValuelistVal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAVValuelistVal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyAVValuelistVal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->vlsIxBrlyVValuelist = atol((char*) dbrow[1]); else rec->vlsIxBrlyVValuelist = 0;
			if (dbrow[2]) rec->vlsNum = atol((char*) dbrow[2]); else rec->vlsNum = 0;
			if (dbrow[3]) rec->x1IxBrlyVLocale = atol((char*) dbrow[3]); else rec->x1IxBrlyVLocale = 0;
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyAVValuelistVal::insertRec(
			BrlyAVValuelistVal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxBrlyVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxBrlyVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVValuelistVal / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVValuelistVal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyAVValuelistVal::insertRst(
			ListBrlyAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAVValuelistVal::updateRec(
			BrlyAVValuelistVal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxBrlyVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxBrlyVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVValuelistVal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVValuelistVal / stmtUpdateRec)\n");
};

void MyTblBrlyAVValuelistVal::updateRst(
			ListBrlyAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVValuelistVal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVValuelistVal / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyAVValuelistVal::loadRecByRef(
			ubigint ref
			, BrlyAVValuelistVal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyAVValuelistVal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxBrlyVValuelist
			, uint x1IxBrlyVLocale
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	return loadRstBySQL("SELECT ref, vlsIxBrlyVValuelist, vlsNum, x1IxBrlyVLocale, Val FROM TblBrlyAVValuelistVal WHERE vlsIxBrlyVValuelist = " + to_string(vlsIxBrlyVValuelist) + " AND x1IxBrlyVLocale = " + to_string(x1IxBrlyVLocale) + " ORDER BY vlsNum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyAVValuelistVal
 ******************************************************************************/

PgTblBrlyAVValuelistVal::PgTblBrlyAVValuelistVal() : TblBrlyAVValuelistVal(), PgTable() {
};

PgTblBrlyAVValuelistVal::~PgTblBrlyAVValuelistVal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAVValuelistVal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyAVValuelistVal_insertRec", "INSERT INTO TblBrlyAVValuelistVal (vlsIxBrlyVValuelist, vlsNum, x1IxBrlyVLocale, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVValuelistVal_updateRec", "UPDATE TblBrlyAVValuelistVal SET vlsIxBrlyVValuelist = $1, vlsNum = $2, x1IxBrlyVLocale = $3, Val = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVValuelistVal_removeRecByRef", "DELETE FROM TblBrlyAVValuelistVal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyAVValuelistVal_loadRecByRef", "SELECT ref, vlsIxBrlyVValuelist, vlsNum, x1IxBrlyVLocale, Val FROM TblBrlyAVValuelistVal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyAVValuelistVal_loadRstByVlsLcl", "SELECT ref, vlsIxBrlyVValuelist, vlsNum, x1IxBrlyVLocale, Val FROM TblBrlyAVValuelistVal WHERE vlsIxBrlyVValuelist = $1 AND x1IxBrlyVLocale = $2 ORDER BY vlsNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyAVValuelistVal::loadRec(
			PGresult* res
			, BrlyAVValuelistVal** rec
		) {
	char* ptr;

	BrlyAVValuelistVal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAVValuelistVal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixbrlyvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixbrlyvlocale"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->vlsIxBrlyVValuelist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->vlsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxBrlyVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAVValuelistVal::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAVValuelistVal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixbrlyvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixbrlyvlocale"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new BrlyAVValuelistVal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->vlsIxBrlyVValuelist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->vlsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxBrlyVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAVValuelistVal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVValuelistVal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAVValuelistVal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVValuelistVal / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, BrlyAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyAVValuelistVal::insertRec(
			BrlyAVValuelistVal* rec
		) {
	PGresult* res;
	char* ptr;

	uint _vlsIxBrlyVValuelist = htonl(rec->vlsIxBrlyVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxBrlyVLocale = htonl(rec->x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_vlsIxBrlyVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxBrlyVLocale,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyAVValuelistVal_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVValuelistVal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyAVValuelistVal::insertRst(
			ListBrlyAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAVValuelistVal::updateRec(
			BrlyAVValuelistVal* rec
		) {
	PGresult* res;

	uint _vlsIxBrlyVValuelist = htonl(rec->vlsIxBrlyVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxBrlyVLocale = htonl(rec->x1IxBrlyVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_vlsIxBrlyVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxBrlyVLocale,
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyAVValuelistVal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVValuelistVal_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyAVValuelistVal::updateRst(
			ListBrlyAVValuelistVal& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAVValuelistVal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyAVValuelistVal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVValuelistVal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyAVValuelistVal::loadRecByRef(
			ubigint ref
			, BrlyAVValuelistVal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyAVValuelistVal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxBrlyVValuelist
			, uint x1IxBrlyVLocale
			, const bool append
			, ListBrlyAVValuelistVal& rst
		) {
	uint _vlsIxBrlyVValuelist = htonl(vlsIxBrlyVValuelist);
	uint _x1IxBrlyVLocale = htonl(x1IxBrlyVLocale);

	const char* vals[] = {
		(char*) &_vlsIxBrlyVValuelist,
		(char*) &_x1IxBrlyVLocale
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblBrlyAVValuelistVal_loadRstByVlsLcl", 2, vals, l, f, append, rst);
};

