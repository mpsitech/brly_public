/**
  * \file BrlyQTtbList.cpp
  * Dbs and XML wrapper for table TblBrlyQTtbList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQTtbList.h"

/******************************************************************************
 class BrlyQTtbList
 ******************************************************************************/

BrlyQTtbList::BrlyQTtbList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refBrlyMFile
			, const string stubRefBrlyMFile
			, const string srefBrlyKAlliance
			, const string titSrefBrlyKAlliance
			, const uint startd
			, const string ftmStartd
			, const uint stopd
			, const string ftmStopd
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->refBrlyMFile = refBrlyMFile;
	this->stubRefBrlyMFile = stubRefBrlyMFile;
	this->srefBrlyKAlliance = srefBrlyKAlliance;
	this->titSrefBrlyKAlliance = titSrefBrlyKAlliance;
	this->startd = startd;
	this->ftmStartd = ftmStartd;
	this->stopd = stopd;
	this->ftmStopd = ftmStopd;
};

void BrlyQTtbList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQTtbList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "fil", stubRefBrlyMFile);
		writeString(wr, "ali", srefBrlyKAlliance);
		writeString(wr, "ali2", titSrefBrlyKAlliance);
		writeString(wr, "sta", ftmStartd);
		writeString(wr, "sto", ftmStopd);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "stubRefBrlyMFile", stubRefBrlyMFile);
		writeString(wr, "srefBrlyKAlliance", srefBrlyKAlliance);
		writeString(wr, "titSrefBrlyKAlliance", titSrefBrlyKAlliance);
		writeString(wr, "ftmStartd", ftmStartd);
		writeString(wr, "ftmStopd", ftmStopd);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQTtbList
 ******************************************************************************/

ListBrlyQTtbList::ListBrlyQTtbList() {
};

ListBrlyQTtbList::ListBrlyQTtbList(
			const ListBrlyQTtbList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQTtbList(*(src.nodes[i]));
};

ListBrlyQTtbList::~ListBrlyQTtbList() {
	clear();
};

void ListBrlyQTtbList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQTtbList::size() const {
	return(nodes.size());
};

void ListBrlyQTtbList::append(
			BrlyQTtbList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQTtbList& ListBrlyQTtbList::operator=(
			const ListBrlyQTtbList& src
		) {
	BrlyQTtbList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQTtbList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQTtbList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQTtbList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQTtbList
 ******************************************************************************/

TblBrlyQTtbList::TblBrlyQTtbList() {
};

TblBrlyQTtbList::~TblBrlyQTtbList() {
};

bool TblBrlyQTtbList::loadRecBySQL(
			const string& sqlstr
			, BrlyQTtbList** rec
		) {
	return false;
};

ubigint TblBrlyQTtbList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQTtbList& rst
		) {
	return 0;
};

void TblBrlyQTtbList::insertRec(
			BrlyQTtbList* rec
		) {
};

ubigint TblBrlyQTtbList::insertNewRec(
			BrlyQTtbList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refBrlyMFile
			, const string stubRefBrlyMFile
			, const string srefBrlyKAlliance
			, const string titSrefBrlyKAlliance
			, const uint startd
			, const string ftmStartd
			, const uint stopd
			, const string ftmStopd
		) {
	ubigint retval = 0;
	BrlyQTtbList* _rec = NULL;

	_rec = new BrlyQTtbList(0, jref, jnum, ref, Title, refBrlyMFile, stubRefBrlyMFile, srefBrlyKAlliance, titSrefBrlyKAlliance, startd, ftmStartd, stopd, ftmStopd);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQTtbList::appendNewRecToRst(
			ListBrlyQTtbList& rst
			, BrlyQTtbList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const ubigint refBrlyMFile
			, const string stubRefBrlyMFile
			, const string srefBrlyKAlliance
			, const string titSrefBrlyKAlliance
			, const uint startd
			, const string ftmStartd
			, const uint stopd
			, const string ftmStopd
		) {
	ubigint retval = 0;
	BrlyQTtbList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, refBrlyMFile, stubRefBrlyMFile, srefBrlyKAlliance, titSrefBrlyKAlliance, startd, ftmStartd, stopd, ftmStopd);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQTtbList::insertRst(
			ListBrlyQTtbList& rst
		) {
};

void TblBrlyQTtbList::updateRec(
			BrlyQTtbList* rec
		) {
};

void TblBrlyQTtbList::updateRst(
			ListBrlyQTtbList& rst
		) {
};

void TblBrlyQTtbList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQTtbList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQTtbList::loadRecByQref(
			ubigint qref
			, BrlyQTtbList** rec
		) {
	return false;
};

ubigint TblBrlyQTtbList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQTtbList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQTtbList
 ******************************************************************************/

MyTblBrlyQTtbList::MyTblBrlyQTtbList() : TblBrlyQTtbList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQTtbList::~MyTblBrlyQTtbList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQTtbList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQTtbList (jref, jnum, ref, Title, refBrlyMFile, srefBrlyKAlliance, startd, stopd) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQTtbList SET jref = ?, jnum = ?, ref = ?, Title = ?, refBrlyMFile = ?, srefBrlyKAlliance = ?, startd = ?, stopd = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQTtbList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQTtbList WHERE jref = ?", false);
};

bool MyTblBrlyQTtbList::loadRecBySQL(
			const string& sqlstr
			, BrlyQTtbList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQTtbList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQTtbList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQTtbList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->refBrlyMFile = atoll((char*) dbrow[5]); else _rec->refBrlyMFile = 0;
		if (dbrow[6]) _rec->srefBrlyKAlliance.assign(dbrow[6], dblengths[6]); else _rec->srefBrlyKAlliance = "";
		if (dbrow[7]) _rec->startd = atol((char*) dbrow[7]); else _rec->startd = 0;
		if (dbrow[8]) _rec->stopd = atol((char*) dbrow[8]); else _rec->stopd = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQTtbList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQTtbList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQTtbList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQTtbList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQTtbList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->refBrlyMFile = atoll((char*) dbrow[5]); else rec->refBrlyMFile = 0;
			if (dbrow[6]) rec->srefBrlyKAlliance.assign(dbrow[6], dblengths[6]); else rec->srefBrlyKAlliance = "";
			if (dbrow[7]) rec->startd = atol((char*) dbrow[7]); else rec->startd = 0;
			if (dbrow[8]) rec->stopd = atol((char*) dbrow[8]); else rec->stopd = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQTtbList::insertRec(
			BrlyQTtbList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->Title.length();
	l[5] = rec->srefBrlyKAlliance.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMFile,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefBrlyKAlliance.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->startd,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->stopd,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQTtbList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQTtbList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQTtbList::insertRst(
			ListBrlyQTtbList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQTtbList::updateRec(
			BrlyQTtbList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->Title.length();
	l[5] = rec->srefBrlyKAlliance.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMFile,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->srefBrlyKAlliance.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->startd,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->stopd,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQTtbList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQTtbList / stmtUpdateRec)\n");
};

void MyTblBrlyQTtbList::updateRst(
			ListBrlyQTtbList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQTtbList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQTtbList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQTtbList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQTtbList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQTtbList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQTtbList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQTtbList::loadRecByQref(
			ubigint qref
			, BrlyQTtbList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQTtbList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQTtbList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQTtbList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQTtbList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQTtbList
 ******************************************************************************/

PgTblBrlyQTtbList::PgTblBrlyQTtbList() : TblBrlyQTtbList(), PgTable() {
};

PgTblBrlyQTtbList::~PgTblBrlyQTtbList() {
};

void PgTblBrlyQTtbList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQTtbList_insertRec", "INSERT INTO TblBrlyQTtbList (jref, jnum, ref, Title, refBrlyMFile, srefBrlyKAlliance, startd, stopd) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQTtbList_updateRec", "UPDATE TblBrlyQTtbList SET jref = $1, jnum = $2, ref = $3, Title = $4, refBrlyMFile = $5, srefBrlyKAlliance = $6, startd = $7, stopd = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQTtbList_removeRecByQref", "DELETE FROM TblBrlyQTtbList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQTtbList_removeRstByJref", "DELETE FROM TblBrlyQTtbList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQTtbList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, refBrlyMFile, srefBrlyKAlliance, startd, stopd FROM TblBrlyQTtbList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQTtbList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, refBrlyMFile, srefBrlyKAlliance, startd, stopd FROM TblBrlyQTtbList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQTtbList::loadRec(
			PGresult* res
			, BrlyQTtbList** rec
		) {
	char* ptr;

	BrlyQTtbList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQTtbList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refbrlymfile"),
			PQfnumber(res, "srefbrlykalliance"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "stopd")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refBrlyMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->srefBrlyKAlliance.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->stopd = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQTtbList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQTtbList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQTtbList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refbrlymfile"),
			PQfnumber(res, "srefbrlykalliance"),
			PQfnumber(res, "startd"),
			PQfnumber(res, "stopd")
		};

		while (numread < numrow) {
			rec = new BrlyQTtbList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refBrlyMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->srefBrlyKAlliance.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->stopd = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQTtbList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQTtbList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQTtbList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQTtbList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQTtbList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQTtbList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQTtbList::loadRecBySQL(
			const string& sqlstr
			, BrlyQTtbList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQTtbList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQTtbList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQTtbList::insertRec(
			BrlyQTtbList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refBrlyMFile = htonl64(rec->refBrlyMFile);
	uint _startd = htonl(rec->startd);
	uint _stopd = htonl(rec->stopd);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_refBrlyMFile,
		rec->srefBrlyKAlliance.c_str(),
		(char*) &_startd,
		(char*) &_stopd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQTtbList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQTtbList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQTtbList::insertRst(
			ListBrlyQTtbList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQTtbList::updateRec(
			BrlyQTtbList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refBrlyMFile = htonl64(rec->refBrlyMFile);
	uint _startd = htonl(rec->startd);
	uint _stopd = htonl(rec->stopd);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_refBrlyMFile,
		rec->srefBrlyKAlliance.c_str(),
		(char*) &_startd,
		(char*) &_stopd,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQTtbList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQTtbList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQTtbList::updateRst(
			ListBrlyQTtbList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQTtbList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQTtbList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQTtbList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQTtbList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQTtbList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQTtbList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQTtbList::loadRecByQref(
			ubigint qref
			, BrlyQTtbList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQTtbList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQTtbList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQTtbList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQTtbList_loadRstByJref", 1, vals, l, f, append, rst);
};

