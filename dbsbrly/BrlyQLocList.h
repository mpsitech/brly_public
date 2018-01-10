/**
  * \file BrlyQLocList.h
  * Dbs and XML wrapper for table TblBrlyQLocList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCLIST_H
#define BRLYQLOCLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocList: record of TblBrlyQLocList
  */
class BrlyQLocList {

public:
	BrlyQLocList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string srefICAO = "", const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint refBrlyMRegion = 0, const string stubRefBrlyMRegion = "", const ubigint refBrlyMEquipment = 0, const string stubRefBrlyMEquipment = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string srefICAO;
	string Title;
	uint ixVBasetype;
	string srefIxVBasetype;
	string titIxVBasetype;
	ubigint refBrlyMRegion;
	string stubRefBrlyMRegion;
	ubigint refBrlyMEquipment;
	string stubRefBrlyMEquipment;
	double alt;
	double theta;
	double phi;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLocList: recordset of TblBrlyQLocList
  */
class ListBrlyQLocList {

public:
	ListBrlyQLocList();
	ListBrlyQLocList(const ListBrlyQLocList& src);
	~ListBrlyQLocList();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocList* rec);

	ListBrlyQLocList& operator=(const ListBrlyQLocList& src);

public:
	vector<BrlyQLocList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocList: C++ wrapper for table TblBrlyQLocList
  */
class TblBrlyQLocList {

public:
	TblBrlyQLocList();
	virtual ~TblBrlyQLocList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocList& rst);

	virtual void insertRec(BrlyQLocList* rec);
	ubigint insertNewRec(BrlyQLocList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string srefICAO = "", const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint refBrlyMRegion = 0, const string stubRefBrlyMRegion = "", const ubigint refBrlyMEquipment = 0, const string stubRefBrlyMEquipment = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLocList& rst, BrlyQLocList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string srefICAO = "", const string Title = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const ubigint refBrlyMRegion = 0, const string stubRefBrlyMRegion = "", const ubigint refBrlyMEquipment = 0, const string stubRefBrlyMEquipment = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0);
	virtual void insertRst(ListBrlyQLocList& rst);
	virtual void updateRec(BrlyQLocList* rec);
	virtual void updateRst(ListBrlyQLocList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocList& rst);
};

/**
  * MyBrlyQLocList: C++ wrapper for table TblBrlyQLocList (MySQL database)
  */
class MyTblBrlyQLocList : public TblBrlyQLocList, public MyTable {

public:
	MyTblBrlyQLocList();
	~MyTblBrlyQLocList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocList& rst);

	void insertRec(BrlyQLocList* rec);
	void insertRst(ListBrlyQLocList& rst);
	void updateRec(BrlyQLocList* rec);
	void updateRst(ListBrlyQLocList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocList& rst);
};

/**
  * PgBrlyQLocList: C++ wrapper for table TblBrlyQLocList (PgSQL database)
  */
class PgTblBrlyQLocList : public TblBrlyQLocList, public PgTable {

public:
	PgTblBrlyQLocList();
	~PgTblBrlyQLocList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocList& rst);

	void insertRec(BrlyQLocList* rec);
	void insertRst(ListBrlyQLocList& rst);
	void updateRec(BrlyQLocList* rec);
	void updateRst(ListBrlyQLocList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocList& rst);
};

#endif

