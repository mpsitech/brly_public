/**
  * \file PnlBrlySegMNConnection.h
  * API code for job PnlBrlySegMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYSEGMNCONNECTION_H
#define PNLBRLYSEGMNCONNECTION_H

#include "ApiBrly_blks.h"

#include "BrlyQSegMNConnection.h"

#include "QryBrlySegMNConnection.h"

#define VecVBrlySegMNConnectionDo PnlBrlySegMNConnection::VecVDo

#define ContInfBrlySegMNConnection PnlBrlySegMNConnection::ContInf
#define StatAppBrlySegMNConnection PnlBrlySegMNConnection::StatApp
#define StatShrBrlySegMNConnection PnlBrlySegMNConnection::StatShr
#define StgIacBrlySegMNConnection PnlBrlySegMNConnection::StgIac
#define TagBrlySegMNConnection PnlBrlySegMNConnection::Tag

#define DpchAppBrlySegMNConnectionData PnlBrlySegMNConnection::DpchAppData
#define DpchAppBrlySegMNConnectionDo PnlBrlySegMNConnection::DpchAppDo
#define DpchEngBrlySegMNConnectionData PnlBrlySegMNConnection::DpchEngData

/**
  * PnlBrlySegMNConnection
  */
namespace PnlBrlySegMNConnection {
	/**
		* VecVDo (full: VecVBrlySegMNConnectionDo)
		*/
	class VecVDo {

	public:
		static const uint BUTVIEWCLICK = 1;
		static const uint BUTADDCLICK = 2;
		static const uint BUTSUBCLICK = 3;
		static const uint BUTREFRESHCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlySegMNConnection)
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
	  * StatApp (full: StatAppBrlySegMNConnection)
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
	  * StatShr (full: StatShrBrlySegMNConnection)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTVIEWAVAIL = 1;
		static const uint BUTVIEWACTIVE = 2;
		static const uint BUTADDAVAIL = 3;
		static const uint BUTSUBAVAIL = 4;
		static const uint BUTSUBACTIVE = 5;

	public:
		StatShr(const bool ButViewAvail = true, const bool ButViewActive = true, const bool ButAddAvail = true, const bool ButSubAvail = true, const bool ButSubActive = true);

	public:
		bool ButViewAvail;
		bool ButViewActive;
		bool ButAddAvail;
		bool ButSubAvail;
		bool ButSubActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacBrlySegMNConnection)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;
		static const uint TCOSTAWIDTH = 2;
		static const uint TCOSTOWIDTH = 3;
		static const uint TCOLP0WIDTH = 4;
		static const uint TCOLP1WIDTH = 5;

	public:
		StgIac(const uint TcoMrefWidth = 100, const uint TcoStaWidth = 100, const uint TcoStoWidth = 100, const uint TcoLp0Width = 100, const uint TcoLp1Width = 100);

	public:
		uint TcoMrefWidth;
		uint TcoStaWidth;
		uint TcoStoWidth;
		uint TcoLp0Width;
		uint TcoLp1Width;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagBrlySegMNConnection)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOMREF = 5;
		static const uint TCOSTA = 6;
		static const uint TCOSTO = 7;
		static const uint TCOLP0 = 8;
		static const uint TCOLP1 = 9;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoMref = "", const string& TcoSta = "", const string& TcoSto = "", const string& TcoLp0 = "", const string& TcoLp1 = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoMref;
		string TcoSta;
		string TcoSto;
		string TcoLp0;
		string TcoLp1;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlySegMNConnectionData)
		*/
	class DpchAppData : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryBrlySegMNConnection::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryBrlySegMNConnection::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppBrlySegMNConnectionDo)
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
		* DpchEngData (full: DpchEngBrlySegMNConnectionData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListBrlyQSegMNConnection rst;
		QryBrlySegMNConnection::StatApp statappqry;
		QryBrlySegMNConnection::StatShr statshrqry;
		QryBrlySegMNConnection::StgIac stgiacqry;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

