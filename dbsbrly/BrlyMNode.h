/**
  * \file BrlyMNode.h
  * database access for table TblBrlyMNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMNODE_H
#define BRLYMNODE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyMNode: record of TblBrlyMNode
  */
class BrlyMNode {

public:
	BrlyMNode(const ubigint ref = 0, const ubigint refBrlyMRelay = 0, const ubigint supRefBrlyMNode = 0, const usmallint supLvl = 0, const uint supNum = 0, const ubigint refBrlyMEquipment = 0);

public:
	ubigint ref;
	ubigint refBrlyMRelay;
	ubigint supRefBrlyMNode;
	usmallint supLvl;
	uint supNum;
	ubigint refBrlyMEquipment;

public:
	bool operator==(const BrlyMNode& comp);
	bool operator!=(const BrlyMNode& comp);
};

/**
  * ListBrlyMNode: recordset of TblBrlyMNode
  */
class ListBrlyMNode {

public:
	ListBrlyMNode();
	ListBrlyMNode(const ListBrlyMNode& src);
	~ListBrlyMNode();

	void clear();
	unsigned int size() const;
	void append(BrlyMNode* rec);

	BrlyMNode* operator[](const uint ix);
	ListBrlyMNode& operator=(const ListBrlyMNode& src);
	bool operator==(const ListBrlyMNode& comp);
	bool operator!=(const ListBrlyMNode& comp);

public:
	vector<BrlyMNode*> nodes;
};

/**
  * TblBrlyMNode: C++ wrapper for table TblBrlyMNode
  */
class TblBrlyMNode {

public:

public:
	TblBrlyMNode();
	virtual ~TblBrlyMNode();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMNode** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMNode& rst);

	virtual void insertRec(BrlyMNode* rec);
	ubigint insertNewRec(BrlyMNode** rec = NULL, const ubigint refBrlyMRelay = 0, const ubigint supRefBrlyMNode = 0, const usmallint supLvl = 0, const uint supNum = 0, const ubigint refBrlyMEquipment = 0);
	ubigint appendNewRecToRst(ListBrlyMNode& rst, BrlyMNode** rec = NULL, const ubigint refBrlyMRelay = 0, const ubigint supRefBrlyMNode = 0, const usmallint supLvl = 0, const uint supNum = 0, const ubigint refBrlyMEquipment = 0);
	virtual void insertRst(ListBrlyMNode& rst, bool transact = false);
	virtual void updateRec(BrlyMNode* rec);
	virtual void updateRst(ListBrlyMNode& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMNode** rec);
	virtual bool confirmByRef(ubigint ref);
	virtual ubigint loadRefsBySup(ubigint supRefBrlyMNode, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByRly(ubigint refBrlyMRelay, const bool append, ListBrlyMNode& rst);
	virtual ubigint loadRstBySup(ubigint supRefBrlyMNode, const bool append, ListBrlyMNode& rst);
	virtual bool loadSupByRef(ubigint ref, ubigint& supRefBrlyMNode);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMNode& rst);
	ubigint loadHrefsup(ubigint ref, vector<ubigint>& refs);
	ubigint loadHrefsdown(ubigint ref, const bool append, vector<ubigint>& refs, unsigned int firstix = 0, unsigned int lastix = 0);
	ubigint loadHrstup(ubigint ref, ListBrlyMNode& rst);
	ubigint loadHrstdown(ubigint ref, const bool append, ListBrlyMNode& rst, unsigned int firstix = 0, unsigned int lastix = 0);
};

/**
  * MyBrlyMNode: C++ wrapper for table TblBrlyMNode (MySQL database)
  */
class MyTblBrlyMNode : public TblBrlyMNode, public MyTable {

public:
	MyTblBrlyMNode();
	~MyTblBrlyMNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMNode& rst);

	void insertRec(BrlyMNode* rec);
	void insertRst(ListBrlyMNode& rst, bool transact = false);
	void updateRec(BrlyMNode* rec);
	void updateRst(ListBrlyMNode& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMNode** rec);
	bool confirmByRef(ubigint ref);
	ubigint loadRefsBySup(ubigint supRefBrlyMNode, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRly(ubigint refBrlyMRelay, const bool append, ListBrlyMNode& rst);
	ubigint loadRstBySup(ubigint supRefBrlyMNode, const bool append, ListBrlyMNode& rst);
	bool loadSupByRef(ubigint ref, ubigint& supRefBrlyMNode);
};

/**
  * PgBrlyMNode: C++ wrapper for table TblBrlyMNode (PgSQL database)
  */
class PgTblBrlyMNode : public TblBrlyMNode, public PgTable {

public:
	PgTblBrlyMNode();
	~PgTblBrlyMNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMNode** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMNode& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMNode** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMNode& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMNode& rst);

	void insertRec(BrlyMNode* rec);
	void insertRst(ListBrlyMNode& rst, bool transact = false);
	void updateRec(BrlyMNode* rec);
	void updateRst(ListBrlyMNode& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMNode** rec);
	bool confirmByRef(ubigint ref);
	ubigint loadRefsBySup(ubigint supRefBrlyMNode, const bool append, vector<ubigint>& refs);
	ubigint loadRstByRly(ubigint refBrlyMRelay, const bool append, ListBrlyMNode& rst);
	ubigint loadRstBySup(ubigint supRefBrlyMNode, const bool append, ListBrlyMNode& rst);
	bool loadSupByRef(ubigint ref, ubigint& supRefBrlyMNode);
};

#endif

