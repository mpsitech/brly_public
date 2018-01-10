/**
  * \file BrlyMEquipment.h
  * database access for table TblBrlyMEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMEQUIPMENT_H
#define BRLYMEQUIPMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMEquipmentHkTbl TblBrlyMEquipment::VecVHkTbl
#define VecBrlyWMEquipmentSubset TblBrlyMEquipment::VecWSubset

/**
  * BrlyMEquipment: record of TblBrlyMEquipment
  */
class BrlyMEquipment {

public:
	BrlyMEquipment(const ubigint ref = 0, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const ubigint refBrlyMOperator = 0, const ubigint refBrlyMPlntype = 0, const string srefBrlyKEqptype = "", const bool Fiber = false);

public:
	ubigint ref;
	uint hkIxVTbl;
	ubigint hkUref;
	ubigint refBrlyMOperator;
	ubigint refBrlyMPlntype;
	string srefBrlyKEqptype;
	bool Fiber;

public:
	bool operator==(const BrlyMEquipment& comp);
	bool operator!=(const BrlyMEquipment& comp);
};

/**
  * ListBrlyMEquipment: recordset of TblBrlyMEquipment
  */
class ListBrlyMEquipment {

public:
	ListBrlyMEquipment();
	ListBrlyMEquipment(const ListBrlyMEquipment& src);
	~ListBrlyMEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyMEquipment* rec);

	BrlyMEquipment* operator[](const uint ix);
	ListBrlyMEquipment& operator=(const ListBrlyMEquipment& src);
	bool operator==(const ListBrlyMEquipment& comp);
	bool operator!=(const ListBrlyMEquipment& comp);

public:
	vector<BrlyMEquipment*> nodes;
};

/**
  * TblBrlyMEquipment: C++ wrapper for table TblBrlyMEquipment
  */
class TblBrlyMEquipment {

public:
	/**
		* VecVHkTbl (full: VecBrlyVMEquipmentHkTbl)
		*/
	class VecVHkTbl {

	public:
		static const uint FLT = 1;
		static const uint LOC = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecWSubset (full: VecBrlyWMEquipmentSubset)
		*/
	class VecWSubset {

	public:
		static const uint SBSBRLYBMEQUIPMENTPLN = 1;

		static uint getIx(const string& srefs);
		static void getIcs(const uint ix, set<uint>& ics);
		static string getSrefs(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);
	};

public:
	TblBrlyMEquipment();
	virtual ~TblBrlyMEquipment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMEquipment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMEquipment& rst);

	virtual void insertRec(BrlyMEquipment* rec);
	ubigint insertNewRec(BrlyMEquipment** rec = NULL, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const ubigint refBrlyMOperator = 0, const ubigint refBrlyMPlntype = 0, const string srefBrlyKEqptype = "", const bool Fiber = false);
	ubigint appendNewRecToRst(ListBrlyMEquipment& rst, BrlyMEquipment** rec = NULL, const uint hkIxVTbl = 0, const ubigint hkUref = 0, const ubigint refBrlyMOperator = 0, const ubigint refBrlyMPlntype = 0, const string srefBrlyKEqptype = "", const bool Fiber = false);
	virtual void insertRst(ListBrlyMEquipment& rst, bool transact = false);
	virtual void updateRec(BrlyMEquipment* rec);
	virtual void updateRst(ListBrlyMEquipment& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMEquipment** rec);
	virtual bool loadRecByHktHku(uint hkIxVTbl, ubigint hkUref, BrlyMEquipment** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMEquipment& rst);
};

/**
  * MyBrlyMEquipment: C++ wrapper for table TblBrlyMEquipment (MySQL database)
  */
class MyTblBrlyMEquipment : public TblBrlyMEquipment, public MyTable {

public:
	MyTblBrlyMEquipment();
	~MyTblBrlyMEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMEquipment& rst);

	void insertRec(BrlyMEquipment* rec);
	void insertRst(ListBrlyMEquipment& rst, bool transact = false);
	void updateRec(BrlyMEquipment* rec);
	void updateRst(ListBrlyMEquipment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMEquipment** rec);
	bool loadRecByHktHku(uint hkIxVTbl, ubigint hkUref, BrlyMEquipment** rec);
};

/**
  * PgBrlyMEquipment: C++ wrapper for table TblBrlyMEquipment (PgSQL database)
  */
class PgTblBrlyMEquipment : public TblBrlyMEquipment, public PgTable {

public:
	PgTblBrlyMEquipment();
	~PgTblBrlyMEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMEquipment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMEquipment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMEquipment** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMEquipment& rst);

	void insertRec(BrlyMEquipment* rec);
	void insertRst(ListBrlyMEquipment& rst, bool transact = false);
	void updateRec(BrlyMEquipment* rec);
	void updateRst(ListBrlyMEquipment& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMEquipment** rec);
	bool loadRecByHktHku(uint hkIxVTbl, ubigint hkUref, BrlyMEquipment** rec);
};

#endif

