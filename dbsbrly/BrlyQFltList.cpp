/**
  * \file BrlyQFltList.cpp
  * Dbs and XML wrapper for table TblBrlyQFltList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQFltList.h"

/******************************************************************************
 class BrlyQFltList
 ******************************************************************************/

BrlyQFltList::BrlyQFltList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refBrlyMEquipment
			, const string stubRefBrlyMEquipment
			, const ubigint refBrlyMFaflight
			, const ubigint refBrlyMLeg
			, const string stubRefBrlyMLeg
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->refBrlyMEquipment = refBrlyMEquipment;
	this->stubRefBrlyMEquipment = stubRefBrlyMEquipment;
	this->refBrlyMFaflight = refBrlyMFaflight;
	this->refBrlyMLeg = refBrlyMLeg;
	this->stubRefBrlyMLeg = stubRefBrlyMLeg;
	this->start = start;
	this->ftmStart = ftmStart;
	this->stop = stop;
	this->ftmStop = ftmStop;
};

void BrlyQFltList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQFltList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "eqp", stubRefBrlyMEquipment);
		writeString(wr, "leg", stubRefBrlyMLeg);
		writeString(wr, "sta", ftmStart);
		writeString(wr, "sto", ftmStop);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefBrlyMEquipment", stubRefBrlyMEquipment);
		writeString(wr, "stubRefBrlyMLeg", stubRefBrlyMLeg);
		writeString(wr, "ftmStart", ftmStart);
		writeString(wr, "ftmStop", ftmStop);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQFltList
 ******************************************************************************/

ListBrlyQFltList::ListBrlyQFltList() {
};

ListBrlyQFltList::ListBrlyQFltList(
			const ListBrlyQFltList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFltList(*(src.nodes[i]));
};

ListBrlyQFltList::~ListBrlyQFltList() {
	clear();
};

void ListBrlyQFltList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQFltList::size() const {
	return(nodes.size());
};

void ListBrlyQFltList::append(
			BrlyQFltList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQFltList& ListBrlyQFltList::operator=(
			const ListBrlyQFltList& src
		) {
	BrlyQFltList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQFltList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQFltList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQFltList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQFltList
 ******************************************************************************/

TblBrlyQFltList::TblBrlyQFltList() {
};

TblBrlyQFltList::~TblBrlyQFltList() {
};

bool TblBrlyQFltList::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltList** rec
		) {
	return false;
};

ubigint TblBrlyQFltList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltList& rst
		) {
	return 0;
};

void TblBrlyQFltList::insertRec(
			BrlyQFltList* rec
		) {
};

ubigint TblBrlyQFltList::insertNewRec(
			BrlyQFltList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refBrlyMEquipment
			, const string stubRefBrlyMEquipment
			, const ubigint refBrlyMFaflight
			, const ubigint refBrlyMLeg
			, const string stubRefBrlyMLeg
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	ubigint retval = 0;
	BrlyQFltList* _rec = NULL;

	_rec = new BrlyQFltList(0, jref, jnum, ref, sref, refBrlyMEquipment, stubRefBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, stubRefBrlyMLeg, start, ftmStart, stop, ftmStop);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQFltList::appendNewRecToRst(
			ListBrlyQFltList& rst
			, BrlyQFltList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const ubigint refBrlyMEquipment
			, const string stubRefBrlyMEquipment
			, const ubigint refBrlyMFaflight
			, const ubigint refBrlyMLeg
			, const string stubRefBrlyMLeg
			, const uint start
			, const string ftmStart
			, const uint stop
			, const string ftmStop
		) {
	ubigint retval = 0;
	BrlyQFltList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, refBrlyMEquipment, stubRefBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, stubRefBrlyMLeg, start, ftmStart, stop, ftmStop);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQFltList::insertRst(
			ListBrlyQFltList& rst
		) {
};

void TblBrlyQFltList::updateRec(
			BrlyQFltList* rec
		) {
};

void TblBrlyQFltList::updateRst(
			ListBrlyQFltList& rst
		) {
};

void TblBrlyQFltList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQFltList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQFltList::loadRecByQref(
			ubigint qref
			, BrlyQFltList** rec
		) {
	return false;
};

ubigint TblBrlyQFltList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQFltList
 ******************************************************************************/

MyTblBrlyQFltList::MyTblBrlyQFltList() : TblBrlyQFltList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQFltList::~MyTblBrlyQFltList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQFltList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQFltList (jref, jnum, ref, sref, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, start, stop) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQFltList SET jref = ?, jnum = ?, ref = ?, sref = ?, refBrlyMEquipment = ?, refBrlyMFaflight = ?, refBrlyMLeg = ?, start = ?, stop = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQFltList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQFltList WHERE jref = ?", false);
};

bool MyTblBrlyQFltList::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQFltList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQFltList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->refBrlyMEquipment = atoll((char*) dbrow[5]); else _rec->refBrlyMEquipment = 0;
		if (dbrow[6]) _rec->refBrlyMFaflight = atoll((char*) dbrow[6]); else _rec->refBrlyMFaflight = 0;
		if (dbrow[7]) _rec->refBrlyMLeg = atoll((char*) dbrow[7]); else _rec->refBrlyMLeg = 0;
		if (dbrow[8]) _rec->start = atol((char*) dbrow[8]); else _rec->start = 0;
		if (dbrow[9]) _rec->stop = atol((char*) dbrow[9]); else _rec->stop = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQFltList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQFltList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFltList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQFltList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->refBrlyMEquipment = atoll((char*) dbrow[5]); else rec->refBrlyMEquipment = 0;
			if (dbrow[6]) rec->refBrlyMFaflight = atoll((char*) dbrow[6]); else rec->refBrlyMFaflight = 0;
			if (dbrow[7]) rec->refBrlyMLeg = atoll((char*) dbrow[7]); else rec->refBrlyMLeg = 0;
			if (dbrow[8]) rec->start = atol((char*) dbrow[8]); else rec->start = 0;
			if (dbrow[9]) rec->stop = atol((char*) dbrow[9]); else rec->stop = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQFltList::insertRec(
			BrlyQFltList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMFaflight,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refBrlyMLeg,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->stop,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQFltList::insertRst(
			ListBrlyQFltList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQFltList::updateRec(
			BrlyQFltList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMFaflight,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refBrlyMLeg,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->start,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->stop,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltList / stmtUpdateRec)\n");
};

void MyTblBrlyQFltList::updateRst(
			ListBrlyQFltList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQFltList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQFltList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFltList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFltList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQFltList::loadRecByQref(
			ubigint qref
			, BrlyQFltList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQFltList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQFltList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQFltList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQFltList
 ******************************************************************************/

PgTblBrlyQFltList::PgTblBrlyQFltList() : TblBrlyQFltList(), PgTable() {
};

PgTblBrlyQFltList::~PgTblBrlyQFltList() {
};

void PgTblBrlyQFltList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQFltList_insertRec", "INSERT INTO TblBrlyQFltList (jref, jnum, ref, sref, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, start, stop) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltList_updateRec", "UPDATE TblBrlyQFltList SET jref = $1, jnum = $2, ref = $3, sref = $4, refBrlyMEquipment = $5, refBrlyMFaflight = $6, refBrlyMLeg = $7, start = $8, stop = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltList_removeRecByQref", "DELETE FROM TblBrlyQFltList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltList_removeRstByJref", "DELETE FROM TblBrlyQFltList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQFltList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, start, stop FROM TblBrlyQFltList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFltList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, refBrlyMEquipment, refBrlyMFaflight, refBrlyMLeg, start, stop FROM TblBrlyQFltList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQFltList::loadRec(
			PGresult* res
			, BrlyQFltList** rec
		) {
	char* ptr;

	BrlyQFltList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQFltList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "refbrlymfaflight"),
			PQfnumber(res, "refbrlymleg"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refBrlyMEquipment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refBrlyMFaflight = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refBrlyMLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->stop = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQFltList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQFltList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQFltList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "refbrlymfaflight"),
			PQfnumber(res, "refbrlymleg"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop")
		};

		while (numread < numrow) {
			rec = new BrlyQFltList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refBrlyMEquipment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refBrlyMFaflight = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refBrlyMLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->stop = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQFltList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQFltList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQFltList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQFltList::loadRecBySQL(
			const string& sqlstr
			, BrlyQFltList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFltList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFltList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQFltList::insertRec(
			BrlyQFltList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	ubigint _refBrlyMFaflight = htonl64(rec->refBrlyMFaflight);
	ubigint _refBrlyMLeg = htonl64(rec->refBrlyMLeg);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refBrlyMEquipment,
		(char*) &_refBrlyMFaflight,
		(char*) &_refBrlyMLeg,
		(char*) &_start,
		(char*) &_stop
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQFltList::insertRst(
			ListBrlyQFltList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQFltList::updateRec(
			BrlyQFltList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	ubigint _refBrlyMFaflight = htonl64(rec->refBrlyMFaflight);
	ubigint _refBrlyMLeg = htonl64(rec->refBrlyMLeg);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_refBrlyMEquipment,
		(char*) &_refBrlyMFaflight,
		(char*) &_refBrlyMLeg,
		(char*) &_start,
		(char*) &_stop,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFltList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQFltList::updateRst(
			ListBrlyQFltList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQFltList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFltList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQFltList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFltList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFltList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQFltList::loadRecByQref(
			ubigint qref
			, BrlyQFltList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQFltList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQFltList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFltList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQFltList_loadRstByJref", 1, vals, l, f, append, rst);
};

