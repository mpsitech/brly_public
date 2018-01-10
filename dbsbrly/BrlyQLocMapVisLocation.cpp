/**
  * \file BrlyQLocMapVisLocation.cpp
  * Dbs and XML wrapper for table TblBrlyQLocMapVisLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLocMapVisLocation.h"

/******************************************************************************
 class BrlyQLocMapVisLocation
 ******************************************************************************/

BrlyQLocMapVisLocation::BrlyQLocMapVisLocation(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint mref
			, const string stubMref
			, const double mtheta
			, const double mphi
			, const double x
			, const double y
		) {
	this->qref = qref;
	this->qwr = qwr;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->mref = mref;
	this->stubMref = stubMref;
	this->mtheta = mtheta;
	this->mphi = mphi;
	this->x = x;
	this->y = y;
};

void BrlyQLocMapVisLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocMapVisLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeDouble(wr, "x", x);
		writeDouble(wr, "y", y);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeDouble(wr, "x", x);
		writeDouble(wr, "y", y);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLocMapVisLocation
 ******************************************************************************/

ListBrlyQLocMapVisLocation::ListBrlyQLocMapVisLocation() {
};

ListBrlyQLocMapVisLocation::ListBrlyQLocMapVisLocation(
			const ListBrlyQLocMapVisLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocMapVisLocation(*(src.nodes[i]));
};

ListBrlyQLocMapVisLocation::~ListBrlyQLocMapVisLocation() {
	clear();
};

void ListBrlyQLocMapVisLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocMapVisLocation::size() const {
	return(nodes.size());
};

void ListBrlyQLocMapVisLocation::append(
			BrlyQLocMapVisLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocMapVisLocation& ListBrlyQLocMapVisLocation::operator=(
			const ListBrlyQLocMapVisLocation& src
		) {
	BrlyQLocMapVisLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLocMapVisLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocMapVisLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocMapVisLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocMapVisLocation
 ******************************************************************************/

TblBrlyQLocMapVisLocation::TblBrlyQLocMapVisLocation() {
};

TblBrlyQLocMapVisLocation::~TblBrlyQLocMapVisLocation() {
};

bool TblBrlyQLocMapVisLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocMapVisLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLocMapVisLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocMapVisLocation& rst
		) {
	return 0;
};

void TblBrlyQLocMapVisLocation::insertRec(
			BrlyQLocMapVisLocation* rec
		) {
};

ubigint TblBrlyQLocMapVisLocation::insertNewRec(
			BrlyQLocMapVisLocation** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint mref
			, const string stubMref
			, const double mtheta
			, const double mphi
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	BrlyQLocMapVisLocation* _rec = NULL;

	_rec = new BrlyQLocMapVisLocation(0, qwr, jref, jnum, ref, mref, stubMref, mtheta, mphi, x, y);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocMapVisLocation::appendNewRecToRst(
			ListBrlyQLocMapVisLocation& rst
			, BrlyQLocMapVisLocation** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint mref
			, const string stubMref
			, const double mtheta
			, const double mphi
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	BrlyQLocMapVisLocation* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, mref, stubMref, mtheta, mphi, x, y);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocMapVisLocation::insertRst(
			ListBrlyQLocMapVisLocation& rst
		) {
};

void TblBrlyQLocMapVisLocation::updateRec(
			BrlyQLocMapVisLocation* rec
		) {
};

void TblBrlyQLocMapVisLocation::updateRst(
			ListBrlyQLocMapVisLocation& rst
		) {
};

void TblBrlyQLocMapVisLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocMapVisLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocMapVisLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocMapVisLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLocMapVisLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocMapVisLocation& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLocMapVisLocation
 ******************************************************************************/

MyTblBrlyQLocMapVisLocation::MyTblBrlyQLocMapVisLocation() : TblBrlyQLocMapVisLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocMapVisLocation::~MyTblBrlyQLocMapVisLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocMapVisLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocMapVisLocation (qwr, jref, jnum, ref, mref, mtheta, mphi, x, y) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocMapVisLocation SET qwr = ?, jref = ?, jnum = ?, ref = ?, mref = ?, mtheta = ?, mphi = ?, x = ?, y = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocMapVisLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocMapVisLocation WHERE jref = ?", false);
};

bool MyTblBrlyQLocMapVisLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocMapVisLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocMapVisLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLocMapVisLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLocMapVisLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->mref = atoll((char*) dbrow[5]); else _rec->mref = 0;
		if (dbrow[6]) _rec->mtheta = atof((char*) dbrow[6]); else _rec->mtheta = 0.0;
		if (dbrow[7]) _rec->mphi = atof((char*) dbrow[7]); else _rec->mphi = 0.0;
		if (dbrow[8]) _rec->x = atof((char*) dbrow[8]); else _rec->x = 0.0;
		if (dbrow[9]) _rec->y = atof((char*) dbrow[9]); else _rec->y = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLocMapVisLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocMapVisLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocMapVisLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLocMapVisLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLocMapVisLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->mref = atoll((char*) dbrow[5]); else rec->mref = 0;
			if (dbrow[6]) rec->mtheta = atof((char*) dbrow[6]); else rec->mtheta = 0.0;
			if (dbrow[7]) rec->mphi = atof((char*) dbrow[7]); else rec->mphi = 0.0;
			if (dbrow[8]) rec->x = atof((char*) dbrow[8]); else rec->x = 0.0;
			if (dbrow[9]) rec->y = atof((char*) dbrow[9]); else rec->y = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQLocMapVisLocation::insertRec(
			BrlyQLocMapVisLocation* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->mref,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->mtheta,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->mphi,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->y,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocMapVisLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocMapVisLocation / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLocMapVisLocation::insertRst(
			ListBrlyQLocMapVisLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocMapVisLocation::updateRec(
			BrlyQLocMapVisLocation* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->mref,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->mtheta,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->mphi,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->y,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocMapVisLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocMapVisLocation / stmtUpdateRec)\n");
};

void MyTblBrlyQLocMapVisLocation::updateRst(
			ListBrlyQLocMapVisLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocMapVisLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocMapVisLocation / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocMapVisLocation / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLocMapVisLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocMapVisLocation / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocMapVisLocation / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLocMapVisLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocMapVisLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLocMapVisLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocMapVisLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocMapVisLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocMapVisLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLocMapVisLocation
 ******************************************************************************/

PgTblBrlyQLocMapVisLocation::PgTblBrlyQLocMapVisLocation() : TblBrlyQLocMapVisLocation(), PgTable() {
};

PgTblBrlyQLocMapVisLocation::~PgTblBrlyQLocMapVisLocation() {
};

void PgTblBrlyQLocMapVisLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLocMapVisLocation_insertRec", "INSERT INTO TblBrlyQLocMapVisLocation (qwr, jref, jnum, ref, mref, mtheta, mphi, x, y) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocMapVisLocation_updateRec", "UPDATE TblBrlyQLocMapVisLocation SET qwr = $1, jref = $2, jnum = $3, ref = $4, mref = $5, mtheta = $6, mphi = $7, x = $8, y = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocMapVisLocation_removeRecByQref", "DELETE FROM TblBrlyQLocMapVisLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocMapVisLocation_removeRstByJref", "DELETE FROM TblBrlyQLocMapVisLocation WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLocMapVisLocation_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, mref, mtheta, mphi, x, y FROM TblBrlyQLocMapVisLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocMapVisLocation_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, mref, mtheta, mphi, x, y FROM TblBrlyQLocMapVisLocation WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLocMapVisLocation::loadRec(
			PGresult* res
			, BrlyQLocMapVisLocation** rec
		) {
	char* ptr;

	BrlyQLocMapVisLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocMapVisLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mtheta"),
			PQfnumber(res, "mphi"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->mtheta = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->mphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->y = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLocMapVisLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocMapVisLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocMapVisLocation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mtheta"),
			PQfnumber(res, "mphi"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		while (numread < numrow) {
			rec = new BrlyQLocMapVisLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->mtheta = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->mphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->y = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLocMapVisLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocMapVisLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocMapVisLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocMapVisLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocMapVisLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocMapVisLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocMapVisLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocMapVisLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocMapVisLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocMapVisLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLocMapVisLocation::insertRec(
			BrlyQLocMapVisLocation* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _mref = htonl64(rec->mref);
	string _mtheta = to_string(rec->mtheta);
	string _mphi = to_string(rec->mphi);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_mref,
		_mtheta.c_str(),
		_mphi.c_str(),
		_x.c_str(),
		_y.c_str()
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLocMapVisLocation_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocMapVisLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLocMapVisLocation::insertRst(
			ListBrlyQLocMapVisLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocMapVisLocation::updateRec(
			BrlyQLocMapVisLocation* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _mref = htonl64(rec->mref);
	string _mtheta = to_string(rec->mtheta);
	string _mphi = to_string(rec->mphi);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_mref,
		_mtheta.c_str(),
		_mphi.c_str(),
		_x.c_str(),
		_y.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLocMapVisLocation_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocMapVisLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLocMapVisLocation::updateRst(
			ListBrlyQLocMapVisLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocMapVisLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocMapVisLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocMapVisLocation_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLocMapVisLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocMapVisLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocMapVisLocation_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLocMapVisLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocMapVisLocation** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLocMapVisLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocMapVisLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocMapVisLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocMapVisLocation_loadRstByJref", 1, vals, l, f, append, rst);
};

