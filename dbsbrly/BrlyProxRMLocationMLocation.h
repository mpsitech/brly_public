/**
  * \file BrlyProxRMLocationMLocation.h
  * database access for table TblBrlyProxRMLocationMLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYPROXRMLOCATIONMLOCATION_H
#define BRLYPROXRMLOCATIONMLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyProxRMLocationMLocation: record of TblBrlyProxRMLocationMLocation
  */
class BrlyProxRMLocationMLocation {

public:
	BrlyProxRMLocationMLocation(const ubigint ref = 0, const ubigint dstRefBrlyMLocation = 0, const ubigint orgRefBrlyMLocation = 0, const double deltaphi = 0.0);

public:
	ubigint ref;
	ubigint dstRefBrlyMLocation;
	ubigint orgRefBrlyMLocation;
	double deltaphi;

public:
	bool operator==(const BrlyProxRMLocationMLocation& comp);
	bool operator!=(const BrlyProxRMLocationMLocation& comp);
};

/**
  * ListBrlyProxRMLocationMLocation: recordset of TblBrlyProxRMLocationMLocation
  */
class ListBrlyProxRMLocationMLocation {

public:
	ListBrlyProxRMLocationMLocation();
	ListBrlyProxRMLocationMLocation(const ListBrlyProxRMLocationMLocation& src);
	~ListBrlyProxRMLocationMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyProxRMLocationMLocation* rec);

	BrlyProxRMLocationMLocation* operator[](const uint ix);
	ListBrlyProxRMLocationMLocation& operator=(const ListBrlyProxRMLocationMLocation& src);
	bool operator==(const ListBrlyProxRMLocationMLocation& comp);
	bool operator!=(const ListBrlyProxRMLocationMLocation& comp);

public:
	vector<BrlyProxRMLocationMLocation*> nodes;
};

/**
  * TblBrlyProxRMLocationMLocation: C++ wrapper for table TblBrlyProxRMLocationMLocation
  */
class TblBrlyProxRMLocationMLocation {

public:

public:
	TblBrlyProxRMLocationMLocation();
	virtual ~TblBrlyProxRMLocationMLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyProxRMLocationMLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyProxRMLocationMLocation& rst);

	virtual void insertRec(BrlyProxRMLocationMLocation* rec);
	ubigint insertNewRec(BrlyProxRMLocationMLocation** rec = NULL, const ubigint dstRefBrlyMLocation = 0, const ubigint orgRefBrlyMLocation = 0, const double deltaphi = 0.0);
	ubigint appendNewRecToRst(ListBrlyProxRMLocationMLocation& rst, BrlyProxRMLocationMLocation** rec = NULL, const ubigint dstRefBrlyMLocation = 0, const ubigint orgRefBrlyMLocation = 0, const double deltaphi = 0.0);
	virtual void insertRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyProxRMLocationMLocation* rec);
	virtual void updateRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyProxRMLocationMLocation** rec);
	virtual ubigint loadRstByDlo(ubigint dstRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
	virtual ubigint loadRstByOlo(ubigint orgRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyProxRMLocationMLocation& rst);
};

/**
  * MyBrlyProxRMLocationMLocation: C++ wrapper for table TblBrlyProxRMLocationMLocation (MySQL database)
  */
class MyTblBrlyProxRMLocationMLocation : public TblBrlyProxRMLocationMLocation, public MyTable {

public:
	MyTblBrlyProxRMLocationMLocation();
	~MyTblBrlyProxRMLocationMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyProxRMLocationMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyProxRMLocationMLocation& rst);

	void insertRec(BrlyProxRMLocationMLocation* rec);
	void insertRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	void updateRec(BrlyProxRMLocationMLocation* rec);
	void updateRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyProxRMLocationMLocation** rec);
	ubigint loadRstByDlo(ubigint dstRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
	ubigint loadRstByOlo(ubigint orgRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
};

/**
  * PgBrlyProxRMLocationMLocation: C++ wrapper for table TblBrlyProxRMLocationMLocation (PgSQL database)
  */
class PgTblBrlyProxRMLocationMLocation : public TblBrlyProxRMLocationMLocation, public PgTable {

public:
	PgTblBrlyProxRMLocationMLocation();
	~PgTblBrlyProxRMLocationMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyProxRMLocationMLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyProxRMLocationMLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyProxRMLocationMLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyProxRMLocationMLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyProxRMLocationMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyProxRMLocationMLocation& rst);

	void insertRec(BrlyProxRMLocationMLocation* rec);
	void insertRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	void updateRec(BrlyProxRMLocationMLocation* rec);
	void updateRst(ListBrlyProxRMLocationMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyProxRMLocationMLocation** rec);
	ubigint loadRstByDlo(ubigint dstRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
	ubigint loadRstByOlo(ubigint orgRefBrlyMLocation, const bool append, ListBrlyProxRMLocationMLocation& rst);
};

#endif

