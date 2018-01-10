/**
  * \file BrlyORMConnectionMEquipment.h
  * database access for table TblBrlyORMConnectionMEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYORMCONNECTIONMEQUIPMENT_H
#define BRLYORMCONNECTIONMEQUIPMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyORMConnectionMEquipment: record of TblBrlyORMConnectionMEquipment
  */
class BrlyORMConnectionMEquipment {

public:
	BrlyORMConnectionMEquipment(const ubigint ref = 0, const ubigint refBrlyMConnection = 0, const uint x1Start = 0, const uint ixBrlyVOolop = 0, const ubigint pr1RefLR = 0, const ubigint pr2RefLR = 0);

public:
	ubigint ref;
	ubigint refBrlyMConnection;
	uint x1Start;
	uint ixBrlyVOolop;
	ubigint pr1RefLR;
	ubigint pr2RefLR;

public:
	bool operator==(const BrlyORMConnectionMEquipment& comp);
	bool operator!=(const BrlyORMConnectionMEquipment& comp);
};

/**
  * ListBrlyORMConnectionMEquipment: recordset of TblBrlyORMConnectionMEquipment
  */
class ListBrlyORMConnectionMEquipment {

public:
	ListBrlyORMConnectionMEquipment();
	ListBrlyORMConnectionMEquipment(const ListBrlyORMConnectionMEquipment& src);
	~ListBrlyORMConnectionMEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyORMConnectionMEquipment* rec);

	BrlyORMConnectionMEquipment* operator[](const uint ix);
	ListBrlyORMConnectionMEquipment& operator=(const ListBrlyORMConnectionMEquipment& src);
	bool operator==(const ListBrlyORMConnectionMEquipment& comp);
	bool operator!=(const ListBrlyORMConnectionMEquipment& comp);

public:
	vector<BrlyORMConnectionMEquipment*> nodes;
};

/**
  * TblBrlyORMConnectionMEquipment: C++ wrapper for table TblBrlyORMConnectionMEquipment
  */
class TblBrlyORMConnectionMEquipment {

public:

public:
	TblBrlyORMConnectionMEquipment();
	virtual ~TblBrlyORMConnectionMEquipment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyORMConnectionMEquipment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyORMConnectionMEquipment& rst);

	virtual void insertRec(BrlyORMConnectionMEquipment* rec);
	ubigint insertNewRec(BrlyORMConnectionMEquipment** rec = NULL, const ubigint refBrlyMConnection = 0, const uint x1Start = 0, const uint ixBrlyVOolop = 0, const ubigint pr1RefLR = 0, const ubigint pr2RefLR = 0);
	ubigint appendNewRecToRst(ListBrlyORMConnectionMEquipment& rst, BrlyORMConnectionMEquipment** rec = NULL, const ubigint refBrlyMConnection = 0, const uint x1Start = 0, const uint ixBrlyVOolop = 0, const ubigint pr1RefLR = 0, const ubigint pr2RefLR = 0);
	virtual void insertRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	virtual void updateRec(BrlyORMConnectionMEquipment* rec);
	virtual void updateRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyORMConnectionMEquipment** rec);
	virtual bool loadRecByP1lP2lLop(ubigint pr1RefLR, ubigint pr2RefLR, uint ixBrlyVOolop, BrlyORMConnectionMEquipment** rec);
	virtual ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyORMConnectionMEquipment& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyORMConnectionMEquipment& rst);
};

/**
  * MyBrlyORMConnectionMEquipment: C++ wrapper for table TblBrlyORMConnectionMEquipment (MySQL database)
  */
class MyTblBrlyORMConnectionMEquipment : public TblBrlyORMConnectionMEquipment, public MyTable {

public:
	MyTblBrlyORMConnectionMEquipment();
	~MyTblBrlyORMConnectionMEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyORMConnectionMEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyORMConnectionMEquipment& rst);

	void insertRec(BrlyORMConnectionMEquipment* rec);
	void insertRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	void updateRec(BrlyORMConnectionMEquipment* rec);
	void updateRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyORMConnectionMEquipment** rec);
	bool loadRecByP1lP2lLop(ubigint pr1RefLR, ubigint pr2RefLR, uint ixBrlyVOolop, BrlyORMConnectionMEquipment** rec);
	ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyORMConnectionMEquipment& rst);
};

/**
  * PgBrlyORMConnectionMEquipment: C++ wrapper for table TblBrlyORMConnectionMEquipment (PgSQL database)
  */
class PgTblBrlyORMConnectionMEquipment : public TblBrlyORMConnectionMEquipment, public PgTable {

public:
	PgTblBrlyORMConnectionMEquipment();
	~PgTblBrlyORMConnectionMEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyORMConnectionMEquipment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyORMConnectionMEquipment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyORMConnectionMEquipment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyORMConnectionMEquipment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyORMConnectionMEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyORMConnectionMEquipment& rst);

	void insertRec(BrlyORMConnectionMEquipment* rec);
	void insertRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	void updateRec(BrlyORMConnectionMEquipment* rec);
	void updateRst(ListBrlyORMConnectionMEquipment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyORMConnectionMEquipment** rec);
	bool loadRecByP1lP2lLop(ubigint pr1RefLR, ubigint pr2RefLR, uint ixBrlyVOolop, BrlyORMConnectionMEquipment** rec);
	ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyORMConnectionMEquipment& rst);
};

#endif

