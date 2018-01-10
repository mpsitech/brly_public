/**
  * \file BrlyQUsrList.cpp
  * Dbs and XML wrapper for table TblBrlyQUsrList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQUsrList.h"

/******************************************************************************
 class BrlyQUsrList
 ******************************************************************************/

BrlyQUsrList::BrlyQUsrList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refBrlyMPerson
			, const string stubRefBrlyMPerson
			, const string sref
			, const ubigint refBrlyMUsergroup
			, const string stubRefBrlyMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixBrlyVLocale
			, const string srefIxBrlyVLocale
			, const string titIxBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->refBrlyMPerson = refBrlyMPerson;
	this->stubRefBrlyMPerson = stubRefBrlyMPerson;
	this->sref = sref;
	this->refBrlyMUsergroup = refBrlyMUsergroup;
	this->stubRefBrlyMUsergroup = stubRefBrlyMUsergroup;
	this->ixVState = ixVState;
	this->srefIxVState = srefIxVState;
	this->titIxVState = titIxVState;
	this->ixBrlyVLocale = ixBrlyVLocale;
	this->srefIxBrlyVLocale = srefIxBrlyVLocale;
	this->titIxBrlyVLocale = titIxBrlyVLocale;
	this->ixBrlyVUserlevel = ixBrlyVUserlevel;
	this->srefIxBrlyVUserlevel = srefIxBrlyVUserlevel;
	this->titIxBrlyVUserlevel = titIxBrlyVUserlevel;
};

void BrlyQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsrList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "prs", stubRefBrlyMPerson);
		writeString(wr, "srf", sref);
		writeString(wr, "usg", stubRefBrlyMUsergroup);
		writeString(wr, "ste", srefIxVState);
		writeString(wr, "ste2", titIxVState);
		writeString(wr, "lcl", srefIxBrlyVLocale);
		writeString(wr, "lcl2", titIxBrlyVLocale);
		writeString(wr, "ulv", srefIxBrlyVUserlevel);
		writeString(wr, "ulv2", titIxBrlyVUserlevel);
	} else {
		writeString(wr, "stubRefBrlyMPerson", stubRefBrlyMPerson);
		writeString(wr, "sref", sref);
		writeString(wr, "stubRefBrlyMUsergroup", stubRefBrlyMUsergroup);
		writeString(wr, "srefIxVState", srefIxVState);
		writeString(wr, "titIxVState", titIxVState);
		writeString(wr, "srefIxBrlyVLocale", srefIxBrlyVLocale);
		writeString(wr, "titIxBrlyVLocale", titIxBrlyVLocale);
		writeString(wr, "srefIxBrlyVUserlevel", srefIxBrlyVUserlevel);
		writeString(wr, "titIxBrlyVUserlevel", titIxBrlyVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQUsrList
 ******************************************************************************/

ListBrlyQUsrList::ListBrlyQUsrList() {
};

ListBrlyQUsrList::ListBrlyQUsrList(
			const ListBrlyQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrList(*(src.nodes[i]));
};

ListBrlyQUsrList::~ListBrlyQUsrList() {
	clear();
};

void ListBrlyQUsrList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsrList::size() const {
	return(nodes.size());
};

void ListBrlyQUsrList::append(
			BrlyQUsrList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsrList& ListBrlyQUsrList::operator=(
			const ListBrlyQUsrList& src
		) {
	BrlyQUsrList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQUsrList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsrList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsrList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsrList
 ******************************************************************************/

TblBrlyQUsrList::TblBrlyQUsrList() {
};

TblBrlyQUsrList::~TblBrlyQUsrList() {
};

bool TblBrlyQUsrList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrList** rec
		) {
	return false;
};

ubigint TblBrlyQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	return 0;
};

void TblBrlyQUsrList::insertRec(
			BrlyQUsrList* rec
		) {
};

ubigint TblBrlyQUsrList::insertNewRec(
			BrlyQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refBrlyMPerson
			, const string stubRefBrlyMPerson
			, const string sref
			, const ubigint refBrlyMUsergroup
			, const string stubRefBrlyMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixBrlyVLocale
			, const string srefIxBrlyVLocale
			, const string titIxBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyQUsrList* _rec = NULL;

	_rec = new BrlyQUsrList(0, jref, jnum, ref, refBrlyMPerson, stubRefBrlyMPerson, sref, refBrlyMUsergroup, stubRefBrlyMUsergroup, ixVState, srefIxVState, titIxVState, ixBrlyVLocale, srefIxBrlyVLocale, titIxBrlyVLocale, ixBrlyVUserlevel, srefIxBrlyVUserlevel, titIxBrlyVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsrList::appendNewRecToRst(
			ListBrlyQUsrList& rst
			, BrlyQUsrList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint refBrlyMPerson
			, const string stubRefBrlyMPerson
			, const string sref
			, const ubigint refBrlyMUsergroup
			, const string stubRefBrlyMUsergroup
			, const uint ixVState
			, const string srefIxVState
			, const string titIxVState
			, const uint ixBrlyVLocale
			, const string srefIxBrlyVLocale
			, const string titIxBrlyVLocale
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyQUsrList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, refBrlyMPerson, stubRefBrlyMPerson, sref, refBrlyMUsergroup, stubRefBrlyMUsergroup, ixVState, srefIxVState, titIxVState, ixBrlyVLocale, srefIxBrlyVLocale, titIxBrlyVLocale, ixBrlyVUserlevel, srefIxBrlyVUserlevel, titIxBrlyVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsrList::insertRst(
			ListBrlyQUsrList& rst
		) {
};

void TblBrlyQUsrList::updateRec(
			BrlyQUsrList* rec
		) {
};

void TblBrlyQUsrList::updateRst(
			ListBrlyQUsrList& rst
		) {
};

void TblBrlyQUsrList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsrList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsrList::loadRecByQref(
			ubigint qref
			, BrlyQUsrList** rec
		) {
	return false;
};

ubigint TblBrlyQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQUsrList
 ******************************************************************************/

MyTblBrlyQUsrList::MyTblBrlyQUsrList() : TblBrlyQUsrList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsrList::~MyTblBrlyQUsrList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsrList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsrList (jref, jnum, ref, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsrList SET jref = ?, jnum = ?, ref = ?, refBrlyMPerson = ?, sref = ?, refBrlyMUsergroup = ?, ixVState = ?, ixBrlyVLocale = ?, ixBrlyVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsrList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsrList WHERE jref = ?", false);
};

bool MyTblBrlyQUsrList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsrList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQUsrList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQUsrList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->refBrlyMPerson = atoll((char*) dbrow[4]); else _rec->refBrlyMPerson = 0;
		if (dbrow[5]) _rec->sref.assign(dbrow[5], dblengths[5]); else _rec->sref = "";
		if (dbrow[6]) _rec->refBrlyMUsergroup = atoll((char*) dbrow[6]); else _rec->refBrlyMUsergroup = 0;
		if (dbrow[7]) _rec->ixVState = atol((char*) dbrow[7]); else _rec->ixVState = 0;
		if (dbrow[8]) _rec->ixBrlyVLocale = atol((char*) dbrow[8]); else _rec->ixBrlyVLocale = 0;
		if (dbrow[9]) _rec->ixBrlyVUserlevel = atol((char*) dbrow[9]); else _rec->ixBrlyVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsrList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQUsrList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQUsrList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->refBrlyMPerson = atoll((char*) dbrow[4]); else rec->refBrlyMPerson = 0;
			if (dbrow[5]) rec->sref.assign(dbrow[5], dblengths[5]); else rec->sref = "";
			if (dbrow[6]) rec->refBrlyMUsergroup = atoll((char*) dbrow[6]); else rec->refBrlyMUsergroup = 0;
			if (dbrow[7]) rec->ixVState = atol((char*) dbrow[7]); else rec->ixVState = 0;
			if (dbrow[8]) rec->ixBrlyVLocale = atol((char*) dbrow[8]); else rec->ixBrlyVLocale = 0;
			if (dbrow[9]) rec->ixBrlyVUserlevel = atol((char*) dbrow[9]); else rec->ixBrlyVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQUsrList::insertRec(
			BrlyQUsrList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMUsergroup,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixBrlyVLocale,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQUsrList::insertRst(
			ListBrlyQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsrList::updateRec(
			BrlyQUsrList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[4] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyMPerson,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->sref.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refBrlyMUsergroup,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVState,&(l[6]),&(n[6]),&(e[6])),
		bindUint(&rec->ixBrlyVLocale,&(l[7]),&(n[7]),&(e[7])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrList / stmtUpdateRec)\n");
};

void MyTblBrlyQUsrList::updateRst(
			ListBrlyQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsrList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQUsrList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQUsrList::loadRecByQref(
			ubigint qref
			, BrlyQUsrList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQUsrList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsrList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQUsrList
 ******************************************************************************/

PgTblBrlyQUsrList::PgTblBrlyQUsrList() : TblBrlyQUsrList(), PgTable() {
};

PgTblBrlyQUsrList::~PgTblBrlyQUsrList() {
};

void PgTblBrlyQUsrList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQUsrList_insertRec", "INSERT INTO TblBrlyQUsrList (jref, jnum, ref, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrList_updateRec", "UPDATE TblBrlyQUsrList SET jref = $1, jnum = $2, ref = $3, refBrlyMPerson = $4, sref = $5, refBrlyMUsergroup = $6, ixVState = $7, ixBrlyVLocale = $8, ixBrlyVUserlevel = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrList_removeRecByQref", "DELETE FROM TblBrlyQUsrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrList_removeRstByJref", "DELETE FROM TblBrlyQUsrList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQUsrList_loadRecByQref", "SELECT qref, jref, jnum, ref, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel FROM TblBrlyQUsrList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrList_loadRstByJref", "SELECT qref, jref, jnum, ref, refBrlyMPerson, sref, refBrlyMUsergroup, ixVState, ixBrlyVLocale, ixBrlyVUserlevel FROM TblBrlyQUsrList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQUsrList::loadRec(
			PGresult* res
			, BrlyQUsrList** rec
		) {
	char* ptr;

	BrlyQUsrList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsrList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixbrlyvlocale"),
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refBrlyMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refBrlyMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->ixBrlyVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->ixBrlyVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQUsrList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsrList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymperson"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refbrlymusergroup"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "ixbrlyvlocale"),
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		while (numread < numrow) {
			rec = new BrlyQUsrList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refBrlyMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refBrlyMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->ixBrlyVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->ixBrlyVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQUsrList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsrList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsrList::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQUsrList::insertRec(
			BrlyQUsrList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixBrlyVLocale = htonl(rec->ixBrlyVLocale);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refBrlyMPerson,
		rec->sref.c_str(),
		(char*) &_refBrlyMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixBrlyVLocale,
		(char*) &_ixBrlyVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsrList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQUsrList::insertRst(
			ListBrlyQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsrList::updateRec(
			BrlyQUsrList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refBrlyMPerson = htonl64(rec->refBrlyMPerson);
	ubigint _refBrlyMUsergroup = htonl64(rec->refBrlyMUsergroup);
	uint _ixVState = htonl(rec->ixVState);
	uint _ixBrlyVLocale = htonl(rec->ixBrlyVLocale);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refBrlyMPerson,
		rec->sref.c_str(),
		(char*) &_refBrlyMUsergroup,
		(char*) &_ixVState,
		(char*) &_ixBrlyVLocale,
		(char*) &_ixBrlyVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsrList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQUsrList::updateRst(
			ListBrlyQUsrList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsrList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQUsrList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQUsrList::loadRecByQref(
			ubigint qref
			, BrlyQUsrList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQUsrList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsrList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsrList_loadRstByJref", 1, vals, l, f, append, rst);
};

