/**
  * \file BrlyQConMapLocation.cpp
  * Dbs and XML wrapper for table TblBrlyQConMapLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQConMapLocation.h"

/******************************************************************************
 class BrlyQConMapLocation
 ******************************************************************************/

BrlyQConMapLocation::BrlyQConMapLocation(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double legphi
			, const double legtheta
			, const ubigint mref
			, const string stubMref
			, const ubigint mrefBrlyMEquipment
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
	this->mrefBrlyMEquipment = mrefBrlyMEquipment;
	this->x = x;
	this->y = y;
};

void BrlyQConMapLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConMapLocation";

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
 class ListBrlyQConMapLocation
 ******************************************************************************/

ListBrlyQConMapLocation::ListBrlyQConMapLocation() {
};

ListBrlyQConMapLocation::ListBrlyQConMapLocation(
			const ListBrlyQConMapLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapLocation(*(src.nodes[i]));
};

ListBrlyQConMapLocation::~ListBrlyQConMapLocation() {
	clear();
};

void ListBrlyQConMapLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConMapLocation::size() const {
	return(nodes.size());
};

void ListBrlyQConMapLocation::append(
			BrlyQConMapLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConMapLocation& ListBrlyQConMapLocation::operator=(
			const ListBrlyQConMapLocation& src
		) {
	BrlyQConMapLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQConMapLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConMapLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConMapLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConMapLocation
 ******************************************************************************/

TblBrlyQConMapLocation::TblBrlyQConMapLocation() {
};

TblBrlyQConMapLocation::~TblBrlyQConMapLocation() {
};

bool TblBrlyQConMapLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapLocation** rec
		) {
	return false;
};

ubigint TblBrlyQConMapLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapLocation& rst
		) {
	return 0;
};

void TblBrlyQConMapLocation::insertRec(
			BrlyQConMapLocation* rec
		) {
};

ubigint TblBrlyQConMapLocation::insertNewRec(
			BrlyQConMapLocation** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double legphi
			, const double legtheta
			, const ubigint mref
			, const string stubMref
			, const ubigint mrefBrlyMEquipment
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	BrlyQConMapLocation* _rec = NULL;

	_rec = new BrlyQConMapLocation(0, qwr, jref, jnum, ref, legphi, legtheta, mref, stubMref, mrefBrlyMEquipment, x, y);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConMapLocation::appendNewRecToRst(
			ListBrlyQConMapLocation& rst
			, BrlyQConMapLocation** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const double legphi
			, const double legtheta
			, const ubigint mref
			, const string stubMref
			, const ubigint mrefBrlyMEquipment
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	BrlyQConMapLocation* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, legphi, legtheta, mref, stubMref, mrefBrlyMEquipment, x, y);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConMapLocation::insertRst(
			ListBrlyQConMapLocation& rst
		) {
};

void TblBrlyQConMapLocation::updateRec(
			BrlyQConMapLocation* rec
		) {
};

void TblBrlyQConMapLocation::updateRst(
			ListBrlyQConMapLocation& rst
		) {
};

void TblBrlyQConMapLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConMapLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConMapLocation::loadRecByQref(
			ubigint qref
			, BrlyQConMapLocation** rec
		) {
	return false;
};

ubigint TblBrlyQConMapLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapLocation& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQConMapLocation
 ******************************************************************************/

MyTblBrlyQConMapLocation::MyTblBrlyQConMapLocation() : TblBrlyQConMapLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConMapLocation::~MyTblBrlyQConMapLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConMapLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConMapLocation (qwr, jref, jnum, ref, legphi, legtheta, mref, mrefBrlyMEquipment, x, y) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConMapLocation SET qwr = ?, jref = ?, jnum = ?, ref = ?, legphi = ?, legtheta = ?, mref = ?, mrefBrlyMEquipment = ?, x = ?, y = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConMapLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConMapLocation WHERE jref = ?", false);
};

bool MyTblBrlyQConMapLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConMapLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConMapLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->legphi = atof((char*) dbrow[5]); else _rec->legphi = 0.0;
		if (dbrow[6]) _rec->legtheta = atof((char*) dbrow[6]); else _rec->legtheta = 0.0;
		if (dbrow[7]) _rec->mref = atoll((char*) dbrow[7]); else _rec->mref = 0;
		if (dbrow[8]) _rec->mrefBrlyMEquipment = atoll((char*) dbrow[8]); else _rec->mrefBrlyMEquipment = 0;
		if (dbrow[9]) _rec->x = atof((char*) dbrow[9]); else _rec->x = 0.0;
		if (dbrow[10]) _rec->y = atof((char*) dbrow[10]); else _rec->y = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQConMapLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConMapLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConMapLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->legphi = atof((char*) dbrow[5]); else rec->legphi = 0.0;
			if (dbrow[6]) rec->legtheta = atof((char*) dbrow[6]); else rec->legtheta = 0.0;
			if (dbrow[7]) rec->mref = atoll((char*) dbrow[7]); else rec->mref = 0;
			if (dbrow[8]) rec->mrefBrlyMEquipment = atoll((char*) dbrow[8]); else rec->mrefBrlyMEquipment = 0;
			if (dbrow[9]) rec->x = atof((char*) dbrow[9]); else rec->x = 0.0;
			if (dbrow[10]) rec->y = atof((char*) dbrow[10]); else rec->y = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQConMapLocation::insertRec(
			BrlyQConMapLocation* rec
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
		bindUbigint(&rec->mrefBrlyMEquipment,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->x,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->y,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapLocation / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQConMapLocation::insertRst(
			ListBrlyQConMapLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConMapLocation::updateRec(
			BrlyQConMapLocation* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->legphi,&(l[4]),&(n[4]),&(e[4])),
		bindDouble(&rec->legtheta,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->mref,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->mrefBrlyMEquipment,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->x,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->y,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapLocation / stmtUpdateRec)\n");
};

void MyTblBrlyQConMapLocation::updateRst(
			ListBrlyQConMapLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConMapLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapLocation / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapLocation / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQConMapLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapLocation / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapLocation / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQConMapLocation::loadRecByQref(
			ubigint qref
			, BrlyQConMapLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQConMapLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConMapLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConMapLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQConMapLocation
 ******************************************************************************/

PgTblBrlyQConMapLocation::PgTblBrlyQConMapLocation() : TblBrlyQConMapLocation(), PgTable() {
};

PgTblBrlyQConMapLocation::~PgTblBrlyQConMapLocation() {
};

void PgTblBrlyQConMapLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQConMapLocation_insertRec", "INSERT INTO TblBrlyQConMapLocation (qwr, jref, jnum, ref, legphi, legtheta, mref, mrefBrlyMEquipment, x, y) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapLocation_updateRec", "UPDATE TblBrlyQConMapLocation SET qwr = $1, jref = $2, jnum = $3, ref = $4, legphi = $5, legtheta = $6, mref = $7, mrefBrlyMEquipment = $8, x = $9, y = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapLocation_removeRecByQref", "DELETE FROM TblBrlyQConMapLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapLocation_removeRstByJref", "DELETE FROM TblBrlyQConMapLocation WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQConMapLocation_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, legphi, legtheta, mref, mrefBrlyMEquipment, x, y FROM TblBrlyQConMapLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapLocation_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, legphi, legtheta, mref, mrefBrlyMEquipment, x, y FROM TblBrlyQConMapLocation WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQConMapLocation::loadRec(
			PGresult* res
			, BrlyQConMapLocation** rec
		) {
	char* ptr;

	BrlyQConMapLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConMapLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "legphi"),
			PQfnumber(res, "legtheta"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "mrefbrlymequipment"),
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
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->mrefBrlyMEquipment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->x = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->y = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQConMapLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConMapLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConMapLocation* rec;

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
			PQfnumber(res, "mrefbrlymequipment"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		while (numread < numrow) {
			rec = new BrlyQConMapLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->legphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->legtheta = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->mrefBrlyMEquipment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->x = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->y = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQConMapLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConMapLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConMapLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConMapLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQConMapLocation::insertRec(
			BrlyQConMapLocation* rec
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
	ubigint _mrefBrlyMEquipment = htonl64(rec->mrefBrlyMEquipment);
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
		(char*) &_mrefBrlyMEquipment,
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
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQConMapLocation_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQConMapLocation::insertRst(
			ListBrlyQConMapLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConMapLocation::updateRec(
			BrlyQConMapLocation* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	string _legphi = to_string(rec->legphi);
	string _legtheta = to_string(rec->legtheta);
	ubigint _mref = htonl64(rec->mref);
	ubigint _mrefBrlyMEquipment = htonl64(rec->mrefBrlyMEquipment);
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
		(char*) &_mrefBrlyMEquipment,
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
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMapLocation_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQConMapLocation::updateRst(
			ListBrlyQConMapLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConMapLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLocation_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQConMapLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapLocation_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQConMapLocation::loadRecByQref(
			ubigint qref
			, BrlyQConMapLocation** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQConMapLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConMapLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConMapLocation_loadRstByJref", 1, vals, l, f, append, rst);
};

