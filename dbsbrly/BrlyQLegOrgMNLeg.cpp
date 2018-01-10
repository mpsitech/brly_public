/**
  * \file BrlyQLegOrgMNLeg.cpp
  * Dbs and XML wrapper for table TblBrlyQLegOrgMNLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLegOrgMNLeg.h"

/******************************************************************************
 class BrlyQLegOrgMNLeg
 ******************************************************************************/

BrlyQLegOrgMNLeg::BrlyQLegOrgMNLeg(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double x1VisDstLegphi0
			, const double x1VisDstLegphi1
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const double xVisDstLegphi0
			, const double xVisDstLegphi1
			, const double xVisOrgLegphi0
			, const double xVisOrgLegphi1
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->x1VisDstLegphi0 = x1VisDstLegphi0;
	this->x1VisDstLegphi1 = x1VisDstLegphi1;
	this->VisOrgLegphi0 = VisOrgLegphi0;
	this->VisOrgLegphi1 = VisOrgLegphi1;
	this->xVisDstLegphi0 = xVisDstLegphi0;
	this->xVisDstLegphi1 = xVisDstLegphi1;
	this->xVisOrgLegphi0 = xVisOrgLegphi0;
	this->xVisOrgLegphi1 = xVisOrgLegphi1;
};

void BrlyQLegOrgMNLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLegOrgMNLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeDouble(wr, "dp0", x1VisDstLegphi0);
		writeDouble(wr, "dp1", x1VisDstLegphi1);
		writeDouble(wr, "op0", VisOrgLegphi0);
		writeDouble(wr, "op1", VisOrgLegphi1);
		writeDouble(wr, "xd0", xVisDstLegphi0);
		writeDouble(wr, "xd1", xVisDstLegphi1);
		writeDouble(wr, "xo0", xVisOrgLegphi0);
		writeDouble(wr, "xo1", xVisOrgLegphi1);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeDouble(wr, "x1VisDstLegphi0", x1VisDstLegphi0);
		writeDouble(wr, "x1VisDstLegphi1", x1VisDstLegphi1);
		writeDouble(wr, "VisOrgLegphi0", VisOrgLegphi0);
		writeDouble(wr, "VisOrgLegphi1", VisOrgLegphi1);
		writeDouble(wr, "xVisDstLegphi0", xVisDstLegphi0);
		writeDouble(wr, "xVisDstLegphi1", xVisDstLegphi1);
		writeDouble(wr, "xVisOrgLegphi0", xVisOrgLegphi0);
		writeDouble(wr, "xVisOrgLegphi1", xVisOrgLegphi1);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLegOrgMNLeg
 ******************************************************************************/

ListBrlyQLegOrgMNLeg::ListBrlyQLegOrgMNLeg() {
};

ListBrlyQLegOrgMNLeg::ListBrlyQLegOrgMNLeg(
			const ListBrlyQLegOrgMNLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegOrgMNLeg(*(src.nodes[i]));
};

ListBrlyQLegOrgMNLeg::~ListBrlyQLegOrgMNLeg() {
	clear();
};

void ListBrlyQLegOrgMNLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLegOrgMNLeg::size() const {
	return(nodes.size());
};

void ListBrlyQLegOrgMNLeg::append(
			BrlyQLegOrgMNLeg* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLegOrgMNLeg& ListBrlyQLegOrgMNLeg::operator=(
			const ListBrlyQLegOrgMNLeg& src
		) {
	BrlyQLegOrgMNLeg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLegOrgMNLeg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLegOrgMNLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLegOrgMNLeg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLegOrgMNLeg
 ******************************************************************************/

TblBrlyQLegOrgMNLeg::TblBrlyQLegOrgMNLeg() {
};

TblBrlyQLegOrgMNLeg::~TblBrlyQLegOrgMNLeg() {
};

bool TblBrlyQLegOrgMNLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegOrgMNLeg** rec
		) {
	return false;
};

ubigint TblBrlyQLegOrgMNLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegOrgMNLeg& rst
		) {
	return 0;
};

void TblBrlyQLegOrgMNLeg::insertRec(
			BrlyQLegOrgMNLeg* rec
		) {
};

ubigint TblBrlyQLegOrgMNLeg::insertNewRec(
			BrlyQLegOrgMNLeg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double x1VisDstLegphi0
			, const double x1VisDstLegphi1
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const double xVisDstLegphi0
			, const double xVisDstLegphi1
			, const double xVisOrgLegphi0
			, const double xVisOrgLegphi1
		) {
	ubigint retval = 0;
	BrlyQLegOrgMNLeg* _rec = NULL;

	_rec = new BrlyQLegOrgMNLeg(0, jref, jnum, mref, stubMref, ref, x1VisDstLegphi0, x1VisDstLegphi1, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLegOrgMNLeg::appendNewRecToRst(
			ListBrlyQLegOrgMNLeg& rst
			, BrlyQLegOrgMNLeg** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double x1VisDstLegphi0
			, const double x1VisDstLegphi1
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const double xVisDstLegphi0
			, const double xVisDstLegphi1
			, const double xVisOrgLegphi0
			, const double xVisOrgLegphi1
		) {
	ubigint retval = 0;
	BrlyQLegOrgMNLeg* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1VisDstLegphi0, x1VisDstLegphi1, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLegOrgMNLeg::insertRst(
			ListBrlyQLegOrgMNLeg& rst
		) {
};

void TblBrlyQLegOrgMNLeg::updateRec(
			BrlyQLegOrgMNLeg* rec
		) {
};

void TblBrlyQLegOrgMNLeg::updateRst(
			ListBrlyQLegOrgMNLeg& rst
		) {
};

void TblBrlyQLegOrgMNLeg::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLegOrgMNLeg::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLegOrgMNLeg::loadRecByQref(
			ubigint qref
			, BrlyQLegOrgMNLeg** rec
		) {
	return false;
};

ubigint TblBrlyQLegOrgMNLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegOrgMNLeg& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLegOrgMNLeg
 ******************************************************************************/

MyTblBrlyQLegOrgMNLeg::MyTblBrlyQLegOrgMNLeg() : TblBrlyQLegOrgMNLeg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLegOrgMNLeg::~MyTblBrlyQLegOrgMNLeg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLegOrgMNLeg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLegOrgMNLeg (jref, jnum, mref, ref, x1VisDstLegphi0, x1VisDstLegphi1, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLegOrgMNLeg SET jref = ?, jnum = ?, mref = ?, ref = ?, x1VisDstLegphi0 = ?, x1VisDstLegphi1 = ?, VisOrgLegphi0 = ?, VisOrgLegphi1 = ?, xVisDstLegphi0 = ?, xVisDstLegphi1 = ?, xVisOrgLegphi0 = ?, xVisOrgLegphi1 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLegOrgMNLeg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLegOrgMNLeg WHERE jref = ?", false);
};

bool MyTblBrlyQLegOrgMNLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegOrgMNLeg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLegOrgMNLeg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLegOrgMNLeg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLegOrgMNLeg();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1VisDstLegphi0 = atof((char*) dbrow[5]); else _rec->x1VisDstLegphi0 = 0.0;
		if (dbrow[6]) _rec->x1VisDstLegphi1 = atof((char*) dbrow[6]); else _rec->x1VisDstLegphi1 = 0.0;
		if (dbrow[7]) _rec->VisOrgLegphi0 = atof((char*) dbrow[7]); else _rec->VisOrgLegphi0 = 0.0;
		if (dbrow[8]) _rec->VisOrgLegphi1 = atof((char*) dbrow[8]); else _rec->VisOrgLegphi1 = 0.0;
		if (dbrow[9]) _rec->xVisDstLegphi0 = atof((char*) dbrow[9]); else _rec->xVisDstLegphi0 = 0.0;
		if (dbrow[10]) _rec->xVisDstLegphi1 = atof((char*) dbrow[10]); else _rec->xVisDstLegphi1 = 0.0;
		if (dbrow[11]) _rec->xVisOrgLegphi0 = atof((char*) dbrow[11]); else _rec->xVisOrgLegphi0 = 0.0;
		if (dbrow[12]) _rec->xVisOrgLegphi1 = atof((char*) dbrow[12]); else _rec->xVisOrgLegphi1 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLegOrgMNLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegOrgMNLeg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLegOrgMNLeg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLegOrgMNLeg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLegOrgMNLeg();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1VisDstLegphi0 = atof((char*) dbrow[5]); else rec->x1VisDstLegphi0 = 0.0;
			if (dbrow[6]) rec->x1VisDstLegphi1 = atof((char*) dbrow[6]); else rec->x1VisDstLegphi1 = 0.0;
			if (dbrow[7]) rec->VisOrgLegphi0 = atof((char*) dbrow[7]); else rec->VisOrgLegphi0 = 0.0;
			if (dbrow[8]) rec->VisOrgLegphi1 = atof((char*) dbrow[8]); else rec->VisOrgLegphi1 = 0.0;
			if (dbrow[9]) rec->xVisDstLegphi0 = atof((char*) dbrow[9]); else rec->xVisDstLegphi0 = 0.0;
			if (dbrow[10]) rec->xVisDstLegphi1 = atof((char*) dbrow[10]); else rec->xVisDstLegphi1 = 0.0;
			if (dbrow[11]) rec->xVisOrgLegphi0 = atof((char*) dbrow[11]); else rec->xVisOrgLegphi0 = 0.0;
			if (dbrow[12]) rec->xVisOrgLegphi1 = atof((char*) dbrow[12]); else rec->xVisOrgLegphi1 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQLegOrgMNLeg::insertRec(
			BrlyQLegOrgMNLeg* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->x1VisDstLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1VisDstLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->VisOrgLegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->VisOrgLegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->xVisDstLegphi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->xVisDstLegphi1,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->xVisOrgLegphi0,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->xVisOrgLegphi1,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegOrgMNLeg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegOrgMNLeg / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLegOrgMNLeg::insertRst(
			ListBrlyQLegOrgMNLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLegOrgMNLeg::updateRec(
			BrlyQLegOrgMNLeg* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->x1VisDstLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->x1VisDstLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->VisOrgLegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->VisOrgLegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->xVisDstLegphi0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->xVisDstLegphi1,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->xVisOrgLegphi0,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->xVisOrgLegphi1,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->qref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegOrgMNLeg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegOrgMNLeg / stmtUpdateRec)\n");
};

void MyTblBrlyQLegOrgMNLeg::updateRst(
			ListBrlyQLegOrgMNLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLegOrgMNLeg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegOrgMNLeg / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegOrgMNLeg / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLegOrgMNLeg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegOrgMNLeg / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegOrgMNLeg / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLegOrgMNLeg::loadRecByQref(
			ubigint qref
			, BrlyQLegOrgMNLeg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLegOrgMNLeg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLegOrgMNLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegOrgMNLeg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLegOrgMNLeg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLegOrgMNLeg
 ******************************************************************************/

PgTblBrlyQLegOrgMNLeg::PgTblBrlyQLegOrgMNLeg() : TblBrlyQLegOrgMNLeg(), PgTable() {
};

PgTblBrlyQLegOrgMNLeg::~PgTblBrlyQLegOrgMNLeg() {
};

void PgTblBrlyQLegOrgMNLeg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLegOrgMNLeg_insertRec", "INSERT INTO TblBrlyQLegOrgMNLeg (jref, jnum, mref, ref, x1VisDstLegphi0, x1VisDstLegphi1, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING qref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegOrgMNLeg_updateRec", "UPDATE TblBrlyQLegOrgMNLeg SET jref = $1, jnum = $2, mref = $3, ref = $4, x1VisDstLegphi0 = $5, x1VisDstLegphi1 = $6, VisOrgLegphi0 = $7, VisOrgLegphi1 = $8, xVisDstLegphi0 = $9, xVisDstLegphi1 = $10, xVisOrgLegphi0 = $11, xVisOrgLegphi1 = $12 WHERE qref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegOrgMNLeg_removeRecByQref", "DELETE FROM TblBrlyQLegOrgMNLeg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegOrgMNLeg_removeRstByJref", "DELETE FROM TblBrlyQLegOrgMNLeg WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLegOrgMNLeg_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1VisDstLegphi0, x1VisDstLegphi1, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1 FROM TblBrlyQLegOrgMNLeg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegOrgMNLeg_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1VisDstLegphi0, x1VisDstLegphi1, VisOrgLegphi0, VisOrgLegphi1, xVisDstLegphi0, xVisDstLegphi1, xVisOrgLegphi0, xVisOrgLegphi1 FROM TblBrlyQLegOrgMNLeg WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLegOrgMNLeg::loadRec(
			PGresult* res
			, BrlyQLegOrgMNLeg** rec
		) {
	char* ptr;

	BrlyQLegOrgMNLeg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLegOrgMNLeg();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1visdstlegphi0"),
			PQfnumber(res, "x1visdstlegphi1"),
			PQfnumber(res, "visorglegphi0"),
			PQfnumber(res, "visorglegphi1"),
			PQfnumber(res, "xvisdstlegphi0"),
			PQfnumber(res, "xvisdstlegphi1"),
			PQfnumber(res, "xvisorglegphi0"),
			PQfnumber(res, "xvisorglegphi1")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1VisDstLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1VisDstLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->VisOrgLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->VisOrgLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->xVisDstLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->xVisDstLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->xVisOrgLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->xVisOrgLegphi1 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLegOrgMNLeg::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLegOrgMNLeg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLegOrgMNLeg* rec;

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
			PQfnumber(res, "x1visdstlegphi0"),
			PQfnumber(res, "x1visdstlegphi1"),
			PQfnumber(res, "visorglegphi0"),
			PQfnumber(res, "visorglegphi1"),
			PQfnumber(res, "xvisdstlegphi0"),
			PQfnumber(res, "xvisdstlegphi1"),
			PQfnumber(res, "xvisorglegphi0"),
			PQfnumber(res, "xvisorglegphi1")
		};

		while (numread < numrow) {
			rec = new BrlyQLegOrgMNLeg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1VisDstLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1VisDstLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->VisOrgLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->VisOrgLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->xVisDstLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->xVisDstLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->xVisOrgLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->xVisOrgLegphi1 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLegOrgMNLeg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLegOrgMNLeg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegOrgMNLeg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegOrgMNLeg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLegOrgMNLeg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegOrgMNLeg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLegOrgMNLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegOrgMNLeg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegOrgMNLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegOrgMNLeg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLegOrgMNLeg::insertRec(
			BrlyQLegOrgMNLeg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	string _x1VisDstLegphi0 = to_string(rec->x1VisDstLegphi0);
	string _x1VisDstLegphi1 = to_string(rec->x1VisDstLegphi1);
	string _VisOrgLegphi0 = to_string(rec->VisOrgLegphi0);
	string _VisOrgLegphi1 = to_string(rec->VisOrgLegphi1);
	string _xVisDstLegphi0 = to_string(rec->xVisDstLegphi0);
	string _xVisDstLegphi1 = to_string(rec->xVisDstLegphi1);
	string _xVisOrgLegphi0 = to_string(rec->xVisOrgLegphi0);
	string _xVisOrgLegphi1 = to_string(rec->xVisOrgLegphi1);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		_x1VisDstLegphi0.c_str(),
		_x1VisDstLegphi1.c_str(),
		_VisOrgLegphi0.c_str(),
		_VisOrgLegphi1.c_str(),
		_xVisDstLegphi0.c_str(),
		_xVisDstLegphi1.c_str(),
		_xVisOrgLegphi0.c_str(),
		_xVisOrgLegphi1.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLegOrgMNLeg_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegOrgMNLeg_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLegOrgMNLeg::insertRst(
			ListBrlyQLegOrgMNLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLegOrgMNLeg::updateRec(
			BrlyQLegOrgMNLeg* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	string _x1VisDstLegphi0 = to_string(rec->x1VisDstLegphi0);
	string _x1VisDstLegphi1 = to_string(rec->x1VisDstLegphi1);
	string _VisOrgLegphi0 = to_string(rec->VisOrgLegphi0);
	string _VisOrgLegphi1 = to_string(rec->VisOrgLegphi1);
	string _xVisDstLegphi0 = to_string(rec->xVisDstLegphi0);
	string _xVisDstLegphi1 = to_string(rec->xVisDstLegphi1);
	string _xVisOrgLegphi0 = to_string(rec->xVisOrgLegphi0);
	string _xVisOrgLegphi1 = to_string(rec->xVisOrgLegphi1);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		_x1VisDstLegphi0.c_str(),
		_x1VisDstLegphi1.c_str(),
		_VisOrgLegphi0.c_str(),
		_VisOrgLegphi1.c_str(),
		_xVisDstLegphi0.c_str(),
		_xVisDstLegphi1.c_str(),
		_xVisOrgLegphi0.c_str(),
		_xVisOrgLegphi1.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLegOrgMNLeg_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegOrgMNLeg_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLegOrgMNLeg::updateRst(
			ListBrlyQLegOrgMNLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLegOrgMNLeg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegOrgMNLeg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegOrgMNLeg_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLegOrgMNLeg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegOrgMNLeg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegOrgMNLeg_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLegOrgMNLeg::loadRecByQref(
			ubigint qref
			, BrlyQLegOrgMNLeg** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLegOrgMNLeg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLegOrgMNLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegOrgMNLeg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLegOrgMNLeg_loadRstByJref", 1, vals, l, f, append, rst);
};

