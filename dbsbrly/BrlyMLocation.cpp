/**
  * \file BrlyMLocation.cpp
  * database access for table TblBrlyMLocation (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMLocation.h"

#include "BrlyMLocation_vecs.cpp"

/******************************************************************************
 class BrlyMLocation
 ******************************************************************************/

BrlyMLocation::BrlyMLocation(
			const ubigint ref
			, const uint ixVBasetype
			, const ubigint refBrlyMRegion
			, const ubigint refBrlyMEquipment
			, const string sref
			, const string srefICAO
			, const string Title
			, const double alt
			, const double theta
			, const double phi
			, const string tz
			, const double alpha
			, const bool Calcdone
		) {

	this->ref = ref;
	this->ixVBasetype = ixVBasetype;
	this->refBrlyMRegion = refBrlyMRegion;
	this->refBrlyMEquipment = refBrlyMEquipment;
	this->sref = sref;
	this->srefICAO = srefICAO;
	this->Title = Title;
	this->alt = alt;
	this->theta = theta;
	this->phi = phi;
	this->tz = tz;
	this->alpha = alpha;
	this->Calcdone = Calcdone;
};

bool BrlyMLocation::operator==(
			const BrlyMLocation& comp
		) {
	return false;
};

bool BrlyMLocation::operator!=(
			const BrlyMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMLocation
 ******************************************************************************/

ListBrlyMLocation::ListBrlyMLocation() {
};

ListBrlyMLocation::ListBrlyMLocation(
			const ListBrlyMLocation& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMLocation(*(src.nodes[i]));
};

ListBrlyMLocation::~ListBrlyMLocation() {
	clear();
};

void ListBrlyMLocation::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMLocation::size() const {
	return(nodes.size());
};

void ListBrlyMLocation::append(
			BrlyMLocation* rec
		) {
	nodes.push_back(rec);
};

BrlyMLocation* ListBrlyMLocation::operator[](
			const uint ix
		) {
	BrlyMLocation* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMLocation& ListBrlyMLocation::operator=(
			const ListBrlyMLocation& src
		) {
	BrlyMLocation* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMLocation(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMLocation::operator==(
			const ListBrlyMLocation& comp
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

bool ListBrlyMLocation::operator!=(
			const ListBrlyMLocation& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMLocation
 ******************************************************************************/

TblBrlyMLocation::TblBrlyMLocation() {
};

TblBrlyMLocation::~TblBrlyMLocation() {
};

bool TblBrlyMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyMLocation** rec
		) {
	return false;
};

ubigint TblBrlyMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMLocation& rst
		) {
	return 0;
};

void TblBrlyMLocation::insertRec(
			BrlyMLocation* rec
		) {
};

ubigint TblBrlyMLocation::insertNewRec(
			BrlyMLocation** rec
			, const uint ixVBasetype
			, const ubigint refBrlyMRegion
			, const ubigint refBrlyMEquipment
			, const string sref
			, const string srefICAO
			, const string Title
			, const double alt
			, const double theta
			, const double phi
			, const string tz
			, const double alpha
			, const bool Calcdone
		) {
	ubigint retval = 0;
	BrlyMLocation* _rec = NULL;

	_rec = new BrlyMLocation(0, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMLocation::appendNewRecToRst(
			ListBrlyMLocation& rst
			, BrlyMLocation** rec
			, const uint ixVBasetype
			, const ubigint refBrlyMRegion
			, const ubigint refBrlyMEquipment
			, const string sref
			, const string srefICAO
			, const string Title
			, const double alt
			, const double theta
			, const double phi
			, const string tz
			, const double alpha
			, const bool Calcdone
		) {
	ubigint retval = 0;
	BrlyMLocation* _rec = NULL;

	retval = insertNewRec(&_rec, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMLocation::insertRst(
			ListBrlyMLocation& rst
			, bool transact
		) {
};

void TblBrlyMLocation::updateRec(
			BrlyMLocation* rec
		) {
};

void TblBrlyMLocation::updateRst(
			ListBrlyMLocation& rst
			, bool transact
		) {
};

void TblBrlyMLocation::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMLocation::loadRecByRef(
			ubigint ref
			, BrlyMLocation** rec
		) {
	return false;
};

bool TblBrlyMLocation::loadRecByEqp(
			ubigint refBrlyMEquipment
			, BrlyMLocation** rec
		) {
	return false;
};

bool TblBrlyMLocation::loadRecBySrf(
			string sref
			, BrlyMLocation** rec
		) {
	return false;
};

bool TblBrlyMLocation::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return false;
};

ubigint TblBrlyMLocation::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMLocation::loadRst(
			const bool append
			, ListBrlyMLocation& rst
			, ubigint limit
			, ubigint offset
		) {
	return 0;
};

ubigint TblBrlyMLocation::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyMLocation& rst
		) {
	return 0;
};

ubigint TblBrlyMLocation::loadRstByTyp(
			uint ixVBasetype
			, const bool append
			, ListBrlyMLocation& rst
			, ubigint limit
			, ubigint offset
		) {
	return 0;
};

bool TblBrlyMLocation::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return false;
};

bool TblBrlyMLocation::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return false;
};

ubigint TblBrlyMLocation::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMLocation& rst
		) {
	ubigint numload = 0;
	BrlyMLocation* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMLocation
 ******************************************************************************/

MyTblBrlyMLocation::MyTblBrlyMLocation() : TblBrlyMLocation(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMLocation::~MyTblBrlyMLocation() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMLocation::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMLocation (ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMLocation SET ixVBasetype = ?, refBrlyMRegion = ?, refBrlyMEquipment = ?, sref = ?, srefICAO = ?, Title = ?, alt = ?, theta = ?, phi = ?, tz = ?, alpha = ?, Calcdone = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMLocation WHERE ref = ?", false);
};

bool MyTblBrlyMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyMLocation** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMLocation* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMLocation / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMLocation();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixVBasetype = atol((char*) dbrow[1]); else _rec->ixVBasetype = 0;
		if (dbrow[2]) _rec->refBrlyMRegion = atoll((char*) dbrow[2]); else _rec->refBrlyMRegion = 0;
		if (dbrow[3]) _rec->refBrlyMEquipment = atoll((char*) dbrow[3]); else _rec->refBrlyMEquipment = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->srefICAO.assign(dbrow[5], dblengths[5]); else _rec->srefICAO = "";
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->alt = atof((char*) dbrow[7]); else _rec->alt = 0.0;
		if (dbrow[8]) _rec->theta = atof((char*) dbrow[8]); else _rec->theta = 0.0;
		if (dbrow[9]) _rec->phi = atof((char*) dbrow[9]); else _rec->phi = 0.0;
		if (dbrow[10]) _rec->tz.assign(dbrow[10], dblengths[10]); else _rec->tz = "";
		if (dbrow[11]) _rec->alpha = atof((char*) dbrow[11]); else _rec->alpha = 0.0;
		if (dbrow[12]) _rec->Calcdone = (atoi((char*) dbrow[12]) != 0); else _rec->Calcdone = false;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMLocation& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMLocation* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMLocation / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMLocation();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixVBasetype = atol((char*) dbrow[1]); else rec->ixVBasetype = 0;
			if (dbrow[2]) rec->refBrlyMRegion = atoll((char*) dbrow[2]); else rec->refBrlyMRegion = 0;
			if (dbrow[3]) rec->refBrlyMEquipment = atoll((char*) dbrow[3]); else rec->refBrlyMEquipment = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->srefICAO.assign(dbrow[5], dblengths[5]); else rec->srefICAO = "";
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->alt = atof((char*) dbrow[7]); else rec->alt = 0.0;
			if (dbrow[8]) rec->theta = atof((char*) dbrow[8]); else rec->theta = 0.0;
			if (dbrow[9]) rec->phi = atof((char*) dbrow[9]); else rec->phi = 0.0;
			if (dbrow[10]) rec->tz.assign(dbrow[10], dblengths[10]); else rec->tz = "";
			if (dbrow[11]) rec->alpha = atof((char*) dbrow[11]); else rec->alpha = 0.0;
			if (dbrow[12]) rec->Calcdone = (atoi((char*) dbrow[12]) != 0); else rec->Calcdone = false;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMLocation::insertRec(
			BrlyMLocation* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->sref.length();
	l[4] = rec->srefICAO.length();
	l[5] = rec->Title.length();
	l[9] = rec->tz.length();
	tinyint Calcdone = rec->Calcdone;

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refBrlyMRegion,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefICAO.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->alt,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->theta,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->phi,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->tz.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->alpha,&(l[10]),&(n[10]),&(e[10])),
		bindTinyint(&Calcdone,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMLocation / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMLocation / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMLocation::insertRst(
			ListBrlyMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMLocation::updateRec(
			BrlyMLocation* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();
	l[4] = rec->srefICAO.length();
	l[5] = rec->Title.length();
	l[9] = rec->tz.length();
	tinyint Calcdone = rec->Calcdone;

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixVBasetype,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refBrlyMRegion,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefICAO.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindDouble(&rec->alt,&(l[6]),&(n[6]),&(e[6])),
		bindDouble(&rec->theta,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->phi,&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->tz.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->alpha,&(l[10]),&(n[10]),&(e[10])),
		bindTinyint(&Calcdone,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMLocation / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMLocation / stmtUpdateRec)\n");
};

void MyTblBrlyMLocation::updateRst(
			ListBrlyMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMLocation::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMLocation / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMLocation / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMLocation::loadRecByRef(
			ubigint ref
			, BrlyMLocation** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMLocation WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMLocation::loadRecByEqp(
			ubigint refBrlyMEquipment
			, BrlyMLocation** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE refBrlyMEquipment = " + to_string(refBrlyMEquipment) + "", rec);
};

bool MyTblBrlyMLocation::loadRecBySrf(
			string sref
			, BrlyMLocation** rec
		) {
	return loadRecBySQL("SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE sref = '" + sref + "'", rec);
};

bool MyTblBrlyMLocation::loadRefBySrf(
			string sref
			, ubigint& ref
		) {
	return loadRefBySQL("SELECT ref FROM TblBrlyMLocation WHERE sref = '" + sref + "'", ref);
};

ubigint MyTblBrlyMLocation::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMLocation WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " ORDER BY sref ASC", append, refs);
};

ubigint MyTblBrlyMLocation::loadRst(
			const bool append
			, ListBrlyMLocation& rst
			, ubigint limit
			, ubigint offset
		) {
	if ((limit == 0) && (offset == 0)) limit--;

	return loadRstBySQL("SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation ORDER BY ref ASC LIMIT " + to_string(offset) + "," + to_string(limit) + "", append, rst);
};

ubigint MyTblBrlyMLocation::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyMLocation& rst
		) {
	return loadRstBySQL("SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE refBrlyMRegion = " + to_string(refBrlyMRegion) + " ORDER BY sref ASC", append, rst);
};

ubigint MyTblBrlyMLocation::loadRstByTyp(
			uint ixVBasetype
			, const bool append
			, ListBrlyMLocation& rst
			, ubigint limit
			, ubigint offset
		) {
	if ((limit == 0) && (offset == 0)) limit--;

	return loadRstBySQL("SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE ixVBasetype = " + to_string(ixVBasetype) + " ORDER BY ref ASC LIMIT " + to_string(offset) + "," + to_string(limit) + "", append, rst);
};

bool MyTblBrlyMLocation::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	return loadStringBySQL("SELECT sref FROM TblBrlyMLocation WHERE ref = " + to_string(ref) + "", sref);
};

bool MyTblBrlyMLocation::loadTitByRef(
			ubigint ref
			, string& Title
		) {
	return loadStringBySQL("SELECT Title FROM TblBrlyMLocation WHERE ref = " + to_string(ref) + "", Title);
};

/******************************************************************************
 class PgTblBrlyMLocation
 ******************************************************************************/

PgTblBrlyMLocation::PgTblBrlyMLocation() : TblBrlyMLocation(), PgTable() {
};

PgTblBrlyMLocation::~PgTblBrlyMLocation() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMLocation::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMLocation_insertRec", "INSERT INTO TblBrlyMLocation (ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_updateRec", "UPDATE TblBrlyMLocation SET ixVBasetype = $1, refBrlyMRegion = $2, refBrlyMEquipment = $3, sref = $4, srefICAO = $5, Title = $6, alt = $7, theta = $8, phi = $9, tz = $10, alpha = $11, Calcdone = $12 WHERE ref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_removeRecByRef", "DELETE FROM TblBrlyMLocation WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMLocation_loadRecByRef", "SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMLocation_loadRecByEqp", "SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE refBrlyMEquipment = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_loadRecBySrf", "SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE sref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_loadRefBySrf", "SELECT ref FROM TblBrlyMLocation WHERE sref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_loadRefsByReg", "SELECT ref FROM TblBrlyMLocation WHERE refBrlyMRegion = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_loadRst", "SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation ORDER BY ref ASC OFFSET $1 LIMIT $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_loadRstByReg", "SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE refBrlyMRegion = $1 ORDER BY sref ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_loadRstByTyp", "SELECT ref, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, sref, srefICAO, Title, alt, theta, phi, tz, alpha, Calcdone FROM TblBrlyMLocation WHERE ixVBasetype = $1 ORDER BY ref ASC OFFSET $2 LIMIT $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_loadSrfByRef", "SELECT sref FROM TblBrlyMLocation WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMLocation_loadTitByRef", "SELECT Title FROM TblBrlyMLocation WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMLocation::loadRec(
			PGresult* res
			, BrlyMLocation** rec
		) {
	char* ptr;

	BrlyMLocation* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMLocation();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "sreficao"),
			PQfnumber(res, "title"),
			PQfnumber(res, "alt"),
			PQfnumber(res, "theta"),
			PQfnumber(res, "phi"),
			PQfnumber(res, "tz"),
			PQfnumber(res, "alpha"),
			PQfnumber(res, "calcdone")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refBrlyMRegion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refBrlyMEquipment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefICAO.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->alt = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->theta = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->phi = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->tz.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->alpha = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Calcdone = (atoi(ptr) != 0);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMLocation::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMLocation& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMLocation* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "sreficao"),
			PQfnumber(res, "title"),
			PQfnumber(res, "alt"),
			PQfnumber(res, "theta"),
			PQfnumber(res, "phi"),
			PQfnumber(res, "tz"),
			PQfnumber(res, "alpha"),
			PQfnumber(res, "calcdone")
		};

		while (numread < numrow) {
			rec = new BrlyMLocation();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refBrlyMRegion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refBrlyMEquipment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefICAO.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->alt = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->theta = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->phi = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->tz.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->alpha = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Calcdone = (atoi(ptr) != 0);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMLocation::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMLocation** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLocation / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMLocation::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMLocation& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLocation / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMLocation::loadRecBySQL(
			const string& sqlstr
			, BrlyMLocation** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMLocation::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMLocation& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMLocation::insertRec(
			BrlyMLocation* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	string _alt = to_string(rec->alt);
	string _theta = to_string(rec->theta);
	string _phi = to_string(rec->phi);
	string _alpha = to_string(rec->alpha);
	smallint _Calcdone = htons((smallint) rec->Calcdone);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refBrlyMRegion,
		(char*) &_refBrlyMEquipment,
		rec->sref.c_str(),
		rec->srefICAO.c_str(),
		rec->Title.c_str(),
		_alt.c_str(),
		_theta.c_str(),
		_phi.c_str(),
		rec->tz.c_str(),
		_alpha.c_str(),
		(char*) &_Calcdone
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(smallint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMLocation_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLocation_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMLocation::insertRst(
			ListBrlyMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMLocation::updateRec(
			BrlyMLocation* rec
		) {
	PGresult* res;

	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	string _alt = to_string(rec->alt);
	string _theta = to_string(rec->theta);
	string _phi = to_string(rec->phi);
	string _alpha = to_string(rec->alpha);
	smallint _Calcdone = htons((smallint) rec->Calcdone);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixVBasetype,
		(char*) &_refBrlyMRegion,
		(char*) &_refBrlyMEquipment,
		rec->sref.c_str(),
		rec->srefICAO.c_str(),
		rec->Title.c_str(),
		_alt.c_str(),
		_theta.c_str(),
		_phi.c_str(),
		rec->tz.c_str(),
		_alpha.c_str(),
		(char*) &_Calcdone,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
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
	const int f[] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMLocation_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLocation_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMLocation::updateRst(
			ListBrlyMLocation& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMLocation::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMLocation_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMLocation_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMLocation::loadRecByRef(
			ubigint ref
			, BrlyMLocation** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMLocation_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMLocation::loadRecByEqp(
			ubigint refBrlyMEquipment
			, BrlyMLocation** rec
		) {
	ubigint _refBrlyMEquipment = htonl64(refBrlyMEquipment);

	const char* vals[] = {
		(char*) &_refBrlyMEquipment
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMLocation_loadRecByEqp", 1, vals, l, f, rec);
};

bool PgTblBrlyMLocation::loadRecBySrf(
			string sref
			, BrlyMLocation** rec
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRecByStmt("TblBrlyMLocation_loadRecBySrf", 1, vals, l, f, rec);
};

bool PgTblBrlyMLocation::loadRefBySrf(
			string sref
			, ubigint& ref
		) {

	const char* vals[] = {
		sref.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadRefByStmt("TblBrlyMLocation_loadRefBySrf", 1, vals, l, f, ref);
};

ubigint PgTblBrlyMLocation::loadRefsByReg(
			ubigint refBrlyMRegion
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);

	const char* vals[] = {
		(char*) &_refBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMLocation_loadRefsByReg", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMLocation::loadRst(
			const bool append
			, ListBrlyMLocation& rst
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

	return loadRstByStmt("TblBrlyMLocation_loadRst", 2, vals, l, f, append, rst);
};

ubigint PgTblBrlyMLocation::loadRstByReg(
			ubigint refBrlyMRegion
			, const bool append
			, ListBrlyMLocation& rst
		) {
	ubigint _refBrlyMRegion = htonl64(refBrlyMRegion);

	const char* vals[] = {
		(char*) &_refBrlyMRegion
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMLocation_loadRstByReg", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyMLocation::loadRstByTyp(
			uint ixVBasetype
			, const bool append
			, ListBrlyMLocation& rst
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

	return loadRstByStmt("TblBrlyMLocation_loadRstByTyp", 3, vals, l, f, append, rst);
};

bool PgTblBrlyMLocation::loadSrfByRef(
			ubigint ref
			, string& sref
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblBrlyMLocation_loadSrfByRef", 1, vals, l, f, sref);
};

bool PgTblBrlyMLocation::loadTitByRef(
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

	return loadStringByStmt("TblBrlyMLocation_loadTitByRef", 1, vals, l, f, Title);
};

