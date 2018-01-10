/**
  * \file BrlyAVKeylistKey.cpp
  * database access for table TblBrlyAVKeylistKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyAVKeylistKey.h"

/******************************************************************************
 class BrlyAVKeylistKey
 ******************************************************************************/

BrlyAVKeylistKey::BrlyAVKeylistKey(
			const ubigint ref
			, const uint klsIxBrlyVKeylist
			, const uint klsNum
			, const uint x1IxBrlyVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->klsIxBrlyVKeylist = klsIxBrlyVKeylist;
	this->klsNum = klsNum;
	this->x1IxBrlyVMaintable = x1IxBrlyVMaintable;
	this->x1Uref = x1Uref;
	this->Fixed = Fixed;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->refJ = refJ;
	this->Title = Title;
	this->Comment = Comment;
};

bool BrlyAVKeylistKey::operator==(
			const BrlyAVKeylistKey& comp
		) {
	return false;
};

bool BrlyAVKeylistKey::operator!=(
			const BrlyAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyAVKeylistKey
 ******************************************************************************/

ListBrlyAVKeylistKey::ListBrlyAVKeylistKey() {
};

ListBrlyAVKeylistKey::ListBrlyAVKeylistKey(
			const ListBrlyAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyAVKeylistKey(*(src.nodes[i]));
};

ListBrlyAVKeylistKey::~ListBrlyAVKeylistKey() {
	clear();
};

void ListBrlyAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyAVKeylistKey::size() const {
	return(nodes.size());
};

void ListBrlyAVKeylistKey::append(
			BrlyAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

BrlyAVKeylistKey* ListBrlyAVKeylistKey::operator[](
			const uint ix
		) {
	BrlyAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyAVKeylistKey& ListBrlyAVKeylistKey::operator=(
			const ListBrlyAVKeylistKey& src
		) {
	BrlyAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyAVKeylistKey::operator==(
			const ListBrlyAVKeylistKey& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListBrlyAVKeylistKey::operator!=(
			const ListBrlyAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyAVKeylistKey
 ******************************************************************************/

TblBrlyAVKeylistKey::TblBrlyAVKeylistKey() {
};

TblBrlyAVKeylistKey::~TblBrlyAVKeylistKey() {
};

bool TblBrlyAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, BrlyAVKeylistKey** rec
		) {
	return false;
};

ubigint TblBrlyAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	return 0;
};

void TblBrlyAVKeylistKey::insertRec(
			BrlyAVKeylistKey* rec
		) {
};

ubigint TblBrlyAVKeylistKey::insertNewRec(
			BrlyAVKeylistKey** rec
			, const uint klsIxBrlyVKeylist
			, const uint klsNum
			, const uint x1IxBrlyVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyAVKeylistKey* _rec = NULL;

	_rec = new BrlyAVKeylistKey(0, klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyAVKeylistKey::appendNewRecToRst(
			ListBrlyAVKeylistKey& rst
			, BrlyAVKeylistKey** rec
			, const uint klsIxBrlyVKeylist
			, const uint klsNum
			, const uint x1IxBrlyVMaintable
			, const ubigint x1Uref
			, const bool Fixed
			, const string sref
			, const string Avail
			, const string Implied
			, const ubigint refJ
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyAVKeylistKey::insertRst(
			ListBrlyAVKeylistKey& rst
			, bool transact
		) {
};

void TblBrlyAVKeylistKey::updateRec(
			BrlyAVKeylistKey* rec
		) {
};

void TblBrlyAVKeylistKey::updateRst(
			ListBrlyAVKeylistKey& rst
			, bool transact
		) {
};

void TblBrlyAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyAVKeylistKey::loadRecByRef(
			ubigint ref
			, BrlyAVKeylistKey** rec
		) {
	return false;
};

bool TblBrlyAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxBrlyVKeylist
			, uint x1IxBrlyVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return false;
};

bool TblBrlyAVKeylistKey::loadRefByKlsSrf(
			uint klsIxBrlyVKeylist
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblBrlyAVKeylistKey::loadRstByKls(
			uint klsIxBrlyVKeylist
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	return 0;
};

ubigint TblBrlyAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxBrlyVKeylist
			, uint x1IxBrlyVMaintable
			, ubigint x1Uref
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	return 0;
};

bool TblBrlyAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblBrlyAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	ubigint numload = 0;
	BrlyAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyAVKeylistKey
 ******************************************************************************/

MyTblBrlyAVKeylistKey::MyTblBrlyAVKeylistKey() : TblBrlyAVKeylistKey(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyAVKeylistKey::~MyTblBrlyAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyAVKeylistKey (klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyAVKeylistKey SET klsIxBrlyVKeylist = ?, klsNum = ?, x1IxBrlyVMaintable = ?, x1Uref = ?, Fixed = ?, sref = ?, Avail = ?, Implied = ?, refJ = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyAVKeylistKey WHERE ref = ?", false);
};

bool MyTblBrlyAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, BrlyAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAVKeylistKey / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->klsIxBrlyVKeylist = atol((char*) dbrow[1]); else _rec->klsIxBrlyVKeylist = 0;
		if (dbrow[2]) _rec->klsNum = atol((char*) dbrow[2]); else _rec->klsNum = 0;
		if (dbrow[3]) _rec->x1IxBrlyVMaintable = atol((char*) dbrow[3]); else _rec->x1IxBrlyVMaintable = 0;
		if (dbrow[4]) _rec->x1Uref = atoll((char*) dbrow[4]); else _rec->x1Uref = 0;
		if (dbrow[5]) _rec->Fixed = (atoi((char*) dbrow[5]) != 0); else _rec->Fixed = false;
		if (dbrow[6]) _rec->sref.assign(dbrow[6], dblengths[6]); else _rec->sref = "";
		if (dbrow[7]) _rec->Avail.assign(dbrow[7], dblengths[7]); else _rec->Avail = "";
		if (dbrow[8]) _rec->Implied.assign(dbrow[8], dblengths[8]); else _rec->Implied = "";
		if (dbrow[9]) _rec->refJ = atoll((char*) dbrow[9]); else _rec->refJ = 0;
		if (dbrow[10]) _rec->Title.assign(dbrow[10], dblengths[10]); else _rec->Title = "";
		if (dbrow[11]) _rec->Comment.assign(dbrow[11], dblengths[11]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyAVKeylistKey / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->klsIxBrlyVKeylist = atol((char*) dbrow[1]); else rec->klsIxBrlyVKeylist = 0;
			if (dbrow[2]) rec->klsNum = atol((char*) dbrow[2]); else rec->klsNum = 0;
			if (dbrow[3]) rec->x1IxBrlyVMaintable = atol((char*) dbrow[3]); else rec->x1IxBrlyVMaintable = 0;
			if (dbrow[4]) rec->x1Uref = atoll((char*) dbrow[4]); else rec->x1Uref = 0;
			if (dbrow[5]) rec->Fixed = (atoi((char*) dbrow[5]) != 0); else rec->Fixed = false;
			if (dbrow[6]) rec->sref.assign(dbrow[6], dblengths[6]); else rec->sref = "";
			if (dbrow[7]) rec->Avail.assign(dbrow[7], dblengths[7]); else rec->Avail = "";
			if (dbrow[8]) rec->Implied.assign(dbrow[8], dblengths[8]); else rec->Implied = "";
			if (dbrow[9]) rec->refJ = atoll((char*) dbrow[9]); else rec->refJ = 0;
			if (dbrow[10]) rec->Title.assign(dbrow[10], dblengths[10]); else rec->Title = "";
			if (dbrow[11]) rec->Comment.assign(dbrow[11], dblengths[11]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyAVKeylistKey::insertRec(
			BrlyAVKeylistKey* rec
		) {
	unsigned long l[11]; my_bool n[11]; my_bool e[11];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxBrlyVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxBrlyVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVKeylistKey / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVKeylistKey / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyAVKeylistKey::insertRst(
			ListBrlyAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyAVKeylistKey::updateRec(
			BrlyAVKeylistKey* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	tinyint Fixed = rec->Fixed;
	l[5] = rec->sref.length();
	l[6] = rec->Avail.length();
	l[7] = rec->Implied.length();
	l[9] = rec->Title.length();
	l[10] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->klsIxBrlyVKeylist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->klsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxBrlyVMaintable,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1Uref,&(l[3]),&(n[3]),&(e[3])),
		bindTinyint(&Fixed,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->sref.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Avail.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Implied.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refJ,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Title.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindUbigint(&rec->ref,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVKeylistKey / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVKeylistKey / stmtUpdateRec)\n");
};

void MyTblBrlyAVKeylistKey::updateRst(
			ListBrlyAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyAVKeylistKey / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyAVKeylistKey / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyAVKeylistKey::loadRecByRef(
			ubigint ref
			, BrlyAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxBrlyVKeylist
			, uint x1IxBrlyVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = " + to_string(klsIxBrlyVKeylist) + " AND x1IxBrlyVMaintable = " + to_string(x1IxBrlyVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " AND sref = '" + sref + "'", ref);
};

bool MyTblBrlyAVKeylistKey::loadRefByKlsSrf(
			uint klsIxBrlyVKeylist
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = " + to_string(klsIxBrlyVKeylist) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblBrlyAVKeylistKey::loadRstByKls(
			uint klsIxBrlyVKeylist
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = " + to_string(klsIxBrlyVKeylist) + " ORDER BY klsNum ASC", append, rst);
};

ubigint MyTblBrlyAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxBrlyVKeylist
			, uint x1IxBrlyVMaintable
			, ubigint x1Uref
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = " + to_string(klsIxBrlyVKeylist) + " AND x1IxBrlyVMaintable = " + to_string(x1IxBrlyVMaintable) + " AND x1Uref = " + to_string(x1Uref) + " ORDER BY klsNum ASC", append, rst);
};

bool MyTblBrlyAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblBrlyAVKeylistKey WHERE ref = " + to_string(ref) + "", Title);
};

/******************************************************************************
 class PgTblBrlyAVKeylistKey
 ******************************************************************************/

PgTblBrlyAVKeylistKey::PgTblBrlyAVKeylistKey() : TblBrlyAVKeylistKey(), PgTable() {
};

PgTblBrlyAVKeylistKey::~PgTblBrlyAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyAVKeylistKey::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyAVKeylistKey_insertRec", "INSERT INTO TblBrlyAVKeylistKey (klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11) RETURNING ref", 11, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVKeylistKey_updateRec", "UPDATE TblBrlyAVKeylistKey SET klsIxBrlyVKeylist = $1, klsNum = $2, x1IxBrlyVMaintable = $3, x1Uref = $4, Fixed = $5, sref = $6, Avail = $7, Implied = $8, refJ = $9, Title = $10, Comment = $11 WHERE ref = $12", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVKeylistKey_removeRecByRef", "DELETE FROM TblBrlyAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyAVKeylistKey_loadRecByRef", "SELECT ref, klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblBrlyAVKeylistKey WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyAVKeylistKey_loadRefByKlsMtbUrfSrf", "SELECT ref FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = $1 AND x1IxBrlyVMaintable = $2 AND x1Uref = $3 AND sref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVKeylistKey_loadRefByKlsSrf", "SELECT ref FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVKeylistKey_loadRstByKls", "SELECT ref, klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = $1 ORDER BY klsNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVKeylistKey_loadRstByKlsMtbUrf", "SELECT ref, klsIxBrlyVKeylist, klsNum, x1IxBrlyVMaintable, x1Uref, Fixed, sref, Avail, Implied, refJ, Title, Comment FROM TblBrlyAVKeylistKey WHERE klsIxBrlyVKeylist = $1 AND x1IxBrlyVMaintable = $2 AND x1Uref = $3 ORDER BY klsNum ASC", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyAVKeylistKey_loadTitByRef", "SELECT Title FROM TblBrlyAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyAVKeylistKey::loadRec(
			PGresult* res
			, BrlyAVKeylistKey** rec
		) {
	char* ptr;

	BrlyAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixbrlyvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixbrlyvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->klsIxBrlyVKeylist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->klsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxBrlyVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1Uref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Fixed = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Avail.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Implied.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[11]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "klsixbrlyvkeylist"),
			PQfnumber(res, "klsnum"),
			PQfnumber(res, "x1ixbrlyvmaintable"),
			PQfnumber(res, "x1uref"),
			PQfnumber(res, "fixed"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "avail"),
			PQfnumber(res, "implied"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new BrlyAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->klsIxBrlyVKeylist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->klsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxBrlyVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1Uref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Fixed = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Avail.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Implied.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[11]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVKeylistKey / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVKeylistKey / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, BrlyAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyAVKeylistKey::insertRec(
			BrlyAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	uint _klsIxBrlyVKeylist = htonl(rec->klsIxBrlyVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxBrlyVMaintable = htonl(rec->x1IxBrlyVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);

	const char* vals[] = {
		(char*) &_klsIxBrlyVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxBrlyVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyAVKeylistKey_insertRec", 11, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVKeylistKey_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyAVKeylistKey::insertRst(
			ListBrlyAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyAVKeylistKey::updateRec(
			BrlyAVKeylistKey* rec
		) {
	PGresult* res;

	uint _klsIxBrlyVKeylist = htonl(rec->klsIxBrlyVKeylist);
	uint _klsNum = htonl(rec->klsNum);
	uint _x1IxBrlyVMaintable = htonl(rec->x1IxBrlyVMaintable);
	ubigint _x1Uref = htonl64(rec->x1Uref);
	smallint _Fixed = htons((smallint) rec->Fixed);
	ubigint _refJ = htonl64(rec->refJ);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_klsIxBrlyVKeylist,
		(char*) &_klsNum,
		(char*) &_x1IxBrlyVMaintable,
		(char*) &_x1Uref,
		(char*) &_Fixed,
		rec->sref.c_str(),
		rec->Avail.c_str(),
		rec->Implied.c_str(),
		(char*) &_refJ,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(smallint),
		0,
		0,
		0,
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyAVKeylistKey_updateRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVKeylistKey_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyAVKeylistKey::updateRst(
			ListBrlyAVKeylistKey& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblBrlyAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyAVKeylistKey_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyAVKeylistKey::loadRecByRef(
			ubigint ref
			, BrlyAVKeylistKey** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyAVKeylistKey::loadRefByKlsMtbUrfSrf(
			uint klsIxBrlyVKeylist
			, uint x1IxBrlyVMaintable
			, ubigint x1Uref
			, string sref
			, ubigint& ref
		) {
	uint _klsIxBrlyVKeylist = htonl(klsIxBrlyVKeylist);
	uint _x1IxBrlyVMaintable = htonl(x1IxBrlyVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxBrlyVKeylist,
		(char*) &_x1IxBrlyVMaintable,
		(char*) &_x1Uref,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1,1,1,0};

	return loadRefByStmt("TblBrlyAVKeylistKey_loadRefByKlsMtbUrfSrf", 4, vals, l, f, ref);
};

bool PgTblBrlyAVKeylistKey::loadRefByKlsSrf(
			uint klsIxBrlyVKeylist
			, string sref
			, ubigint& ref
		) {
	uint _klsIxBrlyVKeylist = htonl(klsIxBrlyVKeylist);

	const char* vals[] = {
		(char*) &_klsIxBrlyVKeylist,
		sref.c_str()
	};
	const int l[] = {
		sizeof(uint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblBrlyAVKeylistKey_loadRefByKlsSrf", 2, vals, l, f, ref);
};

ubigint PgTblBrlyAVKeylistKey::loadRstByKls(
			uint klsIxBrlyVKeylist
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	uint _klsIxBrlyVKeylist = htonl(klsIxBrlyVKeylist);

	const char* vals[] = {
		(char*) &_klsIxBrlyVKeylist
	};
	const int l[] = {
		sizeof(uint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyAVKeylistKey_loadRstByKls", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyAVKeylistKey::loadRstByKlsMtbUrf(
			uint klsIxBrlyVKeylist
			, uint x1IxBrlyVMaintable
			, ubigint x1Uref
			, const bool append
			, ListBrlyAVKeylistKey& rst
		) {
	uint _klsIxBrlyVKeylist = htonl(klsIxBrlyVKeylist);
	uint _x1IxBrlyVMaintable = htonl(x1IxBrlyVMaintable);
	ubigint _x1Uref = htonl64(x1Uref);

	const char* vals[] = {
		(char*) &_klsIxBrlyVKeylist,
		(char*) &_x1IxBrlyVMaintable,
		(char*) &_x1Uref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblBrlyAVKeylistKey_loadRstByKlsMtbUrf", 3, vals, l, f, append, rst);
};

bool PgTblBrlyAVKeylistKey::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblBrlyAVKeylistKey_loadTitByRef", 1, vals, l, f, Title);
};

