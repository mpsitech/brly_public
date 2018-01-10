/**
  * \file BrlyQFilList.h
  * Dbs and XML wrapper for table TblBrlyQFilList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFILLIST_H
#define BRLYQFILLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFilList: record of TblBrlyQFilList
  */
class BrlyQFilList {

public:
	BrlyQFilList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Filename;
	uint refIxVTbl;
	string srefRefIxVTbl;
	string titRefIxVTbl;
	ubigint refUref;
	string stubRefUref;
	string osrefKContent;
	string titOsrefKContent;
	string srefKMimetype;
	string titSrefKMimetype;
	usmallint Size;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQFilList: recordset of TblBrlyQFilList
  */
class ListBrlyQFilList {

public:
	ListBrlyQFilList();
	ListBrlyQFilList(const ListBrlyQFilList& src);
	~ListBrlyQFilList();

	void clear();
	unsigned int size() const;
	void append(BrlyQFilList* rec);

	ListBrlyQFilList& operator=(const ListBrlyQFilList& src);

public:
	vector<BrlyQFilList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFilList: C++ wrapper for table TblBrlyQFilList
  */
class TblBrlyQFilList {

public:
	TblBrlyQFilList();
	virtual ~TblBrlyQFilList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFilList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFilList& rst);

	virtual void insertRec(BrlyQFilList* rec);
	ubigint insertNewRec(BrlyQFilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);
	ubigint appendNewRecToRst(ListBrlyQFilList& rst, BrlyQFilList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Filename = "", const uint refIxVTbl = 0, const string srefRefIxVTbl = "", const string titRefIxVTbl = "", const ubigint refUref = 0, const string stubRefUref = "", const string osrefKContent = "", const string titOsrefKContent = "", const string srefKMimetype = "", const string titSrefKMimetype = "", const usmallint Size = 0);
	virtual void insertRst(ListBrlyQFilList& rst);
	virtual void updateRec(BrlyQFilList* rec);
	virtual void updateRst(ListBrlyQFilList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFilList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFilList& rst);
};

/**
  * MyBrlyQFilList: C++ wrapper for table TblBrlyQFilList (MySQL database)
  */
class MyTblBrlyQFilList : public TblBrlyQFilList, public MyTable {

public:
	MyTblBrlyQFilList();
	~MyTblBrlyQFilList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFilList& rst);

	void insertRec(BrlyQFilList* rec);
	void insertRst(ListBrlyQFilList& rst);
	void updateRec(BrlyQFilList* rec);
	void updateRst(ListBrlyQFilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFilList& rst);
};

/**
  * PgBrlyQFilList: C++ wrapper for table TblBrlyQFilList (PgSQL database)
  */
class PgTblBrlyQFilList : public TblBrlyQFilList, public PgTable {

public:
	PgTblBrlyQFilList();
	~PgTblBrlyQFilList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFilList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFilList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFilList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFilList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFilList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFilList& rst);

	void insertRec(BrlyQFilList* rec);
	void insertRst(ListBrlyQFilList& rst);
	void updateRec(BrlyQFilList* rec);
	void updateRst(ListBrlyQFilList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFilList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFilList& rst);
};

#endif

