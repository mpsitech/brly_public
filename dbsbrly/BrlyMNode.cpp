/**
  * \file BrlyMNode.cpp
  * database access for table TblBrlyMNode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMNode.h"

/******************************************************************************
 class BrlyMNode
 ******************************************************************************/

BrlyMNode::BrlyMNode(
			const ubigint ref
			, const ubigint refBrlyMRelay
			, const ubigint supRefBrlyMNode
			, const usmallint supLvl
			, const uint supNum
			, const ubigint refBrlyMEquipment
		) {

	this->ref = ref;
	this->refBrlyMRelay = refBrlyMRelay;
	this->supRefBrlyMNode = supRefBrlyMNode;
	this->supLvl = supLvl;
	this->supNum = supNum;
	this->refBrlyMEquipment = refBrlyMEquipment;
};

bool BrlyMNode::operator==(
			const BrlyMNode& comp
		) {
	return false;
};

bool BrlyMNode::operator!=(
			const BrlyMNode& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMNode
 ******************************************************************************/

ListBrlyMNode::ListBrlyMNode() {
};

ListBrlyMNode::ListBrlyMNode(
			const ListBrlyMNode& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMNode(*(src.nodes[i]));
};

ListBrlyMNode::~ListBrlyMNode() {
	clear();
};

void ListBrlyMNode::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMNode::size() const {
	return(nodes.size());
};

void ListBrlyMNode::append(
			BrlyMNode* rec
		) {
	nodes.push_back(rec);
};

BrlyMNode* ListBrlyMNode::operator[](
			const uint ix
		) {
	BrlyMNode* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMNode& ListBrlyMNode::operator=(
			const ListBrlyMNode& src
		) {
	BrlyMNode* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMNode(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMNode::operator==(
			const ListBrlyMNode& comp
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

bool ListBrlyMNode::operator!=(
			const ListBrlyMNode& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMNode
 ******************************************************************************/

TblBrlyMNode::TblBrlyMNode() {
};

TblBrlyMNode::~TblBrlyMNode() {
};

bool TblBrlyMNode::loadRecBySQL(
			const string& sqlstr
			, BrlyMNode** rec
		) {
	return false;
};

ubigint TblBrlyMNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMNode& rst
		) {
	return 0;
};

void TblBrlyMNode::insertRec(
			BrlyMNode* rec
		) {
};

ubigint TblBrlyMNode::insertNewRec(
			BrlyMNode** rec
			, const ubigint refBrlyMRelay
			, const ubigint supRefBrlyMNode
			, const usmallint supLvl
			, const uint supNum
			, const ubigint refBrlyMEquipment
		) {
	ubigint retval = 0;
	BrlyMNode* _rec = NULL;

	_rec = new BrlyMNode(0, refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMNode::appendNewRecToRst(
			ListBrlyMNode& rst
			, BrlyMNode** rec
			, const ubigint refBrlyMRelay
			, const ubigint supRefBrlyMNode
			, const usmallint supLvl
			, const uint supNum
			, const ubigint refBrlyMEquipment
		) {
	ubigint retval = 0;
	BrlyMNode* _rec = NULL;

	retval = insertNewRec(&_rec, refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMNode::insertRst(
			ListBrlyMNode& rst
			, bool transact
		) {
};

void TblBrlyMNode::updateRec(
			BrlyMNode* rec
		) {
};

void TblBrlyMNode::updateRst(
			ListBrlyMNode& rst
			, bool transact
		) {
};

void TblBrlyMNode::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMNode::loadRecByRef(
			ubigint ref
			, BrlyMNode** rec
		) {
	return false;
};

bool TblBrlyMNode::confirmByRef(
			ubigint ref
		) {
	return false;
};

ubigint TblBrlyMNode::loadRefsBySup(
			ubigint supRefBrlyMNode
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMNode::loadRstByRly(
			ubigint refBrlyMRelay
			, const bool append
			, ListBrlyMNode& rst
		) {
	return 0;
};

ubigint TblBrlyMNode::loadRstBySup(
			ubigint supRefBrlyMNode
			, const bool append
			, ListBrlyMNode& rst
		) {
	return 0;
};

bool TblBrlyMNode::loadSupByRef(
			ubigint ref
			, ubigint& supRefBrlyMNode
		) {
	return false;
};

ubigint TblBrlyMNode::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMNode& rst
		) {
	ubigint numload = 0;
	BrlyMNode* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

ubigint TblBrlyMNode::loadHrefsup(
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

ubigint TblBrlyMNode::loadHrefsdown(
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

ubigint TblBrlyMNode::loadHrstup(
			ubigint ref
			, ListBrlyMNode& rst
		) {
	BrlyMNode* rec = NULL;

	rst.clear();
	ubigint retval = 0;

	while (loadRecByRef(ref, &rec)) {
		rst.nodes.push_back(rec);
		retval++;

		ref = rec->supRefBrlyMNode;
		if (ref == 0) break;
	};

	return retval;
};

ubigint TblBrlyMNode::loadHrstdown(
			ubigint ref
			, const bool append
			, ListBrlyMNode& rst
			, unsigned int firstix
			, unsigned int lastix
		) {
	BrlyMNode* rec = NULL;

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
 class MyTblBrlyMNode
 ******************************************************************************/

MyTblBrlyMNode::MyTblBrlyMNode() : TblBrlyMNode(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMNode::~MyTblBrlyMNode() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMNode::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMNode (refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMNode SET refBrlyMRelay = ?, supRefBrlyMNode = ?, supLvl = ?, supNum = ?, refBrlyMEquipment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMNode WHERE ref = ?", false);
};

bool MyTblBrlyMNode::loadRecBySQL(
			const string& sqlstr
			, BrlyMNode** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMNode* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMNode / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);

		_rec = new BrlyMNode();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refBrlyMRelay = atoll((char*) dbrow[1]); else _rec->refBrlyMRelay = 0;
		if (dbrow[2]) _rec->supRefBrlyMNode = atoll((char*) dbrow[2]); else _rec->supRefBrlyMNode = 0;
		if (dbrow[3]) _rec->supLvl = atoi((char*) dbrow[3]); else _rec->supLvl = 0;
		if (dbrow[4]) _rec->supNum = atol((char*) dbrow[4]); else _rec->supNum = 0;
		if (dbrow[5]) _rec->refBrlyMEquipment = atoll((char*) dbrow[5]); else _rec->refBrlyMEquipment = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMNode& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMNode* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMNode / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);

			rec = new BrlyMNode();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refBrlyMRelay = atoll((char*) dbrow[1]); else rec->refBrlyMRelay = 0;
			if (dbrow[2]) rec->supRefBrlyMNode = atoll((char*) dbrow[2]); else rec->supRefBrlyMNode = 0;
			if (dbrow[3]) rec->supLvl = atoi((char*) dbrow[3]); else rec->supLvl = 0;
			if (dbrow[4]) rec->supNum = atol((char*) dbrow[4]); else rec->supNum = 0;
			if (dbrow[5]) rec->refBrlyMEquipment = atoll((char*) dbrow[5]); else rec->refBrlyMEquipment = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMNode::insertRec(
			BrlyMNode* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRelay,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->supRefBrlyMNode,&(l[1]),&(n[1]),&(e[1])),
		bindUsmallint(&rec->supLvl,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->supNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMNode / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMNode / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMNode::insertRst(
			ListBrlyMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMNode::updateRec(
			BrlyMNode* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refBrlyMRelay,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->supRefBrlyMNode,&(l[1]),&(n[1]),&(e[1])),
		bindUsmallint(&rec->supLvl,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->supNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refBrlyMEquipment,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMNode / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMNode / stmtUpdateRec)\n");
};

void MyTblBrlyMNode::updateRst(
			ListBrlyMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMNode::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMNode / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMNode / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMNode::loadRecByRef(
			ubigint ref
			, BrlyMNode** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMNode WHERE ref = " + to_string(ref), rec);
};

bool MyTblBrlyMNode::confirmByRef(
			ubigint ref
		) {
	ubigint val;
	return loadRefBySQL("SELECT ref FROM TblBrlyMNode WHERE ref = " + to_string(ref) + "", val);
};

ubigint MyTblBrlyMNode::loadRefsBySup(
			ubigint supRefBrlyMNode
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMNode WHERE supRefBrlyMNode = " + to_string(supRefBrlyMNode) + " ORDER BY supNum ASC", append, refs);
};

ubigint MyTblBrlyMNode::loadRstByRly(
			ubigint refBrlyMRelay
			, const bool append
			, ListBrlyMNode& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment FROM TblBrlyMNode WHERE refBrlyMRelay = " + to_string(refBrlyMRelay) + " ORDER BY supLvl ASC, supRefBrlyMNode ASC, supNum ASC", append, rst);
};

ubigint MyTblBrlyMNode::loadRstBySup(
			ubigint supRefBrlyMNode
			, const bool append
			, ListBrlyMNode& rst
		) {
	return loadRstBySQL("SELECT ref, refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment FROM TblBrlyMNode WHERE supRefBrlyMNode = " + to_string(supRefBrlyMNode) + " ORDER BY supNum ASC", append, rst);
};

bool MyTblBrlyMNode::loadSupByRef(
			ubigint ref
			, ubigint& supRefBrlyMNode
		) {
	return loadRefBySQL("SELECT supRefBrlyMNode FROM TblBrlyMNode WHERE ref = " + to_string(ref) + "", supRefBrlyMNode);
};

/******************************************************************************
 class PgTblBrlyMNode
 ******************************************************************************/

PgTblBrlyMNode::PgTblBrlyMNode() : TblBrlyMNode(), PgTable() {
};

PgTblBrlyMNode::~PgTblBrlyMNode() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMNode::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMNode_insertRec", "INSERT INTO TblBrlyMNode (refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMNode_updateRec", "UPDATE TblBrlyMNode SET refBrlyMRelay = $1, supRefBrlyMNode = $2, supLvl = $3, supNum = $4, refBrlyMEquipment = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMNode_removeRecByRef", "DELETE FROM TblBrlyMNode WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMNode_loadRecByRef", "SELECT ref, refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment FROM TblBrlyMNode WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMNode_confirmByRef", "SELECT ref FROM TblBrlyMNode WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMNode_loadRefsBySup", "SELECT ref FROM TblBrlyMNode WHERE supRefBrlyMNode = $1 ORDER BY supNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMNode_loadRstByRly", "SELECT ref, refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment FROM TblBrlyMNode WHERE refBrlyMRelay = $1 ORDER BY supLvl ASC, supRefBrlyMNode ASC, supNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMNode_loadRstBySup", "SELECT ref, refBrlyMRelay, supRefBrlyMNode, supLvl, supNum, refBrlyMEquipment FROM TblBrlyMNode WHERE supRefBrlyMNode = $1 ORDER BY supNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMNode_loadSupByRef", "SELECT supRefBrlyMNode FROM TblBrlyMNode WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMNode::loadRec(
			PGresult* res
			, BrlyMNode** rec
		) {
	char* ptr;

	BrlyMNode* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMNode();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymrelay"),
			PQfnumber(res, "suprefbrlymnode"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "supnum"),
			PQfnumber(res, "refbrlymequipment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refBrlyMRelay = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->supRefBrlyMNode = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->supLvl = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->supNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refBrlyMEquipment = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMNode::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMNode& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMNode* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refbrlymrelay"),
			PQfnumber(res, "suprefbrlymnode"),
			PQfnumber(res, "suplvl"),
			PQfnumber(res, "supnum"),
			PQfnumber(res, "refbrlymequipment")
		};

		while (numread < numrow) {
			rec = new BrlyMNode();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refBrlyMRelay = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->supRefBrlyMNode = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->supLvl = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->supNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refBrlyMEquipment = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMNode::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMNode** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMNode / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMNode::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMNode& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMNode / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMNode::loadRecBySQL(
			const string& sqlstr
			, BrlyMNode** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMNode::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMNode& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMNode::insertRec(
			BrlyMNode* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refBrlyMRelay = htonl64(rec->refBrlyMRelay);
	ubigint _supRefBrlyMNode = htonl64(rec->supRefBrlyMNode);
	usmallint _supLvl = htons(rec->supLvl);
	uint _supNum = htonl(rec->supNum);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);

	const char* vals[] = {
		(char*) &_refBrlyMRelay,
		(char*) &_supRefBrlyMNode,
		(char*) &_supLvl,
		(char*) &_supNum,
		(char*) &_refBrlyMEquipment
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMNode_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMNode_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMNode::insertRst(
			ListBrlyMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMNode::updateRec(
			BrlyMNode* rec
		) {
	PGresult* res;

	ubigint _refBrlyMRelay = htonl64(rec->refBrlyMRelay);
	ubigint _supRefBrlyMNode = htonl64(rec->supRefBrlyMNode);
	usmallint _supLvl = htons(rec->supLvl);
	uint _supNum = htonl(rec->supNum);
	ubigint _refBrlyMEquipment = htonl64(rec->refBrlyMEquipment);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refBrlyMRelay,
		(char*) &_supRefBrlyMNode,
		(char*) &_supLvl,
		(char*) &_supNum,
		(char*) &_refBrlyMEquipment,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(usmallint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblBrlyMNode_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMNode_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMNode::updateRst(
			ListBrlyMNode& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMNode::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMNode_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMNode_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMNode::loadRecByRef(
			ubigint ref
			, BrlyMNode** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMNode_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblBrlyMNode::confirmByRef(
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

	return loadRefByStmt("TblBrlyMNode_confirmByRef", 1, vals, l, f, _ref);
};

ubigint PgTblBrlyMNode::loadRefsBySup(
			ubigint supRefBrlyMNode
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _supRefBrlyMNode = htonl64(supRefBrlyMNode);

	const char* vals[] = {
		(char*) &_supRefBrlyMNode
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMNode_loadRefsBySup", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMNode::loadRstByRly(
			ubigint refBrlyMRelay
			, const bool append
			, ListBrlyMNode& rst
		) {
	ubigint _refBrlyMRelay = htonl64(refBrlyMRelay);

	const char* vals[] = {
		(char*) &_refBrlyMRelay
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMNode_loadRstByRly", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyMNode::loadRstBySup(
			ubigint supRefBrlyMNode
			, const bool append
			, ListBrlyMNode& rst
		) {
	ubigint _supRefBrlyMNode = htonl64(supRefBrlyMNode);

	const char* vals[] = {
		(char*) &_supRefBrlyMNode
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMNode_loadRstBySup", 1, vals, l, f, append, rst);
};

bool PgTblBrlyMNode::loadSupByRef(
			ubigint ref
			, ubigint& supRefBrlyMNode
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefByStmt("TblBrlyMNode_loadSupByRef", 1, vals, l, f, supRefBrlyMNode);
};

