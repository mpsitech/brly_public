/**
  * \file BrlyQConList.h
  * Dbs and XML wrapper for table TblBrlyQConList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONLIST_H
#define BRLYQCONLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConList: record of TblBrlyQConList
  */
class BrlyQConList {

public:
	BrlyQConList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refBrlyMFlight = 0, const string stubRefBrlyMFlight = "", const ubigint corRefBrlyMLeg = 0, const string stubCorRefBrlyMLeg = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "", const uint ixVModel = 0, const string srefIxVModel = "", const string titIxVModel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint refBrlyMFlight;
	string stubRefBrlyMFlight;
	ubigint corRefBrlyMLeg;
	string stubCorRefBrlyMLeg;
	uint start;
	string ftmStart;
	uint stop;
	string ftmStop;
	uint ixVModel;
	string srefIxVModel;
	string titIxVModel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConList: recordset of TblBrlyQConList
  */
class ListBrlyQConList {

public:
	ListBrlyQConList();
	ListBrlyQConList(const ListBrlyQConList& src);
	~ListBrlyQConList();

	void clear();
	unsigned int size() const;
	void append(BrlyQConList* rec);

	ListBrlyQConList& operator=(const ListBrlyQConList& src);

public:
	vector<BrlyQConList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConList: C++ wrapper for table TblBrlyQConList
  */
class TblBrlyQConList {

public:
	TblBrlyQConList();
	virtual ~TblBrlyQConList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConList& rst);

	virtual void insertRec(BrlyQConList* rec);
	ubigint insertNewRec(BrlyQConList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refBrlyMFlight = 0, const string stubRefBrlyMFlight = "", const ubigint corRefBrlyMLeg = 0, const string stubCorRefBrlyMLeg = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "", const uint ixVModel = 0, const string srefIxVModel = "", const string titIxVModel = "");
	ubigint appendNewRecToRst(ListBrlyQConList& rst, BrlyQConList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refBrlyMFlight = 0, const string stubRefBrlyMFlight = "", const ubigint corRefBrlyMLeg = 0, const string stubCorRefBrlyMLeg = "", const uint start = 0, const string ftmStart = "", const uint stop = 0, const string ftmStop = "", const uint ixVModel = 0, const string srefIxVModel = "", const string titIxVModel = "");
	virtual void insertRst(ListBrlyQConList& rst);
	virtual void updateRec(BrlyQConList* rec);
	virtual void updateRst(ListBrlyQConList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConList& rst);
};

/**
  * MyBrlyQConList: C++ wrapper for table TblBrlyQConList (MySQL database)
  */
class MyTblBrlyQConList : public TblBrlyQConList, public MyTable {

public:
	MyTblBrlyQConList();
	~MyTblBrlyQConList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConList& rst);

	void insertRec(BrlyQConList* rec);
	void insertRst(ListBrlyQConList& rst);
	void updateRec(BrlyQConList* rec);
	void updateRst(ListBrlyQConList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConList& rst);
};

/**
  * PgBrlyQConList: C++ wrapper for table TblBrlyQConList (PgSQL database)
  */
class PgTblBrlyQConList : public TblBrlyQConList, public PgTable {

public:
	PgTblBrlyQConList();
	~PgTblBrlyQConList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConList& rst);

	void insertRec(BrlyQConList* rec);
	void insertRst(ListBrlyQConList& rst);
	void updateRec(BrlyQConList* rec);
	void updateRst(ListBrlyQConList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConList& rst);
};

#endif

