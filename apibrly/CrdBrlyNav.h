/**
  * \file CrdBrlyNav.h
  * API code for job CrdBrlyNav (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef CRDBRLYNAV_H
#define CRDBRLYNAV_H

#include "ApiBrly_blks.h"

#define VecVBrlyNavDo CrdBrlyNav::VecVDo
#define VecVBrlyNavSge CrdBrlyNav::VecVSge

#define ContInfBrlyNav CrdBrlyNav::ContInf
#define StatAppBrlyNav CrdBrlyNav::StatApp
#define StatShrBrlyNav CrdBrlyNav::StatShr
#define TagBrlyNav CrdBrlyNav::Tag

#define DpchAppBrlyNavDo CrdBrlyNav::DpchAppDo
#define DpchEngBrlyNavData CrdBrlyNav::DpchEngData

/**
  * CrdBrlyNav
  */
namespace CrdBrlyNav {
	/**
		* VecVDo (full: VecVBrlyNavDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITSESTRMCLICK = 3;
		static const uint MITCRDUSGCLICK = 4;
		static const uint MITCRDUSRCLICK = 5;
		static const uint MITCRDPRSCLICK = 6;
		static const uint MITCRDFILCLICK = 7;
		static const uint MITCRDOPRCLICK = 8;
		static const uint MITCRDPTYCLICK = 9;
		static const uint MITCRDREGCLICK = 10;
		static const uint MITCRDLOCCLICK = 11;
		static const uint MITCRDLEGCLICK = 12;
		static const uint MITCRDTTBCLICK = 13;
		static const uint MITCRDFLTCLICK = 14;
		static const uint MITCRDCONCLICK = 15;
		static const uint MITAPPLOICLICK = 16;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyNavSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRBRLYABT = 2;
		static const uint CLOSE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyNav)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXSESSES1 = 3;
		static const uint MTXSESSES2 = 4;
		static const uint MTXSESSES3 = 5;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxSesSes1 = "", const string& MtxSesSes2 = "", const string& MtxSesSes3 = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxSesSes1;
		string MtxSesSes2;
		string MtxSesSes3;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyNav)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVREQITMODE = 1;
		static const uint LATENCY = 2;
		static const uint SHORTMENU = 3;
		static const uint WIDTHMENU = 4;
		static const uint INITDONEHEADBAR = 5;
		static const uint INITDONEADMIN = 6;
		static const uint INITDONEBASE = 7;
		static const uint INITDONECONNECT = 8;

	public:
		StatApp(const uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneAdmin = false, const bool initdoneBase = false, const bool initdoneConnect = false);

	public:
		uint ixBrlyVReqitmode;
		usmallint latency;
		string shortMenu;
		uint widthMenu;
		bool initdoneHeadbar;
		bool initdoneAdmin;
		bool initdoneBase;
		bool initdoneConnect;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyNav)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFDLGLOAINI = 1;
		static const uint SCRJREFHEADBAR = 2;
		static const uint SCRJREFADMIN = 3;
		static const uint PNLADMINAVAIL = 4;
		static const uint SCRJREFBASE = 5;
		static const uint PNLBASEAVAIL = 6;
		static const uint SCRJREFCONNECT = 7;
		static const uint PNLCONNECTAVAIL = 8;
		static const uint MSPCRD1AVAIL = 9;
		static const uint MITCRDUSGAVAIL = 10;
		static const uint MITCRDUSRAVAIL = 11;
		static const uint MITCRDPRSAVAIL = 12;
		static const uint MITCRDFILAVAIL = 13;
		static const uint MITCRDOPRAVAIL = 14;
		static const uint MITCRDPTYAVAIL = 15;
		static const uint MSPCRD2AVAIL = 16;
		static const uint MITCRDREGAVAIL = 17;
		static const uint MITCRDLOCAVAIL = 18;
		static const uint MITCRDLEGAVAIL = 19;
		static const uint MITCRDTTBAVAIL = 20;
		static const uint MITCRDFLTAVAIL = 21;
		static const uint MSPCRD3AVAIL = 22;
		static const uint MITCRDCONAVAIL = 23;
		static const uint MSPAPP2AVAIL = 24;
		static const uint MITAPPLOIAVAIL = 25;

	public:
		StatShr(const string& scrJrefDlgloaini = "", const string& scrJrefHeadbar = "", const string& scrJrefAdmin = "", const bool pnladminAvail = false, const string& scrJrefBase = "", const bool pnlbaseAvail = false, const string& scrJrefConnect = "", const bool pnlconnectAvail = false, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MitCrdOprAvail = true, const bool MitCrdPtyAvail = true, const bool MspCrd2Avail = true, const bool MitCrdRegAvail = true, const bool MitCrdLocAvail = true, const bool MitCrdLegAvail = true, const bool MitCrdTtbAvail = true, const bool MitCrdFltAvail = true, const bool MspCrd3Avail = true, const bool MitCrdConAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		string scrJrefDlgloaini;
		string scrJrefHeadbar;
		string scrJrefAdmin;
		bool pnladminAvail;
		string scrJrefBase;
		bool pnlbaseAvail;
		string scrJrefConnect;
		bool pnlconnectAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MitCrdOprAvail;
		bool MitCrdPtyAvail;
		bool MspCrd2Avail;
		bool MitCrdRegAvail;
		bool MitCrdLocAvail;
		bool MitCrdLegAvail;
		bool MitCrdTtbAvail;
		bool MitCrdFltAvail;
		bool MspCrd3Avail;
		bool MitCrdConAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyNav)
	  */
	class Tag : public Block {

	public:
		static const uint MITAPPABT = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MITSESTRM = 3;
		static const uint MITCRDUSG = 4;
		static const uint MITCRDUSR = 5;
		static const uint MITCRDPRS = 6;
		static const uint MITCRDFIL = 7;
		static const uint MITCRDOPR = 8;
		static const uint MITCRDPTY = 9;
		static const uint MITCRDREG = 10;
		static const uint MITCRDLOC = 11;
		static const uint MITCRDLEG = 12;
		static const uint MITCRDTTB = 13;
		static const uint MITCRDFLT = 14;
		static const uint MITCRDCON = 15;
		static const uint MITAPPLOI = 16;

	public:
		Tag(const string& MitAppAbt = "", const string& MrlAppHlp = "", const string& MitSesTrm = "", const string& MitCrdUsg = "", const string& MitCrdUsr = "", const string& MitCrdPrs = "", const string& MitCrdFil = "", const string& MitCrdOpr = "", const string& MitCrdPty = "", const string& MitCrdReg = "", const string& MitCrdLoc = "", const string& MitCrdLeg = "", const string& MitCrdTtb = "", const string& MitCrdFlt = "", const string& MitCrdCon = "", const string& MitAppLoi = "");

	public:
		string MitAppAbt;
		string MrlAppHlp;
		string MitSesTrm;
		string MitCrdUsg;
		string MitCrdUsr;
		string MitCrdPrs;
		string MitCrdFil;
		string MitCrdOpr;
		string MitCrdPty;
		string MitCrdReg;
		string MitCrdLoc;
		string MitCrdLeg;
		string MitCrdTtb;
		string MitCrdFlt;
		string MitCrdCon;
		string MitAppLoi;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyNavDo)
		*/
	class DpchAppDo : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint ALL = 3;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngBrlyNavData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

