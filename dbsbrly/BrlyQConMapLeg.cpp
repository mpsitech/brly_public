/**
  * \file BrlyQConMapLeg.cpp
  * Dbs and XML wrapper for table TblBrlyQConMapLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQConMapLeg.h"

/******************************************************************************
 class BrlyQConMapLeg
 ******************************************************************************/

BrlyQConMapLeg::BrlyQConMapLeg(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mbgnRefBrlyMLocation
			, const ubigint mendRefBrlyMLocation
			, const double mdeltaphi
			, const double dx
			, const double dy
			, const double x0
			, const double y0
		) {
	this->qref = qref;
	this->qwr = qwr;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->VisOrgLegphi0 = VisOrgLegphi0;
	this->VisOrgLegphi1 = VisOrgLegphi1;
	this->mref = mref;
	this->stubMref = stubMref;
	this->mbgnRefBrlyMLocation = mbgnRefBrlyMLocation;
	this->mendRefBrlyMLocation = mendRefBrlyMLocation;
	this->mdeltaphi = mdeltaphi;
	this->dx = dx;
	this->dy = dy;
	this->x0 = x0;
	this->y0 = y0;
};

void BrlyQConMapLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConMapLeg";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
		writeDouble(wr, "x0", x0);
		writeDouble(wr, "y0", y0);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
		writeDouble(wr, "x0", x0);
		writeDouble(wr, "y0", y0);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQConMapLeg
 ******************************************************************************/

ListBrlyQConMapLeg::ListBrlyQConMapLeg() {
};

ListBrlyQConMapLeg::ListBrlyQConMapLeg(
			const ListBrlyQConMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapLeg(*(src.nodes[i]));
};

ListBrlyQConMapLeg::~ListBrlyQConMapLeg() {
	clear();
};

void ListBrlyQConMapLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConMapLeg::size() const {
	return(nodes.size());
};

void ListBrlyQConMapLeg::append(
			BrlyQConMapLeg* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConMapLeg& ListBrlyQConMapLeg::operator=(
			const ListBrlyQConMapLeg& src
		) {
	BrlyQConMapLeg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQConMapLeg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConMapLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConMapLeg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConMapLeg
 ******************************************************************************/

TblBrlyQConMapLeg::TblBrlyQConMapLeg() {
};

TblBrlyQConMapLeg::~TblBrlyQConMapLeg() {
};

bool TblBrlyQConMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapLeg** rec
		) {
	return false;
};

ubigint TblBrlyQConMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapLeg& rst
		) {
	return 0;
};

void TblBrlyQConMapLeg::insertRec(
			BrlyQConMapLeg* rec
		) {
};

ubigint TblBrlyQConMapLeg::insertNewRec(
			BrlyQConMapLeg** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mbgnRefBrlyMLocation
			, const ubigint mendRefBrlyMLocation
			, const double mdeltaphi
			, const double dx
			, const double dy
			, const double x0
			, const double y0
		) {
	ubigint retval = 0;
	BrlyQConMapLeg* _rec = NULL;

	_rec = new BrlyQConMapLeg(0, qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, stubMref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, mdeltaphi, dx, dy, x0, y0);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConMapLeg::appendNewRecToRst(
			ListBrlyQConMapLeg& rst
			, BrlyQConMapLeg** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double VisOrgLegphi0
			, const double VisOrgLegphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mbgnRefBrlyMLocation
			, const ubigint mendRefBrlyMLocation
			, const double mdeltaphi
			, const double dx
			, const double dy
			, const double x0
			, const double y0
		) {
	ubigint retval = 0;
	BrlyQConMapLeg* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, stubMref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, mdeltaphi, dx, dy, x0, y0);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConMapLeg::insertRst(
			ListBrlyQConMapLeg& rst
		) {
};

void TblBrlyQConMapLeg::updateRec(
			BrlyQConMapLeg* rec
		) {
};

void TblBrlyQConMapLeg::updateRst(
			ListBrlyQConMapLeg& rst
		) {
};

void TblBrlyQConMapLeg::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConMapLeg::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQConMapLeg** rec
		) {
	return false;
};

ubigint TblBrlyQConMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapLeg& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQConMapLeg
 ******************************************************************************/

MyTblBrlyQConMapLeg::MyTblBrlyQConMapLeg() : TblBrlyQConMapLeg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConMapLeg::~MyTblBrlyQConMapLeg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConMapLeg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConMapLeg (qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, mdeltaphi, dx, dy, x0, y0) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConMapLeg SET qwr = ?, jref = ?, jnum = ?, ref = ?, VisOrgLegphi0 = ?, VisOrgLegphi1 = ?, mref = ?, mbgnRefBrlyMLocation = ?, mendRefBrlyMLocation = ?, mdeltaphi = ?, dx = ?, dy = ?, x0 = ?, y0 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConMapLeg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConMapLeg WHERE jref = ?", false);
};

bool MyTblBrlyQConMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapLeg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConMapLeg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapLeg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConMapLeg();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->VisOrgLegphi0 = atof((char*) dbrow[5]); else _rec->VisOrgLegphi0 = 0.0;
		if (dbrow[6]) _rec->VisOrgLegphi1 = atof((char*) dbrow[6]); else _rec->VisOrgLegphi1 = 0.0;
		if (dbrow[7]) _rec->mref = atoll((char*) dbrow[7]); else _rec->mref = 0;
		if (dbrow[8]) _rec->mbgnRefBrlyMLocation = atoll((char*) dbrow[8]); else _rec->mbgnRefBrlyMLocation = 0;
		if (dbrow[9]) _rec->mendRefBrlyMLocation = atoll((char*) dbrow[9]); else _rec->mendRefBrlyMLocation = 0;
		if (dbrow[10]) _rec->mdeltaphi = atof((char*) dbrow[10]); else _rec->mdeltaphi = 0.0;
		if (dbrow[11]) _rec->dx = atof((char*) dbrow[11]); else _rec->dx = 0.0;
		if (dbrow[12]) _rec->dy = atof((char*) dbrow[12]); else _rec->dy = 0.0;
		if (dbrow[13]) _rec->x0 = atof((char*) dbrow[13]); else _rec->x0 = 0.0;
		if (dbrow[14]) _rec->y0 = atof((char*) dbrow[14]); else _rec->y0 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQConMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapLeg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConMapLeg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapLeg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConMapLeg();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->VisOrgLegphi0 = atof((char*) dbrow[5]); else rec->VisOrgLegphi0 = 0.0;
			if (dbrow[6]) rec->VisOrgLegphi1 = atof((char*) dbrow[6]); else rec->VisOrgLegphi1 = 0.0;
			if (dbrow[7]) rec->mref = atoll((char*) dbrow[7]); else rec->mref = 0;
			if (dbrow[8]) rec->mbgnRefBrlyMLocation = atoll((char*) dbrow[8]); else rec->mbgnRefBrlyMLocation = 0;
			if (dbrow[9]) rec->mendRefBrlyMLocation = atoll((char*) dbrow[9]); else rec->mendRefBrlyMLocation = 0;
			if (dbrow[10]) rec->mdeltaphi = atof((char*) dbrow[10]); else rec->mdeltaphi = 0.0;
			if (dbrow[11]) rec->dx = atof((char*) dbrow[11]); else rec->dx = 0.0;
			if (dbrow[12]) rec->dy = atof((char*) dbrow[12]); else rec->dy = 0.0;
			if (dbrow[13]) rec->x0 = atof((char*) dbrow[13]); else rec->x0 = 0.0;
			if (dbrow[14]) rec->y0 = atof((char*) dbrow[14]); else rec->y0 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQConMapLeg::insertRec(
			BrlyQConMapLeg* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->VisOrgLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->VisOrgLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->mbgnRefBrlyMLocation,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->mendRefBrlyMLocation,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->mdeltaphi,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->dx,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->dy,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->x0,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->y0,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapLeg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapLeg / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQConMapLeg::insertRst(
			ListBrlyQConMapLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConMapLeg::updateRec(
			BrlyQConMapLeg* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->VisOrgLegphi0,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->VisOrgLegphi1,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->mbgnRefBrlyMLocation,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->mendRefBrlyMLocation,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->mdeltaphi,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->dx,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->dy,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->x0,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->y0,&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->qref,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapLeg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapLeg / stmtUpdateRec)\n");
};

void MyTblBrlyQConMapLeg::updateRst(
			ListBrlyQConMapLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConMapLeg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapLeg / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapLeg / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQConMapLeg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapLeg / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapLeg / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQConMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQConMapLeg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQConMapLeg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapLeg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConMapLeg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQConMapLeg
 ******************************************************************************/

PgTblBrlyQConMapLeg::PgTblBrlyQConMapLeg() : TblBrlyQConMapLeg(), PgTable() {
};

PgTblBrlyQConMapLeg::~PgTblBrlyQConMapLeg() {
};

void PgTblBrlyQConMapLeg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQConMapLeg_insertRec", "INSERT INTO TblBrlyQConMapLeg (qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, mdeltaphi, dx, dy, x0, y0) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14) RETURNING qref", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapLeg_updateRec", "UPDATE TblBrlyQConMapLeg SET qwr = $1, jref = $2, jnum = $3, ref = $4, VisOrgLegphi0 = $5, VisOrgLegphi1 = $6, mref = $7, mbgnRefBrlyMLocation = $8, mendRefBrlyMLocation = $9, mdeltaphi = $10, dx = $11, dy = $12, x0 = $13, y0 = $14 WHERE qref = $15", 15, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapLeg_removeRecByQref", "DELETE FROM TblBrlyQConMapLeg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapLeg_removeRstByJref", "DELETE FROM TblBrlyQConMapLeg WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQConMapLeg_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, mdeltaphi, dx, dy, x0, y0 FROM TblBrlyQConMapLeg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapLeg_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, mdeltaphi, dx, dy, x0, y0 FROM TblBrlyQConMapLeg WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQConMapLeg::loadRec(
			PGresult* res
			, BrlyQConMapLeg** rec
		) {
	char* ptr;

	BrlyQConMapLeg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConMapLeg();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "visorglegphi0"),
			PQfnumber(res, "visorglegphi1"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mbgnrefbrlymlocation"),
			PQfnumber(res, "mendrefbrlymlocation"),
			PQfnumber(res, "mdeltaphi"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->VisOrgLegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->VisOrgLegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->mbgnRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->mendRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->mdeltaphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->dx = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->dy = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->x0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->y0 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQConMapLeg::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConMapLeg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConMapLeg* rec;

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
			PQfnumber(res, "visorglegphi0"),
			PQfnumber(res, "visorglegphi1"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mbgnrefbrlymlocation"),
			PQfnumber(res, "mendrefbrlymlocation"),
			PQfnumber(res, "mdeltaphi"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0")
		};

		while (numread < numrow) {
			rec = new BrlyQConMapLeg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->VisOrgLegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->VisOrgLegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->mbgnRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->mendRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->mdeltaphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->dx = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->dy = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->x0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->y0 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQConMapLeg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConMapLeg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLeg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapLeg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConMapLeg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLeg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapLeg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapLeg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQConMapLeg::insertRec(
			BrlyQConMapLeg* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	string _VisOrgLegphi0 = to_string(rec->VisOrgLegphi0);
	string _VisOrgLegphi1 = to_string(rec->VisOrgLegphi1);
	ubigint _mref = htonl64(rec->mref);
	ubigint _mbgnRefBrlyMLocation = htonl64(rec->mbgnRefBrlyMLocation);
	ubigint _mendRefBrlyMLocation = htonl64(rec->mendRefBrlyMLocation);
	string _mdeltaphi = to_string(rec->mdeltaphi);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		_VisOrgLegphi0.c_str(),
		_VisOrgLegphi1.c_str(),
		(char*) &_mref,
		(char*) &_mbgnRefBrlyMLocation,
		(char*) &_mendRefBrlyMLocation,
		_mdeltaphi.c_str(),
		_dx.c_str(),
		_dy.c_str(),
		_x0.c_str(),
		_y0.c_str()
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQConMapLeg_insertRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLeg_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQConMapLeg::insertRst(
			ListBrlyQConMapLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConMapLeg::updateRec(
			BrlyQConMapLeg* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	string _VisOrgLegphi0 = to_string(rec->VisOrgLegphi0);
	string _VisOrgLegphi1 = to_string(rec->VisOrgLegphi1);
	ubigint _mref = htonl64(rec->mref);
	ubigint _mbgnRefBrlyMLocation = htonl64(rec->mbgnRefBrlyMLocation);
	ubigint _mendRefBrlyMLocation = htonl64(rec->mendRefBrlyMLocation);
	string _mdeltaphi = to_string(rec->mdeltaphi);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		_VisOrgLegphi0.c_str(),
		_VisOrgLegphi1.c_str(),
		(char*) &_mref,
		(char*) &_mbgnRefBrlyMLocation,
		(char*) &_mendRefBrlyMLocation,
		_mdeltaphi.c_str(),
		_dx.c_str(),
		_dy.c_str(),
		_x0.c_str(),
		_y0.c_str(),
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
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMapLeg_updateRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLeg_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQConMapLeg::updateRst(
			ListBrlyQConMapLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConMapLeg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapLeg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLeg_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQConMapLeg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapLeg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLeg_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQConMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQConMapLeg** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQConMapLeg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapLeg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConMapLeg_loadRstByJref", 1, vals, l, f, append, rst);
};

