/**
  * \file BrlyQRlyList.cpp
  * Dbs and XML wrapper for table TblBrlyQRlyList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQRlyList.h"

/******************************************************************************
 class BrlyQRlyList
 ******************************************************************************/

BrlyQRlyList::BrlyQRlyList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const ubigint refBrlyMConnection
			, const string stubRefBrlyMConnection
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
			, const bool Connected
			, const string yesnoConnected
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1Start = x1Start;
	this->ftmX1Start = ftmX1Start;
	this->x1Stop = x1Stop;
	this->ftmX1Stop = ftmX1Stop;
	this->refBrlyMConnection = refBrlyMConnection;
	this->stubRefBrlyMConnection = stubRefBrlyMConnection;
	this->ixVDir = ixVDir;
	this->srefIxVDir = srefIxVDir;
	this->titIxVDir = titIxVDir;
	this->Connected = Connected;
	this->yesnoConnected = yesnoConnected;
};

void BrlyQRlyList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQRlyList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "sta", ftmX1Start);
		writeString(wr, "sto", ftmX1Stop);
		writeString(wr, "con", stubRefBrlyMConnection);
		writeString(wr, "dir", srefIxVDir);
		writeString(wr, "dir2", titIxVDir);
		writeString(wr, "ctd", yesnoConnected);
	} else {
		writeString(wr, "ftmX1Start", ftmX1Start);
		writeString(wr, "ftmX1Stop", ftmX1Stop);
		writeString(wr, "stubRefBrlyMConnection", stubRefBrlyMConnection);
		writeString(wr, "srefIxVDir", srefIxVDir);
		writeString(wr, "titIxVDir", titIxVDir);
		writeString(wr, "yesnoConnected", yesnoConnected);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQRlyList
 ******************************************************************************/

ListBrlyQRlyList::ListBrlyQRlyList() {
};

ListBrlyQRlyList::ListBrlyQRlyList(
			const ListBrlyQRlyList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRlyList(*(src.nodes[i]));
};

ListBrlyQRlyList::~ListBrlyQRlyList() {
	clear();
};

void ListBrlyQRlyList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQRlyList::size() const {
	return(nodes.size());
};

void ListBrlyQRlyList::append(
			BrlyQRlyList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQRlyList& ListBrlyQRlyList::operator=(
			const ListBrlyQRlyList& src
		) {
	BrlyQRlyList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQRlyList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQRlyList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQRlyList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQRlyList
 ******************************************************************************/

TblBrlyQRlyList::TblBrlyQRlyList() {
};

TblBrlyQRlyList::~TblBrlyQRlyList() {
};

bool TblBrlyQRlyList::loadRecBySQL(
			const string& sqlstr
			, BrlyQRlyList** rec
		) {
	return false;
};

ubigint TblBrlyQRlyList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRlyList& rst
		) {
	return 0;
};

void TblBrlyQRlyList::insertRec(
			BrlyQRlyList* rec
		) {
};

ubigint TblBrlyQRlyList::insertNewRec(
			BrlyQRlyList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const ubigint refBrlyMConnection
			, const string stubRefBrlyMConnection
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
			, const bool Connected
			, const string yesnoConnected
		) {
	ubigint retval = 0;
	BrlyQRlyList* _rec = NULL;

	_rec = new BrlyQRlyList(0, jref, jnum, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, refBrlyMConnection, stubRefBrlyMConnection, ixVDir, srefIxVDir, titIxVDir, Connected, yesnoConnected);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQRlyList::appendNewRecToRst(
			ListBrlyQRlyList& rst
			, BrlyQRlyList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint x1Start
			, const string ftmX1Start
			, const uint x1Stop
			, const string ftmX1Stop
			, const ubigint refBrlyMConnection
			, const string stubRefBrlyMConnection
			, const uint ixVDir
			, const string srefIxVDir
			, const string titIxVDir
			, const bool Connected
			, const string yesnoConnected
		) {
	ubigint retval = 0;
	BrlyQRlyList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1Start, ftmX1Start, x1Stop, ftmX1Stop, refBrlyMConnection, stubRefBrlyMConnection, ixVDir, srefIxVDir, titIxVDir, Connected, yesnoConnected);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQRlyList::insertRst(
			ListBrlyQRlyList& rst
		) {
};

void TblBrlyQRlyList::updateRec(
			BrlyQRlyList* rec
		) {
};

void TblBrlyQRlyList::updateRst(
			ListBrlyQRlyList& rst
		) {
};

void TblBrlyQRlyList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQRlyList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQRlyList::loadRecByQref(
			ubigint qref
			, BrlyQRlyList** rec
		) {
	return false;
};

ubigint TblBrlyQRlyList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRlyList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQRlyList
 ******************************************************************************/

MyTblBrlyQRlyList::MyTblBrlyQRlyList() : TblBrlyQRlyList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQRlyList::~MyTblBrlyQRlyList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQRlyList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQRlyList (jref, jnum, ref, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQRlyList SET jref = ?, jnum = ?, ref = ?, x1Start = ?, x1Stop = ?, refBrlyMConnection = ?, ixVDir = ?, Connected = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQRlyList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQRlyList WHERE jref = ?", false);
};

bool MyTblBrlyQRlyList::loadRecBySQL(
			const string& sqlstr
			, BrlyQRlyList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQRlyList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQRlyList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQRlyList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1Start = atol((char*) dbrow[4]); else _rec->x1Start = 0;
		if (dbrow[5]) _rec->x1Stop = atol((char*) dbrow[5]); else _rec->x1Stop = 0;
		if (dbrow[6]) _rec->refBrlyMConnection = atoll((char*) dbrow[6]); else _rec->refBrlyMConnection = 0;
		if (dbrow[7]) _rec->ixVDir = atol((char*) dbrow[7]); else _rec->ixVDir = 0;
		if (dbrow[8]) _rec->Connected = (atoi((char*) dbrow[8]) != 0); else _rec->Connected = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQRlyList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRlyList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQRlyList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQRlyList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQRlyList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1Start = atol((char*) dbrow[4]); else rec->x1Start = 0;
			if (dbrow[5]) rec->x1Stop = atol((char*) dbrow[5]); else rec->x1Stop = 0;
			if (dbrow[6]) rec->refBrlyMConnection = atoll((char*) dbrow[6]); else rec->refBrlyMConnection = 0;
			if (dbrow[7]) rec->ixVDir = atol((char*) dbrow[7]); else rec->ixVDir = 0;
			if (dbrow[8]) rec->Connected = (atoi((char*) dbrow[8]) != 0); else rec->Connected = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQRlyList::insertRec(
			BrlyQRlyList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	tinyint Connected = rec->Connected;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1Start,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Stop,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMConnection,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDir,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Connected,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRlyList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRlyList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQRlyList::insertRst(
			ListBrlyQRlyList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQRlyList::updateRec(
			BrlyQRlyList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	tinyint Connected = rec->Connected;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->x1Start,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->x1Stop,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMConnection,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDir,&(l[6]),&(n[6]),&(e[6])),
		bindTinyint(&Connected,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRlyList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRlyList / stmtUpdateRec)\n");
};

void MyTblBrlyQRlyList::updateRst(
			ListBrlyQRlyList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQRlyList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRlyList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRlyList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQRlyList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRlyList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRlyList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQRlyList::loadRecByQref(
			ubigint qref
			, BrlyQRlyList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQRlyList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQRlyList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRlyList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQRlyList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQRlyList
 ******************************************************************************/

PgTblBrlyQRlyList::PgTblBrlyQRlyList() : TblBrlyQRlyList(), PgTable() {
};

PgTblBrlyQRlyList::~PgTblBrlyQRlyList() {
};

void PgTblBrlyQRlyList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQRlyList_insertRec", "INSERT INTO TblBrlyQRlyList (jref, jnum, ref, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRlyList_updateRec", "UPDATE TblBrlyQRlyList SET jref = $1, jnum = $2, ref = $3, x1Start = $4, x1Stop = $5, refBrlyMConnection = $6, ixVDir = $7, Connected = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRlyList_removeRecByQref", "DELETE FROM TblBrlyQRlyList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRlyList_removeRstByJref", "DELETE FROM TblBrlyQRlyList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQRlyList_loadRecByQref", "SELECT qref, jref, jnum, ref, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected FROM TblBrlyQRlyList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRlyList_loadRstByJref", "SELECT qref, jref, jnum, ref, x1Start, x1Stop, refBrlyMConnection, ixVDir, Connected FROM TblBrlyQRlyList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQRlyList::loadRec(
			PGresult* res
			, BrlyQRlyList** rec
		) {
	char* ptr;

	BrlyQRlyList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQRlyList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "connected")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1Stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refBrlyMConnection = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVDir = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Connected = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQRlyList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQRlyList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQRlyList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "x1stop"),
			PQfnumber(res, "refbrlymconnection"),
			PQfnumber(res, "ixvdir"),
			PQfnumber(res, "connected")
		};

		while (numread < numrow) {
			rec = new BrlyQRlyList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1Stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refBrlyMConnection = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVDir = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Connected = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQRlyList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQRlyList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRlyList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRlyList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQRlyList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRlyList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQRlyList::loadRecBySQL(
			const string& sqlstr
			, BrlyQRlyList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRlyList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRlyList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQRlyList::insertRec(
			BrlyQRlyList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	uint _ixVDir = htonl(rec->ixVDir);
	smallint _Connected = htons((smallint) rec->Connected);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		(char*) &_refBrlyMConnection,
		(char*) &_ixVDir,
		(char*) &_Connected
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQRlyList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRlyList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQRlyList::insertRst(
			ListBrlyQRlyList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQRlyList::updateRec(
			BrlyQRlyList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _x1Start = htonl(rec->x1Start);
	uint _x1Stop = htonl(rec->x1Stop);
	ubigint _refBrlyMConnection = htonl64(rec->refBrlyMConnection);
	uint _ixVDir = htonl(rec->ixVDir);
	smallint _Connected = htons((smallint) rec->Connected);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1Start,
		(char*) &_x1Stop,
		(char*) &_refBrlyMConnection,
		(char*) &_ixVDir,
		(char*) &_Connected,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQRlyList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRlyList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQRlyList::updateRst(
			ListBrlyQRlyList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQRlyList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRlyList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRlyList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQRlyList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRlyList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRlyList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQRlyList::loadRecByQref(
			ubigint qref
			, BrlyQRlyList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQRlyList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQRlyList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRlyList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQRlyList_loadRstByJref", 1, vals, l, f, append, rst);
};

