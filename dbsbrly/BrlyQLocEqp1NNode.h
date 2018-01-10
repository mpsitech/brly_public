/**
  * \file BrlyQLocEqp1NNode.h
  * Dbs and XML wrapper for table TblBrlyQLocEqp1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCEQP1NNODE_H
#define BRLYQLOCEQP1NNODE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocEqp1NNode: record of TblBrlyQLocEqp1NNode
  */
class BrlyQLocEqp1NNode {

public:
	BrlyQLocEqp1NNode(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQLocEqp1NNode: recordset of TblBrlyQLocEqp1NNode
  */
class ListBrlyQLocEqp1NNode {

public:
	ListBrlyQLocEqp1NNode();
	ListBrlyQLocEqp1NNode(const ListBrlyQLocEqp1NNode& src);
	~ListBrlyQLocEqp1NNode();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocEqp1NNode* rec);

	ListBrlyQLocEqp1NNode& operator=(const ListBrlyQLocEqp1NNode& src);

public:
	vector<BrlyQLocEqp1NNode*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocEqp1NNode: C++ wrapper for table TblBrlyQLocEqp1NNode
  */
class TblBrlyQLocEqp1NNode {

public:
	TblBrlyQLocEqp1NNode();
	virtual ~TblBrlyQLocEqp1NNode();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocEqp1NNode** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEqp1NNode& rst);

	virtual void insertRec(BrlyQLocEqp1NNode* rec);
	ubigint insertNewRec(BrlyQLocEqp1NNode** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQLocEqp1NNode& rst, BrlyQLocEqp1NNode** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQLocEqp1NNode& rst);
	virtual void updateRec(BrlyQLocEqp1NNode* rec);
	virtual void updateRst(ListBrlyQLocEqp1NNode& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocEqp1NNode** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEqp1NNode& rst);
};

/**
  * MyBrlyQLocEqp1NNode: C++ wrapper for table TblBrlyQLocEqp1NNode (MySQL database)
  */
class MyTblBrlyQLocEqp1NNode : public TblBrlyQLocEqp1NNode, public MyTable {

public:
	MyTblBrlyQLocEqp1NNode();
	~MyTblBrlyQLocEqp1NNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocEqp1NNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEqp1NNode& rst);

	void insertRec(BrlyQLocEqp1NNode* rec);
	void insertRst(ListBrlyQLocEqp1NNode& rst);
	void updateRec(BrlyQLocEqp1NNode* rec);
	void updateRst(ListBrlyQLocEqp1NNode& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocEqp1NNode** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEqp1NNode& rst);
};

/**
  * PgBrlyQLocEqp1NNode: C++ wrapper for table TblBrlyQLocEqp1NNode (PgSQL database)
  */
class PgTblBrlyQLocEqp1NNode : public TblBrlyQLocEqp1NNode, public PgTable {

public:
	PgTblBrlyQLocEqp1NNode();
	~PgTblBrlyQLocEqp1NNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocEqp1NNode** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocEqp1NNode& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocEqp1NNode** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocEqp1NNode& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocEqp1NNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocEqp1NNode& rst);

	void insertRec(BrlyQLocEqp1NNode* rec);
	void insertRst(ListBrlyQLocEqp1NNode& rst);
	void updateRec(BrlyQLocEqp1NNode* rec);
	void updateRst(ListBrlyQLocEqp1NNode& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocEqp1NNode** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocEqp1NNode& rst);
};

#endif

