/**
  * \file BrlyQLocMapProxLocation.h
  * Dbs and XML wrapper for table TblBrlyQLocMapProxLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMAPPROXLOCATION_H
#define BRLYQLOCMAPPROXLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMapProxLocation: record of TblBrlyQLocMapProxLocation
  */
class BrlyQLocMapProxLocation {

public:
	BrlyQLocMapProxLocation(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint mref = 0, const string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);

public:
	ubigint qref;
	bool qwr;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint mref;
	string stubMref;
	double mtheta;
	double mphi;
	double x;
	double y;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLocMapProxLocation: recordset of TblBrlyQLocMapProxLocation
  */
class ListBrlyQLocMapProxLocation {

public:
	ListBrlyQLocMapProxLocation();
	ListBrlyQLocMapProxLocation(const ListBrlyQLocMapProxLocation& src);
	~ListBrlyQLocMapProxLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMapProxLocation* rec);

	ListBrlyQLocMapProxLocation& operator=(const ListBrlyQLocMapProxLocation& src);

public:
	vector<BrlyQLocMapProxLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocMapProxLocation: C++ wrapper for table TblBrlyQLocMapProxLocation
  */
class TblBrlyQLocMapProxLocation {

public:
	TblBrlyQLocMapProxLocation();
	virtual ~TblBrlyQLocMapProxLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocMapProxLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapProxLocation& rst);

	virtual void insertRec(BrlyQLocMapProxLocation* rec);
	ubigint insertNewRec(BrlyQLocMapProxLocation** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint mref = 0, const string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLocMapProxLocation& rst, BrlyQLocMapProxLocation** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint mref = 0, const string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListBrlyQLocMapProxLocation& rst);
	virtual void updateRec(BrlyQLocMapProxLocation* rec);
	virtual void updateRst(ListBrlyQLocMapProxLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocMapProxLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapProxLocation& rst);
};

/**
  * MyBrlyQLocMapProxLocation: C++ wrapper for table TblBrlyQLocMapProxLocation (MySQL database)
  */
class MyTblBrlyQLocMapProxLocation : public TblBrlyQLocMapProxLocation, public MyTable {

public:
	MyTblBrlyQLocMapProxLocation();
	~MyTblBrlyQLocMapProxLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMapProxLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapProxLocation& rst);

	void insertRec(BrlyQLocMapProxLocation* rec);
	void insertRst(ListBrlyQLocMapProxLocation& rst);
	void updateRec(BrlyQLocMapProxLocation* rec);
	void updateRst(ListBrlyQLocMapProxLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMapProxLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapProxLocation& rst);
};

/**
  * PgBrlyQLocMapProxLocation: C++ wrapper for table TblBrlyQLocMapProxLocation (PgSQL database)
  */
class PgTblBrlyQLocMapProxLocation : public TblBrlyQLocMapProxLocation, public PgTable {

public:
	PgTblBrlyQLocMapProxLocation();
	~PgTblBrlyQLocMapProxLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMapProxLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMapProxLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMapProxLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMapProxLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMapProxLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapProxLocation& rst);

	void insertRec(BrlyQLocMapProxLocation* rec);
	void insertRst(ListBrlyQLocMapProxLocation& rst);
	void updateRec(BrlyQLocMapProxLocation* rec);
	void updateRst(ListBrlyQLocMapProxLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMapProxLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapProxLocation& rst);
};

#endif

