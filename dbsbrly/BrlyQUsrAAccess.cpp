/**
  * \file BrlyQUsrAAccess.cpp
  * Dbs and XML wrapper for table TblBrlyQUsrAAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQUsrAAccess.h"

/******************************************************************************
 class BrlyQUsrAAccess
 ******************************************************************************/

BrlyQUsrAAccess::BrlyQUsrAAccess(
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

void BrlyQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsrAAccess";

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
 class ListBrlyQUsrAAccess
 ******************************************************************************/

ListBrlyQUsrAAccess::ListBrlyQUsrAAccess() {
};

ListBrlyQUsrAAccess::ListBrlyQUsrAAccess(
			const ListBrlyQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrAAccess(*(src.nodes[i]));
};

ListBrlyQUsrAAccess::~ListBrlyQUsrAAccess() {
	clear();
};

void ListBrlyQUsrAAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsrAAccess::size() const {
	return(nodes.size());
};

void ListBrlyQUsrAAccess::append(
			BrlyQUsrAAccess* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsrAAccess& ListBrlyQUsrAAccess::operator=(
			const ListBrlyQUsrAAccess& src
		) {
	BrlyQUsrAAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQUsrAAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsrAAccess::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsrAAccess";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsrAAccess
 ******************************************************************************/

TblBrlyQUsrAAccess::TblBrlyQUsrAAccess() {
};

TblBrlyQUsrAAccess::~TblBrlyQUsrAAccess() {
};

bool TblBrlyQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrAAccess** rec
		) {
	return false;
};

ubigint TblBrlyQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	return 0;
};

void TblBrlyQUsrAAccess::insertRec(
			BrlyQUsrAAccess* rec
		) {
};

ubigint TblBrlyQUsrAAccess::insertNewRec(
			BrlyQUsrAAccess** rec
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
	BrlyQUsrAAccess* _rec = NULL;

	_rec = new BrlyQUsrAAccess(0, jref, jnum, ref, x1IxBrlyVCard, srefX1IxBrlyVCard, titX1IxBrlyVCard, ixBrlyWUiaccess, srefsIxBrlyWUiaccess, titsIxBrlyWUiaccess);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsrAAccess::appendNewRecToRst(
			ListBrlyQUsrAAccess& rst
			, BrlyQUsrAAccess** rec
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
	BrlyQUsrAAccess* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1IxBrlyVCard, srefX1IxBrlyVCard, titX1IxBrlyVCard, ixBrlyWUiaccess, srefsIxBrlyWUiaccess, titsIxBrlyWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsrAAccess::insertRst(
			ListBrlyQUsrAAccess& rst
		) {
};

void TblBrlyQUsrAAccess::updateRec(
			BrlyQUsrAAccess* rec
		) {
};

void TblBrlyQUsrAAccess::updateRst(
			ListBrlyQUsrAAccess& rst
		) {
};

void TblBrlyQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsrAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsrAAccess** rec
		) {
	return false;
};

ubigint TblBrlyQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQUsrAAccess
 ******************************************************************************/

MyTblBrlyQUsrAAccess::MyTblBrlyQUsrAAccess() : TblBrlyQUsrAAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsrAAccess::~MyTblBrlyQUsrAAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsrAAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsrAAccess (jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsrAAccess SET jref = ?, jnum = ?, ref = ?, x1IxBrlyVCard = ?, ixBrlyWUiaccess = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsrAAccess WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsrAAccess WHERE jref = ?", false);
};

bool MyTblBrlyQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrAAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsrAAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQUsrAAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQUsrAAccess();

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

ubigint MyTblBrlyQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsrAAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQUsrAAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQUsrAAccess();

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

void MyTblBrlyQUsrAAccess::insertRec(
			BrlyQUsrAAccess* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1IxBrlyVCard,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyWUiaccess,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrAAccess / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrAAccess / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQUsrAAccess::insertRst(
			ListBrlyQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsrAAccess::updateRec(
			BrlyQUsrAAccess* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrAAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrAAccess / stmtUpdateRec)\n");
};

void MyTblBrlyQUsrAAccess::updateRst(
			ListBrlyQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsrAAccess::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrAAccess / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrAAccess / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQUsrAAccess::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrAAccess / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrAAccess / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQUsrAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsrAAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQUsrAAccess WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsrAAccess WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQUsrAAccess
 ******************************************************************************/

PgTblBrlyQUsrAAccess::PgTblBrlyQUsrAAccess() : TblBrlyQUsrAAccess(), PgTable() {
};

PgTblBrlyQUsrAAccess::~PgTblBrlyQUsrAAccess() {
};

void PgTblBrlyQUsrAAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQUsrAAccess_insertRec", "INSERT INTO TblBrlyQUsrAAccess (jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrAAccess_updateRec", "UPDATE TblBrlyQUsrAAccess SET jref = $1, jnum = $2, ref = $3, x1IxBrlyVCard = $4, ixBrlyWUiaccess = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrAAccess_removeRecByQref", "DELETE FROM TblBrlyQUsrAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrAAccess_removeRstByJref", "DELETE FROM TblBrlyQUsrAAccess WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQUsrAAccess_loadRecByQref", "SELECT qref, jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyQUsrAAccess WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrAAccess_loadRstByJref", "SELECT qref, jref, jnum, ref, x1IxBrlyVCard, ixBrlyWUiaccess FROM TblBrlyQUsrAAccess WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQUsrAAccess::loadRec(
			PGresult* res
			, BrlyQUsrAAccess** rec
		) {
	char* ptr;

	BrlyQUsrAAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsrAAccess();

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

ubigint PgTblBrlyQUsrAAccess::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsrAAccess* rec;

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
			rec = new BrlyQUsrAAccess();

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

bool PgTblBrlyQUsrAAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrAAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrAAccess::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrAAccess / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsrAAccess::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrAAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrAAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQUsrAAccess::insertRec(
			BrlyQUsrAAccess* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrAAccess_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrAAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQUsrAAccess::insertRst(
			ListBrlyQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsrAAccess::updateRec(
			BrlyQUsrAAccess* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrAAccess_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrAAccess_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQUsrAAccess::updateRst(
			ListBrlyQUsrAAccess& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsrAAccess::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrAAccess_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrAAccess_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQUsrAAccess::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrAAccess_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrAAccess_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQUsrAAccess::loadRecByQref(
			ubigint qref
			, BrlyQUsrAAccess** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQUsrAAccess_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsrAAccess::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrAAccess& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsrAAccess_loadRstByJref", 1, vals, l, f, append, rst);
};

