/**
  * \file BrlyQRegList.h
  * Dbs and XML wrapper for table TblBrlyQRegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQREGLIST_H
#define BRLYQREGLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRegList: record of TblBrlyQRegList
  */
class BrlyQRegList {

public:
	BrlyQRegList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint supRefBrlyMRegion = 0, const string stubSupRefBrlyMRegion = "", const uint ixVDst = 0, const string srefIxVDst = "", const string titIxVDst = "", const double toffset = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	string Title;
	ubigint supRefBrlyMRegion;
	string stubSupRefBrlyMRegion;
	uint ixVDst;
	string srefIxVDst;
	string titIxVDst;
	double toffset;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQRegList: recordset of TblBrlyQRegList
  */
class ListBrlyQRegList {

public:
	ListBrlyQRegList();
	ListBrlyQRegList(const ListBrlyQRegList& src);
	~ListBrlyQRegList();

	void clear();
	unsigned int size() const;
	void append(BrlyQRegList* rec);

	ListBrlyQRegList& operator=(const ListBrlyQRegList& src);

public:
	vector<BrlyQRegList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQRegList: C++ wrapper for table TblBrlyQRegList
  */
class TblBrlyQRegList {

public:
	TblBrlyQRegList();
	virtual ~TblBrlyQRegList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQRegList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegList& rst);

	virtual void insertRec(BrlyQRegList* rec);
	ubigint insertNewRec(BrlyQRegList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint supRefBrlyMRegion = 0, const string stubSupRefBrlyMRegion = "", const uint ixVDst = 0, const string srefIxVDst = "", const string titIxVDst = "", const double toffset = 0.0);
	ubigint appendNewRecToRst(ListBrlyQRegList& rst, BrlyQRegList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const string Title = "", const ubigint supRefBrlyMRegion = 0, const string stubSupRefBrlyMRegion = "", const uint ixVDst = 0, const string srefIxVDst = "", const string titIxVDst = "", const double toffset = 0.0);
	virtual void insertRst(ListBrlyQRegList& rst);
	virtual void updateRec(BrlyQRegList* rec);
	virtual void updateRst(ListBrlyQRegList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQRegList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegList& rst);
};

/**
  * MyBrlyQRegList: C++ wrapper for table TblBrlyQRegList (MySQL database)
  */
class MyTblBrlyQRegList : public TblBrlyQRegList, public MyTable {

public:
	MyTblBrlyQRegList();
	~MyTblBrlyQRegList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRegList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegList& rst);

	void insertRec(BrlyQRegList* rec);
	void insertRst(ListBrlyQRegList& rst);
	void updateRec(BrlyQRegList* rec);
	void updateRst(ListBrlyQRegList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRegList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegList& rst);
};

/**
  * PgBrlyQRegList: C++ wrapper for table TblBrlyQRegList (PgSQL database)
  */
class PgTblBrlyQRegList : public TblBrlyQRegList, public PgTable {

public:
	PgTblBrlyQRegList();
	~PgTblBrlyQRegList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRegList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQRegList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRegList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRegList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRegList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegList& rst);

	void insertRec(BrlyQRegList* rec);
	void insertRst(ListBrlyQRegList& rst);
	void updateRec(BrlyQRegList* rec);
	void updateRst(ListBrlyQRegList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRegList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegList& rst);
};

#endif

