/**
  * \file VecBrlyVCall.cpp
  * vector VecBrlyVCall (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "VecBrlyVCall.h"

/******************************************************************************
 namespace VecBrlyVCall
 ******************************************************************************/

uint VecBrlyVCall::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "callbrlyaccess") return CALLBRLYACCESS;
	else if (s == "callbrlyboolvalpreset") return CALLBRLYBOOLVALPRESET;
	else if (s == "callbrlycon.flteq") return CALLBRLYCON_FLTEQ;
	else if (s == "callbrlycon.ttbeq") return CALLBRLYCON_TTBEQ;
	else if (s == "callbrlyconmod") return CALLBRLYCONMOD;
	else if (s == "callbrlyconmod.coreq") return CALLBRLYCONMOD_COREQ;
	else if (s == "callbrlyconmod.flteq") return CALLBRLYCONMOD_FLTEQ;
	else if (s == "callbrlyconreqpmod.coneq") return CALLBRLYCONREQPMOD_CONEQ;
	else if (s == "callbrlyconreqpmod.eqpeq") return CALLBRLYCONREQPMOD_EQPEQ;
	else if (s == "callbrlyconrfltmod.coneq") return CALLBRLYCONRFLTMOD_CONEQ;
	else if (s == "callbrlyconrfltmod.flteq") return CALLBRLYCONRFLTMOD_FLTEQ;
	else if (s == "callbrlyconrsegmod.coneq") return CALLBRLYCONRSEGMOD_CONEQ;
	else if (s == "callbrlyconrsegmod.segeq") return CALLBRLYCONRSEGMOD_SEGEQ;
	else if (s == "callbrlyconupd.refeq") return CALLBRLYCONUPD_REFEQ;
	else if (s == "callbrlycrdactive") return CALLBRLYCRDACTIVE;
	else if (s == "callbrlycrdclose") return CALLBRLYCRDCLOSE;
	else if (s == "callbrlycrdopen") return CALLBRLYCRDOPEN;
	else if (s == "callbrlyctlaparmod.usreq") return CALLBRLYCTLAPARMOD_USREQ;
	else if (s == "callbrlydblvalpreset") return CALLBRLYDBLVALPRESET;
	else if (s == "callbrlydescr") return CALLBRLYDESCR;
	else if (s == "callbrlydlgclose") return CALLBRLYDLGCLOSE;
	else if (s == "callbrlyeqp.hkteq") return CALLBRLYEQP_HKTEQ;
	else if (s == "callbrlyeqp.insbs") return CALLBRLYEQP_INSBS;
	else if (s == "callbrlyeqp.opreq") return CALLBRLYEQP_OPREQ;
	else if (s == "callbrlyeqp.ptyeq") return CALLBRLYEQP_PTYEQ;
	else if (s == "callbrlyeqpmod") return CALLBRLYEQPMOD;
	else if (s == "callbrlyeqpmod.hkthkueq") return CALLBRLYEQPMOD_HKTHKUEQ;
	else if (s == "callbrlyeqpmod.opreq") return CALLBRLYEQPMOD_OPREQ;
	else if (s == "callbrlyeqpmod.ptyeq") return CALLBRLYEQPMOD_PTYEQ;
	else if (s == "callbrlyeqpupd.refeq") return CALLBRLYEQPUPD_REFEQ;
	else if (s == "callbrlyfafawptmod.fafeq") return CALLBRLYFAFAWPTMOD_FAFEQ;
	else if (s == "callbrlyfafmod") return CALLBRLYFAFMOD;
	else if (s == "callbrlyfafupd.refeq") return CALLBRLYFAFUPD_REFEQ;
	else if (s == "callbrlyfil.clueq") return CALLBRLYFIL_CLUEQ;
	else if (s == "callbrlyfil.reteq") return CALLBRLYFIL_RETEQ;
	else if (s == "callbrlyfil.reueq") return CALLBRLYFIL_REUEQ;
	else if (s == "callbrlyfilmod") return CALLBRLYFILMOD;
	else if (s == "callbrlyfilmod.clueq") return CALLBRLYFILMOD_CLUEQ;
	else if (s == "callbrlyfilmod.retreueq") return CALLBRLYFILMOD_RETREUEQ;
	else if (s == "callbrlyfilupd.refeq") return CALLBRLYFILUPD_REFEQ;
	else if (s == "callbrlyflt.eqpeq") return CALLBRLYFLT_EQPEQ;
	else if (s == "callbrlyflt.fafeq") return CALLBRLYFLT_FAFEQ;
	else if (s == "callbrlyflt.ttbeq") return CALLBRLYFLT_TTBEQ;
	else if (s == "callbrlyfltmod") return CALLBRLYFLTMOD;
	else if (s == "callbrlyfltmod.legeq") return CALLBRLYFLTMOD_LEGEQ;
	else if (s == "callbrlyfltmod.ttbeq") return CALLBRLYFLTMOD_TTBEQ;
	else if (s == "callbrlyfltrfltmod.dfleq") return CALLBRLYFLTRFLTMOD_DFLEQ;
	else if (s == "callbrlyfltrfltmod.ofleq") return CALLBRLYFLTRFLTMOD_OFLEQ;
	else if (s == "callbrlyfltrlocmod.flteq") return CALLBRLYFLTRLOCMOD_FLTEQ;
	else if (s == "callbrlyfltrlocmod.loceq") return CALLBRLYFLTRLOCMOD_LOCEQ;
	else if (s == "callbrlyfltupd.refeq") return CALLBRLYFLTUPD_REFEQ;
	else if (s == "callbrlyhusrrunvmod.crdusreq") return CALLBRLYHUSRRUNVMOD_CRDUSREQ;
	else if (s == "callbrlyintvalpreset") return CALLBRLYINTVALPRESET;
	else if (s == "callbrlyixpreset") return CALLBRLYIXPRESET;
	else if (s == "callbrlyklkjkeymod.klsakeyeq") return CALLBRLYKLKJKEYMOD_KLSAKEYEQ;
	else if (s == "callbrlyklsakeymod.klseq") return CALLBRLYKLSAKEYMOD_KLSEQ;
	else if (s == "callbrlyklsakeymod.klsmtburfeq") return CALLBRLYKLSAKEYMOD_KLSMTBURFEQ;
	else if (s == "callbrlyleg.clueq") return CALLBRLYLEG_CLUEQ;
	else if (s == "callbrlyleg.insbs") return CALLBRLYLEG_INSBS;
	else if (s == "callbrlyleg.typeq") return CALLBRLYLEG_TYPEQ;
	else if (s == "callbrlylegmod") return CALLBRLYLEGMOD;
	else if (s == "callbrlylegmod.bloeq") return CALLBRLYLEGMOD_BLOEQ;
	else if (s == "callbrlylegmod.clueq") return CALLBRLYLEGMOD_CLUEQ;
	else if (s == "callbrlylegmod.eloeq") return CALLBRLYLEGMOD_ELOEQ;
	else if (s == "callbrlylegrlegmod.dlgeq") return CALLBRLYLEGRLEGMOD_DLGEQ;
	else if (s == "callbrlylegrlegmod.olgeq") return CALLBRLYLEGRLEGMOD_OLGEQ;
	else if (s == "callbrlylegrlocmod.legeq") return CALLBRLYLEGRLOCMOD_LEGEQ;
	else if (s == "callbrlylegrlocmod.loceq") return CALLBRLYLEGRLOCMOD_LOCEQ;
	else if (s == "callbrlylegupd.refeq") return CALLBRLYLEGUPD_REFEQ;
	else if (s == "callbrlyloc.eqpeq") return CALLBRLYLOC_EQPEQ;
	else if (s == "callbrlyloc.insbs") return CALLBRLYLOC_INSBS;
	else if (s == "callbrlyloc.typeq") return CALLBRLYLOC_TYPEQ;
	else if (s == "callbrlylocmod") return CALLBRLYLOCMOD;
	else if (s == "callbrlylocmod.regeq") return CALLBRLYLOCMOD_REGEQ;
	else if (s == "callbrlylocrsegmod.loceq") return CALLBRLYLOCRSEGMOD_LOCEQ;
	else if (s == "callbrlylocrsegmod.segeq") return CALLBRLYLOCRSEGMOD_SEGEQ;
	else if (s == "callbrlylocupd.refeq") return CALLBRLYLOCUPD_REFEQ;
	else if (s == "callbrlylog") return CALLBRLYLOG;
	else if (s == "callbrlylogout") return CALLBRLYLOGOUT;
	else if (s == "callbrlymastclaim") return CALLBRLYMASTCLAIM;
	else if (s == "callbrlymastslvchg") return CALLBRLYMASTSLVCHG;
	else if (s == "callbrlymonstatchg") return CALLBRLYMONSTATCHG;
	else if (s == "callbrlyndemod") return CALLBRLYNDEMOD;
	else if (s == "callbrlyndemod.eqpeq") return CALLBRLYNDEMOD_EQPEQ;
	else if (s == "callbrlyndemod.rlyeq") return CALLBRLYNDEMOD_RLYEQ;
	else if (s == "callbrlyndemod.supeq") return CALLBRLYNDEMOD_SUPEQ;
	else if (s == "callbrlyndeupd.refeq") return CALLBRLYNDEUPD_REFEQ;
	else if (s == "callbrlynodechg") return CALLBRLYNODECHG;
	else if (s == "callbrlyoprmod") return CALLBRLYOPRMOD;
	else if (s == "callbrlyoprupd.refeq") return CALLBRLYOPRUPD_REFEQ;
	else if (s == "callbrlyplocrlocmod.dloeq") return CALLBRLYPLOCRLOCMOD_DLOEQ;
	else if (s == "callbrlyplocrlocmod.oloeq") return CALLBRLYPLOCRLOCMOD_OLOEQ;
	else if (s == "callbrlyprsadetmod.prseq") return CALLBRLYPRSADETMOD_PRSEQ;
	else if (s == "callbrlyprsjlnmmod.prseq") return CALLBRLYPRSJLNMMOD_PRSEQ;
	else if (s == "callbrlyprsmod") return CALLBRLYPRSMOD;
	else if (s == "callbrlyprsupd.refeq") return CALLBRLYPRSUPD_REFEQ;
	else if (s == "callbrlyptymod") return CALLBRLYPTYMOD;
	else if (s == "callbrlyptyupd.refeq") return CALLBRLYPTYUPD_REFEQ;
	else if (s == "callbrlyrefpreset") return CALLBRLYREFPRESET;
	else if (s == "callbrlyrefspreset") return CALLBRLYREFSPRESET;
	else if (s == "callbrlyreg.insbs") return CALLBRLYREG_INSBS;
	else if (s == "callbrlyreg.isleaf") return CALLBRLYREG_ISLEAF;
	else if (s == "callbrlyreg.supeq") return CALLBRLYREG_SUPEQ;
	else if (s == "callbrlyregadssmod.regeq") return CALLBRLYREGADSSMOD_REGEQ;
	else if (s == "callbrlyregjmod.regeq") return CALLBRLYREGJMOD_REGEQ;
	else if (s == "callbrlyregjtitmod.regeq") return CALLBRLYREGJTITMOD_REGEQ;
	else if (s == "callbrlyregmod") return CALLBRLYREGMOD;
	else if (s == "callbrlyregmod.supeq") return CALLBRLYREGMOD_SUPEQ;
	else if (s == "callbrlyregupd.refeq") return CALLBRLYREGUPD_REFEQ;
	else if (s == "callbrlyrly.coneq") return CALLBRLYRLY_CONEQ;
	else if (s == "callbrlyrlymod") return CALLBRLYRLYMOD;
	else if (s == "callbrlyrlymod.coneq") return CALLBRLYRLYMOD_CONEQ;
	else if (s == "callbrlyrlyupd.refeq") return CALLBRLYRLYUPD_REFEQ;
	else if (s == "callbrlyscr") return CALLBRLYSCR;
	else if (s == "callbrlyseg.reteq") return CALLBRLYSEG_RETEQ;
	else if (s == "callbrlyseg.reueq") return CALLBRLYSEG_REUEQ;
	else if (s == "callbrlysegmod") return CALLBRLYSEGMOD;
	else if (s == "callbrlysegmod.retreueq") return CALLBRLYSEGMOD_RETREUEQ;
	else if (s == "callbrlysegrsegmod.dsgeq") return CALLBRLYSEGRSEGMOD_DSGEQ;
	else if (s == "callbrlysegrsegmod.osgeq") return CALLBRLYSEGRSEGMOD_OSGEQ;
	else if (s == "callbrlysegupd.refeq") return CALLBRLYSEGUPD_REFEQ;
	else if (s == "callbrlysesmod") return CALLBRLYSESMOD;
	else if (s == "callbrlysesmod.usreq") return CALLBRLYSESMOD_USREQ;
	else if (s == "callbrlysesupd.refeq") return CALLBRLYSESUPD_REFEQ;
	else if (s == "callbrlysrefpreset") return CALLBRLYSREFPRESET;
	else if (s == "callbrlystatchg") return CALLBRLYSTATCHG;
	else if (s == "callbrlystgchg") return CALLBRLYSTGCHG;
	else if (s == "callbrlystubchg") return CALLBRLYSTUBCHG;
	else if (s == "callbrlyttb.fileq") return CALLBRLYTTB_FILEQ;
	else if (s == "callbrlyttbmod") return CALLBRLYTTBMOD;
	else if (s == "callbrlyttbupd.refeq") return CALLBRLYTTBUPD_REFEQ;
	else if (s == "callbrlytxtvalpreset") return CALLBRLYTXTVALPRESET;
	else if (s == "callbrlyusgaaccmod.usgeq") return CALLBRLYUSGAACCMOD_USGEQ;
	else if (s == "callbrlyusgmod") return CALLBRLYUSGMOD;
	else if (s == "callbrlyusgupd.refeq") return CALLBRLYUSGUPD_REFEQ;
	else if (s == "callbrlyusr.prseq") return CALLBRLYUSR_PRSEQ;
	else if (s == "callbrlyusr.usgeq") return CALLBRLYUSR_USGEQ;
	else if (s == "callbrlyusraaccmod.usreq") return CALLBRLYUSRAACCMOD_USREQ;
	else if (s == "callbrlyusrjstemod.usreq") return CALLBRLYUSRJSTEMOD_USREQ;
	else if (s == "callbrlyusrmod") return CALLBRLYUSRMOD;
	else if (s == "callbrlyusrrusgmod.usgeq") return CALLBRLYUSRRUSGMOD_USGEQ;
	else if (s == "callbrlyusrrusgmod.usreq") return CALLBRLYUSRRUSGMOD_USREQ;
	else if (s == "callbrlyusrupd.refeq") return CALLBRLYUSRUPD_REFEQ;
	else if (s == "callbrlyvlocrlocmod.dloeq") return CALLBRLYVLOCRLOCMOD_DLOEQ;
	else if (s == "callbrlyvlocrlocmod.oloeq") return CALLBRLYVLOCRLOCMOD_OLOEQ;

	return(0);
};

string VecBrlyVCall::getSref(
			const uint ix
		) {
	if (ix == CALLBRLYACCESS) return("CallBrlyAccess");
	else if (ix == CALLBRLYBOOLVALPRESET) return("CallBrlyBoolvalPreSet");
	else if (ix == CALLBRLYCON_FLTEQ) return("CallBrlyCon.fltEq");
	else if (ix == CALLBRLYCON_TTBEQ) return("CallBrlyCon.ttbEq");
	else if (ix == CALLBRLYCONMOD) return("CallBrlyConMod");
	else if (ix == CALLBRLYCONMOD_COREQ) return("CallBrlyConMod.corEq");
	else if (ix == CALLBRLYCONMOD_FLTEQ) return("CallBrlyConMod.fltEq");
	else if (ix == CALLBRLYCONREQPMOD_CONEQ) return("CallBrlyConReqpMod.conEq");
	else if (ix == CALLBRLYCONREQPMOD_EQPEQ) return("CallBrlyConReqpMod.eqpEq");
	else if (ix == CALLBRLYCONRFLTMOD_CONEQ) return("CallBrlyConRfltMod.conEq");
	else if (ix == CALLBRLYCONRFLTMOD_FLTEQ) return("CallBrlyConRfltMod.fltEq");
	else if (ix == CALLBRLYCONRSEGMOD_CONEQ) return("CallBrlyConRsegMod.conEq");
	else if (ix == CALLBRLYCONRSEGMOD_SEGEQ) return("CallBrlyConRsegMod.segEq");
	else if (ix == CALLBRLYCONUPD_REFEQ) return("CallBrlyConUpd.refEq");
	else if (ix == CALLBRLYCRDACTIVE) return("CallBrlyCrdActive");
	else if (ix == CALLBRLYCRDCLOSE) return("CallBrlyCrdClose");
	else if (ix == CALLBRLYCRDOPEN) return("CallBrlyCrdOpen");
	else if (ix == CALLBRLYCTLAPARMOD_USREQ) return("CallBrlyCtlAparMod.usrEq");
	else if (ix == CALLBRLYDBLVALPRESET) return("CallBrlyDblvalPreSet");
	else if (ix == CALLBRLYDESCR) return("CallBrlyDescr");
	else if (ix == CALLBRLYDLGCLOSE) return("CallBrlyDlgClose");
	else if (ix == CALLBRLYEQP_HKTEQ) return("CallBrlyEqp.hktEq");
	else if (ix == CALLBRLYEQP_INSBS) return("CallBrlyEqp.inSbs");
	else if (ix == CALLBRLYEQP_OPREQ) return("CallBrlyEqp.oprEq");
	else if (ix == CALLBRLYEQP_PTYEQ) return("CallBrlyEqp.ptyEq");
	else if (ix == CALLBRLYEQPMOD) return("CallBrlyEqpMod");
	else if (ix == CALLBRLYEQPMOD_HKTHKUEQ) return("CallBrlyEqpMod.hktHkuEq");
	else if (ix == CALLBRLYEQPMOD_OPREQ) return("CallBrlyEqpMod.oprEq");
	else if (ix == CALLBRLYEQPMOD_PTYEQ) return("CallBrlyEqpMod.ptyEq");
	else if (ix == CALLBRLYEQPUPD_REFEQ) return("CallBrlyEqpUpd.refEq");
	else if (ix == CALLBRLYFAFAWPTMOD_FAFEQ) return("CallBrlyFafAwptMod.fafEq");
	else if (ix == CALLBRLYFAFMOD) return("CallBrlyFafMod");
	else if (ix == CALLBRLYFAFUPD_REFEQ) return("CallBrlyFafUpd.refEq");
	else if (ix == CALLBRLYFIL_CLUEQ) return("CallBrlyFil.cluEq");
	else if (ix == CALLBRLYFIL_RETEQ) return("CallBrlyFil.retEq");
	else if (ix == CALLBRLYFIL_REUEQ) return("CallBrlyFil.reuEq");
	else if (ix == CALLBRLYFILMOD) return("CallBrlyFilMod");
	else if (ix == CALLBRLYFILMOD_CLUEQ) return("CallBrlyFilMod.cluEq");
	else if (ix == CALLBRLYFILMOD_RETREUEQ) return("CallBrlyFilMod.retReuEq");
	else if (ix == CALLBRLYFILUPD_REFEQ) return("CallBrlyFilUpd.refEq");
	else if (ix == CALLBRLYFLT_EQPEQ) return("CallBrlyFlt.eqpEq");
	else if (ix == CALLBRLYFLT_FAFEQ) return("CallBrlyFlt.fafEq");
	else if (ix == CALLBRLYFLT_TTBEQ) return("CallBrlyFlt.ttbEq");
	else if (ix == CALLBRLYFLTMOD) return("CallBrlyFltMod");
	else if (ix == CALLBRLYFLTMOD_LEGEQ) return("CallBrlyFltMod.legEq");
	else if (ix == CALLBRLYFLTMOD_TTBEQ) return("CallBrlyFltMod.ttbEq");
	else if (ix == CALLBRLYFLTRFLTMOD_DFLEQ) return("CallBrlyFltRfltMod.dflEq");
	else if (ix == CALLBRLYFLTRFLTMOD_OFLEQ) return("CallBrlyFltRfltMod.oflEq");
	else if (ix == CALLBRLYFLTRLOCMOD_FLTEQ) return("CallBrlyFltRlocMod.fltEq");
	else if (ix == CALLBRLYFLTRLOCMOD_LOCEQ) return("CallBrlyFltRlocMod.locEq");
	else if (ix == CALLBRLYFLTUPD_REFEQ) return("CallBrlyFltUpd.refEq");
	else if (ix == CALLBRLYHUSRRUNVMOD_CRDUSREQ) return("CallBrlyHusrRunvMod.crdUsrEq");
	else if (ix == CALLBRLYINTVALPRESET) return("CallBrlyIntvalPreSet");
	else if (ix == CALLBRLYIXPRESET) return("CallBrlyIxPreSet");
	else if (ix == CALLBRLYKLKJKEYMOD_KLSAKEYEQ) return("CallBrlyKlkJkeyMod.klsAkeyEq");
	else if (ix == CALLBRLYKLSAKEYMOD_KLSEQ) return("CallBrlyKlsAkeyMod.klsEq");
	else if (ix == CALLBRLYKLSAKEYMOD_KLSMTBURFEQ) return("CallBrlyKlsAkeyMod.klsMtbUrfEq");
	else if (ix == CALLBRLYLEG_CLUEQ) return("CallBrlyLeg.cluEq");
	else if (ix == CALLBRLYLEG_INSBS) return("CallBrlyLeg.inSbs");
	else if (ix == CALLBRLYLEG_TYPEQ) return("CallBrlyLeg.typEq");
	else if (ix == CALLBRLYLEGMOD) return("CallBrlyLegMod");
	else if (ix == CALLBRLYLEGMOD_BLOEQ) return("CallBrlyLegMod.bloEq");
	else if (ix == CALLBRLYLEGMOD_CLUEQ) return("CallBrlyLegMod.cluEq");
	else if (ix == CALLBRLYLEGMOD_ELOEQ) return("CallBrlyLegMod.eloEq");
	else if (ix == CALLBRLYLEGRLEGMOD_DLGEQ) return("CallBrlyLegRlegMod.dlgEq");
	else if (ix == CALLBRLYLEGRLEGMOD_OLGEQ) return("CallBrlyLegRlegMod.olgEq");
	else if (ix == CALLBRLYLEGRLOCMOD_LEGEQ) return("CallBrlyLegRlocMod.legEq");
	else if (ix == CALLBRLYLEGRLOCMOD_LOCEQ) return("CallBrlyLegRlocMod.locEq");
	else if (ix == CALLBRLYLEGUPD_REFEQ) return("CallBrlyLegUpd.refEq");
	else if (ix == CALLBRLYLOC_EQPEQ) return("CallBrlyLoc.eqpEq");
	else if (ix == CALLBRLYLOC_INSBS) return("CallBrlyLoc.inSbs");
	else if (ix == CALLBRLYLOC_TYPEQ) return("CallBrlyLoc.typEq");
	else if (ix == CALLBRLYLOCMOD) return("CallBrlyLocMod");
	else if (ix == CALLBRLYLOCMOD_REGEQ) return("CallBrlyLocMod.regEq");
	else if (ix == CALLBRLYLOCRSEGMOD_LOCEQ) return("CallBrlyLocRsegMod.locEq");
	else if (ix == CALLBRLYLOCRSEGMOD_SEGEQ) return("CallBrlyLocRsegMod.segEq");
	else if (ix == CALLBRLYLOCUPD_REFEQ) return("CallBrlyLocUpd.refEq");
	else if (ix == CALLBRLYLOG) return("CallBrlyLog");
	else if (ix == CALLBRLYLOGOUT) return("CallBrlyLogout");
	else if (ix == CALLBRLYMASTCLAIM) return("CallBrlyMastClaim");
	else if (ix == CALLBRLYMASTSLVCHG) return("CallBrlyMastslvChg");
	else if (ix == CALLBRLYMONSTATCHG) return("CallBrlyMonstatChg");
	else if (ix == CALLBRLYNDEMOD) return("CallBrlyNdeMod");
	else if (ix == CALLBRLYNDEMOD_EQPEQ) return("CallBrlyNdeMod.eqpEq");
	else if (ix == CALLBRLYNDEMOD_RLYEQ) return("CallBrlyNdeMod.rlyEq");
	else if (ix == CALLBRLYNDEMOD_SUPEQ) return("CallBrlyNdeMod.supEq");
	else if (ix == CALLBRLYNDEUPD_REFEQ) return("CallBrlyNdeUpd.refEq");
	else if (ix == CALLBRLYNODECHG) return("CallBrlyNodeChg");
	else if (ix == CALLBRLYOPRMOD) return("CallBrlyOprMod");
	else if (ix == CALLBRLYOPRUPD_REFEQ) return("CallBrlyOprUpd.refEq");
	else if (ix == CALLBRLYPLOCRLOCMOD_DLOEQ) return("CallBrlyPlocRlocMod.dloEq");
	else if (ix == CALLBRLYPLOCRLOCMOD_OLOEQ) return("CallBrlyPlocRlocMod.oloEq");
	else if (ix == CALLBRLYPRSADETMOD_PRSEQ) return("CallBrlyPrsAdetMod.prsEq");
	else if (ix == CALLBRLYPRSJLNMMOD_PRSEQ) return("CallBrlyPrsJlnmMod.prsEq");
	else if (ix == CALLBRLYPRSMOD) return("CallBrlyPrsMod");
	else if (ix == CALLBRLYPRSUPD_REFEQ) return("CallBrlyPrsUpd.refEq");
	else if (ix == CALLBRLYPTYMOD) return("CallBrlyPtyMod");
	else if (ix == CALLBRLYPTYUPD_REFEQ) return("CallBrlyPtyUpd.refEq");
	else if (ix == CALLBRLYREFPRESET) return("CallBrlyRefPreSet");
	else if (ix == CALLBRLYREFSPRESET) return("CallBrlyRefsPreSet");
	else if (ix == CALLBRLYREG_INSBS) return("CallBrlyReg.inSbs");
	else if (ix == CALLBRLYREG_ISLEAF) return("CallBrlyReg.isLeaf");
	else if (ix == CALLBRLYREG_SUPEQ) return("CallBrlyReg.supEq");
	else if (ix == CALLBRLYREGADSSMOD_REGEQ) return("CallBrlyRegAdssMod.regEq");
	else if (ix == CALLBRLYREGJMOD_REGEQ) return("CallBrlyRegJMod.regEq");
	else if (ix == CALLBRLYREGJTITMOD_REGEQ) return("CallBrlyRegJtitMod.regEq");
	else if (ix == CALLBRLYREGMOD) return("CallBrlyRegMod");
	else if (ix == CALLBRLYREGMOD_SUPEQ) return("CallBrlyRegMod.supEq");
	else if (ix == CALLBRLYREGUPD_REFEQ) return("CallBrlyRegUpd.refEq");
	else if (ix == CALLBRLYRLY_CONEQ) return("CallBrlyRly.conEq");
	else if (ix == CALLBRLYRLYMOD) return("CallBrlyRlyMod");
	else if (ix == CALLBRLYRLYMOD_CONEQ) return("CallBrlyRlyMod.conEq");
	else if (ix == CALLBRLYRLYUPD_REFEQ) return("CallBrlyRlyUpd.refEq");
	else if (ix == CALLBRLYSCR) return("CallBrlyScr");
	else if (ix == CALLBRLYSEG_RETEQ) return("CallBrlySeg.retEq");
	else if (ix == CALLBRLYSEG_REUEQ) return("CallBrlySeg.reuEq");
	else if (ix == CALLBRLYSEGMOD) return("CallBrlySegMod");
	else if (ix == CALLBRLYSEGMOD_RETREUEQ) return("CallBrlySegMod.retReuEq");
	else if (ix == CALLBRLYSEGRSEGMOD_DSGEQ) return("CallBrlySegRsegMod.dsgEq");
	else if (ix == CALLBRLYSEGRSEGMOD_OSGEQ) return("CallBrlySegRsegMod.osgEq");
	else if (ix == CALLBRLYSEGUPD_REFEQ) return("CallBrlySegUpd.refEq");
	else if (ix == CALLBRLYSESMOD) return("CallBrlySesMod");
	else if (ix == CALLBRLYSESMOD_USREQ) return("CallBrlySesMod.usrEq");
	else if (ix == CALLBRLYSESUPD_REFEQ) return("CallBrlySesUpd.refEq");
	else if (ix == CALLBRLYSREFPRESET) return("CallBrlySrefPreSet");
	else if (ix == CALLBRLYSTATCHG) return("CallBrlyStatChg");
	else if (ix == CALLBRLYSTGCHG) return("CallBrlyStgChg");
	else if (ix == CALLBRLYSTUBCHG) return("CallBrlyStubChg");
	else if (ix == CALLBRLYTTB_FILEQ) return("CallBrlyTtb.filEq");
	else if (ix == CALLBRLYTTBMOD) return("CallBrlyTtbMod");
	else if (ix == CALLBRLYTTBUPD_REFEQ) return("CallBrlyTtbUpd.refEq");
	else if (ix == CALLBRLYTXTVALPRESET) return("CallBrlyTxtvalPreSet");
	else if (ix == CALLBRLYUSGAACCMOD_USGEQ) return("CallBrlyUsgAaccMod.usgEq");
	else if (ix == CALLBRLYUSGMOD) return("CallBrlyUsgMod");
	else if (ix == CALLBRLYUSGUPD_REFEQ) return("CallBrlyUsgUpd.refEq");
	else if (ix == CALLBRLYUSR_PRSEQ) return("CallBrlyUsr.prsEq");
	else if (ix == CALLBRLYUSR_USGEQ) return("CallBrlyUsr.usgEq");
	else if (ix == CALLBRLYUSRAACCMOD_USREQ) return("CallBrlyUsrAaccMod.usrEq");
	else if (ix == CALLBRLYUSRJSTEMOD_USREQ) return("CallBrlyUsrJsteMod.usrEq");
	else if (ix == CALLBRLYUSRMOD) return("CallBrlyUsrMod");
	else if (ix == CALLBRLYUSRRUSGMOD_USGEQ) return("CallBrlyUsrRusgMod.usgEq");
	else if (ix == CALLBRLYUSRRUSGMOD_USREQ) return("CallBrlyUsrRusgMod.usrEq");
	else if (ix == CALLBRLYUSRUPD_REFEQ) return("CallBrlyUsrUpd.refEq");
	else if (ix == CALLBRLYVLOCRLOCMOD_DLOEQ) return("CallBrlyVlocRlocMod.dloEq");
	else if (ix == CALLBRLYVLOCRLOCMOD_OLOEQ) return("CallBrlyVlocRlocMod.oloEq");

	return("");
};

