/**
  * \file BrlyQConMapNode.h
  * Dbs and XML wrapper for table TblBrlyQConMapNode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPNODE_H
#define BRLYQCONMAPNODE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapNode: record of TblBrlyQConMapNode
  */
class BrlyQConMapNode {

public:
	BrlyQConMapNode(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const ubigint refBrlyMRelay = 0, const ubigint supRefBrlyMNode = 0, const ubigint refBrlyMEquipment = 0, const int jnumRly = 0, const double x0 = 0.0, const double y0 = 0.0, const double u0 = 0.0, const double v0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const double du = 0.0, const double dv = 0.0, const int dt = 0);

public:
	ubigint qref;
	bool qwr;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	ubigint refBrlyMRelay;
	ubigint supRefBrlyMNode;
	ubigint refBrlyMEquipment;
	int jnumRly;
	double x0;
	double y0;
	double u0;
	double v0;
	int t0;
	double dx;
	double dy;
	double du;
	double dv;
	int dt;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConMapNode: recordset of TblBrlyQConMapNode
  */
class ListBrlyQConMapNode {

public:
	ListBrlyQConMapNode();
	ListBrlyQConMapNode(const ListBrlyQConMapNode& src);
	~ListBrlyQConMapNode();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapNode* rec);

	ListBrlyQConMapNode& operator=(const ListBrlyQConMapNode& src);

public:
	vector<BrlyQConMapNode*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConMapNode: C++ wrapper for table TblBrlyQConMapNode
  */
class TblBrlyQConMapNode {

public:
	TblBrlyQConMapNode();
	virtual ~TblBrlyQConMapNode();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConMapNode** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapNode& rst);

	virtual void insertRec(BrlyQConMapNode* rec);
	ubigint insertNewRec(BrlyQConMapNode** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const ubigint refBrlyMRelay = 0, const ubigint supRefBrlyMNode = 0, const ubigint refBrlyMEquipment = 0, const int jnumRly = 0, const double x0 = 0.0, const double y0 = 0.0, const double u0 = 0.0, const double v0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const double du = 0.0, const double dv = 0.0, const int dt = 0);
	ubigint appendNewRecToRst(ListBrlyQConMapNode& rst, BrlyQConMapNode** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const ubigint refBrlyMRelay = 0, const ubigint supRefBrlyMNode = 0, const ubigint refBrlyMEquipment = 0, const int jnumRly = 0, const double x0 = 0.0, const double y0 = 0.0, const double u0 = 0.0, const double v0 = 0.0, const int t0 = 0, const double dx = 0.0, const double dy = 0.0, const double du = 0.0, const double dv = 0.0, const int dt = 0);
	virtual void insertRst(ListBrlyQConMapNode& rst);
	virtual void updateRec(BrlyQConMapNode* rec);
	virtual void updateRst(ListBrlyQConMapNode& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConMapNode** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapNode& rst);
};

/**
  * MyBrlyQConMapNode: C++ wrapper for table TblBrlyQConMapNode (MySQL database)
  */
class MyTblBrlyQConMapNode : public TblBrlyQConMapNode, public MyTable {

public:
	MyTblBrlyQConMapNode();
	~MyTblBrlyQConMapNode();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapNode& rst);

	void insertRec(BrlyQConMapNode* rec);
	void insertRst(ListBrlyQConMapNode& rst);
	void updateRec(BrlyQConMapNode* rec);
	void updateRst(ListBrlyQConMapNode& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapNode** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapNode& rst);
};

/**
  * PgBrlyQConMapNode: C++ wrapper for table TblBrlyQConMapNode (PgSQL database)
  */
class PgTblBrlyQConMapNode : public TblBrlyQConMapNode, public PgTable {

public:
	PgTblBrlyQConMapNode();
	~PgTblBrlyQConMapNode();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapNode** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapNode& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapNode** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapNode& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapNode** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapNode& rst);

	void insertRec(BrlyQConMapNode* rec);
	void insertRst(ListBrlyQConMapNode& rst);
	void updateRec(BrlyQConMapNode* rec);
	void updateRst(ListBrlyQConMapNode& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapNode** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapNode& rst);
};

#endif

