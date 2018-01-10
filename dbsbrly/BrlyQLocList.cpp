/**
  * \file BrlyQLocList.cpp
  * Dbs and XML wrapper for table TblBrlyQLocList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQLocList.h"

/******************************************************************************
 class BrlyQLocList
 ******************************************************************************/

BrlyQLocList::BrlyQLocList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string srefICAO
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refBrlyMRegion
			, const string stubRefBrlyMRegion
			, const ubigint refBrlyMEquipment
			, const string stubRefBrlyMEquipment
			, const double alt
			, const double theta
			, const double phi
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->srefICAO = srefICAO;
	this->Title = Title;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->refBrlyMRegion = refBrlyMRegion;
	this->stubRefBrlyMRegion = stubRefBrlyMRegion;
	this->refBrlyMEquipment = refBrlyMEquipment;
	this->stubRefBrlyMEquipment = stubRefBrlyMEquipment;
	this->alt = alt;
	this->theta = theta;
	this->phi = phi;
};

void BrlyQLocList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQLocList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "ica", srefICAO);
		writeString(wr, "tit", Title);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "reg", stubRefBrlyMRegion);
		writeString(wr, "eqp", stubRefBrlyMEquipment);
		writeDouble(wr, "alt", alt);
		writeDouble(wr, "the", theta);
		writeDouble(wr, "phi", phi);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefICAO", srefICAO);
		writeString(wr, "Title", Title);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubRefBrlyMRegion", stubRefBrlyMRegion);
		writeString(wr, "stubRefBrlyMEquipment", stubRefBrlyMEquipment);
		writeDouble(wr, "alt", alt);
		writeDouble(wr, "theta", theta);
		writeDouble(wr, "phi", phi);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQLocList
 ******************************************************************************/

ListBrlyQLocList::ListBrlyQLocList() {
};

ListBrlyQLocList::ListBrlyQLocList(
			const ListBrlyQLocList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQLocList(*(src.nodes[i]));
};

ListBrlyQLocList::~ListBrlyQLocList() {
	clear();
};

void ListBrlyQLocList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQLocList::size() const {
	return(nodes.size());
};

void ListBrlyQLocList::append(
			BrlyQLocList* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQLocList& ListBrlyQLocList::operator=(
			const ListBrlyQLocList& src
		) {
	BrlyQLocList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQLocList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQLocList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQLocList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQLocList
 ******************************************************************************/

TblBrlyQLocList::TblBrlyQLocList() {
};

TblBrlyQLocList::~TblBrlyQLocList() {
};

bool TblBrlyQLocList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocList** rec
		) {
	return false;
};

ubigint TblBrlyQLocList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocList& rst
		) {
	return 0;
};

void TblBrlyQLocList::insertRec(
			BrlyQLocList* rec
		) {
};

ubigint TblBrlyQLocList::insertNewRec(
			BrlyQLocList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string srefICAO
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refBrlyMRegion
			, const string stubRefBrlyMRegion
			, const ubigint refBrlyMEquipment
			, const string stubRefBrlyMEquipment
			, const double alt
			, const double theta
			, const double phi
		) {
	ubigint retval = 0;
	BrlyQLocList* _rec = NULL;

	_rec = new BrlyQLocList(0, jref, jnum, ref, sref, srefICAO, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, refBrlyMRegion, stubRefBrlyMRegion, refBrlyMEquipment, stubRefBrlyMEquipment, alt, theta, phi);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQLocList::appendNewRecToRst(
			ListBrlyQLocList& rst
			, BrlyQLocList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const string srefICAO
			, const string Title
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint refBrlyMRegion
			, const string stubRefBrlyMRegion
			, const ubigint refBrlyMEquipment
			, const string stubRefBrlyMEquipment
			, const double alt
			, const double theta
			, const double phi
		) {
	ubigint retval = 0;
	BrlyQLocList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, srefICAO, Title, ixVBasetype, srefIxVBasetype, titIxVBasetype, refBrlyMRegion, stubRefBrlyMRegion, refBrlyMEquipment, stubRefBrlyMEquipment, alt, theta, phi);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQLocList::insertRst(
			ListBrlyQLocList& rst
		) {
};

void TblBrlyQLocList::updateRec(
			BrlyQLocList* rec
		) {
};

void TblBrlyQLocList::updateRst(
			ListBrlyQLocList& rst
		) {
};

void TblBrlyQLocList::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQLocList::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQLocList::loadRecByQref(
			ubigint qref
			, BrlyQLocList** rec
		) {
	return false;
};

ubigint TblBrlyQLocList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocList& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQLocList
 ******************************************************************************/

MyTblBrlyQLocList::MyTblBrlyQLocList() : TblBrlyQLocList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQLocList::~MyTblBrlyQLocList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQLocList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQLocList (jref, jnum, ref, sref, srefICAO, Title, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, alt, theta, phi) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQLocList SET jref = ?, jnum = ?, ref = ?, sref = ?, srefICAO = ?, Title = ?, ixVBasetype = ?, refBrlyMRegion = ?, refBrlyMEquipment = ?, alt = ?, theta = ?, phi = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQLocList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQLocList WHERE jref = ?", false);
};

bool MyTblBrlyQLocList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQLocList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLocList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyQLocList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->srefICAO.assign(dbrow[5], dblengths[5]); else _rec->srefICAO = "";
		if (dbrow[6]) _rec->Title.assign(dbrow[6], dblengths[6]); else _rec->Title = "";
		if (dbrow[7]) _rec->ixVBasetype = atol((char*) dbrow[7]); else _rec->ixVBasetype = 0;
		if (dbrow[8]) _rec->refBrlyMRegion = atoll((char*) dbrow[8]); else _rec->refBrlyMRegion = 0;
		if (dbrow[9]) _rec->refBrlyMEquipment = atoll((char*) dbrow[9]); else _rec->refBrlyMEquipment = 0;
		if (dbrow[10]) _rec->alt = atof((char*) dbrow[10]); else _rec->alt = 0.0;
		if (dbrow[11]) _rec->theta = atof((char*) dbrow[11]); else _rec->theta = 0.0;
		if (dbrow[12]) _rec->phi = atof((char*) dbrow[12]); else _rec->phi = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQLocList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQLocList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQLocList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyQLocList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->srefICAO.assign(dbrow[5], dblengths[5]); else rec->srefICAO = "";
			if (dbrow[6]) rec->Title.assign(dbrow[6], dblengths[6]); else rec->Title = "";
			if (dbrow[7]) rec->ixVBasetype = atol((char*) dbrow[7]); else rec->ixVBasetype = 0;
			if (dbrow[8]) rec->refBrlyMRegion = atoll((char*) dbrow[8]); else rec->refBrlyMRegion = 0;
			if (dbrow[9]) rec->refBrlyMEquipment = atoll((char*) dbrow[9]); else rec->refBrlyMEquipment = 0;
			if (dbrow[10]) rec->alt = atof((char*) dbrow[10]); else rec->alt = 0.0;
			if (dbrow[11]) rec->theta = atof((char*) dbrow[11]); else rec->theta = 0.0;
			if (dbrow[12]) rec->phi = atof((char*) dbrow[12]); else rec->phi = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQLocList::insertRec(
			BrlyQLocList* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[3] = rec->sref.length();
	l[4] = rec->srefICAO.length();
	l[5] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefICAO.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVBasetype,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refBrlyMRegion,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->alt,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->theta,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->phi,&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQLocList::insertRst(
			ListBrlyQLocList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQLocList::updateRec(
			BrlyQLocList* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[3] = rec->sref.length();
	l[4] = rec->srefICAO.length();
	l[5] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->srefICAO.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Title.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->ixVBasetype,&(l[6]),&(n[6]),&(e[6])),
		bindUbigint(&rec->refBrlyMRegion,&(l[7]),&(n[7]),&(e[7])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->alt,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->theta,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->phi,&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->qref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocList / stmtUpdateRec)\n");
};

void MyTblBrlyQLocList::updateRst(
			ListBrlyQLocList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQLocList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocList / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQLocList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQLocList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQLocList / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQLocList::loadRecByQref(
			ubigint qref
			, BrlyQLocList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQLocList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQLocList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQLocList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQLocList
 ******************************************************************************/

PgTblBrlyQLocList::PgTblBrlyQLocList() : TblBrlyQLocList(), PgTable() {
};

PgTblBrlyQLocList::~PgTblBrlyQLocList() {
};

void PgTblBrlyQLocList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQLocList_insertRec", "INSERT INTO TblBrlyQLocList (jref, jnum, ref, sref, srefICAO, Title, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, alt, theta, phi) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING qref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocList_updateRec", "UPDATE TblBrlyQLocList SET jref = $1, jnum = $2, ref = $3, sref = $4, srefICAO = $5, Title = $6, ixVBasetype = $7, refBrlyMRegion = $8, refBrlyMEquipment = $9, alt = $10, theta = $11, phi = $12 WHERE qref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocList_removeRecByQref", "DELETE FROM TblBrlyQLocList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocList_removeRstByJref", "DELETE FROM TblBrlyQLocList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQLocList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, srefICAO, Title, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, alt, theta, phi FROM TblBrlyQLocList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQLocList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, srefICAO, Title, ixVBasetype, refBrlyMRegion, refBrlyMEquipment, alt, theta, phi FROM TblBrlyQLocList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQLocList::loadRec(
			PGresult* res
			, BrlyQLocList** rec
		) {
	char* ptr;

	BrlyQLocList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQLocList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "sreficao"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "alt"),
			PQfnumber(res, "theta"),
			PQfnumber(res, "phi")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->srefICAO.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->refBrlyMRegion = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->refBrlyMEquipment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->alt = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->theta = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->phi = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQLocList::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQLocList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQLocList* rec;

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
			PQfnumber(res, "sreficao"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "refbrlymregion"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "alt"),
			PQfnumber(res, "theta"),
			PQfnumber(res, "phi")
		};

		while (numread < numrow) {
			rec = new BrlyQLocList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->srefICAO.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->refBrlyMRegion = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->refBrlyMEquipment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->alt = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->theta = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->phi = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQLocList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQLocList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQLocList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQLocList::loadRecBySQL(
			const string& sqlstr
			, BrlyQLocList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQLocList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQLocList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQLocList::insertRec(
			BrlyQLocList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	string _alt = to_string(rec->alt);
	string _theta = to_string(rec->theta);
	string _phi = to_string(rec->phi);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->srefICAO.c_str(),
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refBrlyMRegion,
		(char*) &_refBrlyMEquipment,
		_alt.c_str(),
		_theta.c_str(),
		_phi.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblBrlyQLocList_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQLocList::insertRst(
			ListBrlyQLocList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQLocList::updateRec(
			BrlyQLocList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _refBrlyMRegion = htonl64(rec->refBrlyMRegion);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	string _alt = to_string(rec->alt);
	string _theta = to_string(rec->theta);
	string _phi = to_string(rec->phi);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		rec->srefICAO.c_str(),
		rec->Title.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_refBrlyMRegion,
		(char*) &_refBrlyMEquipment,
		_alt.c_str(),
		_theta.c_str(),
		_phi.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQLocList_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocList_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQLocList::updateRst(
			ListBrlyQLocList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQLocList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQLocList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQLocList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQLocList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQLocList::loadRecByQref(
			ubigint qref
			, BrlyQLocList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQLocList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQLocList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQLocList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQLocList_loadRstByJref", 1, vals, l, f, append, rst);
};

