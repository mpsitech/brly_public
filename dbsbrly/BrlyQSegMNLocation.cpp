/**
  * \file BrlyQSegMNLocation.cpp
  * Dbs and XML wrapper for table TblBrlyQSegMNLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQSegMNLocation.h"

/******************************************************************************
 class BrlyQSegMNLocation
 ******************************************************************************/

BrlyQSegMNLocation::BrlyQSegMNLocation(
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
			, const double x2VisSegphi0
			, const double x2VisSegphi1
			, const double segphi
			, const double segtheta
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
	this->x2VisSegphi0 = x2VisSegphi0;
	this->x2VisSegphi1 = x2VisSegphi1;
	this->segphi = segphi;
	this->segtheta = segtheta;
};

void BrlyQSegMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQSegMNLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "sta", ftmX1Start);
		writeString(wr, "sto", ftmX1Stop);
		writeDouble(wr, "sp0", x2VisSegphi0);
		writeDouble(wr, "sp1", x2VisSegphi1);
		writeDouble(wr, "sph", segphi);
		writeDouble(wr, "sth", segtheta);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "ftmX1Start", ftmX1Start);
		writeString(wr, "ftmX1Stop", ftmX1Stop);
		writeDouble(wr, "x2VisSegphi0", x2VisSegphi0);
		writeDouble(wr, "x2VisSegphi1", x2VisSegphi1);
		writeDouble(wr, "segphi", segphi);
		writeDouble(wr, "segtheta", segtheta);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQSegMNLocation
 ******************************************************************************/

ListBrlyQSegMNLocation::ListBrlyQSegMNLocation() {
};

ListBrlyQSegMNLocation::ListBrlyQSegMNLocation(
			const ListBrlyQSegMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegMNLocation(*(src.nodes[i]));
};

ListBrlyQSegMNLocation::~ListBrlyQSegMNLocation() {
	clear();
};

void ListBrlyQSegMNLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQSegMNLocation::size() const {
	return(nodes.size());
};

void ListBrlyQSegMNLocation::append(
			BrlyQSegMNLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQSegMNLocation& ListBrlyQSegMNLocation::operator=(
			const ListBrlyQSegMNLocation& src
		) {
	BrlyQSegMNLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQSegMNLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQSegMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQSegMNLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQSegMNLocation
 ******************************************************************************/

TblBrlyQSegMNLocation::TblBrlyQSegMNLocation() {
};

TblBrlyQSegMNLocation::~TblBrlyQSegMNLocation() {
};

bool TblBrlyQSegMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQSegMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegMNLocation& rst
		) {
	return 0;
};

void TblBrlyQSegMNLocation::insertRec(
			BrlyQSegMNLocation* rec
		) {
};

ubigint TblBrlyQSegMNLocation::insertNewRec(
			BrlyQSegMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const double x2VisSegphi0
			, const double x2VisSegphi1
			, const double segphi
			, const double segtheta
		) {
	ubigint retval = 0;
	BrlyQSegMNLocation* _rec = NULL;

	_rec = new BrlyQSegMNLocation(0, jref, jnum, mref, stubMref, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, x2VisSegphi0, x2VisSegphi1, segphi, segtheta);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQSegMNLocation::appendNewRecToRst(
			ListBrlyQSegMNLocation& rst
			, BrlyQSegMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const double x2VisSegphi0
			, const double x2VisSegphi1
			, const double segphi
			, const double segtheta
		) {
	ubigint retval = 0;
	BrlyQSegMNLocation* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, x2VisSegphi0, x2VisSegphi1, segphi, segtheta);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQSegMNLocation::insertRst(
			ListBrlyQSegMNLocation& rst
		) {
};

void TblBrlyQSegMNLocation::updateRec(
			BrlyQSegMNLocation* rec
		) {
};

void TblBrlyQSegMNLocation::updateRst(
			ListBrlyQSegMNLocation& rst
		) {
};

void TblBrlyQSegMNLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQSegMNLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQSegMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQSegMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQSegMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegMNLocation& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQSegMNLocation
 ******************************************************************************/

MyTblBrlyQSegMNLocation::MyTblBrlyQSegMNLocation() : TblBrlyQSegMNLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQSegMNLocation::~MyTblBrlyQSegMNLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQSegMNLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQSegMNLocation (jref, jnum, mref, ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, segphi, segtheta) VALUES (?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQSegMNLocation SET jref = ?, jnum = ?, mref = ?, ref = ?, x1Start = ?, x1Stop = ?, x2VisSegphi0 = ?, x2VisSegphi1 = ?, segphi = ?, segtheta = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQSegMNLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQSegMNLocation WHERE jref = ?", false);
};

bool MyTblBrlyQSegMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegMNLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQSegMNLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQSegMNLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQSegMNLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1Start = atol((char*) dbrow[5]); else _rec->x1Start = 0;
		if (dbrow[6]) _rec->x1Stop = atol((char*) dbrow[6]); else _rec->x1Stop = 0;
		if (dbrow[7]) _rec->x2VisSegphi0 = atof((char*) dbrow[7]); else _rec->x2VisSegphi0 = 0.0;
		if (dbrow[8]) _rec->x2VisSegphi1 = atof((char*) dbrow[8]); else _rec->x2VisSegphi1 = 0.0;
		if (dbrow[9]) _rec->segphi = atof((char*) dbrow[9]); else _rec->segphi = 0.0;
		if (dbrow[10]) _rec->segtheta = atof((char*) dbrow[10]); else _rec->segtheta = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQSegMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegMNLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQSegMNLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQSegMNLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQSegMNLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1Start = atol((char*) dbrow[5]); else rec->x1Start = 0;
			if (dbrow[6]) rec->x1Stop = atol((char*) dbrow[6]); else rec->x1Stop = 0;
			if (dbrow[7]) rec->x2VisSegphi0 = atof((char*) dbrow[7]); else rec->x2VisSegphi0 = 0.0;
			if (dbrow[8]) rec->x2VisSegphi1 = atof((char*) dbrow[8]); else rec->x2VisSegphi1 = 0.0;
			if (dbrow[9]) rec->segphi = atof((char*) dbrow[9]); else rec->segphi = 0.0;
			if (dbrow[10]) rec->segtheta = atof((char*) dbrow[10]); else rec->segtheta = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQSegMNLocation::insertRec(
			BrlyQSegMNLocation* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x2VisSegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x2VisSegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->segphi,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->segtheta,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegMNLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegMNLocation / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQSegMNLocation::insertRst(
			ListBrlyQSegMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQSegMNLocation::updateRec(
			BrlyQSegMNLocation* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->x2VisSegphi0,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->x2VisSegphi1,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->segphi,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->segtheta,&(l[9]),&(n[9]),&(e[9])),
		bindUbigint(&rec->qref,&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegMNLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegMNLocation / stmtUpdateRec)\n");
};

void MyTblBrlyQSegMNLocation::updateRst(
			ListBrlyQSegMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQSegMNLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegMNLocation / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegMNLocation / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQSegMNLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegMNLocation / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegMNLocation / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQSegMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQSegMNLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQSegMNLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQSegMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegMNLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQSegMNLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQSegMNLocation
 ******************************************************************************/

PgTblBrlyQSegMNLocation::PgTblBrlyQSegMNLocation() : TblBrlyQSegMNLocation(), PgTable() {
};

PgTblBrlyQSegMNLocation::~PgTblBrlyQSegMNLocation() {
};

void PgTblBrlyQSegMNLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQSegMNLocation_insertRec", "INSERT INTO TblBrlyQSegMNLocation (jref, jnum, mref, ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, segphi, segtheta) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10) RETURNING qref", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegMNLocation_updateRec", "UPDATE TblBrlyQSegMNLocation SET jref = $1, jnum = $2, mref = $3, ref = $4, x1Start = $5, x1Stop = $6, x2VisSegphi0 = $7, x2VisSegphi1 = $8, segphi = $9, segtheta = $10 WHERE qref = $11", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegMNLocation_removeRecByQref", "DELETE FROM TblBrlyQSegMNLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegMNLocation_removeRstByJref", "DELETE FROM TblBrlyQSegMNLocation WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQSegMNLocation_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, segphi, segtheta FROM TblBrlyQSegMNLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegMNLocation_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1Start, x1Stop, x2VisSegphi0, x2VisSegphi1, segphi, segtheta FROM TblBrlyQSegMNLocation WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQSegMNLocation::loadRec(
			PGresult* res
			, BrlyQSegMNLocation** rec
		) {
	char* ptr;

	BrlyQSegMNLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQSegMNLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "x2vissegphi0"),
			PQfnumber(res, "x2vissegphi1"),
			PQfnumber(res, "segphi"),
			PQfnumber(res, "segtheta")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->x2VisSegphi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->x2VisSegphi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->segphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->segtheta = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQSegMNLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQSegMNLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQSegMNLocation* rec;

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
			PQfnumber(res, "x2vissegphi0"),
			PQfnumber(res, "x2vissegphi1"),
			PQfnumber(res, "segphi"),
			PQfnumber(res, "segtheta")
		};

		while (numread < numrow) {
			rec = new BrlyQSegMNLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->x2VisSegphi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->x2VisSegphi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->segphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->segtheta = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQSegMNLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQSegMNLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQSegMNLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQSegMNLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQSegMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegMNLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQSegMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegMNLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQSegMNLocation::insertRec(
			BrlyQSegMNLocation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2VisSegphi0 = to_string(rec->x2VisSegphi0);
	string _x2VisSegphi1 = to_string(rec->x2VisSegphi1);
	string _segphi = to_string(rec->segphi);
	string _segtheta = to_string(rec->segtheta);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2VisSegphi0.c_str(),
		_x2VisSegphi1.c_str(),
		_segphi.c_str(),
		_segtheta.c_str()
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

	res = PQexecPrepared(dbs, "TblBrlyQSegMNLocation_insertRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQSegMNLocation::insertRst(
			ListBrlyQSegMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQSegMNLocation::updateRec(
			BrlyQSegMNLocation* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	string _x2VisSegphi0 = to_string(rec->x2VisSegphi0);
	string _x2VisSegphi1 = to_string(rec->x2VisSegphi1);
	string _segphi = to_string(rec->segphi);
	string _segtheta = to_string(rec->segtheta);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		_x2VisSegphi0.c_str(),
		_x2VisSegphi1.c_str(),
		_segphi.c_str(),
		_segtheta.c_str(),
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

	res = PQexecPrepared(dbs, "TblBrlyQSegMNLocation_updateRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQSegMNLocation::updateRst(
			ListBrlyQSegMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQSegMNLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQSegMNLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNLocation_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQSegMNLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQSegMNLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNLocation_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQSegMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQSegMNLocation** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQSegMNLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQSegMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegMNLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQSegMNLocation_loadRstByJref", 1, vals, l, f, append, rst);
};

