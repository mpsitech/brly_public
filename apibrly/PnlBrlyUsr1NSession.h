/**
  * \file PnlBrlyUsr1NSession.h
  * API code for job PnlBrlyUsr1NSession (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYUSR1NSESSION_H
#define PNLBRLYUSR1NSESSION_H

#include "ApiBrly_blks.h"

#include "BrlyQUsr1NSession.h"

#include "QryBrlyUsr1NSession.h"

#define VecVBrlyUsr1NSessionDo PnlBrlyUsr1NSession::VecVDo

#define ContInfBrlyUsr1NSession PnlBrlyUsr1NSession::ContInf
#define StatAppBrlyUsr1NSession PnlBrlyUsr1NSession::StatApp
#define StgIacBrlyUsr1NSession PnlBrlyUsr1NSession::StgIac
#define TagBrlyUsr1NSession PnlBrlyUsr1NSession::Tag

#define DpchAppBrlyUsr1NSessionData PnlBrlyUsr1NSession::DpchAppData
#define DpchAppBrlyUsr1NSessionDo PnlBrlyUsr1NSession::DpchAppDo
#define DpchEngBrlyUsr1NSessionData PnlBrlyUsr1NSession::DpchEngData

/**
  * PnlBrlyUsr1NSession
  */
namespace PnlBrlyUsr1NSession {
	/**
		* VecVDo (full: VecVBrlyUsr1NSessionDo)
		*/
	class VecVDo {

	public:
		static const uint BUTREFRESHCLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyUsr1NSession)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyUsr1NSession)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND);

	public:
		uint ixBrlyVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StgIac (full: StgIacBrlyUsr1NSession)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlyUsr1NSession)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOREF = 5;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoRef = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyUsr1NSessionData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlyUsr1NSession::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlyUsr1NSession::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyUsr1NSessionDo)
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
		* DpchEngData (full: DpchEngBrlyUsr1NSessionData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STGIAC = 5;
		static const uint TAG = 6;
		static const uint RST = 7;
		static const uint STATAPPQRY = 8;
		static const uint STATSHRQRY = 9;
		static const uint STGIACQRY = 10;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StgIac stgiac;
		Tag tag;
		ListBrlyQUsr1NSession rst;
		QryBrlyUsr1NSession::StatApp statappqry;
		QryBrlyUsr1NSession::StatShr statshrqry;
		QryBrlyUsr1NSession::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

