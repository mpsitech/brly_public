/**
  * \file BrlyQConConMNEquipment.h
  * Dbs and XML wrapper for table TblBrlyQConConMNEquipment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONCONMNEQUIPMENT_H
#define BRLYQCONCONMNEQUIPMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConConMNEquipment: record of TblBrlyQConConMNEquipment
  */
class BrlyQConConMNEquipment {

public:
	BrlyQConConMNEquipment(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "", const uint conNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint conIxBrlyVLat;
	string srefConIxBrlyVLat;
	uint conNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConConMNEquipment: recordset of TblBrlyQConConMNEquipment
  */
class ListBrlyQConConMNEquipment {

public:
	ListBrlyQConConMNEquipment();
	ListBrlyQConConMNEquipment(const ListBrlyQConConMNEquipment& src);
	~ListBrlyQConConMNEquipment();

	void clear();
	unsigned int size() const;
	void append(BrlyQConConMNEquipment* rec);

	ListBrlyQConConMNEquipment& operator=(const ListBrlyQConConMNEquipment& src);

public:
	vector<BrlyQConConMNEquipment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConConMNEquipment: C++ wrapper for table TblBrlyQConConMNEquipment
  */
class TblBrlyQConConMNEquipment {

public:
	TblBrlyQConConMNEquipment();
	virtual ~TblBrlyQConConMNEquipment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConConMNEquipment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConConMNEquipment& rst);

	virtual void insertRec(BrlyQConConMNEquipment* rec);
	ubigint insertNewRec(BrlyQConConMNEquipment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "", const uint conNum = 0);
	ubigint appendNewRecToRst(ListBrlyQConConMNEquipment& rst, BrlyQConConMNEquipment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint conIxBrlyVLat = 0, const string srefConIxBrlyVLat = "", const uint conNum = 0);
	virtual void insertRst(ListBrlyQConConMNEquipment& rst);
	virtual void updateRec(BrlyQConConMNEquipment* rec);
	virtual void updateRst(ListBrlyQConConMNEquipment& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConConMNEquipment** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConConMNEquipment& rst);
};

/**
  * MyBrlyQConConMNEquipment: C++ wrapper for table TblBrlyQConConMNEquipment (MySQL database)
  */
class MyTblBrlyQConConMNEquipment : public TblBrlyQConConMNEquipment, public MyTable {

public:
	MyTblBrlyQConConMNEquipment();
	~MyTblBrlyQConConMNEquipment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConConMNEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConConMNEquipment& rst);

	void insertRec(BrlyQConConMNEquipment* rec);
	void insertRst(ListBrlyQConConMNEquipment& rst);
	void updateRec(BrlyQConConMNEquipment* rec);
	void updateRst(ListBrlyQConConMNEquipment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConConMNEquipment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConConMNEquipment& rst);
};

/**
  * PgBrlyQConConMNEquipment: C++ wrapper for table TblBrlyQConConMNEquipment (PgSQL database)
  */
class PgTblBrlyQConConMNEquipment : public TblBrlyQConConMNEquipment, public PgTable {

public:
	PgTblBrlyQConConMNEquipment();
	~PgTblBrlyQConConMNEquipment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConConMNEquipment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConConMNEquipment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConConMNEquipment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConConMNEquipment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConConMNEquipment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConConMNEquipment& rst);

	void insertRec(BrlyQConConMNEquipment* rec);
	void insertRst(ListBrlyQConConMNEquipment& rst);
	void updateRec(BrlyQConConMNEquipment* rec);
	void updateRst(ListBrlyQConConMNEquipment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConConMNEquipment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConConMNEquipment& rst);
};

#endif

