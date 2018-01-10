/**
  * \file BrlyMSegment.h
  * database access for table TblBrlyMSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMSEGMENT_H
#define BRLYMSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMSegmentRefTbl TblBrlyMSegment::VecVRefTbl

/**
  * BrlyMSegment: record of TblBrlyMSegment
  */
class BrlyMSegment {

public:
	BrlyMSegment(const ubigint ref = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const uint refNum = 0, const double deltaphi = 0.0, const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const uint start = 0, const uint stop = 0, const bool Calcdone = false);

public:
	ubigint ref;
	uint refIxVTbl;
	ubigint refUref;
	uint refNum;
	double deltaphi;
	double alt0;
	double alt1;
	double theta0;
	double theta1;
	double phi0;
	double phi1;
	uint start;
	uint stop;
	bool Calcdone;

public:
	bool operator==(const BrlyMSegment& comp);
	bool operator!=(const BrlyMSegment& comp);
};

/**
  * ListBrlyMSegment: recordset of TblBrlyMSegment
  */
class ListBrlyMSegment {

public:
	ListBrlyMSegment();
	ListBrlyMSegment(const ListBrlyMSegment& src);
	~ListBrlyMSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyMSegment* rec);

	BrlyMSegment* operator[](const uint ix);
	ListBrlyMSegment& operator=(const ListBrlyMSegment& src);
	bool operator==(const ListBrlyMSegment& comp);
	bool operator!=(const ListBrlyMSegment& comp);

public:
	vector<BrlyMSegment*> nodes;
};

/**
  * TblBrlyMSegment: C++ wrapper for table TblBrlyMSegment
  */
class TblBrlyMSegment {

public:
	/**
		* VecVRefTbl (full: VecBrlyVMSegmentRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const uint CON = 1;
		static const uint FLT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

public:
	TblBrlyMSegment();
	virtual ~TblBrlyMSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMSegment& rst);

	virtual void insertRec(BrlyMSegment* rec);
	ubigint insertNewRec(BrlyMSegment** rec = NULL, const uint refIxVTbl = 0, const ubigint refUref = 0, const uint refNum = 0, const double deltaphi = 0.0, const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const uint start = 0, const uint stop = 0, const bool Calcdone = false);
	ubigint appendNewRecToRst(ListBrlyMSegment& rst, BrlyMSegment** rec = NULL, const uint refIxVTbl = 0, const ubigint refUref = 0, const uint refNum = 0, const double deltaphi = 0.0, const double alt0 = 0.0, const double alt1 = 0.0, const double theta0 = 0.0, const double theta1 = 0.0, const double phi0 = 0.0, const double phi1 = 0.0, const uint start = 0, const uint stop = 0, const bool Calcdone = false);
	virtual void insertRst(ListBrlyMSegment& rst, bool transact = false);
	virtual void updateRec(BrlyMSegment* rec);
	virtual void updateRst(ListBrlyMSegment& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMSegment** rec);
	virtual ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListBrlyMSegment& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMSegment& rst);
};

/**
  * MyBrlyMSegment: C++ wrapper for table TblBrlyMSegment (MySQL database)
  */
class MyTblBrlyMSegment : public TblBrlyMSegment, public MyTable {

public:
	MyTblBrlyMSegment();
	~MyTblBrlyMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMSegment& rst);

	void insertRec(BrlyMSegment* rec);
	void insertRst(ListBrlyMSegment& rst, bool transact = false);
	void updateRec(BrlyMSegment* rec);
	void updateRst(ListBrlyMSegment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMSegment** rec);
	ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListBrlyMSegment& rst);
};

/**
  * PgBrlyMSegment: C++ wrapper for table TblBrlyMSegment (PgSQL database)
  */
class PgTblBrlyMSegment : public TblBrlyMSegment, public PgTable {

public:
	PgTblBrlyMSegment();
	~PgTblBrlyMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMSegment& rst);

	void insertRec(BrlyMSegment* rec);
	void insertRst(ListBrlyMSegment& rst, bool transact = false);
	void updateRec(BrlyMSegment* rec);
	void updateRst(ListBrlyMSegment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMSegment** rec);
	ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListBrlyMSegment& rst);
};

#endif

