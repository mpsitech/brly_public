/**
  * \file BrlyQLocProxOrgMNLocation.h
  * Dbs and XML wrapper for table TblBrlyQLocProxOrgMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCPROXORGMNLOCATION_H
#define BRLYQLOCPROXORGMNLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocProxOrgMNLocation: record of TblBrlyQLocProxOrgMNLocation
  */
class BrlyQLocProxOrgMNLocation {

public:
	BrlyQLocProxOrgMNLocation(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double deltaphi = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	double deltaphi;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLocProxOrgMNLocation: recordset of TblBrlyQLocProxOrgMNLocation
  */
class ListBrlyQLocProxOrgMNLocation {

public:
	ListBrlyQLocProxOrgMNLocation();
	ListBrlyQLocProxOrgMNLocation(const ListBrlyQLocProxOrgMNLocation& src);
	~ListBrlyQLocProxOrgMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocProxOrgMNLocation* rec);

	ListBrlyQLocProxOrgMNLocation& operator=(const ListBrlyQLocProxOrgMNLocation& src);

public:
	vector<BrlyQLocProxOrgMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocProxOrgMNLocation: C++ wrapper for table TblBrlyQLocProxOrgMNLocation
  */
class TblBrlyQLocProxOrgMNLocation {

public:
	TblBrlyQLocProxOrgMNLocation();
	virtual ~TblBrlyQLocProxOrgMNLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocProxOrgMNLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocProxOrgMNLocation& rst);

	virtual void insertRec(BrlyQLocProxOrgMNLocation* rec);
	ubigint insertNewRec(BrlyQLocProxOrgMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double deltaphi = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLocProxOrgMNLocation& rst, BrlyQLocProxOrgMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const double deltaphi = 0.0);
	virtual void insertRst(ListBrlyQLocProxOrgMNLocation& rst);
	virtual void updateRec(BrlyQLocProxOrgMNLocation* rec);
	virtual void updateRst(ListBrlyQLocProxOrgMNLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocProxOrgMNLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocProxOrgMNLocation& rst);
};

/**
  * MyBrlyQLocProxOrgMNLocation: C++ wrapper for table TblBrlyQLocProxOrgMNLocation (MySQL database)
  */
class MyTblBrlyQLocProxOrgMNLocation : public TblBrlyQLocProxOrgMNLocation, public MyTable {

public:
	MyTblBrlyQLocProxOrgMNLocation();
	~MyTblBrlyQLocProxOrgMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocProxOrgMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocProxOrgMNLocation& rst);

	void insertRec(BrlyQLocProxOrgMNLocation* rec);
	void insertRst(ListBrlyQLocProxOrgMNLocation& rst);
	void updateRec(BrlyQLocProxOrgMNLocation* rec);
	void updateRst(ListBrlyQLocProxOrgMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocProxOrgMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocProxOrgMNLocation& rst);
};

/**
  * PgBrlyQLocProxOrgMNLocation: C++ wrapper for table TblBrlyQLocProxOrgMNLocation (PgSQL database)
  */
class PgTblBrlyQLocProxOrgMNLocation : public TblBrlyQLocProxOrgMNLocation, public PgTable {

public:
	PgTblBrlyQLocProxOrgMNLocation();
	~PgTblBrlyQLocProxOrgMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocProxOrgMNLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocProxOrgMNLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocProxOrgMNLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocProxOrgMNLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocProxOrgMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocProxOrgMNLocation& rst);

	void insertRec(BrlyQLocProxOrgMNLocation* rec);
	void insertRst(ListBrlyQLocProxOrgMNLocation& rst);
	void updateRec(BrlyQLocProxOrgMNLocation* rec);
	void updateRst(ListBrlyQLocProxOrgMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocProxOrgMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocProxOrgMNLocation& rst);
};

#endif

