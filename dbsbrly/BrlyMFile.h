/**
  * \file BrlyMFile.h
  * database access for table TblBrlyMFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYMFILE_H
#define BRLYMFILE_H

#include <sbecore/MyDbs.h>
#include <sbecore/PgDbs.h>

#include <sbecore/Xmlio.h>

using namespace Xmlio;

#define VecBrlyVMFileRefTbl TblBrlyMFile::VecVRefTbl

/**
  * BrlyMFile: record of TblBrlyMFile
  */
class BrlyMFile {

public:
	BrlyMFile(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refBrlyCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refBrlyCFile;
	uint refIxVTbl;
	ubigint refUref;
	string osrefKContent;
	uint Archived;
	string Filename;
	string Archivename;
	string srefKMimetype;
	usmallint Size;
	string Comment;

public:
	bool operator==(const BrlyMFile& comp);
	bool operator!=(const BrlyMFile& comp);
};

/**
  * ListBrlyMFile: recordset of TblBrlyMFile
  */
class ListBrlyMFile {

public:
	ListBrlyMFile();
	ListBrlyMFile(const ListBrlyMFile& src);
	~ListBrlyMFile();

	void clear();
	unsigned int size() const;
	void append(BrlyMFile* rec);

	BrlyMFile* operator[](const uint ix);
	ListBrlyMFile& operator=(const ListBrlyMFile& src);
	bool operator==(const ListBrlyMFile& comp);
	bool operator!=(const ListBrlyMFile& comp);

public:
	vector<BrlyMFile*> nodes;
};

/**
  * TblBrlyMFile: C++ wrapper for table TblBrlyMFile
  */
class TblBrlyMFile {

public:
	/**
		* VecVRefTbl (full: VecBrlyVMFileRefTbl)
		*/
	class VecVRefTbl {

	public:
		static const uint VOID = 1;
		static const uint TTB = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixBrlyVLocale);

		static void fillFeed(const uint ixBrlyVLocale, Feed& feed);
	};

public:
	TblBrlyMFile();
	virtual ~TblBrlyMFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, BrlyMFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFile& rst);

	virtual void insertRec(BrlyMFile* rec);
	ubigint insertNewRec(BrlyMFile** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refBrlyCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListBrlyMFile& rst, BrlyMFile** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refBrlyCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const usmallint Size = 0, const string Comment = "");
	virtual void insertRst(ListBrlyMFile& rst, bool transact = false);
	virtual void updateRec(BrlyMFile* rec);
	virtual void updateRst(ListBrlyMFile& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, BrlyMFile** rec);
	virtual ubigint loadRefsByClu(ubigint refBrlyCFile, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRefsByRetReu(uint refIxVTbl, ubigint refUref, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByClu(ubigint refBrlyCFile, const bool append, ListBrlyMFile& rst);
	virtual ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListBrlyMFile& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListBrlyMFile& rst);
};

/**
  * MyBrlyMFile: C++ wrapper for table TblBrlyMFile (MySQL database)
  */
class MyTblBrlyMFile : public TblBrlyMFile, public MyTable {

public:
	MyTblBrlyMFile();
	~MyTblBrlyMFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFile& rst);

	void insertRec(BrlyMFile* rec);
	void insertRst(ListBrlyMFile& rst, bool transact = false);
	void updateRec(BrlyMFile* rec);
	void updateRst(ListBrlyMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMFile** rec);
	ubigint loadRefsByClu(ubigint refBrlyCFile, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByRetReu(uint refIxVTbl, ubigint refUref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByClu(ubigint refBrlyCFile, const bool append, ListBrlyMFile& rst);
	ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListBrlyMFile& rst);
};

/**
  * PgBrlyMFile: C++ wrapper for table TblBrlyMFile (PgSQL database)
  */
class PgTblBrlyMFile : public TblBrlyMFile, public PgTable {

public:
	PgTblBrlyMFile();
	~PgTblBrlyMFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, BrlyMFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListBrlyMFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, BrlyMFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListBrlyMFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, BrlyMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListBrlyMFile& rst);

	void insertRec(BrlyMFile* rec);
	void insertRst(ListBrlyMFile& rst, bool transact = false);
	void updateRec(BrlyMFile* rec);
	void updateRst(ListBrlyMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, BrlyMFile** rec);
	ubigint loadRefsByClu(ubigint refBrlyCFile, const bool append, vector<ubigint>& refs);
	ubigint loadRefsByRetReu(uint refIxVTbl, ubigint refUref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByClu(ubigint refBrlyCFile, const bool append, ListBrlyMFile& rst);
	ubigint loadRstByRetReu(uint refIxVTbl, ubigint refUref, const bool append, ListBrlyMFile& rst);
};

#endif

