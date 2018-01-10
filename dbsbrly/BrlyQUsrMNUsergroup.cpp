/**
  * \file BrlyQUsrMNUsergroup.cpp
  * Dbs and XML wrapper for table TblBrlyQUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQUsrMNUsergroup.h"

/******************************************************************************
 class BrlyQUsrMNUsergroup
 ******************************************************************************/

BrlyQUsrMNUsergroup::BrlyQUsrMNUsergroup(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixBrlyVUserlevel = ixBrlyVUserlevel;
	this->srefIxBrlyVUserlevel = srefIxBrlyVUserlevel;
	this->titIxBrlyVUserlevel = titIxBrlyVUserlevel;
};

void BrlyQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQUsrMNUsergroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxBrlyVUserlevel);
		writeString(wr, "ulv2", titIxBrlyVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxBrlyVUserlevel", srefIxBrlyVUserlevel);
		writeString(wr, "titIxBrlyVUserlevel", titIxBrlyVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQUsrMNUsergroup
 ******************************************************************************/

ListBrlyQUsrMNUsergroup::ListBrlyQUsrMNUsergroup() {
};

ListBrlyQUsrMNUsergroup::ListBrlyQUsrMNUsergroup(
			const ListBrlyQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQUsrMNUsergroup(*(src.nodes[i]));
};

ListBrlyQUsrMNUsergroup::~ListBrlyQUsrMNUsergroup() {
	clear();
};

void ListBrlyQUsrMNUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQUsrMNUsergroup::size() const {
	return(nodes.size());
};

void ListBrlyQUsrMNUsergroup::append(
			BrlyQUsrMNUsergroup* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQUsrMNUsergroup& ListBrlyQUsrMNUsergroup::operator=(
			const ListBrlyQUsrMNUsergroup& src
		) {
	BrlyQUsrMNUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQUsrMNUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQUsrMNUsergroup";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQUsrMNUsergroup
 ******************************************************************************/

TblBrlyQUsrMNUsergroup::TblBrlyQUsrMNUsergroup() {
};

TblBrlyQUsrMNUsergroup::~TblBrlyQUsrMNUsergroup() {
};

bool TblBrlyQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblBrlyQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrMNUsergroup& rst
		) {
	return 0;
};

void TblBrlyQUsrMNUsergroup::insertRec(
			BrlyQUsrMNUsergroup* rec
		) {
};

ubigint TblBrlyQUsrMNUsergroup::insertNewRec(
			BrlyQUsrMNUsergroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyQUsrMNUsergroup* _rec = NULL;

	_rec = new BrlyQUsrMNUsergroup(0, jref, jnum, mref, stubMref, ref, ixBrlyVUserlevel, srefIxBrlyVUserlevel, titIxBrlyVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQUsrMNUsergroup::appendNewRecToRst(
			ListBrlyQUsrMNUsergroup& rst
			, BrlyQUsrMNUsergroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixBrlyVUserlevel
			, const string srefIxBrlyVUserlevel
			, const string titIxBrlyVUserlevel
		) {
	ubigint retval = 0;
	BrlyQUsrMNUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixBrlyVUserlevel, srefIxBrlyVUserlevel, titIxBrlyVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQUsrMNUsergroup::insertRst(
			ListBrlyQUsrMNUsergroup& rst
		) {
};

void TblBrlyQUsrMNUsergroup::updateRec(
			BrlyQUsrMNUsergroup* rec
		) {
};

void TblBrlyQUsrMNUsergroup::updateRst(
			ListBrlyQUsrMNUsergroup& rst
		) {
};

void TblBrlyQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, BrlyQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblBrlyQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrMNUsergroup& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQUsrMNUsergroup
 ******************************************************************************/

MyTblBrlyQUsrMNUsergroup::MyTblBrlyQUsrMNUsergroup() : TblBrlyQUsrMNUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQUsrMNUsergroup::~MyTblBrlyQUsrMNUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQUsrMNUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQUsrMNUsergroup (jref, jnum, mref, ref, ixBrlyVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQUsrMNUsergroup SET jref = ?, jnum = ?, mref = ?, ref = ?, ixBrlyVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQUsrMNUsergroup WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQUsrMNUsergroup WHERE jref = ?", false);
};

bool MyTblBrlyQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrMNUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQUsrMNUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQUsrMNUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQUsrMNUsergroup();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixBrlyVUserlevel = atol((char*) dbrow[5]); else _rec->ixBrlyVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrMNUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQUsrMNUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQUsrMNUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQUsrMNUsergroup();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixBrlyVUserlevel = atol((char*) dbrow[5]); else rec->ixBrlyVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQUsrMNUsergroup::insertRec(
			BrlyQUsrMNUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrMNUsergroup / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrMNUsergroup / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQUsrMNUsergroup::insertRst(
			ListBrlyQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQUsrMNUsergroup::updateRec(
			BrlyQUsrMNUsergroup* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixBrlyVUserlevel,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrMNUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrMNUsergroup / stmtUpdateRec)\n");
};

void MyTblBrlyQUsrMNUsergroup::updateRst(
			ListBrlyQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrMNUsergroup / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrMNUsergroup / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQUsrMNUsergroup / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQUsrMNUsergroup / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, BrlyQUsrMNUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQUsrMNUsergroup WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrMNUsergroup& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQUsrMNUsergroup WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQUsrMNUsergroup
 ******************************************************************************/

PgTblBrlyQUsrMNUsergroup::PgTblBrlyQUsrMNUsergroup() : TblBrlyQUsrMNUsergroup(), PgTable() {
};

PgTblBrlyQUsrMNUsergroup::~PgTblBrlyQUsrMNUsergroup() {
};

void PgTblBrlyQUsrMNUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQUsrMNUsergroup_insertRec", "INSERT INTO TblBrlyQUsrMNUsergroup (jref, jnum, mref, ref, ixBrlyVUserlevel) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrMNUsergroup_updateRec", "UPDATE TblBrlyQUsrMNUsergroup SET jref = $1, jnum = $2, mref = $3, ref = $4, ixBrlyVUserlevel = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrMNUsergroup_removeRecByQref", "DELETE FROM TblBrlyQUsrMNUsergroup WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrMNUsergroup_removeRstByJref", "DELETE FROM TblBrlyQUsrMNUsergroup WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQUsrMNUsergroup_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixBrlyVUserlevel FROM TblBrlyQUsrMNUsergroup WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQUsrMNUsergroup_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixBrlyVUserlevel FROM TblBrlyQUsrMNUsergroup WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQUsrMNUsergroup::loadRec(
			PGresult* res
			, BrlyQUsrMNUsergroup** rec
		) {
	char* ptr;

	BrlyQUsrMNUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQUsrMNUsergroup();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixBrlyVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQUsrMNUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQUsrMNUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQUsrMNUsergroup* rec;

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
			PQfnumber(res, "ixbrlyvuserlevel")
		};

		while (numread < numrow) {
			rec = new BrlyQUsrMNUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixBrlyVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQUsrMNUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrMNUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrMNUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrMNUsergroup / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, BrlyQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQUsrMNUsergroup::insertRec(
			BrlyQUsrMNUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixBrlyVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsrMNUsergroup_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrMNUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQUsrMNUsergroup::insertRst(
			ListBrlyQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQUsrMNUsergroup::updateRec(
			BrlyQUsrMNUsergroup* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixBrlyVUserlevel = htonl(rec->ixBrlyVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixBrlyVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQUsrMNUsergroup_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrMNUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQUsrMNUsergroup::updateRst(
			ListBrlyQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQUsrMNUsergroup::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrMNUsergroup_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrMNUsergroup_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQUsrMNUsergroup::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQUsrMNUsergroup_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQUsrMNUsergroup_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, BrlyQUsrMNUsergroup** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQUsrMNUsergroup_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQUsrMNUsergroup& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQUsrMNUsergroup_loadRstByJref", 1, vals, l, f, append, rst);
};

