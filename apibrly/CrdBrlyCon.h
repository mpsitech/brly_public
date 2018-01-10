/**
  * \file CrdBrlyCon.h
  * API code for job CrdBrlyCon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef CRDBRLYCON_H
#define CRDBRLYCON_H

#include "ApiBrly_blks.h"

#define VecVBrlyConDo CrdBrlyCon::VecVDo
#define VecVBrlyConSge CrdBrlyCon::VecVSge

#define ContInfBrlyCon CrdBrlyCon::ContInf
#define StatAppBrlyCon CrdBrlyCon::StatApp
#define StatShrBrlyCon CrdBrlyCon::StatShr
#define TagBrlyCon CrdBrlyCon::Tag

#define DpchAppBrlyConDo CrdBrlyCon::DpchAppDo
#define DpchEngBrlyConData CrdBrlyCon::DpchEngData

/**
  * CrdBrlyCon
  */
namespace CrdBrlyCon {
	/**
		* VecVDo (full: VecVBrlyConDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDNEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVBrlyConSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRBRLYABT = 2;
		static const uint CLOSE = 3;
		static const uint CRGIDLE = 4;
		static const uint CORRGEN = 5;
		static const uint CORRCALC = 6;
		static const uint CRGDONE = 7;
		static const uint CONGEN = 8;
		static const uint CNGDONE = 9;
		static const uint CALC1 = 10;
		static const uint CALC2 = 11;
		static const uint CALC3 = 12;
		static const uint CALC4 = 13;
		static const uint DONE = 14;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyCon)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDCON = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdCon = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdCon;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyCon)
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
	  * StatShr (full: StatShrBrlyCon)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFDLGNEW = 1;
		static const uint SCRJREFHEADBAR = 2;
		static const uint SCRJREFLIST = 3;
		static const uint SCRJREFREC = 4;
		static const uint MSPCRD1AVAIL = 5;
		static const uint MITCRDNEWAVAIL = 6;

	public:
		StatShr(const string& scrJrefDlgnew = "", const string& scrJrefHeadbar = "", const string& scrJrefList = "", const string& scrJrefRec = "", const bool MspCrd1Avail = true, const bool MitCrdNewAvail = true);

	public:
		string scrJrefDlgnew;
		string scrJrefHeadbar;
		string scrJrefList;
		string scrJrefRec;
		bool MspCrd1Avail;
		bool MitCrdNewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyCon)
	  */
	class Tag : public Block {

	public:
		static const uint MITAPPABT = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MITCRDNEW = 3;

	public:
		Tag(const string& MitAppAbt = "", const string& MrlAppHlp = "", const string& MitCrdNew = "");

	public:
		string MitAppAbt;
		string MrlAppHlp;
		string MitCrdNew;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyConDo)
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
		* DpchEngData (full: DpchEngBrlyConData)
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

