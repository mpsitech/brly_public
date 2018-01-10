/**
  * \file BrlyQConMapRelay.h
  * Dbs and XML wrapper for table TblBrlyQConMapRelay (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPRELAY_H
#define BRLYQCONMAPRELAY_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapRelay: record of TblBrlyQConMapRelay
  */
class BrlyQConMapRelay {

public:
	BrlyQConMapRelay(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const uint ixVDir = 0, const string srefIxVDir = "", const bool Connected = false, const string yesnoConnected = "", const usmallint Nhop = 0);

public:
	ubigint qref;
	bool qwr;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint x1Start;
	uint x1Stop;
	uint ixVDir;
	string srefIxVDir;
	bool Connected;
	string yesnoConnected;
	usmallint Nhop;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConMapRelay: recordset of TblBrlyQConMapRelay
  */
class ListBrlyQConMapRelay {

public:
	ListBrlyQConMapRelay();
	ListBrlyQConMapRelay(const ListBrlyQConMapRelay& src);
	~ListBrlyQConMapRelay();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapRelay* rec);

	ListBrlyQConMapRelay& operator=(const ListBrlyQConMapRelay& src);

public:
	vector<BrlyQConMapRelay*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConMapRelay: C++ wrapper for table TblBrlyQConMapRelay
  */
class TblBrlyQConMapRelay {

public:
	TblBrlyQConMapRelay();
	virtual ~TblBrlyQConMapRelay();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConMapRelay** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapRelay& rst);

	virtual void insertRec(BrlyQConMapRelay* rec);
	ubigint insertNewRec(BrlyQConMapRelay** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const uint ixVDir = 0, const string srefIxVDir = "", const bool Connected = false, const string yesnoConnected = "", const usmallint Nhop = 0);
	ubigint appendNewRecToRst(ListBrlyQConMapRelay& rst, BrlyQConMapRelay** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const uint ixVDir = 0, const string srefIxVDir = "", const bool Connected = false, const string yesnoConnected = "", const usmallint Nhop = 0);
	virtual void insertRst(ListBrlyQConMapRelay& rst);
	virtual void updateRec(BrlyQConMapRelay* rec);
	virtual void updateRst(ListBrlyQConMapRelay& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConMapRelay** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapRelay& rst);
};

/**
  * MyBrlyQConMapRelay: C++ wrapper for table TblBrlyQConMapRelay (MySQL database)
  */
class MyTblBrlyQConMapRelay : public TblBrlyQConMapRelay, public MyTable {

public:
	MyTblBrlyQConMapRelay();
	~MyTblBrlyQConMapRelay();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapRelay** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapRelay& rst);

	void insertRec(BrlyQConMapRelay* rec);
	void insertRst(ListBrlyQConMapRelay& rst);
	void updateRec(BrlyQConMapRelay* rec);
	void updateRst(ListBrlyQConMapRelay& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapRelay** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapRelay& rst);
};

/**
  * PgBrlyQConMapRelay: C++ wrapper for table TblBrlyQConMapRelay (PgSQL database)
  */
class PgTblBrlyQConMapRelay : public TblBrlyQConMapRelay, public PgTable {

public:
	PgTblBrlyQConMapRelay();
	~PgTblBrlyQConMapRelay();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapRelay** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapRelay& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapRelay** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapRelay& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapRelay** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapRelay& rst);

	void insertRec(BrlyQConMapRelay* rec);
	void insertRst(ListBrlyQConMapRelay& rst);
	void updateRec(BrlyQConMapRelay* rec);
	void updateRst(ListBrlyQConMapRelay& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapRelay** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapRelay& rst);
};

#endif

