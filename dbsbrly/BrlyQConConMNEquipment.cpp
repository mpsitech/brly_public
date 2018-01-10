/**
  * \file BrlyQConConMNEquipment.cpp
  * Dbs and XML wrapper for table TblBrlyQConConMNEquipment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQConConMNEquipment.h"

/******************************************************************************
 class BrlyQConConMNEquipment
 ******************************************************************************/

BrlyQConConMNEquipment::BrlyQConConMNEquipment(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
			, const uint conNum
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->conIxBrlyVLat = conIxBrlyVLat;
	this->srefConIxBrlyVLat = srefConIxBrlyVLat;
	this->conNum = conNum;
};

void BrlyQConConMNEquipment::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConConMNEquipment";

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
 class ListBrlyQConConMNEquipment
 ******************************************************************************/

ListBrlyQConConMNEquipment::ListBrlyQConConMNEquipment() {
};

ListBrlyQConConMNEquipment::ListBrlyQConConMNEquipment(
			const ListBrlyQConConMNEquipment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConConMNEquipment(*(src.nodes[i]));
};

ListBrlyQConConMNEquipment::~ListBrlyQConConMNEquipment() {
	clear();
};

void ListBrlyQConConMNEquipment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConConMNEquipment::size() const {
	return(nodes.size());
};

void ListBrlyQConConMNEquipment::append(
			BrlyQConConMNEquipment* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConConMNEquipment& ListBrlyQConConMNEquipment::operator=(
			const ListBrlyQConConMNEquipment& src
		) {
	BrlyQConConMNEquipment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQConConMNEquipment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConConMNEquipment::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConConMNEquipment";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConConMNEquipment
 ******************************************************************************/

TblBrlyQConConMNEquipment::TblBrlyQConConMNEquipment() {
};

TblBrlyQConConMNEquipment::~TblBrlyQConConMNEquipment() {
};

bool TblBrlyQConConMNEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConConMNEquipment** rec
		) {
	return false;
};

ubigint TblBrlyQConConMNEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConConMNEquipment& rst
		) {
	return 0;
};

void TblBrlyQConConMNEquipment::insertRec(
			BrlyQConConMNEquipment* rec
		) {
};

ubigint TblBrlyQConConMNEquipment::insertNewRec(
			BrlyQConConMNEquipment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
			, const uint conNum
		) {
	ubigint retval = 0;
	BrlyQConConMNEquipment* _rec = NULL;

	_rec = new BrlyQConConMNEquipment(0, jref, jnum, mref, stubMref, ref, conIxBrlyVLat, srefConIxBrlyVLat, conNum);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConConMNEquipment::appendNewRecToRst(
			ListBrlyQConConMNEquipment& rst
			, BrlyQConConMNEquipment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint conIxBrlyVLat
			, const string srefConIxBrlyVLat
			, const uint conNum
		) {
	ubigint retval = 0;
	BrlyQConConMNEquipment* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, conIxBrlyVLat, srefConIxBrlyVLat, conNum);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConConMNEquipment::insertRst(
			ListBrlyQConConMNEquipment& rst
		) {
};

void TblBrlyQConConMNEquipment::updateRec(
			BrlyQConConMNEquipment* rec
		) {
};

void TblBrlyQConConMNEquipment::updateRst(
			ListBrlyQConConMNEquipment& rst
		) {
};

void TblBrlyQConConMNEquipment::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConConMNEquipment::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConConMNEquipment::loadRecByQref(
			ubigint qref
			, BrlyQConConMNEquipment** rec
		) {
	return false;
};

ubigint TblBrlyQConConMNEquipment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConConMNEquipment& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQConConMNEquipment
 ******************************************************************************/

MyTblBrlyQConConMNEquipment::MyTblBrlyQConConMNEquipment() : TblBrlyQConConMNEquipment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConConMNEquipment::~MyTblBrlyQConConMNEquipment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConConMNEquipment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConConMNEquipment (jref, jnum, mref, ref, conIxBrlyVLat, conNum) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConConMNEquipment SET jref = ?, jnum = ?, mref = ?, ref = ?, conIxBrlyVLat = ?, conNum = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConConMNEquipment WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConConMNEquipment WHERE jref = ?", false);
};

bool MyTblBrlyQConConMNEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConConMNEquipment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConConMNEquipment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConConMNEquipment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConConMNEquipment();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->conIxBrlyVLat = atol((char*) dbrow[5]); else _rec->conIxBrlyVLat = 0;
		if (dbrow[6]) _rec->conNum = atol((char*) dbrow[6]); else _rec->conNum = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQConConMNEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConConMNEquipment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConConMNEquipment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConConMNEquipment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConConMNEquipment();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->conIxBrlyVLat = atol((char*) dbrow[5]); else rec->conIxBrlyVLat = 0;
			if (dbrow[6]) rec->conNum = atol((char*) dbrow[6]); else rec->conNum = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQConConMNEquipment::insertRec(
			BrlyQConConMNEquipment* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->conIxBrlyVLat,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->conNum,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConConMNEquipment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConConMNEquipment / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQConConMNEquipment::insertRst(
			ListBrlyQConConMNEquipment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConConMNEquipment::updateRec(
			BrlyQConConMNEquipment* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->conIxBrlyVLat,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->conNum,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConConMNEquipment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConConMNEquipment / stmtUpdateRec)\n");
};

void MyTblBrlyQConConMNEquipment::updateRst(
			ListBrlyQConConMNEquipment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConConMNEquipment::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConConMNEquipment / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConConMNEquipment / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQConConMNEquipment::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConConMNEquipment / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConConMNEquipment / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQConConMNEquipment::loadRecByQref(
			ubigint qref
			, BrlyQConConMNEquipment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQConConMNEquipment WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConConMNEquipment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConConMNEquipment& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConConMNEquipment WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQConConMNEquipment
 ******************************************************************************/

PgTblBrlyQConConMNEquipment::PgTblBrlyQConConMNEquipment() : TblBrlyQConConMNEquipment(), PgTable() {
};

PgTblBrlyQConConMNEquipment::~PgTblBrlyQConConMNEquipment() {
};

void PgTblBrlyQConConMNEquipment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQConConMNEquipment_insertRec", "INSERT INTO TblBrlyQConConMNEquipment (jref, jnum, mref, ref, conIxBrlyVLat, conNum) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConConMNEquipment_updateRec", "UPDATE TblBrlyQConConMNEquipment SET jref = $1, jnum = $2, mref = $3, ref = $4, conIxBrlyVLat = $5, conNum = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConConMNEquipment_removeRecByQref", "DELETE FROM TblBrlyQConConMNEquipment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConConMNEquipment_removeRstByJref", "DELETE FROM TblBrlyQConConMNEquipment WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQConConMNEquipment_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, conIxBrlyVLat, conNum FROM TblBrlyQConConMNEquipment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConConMNEquipment_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, conIxBrlyVLat, conNum FROM TblBrlyQConConMNEquipment WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQConConMNEquipment::loadRec(
			PGresult* res
			, BrlyQConConMNEquipment** rec
		) {
	char* ptr;

	BrlyQConConMNEquipment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConConMNEquipment();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "conixbrlyvlat"),
			PQfnumber(res, "connum")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->conIxBrlyVLat = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->conNum = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQConConMNEquipment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConConMNEquipment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConConMNEquipment* rec;

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
			PQfnumber(res, "conixbrlyvlat"),
			PQfnumber(res, "connum")
		};

		while (numread < numrow) {
			rec = new BrlyQConConMNEquipment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->conIxBrlyVLat = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->conNum = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQConConMNEquipment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConConMNEquipment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConConMNEquipment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConConMNEquipment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConConMNEquipment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConConMNEquipment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConConMNEquipment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConConMNEquipment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConConMNEquipment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConConMNEquipment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQConConMNEquipment::insertRec(
			BrlyQConConMNEquipment* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _conIxBrlyVLat = htonl(rec->conIxBrlyVLat);
	uint _conNum = htonl(rec->conNum);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_conIxBrlyVLat,
		(char*) &_conNum
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConConMNEquipment_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConConMNEquipment_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQConConMNEquipment::insertRst(
			ListBrlyQConConMNEquipment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConConMNEquipment::updateRec(
			BrlyQConConMNEquipment* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _conIxBrlyVLat = htonl(rec->conIxBrlyVLat);
	uint _conNum = htonl(rec->conNum);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_conIxBrlyVLat,
		(char*) &_conNum,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConConMNEquipment_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConConMNEquipment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQConConMNEquipment::updateRst(
			ListBrlyQConConMNEquipment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConConMNEquipment::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConConMNEquipment_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConConMNEquipment_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQConConMNEquipment::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConConMNEquipment_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConConMNEquipment_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQConConMNEquipment::loadRecByQref(
			ubigint qref
			, BrlyQConConMNEquipment** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQConConMNEquipment_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConConMNEquipment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConConMNEquipment& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConConMNEquipment_loadRstByJref", 1, vals, l, f, append, rst);
};

