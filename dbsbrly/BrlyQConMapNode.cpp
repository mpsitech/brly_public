/**
  * \file BrlyQConMapNode.cpp
  * Dbs and XML wrapper for table TblBrlyQConMapNode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyQConMapNode.h"

/******************************************************************************
 class BrlyQConMapNode
 ******************************************************************************/

BrlyQConMapNode::BrlyQConMapNode(
			const ubigint qref
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const ubigint refBrlyMRelay
			, const ubigint supRefBrlyMNode
			, const ubigint refBrlyMEquipment
			, const int jnumRly
			, const double x0
			, const double y0
			, const double u0
			, const double v0
			, const int t0
			, const double dx
			, const double dy
			, const double du
			, const double dv
			, const int dt
		) {
	this->qref = qref;
	this->qwr = qwr;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
	this->refBrlyMRelay = refBrlyMRelay;
	this->supRefBrlyMNode = supRefBrlyMNode;
	this->refBrlyMEquipment = refBrlyMEquipment;
	this->jnumRly = jnumRly;
	this->x0 = x0;
	this->y0 = y0;
	this->u0 = u0;
	this->v0 = v0;
	this->t0 = t0;
	this->dx = dx;
	this->dy = dy;
	this->du = du;
	this->dv = dv;
	this->dt = dt;
};

void BrlyQConMapNode::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "BrlyQConMapNode";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
		writeInt(wr, "jnr", jnumRly);
		writeDouble(wr, "x0", x0);
		writeDouble(wr, "y0", y0);
		writeDouble(wr, "u0", u0);
		writeDouble(wr, "v0", v0);
		writeInt(wr, "t0", t0);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
		writeDouble(wr, "du", du);
		writeDouble(wr, "dv", dv);
		writeInt(wr, "dt", dt);
	} else {
		writeString(wr, "stubRef", stubRef);
		writeInt(wr, "jnumRly", jnumRly);
		writeDouble(wr, "x0", x0);
		writeDouble(wr, "y0", y0);
		writeDouble(wr, "u0", u0);
		writeDouble(wr, "v0", v0);
		writeInt(wr, "t0", t0);
		writeDouble(wr, "dx", dx);
		writeDouble(wr, "dy", dy);
		writeDouble(wr, "du", du);
		writeDouble(wr, "dv", dv);
		writeInt(wr, "dt", dt);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListBrlyQConMapNode
 ******************************************************************************/

ListBrlyQConMapNode::ListBrlyQConMapNode() {
};

ListBrlyQConMapNode::ListBrlyQConMapNode(
			const ListBrlyQConMapNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyQConMapNode(*(src.nodes[i]));
};

ListBrlyQConMapNode::~ListBrlyQConMapNode() {
	clear();
};

void ListBrlyQConMapNode::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyQConMapNode::size() const {
	return(nodes.size());
};

void ListBrlyQConMapNode::append(
			BrlyQConMapNode* rec
		) {
	nodes.push_back(rec);
};

ListBrlyQConMapNode& ListBrlyQConMapNode::operator=(
			const ListBrlyQConMapNode& src
		) {
	BrlyQConMapNode* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyQConMapNode(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListBrlyQConMapNode::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListBrlyQConMapNode";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]->qwr) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblBrlyQConMapNode
 ******************************************************************************/

TblBrlyQConMapNode::TblBrlyQConMapNode() {
};

TblBrlyQConMapNode::~TblBrlyQConMapNode() {
};

bool TblBrlyQConMapNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapNode** rec
		) {
	return false;
};

ubigint TblBrlyQConMapNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapNode& rst
		) {
	return 0;
};

void TblBrlyQConMapNode::insertRec(
			BrlyQConMapNode* rec
		) {
};

ubigint TblBrlyQConMapNode::insertNewRec(
			BrlyQConMapNode** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const ubigint refBrlyMRelay
			, const ubigint supRefBrlyMNode
			, const ubigint refBrlyMEquipment
			, const int jnumRly
			, const double x0
			, const double y0
			, const double u0
			, const double v0
			, const int t0
			, const double dx
			, const double dy
			, const double du
			, const double dv
			, const int dt
		) {
	ubigint retval = 0;
	BrlyQConMapNode* _rec = NULL;

	_rec = new BrlyQConMapNode(0, qwr, jref, jnum, ref, stubRef, refBrlyMRelay, supRefBrlyMNode, refBrlyMEquipment, jnumRly, x0, y0, u0, v0, t0, dx, dy, du, dv, dt);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyQConMapNode::appendNewRecToRst(
			ListBrlyQConMapNode& rst
			, BrlyQConMapNode** rec
			, const bool qwr
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
			, const ubigint refBrlyMRelay
			, const ubigint supRefBrlyMNode
			, const ubigint refBrlyMEquipment
			, const int jnumRly
			, const double x0
			, const double y0
			, const double u0
			, const double v0
			, const int t0
			, const double dx
			, const double dy
			, const double du
			, const double dv
			, const int dt
		) {
	ubigint retval = 0;
	BrlyQConMapNode* _rec = NULL;

	retval = insertNewRec(&_rec, qwr, jref, jnum, ref, stubRef, refBrlyMRelay, supRefBrlyMNode, refBrlyMEquipment, jnumRly, x0, y0, u0, v0, t0, dx, dy, du, dv, dt);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyQConMapNode::insertRst(
			ListBrlyQConMapNode& rst
		) {
};

void TblBrlyQConMapNode::updateRec(
			BrlyQConMapNode* rec
		) {
};

void TblBrlyQConMapNode::updateRst(
			ListBrlyQConMapNode& rst
		) {
};

void TblBrlyQConMapNode::removeRecByQref(
			ubigint qref
		) {
};

void TblBrlyQConMapNode::removeRstByJref(
			ubigint jref
		) {
};

bool TblBrlyQConMapNode::loadRecByQref(
			ubigint qref
			, BrlyQConMapNode** rec
		) {
	return false;
};

ubigint TblBrlyQConMapNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapNode& rst
		) {
	return 0;
};

/******************************************************************************
 class MyTblBrlyQConMapNode
 ******************************************************************************/

MyTblBrlyQConMapNode::MyTblBrlyQConMapNode() : TblBrlyQConMapNode(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblBrlyQConMapNode::~MyTblBrlyQConMapNode() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblBrlyQConMapNode::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyQConMapNode (qwr, jref, jnum, ref, refBrlyMRelay, supRefBrlyMNode, refBrlyMEquipment, jnumRly, x0, y0, u0, v0, t0, dx, dy, du, dv, dt) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyQConMapNode SET qwr = ?, jref = ?, jnum = ?, ref = ?, refBrlyMRelay = ?, supRefBrlyMNode = ?, refBrlyMEquipment = ?, jnumRly = ?, x0 = ?, y0 = ?, u0 = ?, v0 = ?, t0 = ?, dx = ?, dy = ?, du = ?, dv = ?, dt = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblBrlyQConMapNode WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblBrlyQConMapNode WHERE jref = ?", false);
};

bool MyTblBrlyQConMapNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapNode** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyQConMapNode* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapNode / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyQConMapNode();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->qwr = (atoi((char*) dbrow[1]) != 0); else _rec->qwr = false;
		if (dbrow[2]) _rec->jref = atoll((char*) dbrow[2]); else _rec->jref = 0;
		if (dbrow[3]) _rec->jnum = atol((char*) dbrow[3]); else _rec->jnum = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->refBrlyMRelay = atoll((char*) dbrow[5]); else _rec->refBrlyMRelay = 0;
		if (dbrow[6]) _rec->supRefBrlyMNode = atoll((char*) dbrow[6]); else _rec->supRefBrlyMNode = 0;
		if (dbrow[7]) _rec->refBrlyMEquipment = atoll((char*) dbrow[7]); else _rec->refBrlyMEquipment = 0;
		if (dbrow[8]) _rec->jnumRly = atol((char*) dbrow[8]); else _rec->jnumRly = 0;
		if (dbrow[9]) _rec->x0 = atof((char*) dbrow[9]); else _rec->x0 = 0.0;
		if (dbrow[10]) _rec->y0 = atof((char*) dbrow[10]); else _rec->y0 = 0.0;
		if (dbrow[11]) _rec->u0 = atof((char*) dbrow[11]); else _rec->u0 = 0.0;
		if (dbrow[12]) _rec->v0 = atof((char*) dbrow[12]); else _rec->v0 = 0.0;
		if (dbrow[13]) _rec->t0 = atol((char*) dbrow[13]); else _rec->t0 = 0;
		if (dbrow[14]) _rec->dx = atof((char*) dbrow[14]); else _rec->dx = 0.0;
		if (dbrow[15]) _rec->dy = atof((char*) dbrow[15]); else _rec->dy = 0.0;
		if (dbrow[16]) _rec->du = atof((char*) dbrow[16]); else _rec->du = 0.0;
		if (dbrow[17]) _rec->dv = atof((char*) dbrow[17]); else _rec->dv = 0.0;
		if (dbrow[18]) _rec->dt = atol((char*) dbrow[18]); else _rec->dt = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyQConMapNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapNode& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyQConMapNode* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyQConMapNode / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyQConMapNode();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->qwr = (atoi((char*) dbrow[1]) != 0); else rec->qwr = false;
			if (dbrow[2]) rec->jref = atoll((char*) dbrow[2]); else rec->jref = 0;
			if (dbrow[3]) rec->jnum = atol((char*) dbrow[3]); else rec->jnum = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->refBrlyMRelay = atoll((char*) dbrow[5]); else rec->refBrlyMRelay = 0;
			if (dbrow[6]) rec->supRefBrlyMNode = atoll((char*) dbrow[6]); else rec->supRefBrlyMNode = 0;
			if (dbrow[7]) rec->refBrlyMEquipment = atoll((char*) dbrow[7]); else rec->refBrlyMEquipment = 0;
			if (dbrow[8]) rec->jnumRly = atol((char*) dbrow[8]); else rec->jnumRly = 0;
			if (dbrow[9]) rec->x0 = atof((char*) dbrow[9]); else rec->x0 = 0.0;
			if (dbrow[10]) rec->y0 = atof((char*) dbrow[10]); else rec->y0 = 0.0;
			if (dbrow[11]) rec->u0 = atof((char*) dbrow[11]); else rec->u0 = 0.0;
			if (dbrow[12]) rec->v0 = atof((char*) dbrow[12]); else rec->v0 = 0.0;
			if (dbrow[13]) rec->t0 = atol((char*) dbrow[13]); else rec->t0 = 0;
			if (dbrow[14]) rec->dx = atof((char*) dbrow[14]); else rec->dx = 0.0;
			if (dbrow[15]) rec->dy = atof((char*) dbrow[15]); else rec->dy = 0.0;
			if (dbrow[16]) rec->du = atof((char*) dbrow[16]); else rec->du = 0.0;
			if (dbrow[17]) rec->dv = atof((char*) dbrow[17]); else rec->dv = 0.0;
			if (dbrow[18]) rec->dt = atol((char*) dbrow[18]); else rec->dt = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyQConMapNode::insertRec(
			BrlyQConMapNode* rec
		) {
	unsigned long l[18]; my_bool n[18]; my_bool e[18];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMRelay,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefBrlyMNode,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[6]),&(n[6]),&(e[6])),
		bindInt(&rec->jnumRly,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->x0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->y0,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->u0,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->v0,&(l[11]),&(n[11]),&(e[11])),
		bindInt(&rec->t0,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->dx,&(l[13]),&(n[13]),&(e[13])),
		bindDouble(&rec->dy,&(l[14]),&(n[14]),&(e[14])),
		bindDouble(&rec->du,&(l[15]),&(n[15]),&(e[15])),
		bindDouble(&rec->dv,&(l[16]),&(n[16]),&(e[16])),
		bindInt(&rec->dt,&(l[17]),&(n[17]),&(e[17]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapNode / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapNode / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyQConMapNode::insertRst(
			ListBrlyQConMapNode& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyQConMapNode::updateRec(
			BrlyQConMapNode* rec
		) {
	unsigned long l[19]; my_bool n[19]; my_bool e[19];

	tinyint qwr = rec->qwr;

	MYSQL_BIND bind[] = {
		bindTinyint(&qwr,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->jref,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->jnum,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMRelay,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefBrlyMNode,&(l[5]),&(n[5]),&(e[5])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[6]),&(n[6]),&(e[6])),
		bindInt(&rec->jnumRly,&(l[7]),&(n[7]),&(e[7])),
		bindDouble(&rec->x0,&(l[8]),&(n[8]),&(e[8])),
		bindDouble(&rec->y0,&(l[9]),&(n[9]),&(e[9])),
		bindDouble(&rec->u0,&(l[10]),&(n[10]),&(e[10])),
		bindDouble(&rec->v0,&(l[11]),&(n[11]),&(e[11])),
		bindInt(&rec->t0,&(l[12]),&(n[12]),&(e[12])),
		bindDouble(&rec->dx,&(l[13]),&(n[13]),&(e[13])),
		bindDouble(&rec->dy,&(l[14]),&(n[14]),&(e[14])),
		bindDouble(&rec->du,&(l[15]),&(n[15]),&(e[15])),
		bindDouble(&rec->dv,&(l[16]),&(n[16]),&(e[16])),
		bindInt(&rec->dt,&(l[17]),&(n[17]),&(e[17])),
		bindUbigint(&rec->qref,&(l[18]),&(n[18]),&(e[18]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapNode / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapNode / stmtUpdateRec)\n");
};

void MyTblBrlyQConMapNode::updateRst(
			ListBrlyQConMapNode& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyQConMapNode::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapNode / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapNode / stmtRemoveRecByQref)\n");
};

void MyTblBrlyQConMapNode::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyQConMapNode / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyQConMapNode / stmtRemoveRstByJref)\n");
};

bool MyTblBrlyQConMapNode::loadRecByQref(
			ubigint qref
			, BrlyQConMapNode** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyQConMapNode WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblBrlyQConMapNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapNode& rst
		) {
	return loadRstBySQL("SELECT * FROM TblBrlyQConMapNode WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyQConMapNode
 ******************************************************************************/

PgTblBrlyQConMapNode::PgTblBrlyQConMapNode() : TblBrlyQConMapNode(), PgTable() {
};

PgTblBrlyQConMapNode::~PgTblBrlyQConMapNode() {
};

void PgTblBrlyQConMapNode::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyQConMapNode_insertRec", "INSERT INTO TblBrlyQConMapNode (qwr, jref, jnum, ref, refBrlyMRelay, supRefBrlyMNode, refBrlyMEquipment, jnumRly, x0, y0, u0, v0, t0, dx, dy, du, dv, dt) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18) RETURNING qref", 18, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapNode_updateRec", "UPDATE TblBrlyQConMapNode SET qwr = $1, jref = $2, jnum = $3, ref = $4, refBrlyMRelay = $5, supRefBrlyMNode = $6, refBrlyMEquipment = $7, jnumRly = $8, x0 = $9, y0 = $10, u0 = $11, v0 = $12, t0 = $13, dx = $14, dy = $15, du = $16, dv = $17, dt = $18 WHERE qref = $19", 19, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapNode_removeRecByQref", "DELETE FROM TblBrlyQConMapNode WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapNode_removeRstByJref", "DELETE FROM TblBrlyQConMapNode WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyQConMapNode_loadRecByQref", "SELECT qref, qwr, jref, jnum, ref, refBrlyMRelay, supRefBrlyMNode, refBrlyMEquipment, jnumRly, x0, y0, u0, v0, t0, dx, dy, du, dv, dt FROM TblBrlyQConMapNode WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyQConMapNode_loadRstByJref", "SELECT qref, qwr, jref, jnum, ref, refBrlyMRelay, supRefBrlyMNode, refBrlyMEquipment, jnumRly, x0, y0, u0, v0, t0, dx, dy, du, dv, dt FROM TblBrlyQConMapNode WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyQConMapNode::loadRec(
			PGresult* res
			, BrlyQConMapNode** rec
		) {
	char* ptr;

	BrlyQConMapNode* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyQConMapNode();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymrelay"),
			PQfnumber(res, "suprefbrlymnode"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "jnumrly"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "u0"),
			PQfnumber(res, "v0"),
			PQfnumber(res, "t0"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "du"),
			PQfnumber(res, "dv"),
			PQfnumber(res, "dt")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->qwr = (atoi(ptr) != 0);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refBrlyMRelay = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->supRefBrlyMNode = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->refBrlyMEquipment = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->jnumRly = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->x0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->y0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->u0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->v0 = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->t0 = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[14]); _rec->dx = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[15]); _rec->dy = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[16]); _rec->du = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[17]); _rec->dv = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[18]); _rec->dt = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyQConMapNode::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyQConMapNode& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyQConMapNode* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "qwr"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymrelay"),
			PQfnumber(res, "suprefbrlymnode"),
			PQfnumber(res, "refbrlymequipment"),
			PQfnumber(res, "jnumrly"),
			PQfnumber(res, "x0"),
			PQfnumber(res, "y0"),
			PQfnumber(res, "u0"),
			PQfnumber(res, "v0"),
			PQfnumber(res, "t0"),
			PQfnumber(res, "dx"),
			PQfnumber(res, "dy"),
			PQfnumber(res, "du"),
			PQfnumber(res, "dv"),
			PQfnumber(res, "dt")
		};

		while (numread < numrow) {
			rec = new BrlyQConMapNode();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->qwr = (atoi(ptr) != 0);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refBrlyMRelay = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->supRefBrlyMNode = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->refBrlyMEquipment = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->jnumRly = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[9]); rec->x0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[10]); rec->y0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[11]); rec->u0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->v0 = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[13]); rec->t0 = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[14]); rec->dx = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[15]); rec->dy = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[16]); rec->du = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[17]); rec->dv = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[18]); rec->dt = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyQConMapNode::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyQConMapNode** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapNode / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapNode::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyQConMapNode& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapNode / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyQConMapNode::loadRecBySQL(
			const string& sqlstr
			, BrlyQConMapNode** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyQConMapNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyQConMapNode& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyQConMapNode::insertRec(
			BrlyQConMapNode* rec
		) {
	PGresult* res;
	char* ptr;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refBrlyMRelay = htonl64(rec->refBrlyMRelay);
	ubigint _supRefBrlyMNode = htonl64(rec->supRefBrlyMNode);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	int _jnumRly = htonl(rec->jnumRly);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	string _u0 = to_string(rec->u0);
	string _v0 = to_string(rec->v0);
	int _t0 = htonl(rec->t0);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	string _du = to_string(rec->du);
	string _dv = to_string(rec->dv);
	int _dt = htonl(rec->dt);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refBrlyMRelay,
		(char*) &_supRefBrlyMNode,
		(char*) &_refBrlyMEquipment,
		(char*) &_jnumRly,
		_x0.c_str(),
		_y0.c_str(),
		_u0.c_str(),
		_v0.c_str(),
		(char*) &_t0,
		_dx.c_str(),
		_dy.c_str(),
		_du.c_str(),
		_dv.c_str(),
		(char*) &_dt
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(int),
		0,
		0,
		0,
		0,
		sizeof(int),
		0,
		0,
		0,
		0,
		sizeof(int)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMapNode_insertRec", 18, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapNode_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyQConMapNode::insertRst(
			ListBrlyQConMapNode& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyQConMapNode::updateRec(
			BrlyQConMapNode* rec
		) {
	PGresult* res;

	smallint _qwr = htons((smallint) rec->qwr);
	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _refBrlyMRelay = htonl64(rec->refBrlyMRelay);
	ubigint _supRefBrlyMNode = htonl64(rec->supRefBrlyMNode);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	int _jnumRly = htonl(rec->jnumRly);
	string _x0 = to_string(rec->x0);
	string _y0 = to_string(rec->y0);
	string _u0 = to_string(rec->u0);
	string _v0 = to_string(rec->v0);
	int _t0 = htonl(rec->t0);
	string _dx = to_string(rec->dx);
	string _dy = to_string(rec->dy);
	string _du = to_string(rec->du);
	string _dv = to_string(rec->dv);
	int _dt = htonl(rec->dt);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_qwr,
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_refBrlyMRelay,
		(char*) &_supRefBrlyMNode,
		(char*) &_refBrlyMEquipment,
		(char*) &_jnumRly,
		_x0.c_str(),
		_y0.c_str(),
		_u0.c_str(),
		_v0.c_str(),
		(char*) &_t0,
		_dx.c_str(),
		_dy.c_str(),
		_du.c_str(),
		_dv.c_str(),
		(char*) &_dt,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(smallint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(int),
		0,
		0,
		0,
		0,
		sizeof(int),
		0,
		0,
		0,
		0,
		sizeof(int),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyQConMapNode_updateRec", 19, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapNode_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyQConMapNode::updateRst(
			ListBrlyQConMapNode& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyQConMapNode::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapNode_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapNode_removeRecByQref)\n");

	PQclear(res);
};

void PgTblBrlyQConMapNode::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblBrlyQConMapNode_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyQConMapNode_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblBrlyQConMapNode::loadRecByQref(
			ubigint qref
			, BrlyQConMapNode** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyQConMapNode_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblBrlyQConMapNode::loadRstByJref(
			ubigint jref
			, const bool append
			, ListBrlyQConMapNode& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyQConMapNode_loadRstByJref", 1, vals, l, f, append, rst);
};

