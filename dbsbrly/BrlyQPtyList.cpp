/**
  * \file BrlyQPtyList.cpp
  * Dbs and XML wrapper for table TblBrlyQPtyList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQPtyList.h"

/******************************************************************************
 class BrlyQPtyList
 ******************************************************************************/

BrlyQPtyList::BrlyQPtyList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const string srefBrlyKEqptype
			, const string titSrefBrlyKEqptype
			, const usmallint Capacity
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->srefBrlyKEqptype = srefBrlyKEqptype;
	this->titSrefBrlyKEqptype = titSrefBrlyKEqptype;
	this->Capacity = Capacity;
};

void BrlyQPtyList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQPtyList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "ety", srefBrlyKEqptype);
		writeString(wr, "ety2", titSrefBrlyKEqptype);
		writeUint(wr, "cap", Capacity);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "srefBrlyKEqptype", srefBrlyKEqptype);
		writeString(wr, "titSrefBrlyKEqptype", titSrefBrlyKEqptype);
		writeUint(wr, "Capacity", Capacity);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQPtyList
 ******************************************************************************/

ListBrlyQPtyList::ListBrlyQPtyList() {
};

ListBrlyQPtyList::ListBrlyQPtyList(
			const ListBrlyQPtyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQPtyList(*(src.nodes[i]));
};

ListBrlyQPtyList::~ListBrlyQPtyList() {
	clear();
};

void ListBrlyQPtyList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQPtyList::size() const {
	return(nodes.size());
};

void ListBrlyQPtyList::append(
			BrlyQPtyList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQPtyList& ListBrlyQPtyList::operator=(
			const ListBrlyQPtyList& src
		) {
	BrlyQPtyList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQPtyList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQPtyList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQPtyList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQPtyList
 ******************************************************************************/

TblBrlyQPtyList::TblBrlyQPtyList() {
};

TblBrlyQPtyList::~TblBrlyQPtyList() {
};

bool TblBrlyQPtyList::loadRecBySQL(
			const string& sqlstr
			, BrlyQPtyList** rec
		) {
	return false;
};

ubigint TblBrlyQPtyList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPtyList& rst
		) {
	return 0;
};

void TblBrlyQPtyList::insertRec(
			BrlyQPtyList* rec
		) {
};

ubigint TblBrlyQPtyList::insertNewRec(
			BrlyQPtyList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const string srefBrlyKEqptype
			, const string titSrefBrlyKEqptype
			, const usmallint Capacity
		) {
	ubigint retval = 0;
	BrlyQPtyList* _rec = NULL;

	_rec = new BrlyQPtyList(0, jref, jnum, ref, sref, Title, srefBrlyKEqptype, titSrefBrlyKEqptype, Capacity);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQPtyList::appendNewRecToRst(
			ListBrlyQPtyList& rst
			, BrlyQPtyList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const string srefBrlyKEqptype
			, const string titSrefBrlyKEqptype
			, const usmallint Capacity
		) {
	ubigint retval = 0;
	BrlyQPtyList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, srefBrlyKEqptype, titSrefBrlyKEqptype, Capacity);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQPtyList::insertRst(
			ListBrlyQPtyList& rst
		) {
};

void TblBrlyQPtyList::updateRec(
			BrlyQPtyList* rec
		) {
};

void TblBrlyQPtyList::updateRst(
			ListBrlyQPtyList& rst
		) {
};

void TblBrlyQPtyList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQPtyList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQPtyList::loadRecByQref(
			ubigint qref
			, BrlyQPtyList** rec
		) {
	return false;
};

ubigint TblBrlyQPtyList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPtyList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQPtyList
 ******************************************************************************/

MyTblBrlyQPtyList::MyTblBrlyQPtyList() : TblBrlyQPtyList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQPtyList::~MyTblBrlyQPtyList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQPtyList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQPtyList (jref, jnum, ref, sref, Title, srefBrlyKEqptype, Capacity) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQPtyList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, srefBrlyKEqptype = ?, Capacity = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQPtyList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQPtyList WHERE jref = ?", false);
};

bool MyTblBrlyQPtyList::loadRecBySQL(
			const string& sqlstr
			, BrlyQPtyList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQPtyList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQPtyList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQPtyList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->srefBrlyKEqptype.assign(dbrow[6], dblengths[6]); else _rec->srefBrlyKEqptype = "";
		if (dbrow[7]) _rec->Capacity = atoi((char*) dbrow[7]); else _rec->Capacity = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQPtyList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPtyList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQPtyList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQPtyList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQPtyList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->srefBrlyKEqptype.assign(dbrow[6], dblengths[6]); else rec->srefBrlyKEqptype = "";
			if (dbrow[7]) rec->Capacity = atoi((char*) dbrow[7]); else rec->Capacity = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQPtyList::insertRec(
			BrlyQPtyList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	l[5] = rec->srefBrlyKEqptype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefBrlyKEqptype.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Capacity,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQPtyList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQPtyList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQPtyList::insertRst(
			ListBrlyQPtyList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQPtyList::updateRec(
			BrlyQPtyList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();
	l[5] = rec->srefBrlyKEqptype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefBrlyKEqptype.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUsmallint(&rec->Capacity,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQPtyList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQPtyList / stmtUpdateRec)\n");
};

void MyTblBrlyQPtyList::updateRst(
			ListBrlyQPtyList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQPtyList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQPtyList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQPtyList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQPtyList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQPtyList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQPtyList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQPtyList::loadRecByQref(
			ubigint qref
			, BrlyQPtyList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQPtyList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQPtyList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPtyList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQPtyList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQPtyList
 ******************************************************************************/

PgTblBrlyQPtyList::PgTblBrlyQPtyList() : TblBrlyQPtyList(), PgTable() {
};

PgTblBrlyQPtyList::~PgTblBrlyQPtyList() {
};

void PgTblBrlyQPtyList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQPtyList_insertRec", "INSERT INTO TblBrlyQPtyList (jref, jnum, ref, sref, Title, srefBrlyKEqptype, Capacity) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQPtyList_updateRec", "UPDATE TblBrlyQPtyList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, srefBrlyKEqptype = $6, Capacity = $7 WHERE qref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQPtyList_removeRecByQref", "DELETE FROM TblBrlyQPtyList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQPtyList_removeRstByJref", "DELETE FROM TblBrlyQPtyList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQPtyList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, srefBrlyKEqptype, Capacity FROM TblBrlyQPtyList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQPtyList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, srefBrlyKEqptype, Capacity FROM TblBrlyQPtyList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQPtyList::loadRec(
			PGresult* res
			, BrlyQPtyList** rec
		) {
	char* ptr;

	BrlyQPtyList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQPtyList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "srefbrlykeqptype"),
			PQfnumber(res, "capacity")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefBrlyKEqptype.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Capacity = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQPtyList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQPtyList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQPtyList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "srefbrlykeqptype"),
			PQfnumber(res, "capacity")
		};

		while (numread < numrow) {
			rec = new BrlyQPtyList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefBrlyKEqptype.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Capacity = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQPtyList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQPtyList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPtyList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQPtyList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQPtyList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPtyList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQPtyList::loadRecBySQL(
			const string& sqlstr
			, BrlyQPtyList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQPtyList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQPtyList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQPtyList::insertRec(
			BrlyQPtyList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	usmallint _Capacity = htons(rec->Capacity);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->srefBrlyKEqptype.c_str(),
		(char*) &_Capacity
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQPtyList_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPtyList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQPtyList::insertRst(
			ListBrlyQPtyList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQPtyList::updateRec(
			BrlyQPtyList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	usmallint _Capacity = htons(rec->Capacity);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		rec->srefBrlyKEqptype.c_str(),
		(char*) &_Capacity,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQPtyList_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPtyList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQPtyList::updateRst(
			ListBrlyQPtyList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQPtyList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQPtyList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPtyList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQPtyList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQPtyList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQPtyList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQPtyList::loadRecByQref(
			ubigint qref
			, BrlyQPtyList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQPtyList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQPtyList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQPtyList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQPtyList_loadRstByJref", 1, vals, l, f, append, rst);
};

