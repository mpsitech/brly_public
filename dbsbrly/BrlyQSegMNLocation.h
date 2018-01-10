/**
  * \file BrlyQSegMNLocation.h
  * Dbs and XML wrapper for table TblBrlyQSegMNLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQSEGMNLOCATION_H
#define BRLYQSEGMNLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQSegMNLocation: record of TblBrlyQSegMNLocation
  */
class BrlyQSegMNLocation {

public:
	BrlyQSegMNLocation(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint x1Start;
	string ftmX1Start;
	uint x1Stop;
	string ftmX1Stop;
	double x2VisSegphi0;
	double x2VisSegphi1;
	double segphi;
	double segtheta;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQSegMNLocation: recordset of TblBrlyQSegMNLocation
  */
class ListBrlyQSegMNLocation {

public:
	ListBrlyQSegMNLocation();
	ListBrlyQSegMNLocation(const ListBrlyQSegMNLocation& src);
	~ListBrlyQSegMNLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQSegMNLocation* rec);

	ListBrlyQSegMNLocation& operator=(const ListBrlyQSegMNLocation& src);

public:
	vector<BrlyQSegMNLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQSegMNLocation: C++ wrapper for table TblBrlyQSegMNLocation
  */
class TblBrlyQSegMNLocation {

public:
	TblBrlyQSegMNLocation();
	virtual ~TblBrlyQSegMNLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQSegMNLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegMNLocation& rst);

	virtual void insertRec(BrlyQSegMNLocation* rec);
	ubigint insertNewRec(BrlyQSegMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);
	ubigint appendNewRecToRst(ListBrlyQSegMNLocation& rst, BrlyQSegMNLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);
	virtual void insertRst(ListBrlyQSegMNLocation& rst);
	virtual void updateRec(BrlyQSegMNLocation* rec);
	virtual void updateRst(ListBrlyQSegMNLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQSegMNLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegMNLocation& rst);
};

/**
  * MyBrlyQSegMNLocation: C++ wrapper for table TblBrlyQSegMNLocation (MySQL database)
  */
class MyTblBrlyQSegMNLocation : public TblBrlyQSegMNLocation, public MyTable {

public:
	MyTblBrlyQSegMNLocation();
	~MyTblBrlyQSegMNLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSegMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegMNLocation& rst);

	void insertRec(BrlyQSegMNLocation* rec);
	void insertRst(ListBrlyQSegMNLocation& rst);
	void updateRec(BrlyQSegMNLocation* rec);
	void updateRst(ListBrlyQSegMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSegMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegMNLocation& rst);
};

/**
  * PgBrlyQSegMNLocation: C++ wrapper for table TblBrlyQSegMNLocation (PgSQL database)
  */
class PgTblBrlyQSegMNLocation : public TblBrlyQSegMNLocation, public PgTable {

public:
	PgTblBrlyQSegMNLocation();
	~PgTblBrlyQSegMNLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSegMNLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQSegMNLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSegMNLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSegMNLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSegMNLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegMNLocation& rst);

	void insertRec(BrlyQSegMNLocation* rec);
	void insertRst(ListBrlyQSegMNLocation& rst);
	void updateRec(BrlyQSegMNLocation* rec);
	void updateRst(ListBrlyQSegMNLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSegMNLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegMNLocation& rst);
};

#endif

