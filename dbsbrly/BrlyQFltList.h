/**
  * \file BrlyQFltList.h
  * Dbs and XML wrapper for table TblBrlyQFltList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTLIST_H
#define BRLYQFLTLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltList: record of TblBrlyQFltList
  */
class BrlyQFltList {

public:
	BrlyQFltList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint refBrlyMEquipment = 0, const string stubRefBrlyMEquipment = "", const ubigint refBrlyMFaflight = 0, const ubigint refBrlyMLeg = 0, const string stubRefBrlyMLeg = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	ubigint refBrlyMEquipment;
	string stubRefBrlyMEquipment;
	ubigint refBrlyMFaflight;
	ubigint refBrlyMLeg;
	string stubRefBrlyMLeg;
	uint start;
	string ftmStart;
	uint stop;
	string ftmStop;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQFltList: recordset of TblBrlyQFltList
  */
class ListBrlyQFltList {

public:
	ListBrlyQFltList();
	ListBrlyQFltList(const ListBrlyQFltList& src);
	~ListBrlyQFltList();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltList* rec);

	ListBrlyQFltList& operator=(const ListBrlyQFltList& src);

public:
	vector<BrlyQFltList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFltList: C++ wrapper for table TblBrlyQFltList
  */
class TblBrlyQFltList {

public:
	TblBrlyQFltList();
	virtual ~TblBrlyQFltList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFltList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltList& rst);

	virtual void insertRec(BrlyQFltList* rec);
	ubigint insertNewRec(BrlyQFltList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint refBrlyMEquipment = 0, const string stubRefBrlyMEquipment = "", const ubigint refBrlyMFaflight = 0, const ubigint refBrlyMLeg = 0, const string stubRefBrlyMLeg = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");
	ubigint appendNewRecToRst(ListBrlyQFltList& rst, BrlyQFltList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const ubigint refBrlyMEquipment = 0, const string stubRefBrlyMEquipment = "", const ubigint refBrlyMFaflight = 0, const ubigint refBrlyMLeg = 0, const string stubRefBrlyMLeg = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "");
	virtual void insertRst(ListBrlyQFltList& rst);
	virtual void updateRec(BrlyQFltList* rec);
	virtual void updateRst(ListBrlyQFltList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFltList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltList& rst);
};

/**
  * MyBrlyQFltList: C++ wrapper for table TblBrlyQFltList (MySQL database)
  */
class MyTblBrlyQFltList : public TblBrlyQFltList, public MyTable {

public:
	MyTblBrlyQFltList();
	~MyTblBrlyQFltList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltList& rst);

	void insertRec(BrlyQFltList* rec);
	void insertRst(ListBrlyQFltList& rst);
	void updateRec(BrlyQFltList* rec);
	void updateRst(ListBrlyQFltList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltList& rst);
};

/**
  * PgBrlyQFltList: C++ wrapper for table TblBrlyQFltList (PgSQL database)
  */
class PgTblBrlyQFltList : public TblBrlyQFltList, public PgTable {

public:
	PgTblBrlyQFltList();
	~PgTblBrlyQFltList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltList& rst);

	void insertRec(BrlyQFltList* rec);
	void insertRst(ListBrlyQFltList& rst);
	void updateRec(BrlyQFltList* rec);
	void updateRst(ListBrlyQFltList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltList& rst);
};

#endif

