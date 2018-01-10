/**
  * \file BrlyQLocMapLeg.h
  * Dbs and XML wrapper for table TblBrlyQLocMapLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMAPLEG_H
#define BRLYQLOCMAPLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMapLeg: record of TblBrlyQLocMapLeg
  */
class BrlyQLocMapLeg {

public:
	BrlyQLocMapLeg(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0, const double lam1 = 0.0, const double lam2 = 0.0, const double lam3 = 0.0);

public:
	ubigint qref;
	bool qwr;
	ubigint jref;
	uint jnum;
	ubigint ref;
	double x1VisLegphi0;
	double x1VisLegphi1;
	ubigint mref;
	string stubMref;
	ubigint mbgnRefBrlyMLocation;
	ubigint mendRefBrlyMLocation;
	double dx;
	double dy;
	double x0;
	double y0;
	double lam1;
	double lam2;
	double lam3;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLocMapLeg: recordset of TblBrlyQLocMapLeg
  */
class ListBrlyQLocMapLeg {

public:
	ListBrlyQLocMapLeg();
	ListBrlyQLocMapLeg(const ListBrlyQLocMapLeg& src);
	~ListBrlyQLocMapLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMapLeg* rec);

	ListBrlyQLocMapLeg& operator=(const ListBrlyQLocMapLeg& src);

public:
	vector<BrlyQLocMapLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocMapLeg: C++ wrapper for table TblBrlyQLocMapLeg
  */
class TblBrlyQLocMapLeg {

public:
	TblBrlyQLocMapLeg();
	virtual ~TblBrlyQLocMapLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocMapLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapLeg& rst);

	virtual void insertRec(BrlyQLocMapLeg* rec);
	ubigint insertNewRec(BrlyQLocMapLeg** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0, const double lam1 = 0.0, const double lam2 = 0.0, const double lam3 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLocMapLeg& rst, BrlyQLocMapLeg** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0, const double lam1 = 0.0, const double lam2 = 0.0, const double lam3 = 0.0);
	virtual void insertRst(ListBrlyQLocMapLeg& rst);
	virtual void updateRec(BrlyQLocMapLeg* rec);
	virtual void updateRst(ListBrlyQLocMapLeg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocMapLeg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapLeg& rst);
};

/**
  * MyBrlyQLocMapLeg: C++ wrapper for table TblBrlyQLocMapLeg (MySQL database)
  */
class MyTblBrlyQLocMapLeg : public TblBrlyQLocMapLeg, public MyTable {

public:
	MyTblBrlyQLocMapLeg();
	~MyTblBrlyQLocMapLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMapLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapLeg& rst);

	void insertRec(BrlyQLocMapLeg* rec);
	void insertRst(ListBrlyQLocMapLeg& rst);
	void updateRec(BrlyQLocMapLeg* rec);
	void updateRst(ListBrlyQLocMapLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMapLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapLeg& rst);
};

/**
  * PgBrlyQLocMapLeg: C++ wrapper for table TblBrlyQLocMapLeg (PgSQL database)
  */
class PgTblBrlyQLocMapLeg : public TblBrlyQLocMapLeg, public PgTable {

public:
	PgTblBrlyQLocMapLeg();
	~PgTblBrlyQLocMapLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMapLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMapLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMapLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMapLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMapLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapLeg& rst);

	void insertRec(BrlyQLocMapLeg* rec);
	void insertRst(ListBrlyQLocMapLeg& rst);
	void updateRec(BrlyQLocMapLeg* rec);
	void updateRst(ListBrlyQLocMapLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMapLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapLeg& rst);
};

#endif

