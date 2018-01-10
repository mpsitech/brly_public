/**
  * \file BrlyAVControlPar.h
  * database access for table TblBrlyAVControlPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYAVCONTROLPAR_H
#define BRLYAVCONTROLPAR_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyAVControlPar: record of TblBrlyAVControlPar
  */
class BrlyAVControlPar {

public:
	BrlyAVControlPar(const ubigint ref = 0, const uint ixBrlyVControl = 0, const ubigint x1RefBrlyMUser = 0, const uint x2IxBrlyVLocale = 0, const string Par = "", const string Val = "");

public:
	ubigint ref;
	uint ixBrlyVControl;
	ubigint x1RefBrlyMUser;
	uint x2IxBrlyVLocale;
	string Par;
	string Val;

public:
	bool operator==(const BrlyAVControlPar& comp);
	bool operator!=(const BrlyAVControlPar& comp);
};

/**
  * ListBrlyAVControlPar: recordset of TblBrlyAVControlPar
  */
class ListBrlyAVControlPar {

public:
	ListBrlyAVControlPar();
	ListBrlyAVControlPar(const ListBrlyAVControlPar& src);
	~ListBrlyAVControlPar();

	void clear();
	unsigned int size() const;
	void append(BrlyAVControlPar* rec);

	BrlyAVControlPar* operator[](const uint ix);
	ListBrlyAVControlPar& operator=(const ListBrlyAVControlPar& src);
	bool operator==(const ListBrlyAVControlPar& comp);
	bool operator!=(const ListBrlyAVControlPar& comp);

public:
	vector<BrlyAVControlPar*> nodes;
};

/**
  * TblBrlyAVControlPar: C++ wrapper for table TblBrlyAVControlPar
  */
class TblBrlyAVControlPar {

public:

public:
	TblBrlyAVControlPar();
	virtual ~TblBrlyAVControlPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyAVControlPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVControlPar& rst);

	virtual void insertRec(BrlyAVControlPar* rec);
	ubigint insertNewRec(BrlyAVControlPar** rec = NULL, const uint ixBrlyVControl = 0, const ubigint x1RefBrlyMUser = 0, const uint x2IxBrlyVLocale = 0, const string Par = "", const string Val = "");
	ubigint appendNewRecToRst(ListBrlyAVControlPar& rst, BrlyAVControlPar** rec = NULL, const uint ixBrlyVControl = 0, const ubigint x1RefBrlyMUser = 0, const uint x2IxBrlyVLocale = 0, const string Par = "", const string Val = "");
	virtual void insertRst(ListBrlyAVControlPar& rst, bool transact = false);
	virtual void updateRec(BrlyAVControlPar* rec);
	virtual void updateRst(ListBrlyAVControlPar& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyAVControlPar** rec);
	virtual bool loadRefByCtlUsrPar(uint ixBrlyVControl, ubigint x1RefBrlyMUser, string Par, ubigint& ref);
	virtual bool loadValByCtlUsrPar(uint ixBrlyVControl, ubigint x1RefBrlyMUser, string Par, string& Val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyAVControlPar& rst);
};

/**
  * MyBrlyAVControlPar: C++ wrapper for table TblBrlyAVControlPar (MySQL database)
  */
class MyTblBrlyAVControlPar : public TblBrlyAVControlPar, public MyTable {

public:
	MyTblBrlyAVControlPar();
	~MyTblBrlyAVControlPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAVControlPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVControlPar& rst);

	void insertRec(BrlyAVControlPar* rec);
	void insertRst(ListBrlyAVControlPar& rst, bool transact = false);
	void updateRec(BrlyAVControlPar* rec);
	void updateRst(ListBrlyAVControlPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAVControlPar** rec);
	bool loadRefByCtlUsrPar(uint ixBrlyVControl, ubigint x1RefBrlyMUser, string Par, ubigint& ref);
	bool loadValByCtlUsrPar(uint ixBrlyVControl, ubigint x1RefBrlyMUser, string Par, string& Val);
};

/**
  * PgBrlyAVControlPar: C++ wrapper for table TblBrlyAVControlPar (PgSQL database)
  */
class PgTblBrlyAVControlPar : public TblBrlyAVControlPar, public PgTable {

public:
	PgTblBrlyAVControlPar();
	~PgTblBrlyAVControlPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyAVControlPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyAVControlPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyAVControlPar** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyAVControlPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyAVControlPar& rst);

	void insertRec(BrlyAVControlPar* rec);
	void insertRst(ListBrlyAVControlPar& rst, bool transact = false);
	void updateRec(BrlyAVControlPar* rec);
	void updateRst(ListBrlyAVControlPar& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyAVControlPar** rec);
	bool loadRefByCtlUsrPar(uint ixBrlyVControl, ubigint x1RefBrlyMUser, string Par, ubigint& ref);
	bool loadValByCtlUsrPar(uint ixBrlyVControl, ubigint x1RefBrlyMUser, string Par, string& Val);
};

#endif

