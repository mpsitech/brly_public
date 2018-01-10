/**
  * \file BrlyQLocMapVisLocation.h
  * Dbs and XML wrapper for table TblBrlyQLocMapVisLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMAPVISLOCATION_H
#define BRLYQLOCMAPVISLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMapVisLocation: record of TblBrlyQLocMapVisLocation
  */
class BrlyQLocMapVisLocation {

public:
	BrlyQLocMapVisLocation(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint mref = 0, const string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);

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
  * ListBrlyQLocMapVisLocation: recordset of TblBrlyQLocMapVisLocation
  */
class ListBrlyQLocMapVisLocation {

public:
	ListBrlyQLocMapVisLocation();
	ListBrlyQLocMapVisLocation(const ListBrlyQLocMapVisLocation& src);
	~ListBrlyQLocMapVisLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMapVisLocation* rec);

	ListBrlyQLocMapVisLocation& operator=(const ListBrlyQLocMapVisLocation& src);

public:
	vector<BrlyQLocMapVisLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocMapVisLocation: C++ wrapper for table TblBrlyQLocMapVisLocation
  */
class TblBrlyQLocMapVisLocation {

public:
	TblBrlyQLocMapVisLocation();
	virtual ~TblBrlyQLocMapVisLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocMapVisLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapVisLocation& rst);

	virtual void insertRec(BrlyQLocMapVisLocation* rec);
	ubigint insertNewRec(BrlyQLocMapVisLocation** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint mref = 0, const string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLocMapVisLocation& rst, BrlyQLocMapVisLocation** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint mref = 0, const string stubMref = "", const double mtheta = 0.0, const double mphi = 0.0, const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListBrlyQLocMapVisLocation& rst);
	virtual void updateRec(BrlyQLocMapVisLocation* rec);
	virtual void updateRst(ListBrlyQLocMapVisLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocMapVisLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapVisLocation& rst);
};

/**
  * MyBrlyQLocMapVisLocation: C++ wrapper for table TblBrlyQLocMapVisLocation (MySQL database)
  */
class MyTblBrlyQLocMapVisLocation : public TblBrlyQLocMapVisLocation, public MyTable {

public:
	MyTblBrlyQLocMapVisLocation();
	~MyTblBrlyQLocMapVisLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMapVisLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapVisLocation& rst);

	void insertRec(BrlyQLocMapVisLocation* rec);
	void insertRst(ListBrlyQLocMapVisLocation& rst);
	void updateRec(BrlyQLocMapVisLocation* rec);
	void updateRst(ListBrlyQLocMapVisLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMapVisLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapVisLocation& rst);
};

/**
  * PgBrlyQLocMapVisLocation: C++ wrapper for table TblBrlyQLocMapVisLocation (PgSQL database)
  */
class PgTblBrlyQLocMapVisLocation : public TblBrlyQLocMapVisLocation, public PgTable {

public:
	PgTblBrlyQLocMapVisLocation();
	~PgTblBrlyQLocMapVisLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMapVisLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMapVisLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMapVisLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMapVisLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMapVisLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMapVisLocation& rst);

	void insertRec(BrlyQLocMapVisLocation* rec);
	void insertRst(ListBrlyQLocMapVisLocation& rst);
	void updateRec(BrlyQLocMapVisLocation* rec);
	void updateRst(ListBrlyQLocMapVisLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMapVisLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMapVisLocation& rst);
};

#endif

