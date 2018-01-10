/**
  * \file BrlyQUsgMNUser.h
  * Dbs and XML wrapper for table TblBrlyQUsgMNUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSGMNUSER_H
#define BRLYQUSGMNUSER_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsgMNUser: record of TblBrlyQUsgMNUser
  */
class BrlyQUsgMNUser {

public:
	BrlyQUsgMNUser(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint ixBrlyVUserlevel;
	string srefIxBrlyVUserlevel;
	string titIxBrlyVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQUsgMNUser: recordset of TblBrlyQUsgMNUser
  */
class ListBrlyQUsgMNUser {

public:
	ListBrlyQUsgMNUser();
	ListBrlyQUsgMNUser(const ListBrlyQUsgMNUser& src);
	~ListBrlyQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsgMNUser* rec);

	ListBrlyQUsgMNUser& operator=(const ListBrlyQUsgMNUser& src);

public:
	vector<BrlyQUsgMNUser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQUsgMNUser: C++ wrapper for table TblBrlyQUsgMNUser
  */
class TblBrlyQUsgMNUser {

public:
	TblBrlyQUsgMNUser();
	virtual ~TblBrlyQUsgMNUser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQUsgMNUser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgMNUser& rst);

	virtual void insertRec(BrlyQUsgMNUser* rec);
	ubigint insertNewRec(BrlyQUsgMNUser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");
	ubigint appendNewRecToRst(ListBrlyQUsgMNUser& rst, BrlyQUsgMNUser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");
	virtual void insertRst(ListBrlyQUsgMNUser& rst);
	virtual void updateRec(BrlyQUsgMNUser* rec);
	virtual void updateRst(ListBrlyQUsgMNUser& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQUsgMNUser** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgMNUser& rst);
};

/**
  * MyBrlyQUsgMNUser: C++ wrapper for table TblBrlyQUsgMNUser (MySQL database)
  */
class MyTblBrlyQUsgMNUser : public TblBrlyQUsgMNUser, public MyTable {

public:
	MyTblBrlyQUsgMNUser();
	~MyTblBrlyQUsgMNUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsgMNUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgMNUser& rst);

	void insertRec(BrlyQUsgMNUser* rec);
	void insertRst(ListBrlyQUsgMNUser& rst);
	void updateRec(BrlyQUsgMNUser* rec);
	void updateRst(ListBrlyQUsgMNUser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsgMNUser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgMNUser& rst);
};

/**
  * PgBrlyQUsgMNUser: C++ wrapper for table TblBrlyQUsgMNUser (PgSQL database)
  */
class PgTblBrlyQUsgMNUser : public TblBrlyQUsgMNUser, public PgTable {

public:
	PgTblBrlyQUsgMNUser();
	~PgTblBrlyQUsgMNUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsgMNUser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsgMNUser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsgMNUser** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsgMNUser& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsgMNUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgMNUser& rst);

	void insertRec(BrlyQUsgMNUser* rec);
	void insertRst(ListBrlyQUsgMNUser& rst);
	void updateRec(BrlyQUsgMNUser* rec);
	void updateRst(ListBrlyQUsgMNUser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsgMNUser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgMNUser& rst);
};

#endif

