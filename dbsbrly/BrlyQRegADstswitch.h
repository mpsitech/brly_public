/**
  * \file BrlyQRegADstswitch.h
  * Dbs and XML wrapper for table TblBrlyQRegADstswitch (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQREGADSTSWITCH_H
#define BRLYQREGADSTSWITCH_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRegADstswitch: record of TblBrlyQRegADstswitch
  */
class BrlyQRegADstswitch {

public:
	BrlyQRegADstswitch(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint startd;
	string ftmStartd;
	uint startt;
	string ftmStartt;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQRegADstswitch: recordset of TblBrlyQRegADstswitch
  */
class ListBrlyQRegADstswitch {

public:
	ListBrlyQRegADstswitch();
	ListBrlyQRegADstswitch(const ListBrlyQRegADstswitch& src);
	~ListBrlyQRegADstswitch();

	void clear();
	unsigned int size() const;
	void append(BrlyQRegADstswitch* rec);

	ListBrlyQRegADstswitch& operator=(const ListBrlyQRegADstswitch& src);

public:
	vector<BrlyQRegADstswitch*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQRegADstswitch: C++ wrapper for table TblBrlyQRegADstswitch
  */
class TblBrlyQRegADstswitch {

public:
	TblBrlyQRegADstswitch();
	virtual ~TblBrlyQRegADstswitch();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQRegADstswitch** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegADstswitch& rst);

	virtual void insertRec(BrlyQRegADstswitch* rec);
	ubigint insertNewRec(BrlyQRegADstswitch** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "");
	ubigint appendNewRecToRst(ListBrlyQRegADstswitch& rst, BrlyQRegADstswitch** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint startd = 0, const string ftmStartd = "", const uint startt = 0, const string ftmStartt = "");
	virtual void insertRst(ListBrlyQRegADstswitch& rst);
	virtual void updateRec(BrlyQRegADstswitch* rec);
	virtual void updateRst(ListBrlyQRegADstswitch& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQRegADstswitch** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegADstswitch& rst);
};

/**
  * MyBrlyQRegADstswitch: C++ wrapper for table TblBrlyQRegADstswitch (MySQL database)
  */
class MyTblBrlyQRegADstswitch : public TblBrlyQRegADstswitch, public MyTable {

public:
	MyTblBrlyQRegADstswitch();
	~MyTblBrlyQRegADstswitch();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRegADstswitch** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegADstswitch& rst);

	void insertRec(BrlyQRegADstswitch* rec);
	void insertRst(ListBrlyQRegADstswitch& rst);
	void updateRec(BrlyQRegADstswitch* rec);
	void updateRst(ListBrlyQRegADstswitch& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRegADstswitch** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegADstswitch& rst);
};

/**
  * PgBrlyQRegADstswitch: C++ wrapper for table TblBrlyQRegADstswitch (PgSQL database)
  */
class PgTblBrlyQRegADstswitch : public TblBrlyQRegADstswitch, public PgTable {

public:
	PgTblBrlyQRegADstswitch();
	~PgTblBrlyQRegADstswitch();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRegADstswitch** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQRegADstswitch& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRegADstswitch** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRegADstswitch& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRegADstswitch** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRegADstswitch& rst);

	void insertRec(BrlyQRegADstswitch* rec);
	void insertRst(ListBrlyQRegADstswitch& rst);
	void updateRec(BrlyQRegADstswitch* rec);
	void updateRst(ListBrlyQRegADstswitch& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRegADstswitch** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRegADstswitch& rst);
};

#endif

