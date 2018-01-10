/**
  * \file BrlyQRlyList.h
  * Dbs and XML wrapper for table TblBrlyQRlyList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQRLYLIST_H
#define BRLYQRLYLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRlyList: record of TblBrlyQRlyList
  */
class BrlyQRlyList {

public:
	BrlyQRlyList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const ubigint refBrlyMConnection = 0, const string stubRefBrlyMConnection = "", const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "", const bool Connected = false, const string yesnoConnected = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint x1Start;
	string ftmX1Start;
	uint x1Stop;
	string ftmX1Stop;
	ubigint refBrlyMConnection;
	string stubRefBrlyMConnection;
	uint ixVDir;
	string srefIxVDir;
	string titIxVDir;
	bool Connected;
	string yesnoConnected;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQRlyList: recordset of TblBrlyQRlyList
  */
class ListBrlyQRlyList {

public:
	ListBrlyQRlyList();
	ListBrlyQRlyList(const ListBrlyQRlyList& src);
	~ListBrlyQRlyList();

	void clear();
	unsigned int size() const;
	void append(BrlyQRlyList* rec);

	ListBrlyQRlyList& operator=(const ListBrlyQRlyList& src);

public:
	vector<BrlyQRlyList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQRlyList: C++ wrapper for table TblBrlyQRlyList
  */
class TblBrlyQRlyList {

public:
	TblBrlyQRlyList();
	virtual ~TblBrlyQRlyList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQRlyList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRlyList& rst);

	virtual void insertRec(BrlyQRlyList* rec);
	ubigint insertNewRec(BrlyQRlyList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const ubigint refBrlyMConnection = 0, const string stubRefBrlyMConnection = "", const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "", const bool Connected = false, const string yesnoConnected = "");
	ubigint appendNewRecToRst(ListBrlyQRlyList& rst, BrlyQRlyList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const ubigint refBrlyMConnection = 0, const string stubRefBrlyMConnection = "", const uint ixVDir = 0, const string srefIxVDir = "", const string titIxVDir = "", const bool Connected = false, const string yesnoConnected = "");
	virtual void insertRst(ListBrlyQRlyList& rst);
	virtual void updateRec(BrlyQRlyList* rec);
	virtual void updateRst(ListBrlyQRlyList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQRlyList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRlyList& rst);
};

/**
  * MyBrlyQRlyList: C++ wrapper for table TblBrlyQRlyList (MySQL database)
  */
class MyTblBrlyQRlyList : public TblBrlyQRlyList, public MyTable {

public:
	MyTblBrlyQRlyList();
	~MyTblBrlyQRlyList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRlyList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRlyList& rst);

	void insertRec(BrlyQRlyList* rec);
	void insertRst(ListBrlyQRlyList& rst);
	void updateRec(BrlyQRlyList* rec);
	void updateRst(ListBrlyQRlyList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRlyList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRlyList& rst);
};

/**
  * PgBrlyQRlyList: C++ wrapper for table TblBrlyQRlyList (PgSQL database)
  */
class PgTblBrlyQRlyList : public TblBrlyQRlyList, public PgTable {

public:
	PgTblBrlyQRlyList();
	~PgTblBrlyQRlyList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRlyList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQRlyList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRlyList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRlyList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRlyList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRlyList& rst);

	void insertRec(BrlyQRlyList* rec);
	void insertRst(ListBrlyQRlyList& rst);
	void updateRec(BrlyQRlyList* rec);
	void updateRst(ListBrlyQRlyList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRlyList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRlyList& rst);
};

#endif

