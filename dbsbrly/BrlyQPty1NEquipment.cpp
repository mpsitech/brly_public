/**
  * \file BrlyQPty1NEquipment.cpp
  * Dbs and XML wrapper for table TblBrlyQPty1NEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQPty1NEquipment.h"

/******************************************************************************
 class BrlyQPty1NEquipment
 ******************************************************************************/

BrlyQPty1NEquipment::BrlyQPty1NEquipment(
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

void BrlyQPty1NEquipment::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQPty1NEquipment";

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
 class ListBrlyQPty1NEquipment
 ******************************************************************************/

ListBrlyQPty1NEquipment::ListBrlyQPty1NEquipment() {
};

ListBrlyQPty1NEquipment::ListBrlyQPty1NEquipment(
			const ListBrlyQPty1NEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPty1NEquipment(*(src.nodes[i]));
};

ListBrlyQPty1NEquipment::~ListBrlyQPty1NEquipment() {
	clear();
};

void ListBrlyQPty1NEquipment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQPty1NEquipment::size() const {
	return(nodes.size());
};

void ListBrlyQPty1NEquipment::append(
			BrlyQPty1NEquipment* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQPty1NEquipment& ListBrlyQPty1NEquipment::operator=(
			const ListBrlyQPty1NEquipment& src
		) {
	BrlyQPty1NEquipment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQPty1NEquipment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQPty1NEquipment::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQPty1NEquipment";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQPty1NEquipment
 ******************************************************************************/

TblBrlyQPty1NEquipment::TblBrlyQPty1NEquipment() {
};

TblBrlyQPty1NEquipment::~TblBrlyQPty1NEquipment() {
};

bool TblBrlyQPty1NEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyQPty1NEquipment** rec
		) {
	return false;
};

ubigint TblBrlyQPty1NEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPty1NEquipment& rst
		) {
	return 0;
};

void TblBrlyQPty1NEquipment::insertRec(
			BrlyQPty1NEquipment* rec
		) {
};

ubigint TblBrlyQPty1NEquipment::insertNewRec(
			BrlyQPty1NEquipment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQPty1NEquipment* _rec = NULL;

	_rec = new BrlyQPty1NEquipment(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQPty1NEquipment::appendNewRecToRst(
			ListBrlyQPty1NEquipment& rst
			, BrlyQPty1NEquipment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQPty1NEquipment* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQPty1NEquipment::insertRst(
			ListBrlyQPty1NEquipment& rst
		) {
};

void TblBrlyQPty1NEquipment::updateRec(
			BrlyQPty1NEquipment* rec
		) {
};

void TblBrlyQPty1NEquipment::updateRst(
			ListBrlyQPty1NEquipment& rst
		) {
};

void TblBrlyQPty1NEquipment::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQPty1NEquipment::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQPty1NEquipment::loadRecByQref(
			ubigint qref
			, BrlyQPty1NEquipment** rec
		) {
	return false;
};

ubigint TblBrlyQPty1NEquipment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPty1NEquipment& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQPty1NEquipment
 ******************************************************************************/

MyTblBrlyQPty1NEquipment::MyTblBrlyQPty1NEquipment() : TblBrlyQPty1NEquipment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQPty1NEquipment::~MyTblBrlyQPty1NEquipment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQPty1NEquipment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQPty1NEquipment (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQPty1NEquipment SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQPty1NEquipment WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQPty1NEquipment WHERE jref = ?", false);
};

bool MyTblBrlyQPty1NEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyQPty1NEquipment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQPty1NEquipment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQPty1NEquipment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQPty1NEquipment();

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

ubigint MyTblBrlyQPty1NEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPty1NEquipment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQPty1NEquipment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQPty1NEquipment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQPty1NEquipment();

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

void MyTblBrlyQPty1NEquipment::insertRec(
			BrlyQPty1NEquipment* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQPty1NEquipment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQPty1NEquipment / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQPty1NEquipment::insertRst(
			ListBrlyQPty1NEquipment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQPty1NEquipment::updateRec(
			BrlyQPty1NEquipment* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQPty1NEquipment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQPty1NEquipment / stmtUpdateRec)\n");
};

void MyTblBrlyQPty1NEquipment::updateRst(
			ListBrlyQPty1NEquipment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQPty1NEquipment::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQPty1NEquipment / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQPty1NEquipment / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQPty1NEquipment::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQPty1NEquipment / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQPty1NEquipment / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQPty1NEquipment::loadRecByQref(
			ubigint qref
			, BrlyQPty1NEquipment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQPty1NEquipment WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQPty1NEquipment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPty1NEquipment& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQPty1NEquipment WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQPty1NEquipment
 ******************************************************************************/

PgTblBrlyQPty1NEquipment::PgTblBrlyQPty1NEquipment() : TblBrlyQPty1NEquipment(), PgTable() {
};

PgTblBrlyQPty1NEquipment::~PgTblBrlyQPty1NEquipment() {
};

void PgTblBrlyQPty1NEquipment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQPty1NEquipment_insertRec", "INSERT INTO TblBrlyQPty1NEquipment (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQPty1NEquipment_updateRec", "UPDATE TblBrlyQPty1NEquipment SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQPty1NEquipment_removeRecByQref", "DELETE FROM TblBrlyQPty1NEquipment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQPty1NEquipment_removeRstByJref", "DELETE FROM TblBrlyQPty1NEquipment WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQPty1NEquipment_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQPty1NEquipment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQPty1NEquipment_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQPty1NEquipment WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQPty1NEquipment::loadRec(
			PGresult* res
			, BrlyQPty1NEquipment** rec
		) {
	char* ptr;

	BrlyQPty1NEquipment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQPty1NEquipment();

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

ubigint PgTblBrlyQPty1NEquipment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQPty1NEquipment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQPty1NEquipment* rec;

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
			rec = new BrlyQPty1NEquipment();

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

bool PgTblBrlyQPty1NEquipment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQPty1NEquipment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPty1NEquipment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQPty1NEquipment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQPty1NEquipment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPty1NEquipment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQPty1NEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyQPty1NEquipment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQPty1NEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPty1NEquipment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQPty1NEquipment::insertRec(
			BrlyQPty1NEquipment* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQPty1NEquipment_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPty1NEquipment_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQPty1NEquipment::insertRst(
			ListBrlyQPty1NEquipment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQPty1NEquipment::updateRec(
			BrlyQPty1NEquipment* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQPty1NEquipment_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPty1NEquipment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQPty1NEquipment::updateRst(
			ListBrlyQPty1NEquipment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQPty1NEquipment::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQPty1NEquipment_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPty1NEquipment_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQPty1NEquipment::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQPty1NEquipment_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPty1NEquipment_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQPty1NEquipment::loadRecByQref(
			ubigint qref
			, BrlyQPty1NEquipment** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQPty1NEquipment_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQPty1NEquipment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPty1NEquipment& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQPty1NEquipment_loadRstByJref", 1, vals, l, f, append, rst);
};

