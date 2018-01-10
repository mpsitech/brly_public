/**
  * \file BrlyRMLocationMSegment.h
  * database access for table TblBrlyRMLocationMSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMLOCATIONMSEGMENT_H
#define BRLYRMLOCATIONMSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMLocationMSegment: record of TblBrlyRMLocationMSegment
  */
class BrlyRMLocationMSegment {

public:
	BrlyRMLocationMSegment(const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const ubigint refBrlyMLocation = 0, const ubigint refBrlyMSegment = 0, const double segphi = 0.0, const double segtheta = 0.0);

public:
	ubigint ref;
	uint x1Start;
	uint x1Stop;
	double x2VisSegphi0;
	double x2VisSegphi1;
	ubigint refBrlyMLocation;
	ubigint refBrlyMSegment;
	double segphi;
	double segtheta;

public:
	bool operator==(const BrlyRMLocationMSegment& comp);
	bool operator!=(const BrlyRMLocationMSegment& comp);
};

/**
  * ListBrlyRMLocationMSegment: recordset of TblBrlyRMLocationMSegment
  */
class ListBrlyRMLocationMSegment {

public:
	ListBrlyRMLocationMSegment();
	ListBrlyRMLocationMSegment(const ListBrlyRMLocationMSegment& src);
	~ListBrlyRMLocationMSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyRMLocationMSegment* rec);

	BrlyRMLocationMSegment* operator[](const uint ix);
	ListBrlyRMLocationMSegment& operator=(const ListBrlyRMLocationMSegment& src);
	bool operator==(const ListBrlyRMLocationMSegment& comp);
	bool operator!=(const ListBrlyRMLocationMSegment& comp);

public:
	vector<BrlyRMLocationMSegment*> nodes;
};

/**
  * TblBrlyRMLocationMSegment: C++ wrapper for table TblBrlyRMLocationMSegment
  */
class TblBrlyRMLocationMSegment {

public:

public:
	TblBrlyRMLocationMSegment();
	virtual ~TblBrlyRMLocationMSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMLocationMSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLocationMSegment& rst);

	virtual void insertRec(BrlyRMLocationMSegment* rec);
	ubigint insertNewRec(BrlyRMLocationMSegment** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const ubigint refBrlyMLocation = 0, const ubigint refBrlyMSegment = 0, const double segphi = 0.0, const double segtheta = 0.0);
	ubigint appendNewRecToRst(ListBrlyRMLocationMSegment& rst, BrlyRMLocationMSegment** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const ubigint refBrlyMLocation = 0, const ubigint refBrlyMSegment = 0, const double segphi = 0.0, const double segtheta = 0.0);
	virtual void insertRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	virtual void updateRec(BrlyRMLocationMSegment* rec);
	virtual void updateRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMLocationMSegment** rec);
	virtual ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMLocationMSegment& rst);
	virtual ubigint loadRstBySeg(ubigint refBrlyMSegment, const bool append, ListBrlyRMLocationMSegment& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMLocationMSegment& rst);
};

/**
  * MyBrlyRMLocationMSegment: C++ wrapper for table TblBrlyRMLocationMSegment (MySQL database)
  */
class MyTblBrlyRMLocationMSegment : public TblBrlyRMLocationMSegment, public MyTable {

public:
	MyTblBrlyRMLocationMSegment();
	~MyTblBrlyRMLocationMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMLocationMSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLocationMSegment& rst);

	void insertRec(BrlyRMLocationMSegment* rec);
	void insertRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	void updateRec(BrlyRMLocationMSegment* rec);
	void updateRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMLocationMSegment** rec);
	ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMLocationMSegment& rst);
	ubigint loadRstBySeg(ubigint refBrlyMSegment, const bool append, ListBrlyRMLocationMSegment& rst);
};

/**
  * PgBrlyRMLocationMSegment: C++ wrapper for table TblBrlyRMLocationMSegment (PgSQL database)
  */
class PgTblBrlyRMLocationMSegment : public TblBrlyRMLocationMSegment, public PgTable {

public:
	PgTblBrlyRMLocationMSegment();
	~PgTblBrlyRMLocationMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMLocationMSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMLocationMSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMLocationMSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMLocationMSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMLocationMSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLocationMSegment& rst);

	void insertRec(BrlyRMLocationMSegment* rec);
	void insertRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	void updateRec(BrlyRMLocationMSegment* rec);
	void updateRst(ListBrlyRMLocationMSegment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMLocationMSegment** rec);
	ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMLocationMSegment& rst);
	ubigint loadRstBySeg(ubigint refBrlyMSegment, const bool append, ListBrlyRMLocationMSegment& rst);
};

#endif

