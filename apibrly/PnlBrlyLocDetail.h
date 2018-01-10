/**
  * \file PnlBrlyLocDetail.h
  * API code for job PnlBrlyLocDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLOCDETAIL_H
#define PNLBRLYLOCDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyLocDetailDo PnlBrlyLocDetail::VecVDo

#define ContIacBrlyLocDetail PnlBrlyLocDetail::ContIac
#define ContInfBrlyLocDetail PnlBrlyLocDetail::ContInf
#define StatAppBrlyLocDetail PnlBrlyLocDetail::StatApp
#define StatShrBrlyLocDetail PnlBrlyLocDetail::StatShr
#define TagBrlyLocDetail PnlBrlyLocDetail::Tag

#define DpchAppBrlyLocDetailData PnlBrlyLocDetail::DpchAppData
#define DpchAppBrlyLocDetailDo PnlBrlyLocDetail::DpchAppDo
#define DpchEngBrlyLocDetailData PnlBrlyLocDetail::DpchEngData

/**
  * PnlBrlyLocDetail
  */
namespace PnlBrlyLocDetail {
	/**
		* VecVDo (full: VecVBrlyLocDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTEQPNEWCLICK = 2;
		static const uint BUTEQPDELETECLICK = 3;
		static const uint BUTEQPOPRVIEWCLICK = 4;
		static const uint BUTEQPPTYVIEWCLICK = 5;
		static const uint BUTEQPETYEDITCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyLocDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFICA = 1;
		static const uint TXFTIT = 2;
		static const uint NUMFPUPTYP = 3;
		static const uint TXFALT = 4;
		static const uint TXFTHE = 5;
		static const uint TXFPHI = 6;
		static const uint TXFTZ = 7;
		static const uint TXFAPH = 8;
		static const uint CHKCDN = 9;
		static const uint NUMFPUPEQPETY = 10;
		static const uint TXFEQPETY = 11;
		static const uint CHKEQPFIB = 12;

	public:
		ContIac(const string& TxfIca = "", const string& TxfTit = "", const uint numFPupTyp = 1, const string& TxfAlt = "", const string& TxfThe = "", const string& TxfPhi = "", const string& TxfTz = "", const string& TxfAph = "", const bool ChkCdn = false, const uint numFPupEqpEty = 1, const string& TxfEqpEty = "", const bool ChkEqpFib = false);

	public:
		string TxfIca;
		string TxfTit;
		uint numFPupTyp;
		string TxfAlt;
		string TxfThe;
		string TxfPhi;
		string TxfTz;
		string TxfAph;
		bool ChkCdn;
		uint numFPupEqpEty;
		string TxfEqpEty;
		bool ChkEqpFib;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfBrlyLocDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTREG = 2;
		static const uint TXTEQPOPR = 3;
		static const uint TXTEQPPTY = 4;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtReg = "", const string& TxtEqpOpr = "", const string& TxtEqpPty = "");

	public:
		string TxtSrf;
		string TxtReg;
		string TxtEqpOpr;
		string TxtEqpPty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyLocDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint PUPEQPETYALT = 2;

	public:
		StatApp(const uint ixBrlyVExpstate = VecBrlyVExpstate::MIND, const bool PupEqpEtyAlt = false);

	public:
		uint ixBrlyVExpstate;
		bool PupEqpEtyAlt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyLocDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFEQPETYVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint TXTSRFACTIVE = 4;
		static const uint TXFICAACTIVE = 5;
		static const uint TXFTITACTIVE = 6;
		static const uint PUPTYPACTIVE = 7;
		static const uint TXTREGACTIVE = 8;
		static const uint TXFALTACTIVE = 9;
		static const uint TXFTHEACTIVE = 10;
		static const uint TXFPHIACTIVE = 11;
		static const uint TXFTZACTIVE = 12;
		static const uint TXFAPHACTIVE = 13;
		static const uint CHKCDNACTIVE = 14;
		static const uint BUTEQPNEWAVAIL = 15;
		static const uint BUTEQPDELETEAVAIL = 16;
		static const uint TXTEQPOPRAVAIL = 17;
		static const uint TXTEQPOPRACTIVE = 18;
		static const uint BUTEQPOPRVIEWAVAIL = 19;
		static const uint BUTEQPOPRVIEWACTIVE = 20;
		static const uint TXTEQPPTYAVAIL = 21;
		static const uint TXTEQPPTYACTIVE = 22;
		static const uint BUTEQPPTYVIEWAVAIL = 23;
		static const uint BUTEQPPTYVIEWACTIVE = 24;
		static const uint PUPEQPETYAVAIL = 25;
		static const uint PUPEQPETYACTIVE = 26;
		static const uint BUTEQPETYEDITAVAIL = 27;
		static const uint CHKEQPFIBAVAIL = 28;
		static const uint CHKEQPFIBACTIVE = 29;

	public:
		StatShr(const bool TxfEqpEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxfIcaActive = true, const bool TxfTitActive = true, const bool PupTypActive = true, const bool TxtRegActive = true, const bool TxfAltActive = true, const bool TxfTheActive = true, const bool TxfPhiActive = true, const bool TxfTzActive = true, const bool TxfAphActive = true, const bool ChkCdnActive = true, const bool ButEqpNewAvail = true, const bool ButEqpDeleteAvail = true, const bool TxtEqpOprAvail = true, const bool TxtEqpOprActive = true, const bool ButEqpOprViewAvail = true, const bool ButEqpOprViewActive = true, const bool TxtEqpPtyAvail = true, const bool TxtEqpPtyActive = true, const bool ButEqpPtyViewAvail = true, const bool ButEqpPtyViewActive = true, const bool PupEqpEtyAvail = true, const bool PupEqpEtyActive = true, const bool ButEqpEtyEditAvail = true, const bool ChkEqpFibAvail = true, const bool ChkEqpFibActive = true);

	public:
		bool TxfEqpEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxfIcaActive;
		bool TxfTitActive;
		bool PupTypActive;
		bool TxtRegActive;
		bool TxfAltActive;
		bool TxfTheActive;
		bool TxfPhiActive;
		bool TxfTzActive;
		bool TxfAphActive;
		bool ChkCdnActive;
		bool ButEqpNewAvail;
		bool ButEqpDeleteAvail;
		bool TxtEqpOprAvail;
		bool TxtEqpOprActive;
		bool ButEqpOprViewAvail;
		bool ButEqpOprViewActive;
		bool TxtEqpPtyAvail;
		bool TxtEqpPtyActive;
		bool ButEqpPtyViewAvail;
		bool ButEqpPtyViewActive;
		bool PupEqpEtyAvail;
		bool PupEqpEtyActive;
		bool ButEqpEtyEditAvail;
		bool ChkEqpFibAvail;
		bool ChkEqpFibActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyLocDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTICA = 3;
		static const uint CPTTIT = 4;
		static const uint CPTTYP = 5;
		static const uint CPTREG = 6;
		static const uint CPTALT = 7;
		static const uint CPTTHE = 8;
		static const uint CPTPHI = 9;
		static const uint CPTTZ = 10;
		static const uint CPTAPH = 11;
		static const uint CPTCDN = 12;
		static const uint HDGEQP = 13;
		static const uint CPTEQPOPR = 14;
		static const uint CPTEQPPTY = 15;
		static const uint CPTEQPETY = 16;
		static const uint CPTEQPFIB = 17;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptIca = "", const string& CptTit = "", const string& CptTyp = "", const string& CptReg = "", const string& CptAlt = "", const string& CptThe = "", const string& CptPhi = "", const string& CptTz = "", const string& CptAph = "", const string& CptCdn = "", const string& HdgEqp = "", const string& CptEqpOpr = "", const string& CptEqpPty = "", const string& CptEqpEty = "", const string& CptEqpFib = "");

	public:
		string Cpt;
		string CptSrf;
		string CptIca;
		string CptTit;
		string CptTyp;
		string CptReg;
		string CptAlt;
		string CptThe;
		string CptPhi;
		string CptTz;
		string CptAph;
		string CptCdn;
		string HdgEqp;
		string CptEqpOpr;
		string CptEqpPty;
		string CptEqpEty;
		string CptEqpFib;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyLocDetailData)
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
		* DpchAppDo (full: DpchAppBrlyLocDetailDo)
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
		* DpchEngData (full: DpchEngBrlyLocDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPEQPETY = 4;
		static const uint FEEDFPUPTYP = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupEqpEty;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

