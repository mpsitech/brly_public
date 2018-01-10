/**
  * \file BrlyQFltOrgMNFlight.h
  * Dbs and XML wrapper for table TblBrlyQFltOrgMNFlight (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTORGMNFLIGHT_H
#define BRLYQFLTORGMNFLIGHT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltOrgMNFlight: record of TblBrlyQFltOrgMNFlight
  */
class BrlyQFltOrgMNFlight {

public:
	BrlyQFltOrgMNFlight(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");

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
  * ListBrlyQFltOrgMNFlight: recordset of TblBrlyQFltOrgMNFlight
  */
class ListBrlyQFltOrgMNFlight {

public:
	ListBrlyQFltOrgMNFlight();
	ListBrlyQFltOrgMNFlight(const ListBrlyQFltOrgMNFlight& src);
	~ListBrlyQFltOrgMNFlight();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltOrgMNFlight* rec);

	ListBrlyQFltOrgMNFlight& operator=(const ListBrlyQFltOrgMNFlight& src);

public:
	vector<BrlyQFltOrgMNFlight*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFltOrgMNFlight: C++ wrapper for table TblBrlyQFltOrgMNFlight
  */
class TblBrlyQFltOrgMNFlight {

public:
	TblBrlyQFltOrgMNFlight();
	virtual ~TblBrlyQFltOrgMNFlight();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFltOrgMNFlight** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltOrgMNFlight& rst);

	virtual void insertRec(BrlyQFltOrgMNFlight* rec);
	ubigint insertNewRec(BrlyQFltOrgMNFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");
	ubigint appendNewRecToRst(ListBrlyQFltOrgMNFlight& rst, BrlyQFltOrgMNFlight** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1VisStart = 0, const string ftmX1VisStart = "", const uint x1VisStop = 0, const string ftmX1VisStop = "", const uint xVisStart = 0, const string ftmXVisStart = "", const uint xVisStop = 0, const string ftmXVisStop = "");
	virtual void insertRst(ListBrlyQFltOrgMNFlight& rst);
	virtual void updateRec(BrlyQFltOrgMNFlight* rec);
	virtual void updateRst(ListBrlyQFltOrgMNFlight& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFltOrgMNFlight** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltOrgMNFlight& rst);
};

/**
  * MyBrlyQFltOrgMNFlight: C++ wrapper for table TblBrlyQFltOrgMNFlight (MySQL database)
  */
class MyTblBrlyQFltOrgMNFlight : public TblBrlyQFltOrgMNFlight, public MyTable {

public:
	MyTblBrlyQFltOrgMNFlight();
	~MyTblBrlyQFltOrgMNFlight();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltOrgMNFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltOrgMNFlight& rst);

	void insertRec(BrlyQFltOrgMNFlight* rec);
	void insertRst(ListBrlyQFltOrgMNFlight& rst);
	void updateRec(BrlyQFltOrgMNFlight* rec);
	void updateRst(ListBrlyQFltOrgMNFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltOrgMNFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltOrgMNFlight& rst);
};

/**
  * PgBrlyQFltOrgMNFlight: C++ wrapper for table TblBrlyQFltOrgMNFlight (PgSQL database)
  */
class PgTblBrlyQFltOrgMNFlight : public TblBrlyQFltOrgMNFlight, public PgTable {

public:
	PgTblBrlyQFltOrgMNFlight();
	~PgTblBrlyQFltOrgMNFlight();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltOrgMNFlight** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltOrgMNFlight& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltOrgMNFlight** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltOrgMNFlight& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltOrgMNFlight** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltOrgMNFlight& rst);

	void insertRec(BrlyQFltOrgMNFlight* rec);
	void insertRst(ListBrlyQFltOrgMNFlight& rst);
	void updateRec(BrlyQFltOrgMNFlight* rec);
	void updateRst(ListBrlyQFltOrgMNFlight& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltOrgMNFlight** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltOrgMNFlight& rst);
};

#endif

