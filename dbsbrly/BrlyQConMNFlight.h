/**
  * \file BrlyQConMNFlight.h
  * Dbs and XML wrapper for table TblBrlyQConMNFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMNFLIGHT_H
#define BRLYQCONMNFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMNFlight: record of TblBrlyQConMNFlight
  */
class BrlyQConMNFlight {

public:
	BrlyQConMNFlight(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

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
	double x2Legphi0;
	double x2Legphi1;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConMNFlight: recordset of TblBrlyQConMNFlight
  */
class ListBrlyQConMNFlight {

public:
	ListBrlyQConMNFlight();
	ListBrlyQConMNFlight(const ListBrlyQConMNFlight& src);
	~ListBrlyQConMNFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMNFlight* rec);

	ListBrlyQConMNFlight& operator=(const ListBrlyQConMNFlight& src);

public:
	vector<BrlyQConMNFlight*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConMNFlight: C++ wrapper for table TblBrlyQConMNFlight
  */
class TblBrlyQConMNFlight {

public:
	TblBrlyQConMNFlight();
	virtual ~TblBrlyQConMNFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConMNFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMNFlight& rst);

	virtual void insertRec(BrlyQConMNFlight* rec);
	ubigint insertNewRec(BrlyQConMNFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQConMNFlight& rst, BrlyQConMNFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	virtual void insertRst(ListBrlyQConMNFlight& rst);
	virtual void updateRec(BrlyQConMNFlight* rec);
	virtual void updateRst(ListBrlyQConMNFlight& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConMNFlight** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMNFlight& rst);
};

/**
  * MyBrlyQConMNFlight: C++ wrapper for table TblBrlyQConMNFlight (MySQL database)
  */
class MyTblBrlyQConMNFlight : public TblBrlyQConMNFlight, public MyTable {

public:
	MyTblBrlyQConMNFlight();
	~MyTblBrlyQConMNFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMNFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMNFlight& rst);

	void insertRec(BrlyQConMNFlight* rec);
	void insertRst(ListBrlyQConMNFlight& rst);
	void updateRec(BrlyQConMNFlight* rec);
	void updateRst(ListBrlyQConMNFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMNFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMNFlight& rst);
};

/**
  * PgBrlyQConMNFlight: C++ wrapper for table TblBrlyQConMNFlight (PgSQL database)
  */
class PgTblBrlyQConMNFlight : public TblBrlyQConMNFlight, public PgTable {

public:
	PgTblBrlyQConMNFlight();
	~PgTblBrlyQConMNFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMNFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMNFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMNFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMNFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMNFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMNFlight& rst);

	void insertRec(BrlyQConMNFlight* rec);
	void insertRst(ListBrlyQConMNFlight& rst);
	void updateRec(BrlyQConMNFlight* rec);
	void updateRst(ListBrlyQConMNFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMNFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMNFlight& rst);
};

#endif

