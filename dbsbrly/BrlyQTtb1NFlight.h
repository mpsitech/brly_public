/**
  * \file BrlyQTtb1NFlight.h
  * Dbs and XML wrapper for table TblBrlyQTtb1NFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQTTB1NFLIGHT_H
#define BRLYQTTB1NFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQTtb1NFlight: record of TblBrlyQTtb1NFlight
  */
class BrlyQTtb1NFlight {

public:
	BrlyQTtb1NFlight(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQTtb1NFlight: recordset of TblBrlyQTtb1NFlight
  */
class ListBrlyQTtb1NFlight {

public:
	ListBrlyQTtb1NFlight();
	ListBrlyQTtb1NFlight(const ListBrlyQTtb1NFlight& src);
	~ListBrlyQTtb1NFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQTtb1NFlight* rec);

	ListBrlyQTtb1NFlight& operator=(const ListBrlyQTtb1NFlight& src);

public:
	vector<BrlyQTtb1NFlight*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQTtb1NFlight: C++ wrapper for table TblBrlyQTtb1NFlight
  */
class TblBrlyQTtb1NFlight {

public:
	TblBrlyQTtb1NFlight();
	virtual ~TblBrlyQTtb1NFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQTtb1NFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtb1NFlight& rst);

	virtual void insertRec(BrlyQTtb1NFlight* rec);
	ubigint insertNewRec(BrlyQTtb1NFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQTtb1NFlight& rst, BrlyQTtb1NFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQTtb1NFlight& rst);
	virtual void updateRec(BrlyQTtb1NFlight* rec);
	virtual void updateRst(ListBrlyQTtb1NFlight& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQTtb1NFlight** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtb1NFlight& rst);
};

/**
  * MyBrlyQTtb1NFlight: C++ wrapper for table TblBrlyQTtb1NFlight (MySQL database)
  */
class MyTblBrlyQTtb1NFlight : public TblBrlyQTtb1NFlight, public MyTable {

public:
	MyTblBrlyQTtb1NFlight();
	~MyTblBrlyQTtb1NFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQTtb1NFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtb1NFlight& rst);

	void insertRec(BrlyQTtb1NFlight* rec);
	void insertRst(ListBrlyQTtb1NFlight& rst);
	void updateRec(BrlyQTtb1NFlight* rec);
	void updateRst(ListBrlyQTtb1NFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQTtb1NFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtb1NFlight& rst);
};

/**
  * PgBrlyQTtb1NFlight: C++ wrapper for table TblBrlyQTtb1NFlight (PgSQL database)
  */
class PgTblBrlyQTtb1NFlight : public TblBrlyQTtb1NFlight, public PgTable {

public:
	PgTblBrlyQTtb1NFlight();
	~PgTblBrlyQTtb1NFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQTtb1NFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQTtb1NFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQTtb1NFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQTtb1NFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQTtb1NFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQTtb1NFlight& rst);

	void insertRec(BrlyQTtb1NFlight* rec);
	void insertRst(ListBrlyQTtb1NFlight& rst);
	void updateRec(BrlyQTtb1NFlight* rec);
	void updateRst(ListBrlyQTtb1NFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQTtb1NFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQTtb1NFlight& rst);
};

#endif

