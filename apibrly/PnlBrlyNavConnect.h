/**
  * \file PnlBrlyNavConnect.h
  * API code for job PnlBrlyNavConnect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYNAVCONNECT_H
#define PNLBRLYNAVCONNECT_H

#include "ApiBrly_blks.h"

#define VecVBrlyNavConnectDo PnlBrlyNavConnect::VecVDo

#define ContIacBrlyNavConnect PnlBrlyNavConnect::ContIac
#define StatAppBrlyNavConnect PnlBrlyNavConnect::StatApp
#define StatShrBrlyNavConnect PnlBrlyNavConnect::StatShr
#define TagBrlyNavConnect PnlBrlyNavConnect::Tag

#define DpchAppBrlyNavConnectData PnlBrlyNavConnect::DpchAppData
#define DpchAppBrlyNavConnectDo PnlBrlyNavConnect::DpchAppDo
#define DpchEngBrlyNavConnectData PnlBrlyNavConnect::DpchEngData

/**
  * PnlBrlyNavConnect
  */
namespace PnlBrlyNavConnect {
	/**
		* VecVDo (full: VecVBrlyNavConnectDo)
		*/
	class VecVDo {

	public:
		static const uint BUTCONVIEWCLICK = 1;
		static const uint BUTCONNEWCRDCLICK = 2;
		static const uint BUTRLYVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavConnect)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTCON = 1;
		static const uint NUMFLSTRLY = 2;

	public:
		ContIac(const uint numFLstCon = 1, const uint numFLstRly = 1);

	public:
		uint numFLstCon;
		uint numFLstRly;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyNavConnect)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint LSTCONALT = 2;
		static const uint LSTRLYALT = 3;
		static const uint LSTCONNUMFIRSTDISP = 4;
		static const uint LSTRLYNUMFIRSTDISP = 5;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstConAlt = true, const bool LstRlyAlt = true, const uint LstConNumFirstdisp = 1, const uint LstRlyNumFirstdisp = 1);

	public:
		uint ixBrlyVExpstate;
		bool LstConAlt;
		bool LstRlyAlt;
		uint LstConNumFirstdisp;
		uint LstRlyNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyNavConnect)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTCONAVAIL = 1;
		static const uint BUTCONVIEWACTIVE = 2;
		static const uint LSTRLYAVAIL = 3;
		static const uint BUTRLYVIEWACTIVE = 4;

	public:
		StatShr(const bool LstConAvail = true, const bool ButConViewActive = true, const bool LstRlyAvail = true, const bool ButRlyViewActive = true);

	public:
		bool LstConAvail;
		bool ButConViewActive;
		bool LstRlyAvail;
		bool ButRlyViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyNavConnect)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTCON = 2;
		static const uint CPTRLY = 3;

	public:
		Tag(const string& Cpt = "", const string& CptCon = "", const string& CptRly = "");

	public:
		string Cpt;
		string CptCon;
		string CptRly;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavConnectData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint ALL = 3;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyNavConnectDo)
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
		* DpchEngData (full: DpchEngBrlyNavConnectData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTCON = 3;
		static const uint FEEDFLSTRLY = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstCon;
		Feed feedFLstRly;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

