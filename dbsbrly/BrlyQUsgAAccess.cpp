/**
  * \file BrlyQUsgAAccess.cpp
  * Dbs and XML wrapper for table TblBrlyQUsgAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQUsgAAccess.h"

/******************************************************************************
 class BrlyQUsgAAccess
 ******************************************************************************/

BrlyQUsgAAccess::BrlyQUsgAAccess(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxBrlyVCard
			, const string srefX1IxBrlyVCard
			, const string titX1IxBrlyVCard
			, const uint ixBrlyWUiaccess
			, const string srefsIxBrlyWUiaccess
			, const string titsIxBrlyWUiaccess
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1IxBrlyVCard = x1IxBrlyVCard;
	this->srefX1IxBrlyVCard = srefX1IxBrlyVCard;
	this->titX1IxBrlyVCard = titX1IxBrlyVCard;
	this->ixBrlyWUiaccess = ixBrlyWUiaccess;
	this->srefsIxBrlyWUiaccess = srefsIxBrlyWUiaccess;
	this->titsIxBrlyWUiaccess = titsIxBrlyWUiaccess;
};

void BrlyQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsgAAccess";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "crd", srefX1IxBrlyVCard);
		writeString(wr, "crd2", titX1IxBrlyVCard);
		writeString(wr, "uac", srefsIxBrlyWUiaccess);
		writeString(wr, "uac2", titsIxBrlyWUiaccess);
	} else {
		writeString(wr, "srefX1IxBrlyVCard", srefX1IxBrlyVCard);
		writeString(wr, "titX1IxBrlyVCard", titX1IxBrlyVCard);
		writeString(wr, "srefsIxBrlyWUiaccess", srefsIxBrlyWUiaccess);
		writeString(wr, "titsIxBrlyWUiaccess", titsIxBrlyWUiaccess);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQUsgAAccess
 ******************************************************************************/

ListBrlyQUsgAAccess::ListBrlyQUsgAAccess() {
};

ListBrlyQUsgAAccess::ListBrlyQUsgAAccess(
			const ListBrlyQUsgAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsgAAccess(*(src.nodes[i]));
};

ListBrlyQUsgAAccess::~ListBrlyQUsgAAccess() {
	clear();
};

void ListBrlyQUsgAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsgAAccess::size() const {
	return(nodes.size());
};

void ListBrlyQUsgAAccess::append(
			BrlyQUsgAAccess* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsgAAccess& ListBrlyQUsgAAccess::operator=(
			const ListBrlyQUsgAAccess& src
		) {
	BrlyQUsgAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQUsgAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsgAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsgAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsgAAccess
 ******************************************************************************/

TblBrlyQUsgAAccess::TblBrlyQUsgAAccess() {
};

TblBrlyQUsgAAccess::~TblBrlyQUsgAAccess() {
};

bool TblBrlyQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgAAccess** rec
		) {
	return false;
};

ubigint TblBrlyQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	return 0;
};

void TblBrlyQUsgAAccess::insertRec(
			BrlyQUsgAAccess* rec
		) {
};

ubigint TblBrlyQUsgAAccess::insertNewRec(
			BrlyQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxBrlyVCard
			, const string srefX1IxBrlyVCard
			, const string titX1IxBrlyVCard
			, const uint ixBrlyWUiaccess
			, const string srefsIxBrlyWUiaccess
			, const string titsIxBrlyWUiaccess
		) {
	ubigint retval = 0;
	BrlyQUsgAAccess* _rec = NULL;

	_rec = new BrlyQUsgAAccess(0, jref, jnum, ref, x1IxBrlyVCard, srefX1IxBrlyVCard, titX1IxBrlyVCard, ixBrlyWUiaccess, srefsIxBrlyWUiaccess, titsIxBrlyWUiaccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsgAAccess::appendNewRecToRst(
			ListBrlyQUsgAAccess& rst
			, BrlyQUsgAAccess** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1IxBrlyVCard
			, const string srefX1IxBrlyVCard
			, const string titX1IxBrlyVCard
			, const uint ixBrlyWUiaccess
			, const string srefsIxBrlyWUiaccess
			, const string titsIxBrlyWUiaccess
		) {
	ubigint retval = 0;
	BrlyQUsgAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxBrlyVCard, srefX1IxBrlyVCard, titX1IxBrlyVCard, ixBrlyWUiaccess, srefsIxBrlyWUiaccess, titsIxBrlyWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsgAAccess::insertRst(
			ListBrlyQUsgAAccess& rst
		) {
};

void TblBrlyQUsgAAccess::updateRec(
			BrlyQUsgAAccess* rec
		) {
};

void TblBrlyQUsgAAccess::updateRst(
			ListBrlyQUsgAAccess& rst
		) {
};

void TblBrlyQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsgAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsgAAccess** rec
		) {
	return false;
};

ubigint TblBrlyQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQUsgAAccess
 ******************************************************************************/

MyTblBrlyQUsgAAccess::MyTblBrlyQUsgAAccess() : TblBrlyQUsgAAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsgAAccess::~MyTblBrlyQUsgAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsgAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsgAAccess (jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsgAAccess SET jref = ?, jnum = ?, ref = ?, x1IxBrlyVCard = ?, ixBrlyWUiaccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsgAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsgAAccess WHERE jref = ?", false);
};

bool MyTblBrlyQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsgAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQUsgAAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQUsgAAccess();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1IxBrlyVCard = atol((char*) dbrow[4]); else _rec->x1IxBrlyVCard = 0;
		if (dbrow[5]) _rec->ixBrlyWUiaccess = atol((char*) dbrow[5]); else _rec->ixBrlyWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsgAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQUsgAAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQUsgAAccess();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1IxBrlyVCard = atol((char*) dbrow[4]); else rec->x1IxBrlyVCard = 0;
			if (dbrow[5]) rec->ixBrlyWUiaccess = atol((char*) dbrow[5]); else rec->ixBrlyWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQUsgAAccess::insertRec(
			BrlyQUsgAAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxBrlyVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyWUiaccess,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsgAAccess / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsgAAccess / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQUsgAAccess::insertRst(
			ListBrlyQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsgAAccess::updateRec(
			BrlyQUsgAAccess* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxBrlyVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyWUiaccess,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsgAAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsgAAccess / stmtUpdateRec)\n");
};

void MyTblBrlyQUsgAAccess::updateRst(
			ListBrlyQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsgAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsgAAccess / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsgAAccess / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQUsgAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsgAAccess / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsgAAccess / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQUsgAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsgAAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQUsgAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsgAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQUsgAAccess
 ******************************************************************************/

PgTblBrlyQUsgAAccess::PgTblBrlyQUsgAAccess() : TblBrlyQUsgAAccess(), PgTable() {
};

PgTblBrlyQUsgAAccess::~PgTblBrlyQUsgAAccess() {
};

void PgTblBrlyQUsgAAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQUsgAAccess_insertRec", "INSERT INTO TblBrlyQUsgAAccess (jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsgAAccess_updateRec", "UPDATE TblBrlyQUsgAAccess SET jref = $1, jnum = $2, ref = $3, x1IxBrlyVCard = $4, ixBrlyWUiaccess = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsgAAccess_removeRecByQref", "DELETE FROM TblBrlyQUsgAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsgAAccess_removeRstByJref", "DELETE FROM TblBrlyQUsgAAccess WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQUsgAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyQUsgAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsgAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyQUsgAAccess WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQUsgAAccess::loadRec(
			PGresult* res
			, BrlyQUsgAAccess** rec
		) {
	char* ptr;

	BrlyQUsgAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsgAAccess();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixbrlyvcard"),
			PQfnumber(res, "ixbrlywuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1IxBrlyVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixBrlyWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQUsgAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsgAAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1ixbrlyvcard"),
			PQfnumber(res, "ixbrlywuiaccess")
		};

		while (numread < numrow) {
			rec = new BrlyQUsgAAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1IxBrlyVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixBrlyWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQUsgAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsgAAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsgAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsgAAccess / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsgAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsgAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsgAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQUsgAAccess::insertRec(
			BrlyQUsgAAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxBrlyVCard = htonl(rec->x1IxBrlyVCard);
	uint _ixBrlyWUiaccess = htonl(rec->ixBrlyWUiaccess);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxBrlyVCard,
		(char*) &_ixBrlyWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsgAAccess_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsgAAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQUsgAAccess::insertRst(
			ListBrlyQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsgAAccess::updateRec(
			BrlyQUsgAAccess* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1IxBrlyVCard = htonl(rec->x1IxBrlyVCard);
	uint _ixBrlyWUiaccess = htonl(rec->ixBrlyWUiaccess);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1IxBrlyVCard,
		(char*) &_ixBrlyWUiaccess,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsgAAccess_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsgAAccess_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQUsgAAccess::updateRst(
			ListBrlyQUsgAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsgAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsgAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsgAAccess_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQUsgAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsgAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsgAAccess_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQUsgAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsgAAccess** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQUsgAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsgAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsgAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsgAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};

