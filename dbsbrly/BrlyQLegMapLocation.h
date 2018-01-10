/**
  * \file BrlyQLegMapLocation.h
  * Dbs and XML wrapper for table TblBrlyQLegMapLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGMAPLOCATION_H
#define BRLYQLEGMAPLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegMapLocation: record of TblBrlyQLegMapLocation
  */
class BrlyQLegMapLocation {

public:
	BrlyQLegMapLocation(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const ubigint mref = 0, const string stubMref = "", const double x = 0.0, const double y = 0.0);

public:
	ubigint qref;
	bool qwr;
	ubigint jref;
	uint jnum;
	ubigint ref;
	double legphi;
	double legtheta;
	ubigint mref;
	string stubMref;
	double x;
	double y;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLegMapLocation: recordset of TblBrlyQLegMapLocation
  */
class ListBrlyQLegMapLocation {

public:
	ListBrlyQLegMapLocation();
	ListBrlyQLegMapLocation(const ListBrlyQLegMapLocation& src);
	~ListBrlyQLegMapLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegMapLocation* rec);

	ListBrlyQLegMapLocation& operator=(const ListBrlyQLegMapLocation& src);

public:
	vector<BrlyQLegMapLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLegMapLocation: C++ wrapper for table TblBrlyQLegMapLocation
  */
class TblBrlyQLegMapLocation {

public:
	TblBrlyQLegMapLocation();
	virtual ~TblBrlyQLegMapLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLegMapLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMapLocation& rst);

	virtual void insertRec(BrlyQLegMapLocation* rec);
	ubigint insertNewRec(BrlyQLegMapLocation** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const ubigint mref = 0, const string stubMref = "", const double x = 0.0, const double y = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLegMapLocation& rst, BrlyQLegMapLocation** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const ubigint mref = 0, const string stubMref = "", const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListBrlyQLegMapLocation& rst);
	virtual void updateRec(BrlyQLegMapLocation* rec);
	virtual void updateRst(ListBrlyQLegMapLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLegMapLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMapLocation& rst);
};

/**
  * MyBrlyQLegMapLocation: C++ wrapper for table TblBrlyQLegMapLocation (MySQL database)
  */
class MyTblBrlyQLegMapLocation : public TblBrlyQLegMapLocation, public MyTable {

public:
	MyTblBrlyQLegMapLocation();
	~MyTblBrlyQLegMapLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegMapLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMapLocation& rst);

	void insertRec(BrlyQLegMapLocation* rec);
	void insertRst(ListBrlyQLegMapLocation& rst);
	void updateRec(BrlyQLegMapLocation* rec);
	void updateRst(ListBrlyQLegMapLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegMapLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMapLocation& rst);
};

/**
  * PgBrlyQLegMapLocation: C++ wrapper for table TblBrlyQLegMapLocation (PgSQL database)
  */
class PgTblBrlyQLegMapLocation : public TblBrlyQLegMapLocation, public PgTable {

public:
	PgTblBrlyQLegMapLocation();
	~PgTblBrlyQLegMapLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegMapLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegMapLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegMapLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegMapLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegMapLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegMapLocation& rst);

	void insertRec(BrlyQLegMapLocation* rec);
	void insertRst(ListBrlyQLegMapLocation& rst);
	void updateRec(BrlyQLegMapLocation* rec);
	void updateRst(ListBrlyQLegMapLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegMapLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegMapLocation& rst);
};

#endif

