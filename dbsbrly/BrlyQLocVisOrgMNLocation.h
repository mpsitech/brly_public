/**
  * \file BrlyQLocVisOrgMNLocation.h
  * Dbs and XML wrapper for table TblBrlyQLocVisOrgMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCVISORGMNLOCATION_H
#define BRLYQLOCVISORGMNLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocVisOrgMNLocation: record of TblBrlyQLocVisOrgMNLocation
  */
class BrlyQLocVisOrgMNLocation {

public:
	BrlyQLocVisOrgMNLocation(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLocVisOrgMNLocation: recordset of TblBrlyQLocVisOrgMNLocation
  */
class ListBrlyQLocVisOrgMNLocation {

public:
	ListBrlyQLocVisOrgMNLocation();
	ListBrlyQLocVisOrgMNLocation(const ListBrlyQLocVisOrgMNLocation& src);
	~ListBrlyQLocVisOrgMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocVisOrgMNLocation* rec);

	ListBrlyQLocVisOrgMNLocation& operator=(const ListBrlyQLocVisOrgMNLocation& src);

public:
	vector<BrlyQLocVisOrgMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocVisOrgMNLocation: C++ wrapper for table TblBrlyQLocVisOrgMNLocation
  */
class TblBrlyQLocVisOrgMNLocation {

public:
	TblBrlyQLocVisOrgMNLocation();
	virtual ~TblBrlyQLocVisOrgMNLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocVisOrgMNLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocVisOrgMNLocation& rst);

	virtual void insertRec(BrlyQLocVisOrgMNLocation* rec);
	ubigint insertNewRec(BrlyQLocVisOrgMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListBrlyQLocVisOrgMNLocation& rst, BrlyQLocVisOrgMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListBrlyQLocVisOrgMNLocation& rst);
	virtual void updateRec(BrlyQLocVisOrgMNLocation* rec);
	virtual void updateRst(ListBrlyQLocVisOrgMNLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocVisOrgMNLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocVisOrgMNLocation& rst);
};

/**
  * MyBrlyQLocVisOrgMNLocation: C++ wrapper for table TblBrlyQLocVisOrgMNLocation (MySQL database)
  */
class MyTblBrlyQLocVisOrgMNLocation : public TblBrlyQLocVisOrgMNLocation, public MyTable {

public:
	MyTblBrlyQLocVisOrgMNLocation();
	~MyTblBrlyQLocVisOrgMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocVisOrgMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocVisOrgMNLocation& rst);

	void insertRec(BrlyQLocVisOrgMNLocation* rec);
	void insertRst(ListBrlyQLocVisOrgMNLocation& rst);
	void updateRec(BrlyQLocVisOrgMNLocation* rec);
	void updateRst(ListBrlyQLocVisOrgMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocVisOrgMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocVisOrgMNLocation& rst);
};

/**
  * PgBrlyQLocVisOrgMNLocation: C++ wrapper for table TblBrlyQLocVisOrgMNLocation (PgSQL database)
  */
class PgTblBrlyQLocVisOrgMNLocation : public TblBrlyQLocVisOrgMNLocation, public PgTable {

public:
	PgTblBrlyQLocVisOrgMNLocation();
	~PgTblBrlyQLocVisOrgMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocVisOrgMNLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocVisOrgMNLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocVisOrgMNLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocVisOrgMNLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocVisOrgMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocVisOrgMNLocation& rst);

	void insertRec(BrlyQLocVisOrgMNLocation* rec);
	void insertRst(ListBrlyQLocVisOrgMNLocation& rst);
	void updateRec(BrlyQLocVisOrgMNLocation* rec);
	void updateRst(ListBrlyQLocVisOrgMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocVisOrgMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocVisOrgMNLocation& rst);
};

#endif

