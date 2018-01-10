/**
  * \file BrlyQReg1NLocation.h
  * Dbs and XML wrapper for table TblBrlyQReg1NLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQREG1NLOCATION_H
#define BRLYQREG1NLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQReg1NLocation: record of TblBrlyQReg1NLocation
  */
class BrlyQReg1NLocation {

public:
	BrlyQReg1NLocation(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQReg1NLocation: recordset of TblBrlyQReg1NLocation
  */
class ListBrlyQReg1NLocation {

public:
	ListBrlyQReg1NLocation();
	ListBrlyQReg1NLocation(const ListBrlyQReg1NLocation& src);
	~ListBrlyQReg1NLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQReg1NLocation* rec);

	ListBrlyQReg1NLocation& operator=(const ListBrlyQReg1NLocation& src);

public:
	vector<BrlyQReg1NLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQReg1NLocation: C++ wrapper for table TblBrlyQReg1NLocation
  */
class TblBrlyQReg1NLocation {

public:
	TblBrlyQReg1NLocation();
	virtual ~TblBrlyQReg1NLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQReg1NLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQReg1NLocation& rst);

	virtual void insertRec(BrlyQReg1NLocation* rec);
	ubigint insertNewRec(BrlyQReg1NLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQReg1NLocation& rst, BrlyQReg1NLocation** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQReg1NLocation& rst);
	virtual void updateRec(BrlyQReg1NLocation* rec);
	virtual void updateRst(ListBrlyQReg1NLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQReg1NLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQReg1NLocation& rst);
};

/**
  * MyBrlyQReg1NLocation: C++ wrapper for table TblBrlyQReg1NLocation (MySQL database)
  */
class MyTblBrlyQReg1NLocation : public TblBrlyQReg1NLocation, public MyTable {

public:
	MyTblBrlyQReg1NLocation();
	~MyTblBrlyQReg1NLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQReg1NLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQReg1NLocation& rst);

	void insertRec(BrlyQReg1NLocation* rec);
	void insertRst(ListBrlyQReg1NLocation& rst);
	void updateRec(BrlyQReg1NLocation* rec);
	void updateRst(ListBrlyQReg1NLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQReg1NLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQReg1NLocation& rst);
};

/**
  * PgBrlyQReg1NLocation: C++ wrapper for table TblBrlyQReg1NLocation (PgSQL database)
  */
class PgTblBrlyQReg1NLocation : public TblBrlyQReg1NLocation, public PgTable {

public:
	PgTblBrlyQReg1NLocation();
	~PgTblBrlyQReg1NLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQReg1NLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQReg1NLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQReg1NLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQReg1NLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQReg1NLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQReg1NLocation& rst);

	void insertRec(BrlyQReg1NLocation* rec);
	void insertRst(ListBrlyQReg1NLocation& rst);
	void updateRec(BrlyQReg1NLocation* rec);
	void updateRst(ListBrlyQReg1NLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQReg1NLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQReg1NLocation& rst);
};

#endif

