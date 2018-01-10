/**
  * \file BrlyQLocProxOrgMNLocation.cpp
  * Dbs and XML wrapper for table TblBrlyQLocProxOrgMNLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLocProxOrgMNLocation.h"

/******************************************************************************
 class BrlyQLocProxOrgMNLocation
 ******************************************************************************/

BrlyQLocProxOrgMNLocation::BrlyQLocProxOrgMNLocation(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double deltaphi
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->deltaphi = deltaphi;
};

void BrlyQLocProxOrgMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocProxOrgMNLocation";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeDouble(wr, "dph", deltaphi);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeDouble(wr, "deltaphi", deltaphi);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLocProxOrgMNLocation
 ******************************************************************************/

ListBrlyQLocProxOrgMNLocation::ListBrlyQLocProxOrgMNLocation() {
};

ListBrlyQLocProxOrgMNLocation::ListBrlyQLocProxOrgMNLocation(
			const ListBrlyQLocProxOrgMNLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocProxOrgMNLocation(*(src.nodes[i]));
};

ListBrlyQLocProxOrgMNLocation::~ListBrlyQLocProxOrgMNLocation() {
	clear();
};

void ListBrlyQLocProxOrgMNLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocProxOrgMNLocation::size() const {
	return(nodes.size());
};

void ListBrlyQLocProxOrgMNLocation::append(
			BrlyQLocProxOrgMNLocation* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocProxOrgMNLocation& ListBrlyQLocProxOrgMNLocation::operator=(
			const ListBrlyQLocProxOrgMNLocation& src
		) {
	BrlyQLocProxOrgMNLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLocProxOrgMNLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocProxOrgMNLocation::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocProxOrgMNLocation";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocProxOrgMNLocation
 ******************************************************************************/

TblBrlyQLocProxOrgMNLocation::TblBrlyQLocProxOrgMNLocation() {
};

TblBrlyQLocProxOrgMNLocation::~TblBrlyQLocProxOrgMNLocation() {
};

bool TblBrlyQLocProxOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocProxOrgMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLocProxOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	return 0;
};

void TblBrlyQLocProxOrgMNLocation::insertRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
};

ubigint TblBrlyQLocProxOrgMNLocation::insertNewRec(
			BrlyQLocProxOrgMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double deltaphi
		) {
	ubigint retval = 0;
	BrlyQLocProxOrgMNLocation* _rec = NULL;

	_rec = new BrlyQLocProxOrgMNLocation(0, jref, jnum, mref, stubMref, ref, deltaphi);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocProxOrgMNLocation::appendNewRecToRst(
			ListBrlyQLocProxOrgMNLocation& rst
			, BrlyQLocProxOrgMNLocation** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const double deltaphi
		) {
	ubigint retval = 0;
	BrlyQLocProxOrgMNLocation* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, deltaphi);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocProxOrgMNLocation::insertRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
};

void TblBrlyQLocProxOrgMNLocation::updateRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
};

void TblBrlyQLocProxOrgMNLocation::updateRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
};

void TblBrlyQLocProxOrgMNLocation::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocProxOrgMNLocation::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocProxOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocProxOrgMNLocation** rec
		) {
	return false;
};

ubigint TblBrlyQLocProxOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLocProxOrgMNLocation
 ******************************************************************************/

MyTblBrlyQLocProxOrgMNLocation::MyTblBrlyQLocProxOrgMNLocation() : TblBrlyQLocProxOrgMNLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocProxOrgMNLocation::~MyTblBrlyQLocProxOrgMNLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocProxOrgMNLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocProxOrgMNLocation (jref, jnum, mref, ref, deltaphi) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocProxOrgMNLocation SET jref = ?, jnum = ?, mref = ?, ref = ?, deltaphi = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocProxOrgMNLocation WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocProxOrgMNLocation WHERE jref = ?", false);
};

bool MyTblBrlyQLocProxOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocProxOrgMNLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocProxOrgMNLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLocProxOrgMNLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQLocProxOrgMNLocation();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->deltaphi = atof((char*) dbrow[5]); else _rec->deltaphi = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLocProxOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocProxOrgMNLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLocProxOrgMNLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQLocProxOrgMNLocation();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->deltaphi = atof((char*) dbrow[5]); else rec->deltaphi = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQLocProxOrgMNLocation::insertRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->deltaphi,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocProxOrgMNLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocProxOrgMNLocation / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLocProxOrgMNLocation::insertRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocProxOrgMNLocation::updateRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindDouble(&rec->deltaphi,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocProxOrgMNLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocProxOrgMNLocation / stmtUpdateRec)\n");
};

void MyTblBrlyQLocProxOrgMNLocation::updateRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocProxOrgMNLocation::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocProxOrgMNLocation / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocProxOrgMNLocation / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLocProxOrgMNLocation::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocProxOrgMNLocation / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocProxOrgMNLocation / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLocProxOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocProxOrgMNLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLocProxOrgMNLocation WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocProxOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocProxOrgMNLocation WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLocProxOrgMNLocation
 ******************************************************************************/

PgTblBrlyQLocProxOrgMNLocation::PgTblBrlyQLocProxOrgMNLocation() : TblBrlyQLocProxOrgMNLocation(), PgTable() {
};

PgTblBrlyQLocProxOrgMNLocation::~PgTblBrlyQLocProxOrgMNLocation() {
};

void PgTblBrlyQLocProxOrgMNLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLocProxOrgMNLocation_insertRec", "INSERT INTO TblBrlyQLocProxOrgMNLocation (jref, jnum, mref, ref, deltaphi) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocProxOrgMNLocation_updateRec", "UPDATE TblBrlyQLocProxOrgMNLocation SET jref = $1, jnum = $2, mref = $3, ref = $4, deltaphi = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocProxOrgMNLocation_removeRecByQref", "DELETE FROM TblBrlyQLocProxOrgMNLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocProxOrgMNLocation_removeRstByJref", "DELETE FROM TblBrlyQLocProxOrgMNLocation WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLocProxOrgMNLocation_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, deltaphi FROM TblBrlyQLocProxOrgMNLocation WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocProxOrgMNLocation_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, deltaphi FROM TblBrlyQLocProxOrgMNLocation WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLocProxOrgMNLocation::loadRec(
			PGresult* res
			, BrlyQLocProxOrgMNLocation** rec
		) {
	char* ptr;

	BrlyQLocProxOrgMNLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocProxOrgMNLocation();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "deltaphi")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->deltaphi = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLocProxOrgMNLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocProxOrgMNLocation* rec;

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
			PQfnumber(res, "deltaphi")
		};

		while (numread < numrow) {
			rec = new BrlyQLocProxOrgMNLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->deltaphi = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLocProxOrgMNLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocProxOrgMNLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocProxOrgMNLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocProxOrgMNLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocProxOrgMNLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocProxOrgMNLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocProxOrgMNLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocProxOrgMNLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLocProxOrgMNLocation::insertRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	string _deltaphi = to_string(rec->deltaphi);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		_deltaphi.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLocProxOrgMNLocation_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocProxOrgMNLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLocProxOrgMNLocation::insertRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocProxOrgMNLocation::updateRec(
			BrlyQLocProxOrgMNLocation* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	string _deltaphi = to_string(rec->deltaphi);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		_deltaphi.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLocProxOrgMNLocation_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocProxOrgMNLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLocProxOrgMNLocation::updateRst(
			ListBrlyQLocProxOrgMNLocation& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocProxOrgMNLocation::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocProxOrgMNLocation_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocProxOrgMNLocation_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLocProxOrgMNLocation::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocProxOrgMNLocation_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocProxOrgMNLocation_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLocProxOrgMNLocation::loadRecByQref(
			ubigint qref
			, BrlyQLocProxOrgMNLocation** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLocProxOrgMNLocation_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocProxOrgMNLocation::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocProxOrgMNLocation& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocProxOrgMNLocation_loadRstByJref", 1, vals, l, f, append, rst);
};

