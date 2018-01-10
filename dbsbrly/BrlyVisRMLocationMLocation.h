/**
  * \file BrlyVisRMLocationMLocation.h
  * database access for table TblBrlyVisRMLocationMLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYVISRMLOCATIONMLOCATION_H
#define BRLYVISRMLOCATIONMLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyVisRMLocationMLocation: record of TblBrlyVisRMLocationMLocation
  */
class BrlyVisRMLocationMLocation {

public:
	BrlyVisRMLocationMLocation(const ubigint ref = 0, const ubigint dstRefBrlyMLocation = 0, const ubigint orgRefBrlyMLocation = 0);

public:
	ubigint ref;
	ubigint dstRefBrlyMLocation;
	ubigint orgRefBrlyMLocation;

public:
	bool operator==(const BrlyVisRMLocationMLocation& comp);
	bool operator!=(const BrlyVisRMLocationMLocation& comp);
};

/**
  * ListBrlyVisRMLocationMLocation: recordset of TblBrlyVisRMLocationMLocation
  */
class ListBrlyVisRMLocationMLocation {

public:
	ListBrlyVisRMLocationMLocation();
	ListBrlyVisRMLocationMLocation(const ListBrlyVisRMLocationMLocation& src);
	~ListBrlyVisRMLocationMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyVisRMLocationMLocation* rec);

	BrlyVisRMLocationMLocation* operator[](const uint ix);
	ListBrlyVisRMLocationMLocation& operator=(const ListBrlyVisRMLocationMLocation& src);
	bool operator==(const ListBrlyVisRMLocationMLocation& comp);
	bool operator!=(const ListBrlyVisRMLocationMLocation& comp);

public:
	vector<BrlyVisRMLocationMLocation*> nodes;
};

/**
  * TblBrlyVisRMLocationMLocation: C++ wrapper for table TblBrlyVisRMLocationMLocation
  */
class TblBrlyVisRMLocationMLocation {

public:

public:
	TblBrlyVisRMLocationMLocation();
	virtual ~TblBrlyVisRMLocationMLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyVisRMLocationMLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyVisRMLocationMLocation& rst);

	virtual void insertRec(BrlyVisRMLocationMLocation* rec);
	ubigint insertNewRec(BrlyVisRMLocationMLocation** rec = NULL, const ubigint dstRefBrlyMLocation = 0, const ubigint orgRefBrlyMLocation = 0);
	ubigint appendNewRecToRst(ListBrlyVisRMLocationMLocation& rst, BrlyVisRMLocationMLocation** rec = NULL, const ubigint dstRefBrlyMLocation = 0, const ubigint orgRefBrlyMLocation = 0);
	virtual void insertRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyVisRMLocationMLocation* rec);
	virtual void updateRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyVisRMLocationMLocation** rec);
	virtual ubigint loadDlosByOlo(ubigint orgRefBrlyMLocation, const bool append, vector<ubigint>& dstRefBrlyMLocations);
	virtual ubigint loadOlosByDlo(ubigint dstRefBrlyMLocation, const bool append, vector<ubigint>& orgRefBrlyMLocations);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyVisRMLocationMLocation& rst);
};

/**
  * MyBrlyVisRMLocationMLocation: C++ wrapper for table TblBrlyVisRMLocationMLocation (MySQL database)
  */
class MyTblBrlyVisRMLocationMLocation : public TblBrlyVisRMLocationMLocation, public MyTable {

public:
	MyTblBrlyVisRMLocationMLocation();
	~MyTblBrlyVisRMLocationMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyVisRMLocationMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyVisRMLocationMLocation& rst);

	void insertRec(BrlyVisRMLocationMLocation* rec);
	void insertRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	void updateRec(BrlyVisRMLocationMLocation* rec);
	void updateRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyVisRMLocationMLocation** rec);
	ubigint loadDlosByOlo(ubigint orgRefBrlyMLocation, const bool append, vector<ubigint>& dstRefBrlyMLocations);
	ubigint loadOlosByDlo(ubigint dstRefBrlyMLocation, const bool append, vector<ubigint>& orgRefBrlyMLocations);
};

/**
  * PgBrlyVisRMLocationMLocation: C++ wrapper for table TblBrlyVisRMLocationMLocation (PgSQL database)
  */
class PgTblBrlyVisRMLocationMLocation : public TblBrlyVisRMLocationMLocation, public PgTable {

public:
	PgTblBrlyVisRMLocationMLocation();
	~PgTblBrlyVisRMLocationMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyVisRMLocationMLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyVisRMLocationMLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyVisRMLocationMLocation** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyVisRMLocationMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyVisRMLocationMLocation& rst);

	void insertRec(BrlyVisRMLocationMLocation* rec);
	void insertRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	void updateRec(BrlyVisRMLocationMLocation* rec);
	void updateRst(ListBrlyVisRMLocationMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyVisRMLocationMLocation** rec);
	ubigint loadDlosByOlo(ubigint orgRefBrlyMLocation, const bool append, vector<ubigint>& dstRefBrlyMLocations);
	ubigint loadOlosByDlo(ubigint dstRefBrlyMLocation, const bool append, vector<ubigint>& orgRefBrlyMLocations);
};

#endif

