/**
  * \file BrlyQLegList.cpp
  * Dbs and XML wrapper for table TblBrlyQLegList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLegList.h"

/******************************************************************************
 class BrlyQLegList
 ******************************************************************************/

BrlyQLegList::BrlyQLegList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint bgnRefBrlyMLocation
			, const string stubBgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const string stubEndRefBrlyMLocation
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const double alt
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->bgnRefBrlyMLocation = bgnRefBrlyMLocation;
	this->stubBgnRefBrlyMLocation = stubBgnRefBrlyMLocation;
	this->endRefBrlyMLocation = endRefBrlyMLocation;
	this->stubEndRefBrlyMLocation = stubEndRefBrlyMLocation;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->alt = alt;
};

void BrlyQLegList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLegList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "blo", stubBgnRefBrlyMLocation);
		writeString(wr, "elo", stubEndRefBrlyMLocation);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeDouble(wr, "alt", alt);
	} else {
		writeString(wr, "stubBgnRefBrlyMLocation", stubBgnRefBrlyMLocation);
		writeString(wr, "stubEndRefBrlyMLocation", stubEndRefBrlyMLocation);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeDouble(wr, "alt", alt);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLegList
 ******************************************************************************/

ListBrlyQLegList::ListBrlyQLegList() {
};

ListBrlyQLegList::ListBrlyQLegList(
			const ListBrlyQLegList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLegList(*(src.nodes[i]));
};

ListBrlyQLegList::~ListBrlyQLegList() {
	clear();
};

void ListBrlyQLegList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLegList::size() const {
	return(nodes.size());
};

void ListBrlyQLegList::append(
			BrlyQLegList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLegList& ListBrlyQLegList::operator=(
			const ListBrlyQLegList& src
		) {
	BrlyQLegList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLegList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLegList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLegList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLegList
 ******************************************************************************/

TblBrlyQLegList::TblBrlyQLegList() {
};

TblBrlyQLegList::~TblBrlyQLegList() {
};

bool TblBrlyQLegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegList** rec
		) {
	return false;
};

ubigint TblBrlyQLegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegList& rst
		) {
	return 0;
};

void TblBrlyQLegList::insertRec(
			BrlyQLegList* rec
		) {
};

ubigint TblBrlyQLegList::insertNewRec(
			BrlyQLegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint bgnRefBrlyMLocation
			, const string stubBgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const string stubEndRefBrlyMLocation
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const double alt
		) {
	ubigint retval = 0;
	BrlyQLegList* _rec = NULL;

	_rec = new BrlyQLegList(0, jref, jnum, ref, bgnRefBrlyMLocation, stubBgnRefBrlyMLocation, endRefBrlyMLocation, stubEndRefBrlyMLocation, ixVBasetype, srefIxVBasetype, titIxVBasetype, alt);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLegList::appendNewRecToRst(
			ListBrlyQLegList& rst
			, BrlyQLegList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint bgnRefBrlyMLocation
			, const string stubBgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const string stubEndRefBrlyMLocation
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const double alt
		) {
	ubigint retval = 0;
	BrlyQLegList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, bgnRefBrlyMLocation, stubBgnRefBrlyMLocation, endRefBrlyMLocation, stubEndRefBrlyMLocation, ixVBasetype, srefIxVBasetype, titIxVBasetype, alt);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLegList::insertRst(
			ListBrlyQLegList& rst
		) {
};

void TblBrlyQLegList::updateRec(
			BrlyQLegList* rec
		) {
};

void TblBrlyQLegList::updateRst(
			ListBrlyQLegList& rst
		) {
};

void TblBrlyQLegList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLegList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLegList::loadRecByQref(
			ubigint qref
			, BrlyQLegList** rec
		) {
	return false;
};

ubigint TblBrlyQLegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLegList
 ******************************************************************************/

MyTblBrlyQLegList::MyTblBrlyQLegList() : TblBrlyQLegList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLegList::~MyTblBrlyQLegList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLegList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLegList (jref, jnum, ref, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLegList SET jref = ?, jnum = ?, ref = ?, bgnRefBrlyMLocation = ?, endRefBrlyMLocation = ?, ixVBasetype = ?, alt = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLegList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLegList WHERE jref = ?", false);
};

bool MyTblBrlyQLegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLegList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLegList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLegList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->bgnRefBrlyMLocation = atoll((char*) dbrow[4]); else _rec->bgnRefBrlyMLocation = 0;
		if (dbrow[5]) _rec->endRefBrlyMLocation = atoll((char*) dbrow[5]); else _rec->endRefBrlyMLocation = 0;
		if (dbrow[6]) _rec->ixVBasetype = atol((char*) dbrow[6]); else _rec->ixVBasetype = 0;
		if (dbrow[7]) _rec->alt = atof((char*) dbrow[7]); else _rec->alt = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLegList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLegList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLegList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->bgnRefBrlyMLocation = atoll((char*) dbrow[4]); else rec->bgnRefBrlyMLocation = 0;
			if (dbrow[5]) rec->endRefBrlyMLocation = atoll((char*) dbrow[5]); else rec->endRefBrlyMLocation = 0;
			if (dbrow[6]) rec->ixVBasetype = atol((char*) dbrow[6]); else rec->ixVBasetype = 0;
			if (dbrow[7]) rec->alt = atof((char*) dbrow[7]); else rec->alt = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQLegList::insertRec(
			BrlyQLegList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->bgnRefBrlyMLocation,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->endRefBrlyMLocation,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->alt,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLegList::insertRst(
			ListBrlyQLegList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLegList::updateRec(
			BrlyQLegList* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->bgnRefBrlyMLocation,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->endRefBrlyMLocation,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVBasetype,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->alt,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegList / stmtUpdateRec)\n");
};

void MyTblBrlyQLegList::updateRst(
			ListBrlyQLegList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLegList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLegList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLegList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLegList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLegList::loadRecByQref(
			ubigint qref
			, BrlyQLegList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLegList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLegList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLegList
 ******************************************************************************/

PgTblBrlyQLegList::PgTblBrlyQLegList() : TblBrlyQLegList(), PgTable() {
};

PgTblBrlyQLegList::~PgTblBrlyQLegList() {
};

void PgTblBrlyQLegList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLegList_insertRec", "INSERT INTO TblBrlyQLegList (jref, jnum, ref, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegList_updateRec", "UPDATE TblBrlyQLegList SET jref = $1, jnum = $2, ref = $3, bgnRefBrlyMLocation = $4, endRefBrlyMLocation = $5, ixVBasetype = $6, alt = $7 WHERE qref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegList_removeRecByQref", "DELETE FROM TblBrlyQLegList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegList_removeRstByJref", "DELETE FROM TblBrlyQLegList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLegList_loadRecByQref", "SELECT qref, jref, jnum, ref, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt FROM TblBrlyQLegList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLegList_loadRstByJref", "SELECT qref, jref, jnum, ref, bgnRefBrlyMLocation, endRefBrlyMLocation, ixVBasetype, alt FROM TblBrlyQLegList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLegList::loadRec(
			PGresult* res
			, BrlyQLegList** rec
		) {
	char* ptr;

	BrlyQLegList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLegList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "bgnrefbrlymlocation"),
			PQfnumber(res, "endrefbrlymlocation"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "alt")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->bgnRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->endRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->alt = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLegList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLegList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLegList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "bgnrefbrlymlocation"),
			PQfnumber(res, "endrefbrlymlocation"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "alt")
		};

		while (numread < numrow) {
			rec = new BrlyQLegList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->bgnRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->endRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->alt = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLegList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLegList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLegList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLegList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLegList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLegList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLegList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLegList::insertRec(
			BrlyQLegList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _bgnRefBrlyMLocation = htonl64(rec->bgnRefBrlyMLocation);
	ubigint _endRefBrlyMLocation = htonl64(rec->endRefBrlyMLocation);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	string _alt = to_string(rec->alt);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_bgnRefBrlyMLocation,
		(char*) &_endRefBrlyMLocation,
		(char*) &_ixVBasetype,
		_alt.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLegList_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLegList::insertRst(
			ListBrlyQLegList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLegList::updateRec(
			BrlyQLegList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _bgnRefBrlyMLocation = htonl64(rec->bgnRefBrlyMLocation);
	ubigint _endRefBrlyMLocation = htonl64(rec->endRefBrlyMLocation);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	string _alt = to_string(rec->alt);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_bgnRefBrlyMLocation,
		(char*) &_endRefBrlyMLocation,
		(char*) &_ixVBasetype,
		_alt.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLegList_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLegList::updateRst(
			ListBrlyQLegList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLegList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLegList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLegList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLegList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLegList::loadRecByQref(
			ubigint qref
			, BrlyQLegList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLegList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLegList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLegList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLegList_loadRstByJref", 1, vals, l, f, append, rst);
};

