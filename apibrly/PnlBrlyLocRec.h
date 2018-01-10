/**
  * \file PnlBrlyLocRec.h
  * API code for job PnlBrlyLocRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYLOCREC_H
#define PNLBRLYLOCREC_H

#include "ApiBrly_blks.h"

#define VecVBrlyLocRecDo PnlBrlyLocRec::VecVDo

#define ContInfBrlyLocRec PnlBrlyLocRec::ContInf
#define StatAppBrlyLocRec PnlBrlyLocRec::StatApp
#define StatShrBrlyLocRec PnlBrlyLocRec::StatShr
#define TagBrlyLocRec PnlBrlyLocRec::Tag

#define DpchAppBrlyLocRecDo PnlBrlyLocRec::DpchAppDo
#define DpchEngBrlyLocRecData PnlBrlyLocRec::DpchEngData

/**
  * PnlBrlyLocRec
  */
namespace PnlBrlyLocRec {
	/**
		* VecVDo (full: VecVBrlyLocRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyLocRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppBrlyLocRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEMAP = 2;
		static const uint INITDONEBGN1NLEG = 3;
		static const uint INITDONEEND1NLEG = 4;
		static const uint INITDONEEQP1NNODE = 5;
		static const uint INITDONEMNSEGMENT = 6;
		static const uint INITDONEPROXORGMNLOCATION = 7;
		static const uint INITDONEVISORGMNLOCATION = 8;
		static const uint INITDONEMNLEG = 9;
		static const uint INITDONEMNFLIGHT = 10;
		static const uint INITDONEEQPMNCONNECTION = 11;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneMap = false, const bool initdoneBgn1NLeg = false, const bool initdoneEnd1NLeg = false, const bool initdoneEqp1NNode = false, const bool initdoneMNSegment = false, const bool initdoneProxOrgMNLocation = false, const bool initdoneVisOrgMNLocation = false, const bool initdoneMNLeg = false, const bool initdoneMNFlight = false, const bool initdoneEqpMNConnection = false);

	public:
		bool initdoneDetail;
		bool initdoneMap;
		bool initdoneBgn1NLeg;
		bool initdoneEnd1NLeg;
		bool initdoneEqp1NNode;
		bool initdoneMNSegment;
		bool initdoneProxOrgMNLocation;
		bool initdoneVisOrgMNLocation;
		bool initdoneMNLeg;
		bool initdoneMNFlight;
		bool initdoneEqpMNConnection;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyLocRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFMAP = 3;
		static const uint SCRJREFBGN1NLEG = 4;
		static const uint PNLBGN1NLEGAVAIL = 5;
		static const uint SCRJREFEND1NLEG = 6;
		static const uint PNLEND1NLEGAVAIL = 7;
		static const uint SCRJREFEQP1NNODE = 8;
		static const uint PNLEQP1NNODEAVAIL = 9;
		static const uint SCRJREFMNSEGMENT = 10;
		static const uint SCRJREFPROXORGMNLOCATION = 11;
		static const uint SCRJREFVISORGMNLOCATION = 12;
		static const uint SCRJREFMNLEG = 13;
		static const uint SCRJREFMNFLIGHT = 14;
		static const uint SCRJREFEQPMNCONNECTION = 15;
		static const uint PNLEQPMNCONNECTIONAVAIL = 16;
		static const uint BUTREGULARIZEACTIVE = 17;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefMap = "", const string& scrJrefBgn1NLeg = "", const bool pnlbgn1nlegAvail = false, const string& scrJrefEnd1NLeg = "", const bool pnlend1nlegAvail = false, const string& scrJrefEqp1NNode = "", const bool pnleqp1nnodeAvail = false, const string& scrJrefMNSegment = "", const string& scrJrefProxOrgMNLocation = "", const string& scrJrefVisOrgMNLocation = "", const string& scrJrefMNLeg = "", const string& scrJrefMNFlight = "", const string& scrJrefEqpMNConnection = "", const bool pnleqpmnconnectionAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		string scrJrefDetail;
		string scrJrefMap;
		string scrJrefBgn1NLeg;
		bool pnlbgn1nlegAvail;
		string scrJrefEnd1NLeg;
		bool pnlend1nlegAvail;
		string scrJrefEqp1NNode;
		bool pnleqp1nnodeAvail;
		string scrJrefMNSegment;
		string scrJrefProxOrgMNLocation;
		string scrJrefVisOrgMNLocation;
		string scrJrefMNLeg;
		string scrJrefMNFlight;
		string scrJrefEqpMNConnection;
		bool pnleqpmnconnectionAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyLocRec)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;

	public:
		Tag(const string& Cpt = "");

	public:
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppBrlyLocRecDo)
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
		* DpchEngData (full: DpchEngBrlyLocRecData)
		*/
	class DpchEngData : public DpchEngBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		string getSrefsMask();

		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

