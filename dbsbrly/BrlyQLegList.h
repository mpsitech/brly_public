/**
  * \file BrlyQLegList.h
  * Dbs and XML wrapper for table TblBrlyQLegList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLEGLIST_H
#define BRLYQLEGLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLegList: record of TblBrlyQLegList
  */
class BrlyQLegList {

public:
	BrlyQLegList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint bgnRefBrlyMLocation = 0, const string stubBgnRefBrlyMLocation = "", const ubigint endRefBrlyMLocation = 0, const string stubEndRefBrlyMLocation = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const double alt = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint bgnRefBrlyMLocation;
	string stubBgnRefBrlyMLocation;
	ubigint endRefBrlyMLocation;
	string stubEndRefBrlyMLocation;
	uint ixVBasetype;
	string srefIxVBasetype;
	string titIxVBasetype;
	double alt;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLegList: recordset of TblBrlyQLegList
  */
class ListBrlyQLegList {

public:
	ListBrlyQLegList();
	ListBrlyQLegList(const ListBrlyQLegList& src);
	~ListBrlyQLegList();

	void clear();
	unsigned int size() const;
	void append(BrlyQLegList* rec);

	ListBrlyQLegList& operator=(const ListBrlyQLegList& src);

public:
	vector<BrlyQLegList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLegList: C++ wrapper for table TblBrlyQLegList
  */
class TblBrlyQLegList {

public:
	TblBrlyQLegList();
	virtual ~TblBrlyQLegList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLegList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegList& rst);

	virtual void insertRec(BrlyQLegList* rec);
	ubigint insertNewRec(BrlyQLegList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint bgnRefBrlyMLocation = 0, const string stubBgnRefBrlyMLocation = "", const ubigint endRefBrlyMLocation = 0, const string stubEndRefBrlyMLocation = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const double alt = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLegList& rst, BrlyQLegList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint bgnRefBrlyMLocation = 0, const string stubBgnRefBrlyMLocation = "", const ubigint endRefBrlyMLocation = 0, const string stubEndRefBrlyMLocation = "", const uint ixVBasetype = 0, const string srefIxVBasetype = "", const string titIxVBasetype = "", const double alt = 0.0);
	virtual void insertRst(ListBrlyQLegList& rst);
	virtual void updateRec(BrlyQLegList* rec);
	virtual void updateRst(ListBrlyQLegList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLegList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegList& rst);
};

/**
  * MyBrlyQLegList: C++ wrapper for table TblBrlyQLegList (MySQL database)
  */
class MyTblBrlyQLegList : public TblBrlyQLegList, public MyTable {

public:
	MyTblBrlyQLegList();
	~MyTblBrlyQLegList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegList& rst);

	void insertRec(BrlyQLegList* rec);
	void insertRst(ListBrlyQLegList& rst);
	void updateRec(BrlyQLegList* rec);
	void updateRst(ListBrlyQLegList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegList& rst);
};

/**
  * PgBrlyQLegList: C++ wrapper for table TblBrlyQLegList (PgSQL database)
  */
class PgTblBrlyQLegList : public TblBrlyQLegList, public PgTable {

public:
	PgTblBrlyQLegList();
	~PgTblBrlyQLegList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLegList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLegList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLegList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLegList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLegList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLegList& rst);

	void insertRec(BrlyQLegList* rec);
	void insertRst(ListBrlyQLegList& rst);
	void updateRec(BrlyQLegList* rec);
	void updateRst(ListBrlyQLegList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLegList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLegList& rst);
};

#endif

