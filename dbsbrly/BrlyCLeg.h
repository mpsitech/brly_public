/**
  * \file BrlyCLeg.h
  * Dbs and XML wrapper for table TblBrlyCLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYCLEG_H
#define BRLYCLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * TblBrlyCLeg: C++ wrapper for table TblBrlyCLeg
  */
class TblBrlyCLeg {

public:
	TblBrlyCLeg();
	virtual ~TblBrlyCLeg();

public:
	virtual ubigint getNewRef();
};

/**
  * MyTblBrlyCLeg: C++ wrapper for table TblBrlyCLeg (MySQL database)
  */
class MyTblBrlyCLeg : public TblBrlyCLeg, public MyTable {

public:
	MyTblBrlyCLeg();
	~MyTblBrlyCLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	ubigint getNewRef();
};

/**
  * PgTblBrlyCLeg: C++ wrapper for table TblBrlyCLeg (PgSQL database)
  */
class PgTblBrlyCLeg : public TblBrlyCLeg, public PgTable {

public:
	PgTblBrlyCLeg();
	~PgTblBrlyCLeg();

public:
	void initStatements();

public:
	ubigint getNewRef();
};

#endif

