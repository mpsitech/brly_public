/**
  * \file BrlyQConMNSegment.h
  * Dbs and XML wrapper for table TblBrlyQConMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMNSEGMENT_H
#define BRLYQCONMNSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMNSegment: record of TblBrlyQConMNSegment
  */
class BrlyQConMNSegment {

public:
	BrlyQConMNSegment(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint x1Start;
	string ftmX1Start;
	uint x1Stop;
	string ftmX1Stop;
	double x2Legphi0;
	double x2Legphi1;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConMNSegment: recordset of TblBrlyQConMNSegment
  */
class ListBrlyQConMNSegment {

public:
	ListBrlyQConMNSegment();
	ListBrlyQConMNSegment(const ListBrlyQConMNSegment& src);
	~ListBrlyQConMNSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMNSegment* rec);

	ListBrlyQConMNSegment& operator=(const ListBrlyQConMNSegment& src);

public:
	vector<BrlyQConMNSegment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConMNSegment: C++ wrapper for table TblBrlyQConMNSegment
  */
class TblBrlyQConMNSegment {

public:
	TblBrlyQConMNSegment();
	virtual ~TblBrlyQConMNSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConMNSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMNSegment& rst);

	virtual void insertRec(BrlyQConMNSegment* rec);
	ubigint insertNewRec(BrlyQConMNSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQConMNSegment& rst, BrlyQConMNSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);
	virtual void insertRst(ListBrlyQConMNSegment& rst);
	virtual void updateRec(BrlyQConMNSegment* rec);
	virtual void updateRst(ListBrlyQConMNSegment& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConMNSegment** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMNSegment& rst);
};

/**
  * MyBrlyQConMNSegment: C++ wrapper for table TblBrlyQConMNSegment (MySQL database)
  */
class MyTblBrlyQConMNSegment : public TblBrlyQConMNSegment, public MyTable {

public:
	MyTblBrlyQConMNSegment();
	~MyTblBrlyQConMNSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMNSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMNSegment& rst);

	void insertRec(BrlyQConMNSegment* rec);
	void insertRst(ListBrlyQConMNSegment& rst);
	void updateRec(BrlyQConMNSegment* rec);
	void updateRst(ListBrlyQConMNSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMNSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMNSegment& rst);
};

/**
  * PgBrlyQConMNSegment: C++ wrapper for table TblBrlyQConMNSegment (PgSQL database)
  */
class PgTblBrlyQConMNSegment : public TblBrlyQConMNSegment, public PgTable {

public:
	PgTblBrlyQConMNSegment();
	~PgTblBrlyQConMNSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMNSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMNSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMNSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMNSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMNSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMNSegment& rst);

	void insertRec(BrlyQConMNSegment* rec);
	void insertRst(ListBrlyQConMNSegment& rst);
	void updateRec(BrlyQConMNSegment* rec);
	void updateRst(ListBrlyQConMNSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMNSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMNSegment& rst);
};

#endif

