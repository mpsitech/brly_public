/**
  * \file BrlyQSegOrgMNSegment.h
  * Dbs and XML wrapper for table TblBrlyQSegOrgMNSegment (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQSEGORGMNSEGMENT_H
#define BRLYQSEGORGMNSEGMENT_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQSegOrgMNSegment: record of TblBrlyQSegOrgMNSegment
  */
class BrlyQSegOrgMNSegment {

public:
	BrlyQSegOrgMNSegment(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);

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
	double x2VisDstSegphi0;
	double x2VisDstSegphi1;
	double VisOrgSegphi0;
	double VisOrgSegphi1;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQSegOrgMNSegment: recordset of TblBrlyQSegOrgMNSegment
  */
class ListBrlyQSegOrgMNSegment {

public:
	ListBrlyQSegOrgMNSegment();
	ListBrlyQSegOrgMNSegment(const ListBrlyQSegOrgMNSegment& src);
	~ListBrlyQSegOrgMNSegment();

	void clear();
	unsigned int size() const;
	void append(BrlyQSegOrgMNSegment* rec);

	ListBrlyQSegOrgMNSegment& operator=(const ListBrlyQSegOrgMNSegment& src);

public:
	vector<BrlyQSegOrgMNSegment*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQSegOrgMNSegment: C++ wrapper for table TblBrlyQSegOrgMNSegment
  */
class TblBrlyQSegOrgMNSegment {

public:
	TblBrlyQSegOrgMNSegment();
	virtual ~TblBrlyQSegOrgMNSegment();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQSegOrgMNSegment** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegOrgMNSegment& rst);

	virtual void insertRec(BrlyQSegOrgMNSegment* rec);
	ubigint insertNewRec(BrlyQSegOrgMNSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyQSegOrgMNSegment& rst, BrlyQSegOrgMNSegment** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint x1Start = 0, const string ftmX1Start = "", const uint x1Stop = 0, const string ftmX1Stop = "", const double x2VisDstSegphi0 = 0.0, const double x2VisDstSegphi1 = 0.0, const double VisOrgSegphi0 = 0.0, const double VisOrgSegphi1 = 0.0);
	virtual void insertRst(ListBrlyQSegOrgMNSegment& rst);
	virtual void updateRec(BrlyQSegOrgMNSegment* rec);
	virtual void updateRst(ListBrlyQSegOrgMNSegment& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQSegOrgMNSegment** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegOrgMNSegment& rst);
};

/**
  * MyBrlyQSegOrgMNSegment: C++ wrapper for table TblBrlyQSegOrgMNSegment (MySQL database)
  */
class MyTblBrlyQSegOrgMNSegment : public TblBrlyQSegOrgMNSegment, public MyTable {

public:
	MyTblBrlyQSegOrgMNSegment();
	~MyTblBrlyQSegOrgMNSegment();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSegOrgMNSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegOrgMNSegment& rst);

	void insertRec(BrlyQSegOrgMNSegment* rec);
	void insertRst(ListBrlyQSegOrgMNSegment& rst);
	void updateRec(BrlyQSegOrgMNSegment* rec);
	void updateRst(ListBrlyQSegOrgMNSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSegOrgMNSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegOrgMNSegment& rst);
};

/**
  * PgBrlyQSegOrgMNSegment: C++ wrapper for table TblBrlyQSegOrgMNSegment (PgSQL database)
  */
class PgTblBrlyQSegOrgMNSegment : public TblBrlyQSegOrgMNSegment, public PgTable {

public:
	PgTblBrlyQSegOrgMNSegment();
	~PgTblBrlyQSegOrgMNSegment();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQSegOrgMNSegment** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQSegOrgMNSegment& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQSegOrgMNSegment** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQSegOrgMNSegment& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQSegOrgMNSegment** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQSegOrgMNSegment& rst);

	void insertRec(BrlyQSegOrgMNSegment* rec);
	void insertRst(ListBrlyQSegOrgMNSegment& rst);
	void updateRec(BrlyQSegOrgMNSegment* rec);
	void updateRst(ListBrlyQSegOrgMNSegment& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQSegOrgMNSegment** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQSegOrgMNSegment& rst);
};

#endif

