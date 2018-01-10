/**
  * \file BrlyQFltRef1NSegment.cpp
  * Dbs and XML wrapper for table TblBrlyQFltRef1NSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQFltRef1NSegment.h"

/******************************************************************************
 class BrlyQFltRef1NSegment
 ******************************************************************************/

BrlyQFltRef1NSegment::BrlyQFltRef1NSegment(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->refNum = refNum;
};

void BrlyQFltRef1NSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQFltRef1NSegment";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQFltRef1NSegment
 ******************************************************************************/

ListBrlyQFltRef1NSegment::ListBrlyQFltRef1NSegment() {
};

ListBrlyQFltRef1NSegment::ListBrlyQFltRef1NSegment(
			const ListBrlyQFltRef1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltRef1NSegment(*(src.nodes[i]));
};

ListBrlyQFltRef1NSegment::~ListBrlyQFltRef1NSegment() {
	clear();
};

void ListBrlyQFltRef1NSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQFltRef1NSegment::size() const {
	return(nodes.size());
};

void ListBrlyQFltRef1NSegment::append(
			BrlyQFltRef1NSegment* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQFltRef1NSegment& ListBrlyQFltRef1NSegment::operator=(
			const ListBrlyQFltRef1NSegment& src
		) {
	BrlyQFltRef1NSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQFltRef1NSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQFltRef1NSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQFltRef1NSegment";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQFltRef1NSegment
 ******************************************************************************/

TblBrlyQFltRef1NSegment::TblBrlyQFltRef1NSegment() {
};

TblBrlyQFltRef1NSegment::~TblBrlyQFltRef1NSegment() {
};

bool TblBrlyQFltRef1NSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltRef1NSegment** rec
		) {
	return false;
};

ubigint TblBrlyQFltRef1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltRef1NSegment& rst
		) {
	return 0;
};

void TblBrlyQFltRef1NSegment::insertRec(
			BrlyQFltRef1NSegment* rec
		) {
};

ubigint TblBrlyQFltRef1NSegment::insertNewRec(
			BrlyQFltRef1NSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	ubigint retval = 0;
	BrlyQFltRef1NSegment* _rec = NULL;

	_rec = new BrlyQFltRef1NSegment(0, jref, jnum, ref, stubRef, refNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQFltRef1NSegment::appendNewRecToRst(
			ListBrlyQFltRef1NSegment& rst
			, BrlyQFltRef1NSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	ubigint retval = 0;
	BrlyQFltRef1NSegment* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, refNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQFltRef1NSegment::insertRst(
			ListBrlyQFltRef1NSegment& rst
		) {
};

void TblBrlyQFltRef1NSegment::updateRec(
			BrlyQFltRef1NSegment* rec
		) {
};

void TblBrlyQFltRef1NSegment::updateRst(
			ListBrlyQFltRef1NSegment& rst
		) {
};

void TblBrlyQFltRef1NSegment::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQFltRef1NSegment::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQFltRef1NSegment::loadRecByQref(
			ubigint qref
			, BrlyQFltRef1NSegment** rec
		) {
	return false;
};

ubigint TblBrlyQFltRef1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltRef1NSegment& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQFltRef1NSegment
 ******************************************************************************/

MyTblBrlyQFltRef1NSegment::MyTblBrlyQFltRef1NSegment() : TblBrlyQFltRef1NSegment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQFltRef1NSegment::~MyTblBrlyQFltRef1NSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQFltRef1NSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQFltRef1NSegment (jref, jnum, ref, refNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQFltRef1NSegment SET jref = ?, jnum = ?, ref = ?, refNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQFltRef1NSegment WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQFltRef1NSegment WHERE jref = ?", false);
};

bool MyTblBrlyQFltRef1NSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltRef1NSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQFltRef1NSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltRef1NSegment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQFltRef1NSegment();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refNum = atol((char*) dbrow[4]); else _rec->refNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQFltRef1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltRef1NSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQFltRef1NSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltRef1NSegment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQFltRef1NSegment();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refNum = atol((char*) dbrow[4]); else rec->refNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQFltRef1NSegment::insertRec(
			BrlyQFltRef1NSegment* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltRef1NSegment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltRef1NSegment / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQFltRef1NSegment::insertRst(
			ListBrlyQFltRef1NSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQFltRef1NSegment::updateRec(
			BrlyQFltRef1NSegment* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltRef1NSegment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltRef1NSegment / stmtUpdateRec)\n");
};

void MyTblBrlyQFltRef1NSegment::updateRst(
			ListBrlyQFltRef1NSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQFltRef1NSegment::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltRef1NSegment / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltRef1NSegment / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQFltRef1NSegment::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltRef1NSegment / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltRef1NSegment / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQFltRef1NSegment::loadRecByQref(
			ubigint qref
			, BrlyQFltRef1NSegment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQFltRef1NSegment WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQFltRef1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltRef1NSegment& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQFltRef1NSegment WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQFltRef1NSegment
 ******************************************************************************/

PgTblBrlyQFltRef1NSegment::PgTblBrlyQFltRef1NSegment() : TblBrlyQFltRef1NSegment(), PgTable() {
};

PgTblBrlyQFltRef1NSegment::~PgTblBrlyQFltRef1NSegment() {
};

void PgTblBrlyQFltRef1NSegment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQFltRef1NSegment_insertRec", "INSERT INTO TblBrlyQFltRef1NSegment (jref, jnum, ref, refNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltRef1NSegment_updateRec", "UPDATE TblBrlyQFltRef1NSegment SET jref = $1, jnum = $2, ref = $3, refNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltRef1NSegment_removeRecByQref", "DELETE FROM TblBrlyQFltRef1NSegment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltRef1NSegment_removeRstByJref", "DELETE FROM TblBrlyQFltRef1NSegment WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQFltRef1NSegment_loadRecByQref", "SELECT qref, jref, jnum, ref, refNum FROM TblBrlyQFltRef1NSegment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltRef1NSegment_loadRstByJref", "SELECT qref, jref, jnum, ref, refNum FROM TblBrlyQFltRef1NSegment WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQFltRef1NSegment::loadRec(
			PGresult* res
			, BrlyQFltRef1NSegment** rec
		) {
	char* ptr;

	BrlyQFltRef1NSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQFltRef1NSegment();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refnum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQFltRef1NSegment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQFltRef1NSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQFltRef1NSegment* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refnum")
		};

		while (numread < numrow) {
			rec = new BrlyQFltRef1NSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQFltRef1NSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQFltRef1NSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltRef1NSegment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltRef1NSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQFltRef1NSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltRef1NSegment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQFltRef1NSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltRef1NSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltRef1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltRef1NSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQFltRef1NSegment::insertRec(
			BrlyQFltRef1NSegment* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refNum = htonl(rec->refNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltRef1NSegment_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltRef1NSegment_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQFltRef1NSegment::insertRst(
			ListBrlyQFltRef1NSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQFltRef1NSegment::updateRec(
			BrlyQFltRef1NSegment* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refNum = htonl(rec->refNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltRef1NSegment_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltRef1NSegment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQFltRef1NSegment::updateRst(
			ListBrlyQFltRef1NSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQFltRef1NSegment::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyQFltRef1NSegment_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltRef1NSegment_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQFltRef1NSegment::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyQFltRef1NSegment_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltRef1NSegment_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQFltRef1NSegment::loadRecByQref(
			ubigint qref
			, BrlyQFltRef1NSegment** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQFltRef1NSegment_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQFltRef1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltRef1NSegment& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQFltRef1NSegment_loadRstByJref", 1, vals, l, f, append, rst);
};

