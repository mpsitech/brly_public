/**
  * \file BrlyQLeg1NFlight.h
  * Dbs and XML wrapper for table TblBrlyQLeg1NFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEG1NFLIGHT_H
#define BRLYQLEG1NFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLeg1NFlight: record of TblBrlyQLeg1NFlight
  */
class BrlyQLeg1NFlight {

public:
	BrlyQLeg1NFlight(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQLeg1NFlight: recordset of TblBrlyQLeg1NFlight
  */
class ListBrlyQLeg1NFlight {

public:
	ListBrlyQLeg1NFlight();
	ListBrlyQLeg1NFlight(const ListBrlyQLeg1NFlight& src);
	~ListBrlyQLeg1NFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQLeg1NFlight* rec);

	ListBrlyQLeg1NFlight& operator=(const ListBrlyQLeg1NFlight& src);

public:
	vector<BrlyQLeg1NFlight*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLeg1NFlight: C++ wrapper for table TblBrlyQLeg1NFlight
  */
class TblBrlyQLeg1NFlight {

public:
	TblBrlyQLeg1NFlight();
	virtual ~TblBrlyQLeg1NFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLeg1NFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLeg1NFlight& rst);

	virtual void insertRec(BrlyQLeg1NFlight* rec);
	ubigint insertNewRec(BrlyQLeg1NFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQLeg1NFlight& rst, BrlyQLeg1NFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQLeg1NFlight& rst);
	virtual void updateRec(BrlyQLeg1NFlight* rec);
	virtual void updateRst(ListBrlyQLeg1NFlight& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLeg1NFlight** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLeg1NFlight& rst);
};

/**
  * MyBrlyQLeg1NFlight: C++ wrapper for table TblBrlyQLeg1NFlight (MySQL database)
  */
class MyTblBrlyQLeg1NFlight : public TblBrlyQLeg1NFlight, public MyTable {

public:
	MyTblBrlyQLeg1NFlight();
	~MyTblBrlyQLeg1NFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLeg1NFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLeg1NFlight& rst);

	void insertRec(BrlyQLeg1NFlight* rec);
	void insertRst(ListBrlyQLeg1NFlight& rst);
	void updateRec(BrlyQLeg1NFlight* rec);
	void updateRst(ListBrlyQLeg1NFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLeg1NFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLeg1NFlight& rst);
};

/**
  * PgBrlyQLeg1NFlight: C++ wrapper for table TblBrlyQLeg1NFlight (PgSQL database)
  */
class PgTblBrlyQLeg1NFlight : public TblBrlyQLeg1NFlight, public PgTable {

public:
	PgTblBrlyQLeg1NFlight();
	~PgTblBrlyQLeg1NFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLeg1NFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLeg1NFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLeg1NFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLeg1NFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLeg1NFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLeg1NFlight& rst);

	void insertRec(BrlyQLeg1NFlight* rec);
	void insertRst(ListBrlyQLeg1NFlight& rst);
	void updateRec(BrlyQLeg1NFlight* rec);
	void updateRst(ListBrlyQLeg1NFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLeg1NFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLeg1NFlight& rst);
};

#endif

