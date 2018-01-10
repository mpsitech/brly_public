/**
  * \file BrlyQSelect.h
  * Dbs and XML wrapper for table TblBrlyQSelect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQSELECT_H
#define BRLYQSELECT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQSelect: record of TblBrlyQSelect
  */
class BrlyQSelect {

public:
	BrlyQSelect(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	uint ix;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQSelect: recordset of TblBrlyQSelect
  */
class ListBrlyQSelect {

public:
	ListBrlyQSelect();
	ListBrlyQSelect(const ListBrlyQSelect& src);
	~ListBrlyQSelect();

	void clear();
	unsigned int size() const;
	void append(BrlyQSelect* rec);

	ListBrlyQSelect& operator=(const ListBrlyQSelect& src);

public:
	vector<BrlyQSelect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQSelect: C++ wrapper for table TblBrlyQSelect
  */
class TblBrlyQSelect {

public:
	TblBrlyQSelect();
	virtual ~TblBrlyQSelect();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQSelect** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSelect& rst);

	virtual void insertRec(BrlyQSelect* rec);
	ubigint insertNewRec(BrlyQSelect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);
	ubigint appendNewRecToRst(ListBrlyQSelect& rst, BrlyQSelect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);
	virtual void insertRst(ListBrlyQSelect& rst);
	virtual void updateRec(BrlyQSelect* rec);
	virtual void updateRst(ListBrlyQSelect& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQSelect** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSelect& rst);
};

/**
  * MyBrlyQSelect: C++ wrapper for table TblBrlyQSelect (MySQL database)
  */
class MyTblBrlyQSelect : public TblBrlyQSelect, public MyTable {

public:
	MyTblBrlyQSelect();
	~MyTblBrlyQSelect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSelect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSelect& rst);

	void insertRec(BrlyQSelect* rec);
	void insertRst(ListBrlyQSelect& rst);
	void updateRec(BrlyQSelect* rec);
	void updateRst(ListBrlyQSelect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSelect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSelect& rst);
};

/**
  * PgBrlyQSelect: C++ wrapper for table TblBrlyQSelect (PgSQL database)
  */
class PgTblBrlyQSelect : public TblBrlyQSelect, public PgTable {

public:
	PgTblBrlyQSelect();
	~PgTblBrlyQSelect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSelect** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQSelect& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSelect** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSelect& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSelect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSelect& rst);

	void insertRec(BrlyQSelect* rec);
	void insertRst(ListBrlyQSelect& rst);
	void updateRec(BrlyQSelect* rec);
	void updateRst(ListBrlyQSelect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSelect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSelect& rst);
};

#endif

