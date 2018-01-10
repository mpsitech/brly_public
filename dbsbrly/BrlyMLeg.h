/**
  * \file BrlyMLeg.h
  * database access for table TblBrlyMLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMLEG_H
#define BRLYMLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMLegBasetype TblBrlyMLeg::VecVBasetype
#define VecBrlyWMLegSubset TblBrlyMLeg::VecWSubset

/**
  * BrlyMLeg: record of TblBrlyMLeg
  */
class BrlyMLeg {

public:
	BrlyMLeg(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const ubigint refBrlyCLeg = 0, const ubigint bgnRefBrlyMLocation = 0, const ubigint endRefBrlyMLocation = 0, const double alt = 0.0, const double deltaphi = 0.0, const double alpha = 0.0, const double xAlt = 0.0, const double xPhi0 = 0.0, const double xPhi1 = 0.0, const double xAlpha = 0.0, const bool Calcdone = false);

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	uint ixVBasetype;
	ubigint refBrlyCLeg;
	ubigint bgnRefBrlyMLocation;
	ubigint endRefBrlyMLocation;
	double alt;
	double deltaphi;
	double alpha;
	double xAlt;
	double xPhi0;
	double xPhi1;
	double xAlpha;
	bool Calcdone;

public:
	bool operator==(const BrlyMLeg& comp);
	bool operator!=(const BrlyMLeg& comp);
};

/**
  * ListBrlyMLeg: recordset of TblBrlyMLeg
  */
class ListBrlyMLeg {

public:
	ListBrlyMLeg();
	ListBrlyMLeg(const ListBrlyMLeg& src);
	~ListBrlyMLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyMLeg* rec);

	BrlyMLeg* operator[](const uint ix);
	ListBrlyMLeg& operator=(const ListBrlyMLeg& src);
	bool operator==(const ListBrlyMLeg& comp);
	bool operator!=(const ListBrlyMLeg& comp);

public:
	vector<BrlyMLeg*> nodes;
};

/**
  * TblBrlyMLeg: C++ wrapper for table TblBrlyMLeg
  */
class TblBrlyMLeg {

public:
	/**
		* VecVBasetype (full: VecBrlyVMLegBasetype)
		*/
	class VecVBasetype {

	public:
		static const uint CORR = 1;
		static const uint RTE = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecWSubset (full: VecBrlyWMLegSubset)
		*/
	class VecWSubset {

	public:
		static const uint SBSBRLYBMLEGCOR = 1;
		static const uint SBSBRLYBMLEGRTE = 2;

		static uint getIx(const string& srefs);
		static void getIcs(const uint ix, set<uint>& ics);
		static string getSrefs(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);
	};

public:
	TblBrlyMLeg();
	virtual ~TblBrlyMLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMLeg& rst);

	virtual void insertRec(BrlyMLeg* rec);
	ubigint insertNewRec(BrlyMLeg** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const ubigint refBrlyCLeg = 0, const ubigint bgnRefBrlyMLocation = 0, const ubigint endRefBrlyMLocation = 0, const double alt = 0.0, const double deltaphi = 0.0, const double alpha = 0.0, const double xAlt = 0.0, const double xPhi0 = 0.0, const double xPhi1 = 0.0, const double xAlpha = 0.0, const bool Calcdone = false);
	ubigint appendNewRecToRst(ListBrlyMLeg& rst, BrlyMLeg** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const uint ixVBasetype = 0, const ubigint refBrlyCLeg = 0, const ubigint bgnRefBrlyMLocation = 0, const ubigint endRefBrlyMLocation = 0, const double alt = 0.0, const double deltaphi = 0.0, const double alpha = 0.0, const double xAlt = 0.0, const double xPhi0 = 0.0, const double xPhi1 = 0.0, const double xAlpha = 0.0, const bool Calcdone = false);
	virtual void insertRst(ListBrlyMLeg& rst, bool transact = false);
	virtual void updateRec(BrlyMLeg* rec);
	virtual void updateRst(ListBrlyMLeg& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMLeg** rec);
	virtual bool loadRefByTypBloElo(uint ixVBasetype, ubigint bgnRefBrlyMLocation, ubigint endRefBrlyMLocation, ubigint& ref);
	virtual ubigint loadRefsByBlo(ubigint bgnRefBrlyMLocation, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRefsByClu(ubigint refBrlyCLeg, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRefsByElo(ubigint endRefBrlyMLocation, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRst(const bool append, ListBrlyMLeg& rst, ubigint limit = 0, ubigint offset = 0);
	virtual ubigint loadRstByBlo(ubigint bgnRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	virtual ubigint loadRstByClu(ubigint refBrlyCLeg, const bool append, ListBrlyMLeg& rst);
	virtual ubigint loadRstByElo(ubigint endRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	virtual ubigint loadRstByTyp(uint ixVBasetype, const bool append, ListBrlyMLeg& rst, ubigint limit = 0, ubigint offset = 0);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMLeg& rst);
};

/**
  * MyBrlyMLeg: C++ wrapper for table TblBrlyMLeg (MySQL database)
  */
class MyTblBrlyMLeg : public TblBrlyMLeg, public MyTable {

public:
	MyTblBrlyMLeg();
	~MyTblBrlyMLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMLeg& rst);

	void insertRec(BrlyMLeg* rec);
	void insertRst(ListBrlyMLeg& rst, bool transact = false);
	void updateRec(BrlyMLeg* rec);
	void updateRst(ListBrlyMLeg& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMLeg** rec);
	bool loadRefByTypBloElo(uint ixVBasetype, ubigint bgnRefBrlyMLocation, ubigint endRefBrlyMLocation, ubigint& ref);
	ubigint loadRefsByBlo(ubigint bgnRefBrlyMLocation, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByClu(ubigint refBrlyCLeg, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByElo(ubigint endRefBrlyMLocation, const bool append, vector<ubigint>& refs);
	ubigint loadRst(const bool append, ListBrlyMLeg& rst, ubigint limit = 0, ubigint offset = 0);
	ubigint loadRstByBlo(ubigint bgnRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	ubigint loadRstByClu(ubigint refBrlyCLeg, const bool append, ListBrlyMLeg& rst);
	ubigint loadRstByElo(ubigint endRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	ubigint loadRstByTyp(uint ixVBasetype, const bool append, ListBrlyMLeg& rst, ubigint limit = 0, ubigint offset = 0);
};

/**
  * PgBrlyMLeg: C++ wrapper for table TblBrlyMLeg (PgSQL database)
  */
class PgTblBrlyMLeg : public TblBrlyMLeg, public PgTable {

public:
	PgTblBrlyMLeg();
	~PgTblBrlyMLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMLeg& rst);

	void insertRec(BrlyMLeg* rec);
	void insertRst(ListBrlyMLeg& rst, bool transact = false);
	void updateRec(BrlyMLeg* rec);
	void updateRst(ListBrlyMLeg& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMLeg** rec);
	bool loadRefByTypBloElo(uint ixVBasetype, ubigint bgnRefBrlyMLocation, ubigint endRefBrlyMLocation, ubigint& ref);
	ubigint loadRefsByBlo(ubigint bgnRefBrlyMLocation, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByClu(ubigint refBrlyCLeg, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByElo(ubigint endRefBrlyMLocation, const bool append, vector<ubigint>& refs);
	ubigint loadRst(const bool append, ListBrlyMLeg& rst, ubigint limit = 0, ubigint offset = 0);
	ubigint loadRstByBlo(ubigint bgnRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	ubigint loadRstByClu(ubigint refBrlyCLeg, const bool append, ListBrlyMLeg& rst);
	ubigint loadRstByElo(ubigint endRefBrlyMLocation, const bool append, ListBrlyMLeg& rst);
	ubigint loadRstByTyp(uint ixVBasetype, const bool append, ListBrlyMLeg& rst, ubigint limit = 0, ubigint offset = 0);
};

#endif

