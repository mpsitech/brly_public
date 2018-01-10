/**
  * \file BrlyJMRegion.h
  * database access for table TblBrlyJMRegion (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYJMREGION_H
#define BRLYJMREGION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyJMRegion: record of TblBrlyJMRegion
  */
class BrlyJMRegion {

public:
	BrlyJMRegion(const ubigint ref = 0, const ubigint refBrlyMRegion = 0, const uint x1Startd = 0, const uint x1Stopd = 0, const uint ixVDst = 0, const double toffset = 0.0);

public:
	ubigint ref;
	ubigint refBrlyMRegion;
	uint x1Startd;
	uint x1Stopd;
	uint ixVDst;
	double toffset;

public:
	bool operator==(const BrlyJMRegion& comp);
	bool operator!=(const BrlyJMRegion& comp);
};

/**
  * ListBrlyJMRegion: recordset of TblBrlyJMRegion
  */
class ListBrlyJMRegion {

public:
	ListBrlyJMRegion();
	ListBrlyJMRegion(const ListBrlyJMRegion& src);
	~ListBrlyJMRegion();

	void clear();
	unsigned int size() const;
	void append(BrlyJMRegion* rec);

	BrlyJMRegion* operator[](const uint ix);
	ListBrlyJMRegion& operator=(const ListBrlyJMRegion& src);
	bool operator==(const ListBrlyJMRegion& comp);
	bool operator!=(const ListBrlyJMRegion& comp);

public:
	vector<BrlyJMRegion*> nodes;
};

/**
  * TblBrlyJMRegion: C++ wrapper for table TblBrlyJMRegion
  */
class TblBrlyJMRegion {

public:

public:
	TblBrlyJMRegion();
	virtual ~TblBrlyJMRegion();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyJMRegion** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMRegion& rst);

	virtual void insertRec(BrlyJMRegion* rec);
	ubigint insertNewRec(BrlyJMRegion** rec = NULL, const ubigint refBrlyMRegion = 0, const uint x1Startd = 0, const uint x1Stopd = 0, const uint ixVDst = 0, const double toffset = 0.0);
	ubigint appendNewRecToRst(ListBrlyJMRegion& rst, BrlyJMRegion** rec = NULL, const ubigint refBrlyMRegion = 0, const uint x1Startd = 0, const uint x1Stopd = 0, const uint ixVDst = 0, const double toffset = 0.0);
	virtual void insertRst(ListBrlyJMRegion& rst, bool transact = false);
	virtual void updateRec(BrlyJMRegion* rec);
	virtual void updateRst(ListBrlyJMRegion& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyJMRegion** rec);
	virtual bool loadRecByRegStaSto(ubigint refBrlyMRegion, uint x1Startd, uint x1Stopd, BrlyJMRegion** rec);
	virtual ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyJMRegion& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyJMRegion& rst);
};

/**
  * MyBrlyJMRegion: C++ wrapper for table TblBrlyJMRegion (MySQL database)
  */
class MyTblBrlyJMRegion : public TblBrlyJMRegion, public MyTable {

public:
	MyTblBrlyJMRegion();
	~MyTblBrlyJMRegion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJMRegion** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMRegion& rst);

	void insertRec(BrlyJMRegion* rec);
	void insertRst(ListBrlyJMRegion& rst, bool transact = false);
	void updateRec(BrlyJMRegion* rec);
	void updateRst(ListBrlyJMRegion& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJMRegion** rec);
	bool loadRecByRegStaSto(ubigint refBrlyMRegion, uint x1Startd, uint x1Stopd, BrlyJMRegion** rec);
	ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyJMRegion& rst);
};

/**
  * PgBrlyJMRegion: C++ wrapper for table TblBrlyJMRegion (PgSQL database)
  */
class PgTblBrlyJMRegion : public TblBrlyJMRegion, public PgTable {

public:
	PgTblBrlyJMRegion();
	~PgTblBrlyJMRegion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyJMRegion** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyJMRegion& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyJMRegion** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyJMRegion& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyJMRegion** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyJMRegion& rst);

	void insertRec(BrlyJMRegion* rec);
	void insertRst(ListBrlyJMRegion& rst, bool transact = false);
	void updateRec(BrlyJMRegion* rec);
	void updateRst(ListBrlyJMRegion& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyJMRegion** rec);
	bool loadRecByRegStaSto(ubigint refBrlyMRegion, uint x1Startd, uint x1Stopd, BrlyJMRegion** rec);
	ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyJMRegion& rst);
};

#endif

