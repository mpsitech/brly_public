/**
  * \file BrlyRMSegmentMSegment.h
  * database access for table TblBrlyRMSegmentMSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMSEGMENTMSEGMENT_H
#define BRLYRMSEGMENTMSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMSegmentMSegment: record of TblBrlyRMSegmentMSegment
  */
class BrlyRMSegmentMSegment {

public:
	BrlyRMSegmentMSegment(const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const ubigint dstRefBrlyMSegment = 0, const ubigint orgRefBrlyMSegment = 0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);

public:
	ubigint ref;
	uint x1Start;
	uint x1Stop;
	double x2VisDstSegphi0;
	double x2VisDstSegphi1;
	ubigint dstRefBrlyMSegment;
	ubigint orgRefBrlyMSegment;
	double VisOrgSegphi0;
	double VisOrgSegphi1;

public:
	bool operator==(const BrlyRMSegmentMSegment& comp);
	bool operator!=(const BrlyRMSegmentMSegment& comp);
};

/**
  * ListBrlyRMSegmentMSegment: recordset of TblBrlyRMSegmentMSegment
  */
class ListBrlyRMSegmentMSegment {

public:
	ListBrlyRMSegmentMSegment();
	ListBrlyRMSegmentMSegment(const ListBrlyRMSegmentMSegment& src);
	~ListBrlyRMSegmentMSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyRMSegmentMSegment* rec);

	BrlyRMSegmentMSegment* operator[](const uint ix);
	ListBrlyRMSegmentMSegment& operator=(const ListBrlyRMSegmentMSegment& src);
	bool operator==(const ListBrlyRMSegmentMSegment& comp);
	bool operator!=(const ListBrlyRMSegmentMSegment& comp);

public:
	vector<BrlyRMSegmentMSegment*> nodes;
};

/**
  * TblBrlyRMSegmentMSegment: C++ wrapper for table TblBrlyRMSegmentMSegment
  */
class TblBrlyRMSegmentMSegment {

public:

public:
	TblBrlyRMSegmentMSegment();
	virtual ~TblBrlyRMSegmentMSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMSegmentMSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMSegmentMSegment& rst);

	virtual void insertRec(BrlyRMSegmentMSegment* rec);
	ubigint insertNewRec(BrlyRMSegmentMSegment** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const ubigint dstRefBrlyMSegment = 0, const ubigint orgRefBrlyMSegment = 0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyRMSegmentMSegment& rst, BrlyRMSegmentMSegment** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const ubigint dstRefBrlyMSegment = 0, const ubigint orgRefBrlyMSegment = 0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);
	virtual void insertRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	virtual void updateRec(BrlyRMSegmentMSegment* rec);
	virtual void updateRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMSegmentMSegment** rec);
	virtual ubigint loadRstByDsg(ubigint dstRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
	virtual ubigint loadRstByOsg(ubigint orgRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMSegmentMSegment& rst);
};

/**
  * MyBrlyRMSegmentMSegment: C++ wrapper for table TblBrlyRMSegmentMSegment (MySQL database)
  */
class MyTblBrlyRMSegmentMSegment : public TblBrlyRMSegmentMSegment, public MyTable {

public:
	MyTblBrlyRMSegmentMSegment();
	~MyTblBrlyRMSegmentMSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMSegmentMSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMSegmentMSegment& rst);

	void insertRec(BrlyRMSegmentMSegment* rec);
	void insertRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	void updateRec(BrlyRMSegmentMSegment* rec);
	void updateRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMSegmentMSegment** rec);
	ubigint loadRstByDsg(ubigint dstRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
	ubigint loadRstByOsg(ubigint orgRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
};

/**
  * PgBrlyRMSegmentMSegment: C++ wrapper for table TblBrlyRMSegmentMSegment (PgSQL database)
  */
class PgTblBrlyRMSegmentMSegment : public TblBrlyRMSegmentMSegment, public PgTable {

public:
	PgTblBrlyRMSegmentMSegment();
	~PgTblBrlyRMSegmentMSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMSegmentMSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMSegmentMSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMSegmentMSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMSegmentMSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMSegmentMSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMSegmentMSegment& rst);

	void insertRec(BrlyRMSegmentMSegment* rec);
	void insertRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	void updateRec(BrlyRMSegmentMSegment* rec);
	void updateRst(ListBrlyRMSegmentMSegment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMSegmentMSegment** rec);
	ubigint loadRstByDsg(ubigint dstRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
	ubigint loadRstByOsg(ubigint orgRefBrlyMSegment, const bool append, ListBrlyRMSegmentMSegment& rst);
};

#endif

