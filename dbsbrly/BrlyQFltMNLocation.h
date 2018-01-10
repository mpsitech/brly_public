/**
  * \file BrlyQFltMNLocation.h
  * Dbs and XML wrapper for table TblBrlyQFltMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTMNLOCATION_H
#define BRLYQFLTMNLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltMNLocation: record of TblBrlyQFltMNLocation
  */
class BrlyQFltMNLocation {

public:
	BrlyQFltMNLocation(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint x1VisStart;
	string ftmX1VisStart;
	uint x1VisStop;
	string ftmX1VisStop;
	uint xVisStart;
	string ftmXVisStart;
	uint xVisStop;
	string ftmXVisStop;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQFltMNLocation: recordset of TblBrlyQFltMNLocation
  */
class ListBrlyQFltMNLocation {

public:
	ListBrlyQFltMNLocation();
	ListBrlyQFltMNLocation(const ListBrlyQFltMNLocation& src);
	~ListBrlyQFltMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltMNLocation* rec);

	ListBrlyQFltMNLocation& operator=(const ListBrlyQFltMNLocation& src);

public:
	vector<BrlyQFltMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFltMNLocation: C++ wrapper for table TblBrlyQFltMNLocation
  */
class TblBrlyQFltMNLocation {

public:
	TblBrlyQFltMNLocation();
	virtual ~TblBrlyQFltMNLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFltMNLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltMNLocation& rst);

	virtual void insertRec(BrlyQFltMNLocation* rec);
	ubigint insertNewRec(BrlyQFltMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");
	ubigint appendNewRecToRst(ListBrlyQFltMNLocation& rst, BrlyQFltMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");
	virtual void insertRst(ListBrlyQFltMNLocation& rst);
	virtual void updateRec(BrlyQFltMNLocation* rec);
	virtual void updateRst(ListBrlyQFltMNLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFltMNLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltMNLocation& rst);
};

/**
  * MyBrlyQFltMNLocation: C++ wrapper for table TblBrlyQFltMNLocation (MySQL database)
  */
class MyTblBrlyQFltMNLocation : public TblBrlyQFltMNLocation, public MyTable {

public:
	MyTblBrlyQFltMNLocation();
	~MyTblBrlyQFltMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltMNLocation& rst);

	void insertRec(BrlyQFltMNLocation* rec);
	void insertRst(ListBrlyQFltMNLocation& rst);
	void updateRec(BrlyQFltMNLocation* rec);
	void updateRst(ListBrlyQFltMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltMNLocation& rst);
};

/**
  * PgBrlyQFltMNLocation: C++ wrapper for table TblBrlyQFltMNLocation (PgSQL database)
  */
class PgTblBrlyQFltMNLocation : public TblBrlyQFltMNLocation, public PgTable {

public:
	PgTblBrlyQFltMNLocation();
	~PgTblBrlyQFltMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltMNLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltMNLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltMNLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltMNLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltMNLocation& rst);

	void insertRec(BrlyQFltMNLocation* rec);
	void insertRst(ListBrlyQFltMNLocation& rst);
	void updateRec(BrlyQFltMNLocation* rec);
	void updateRst(ListBrlyQFltMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltMNLocation& rst);
};

#endif

