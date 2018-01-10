/**
  * \file BrlyRMFlightMFlight.h
  * database access for table TblBrlyRMFlightMFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMFLIGHTMFLIGHT_H
#define BRLYRMFLIGHTMFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMFlightMFlight: record of TblBrlyRMFlightMFlight
  */
class BrlyRMFlightMFlight {

public:
	BrlyRMFlightMFlight(const ubigint ref = 0, const uint x1VisStart = 0, const uint x1VisStop = 0, const ubigint dstRefBrlyMFlight = 0, const ubigint orgRefBrlyMFlight = 0, const uint xVisStart = 0, const uint xVisStop = 0);

public:
	ubigint ref;
	uint x1VisStart;
	uint x1VisStop;
	ubigint dstRefBrlyMFlight;
	ubigint orgRefBrlyMFlight;
	uint xVisStart;
	uint xVisStop;

public:
	bool operator==(const BrlyRMFlightMFlight& comp);
	bool operator!=(const BrlyRMFlightMFlight& comp);
};

/**
  * ListBrlyRMFlightMFlight: recordset of TblBrlyRMFlightMFlight
  */
class ListBrlyRMFlightMFlight {

public:
	ListBrlyRMFlightMFlight();
	ListBrlyRMFlightMFlight(const ListBrlyRMFlightMFlight& src);
	~ListBrlyRMFlightMFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyRMFlightMFlight* rec);

	BrlyRMFlightMFlight* operator[](const uint ix);
	ListBrlyRMFlightMFlight& operator=(const ListBrlyRMFlightMFlight& src);
	bool operator==(const ListBrlyRMFlightMFlight& comp);
	bool operator!=(const ListBrlyRMFlightMFlight& comp);

public:
	vector<BrlyRMFlightMFlight*> nodes;
};

/**
  * TblBrlyRMFlightMFlight: C++ wrapper for table TblBrlyRMFlightMFlight
  */
class TblBrlyRMFlightMFlight {

public:

public:
	TblBrlyRMFlightMFlight();
	virtual ~TblBrlyRMFlightMFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMFlightMFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMFlightMFlight& rst);

	virtual void insertRec(BrlyRMFlightMFlight* rec);
	ubigint insertNewRec(BrlyRMFlightMFlight** rec = NULL, const uint x1VisStart = 0, const uint x1VisStop = 0, const ubigint dstRefBrlyMFlight = 0, const ubigint orgRefBrlyMFlight = 0, const uint xVisStart = 0, const uint xVisStop = 0);
	ubigint appendNewRecToRst(ListBrlyRMFlightMFlight& rst, BrlyRMFlightMFlight** rec = NULL, const uint x1VisStart = 0, const uint x1VisStop = 0, const ubigint dstRefBrlyMFlight = 0, const ubigint orgRefBrlyMFlight = 0, const uint xVisStart = 0, const uint xVisStop = 0);
	virtual void insertRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	virtual void updateRec(BrlyRMFlightMFlight* rec);
	virtual void updateRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMFlightMFlight** rec);
	virtual ubigint loadRstByDfl(ubigint dstRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
	virtual ubigint loadRstByOfl(ubigint orgRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMFlightMFlight& rst);
};

/**
  * MyBrlyRMFlightMFlight: C++ wrapper for table TblBrlyRMFlightMFlight (MySQL database)
  */
class MyTblBrlyRMFlightMFlight : public TblBrlyRMFlightMFlight, public MyTable {

public:
	MyTblBrlyRMFlightMFlight();
	~MyTblBrlyRMFlightMFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMFlightMFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMFlightMFlight& rst);

	void insertRec(BrlyRMFlightMFlight* rec);
	void insertRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	void updateRec(BrlyRMFlightMFlight* rec);
	void updateRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMFlightMFlight** rec);
	ubigint loadRstByDfl(ubigint dstRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
	ubigint loadRstByOfl(ubigint orgRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
};

/**
  * PgBrlyRMFlightMFlight: C++ wrapper for table TblBrlyRMFlightMFlight (PgSQL database)
  */
class PgTblBrlyRMFlightMFlight : public TblBrlyRMFlightMFlight, public PgTable {

public:
	PgTblBrlyRMFlightMFlight();
	~PgTblBrlyRMFlightMFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMFlightMFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMFlightMFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMFlightMFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMFlightMFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMFlightMFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMFlightMFlight& rst);

	void insertRec(BrlyRMFlightMFlight* rec);
	void insertRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	void updateRec(BrlyRMFlightMFlight* rec);
	void updateRst(ListBrlyRMFlightMFlight& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMFlightMFlight** rec);
	ubigint loadRstByDfl(ubigint dstRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
	ubigint loadRstByOfl(ubigint orgRefBrlyMFlight, const bool append, ListBrlyRMFlightMFlight& rst);
};

#endif

