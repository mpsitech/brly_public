/**
  * \file BrlyQRegSup1NRegion.h
  * Dbs and XML wrapper for table TblBrlyQRegSup1NRegion (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQREGSUP1NREGION_H
#define BRLYQREGSUP1NREGION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRegSup1NRegion: record of TblBrlyQRegSup1NRegion
  */
class BrlyQRegSup1NRegion {

public:
	BrlyQRegSup1NRegion(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQRegSup1NRegion: recordset of TblBrlyQRegSup1NRegion
  */
class ListBrlyQRegSup1NRegion {

public:
	ListBrlyQRegSup1NRegion();
	ListBrlyQRegSup1NRegion(const ListBrlyQRegSup1NRegion& src);
	~ListBrlyQRegSup1NRegion();

	void clear();
	unsigned int size() const;
	void append(BrlyQRegSup1NRegion* rec);

	ListBrlyQRegSup1NRegion& operator=(const ListBrlyQRegSup1NRegion& src);

public:
	vector<BrlyQRegSup1NRegion*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQRegSup1NRegion: C++ wrapper for table TblBrlyQRegSup1NRegion
  */
class TblBrlyQRegSup1NRegion {

public:
	TblBrlyQRegSup1NRegion();
	virtual ~TblBrlyQRegSup1NRegion();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQRegSup1NRegion** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegSup1NRegion& rst);

	virtual void insertRec(BrlyQRegSup1NRegion* rec);
	ubigint insertNewRec(BrlyQRegSup1NRegion** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQRegSup1NRegion& rst, BrlyQRegSup1NRegion** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQRegSup1NRegion& rst);
	virtual void updateRec(BrlyQRegSup1NRegion* rec);
	virtual void updateRst(ListBrlyQRegSup1NRegion& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQRegSup1NRegion** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegSup1NRegion& rst);
};

/**
  * MyBrlyQRegSup1NRegion: C++ wrapper for table TblBrlyQRegSup1NRegion (MySQL database)
  */
class MyTblBrlyQRegSup1NRegion : public TblBrlyQRegSup1NRegion, public MyTable {

public:
	MyTblBrlyQRegSup1NRegion();
	~MyTblBrlyQRegSup1NRegion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRegSup1NRegion** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegSup1NRegion& rst);

	void insertRec(BrlyQRegSup1NRegion* rec);
	void insertRst(ListBrlyQRegSup1NRegion& rst);
	void updateRec(BrlyQRegSup1NRegion* rec);
	void updateRst(ListBrlyQRegSup1NRegion& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRegSup1NRegion** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegSup1NRegion& rst);
};

/**
  * PgBrlyQRegSup1NRegion: C++ wrapper for table TblBrlyQRegSup1NRegion (PgSQL database)
  */
class PgTblBrlyQRegSup1NRegion : public TblBrlyQRegSup1NRegion, public PgTable {

public:
	PgTblBrlyQRegSup1NRegion();
	~PgTblBrlyQRegSup1NRegion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRegSup1NRegion** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQRegSup1NRegion& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRegSup1NRegion** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRegSup1NRegion& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRegSup1NRegion** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegSup1NRegion& rst);

	void insertRec(BrlyQRegSup1NRegion* rec);
	void insertRst(ListBrlyQRegSup1NRegion& rst);
	void updateRec(BrlyQRegSup1NRegion* rec);
	void updateRst(ListBrlyQRegSup1NRegion& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRegSup1NRegion** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegSup1NRegion& rst);
};

#endif

