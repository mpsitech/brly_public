/**
  * \file BrlyQRegList.cpp
  * Dbs and XML wrapper for table TblBrlyQRegList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQRegList.h"

/******************************************************************************
 class BrlyQRegList
 ******************************************************************************/

BrlyQRegList::BrlyQRegList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint supRefBrlyMRegion
			, const string stubSupRefBrlyMRegion
			, const uint ixVDst
			, const string srefIxVDst
			, const string titIxVDst
			, const double toffset
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->Title = Title;
	this->supRefBrlyMRegion = supRefBrlyMRegion;
	this->stubSupRefBrlyMRegion = stubSupRefBrlyMRegion;
	this->ixVDst = ixVDst;
	this->srefIxVDst = srefIxVDst;
	this->titIxVDst = titIxVDst;
	this->toffset = toffset;
};

void BrlyQRegList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQRegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "tit", Title);
		writeString(wr, "sup", stubSupRefBrlyMRegion);
		writeString(wr, "dst", srefIxVDst);
		writeString(wr, "dst2", titIxVDst);
		writeDouble(wr, "tof", toffset);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "Title", Title);
		writeString(wr, "stubSupRefBrlyMRegion", stubSupRefBrlyMRegion);
		writeString(wr, "srefIxVDst", srefIxVDst);
		writeString(wr, "titIxVDst", titIxVDst);
		writeDouble(wr, "toffset", toffset);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQRegList
 ******************************************************************************/

ListBrlyQRegList::ListBrlyQRegList() {
};

ListBrlyQRegList::ListBrlyQRegList(
			const ListBrlyQRegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQRegList(*(src.nodes[i]));
};

ListBrlyQRegList::~ListBrlyQRegList() {
	clear();
};

void ListBrlyQRegList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQRegList::size() const {
	return(nodes.size());
};

void ListBrlyQRegList::append(
			BrlyQRegList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQRegList& ListBrlyQRegList::operator=(
			const ListBrlyQRegList& src
		) {
	BrlyQRegList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQRegList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQRegList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQRegList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQRegList
 ******************************************************************************/

TblBrlyQRegList::TblBrlyQRegList() {
};

TblBrlyQRegList::~TblBrlyQRegList() {
};

bool TblBrlyQRegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegList** rec
		) {
	return false;
};

ubigint TblBrlyQRegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegList& rst
		) {
	return 0;
};

void TblBrlyQRegList::insertRec(
			BrlyQRegList* rec
		) {
};

ubigint TblBrlyQRegList::insertNewRec(
			BrlyQRegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint supRefBrlyMRegion
			, const string stubSupRefBrlyMRegion
			, const uint ixVDst
			, const string srefIxVDst
			, const string titIxVDst
			, const double toffset
		) {
	ubigint retval = 0;
	BrlyQRegList* _rec = NULL;

	_rec = new BrlyQRegList(0, jref, jnum, ref, sref, Title, supRefBrlyMRegion, stubSupRefBrlyMRegion, ixVDst, srefIxVDst, titIxVDst, toffset);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQRegList::appendNewRecToRst(
			ListBrlyQRegList& rst
			, BrlyQRegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string Title
			, const ubigint supRefBrlyMRegion
			, const string stubSupRefBrlyMRegion
			, const uint ixVDst
			, const string srefIxVDst
			, const string titIxVDst
			, const double toffset
		) {
	ubigint retval = 0;
	BrlyQRegList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, Title, supRefBrlyMRegion, stubSupRefBrlyMRegion, ixVDst, srefIxVDst, titIxVDst, toffset);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQRegList::insertRst(
			ListBrlyQRegList& rst
		) {
};

void TblBrlyQRegList::updateRec(
			BrlyQRegList* rec
		) {
};

void TblBrlyQRegList::updateRst(
			ListBrlyQRegList& rst
		) {
};

void TblBrlyQRegList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQRegList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQRegList::loadRecByQref(
			ubigint qref
			, BrlyQRegList** rec
		) {
	return false;
};

ubigint TblBrlyQRegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQRegList
 ******************************************************************************/

MyTblBrlyQRegList::MyTblBrlyQRegList() : TblBrlyQRegList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQRegList::~MyTblBrlyQRegList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQRegList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQRegList (jref, jnum, ref, sref, Title, supRefBrlyMRegion, ixVDst, toffset) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQRegList SET jref = ?, jnum = ?, ref = ?, sref = ?, Title = ?, supRefBrlyMRegion = ?, ixVDst = ?, toffset = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQRegList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQRegList WHERE jref = ?", false);
};

bool MyTblBrlyQRegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQRegList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQRegList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQRegList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->supRefBrlyMRegion = atoll((char*) dbrow[6]); else _rec->supRefBrlyMRegion = 0;
		if (dbrow[7]) _rec->ixVDst = atol((char*) dbrow[7]); else _rec->ixVDst = 0;
		if (dbrow[8]) _rec->toffset = atof((char*) dbrow[8]); else _rec->toffset = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQRegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQRegList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQRegList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQRegList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->supRefBrlyMRegion = atoll((char*) dbrow[6]); else rec->supRefBrlyMRegion = 0;
			if (dbrow[7]) rec->ixVDst = atol((char*) dbrow[7]); else rec->ixVDst = 0;
			if (dbrow[8]) rec->toffset = atof((char*) dbrow[8]); else rec->toffset = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQRegList::insertRec(
			BrlyQRegList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefBrlyMRegion,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDst,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->toffset,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRegList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRegList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQRegList::insertRst(
			ListBrlyQRegList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQRegList::updateRec(
			BrlyQRegList* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[3] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefBrlyMRegion,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDst,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->toffset,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->qref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRegList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRegList / stmtUpdateRec)\n");
};

void MyTblBrlyQRegList::updateRst(
			ListBrlyQRegList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQRegList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRegList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRegList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQRegList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQRegList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQRegList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQRegList::loadRecByQref(
			ubigint qref
			, BrlyQRegList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQRegList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQRegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQRegList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQRegList
 ******************************************************************************/

PgTblBrlyQRegList::PgTblBrlyQRegList() : TblBrlyQRegList(), PgTable() {
};

PgTblBrlyQRegList::~PgTblBrlyQRegList() {
};

void PgTblBrlyQRegList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQRegList_insertRec", "INSERT INTO TblBrlyQRegList (jref, jnum, ref, sref, Title, supRefBrlyMRegion, ixVDst, toffset) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING qref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRegList_updateRec", "UPDATE TblBrlyQRegList SET jref = $1, jnum = $2, ref = $3, sref = $4, Title = $5, supRefBrlyMRegion = $6, ixVDst = $7, toffset = $8 WHERE qref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRegList_removeRecByQref", "DELETE FROM TblBrlyQRegList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRegList_removeRstByJref", "DELETE FROM TblBrlyQRegList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQRegList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, Title, supRefBrlyMRegion, ixVDst, toffset FROM TblBrlyQRegList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQRegList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, Title, supRefBrlyMRegion, ixVDst, toffset FROM TblBrlyQRegList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQRegList::loadRec(
			PGresult* res
			, BrlyQRegList** rec
		) {
	char* ptr;

	BrlyQRegList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQRegList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "suprefbrlymregion"),
			PQfnumber(res, "ixvdst"),
			PQfnumber(res, "toffset")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->supRefBrlyMRegion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVDst = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->toffset = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQRegList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQRegList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQRegList* rec;

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
			PQfnumber(res, "title"),
			PQfnumber(res, "suprefbrlymregion"),
			PQfnumber(res, "ixvdst"),
			PQfnumber(res, "toffset")
		};

		while (numread < numrow) {
			rec = new BrlyQRegList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->supRefBrlyMRegion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVDst = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->toffset = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQRegList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQRegList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRegList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQRegList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQRegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQRegList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQRegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQRegList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQRegList::insertRec(
			BrlyQRegList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _supRefBrlyMRegion = htonl64(rec->supRefBrlyMRegion);
	uint _ixVDst = htonl(rec->ixVDst);
	string _toffset = to_string(rec->toffset);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_supRefBrlyMRegion,
		(char*) &_ixVDst,
		_toffset.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyQRegList_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQRegList::insertRst(
			ListBrlyQRegList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQRegList::updateRec(
			BrlyQRegList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _supRefBrlyMRegion = htonl64(rec->supRefBrlyMRegion);
	uint _ixVDst = htonl(rec->ixVDst);
	string _toffset = to_string(rec->toffset);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->Title.c_str(),
		(char*) &_supRefBrlyMRegion,
		(char*) &_ixVDst,
		_toffset.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQRegList_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQRegList::updateRst(
			ListBrlyQRegList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQRegList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRegList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQRegList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQRegList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQRegList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQRegList::loadRecByQref(
			ubigint qref
			, BrlyQRegList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQRegList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQRegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQRegList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQRegList_loadRstByJref", 1, vals, l, f, append, rst);
};

