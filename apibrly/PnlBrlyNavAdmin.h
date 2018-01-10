/**
  * \file PnlBrlyNavAdmin.h
  * API code for job PnlBrlyNavAdmin (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYNAVADMIN_H
#define PNLBRLYNAVADMIN_H

#include "ApiBrly_blks.h"

#define VecVBrlyNavAdminDo PnlBrlyNavAdmin::VecVDo

#define ContIacBrlyNavAdmin PnlBrlyNavAdmin::ContIac
#define StatAppBrlyNavAdmin PnlBrlyNavAdmin::StatApp
#define StatShrBrlyNavAdmin PnlBrlyNavAdmin::StatShr
#define TagBrlyNavAdmin PnlBrlyNavAdmin::Tag

#define DpchAppBrlyNavAdminData PnlBrlyNavAdmin::DpchAppData
#define DpchAppBrlyNavAdminDo PnlBrlyNavAdmin::DpchAppDo
#define DpchEngBrlyNavAdminData PnlBrlyNavAdmin::DpchEngData

/**
  * PnlBrlyNavAdmin
  */
namespace PnlBrlyNavAdmin {
	/**
		* VecVDo (full: VecVBrlyNavAdminDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUSGVIEWCLICK = 1;
		static const uint BUTUSGNEWCRDCLICK = 2;
		static const uint BUTUSRVIEWCLICK = 3;
		static const uint BUTUSRNEWCRDCLICK = 4;
		static const uint BUTPRSVIEWCLICK = 5;
		static const uint BUTPRSNEWCRDCLICK = 6;
		static const uint BUTFILVIEWCLICK = 7;
		static const uint BUTFILNEWCRDCLICK = 8;
		static const uint BUTOPRVIEWCLICK = 9;
		static const uint BUTOPRNEWCRDCLICK = 10;
		static const uint BUTPTYVIEWCLICK = 11;
		static const uint BUTPTYNEWCRDCLICK = 12;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyNavAdmin)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTUSG = 1;
		static const uint NUMFLSTUSR = 2;
		static const uint NUMFLSTPRS = 3;
		static const uint NUMFLSTFIL = 4;
		static const uint NUMFLSTOPR = 5;
		static const uint NUMFLSTPTY = 6;

	public:
		ContIac(const uint numFLstUsg = 1, const uint numFLstUsr = 1, const uint numFLstPrs = 1, const uint numFLstFil = 1, const uint numFLstOpr = 1, const uint numFLstPty = 1);

	public:
		uint numFLstUsg;
		uint numFLstUsr;
		uint numFLstPrs;
		uint numFLstFil;
		uint numFLstOpr;
		uint numFLstPty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyNavAdmin)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint LSTUSGALT = 2;
		static const uint LSTUSRALT = 3;
		static const uint LSTPRSALT = 4;
		static const uint LSTFILALT = 5;
		static const uint LSTOPRALT = 6;
		static const uint LSTPTYALT = 7;
		static const uint LSTUSGNUMFIRSTDISP = 8;
		static const uint LSTUSRNUMFIRSTDISP = 9;
		static const uint LSTPRSNUMFIRSTDISP = 10;
		static const uint LSTFILNUMFIRSTDISP = 11;
		static const uint LSTOPRNUMFIRSTDISP = 12;
		static const uint LSTPTYNUMFIRSTDISP = 13;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const bool LstFilAlt = true, const bool LstOprAlt = true, const bool LstPtyAlt = true, const uint LstUsgNumFirstdisp = 1, const uint LstUsrNumFirstdisp = 1, const uint LstPrsNumFirstdisp = 1, const uint LstFilNumFirstdisp = 1, const uint LstOprNumFirstdisp = 1, const uint LstPtyNumFirstdisp = 1);

	public:
		uint ixBrlyVExpstate;
		bool LstUsgAlt;
		bool LstUsrAlt;
		bool LstPrsAlt;
		bool LstFilAlt;
		bool LstOprAlt;
		bool LstPtyAlt;
		uint LstUsgNumFirstdisp;
		uint LstUsrNumFirstdisp;
		uint LstPrsNumFirstdisp;
		uint LstFilNumFirstdisp;
		uint LstOprNumFirstdisp;
		uint LstPtyNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyNavAdmin)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTUSGAVAIL = 1;
		static const uint BUTUSGVIEWACTIVE = 2;
		static const uint LSTUSRAVAIL = 3;
		static const uint BUTUSRVIEWACTIVE = 4;
		static const uint LSTPRSAVAIL = 5;
		static const uint BUTPRSVIEWACTIVE = 6;
		static const uint LSTFILAVAIL = 7;
		static const uint BUTFILVIEWACTIVE = 8;
		static const uint LSTOPRAVAIL = 9;
		static const uint BUTOPRVIEWACTIVE = 10;
		static const uint LSTPTYAVAIL = 11;
		static const uint BUTPTYVIEWACTIVE = 12;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true, const bool LstOprAvail = true, const bool ButOprViewActive = true, const bool LstPtyAvail = true, const bool ButPtyViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;
		bool LstOprAvail;
		bool ButOprViewActive;
		bool LstPtyAvail;
		bool ButPtyViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyNavAdmin)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTUSG = 2;
		static const uint CPTUSR = 3;
		static const uint CPTPRS = 4;
		static const uint CPTFIL = 5;
		static const uint CPTOPR = 6;
		static const uint CPTPTY = 7;

	public:
		Tag(const string& Cpt = "", const string& CptUsg = "", const string& CptUsr = "", const string& CptPrs = "", const string& CptFil = "", const string& CptOpr = "", const string& CptPty = "");

	public:
		string Cpt;
		string CptUsg;
		string CptUsr;
		string CptPrs;
		string CptFil;
		string CptOpr;
		string CptPty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyNavAdminData)
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
		* DpchAppDo (full: DpchAppBrlyNavAdminDo)
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
		* DpchEngData (full: DpchEngBrlyNavAdminData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTFIL = 3;
		static const uint FEEDFLSTOPR = 4;
		static const uint FEEDFLSTPRS = 5;
		static const uint FEEDFLSTPTY = 6;
		static const uint FEEDFLSTUSG = 7;
		static const uint FEEDFLSTUSR = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstFil;
		Feed feedFLstOpr;
		Feed feedFLstPrs;
		Feed feedFLstPty;
		Feed feedFLstUsg;
		Feed feedFLstUsr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

