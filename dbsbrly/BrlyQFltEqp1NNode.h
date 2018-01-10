/**
  * \file BrlyQFltEqp1NNode.h
  * Dbs and XML wrapper for table TblBrlyQFltEqp1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTEQP1NNODE_H
#define BRLYQFLTEQP1NNODE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltEqp1NNode: record of TblBrlyQFltEqp1NNode
  */
class BrlyQFltEqp1NNode {

public:
	BrlyQFltEqp1NNode(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQFltEqp1NNode: recordset of TblBrlyQFltEqp1NNode
  */
class ListBrlyQFltEqp1NNode {

public:
	ListBrlyQFltEqp1NNode();
	ListBrlyQFltEqp1NNode(const ListBrlyQFltEqp1NNode& src);
	~ListBrlyQFltEqp1NNode();

	void clear();
	unsigned int size() const;
	void append(BrlyQFltEqp1NNode* rec);

	ListBrlyQFltEqp1NNode& operator=(const ListBrlyQFltEqp1NNode& src);

public:
	vector<BrlyQFltEqp1NNode*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQFltEqp1NNode: C++ wrapper for table TblBrlyQFltEqp1NNode
  */
class TblBrlyQFltEqp1NNode {

public:
	TblBrlyQFltEqp1NNode();
	virtual ~TblBrlyQFltEqp1NNode();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQFltEqp1NNode** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltEqp1NNode& rst);

	virtual void insertRec(BrlyQFltEqp1NNode* rec);
	ubigint insertNewRec(BrlyQFltEqp1NNode** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQFltEqp1NNode& rst, BrlyQFltEqp1NNode** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQFltEqp1NNode& rst);
	virtual void updateRec(BrlyQFltEqp1NNode* rec);
	virtual void updateRst(ListBrlyQFltEqp1NNode& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQFltEqp1NNode** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltEqp1NNode& rst);
};

/**
  * MyBrlyQFltEqp1NNode: C++ wrapper for table TblBrlyQFltEqp1NNode (MySQL database)
  */
class MyTblBrlyQFltEqp1NNode : public TblBrlyQFltEqp1NNode, public MyTable {

public:
	MyTblBrlyQFltEqp1NNode();
	~MyTblBrlyQFltEqp1NNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltEqp1NNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltEqp1NNode& rst);

	void insertRec(BrlyQFltEqp1NNode* rec);
	void insertRst(ListBrlyQFltEqp1NNode& rst);
	void updateRec(BrlyQFltEqp1NNode* rec);
	void updateRst(ListBrlyQFltEqp1NNode& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltEqp1NNode** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltEqp1NNode& rst);
};

/**
  * PgBrlyQFltEqp1NNode: C++ wrapper for table TblBrlyQFltEqp1NNode (PgSQL database)
  */
class PgTblBrlyQFltEqp1NNode : public TblBrlyQFltEqp1NNode, public PgTable {

public:
	PgTblBrlyQFltEqp1NNode();
	~PgTblBrlyQFltEqp1NNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQFltEqp1NNode** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQFltEqp1NNode& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQFltEqp1NNode** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQFltEqp1NNode& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQFltEqp1NNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQFltEqp1NNode& rst);

	void insertRec(BrlyQFltEqp1NNode* rec);
	void insertRst(ListBrlyQFltEqp1NNode& rst);
	void updateRec(BrlyQFltEqp1NNode* rec);
	void updateRst(ListBrlyQFltEqp1NNode& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQFltEqp1NNode** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQFltEqp1NNode& rst);
};

#endif

