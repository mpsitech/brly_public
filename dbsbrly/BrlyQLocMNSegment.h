/**
  * \file BrlyQLocMNSegment.h
  * Dbs and XML wrapper for table TblBrlyQLocMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCMNSEGMENT_H
#define BRLYQLOCMNSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocMNSegment: record of TblBrlyQLocMNSegment
  */
class BrlyQLocMNSegment {

public:
	BrlyQLocMNSegment(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);

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
	double x2VisSegphi0;
	double x2VisSegphi1;
	double segphi;
	double segtheta;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQLocMNSegment: recordset of TblBrlyQLocMNSegment
  */
class ListBrlyQLocMNSegment {

public:
	ListBrlyQLocMNSegment();
	ListBrlyQLocMNSegment(const ListBrlyQLocMNSegment& src);
	~ListBrlyQLocMNSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQLocMNSegment* rec);

	ListBrlyQLocMNSegment& operator=(const ListBrlyQLocMNSegment& src);

public:
	vector<BrlyQLocMNSegment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQLocMNSegment: C++ wrapper for table TblBrlyQLocMNSegment
  */
class TblBrlyQLocMNSegment {

public:
	TblBrlyQLocMNSegment();
	virtual ~TblBrlyQLocMNSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQLocMNSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNSegment& rst);

	virtual void insertRec(BrlyQLocMNSegment* rec);
	ubigint insertNewRec(BrlyQLocMNSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);
	ubigint appendNewRecToRst(ListBrlyQLocMNSegment& rst, BrlyQLocMNSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisSegphi0 = 0.0, const double x2VisSegphi1 = 0.0, const double segphi = 0.0, const double segtheta = 0.0);
	virtual void insertRst(ListBrlyQLocMNSegment& rst);
	virtual void updateRec(BrlyQLocMNSegment* rec);
	virtual void updateRst(ListBrlyQLocMNSegment& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQLocMNSegment** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNSegment& rst);
};

/**
  * MyBrlyQLocMNSegment: C++ wrapper for table TblBrlyQLocMNSegment (MySQL database)
  */
class MyTblBrlyQLocMNSegment : public TblBrlyQLocMNSegment, public MyTable {

public:
	MyTblBrlyQLocMNSegment();
	~MyTblBrlyQLocMNSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMNSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNSegment& rst);

	void insertRec(BrlyQLocMNSegment* rec);
	void insertRst(ListBrlyQLocMNSegment& rst);
	void updateRec(BrlyQLocMNSegment* rec);
	void updateRst(ListBrlyQLocMNSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMNSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNSegment& rst);
};

/**
  * PgBrlyQLocMNSegment: C++ wrapper for table TblBrlyQLocMNSegment (PgSQL database)
  */
class PgTblBrlyQLocMNSegment : public TblBrlyQLocMNSegment, public PgTable {

public:
	PgTblBrlyQLocMNSegment();
	~PgTblBrlyQLocMNSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQLocMNSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQLocMNSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQLocMNSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQLocMNSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQLocMNSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQLocMNSegment& rst);

	void insertRec(BrlyQLocMNSegment* rec);
	void insertRst(ListBrlyQLocMNSegment& rst);
	void updateRec(BrlyQLocMNSegment* rec);
	void updateRst(ListBrlyQLocMNSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQLocMNSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQLocMNSegment& rst);
};

#endif

