/**
  * \file BrlyQConMapLocation.h
  * Dbs and XML wrapper for table TblBrlyQConMapLocation (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQCONMAPLOCATION_H
#define BRLYQCONMAPLOCATION_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQConMapLocation: record of TblBrlyQConMapLocation
  */
class BrlyQConMapLocation {

public:
	BrlyQConMapLocation(const ubigint qref = 0, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mrefBrlyMEquipment = 0, const double x = 0.0, const double y = 0.0);

public:
	ubigint qref;
	bool qwr;
	ubigint jref;
	uint jnum;
	ubigint ref;
	double legphi;
	double legtheta;
	ubigint mref;
	string stubMref;
	ubigint mrefBrlyMEquipment;
	double x;
	double y;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListBrlyQConMapLocation: recordset of TblBrlyQConMapLocation
  */
class ListBrlyQConMapLocation {

public:
	ListBrlyQConMapLocation();
	ListBrlyQConMapLocation(const ListBrlyQConMapLocation& src);
	~ListBrlyQConMapLocation();

	void clear();
	unsigned int size() const;
	void append(BrlyQConMapLocation* rec);

	ListBrlyQConMapLocation& operator=(const ListBrlyQConMapLocation& src);

public:
	vector<BrlyQConMapLocation*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblBrlyQConMapLocation: C++ wrapper for table TblBrlyQConMapLocation
  */
class TblBrlyQConMapLocation {

public:
	TblBrlyQConMapLocation();
	virtual ~TblBrlyQConMapLocation();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyQConMapLocation** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapLocation& rst);

	virtual void insertRec(BrlyQConMapLocation* rec);
	ubigint insertNewRec(BrlyQConMapLocation** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mrefBrlyMEquipment = 0, const double x = 0.0, const double y = 0.0);
	ubigint appendNewRecToRst(ListBrlyQConMapLocation& rst, BrlyQConMapLocation** rec = NULL, const bool qwr = false, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const double legphi = 0.0, const double legtheta = 0.0, const ubigint mref = 0, const string stubMref = "", const ubigint mrefBrlyMEquipment = 0, const double x = 0.0, const double y = 0.0);
	virtual void insertRst(ListBrlyQConMapLocation& rst);
	virtual void updateRec(BrlyQConMapLocation* rec);
	virtual void updateRst(ListBrlyQConMapLocation& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, BrlyQConMapLocation** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapLocation& rst);
};

/**
  * MyBrlyQConMapLocation: C++ wrapper for table TblBrlyQConMapLocation (MySQL database)
  */
class MyTblBrlyQConMapLocation : public TblBrlyQConMapLocation, public MyTable {

public:
	MyTblBrlyQConMapLocation();
	~MyTblBrlyQConMapLocation();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapLocation& rst);

	void insertRec(BrlyQConMapLocation* rec);
	void insertRst(ListBrlyQConMapLocation& rst);
	void updateRec(BrlyQConMapLocation* rec);
	void updateRst(ListBrlyQConMapLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapLocation& rst);
};

/**
  * PgBrlyQConMapLocation: C++ wrapper for table TblBrlyQConMapLocation (PgSQL database)
  */
class PgTblBrlyQConMapLocation : public TblBrlyQConMapLocation, public PgTable {

public:
	PgTblBrlyQConMapLocation();
	~PgTblBrlyQConMapLocation();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyQConMapLocation** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyQConMapLocation& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyQConMapLocation** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyQConMapLocation& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyQConMapLocation** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyQConMapLocation& rst);

	void insertRec(BrlyQConMapLocation* rec);
	void insertRst(ListBrlyQConMapLocation& rst);
	void updateRec(BrlyQConMapLocation* rec);
	void updateRst(ListBrlyQConMapLocation& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, BrlyQConMapLocation** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListBrlyQConMapLocation& rst);
};

#endif

