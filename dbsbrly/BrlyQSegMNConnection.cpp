/**
  * \file BrlyQSegMNConnection.cpp
  * Dbs and XML wrapper for table TblBrlyQSegMNConnection (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQSegMNConnection.h"

/******************************************************************************
 class BrlyQSegMNConnection
 ******************************************************************************/

BrlyQSegMNConnection::BrlyQSegMNConnection(
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

void BrlyQSegMNConnection::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQSegMNConnection";

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
 class ListBrlyQSegMNConnection
 ******************************************************************************/

ListBrlyQSegMNConnection::ListBrlyQSegMNConnection() {
};

ListBrlyQSegMNConnection::ListBrlyQSegMNConnection(
			const ListBrlyQSegMNConnection& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQSegMNConnection(*(src.nodes[i]));
};

ListBrlyQSegMNConnection::~ListBrlyQSegMNConnection() {
	clear();
};

void ListBrlyQSegMNConnection::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQSegMNConnection::size() const {
	return(nodes.size());
};

void ListBrlyQSegMNConnection::append(
			BrlyQSegMNConnection* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQSegMNConnection& ListBrlyQSegMNConnection::operator=(
			const ListBrlyQSegMNConnection& src
		) {
	BrlyQSegMNConnection* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQSegMNConnection(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQSegMNConnection::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQSegMNConnection";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQSegMNConnection
 ******************************************************************************/

TblBrlyQSegMNConnection::TblBrlyQSegMNConnection() {
};

TblBrlyQSegMNConnection::~TblBrlyQSegMNConnection() {
};

bool TblBrlyQSegMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegMNConnection** rec
		) {
	return false;
};

ubigint TblBrlyQSegMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegMNConnection& rst
		) {
	return 0;
};

void TblBrlyQSegMNConnection::insertRec(
			BrlyQSegMNConnection* rec
		) {
};

ubigint TblBrlyQSegMNConnection::insertNewRec(
			BrlyQSegMNConnection** rec
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
	BrlyQSegMNConnection* _rec = NULL;

	_rec = new BrlyQSegMNConnection(0, jref, jnum, mref, stubMref, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, x2Legphi0, x2Legphi1);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQSegMNConnection::appendNewRecToRst(
			ListBrlyQSegMNConnection& rst
			, BrlyQSegMNConnection** rec
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
	BrlyQSegMNConnection* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, x2Legphi0, x2Legphi1);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQSegMNConnection::insertRst(
			ListBrlyQSegMNConnection& rst
		) {
};

void TblBrlyQSegMNConnection::updateRec(
			BrlyQSegMNConnection* rec
		) {
};

void TblBrlyQSegMNConnection::updateRst(
			ListBrlyQSegMNConnection& rst
		) {
};

void TblBrlyQSegMNConnection::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQSegMNConnection::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQSegMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQSegMNConnection** rec
		) {
	return false;
};

ubigint TblBrlyQSegMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegMNConnection& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQSegMNConnection
 ******************************************************************************/

MyTblBrlyQSegMNConnection::MyTblBrlyQSegMNConnection() : TblBrlyQSegMNConnection(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQSegMNConnection::~MyTblBrlyQSegMNConnection() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQSegMNConnection::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQSegMNConnection (jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQSegMNConnection SET jref = ?, jnum = ?, mref = ?, ref = ?, x1Start = ?, x1Stop = ?, x2Legphi0 = ?, x2Legphi1 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQSegMNConnection WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQSegMNConnection WHERE jref = ?", false);
};

bool MyTblBrlyQSegMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegMNConnection** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQSegMNConnection* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQSegMNConnection / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQSegMNConnection();

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

ubigint MyTblBrlyQSegMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegMNConnection& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQSegMNConnection* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQSegMNConnection / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQSegMNConnection();

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

void MyTblBrlyQSegMNConnection::insertRec(
			BrlyQSegMNConnection* rec
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

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegMNConnection / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegMNConnection / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQSegMNConnection::insertRst(
			ListBrlyQSegMNConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQSegMNConnection::updateRec(
			BrlyQSegMNConnection* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegMNConnection / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegMNConnection / stmtUpdateRec)\n");
};

void MyTblBrlyQSegMNConnection::updateRst(
			ListBrlyQSegMNConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQSegMNConnection::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegMNConnection / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegMNConnection / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQSegMNConnection::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQSegMNConnection / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQSegMNConnection / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQSegMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQSegMNConnection** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQSegMNConnection WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQSegMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegMNConnection& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQSegMNConnection WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQSegMNConnection
 ******************************************************************************/

PgTblBrlyQSegMNConnection::PgTblBrlyQSegMNConnection() : TblBrlyQSegMNConnection(), PgTable() {
};

PgTblBrlyQSegMNConnection::~PgTblBrlyQSegMNConnection() {
};

void PgTblBrlyQSegMNConnection::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQSegMNConnection_insertRec", "INSERT INTO TblBrlyQSegMNConnection (jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegMNConnection_updateRec", "UPDATE TblBrlyQSegMNConnection SET jref = $1, jnum = $2, mref = $3, ref = $4, x1Start = $5, x1Stop = $6, x2Legphi0 = $7, x2Legphi1 = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegMNConnection_removeRecByQref", "DELETE FROM TblBrlyQSegMNConnection WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegMNConnection_removeRstByJref", "DELETE FROM TblBrlyQSegMNConnection WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQSegMNConnection_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1 FROM TblBrlyQSegMNConnection WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQSegMNConnection_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1Start, x1Stop, x2Legphi0, x2Legphi1 FROM TblBrlyQSegMNConnection WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQSegMNConnection::loadRec(
			PGresult* res
			, BrlyQSegMNConnection** rec
		) {
	char* ptr;

	BrlyQSegMNConnection* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQSegMNConnection();

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

ubigint PgTblBrlyQSegMNConnection::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQSegMNConnection& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQSegMNConnection* rec;

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
			rec = new BrlyQSegMNConnection();

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

bool PgTblBrlyQSegMNConnection::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQSegMNConnection** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNConnection / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQSegMNConnection::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQSegMNConnection& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNConnection / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQSegMNConnection::loadRecBySQL(
			const string& sqlstr
			, BrlyQSegMNConnection** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQSegMNConnection::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQSegMNConnection& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQSegMNConnection::insertRec(
			BrlyQSegMNConnection* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQSegMNConnection_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNConnection_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQSegMNConnection::insertRst(
			ListBrlyQSegMNConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQSegMNConnection::updateRec(
			BrlyQSegMNConnection* rec
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

	res = PQexecPrepared(dbs, "TblBrlyQSegMNConnection_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNConnection_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQSegMNConnection::updateRst(
			ListBrlyQSegMNConnection& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQSegMNConnection::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQSegMNConnection_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNConnection_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQSegMNConnection::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQSegMNConnection_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQSegMNConnection_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQSegMNConnection::loadRecByQref(
			ubigint qref
			, BrlyQSegMNConnection** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQSegMNConnection_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQSegMNConnection::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQSegMNConnection& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQSegMNConnection_loadRstByJref", 1, vals, l, f, append, rst);
};

