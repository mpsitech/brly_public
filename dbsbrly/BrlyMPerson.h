/**
  * \file BrlyMPerson.h
  * database access for table TblBrlyMPerson (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMPERSON_H
#define BRLYMPERSON_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMPersonSex TblBrlyMPerson::VecVSex
#define VecBrlyWMPersonDerivate TblBrlyMPerson::VecWDerivate

/**
  * BrlyMPerson: record of TblBrlyMPerson
  */
class BrlyMPerson {

public:
	BrlyMPerson(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string telVal = "", const ubigint emlRefADetail = 0, const string emlVal = "", const string Salutation = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint ixWDerivate;
	uint ixVSex;
	string Title;
	string Firstname;
	ubigint refJLastname;
	string Lastname;
	ubigint telRefADetail;
	string telVal;
	ubigint emlRefADetail;
	string emlVal;
	string Salutation;

public:
	bool operator==(const BrlyMPerson& comp);
	bool operator!=(const BrlyMPerson& comp);
};

/**
  * ListBrlyMPerson: recordset of TblBrlyMPerson
  */
class ListBrlyMPerson {

public:
	ListBrlyMPerson();
	ListBrlyMPerson(const ListBrlyMPerson& src);
	~ListBrlyMPerson();

	void clear();
	unsigned int size() const;
	void append(BrlyMPerson* rec);

	BrlyMPerson* operator[](const uint ix);
	ListBrlyMPerson& operator=(const ListBrlyMPerson& src);
	bool operator==(const ListBrlyMPerson& comp);
	bool operator!=(const ListBrlyMPerson& comp);

public:
	vector<BrlyMPerson*> nodes;
};

/**
  * TblBrlyMPerson: C++ wrapper for table TblBrlyMPerson
  */
class TblBrlyMPerson {

public:
	/**
		* VecVSex (full: VecBrlyVMPersonSex)
		*/
	class VecVSex {

	public:
		static const uint F = 1;
		static const uint M = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecWDerivate (full: VecBrlyWMPersonDerivate)
		*/
	class VecWDerivate {

	public:
		static const uint USR = 1;

		static uint getIx(const string& srefs);
		static void getIcs(const uint ix, set<uint>& ics);
		static string getSrefs(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

public:
	TblBrlyMPerson();
	virtual ~TblBrlyMPerson();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMPerson** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMPerson& rst);

	virtual void insertRec(BrlyMPerson* rec);
	ubigint insertNewRec(BrlyMPerson** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string telVal = "", const ubigint emlRefADetail = 0, const string emlVal = "", const string Salutation = "");
	ubigint appendNewRecToRst(ListBrlyMPerson& rst, BrlyMPerson** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixWDerivate = 0, const uint ixVSex = 0, const string Title = "", const string Firstname = "", const ubigint refJLastname = 0, const string Lastname = "", const ubigint telRefADetail = 0, const string telVal = "", const ubigint emlRefADetail = 0, const string emlVal = "", const string Salutation = "");
	virtual void insertRst(ListBrlyMPerson& rst, bool transact = false);
	virtual void updateRec(BrlyMPerson* rec);
	virtual void updateRst(ListBrlyMPerson& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMPerson** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMPerson& rst);
};

/**
  * MyBrlyMPerson: C++ wrapper for table TblBrlyMPerson (MySQL database)
  */
class MyTblBrlyMPerson : public TblBrlyMPerson, public MyTable {

public:
	MyTblBrlyMPerson();
	~MyTblBrlyMPerson();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMPerson& rst);

	void insertRec(BrlyMPerson* rec);
	void insertRst(ListBrlyMPerson& rst, bool transact = false);
	void updateRec(BrlyMPerson* rec);
	void updateRst(ListBrlyMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMPerson** rec);
};

/**
  * PgBrlyMPerson: C++ wrapper for table TblBrlyMPerson (PgSQL database)
  */
class PgTblBrlyMPerson : public TblBrlyMPerson, public PgTable {

public:
	PgTblBrlyMPerson();
	~PgTblBrlyMPerson();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMPerson** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMPerson& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMPerson** rec);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMPerson** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMPerson& rst);

	void insertRec(BrlyMPerson* rec);
	void insertRst(ListBrlyMPerson& rst, bool transact = false);
	void updateRec(BrlyMPerson* rec);
	void updateRst(ListBrlyMPerson& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMPerson** rec);
};

#endif

