/**
  * \file BrlyQLegMapLeg.cpp
  * Dbs and XML wrapper for table TblBrlyQLegMapLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLegMapLeg.h"

/******************************************************************************
 class BrlyQLegMapLeg
 ******************************************************************************/

BrlyQLegMapLeg::BrlyQLegMapLeg(
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
	this->dx = dx;
	this->dy = dy;
	this->x0 = x0;
	this->y0 = y0;
};

void BrlyQLegMapLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLegMapLeg";

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
 class ListBrlyQLegMapLeg
 ******************************************************************************/

ListBrlyQLegMapLeg::ListBrlyQLegMapLeg() {
};

ListBrlyQLegMapLeg::ListBrlyQLegMapLeg(
			const ListBrlyQLegMapLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegMapLeg(*(src.nodes[i]));
};

ListBrlyQLegMapLeg::~ListBrlyQLegMapLeg() {
	clear();
};

void ListBrlyQLegMapLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLegMapLeg::size() const {
	return(nodes.size());
};

void ListBrlyQLegMapLeg::append(
			BrlyQLegMapLeg* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLegMapLeg& ListBrlyQLegMapLeg::operator=(
			const ListBrlyQLegMapLeg& src
		) {
	BrlyQLegMapLeg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLegMapLeg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLegMapLeg::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLegMapLeg";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLegMapLeg
 ******************************************************************************/

TblBrlyQLegMapLeg::TblBrlyQLegMapLeg() {
};

TblBrlyQLegMapLeg::~TblBrlyQLegMapLeg() {
};

bool TblBrlyQLegMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMapLeg** rec
		) {
	return false;
};

ubigint TblBrlyQLegMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMapLeg& rst
		) {
	return 0;
};

void TblBrlyQLegMapLeg::insertRec(
			BrlyQLegMapLeg* rec
		) {
};

ubigint TblBrlyQLegMapLeg::insertNewRec(
			BrlyQLegMapLeg** rec
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
			, const double dx
			, const double dy
			, const double x0
			, const double y0
		) {
	ubigint retval = 0;
	BrlyQLegMapLeg* _rec = NULL;

	_rec = new BrlyQLegMapLeg(0, qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, stubMref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLegMapLeg::appendNewRecToRst(
			ListBrlyQLegMapLeg& rst
			, BrlyQLegMapLeg** rec
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
			, const double dx
			, const double dy
			, const double x0
			, const double y0
		) {
	ubigint retval = 0;
	BrlyQLegMapLeg* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, stubMref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLegMapLeg::insertRst(
			ListBrlyQLegMapLeg& rst
		) {
};

void TblBrlyQLegMapLeg::updateRec(
			BrlyQLegMapLeg* rec
		) {
};

void TblBrlyQLegMapLeg::updateRst(
			ListBrlyQLegMapLeg& rst
		) {
};

void TblBrlyQLegMapLeg::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLegMapLeg::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLegMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQLegMapLeg** rec
		) {
	return false;
};

ubigint TblBrlyQLegMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMapLeg& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLegMapLeg
 ******************************************************************************/

MyTblBrlyQLegMapLeg::MyTblBrlyQLegMapLeg() : TblBrlyQLegMapLeg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLegMapLeg::~MyTblBrlyQLegMapLeg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLegMapLeg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLegMapLeg (qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLegMapLeg SET qwr = ?, jref = ?, jnum = ?, ref = ?, VisOrgLegphi0 = ?, VisOrgLegphi1 = ?, mref = ?, mbgnRefBrlyMLocation = ?, mendRefBrlyMLocation = ?, dx = ?, dy = ?, x0 = ?, y0 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLegMapLeg WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLegMapLeg WHERE jref = ?", false);
};

bool MyTblBrlyQLegMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMapLeg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLegMapLeg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLegMapLeg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLegMapLeg();

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
		if (dbrow[10]) _rec->dx = atof((char*) dbrow[10]); else _rec->dx = 0.0;
		if (dbrow[11]) _rec->dy = atof((char*) dbrow[11]); else _rec->dy = 0.0;
		if (dbrow[12]) _rec->x0 = atof((char*) dbrow[12]); else _rec->x0 = 0.0;
		if (dbrow[13]) _rec->y0 = atof((char*) dbrow[13]); else _rec->y0 = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLegMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMapLeg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLegMapLeg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLegMapLeg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLegMapLeg();

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
			if (dbrow[10]) rec->dx = atof((char*) dbrow[10]); else rec->dx = 0.0;
			if (dbrow[11]) rec->dy = atof((char*) dbrow[11]); else rec->dy = 0.0;
			if (dbrow[12]) rec->x0 = atof((char*) dbrow[12]); else rec->x0 = 0.0;
			if (dbrow[13]) rec->y0 = atof((char*) dbrow[13]); else rec->y0 = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQLegMapLeg::insertRec(
			BrlyQLegMapLeg* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

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
		bindDouble(&rec->dx,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->dy,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->x0,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->y0,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegMapLeg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegMapLeg / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLegMapLeg::insertRst(
			ListBrlyQLegMapLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLegMapLeg::updateRec(
			BrlyQLegMapLeg* rec
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
		bindDouble(&rec->dx,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->dy,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->x0,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->y0,&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegMapLeg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegMapLeg / stmtUpdateRec)\n");
};

void MyTblBrlyQLegMapLeg::updateRst(
			ListBrlyQLegMapLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLegMapLeg::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegMapLeg / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegMapLeg / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLegMapLeg::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegMapLeg / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegMapLeg / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLegMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQLegMapLeg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLegMapLeg WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLegMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMapLeg& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLegMapLeg WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLegMapLeg
 ******************************************************************************/

PgTblBrlyQLegMapLeg::PgTblBrlyQLegMapLeg() : TblBrlyQLegMapLeg(), PgTable() {
};

PgTblBrlyQLegMapLeg::~PgTblBrlyQLegMapLeg() {
};

void PgTblBrlyQLegMapLeg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLegMapLeg_insertRec", "INSERT INTO TblBrlyQLegMapLeg (qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegMapLeg_updateRec", "UPDATE TblBrlyQLegMapLeg SET qwr = $1, jref = $2, jnum = $3, ref = $4, VisOrgLegphi0 = $5, VisOrgLegphi1 = $6, mref = $7, mbgnRefBrlyMLocation = $8, mendRefBrlyMLocation = $9, dx = $10, dy = $11, x0 = $12, y0 = $13 WHERE qref = $14", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegMapLeg_removeRecByQref", "DELETE FROM TblBrlyQLegMapLeg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegMapLeg_removeRstByJref", "DELETE FROM TblBrlyQLegMapLeg WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLegMapLeg_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0 FROM TblBrlyQLegMapLeg WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegMapLeg_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, VisOrgLegphi0, VisOrgLegphi1, mref, mbgnRefBrlyMLocation, mendRefBrlyMLocation, dx, dy, x0, y0 FROM TblBrlyQLegMapLeg WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLegMapLeg::loadRec(
			PGresult* res
			, BrlyQLegMapLeg** rec
		) {
	char* ptr;

	BrlyQLegMapLeg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLegMapLeg();

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
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->dx = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->dy = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->x0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->y0 = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLegMapLeg::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLegMapLeg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLegMapLeg* rec;

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
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0")
		};

		while (numread < numrow) {
			rec = new BrlyQLegMapLeg();

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
			ptr = PQgetvalue(res, numread, fnum[10]); rec->dx = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->dy = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->x0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->y0 = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLegMapLeg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLegMapLeg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLeg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegMapLeg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLegMapLeg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLeg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLegMapLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegMapLeg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegMapLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegMapLeg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLegMapLeg::insertRec(
			BrlyQLegMapLeg* rec
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
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLegMapLeg_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLeg_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLegMapLeg::insertRst(
			ListBrlyQLegMapLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLegMapLeg::updateRec(
			BrlyQLegMapLeg* rec
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
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLegMapLeg_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLeg_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLegMapLeg::updateRst(
			ListBrlyQLegMapLeg& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLegMapLeg::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegMapLeg_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLeg_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLegMapLeg::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegMapLeg_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegMapLeg_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLegMapLeg::loadRecByQref(
			ubigint qref
			, BrlyQLegMapLeg** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLegMapLeg_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLegMapLeg::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegMapLeg& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLegMapLeg_loadRstByJref", 1, vals, l, f, append, rst);
};

