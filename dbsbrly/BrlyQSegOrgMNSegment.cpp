/**
  * \file BrlyQSegOrgMNSegment.cpp
  * Dbs and XML wrapper for table TblBrlyQSegOrgMNSegment (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQSegOrgMNSegment.h"

/******************************************************************************
 class BrlyQSegOrgMNSegment
 ******************************************************************************/

BrlyQSegOrgMNSegment::BrlyQSegOrgMNSegment(
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
			, const double x2VisDstSegphi0
			, const double x2VisDstSegphi1
			, const double VisOrgSegphi0
			, const double VisOrgSegphi1
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
	this->x2VisDstSegphi0 = x2VisDstSegphi0;
	this->x2VisDstSegphi1 = x2VisDstSegphi1;
	this->VisOrgSegphi0 = VisOrgSegphi0;
	this->VisOrgSegphi1 = VisOrgSegphi1;
};

void BrlyQSegOrgMNSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQSegOrgMNSegment";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "sta", ftmX1Start);
		writeString(wr, "sto", ftmX1Stop);
		writeDouble(wr, "dp0", x2VisDstSegphi0);
		writeDouble(wr, "dp1", x2VisDstSegphi1);
		writeDouble(wr, "op0", VisOrgSegphi0);
		writeDouble(wr, "op1", VisOrgSegphi1);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "ftmX1Start", ftmX1Start);
		writeString(wr, "ftmX1Stop", ftmX1Stop);
		writeDouble(wr, "x2VisDstSegphi0", x2VisDstSegphi0);
		writeDouble(wr, "x2VisDstSegphi1", x2VisDstSegphi1);
		writeDouble(wr, "VisOrgSegphi0", VisOrgSegphi0);
		writeDouble(wr, "VisOrgSegphi1", VisOrgSegphi1);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQSegOrgMNSegment
 ******************************************************************************/

ListBrlyQSegOrgMNSegment::ListBrlyQSegOrgMNSegment() {
};

ListBrlyQSegOrgMNSegment::ListBrlyQSegOrgMNSegment(
			const ListBrlyQSegOrgMNSegment& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegOrgMNSegment(*(src.nodes[i]));
};

ListBrlyQSegOrgMNSegment::~ListBrlyQSegOrgMNSegment() {
	clear();
};

void ListBrlyQSegOrgMNSegment::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQSegOrgMNSegment::size() const {
	return(nodes.size());
};

void ListBrlyQSegOrgMNSegment::append(
			BrlyQSegOrgMNSegment* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQSegOrgMNSegment& ListBrlyQSegOrgMNSegment::operator=(
			const ListBrlyQSegOrgMNSegment& src
		) {
	BrlyQSegOrgMNSegment* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQSegOrgMNSegment(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQSegOrgMNSegment::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQSegOrgMNSegment";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQSegOrgMNSegment
 ******************************************************************************/

TblBrlyQSegOrgMNSegment::TblBrlyQSegOrgMNSegment() {
};

TblBrlyQSegOrgMNSegment::~TblBrlyQSegOrgMNSegment() {
};

bool TblBrlyQSegOrgMNSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegOrgMNSegment** rec
		) {
	return false;
};

ubigint TblBrlyQSegOrgMNSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegOrgMNSegment& rst
		) {
	return 0;
};

void TblBrlyQSegOrgMNSegment::insertRec(
			BrlyQSegOrgMNSegment* rec
		) {
};

ubigint TblBrlyQSegOrgMNSegment::insertNewRec(
			BrlyQSegOrgMNSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const double x2VisDstSegphi0
			, const double x2VisDstSegphi1
			, const double VisOrgSegphi0
			, const double VisOrgSegphi1
		) {
	ubigint retval = 0;
	BrlyQSegOrgMNSegment* _rec = NULL;

	_rec = new BrlyQSegOrgMNSegment(0, jref, jnum, mref, stubMref, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, x2VisDstSegphi0, x2VisDstSegphi1, VisOrgSegphi0, VisOrgSegphi1);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQSegOrgMNSegment::appendNewRecToRst(
			ListBrlyQSegOrgMNSegment& rst
			, BrlyQSegOrgMNSegment** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const double x2VisDstSegphi0
			, const double x2VisDstSegphi1
			, const double VisOrgSegphi0
			, const double VisOrgSegphi1
		) {
	ubigint retval = 0;
	BrlyQSegOrgMNSegment* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, x2VisDstSegphi0, x2VisDstSegphi1, VisOrgSegphi0, VisOrgSegphi1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQSegOrgMNSegment::insertRst(
			ListBrlyQSegOrgMNSegment& rst
		) {
};

void TblBrlyQSegOrgMNSegment::updateRec(
			BrlyQSegOrgMNSegment* rec
		) {
};

void TblBrlyQSegOrgMNSegment::updateRst(
			ListBrlyQSegOrgMNSegment& rst
		) {
};

void TblBrlyQSegOrgMNSegment::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQSegOrgMNSegment::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQSegOrgMNSegment::loadRecByQref(
			ubigint qref
			, BrlyQSegOrgMNSegment** rec
		) {
	return false;
};

ubigint TblBrlyQSegOrgMNSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegOrgMNSegment& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQSegOrgMNSegment
 ******************************************************************************/

MyTblBrlyQSegOrgMNSegment::MyTblBrlyQSegOrgMNSegment() : TblBrlyQSegOrgMNSegment(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQSegOrgMNSegment::~MyTblBrlyQSegOrgMNSegment() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQSegOrgMNSegment::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQSegOrgMNSegment (jref, jnum, mref, ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, VisOrgSegphi0, VisOrgSegphi1) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQSegOrgMNSegment SET jref = ?, jnum = ?, mref = ?, ref = ?, x1Start = ?, x1Stop = ?, x2VisDstSegphi0 = ?, x2VisDstSegphi1 = ?, VisOrgSegphi0 = ?, VisOrgSegphi1 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQSegOrgMNSegment WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQSegOrgMNSegment WHERE jref = ?", false);
};

bool MyTblBrlyQSegOrgMNSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegOrgMNSegment** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQSegOrgMNSegment* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQSegOrgMNSegment / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQSegOrgMNSegment();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1Start = atol((char*) dbrow[5]); else _rec->x1Start = 0;
		if (dbrow[6]) _rec->x1Stop = atol((char*) dbrow[6]); else _rec->x1Stop = 0;
		if (dbrow[7]) _rec->x2VisDstSegphi0 = atof((char*) dbrow[7]); else _rec->x2VisDstSegphi0 = 0.0;
		if (dbrow[8]) _rec->x2VisDstSegphi1 = atof((char*) dbrow[8]); else _rec->x2VisDstSegphi1 = 0.0;
		if (dbrow[9]) _rec->VisOrgSegphi0 = atof((char*) dbrow[9]); else _rec->VisOrgSegphi0 = 0.0;
		if (dbrow[10]) _rec->VisOrgSegphi1 = atof((char*) dbrow[10]); else _rec->VisOrgSegphi1 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQSegOrgMNSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegOrgMNSegment& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQSegOrgMNSegment* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQSegOrgMNSegment / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQSegOrgMNSegment();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1Start = atol((char*) dbrow[5]); else rec->x1Start = 0;
			if (dbrow[6]) rec->x1Stop = atol((char*) dbrow[6]); else rec->x1Stop = 0;
			if (dbrow[7]) rec->x2VisDstSegphi0 = atof((char*) dbrow[7]); else rec->x2VisDstSegphi0 = 0.0;
			if (dbrow[8]) rec->x2VisDstSegphi1 = atof((char*) dbrow[8]); else rec->x2VisDstSegphi1 = 0.0;
			if (dbrow[9]) rec->VisOrgSegphi0 = atof((char*) dbrow[9]); else rec->VisOrgSegphi0 = 0.0;
			if (dbrow[10]) rec->VisOrgSegphi1 = atof((char*) dbrow[10]); else rec->VisOrgSegphi1 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQSegOrgMNSegment::insertRec(
			BrlyQSegOrgMNSegment* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x2VisDstSegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x2VisDstSegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->VisOrgSegphi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->VisOrgSegphi1,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegOrgMNSegment / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegOrgMNSegment / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQSegOrgMNSegment::insertRst(
			ListBrlyQSegOrgMNSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQSegOrgMNSegment::updateRec(
			BrlyQSegOrgMNSegment* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x2VisDstSegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x2VisDstSegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->VisOrgSegphi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->VisOrgSegphi1,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegOrgMNSegment / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegOrgMNSegment / stmtUpdateRec)\n");
};

void MyTblBrlyQSegOrgMNSegment::updateRst(
			ListBrlyQSegOrgMNSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQSegOrgMNSegment::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegOrgMNSegment / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegOrgMNSegment / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQSegOrgMNSegment::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegOrgMNSegment / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegOrgMNSegment / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQSegOrgMNSegment::loadRecByQref(
			ubigint qref
			, BrlyQSegOrgMNSegment** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQSegOrgMNSegment WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQSegOrgMNSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegOrgMNSegment& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQSegOrgMNSegment WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQSegOrgMNSegment
 ******************************************************************************/

PgTblBrlyQSegOrgMNSegment::PgTblBrlyQSegOrgMNSegment() : TblBrlyQSegOrgMNSegment(), PgTable() {
};

PgTblBrlyQSegOrgMNSegment::~PgTblBrlyQSegOrgMNSegment() {
};

void PgTblBrlyQSegOrgMNSegment::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQSegOrgMNSegment_insertRec", "INSERT INTO TblBrlyQSegOrgMNSegment (jref, jnum, mref, ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, VisOrgSegphi0, VisOrgSegphi1) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegOrgMNSegment_updateRec", "UPDATE TblBrlyQSegOrgMNSegment SET jref = $1, jnum = $2, mref = $3, ref = $4, x1Start = $5, x1Stop = $6, x2VisDstSegphi0 = $7, x2VisDstSegphi1 = $8, VisOrgSegphi0 = $9, VisOrgSegphi1 = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegOrgMNSegment_removeRecByQref", "DELETE FROM TblBrlyQSegOrgMNSegment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegOrgMNSegment_removeRstByJref", "DELETE FROM TblBrlyQSegOrgMNSegment WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQSegOrgMNSegment_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, VisOrgSegphi0, VisOrgSegphi1 FROM TblBrlyQSegOrgMNSegment WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegOrgMNSegment_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1Start, x1Stop, x2VisDstSegphi0, x2VisDstSegphi1, VisOrgSegphi0, VisOrgSegphi1 FROM TblBrlyQSegOrgMNSegment WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQSegOrgMNSegment::loadRec(
			PGresult* res
			, BrlyQSegOrgMNSegment** rec
		) {
	char* ptr;

	BrlyQSegOrgMNSegment* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQSegOrgMNSegment();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2visdstsegphi0"),
			PQfnumber(res, "x2visdstsegphi1"),
			PQfnumber(res, "visorgsegphi0"),
			PQfnumber(res, "visorgsegphi1")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x2VisDstSegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x2VisDstSegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->VisOrgSegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->VisOrgSegphi1 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQSegOrgMNSegment::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQSegOrgMNSegment& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQSegOrgMNSegment* rec;

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
			PQfnumber(res, "x2visdstsegphi0"),
			PQfnumber(res, "x2visdstsegphi1"),
			PQfnumber(res, "visorgsegphi0"),
			PQfnumber(res, "visorgsegphi1")
		};

		while (numread < numrow) {
			rec = new BrlyQSegOrgMNSegment();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x2VisDstSegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x2VisDstSegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->VisOrgSegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->VisOrgSegphi1 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQSegOrgMNSegment::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQSegOrgMNSegment** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegOrgMNSegment / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQSegOrgMNSegment::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQSegOrgMNSegment& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegOrgMNSegment / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQSegOrgMNSegment::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegOrgMNSegment** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQSegOrgMNSegment::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegOrgMNSegment& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQSegOrgMNSegment::insertRec(
			BrlyQSegOrgMNSegment* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2VisDstSegphi0 = to_string(rec->x2VisDstSegphi0);
	string _x2VisDstSegphi1 = to_string(rec->x2VisDstSegphi1);
	string _VisOrgSegphi0 = to_string(rec->VisOrgSegphi0);
	string _VisOrgSegphi1 = to_string(rec->VisOrgSegphi1);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2VisDstSegphi0.c_str(),
		_x2VisDstSegphi1.c_str(),
		_VisOrgSegphi0.c_str(),
		_VisOrgSegphi1.c_str()
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
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQSegOrgMNSegment_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegOrgMNSegment_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQSegOrgMNSegment::insertRst(
			ListBrlyQSegOrgMNSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQSegOrgMNSegment::updateRec(
			BrlyQSegOrgMNSegment* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2VisDstSegphi0 = to_string(rec->x2VisDstSegphi0);
	string _x2VisDstSegphi1 = to_string(rec->x2VisDstSegphi1);
	string _VisOrgSegphi0 = to_string(rec->VisOrgSegphi0);
	string _VisOrgSegphi1 = to_string(rec->VisOrgSegphi1);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2VisDstSegphi0.c_str(),
		_x2VisDstSegphi1.c_str(),
		_VisOrgSegphi0.c_str(),
		_VisOrgSegphi1.c_str(),
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
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQSegOrgMNSegment_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegOrgMNSegment_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQSegOrgMNSegment::updateRst(
			ListBrlyQSegOrgMNSegment& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQSegOrgMNSegment::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQSegOrgMNSegment_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegOrgMNSegment_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQSegOrgMNSegment::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQSegOrgMNSegment_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegOrgMNSegment_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQSegOrgMNSegment::loadRecByQref(
			ubigint qref
			, BrlyQSegOrgMNSegment** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQSegOrgMNSegment_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQSegOrgMNSegment::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegOrgMNSegment& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQSegOrgMNSegment_loadRstByJref", 1, vals, l, f, append, rst);
};

