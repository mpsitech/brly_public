/**
  * \file BrlyQTtbRef1NFile.h
  * Dbs and XML wrapper for table TblBrlyQTtbRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQTTBREF1NFILE_H
#define BRLYQTTBREF1NFILE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQTtbRef1NFile: record of TblBrlyQTtbRef1NFile
  */
class BrlyQTtbRef1NFile {

public:
	BrlyQTtbRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQTtbRef1NFile: recordset of TblBrlyQTtbRef1NFile
  */
class ListBrlyQTtbRef1NFile {

public:
	ListBrlyQTtbRef1NFile();
	ListBrlyQTtbRef1NFile(const ListBrlyQTtbRef1NFile& src);
	~ListBrlyQTtbRef1NFile();

	void clear();
	unsigned int size() const;
	void append(BrlyQTtbRef1NFile* rec);

	ListBrlyQTtbRef1NFile& operator=(const ListBrlyQTtbRef1NFile& src);

public:
	vector<BrlyQTtbRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQTtbRef1NFile: C++ wrapper for table TblBrlyQTtbRef1NFile
  */
class TblBrlyQTtbRef1NFile {

public:
	TblBrlyQTtbRef1NFile();
	virtual ~TblBrlyQTtbRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQTtbRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtbRef1NFile& rst);

	virtual void insertRec(BrlyQTtbRef1NFile* rec);
	ubigint insertNewRec(BrlyQTtbRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQTtbRef1NFile& rst, BrlyQTtbRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQTtbRef1NFile& rst);
	virtual void updateRec(BrlyQTtbRef1NFile* rec);
	virtual void updateRst(ListBrlyQTtbRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQTtbRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtbRef1NFile& rst);
};

/**
  * MyBrlyQTtbRef1NFile: C++ wrapper for table TblBrlyQTtbRef1NFile (MySQL database)
  */
class MyTblBrlyQTtbRef1NFile : public TblBrlyQTtbRef1NFile, public MyTable {

public:
	MyTblBrlyQTtbRef1NFile();
	~MyTblBrlyQTtbRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQTtbRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtbRef1NFile& rst);

	void insertRec(BrlyQTtbRef1NFile* rec);
	void insertRst(ListBrlyQTtbRef1NFile& rst);
	void updateRec(BrlyQTtbRef1NFile* rec);
	void updateRst(ListBrlyQTtbRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQTtbRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtbRef1NFile& rst);
};

/**
  * PgBrlyQTtbRef1NFile: C++ wrapper for table TblBrlyQTtbRef1NFile (PgSQL database)
  */
class PgTblBrlyQTtbRef1NFile : public TblBrlyQTtbRef1NFile, public PgTable {

public:
	PgTblBrlyQTtbRef1NFile();
	~PgTblBrlyQTtbRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQTtbRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQTtbRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQTtbRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQTtbRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQTtbRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtbRef1NFile& rst);

	void insertRec(BrlyQTtbRef1NFile* rec);
	void insertRst(ListBrlyQTtbRef1NFile& rst);
	void updateRec(BrlyQTtbRef1NFile* rec);
	void updateRst(ListBrlyQTtbRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQTtbRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtbRef1NFile& rst);
};

#endif

