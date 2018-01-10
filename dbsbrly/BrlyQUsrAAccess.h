/**
  * \file BrlyQUsrAAccess.h
  * Dbs and XML wrapper for table TblBrlyQUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSRAACCESS_H
#define BRLYQUSRAACCESS_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsrAAccess: record of TblBrlyQUsrAAccess
  */
class BrlyQUsrAAccess {

public:
	BrlyQUsrAAccess(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxBrlyVCard = 0, const string srefX1IxBrlyVCard = "", const string titX1IxBrlyVCard = "", const uint ixBrlyWUiaccess = 0, const string srefsIxBrlyWUiaccess = "", const string titsIxBrlyWUiaccess = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint x1IxBrlyVCard;
	string srefX1IxBrlyVCard;
	string titX1IxBrlyVCard;
	uint ixBrlyWUiaccess;
	string srefsIxBrlyWUiaccess;
	string titsIxBrlyWUiaccess;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQUsrAAccess: recordset of TblBrlyQUsrAAccess
  */
class ListBrlyQUsrAAccess {

public:
	ListBrlyQUsrAAccess();
	ListBrlyQUsrAAccess(const ListBrlyQUsrAAccess& src);
	~ListBrlyQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsrAAccess* rec);

	ListBrlyQUsrAAccess& operator=(const ListBrlyQUsrAAccess& src);

public:
	vector<BrlyQUsrAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQUsrAAccess: C++ wrapper for table TblBrlyQUsrAAccess
  */
class TblBrlyQUsrAAccess {

public:
	TblBrlyQUsrAAccess();
	virtual ~TblBrlyQUsrAAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQUsrAAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrAAccess& rst);

	virtual void insertRec(BrlyQUsrAAccess* rec);
	ubigint insertNewRec(BrlyQUsrAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxBrlyVCard = 0, const string srefX1IxBrlyVCard = "", const string titX1IxBrlyVCard = "", const uint ixBrlyWUiaccess = 0, const string srefsIxBrlyWUiaccess = "", const string titsIxBrlyWUiaccess = "");
	ubigint appendNewRecToRst(ListBrlyQUsrAAccess& rst, BrlyQUsrAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxBrlyVCard = 0, const string srefX1IxBrlyVCard = "", const string titX1IxBrlyVCard = "", const uint ixBrlyWUiaccess = 0, const string srefsIxBrlyWUiaccess = "", const string titsIxBrlyWUiaccess = "");
	virtual void insertRst(ListBrlyQUsrAAccess& rst);
	virtual void updateRec(BrlyQUsrAAccess* rec);
	virtual void updateRst(ListBrlyQUsrAAccess& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQUsrAAccess** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrAAccess& rst);
};

/**
  * MyBrlyQUsrAAccess: C++ wrapper for table TblBrlyQUsrAAccess (MySQL database)
  */
class MyTblBrlyQUsrAAccess : public TblBrlyQUsrAAccess, public MyTable {

public:
	MyTblBrlyQUsrAAccess();
	~MyTblBrlyQUsrAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsrAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrAAccess& rst);

	void insertRec(BrlyQUsrAAccess* rec);
	void insertRst(ListBrlyQUsrAAccess& rst);
	void updateRec(BrlyQUsrAAccess* rec);
	void updateRst(ListBrlyQUsrAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsrAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrAAccess& rst);
};

/**
  * PgBrlyQUsrAAccess: C++ wrapper for table TblBrlyQUsrAAccess (PgSQL database)
  */
class PgTblBrlyQUsrAAccess : public TblBrlyQUsrAAccess, public PgTable {

public:
	PgTblBrlyQUsrAAccess();
	~PgTblBrlyQUsrAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsrAAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsrAAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsrAAccess** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsrAAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsrAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsrAAccess& rst);

	void insertRec(BrlyQUsrAAccess* rec);
	void insertRst(ListBrlyQUsrAAccess& rst);
	void updateRec(BrlyQUsrAAccess* rec);
	void updateRst(ListBrlyQUsrAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsrAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsrAAccess& rst);
};

#endif

