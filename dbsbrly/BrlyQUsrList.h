/**
  * \file BrlyQUsrList.h
  * Dbs and XML wrapper for table TblBrlyQUsrList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSRLIST_H
#define BRLYQUSRLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsrList: record of TblBrlyQUsrList
  */
class BrlyQUsrList {

public:
	BrlyQUsrList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refBrlyMPerson = 0, const string stubRefBrlyMPerson = "", const string sref = "", const ubigint refBrlyMUsergroup = 0, const string stubRefBrlyMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixBrlyVLocale = 0, const string srefIxBrlyVLocale = "", const string titIxBrlyVLocale = "", const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint refBrlyMPerson;
	string stubRefBrlyMPerson;
	string sref;
	ubigint refBrlyMUsergroup;
	string stubRefBrlyMUsergroup;
	uint ixVState;
	string srefIxVState;
	string titIxVState;
	uint ixBrlyVLocale;
	string srefIxBrlyVLocale;
	string titIxBrlyVLocale;
	uint ixBrlyVUserlevel;
	string srefIxBrlyVUserlevel;
	string titIxBrlyVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQUsrList: recordset of TblBrlyQUsrList
  */
class ListBrlyQUsrList {

public:
	ListBrlyQUsrList();
	ListBrlyQUsrList(const ListBrlyQUsrList& src);
	~ListBrlyQUsrList();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsrList* rec);

	ListBrlyQUsrList& operator=(const ListBrlyQUsrList& src);

public:
	vector<BrlyQUsrList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQUsrList: C++ wrapper for table TblBrlyQUsrList
  */
class TblBrlyQUsrList {

public:
	TblBrlyQUsrList();
	virtual ~TblBrlyQUsrList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQUsrList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrList& rst);

	virtual void insertRec(BrlyQUsrList* rec);
	ubigint insertNewRec(BrlyQUsrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refBrlyMPerson = 0, const string stubRefBrlyMPerson = "", const string sref = "", const ubigint refBrlyMUsergroup = 0, const string stubRefBrlyMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixBrlyVLocale = 0, const string srefIxBrlyVLocale = "", const string titIxBrlyVLocale = "", const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");
	ubigint appendNewRecToRst(ListBrlyQUsrList& rst, BrlyQUsrList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint refBrlyMPerson = 0, const string stubRefBrlyMPerson = "", const string sref = "", const ubigint refBrlyMUsergroup = 0, const string stubRefBrlyMUsergroup = "", const uint ixVState = 0, const string srefIxVState = "", const string titIxVState = "", const uint ixBrlyVLocale = 0, const string srefIxBrlyVLocale = "", const string titIxBrlyVLocale = "", const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");
	virtual void insertRst(ListBrlyQUsrList& rst);
	virtual void updateRec(BrlyQUsrList* rec);
	virtual void updateRst(ListBrlyQUsrList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQUsrList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrList& rst);
};

/**
  * MyBrlyQUsrList: C++ wrapper for table TblBrlyQUsrList (MySQL database)
  */
class MyTblBrlyQUsrList : public TblBrlyQUsrList, public MyTable {

public:
	MyTblBrlyQUsrList();
	~MyTblBrlyQUsrList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrList& rst);

	void insertRec(BrlyQUsrList* rec);
	void insertRst(ListBrlyQUsrList& rst);
	void updateRec(BrlyQUsrList* rec);
	void updateRst(ListBrlyQUsrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrList& rst);
};

/**
  * PgBrlyQUsrList: C++ wrapper for table TblBrlyQUsrList (PgSQL database)
  */
class PgTblBrlyQUsrList : public TblBrlyQUsrList, public PgTable {

public:
	PgTblBrlyQUsrList();
	~PgTblBrlyQUsrList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsrList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsrList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsrList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsrList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsrList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrList& rst);

	void insertRec(BrlyQUsrList* rec);
	void insertRst(ListBrlyQUsrList& rst);
	void updateRec(BrlyQUsrList* rec);
	void updateRst(ListBrlyQUsrList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsrList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrList& rst);
};

#endif

