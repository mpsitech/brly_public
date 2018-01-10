/**
  * \file BrlyQFltEqpMNConnection.cpp
  * Dbs and XML wrapper for table TblBrlyQFltEqpMNConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQFltEqpMNConnection.h"

/******************************************************************************
 class BrlyQFltEqpMNConnection
 ******************************************************************************/

BrlyQFltEqpMNConnection::BrlyQFltEqpMNConnection(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->conIxBrlyVLat = conIxBrlyVLat;
	this->srefConIxBrlyVLat = srefConIxBrlyVLat;
};

void BrlyQFltEqpMNConnection::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQFltEqpMNConnection";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "lat", srefConIxBrlyVLat);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefConIxBrlyVLat", srefConIxBrlyVLat);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQFltEqpMNConnection
 ******************************************************************************/

ListBrlyQFltEqpMNConnection::ListBrlyQFltEqpMNConnection() {
};

ListBrlyQFltEqpMNConnection::ListBrlyQFltEqpMNConnection(
			const ListBrlyQFltEqpMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltEqpMNConnection(*(src.nodes[i]));
};

ListBrlyQFltEqpMNConnection::~ListBrlyQFltEqpMNConnection() {
	clear();
};

void ListBrlyQFltEqpMNConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQFltEqpMNConnection::size() const {
	return(nodes.size());
};

void ListBrlyQFltEqpMNConnection::append(
			BrlyQFltEqpMNConnection* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQFltEqpMNConnection& ListBrlyQFltEqpMNConnection::operator=(
			const ListBrlyQFltEqpMNConnection& src
		) {
	BrlyQFltEqpMNConnection* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQFltEqpMNConnection(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQFltEqpMNConnection::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQFltEqpMNConnection";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQFltEqpMNConnection
 ******************************************************************************/

TblBrlyQFltEqpMNConnection::TblBrlyQFltEqpMNConnection() {
};

TblBrlyQFltEqpMNConnection::~TblBrlyQFltEqpMNConnection() {
};

bool TblBrlyQFltEqpMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltEqpMNConnection** rec
		) {
	return false;
};

ubigint TblBrlyQFltEqpMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltEqpMNConnection& rst
		) {
	return 0;
};

void TblBrlyQFltEqpMNConnection::insertRec(
			BrlyQFltEqpMNConnection* rec
		) {
};

ubigint TblBrlyQFltEqpMNConnection::insertNewRec(
			BrlyQFltEqpMNConnection** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
		) {
	ubigint retval = 0;
	BrlyQFltEqpMNConnection* _rec = NULL;

	_rec = new BrlyQFltEqpMNConnection(0, jref, jnum, mref, stubMref, ref, conIxBrlyVLat, srefConIxBrlyVLat);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQFltEqpMNConnection::appendNewRecToRst(
			ListBrlyQFltEqpMNConnection& rst
			, BrlyQFltEqpMNConnection** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
		) {
	ubigint retval = 0;
	BrlyQFltEqpMNConnection* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, conIxBrlyVLat, srefConIxBrlyVLat);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQFltEqpMNConnection::insertRst(
			ListBrlyQFltEqpMNConnection& rst
		) {
};

void TblBrlyQFltEqpMNConnection::updateRec(
			BrlyQFltEqpMNConnection* rec
		) {
};

void TblBrlyQFltEqpMNConnection::updateRst(
			ListBrlyQFltEqpMNConnection& rst
		) {
};

void TblBrlyQFltEqpMNConnection::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQFltEqpMNConnection::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQFltEqpMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQFltEqpMNConnection** rec
		) {
	return false;
};

ubigint TblBrlyQFltEqpMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltEqpMNConnection& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQFltEqpMNConnection
 ******************************************************************************/

MyTblBrlyQFltEqpMNConnection::MyTblBrlyQFltEqpMNConnection() : TblBrlyQFltEqpMNConnection(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQFltEqpMNConnection::~MyTblBrlyQFltEqpMNConnection() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQFltEqpMNConnection::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQFltEqpMNConnection (jref, jnum, mref, ref, conIxBrlyVLat) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQFltEqpMNConnection SET jref = ?, jnum = ?, mref = ?, ref = ?, conIxBrlyVLat = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQFltEqpMNConnection WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQFltEqpMNConnection WHERE jref = ?", false);
};

bool MyTblBrlyQFltEqpMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltEqpMNConnection** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQFltEqpMNConnection* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltEqpMNConnection / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQFltEqpMNConnection();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->conIxBrlyVLat = atol((char*) dbrow[5]); else _rec->conIxBrlyVLat = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQFltEqpMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltEqpMNConnection& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQFltEqpMNConnection* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltEqpMNConnection / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQFltEqpMNConnection();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->conIxBrlyVLat = atol((char*) dbrow[5]); else rec->conIxBrlyVLat = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQFltEqpMNConnection::insertRec(
			BrlyQFltEqpMNConnection* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->conIxBrlyVLat,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltEqpMNConnection / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltEqpMNConnection / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQFltEqpMNConnection::insertRst(
			ListBrlyQFltEqpMNConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQFltEqpMNConnection::updateRec(
			BrlyQFltEqpMNConnection* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->conIxBrlyVLat,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltEqpMNConnection / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltEqpMNConnection / stmtUpdateRec)\n");
};

void MyTblBrlyQFltEqpMNConnection::updateRst(
			ListBrlyQFltEqpMNConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQFltEqpMNConnection::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltEqpMNConnection / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltEqpMNConnection / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQFltEqpMNConnection::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltEqpMNConnection / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltEqpMNConnection / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQFltEqpMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQFltEqpMNConnection** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQFltEqpMNConnection WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQFltEqpMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltEqpMNConnection& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQFltEqpMNConnection WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQFltEqpMNConnection
 ******************************************************************************/

PgTblBrlyQFltEqpMNConnection::PgTblBrlyQFltEqpMNConnection() : TblBrlyQFltEqpMNConnection(), PgTable() {
};

PgTblBrlyQFltEqpMNConnection::~PgTblBrlyQFltEqpMNConnection() {
};

void PgTblBrlyQFltEqpMNConnection::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQFltEqpMNConnection_insertRec", "INSERT INTO TblBrlyQFltEqpMNConnection (jref, jnum, mref, ref, conIxBrlyVLat) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltEqpMNConnection_updateRec", "UPDATE TblBrlyQFltEqpMNConnection SET jref = $1, jnum = $2, mref = $3, ref = $4, conIxBrlyVLat = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltEqpMNConnection_removeRecByQref", "DELETE FROM TblBrlyQFltEqpMNConnection WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltEqpMNConnection_removeRstByJref", "DELETE FROM TblBrlyQFltEqpMNConnection WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQFltEqpMNConnection_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, conIxBrlyVLat FROM TblBrlyQFltEqpMNConnection WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltEqpMNConnection_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, conIxBrlyVLat FROM TblBrlyQFltEqpMNConnection WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQFltEqpMNConnection::loadRec(
			PGresult* res
			, BrlyQFltEqpMNConnection** rec
		) {
	char* ptr;

	BrlyQFltEqpMNConnection* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQFltEqpMNConnection();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "conixbrlyvlat")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->conIxBrlyVLat = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQFltEqpMNConnection::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQFltEqpMNConnection& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQFltEqpMNConnection* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "conixbrlyvlat")
		};

		while (numread < numrow) {
			rec = new BrlyQFltEqpMNConnection();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->conIxBrlyVLat = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQFltEqpMNConnection::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQFltEqpMNConnection** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltEqpMNConnection / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltEqpMNConnection::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQFltEqpMNConnection& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltEqpMNConnection / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQFltEqpMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltEqpMNConnection** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltEqpMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltEqpMNConnection& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQFltEqpMNConnection::insertRec(
			BrlyQFltEqpMNConnection* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _conIxBrlyVLat = htonl(rec->conIxBrlyVLat);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_conIxBrlyVLat
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltEqpMNConnection_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltEqpMNConnection_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQFltEqpMNConnection::insertRst(
			ListBrlyQFltEqpMNConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQFltEqpMNConnection::updateRec(
			BrlyQFltEqpMNConnection* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _conIxBrlyVLat = htonl(rec->conIxBrlyVLat);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_conIxBrlyVLat,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltEqpMNConnection_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltEqpMNConnection_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQFltEqpMNConnection::updateRst(
			ListBrlyQFltEqpMNConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQFltEqpMNConnection::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFltEqpMNConnection_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltEqpMNConnection_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQFltEqpMNConnection::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFltEqpMNConnection_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltEqpMNConnection_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQFltEqpMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQFltEqpMNConnection** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQFltEqpMNConnection_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQFltEqpMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltEqpMNConnection& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQFltEqpMNConnection_loadRstByJref", 1, vals, l, f, append, rst);
};

