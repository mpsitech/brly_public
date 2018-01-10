/**
  * \file BrlyQPrsList.h
  * Dbs and XML wrapper for table TblBrlyQPrsList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPRSLIST_H
#define BRLYQPRSLIST_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPrsList: record of TblBrlyQPrsList
  */
class BrlyQPrsList {

public:
	BrlyQPrsList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string telVal = "", const string emlVal = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string Title;
	string Firstname;
	string Lastname;
	ubigint grp;
	string stubGrp;
	ubigint own;
	string stubOwn;
	uint ixVSex;
	string srefIxVSex;
	string titIxVSex;
	string telVal;
	string emlVal;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQPrsList: recordset of TblBrlyQPrsList
  */
class ListBrlyQPrsList {

public:
	ListBrlyQPrsList();
	ListBrlyQPrsList(const ListBrlyQPrsList& src);
	~ListBrlyQPrsList();

	void clear();
	unsigned int size() const;
	void append(BrlyQPrsList* rec);

	ListBrlyQPrsList& operator=(const ListBrlyQPrsList& src);

public:
	vector<BrlyQPrsList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQPrsList: C++ wrapper for table TblBrlyQPrsList
  */
class TblBrlyQPrsList {

public:
	TblBrlyQPrsList();
	virtual ~TblBrlyQPrsList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQPrsList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPrsList& rst);

	virtual void insertRec(BrlyQPrsList* rec);
	ubigint insertNewRec(BrlyQPrsList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string telVal = "", const string emlVal = "");
	ubigint appendNewRecToRst(ListBrlyQPrsList& rst, BrlyQPrsList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string Title = "", const string Firstname = "", const string Lastname = "", const ubigint grp = 0, const string stubGrp = "", const ubigint own = 0, const string stubOwn = "", const uint ixVSex = 0, const string srefIxVSex = "", const string titIxVSex = "", const string telVal = "", const string emlVal = "");
	virtual void insertRst(ListBrlyQPrsList& rst);
	virtual void updateRec(BrlyQPrsList* rec);
	virtual void updateRst(ListBrlyQPrsList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQPrsList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPrsList& rst);
};

/**
  * MyBrlyQPrsList: C++ wrapper for table TblBrlyQPrsList (MySQL database)
  */
class MyTblBrlyQPrsList : public TblBrlyQPrsList, public MyTable {

public:
	MyTblBrlyQPrsList();
	~MyTblBrlyQPrsList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPrsList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPrsList& rst);

	void insertRec(BrlyQPrsList* rec);
	void insertRst(ListBrlyQPrsList& rst);
	void updateRec(BrlyQPrsList* rec);
	void updateRst(ListBrlyQPrsList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPrsList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPrsList& rst);
};

/**
  * PgBrlyQPrsList: C++ wrapper for table TblBrlyQPrsList (PgSQL database)
  */
class PgTblBrlyQPrsList : public TblBrlyQPrsList, public PgTable {

public:
	PgTblBrlyQPrsList();
	~PgTblBrlyQPrsList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPrsList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQPrsList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPrsList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPrsList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPrsList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPrsList& rst);

	void insertRec(BrlyQPrsList* rec);
	void insertRst(ListBrlyQPrsList& rst);
	void updateRec(BrlyQPrsList* rec);
	void updateRst(ListBrlyQPrsList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPrsList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPrsList& rst);
};

#endif

