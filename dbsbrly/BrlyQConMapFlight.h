/**
  * \file BrlyQConMapFlight.h
  * Dbs and XML wrapper for table TblBrlyQConMapFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPFLIGHT_H
#define BRLYQCONMAPFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapFlight: record of TblBrlyQConMapFlight
  */
class BrlyQConMapFlight {

public:
	BrlyQConMapFlight(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mrefBrlyMEquipment = 0, const ubigint mrefBrlyMLeg = 0, const uint mstart = 0, const uint mstop = 0, const double x0 = 0.0, const double y0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const int dt = 0);

public:
	ubigint qref;
	bool qwr;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint x1Start;
	uint x1Stop;
	double x2Legphi0;
	double x2Legphi1;
	ubigint mref;
	string stubMref;
	ubigint mrefBrlyMEquipment;
	ubigint mrefBrlyMLeg;
	uint mstart;
	uint mstop;
	double x0;
	double y0;
	int t0;
	double dx;
	double dy;
	int dt;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConMapFlight: recordset of TblBrlyQConMapFlight
  */
class ListBrlyQConMapFlight {

public:
	ListBrlyQConMapFlight();
	ListBrlyQConMapFlight(const ListBrlyQConMapFlight& src);
	~ListBrlyQConMapFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapFlight* rec);

	ListBrlyQConMapFlight& operator=(const ListBrlyQConMapFlight& src);

public:
	vector<BrlyQConMapFlight*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConMapFlight: C++ wrapper for table TblBrlyQConMapFlight
  */
class TblBrlyQConMapFlight {

public:
	TblBrlyQConMapFlight();
	virtual ~TblBrlyQConMapFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConMapFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapFlight& rst);

	virtual void insertRec(BrlyQConMapFlight* rec);
	ubigint insertNewRec(BrlyQConMapFlight** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mrefBrlyMEquipment = 0, const ubigint mrefBrlyMLeg = 0, const uint mstart = 0, const uint mstop = 0, const double x0 = 0.0, const double y0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const int dt = 0);
	ubigint appendNewRecToRst(ListBrlyQConMapFlight& rst, BrlyQConMapFlight** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1Start = 0, const uint x1Stop = 0, const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mrefBrlyMEquipment = 0, const ubigint mrefBrlyMLeg = 0, const uint mstart = 0, const uint mstop = 0, const double x0 = 0.0, const double y0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const int dt = 0);
	virtual void insertRst(ListBrlyQConMapFlight& rst);
	virtual void updateRec(BrlyQConMapFlight* rec);
	virtual void updateRst(ListBrlyQConMapFlight& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConMapFlight** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapFlight& rst);
};

/**
  * MyBrlyQConMapFlight: C++ wrapper for table TblBrlyQConMapFlight (MySQL database)
  */
class MyTblBrlyQConMapFlight : public TblBrlyQConMapFlight, public MyTable {

public:
	MyTblBrlyQConMapFlight();
	~MyTblBrlyQConMapFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapFlight& rst);

	void insertRec(BrlyQConMapFlight* rec);
	void insertRst(ListBrlyQConMapFlight& rst);
	void updateRec(BrlyQConMapFlight* rec);
	void updateRst(ListBrlyQConMapFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapFlight& rst);
};

/**
  * PgBrlyQConMapFlight: C++ wrapper for table TblBrlyQConMapFlight (PgSQL database)
  */
class PgTblBrlyQConMapFlight : public TblBrlyQConMapFlight, public PgTable {

public:
	PgTblBrlyQConMapFlight();
	~PgTblBrlyQConMapFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapFlight& rst);

	void insertRec(BrlyQConMapFlight* rec);
	void insertRst(ListBrlyQConMapFlight& rst);
	void updateRec(BrlyQConMapFlight* rec);
	void updateRst(ListBrlyQConMapFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapFlight& rst);
};

#endif

