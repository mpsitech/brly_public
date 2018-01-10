/**
  * \file BrlyQTtbList.h
  * Dbs and XML wrapper for table TblBrlyQTtbList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQTTBLIST_H
#define BRLYQTTBLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQTtbList: record of TblBrlyQTtbList
  */
class BrlyQTtbList {

public:
	BrlyQTtbList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refBrlyMFile = 0, const string stubRefBrlyMFile = "", const string srefBrlyKAlliance = "", const string titSrefBrlyKAlliance = "", const uint startd = 0, const string ftmStartd = "", const uint stopd = 0, const string ftmStopd = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	ubigint refBrlyMFile;
	string stubRefBrlyMFile;
	string srefBrlyKAlliance;
	string titSrefBrlyKAlliance;
	uint startd;
	string ftmStartd;
	uint stopd;
	string ftmStopd;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQTtbList: recordset of TblBrlyQTtbList
  */
class ListBrlyQTtbList {

public:
	ListBrlyQTtbList();
	ListBrlyQTtbList(const ListBrlyQTtbList& src);
	~ListBrlyQTtbList();

	void clear();
	unsigned int size() const;
	void append(BrlyQTtbList* rec);

	ListBrlyQTtbList& operator=(const ListBrlyQTtbList& src);

public:
	vector<BrlyQTtbList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQTtbList: C++ wrapper for table TblBrlyQTtbList
  */
class TblBrlyQTtbList {

public:
	TblBrlyQTtbList();
	virtual ~TblBrlyQTtbList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQTtbList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtbList& rst);

	virtual void insertRec(BrlyQTtbList* rec);
	ubigint insertNewRec(BrlyQTtbList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refBrlyMFile = 0, const string stubRefBrlyMFile = "", const string srefBrlyKAlliance = "", const string titSrefBrlyKAlliance = "", const uint startd = 0, const string ftmStartd = "", const uint stopd = 0, const string ftmStopd = "");
	ubigint appendNewRecToRst(ListBrlyQTtbList& rst, BrlyQTtbList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const ubigint refBrlyMFile = 0, const string stubRefBrlyMFile = "", const string srefBrlyKAlliance = "", const string titSrefBrlyKAlliance = "", const uint startd = 0, const string ftmStartd = "", const uint stopd = 0, const string ftmStopd = "");
	virtual void insertRst(ListBrlyQTtbList& rst);
	virtual void updateRec(BrlyQTtbList* rec);
	virtual void updateRst(ListBrlyQTtbList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQTtbList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtbList& rst);
};

/**
  * MyBrlyQTtbList: C++ wrapper for table TblBrlyQTtbList (MySQL database)
  */
class MyTblBrlyQTtbList : public TblBrlyQTtbList, public MyTable {

public:
	MyTblBrlyQTtbList();
	~MyTblBrlyQTtbList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQTtbList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtbList& rst);

	void insertRec(BrlyQTtbList* rec);
	void insertRst(ListBrlyQTtbList& rst);
	void updateRec(BrlyQTtbList* rec);
	void updateRst(ListBrlyQTtbList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQTtbList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtbList& rst);
};

/**
  * PgBrlyQTtbList: C++ wrapper for table TblBrlyQTtbList (PgSQL database)
  */
class PgTblBrlyQTtbList : public TblBrlyQTtbList, public PgTable {

public:
	PgTblBrlyQTtbList();
	~PgTblBrlyQTtbList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQTtbList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQTtbList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQTtbList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQTtbList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQTtbList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtbList& rst);

	void insertRec(BrlyQTtbList* rec);
	void insertRst(ListBrlyQTtbList& rst);
	void updateRec(BrlyQTtbList* rec);
	void updateRst(ListBrlyQTtbList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQTtbList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtbList& rst);
};

#endif

