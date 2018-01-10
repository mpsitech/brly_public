/**
  * \file BrlyAMRegionDstswitch.h
  * database access for table TblBrlyAMRegionDstswitch (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYAMREGIONDSTSWITCH_H
#define BRLYAMREGIONDSTSWITCH_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAMRegionDstswitch: record of TblBrlyAMRegionDstswitch
  */
class BrlyAMRegionDstswitch {

public:
	BrlyAMRegionDstswitch(const ubigint ref = 0, const ubigint refBrlyMRegion = 0, const uint startd = 0, const uint startt = 0);

public:
	ubigint ref;
	ubigint refBrlyMRegion;
	uint startd;
	uint startt;

public:
	bool operator==(const BrlyAMRegionDstswitch& comp);
	bool operator!=(const BrlyAMRegionDstswitch& comp);
};

/**
  * ListBrlyAMRegionDstswitch: recordset of TblBrlyAMRegionDstswitch
  */
class ListBrlyAMRegionDstswitch {

public:
	ListBrlyAMRegionDstswitch();
	ListBrlyAMRegionDstswitch(const ListBrlyAMRegionDstswitch& src);
	~ListBrlyAMRegionDstswitch();

	void clear();
	unsigned int size() const;
	void append(BrlyAMRegionDstswitch* rec);

	BrlyAMRegionDstswitch* operator[](const uint ix);
	ListBrlyAMRegionDstswitch& operator=(const ListBrlyAMRegionDstswitch& src);
	bool operator==(const ListBrlyAMRegionDstswitch& comp);
	bool operator!=(const ListBrlyAMRegionDstswitch& comp);

public:
	vector<BrlyAMRegionDstswitch*> nodes;
};

/**
  * TblBrlyAMRegionDstswitch: C++ wrapper for table TblBrlyAMRegionDstswitch
  */
class TblBrlyAMRegionDstswitch {

public:

public:
	TblBrlyAMRegionDstswitch();
	virtual ~TblBrlyAMRegionDstswitch();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAMRegionDstswitch** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMRegionDstswitch& rst);

	virtual void insertRec(BrlyAMRegionDstswitch* rec);
	ubigint insertNewRec(BrlyAMRegionDstswitch** rec = NULL, const ubigint refBrlyMRegion = 0, const uint startd = 0, const uint startt = 0);
	ubigint appendNewRecToRst(ListBrlyAMRegionDstswitch& rst, BrlyAMRegionDstswitch** rec = NULL, const ubigint refBrlyMRegion = 0, const uint startd = 0, const uint startt = 0);
	virtual void insertRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	virtual void updateRec(BrlyAMRegionDstswitch* rec);
	virtual void updateRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAMRegionDstswitch** rec);
	virtual ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyAMRegionDstswitch& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAMRegionDstswitch& rst);
};

/**
  * MyBrlyAMRegionDstswitch: C++ wrapper for table TblBrlyAMRegionDstswitch (MySQL database)
  */
class MyTblBrlyAMRegionDstswitch : public TblBrlyAMRegionDstswitch, public MyTable {

public:
	MyTblBrlyAMRegionDstswitch();
	~MyTblBrlyAMRegionDstswitch();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMRegionDstswitch** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMRegionDstswitch& rst);

	void insertRec(BrlyAMRegionDstswitch* rec);
	void insertRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	void updateRec(BrlyAMRegionDstswitch* rec);
	void updateRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMRegionDstswitch** rec);
	ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyAMRegionDstswitch& rst);
};

/**
  * PgBrlyAMRegionDstswitch: C++ wrapper for table TblBrlyAMRegionDstswitch (PgSQL database)
  */
class PgTblBrlyAMRegionDstswitch : public TblBrlyAMRegionDstswitch, public PgTable {

public:
	PgTblBrlyAMRegionDstswitch();
	~PgTblBrlyAMRegionDstswitch();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAMRegionDstswitch** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAMRegionDstswitch& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAMRegionDstswitch** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyAMRegionDstswitch& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAMRegionDstswitch** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAMRegionDstswitch& rst);

	void insertRec(BrlyAMRegionDstswitch* rec);
	void insertRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	void updateRec(BrlyAMRegionDstswitch* rec);
	void updateRst(ListBrlyAMRegionDstswitch& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAMRegionDstswitch** rec);
	ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyAMRegionDstswitch& rst);
};

#endif

