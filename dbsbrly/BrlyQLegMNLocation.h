/**
  * \file BrlyQLegMNLocation.h
  * Dbs and XML wrapper for table TblBrlyQLegMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGMNLOCATION_H
#define BRLYQLEGMNLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegMNLocation: record of TblBrlyQLegMNLocation
  */
class BrlyQLegMNLocation {

public:
	BrlyQLegMNLocation(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);

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
  * ListBrlyQLegMNLocation: recordset of TblBrlyQLegMNLocation
  */
class ListBrlyQLegMNLocation {

public:
	ListBrlyQLegMNLocation();
	ListBrlyQLegMNLocation(const ListBrlyQLegMNLocation& src);
	~ListBrlyQLegMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegMNLocation* rec);

	ListBrlyQLegMNLocation& operator=(const ListBrlyQLegMNLocation& src);

public:
	vector<BrlyQLegMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLegMNLocation: C++ wrapper for table TblBrlyQLegMNLocation
  */
class TblBrlyQLegMNLocation {

public:
	TblBrlyQLegMNLocation();
	virtual ~TblBrlyQLegMNLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLegMNLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMNLocation& rst);

	virtual void insertRec(BrlyQLegMNLocation* rec);
	ubigint insertNewRec(BrlyQLegMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLegMNLocation& rst, BrlyQLegMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double x1VisLegphi0 = 0.0, const double x1VisLegphi1 = 0.0, const double legphi = 0.0, const double legtheta = 0.0, const double xVisLegphi0 = 0.0, const double xVisLegphi1 = 0.0);
	virtual void insertRst(ListBrlyQLegMNLocation& rst);
	virtual void updateRec(BrlyQLegMNLocation* rec);
	virtual void updateRst(ListBrlyQLegMNLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLegMNLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMNLocation& rst);
};

/**
  * MyBrlyQLegMNLocation: C++ wrapper for table TblBrlyQLegMNLocation (MySQL database)
  */
class MyTblBrlyQLegMNLocation : public TblBrlyQLegMNLocation, public MyTable {

public:
	MyTblBrlyQLegMNLocation();
	~MyTblBrlyQLegMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMNLocation& rst);

	void insertRec(BrlyQLegMNLocation* rec);
	void insertRst(ListBrlyQLegMNLocation& rst);
	void updateRec(BrlyQLegMNLocation* rec);
	void updateRst(ListBrlyQLegMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMNLocation& rst);
};

/**
  * PgBrlyQLegMNLocation: C++ wrapper for table TblBrlyQLegMNLocation (PgSQL database)
  */
class PgTblBrlyQLegMNLocation : public TblBrlyQLegMNLocation, public PgTable {

public:
	PgTblBrlyQLegMNLocation();
	~PgTblBrlyQLegMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegMNLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegMNLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegMNLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegMNLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMNLocation& rst);

	void insertRec(BrlyQLegMNLocation* rec);
	void insertRst(ListBrlyQLegMNLocation& rst);
	void updateRec(BrlyQLegMNLocation* rec);
	void updateRst(ListBrlyQLegMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMNLocation& rst);
};

#endif

