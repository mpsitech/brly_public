/**
  * \file BrlyQFlt1NConnection.cpp
  * Dbs and XML wrapper for table TblBrlyQFlt1NConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQFlt1NConnection.h"

/******************************************************************************
 class BrlyQFlt1NConnection
 ******************************************************************************/

BrlyQFlt1NConnection::BrlyQFlt1NConnection(
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

void BrlyQFlt1NConnection::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQFlt1NConnection";

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
 class ListBrlyQFlt1NConnection
 ******************************************************************************/

ListBrlyQFlt1NConnection::ListBrlyQFlt1NConnection() {
};

ListBrlyQFlt1NConnection::ListBrlyQFlt1NConnection(
			const ListBrlyQFlt1NConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFlt1NConnection(*(src.nodes[i]));
};

ListBrlyQFlt1NConnection::~ListBrlyQFlt1NConnection() {
	clear();
};

void ListBrlyQFlt1NConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQFlt1NConnection::size() const {
	return(nodes.size());
};

void ListBrlyQFlt1NConnection::append(
			BrlyQFlt1NConnection* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQFlt1NConnection& ListBrlyQFlt1NConnection::operator=(
			const ListBrlyQFlt1NConnection& src
		) {
	BrlyQFlt1NConnection* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQFlt1NConnection(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQFlt1NConnection::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQFlt1NConnection";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQFlt1NConnection
 ******************************************************************************/

TblBrlyQFlt1NConnection::TblBrlyQFlt1NConnection() {
};

TblBrlyQFlt1NConnection::~TblBrlyQFlt1NConnection() {
};

bool TblBrlyQFlt1NConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQFlt1NConnection** rec
		) {
	return false;
};

ubigint TblBrlyQFlt1NConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFlt1NConnection& rst
		) {
	return 0;
};

void TblBrlyQFlt1NConnection::insertRec(
			BrlyQFlt1NConnection* rec
		) {
};

ubigint TblBrlyQFlt1NConnection::insertNewRec(
			BrlyQFlt1NConnection** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQFlt1NConnection* _rec = NULL;

	_rec = new BrlyQFlt1NConnection(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQFlt1NConnection::appendNewRecToRst(
			ListBrlyQFlt1NConnection& rst
			, BrlyQFlt1NConnection** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQFlt1NConnection* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQFlt1NConnection::insertRst(
			ListBrlyQFlt1NConnection& rst
		) {
};

void TblBrlyQFlt1NConnection::updateRec(
			BrlyQFlt1NConnection* rec
		) {
};

void TblBrlyQFlt1NConnection::updateRst(
			ListBrlyQFlt1NConnection& rst
		) {
};

void TblBrlyQFlt1NConnection::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQFlt1NConnection::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQFlt1NConnection::loadRecByQref(
			ubigint qref
			, BrlyQFlt1NConnection** rec
		) {
	return false;
};

ubigint TblBrlyQFlt1NConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFlt1NConnection& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQFlt1NConnection
 ******************************************************************************/

MyTblBrlyQFlt1NConnection::MyTblBrlyQFlt1NConnection() : TblBrlyQFlt1NConnection(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQFlt1NConnection::~MyTblBrlyQFlt1NConnection() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQFlt1NConnection::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQFlt1NConnection (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQFlt1NConnection SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQFlt1NConnection WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQFlt1NConnection WHERE jref = ?", false);
};

bool MyTblBrlyQFlt1NConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQFlt1NConnection** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQFlt1NConnection* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFlt1NConnection / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQFlt1NConnection();

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

ubigint MyTblBrlyQFlt1NConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFlt1NConnection& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQFlt1NConnection* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFlt1NConnection / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQFlt1NConnection();

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

void MyTblBrlyQFlt1NConnection::insertRec(
			BrlyQFlt1NConnection* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFlt1NConnection / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFlt1NConnection / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQFlt1NConnection::insertRst(
			ListBrlyQFlt1NConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQFlt1NConnection::updateRec(
			BrlyQFlt1NConnection* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFlt1NConnection / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFlt1NConnection / stmtUpdateRec)\n");
};

void MyTblBrlyQFlt1NConnection::updateRst(
			ListBrlyQFlt1NConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQFlt1NConnection::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFlt1NConnection / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFlt1NConnection / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQFlt1NConnection::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFlt1NConnection / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFlt1NConnection / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQFlt1NConnection::loadRecByQref(
			ubigint qref
			, BrlyQFlt1NConnection** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQFlt1NConnection WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQFlt1NConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFlt1NConnection& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQFlt1NConnection WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQFlt1NConnection
 ******************************************************************************/

PgTblBrlyQFlt1NConnection::PgTblBrlyQFlt1NConnection() : TblBrlyQFlt1NConnection(), PgTable() {
};

PgTblBrlyQFlt1NConnection::~PgTblBrlyQFlt1NConnection() {
};

void PgTblBrlyQFlt1NConnection::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQFlt1NConnection_insertRec", "INSERT INTO TblBrlyQFlt1NConnection (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFlt1NConnection_updateRec", "UPDATE TblBrlyQFlt1NConnection SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFlt1NConnection_removeRecByQref", "DELETE FROM TblBrlyQFlt1NConnection WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFlt1NConnection_removeRstByJref", "DELETE FROM TblBrlyQFlt1NConnection WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQFlt1NConnection_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQFlt1NConnection WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFlt1NConnection_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQFlt1NConnection WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQFlt1NConnection::loadRec(
			PGresult* res
			, BrlyQFlt1NConnection** rec
		) {
	char* ptr;

	BrlyQFlt1NConnection* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQFlt1NConnection();

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

ubigint PgTblBrlyQFlt1NConnection::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQFlt1NConnection& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQFlt1NConnection* rec;

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
			rec = new BrlyQFlt1NConnection();

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

bool PgTblBrlyQFlt1NConnection::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQFlt1NConnection** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFlt1NConnection / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFlt1NConnection::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQFlt1NConnection& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFlt1NConnection / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQFlt1NConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQFlt1NConnection** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFlt1NConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFlt1NConnection& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQFlt1NConnection::insertRec(
			BrlyQFlt1NConnection* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQFlt1NConnection_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFlt1NConnection_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQFlt1NConnection::insertRst(
			ListBrlyQFlt1NConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQFlt1NConnection::updateRec(
			BrlyQFlt1NConnection* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQFlt1NConnection_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFlt1NConnection_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQFlt1NConnection::updateRst(
			ListBrlyQFlt1NConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQFlt1NConnection::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFlt1NConnection_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFlt1NConnection_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQFlt1NConnection::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFlt1NConnection_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFlt1NConnection_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQFlt1NConnection::loadRecByQref(
			ubigint qref
			, BrlyQFlt1NConnection** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQFlt1NConnection_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQFlt1NConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFlt1NConnection& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQFlt1NConnection_loadRstByJref", 1, vals, l, f, append, rst);
};

