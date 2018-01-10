/**
  * \file BrlyMLocation.h
  * database access for table TblBrlyMLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMLOCATION_H
#define BRLYMLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMLocationBasetype TblBrlyMLocation::VecVBasetype
#define VecBrlyWMLocationSubset TblBrlyMLocation::VecWSubset

/**
  * BrlyMLocation: record of TblBrlyMLocation
  */
class BrlyMLocation {

public:
	BrlyMLocation(const ubigint ref = 0, const uint ixVBasetype = 0, const ubigint refBrlyMRegion = 0, const ubigint refBrlyMEquipment = 0, const string sref = "", const string srefICAO = "", const string Title = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0, const string tz = "", const double alpha = 0.0, const bool Calcdone = false);

public:
	ubigint ref;
	uint ixVBasetype;
	ubigint refBrlyMRegion;
	ubigint refBrlyMEquipment;
	string sref;
	string srefICAO;
	string Title;
	double alt;
	double theta;
	double phi;
	string tz;
	double alpha;
	bool Calcdone;

public:
	bool operator==(const BrlyMLocation& comp);
	bool operator!=(const BrlyMLocation& comp);
};

/**
  * ListBrlyMLocation: recordset of TblBrlyMLocation
  */
class ListBrlyMLocation {

public:
	ListBrlyMLocation();
	ListBrlyMLocation(const ListBrlyMLocation& src);
	~ListBrlyMLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyMLocation* rec);

	BrlyMLocation* operator[](const uint ix);
	ListBrlyMLocation& operator=(const ListBrlyMLocation& src);
	bool operator==(const ListBrlyMLocation& comp);
	bool operator!=(const ListBrlyMLocation& comp);

public:
	vector<BrlyMLocation*> nodes;
};

/**
  * TblBrlyMLocation: C++ wrapper for table TblBrlyMLocation
  */
class TblBrlyMLocation {

public:
	/**
		* VecVBasetype (full: VecBrlyVMLocationBasetype)
		*/
	class VecVBasetype {

	public:
		static const uint APT = 1;
		static const uint GND = 2;
		static const uint ELV = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

	/**
		* VecWSubset (full: VecBrlyWMLocationSubset)
		*/
	class VecWSubset {

	public:
		static const uint SBSBRLYBMLOCATIONAPT = 1;

		static uint getIx(const string& srefs);
		static void getIcs(const uint ix, set<uint>& ics);
		static string getSrefs(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);
	};

public:
	TblBrlyMLocation();
	virtual ~TblBrlyMLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMLocation& rst);

	virtual void insertRec(BrlyMLocation* rec);
	ubigint insertNewRec(BrlyMLocation** rec = NULL, const uint ixVBasetype = 0, const ubigint refBrlyMRegion = 0, const ubigint refBrlyMEquipment = 0, const string sref = "", const string srefICAO = "", const string Title = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0, const string tz = "", const double alpha = 0.0, const bool Calcdone = false);
	ubigint appendNewRecToRst(ListBrlyMLocation& rst, BrlyMLocation** rec = NULL, const uint ixVBasetype = 0, const ubigint refBrlyMRegion = 0, const ubigint refBrlyMEquipment = 0, const string sref = "", const string srefICAO = "", const string Title = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0, const string tz = "", const double alpha = 0.0, const bool Calcdone = false);
	virtual void insertRst(ListBrlyMLocation& rst, bool transact = false);
	virtual void updateRec(BrlyMLocation* rec);
	virtual void updateRst(ListBrlyMLocation& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMLocation** rec);
	virtual bool loadRecByEqp(ubigint refBrlyMEquipment, BrlyMLocation** rec);
	virtual bool loadRecBySrf(string sref, BrlyMLocation** rec);
	virtual bool loadRefBySrf(string sref, ubigint& ref);
	virtual ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRst(const bool append, ListBrlyMLocation& rst, ubigint limit = 0, ubigint offset = 0);
	virtual ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyMLocation& rst);
	virtual ubigint loadRstByTyp(uint ixVBasetype, const bool append, ListBrlyMLocation& rst, ubigint limit = 0, ubigint offset = 0);
	virtual bool loadSrfByRef(ubigint ref, string& sref);
	virtual bool loadTitByRef(ubigint ref, string& Title);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMLocation& rst);
};

/**
  * MyBrlyMLocation: C++ wrapper for table TblBrlyMLocation (MySQL database)
  */
class MyTblBrlyMLocation : public TblBrlyMLocation, public MyTable {

public:
	MyTblBrlyMLocation();
	~MyTblBrlyMLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMLocation& rst);

	void insertRec(BrlyMLocation* rec);
	void insertRst(ListBrlyMLocation& rst, bool transact = false);
	void updateRec(BrlyMLocation* rec);
	void updateRst(ListBrlyMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMLocation** rec);
	bool loadRecByEqp(ubigint refBrlyMEquipment, BrlyMLocation** rec);
	bool loadRecBySrf(string sref, BrlyMLocation** rec);
	bool loadRefBySrf(string sref, ubigint& ref);
	ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRst(const bool append, ListBrlyMLocation& rst, ubigint limit = 0, ubigint offset = 0);
	ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyMLocation& rst);
	ubigint loadRstByTyp(uint ixVBasetype, const bool append, ListBrlyMLocation& rst, ubigint limit = 0, ubigint offset = 0);
	bool loadSrfByRef(ubigint ref, string& sref);
	bool loadTitByRef(ubigint ref, string& Title);
};

/**
  * PgBrlyMLocation: C++ wrapper for table TblBrlyMLocation (PgSQL database)
  */
class PgTblBrlyMLocation : public TblBrlyMLocation, public PgTable {

public:
	PgTblBrlyMLocation();
	~PgTblBrlyMLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMLocation& rst);

	void insertRec(BrlyMLocation* rec);
	void insertRst(ListBrlyMLocation& rst, bool transact = false);
	void updateRec(BrlyMLocation* rec);
	void updateRst(ListBrlyMLocation& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMLocation** rec);
	bool loadRecByEqp(ubigint refBrlyMEquipment, BrlyMLocation** rec);
	bool loadRecBySrf(string sref, BrlyMLocation** rec);
	bool loadRefBySrf(string sref, ubigint& ref);
	ubigint loadRefsByReg(ubigint refBrlyMRegion, const bool append, vector<ubigint>& refs);
	ubigint loadRst(const bool append, ListBrlyMLocation& rst, ubigint limit = 0, ubigint offset = 0);
	ubigint loadRstByReg(ubigint refBrlyMRegion, const bool append, ListBrlyMLocation& rst);
	ubigint loadRstByTyp(uint ixVBasetype, const bool append, ListBrlyMLocation& rst, ubigint limit = 0, ubigint offset = 0);
	bool loadSrfByRef(ubigint ref, string& sref);
	bool loadTitByRef(ubigint ref, string& Title);
};

#endif

