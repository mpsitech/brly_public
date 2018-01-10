/**
  * \file BrlyMConnection.h
  * database access for table TblBrlyMConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMCONNECTION_H
#define BRLYMCONNECTION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMConnectionModel TblBrlyMConnection::VecVModel

/**
  * BrlyMConnection: record of TblBrlyMConnection
  */
class BrlyMConnection {

public:
	BrlyMConnection(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refBrlyMFlight = 0, const ubigint corRefBrlyMLeg = 0, const uint start = 0, const uint stop = 0, const uint ixVModel = 0, const ubigint refBrlyMTimetable = 0, const string srefsBrlyKEqptype = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refBrlyMFlight;
	ubigint corRefBrlyMLeg;
	uint start;
	uint stop;
	uint ixVModel;
	ubigint refBrlyMTimetable;
	string srefsBrlyKEqptype;

public:
	bool operator==(const BrlyMConnection& comp);
	bool operator!=(const BrlyMConnection& comp);
};

/**
  * ListBrlyMConnection: recordset of TblBrlyMConnection
  */
class ListBrlyMConnection {

public:
	ListBrlyMConnection();
	ListBrlyMConnection(const ListBrlyMConnection& src);
	~ListBrlyMConnection();

	void clear();
	unsigned int size() const;
	void append(BrlyMConnection* rec);

	BrlyMConnection* operator[](const uint ix);
	ListBrlyMConnection& operator=(const ListBrlyMConnection& src);
	bool operator==(const ListBrlyMConnection& comp);
	bool operator!=(const ListBrlyMConnection& comp);

public:
	vector<BrlyMConnection*> nodes;
};

/**
  * TblBrlyMConnection: C++ wrapper for table TblBrlyMConnection
  */
class TblBrlyMConnection {

public:
	/**
		* VecVModel (full: VecBrlyVMConnectionModel)
		*/
	class VecVModel {

	public:
		static const uint SPL = 1;
		static const uint EXT = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

public:
	TblBrlyMConnection();
	virtual ~TblBrlyMConnection();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMConnection** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMConnection& rst);

	virtual void insertRec(BrlyMConnection* rec);
	ubigint insertNewRec(BrlyMConnection** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refBrlyMFlight = 0, const ubigint corRefBrlyMLeg = 0, const uint start = 0, const uint stop = 0, const uint ixVModel = 0, const ubigint refBrlyMTimetable = 0, const string srefsBrlyKEqptype = "");
	ubigint appendNewRecToRst(ListBrlyMConnection& rst, BrlyMConnection** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refBrlyMFlight = 0, const ubigint corRefBrlyMLeg = 0, const uint start = 0, const uint stop = 0, const uint ixVModel = 0, const ubigint refBrlyMTimetable = 0, const string srefsBrlyKEqptype = "");
	virtual void insertRst(ListBrlyMConnection& rst, bool transact = false);
	virtual void updateRec(BrlyMConnection* rec);
	virtual void updateRst(ListBrlyMConnection& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMConnection** rec);
	virtual ubigint loadRefsByLeg(const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByLeg(const bool append, ListBrlyMConnection& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMConnection& rst);
};

/**
  * MyBrlyMConnection: C++ wrapper for table TblBrlyMConnection (MySQL database)
  */
class MyTblBrlyMConnection : public TblBrlyMConnection, public MyTable {

public:
	MyTblBrlyMConnection();
	~MyTblBrlyMConnection();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMConnection& rst);

	void insertRec(BrlyMConnection* rec);
	void insertRst(ListBrlyMConnection& rst, bool transact = false);
	void updateRec(BrlyMConnection* rec);
	void updateRst(ListBrlyMConnection& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMConnection** rec);
	ubigint loadRefsByLeg(const bool append, vector<ubigint>& refs);
	ubigint loadRstByLeg(const bool append, ListBrlyMConnection& rst);
};

/**
  * PgBrlyMConnection: C++ wrapper for table TblBrlyMConnection (PgSQL database)
  */
class PgTblBrlyMConnection : public TblBrlyMConnection, public PgTable {

public:
	PgTblBrlyMConnection();
	~PgTblBrlyMConnection();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMConnection** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMConnection& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMConnection** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMConnection& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMConnection** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMConnection& rst);

	void insertRec(BrlyMConnection* rec);
	void insertRst(ListBrlyMConnection& rst, bool transact = false);
	void updateRec(BrlyMConnection* rec);
	void updateRst(ListBrlyMConnection& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMConnection** rec);
	ubigint loadRefsByLeg(const bool append, vector<ubigint>& refs);
	ubigint loadRstByLeg(const bool append, ListBrlyMConnection& rst);
};

#endif

