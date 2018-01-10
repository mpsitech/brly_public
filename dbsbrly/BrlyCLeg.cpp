/**
  * \file BrlyCLeg.cpp
  * Dbs and XML wrapper for table TblBrlyCLeg (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "BrlyCLeg.h"

/******************************************************************************
 class TblBrlyCLeg
 ******************************************************************************/

TblBrlyCLeg::TblBrlyCLeg() {
};

TblBrlyCLeg::~TblBrlyCLeg() {
};

ubigint TblBrlyCLeg::getNewRef() {
	return 0;
};

/******************************************************************************
 class MyTblBrlyCLeg
 ******************************************************************************/

MyTblBrlyCLeg::MyTblBrlyCLeg() : TblBrlyCLeg(), MyTable() {
	stmtGetNewRef = NULL;
};

MyTblBrlyCLeg::~MyTblBrlyCLeg() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblBrlyCLeg::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblBrlyCLeg () VALUES ()", false);
};

ubigint MyTblBrlyCLeg::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblBrlyCLeg / stmtGetNewRef)\n");
	if (mysql_stmt_execute(stmtGetNewRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblBrlyCLeg / stmtGetNewRef)\n");
	return mysql_stmt_insert_id(stmtGetNewRef);
};

/******************************************************************************
 class PgTblBrlyCLeg
 ******************************************************************************/

PgTblBrlyCLeg::PgTblBrlyCLeg() : TblBrlyCLeg(), PgTable() {
};

PgTblBrlyCLeg::~PgTblBrlyCLeg() {
};

void PgTblBrlyCLeg::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblBrlyCLeg_getNewRef", "SELECT nextval('TblBrlyCLeg')", 0, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

ubigint PgTblBrlyCLeg::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblBrlyCLeg_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblBrlyCLeg_getNewRef)\n");

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};

