/**
  * \file BrlyQConMapRelay.cpp
  * Dbs and XML wrapper for table TblBrlyQConMapRelay (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQConMapRelay.h"

/******************************************************************************
 class BrlyQConMapRelay
 ******************************************************************************/

BrlyQConMapRelay::BrlyQConMapRelay(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const uint ixVDir
			, const string srefIxVDir
			, const bool Connected
			, const string yesnoConnected
			, const usmallint Nhop
		) {
	this->qref = qref;
	this->qwr = qwr;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1Start = x1Start;
	this->x1Stop = x1Stop;
	this->ixVDir = ixVDir;
	this->srefIxVDir = srefIxVDir;
	this->Connected = Connected;
	this->yesnoConnected = yesnoConnected;
	this->Nhop = Nhop;
};

void BrlyQConMapRelay::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConMapRelay";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeUint(wr, "sta", x1Start);
		writeUint(wr, "sto", x1Stop);
		writeString(wr, "dir", srefIxVDir);
		writeString(wr, "ctd", yesnoConnected);
		writeUint(wr, "nhp", Nhop);
	} else {
		writeUint(wr, "x1Start", x1Start);
		writeUint(wr, "x1Stop", x1Stop);
		writeString(wr, "srefIxVDir", srefIxVDir);
		writeString(wr, "yesnoConnected", yesnoConnected);
		writeUint(wr, "Nhop", Nhop);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQConMapRelay
 ******************************************************************************/

ListBrlyQConMapRelay::ListBrlyQConMapRelay() {
};

ListBrlyQConMapRelay::ListBrlyQConMapRelay(
			const ListBrlyQConMapRelay& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapRelay(*(src.nodes[i]));
};

ListBrlyQConMapRelay::~ListBrlyQConMapRelay() {
	clear();
};

void ListBrlyQConMapRelay::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConMapRelay::size() const {
	return(nodes.size());
};

void ListBrlyQConMapRelay::append(
			BrlyQConMapRelay* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConMapRelay& ListBrlyQConMapRelay::operator=(
			const ListBrlyQConMapRelay& src
		) {
	BrlyQConMapRelay* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQConMapRelay(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConMapRelay::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConMapRelay";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConMapRelay
 ******************************************************************************/

TblBrlyQConMapRelay::TblBrlyQConMapRelay() {
};

TblBrlyQConMapRelay::~TblBrlyQConMapRelay() {
};

bool TblBrlyQConMapRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapRelay** rec
		) {
	return false;
};

ubigint TblBrlyQConMapRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapRelay& rst
		) {
	return 0;
};

void TblBrlyQConMapRelay::insertRec(
			BrlyQConMapRelay* rec
		) {
};

ubigint TblBrlyQConMapRelay::insertNewRec(
			BrlyQConMapRelay** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const uint ixVDir
			, const string srefIxVDir
			, const bool Connected
			, const string yesnoConnected
			, const usmallint Nhop
		) {
	ubigint retval = 0;
	BrlyQConMapRelay* _rec = NULL;

	_rec = new BrlyQConMapRelay(0, qwr, jref, jnum, ref, x1Start, x1Stop, ixVDir, srefIxVDir, Connected, yesnoConnected, Nhop);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConMapRelay::appendNewRecToRst(
			ListBrlyQConMapRelay& rst
			, BrlyQConMapRelay** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const uint x1Stop
			, const uint ixVDir
			, const string srefIxVDir
			, const bool Connected
			, const string yesnoConnected
			, const usmallint Nhop
		) {
	ubigint retval = 0;
	BrlyQConMapRelay* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, x1Start, x1Stop, ixVDir, srefIxVDir, Connected, yesnoConnected, Nhop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConMapRelay::insertRst(
			ListBrlyQConMapRelay& rst
		) {
};

void TblBrlyQConMapRelay::updateRec(
			BrlyQConMapRelay* rec
		) {
};

void TblBrlyQConMapRelay::updateRst(
			ListBrlyQConMapRelay& rst
		) {
};

void TblBrlyQConMapRelay::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConMapRelay::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConMapRelay::loadRecByQref(
			ubigint qref
			, BrlyQConMapRelay** rec
		) {
	return false;
};

ubigint TblBrlyQConMapRelay::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapRelay& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQConMapRelay
 ******************************************************************************/

MyTblBrlyQConMapRelay::MyTblBrlyQConMapRelay() : TblBrlyQConMapRelay(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConMapRelay::~MyTblBrlyQConMapRelay() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConMapRelay::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConMapRelay (qwr, jref, jnum, ref, x1Start, x1Stop, ixVDir, Connected, Nhop) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConMapRelay SET qwr = ?, jref = ?, jnum = ?, ref = ?, x1Start = ?, x1Stop = ?, ixVDir = ?, Connected = ?, Nhop = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConMapRelay WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConMapRelay WHERE jref = ?", false);
};

bool MyTblBrlyQConMapRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapRelay** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConMapRelay* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapRelay / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConMapRelay();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1Start = atol((char*) dbrow[5]); else _rec->x1Start = 0;
		if (dbrow[6]) _rec->x1Stop = atol((char*) dbrow[6]); else _rec->x1Stop = 0;
		if (dbrow[7]) _rec->ixVDir = atol((char*) dbrow[7]); else _rec->ixVDir = 0;
		if (dbrow[8]) _rec->Connected = (atoi((char*) dbrow[8]) != 0); else _rec->Connected = false;
		if (dbrow[9]) _rec->Nhop = atoi((char*) dbrow[9]); else _rec->Nhop = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQConMapRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapRelay& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConMapRelay* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapRelay / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConMapRelay();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1Start = atol((char*) dbrow[5]); else rec->x1Start = 0;
			if (dbrow[6]) rec->x1Stop = atol((char*) dbrow[6]); else rec->x1Stop = 0;
			if (dbrow[7]) rec->ixVDir = atol((char*) dbrow[7]); else rec->ixVDir = 0;
			if (dbrow[8]) rec->Connected = (atoi((char*) dbrow[8]) != 0); else rec->Connected = false;
			if (dbrow[9]) rec->Nhop = atoi((char*) dbrow[9]); else rec->Nhop = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQConMapRelay::insertRec(
			BrlyQConMapRelay* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	tinyint qwr = rec->qwr;
	tinyint Connected = rec->Connected;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDir,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Connected,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Nhop,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapRelay / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapRelay / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQConMapRelay::insertRst(
			ListBrlyQConMapRelay& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConMapRelay::updateRec(
			BrlyQConMapRelay* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	tinyint qwr = rec->qwr;
	tinyint Connected = rec->Connected;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Start,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->x1Stop,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDir,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Connected,&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Nhop,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapRelay / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapRelay / stmtUpdateRec)\n");
};

void MyTblBrlyQConMapRelay::updateRst(
			ListBrlyQConMapRelay& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConMapRelay::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapRelay / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapRelay / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQConMapRelay::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapRelay / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapRelay / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQConMapRelay::loadRecByQref(
			ubigint qref
			, BrlyQConMapRelay** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQConMapRelay WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConMapRelay::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapRelay& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConMapRelay WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQConMapRelay
 ******************************************************************************/

PgTblBrlyQConMapRelay::PgTblBrlyQConMapRelay() : TblBrlyQConMapRelay(), PgTable() {
};

PgTblBrlyQConMapRelay::~PgTblBrlyQConMapRelay() {
};

void PgTblBrlyQConMapRelay::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQConMapRelay_insertRec", "INSERT INTO TblBrlyQConMapRelay (qwr, jref, jnum, ref, x1Start, x1Stop, ixVDir, Connected, Nhop) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapRelay_updateRec", "UPDATE TblBrlyQConMapRelay SET qwr = $1, jref = $2, jnum = $3, ref = $4, x1Start = $5, x1Stop = $6, ixVDir = $7, Connected = $8, Nhop = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapRelay_removeRecByQref", "DELETE FROM TblBrlyQConMapRelay WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapRelay_removeRstByJref", "DELETE FROM TblBrlyQConMapRelay WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQConMapRelay_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, x1Start, x1Stop, ixVDir, Connected, Nhop FROM TblBrlyQConMapRelay WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapRelay_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, x1Start, x1Stop, ixVDir, Connected, Nhop FROM TblBrlyQConMapRelay WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQConMapRelay::loadRec(
			PGresult* res
			, BrlyQConMapRelay** rec
		) {
	char* ptr;

	BrlyQConMapRelay* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConMapRelay();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "connected"),
			PQfnumber(res, "nhop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVDir = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Connected = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Nhop = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQConMapRelay::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConMapRelay& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConMapRelay* rec;

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
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "connected"),
			PQfnumber(res, "nhop")
		};

		while (numread < numrow) {
			rec = new BrlyQConMapRelay();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVDir = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Connected = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Nhop = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQConMapRelay::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConMapRelay** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapRelay / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapRelay::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConMapRelay& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapRelay / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConMapRelay::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapRelay** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapRelay::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapRelay& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQConMapRelay::insertRec(
			BrlyQConMapRelay* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	uint _ixVDir = htonl(rec->ixVDir);
	smallint _Connected = htons((smallint) rec->Connected);
	usmallint _Nhop = htons(rec->Nhop);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		(char*) &_ixVDir,
		(char*) &_Connected,
		(char*) &_Nhop
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMapRelay_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapRelay_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQConMapRelay::insertRst(
			ListBrlyQConMapRelay& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConMapRelay::updateRec(
			BrlyQConMapRelay* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	uint _ixVDir = htonl(rec->ixVDir);
	smallint _Connected = htons((smallint) rec->Connected);
	usmallint _Nhop = htons(rec->Nhop);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		(char*) &_ixVDir,
		(char*) &_Connected,
		(char*) &_Nhop,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMapRelay_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapRelay_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQConMapRelay::updateRst(
			ListBrlyQConMapRelay& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConMapRelay::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapRelay_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapRelay_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQConMapRelay::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapRelay_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapRelay_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQConMapRelay::loadRecByQref(
			ubigint qref
			, BrlyQConMapRelay** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQConMapRelay_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConMapRelay::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapRelay& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConMapRelay_loadRstByJref", 1, vals, l, f, append, rst);
};

