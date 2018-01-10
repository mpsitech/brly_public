/**
  * \file BrlyMLeg.cpp
  * database access for table TblBrlyMLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMLeg.h"

#include "BrlyMLeg_vecs.cpp"

/******************************************************************************
 class BrlyMLeg
 ******************************************************************************/

BrlyMLeg::BrlyMLeg(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refBrlyCLeg
			, const ubigint bgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const double alt
			, const double deltaphi
			, const double alpha
			, const double xAlt
			, const double xPhi0
			, const double xPhi1
			, const double xAlpha
			, const bool Calcdone
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->ixVBasetype = ixVBasetype;
	this->refBrlyCLeg = refBrlyCLeg;
	this->bgnRefBrlyMLocation = bgnRefBrlyMLocation;
	this->endRefBrlyMLocation = endRefBrlyMLocation;
	this->alt = alt;
	this->deltaphi = deltaphi;
	this->alpha = alpha;
	this->xAlt = xAlt;
	this->xPhi0 = xPhi0;
	this->xPhi1 = xPhi1;
	this->xAlpha = xAlpha;
	this->Calcdone = Calcdone;
};

bool BrlyMLeg::operator==(
			const BrlyMLeg& comp
		) {
	return false;
};

bool BrlyMLeg::operator!=(
			const BrlyMLeg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMLeg
 ******************************************************************************/

ListBrlyMLeg::ListBrlyMLeg() {
};

ListBrlyMLeg::ListBrlyMLeg(
			const ListBrlyMLeg& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMLeg(*(src.nodes[i]));
};

ListBrlyMLeg::~ListBrlyMLeg() {
	clear();
};

void ListBrlyMLeg::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMLeg::size() const {
	return(nodes.size());
};

void ListBrlyMLeg::append(
			BrlyMLeg* rec
		) {
	nodes.push_back(rec);
};

BrlyMLeg* ListBrlyMLeg::operator[](
			const uint ix
		) {
	BrlyMLeg* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMLeg& ListBrlyMLeg::operator=(
			const ListBrlyMLeg& src
		) {
	BrlyMLeg* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMLeg(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMLeg::operator==(
			const ListBrlyMLeg& comp
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

bool ListBrlyMLeg::operator!=(
			const ListBrlyMLeg& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMLeg
 ******************************************************************************/

TblBrlyMLeg::TblBrlyMLeg() {
};

TblBrlyMLeg::~TblBrlyMLeg() {
};

bool TblBrlyMLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyMLeg** rec
		) {
	return false;
};

ubigint TblBrlyMLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMLeg& rst
		) {
	return 0;
};

void TblBrlyMLeg::insertRec(
			BrlyMLeg* rec
		) {
};

ubigint TblBrlyMLeg::insertNewRec(
			BrlyMLeg** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refBrlyCLeg
			, const ubigint bgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const double alt
			, const double deltaphi
			, const double alpha
			, const double xAlt
			, const double xPhi0
			, const double xPhi1
			, const double xAlpha
			, const bool Calcdone
		) {
	ubigint retval = 0;
	BrlyMLeg* _rec = NULL;

	_rec = new BrlyMLeg(0, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMLeg::appendNewRecToRst(
			ListBrlyMLeg& rst
			, BrlyMLeg** rec
			, const ubigint grp
			, const ubigint own
			, const uint ixVBasetype
			, const ubigint refBrlyCLeg
			, const ubigint bgnRefBrlyMLocation
			, const ubigint endRefBrlyMLocation
			, const double alt
			, const double deltaphi
			, const double alpha
			, const double xAlt
			, const double xPhi0
			, const double xPhi1
			, const double xAlpha
			, const bool Calcdone
		) {
	ubigint retval = 0;
	BrlyMLeg* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMLeg::insertRst(
			ListBrlyMLeg& rst
			, bool transact
		) {
};

void TblBrlyMLeg::updateRec(
			BrlyMLeg* rec
		) {
};

void TblBrlyMLeg::updateRst(
			ListBrlyMLeg& rst
			, bool transact
		) {
};

void TblBrlyMLeg::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMLeg::loadRecByRef(
			ubigint ref
			, BrlyMLeg** rec
		) {
	return false;
};

bool TblBrlyMLeg::loadRefByTypBloElo(
			uint ixVBasetype
			, ubigint bgnRefBrlyMLocation
			, ubigint endRefBrlyMLocation
			, ubigint& ref
		) {
	return false;
};

ubigint TblBrlyMLeg::loadRefsByBlo(
			ubigint bgnRefBrlyMLocation
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMLeg::loadRefsByClu(
			ubigint refBrlyCLeg
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMLeg::loadRefsByElo(
			ubigint endRefBrlyMLocation
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMLeg::loadRst(
			const bool append
			, ListBrlyMLeg& rst
			, ubigint limit
			, ubigint offset
		) {
	return 0;
};

ubigint TblBrlyMLeg::loadRstByBlo(
			ubigint bgnRefBrlyMLocation
			, const bool append
			, ListBrlyMLeg& rst
		) {
	return 0;
};

ubigint TblBrlyMLeg::loadRstByClu(
			ubigint refBrlyCLeg
			, const bool append
			, ListBrlyMLeg& rst
		) {
	return 0;
};

ubigint TblBrlyMLeg::loadRstByElo(
			ubigint endRefBrlyMLocation
			, const bool append
			, ListBrlyMLeg& rst
		) {
	return 0;
};

ubigint TblBrlyMLeg::loadRstByTyp(
			uint ixVBasetype
			, const bool append
			, ListBrlyMLeg& rst
			, ubigint limit
			, ubigint offset
		) {
	return 0;
};

ubigint TblBrlyMLeg::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMLeg& rst
		) {
	ubigint numload = 0;
	BrlyMLeg* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMLeg
 ******************************************************************************/

MyTblBrlyMLeg::MyTblBrlyMLeg() : TblBrlyMLeg(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMLeg::~MyTblBrlyMLeg() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMLeg::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMLeg (grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMLeg SET grp = ?, own = ?, ixVBasetype = ?, refBrlyCLeg = ?, bgnRefBrlyMLocation = ?, endRefBrlyMLocation = ?, alt = ?, deltaphi = ?, alpha = ?, xAlt = ?, xPhi0 = ?, xPhi1 = ?, xAlpha = ?, Calcdone = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMLeg WHERE ref = ?", false);
};

bool MyTblBrlyMLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyMLeg** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMLeg* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMLeg / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyMLeg();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->ixVBasetype = atol((char*) dbrow[3]); else _rec->ixVBasetype = 0;
		if (dbrow[4]) _rec->refBrlyCLeg = atoll((char*) dbrow[4]); else _rec->refBrlyCLeg = 0;
		if (dbrow[5]) _rec->bgnRefBrlyMLocation = atoll((char*) dbrow[5]); else _rec->bgnRefBrlyMLocation = 0;
		if (dbrow[6]) _rec->endRefBrlyMLocation = atoll((char*) dbrow[6]); else _rec->endRefBrlyMLocation = 0;
		if (dbrow[7]) _rec->alt = atof((char*) dbrow[7]); else _rec->alt = 0.0;
		if (dbrow[8]) _rec->deltaphi = atof((char*) dbrow[8]); else _rec->deltaphi = 0.0;
		if (dbrow[9]) _rec->alpha = atof((char*) dbrow[9]); else _rec->alpha = 0.0;
		if (dbrow[10]) _rec->xAlt = atof((char*) dbrow[10]); else _rec->xAlt = 0.0;
		if (dbrow[11]) _rec->xPhi0 = atof((char*) dbrow[11]); else _rec->xPhi0 = 0.0;
		if (dbrow[12]) _rec->xPhi1 = atof((char*) dbrow[12]); else _rec->xPhi1 = 0.0;
		if (dbrow[13]) _rec->xAlpha = atof((char*) dbrow[13]); else _rec->xAlpha = 0.0;
		if (dbrow[14]) _rec->Calcdone = (atoi((char*) dbrow[14]) != 0); else _rec->Calcdone = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMLeg& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMLeg* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMLeg / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyMLeg();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->ixVBasetype = atol((char*) dbrow[3]); else rec->ixVBasetype = 0;
			if (dbrow[4]) rec->refBrlyCLeg = atoll((char*) dbrow[4]); else rec->refBrlyCLeg = 0;
			if (dbrow[5]) rec->bgnRefBrlyMLocation = atoll((char*) dbrow[5]); else rec->bgnRefBrlyMLocation = 0;
			if (dbrow[6]) rec->endRefBrlyMLocation = atoll((char*) dbrow[6]); else rec->endRefBrlyMLocation = 0;
			if (dbrow[7]) rec->alt = atof((char*) dbrow[7]); else rec->alt = 0.0;
			if (dbrow[8]) rec->deltaphi = atof((char*) dbrow[8]); else rec->deltaphi = 0.0;
			if (dbrow[9]) rec->alpha = atof((char*) dbrow[9]); else rec->alpha = 0.0;
			if (dbrow[10]) rec->xAlt = atof((char*) dbrow[10]); else rec->xAlt = 0.0;
			if (dbrow[11]) rec->xPhi0 = atof((char*) dbrow[11]); else rec->xPhi0 = 0.0;
			if (dbrow[12]) rec->xPhi1 = atof((char*) dbrow[12]); else rec->xPhi1 = 0.0;
			if (dbrow[13]) rec->xAlpha = atof((char*) dbrow[13]); else rec->xAlpha = 0.0;
			if (dbrow[14]) rec->Calcdone = (atoi((char*) dbrow[14]) != 0); else rec->Calcdone = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMLeg::insertRec(
			BrlyMLeg* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	tinyint Calcdone = rec->Calcdone;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyCLeg,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->bgnRefBrlyMLocation,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->endRefBrlyMLocation,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->alt,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->deltaphi,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->alpha,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->xAlt,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->xPhi0,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->xPhi1,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->xAlpha,&(l[12]),&(n[12]),&(e[12])),
		bindTinyint(&Calcdone,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMLeg / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMLeg / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMLeg::insertRst(
			ListBrlyMLeg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMLeg::updateRec(
			BrlyMLeg* rec
		) {
	unsigned long l[15]; my_bool n[15]; my_bool e[15];

	tinyint Calcdone = rec->Calcdone;

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVBasetype,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refBrlyCLeg,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->bgnRefBrlyMLocation,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->endRefBrlyMLocation,&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->alt,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->deltaphi,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->alpha,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->xAlt,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->xPhi0,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->xPhi1,&(l[11]),&(n[11]),&(e[11])),
		bindDouble(&rec->xAlpha,&(l[12]),&(n[12]),&(e[12])),
		bindTinyint(&Calcdone,&(l[13]),&(n[13]),&(e[13])),
		bindUbigint(&rec->ref,&(l[14]),&(n[14]),&(e[14]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMLeg / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMLeg / stmtUpdateRec)\n");
};

void MyTblBrlyMLeg::updateRst(
			ListBrlyMLeg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMLeg::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMLeg / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMLeg / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMLeg::loadRecByRef(
			ubigint ref
			, BrlyMLeg** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMLeg WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMLeg::loadRefByTypBloElo(
			uint ixVBasetype
			, ubigint bgnRefBrlyMLocation
			, ubigint endRefBrlyMLocation
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(ixVBasetype) + " AND bgnRefBrlyMLocation = " + to_string(bgnRefBrlyMLocation) + " AND endRefBrlyMLocation = " + to_string(endRefBrlyMLocation) + "", ref);
};

ubigint MyTblBrlyMLeg::loadRefsByBlo(
			ubigint bgnRefBrlyMLocation
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMLeg WHERE bgnRefBrlyMLocation = " + to_string(bgnRefBrlyMLocation) + " ORDER BY endRefBrlyMLocation ASC", append, refs);
};

ubigint MyTblBrlyMLeg::loadRefsByClu(
			ubigint refBrlyCLeg
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMLeg WHERE refBrlyCLeg = " + to_string(refBrlyCLeg) + "", append, refs);
};

ubigint MyTblBrlyMLeg::loadRefsByElo(
			ubigint endRefBrlyMLocation
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMLeg WHERE endRefBrlyMLocation = " + to_string(endRefBrlyMLocation) + " ORDER BY bgnRefBrlyMLocation ASC", append, refs);
};

ubigint MyTblBrlyMLeg::loadRst(
			const bool append
			, ListBrlyMLeg& rst
			, ubigint limit
			, ubigint offset
		) {
	if ((limit == 0) && (offset == 0)) limit--;

	return loadRstBySQL("SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg ORDER BY ref ASC LIMIT " + to_string(offset) + "," + to_string(limit) + "", append, rst);
};

ubigint MyTblBrlyMLeg::loadRstByBlo(
			ubigint bgnRefBrlyMLocation
			, const bool append
			, ListBrlyMLeg& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE bgnRefBrlyMLocation = " + to_string(bgnRefBrlyMLocation) + " ORDER BY endRefBrlyMLocation ASC", append, rst);
};

ubigint MyTblBrlyMLeg::loadRstByClu(
			ubigint refBrlyCLeg
			, const bool append
			, ListBrlyMLeg& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE refBrlyCLeg = " + to_string(refBrlyCLeg) + "", append, rst);
};

ubigint MyTblBrlyMLeg::loadRstByElo(
			ubigint endRefBrlyMLocation
			, const bool append
			, ListBrlyMLeg& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE endRefBrlyMLocation = " + to_string(endRefBrlyMLocation) + " ORDER BY bgnRefBrlyMLocation ASC", append, rst);
};

ubigint MyTblBrlyMLeg::loadRstByTyp(
			uint ixVBasetype
			, const bool append
			, ListBrlyMLeg& rst
			, ubigint limit
			, ubigint offset
		) {
	if ((limit == 0) && (offset == 0)) limit--;

	return loadRstBySQL("SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE ixVBasetype = " + to_string(ixVBasetype) + " ORDER BY ref ASC LIMIT " + to_string(offset) + "," + to_string(limit) + "", append, rst);
};

/******************************************************************************
 class PgTblBrlyMLeg
 ******************************************************************************/

PgTblBrlyMLeg::PgTblBrlyMLeg() : TblBrlyMLeg(), PgTable() {
};

PgTblBrlyMLeg::~PgTblBrlyMLeg() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMLeg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMLeg_insertRec", "INSERT INTO TblBrlyMLeg (grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14) RETURNING ref", 14, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_updateRec", "UPDATE TblBrlyMLeg SET grp = $1, own = $2, ixVBasetype = $3, refBrlyCLeg = $4, bgnRefBrlyMLocation = $5, endRefBrlyMLocation = $6, alt = $7, deltaphi = $8, alpha = $9, xAlt = $10, xPhi0 = $11, xPhi1 = $12, xAlpha = $13, Calcdone = $14 WHERE ref = $15", 15, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_removeRecByRef", "DELETE FROM TblBrlyMLeg WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMLeg_loadRecByRef", "SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRefByTypBloElo", "SELECT ref FROM TblBrlyMLeg WHERE ixVBasetype = $1 AND bgnRefBrlyMLocation = $2 AND endRefBrlyMLocation = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRefsByBlo", "SELECT ref FROM TblBrlyMLeg WHERE bgnRefBrlyMLocation = $1 ORDER BY endRefBrlyMLocation ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRefsByClu", "SELECT ref FROM TblBrlyMLeg WHERE refBrlyCLeg = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRefsByElo", "SELECT ref FROM TblBrlyMLeg WHERE endRefBrlyMLocation = $1 ORDER BY bgnRefBrlyMLocation ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRst", "SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg ORDER BY ref ASC OFFSET $1 LIMIT $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRstByBlo", "SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE bgnRefBrlyMLocation = $1 ORDER BY endRefBrlyMLocation ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRstByClu", "SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE refBrlyCLeg = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRstByElo", "SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE endRefBrlyMLocation = $1 ORDER BY bgnRefBrlyMLocation ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLeg_loadRstByTyp", "SELECT ref, grp, own, ixVBasetype, refBrlyCLeg, bgnRefBrlyMLocation, endRefBrlyMLocation, alt, deltaphi, alpha, xAlt, xPhi0, xPhi1, xAlpha, Calcdone FROM TblBrlyMLeg WHERE ixVBasetype = $1 ORDER BY ref ASC OFFSET $2 LIMIT $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMLeg::loadRec(
			PGresult* res
			, BrlyMLeg** rec
		) {
	char* ptr;

	BrlyMLeg* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMLeg();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refbrlycleg"),
			PQfnumber(res, "bgnrefbrlymlocation"),
			PQfnumber(res, "endrefbrlymlocation"),
			PQfnumber(res, "alt"),
			PQfnumber(res, "deltaphi"),
			PQfnumber(res, "alpha"),
			PQfnumber(res, "xalt"),
			PQfnumber(res, "xphi0"),
			PQfnumber(res, "xphi1"),
			PQfnumber(res, "xalpha"),
			PQfnumber(res, "calcdone")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refBrlyCLeg = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->bgnRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->endRefBrlyMLocation = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->alt = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->deltaphi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->alpha = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->xAlt = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->xPhi0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->xPhi1 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->xAlpha = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->Calcdone = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMLeg::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMLeg& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMLeg* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refbrlycleg"),
			PQfnumber(res, "bgnrefbrlymlocation"),
			PQfnumber(res, "endrefbrlymlocation"),
			PQfnumber(res, "alt"),
			PQfnumber(res, "deltaphi"),
			PQfnumber(res, "alpha"),
			PQfnumber(res, "xalt"),
			PQfnumber(res, "xphi0"),
			PQfnumber(res, "xphi1"),
			PQfnumber(res, "xalpha"),
			PQfnumber(res, "calcdone")
		};

		while (numread < numrow) {
			rec = new BrlyMLeg();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refBrlyCLeg = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->bgnRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->endRefBrlyMLocation = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->alt = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->deltaphi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->alpha = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->xAlt = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->xPhi0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->xPhi1 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->xAlpha = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->Calcdone = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMLeg::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMLeg** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLeg / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMLeg::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMLeg& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLeg / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMLeg::loadRecBySQL(
			const string& sqlstr
			, BrlyMLeg** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMLeg::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMLeg& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMLeg::insertRec(
			BrlyMLeg* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refBrlyCLeg = htonl64(rec->refBrlyCLeg);
	ubigint _bgnRefBrlyMLocation = htonl64(rec->bgnRefBrlyMLocation);
	ubigint _endRefBrlyMLocation = htonl64(rec->endRefBrlyMLocation);
	string _alt = to_string(rec->alt);
	string _deltaphi = to_string(rec->deltaphi);
	string _alpha = to_string(rec->alpha);
	string _xAlt = to_string(rec->xAlt);
	string _xPhi0 = to_string(rec->xPhi0);
	string _xPhi1 = to_string(rec->xPhi1);
	string _xAlpha = to_string(rec->xAlpha);
	smallint _Calcdone = htons((smallint) rec->Calcdone);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_refBrlyCLeg,
		(char*) &_bgnRefBrlyMLocation,
		(char*) &_endRefBrlyMLocation,
		_alt.c_str(),
		_deltaphi.c_str(),
		_alpha.c_str(),
		_xAlt.c_str(),
		_xPhi0.c_str(),
		_xPhi1.c_str(),
		_xAlpha.c_str(),
		(char*) &_Calcdone
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMLeg_insertRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLeg_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMLeg::insertRst(
			ListBrlyMLeg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMLeg::updateRec(
			BrlyMLeg* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refBrlyCLeg = htonl64(rec->refBrlyCLeg);
	ubigint _bgnRefBrlyMLocation = htonl64(rec->bgnRefBrlyMLocation);
	ubigint _endRefBrlyMLocation = htonl64(rec->endRefBrlyMLocation);
	string _alt = to_string(rec->alt);
	string _deltaphi = to_string(rec->deltaphi);
	string _alpha = to_string(rec->alpha);
	string _xAlt = to_string(rec->xAlt);
	string _xPhi0 = to_string(rec->xPhi0);
	string _xPhi1 = to_string(rec->xPhi1);
	string _xAlpha = to_string(rec->xAlpha);
	smallint _Calcdone = htons((smallint) rec->Calcdone);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_ixVBasetype,
		(char*) &_refBrlyCLeg,
		(char*) &_bgnRefBrlyMLocation,
		(char*) &_endRefBrlyMLocation,
		_alt.c_str(),
		_deltaphi.c_str(),
		_alpha.c_str(),
		_xAlt.c_str(),
		_xPhi0.c_str(),
		_xPhi1.c_str(),
		_xAlpha.c_str(),
		(char*) &_Calcdone,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(smallint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMLeg_updateRec", 15, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLeg_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMLeg::updateRst(
			ListBrlyMLeg& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMLeg::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMLeg_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLeg_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMLeg::loadRecByRef(
			ubigint ref
			, BrlyMLeg** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMLeg_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMLeg::loadRefByTypBloElo(
			uint ixVBasetype
			, ubigint bgnRefBrlyMLocation
			, ubigint endRefBrlyMLocation
			, ubigint& ref
		) {
	uint _ixVBasetype = htonl(ixVBasetype);
	ubigint _bgnRefBrlyMLocation = htonl64(bgnRefBrlyMLocation);
	ubigint _endRefBrlyMLocation = htonl64(endRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_bgnRefBrlyMLocation,
		(char*) &_endRefBrlyMLocation
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRefByStmt("TblBrlyMLeg_loadRefByTypBloElo", 3, vals, l, f, ref);
};

ubigint PgTblBrlyMLeg::loadRefsByBlo(
			ubigint bgnRefBrlyMLocation
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _bgnRefBrlyMLocation = htonl64(bgnRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_bgnRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMLeg_loadRefsByBlo", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMLeg::loadRefsByClu(
			ubigint refBrlyCLeg
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyCLeg = htonl64(refBrlyCLeg);

	const char* vals[] = {
		(char*) &_refBrlyCLeg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMLeg_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMLeg::loadRefsByElo(
			ubigint endRefBrlyMLocation
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _endRefBrlyMLocation = htonl64(endRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_endRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMLeg_loadRefsByElo", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMLeg::loadRst(
			const bool append
			, ListBrlyMLeg& rst
			, ubigint limit
			, ubigint offset
		) {
	ubigint _offset = htonl64(offset);

	ubigint _limit = htonl64(limit);
	char* _limitptr = NULL;
	int _limitl = 0;

	if (limit != 0) {
		_limitptr = (char*) &_limit;
		_limitl = sizeof(ubigint);
	};

	const char* vals[] = {
		(char*) &_offset,
		_limitptr
	};
	const int l[] = {
		sizeof(ubigint),
		_limitl
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblBrlyMLeg_loadRst", 2, vals, l, f, append, rst);
};

ubigint PgTblBrlyMLeg::loadRstByBlo(
			ubigint bgnRefBrlyMLocation
			, const bool append
			, ListBrlyMLeg& rst
		) {
	ubigint _bgnRefBrlyMLocation = htonl64(bgnRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_bgnRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMLeg_loadRstByBlo", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyMLeg::loadRstByClu(
			ubigint refBrlyCLeg
			, const bool append
			, ListBrlyMLeg& rst
		) {
	ubigint _refBrlyCLeg = htonl64(refBrlyCLeg);

	const char* vals[] = {
		(char*) &_refBrlyCLeg
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMLeg_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyMLeg::loadRstByElo(
			ubigint endRefBrlyMLocation
			, const bool append
			, ListBrlyMLeg& rst
		) {
	ubigint _endRefBrlyMLocation = htonl64(endRefBrlyMLocation);

	const char* vals[] = {
		(char*) &_endRefBrlyMLocation
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMLeg_loadRstByElo", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyMLeg::loadRstByTyp(
			uint ixVBasetype
			, const bool append
			, ListBrlyMLeg& rst
			, ubigint limit
			, ubigint offset
		) {
	uint _ixVBasetype = htonl(ixVBasetype);
	ubigint _offset = htonl64(offset);

	ubigint _limit = htonl64(limit);
	char* _limitptr = NULL;
	int _limitl = 0;

	if (limit != 0) {
		_limitptr = (char*) &_limit;
		_limitl = sizeof(ubigint);
	};

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_offset,
		_limitptr
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		_limitl
	};
	const int f[] = {1,1,1};

	return loadRstByStmt("TblBrlyMLeg_loadRstByTyp", 3, vals, l, f, append, rst);
};

