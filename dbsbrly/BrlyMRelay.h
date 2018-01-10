/**
  * \file BrlyMRelay.h
  * database access for table TblBrlyMRelay (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMRELAY_H
#define BRLYMRELAY_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMRelayDir TblBrlyMRelay::VecVDir

/**
  * BrlyMRelay: record of TblBrlyMRelay
  */
class BrlyMRelay {

public:
	BrlyMRelay(const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const ubigint refBrlyMConnection = 0, const uint ixVDir = 0, const bool Connected = false, const usmallint Nhop = 0);

public:
	ubigint ref;
	uint x1Start;
	uint x1Stop;
	ubigint refBrlyMConnection;
	uint ixVDir;
	bool Connected;
	usmallint Nhop;

public:
	bool operator==(const BrlyMRelay& comp);
	bool operator!=(const BrlyMRelay& comp);
};

/**
  * ListBrlyMRelay: recordset of TblBrlyMRelay
  */
class ListBrlyMRelay {

public:
	ListBrlyMRelay();
	ListBrlyMRelay(const ListBrlyMRelay& src);
	~ListBrlyMRelay();

	void clear();
	unsigned int size() const;
	void append(BrlyMRelay* rec);

	BrlyMRelay* operator[](const uint ix);
	ListBrlyMRelay& operator=(const ListBrlyMRelay& src);
	bool operator==(const ListBrlyMRelay& comp);
	bool operator!=(const ListBrlyMRelay& comp);

public:
	vector<BrlyMRelay*> nodes;
};

/**
  * TblBrlyMRelay: C++ wrapper for table TblBrlyMRelay
  */
class TblBrlyMRelay {

public:
	/**
		* VecVDir (full: VecBrlyVMRelayDir)
		*/
	class VecVDir {

	public:
		static const uint BWD = 1;
		static const uint FWD = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

public:
	TblBrlyMRelay();
	virtual ~TblBrlyMRelay();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMRelay** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMRelay& rst);

	virtual void insertRec(BrlyMRelay* rec);
	ubigint insertNewRec(BrlyMRelay** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const ubigint refBrlyMConnection = 0, const uint ixVDir = 0, const bool Connected = false, const usmallint Nhop = 0);
	ubigint appendNewRecToRst(ListBrlyMRelay& rst, BrlyMRelay** rec = NULL, const uint x1Start = 0, const uint x1Stop = 0, const ubigint refBrlyMConnection = 0, const uint ixVDir = 0, const bool Connected = false, const usmallint Nhop = 0);
	virtual void insertRst(ListBrlyMRelay& rst, bool transact = false);
	virtual void updateRec(BrlyMRelay* rec);
	virtual void updateRst(ListBrlyMRelay& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMRelay** rec);
	virtual ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyMRelay& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMRelay& rst);
};

/**
  * MyBrlyMRelay: C++ wrapper for table TblBrlyMRelay (MySQL database)
  */
class MyTblBrlyMRelay : public TblBrlyMRelay, public MyTable {

public:
	MyTblBrlyMRelay();
	~MyTblBrlyMRelay();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMRelay** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMRelay& rst);

	void insertRec(BrlyMRelay* rec);
	void insertRst(ListBrlyMRelay& rst, bool transact = false);
	void updateRec(BrlyMRelay* rec);
	void updateRst(ListBrlyMRelay& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMRelay** rec);
	ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyMRelay& rst);
};

/**
  * PgBrlyMRelay: C++ wrapper for table TblBrlyMRelay (PgSQL database)
  */
class PgTblBrlyMRelay : public TblBrlyMRelay, public PgTable {

public:
	PgTblBrlyMRelay();
	~PgTblBrlyMRelay();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMRelay** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMRelay& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMRelay** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMRelay& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMRelay** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMRelay& rst);

	void insertRec(BrlyMRelay* rec);
	void insertRst(ListBrlyMRelay& rst, bool transact = false);
	void updateRec(BrlyMRelay* rec);
	void updateRst(ListBrlyMRelay& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMRelay** rec);
	ubigint loadRstByCon(ubigint refBrlyMConnection, const bool append, ListBrlyMRelay& rst);
};

#endif

