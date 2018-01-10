/**
  * \file BrlyQLegMapLocation.cpp
  * Dbs and XML wrapper for table TblBrlyQLegMapLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLegMapLocation.h"

/******************************************************************************
 class BrlyQLegMapLocation
 ******************************************************************************/

BrlyQLegMapLocation::BrlyQLegMapLocation(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double legphi
			, const double legtheta
			, const ubigint mref
			, const string stubMref
			, const double x
			, const double y
		) {
	this->qref = qref;
	this->qwr = qwr;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->legphi = legphi;
	this->legtheta = legtheta;
	this->mref = mref;
	this->stubMref = stubMref;
	this->x = x;
	this->y = y;
};

void BrlyQLegMapLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLegMapLocation";

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
 class ListBrlyQLegMapLocation
 ******************************************************************************/

ListBrlyQLegMapLocation::ListBrlyQLegMapLocation() {
};

ListBrlyQLegMapLocation::ListBrlyQLegMapLocation(
			const ListBrlyQLegMapLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegMapLocation(*(src.nodes[i]));
};

ListBrlyQLegMapLocation::~ListBrlyQLegMapLocation() {
	clear();
};

void ListBrlyQLegMapLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLegMapLocation::size() const {
	return(nodes.size());
};

void ListBrlyQLegMapLocation::append(
			BrlyQLegMapLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLegMapLocation& ListBrlyQLegMapLocation::operator=(
			const ListBrlyQLegMapLocation& src
		) {
	BrlyQLegMapLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLegMapLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLegMapLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLegMapLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLegMapLocation
 ******************************************************************************/

TblBrlyQLegMapLocation::TblBrlyQLegMapLocation() {
};

TblBrlyQLegMapLocation::~TblBrlyQLegMapLocation() {
};

bool TblBrlyQLegMapLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMapLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLegMapLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMapLocation& rst
		) {
	return 0;
};

void TblBrlyQLegMapLocation::insertRec(
			BrlyQLegMapLocation* rec
		) {
};

ubigint TblBrlyQLegMapLocation::insertNewRec(
			BrlyQLegMapLocation** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double legphi
			, const double legtheta
			, const ubigint mref
			, const string stubMref
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	BrlyQLegMapLocation* _rec = NULL;

	_rec = new BrlyQLegMapLocation(0, qwr, jref, jnum, ref, legphi, legtheta, mref, stubMref, x, y);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLegMapLocation::appendNewRecToRst(
			ListBrlyQLegMapLocation& rst
			, BrlyQLegMapLocation** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double legphi
			, const double legtheta
			, const ubigint mref
			, const string stubMref
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	BrlyQLegMapLocation* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, legphi, legtheta, mref, stubMref, x, y);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLegMapLocation::insertRst(
			ListBrlyQLegMapLocation& rst
		) {
};

void TblBrlyQLegMapLocation::updateRec(
			BrlyQLegMapLocation* rec
		) {
};

void TblBrlyQLegMapLocation::updateRst(
			ListBrlyQLegMapLocation& rst
		) {
};

void TblBrlyQLegMapLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLegMapLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLegMapLocation::loadRecByQref(
			ubigint qref
			, BrlyQLegMapLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLegMapLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMapLocation& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLegMapLocation
 ******************************************************************************/

MyTblBrlyQLegMapLocation::MyTblBrlyQLegMapLocation() : TblBrlyQLegMapLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLegMapLocation::~MyTblBrlyQLegMapLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLegMapLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLegMapLocation (qwr, jref, jnum, ref, legphi, legtheta, mref, x, y) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLegMapLocation SET qwr = ?, jref = ?, jnum = ?, ref = ?, legphi = ?, legtheta = ?, mref = ?, x = ?, y = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLegMapLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLegMapLocation WHERE jref = ?", false);
};

bool MyTblBrlyQLegMapLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMapLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLegMapLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLegMapLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLegMapLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->legphi = atof((char*) dbrow[5]); else _rec->legphi = 0.0;
		if (dbrow[6]) _rec->legtheta = atof((char*) dbrow[6]); else _rec->legtheta = 0.0;
		if (dbrow[7]) _rec->mref = atoll((char*) dbrow[7]); else _rec->mref = 0;
		if (dbrow[8]) _rec->x = atof((char*) dbrow[8]); else _rec->x = 0.0;
		if (dbrow[9]) _rec->y = atof((char*) dbrow[9]); else _rec->y = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLegMapLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMapLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLegMapLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLegMapLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLegMapLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->legphi = atof((char*) dbrow[5]); else rec->legphi = 0.0;
			if (dbrow[6]) rec->legtheta = atof((char*) dbrow[6]); else rec->legtheta = 0.0;
			if (dbrow[7]) rec->mref = atoll((char*) dbrow[7]); else rec->mref = 0;
			if (dbrow[8]) rec->x = atof((char*) dbrow[8]); else rec->x = 0.0;
			if (dbrow[9]) rec->y = atof((char*) dbrow[9]); else rec->y = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQLegMapLocation::insertRec(
			BrlyQLegMapLocation* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->legphi,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->legtheta,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mref,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->y,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegMapLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegMapLocation / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLegMapLocation::insertRst(
			ListBrlyQLegMapLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLegMapLocation::updateRec(
			BrlyQLegMapLocation* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->legphi,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->legtheta,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mref,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->y,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegMapLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegMapLocation / stmtUpdateRec)\n");
};

void MyTblBrlyQLegMapLocation::updateRst(
			ListBrlyQLegMapLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLegMapLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegMapLocation / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegMapLocation / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLegMapLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegMapLocation / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegMapLocation / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLegMapLocation::loadRecByQref(
			ubigint qref
			, BrlyQLegMapLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLegMapLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLegMapLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMapLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLegMapLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLegMapLocation
 ******************************************************************************/

PgTblBrlyQLegMapLocation::PgTblBrlyQLegMapLocation() : TblBrlyQLegMapLocation(), PgTable() {
};

PgTblBrlyQLegMapLocation::~PgTblBrlyQLegMapLocation() {
};

void PgTblBrlyQLegMapLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLegMapLocation_insertRec", "INSERT INTO TblBrlyQLegMapLocation (qwr, jref, jnum, ref, legphi, legtheta, mref, x, y) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegMapLocation_updateRec", "UPDATE TblBrlyQLegMapLocation SET qwr = $1, jref = $2, jnum = $3, ref = $4, legphi = $5, legtheta = $6, mref = $7, x = $8, y = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegMapLocation_removeRecByQref", "DELETE FROM TblBrlyQLegMapLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegMapLocation_removeRstByJref", "DELETE FROM TblBrlyQLegMapLocation WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLegMapLocation_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, legphi, legtheta, mref, x, y FROM TblBrlyQLegMapLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegMapLocation_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, legphi, legtheta, mref, x, y FROM TblBrlyQLegMapLocation WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLegMapLocation::loadRec(
			PGresult* res
			, BrlyQLegMapLocation** rec
		) {
	char* ptr;

	BrlyQLegMapLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLegMapLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "legphi"),
			PQfnumber(res, "legtheta"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->legphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->legtheta = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->y = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLegMapLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLegMapLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLegMapLocation* rec;

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
			PQfnumber(res, "legphi"),
			PQfnumber(res, "legtheta"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		while (numread < numrow) {
			rec = new BrlyQLegMapLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->legphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->legtheta = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->y = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLegMapLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLegMapLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegMapLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLegMapLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLegMapLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMapLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegMapLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMapLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLegMapLocation::insertRec(
			BrlyQLegMapLocation* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	string _legphi = to_string(rec->legphi);
	string _legtheta = to_string(rec->legtheta);
	ubigint _mref = htonl64(rec->mref);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		_legphi.c_str(),
		_legtheta.c_str(),
		(char*) &_mref,
		_x.c_str(),
		_y.c_str()
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLegMapLocation_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLegMapLocation::insertRst(
			ListBrlyQLegMapLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLegMapLocation::updateRec(
			BrlyQLegMapLocation* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	string _legphi = to_string(rec->legphi);
	string _legtheta = to_string(rec->legtheta);
	ubigint _mref = htonl64(rec->mref);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		_legphi.c_str(),
		_legtheta.c_str(),
		(char*) &_mref,
		_x.c_str(),
		_y.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLegMapLocation_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLegMapLocation::updateRst(
			ListBrlyQLegMapLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLegMapLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegMapLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLocation_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLegMapLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegMapLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLocation_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLegMapLocation::loadRecByQref(
			ubigint qref
			, BrlyQLegMapLocation** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLegMapLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLegMapLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMapLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLegMapLocation_loadRstByJref", 1, vals, l, f, append, rst);
};

