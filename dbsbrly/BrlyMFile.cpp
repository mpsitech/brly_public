/**
  * \file BrlyMFile.cpp
  * database access for table TblBrlyMFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyMFile.h"

#include "BrlyMFile_vecs.cpp"

/******************************************************************************
 class BrlyMFile
 ******************************************************************************/

BrlyMFile::BrlyMFile(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refBrlyCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const usmallint Size
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refBrlyCFile = refBrlyCFile;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->osrefKContent = osrefKContent;
	this->Archived = Archived;
	this->Filename = Filename;
	this->Archivename = Archivename;
	this->srefKMimetype = srefKMimetype;
	this->Size = Size;
	this->Comment = Comment;
};

bool BrlyMFile::operator==(
			const BrlyMFile& comp
		) {
	return false;
};

bool BrlyMFile::operator!=(
			const BrlyMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListBrlyMFile
 ******************************************************************************/

ListBrlyMFile::ListBrlyMFile() {
};

ListBrlyMFile::ListBrlyMFile(
			const ListBrlyMFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new BrlyMFile(*(src.nodes[i]));
};

ListBrlyMFile::~ListBrlyMFile() {
	clear();
};

void ListBrlyMFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListBrlyMFile::size() const {
	return(nodes.size());
};

void ListBrlyMFile::append(
			BrlyMFile* rec
		) {
	nodes.push_back(rec);
};

BrlyMFile* ListBrlyMFile::operator[](
			const uint ix
		) {
	BrlyMFile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListBrlyMFile& ListBrlyMFile::operator=(
			const ListBrlyMFile& src
		) {
	BrlyMFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new BrlyMFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListBrlyMFile::operator==(
			const ListBrlyMFile& comp
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

bool ListBrlyMFile::operator!=(
			const ListBrlyMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblBrlyMFile
 ******************************************************************************/

TblBrlyMFile::TblBrlyMFile() {
};

TblBrlyMFile::~TblBrlyMFile() {
};

bool TblBrlyMFile::loadRecBySQL(
			const string& sqlstr
			, BrlyMFile** rec
		) {
	return false;
};

ubigint TblBrlyMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFile& rst
		) {
	return 0;
};

void TblBrlyMFile::insertRec(
			BrlyMFile* rec
		) {
};

ubigint TblBrlyMFile::insertNewRec(
			BrlyMFile** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refBrlyCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const usmallint Size
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyMFile* _rec = NULL;

	_rec = new BrlyMFile(0, grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblBrlyMFile::appendNewRecToRst(
			ListBrlyMFile& rst
			, BrlyMFile** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refBrlyCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const usmallint Size
			, const string Comment
		) {
	ubigint retval = 0;
	BrlyMFile* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblBrlyMFile::insertRst(
			ListBrlyMFile& rst
			, bool transact
		) {
};

void TblBrlyMFile::updateRec(
			BrlyMFile* rec
		) {
};

void TblBrlyMFile::updateRst(
			ListBrlyMFile& rst
			, bool transact
		) {
};

void TblBrlyMFile::removeRecByRef(
			ubigint ref
		) {
};

bool TblBrlyMFile::loadRecByRef(
			ubigint ref
			, BrlyMFile** rec
		) {
	return false;
};

ubigint TblBrlyMFile::loadRefsByClu(
			ubigint refBrlyCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMFile::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblBrlyMFile::loadRstByClu(
			ubigint refBrlyCFile
			, const bool append
			, ListBrlyMFile& rst
		) {
	return 0;
};

ubigint TblBrlyMFile::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListBrlyMFile& rst
		) {
	return 0;
};

ubigint TblBrlyMFile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListBrlyMFile& rst
		) {
	ubigint numload = 0;
	BrlyMFile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

/******************************************************************************
 class MyTblBrlyMFile
 ******************************************************************************/

MyTblBrlyMFile::MyTblBrlyMFile() : TblBrlyMFile(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblBrlyMFile::~MyTblBrlyMFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblBrlyMFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblBrlyMFile (grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblBrlyMFile SET grp = ?, own = ?, refBrlyCFile = ?, refIxVTbl = ?, refUref = ?, osrefKContent = ?, Archived = ?, Filename = ?, Archivename = ?, srefKMimetype = ?, Size = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblBrlyMFile WHERE ref = ?", false);
};

bool MyTblBrlyMFile::loadRecBySQL(
			const string& sqlstr
			, BrlyMFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	BrlyMFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMFile / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new BrlyMFile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refBrlyCFile = atoll((char*) dbrow[3]); else _rec->refBrlyCFile = 0;
		if (dbrow[4]) _rec->refIxVTbl = atol((char*) dbrow[4]); else _rec->refIxVTbl = 0;
		if (dbrow[5]) _rec->refUref = atoll((char*) dbrow[5]); else _rec->refUref = 0;
		if (dbrow[6]) _rec->osrefKContent.assign(dbrow[6], dblengths[6]); else _rec->osrefKContent = "";
		if (dbrow[7]) _rec->Archived = atol((char*) dbrow[7]); else _rec->Archived = 0;
		if (dbrow[8]) _rec->Filename.assign(dbrow[8], dblengths[8]); else _rec->Filename = "";
		if (dbrow[9]) _rec->Archivename.assign(dbrow[9], dblengths[9]); else _rec->Archivename = "";
		if (dbrow[10]) _rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else _rec->srefKMimetype = "";
		if (dbrow[11]) _rec->Size = atoi((char*) dbrow[11]); else _rec->Size = 0;
		if (dbrow[12]) _rec->Comment.assign(dbrow[12], dblengths[12]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblBrlyMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	BrlyMFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblBrlyMFile / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new BrlyMFile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refBrlyCFile = atoll((char*) dbrow[3]); else rec->refBrlyCFile = 0;
			if (dbrow[4]) rec->refIxVTbl = atol((char*) dbrow[4]); else rec->refIxVTbl = 0;
			if (dbrow[5]) rec->refUref = atoll((char*) dbrow[5]); else rec->refUref = 0;
			if (dbrow[6]) rec->osrefKContent.assign(dbrow[6], dblengths[6]); else rec->osrefKContent = "";
			if (dbrow[7]) rec->Archived = atol((char*) dbrow[7]); else rec->Archived = 0;
			if (dbrow[8]) rec->Filename.assign(dbrow[8], dblengths[8]); else rec->Filename = "";
			if (dbrow[9]) rec->Archivename.assign(dbrow[9], dblengths[9]); else rec->Archivename = "";
			if (dbrow[10]) rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else rec->srefKMimetype = "";
			if (dbrow[11]) rec->Size = atoi((char*) dbrow[11]); else rec->Size = 0;
			if (dbrow[12]) rec->Comment.assign(dbrow[12], dblengths[12]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblBrlyMFile::insertRec(
			BrlyMFile* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->osrefKContent.length();
	l[7] = rec->Filename.length();
	l[8] = rec->Archivename.length();
	l[9] = rec->srefKMimetype.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyCFile,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Archived,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Archivename.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUsmallint(&rec->Size,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFile / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFile / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblBrlyMFile::insertRst(
			ListBrlyMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblBrlyMFile::updateRec(
			BrlyMFile* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->osrefKContent.length();
	l[7] = rec->Filename.length();
	l[8] = rec->Archivename.length();
	l[9] = rec->srefKMimetype.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refBrlyCFile,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Archived,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Archivename.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUsmallint(&rec->Size,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFile / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFile / stmtUpdateRec)\n");
};

void MyTblBrlyMFile::updateRst(
			ListBrlyMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblBrlyMFile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyMFile / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyMFile / stmtRemoveRecByRef)\n");
};

bool MyTblBrlyMFile::loadRecByRef(
			ubigint ref
			, BrlyMFile** rec
		) {
	return loadRecBySQL("SELECT * FROM TblBrlyMFile WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblBrlyMFile::loadRefsByClu(
			ubigint refBrlyCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMFile WHERE refBrlyCFile = " + to_string(refBrlyCFile) + "", append, refs);
};

ubigint MyTblBrlyMFile::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblBrlyMFile WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY Filename ASC", append, refs);
};

ubigint MyTblBrlyMFile::loadRstByClu(
			ubigint refBrlyCFile
			, const bool append
			, ListBrlyMFile& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblBrlyMFile WHERE refBrlyCFile = " + to_string(refBrlyCFile) + "", append, rst);
};

ubigint MyTblBrlyMFile::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListBrlyMFile& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblBrlyMFile WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY Filename ASC", append, rst);
};

/******************************************************************************
 class PgTblBrlyMFile
 ******************************************************************************/

PgTblBrlyMFile::PgTblBrlyMFile() : TblBrlyMFile(), PgTable() {
};

PgTblBrlyMFile::~PgTblBrlyMFile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblBrlyMFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyMFile_insertRec", "INSERT INTO TblBrlyMFile (grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFile_updateRec", "UPDATE TblBrlyMFile SET grp = $1, own = $2, refBrlyCFile = $3, refIxVTbl = $4, refUref = $5, osrefKContent = $6, Archived = $7, Filename = $8, Archivename = $9, srefKMimetype = $10, Size = $11, Comment = $12 WHERE ref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFile_removeRecByRef", "DELETE FROM TblBrlyMFile WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblBrlyMFile_loadRecByRef", "SELECT ref, grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblBrlyMFile WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblBrlyMFile_loadRefsByClu", "SELECT ref FROM TblBrlyMFile WHERE refBrlyCFile = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFile_loadRefsByRetReu", "SELECT ref FROM TblBrlyMFile WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY Filename ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFile_loadRstByClu", "SELECT ref, grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblBrlyMFile WHERE refBrlyCFile = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblBrlyMFile_loadRstByRetReu", "SELECT ref, grp, own, refBrlyCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblBrlyMFile WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY Filename ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblBrlyMFile::loadRec(
			PGresult* res
			, BrlyMFile** rec
		) {
	char* ptr;

	BrlyMFile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new BrlyMFile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refbrlycfile"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "archived"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "archivename"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refBrlyCFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->osrefKContent.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Archived = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Filename.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Archivename.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefKMimetype.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Size = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblBrlyMFile::loadRst(
			PGresult* res
			, const bool append
			, ListBrlyMFile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	BrlyMFile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refbrlycfile"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "archived"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "archivename"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new BrlyMFile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refBrlyCFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->osrefKContent.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Archived = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Filename.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Archivename.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefKMimetype.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Size = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblBrlyMFile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, BrlyMFile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFile / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMFile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListBrlyMFile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFile / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblBrlyMFile::loadRecBySQL(
			const string& sqlstr
			, BrlyMFile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblBrlyMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListBrlyMFile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblBrlyMFile::insertRec(
			BrlyMFile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refBrlyCFile = htonl64(rec->refBrlyCFile);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _Archived = htonl(rec->Archived);
	usmallint _Size = htons(rec->Size);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refBrlyCFile,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		(char*) &_Archived,
		rec->Filename.c_str(),
		rec->Archivename.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		0,
		0,
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblBrlyMFile_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFile_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
};

void PgTblBrlyMFile::insertRst(
			ListBrlyMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblBrlyMFile::updateRec(
			BrlyMFile* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refBrlyCFile = htonl64(rec->refBrlyCFile);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _Archived = htonl(rec->Archived);
	usmallint _Size = htons(rec->Size);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refBrlyCFile,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		(char*) &_Archived,
		rec->Filename.c_str(),
		rec->Archivename.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		0,
		0,
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblBrlyMFile_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFile_updateRec)\n");

	PQclear(res);
};

void PgTblBrlyMFile::updateRst(
			ListBrlyMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblBrlyMFile::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblBrlyMFile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyMFile_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblBrlyMFile::loadRecByRef(
			ubigint ref
			, BrlyMFile** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblBrlyMFile_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblBrlyMFile::loadRefsByClu(
			ubigint refBrlyCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refBrlyCFile = htonl64(refBrlyCFile);

	const char* vals[] = {
		(char*) &_refBrlyCFile
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblBrlyMFile_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblBrlyMFile::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblBrlyMFile_loadRefsByRetReu", 2, vals, l, f, append, refs);
};

ubigint PgTblBrlyMFile::loadRstByClu(
			ubigint refBrlyCFile
			, const bool append
			, ListBrlyMFile& rst
		) {
	ubigint _refBrlyCFile = htonl64(refBrlyCFile);

	const char* vals[] = {
		(char*) &_refBrlyCFile
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblBrlyMFile_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblBrlyMFile::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListBrlyMFile& rst
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblBrlyMFile_loadRstByRetReu", 2, vals, l, f, append, rst);
};

