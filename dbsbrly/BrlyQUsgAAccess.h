/**
  * \file BrlyQUsgAAccess.h
  * Dbs and XML wrapper for table TblBrlyQUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQUSGAACCESS_H
#define BRLYQUSGAACCESS_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQUsgAAccess: record of TblBrlyQUsgAAccess
  */
class BrlyQUsgAAccess {

public:
	BrlyQUsgAAccess(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxBrlyVCard = 0, const string srefX1IxBrlyVCard = "", const string titX1IxBrlyVCard = "", const uint ixBrlyWUiaccess = 0, const string srefsIxBrlyWUiaccess = "", const string titsIxBrlyWUiaccess = "");

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
  * ListBrlyQUsgAAccess: recordset of TblBrlyQUsgAAccess
  */
class ListBrlyQUsgAAccess {

public:
	ListBrlyQUsgAAccess();
	ListBrlyQUsgAAccess(const ListBrlyQUsgAAccess& src);
	~ListBrlyQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(BrlyQUsgAAccess* rec);

	ListBrlyQUsgAAccess& operator=(const ListBrlyQUsgAAccess& src);

public:
	vector<BrlyQUsgAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQUsgAAccess: C++ wrapper for table TblBrlyQUsgAAccess
  */
class TblBrlyQUsgAAccess {

public:
	TblBrlyQUsgAAccess();
	virtual ~TblBrlyQUsgAAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQUsgAAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgAAccess& rst);

	virtual void insertRec(BrlyQUsgAAccess* rec);
	ubigint insertNewRec(BrlyQUsgAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxBrlyVCard = 0, const string srefX1IxBrlyVCard = "", const string titX1IxBrlyVCard = "", const uint ixBrlyWUiaccess = 0, const string srefsIxBrlyWUiaccess = "", const string titsIxBrlyWUiaccess = "");
	ubigint appendNewRecToRst(ListBrlyQUsgAAccess& rst, BrlyQUsgAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxBrlyVCard = 0, const string srefX1IxBrlyVCard = "", const string titX1IxBrlyVCard = "", const uint ixBrlyWUiaccess = 0, const string srefsIxBrlyWUiaccess = "", const string titsIxBrlyWUiaccess = "");
	virtual void insertRst(ListBrlyQUsgAAccess& rst);
	virtual void updateRec(BrlyQUsgAAccess* rec);
	virtual void updateRst(ListBrlyQUsgAAccess& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQUsgAAccess** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgAAccess& rst);
};

/**
  * MyBrlyQUsgAAccess: C++ wrapper for table TblBrlyQUsgAAccess (MySQL database)
  */
class MyTblBrlyQUsgAAccess : public TblBrlyQUsgAAccess, public MyTable {

public:
	MyTblBrlyQUsgAAccess();
	~MyTblBrlyQUsgAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsgAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgAAccess& rst);

	void insertRec(BrlyQUsgAAccess* rec);
	void insertRst(ListBrlyQUsgAAccess& rst);
	void updateRec(BrlyQUsgAAccess* rec);
	void updateRst(ListBrlyQUsgAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsgAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgAAccess& rst);
};

/**
  * PgBrlyQUsgAAccess: C++ wrapper for table TblBrlyQUsgAAccess (PgSQL database)
  */
class PgTblBrlyQUsgAAccess : public TblBrlyQUsgAAccess, public PgTable {

public:
	PgTblBrlyQUsgAAccess();
	~PgTblBrlyQUsgAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQUsgAAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQUsgAAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQUsgAAccess** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQUsgAAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQUsgAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQUsgAAccess& rst);

	void insertRec(BrlyQUsgAAccess* rec);
	void insertRst(ListBrlyQUsgAAccess& rst);
	void updateRec(BrlyQUsgAAccess* rec);
	void updateRst(ListBrlyQUsgAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQUsgAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQUsgAAccess& rst);
};

#endif

