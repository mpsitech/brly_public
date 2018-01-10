/**
  * \file BrlyQConMapLeg.h
  * Dbs and XML wrapper for table TblBrlyQConMapLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPLEG_H
#define BRLYQCONMAPLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapLeg: record of TblBrlyQConMapLeg
  */
class BrlyQConMapLeg {

public:
	BrlyQConMapLeg(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double mdeltaphi = 0.0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);

public:
	ubigint qref;
	bool qwr;
	ubigint jref;
	uint jnum;
	ubigint ref;
	double VisOrgLegphi0;
	double VisOrgLegphi1;
	ubigint mref;
	string stubMref;
	ubigint mbgnRefBrlyMLocation;
	ubigint mendRefBrlyMLocation;
	double mdeltaphi;
	double dx;
	double dy;
	double x0;
	double y0;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConMapLeg: recordset of TblBrlyQConMapLeg
  */
class ListBrlyQConMapLeg {

public:
	ListBrlyQConMapLeg();
	ListBrlyQConMapLeg(const ListBrlyQConMapLeg& src);
	~ListBrlyQConMapLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapLeg* rec);

	ListBrlyQConMapLeg& operator=(const ListBrlyQConMapLeg& src);

public:
	vector<BrlyQConMapLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConMapLeg: C++ wrapper for table TblBrlyQConMapLeg
  */
class TblBrlyQConMapLeg {

public:
	TblBrlyQConMapLeg();
	virtual ~TblBrlyQConMapLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConMapLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapLeg& rst);

	virtual void insertRec(BrlyQConMapLeg* rec);
	ubigint insertNewRec(BrlyQConMapLeg** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double mdeltaphi = 0.0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQConMapLeg& rst, BrlyQConMapLeg** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double mdeltaphi = 0.0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);
	virtual void insertRst(ListBrlyQConMapLeg& rst);
	virtual void updateRec(BrlyQConMapLeg* rec);
	virtual void updateRst(ListBrlyQConMapLeg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConMapLeg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapLeg& rst);
};

/**
  * MyBrlyQConMapLeg: C++ wrapper for table TblBrlyQConMapLeg (MySQL database)
  */
class MyTblBrlyQConMapLeg : public TblBrlyQConMapLeg, public MyTable {

public:
	MyTblBrlyQConMapLeg();
	~MyTblBrlyQConMapLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapLeg& rst);

	void insertRec(BrlyQConMapLeg* rec);
	void insertRst(ListBrlyQConMapLeg& rst);
	void updateRec(BrlyQConMapLeg* rec);
	void updateRst(ListBrlyQConMapLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapLeg& rst);
};

/**
  * PgBrlyQConMapLeg: C++ wrapper for table TblBrlyQConMapLeg (PgSQL database)
  */
class PgTblBrlyQConMapLeg : public TblBrlyQConMapLeg, public PgTable {

public:
	PgTblBrlyQConMapLeg();
	~PgTblBrlyQConMapLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapLeg& rst);

	void insertRec(BrlyQConMapLeg* rec);
	void insertRst(ListBrlyQConMapLeg& rst);
	void updateRec(BrlyQConMapLeg* rec);
	void updateRst(ListBrlyQConMapLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapLeg& rst);
};

#endif

