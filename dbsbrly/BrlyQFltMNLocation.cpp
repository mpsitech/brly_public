/**
  * \file BrlyQFltMNLocation.cpp
  * Dbs and XML wrapper for table TblBrlyQFltMNLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQFltMNLocation.h"

/******************************************************************************
 class BrlyQFltMNLocation
 ******************************************************************************/

BrlyQFltMNLocation::BrlyQFltMNLocation(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1VisStart
			, const string ftmX1VisStart
			, const uint x1VisStop
			, const string ftmX1VisStop
			, const uint xVisStart
			, const string ftmXVisStart
			, const uint xVisStop
			, const string ftmXVisStop
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->x1VisStart = x1VisStart;
	this->ftmX1VisStart = ftmX1VisStart;
	this->x1VisStop = x1VisStop;
	this->ftmX1VisStop = ftmX1VisStop;
	this->xVisStart = xVisStart;
	this->ftmXVisStart = ftmXVisStart;
	this->xVisStop = xVisStop;
	this->ftmXVisStop = ftmXVisStop;
};

void BrlyQFltMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQFltMNLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "sta", ftmX1VisStart);
		writeString(wr, "sto", ftmX1VisStop);
		writeString(wr, "xsa", ftmXVisStart);
		writeString(wr, "xso", ftmXVisStop);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "ftmX1VisStart", ftmX1VisStart);
		writeString(wr, "ftmX1VisStop", ftmX1VisStop);
		writeString(wr, "ftmXVisStart", ftmXVisStart);
		writeString(wr, "ftmXVisStop", ftmXVisStop);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQFltMNLocation
 ******************************************************************************/

ListBrlyQFltMNLocation::ListBrlyQFltMNLocation() {
};

ListBrlyQFltMNLocation::ListBrlyQFltMNLocation(
			const ListBrlyQFltMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltMNLocation(*(src.nodes[i]));
};

ListBrlyQFltMNLocation::~ListBrlyQFltMNLocation() {
	clear();
};

void ListBrlyQFltMNLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQFltMNLocation::size() const {
	return(nodes.size());
};

void ListBrlyQFltMNLocation::append(
			BrlyQFltMNLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQFltMNLocation& ListBrlyQFltMNLocation::operator=(
			const ListBrlyQFltMNLocation& src
		) {
	BrlyQFltMNLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQFltMNLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQFltMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQFltMNLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQFltMNLocation
 ******************************************************************************/

TblBrlyQFltMNLocation::TblBrlyQFltMNLocation() {
};

TblBrlyQFltMNLocation::~TblBrlyQFltMNLocation() {
};

bool TblBrlyQFltMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQFltMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltMNLocation& rst
		) {
	return 0;
};

void TblBrlyQFltMNLocation::insertRec(
			BrlyQFltMNLocation* rec
		) {
};

ubigint TblBrlyQFltMNLocation::insertNewRec(
			BrlyQFltMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1VisStart
			, const string ftmX1VisStart
			, const uint x1VisStop
			, const string ftmX1VisStop
			, const uint xVisStart
			, const string ftmXVisStart
			, const uint xVisStop
			, const string ftmXVisStop
		) {
	ubigint retval = 0;
	BrlyQFltMNLocation* _rec = NULL;

	_rec = new BrlyQFltMNLocation(0, jref, jnum, mref, stubMref, ref, x1VisStart, ftmX1VisStart, x1VisStop, ftmX1VisStop, xVisStart, ftmXVisStart, xVisStop, ftmXVisStop);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQFltMNLocation::appendNewRecToRst(
			ListBrlyQFltMNLocation& rst
			, BrlyQFltMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1VisStart
			, const string ftmX1VisStart
			, const uint x1VisStop
			, const string ftmX1VisStop
			, const uint xVisStart
			, const string ftmXVisStart
			, const uint xVisStop
			, const string ftmXVisStop
		) {
	ubigint retval = 0;
	BrlyQFltMNLocation* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1VisStart, ftmX1VisStart, x1VisStop, ftmX1VisStop, xVisStart, ftmXVisStart, xVisStop, ftmXVisStop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQFltMNLocation::insertRst(
			ListBrlyQFltMNLocation& rst
		) {
};

void TblBrlyQFltMNLocation::updateRec(
			BrlyQFltMNLocation* rec
		) {
};

void TblBrlyQFltMNLocation::updateRst(
			ListBrlyQFltMNLocation& rst
		) {
};

void TblBrlyQFltMNLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQFltMNLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQFltMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQFltMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQFltMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltMNLocation& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQFltMNLocation
 ******************************************************************************/

MyTblBrlyQFltMNLocation::MyTblBrlyQFltMNLocation() : TblBrlyQFltMNLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQFltMNLocation::~MyTblBrlyQFltMNLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQFltMNLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQFltMNLocation (jref, jnum, mref, ref, x1VisStart, x1VisStop, xVisStart, xVisStop) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQFltMNLocation SET jref = ?, jnum = ?, mref = ?, ref = ?, x1VisStart = ?, x1VisStop = ?, xVisStart = ?, xVisStop = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQFltMNLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQFltMNLocation WHERE jref = ?", false);
};

bool MyTblBrlyQFltMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltMNLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQFltMNLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltMNLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQFltMNLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1VisStart = atol((char*) dbrow[5]); else _rec->x1VisStart = 0;
		if (dbrow[6]) _rec->x1VisStop = atol((char*) dbrow[6]); else _rec->x1VisStop = 0;
		if (dbrow[7]) _rec->xVisStart = atol((char*) dbrow[7]); else _rec->xVisStart = 0;
		if (dbrow[8]) _rec->xVisStop = atol((char*) dbrow[8]); else _rec->xVisStop = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQFltMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltMNLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQFltMNLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltMNLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQFltMNLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1VisStart = atol((char*) dbrow[5]); else rec->x1VisStart = 0;
			if (dbrow[6]) rec->x1VisStop = atol((char*) dbrow[6]); else rec->x1VisStop = 0;
			if (dbrow[7]) rec->xVisStart = atol((char*) dbrow[7]); else rec->xVisStart = 0;
			if (dbrow[8]) rec->xVisStop = atol((char*) dbrow[8]); else rec->xVisStop = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQFltMNLocation::insertRec(
			BrlyQFltMNLocation* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1VisStart,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1VisStop,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->xVisStart,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->xVisStop,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltMNLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltMNLocation / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQFltMNLocation::insertRst(
			ListBrlyQFltMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQFltMNLocation::updateRec(
			BrlyQFltMNLocation* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1VisStart,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1VisStop,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->xVisStart,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->xVisStop,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltMNLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltMNLocation / stmtUpdateRec)\n");
};

void MyTblBrlyQFltMNLocation::updateRst(
			ListBrlyQFltMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQFltMNLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltMNLocation / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltMNLocation / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQFltMNLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltMNLocation / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltMNLocation / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQFltMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQFltMNLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQFltMNLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQFltMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltMNLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQFltMNLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQFltMNLocation
 ******************************************************************************/

PgTblBrlyQFltMNLocation::PgTblBrlyQFltMNLocation() : TblBrlyQFltMNLocation(), PgTable() {
};

PgTblBrlyQFltMNLocation::~PgTblBrlyQFltMNLocation() {
};

void PgTblBrlyQFltMNLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQFltMNLocation_insertRec", "INSERT INTO TblBrlyQFltMNLocation (jref, jnum, mref, ref, x1VisStart, x1VisStop, xVisStart, xVisStop) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltMNLocation_updateRec", "UPDATE TblBrlyQFltMNLocation SET jref = $1, jnum = $2, mref = $3, ref = $4, x1VisStart = $5, x1VisStop = $6, xVisStart = $7, xVisStop = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltMNLocation_removeRecByQref", "DELETE FROM TblBrlyQFltMNLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltMNLocation_removeRstByJref", "DELETE FROM TblBrlyQFltMNLocation WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQFltMNLocation_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1VisStart, x1VisStop, xVisStart, xVisStop FROM TblBrlyQFltMNLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltMNLocation_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1VisStart, x1VisStop, xVisStart, xVisStop FROM TblBrlyQFltMNLocation WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQFltMNLocation::loadRec(
			PGresult* res
			, BrlyQFltMNLocation** rec
		) {
	char* ptr;

	BrlyQFltMNLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQFltMNLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1visstart"),
			PQfnumber(res, "x1visstop"),
			PQfnumber(res, "xvisstart"),
			PQfnumber(res, "xvisstop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1VisStart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1VisStop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->xVisStart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->xVisStop = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQFltMNLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQFltMNLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQFltMNLocation* rec;

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
			PQfnumber(res, "x1visstart"),
			PQfnumber(res, "x1visstop"),
			PQfnumber(res, "xvisstart"),
			PQfnumber(res, "xvisstop")
		};

		while (numread < numrow) {
			rec = new BrlyQFltMNLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1VisStart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1VisStop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->xVisStart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->xVisStop = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQFltMNLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQFltMNLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltMNLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltMNLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQFltMNLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltMNLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQFltMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltMNLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltMNLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQFltMNLocation::insertRec(
			BrlyQFltMNLocation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1VisStart = htonl(rec->x1VisStart);
	uint _x1VisStop = htonl(rec->x1VisStop);
	uint _xVisStart = htonl(rec->xVisStart);
	uint _xVisStop = htonl(rec->xVisStop);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1VisStart,
		(char*) &_x1VisStop,
		(char*) &_xVisStart,
		(char*) &_xVisStop
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltMNLocation_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltMNLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQFltMNLocation::insertRst(
			ListBrlyQFltMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQFltMNLocation::updateRec(
			BrlyQFltMNLocation* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1VisStart = htonl(rec->x1VisStart);
	uint _x1VisStop = htonl(rec->x1VisStop);
	uint _xVisStart = htonl(rec->xVisStart);
	uint _xVisStop = htonl(rec->xVisStop);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1VisStart,
		(char*) &_x1VisStop,
		(char*) &_xVisStart,
		(char*) &_xVisStop,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltMNLocation_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltMNLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQFltMNLocation::updateRst(
			ListBrlyQFltMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQFltMNLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFltMNLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltMNLocation_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQFltMNLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFltMNLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltMNLocation_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQFltMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQFltMNLocation** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQFltMNLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQFltMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltMNLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQFltMNLocation_loadRstByJref", 1, vals, l, f, append, rst);
};

