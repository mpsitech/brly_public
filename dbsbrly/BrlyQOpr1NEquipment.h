/**
  * \file BrlyQOpr1NEquipment.h
  * Dbs and XML wrapper for table TblBrlyQOpr1NEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQOPR1NEQUIPMENT_H
#define BRLYQOPR1NEQUIPMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQOpr1NEquipment: record of TblBrlyQOpr1NEquipment
  */
class BrlyQOpr1NEquipment {

public:
	BrlyQOpr1NEquipment(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQOpr1NEquipment: recordset of TblBrlyQOpr1NEquipment
  */
class ListBrlyQOpr1NEquipment {

public:
	ListBrlyQOpr1NEquipment();
	ListBrlyQOpr1NEquipment(const ListBrlyQOpr1NEquipment& src);
	~ListBrlyQOpr1NEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyQOpr1NEquipment* rec);

	ListBrlyQOpr1NEquipment& operator=(const ListBrlyQOpr1NEquipment& src);

public:
	vector<BrlyQOpr1NEquipment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQOpr1NEquipment: C++ wrapper for table TblBrlyQOpr1NEquipment
  */
class TblBrlyQOpr1NEquipment {

public:
	TblBrlyQOpr1NEquipment();
	virtual ~TblBrlyQOpr1NEquipment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQOpr1NEquipment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQOpr1NEquipment& rst);

	virtual void insertRec(BrlyQOpr1NEquipment* rec);
	ubigint insertNewRec(BrlyQOpr1NEquipment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQOpr1NEquipment& rst, BrlyQOpr1NEquipment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQOpr1NEquipment& rst);
	virtual void updateRec(BrlyQOpr1NEquipment* rec);
	virtual void updateRst(ListBrlyQOpr1NEquipment& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQOpr1NEquipment** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQOpr1NEquipment& rst);
};

/**
  * MyBrlyQOpr1NEquipment: C++ wrapper for table TblBrlyQOpr1NEquipment (MySQL database)
  */
class MyTblBrlyQOpr1NEquipment : public TblBrlyQOpr1NEquipment, public MyTable {

public:
	MyTblBrlyQOpr1NEquipment();
	~MyTblBrlyQOpr1NEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQOpr1NEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQOpr1NEquipment& rst);

	void insertRec(BrlyQOpr1NEquipment* rec);
	void insertRst(ListBrlyQOpr1NEquipment& rst);
	void updateRec(BrlyQOpr1NEquipment* rec);
	void updateRst(ListBrlyQOpr1NEquipment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQOpr1NEquipment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQOpr1NEquipment& rst);
};

/**
  * PgBrlyQOpr1NEquipment: C++ wrapper for table TblBrlyQOpr1NEquipment (PgSQL database)
  */
class PgTblBrlyQOpr1NEquipment : public TblBrlyQOpr1NEquipment, public PgTable {

public:
	PgTblBrlyQOpr1NEquipment();
	~PgTblBrlyQOpr1NEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQOpr1NEquipment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQOpr1NEquipment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQOpr1NEquipment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQOpr1NEquipment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQOpr1NEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQOpr1NEquipment& rst);

	void insertRec(BrlyQOpr1NEquipment* rec);
	void insertRst(ListBrlyQOpr1NEquipment& rst);
	void updateRec(BrlyQOpr1NEquipment* rec);
	void updateRst(ListBrlyQOpr1NEquipment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQOpr1NEquipment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQOpr1NEquipment& rst);
};

#endif

