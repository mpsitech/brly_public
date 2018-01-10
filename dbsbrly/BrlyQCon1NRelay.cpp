/**
  * \file BrlyQCon1NRelay.cpp
  * Dbs and XML wrapper for table TblBrlyQCon1NRelay (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQCon1NRelay.h"

/******************************************************************************
 class BrlyQCon1NRelay
 ******************************************************************************/

BrlyQCon1NRelay::BrlyQCon1NRelay(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void BrlyQCon1NRelay::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQCon1NRelay";

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
 class ListBrlyQCon1NRelay
 ******************************************************************************/

ListBrlyQCon1NRelay::ListBrlyQCon1NRelay() {
};

ListBrlyQCon1NRelay::ListBrlyQCon1NRelay(
			const ListBrlyQCon1NRelay& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQCon1NRelay(*(src.nodes[i]));
};

ListBrlyQCon1NRelay::~ListBrlyQCon1NRelay() {
	clear();
};

void ListBrlyQCon1NRelay::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQCon1NRelay::size() const {
	return(nodes.size());
};

void ListBrlyQCon1NRelay::append(
			BrlyQCon1NRelay* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQCon1NRelay& ListBrlyQCon1NRelay::operator=(
			const ListBrlyQCon1NRelay& src
		) {
	BrlyQCon1NRelay* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQCon1NRelay(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQCon1NRelay::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQCon1NRelay";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQCon1NRelay
 ******************************************************************************/

TblBrlyQCon1NRelay::TblBrlyQCon1NRelay() {
};

TblBrlyQCon1NRelay::~TblBrlyQCon1NRelay() {
};

bool TblBrlyQCon1NRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyQCon1NRelay** rec
		) {
	return false;
};

ubigint TblBrlyQCon1NRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQCon1NRelay& rst
		) {
	return 0;
};

void TblBrlyQCon1NRelay::insertRec(
			BrlyQCon1NRelay* rec
		) {
};

ubigint TblBrlyQCon1NRelay::insertNewRec(
			BrlyQCon1NRelay** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQCon1NRelay* _rec = NULL;

	_rec = new BrlyQCon1NRelay(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQCon1NRelay::appendNewRecToRst(
			ListBrlyQCon1NRelay& rst
			, BrlyQCon1NRelay** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQCon1NRelay* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQCon1NRelay::insertRst(
			ListBrlyQCon1NRelay& rst
		) {
};

void TblBrlyQCon1NRelay::updateRec(
			BrlyQCon1NRelay* rec
		) {
};

void TblBrlyQCon1NRelay::updateRst(
			ListBrlyQCon1NRelay& rst
		) {
};

void TblBrlyQCon1NRelay::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQCon1NRelay::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQCon1NRelay::loadRecByQref(
			ubigint qref
			, BrlyQCon1NRelay** rec
		) {
	return false;
};

ubigint TblBrlyQCon1NRelay::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQCon1NRelay& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQCon1NRelay
 ******************************************************************************/

MyTblBrlyQCon1NRelay::MyTblBrlyQCon1NRelay() : TblBrlyQCon1NRelay(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQCon1NRelay::~MyTblBrlyQCon1NRelay() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQCon1NRelay::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQCon1NRelay (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQCon1NRelay SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQCon1NRelay WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQCon1NRelay WHERE jref = ?", false);
};

bool MyTblBrlyQCon1NRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyQCon1NRelay** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQCon1NRelay* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQCon1NRelay / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQCon1NRelay();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQCon1NRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQCon1NRelay& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQCon1NRelay* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQCon1NRelay / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQCon1NRelay();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQCon1NRelay::insertRec(
			BrlyQCon1NRelay* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQCon1NRelay / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQCon1NRelay / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQCon1NRelay::insertRst(
			ListBrlyQCon1NRelay& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQCon1NRelay::updateRec(
			BrlyQCon1NRelay* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQCon1NRelay / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQCon1NRelay / stmtUpdateRec)\n");
};

void MyTblBrlyQCon1NRelay::updateRst(
			ListBrlyQCon1NRelay& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQCon1NRelay::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQCon1NRelay / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQCon1NRelay / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQCon1NRelay::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQCon1NRelay / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQCon1NRelay / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQCon1NRelay::loadRecByQref(
			ubigint qref
			, BrlyQCon1NRelay** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQCon1NRelay WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQCon1NRelay::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQCon1NRelay& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQCon1NRelay WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQCon1NRelay
 ******************************************************************************/

PgTblBrlyQCon1NRelay::PgTblBrlyQCon1NRelay() : TblBrlyQCon1NRelay(), PgTable() {
};

PgTblBrlyQCon1NRelay::~PgTblBrlyQCon1NRelay() {
};

void PgTblBrlyQCon1NRelay::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQCon1NRelay_insertRec", "INSERT INTO TblBrlyQCon1NRelay (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQCon1NRelay_updateRec", "UPDATE TblBrlyQCon1NRelay SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQCon1NRelay_removeRecByQref", "DELETE FROM TblBrlyQCon1NRelay WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQCon1NRelay_removeRstByJref", "DELETE FROM TblBrlyQCon1NRelay WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQCon1NRelay_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQCon1NRelay WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQCon1NRelay_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQCon1NRelay WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQCon1NRelay::loadRec(
			PGresult* res
			, BrlyQCon1NRelay** rec
		) {
	char* ptr;

	BrlyQCon1NRelay* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQCon1NRelay();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQCon1NRelay::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQCon1NRelay& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQCon1NRelay* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new BrlyQCon1NRelay();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQCon1NRelay::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQCon1NRelay** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQCon1NRelay / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQCon1NRelay::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQCon1NRelay& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQCon1NRelay / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQCon1NRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyQCon1NRelay** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQCon1NRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQCon1NRelay& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQCon1NRelay::insertRec(
			BrlyQCon1NRelay* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQCon1NRelay_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQCon1NRelay_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQCon1NRelay::insertRst(
			ListBrlyQCon1NRelay& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQCon1NRelay::updateRec(
			BrlyQCon1NRelay* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQCon1NRelay_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQCon1NRelay_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQCon1NRelay::updateRst(
			ListBrlyQCon1NRelay& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQCon1NRelay::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQCon1NRelay_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQCon1NRelay_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQCon1NRelay::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQCon1NRelay_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQCon1NRelay_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQCon1NRelay::loadRecByQref(
			ubigint qref
			, BrlyQCon1NRelay** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQCon1NRelay_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQCon1NRelay::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQCon1NRelay& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQCon1NRelay_loadRstByJref", 1, vals, l, f, append, rst);
};

