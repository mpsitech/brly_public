/**
  * \file BrlyQPty1NEquipment.h
  * Dbs and XML wrapper for table TblBrlyQPty1NEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQPTY1NEQUIPMENT_H
#define BRLYQPTY1NEQUIPMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQPty1NEquipment: record of TblBrlyQPty1NEquipment
  */
class BrlyQPty1NEquipment {

public:
	BrlyQPty1NEquipment(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListBrlyQPty1NEquipment: recordset of TblBrlyQPty1NEquipment
  */
class ListBrlyQPty1NEquipment {

public:
	ListBrlyQPty1NEquipment();
	ListBrlyQPty1NEquipment(const ListBrlyQPty1NEquipment& src);
	~ListBrlyQPty1NEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyQPty1NEquipment* rec);

	ListBrlyQPty1NEquipment& operator=(const ListBrlyQPty1NEquipment& src);

public:
	vector<BrlyQPty1NEquipment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQPty1NEquipment: C++ wrapper for table TblBrlyQPty1NEquipment
  */
class TblBrlyQPty1NEquipment {

public:
	TblBrlyQPty1NEquipment();
	virtual ~TblBrlyQPty1NEquipment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQPty1NEquipment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPty1NEquipment& rst);

	virtual void insertRec(BrlyQPty1NEquipment* rec);
	ubigint insertNewRec(BrlyQPty1NEquipment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListBrlyQPty1NEquipment& rst, BrlyQPty1NEquipment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListBrlyQPty1NEquipment& rst);
	virtual void updateRec(BrlyQPty1NEquipment* rec);
	virtual void updateRst(ListBrlyQPty1NEquipment& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQPty1NEquipment** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPty1NEquipment& rst);
};

/**
  * MyBrlyQPty1NEquipment: C++ wrapper for table TblBrlyQPty1NEquipment (MySQL database)
  */
class MyTblBrlyQPty1NEquipment : public TblBrlyQPty1NEquipment, public MyTable {

public:
	MyTblBrlyQPty1NEquipment();
	~MyTblBrlyQPty1NEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPty1NEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPty1NEquipment& rst);

	void insertRec(BrlyQPty1NEquipment* rec);
	void insertRst(ListBrlyQPty1NEquipment& rst);
	void updateRec(BrlyQPty1NEquipment* rec);
	void updateRst(ListBrlyQPty1NEquipment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPty1NEquipment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPty1NEquipment& rst);
};

/**
  * PgBrlyQPty1NEquipment: C++ wrapper for table TblBrlyQPty1NEquipment (PgSQL database)
  */
class PgTblBrlyQPty1NEquipment : public TblBrlyQPty1NEquipment, public PgTable {

public:
	PgTblBrlyQPty1NEquipment();
	~PgTblBrlyQPty1NEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQPty1NEquipment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQPty1NEquipment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQPty1NEquipment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQPty1NEquipment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQPty1NEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQPty1NEquipment& rst);

	void insertRec(BrlyQPty1NEquipment* rec);
	void insertRst(ListBrlyQPty1NEquipment& rst);
	void updateRec(BrlyQPty1NEquipment* rec);
	void updateRst(ListBrlyQPty1NEquipment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQPty1NEquipment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQPty1NEquipment& rst);
};

#endif

