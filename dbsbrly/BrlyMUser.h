/**
  * \file BrlyMUser.h
  * database access for table TblBrlyMUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMUSER_H
#define BRLYMUSER_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMUserState TblBrlyMUser::VecVState

/**
  * BrlyMUser: record of TblBrlyMUser
  */
class BrlyMUser {

public:
	BrlyMUser(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refBrlyMUsergroup = 0, const ubigint refBrlyMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixBrlyVLocale = 0, const uint ixBrlyVUserlevel = 0, const string Password = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refRUsergroup;
	ubigint refBrlyMUsergroup;
	ubigint refBrlyMPerson;
	string sref;
	ubigint refJState;
	uint ixVState;
	uint ixBrlyVLocale;
	uint ixBrlyVUserlevel;
	string Password;

public:
	bool operator==(const BrlyMUser& comp);
	bool operator!=(const BrlyMUser& comp);
};

/**
  * ListBrlyMUser: recordset of TblBrlyMUser
  */
class ListBrlyMUser {

public:
	ListBrlyMUser();
	ListBrlyMUser(const ListBrlyMUser& src);
	~ListBrlyMUser();

	void clear();
	unsigned int size() const;
	void append(BrlyMUser* rec);

	BrlyMUser* operator[](const uint ix);
	ListBrlyMUser& operator=(const ListBrlyMUser& src);
	bool operator==(const ListBrlyMUser& comp);
	bool operator!=(const ListBrlyMUser& comp);

public:
	vector<BrlyMUser*> nodes;
};

/**
  * TblBrlyMUser: C++ wrapper for table TblBrlyMUser
  */
class TblBrlyMUser {

public:
	/**
		* VecVState (full: VecBrlyVMUserState)
		*/
	class VecVState {

	public:
		static const uint ACT = 1;
		static const uint DSG = 2;
		static const uint DUE = 3;
		static const uint EXP = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

public:
	TblBrlyMUser();
	virtual ~TblBrlyMUser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMUser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMUser& rst);

	virtual void insertRec(BrlyMUser* rec);
	ubigint insertNewRec(BrlyMUser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refBrlyMUsergroup = 0, const ubigint refBrlyMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixBrlyVLocale = 0, const uint ixBrlyVUserlevel = 0, const string Password = "");
	ubigint appendNewRecToRst(ListBrlyMUser& rst, BrlyMUser** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refRUsergroup = 0, const ubigint refBrlyMUsergroup = 0, const ubigint refBrlyMPerson = 0, const string sref = "", const ubigint refJState = 0, const uint ixVState = 0, const uint ixBrlyVLocale = 0, const uint ixBrlyVUserlevel = 0, const string Password = "");
	virtual void insertRst(ListBrlyMUser& rst, bool transact = false);
	virtual void updateRec(BrlyMUser* rec);
	virtual void updateRst(ListBrlyMUser& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMUser** rec);
	virtual bool loadRecByPrs(ubigint refBrlyMPerson, BrlyMUser** rec);
	virtual bool loadRecBySrf(string sref, BrlyMUser** rec);
	virtual bool loadRefByPrs(ubigint refBrlyMPerson, ubigint& ref);
	virtual bool loadRefBySrf(string sref, ubigint& ref);
	virtual bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	virtual ubigint loadRefsByUsg(ubigint refBrlyMUsergroup, const bool append, vector<ubigint>& refs);
	virtual bool loadSrfByRef(ubigint ref, string& sref);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMUser& rst);
};

/**
  * MyBrlyMUser: C++ wrapper for table TblBrlyMUser (MySQL database)
  */
class MyTblBrlyMUser : public TblBrlyMUser, public MyTable {

public:
	MyTblBrlyMUser();
	~MyTblBrlyMUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMUser& rst);

	void insertRec(BrlyMUser* rec);
	void insertRst(ListBrlyMUser& rst, bool transact = false);
	void updateRec(BrlyMUser* rec);
	void updateRst(ListBrlyMUser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMUser** rec);
	bool loadRecByPrs(ubigint refBrlyMPerson, BrlyMUser** rec);
	bool loadRecBySrf(string sref, BrlyMUser** rec);
	bool loadRefByPrs(ubigint refBrlyMPerson, ubigint& ref);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	ubigint loadRefsByUsg(ubigint refBrlyMUsergroup, const bool append, vector<ubigint>& refs);
	bool loadSrfByRef(ubigint ref, string& sref);
};

/**
  * PgBrlyMUser: C++ wrapper for table TblBrlyMUser (PgSQL database)
  */
class PgTblBrlyMUser : public TblBrlyMUser, public PgTable {

public:
	PgTblBrlyMUser();
	~PgTblBrlyMUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMUser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMUser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMUser** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMUser& rst);

	void insertRec(BrlyMUser* rec);
	void insertRst(ListBrlyMUser& rst, bool transact = false);
	void updateRec(BrlyMUser* rec);
	void updateRst(ListBrlyMUser& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMUser** rec);
	bool loadRecByPrs(ubigint refBrlyMPerson, BrlyMUser** rec);
	bool loadRecBySrf(string sref, BrlyMUser** rec);
	bool loadRefByPrs(ubigint refBrlyMPerson, ubigint& ref);
	bool loadRefBySrf(string sref, ubigint& ref);
	bool loadRefBySrfPwd(string sref, string Password, ubigint& ref);
	ubigint loadRefsByUsg(ubigint refBrlyMUsergroup, const bool append, vector<ubigint>& refs);
	bool loadSrfByRef(ubigint ref, string& sref);
};

#endif

