/**
  * \file BrlyQLeg1NFlight.cpp
  * Dbs and XML wrapper for table TblBrlyQLeg1NFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLeg1NFlight.h"

/******************************************************************************
 class BrlyQLeg1NFlight
 ******************************************************************************/

BrlyQLeg1NFlight::BrlyQLeg1NFlight(
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

void BrlyQLeg1NFlight::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLeg1NFlight";

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
 class ListBrlyQLeg1NFlight
 ******************************************************************************/

ListBrlyQLeg1NFlight::ListBrlyQLeg1NFlight() {
};

ListBrlyQLeg1NFlight::ListBrlyQLeg1NFlight(
			const ListBrlyQLeg1NFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLeg1NFlight(*(src.nodes[i]));
};

ListBrlyQLeg1NFlight::~ListBrlyQLeg1NFlight() {
	clear();
};

void ListBrlyQLeg1NFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLeg1NFlight::size() const {
	return(nodes.size());
};

void ListBrlyQLeg1NFlight::append(
			BrlyQLeg1NFlight* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLeg1NFlight& ListBrlyQLeg1NFlight::operator=(
			const ListBrlyQLeg1NFlight& src
		) {
	BrlyQLeg1NFlight* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLeg1NFlight(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLeg1NFlight::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLeg1NFlight";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLeg1NFlight
 ******************************************************************************/

TblBrlyQLeg1NFlight::TblBrlyQLeg1NFlight() {
};

TblBrlyQLeg1NFlight::~TblBrlyQLeg1NFlight() {
};

bool TblBrlyQLeg1NFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyQLeg1NFlight** rec
		) {
	return false;
};

ubigint TblBrlyQLeg1NFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLeg1NFlight& rst
		) {
	return 0;
};

void TblBrlyQLeg1NFlight::insertRec(
			BrlyQLeg1NFlight* rec
		) {
};

ubigint TblBrlyQLeg1NFlight::insertNewRec(
			BrlyQLeg1NFlight** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQLeg1NFlight* _rec = NULL;

	_rec = new BrlyQLeg1NFlight(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLeg1NFlight::appendNewRecToRst(
			ListBrlyQLeg1NFlight& rst
			, BrlyQLeg1NFlight** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQLeg1NFlight* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLeg1NFlight::insertRst(
			ListBrlyQLeg1NFlight& rst
		) {
};

void TblBrlyQLeg1NFlight::updateRec(
			BrlyQLeg1NFlight* rec
		) {
};

void TblBrlyQLeg1NFlight::updateRst(
			ListBrlyQLeg1NFlight& rst
		) {
};

void TblBrlyQLeg1NFlight::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLeg1NFlight::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLeg1NFlight::loadRecByQref(
			ubigint qref
			, BrlyQLeg1NFlight** rec
		) {
	return false;
};

ubigint TblBrlyQLeg1NFlight::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLeg1NFlight& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLeg1NFlight
 ******************************************************************************/

MyTblBrlyQLeg1NFlight::MyTblBrlyQLeg1NFlight() : TblBrlyQLeg1NFlight(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLeg1NFlight::~MyTblBrlyQLeg1NFlight() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLeg1NFlight::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLeg1NFlight (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLeg1NFlight SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLeg1NFlight WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLeg1NFlight WHERE jref = ?", false);
};

bool MyTblBrlyQLeg1NFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyQLeg1NFlight** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLeg1NFlight* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLeg1NFlight / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLeg1NFlight();

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

ubigint MyTblBrlyQLeg1NFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLeg1NFlight& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLeg1NFlight* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLeg1NFlight / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLeg1NFlight();

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

void MyTblBrlyQLeg1NFlight::insertRec(
			BrlyQLeg1NFlight* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLeg1NFlight / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLeg1NFlight / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLeg1NFlight::insertRst(
			ListBrlyQLeg1NFlight& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLeg1NFlight::updateRec(
			BrlyQLeg1NFlight* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLeg1NFlight / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLeg1NFlight / stmtUpdateRec)\n");
};

void MyTblBrlyQLeg1NFlight::updateRst(
			ListBrlyQLeg1NFlight& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLeg1NFlight::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLeg1NFlight / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLeg1NFlight / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLeg1NFlight::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLeg1NFlight / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLeg1NFlight / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLeg1NFlight::loadRecByQref(
			ubigint qref
			, BrlyQLeg1NFlight** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLeg1NFlight WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLeg1NFlight::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLeg1NFlight& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLeg1NFlight WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLeg1NFlight
 ******************************************************************************/

PgTblBrlyQLeg1NFlight::PgTblBrlyQLeg1NFlight() : TblBrlyQLeg1NFlight(), PgTable() {
};

PgTblBrlyQLeg1NFlight::~PgTblBrlyQLeg1NFlight() {
};

void PgTblBrlyQLeg1NFlight::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLeg1NFlight_insertRec", "INSERT INTO TblBrlyQLeg1NFlight (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLeg1NFlight_updateRec", "UPDATE TblBrlyQLeg1NFlight SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLeg1NFlight_removeRecByQref", "DELETE FROM TblBrlyQLeg1NFlight WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLeg1NFlight_removeRstByJref", "DELETE FROM TblBrlyQLeg1NFlight WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLeg1NFlight_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQLeg1NFlight WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLeg1NFlight_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQLeg1NFlight WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLeg1NFlight::loadRec(
			PGresult* res
			, BrlyQLeg1NFlight** rec
		) {
	char* ptr;

	BrlyQLeg1NFlight* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLeg1NFlight();

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

ubigint PgTblBrlyQLeg1NFlight::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLeg1NFlight& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLeg1NFlight* rec;

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
			rec = new BrlyQLeg1NFlight();

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

bool PgTblBrlyQLeg1NFlight::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLeg1NFlight** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLeg1NFlight / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLeg1NFlight::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLeg1NFlight& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLeg1NFlight / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLeg1NFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyQLeg1NFlight** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLeg1NFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLeg1NFlight& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLeg1NFlight::insertRec(
			BrlyQLeg1NFlight* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQLeg1NFlight_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLeg1NFlight_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLeg1NFlight::insertRst(
			ListBrlyQLeg1NFlight& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLeg1NFlight::updateRec(
			BrlyQLeg1NFlight* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQLeg1NFlight_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLeg1NFlight_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLeg1NFlight::updateRst(
			ListBrlyQLeg1NFlight& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLeg1NFlight::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLeg1NFlight_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLeg1NFlight_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLeg1NFlight::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLeg1NFlight_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLeg1NFlight_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLeg1NFlight::loadRecByQref(
			ubigint qref
			, BrlyQLeg1NFlight** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLeg1NFlight_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLeg1NFlight::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLeg1NFlight& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLeg1NFlight_loadRstByJref", 1, vals, l, f, append, rst);
};

