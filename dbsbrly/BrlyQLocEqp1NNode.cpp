/**
  * \file BrlyQLocEqp1NNode.cpp
  * Dbs and XML wrapper for table TblBrlyQLocEqp1NNode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLocEqp1NNode.h"

/******************************************************************************
 class BrlyQLocEqp1NNode
 ******************************************************************************/

BrlyQLocEqp1NNode::BrlyQLocEqp1NNode(
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

void BrlyQLocEqp1NNode::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocEqp1NNode";

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
 class ListBrlyQLocEqp1NNode
 ******************************************************************************/

ListBrlyQLocEqp1NNode::ListBrlyQLocEqp1NNode() {
};

ListBrlyQLocEqp1NNode::ListBrlyQLocEqp1NNode(
			const ListBrlyQLocEqp1NNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocEqp1NNode(*(src.nodes[i]));
};

ListBrlyQLocEqp1NNode::~ListBrlyQLocEqp1NNode() {
	clear();
};

void ListBrlyQLocEqp1NNode::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocEqp1NNode::size() const {
	return(nodes.size());
};

void ListBrlyQLocEqp1NNode::append(
			BrlyQLocEqp1NNode* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocEqp1NNode& ListBrlyQLocEqp1NNode::operator=(
			const ListBrlyQLocEqp1NNode& src
		) {
	BrlyQLocEqp1NNode* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLocEqp1NNode(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocEqp1NNode::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocEqp1NNode";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocEqp1NNode
 ******************************************************************************/

TblBrlyQLocEqp1NNode::TblBrlyQLocEqp1NNode() {
};

TblBrlyQLocEqp1NNode::~TblBrlyQLocEqp1NNode() {
};

bool TblBrlyQLocEqp1NNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocEqp1NNode** rec
		) {
	return false;
};

ubigint TblBrlyQLocEqp1NNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocEqp1NNode& rst
		) {
	return 0;
};

void TblBrlyQLocEqp1NNode::insertRec(
			BrlyQLocEqp1NNode* rec
		) {
};

ubigint TblBrlyQLocEqp1NNode::insertNewRec(
			BrlyQLocEqp1NNode** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQLocEqp1NNode* _rec = NULL;

	_rec = new BrlyQLocEqp1NNode(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocEqp1NNode::appendNewRecToRst(
			ListBrlyQLocEqp1NNode& rst
			, BrlyQLocEqp1NNode** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	BrlyQLocEqp1NNode* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocEqp1NNode::insertRst(
			ListBrlyQLocEqp1NNode& rst
		) {
};

void TblBrlyQLocEqp1NNode::updateRec(
			BrlyQLocEqp1NNode* rec
		) {
};

void TblBrlyQLocEqp1NNode::updateRst(
			ListBrlyQLocEqp1NNode& rst
		) {
};

void TblBrlyQLocEqp1NNode::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocEqp1NNode::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocEqp1NNode::loadRecByQref(
			ubigint qref
			, BrlyQLocEqp1NNode** rec
		) {
	return false;
};

ubigint TblBrlyQLocEqp1NNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocEqp1NNode& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLocEqp1NNode
 ******************************************************************************/

MyTblBrlyQLocEqp1NNode::MyTblBrlyQLocEqp1NNode() : TblBrlyQLocEqp1NNode(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocEqp1NNode::~MyTblBrlyQLocEqp1NNode() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocEqp1NNode::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocEqp1NNode (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocEqp1NNode SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocEqp1NNode WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocEqp1NNode WHERE jref = ?", false);
};

bool MyTblBrlyQLocEqp1NNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocEqp1NNode** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocEqp1NNode* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLocEqp1NNode / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLocEqp1NNode();

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

ubigint MyTblBrlyQLocEqp1NNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocEqp1NNode& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocEqp1NNode* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLocEqp1NNode / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLocEqp1NNode();

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

void MyTblBrlyQLocEqp1NNode::insertRec(
			BrlyQLocEqp1NNode* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocEqp1NNode / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocEqp1NNode / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLocEqp1NNode::insertRst(
			ListBrlyQLocEqp1NNode& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocEqp1NNode::updateRec(
			BrlyQLocEqp1NNode* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocEqp1NNode / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocEqp1NNode / stmtUpdateRec)\n");
};

void MyTblBrlyQLocEqp1NNode::updateRst(
			ListBrlyQLocEqp1NNode& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocEqp1NNode::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocEqp1NNode / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocEqp1NNode / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLocEqp1NNode::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocEqp1NNode / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocEqp1NNode / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLocEqp1NNode::loadRecByQref(
			ubigint qref
			, BrlyQLocEqp1NNode** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLocEqp1NNode WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocEqp1NNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocEqp1NNode& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocEqp1NNode WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLocEqp1NNode
 ******************************************************************************/

PgTblBrlyQLocEqp1NNode::PgTblBrlyQLocEqp1NNode() : TblBrlyQLocEqp1NNode(), PgTable() {
};

PgTblBrlyQLocEqp1NNode::~PgTblBrlyQLocEqp1NNode() {
};

void PgTblBrlyQLocEqp1NNode::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLocEqp1NNode_insertRec", "INSERT INTO TblBrlyQLocEqp1NNode (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocEqp1NNode_updateRec", "UPDATE TblBrlyQLocEqp1NNode SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocEqp1NNode_removeRecByQref", "DELETE FROM TblBrlyQLocEqp1NNode WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocEqp1NNode_removeRstByJref", "DELETE FROM TblBrlyQLocEqp1NNode WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLocEqp1NNode_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblBrlyQLocEqp1NNode WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocEqp1NNode_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblBrlyQLocEqp1NNode WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLocEqp1NNode::loadRec(
			PGresult* res
			, BrlyQLocEqp1NNode** rec
		) {
	char* ptr;

	BrlyQLocEqp1NNode* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocEqp1NNode();

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

ubigint PgTblBrlyQLocEqp1NNode::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocEqp1NNode& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocEqp1NNode* rec;

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
			rec = new BrlyQLocEqp1NNode();

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

bool PgTblBrlyQLocEqp1NNode::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocEqp1NNode** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocEqp1NNode / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocEqp1NNode::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocEqp1NNode& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocEqp1NNode / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocEqp1NNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocEqp1NNode** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocEqp1NNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocEqp1NNode& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLocEqp1NNode::insertRec(
			BrlyQLocEqp1NNode* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQLocEqp1NNode_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocEqp1NNode_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLocEqp1NNode::insertRst(
			ListBrlyQLocEqp1NNode& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocEqp1NNode::updateRec(
			BrlyQLocEqp1NNode* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQLocEqp1NNode_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocEqp1NNode_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLocEqp1NNode::updateRst(
			ListBrlyQLocEqp1NNode& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocEqp1NNode::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocEqp1NNode_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocEqp1NNode_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLocEqp1NNode::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocEqp1NNode_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocEqp1NNode_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLocEqp1NNode::loadRecByQref(
			ubigint qref
			, BrlyQLocEqp1NNode** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLocEqp1NNode_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocEqp1NNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocEqp1NNode& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocEqp1NNode_loadRstByJref", 1, vals, l, f, append, rst);
};

