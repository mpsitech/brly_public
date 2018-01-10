/**
  * \file BrlyQConRef1NSegment.cpp
  * Dbs and XML wrapper for table TblBrlyQConRef1NSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQConRef1NSegment.h"

/******************************************************************************
 class BrlyQConRef1NSegment
 ******************************************************************************/

BrlyQConRef1NSegment::BrlyQConRef1NSegment(
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

void BrlyQConRef1NSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConRef1NSegment";

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
 class ListBrlyQConRef1NSegment
 ******************************************************************************/

ListBrlyQConRef1NSegment::ListBrlyQConRef1NSegment() {
};

ListBrlyQConRef1NSegment::ListBrlyQConRef1NSegment(
			const ListBrlyQConRef1NSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConRef1NSegment(*(src.nodes[i]));
};

ListBrlyQConRef1NSegment::~ListBrlyQConRef1NSegment() {
	clear();
};

void ListBrlyQConRef1NSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConRef1NSegment::size() const {
	return(nodes.size());
};

void ListBrlyQConRef1NSegment::append(
			BrlyQConRef1NSegment* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConRef1NSegment& ListBrlyQConRef1NSegment::operator=(
			const ListBrlyQConRef1NSegment& src
		) {
	BrlyQConRef1NSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQConRef1NSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConRef1NSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConRef1NSegment";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConRef1NSegment
 ******************************************************************************/

TblBrlyQConRef1NSegment::TblBrlyQConRef1NSegment() {
};

TblBrlyQConRef1NSegment::~TblBrlyQConRef1NSegment() {
};

bool TblBrlyQConRef1NSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConRef1NSegment** rec
		) {
	return false;
};

ubigint TblBrlyQConRef1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConRef1NSegment& rst
		) {
	return 0;
};

void TblBrlyQConRef1NSegment::insertRec(
			BrlyQConRef1NSegment* rec
		) {
};

ubigint TblBrlyQConRef1NSegment::insertNewRec(
			BrlyQConRef1NSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	ubigint retval = 0;
	BrlyQConRef1NSegment* _rec = NULL;

	_rec = new BrlyQConRef1NSegment(0, jref, jnum, ref, stubRef, refNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConRef1NSegment::appendNewRecToRst(
			ListBrlyQConRef1NSegment& rst
			, BrlyQConRef1NSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const uint refNum
		) {
	ubigint retval = 0;
	BrlyQConRef1NSegment* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef, refNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConRef1NSegment::insertRst(
			ListBrlyQConRef1NSegment& rst
		) {
};

void TblBrlyQConRef1NSegment::updateRec(
			BrlyQConRef1NSegment* rec
		) {
};

void TblBrlyQConRef1NSegment::updateRst(
			ListBrlyQConRef1NSegment& rst
		) {
};

void TblBrlyQConRef1NSegment::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConRef1NSegment::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConRef1NSegment::loadRecByQref(
			ubigint qref
			, BrlyQConRef1NSegment** rec
		) {
	return false;
};

ubigint TblBrlyQConRef1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConRef1NSegment& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQConRef1NSegment
 ******************************************************************************/

MyTblBrlyQConRef1NSegment::MyTblBrlyQConRef1NSegment() : TblBrlyQConRef1NSegment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConRef1NSegment::~MyTblBrlyQConRef1NSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConRef1NSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConRef1NSegment (jref, jnum, ref, refNum) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConRef1NSegment SET jref = ?, jnum = ?, ref = ?, refNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConRef1NSegment WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConRef1NSegment WHERE jref = ?", false);
};

bool MyTblBrlyQConRef1NSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConRef1NSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConRef1NSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConRef1NSegment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConRef1NSegment();

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

ubigint MyTblBrlyQConRef1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConRef1NSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConRef1NSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConRef1NSegment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConRef1NSegment();

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

void MyTblBrlyQConRef1NSegment::insertRec(
			BrlyQConRef1NSegment* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refNum,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConRef1NSegment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConRef1NSegment / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQConRef1NSegment::insertRst(
			ListBrlyQConRef1NSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConRef1NSegment::updateRec(
			BrlyQConRef1NSegment* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->qref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConRef1NSegment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConRef1NSegment / stmtUpdateRec)\n");
};

void MyTblBrlyQConRef1NSegment::updateRst(
			ListBrlyQConRef1NSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConRef1NSegment::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConRef1NSegment / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConRef1NSegment / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQConRef1NSegment::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConRef1NSegment / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConRef1NSegment / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQConRef1NSegment::loadRecByQref(
			ubigint qref
			, BrlyQConRef1NSegment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQConRef1NSegment WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConRef1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConRef1NSegment& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConRef1NSegment WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQConRef1NSegment
 ******************************************************************************/

PgTblBrlyQConRef1NSegment::PgTblBrlyQConRef1NSegment() : TblBrlyQConRef1NSegment(), PgTable() {
};

PgTblBrlyQConRef1NSegment::~PgTblBrlyQConRef1NSegment() {
};

void PgTblBrlyQConRef1NSegment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQConRef1NSegment_insertRec", "INSERT INTO TblBrlyQConRef1NSegment (jref, jnum, ref, refNum) VALUES ($1,$2,$3,$4) RETURNING qref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConRef1NSegment_updateRec", "UPDATE TblBrlyQConRef1NSegment SET jref = $1, jnum = $2, ref = $3, refNum = $4 WHERE qref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConRef1NSegment_removeRecByQref", "DELETE FROM TblBrlyQConRef1NSegment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConRef1NSegment_removeRstByJref", "DELETE FROM TblBrlyQConRef1NSegment WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQConRef1NSegment_loadRecByQref", "SELECT qref, jref, jnum, ref, refNum FROM TblBrlyQConRef1NSegment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConRef1NSegment_loadRstByJref", "SELECT qref, jref, jnum, ref, refNum FROM TblBrlyQConRef1NSegment WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQConRef1NSegment::loadRec(
			PGresult* res
			, BrlyQConRef1NSegment** rec
		) {
	char* ptr;

	BrlyQConRef1NSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConRef1NSegment();

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

ubigint PgTblBrlyQConRef1NSegment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConRef1NSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConRef1NSegment* rec;

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
			rec = new BrlyQConRef1NSegment();

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

bool PgTblBrlyQConRef1NSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConRef1NSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConRef1NSegment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConRef1NSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConRef1NSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConRef1NSegment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConRef1NSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConRef1NSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConRef1NSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConRef1NSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQConRef1NSegment::insertRec(
			BrlyQConRef1NSegment* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQConRef1NSegment_insertRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConRef1NSegment_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQConRef1NSegment::insertRst(
			ListBrlyQConRef1NSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConRef1NSegment::updateRec(
			BrlyQConRef1NSegment* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQConRef1NSegment_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConRef1NSegment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQConRef1NSegment::updateRst(
			ListBrlyQConRef1NSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConRef1NSegment::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConRef1NSegment_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConRef1NSegment_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQConRef1NSegment::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConRef1NSegment_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConRef1NSegment_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQConRef1NSegment::loadRecByQref(
			ubigint qref
			, BrlyQConRef1NSegment** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQConRef1NSegment_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConRef1NSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConRef1NSegment& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConRef1NSegment_loadRstByJref", 1, vals, l, f, append, rst);
};

