/**
  * \file BrlyMRegion.cpp
  * database access for table TblBrlyMRegion (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMRegion.h"

#include "BrlyMRegion_vecs.cpp"

/******************************************************************************
 class BrlyMRegion
 ******************************************************************************/

BrlyMRegion::BrlyMRegion(
			const ubigint ref
			, const ubigint supRefBrlyMRegion
			, const usmallint supLvl
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const ubigint refJ
			, const uint ixVDst
			, const double toffset
		) {

	this->ref = ref;
	this->supRefBrlyMRegion = supRefBrlyMRegion;
	this->supLvl = supLvl;
	this->sref = sref;
	this->refJTitle = refJTitle;
	this->Title = Title;
	this->refJ = refJ;
	this->ixVDst = ixVDst;
	this->toffset = toffset;
};

bool BrlyMRegion::operator==(
			const BrlyMRegion& comp
		) {
	return false;
};

bool BrlyMRegion::operator!=(
			const BrlyMRegion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMRegion
 ******************************************************************************/

ListBrlyMRegion::ListBrlyMRegion() {
};

ListBrlyMRegion::ListBrlyMRegion(
			const ListBrlyMRegion& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMRegion(*(src.nodes[i]));
};

ListBrlyMRegion::~ListBrlyMRegion() {
	clear();
};

void ListBrlyMRegion::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMRegion::size() const {
	return(nodes.size());
};

void ListBrlyMRegion::append(
			BrlyMRegion* rec
		) {
	nodes.push_back(rec);
};

BrlyMRegion* ListBrlyMRegion::operator[](
			const uint ix
		) {
	BrlyMRegion* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMRegion& ListBrlyMRegion::operator=(
			const ListBrlyMRegion& src
		) {
	BrlyMRegion* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMRegion(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMRegion::operator==(
			const ListBrlyMRegion& comp
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

bool ListBrlyMRegion::operator!=(
			const ListBrlyMRegion& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMRegion
 ******************************************************************************/

TblBrlyMRegion::TblBrlyMRegion() {
};

TblBrlyMRegion::~TblBrlyMRegion() {
};

bool TblBrlyMRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyMRegion** rec
		) {
	return false;
};

ubigint TblBrlyMRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMRegion& rst
		) {
	return 0;
};

void TblBrlyMRegion::insertRec(
			BrlyMRegion* rec
		) {
};

ubigint TblBrlyMRegion::insertNewRec(
			BrlyMRegion** rec
			, const ubigint supRefBrlyMRegion
			, const usmallint supLvl
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const ubigint refJ
			, const uint ixVDst
			, const double toffset
		) {
	ubigint retval = 0;
	BrlyMRegion* _rec = NULL;

	_rec = new BrlyMRegion(0, supRefBrlyMRegion, supLvl, sref, refJTitle, Title, refJ, ixVDst, toffset);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMRegion::appendNewRecToRst(
			ListBrlyMRegion& rst
			, BrlyMRegion** rec
			, const ubigint supRefBrlyMRegion
			, const usmallint supLvl
			, const string sref
			, const ubigint refJTitle
			, const string Title
			, const ubigint refJ
			, const uint ixVDst
			, const double toffset
		) {
	ubigint retval = 0;
	BrlyMRegion* _rec = NULL;

	retval = insertNewRec(&_rec, supRefBrlyMRegion, supLvl, sref, refJTitle, Title, refJ, ixVDst, toffset);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMRegion::insertRst(
			ListBrlyMRegion& rst
			, bool transact
		) {
};

void TblBrlyMRegion::updateRec(
			BrlyMRegion* rec
		) {
};

void TblBrlyMRegion::updateRst(
			ListBrlyMRegion& rst
			, bool transact
		) {
};

void TblBrlyMRegion::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMRegion::loadRecByRef(
			ubigint ref
			, BrlyMRegion** rec
		) {
	return false;
};

bool TblBrlyMRegion::confirmByRef(
			ubigint ref
		) {
	return false;
};

bool TblBrlyMRegion::loadRefBySupSrf(
			ubigint supRefBrlyMRegion
			, string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblBrlyMRegion::loadRefsBySup(
			ubigint supRefBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMRegion::loadRstBySup(
			ubigint supRefBrlyMRegion
			, const bool append
			, ListBrlyMRegion& rst
		) {
	return 0;
};

bool TblBrlyMRegion::loadSupByRef(
			ubigint ref
			, ubigint& supRefBrlyMRegion
		) {
	return false;
};

ubigint TblBrlyMRegion::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMRegion& rst
		) {
	ubigint numload = 0;
	BrlyMRegion* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblBrlyMRegion::loadHrefsup(
			ubigint ref
			, vector<ubigint>& refs
		) {
	ubigint sup;

	refs.resize(0);
	ubigint retval = 0;

	while (loadSupByRef(ref, sup)) {
		refs.push_back(ref);
		retval++;

		ref = sup;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblBrlyMRegion::loadHrefsdown(
			ubigint ref
			, const bool append
			, vector<ubigint>& refs
			, unsigned int firstix
			, unsigned int lastix
		) {
	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) refs.resize(0);

		if (confirmByRef(ref)) {
			refs.push_back(ref);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i=firstix;i<=lastix;i++) {
		newfirstix = refs.size();
		retval += loadRefsBySup(refs[i], true, refs);
		newlastix = refs.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrefsdown(0, true, refs, newfirstix, newlastix);
	};

	return retval;
};

ubigint TblBrlyMRegion::loadHrstup(
			ubigint ref
			, ListBrlyMRegion& rst
		) {
	BrlyMRegion* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefBrlyMRegion;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblBrlyMRegion::loadHrstdown(
			ubigint ref
			, const bool append
			, ListBrlyMRegion& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	BrlyMRegion* rec = NULL;

	unsigned int newfirstix, newlastix;

	ubigint retval = 0;

	// initial call
	if ((firstix == 0) && (lastix == 0)) {
		if (!append) rst.clear();

		if (loadRecByRef(ref, &rec)) {
			rst.nodes.push_back(rec);
			retval = 1;

		} else {
			// ensure that no recursion takes place
			firstix = 1;
		};
	};

	for (unsigned int i=firstix;i<=lastix;i++) {
		rec = rst.nodes[i];

		newfirstix = rst.nodes.size();
		retval += loadRstBySup(rec->ref, true, rst);
		newlastix = rst.nodes.size() - 1;

		if (newlastix >= newfirstix) retval += loadHrstdown(0, true, rst, newfirstix, newlastix);
	};

	return retval;
};

/******************************************************************************
 class MyTblBrlyMRegion
 ******************************************************************************/

MyTblBrlyMRegion::MyTblBrlyMRegion() : TblBrlyMRegion(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMRegion::~MyTblBrlyMRegion() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMRegion::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMRegion (supRefBrlyMRegion, supLvl, sref, refJTitle, Title, refJ, ixVDst, toffset) VALUES (?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMRegion SET supRefBrlyMRegion = ?, supLvl = ?, sref = ?, refJTitle = ?, Title = ?, refJ = ?, ixVDst = ?, toffset = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMRegion WHERE ref = ?", false);
};

bool MyTblBrlyMRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyMRegion** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMRegion* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMRegion / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMRegion();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->supRefBrlyMRegion = atoll((char*) dbrow[1]); else _rec->supRefBrlyMRegion = 0;
		if (dbrow[2]) _rec->supLvl = atoi((char*) dbrow[2]); else _rec->supLvl = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->refJTitle = atoll((char*) dbrow[4]); else _rec->refJTitle = 0;
		if (dbrow[5]) _rec->Title.assign(dbrow[5], dblengths[5]); else _rec->Title = "";
		if (dbrow[6]) _rec->refJ = atoll((char*) dbrow[6]); else _rec->refJ = 0;
		if (dbrow[7]) _rec->ixVDst = atol((char*) dbrow[7]); else _rec->ixVDst = 0;
		if (dbrow[8]) _rec->toffset = atof((char*) dbrow[8]); else _rec->toffset = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMRegion& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMRegion* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMRegion / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMRegion();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->supRefBrlyMRegion = atoll((char*) dbrow[1]); else rec->supRefBrlyMRegion = 0;
			if (dbrow[2]) rec->supLvl = atoi((char*) dbrow[2]); else rec->supLvl = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->refJTitle = atoll((char*) dbrow[4]); else rec->refJTitle = 0;
			if (dbrow[5]) rec->Title.assign(dbrow[5], dblengths[5]); else rec->Title = "";
			if (dbrow[6]) rec->refJ = atoll((char*) dbrow[6]); else rec->refJ = 0;
			if (dbrow[7]) rec->ixVDst = atol((char*) dbrow[7]); else rec->ixVDst = 0;
			if (dbrow[8]) rec->toffset = atof((char*) dbrow[8]); else rec->toffset = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMRegion::insertRec(
			BrlyMRegion* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[2] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUsmallint(&rec->supLvl,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJTitle,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refJ,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDst,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->toffset,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMRegion / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMRegion / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMRegion::insertRst(
			ListBrlyMRegion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMRegion::updateRec(
			BrlyMRegion* rec
		) {
	unsigned long l[9]; my_bool n[9]; my_bool e[9];

	l[2] = rec->sref.length();
	l[4] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->supRefBrlyMRegion,&(l[0]),&(n[0]),&(e[0])),
		bindUsmallint(&rec->supLvl,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJTitle,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Title.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refJ,&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVDst,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->toffset,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->ref,&(l[8]),&(n[8]),&(e[8]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMRegion / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMRegion / stmtUpdateRec)\n");
};

void MyTblBrlyMRegion::updateRst(
			ListBrlyMRegion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMRegion::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMRegion / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMRegion / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMRegion::loadRecByRef(
			ubigint ref
			, BrlyMRegion** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMRegion WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMRegion::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblBrlyMRegion WHERE ref = " + to_string(ref) + "", val);
};

bool MyTblBrlyMRegion::loadRefBySupSrf(
			ubigint supRefBrlyMRegion
			, string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyMRegion WHERE supRefBrlyMRegion = " + to_string(supRefBrlyMRegion) + " AND sref = '" + sref + "'", ref);
};

ubigint MyTblBrlyMRegion::loadRefsBySup(
			ubigint supRefBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMRegion WHERE supRefBrlyMRegion = " + to_string(supRefBrlyMRegion) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblBrlyMRegion::loadRstBySup(
			ubigint supRefBrlyMRegion
			, const bool append
			, ListBrlyMRegion& rst
		) {
	return loadRstBySQL("SELECT ref, supRefBrlyMRegion, supLvl, sref, refJTitle, Title, refJ, ixVDst, toffset FROM TblBrlyMRegion WHERE supRefBrlyMRegion = " + to_string(supRefBrlyMRegion) + " ORDER BY sref ASC", append, rst);
};

bool MyTblBrlyMRegion::loadSupByRef(
			ubigint ref
			, ubigint& supRefBrlyMRegion
		) {
	return loadRefBySQL("SELECT supRefBrlyMRegion FROM TblBrlyMRegion WHERE ref = " + to_string(ref) + "", supRefBrlyMRegion);
};

/******************************************************************************
 class PgTblBrlyMRegion
 ******************************************************************************/

PgTblBrlyMRegion::PgTblBrlyMRegion() : TblBrlyMRegion(), PgTable() {
};

PgTblBrlyMRegion::~PgTblBrlyMRegion() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMRegion::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMRegion_insertRec", "INSERT INTO TblBrlyMRegion (supRefBrlyMRegion, supLvl, sref, refJTitle, Title, refJ, ixVDst, toffset) VALUES ($1,$2,$3,$4,$5,$6,$7,$8) RETURNING ref", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMRegion_updateRec", "UPDATE TblBrlyMRegion SET supRefBrlyMRegion = $1, supLvl = $2, sref = $3, refJTitle = $4, Title = $5, refJ = $6, ixVDst = $7, toffset = $8 WHERE ref = $9", 9, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMRegion_removeRecByRef", "DELETE FROM TblBrlyMRegion WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMRegion_loadRecByRef", "SELECT ref, supRefBrlyMRegion, supLvl, sref, refJTitle, Title, refJ, ixVDst, toffset FROM TblBrlyMRegion WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMRegion_confirmByRef", "SELECT ref FROM TblBrlyMRegion WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMRegion_loadRefBySupSrf", "SELECT ref FROM TblBrlyMRegion WHERE supRefBrlyMRegion = $1 AND sref = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMRegion_loadRefsBySup", "SELECT ref FROM TblBrlyMRegion WHERE supRefBrlyMRegion = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMRegion_loadRstBySup", "SELECT ref, supRefBrlyMRegion, supLvl, sref, refJTitle, Title, refJ, ixVDst, toffset FROM TblBrlyMRegion WHERE supRefBrlyMRegion = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMRegion_loadSupByRef", "SELECT supRefBrlyMRegion FROM TblBrlyMRegion WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMRegion::loadRec(
			PGresult* res
			, BrlyMRegion** rec
		) {
	char* ptr;

	BrlyMRegion* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMRegion();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefbrlymregion"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "ixvdst"),
			PQfnumber(res, "toffset")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->supRefBrlyMRegion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->supLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refJTitle = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refJ = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVDst = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->toffset = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMRegion::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMRegion& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMRegion* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "suprefbrlymregion"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "refjtitle"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refj"),
			PQfnumber(res, "ixvdst"),
			PQfnumber(res, "toffset")
		};

		while (numread < numrow) {
			rec = new BrlyMRegion();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->supRefBrlyMRegion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->supLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refJTitle = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refJ = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVDst = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->toffset = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMRegion::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMRegion** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRegion / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMRegion::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMRegion& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRegion / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMRegion::loadRecBySQL(
			const string& sqlstr
			, BrlyMRegion** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMRegion::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMRegion& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMRegion::insertRec(
			BrlyMRegion* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _supRefBrlyMRegion = htonl64(rec->supRefBrlyMRegion);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _refJ = htonl64(rec->refJ);
	uint _ixVDst = htonl(rec->ixVDst);
	string _toffset = to_string(rec->toffset);

	const char* vals[] = {
		(char*) &_supRefBrlyMRegion,
		(char*) &_supLvl,
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_refJ,
		(char*) &_ixVDst,
		_toffset.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0, 1, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyMRegion_insertRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRegion_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMRegion::insertRst(
			ListBrlyMRegion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMRegion::updateRec(
			BrlyMRegion* rec
		) {
	PGresult* res;

	ubigint _supRefBrlyMRegion = htonl64(rec->supRefBrlyMRegion);
	usmallint _supLvl = htons(rec->supLvl);
	ubigint _refJTitle = htonl64(rec->refJTitle);
	ubigint _refJ = htonl64(rec->refJ);
	uint _ixVDst = htonl(rec->ixVDst);
	string _toffset = to_string(rec->toffset);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_supRefBrlyMRegion,
		(char*) &_supLvl,
		rec->sref.c_str(),
		(char*) &_refJTitle,
		rec->Title.c_str(),
		(char*) &_refJ,
		(char*) &_ixVDst,
		_toffset.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(usmallint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMRegion_updateRec", 9, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRegion_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMRegion::updateRst(
			ListBrlyMRegion& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMRegion::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMRegion_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMRegion_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMRegion::loadRecByRef(
			ubigint ref
			, BrlyMRegion** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMRegion_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMRegion::confirmByRef(
			ubigint ref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblBrlyMRegion_confirmByRef", 1, vals, l, f, _ref);
};

bool PgTblBrlyMRegion::loadRefBySupSrf(
			ubigint supRefBrlyMRegion
			, string sref
			, ubigint& ref
		) {
	ubigint _supRefBrlyMRegion = htonl64(supRefBrlyMRegion);

	const char* vals[] = {
		(char*) &_supRefBrlyMRegion,
		sref.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0
	};
	const int f[] = {1,0};

	return loadRefByStmt("TblBrlyMRegion_loadRefBySupSrf", 2, vals, l, f, ref);
};

ubigint PgTblBrlyMRegion::loadRefsBySup(
			ubigint supRefBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefBrlyMRegion = htonl64(supRefBrlyMRegion);

	const char* vals[] = {
		(char*) &_supRefBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMRegion_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMRegion::loadRstBySup(
			ubigint supRefBrlyMRegion
			, const bool append
			, ListBrlyMRegion& rst
		) {
	ubigint _supRefBrlyMRegion = htonl64(supRefBrlyMRegion);

	const char* vals[] = {
		(char*) &_supRefBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMRegion_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblBrlyMRegion::loadSupByRef(
			ubigint ref
			, ubigint& supRefBrlyMRegion
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblBrlyMRegion_loadSupByRef", 1, vals, l, f, supRefBrlyMRegion);
};

