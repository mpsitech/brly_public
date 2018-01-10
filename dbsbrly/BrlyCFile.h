/**
  * \file BrlyCFile.h
  * Dbs and XML wrapper for table TblBrlyCFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYCFILE_H
#define BRLYCFILE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * TblBrlyCFile: C++ wrapper for table TblBrlyCFile
  */
class TblBrlyCFile {

public:
	TblBrlyCFile();
	virtual ~TblBrlyCFile();

public:
	virtual ubigint getNewRef();
};

/**
  * MyTblBrlyCFile: C++ wrapper for table TblBrlyCFile (MySQL database)
  */
class MyTblBrlyCFile : public TblBrlyCFile, public MyTable {

public:
	MyTblBrlyCFile();
	~MyTblBrlyCFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtGetNewRef;

public:
	ubigint getNewRef();
};

/**
  * PgTblBrlyCFile: C++ wrapper for table TblBrlyCFile (PgSQL database)
  */
class PgTblBrlyCFile : public TblBrlyCFile, public PgTable {

public:
	PgTblBrlyCFile();
	~PgTblBrlyCFile();

public:
	void initStatements();

public:
	ubigint getNewRef();
};

#endif

