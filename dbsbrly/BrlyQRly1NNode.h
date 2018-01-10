/**
  * \file BrlyQRly1NNode.h
  * Dbs and XML wrapper for table TblBrlyQRly1NNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQRLY1NNODE_H
#define BRLYQRLY1NNODE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQRly1NNode: record of TblBrlyQRly1NNode
  */
class BrlyQRly1NNode {

public:
	BrlyQRly1NNode(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQRly1NNode: recordset of TblBrlyQRly1NNode
  */
class ListBrlyQRly1NNode {

public:
	ListBrlyQRly1NNode();
	ListBrlyQRly1NNode(const ListBrlyQRly1NNode& src);
	~ListBrlyQRly1NNode();

	void clear();
	unsigned int size() const;
	void append(BrlyQRly1NNode* rec);

	ListBrlyQRly1NNode& operator=(const ListBrlyQRly1NNode& src);

public:
	vector<BrlyQRly1NNode*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQRly1NNode: C++ wrapper for table TblBrlyQRly1NNode
  */
class TblBrlyQRly1NNode {

public:
	TblBrlyQRly1NNode();
	virtual ~TblBrlyQRly1NNode();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQRly1NNode** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRly1NNode& rst);

	virtual void insertRec(BrlyQRly1NNode* rec);
	ubigint insertNewRec(BrlyQRly1NNode** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQRly1NNode& rst, BrlyQRly1NNode** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQRly1NNode& rst);
	virtual void updateRec(BrlyQRly1NNode* rec);
	virtual void updateRst(ListBrlyQRly1NNode& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQRly1NNode** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRly1NNode& rst);
};

/**
  * MyBrlyQRly1NNode: C++ wrapper for table TblBrlyQRly1NNode (MySQL database)
  */
class MyTblBrlyQRly1NNode : public TblBrlyQRly1NNode, public MyTable {

public:
	MyTblBrlyQRly1NNode();
	~MyTblBrlyQRly1NNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRly1NNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRly1NNode& rst);

	void insertRec(BrlyQRly1NNode* rec);
	void insertRst(ListBrlyQRly1NNode& rst);
	void updateRec(BrlyQRly1NNode* rec);
	void updateRst(ListBrlyQRly1NNode& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRly1NNode** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRly1NNode& rst);
};

/**
  * PgBrlyQRly1NNode: C++ wrapper for table TblBrlyQRly1NNode (PgSQL database)
  */
class PgTblBrlyQRly1NNode : public TblBrlyQRly1NNode, public PgTable {

public:
	PgTblBrlyQRly1NNode();
	~PgTblBrlyQRly1NNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQRly1NNode** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQRly1NNode& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQRly1NNode** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQRly1NNode& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQRly1NNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQRly1NNode& rst);

	void insertRec(BrlyQRly1NNode* rec);
	void insertRst(ListBrlyQRly1NNode& rst);
	void updateRec(BrlyQRly1NNode* rec);
	void updateRst(ListBrlyQRly1NNode& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQRly1NNode** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQRly1NNode& rst);
};

#endif

