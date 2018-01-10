/**
  * \file CrdBrlyTtb.h
  * API code for job CrdBrlyTtb (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef CRDBRLYTTB_H
#define CRDBRLYTTB_H

#include "ApiBrly_blks.h"

#define VecVBrlyTtbDo CrdBrlyTtb::VecVDo
#define VecVBrlyTtbSge CrdBrlyTtb::VecVSge

#define ContInfBrlyTtb CrdBrlyTtb::ContInf
#define StatAppBrlyTtb CrdBrlyTtb::StatApp
#define StatShrBrlyTtb CrdBrlyTtb::StatShr
#define TagBrlyTtb CrdBrlyTtb::Tag

#define DpchAppBrlyTtbDo CrdBrlyTtb::DpchAppDo
#define DpchEngBrlyTtbData CrdBrlyTtb::DpchEngData

/**
  * CrdBrlyTtb
  */
namespace CrdBrlyTtb {
	/**
		* VecVDo (full: VecVBrlyTtbDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDNEWCLICK = 3;
		static const uint MITCRDTRLCLICK = 4;
		static const uint MITCRDIFLCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyTtbSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRBRLYABT = 2;
		static const uint CLOSE = 3;
		static const uint IMPIDLE = 4;
		static const uint IMPORT = 5;
		static const uint IMPDONE = 6;
		static const uint SEGMENT = 7;
		static const uint SEGDONE = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyTtb)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDTTB = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdTtb = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdTtb;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyTtb)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVREQITMODE = 1;
		static const uint LATENCY = 2;
		static const uint SHORTMENU = 3;
		static const uint WIDTHMENU = 4;
		static const uint INITDONEHEADBAR = 5;
		static const uint INITDONELIST = 6;
		static const uint INITDONEREC = 7;

	public:
		StatApp(const uint ixBrlyVReqitmode = VecBrlyVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);

	public:
		uint ixBrlyVReqitmode;
		usmallint latency;
		string shortMenu;
		uint widthMenu;
		bool initdoneHeadbar;
		bool initdoneList;
		bool initdoneRec;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyTtb)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFDLGIMPFLT = 1;
		static const uint SCRJREFDLGNEW = 2;
		static const uint SCRJREFDLGTRLORIG = 3;
		static const uint SCRJREFHEADBAR = 4;
		static const uint SCRJREFLIST = 5;
		static const uint SCRJREFREC = 6;
		static const uint MSPCRD1AVAIL = 7;
		static const uint MITCRDNEWAVAIL = 8;
		static const uint MITCRDTRLAVAIL = 9;
		static const uint MITCRDIFLAVAIL = 10;
		static const uint MITCRDIFLACTIVE = 11;

	public:
		StatShr(const string& scrJrefDlgimpflt = "", const string& scrJrefDlgnew = "", const string& scrJrefDlgtrlorig = "", const string& scrJrefHeadbar = "", const string& scrJrefList = "", const string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true, const bool MitCrdTrlAvail = true, const bool MitCrdIflAvail = true, const bool MitCrdIflActive = true);

	public:
		string scrJrefDlgimpflt;
		string scrJrefDlgnew;
		string scrJrefDlgtrlorig;
		string scrJrefHeadbar;
		string scrJrefList;
		string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;
		bool MitCrdTrlAvail;
		bool MitCrdIflAvail;
		bool MitCrdIflActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyTtb)
	  */
	class Tag : public Block {

	public:
		static const uint MITAPPABT = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MITCRDNEW = 3;
		static const uint MITCRDTRL = 4;
		static const uint MITCRDIFL = 5;

	public:
		Tag(const string& MitAppAbt = "", const string& MrlAppHlp = "", const string& MitCrdNew = "", const string& MitCrdTrl = "", const string& MitCrdIfl = "");

	public:
		string MitAppAbt;
		string MrlAppHlp;
		string MitCrdNew;
		string MitCrdTrl;
		string MitCrdIfl;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyTtbDo)
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
		* DpchEngData (full: DpchEngBrlyTtbData)
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

