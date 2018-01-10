/**
  * \file BrlyQPreselect.h
  * Dbs and XML wrapper for table TblBrlyQPreselect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPRESELECT_H
#define BRLYQPRESELECT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPreselect: record of TblBrlyQPreselect
  */
class BrlyQPreselect {

public:
	BrlyQPreselect(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQPreselect: recordset of TblBrlyQPreselect
  */
class ListBrlyQPreselect {

public:
	ListBrlyQPreselect();
	ListBrlyQPreselect(const ListBrlyQPreselect& src);
	~ListBrlyQPreselect();

	void clear();
	unsigned int size() const;
	void append(BrlyQPreselect* rec);

	ListBrlyQPreselect& operator=(const ListBrlyQPreselect& src);

public:
	vector<BrlyQPreselect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQPreselect: C++ wrapper for table TblBrlyQPreselect
  */
class TblBrlyQPreselect {

public:
	TblBrlyQPreselect();
	virtual ~TblBrlyQPreselect();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQPreselect** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPreselect& rst);

	virtual void insertRec(BrlyQPreselect* rec);
	ubigint insertNewRec(BrlyQPreselect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);
	ubigint appendNewRecToRst(ListBrlyQPreselect& rst, BrlyQPreselect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);
	virtual void insertRst(ListBrlyQPreselect& rst);
	virtual void updateRec(BrlyQPreselect* rec);
	virtual void updateRst(ListBrlyQPreselect& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQPreselect** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPreselect& rst);
};

/**
  * MyBrlyQPreselect: C++ wrapper for table TblBrlyQPreselect (MySQL database)
  */
class MyTblBrlyQPreselect : public TblBrlyQPreselect, public MyTable {

public:
	MyTblBrlyQPreselect();
	~MyTblBrlyQPreselect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPreselect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPreselect& rst);

	void insertRec(BrlyQPreselect* rec);
	void insertRst(ListBrlyQPreselect& rst);
	void updateRec(BrlyQPreselect* rec);
	void updateRst(ListBrlyQPreselect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPreselect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPreselect& rst);
};

/**
  * PgBrlyQPreselect: C++ wrapper for table TblBrlyQPreselect (PgSQL database)
  */
class PgTblBrlyQPreselect : public TblBrlyQPreselect, public PgTable {

public:
	PgTblBrlyQPreselect();
	~PgTblBrlyQPreselect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPreselect** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQPreselect& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPreselect** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPreselect& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPreselect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPreselect& rst);

	void insertRec(BrlyQPreselect* rec);
	void insertRst(ListBrlyQPreselect& rst);
	void updateRec(BrlyQPreselect* rec);
	void updateRst(ListBrlyQPreselect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPreselect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPreselect& rst);
};

#endif

