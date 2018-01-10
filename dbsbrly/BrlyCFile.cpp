/**
  * \file BrlyCFile.cpp
  * Dbs and XML wrapper for table TblBrlyCFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyCFile.h"

/******************************************************************************
 class TblBrlyCFile
 ******************************************************************************/

TblBrlyCFile::TblBrlyCFile() {
};

TblBrlyCFile::~TblBrlyCFile() {
};

ubigint TblBrlyCFile::getNewRef() {
	return 0;
};

/******************************************************************************
 class MyTblBrlyCFile
 ******************************************************************************/

MyTblBrlyCFile::MyTblBrlyCFile() : TblBrlyCFile(), MyTable() {
	stmtGetNewRef = NULL;
};

MyTblBrlyCFile::~MyTblBrlyCFile() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblBrlyCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblBrlyCFile () VALUES ()", false);
};

ubigint MyTblBrlyCFile::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyCFile / stmtGetNewRef)\n");
	if (mysql_stmt_execute(stmtGetNewRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyCFile / stmtGetNewRef)\n");
	return mysql_stmt_insert_id(stmtGetNewRef);
};

/******************************************************************************
 class PgTblBrlyCFile
 ******************************************************************************/

PgTblBrlyCFile::PgTblBrlyCFile() : TblBrlyCFile(), PgTable() {
};

PgTblBrlyCFile::~PgTblBrlyCFile() {
};

void PgTblBrlyCFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyCFile_getNewRef", "SELECT nextval('TblBrlyCFile')", 0, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

ubigint PgTblBrlyCFile::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblBrlyCFile_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyCFile_getNewRef)\n");

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};

