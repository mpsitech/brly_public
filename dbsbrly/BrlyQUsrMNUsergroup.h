/**
  * \file BrlyQUsrMNUsergroup.h
  * Dbs and XML wrapper for table TblBrlyQUsrMNUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSRMNUSERGROUP_H
#define BRLYQUSRMNUSERGROUP_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsrMNUsergroup: record of TblBrlyQUsrMNUsergroup
  */
class BrlyQUsrMNUsergroup {

public:
	BrlyQUsrMNUsergroup(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");

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
  * ListBrlyQUsrMNUsergroup: recordset of TblBrlyQUsrMNUsergroup
  */
class ListBrlyQUsrMNUsergroup {

public:
	ListBrlyQUsrMNUsergroup();
	ListBrlyQUsrMNUsergroup(const ListBrlyQUsrMNUsergroup& src);
	~ListBrlyQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsrMNUsergroup* rec);

	ListBrlyQUsrMNUsergroup& operator=(const ListBrlyQUsrMNUsergroup& src);

public:
	vector<BrlyQUsrMNUsergroup*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQUsrMNUsergroup: C++ wrapper for table TblBrlyQUsrMNUsergroup
  */
class TblBrlyQUsrMNUsergroup {

public:
	TblBrlyQUsrMNUsergroup();
	virtual ~TblBrlyQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQUsrMNUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrMNUsergroup& rst);

	virtual void insertRec(BrlyQUsrMNUsergroup* rec);
	ubigint insertNewRec(BrlyQUsrMNUsergroup** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");
	ubigint appendNewRecToRst(ListBrlyQUsrMNUsergroup& rst, BrlyQUsrMNUsergroup** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixBrlyVUserlevel = 0, const string srefIxBrlyVUserlevel = "", const string titIxBrlyVUserlevel = "");
	virtual void insertRst(ListBrlyQUsrMNUsergroup& rst);
	virtual void updateRec(BrlyQUsrMNUsergroup* rec);
	virtual void updateRst(ListBrlyQUsrMNUsergroup& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQUsrMNUsergroup** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrMNUsergroup& rst);
};

/**
  * MyBrlyQUsrMNUsergroup: C++ wrapper for table TblBrlyQUsrMNUsergroup (MySQL database)
  */
class MyTblBrlyQUsrMNUsergroup : public TblBrlyQUsrMNUsergroup, public MyTable {

public:
	MyTblBrlyQUsrMNUsergroup();
	~MyTblBrlyQUsrMNUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsrMNUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrMNUsergroup& rst);

	void insertRec(BrlyQUsrMNUsergroup* rec);
	void insertRst(ListBrlyQUsrMNUsergroup& rst);
	void updateRec(BrlyQUsrMNUsergroup* rec);
	void updateRst(ListBrlyQUsrMNUsergroup& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsrMNUsergroup** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrMNUsergroup& rst);
};

/**
  * PgBrlyQUsrMNUsergroup: C++ wrapper for table TblBrlyQUsrMNUsergroup (PgSQL database)
  */
class PgTblBrlyQUsrMNUsergroup : public TblBrlyQUsrMNUsergroup, public PgTable {

public:
	PgTblBrlyQUsrMNUsergroup();
	~PgTblBrlyQUsrMNUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsrMNUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsrMNUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsrMNUsergroup** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsrMNUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrMNUsergroup& rst);

	void insertRec(BrlyQUsrMNUsergroup* rec);
	void insertRst(ListBrlyQUsrMNUsergroup& rst);
	void updateRec(BrlyQUsrMNUsergroup* rec);
	void updateRst(ListBrlyQUsrMNUsergroup& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsrMNUsergroup** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrMNUsergroup& rst);
};

#endif

