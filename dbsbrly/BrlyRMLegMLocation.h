/**
  * \file BrlyRMLegMLocation.h
  * database access for table TblBrlyRMLegMLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMLEGMLOCATION_H
#define BRLYRMLEGMLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMLegMLocation: record of TblBrlyRMLegMLocation
  */
class BrlyRMLegMLocation {

public:
	BrlyRMLegMLocation(const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const ubigint refBrlyMLeg = 0, const ubigint refBrlyMLocation = 0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);

public:
	ubigint ref;
	double x1VisLegphi0;
	double x1VisLegphi1;
	ubigint refBrlyMLeg;
	ubigint refBrlyMLocation;
	double legphi;
	double legtheta;
	double xVisLegphi0;
	double xVisLegphi1;

public:
	bool operator==(const BrlyRMLegMLocation& comp);
	bool operator!=(const BrlyRMLegMLocation& comp);
};

/**
  * ListBrlyRMLegMLocation: recordset of TblBrlyRMLegMLocation
  */
class ListBrlyRMLegMLocation {

public:
	ListBrlyRMLegMLocation();
	ListBrlyRMLegMLocation(const ListBrlyRMLegMLocation& src);
	~ListBrlyRMLegMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyRMLegMLocation* rec);

	BrlyRMLegMLocation* operator[](const uint ix);
	ListBrlyRMLegMLocation& operator=(const ListBrlyRMLegMLocation& src);
	bool operator==(const ListBrlyRMLegMLocation& comp);
	bool operator!=(const ListBrlyRMLegMLocation& comp);

public:
	vector<BrlyRMLegMLocation*> nodes;
};

/**
  * TblBrlyRMLegMLocation: C++ wrapper for table TblBrlyRMLegMLocation
  */
class TblBrlyRMLegMLocation {

public:

public:
	TblBrlyRMLegMLocation();
	virtual ~TblBrlyRMLegMLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMLegMLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLegMLocation& rst);

	virtual void insertRec(BrlyRMLegMLocation* rec);
	ubigint insertNewRec(BrlyRMLegMLocation** rec = NULL, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const ubigint refBrlyMLeg = 0, const ubigint refBrlyMLocation = 0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyRMLegMLocation& rst, BrlyRMLegMLocation** rec = NULL, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const ubigint refBrlyMLeg = 0, const ubigint refBrlyMLocation = 0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	virtual void insertRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyRMLegMLocation* rec);
	virtual void updateRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMLegMLocation** rec);
	virtual ubigint loadRstByLeg(ubigint refBrlyMLeg, const bool append, ListBrlyRMLegMLocation& rst);
	virtual ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMLegMLocation& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMLegMLocation& rst);
};

/**
  * MyBrlyRMLegMLocation: C++ wrapper for table TblBrlyRMLegMLocation (MySQL database)
  */
class MyTblBrlyRMLegMLocation : public TblBrlyRMLegMLocation, public MyTable {

public:
	MyTblBrlyRMLegMLocation();
	~MyTblBrlyRMLegMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMLegMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLegMLocation& rst);

	void insertRec(BrlyRMLegMLocation* rec);
	void insertRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	void updateRec(BrlyRMLegMLocation* rec);
	void updateRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMLegMLocation** rec);
	ubigint loadRstByLeg(ubigint refBrlyMLeg, const bool append, ListBrlyRMLegMLocation& rst);
	ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMLegMLocation& rst);
};

/**
  * PgBrlyRMLegMLocation: C++ wrapper for table TblBrlyRMLegMLocation (PgSQL database)
  */
class PgTblBrlyRMLegMLocation : public TblBrlyRMLegMLocation, public PgTable {

public:
	PgTblBrlyRMLegMLocation();
	~PgTblBrlyRMLegMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMLegMLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMLegMLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMLegMLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMLegMLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMLegMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLegMLocation& rst);

	void insertRec(BrlyRMLegMLocation* rec);
	void insertRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	void updateRec(BrlyRMLegMLocation* rec);
	void updateRst(ListBrlyRMLegMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMLegMLocation** rec);
	ubigint loadRstByLeg(ubigint refBrlyMLeg, const bool append, ListBrlyRMLegMLocation& rst);
	ubigint loadRstByLoc(ubigint refBrlyMLocation, const bool append, ListBrlyRMLegMLocation& rst);
};

#endif

