/**
  * \file BrlyQConMNSegment.cpp
  * Dbs and XML wrapper for table TblBrlyQConMNSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQConMNSegment.h"

/******************************************************************************
 class BrlyQConMNSegment
 ******************************************************************************/

BrlyQConMNSegment::BrlyQConMNSegment(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const double x2Legphi0
			, const double x2Legphi1
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->x1Start = x1Start;
	this->ftmX1Start = ftmX1Start;
	this->x1Stop = x1Stop;
	this->ftmX1Stop = ftmX1Stop;
	this->x2Legphi0 = x2Legphi0;
	this->x2Legphi1 = x2Legphi1;
};

void BrlyQConMNSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConMNSegment";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "sta", ftmX1Start);
		writeString(wr, "sto", ftmX1Stop);
		writeDouble(wr, "lp0", x2Legphi0);
		writeDouble(wr, "lp1", x2Legphi1);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "ftmX1Start", ftmX1Start);
		writeString(wr, "ftmX1Stop", ftmX1Stop);
		writeDouble(wr, "x2Legphi0", x2Legphi0);
		writeDouble(wr, "x2Legphi1", x2Legphi1);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQConMNSegment
 ******************************************************************************/

ListBrlyQConMNSegment::ListBrlyQConMNSegment() {
};

ListBrlyQConMNSegment::ListBrlyQConMNSegment(
			const ListBrlyQConMNSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMNSegment(*(src.nodes[i]));
};

ListBrlyQConMNSegment::~ListBrlyQConMNSegment() {
	clear();
};

void ListBrlyQConMNSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConMNSegment::size() const {
	return(nodes.size());
};

void ListBrlyQConMNSegment::append(
			BrlyQConMNSegment* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConMNSegment& ListBrlyQConMNSegment::operator=(
			const ListBrlyQConMNSegment& src
		) {
	BrlyQConMNSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQConMNSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConMNSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConMNSegment";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConMNSegment
 ******************************************************************************/

TblBrlyQConMNSegment::TblBrlyQConMNSegment() {
};

TblBrlyQConMNSegment::~TblBrlyQConMNSegment() {
};

bool TblBrlyQConMNSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMNSegment** rec
		) {
	return false;
};

ubigint TblBrlyQConMNSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMNSegment& rst
		) {
	return 0;
};

void TblBrlyQConMNSegment::insertRec(
			BrlyQConMNSegment* rec
		) {
};

ubigint TblBrlyQConMNSegment::insertNewRec(
			BrlyQConMNSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const double x2Legphi0
			, const double x2Legphi1
		) {
	ubigint retval = 0;
	BrlyQConMNSegment* _rec = NULL;

	_rec = new BrlyQConMNSegment(0, jref, jnum, mref, stubMref, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, x2Legphi0, x2Legphi1);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConMNSegment::appendNewRecToRst(
			ListBrlyQConMNSegment& rst
			, BrlyQConMNSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const double x2Legphi0
			, const double x2Legphi1
		) {
	ubigint retval = 0;
	BrlyQConMNSegment* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, x2Legphi0, x2Legphi1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConMNSegment::insertRst(
			ListBrlyQConMNSegment& rst
		) {
};

void TblBrlyQConMNSegment::updateRec(
			BrlyQConMNSegment* rec
		) {
};

void TblBrlyQConMNSegment::updateRst(
			ListBrlyQConMNSegment& rst
		) {
};

void TblBrlyQConMNSegment::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConMNSegment::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConMNSegment::loadRecByQref(
			ubigint qref
			, BrlyQConMNSegment** rec
		) {
	return false;
};

ubigint TblBrlyQConMNSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMNSegment& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQConMNSegment
 ******************************************************************************/

MyTblBrlyQConMNSegment::MyTblBrlyQConMNSegment() : TblBrlyQConMNSegment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConMNSegment::~MyTblBrlyQConMNSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConMNSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConMNSegment (jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConMNSegment SET jref = ?, jnum = ?, mref = ?, ref = ?, x1Start = ?, x1Stop = ?, x2Legphi0 = ?, x2Legphi1 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConMNSegment WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConMNSegment WHERE jref = ?", false);
};

bool MyTblBrlyQConMNSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMNSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConMNSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMNSegment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConMNSegment();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1Start = atol((char*) dbrow[5]); else _rec->x1Start = 0;
		if (dbrow[6]) _rec->x1Stop = atol((char*) dbrow[6]); else _rec->x1Stop = 0;
		if (dbrow[7]) _rec->x2Legphi0 = atof((char*) dbrow[7]); else _rec->x2Legphi0 = 0.0;
		if (dbrow[8]) _rec->x2Legphi1 = atof((char*) dbrow[8]); else _rec->x2Legphi1 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQConMNSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMNSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConMNSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMNSegment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConMNSegment();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1Start = atol((char*) dbrow[5]); else rec->x1Start = 0;
			if (dbrow[6]) rec->x1Stop = atol((char*) dbrow[6]); else rec->x1Stop = 0;
			if (dbrow[7]) rec->x2Legphi0 = atof((char*) dbrow[7]); else rec->x2Legphi0 = 0.0;
			if (dbrow[8]) rec->x2Legphi1 = atof((char*) dbrow[8]); else rec->x2Legphi1 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQConMNSegment::insertRec(
			BrlyQConMNSegment* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x2Legphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x2Legphi1,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMNSegment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMNSegment / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQConMNSegment::insertRst(
			ListBrlyQConMNSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConMNSegment::updateRec(
			BrlyQConMNSegment* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x2Legphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x2Legphi1,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMNSegment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMNSegment / stmtUpdateRec)\n");
};

void MyTblBrlyQConMNSegment::updateRst(
			ListBrlyQConMNSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConMNSegment::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMNSegment / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMNSegment / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQConMNSegment::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMNSegment / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMNSegment / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQConMNSegment::loadRecByQref(
			ubigint qref
			, BrlyQConMNSegment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQConMNSegment WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConMNSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMNSegment& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConMNSegment WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQConMNSegment
 ******************************************************************************/

PgTblBrlyQConMNSegment::PgTblBrlyQConMNSegment() : TblBrlyQConMNSegment(), PgTable() {
};

PgTblBrlyQConMNSegment::~PgTblBrlyQConMNSegment() {
};

void PgTblBrlyQConMNSegment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQConMNSegment_insertRec", "INSERT INTO TblBrlyQConMNSegment (jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMNSegment_updateRec", "UPDATE TblBrlyQConMNSegment SET jref = $1, jnum = $2, mref = $3, ref = $4, x1Start = $5, x1Stop = $6, x2Legphi0 = $7, x2Legphi1 = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMNSegment_removeRecByQref", "DELETE FROM TblBrlyQConMNSegment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMNSegment_removeRstByJref", "DELETE FROM TblBrlyQConMNSegment WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQConMNSegment_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1 FROM TblBrlyQConMNSegment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMNSegment_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1 FROM TblBrlyQConMNSegment WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQConMNSegment::loadRec(
			PGresult* res
			, BrlyQConMNSegment** rec
		) {
	char* ptr;

	BrlyQConMNSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConMNSegment();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2legphi0"),
			PQfnumber(res, "x2legphi1")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x2Legphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x2Legphi1 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQConMNSegment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConMNSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConMNSegment* rec;

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
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2legphi0"),
			PQfnumber(res, "x2legphi1")
		};

		while (numread < numrow) {
			rec = new BrlyQConMNSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x2Legphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x2Legphi1 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQConMNSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConMNSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMNSegment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMNSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConMNSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMNSegment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConMNSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMNSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMNSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMNSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQConMNSegment::insertRec(
			BrlyQConMNSegment* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2Legphi0 = to_string(rec->x2Legphi0);
	string _x2Legphi1 = to_string(rec->x2Legphi1);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2Legphi0.c_str(),
		_x2Legphi1.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQConMNSegment_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMNSegment_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQConMNSegment::insertRst(
			ListBrlyQConMNSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConMNSegment::updateRec(
			BrlyQConMNSegment* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2Legphi0 = to_string(rec->x2Legphi0);
	string _x2Legphi1 = to_string(rec->x2Legphi1);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2Legphi0.c_str(),
		_x2Legphi1.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMNSegment_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMNSegment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQConMNSegment::updateRst(
			ListBrlyQConMNSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConMNSegment::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMNSegment_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMNSegment_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQConMNSegment::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMNSegment_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMNSegment_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQConMNSegment::loadRecByQref(
			ubigint qref
			, BrlyQConMNSegment** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQConMNSegment_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConMNSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMNSegment& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConMNSegment_loadRstByJref", 1, vals, l, f, append, rst);
};

