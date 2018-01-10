/**
  * \file BrlyRMLegMLeg.h
  * database access for table TblBrlyRMLegMLeg (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYRMLEGMLEG_H
#define BRLYRMLEGMLEG_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

/**
  * BrlyRMLegMLeg: record of TblBrlyRMLegMLeg
  */
class BrlyRMLegMLeg {

public:
	BrlyRMLegMLeg(const ubigint ref = 0, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const ubigint dstRefBrlyMLeg = 0, const ubigint orgRefBrlyMLeg = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);

public:
	ubigint ref;
	double x1VisDstLegphi0;
	double x1VisDstLegphi1;
	ubigint dstRefBrlyMLeg;
	ubigint orgRefBrlyMLeg;
	double VisOrgLegphi0;
	double VisOrgLegphi1;
	double xVisDstLegphi0;
	double xVisDstLegphi1;
	double xVisOrgLegphi0;
	double xVisOrgLegphi1;

public:
	bool operator==(const BrlyRMLegMLeg& comp);
	bool operator!=(const BrlyRMLegMLeg& comp);
};

/**
  * ListBrlyRMLegMLeg: recordset of TblBrlyRMLegMLeg
  */
class ListBrlyRMLegMLeg {

public:
	ListBrlyRMLegMLeg();
	ListBrlyRMLegMLeg(const ListBrlyRMLegMLeg& src);
	~ListBrlyRMLegMLeg();

	void clear();
	unsigned int size() const;
	void append(BrlyRMLegMLeg* rec);

	BrlyRMLegMLeg* operator[](const uint ix);
	ListBrlyRMLegMLeg& operator=(const ListBrlyRMLegMLeg& src);
	bool operator==(const ListBrlyRMLegMLeg& comp);
	bool operator!=(const ListBrlyRMLegMLeg& comp);

public:
	vector<BrlyRMLegMLeg*> nodes;
};

/**
  * TblBrlyRMLegMLeg: C++ wrapper for table TblBrlyRMLegMLeg
  */
class TblBrlyRMLegMLeg {

public:

public:
	TblBrlyRMLegMLeg();
	virtual ~TblBrlyRMLegMLeg();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyRMLegMLeg** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLegMLeg& rst);

	virtual void insertRec(BrlyRMLegMLeg* rec);
	ubigint insertNewRec(BrlyRMLegMLeg** rec = NULL, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const ubigint dstRefBrlyMLeg = 0, const ubigint orgRefBrlyMLeg = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);
	ubigint appendNewRecToRst(ListBrlyRMLegMLeg& rst, BrlyRMLegMLeg** rec = NULL, const double x1VisDstLegphi0 = 0.0, const double x1VisDstLegphi1 = 0.0, const ubigint dstRefBrlyMLeg = 0, const ubigint orgRefBrlyMLeg = 0, const double VisOrgLegphi0 = 0.0, const double VisOrgLegphi1 = 0.0, const double xVisDstLegphi0 = 0.0, const double xVisDstLegphi1 = 0.0, const double xVisOrgLegphi0 = 0.0, const double xVisOrgLegphi1 = 0.0);
	virtual void insertRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	virtual void updateRec(BrlyRMLegMLeg* rec);
	virtual void updateRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyRMLegMLeg** rec);
	virtual ubigint loadRstByDlg(ubigint dstRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
	virtual ubigint loadRstByOlg(ubigint orgRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyRMLegMLeg& rst);
};

/**
  * MyBrlyRMLegMLeg: C++ wrapper for table TblBrlyRMLegMLeg (MySQL database)
  */
class MyTblBrlyRMLegMLeg : public TblBrlyRMLegMLeg, public MyTable {

public:
	MyTblBrlyRMLegMLeg();
	~MyTblBrlyRMLegMLeg();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMLegMLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLegMLeg& rst);

	void insertRec(BrlyRMLegMLeg* rec);
	void insertRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	void updateRec(BrlyRMLegMLeg* rec);
	void updateRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMLegMLeg** rec);
	ubigint loadRstByDlg(ubigint dstRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
	ubigint loadRstByOlg(ubigint orgRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
};

/**
  * PgBrlyRMLegMLeg: C++ wrapper for table TblBrlyRMLegMLeg (PgSQL database)
  */
class PgTblBrlyRMLegMLeg : public TblBrlyRMLegMLeg, public PgTable {

public:
	PgTblBrlyRMLegMLeg();
	~PgTblBrlyRMLegMLeg();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyRMLegMLeg** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyRMLegMLeg& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyRMLegMLeg** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyRMLegMLeg& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyRMLegMLeg** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyRMLegMLeg& rst);

	void insertRec(BrlyRMLegMLeg* rec);
	void insertRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	void updateRec(BrlyRMLegMLeg* rec);
	void updateRst(ListBrlyRMLegMLeg& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyRMLegMLeg** rec);
	ubigint loadRstByDlg(ubigint dstRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
	ubigint loadRstByOlg(ubigint orgRefBrlyMLeg, const bool append, ListBrlyRMLegMLeg& rst);
};

#endif

