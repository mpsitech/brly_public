/**
  * \file BrlyMFlight.h
  * database access for table TblBrlyMFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMFLIGHT_H
#define BRLYMFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyMFlight: record of TblBrlyMFlight
  */
class BrlyMFlight {

public:
	BrlyMFlight(const ubigint ref = 0, const ubigint refBrlyMTimetable = 0, const ubigint refBrlyMEquipment = 0, const ubigint refBrlyMFaflight = 0, const ubigint refBrlyMLeg = 0, const string sref = "", const uint start = 0, const uint stop = 0, const uint xStart = 0, const uint xStop = 0, const bool Calcdone = false, const bool Segdone = false);

public:
	ubigint ref;
	ubigint refBrlyMTimetable;
	ubigint refBrlyMEquipment;
	ubigint refBrlyMFaflight;
	ubigint refBrlyMLeg;
	string sref;
	uint start;
	uint stop;
	uint xStart;
	uint xStop;
	bool Calcdone;
	bool Segdone;

public:
	bool operator==(const BrlyMFlight& comp);
	bool operator!=(const BrlyMFlight& comp);
};

/**
  * ListBrlyMFlight: recordset of TblBrlyMFlight
  */
class ListBrlyMFlight {

public:
	ListBrlyMFlight();
	ListBrlyMFlight(const ListBrlyMFlight& src);
	~ListBrlyMFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyMFlight* rec);

	BrlyMFlight* operator[](const uint ix);
	ListBrlyMFlight& operator=(const ListBrlyMFlight& src);
	bool operator==(const ListBrlyMFlight& comp);
	bool operator!=(const ListBrlyMFlight& comp);

public:
	vector<BrlyMFlight*> nodes;
};

/**
  * TblBrlyMFlight: C++ wrapper for table TblBrlyMFlight
  */
class TblBrlyMFlight {

public:

public:
	TblBrlyMFlight();
	virtual ~TblBrlyMFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFlight& rst);

	virtual void insertRec(BrlyMFlight* rec);
	ubigint insertNewRec(BrlyMFlight** rec = NULL, const ubigint refBrlyMTimetable = 0, const ubigint refBrlyMEquipment = 0, const ubigint refBrlyMFaflight = 0, const ubigint refBrlyMLeg = 0, const string sref = "", const uint start = 0, const uint stop = 0, const uint xStart = 0, const uint xStop = 0, const bool Calcdone = false, const bool Segdone = false);
	ubigint appendNewRecToRst(ListBrlyMFlight& rst, BrlyMFlight** rec = NULL, const ubigint refBrlyMTimetable = 0, const ubigint refBrlyMEquipment = 0, const ubigint refBrlyMFaflight = 0, const ubigint refBrlyMLeg = 0, const string sref = "", const uint start = 0, const uint stop = 0, const uint xStart = 0, const uint xStop = 0, const bool Calcdone = false, const bool Segdone = false);
	virtual void insertRst(ListBrlyMFlight& rst, bool transact = false);
	virtual void updateRec(BrlyMFlight* rec);
	virtual void updateRst(ListBrlyMFlight& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMFlight** rec);
	virtual bool loadRecByEqp(ubigint refBrlyMEquipment, BrlyMFlight** rec);
	virtual bool loadRecByFaf(ubigint refBrlyMFaflight, BrlyMFlight** rec);
	virtual ubigint loadRefsByLeg(ubigint refBrlyMLeg, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByLeg(ubigint refBrlyMLeg, const bool append, ListBrlyMFlight& rst);
	virtual bool loadSrfByRef(ubigint ref, string& sref);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMFlight& rst);
};

/**
  * MyBrlyMFlight: C++ wrapper for table TblBrlyMFlight (MySQL database)
  */
class MyTblBrlyMFlight : public TblBrlyMFlight, public MyTable {

public:
	MyTblBrlyMFlight();
	~MyTblBrlyMFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFlight& rst);

	void insertRec(BrlyMFlight* rec);
	void insertRst(ListBrlyMFlight& rst, bool transact = false);
	void updateRec(BrlyMFlight* rec);
	void updateRst(ListBrlyMFlight& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMFlight** rec);
	bool loadRecByEqp(ubigint refBrlyMEquipment, BrlyMFlight** rec);
	bool loadRecByFaf(ubigint refBrlyMFaflight, BrlyMFlight** rec);
	ubigint loadRefsByLeg(ubigint refBrlyMLeg, const bool append, vector<ubigint>& refs);
	ubigint loadRstByLeg(ubigint refBrlyMLeg, const bool append, ListBrlyMFlight& rst);
	bool loadSrfByRef(ubigint ref, string& sref);
};

/**
  * PgBrlyMFlight: C++ wrapper for table TblBrlyMFlight (PgSQL database)
  */
class PgTblBrlyMFlight : public TblBrlyMFlight, public PgTable {

public:
	PgTblBrlyMFlight();
	~PgTblBrlyMFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFlight& rst);

	void insertRec(BrlyMFlight* rec);
	void insertRst(ListBrlyMFlight& rst, bool transact = false);
	void updateRec(BrlyMFlight* rec);
	void updateRst(ListBrlyMFlight& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMFlight** rec);
	bool loadRecByEqp(ubigint refBrlyMEquipment, BrlyMFlight** rec);
	bool loadRecByFaf(ubigint refBrlyMFaflight, BrlyMFlight** rec);
	ubigint loadRefsByLeg(ubigint refBrlyMLeg, const bool append, vector<ubigint>& refs);
	ubigint loadRstByLeg(ubigint refBrlyMLeg, const bool append, ListBrlyMFlight& rst);
	bool loadSrfByRef(ubigint ref, string& sref);
};

#endif

