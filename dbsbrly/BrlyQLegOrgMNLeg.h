/**
  * \file BrlyQLegOrgMNLeg.h
  * Dbs and XML wrapper for table TblBrlyQLegOrgMNLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGORGMNLEG_H
#define BRLYQLEGORGMNLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegOrgMNLeg: record of TblBrlyQLegOrgMNLeg
  */
class BrlyQLegOrgMNLeg {

public:
	BrlyQLegOrgMNLeg(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	double x1VisDstLegphi0;
	double x1VisDstLegphi1;
	double VisOrgLegphi0;
	double VisOrgLegphi1;
	double xVisDstLegphi0;
	double xVisDstLegphi1;
	double xVisOrgLegphi0;
	double xVisOrgLegphi1;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLegOrgMNLeg: recordset of TblBrlyQLegOrgMNLeg
  */
class ListBrlyQLegOrgMNLeg {

public:
	ListBrlyQLegOrgMNLeg();
	ListBrlyQLegOrgMNLeg(const ListBrlyQLegOrgMNLeg& src);
	~ListBrlyQLegOrgMNLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegOrgMNLeg* rec);

	ListBrlyQLegOrgMNLeg& operator=(const ListBrlyQLegOrgMNLeg& src);

public:
	vector<BrlyQLegOrgMNLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLegOrgMNLeg: C++ wrapper for table TblBrlyQLegOrgMNLeg
  */
class TblBrlyQLegOrgMNLeg {

public:
	TblBrlyQLegOrgMNLeg();
	virtual ~TblBrlyQLegOrgMNLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLegOrgMNLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegOrgMNLeg& rst);

	virtual void insertRec(BrlyQLegOrgMNLeg* rec);
	ubigint insertNewRec(BrlyQLegOrgMNLeg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLegOrgMNLeg& rst, BrlyQLegOrgMNLeg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);
	virtual void insertRst(ListBrlyQLegOrgMNLeg& rst);
	virtual void updateRec(BrlyQLegOrgMNLeg* rec);
	virtual void updateRst(ListBrlyQLegOrgMNLeg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLegOrgMNLeg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegOrgMNLeg& rst);
};

/**
  * MyBrlyQLegOrgMNLeg: C++ wrapper for table TblBrlyQLegOrgMNLeg (MySQL database)
  */
class MyTblBrlyQLegOrgMNLeg : public TblBrlyQLegOrgMNLeg, public MyTable {

public:
	MyTblBrlyQLegOrgMNLeg();
	~MyTblBrlyQLegOrgMNLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegOrgMNLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegOrgMNLeg& rst);

	void insertRec(BrlyQLegOrgMNLeg* rec);
	void insertRst(ListBrlyQLegOrgMNLeg& rst);
	void updateRec(BrlyQLegOrgMNLeg* rec);
	void updateRst(ListBrlyQLegOrgMNLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegOrgMNLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegOrgMNLeg& rst);
};

/**
  * PgBrlyQLegOrgMNLeg: C++ wrapper for table TblBrlyQLegOrgMNLeg (PgSQL database)
  */
class PgTblBrlyQLegOrgMNLeg : public TblBrlyQLegOrgMNLeg, public PgTable {

public:
	PgTblBrlyQLegOrgMNLeg();
	~PgTblBrlyQLegOrgMNLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegOrgMNLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegOrgMNLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegOrgMNLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegOrgMNLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegOrgMNLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegOrgMNLeg& rst);

	void insertRec(BrlyQLegOrgMNLeg* rec);
	void insertRst(ListBrlyQLegOrgMNLeg& rst);
	void updateRec(BrlyQLegOrgMNLeg* rec);
	void updateRst(ListBrlyQLegOrgMNLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegOrgMNLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegOrgMNLeg& rst);
};

#endif

