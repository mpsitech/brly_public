/**
  * \file BrlyLRMConnectionMEquipment.h
  * database access for table TblBrlyLRMConnectionMEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYLRMCONNECTIONMEQUIPMENT_H
#define BRLYLRMCONNECTIONMEQUIPMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyLRMConnectionMEquipment: record of TblBrlyLRMConnectionMEquipment
  */
class BrlyLRMConnectionMEquipment {

public:
	BrlyLRMConnectionMEquipment(const ubigint ref = 0, const uint conIxBrlyVLat = 0, const ubigint conRefBrlyMConnection = 0, const uint conNum = 0, const ubigint refBrlyMEquipment = 0);

public:
	ubigint ref;
	uint conIxBrlyVLat;
	ubigint conRefBrlyMConnection;
	uint conNum;
	ubigint refBrlyMEquipment;

public:
	bool operator==(const BrlyLRMConnectionMEquipment& comp);
	bool operator!=(const BrlyLRMConnectionMEquipment& comp);
};

/**
  * ListBrlyLRMConnectionMEquipment: recordset of TblBrlyLRMConnectionMEquipment
  */
class ListBrlyLRMConnectionMEquipment {

public:
	ListBrlyLRMConnectionMEquipment();
	ListBrlyLRMConnectionMEquipment(const ListBrlyLRMConnectionMEquipment& src);
	~ListBrlyLRMConnectionMEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyLRMConnectionMEquipment* rec);

	BrlyLRMConnectionMEquipment* operator[](const uint ix);
	ListBrlyLRMConnectionMEquipment& operator=(const ListBrlyLRMConnectionMEquipment& src);
	bool operator==(const ListBrlyLRMConnectionMEquipment& comp);
	bool operator!=(const ListBrlyLRMConnectionMEquipment& comp);

public:
	vector<BrlyLRMConnectionMEquipment*> nodes;
};

/**
  * TblBrlyLRMConnectionMEquipment: C++ wrapper for table TblBrlyLRMConnectionMEquipment
  */
class TblBrlyLRMConnectionMEquipment {

public:

public:
	TblBrlyLRMConnectionMEquipment();
	virtual ~TblBrlyLRMConnectionMEquipment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyLRMConnectionMEquipment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyLRMConnectionMEquipment& rst);

	virtual void insertRec(BrlyLRMConnectionMEquipment* rec);
	ubigint insertNewRec(BrlyLRMConnectionMEquipment** rec = NULL, const uint conIxBrlyVLat = 0, const ubigint conRefBrlyMConnection = 0, const uint conNum = 0, const ubigint refBrlyMEquipment = 0);
	ubigint appendNewRecToRst(ListBrlyLRMConnectionMEquipment& rst, BrlyLRMConnectionMEquipment** rec = NULL, const uint conIxBrlyVLat = 0, const ubigint conRefBrlyMConnection = 0, const uint conNum = 0, const ubigint refBrlyMEquipment = 0);
	virtual void insertRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	virtual void updateRec(BrlyLRMConnectionMEquipment* rec);
	virtual void updateRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyLRMConnectionMEquipment** rec);
	virtual ubigint loadConsByEqp(ubigint refBrlyMEquipment, const bool append, vector<ubigint>& conRefBrlyMConnections);
	virtual ubigint loadEqpsByCon(ubigint conRefBrlyMConnection, const bool append, vector<ubigint>& refBrlyMEquipments);
	virtual ubigint loadRefsByConLat(ubigint conRefBrlyMConnection, uint conIxBrlyVLat, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByCon(ubigint conRefBrlyMConnection, const bool append, ListBrlyLRMConnectionMEquipment& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyLRMConnectionMEquipment& rst);
};

/**
  * MyBrlyLRMConnectionMEquipment: C++ wrapper for table TblBrlyLRMConnectionMEquipment (MySQL database)
  */
class MyTblBrlyLRMConnectionMEquipment : public TblBrlyLRMConnectionMEquipment, public MyTable {

public:
	MyTblBrlyLRMConnectionMEquipment();
	~MyTblBrlyLRMConnectionMEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyLRMConnectionMEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyLRMConnectionMEquipment& rst);

	void insertRec(BrlyLRMConnectionMEquipment* rec);
	void insertRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	void updateRec(BrlyLRMConnectionMEquipment* rec);
	void updateRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyLRMConnectionMEquipment** rec);
	ubigint loadConsByEqp(ubigint refBrlyMEquipment, const bool append, vector<ubigint>& conRefBrlyMConnections);
	ubigint loadEqpsByCon(ubigint conRefBrlyMConnection, const bool append, vector<ubigint>& refBrlyMEquipments);
	ubigint loadRefsByConLat(ubigint conRefBrlyMConnection, uint conIxBrlyVLat, const bool append, vector<ubigint>& refs);
	ubigint loadRstByCon(ubigint conRefBrlyMConnection, const bool append, ListBrlyLRMConnectionMEquipment& rst);
};

/**
  * PgBrlyLRMConnectionMEquipment: C++ wrapper for table TblBrlyLRMConnectionMEquipment (PgSQL database)
  */
class PgTblBrlyLRMConnectionMEquipment : public TblBrlyLRMConnectionMEquipment, public PgTable {

public:
	PgTblBrlyLRMConnectionMEquipment();
	~PgTblBrlyLRMConnectionMEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyLRMConnectionMEquipment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyLRMConnectionMEquipment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyLRMConnectionMEquipment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyLRMConnectionMEquipment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyLRMConnectionMEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyLRMConnectionMEquipment& rst);

	void insertRec(BrlyLRMConnectionMEquipment* rec);
	void insertRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	void updateRec(BrlyLRMConnectionMEquipment* rec);
	void updateRst(ListBrlyLRMConnectionMEquipment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyLRMConnectionMEquipment** rec);
	ubigint loadConsByEqp(ubigint refBrlyMEquipment, const bool append, vector<ubigint>& conRefBrlyMConnections);
	ubigint loadEqpsByCon(ubigint conRefBrlyMConnection, const bool append, vector<ubigint>& refBrlyMEquipments);
	ubigint loadRefsByConLat(ubigint conRefBrlyMConnection, uint conIxBrlyVLat, const bool append, vector<ubigint>& refs);
	ubigint loadRstByCon(ubigint conRefBrlyMConnection, const bool append, ListBrlyLRMConnectionMEquipment& rst);
};

#endif

