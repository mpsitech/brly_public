/**
  * \file BrlyQConMapFlight.cpp
  * Dbs and XML wrapper for table TblBrlyQConMapFlight (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQConMapFlight.h"

/******************************************************************************
 class BrlyQConMapFlight
 ******************************************************************************/

BrlyQConMapFlight::BrlyQConMapFlight(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mrefBrlyMEquipment
			, const ubigint mrefBrlyMLeg
			, const uint mstart
			, const uint mstop
			, const double x0
			, const double y0
			, const int t0
			, const double dx
			, const double dy
			, const int dt
		) {
	this->qref = qref;
	this->qwr = qwr;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1Start = x1Start;
	this->x1Stop = x1Stop;
	this->x2Legphi0 = x2Legphi0;
	this->x2Legphi1 = x2Legphi1;
	this->mref = mref;
	this->stubMref = stubMref;
	this->mrefBrlyMEquipment = mrefBrlyMEquipment;
	this->mrefBrlyMLeg = mrefBrlyMLeg;
	this->mstart = mstart;
	this->mstop = mstop;
	this->x0 = x0;
	this->y0 = y0;
	this->t0 = t0;
	this->dx = dx;
	this->dy = dy;
	this->dt = dt;
};

void BrlyQConMapFlight::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConMapFlight";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeDouble(wr, "x0", x0);
		writeDouble(wr, "y0", y0);
		writeInt(wr, "t0", t0);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
		writeInt(wr, "dt", dt);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeDouble(wr, "x0", x0);
		writeDouble(wr, "y0", y0);
		writeInt(wr, "t0", t0);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
		writeInt(wr, "dt", dt);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQConMapFlight
 ******************************************************************************/

ListBrlyQConMapFlight::ListBrlyQConMapFlight() {
};

ListBrlyQConMapFlight::ListBrlyQConMapFlight(
			const ListBrlyQConMapFlight& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapFlight(*(src.nodes[i]));
};

ListBrlyQConMapFlight::~ListBrlyQConMapFlight() {
	clear();
};

void ListBrlyQConMapFlight::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConMapFlight::size() const {
	return(nodes.size());
};

void ListBrlyQConMapFlight::append(
			BrlyQConMapFlight* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConMapFlight& ListBrlyQConMapFlight::operator=(
			const ListBrlyQConMapFlight& src
		) {
	BrlyQConMapFlight* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQConMapFlight(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConMapFlight::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConMapFlight";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConMapFlight
 ******************************************************************************/

TblBrlyQConMapFlight::TblBrlyQConMapFlight() {
};

TblBrlyQConMapFlight::~TblBrlyQConMapFlight() {
};

bool TblBrlyQConMapFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapFlight** rec
		) {
	return false;
};

ubigint TblBrlyQConMapFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapFlight& rst
		) {
	return 0;
};

void TblBrlyQConMapFlight::insertRec(
			BrlyQConMapFlight* rec
		) {
};

ubigint TblBrlyQConMapFlight::insertNewRec(
			BrlyQConMapFlight** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mrefBrlyMEquipment
			, const ubigint mrefBrlyMLeg
			, const uint mstart
			, const uint mstop
			, const double x0
			, const double y0
			, const int t0
			, const double dx
			, const double dy
			, const int dt
		) {
	ubigint retval = 0;
	BrlyQConMapFlight* _rec = NULL;

	_rec = new BrlyQConMapFlight(0, qwr, jref, jnum, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, mref, stubMref, mrefBrlyMEquipment, mrefBrlyMLeg, mstart, mstop, x0, y0, t0, dx, dy, dt);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConMapFlight::appendNewRecToRst(
			ListBrlyQConMapFlight& rst
			, BrlyQConMapFlight** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const double x2Legphi0
			, const double x2Legphi1
			, const ubigint mref
			, const string stubMref
			, const ubigint mrefBrlyMEquipment
			, const ubigint mrefBrlyMLeg
			, const uint mstart
			, const uint mstop
			, const double x0
			, const double y0
			, const int t0
			, const double dx
			, const double dy
			, const int dt
		) {
	ubigint retval = 0;
	BrlyQConMapFlight* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, mref, stubMref, mrefBrlyMEquipment, mrefBrlyMLeg, mstart, mstop, x0, y0, t0, dx, dy, dt);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConMapFlight::insertRst(
			ListBrlyQConMapFlight& rst
		) {
};

void TblBrlyQConMapFlight::updateRec(
			BrlyQConMapFlight* rec
		) {
};

void TblBrlyQConMapFlight::updateRst(
			ListBrlyQConMapFlight& rst
		) {
};

void TblBrlyQConMapFlight::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConMapFlight::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConMapFlight::loadRecByQref(
			ubigint qref
			, BrlyQConMapFlight** rec
		) {
	return false;
};

ubigint TblBrlyQConMapFlight::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapFlight& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQConMapFlight
 ******************************************************************************/

MyTblBrlyQConMapFlight::MyTblBrlyQConMapFlight() : TblBrlyQConMapFlight(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConMapFlight::~MyTblBrlyQConMapFlight() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConMapFlight::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConMapFlight (qwr, jref, jnum, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, mref, mrefBrlyMEquipment, mrefBrlyMLeg, mstart, mstop, x0, y0, t0, dx, dy, dt) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConMapFlight SET qwr = ?, jref = ?, jnum = ?, ref = ?, x1Start = ?, x1Stop = ?, x2Legphi0 = ?, x2Legphi1 = ?, mref = ?, mrefBrlyMEquipment = ?, mrefBrlyMLeg = ?, mstart = ?, mstop = ?, x0 = ?, y0 = ?, t0 = ?, dx = ?, dy = ?, dt = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConMapFlight WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConMapFlight WHERE jref = ?", false);
};

bool MyTblBrlyQConMapFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapFlight** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConMapFlight* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapFlight / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConMapFlight();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1Start = atol((char*) dbrow[5]); else _rec->x1Start = 0;
		if (dbrow[6]) _rec->x1Stop = atol((char*) dbrow[6]); else _rec->x1Stop = 0;
		if (dbrow[7]) _rec->x2Legphi0 = atof((char*) dbrow[7]); else _rec->x2Legphi0 = 0.0;
		if (dbrow[8]) _rec->x2Legphi1 = atof((char*) dbrow[8]); else _rec->x2Legphi1 = 0.0;
		if (dbrow[9]) _rec->mref = atoll((char*) dbrow[9]); else _rec->mref = 0;
		if (dbrow[10]) _rec->mrefBrlyMEquipment = atoll((char*) dbrow[10]); else _rec->mrefBrlyMEquipment = 0;
		if (dbrow[11]) _rec->mrefBrlyMLeg = atoll((char*) dbrow[11]); else _rec->mrefBrlyMLeg = 0;
		if (dbrow[12]) _rec->mstart = atol((char*) dbrow[12]); else _rec->mstart = 0;
		if (dbrow[13]) _rec->mstop = atol((char*) dbrow[13]); else _rec->mstop = 0;
		if (dbrow[14]) _rec->x0 = atof((char*) dbrow[14]); else _rec->x0 = 0.0;
		if (dbrow[15]) _rec->y0 = atof((char*) dbrow[15]); else _rec->y0 = 0.0;
		if (dbrow[16]) _rec->t0 = atol((char*) dbrow[16]); else _rec->t0 = 0;
		if (dbrow[17]) _rec->dx = atof((char*) dbrow[17]); else _rec->dx = 0.0;
		if (dbrow[18]) _rec->dy = atof((char*) dbrow[18]); else _rec->dy = 0.0;
		if (dbrow[19]) _rec->dt = atol((char*) dbrow[19]); else _rec->dt = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQConMapFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapFlight& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConMapFlight* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapFlight / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConMapFlight();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1Start = atol((char*) dbrow[5]); else rec->x1Start = 0;
			if (dbrow[6]) rec->x1Stop = atol((char*) dbrow[6]); else rec->x1Stop = 0;
			if (dbrow[7]) rec->x2Legphi0 = atof((char*) dbrow[7]); else rec->x2Legphi0 = 0.0;
			if (dbrow[8]) rec->x2Legphi1 = atof((char*) dbrow[8]); else rec->x2Legphi1 = 0.0;
			if (dbrow[9]) rec->mref = atoll((char*) dbrow[9]); else rec->mref = 0;
			if (dbrow[10]) rec->mrefBrlyMEquipment = atoll((char*) dbrow[10]); else rec->mrefBrlyMEquipment = 0;
			if (dbrow[11]) rec->mrefBrlyMLeg = atoll((char*) dbrow[11]); else rec->mrefBrlyMLeg = 0;
			if (dbrow[12]) rec->mstart = atol((char*) dbrow[12]); else rec->mstart = 0;
			if (dbrow[13]) rec->mstop = atol((char*) dbrow[13]); else rec->mstop = 0;
			if (dbrow[14]) rec->x0 = atof((char*) dbrow[14]); else rec->x0 = 0.0;
			if (dbrow[15]) rec->y0 = atof((char*) dbrow[15]); else rec->y0 = 0.0;
			if (dbrow[16]) rec->t0 = atol((char*) dbrow[16]); else rec->t0 = 0;
			if (dbrow[17]) rec->dx = atof((char*) dbrow[17]); else rec->dx = 0.0;
			if (dbrow[18]) rec->dy = atof((char*) dbrow[18]); else rec->dy = 0.0;
			if (dbrow[19]) rec->dt = atol((char*) dbrow[19]); else rec->dt = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQConMapFlight::insertRec(
			BrlyQConMapFlight* rec
		) {
	unsigned long l[19]; my_bool n[19]; my_bool e[19];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x2Legphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x2Legphi1,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->mref,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->mrefBrlyMEquipment,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->mrefBrlyMLeg,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->mstart,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->mstop,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->x0,&(l[13]),&(n[13]),&(e[13])),
		bindDouble(&rec->y0,&(l[14]),&(n[14]),&(e[14])),
		bindInt(&rec->t0,&(l[15]),&(n[15]),&(e[15])),
		bindDouble(&rec->dx,&(l[16]),&(n[16]),&(e[16])),
		bindDouble(&rec->dy,&(l[17]),&(n[17]),&(e[17])),
		bindInt(&rec->dt,&(l[18]),&(n[18]),&(e[18]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapFlight / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapFlight / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQConMapFlight::insertRst(
			ListBrlyQConMapFlight& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConMapFlight::updateRec(
			BrlyQConMapFlight* rec
		) {
	unsigned long l[20]; my_bool n[20]; my_bool e[20];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x2Legphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x2Legphi1,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->mref,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->mrefBrlyMEquipment,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->mrefBrlyMLeg,&(l[10]),&(n[10]),&(e[10])),
		bindUint(&rec->mstart,&(l[11]),&(n[11]),&(e[11])),
		bindUint(&rec->mstop,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->x0,&(l[13]),&(n[13]),&(e[13])),
		bindDouble(&rec->y0,&(l[14]),&(n[14]),&(e[14])),
		bindInt(&rec->t0,&(l[15]),&(n[15]),&(e[15])),
		bindDouble(&rec->dx,&(l[16]),&(n[16]),&(e[16])),
		bindDouble(&rec->dy,&(l[17]),&(n[17]),&(e[17])),
		bindInt(&rec->dt,&(l[18]),&(n[18]),&(e[18])),
		bindUbigint(&rec->qref,&(l[19]),&(n[19]),&(e[19]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapFlight / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapFlight / stmtUpdateRec)\n");
};

void MyTblBrlyQConMapFlight::updateRst(
			ListBrlyQConMapFlight& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConMapFlight::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapFlight / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapFlight / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQConMapFlight::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapFlight / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapFlight / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQConMapFlight::loadRecByQref(
			ubigint qref
			, BrlyQConMapFlight** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQConMapFlight WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConMapFlight::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapFlight& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConMapFlight WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQConMapFlight
 ******************************************************************************/

PgTblBrlyQConMapFlight::PgTblBrlyQConMapFlight() : TblBrlyQConMapFlight(), PgTable() {
};

PgTblBrlyQConMapFlight::~PgTblBrlyQConMapFlight() {
};

void PgTblBrlyQConMapFlight::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQConMapFlight_insertRec", "INSERT INTO TblBrlyQConMapFlight (qwr, jref, jnum, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, mref, mrefBrlyMEquipment, mrefBrlyMLeg, mstart, mstop, x0, y0, t0, dx, dy, dt) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19) RETURNING qref", 19, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapFlight_updateRec", "UPDATE TblBrlyQConMapFlight SET qwr = $1, jref = $2, jnum = $3, ref = $4, x1Start = $5, x1Stop = $6, x2Legphi0 = $7, x2Legphi1 = $8, mref = $9, mrefBrlyMEquipment = $10, mrefBrlyMLeg = $11, mstart = $12, mstop = $13, x0 = $14, y0 = $15, t0 = $16, dx = $17, dy = $18, dt = $19 WHERE qref = $20", 20, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapFlight_removeRecByQref", "DELETE FROM TblBrlyQConMapFlight WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapFlight_removeRstByJref", "DELETE FROM TblBrlyQConMapFlight WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQConMapFlight_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, mref, mrefBrlyMEquipment, mrefBrlyMLeg, mstart, mstop, x0, y0, t0, dx, dy, dt FROM TblBrlyQConMapFlight WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapFlight_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1, mref, mrefBrlyMEquipment, mrefBrlyMLeg, mstart, mstop, x0, y0, t0, dx, dy, dt FROM TblBrlyQConMapFlight WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQConMapFlight::loadRec(
			PGresult* res
			, BrlyQConMapFlight** rec
		) {
	char* ptr;

	BrlyQConMapFlight* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConMapFlight();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2legphi0"),
			PQfnumber(res, "x2legphi1"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mrefbrlymequipment"),
			PQfnumber(res, "mrefbrlymleg"),
			PQfnumber(res, "mstart"),
			PQfnumber(res, "mstop"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "t0"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "dt")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x2Legphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x2Legphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->mrefBrlyMEquipment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->mrefBrlyMLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->mstart = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->mstop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->x0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->y0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->t0 = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->dx = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[18]); _rec->dy = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[19]); _rec->dt = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQConMapFlight::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConMapFlight& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConMapFlight* rec;

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
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2legphi0"),
			PQfnumber(res, "x2legphi1"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mrefbrlymequipment"),
			PQfnumber(res, "mrefbrlymleg"),
			PQfnumber(res, "mstart"),
			PQfnumber(res, "mstop"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "t0"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "dt")
		};

		while (numread < numrow) {
			rec = new BrlyQConMapFlight();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x2Legphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x2Legphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->mrefBrlyMEquipment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->mrefBrlyMLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->mstart = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->mstop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->x0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->y0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[16]); rec->t0 = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[17]); rec->dx = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[18]); rec->dy = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[19]); rec->dt = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQConMapFlight::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConMapFlight** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapFlight / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapFlight::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConMapFlight& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapFlight / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConMapFlight::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapFlight** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapFlight::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapFlight& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQConMapFlight::insertRec(
			BrlyQConMapFlight* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2Legphi0 = to_string(rec->x2Legphi0);
	string _x2Legphi1 = to_string(rec->x2Legphi1);
	ubigint _mref = htonl64(rec->mref);
	ubigint _mrefBrlyMEquipment = htonl64(rec->mrefBrlyMEquipment);
	ubigint _mrefBrlyMLeg = htonl64(rec->mrefBrlyMLeg);
	uint _mstart = htonl(rec->mstart);
	uint _mstop = htonl(rec->mstop);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	int _t0 = htonl(rec->t0);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	int _dt = htonl(rec->dt);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2Legphi0.c_str(),
		_x2Legphi1.c_str(),
		(char*) &_mref,
		(char*) &_mrefBrlyMEquipment,
		(char*) &_mrefBrlyMLeg,
		(char*) &_mstart,
		(char*) &_mstop,
		_x0.c_str(),
		_y0.c_str(),
		(char*) &_t0,
		_dx.c_str(),
		_dy.c_str(),
		(char*) &_dt
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(int),
		0,
		0,
		sizeof(int)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMapFlight_insertRec", 19, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapFlight_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQConMapFlight::insertRst(
			ListBrlyQConMapFlight& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConMapFlight::updateRec(
			BrlyQConMapFlight* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2Legphi0 = to_string(rec->x2Legphi0);
	string _x2Legphi1 = to_string(rec->x2Legphi1);
	ubigint _mref = htonl64(rec->mref);
	ubigint _mrefBrlyMEquipment = htonl64(rec->mrefBrlyMEquipment);
	ubigint _mrefBrlyMLeg = htonl64(rec->mrefBrlyMLeg);
	uint _mstart = htonl(rec->mstart);
	uint _mstop = htonl(rec->mstop);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	int _t0 = htonl(rec->t0);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	int _dt = htonl(rec->dt);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2Legphi0.c_str(),
		_x2Legphi1.c_str(),
		(char*) &_mref,
		(char*) &_mrefBrlyMEquipment,
		(char*) &_mrefBrlyMLeg,
		(char*) &_mstart,
		(char*) &_mstop,
		_x0.c_str(),
		_y0.c_str(),
		(char*) &_t0,
		_dx.c_str(),
		_dy.c_str(),
		(char*) &_dt,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		0,
		sizeof(int),
		0,
		0,
		sizeof(int),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMapFlight_updateRec", 20, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapFlight_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQConMapFlight::updateRst(
			ListBrlyQConMapFlight& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConMapFlight::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapFlight_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapFlight_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQConMapFlight::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapFlight_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapFlight_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQConMapFlight::loadRecByQref(
			ubigint qref
			, BrlyQConMapFlight** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQConMapFlight_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConMapFlight::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapFlight& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConMapFlight_loadRstByJref", 1, vals, l, f, append, rst);
};

