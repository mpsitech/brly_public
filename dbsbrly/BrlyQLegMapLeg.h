/**
  * \file BrlyQLegMapLeg.h
  * Dbs and XML wrapper for table TblBrlyQLegMapLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGMAPLEG_H
#define BRLYQLEGMAPLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegMapLeg: record of TblBrlyQLegMapLeg
  */
class BrlyQLegMapLeg {

public:
	BrlyQLegMapLeg(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);

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
	double dx;
	double dy;
	double x0;
	double y0;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLegMapLeg: recordset of TblBrlyQLegMapLeg
  */
class ListBrlyQLegMapLeg {

public:
	ListBrlyQLegMapLeg();
	ListBrlyQLegMapLeg(const ListBrlyQLegMapLeg& src);
	~ListBrlyQLegMapLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegMapLeg* rec);

	ListBrlyQLegMapLeg& operator=(const ListBrlyQLegMapLeg& src);

public:
	vector<BrlyQLegMapLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLegMapLeg: C++ wrapper for table TblBrlyQLegMapLeg
  */
class TblBrlyQLegMapLeg {

public:
	TblBrlyQLegMapLeg();
	virtual ~TblBrlyQLegMapLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLegMapLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMapLeg& rst);

	virtual void insertRec(BrlyQLegMapLeg* rec);
	ubigint insertNewRec(BrlyQLegMapLeg** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLegMapLeg& rst, BrlyQLegMapLeg** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mbgnRefBrlyMLocation = 0, const ubigint mendRefBrlyMLocation = 0, const double dx = 0.0, const double dy = 0.0, const double x0 = 0.0, const double y0 = 0.0);
	virtual void insertRst(ListBrlyQLegMapLeg& rst);
	virtual void updateRec(BrlyQLegMapLeg* rec);
	virtual void updateRst(ListBrlyQLegMapLeg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLegMapLeg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMapLeg& rst);
};

/**
  * MyBrlyQLegMapLeg: C++ wrapper for table TblBrlyQLegMapLeg (MySQL database)
  */
class MyTblBrlyQLegMapLeg : public TblBrlyQLegMapLeg, public MyTable {

public:
	MyTblBrlyQLegMapLeg();
	~MyTblBrlyQLegMapLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegMapLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMapLeg& rst);

	void insertRec(BrlyQLegMapLeg* rec);
	void insertRst(ListBrlyQLegMapLeg& rst);
	void updateRec(BrlyQLegMapLeg* rec);
	void updateRst(ListBrlyQLegMapLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegMapLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMapLeg& rst);
};

/**
  * PgBrlyQLegMapLeg: C++ wrapper for table TblBrlyQLegMapLeg (PgSQL database)
  */
class PgTblBrlyQLegMapLeg : public TblBrlyQLegMapLeg, public PgTable {

public:
	PgTblBrlyQLegMapLeg();
	~PgTblBrlyQLegMapLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegMapLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegMapLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegMapLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegMapLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegMapLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMapLeg& rst);

	void insertRec(BrlyQLegMapLeg* rec);
	void insertRst(ListBrlyQLegMapLeg& rst);
	void updateRec(BrlyQLegMapLeg* rec);
	void updateRst(ListBrlyQLegMapLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegMapLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMapLeg& rst);
};

#endif

