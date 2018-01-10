/**
  * \file IexBrlyIni.h
  * import/export handler for database DbsBrly (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef IEXBRLYINI_H
#define IEXBRLYINI_H

#define VecVIexBrlyIniIme IexBrlyIni::VecVIme

#define ImeitemIBrlyIniAVControlPar IexBrlyIni::ImeitemIAVControlPar
#define ImeIBrlyIniAVControlPar IexBrlyIni::ImeIAVControlPar
#define VecWImeIBrlyIniAVControlParIel IexBrlyIni::ImeIAVControlPar::VecWIel

#define ImeitemIBrlyIniJAVKeylistKey IexBrlyIni::ImeitemIJAVKeylistKey
#define ImeIBrlyIniJAVKeylistKey IexBrlyIni::ImeIJAVKeylistKey
#define VecWImeIBrlyIniJAVKeylistKeyIel IexBrlyIni::ImeIJAVKeylistKey::VecWIel

#define ImeitemIBrlyIniAVKeylistKey IexBrlyIni::ImeitemIAVKeylistKey
#define ImeIBrlyIniAVKeylistKey IexBrlyIni::ImeIAVKeylistKey
#define VecWImeIBrlyIniAVKeylistKeyIel IexBrlyIni::ImeIAVKeylistKey::VecWIel

#define ImeitemIBrlyIniAVValuelistVal IexBrlyIni::ImeitemIAVValuelistVal
#define ImeIBrlyIniAVValuelistVal IexBrlyIni::ImeIAVValuelistVal
#define VecWImeIBrlyIniAVValuelistValIel IexBrlyIni::ImeIAVValuelistVal::VecWIel

#define ImeitemIBrlyIniMFile IexBrlyIni::ImeitemIMFile
#define ImeIBrlyIniMFile IexBrlyIni::ImeIMFile
#define VecWImeIBrlyIniMFileIel IexBrlyIni::ImeIMFile::VecWIel

#define ImeitemIBrlyIniMLocation IexBrlyIni::ImeitemIMLocation
#define ImeIBrlyIniMLocation IexBrlyIni::ImeIMLocation
#define VecWImeIBrlyIniMLocationIel IexBrlyIni::ImeIMLocation::VecWIel

#define ImeitemIBrlyIniMOperator IexBrlyIni::ImeitemIMOperator
#define ImeIBrlyIniMOperator IexBrlyIni::ImeIMOperator
#define VecWImeIBrlyIniMOperatorIel IexBrlyIni::ImeIMOperator::VecWIel

#define ImeitemIBrlyIniMPlntype IexBrlyIni::ImeitemIMPlntype
#define ImeIBrlyIniMPlntype IexBrlyIni::ImeIMPlntype
#define VecWImeIBrlyIniMPlntypeIel IexBrlyIni::ImeIMPlntype::VecWIel

#define ImeitemIBrlyIniAMRegionDstswitch IexBrlyIni::ImeitemIAMRegionDstswitch
#define ImeIBrlyIniAMRegionDstswitch IexBrlyIni::ImeIAMRegionDstswitch
#define VecWImeIBrlyIniAMRegionDstswitchIel IexBrlyIni::ImeIAMRegionDstswitch::VecWIel

#define ImeitemIBrlyIniJMRegion IexBrlyIni::ImeitemIJMRegion
#define ImeIBrlyIniJMRegion IexBrlyIni::ImeIJMRegion
#define VecWImeIBrlyIniJMRegionIel IexBrlyIni::ImeIJMRegion::VecWIel

#define ImeitemIBrlyIniJMRegionTitle IexBrlyIni::ImeitemIJMRegionTitle
#define ImeIBrlyIniJMRegionTitle IexBrlyIni::ImeIJMRegionTitle
#define VecWImeIBrlyIniJMRegionTitleIel IexBrlyIni::ImeIJMRegionTitle::VecWIel

#define ImeitemIBrlyIniMRegion IexBrlyIni::ImeitemIMRegion
#define ImeIBrlyIniMRegion IexBrlyIni::ImeIMRegion
#define VecWImeIBrlyIniMRegionIel IexBrlyIni::ImeIMRegion::VecWIel

#define ImeitemIBrlyIniAMUsergroupAccess IexBrlyIni::ImeitemIAMUsergroupAccess
#define ImeIBrlyIniAMUsergroupAccess IexBrlyIni::ImeIAMUsergroupAccess
#define VecWImeIBrlyIniAMUsergroupAccessIel IexBrlyIni::ImeIAMUsergroupAccess::VecWIel

#define ImeitemIBrlyIniJMUserState IexBrlyIni::ImeitemIJMUserState
#define ImeIBrlyIniJMUserState IexBrlyIni::ImeIJMUserState
#define VecWImeIBrlyIniJMUserStateIel IexBrlyIni::ImeIJMUserState::VecWIel

#define ImeitemIBrlyIniJMPersonLastname IexBrlyIni::ImeitemIJMPersonLastname
#define ImeIBrlyIniJMPersonLastname IexBrlyIni::ImeIJMPersonLastname
#define VecWImeIBrlyIniJMPersonLastnameIel IexBrlyIni::ImeIJMPersonLastname::VecWIel

#define ImeitemIBrlyIniMPerson IexBrlyIni::ImeitemIMPerson
#define ImeIBrlyIniMPerson IexBrlyIni::ImeIMPerson
#define VecWImeIBrlyIniMPersonIel IexBrlyIni::ImeIMPerson::VecWIel

#define ImeitemIBrlyIniMUser IexBrlyIni::ImeitemIMUser
#define ImeIBrlyIniMUser IexBrlyIni::ImeIMUser
#define VecWImeIBrlyIniMUserIel IexBrlyIni::ImeIMUser::VecWIel

#define ImeitemIBrlyIniMUsergroup IexBrlyIni::ImeitemIMUsergroup
#define ImeIBrlyIniMUsergroup IexBrlyIni::ImeIMUsergroup
#define VecWImeIBrlyIniMUsergroupIel IexBrlyIni::ImeIMUsergroup::VecWIel

/**
	* IexBrlyIni
	*/
class IexBrlyIni : public JobBrly {

public:
	/**
		* VecVIme (full: VecVIexBrlyIniIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIAVCONTROLPAR = 1;
		static const uint IMEIAVKEYLISTKEY = 2;
		static const uint IMEIAVVALUELISTVAL = 3;
		static const uint IMEIMFILE = 4;
		static const uint IMEIMLOCATION = 5;
		static const uint IMEIMOPERATOR = 6;
		static const uint IMEIMPLNTYPE = 7;
		static const uint IMEIMREGION = 8;
		static const uint IMEIMUSERGROUP = 9;
		static const uint IMEIAMREGIONDSTSWITCH = 10;
		static const uint IMEIAMUSERGROUPACCESS = 11;
		static const uint IMEIJAVKEYLISTKEY = 12;
		static const uint IMEIJMREGION = 13;
		static const uint IMEIJMREGIONTITLE = 14;
		static const uint IMEIMUSER = 15;
		static const uint IMEIJMUSERSTATE = 16;
		static const uint IMEIMPERSON = 17;
		static const uint IMEIJMPERSONLASTNAME = 18;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIAVControlPar (full: ImeitemIBrlyIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public BrlyAVControlPar {

	public:
		ImeitemIAVControlPar(const uint ixBrlyVControl = 0, const string& Par = "", const string& Val = "");
		ImeitemIAVControlPar(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVControlPar (full: ImeIBrlyIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXBRLYVCONTROL = 1;
			static const uint PAR = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey (full: ImeitemIBrlyIniJAVKeylistKey)
		*/
	class ImeitemIJAVKeylistKey : public BrlyJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey(const uint x1IxBrlyVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey (full: ImeIBrlyIniJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXBRLYVLOCALE = 1;
			static const uint TITLE = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJAVKeylistKey();
		~ImeIJAVKeylistKey();

	public:
		vector<ImeitemIJAVKeylistKey*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey (full: ImeitemIBrlyIniAVKeylistKey)
		*/
	class ImeitemIAVKeylistKey : public BrlyAVKeylistKey {

	public:
		ImeitemIAVKeylistKey(const uint klsIxBrlyVKeylist = 0, const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey imeijavkeylistkey;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey (full: ImeIBrlyIniAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const uint SREFKLSIXBRLYVKEYLIST = 1;
			static const uint SREF = 2;
			static const uint AVAIL = 4;
			static const uint IMPLIED = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVKeylistKey();
		~ImeIAVKeylistKey();

	public:
		vector<ImeitemIAVKeylistKey*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVValuelistVal (full: ImeitemIBrlyIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public BrlyAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const uint vlsIxBrlyVValuelist = 0, const uint x1IxBrlyVLocale = 0, const string& Val = "");
		ImeitemIAVValuelistVal(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVValuelistVal (full: ImeIBrlyIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const uint SREFVLSIXBRLYVVALUELIST = 1;
			static const uint SREFX1IXBRLYVLOCALE = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile (full: ImeitemIBrlyIniMFile)
		*/
	class ImeitemIMFile : public BrlyMFile {

	public:
		ImeitemIMFile(const string& osrefKContent = "", const string& Filename = "", const string& srefKMimetype = "", const string& Comment = "");
		ImeitemIMFile(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile (full: ImeIBrlyIniMFile)
		*/
	class ImeIMFile {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMFileIel)
			*/
		class VecWIel {

		public:
			static const uint OSREFKCONTENT = 1;
			static const uint FILENAME = 2;
			static const uint SREFKMIMETYPE = 4;
			static const uint COMMENT = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMFile();
		~ImeIMFile();

	public:
		vector<ImeitemIMFile*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMLocation (full: ImeitemIBrlyIniMLocation)
		*/
	class ImeitemIMLocation : public BrlyMLocation {

	public:
		ImeitemIMLocation(const uint ixVBasetype = 0, const string& hsrefRefBrlyMRegion = "", const string& sref = "", const string& srefICAO = "", const string& Title = "", const double alt = 0.0, const double theta = 0.0, const double phi = 0.0, const string& tz = "");
		ImeitemIMLocation(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefRefBrlyMRegion;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMLocation (full: ImeIBrlyIniMLocation)
		*/
	class ImeIMLocation {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMLocationIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVBASETYPE = 1;
			static const uint HSREFREFBRLYMREGION = 2;
			static const uint SREF = 4;
			static const uint SREFICAO = 8;
			static const uint TITLE = 16;
			static const uint ALT = 32;
			static const uint THETA = 64;
			static const uint PHI = 128;
			static const uint TZ = 256;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMLocation();
		~ImeIMLocation();

	public:
		vector<ImeitemIMLocation*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMOperator (full: ImeitemIBrlyIniMOperator)
		*/
	class ImeitemIMOperator : public BrlyMOperator {

	public:
		ImeitemIMOperator(const string& sref = "", const string& srefICAO = "", const string& Title = "");
		ImeitemIMOperator(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMOperator (full: ImeIBrlyIniMOperator)
		*/
	class ImeIMOperator {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMOperatorIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint SREFICAO = 2;
			static const uint TITLE = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMOperator();
		~ImeIMOperator();

	public:
		vector<ImeitemIMOperator*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPlntype (full: ImeitemIBrlyIniMPlntype)
		*/
	class ImeitemIMPlntype : public BrlyMPlntype {

	public:
		ImeitemIMPlntype(const string& sref = "", const string& Title = "", const string& srefBrlyKEqptype = "", const usmallint Capacity = 0);
		ImeitemIMPlntype(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPlntype (full: ImeIBrlyIniMPlntype)
		*/
	class ImeIMPlntype {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMPlntypeIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint TITLE = 2;
			static const uint SREFBRLYKEQPTYPE = 4;
			static const uint CAPACITY = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMPlntype();
		~ImeIMPlntype();

	public:
		vector<ImeitemIMPlntype*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMRegionDstswitch (full: ImeitemIBrlyIniAMRegionDstswitch)
		*/
	class ImeitemIAMRegionDstswitch : public BrlyAMRegionDstswitch {

	public:
		ImeitemIAMRegionDstswitch(const uint startd = 0, const uint startt = 0);
		ImeitemIAMRegionDstswitch(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMRegionDstswitch (full: ImeIBrlyIniAMRegionDstswitch)
		*/
	class ImeIAMRegionDstswitch {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAMRegionDstswitchIel)
			*/
		class VecWIel {

		public:
			static const uint FTMSTARTD = 1;
			static const uint FTMSTARTT = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMRegionDstswitch();
		~ImeIAMRegionDstswitch();

	public:
		vector<ImeitemIAMRegionDstswitch*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMRegion (full: ImeitemIBrlyIniJMRegion)
		*/
	class ImeitemIJMRegion : public BrlyJMRegion {

	public:
		ImeitemIJMRegion(const uint x1Startd = 0, const uint x1Stopd = 0, const uint ixVDst = 0, const double toffset = 0.0);
		ImeitemIJMRegion(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMRegion (full: ImeIBrlyIniJMRegion)
		*/
	class ImeIJMRegion {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJMRegionIel)
			*/
		class VecWIel {

		public:
			static const uint FTMX1STARTD = 1;
			static const uint FTMX1STOPD = 2;
			static const uint SREFIXVDST = 4;
			static const uint TOFFSET = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMRegion();
		~ImeIJMRegion();

	public:
		vector<ImeitemIJMRegion*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMRegionTitle (full: ImeitemIBrlyIniJMRegionTitle)
		*/
	class ImeitemIJMRegionTitle : public BrlyJMRegionTitle {

	public:
		ImeitemIJMRegionTitle(const uint x1IxBrlyVLocale = 0, const string& Title = "");
		ImeitemIJMRegionTitle(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMRegionTitle (full: ImeIBrlyIniJMRegionTitle)
		*/
	class ImeIJMRegionTitle {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJMRegionTitleIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXBRLYVLOCALE = 1;
			static const uint TITLE = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMRegionTitle();
		~ImeIJMRegionTitle();

	public:
		vector<ImeitemIJMRegionTitle*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMRegion (full: ImeitemIBrlyIniMRegion)
		*/
	class ImeitemIMRegion : public BrlyMRegion {

	public:
		ImeitemIMRegion(const string& hsrefSupRefBrlyMRegion = "", const string& sref = "");
		ImeitemIMRegion(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		string hsrefSupRefBrlyMRegion;

		ImeIAMRegionDstswitch imeiamregiondstswitch;
		ImeIJMRegion imeijmregion;
		ImeIJMRegionTitle imeijmregiontitle;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMRegion (full: ImeIBrlyIniMRegion)
		*/
	class ImeIMRegion {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMRegionIel)
			*/
		class VecWIel {

		public:
			static const uint HSREFSUPREFBRLYMREGION = 1;
			static const uint SREF = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMRegion();
		~ImeIMRegion();

	public:
		vector<ImeitemIMRegion*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIBrlyIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public BrlyAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const uint x1IxBrlyVCard = 0, const uint ixBrlyWUiaccess = 0);
		ImeitemIAMUsergroupAccess(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUsergroupAccess (full: ImeIBrlyIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXBRLYVCARD = 1;
			static const uint SREFSIXBRLYWUIACCESS = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIBrlyIniJMUserState)
		*/
	class ImeitemIJMUserState : public BrlyJMUserState {

	public:
		ImeitemIJMUserState(const uint ixVState = 0);
		ImeitemIJMUserState(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMUserState (full: ImeIBrlyIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVSTATE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIBrlyIniJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public BrlyJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const string& Lastname = "");
		ImeitemIJMPersonLastname(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIBrlyIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const uint LASTNAME = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIBrlyIniMPerson)
		*/
	class ImeitemIMPerson : public BrlyMPerson {

	public:
		ImeitemIMPerson(const uint ixVSex = 0, const string& Title = "", const string& Firstname = "");
		ImeitemIMPerson(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJMPersonLastname imeijmpersonlastname;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIBrlyIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVSEX = 1;
			static const uint TITLE = 2;
			static const uint FIRSTNAME = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUser (full: ImeitemIBrlyIniMUser)
		*/
	class ImeitemIMUser : public BrlyMUser {

	public:
		ImeitemIMUser(const string& sref = "", const uint ixBrlyVLocale = 0, const uint ixBrlyVUserlevel = 0, const string& Password = "");
		ImeitemIMUser(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIBrlyIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMUserIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint SREFIXBRLYVLOCALE = 2;
			static const uint SREFIXBRLYVUSERLEVEL = 4;
			static const uint PASSWORD = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIBrlyIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public BrlyMUsergroup {

	public:
		ImeitemIMUsergroup(const string& sref = "", const string& Comment = "");
		ImeitemIMUsergroup(DbsBrly* dbsbrly, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIBrlyIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIBrlyIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint COMMENT = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexBrlyIni(XchgBrly* xchg, DbsBrly* dbsbrly, const ubigint jrefSup, const uint ixBrlyVLocale);
	~IexBrlyIni();

public:
	uint lineno;
	uint impcnt;

	ImeIAVControlPar imeiavcontrolpar;
	ImeIAVKeylistKey imeiavkeylistkey;
	ImeIAVValuelistVal imeiavvaluelistval;
	ImeIMFile imeimfile;
	ImeIMLocation imeimlocation;
	ImeIMOperator imeimoperator;
	ImeIMPlntype imeimplntype;
	ImeIMRegion imeimregion;
	ImeIMUsergroup imeimusergroup;

public:
	// IP cust --- IBEGIN
	static constexpr double pi = 3.141592653589793238462643383279;

	double radToDeg(double _rad);
	// IP cust --- IEND

public:
	void reset();

	void import(DbsBrly* dbsbrly);

	void collect(DbsBrly* dbsbrly, const map<uint,uint>& icsBrlyVIop = icsBrlyVIopInsAll());

public:
	bool readTxt(Txtrd& txtrd);
	void readXML(xmlXPathContext* docctx, string basexpath);

	bool readTxtFile(const string& fullpath);
	bool readXMLFile(const string& fullpath);

	void writeTxt(fstream& outfile);
	void writeXML(xmlTextWriter* wr, const bool shorttags);

	void writeTxtFile(const string& fullpath);
	void writeXMLFile(const string& fullpath, const bool shorttags);

	static map<uint,uint> icsBrlyVIopInsAll();
	uint getIxBrlyVIop(const map<uint,uint>& icsBrlyVIop, const uint ixVIme, uint& ixBrlyVIop);

public:
	void handleRequest(DbsBrly* dbsbrly, ReqBrly* req);

	void handleCall(DbsBrly* dbsbrly, Call* call);
};

#endif


