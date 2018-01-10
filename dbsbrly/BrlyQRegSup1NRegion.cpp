/**
  * \file BrlyQRegSup1NRegion.cpp
  * Dbs and XML wrapper for table TblBrlyQRegSup1NRegion (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQRegSup1NRegion.h"

/******************************************************************************
 class BrlyQRegSup1NRegion
 ******************************************************************************/

BrlyQRegSup1NRegion::BrlyQRegSup1NRegion(
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

void BrlyQRegSup1NRegion::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQRegSup1NRegion";

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
 class ListBrlyQRegSup1NRegion
 ******************************************************************************/

ListBrlyQRegSup1NRegion::ListBrlyQRegSup1NRegion() {
};

ListBrlyQRegSup1NRegion::ListBrlyQRegSup1NRegion(
			const ListBrlyQRegSup1NRegion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRegSup1NRegion(*(src.nodes[i]));
};

ListBrlyQRegSup1NRegion::~ListBrlyQRegSup1NRegion() {
	clear();
};

void ListBrlyQRegSup1NRegion::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQRegSup1NRegion::size() const {
	return(nodes.size());
};

void ListBrlyQRegSup1NRegion::append(
			BrlyQRegSup1NRegion* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQRegSup1NRegion& ListBrlyQRegSup1NRegion::operator=(
			const ListBrlyQRegSup1NRegion& src
		) {
	BrlyQRegSup1NRegion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQRegSup1NRegion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQRegSup1NRegion::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQRegSup1NRegion";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQRegSup1NRegion
 ******************************************************************************/

TblBrlyQRegSup1NRegion::TblBrlyQRegSup1NRegion() {
};

TblBrlyQRegSup1NRegion::~TblBrlyQRegSup1NRegion() {
};

bool TblBrlyQRegSup1NRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegSup1NRegion** rec
		) {
	return false;
};

ubigint TblBrlyQRegSup1NRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	return 0;
};

void TblBrlyQRegSup1NRegion::insertRec(
			BrlyQRegSup1NRegion* rec
		) {
};

ubigint TblBrlyQRegSup1NRegion::insertNewRec(
			BrlyQRegSup1NRegion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQRegSup1NRegion* _rec = NULL;

	_rec = new BrlyQRegSup1NRegion(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQRegSup1NRegion::appendNewRecToRst(
			ListBrlyQRegSup1NRegion& rst
			, BrlyQRegSup1NRegion** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQRegSup1NRegion* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQRegSup1NRegion::insertRst(
			ListBrlyQRegSup1NRegion& rst
		) {
};

void TblBrlyQRegSup1NRegion::updateRec(
			BrlyQRegSup1NRegion* rec
		) {
};

void TblBrlyQRegSup1NRegion::updateRst(
			ListBrlyQRegSup1NRegion& rst
		) {
};

void TblBrlyQRegSup1NRegion::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQRegSup1NRegion::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQRegSup1NRegion::loadRecByQref(
			ubigint qref
			, BrlyQRegSup1NRegion** rec
		) {
	return false;
};

ubigint TblBrlyQRegSup1NRegion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQRegSup1NRegion
 ******************************************************************************/

MyTblBrlyQRegSup1NRegion::MyTblBrlyQRegSup1NRegion() : TblBrlyQRegSup1NRegion(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQRegSup1NRegion::~MyTblBrlyQRegSup1NRegion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQRegSup1NRegion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQRegSup1NRegion (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQRegSup1NRegion SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQRegSup1NRegion WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQRegSup1NRegion WHERE jref = ?", false);
};

bool MyTblBrlyQRegSup1NRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegSup1NRegion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQRegSup1NRegion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQRegSup1NRegion / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQRegSup1NRegion();

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

ubigint MyTblBrlyQRegSup1NRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQRegSup1NRegion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQRegSup1NRegion / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQRegSup1NRegion();

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

void MyTblBrlyQRegSup1NRegion::insertRec(
			BrlyQRegSup1NRegion* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRegSup1NRegion / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRegSup1NRegion / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQRegSup1NRegion::insertRst(
			ListBrlyQRegSup1NRegion& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQRegSup1NRegion::updateRec(
			BrlyQRegSup1NRegion* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRegSup1NRegion / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRegSup1NRegion / stmtUpdateRec)\n");
};

void MyTblBrlyQRegSup1NRegion::updateRst(
			ListBrlyQRegSup1NRegion& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQRegSup1NRegion::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRegSup1NRegion / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRegSup1NRegion / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQRegSup1NRegion::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRegSup1NRegion / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRegSup1NRegion / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQRegSup1NRegion::loadRecByQref(
			ubigint qref
			, BrlyQRegSup1NRegion** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQRegSup1NRegion WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQRegSup1NRegion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQRegSup1NRegion WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQRegSup1NRegion
 ******************************************************************************/

PgTblBrlyQRegSup1NRegion::PgTblBrlyQRegSup1NRegion() : TblBrlyQRegSup1NRegion(), PgTable() {
};

PgTblBrlyQRegSup1NRegion::~PgTblBrlyQRegSup1NRegion() {
};

void PgTblBrlyQRegSup1NRegion::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQRegSup1NRegion_insertRec", "INSERT INTO TblBrlyQRegSup1NRegion (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRegSup1NRegion_updateRec", "UPDATE TblBrlyQRegSup1NRegion SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRegSup1NRegion_removeRecByQref", "DELETE FROM TblBrlyQRegSup1NRegion WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRegSup1NRegion_removeRstByJref", "DELETE FROM TblBrlyQRegSup1NRegion WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQRegSup1NRegion_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQRegSup1NRegion WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRegSup1NRegion_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQRegSup1NRegion WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQRegSup1NRegion::loadRec(
			PGresult* res
			, BrlyQRegSup1NRegion** rec
		) {
	char* ptr;

	BrlyQRegSup1NRegion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQRegSup1NRegion();

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

ubigint PgTblBrlyQRegSup1NRegion::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQRegSup1NRegion* rec;

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
			rec = new BrlyQRegSup1NRegion();

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

bool PgTblBrlyQRegSup1NRegion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQRegSup1NRegion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegSup1NRegion / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRegSup1NRegion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegSup1NRegion / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQRegSup1NRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegSup1NRegion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRegSup1NRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQRegSup1NRegion::insertRec(
			BrlyQRegSup1NRegion* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQRegSup1NRegion_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegSup1NRegion_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQRegSup1NRegion::insertRst(
			ListBrlyQRegSup1NRegion& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQRegSup1NRegion::updateRec(
			BrlyQRegSup1NRegion* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQRegSup1NRegion_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegSup1NRegion_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQRegSup1NRegion::updateRst(
			ListBrlyQRegSup1NRegion& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQRegSup1NRegion::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRegSup1NRegion_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegSup1NRegion_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQRegSup1NRegion::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRegSup1NRegion_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegSup1NRegion_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQRegSup1NRegion::loadRecByQref(
			ubigint qref
			, BrlyQRegSup1NRegion** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQRegSup1NRegion_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQRegSup1NRegion::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegSup1NRegion& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQRegSup1NRegion_loadRstByJref", 1, vals, l, f, append, rst);
};

