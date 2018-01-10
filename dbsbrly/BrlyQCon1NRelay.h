/**
  * \file BrlyQCon1NRelay.h
  * Dbs and XML wrapper for table TblBrlyQCon1NRelay (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCON1NRELAY_H
#define BRLYQCON1NRELAY_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQCon1NRelay: record of TblBrlyQCon1NRelay
  */
class BrlyQCon1NRelay {

public:
	BrlyQCon1NRelay(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQCon1NRelay: recordset of TblBrlyQCon1NRelay
  */
class ListBrlyQCon1NRelay {

public:
	ListBrlyQCon1NRelay();
	ListBrlyQCon1NRelay(const ListBrlyQCon1NRelay& src);
	~ListBrlyQCon1NRelay();

	void clear();
	unsigned int size() const;
	void append(BrlyQCon1NRelay* rec);

	ListBrlyQCon1NRelay& operator=(const ListBrlyQCon1NRelay& src);

public:
	vector<BrlyQCon1NRelay*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQCon1NRelay: C++ wrapper for table TblBrlyQCon1NRelay
  */
class TblBrlyQCon1NRelay {

public:
	TblBrlyQCon1NRelay();
	virtual ~TblBrlyQCon1NRelay();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQCon1NRelay** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQCon1NRelay& rst);

	virtual void insertRec(BrlyQCon1NRelay* rec);
	ubigint insertNewRec(BrlyQCon1NRelay** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQCon1NRelay& rst, BrlyQCon1NRelay** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQCon1NRelay& rst);
	virtual void updateRec(BrlyQCon1NRelay* rec);
	virtual void updateRst(ListBrlyQCon1NRelay& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQCon1NRelay** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQCon1NRelay& rst);
};

/**
  * MyBrlyQCon1NRelay: C++ wrapper for table TblBrlyQCon1NRelay (MySQL database)
  */
class MyTblBrlyQCon1NRelay : public TblBrlyQCon1NRelay, public MyTable {

public:
	MyTblBrlyQCon1NRelay();
	~MyTblBrlyQCon1NRelay();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQCon1NRelay** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQCon1NRelay& rst);

	void insertRec(BrlyQCon1NRelay* rec);
	void insertRst(ListBrlyQCon1NRelay& rst);
	void updateRec(BrlyQCon1NRelay* rec);
	void updateRst(ListBrlyQCon1NRelay& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQCon1NRelay** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQCon1NRelay& rst);
};

/**
  * PgBrlyQCon1NRelay: C++ wrapper for table TblBrlyQCon1NRelay (PgSQL database)
  */
class PgTblBrlyQCon1NRelay : public TblBrlyQCon1NRelay, public PgTable {

public:
	PgTblBrlyQCon1NRelay();
	~PgTblBrlyQCon1NRelay();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQCon1NRelay** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQCon1NRelay& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQCon1NRelay** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQCon1NRelay& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQCon1NRelay** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQCon1NRelay& rst);

	void insertRec(BrlyQCon1NRelay* rec);
	void insertRst(ListBrlyQCon1NRelay& rst);
	void updateRec(BrlyQCon1NRelay* rec);
	void updateRst(ListBrlyQCon1NRelay& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQCon1NRelay** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQCon1NRelay& rst);
};

#endif

