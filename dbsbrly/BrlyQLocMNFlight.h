/**
  * \file BrlyQLocMNFlight.h
  * Dbs and XML wrapper for table TblBrlyQLocMNFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMNFLIGHT_H
#define BRLYQLOCMNFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMNFlight: record of TblBrlyQLocMNFlight
  */
class BrlyQLocMNFlight {

public:
	BrlyQLocMNFlight(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");

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
  * ListBrlyQLocMNFlight: recordset of TblBrlyQLocMNFlight
  */
class ListBrlyQLocMNFlight {

public:
	ListBrlyQLocMNFlight();
	ListBrlyQLocMNFlight(const ListBrlyQLocMNFlight& src);
	~ListBrlyQLocMNFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMNFlight* rec);

	ListBrlyQLocMNFlight& operator=(const ListBrlyQLocMNFlight& src);

public:
	vector<BrlyQLocMNFlight*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocMNFlight: C++ wrapper for table TblBrlyQLocMNFlight
  */
class TblBrlyQLocMNFlight {

public:
	TblBrlyQLocMNFlight();
	virtual ~TblBrlyQLocMNFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocMNFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNFlight& rst);

	virtual void insertRec(BrlyQLocMNFlight* rec);
	ubigint insertNewRec(BrlyQLocMNFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");
	ubigint appendNewRecToRst(ListBrlyQLocMNFlight& rst, BrlyQLocMNFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");
	virtual void insertRst(ListBrlyQLocMNFlight& rst);
	virtual void updateRec(BrlyQLocMNFlight* rec);
	virtual void updateRst(ListBrlyQLocMNFlight& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocMNFlight** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNFlight& rst);
};

/**
  * MyBrlyQLocMNFlight: C++ wrapper for table TblBrlyQLocMNFlight (MySQL database)
  */
class MyTblBrlyQLocMNFlight : public TblBrlyQLocMNFlight, public MyTable {

public:
	MyTblBrlyQLocMNFlight();
	~MyTblBrlyQLocMNFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMNFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNFlight& rst);

	void insertRec(BrlyQLocMNFlight* rec);
	void insertRst(ListBrlyQLocMNFlight& rst);
	void updateRec(BrlyQLocMNFlight* rec);
	void updateRst(ListBrlyQLocMNFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMNFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNFlight& rst);
};

/**
  * PgBrlyQLocMNFlight: C++ wrapper for table TblBrlyQLocMNFlight (PgSQL database)
  */
class PgTblBrlyQLocMNFlight : public TblBrlyQLocMNFlight, public PgTable {

public:
	PgTblBrlyQLocMNFlight();
	~PgTblBrlyQLocMNFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMNFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMNFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMNFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMNFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMNFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNFlight& rst);

	void insertRec(BrlyQLocMNFlight* rec);
	void insertRst(ListBrlyQLocMNFlight& rst);
	void updateRec(BrlyQLocMNFlight* rec);
	void updateRst(ListBrlyQLocMNFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMNFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNFlight& rst);
};

#endif

