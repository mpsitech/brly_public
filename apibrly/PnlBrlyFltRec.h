/**
  * \file PnlBrlyFltRec.h
  * API code for job PnlBrlyFltRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef PNLBRLYFLTREC_H
#define PNLBRLYFLTREC_H

#include "ApiBrly_blks.h"

#define VecVBrlyFltRecDo PnlBrlyFltRec::VecVDo

#define ContInfBrlyFltRec PnlBrlyFltRec::ContInf
#define StatAppBrlyFltRec PnlBrlyFltRec::StatApp
#define StatShrBrlyFltRec PnlBrlyFltRec::StatShr
#define TagBrlyFltRec PnlBrlyFltRec::Tag

#define DpchAppBrlyFltRecDo PnlBrlyFltRec::DpchAppDo
#define DpchEngBrlyFltRecData PnlBrlyFltRec::DpchEngData

/**
  * PnlBrlyFltRec
  */
namespace PnlBrlyFltRec {
	/**
		* VecVDo (full: VecVBrlyFltRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfBrlyFltRec)
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
	  * StatApp (full: StatAppBrlyFltRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEFAFAWAYPOINT = 3;
		static const uint INITDONE1NCONNECTION = 4;
		static const uint INITDONEREF1NSEGMENT = 5;
		static const uint INITDONEEQP1NNODE = 6;
		static const uint INITDONEMNLOCATION = 7;
		static const uint INITDONEMNCONNECTION = 8;
		static const uint INITDONEORGMNFLIGHT = 9;
		static const uint INITDONEEQPMNCONNECTION = 10;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneFafAWaypoint = false, const bool initdone1NConnection = false, const bool initdoneRef1NSegment = false, const bool initdoneEqp1NNode = false, const bool initdoneMNLocation = false, const bool initdoneMNConnection = false, const bool initdoneOrgMNFlight = false, const bool initdoneEqpMNConnection = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneFafAWaypoint;
		bool initdone1NConnection;
		bool initdoneRef1NSegment;
		bool initdoneEqp1NNode;
		bool initdoneMNLocation;
		bool initdoneMNConnection;
		bool initdoneOrgMNFlight;
		bool initdoneEqpMNConnection;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrBrlyFltRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXBRLYVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFFAFAWAYPOINT = 4;
		static const uint PNLFAFAWAYPOINTAVAIL = 5;
		static const uint SCRJREF1NCONNECTION = 6;
		static const uint SCRJREFREF1NSEGMENT = 7;
		static const uint SCRJREFEQP1NNODE = 8;
		static const uint PNLEQP1NNODEAVAIL = 9;
		static const uint SCRJREFMNLOCATION = 10;
		static const uint SCRJREFMNCONNECTION = 11;
		static const uint SCRJREFORGMNFLIGHT = 12;
		static const uint SCRJREFEQPMNCONNECTION = 13;
		static const uint PNLEQPMNCONNECTIONAVAIL = 14;
		static const uint BUTREGULARIZEACTIVE = 15;

	public:
		StatShr(const uint ixBrlyVExpstate = VecBrlyVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefFafAWaypoint = "", const bool pnlfafawaypointAvail = false, const string& scrJref1NConnection = "", const string& scrJrefRef1NSegment = "", const string& scrJrefEqp1NNode = "", const bool pnleqp1nnodeAvail = false, const string& scrJrefMNLocation = "", const string& scrJrefMNConnection = "", const string& scrJrefOrgMNFlight = "", const string& scrJrefEqpMNConnection = "", const bool pnleqpmnconnectionAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixBrlyVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefFafAWaypoint;
		bool pnlfafawaypointAvail;
		string scrJref1NConnection;
		string scrJrefRef1NSegment;
		string scrJrefEqp1NNode;
		bool pnleqp1nnodeAvail;
		string scrJrefMNLocation;
		string scrJrefMNConnection;
		string scrJrefOrgMNFlight;
		string scrJrefEqpMNConnection;
		bool pnleqpmnconnectionAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagBrlyFltRec)
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
		* DpchAppDo (full: DpchAppBrlyFltRecDo)
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
		* DpchEngData (full: DpchEngBrlyFltRecData)
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

