/**
  * \file BrlyMRegion.h
  * database access for table TblBrlyMRegion (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMREGION_H
#define BRLYMREGION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMRegionDst TblBrlyMRegion::VecVDst
#define VecBrlyWMRegionSubset TblBrlyMRegion::VecWSubset

/**
  * BrlyMRegion: record of TblBrlyMRegion
  */
class BrlyMRegion {

public:
	BrlyMRegion(const ubigint ref = 0, const ubigint supRefBrlyMRegion = 0, const usmallint supLvl = 0, const string sref = "", const ubigint refJTitle = 0, const string Title = "", const ubigint refJ = 0, const uint ixVDst = 0, const double toffset = 0.0);

public:
	ubigint ref;
	ubigint supRefBrlyMRegion;
	usmallint supLvl;
	string sref;
	ubigint refJTitle;
	string Title;
	ubigint refJ;
	uint ixVDst;
	double toffset;

public:
	bool operator==(const BrlyMRegion& comp);
	bool operator!=(const BrlyMRegion& comp);
};

/**
  * ListBrlyMRegion: recordset of TblBrlyMRegion
  */
class ListBrlyMRegion {

public:
	ListBrlyMRegion();
	ListBrlyMRegion(const ListBrlyMRegion& src);
	~ListBrlyMRegion();

	void clear();
	unsigned int size() const;
	void append(BrlyMRegion* rec);

	BrlyMRegion* operator[](const uint ix);
	ListBrlyMRegion& operator=(const ListBrlyMRegion& src);
	bool operator==(const ListBrlyMRegion& comp);
	bool operator!=(const ListBrlyMRegion& comp);

public:
	vector<BrlyMRegion*> nodes;
};

/**
  * TblBrlyMRegion: C++ wrapper for table TblBrlyMRegion
  */
class TblBrlyMRegion {

public:
	/**
		* VecVDst (full: VecBrlyVMRegionDst)
		*/
	class VecVDst {

	public:
		static const uint NONE = 1;
		static const uint NDST = 2;
		static const uint SDST = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecWSubset (full: VecBrlyWMRegionSubset)
		*/
	class VecWSubset {

	public:
		static const uint SBSBRLYBMREGIONRIP = 1;

		static uint getIx(const string& srefs);
		static void getIcs(const uint ix, set<uint>& ics);
		static string getSrefs(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);
	};

public:
	TblBrlyMRegion();
	virtual ~TblBrlyMRegion();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMRegion** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMRegion& rst);

	virtual void insertRec(BrlyMRegion* rec);
	ubigint insertNewRec(BrlyMRegion** rec = NULL, const ubigint supRefBrlyMRegion = 0, const usmallint supLvl = 0, const string sref = "", const ubigint refJTitle = 0, const string Title = "", const ubigint refJ = 0, const uint ixVDst = 0, const double toffset = 0.0);
	ubigint appendNewRecToRst(ListBrlyMRegion& rst, BrlyMRegion** rec = NULL, const ubigint supRefBrlyMRegion = 0, const usmallint supLvl = 0, const string sref = "", const ubigint refJTitle = 0, const string Title = "", const ubigint refJ = 0, const uint ixVDst = 0, const double toffset = 0.0);
	virtual void insertRst(ListBrlyMRegion& rst, bool transact = false);
	virtual void updateRec(BrlyMRegion* rec);
	virtual void updateRst(ListBrlyMRegion& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMRegion** rec);
	virtual bool confirmByRef(ubigint ref);
	virtual bool loadRefBySupSrf(ubigint supRefBrlyMRegion, string sref, ubigint& ref);
	virtual ubigint loadRefsBySup(ubigint supRefBrlyMRegion, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstBySup(ubigint supRefBrlyMRegion, const bool append, ListBrlyMRegion& rst);
	virtual bool loadSupByRef(ubigint ref, ubigint& supRefBrlyMRegion);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMRegion& rst);
	ubigint loadHrefsup(ubigint ref, vector<ubigint>& refs);
	ubigint loadHrefsdown(ubigint ref, const bool append, vector<ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	ubigint loadHrstup(ubigint ref, ListBrlyMRegion& rst);
	ubigint loadHrstdown(ubigint ref, const bool append, ListBrlyMRegion& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

/**
  * MyBrlyMRegion: C++ wrapper for table TblBrlyMRegion (MySQL database)
  */
class MyTblBrlyMRegion : public TblBrlyMRegion, public MyTable {

public:
	MyTblBrlyMRegion();
	~MyTblBrlyMRegion();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMRegion** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMRegion& rst);

	void insertRec(BrlyMRegion* rec);
	void insertRst(ListBrlyMRegion& rst, bool transact = false);
	void updateRec(BrlyMRegion* rec);
	void updateRst(ListBrlyMRegion& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMRegion** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint supRefBrlyMRegion, string sref, ubigint& ref);
	ubigint loadRefsBySup(ubigint supRefBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefBrlyMRegion, const bool append, ListBrlyMRegion& rst);
	bool loadSupByRef(ubigint ref, ubigint& supRefBrlyMRegion);
};

/**
  * PgBrlyMRegion: C++ wrapper for table TblBrlyMRegion (PgSQL database)
  */
class PgTblBrlyMRegion : public TblBrlyMRegion, public PgTable {

public:
	PgTblBrlyMRegion();
	~PgTblBrlyMRegion();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMRegion** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMRegion& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMRegion** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMRegion& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMRegion** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMRegion& rst);

	void insertRec(BrlyMRegion* rec);
	void insertRst(ListBrlyMRegion& rst, bool transact = false);
	void updateRec(BrlyMRegion* rec);
	void updateRst(ListBrlyMRegion& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMRegion** rec);
	bool confirmByRef(ubigint ref);
	bool loadRefBySupSrf(ubigint supRefBrlyMRegion, string sref, ubigint& ref);
	ubigint loadRefsBySup(ubigint supRefBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRstBySup(ubigint supRefBrlyMRegion, const bool append, ListBrlyMRegion& rst);
	bool loadSupByRef(ubigint ref, ubigint& supRefBrlyMRegion);
};

#endif

