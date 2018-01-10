/**
  * \file BrlyQFilList.cpp
  * Dbs and XML wrapper for table TblBrlyQFilList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQFilList.h"

/******************************************************************************
 class BrlyQFilList
 ******************************************************************************/

BrlyQFilList::BrlyQFilList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const usmallint Size
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Filename = Filename;
	this->refIxVTbl = refIxVTbl;
	this->srefRefIxVTbl = srefRefIxVTbl;
	this->titRefIxVTbl = titRefIxVTbl;
	this->refUref = refUref;
	this->stubRefUref = stubRefUref;
	this->osrefKContent = osrefKContent;
	this->titOsrefKContent = titOsrefKContent;
	this->srefKMimetype = srefKMimetype;
	this->titSrefKMimetype = titSrefKMimetype;
	this->Size = Size;
};

void BrlyQFilList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQFilList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fnm", Filename);
		writeString(wr, "ret", srefRefIxVTbl);
		writeString(wr, "ret2", titRefIxVTbl);
		writeString(wr, "reu", stubRefUref);
		writeString(wr, "cnt", osrefKContent);
		writeString(wr, "cnt2", titOsrefKContent);
		writeString(wr, "mim", srefKMimetype);
		writeString(wr, "mim2", titSrefKMimetype);
		writeUint(wr, "siz", Size);
	} else {
		writeString(wr, "Filename", Filename);
		writeString(wr, "srefRefIxVTbl", srefRefIxVTbl);
		writeString(wr, "titRefIxVTbl", titRefIxVTbl);
		writeString(wr, "stubRefUref", stubRefUref);
		writeString(wr, "osrefKContent", osrefKContent);
		writeString(wr, "titOsrefKContent", titOsrefKContent);
		writeString(wr, "srefKMimetype", srefKMimetype);
		writeString(wr, "titSrefKMimetype", titSrefKMimetype);
		writeUint(wr, "Size", Size);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQFilList
 ******************************************************************************/

ListBrlyQFilList::ListBrlyQFilList() {
};

ListBrlyQFilList::ListBrlyQFilList(
			const ListBrlyQFilList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQFilList(*(src.nodes[i]));
};

ListBrlyQFilList::~ListBrlyQFilList() {
	clear();
};

void ListBrlyQFilList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQFilList::size() const {
	return(nodes.size());
};

void ListBrlyQFilList::append(
			BrlyQFilList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQFilList& ListBrlyQFilList::operator=(
			const ListBrlyQFilList& src
		) {
	BrlyQFilList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQFilList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQFilList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQFilList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQFilList
 ******************************************************************************/

TblBrlyQFilList::TblBrlyQFilList() {
};

TblBrlyQFilList::~TblBrlyQFilList() {
};

bool TblBrlyQFilList::loadRecBySQL(
			const string& sqlstr
			, BrlyQFilList** rec
		) {
	return false;
};

ubigint TblBrlyQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFilList& rst
		) {
	return 0;
};

void TblBrlyQFilList::insertRec(
			BrlyQFilList* rec
		) {
};

ubigint TblBrlyQFilList::insertNewRec(
			BrlyQFilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const usmallint Size
		) {
	ubigint retval = 0;
	BrlyQFilList* _rec = NULL;

	_rec = new BrlyQFilList(0, jref, jnum, ref, Filename, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, osrefKContent, titOsrefKContent, srefKMimetype, titSrefKMimetype, Size);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQFilList::appendNewRecToRst(
			ListBrlyQFilList& rst
			, BrlyQFilList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Filename
			, const uint refIxVTbl
			, const string srefRefIxVTbl
			, const string titRefIxVTbl
			, const ubigint refUref
			, const string stubRefUref
			, const string osrefKContent
			, const string titOsrefKContent
			, const string srefKMimetype
			, const string titSrefKMimetype
			, const usmallint Size
		) {
	ubigint retval = 0;
	BrlyQFilList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Filename, refIxVTbl, srefRefIxVTbl, titRefIxVTbl, refUref, stubRefUref, osrefKContent, titOsrefKContent, srefKMimetype, titSrefKMimetype, Size);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQFilList::insertRst(
			ListBrlyQFilList& rst
		) {
};

void TblBrlyQFilList::updateRec(
			BrlyQFilList* rec
		) {
};

void TblBrlyQFilList::updateRst(
			ListBrlyQFilList& rst
		) {
};

void TblBrlyQFilList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQFilList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQFilList::loadRecByQref(
			ubigint qref
			, BrlyQFilList** rec
		) {
	return false;
};

ubigint TblBrlyQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFilList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQFilList
 ******************************************************************************/

MyTblBrlyQFilList::MyTblBrlyQFilList() : TblBrlyQFilList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQFilList::~MyTblBrlyQFilList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQFilList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQFilList (jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size) VALUES (?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQFilList SET jref = ?, jnum = ?, ref = ?, Filename = ?, refIxVTbl = ?, refUref = ?, osrefKContent = ?, srefKMimetype = ?, Size = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQFilList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQFilList WHERE jref = ?", false);
};

bool MyTblBrlyQFilList::loadRecBySQL(
			const string& sqlstr
			, BrlyQFilList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQFilList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFilList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQFilList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Filename.assign(dbrow[4], dblengths[4]); else _rec->Filename = "";
		if (dbrow[5]) _rec->refIxVTbl = atol((char*) dbrow[5]); else _rec->refIxVTbl = 0;
		if (dbrow[6]) _rec->refUref = atoll((char*) dbrow[6]); else _rec->refUref = 0;
		if (dbrow[7]) _rec->osrefKContent.assign(dbrow[7], dblengths[7]); else _rec->osrefKContent = "";
		if (dbrow[8]) _rec->srefKMimetype.assign(dbrow[8], dblengths[8]); else _rec->srefKMimetype = "";
		if (dbrow[9]) _rec->Size = atoi((char*) dbrow[9]); else _rec->Size = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFilList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQFilList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQFilList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQFilList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Filename.assign(dbrow[4], dblengths[4]); else rec->Filename = "";
			if (dbrow[5]) rec->refIxVTbl = atol((char*) dbrow[5]); else rec->refIxVTbl = 0;
			if (dbrow[6]) rec->refUref = atoll((char*) dbrow[6]); else rec->refUref = 0;
			if (dbrow[7]) rec->osrefKContent.assign(dbrow[7], dblengths[7]); else rec->osrefKContent = "";
			if (dbrow[8]) rec->srefKMimetype.assign(dbrow[8], dblengths[8]); else rec->srefKMimetype = "";
			if (dbrow[9]) rec->Size = atoi((char*) dbrow[9]); else rec->Size = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQFilList::insertRec(
			BrlyQFilList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->Filename.length();
	l[6] = rec->osrefKContent.length();
	l[7] = rec->srefKMimetype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Size,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFilList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFilList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQFilList::insertRst(
			ListBrlyQFilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQFilList::updateRec(
			BrlyQFilList* rec
		) {
	unsigned long l[10]; my_bool n[10]; my_bool e[10];

	l[3] = rec->Filename.length();
	l[6] = rec->osrefKContent.length();
	l[7] = rec->srefKMimetype.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->refIxVTbl,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refUref,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUsmallint(&rec->Size,&(l[8]),&(n[8]),&(e[8])),
		bindUbigint(&rec->qref,&(l[9]),&(n[9]),&(e[9]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFilList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFilList / stmtUpdateRec)\n");
};

void MyTblBrlyQFilList::updateRst(
			ListBrlyQFilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQFilList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFilList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFilList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQFilList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQFilList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQFilList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQFilList::loadRecByQref(
			ubigint qref
			, BrlyQFilList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQFilList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFilList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQFilList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQFilList
 ******************************************************************************/

PgTblBrlyQFilList::PgTblBrlyQFilList() : TblBrlyQFilList(), PgTable() {
};

PgTblBrlyQFilList::~PgTblBrlyQFilList() {
};

void PgTblBrlyQFilList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQFilList_insertRec", "INSERT INTO TblBrlyQFilList (jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9) RETURNING qref", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFilList_updateRec", "UPDATE TblBrlyQFilList SET jref = $1, jnum = $2, ref = $3, Filename = $4, refIxVTbl = $5, refUref = $6, osrefKContent = $7, srefKMimetype = $8, Size = $9 WHERE qref = $10", 10, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFilList_removeRecByQref", "DELETE FROM TblBrlyQFilList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFilList_removeRstByJref", "DELETE FROM TblBrlyQFilList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQFilList_loadRecByQref", "SELECT qref, jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size FROM TblBrlyQFilList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQFilList_loadRstByJref", "SELECT qref, jref, jnum, ref, Filename, refIxVTbl, refUref, osrefKContent, srefKMimetype, Size FROM TblBrlyQFilList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQFilList::loadRec(
			PGresult* res
			, BrlyQFilList** rec
		) {
	char* ptr;

	BrlyQFilList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQFilList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Filename.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->osrefKContent.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->srefKMimetype.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Size = atoi(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQFilList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQFilList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQFilList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size")
		};

		while (numread < numrow) {
			rec = new BrlyQFilList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Filename.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->osrefKContent.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->srefKMimetype.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Size = atoi(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQFilList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQFilList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFilList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFilList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQFilList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFilList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQFilList::loadRecBySQL(
			const string& sqlstr
			, BrlyQFilList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQFilList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQFilList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQFilList::insertRec(
			BrlyQFilList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	usmallint _Size = htons(rec->Size);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Filename.c_str(),
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(usmallint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFilList_insertRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFilList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQFilList::insertRst(
			ListBrlyQFilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQFilList::updateRec(
			BrlyQFilList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	usmallint _Size = htons(rec->Size);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Filename.c_str(),
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(usmallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQFilList_updateRec", 10, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFilList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQFilList::updateRst(
			ListBrlyQFilList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQFilList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFilList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFilList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQFilList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQFilList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQFilList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQFilList::loadRecByQref(
			ubigint qref
			, BrlyQFilList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQFilList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQFilList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQFilList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQFilList_loadRstByJref", 1, vals, l, f, append, rst);
};

