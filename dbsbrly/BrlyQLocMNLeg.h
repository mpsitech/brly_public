/**
  * \file BrlyQLocMNLeg.h
  * Dbs and XML wrapper for table TblBrlyQLocMNLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMNLEG_H
#define BRLYQLOCMNLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMNLeg: record of TblBrlyQLocMNLeg
  */
class BrlyQLocMNLeg {

public:
	BrlyQLocMNLeg(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	double x1VisLegphi0;
	double x1VisLegphi1;
	double legphi;
	double legtheta;
	double xVisLegphi0;
	double xVisLegphi1;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLocMNLeg: recordset of TblBrlyQLocMNLeg
  */
class ListBrlyQLocMNLeg {

public:
	ListBrlyQLocMNLeg();
	ListBrlyQLocMNLeg(const ListBrlyQLocMNLeg& src);
	~ListBrlyQLocMNLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMNLeg* rec);

	ListBrlyQLocMNLeg& operator=(const ListBrlyQLocMNLeg& src);

public:
	vector<BrlyQLocMNLeg*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocMNLeg: C++ wrapper for table TblBrlyQLocMNLeg
  */
class TblBrlyQLocMNLeg {

public:
	TblBrlyQLocMNLeg();
	virtual ~TblBrlyQLocMNLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocMNLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNLeg& rst);

	virtual void insertRec(BrlyQLocMNLeg* rec);
	ubigint insertNewRec(BrlyQLocMNLeg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLocMNLeg& rst, BrlyQLocMNLeg** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	virtual void insertRst(ListBrlyQLocMNLeg& rst);
	virtual void updateRec(BrlyQLocMNLeg* rec);
	virtual void updateRst(ListBrlyQLocMNLeg& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocMNLeg** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNLeg& rst);
};

/**
  * MyBrlyQLocMNLeg: C++ wrapper for table TblBrlyQLocMNLeg (MySQL database)
  */
class MyTblBrlyQLocMNLeg : public TblBrlyQLocMNLeg, public MyTable {

public:
	MyTblBrlyQLocMNLeg();
	~MyTblBrlyQLocMNLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMNLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNLeg& rst);

	void insertRec(BrlyQLocMNLeg* rec);
	void insertRst(ListBrlyQLocMNLeg& rst);
	void updateRec(BrlyQLocMNLeg* rec);
	void updateRst(ListBrlyQLocMNLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMNLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNLeg& rst);
};

/**
  * PgBrlyQLocMNLeg: C++ wrapper for table TblBrlyQLocMNLeg (PgSQL database)
  */
class PgTblBrlyQLocMNLeg : public TblBrlyQLocMNLeg, public PgTable {

public:
	PgTblBrlyQLocMNLeg();
	~PgTblBrlyQLocMNLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMNLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMNLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMNLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMNLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMNLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNLeg& rst);

	void insertRec(BrlyQLocMNLeg* rec);
	void insertRst(ListBrlyQLocMNLeg& rst);
	void updateRec(BrlyQLocMNLeg* rec);
	void updateRst(ListBrlyQLocMNLeg& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMNLeg** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNLeg& rst);
};

#endif

