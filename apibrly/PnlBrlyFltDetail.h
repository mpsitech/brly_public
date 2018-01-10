/**
  * \file PnlBrlyFltDetail.h
  * API code for job PnlBrlyFltDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTDETAIL_H
#define PNLBRLYFLTDETAIL_H

#include "ApiBrly_blks.h"

#define VecVBrlyFltDetailDo PnlBrlyFltDetail::VecVDo

#define ContIacBrlyFltDetail PnlBrlyFltDetail::ContIac
#define ContInfBrlyFltDetail PnlBrlyFltDetail::ContInf
#define StatAppBrlyFltDetail PnlBrlyFltDetail::StatApp
#define StatShrBrlyFltDetail PnlBrlyFltDetail::StatShr
#define TagBrlyFltDetail PnlBrlyFltDetail::Tag

#define DpchAppBrlyFltDetailData PnlBrlyFltDetail::DpchAppData
#define DpchAppBrlyFltDetailDo PnlBrlyFltDetail::DpchAppDo
#define DpchEngBrlyFltDetailData PnlBrlyFltDetail::DpchEngData

/**
  * PnlBrlyFltDetail
  */
namespace PnlBrlyFltDetail {
	/**
		* VecVDo (full: VecVBrlyFltDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTTTBVIEWCLICK = 2;
		static const uint BUTFAFNEWCLICK = 3;
		static const uint BUTFAFDELETECLICK = 4;
		static const uint BUTEQPNEWCLICK = 5;
		static const uint BUTEQPDELETECLICK = 6;
		static const uint BUTEQPOPRVIEWCLICK = 7;
		static const uint BUTEQPPTYVIEWCLICK = 8;
		static const uint BUTEQPETYEDITCLICK = 9;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacBrlyFltDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFSTA = 1;
		static const uint TXFSTO = 2;
		static const uint TXFXSA = 3;
		static const uint TXFXSO = 4;
		static const uint CHKCDN = 5;
		static const uint CHKSDN = 6;
		static const uint TXFFAFFID = 7;
		static const uint TXFFAFIDT = 8;
		static const uint TXFFAFACT = 9;
		static const uint TXFFAFFET = 10;
		static const uint TXFFAFFTI = 11;
		static const uint TXFFAFFDT = 12;
		static const uint TXFFAFFSK = 13;
		static const uint TXFFAFFSM = 14;
		static const uint TXFFAFFAT = 15;
		static const uint TXFFAFRTE = 16;
		static const uint TXFFAFADT = 17;
		static const uint TXFFAFEAT = 18;
		static const uint TXFFAFAAT = 19;
		static const uint TXFFAFDVT = 20;
		static const uint TXFFAFORG = 21;
		static const uint TXFFAFDST = 22;
		static const uint TXFFAFONM = 23;
		static const uint TXFFAFOCT = 24;
		static const uint TXFFAFDNM = 25;
		static const uint TXFFAFDCT = 26;
		static const uint NUMFPUPEQPETY = 27;
		static const uint TXFEQPETY = 28;
		static const uint CHKEQPFIB = 29;

	public:
		ContIac(const string& TxfSta = "", const string& TxfSto = "", const string& TxfXsa = "", const string& TxfXso = "", const bool ChkCdn = false, const bool ChkSdn = false, const string& TxfFafFid = "", const string& TxfFafIdt = "", const string& TxfFafAct = "", const string& TxfFafFet = "", const string& TxfFafFti = "", const string& TxfFafFdt = "", const string& TxfFafFsk = "", const string& TxfFafFsm = "", const string& TxfFafFat = "", const string& TxfFafRte = "", const string& TxfFafAdt = "", const string& TxfFafEat = "", const string& TxfFafAat = "", const string& TxfFafDvt = "", const string& TxfFafOrg = "", const string& TxfFafDst = "", const string& TxfFafOnm = "", const string& TxfFafOct = "", const string& TxfFafDnm = "", const string& TxfFafDct = "", const uint numFPupEqpEty = 1, const string& TxfEqpEty = "", const bool ChkEqpFib = false);

	public:
		string TxfSta;
		string TxfSto;
		string TxfXsa;
		string TxfXso;
		bool ChkCdn;
		bool ChkSdn;
		string TxfFafFid;
		string TxfFafIdt;
		string TxfFafAct;
		string TxfFafFet;
		string TxfFafFti;
		string TxfFafFdt;
		string TxfFafFsk;
		string TxfFafFsm;
		string TxfFafFat;
		string TxfFafRte;
		string TxfFafAdt;
		string TxfFafEat;
		string TxfFafAat;
		string TxfFafDvt;
		string TxfFafOrg;
		string TxfFafDst;
		string TxfFafOnm;
		string TxfFafOct;
		string TxfFafDnm;
		string TxfFafDct;
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
	  * ContInf (full: ContInfBrlyFltDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTTTB = 2;
		static const uint TXTLEG = 3;
		static const uint TXTEQPOPR = 4;
		static const uint TXTEQPPTY = 5;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtTtb = "", const string& TxtLeg = "", const string& TxtEqpOpr = "", const string& TxtEqpPty = "");

	public:
		string TxtSrf;
		string TxtTtb;
		string TxtLeg;
		string TxtEqpOpr;
		string TxtEqpPty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyFltDetail)
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
	  * StatShr (full: StatShrBrlyFltDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFEQPETYVALID = 1;
		static const uint BUTSAVEAVAIL = 2;
		static const uint BUTSAVEACTIVE = 3;
		static const uint TXTSRFACTIVE = 4;
		static const uint TXTTTBACTIVE = 5;
		static const uint BUTTTBVIEWAVAIL = 6;
		static const uint BUTTTBVIEWACTIVE = 7;
		static const uint TXTLEGACTIVE = 8;
		static const uint TXFSTAACTIVE = 9;
		static const uint TXFSTOACTIVE = 10;
		static const uint TXFXSAACTIVE = 11;
		static const uint TXFXSOACTIVE = 12;
		static const uint CHKCDNACTIVE = 13;
		static const uint CHKSDNACTIVE = 14;
		static const uint BUTFAFNEWAVAIL = 15;
		static const uint BUTFAFDELETEAVAIL = 16;
		static const uint TXFFAFFIDAVAIL = 17;
		static const uint TXFFAFFIDACTIVE = 18;
		static const uint TXFFAFIDTAVAIL = 19;
		static const uint TXFFAFIDTACTIVE = 20;
		static const uint TXFFAFACTAVAIL = 21;
		static const uint TXFFAFACTACTIVE = 22;
		static const uint TXFFAFFETAVAIL = 23;
		static const uint TXFFAFFETACTIVE = 24;
		static const uint TXFFAFFTIAVAIL = 25;
		static const uint TXFFAFFTIACTIVE = 26;
		static const uint TXFFAFFDTAVAIL = 27;
		static const uint TXFFAFFDTACTIVE = 28;
		static const uint TXFFAFFSKAVAIL = 29;
		static const uint TXFFAFFSKACTIVE = 30;
		static const uint TXFFAFFSMAVAIL = 31;
		static const uint TXFFAFFSMACTIVE = 32;
		static const uint TXFFAFFATAVAIL = 33;
		static const uint TXFFAFFATACTIVE = 34;
		static const uint TXFFAFRTEAVAIL = 35;
		static const uint TXFFAFRTEACTIVE = 36;
		static const uint TXFFAFADTAVAIL = 37;
		static const uint TXFFAFADTACTIVE = 38;
		static const uint TXFFAFEATAVAIL = 39;
		static const uint TXFFAFEATACTIVE = 40;
		static const uint TXFFAFAATAVAIL = 41;
		static const uint TXFFAFAATACTIVE = 42;
		static const uint TXFFAFDVTAVAIL = 43;
		static const uint TXFFAFDVTACTIVE = 44;
		static const uint TXFFAFORGAVAIL = 45;
		static const uint TXFFAFORGACTIVE = 46;
		static const uint TXFFAFDSTAVAIL = 47;
		static const uint TXFFAFDSTACTIVE = 48;
		static const uint TXFFAFONMAVAIL = 49;
		static const uint TXFFAFONMACTIVE = 50;
		static const uint TXFFAFOCTAVAIL = 51;
		static const uint TXFFAFOCTACTIVE = 52;
		static const uint TXFFAFDNMAVAIL = 53;
		static const uint TXFFAFDNMACTIVE = 54;
		static const uint TXFFAFDCTAVAIL = 55;
		static const uint TXFFAFDCTACTIVE = 56;
		static const uint BUTEQPNEWAVAIL = 57;
		static const uint BUTEQPDELETEAVAIL = 58;
		static const uint TXTEQPOPRAVAIL = 59;
		static const uint TXTEQPOPRACTIVE = 60;
		static const uint BUTEQPOPRVIEWAVAIL = 61;
		static const uint BUTEQPOPRVIEWACTIVE = 62;
		static const uint TXTEQPPTYAVAIL = 63;
		static const uint TXTEQPPTYACTIVE = 64;
		static const uint BUTEQPPTYVIEWAVAIL = 65;
		static const uint BUTEQPPTYVIEWACTIVE = 66;
		static const uint PUPEQPETYAVAIL = 67;
		static const uint PUPEQPETYACTIVE = 68;
		static const uint BUTEQPETYEDITAVAIL = 69;
		static const uint CHKEQPFIBAVAIL = 70;
		static const uint CHKEQPFIBACTIVE = 71;

	public:
		StatShr(const bool TxfEqpEtyValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool TxtTtbActive = true, const bool ButTtbViewAvail = true, const bool ButTtbViewActive = true, const bool TxtLegActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfXsaActive = true, const bool TxfXsoActive = true, const bool ChkCdnActive = true, const bool ChkSdnActive = true, const bool ButFafNewAvail = true, const bool ButFafDeleteAvail = true, const bool TxfFafFidAvail = true, const bool TxfFafFidActive = true, const bool TxfFafIdtAvail = true, const bool TxfFafIdtActive = true, const bool TxfFafActAvail = true, const bool TxfFafActActive = true, const bool TxfFafFetAvail = true, const bool TxfFafFetActive = true, const bool TxfFafFtiAvail = true, const bool TxfFafFtiActive = true, const bool TxfFafFdtAvail = true, const bool TxfFafFdtActive = true, const bool TxfFafFskAvail = true, const bool TxfFafFskActive = true, const bool TxfFafFsmAvail = true, const bool TxfFafFsmActive = true, const bool TxfFafFatAvail = true, const bool TxfFafFatActive = true, const bool TxfFafRteAvail = true, const bool TxfFafRteActive = true, const bool TxfFafAdtAvail = true, const bool TxfFafAdtActive = true, const bool TxfFafEatAvail = true, const bool TxfFafEatActive = true, const bool TxfFafAatAvail = true, const bool TxfFafAatActive = true, const bool TxfFafDvtAvail = true, const bool TxfFafDvtActive = true, const bool TxfFafOrgAvail = true, const bool TxfFafOrgActive = true, const bool TxfFafDstAvail = true, const bool TxfFafDstActive = true, const bool TxfFafOnmAvail = true, const bool TxfFafOnmActive = true, const bool TxfFafOctAvail = true, const bool TxfFafOctActive = true, const bool TxfFafDnmAvail = true, const bool TxfFafDnmActive = true, const bool TxfFafDctAvail = true, const bool TxfFafDctActive = true, const bool ButEqpNewAvail = true, const bool ButEqpDeleteAvail = true, const bool TxtEqpOprAvail = true, const bool TxtEqpOprActive = true, const bool ButEqpOprViewAvail = true, const bool ButEqpOprViewActive = true, const bool TxtEqpPtyAvail = true, const bool TxtEqpPtyActive = true, const bool ButEqpPtyViewAvail = true, const bool ButEqpPtyViewActive = true, const bool PupEqpEtyAvail = true, const bool PupEqpEtyActive = true, const bool ButEqpEtyEditAvail = true, const bool ChkEqpFibAvail = true, const bool ChkEqpFibActive = true);

	public:
		bool TxfEqpEtyValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool TxtTtbActive;
		bool ButTtbViewAvail;
		bool ButTtbViewActive;
		bool TxtLegActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfXsaActive;
		bool TxfXsoActive;
		bool ChkCdnActive;
		bool ChkSdnActive;
		bool ButFafNewAvail;
		bool ButFafDeleteAvail;
		bool TxfFafFidAvail;
		bool TxfFafFidActive;
		bool TxfFafIdtAvail;
		bool TxfFafIdtActive;
		bool TxfFafActAvail;
		bool TxfFafActActive;
		bool TxfFafFetAvail;
		bool TxfFafFetActive;
		bool TxfFafFtiAvail;
		bool TxfFafFtiActive;
		bool TxfFafFdtAvail;
		bool TxfFafFdtActive;
		bool TxfFafFskAvail;
		bool TxfFafFskActive;
		bool TxfFafFsmAvail;
		bool TxfFafFsmActive;
		bool TxfFafFatAvail;
		bool TxfFafFatActive;
		bool TxfFafRteAvail;
		bool TxfFafRteActive;
		bool TxfFafAdtAvail;
		bool TxfFafAdtActive;
		bool TxfFafEatAvail;
		bool TxfFafEatActive;
		bool TxfFafAatAvail;
		bool TxfFafAatActive;
		bool TxfFafDvtAvail;
		bool TxfFafDvtActive;
		bool TxfFafOrgAvail;
		bool TxfFafOrgActive;
		bool TxfFafDstAvail;
		bool TxfFafDstActive;
		bool TxfFafOnmAvail;
		bool TxfFafOnmActive;
		bool TxfFafOctAvail;
		bool TxfFafOctActive;
		bool TxfFafDnmAvail;
		bool TxfFafDnmActive;
		bool TxfFafDctAvail;
		bool TxfFafDctActive;
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
	  * Tag (full: TagBrlyFltDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTTB = 3;
		static const uint CPTLEG = 4;
		static const uint CPTSTA = 5;
		static const uint CPTSTO = 6;
		static const uint CPTXSA = 7;
		static const uint CPTXSO = 8;
		static const uint CPTCDN = 9;
		static const uint CPTSDN = 10;
		static const uint HDGFAF = 11;
		static const uint CPTFAFFID = 12;
		static const uint CPTFAFIDT = 13;
		static const uint CPTFAFACT = 14;
		static const uint CPTFAFFET = 15;
		static const uint CPTFAFFTI = 16;
		static const uint CPTFAFFDT = 17;
		static const uint CPTFAFFSK = 18;
		static const uint CPTFAFFSM = 19;
		static const uint CPTFAFFAT = 20;
		static const uint CPTFAFRTE = 21;
		static const uint CPTFAFADT = 22;
		static const uint CPTFAFEAT = 23;
		static const uint CPTFAFAAT = 24;
		static const uint CPTFAFDVT = 25;
		static const uint CPTFAFORG = 26;
		static const uint CPTFAFDST = 27;
		static const uint CPTFAFONM = 28;
		static const uint CPTFAFOCT = 29;
		static const uint CPTFAFDNM = 30;
		static const uint CPTFAFDCT = 31;
		static const uint HDGEQP = 32;
		static const uint CPTEQPOPR = 33;
		static const uint CPTEQPPTY = 34;
		static const uint CPTEQPETY = 35;
		static const uint CPTEQPFIB = 36;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTtb = "", const string& CptLeg = "", const string& CptSta = "", const string& CptSto = "", const string& CptXsa = "", const string& CptXso = "", const string& CptCdn = "", const string& CptSdn = "", const string& HdgFaf = "", const string& CptFafFid = "", const string& CptFafIdt = "", const string& CptFafAct = "", const string& CptFafFet = "", const string& CptFafFti = "", const string& CptFafFdt = "", const string& CptFafFsk = "", const string& CptFafFsm = "", const string& CptFafFat = "", const string& CptFafRte = "", const string& CptFafAdt = "", const string& CptFafEat = "", const string& CptFafAat = "", const string& CptFafDvt = "", const string& CptFafOrg = "", const string& CptFafDst = "", const string& CptFafOnm = "", const string& CptFafOct = "", const string& CptFafDnm = "", const string& CptFafDct = "", const string& HdgEqp = "", const string& CptEqpOpr = "", const string& CptEqpPty = "", const string& CptEqpEty = "", const string& CptEqpFib = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTtb;
		string CptLeg;
		string CptSta;
		string CptSto;
		string CptXsa;
		string CptXso;
		string CptCdn;
		string CptSdn;
		string HdgFaf;
		string CptFafFid;
		string CptFafIdt;
		string CptFafAct;
		string CptFafFet;
		string CptFafFti;
		string CptFafFdt;
		string CptFafFsk;
		string CptFafFsm;
		string CptFafFat;
		string CptFafRte;
		string CptFafAdt;
		string CptFafEat;
		string CptFafAat;
		string CptFafDvt;
		string CptFafOrg;
		string CptFafDst;
		string CptFafOnm;
		string CptFafOct;
		string CptFafDnm;
		string CptFafDct;
		string HdgEqp;
		string CptEqpOpr;
		string CptEqpPty;
		string CptEqpEty;
		string CptEqpFib;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppBrlyFltDetailData)
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
		* DpchAppDo (full: DpchAppBrlyFltDetailDo)
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
		* DpchEngData (full: DpchEngBrlyFltDetailData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPEQPETY = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupEqpEty;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

