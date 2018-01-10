/**
  * \file IexBrlyIni.cpp
  * import/export handler for database DbsBrly (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyd.h>
#endif

#include "IexBrlyIni.h"

#include "IexBrlyIni_blks.cpp"

/******************************************************************************
 class IexBrlyIni
 ******************************************************************************/

IexBrlyIni::IexBrlyIni(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, const ubigint jrefSup
			, const uint ixBrlyVLocale
		) : JobBrly(xchg, VecBrlyVJob::IEXBRLYINI, jrefSup, ixBrlyVLocale) {

	jref = xchg->addJob(this);
};

IexBrlyIni::~IexBrlyIni() {
	// remove job reference from job list
	if (jref != 0) xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
double IexBrlyIni::radToDeg(
			double _rad																					// angle in degrees (0° .. 360°)
		) {
	return(180.0*_rad/pi);
};
// IP cust --- IEND

void IexBrlyIni::reset() {
	imeiavcontrolpar.clear();
	imeiavkeylistkey.clear();
	imeiavvaluelistval.clear();
	imeimfile.clear();
	imeimlocation.clear();
	imeimoperator.clear();
	imeimplntype.clear();
	imeimregion.clear();
	imeimusergroup.clear();

	lineno = 0;
	impcnt = 0;
};

void IexBrlyIni::import(
			DbsBrly* dbsbrly
		) {
	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMLocation* loc = NULL;
	ImeitemIMOperator* opr = NULL;
	ImeitemIMPlntype* pty = NULL;
	ImeitemIMRegion* reg = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMRegionDstswitch* regAdss = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* klkJkey = NULL;
	ImeitemIJMRegion* regJ = NULL;
	ImeitemIJMRegionTitle* regJtit = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint num0;

	// IP import --- IBEGIN
	ImeitemIMRegion* reg2 = NULL;

	ubigint refEaon;
	BrlyMEquipment* eqp = NULL;
	
	string s;

	double earthradius = xchg->stgbrlygeometry.earthradius;
	double hrznaltitude = xchg->stgbrlygeometry.hrznaltitude;
	// IP import --- IEND

	// IP import.traverse --- RBEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0=0;ix0<imeiavcontrolpar.nodes.size();ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		//ctlApar->ixBrlyVControl: IXSREF
		//ctlApar->Par: VOID
		//ctlApar->Val: VOID

		dbsbrly->tblbrlyavcontrolpar->insertRec(ctlApar);
		impcnt++;
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0=0;ix0<imeiavkeylistkey.nodes.size();ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];

		//klsAkey->klsIxBrlyVKeylist: IXSREF
		klsAkey->klsNum = (ix0+1); // TBD
		klsAkey->x1IxBrlyVMaintable = VecBrlyVMaintable::VOID;
		klsAkey->Fixed = true;
		//klsAkey->sref: VOID
		//klsAkey->Avail: VOID
		//klsAkey->Implied: VOID
		//klsAkey->refJ: SUB

		dbsbrly->tblbrlyavkeylistkey->insertRec(klsAkey);
		impcnt++;

		for (unsigned int ix1=0;ix1<klsAkey->imeijavkeylistkey.nodes.size();ix1++) {
			klkJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

			klkJkey->refBrlyAVKeylistKey = klsAkey->ref;
			//klkJkey->x1IxBrlyVLocale: IXSREF
			//klkJkey->Title: VOID
			//klkJkey->Comment: VOID

			dbsbrly->tblbrlyjavkeylistkey->insertRec(klkJkey);
			impcnt++;
		};

		if (klsAkey->imeijavkeylistkey.nodes.size() > 0) {
			klkJkey = klsAkey->imeijavkeylistkey.nodes[0];

			klsAkey->refJ = klkJkey->ref;
			klsAkey->Title = klkJkey->Title;
			klsAkey->Comment = klkJkey->Comment;
			
			dbsbrly->tblbrlyavkeylistkey->updateRec(klsAkey);
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0=0;ix0<imeiavvaluelistval.nodes.size();ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		//vlsAval->vlsIxBrlyVValuelist: IXSREF
		vlsAval->vlsNum = (ix0+1);
		//vlsAval->x1IxBrlyVLocale: IXSREF
		//vlsAval->Val: VOID

		dbsbrly->tblbrlyavvaluelistval->insertRec(vlsAval);
		impcnt++;
	};

	// -- ImeIMOperator
	for (unsigned int ix0=0;ix0<imeimoperator.nodes.size();ix0++) {
		opr = imeimoperator.nodes[ix0];

		//opr->sref: VOID
		//opr->srefICAO: VOID
		//opr->Title: VOID

		dbsbrly->tblbrlymoperator->insertRec(opr);
		impcnt++;

		if (opr->sref.compare("EaOn") == 0) refEaon = opr->ref;
	};

	// -- ImeIMPlntype
	for (unsigned int ix0=0;ix0<imeimplntype.nodes.size();ix0++) {
		pty = imeimplntype.nodes[ix0];

		//pty->sref: VOID
		//pty->Title: VOID
		//pty->srefBrlyKEqptype: VOID
		//pty->Capacity: VOID

		dbsbrly->tblbrlymplntype->insertRec(pty);
		impcnt++;
	};

	// -- ImeIMRegion
	for (unsigned int ix0=0;ix0<imeimregion.nodes.size();ix0++) {
		reg = imeimregion.nodes[ix0];

		//reg->supRefBrlyMRegion: PREVIMP
		for (unsigned int i=0;i<ix0;i++) {
			reg2 = imeimregion.nodes[i];

			s = reg2->sref;
			if (reg2->hsrefSupRefBrlyMRegion.length() > 0) s = reg2->hsrefSupRefBrlyMRegion + ";" + s;

			if (s == reg->hsrefSupRefBrlyMRegion) {
				reg->supRefBrlyMRegion = reg2->ref;
				break;
			};
		};
		//reg->sref: VOID
		//reg->refJTitle: SUB
		//reg->refJ: SUB

		dbsbrly->tblbrlymregion->insertRec(reg);
		impcnt++;

		for (unsigned int ix1=0;ix1<reg->imeiamregiondstswitch.nodes.size();ix1++) {
			regAdss = reg->imeiamregiondstswitch.nodes[ix1];

			regAdss->refBrlyMRegion = reg->ref;
			//regAdss->startd: FTM
			//regAdss->startt: FTM

			dbsbrly->tblbrlyamregiondstswitch->insertRec(regAdss);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<reg->imeijmregiontitle.nodes.size();ix1++) {
			regJtit = reg->imeijmregiontitle.nodes[ix1];

			regJtit->refBrlyMRegion = reg->ref;
			//regJtit->x1IxBrlyVLocale: IXSREF
			//regJtit->Title: VOID

			dbsbrly->tblbrlyjmregiontitle->insertRec(regJtit);
			impcnt++;
		};

		if (reg->imeijmregiontitle.nodes.size() > 0) {
			regJtit = reg->imeijmregiontitle.nodes[0];

			reg->refJTitle = regJtit->ref;
			reg->Title = regJtit->Title;

			dbsbrly->tblbrlymregion->updateRec(reg);
		};

		for (unsigned int ix1=0;ix1<reg->imeijmregion.nodes.size();ix1++) {
			regJ = reg->imeijmregion.nodes[ix1];

			regJ->refBrlyMRegion = reg->ref;
			//regJ->x1Startd: FTM
			//regJ->x1Stopd: FTM
			//regJ->ixVDst: IXSREF
			//regJ->toffset: VOID

			dbsbrly->tblbrlyjmregion->insertRec(regJ);
			impcnt++;
		};

		if (reg->imeijmregion.nodes.size() > 0) {
			regJ = reg->imeijmregion.nodes[0];

			reg->refJ = regJ->ref;
			reg->ixVDst = regJ->ixVDst;
			reg->toffset = regJ->toffset;

			dbsbrly->tblbrlymregion->updateRec(reg);
		};
	};

	// -- ImeIMFile
	for (unsigned int ix0=0;ix0<imeimfile.nodes.size();ix0++) {
		fil = imeimfile.nodes[ix0];

		fil->refIxVTbl = VecBrlyVMFileRefTbl::VOID;
		//fil->osrefKContent: VOID
		//fil->Filename: VOID
		//fil->srefKMimetype: VOID
		//fil->Comment: VOID
		//fil->Archived = PP (DlgBrlyNavLoaini);
		//fil->Archivename = PP (DlgBrlyNavLoaini);
		//fil->Size = PP (DlgBrlyNavLoaini);

		dbsbrly->tblbrlymfile->insertRec(fil);
		impcnt++;
	};

	// -- ImeIMLocation
	for (unsigned int ix0=0;ix0<imeimlocation.nodes.size();ix0++) {
		loc = imeimlocation.nodes[ix0];

		//loc->ixVBasetype: IXSREF
		//loc->refBrlyMRegion: PREVIMP
		for (unsigned int i=0;i<imeimregion.nodes.size();i++) {
			reg = imeimregion.nodes[i];

			s = reg->sref;
			if (reg->hsrefSupRefBrlyMRegion.length() > 0) s = reg->hsrefSupRefBrlyMRegion + ";" + s;

			if (s == loc->hsrefRefBrlyMRegion) {
				loc->refBrlyMRegion = reg->ref;
				break;
			};
		};
		//loc->refBrlyMEquipment: CUSTSQLPP
		//loc->sref: VOID
		//loc->srefICAO: VOID
		//loc->Title: VOID
		//loc->alt: VOID
		//loc->theta: VOID
		//loc->phi: VOID
		//loc->tz: VOID
		//loc->alpha: DEFVAL
		if ((loc->ixVBasetype == VecBrlyVMLocationBasetype::APT) || (loc->ixVBasetype == VecBrlyVMLocationBasetype::GND)) {
			loc->alpha = 85.0;
		} else if (loc->ixVBasetype == VecBrlyVMLocationBasetype::ELV) {
			loc->alpha = radToDeg(acos((earthradius + hrznaltitude) / (earthradius + loc->alt)));
		};
		loc->Calcdone = false;

		// uinc'ed equipment
		if (loc->ixVBasetype == VecBrlyVMLocationBasetype::ELV) {
			if (loc->alt <= 4000.0) dbsbrly->tblbrlymequipment->insertNewRec(&eqp, VecBrlyVMEquipmentHkTbl::LOC, 0, refEaon, 0, "bll", true);
			else dbsbrly->tblbrlymequipment->insertNewRec(&eqp, VecBrlyVMEquipmentHkTbl::LOC, 0, refEaon, 0, "blh", true);
		} else {
			dbsbrly->tblbrlymequipment->insertNewRec(&eqp, VecBrlyVMEquipmentHkTbl::LOC, 0, refEaon, 0, "gnd", true);
		};
		loc->refBrlyMEquipment = eqp->ref;

		dbsbrly->tblbrlymlocation->insertRec(loc);

		eqp->hkUref = loc->ref;
		dbsbrly->tblbrlymequipment->updateRec(eqp);
		delete eqp;

		impcnt++;
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0=0;ix0<imeimusergroup.nodes.size();ix0++) {
		usg = imeimusergroup.nodes[ix0];

		//usg->grp = TBD;
		//usg->own = TBD;
		//usg->sref: VOID
		//usg->Comment: VOID

		dbsbrly->tblbrlymusergroup->insertRec(usg);
		impcnt++;

		for (unsigned int ix1=0;ix1<usg->imeiamusergroupaccess.nodes.size();ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			usgAacc->refBrlyMUsergroup = usg->ref;
			//usgAacc->x1IxBrlyVCard: IXSREF
			//usgAacc->ixBrlyWUiaccess: IXSREF

			dbsbrly->tblbrlyamusergroupaccess->insertRec(usgAacc);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<usg->imeimuser.nodes.size();ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			//usr->grp = TBD;
			//usr->own = TBD;
			//usr->refRUsergroup: IMPPP
			usr->refBrlyMUsergroup = usg->ref;
			//usr->refBrlyMPerson: SUB
			//usr->sref: VOID
			//usr->refJState: SUB
			//usr->ixBrlyVLocale: IXSREF
			//usr->ixBrlyVUserlevel: IXSREF
			//usr->Password: VOID

			dbsbrly->tblbrlymuser->insertRec(usr);
			impcnt++;

			usr->refRUsergroup = dbsbrly->tblbrlyrmusermusergroup->insertNewRec(NULL, usr->ref, usg->ref, usr->ixBrlyVUserlevel);
			dbsbrly->tblbrlymuser->updateRec(usr);

			for (unsigned int ix2=0;ix2<usr->imeijmuserstate.nodes.size();ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				usrJste->refBrlyMUser = usr->ref;
				//usrJste->ixVState: IXSREF

				dbsbrly->tblbrlyjmuserstate->insertRec(usrJste);
				impcnt++;
			};

			if (usr->imeijmuserstate.nodes.size() > 0) {
				usrJste = usr->imeijmuserstate.nodes[0];

				usr->refJState = usrJste->ref;
				usr->ixVState = usrJste->ixVState;

				dbsbrly->tblbrlymuser->updateRec(usr);
			};

			for (unsigned int ix2=0;ix2<usr->imeimperson.nodes.size();ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				prs->ixWDerivate = VecBrlyWMPersonDerivate::USR;
				//prs->ixVSex: IXSREF
				//prs->Title: VOID
				//prs->Firstname: VOID
				//prs->refJLastname: SUB

				dbsbrly->tblbrlymperson->insertRec(prs);
				impcnt++;

				for (unsigned int ix3=0;ix3<prs->imeijmpersonlastname.nodes.size();ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					prsJlnm->refBrlyMPerson = prs->ref;
					//prsJlnm->Lastname = ;

					dbsbrly->tblbrlyjmpersonlastname->insertRec(prsJlnm);
					impcnt++;
				};

				if (prs->imeijmpersonlastname.nodes.size() > 0) {
					prsJlnm = prs->imeijmpersonlastname.nodes[0];

					prs->refJLastname = prsJlnm->ref;
					prs->Lastname = prsJlnm->Lastname;

					dbsbrly->tblbrlymperson->updateRec(prs);
				};
			};

			if (usr->imeimperson.nodes.size() > 0) {
				prs = usr->imeimperson.nodes[0];

				usr->refBrlyMPerson = prs->ref;

				dbsbrly->tblbrlymuser->updateRec(usr);
			};
		};
	};
	// IP import.traverse --- REND

	// IP import.ppr --- INSERT
};

void IexBrlyIni::collect(
			DbsBrly* dbsbrly
			, const map<uint,uint>& icsBrlyVIop
		) {
	ImeitemIAVControlPar* ctlApar = NULL;
	ImeitemIAVKeylistKey* klsAkey = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMLocation* loc = NULL;
	ImeitemIMOperator* opr = NULL;
	ImeitemIMPlntype* pty = NULL;
	ImeitemIMRegion* reg = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMRegionDstswitch* regAdss = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIJAVKeylistKey* klkJkey = NULL;
	ImeitemIJMRegion* regJ = NULL;
	ImeitemIJMRegionTitle* regJtit = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint ixBrlyVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

	// IP collect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0=0;ix0<imeiavcontrolpar.nodes.size();ix0++) {
		ctlApar = imeiavcontrolpar.nodes[ix0];

		if (ctlApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey
	for (unsigned int ix0=0;ix0<imeiavkeylistkey.nodes.size();ix0++) {
		klsAkey = imeiavkeylistkey.nodes[ix0];

		if (klsAkey->ref != 0) {
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJAVKEYLISTKEY, ixBrlyVIop)) {
			dbsbrly->tblbrlyjavkeylistkey->loadRefsByKlk(klsAkey->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey->refJ) {refs[i] = refs[0]; refs[0] = klsAkey->refJ; break;};
			for (unsigned int i=0;i<refs.size();i++) klsAkey->imeijavkeylistkey.nodes.push_back(new ImeitemIJAVKeylistKey(dbsbrly, refs[i]));
		};

		for (unsigned int ix1=0;ix1<klsAkey->imeijavkeylistkey.nodes.size();ix1++) {
			klkJkey = klsAkey->imeijavkeylistkey.nodes[ix1];

			if (klkJkey->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0=0;ix0<imeiavvaluelistval.nodes.size();ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMFile
	for (unsigned int ix0=0;ix0<imeimfile.nodes.size();ix0++) {
		fil = imeimfile.nodes[ix0];

		if (fil->ref != 0) {
		};
	};

	// -- ImeIMLocation
	for (unsigned int ix0=0;ix0<imeimlocation.nodes.size();ix0++) {
		loc = imeimlocation.nodes[ix0];

		if (loc->ref != 0) {
			loc->hsrefRefBrlyMRegion = StubBrly::getStubRegHsref(dbsbrly, loc->refBrlyMRegion, ixBrlyVLocale, Stub::VecVNonetype::VOID, stcch);
		};
	};

	// -- ImeIMOperator
	for (unsigned int ix0=0;ix0<imeimoperator.nodes.size();ix0++) {
		opr = imeimoperator.nodes[ix0];

		if (opr->ref != 0) {
		};
	};

	// -- ImeIMPlntype
	for (unsigned int ix0=0;ix0<imeimplntype.nodes.size();ix0++) {
		pty = imeimplntype.nodes[ix0];

		if (pty->ref != 0) {
		};
	};

	// -- ImeIMRegion
	for (unsigned int ix0=0;ix0<imeimregion.nodes.size();ix0++) {
		reg = imeimregion.nodes[ix0];

		if (reg->ref != 0) {
			reg->hsrefSupRefBrlyMRegion = StubBrly::getStubRegHsref(dbsbrly, reg->supRefBrlyMRegion, ixBrlyVLocale, Stub::VecVNonetype::VOID, stcch);
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIAMREGIONDSTSWITCH, ixBrlyVIop)) {
			dbsbrly->tblbrlyamregiondstswitch->loadRefsByReg(reg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) reg->imeiamregiondstswitch.nodes.push_back(new ImeitemIAMRegionDstswitch(dbsbrly, refs[i]));
		};

		for (unsigned int ix1=0;ix1<reg->imeiamregiondstswitch.nodes.size();ix1++) {
			regAdss = reg->imeiamregiondstswitch.nodes[ix1];

			if (regAdss->ref != 0) {
			};
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJMREGION, ixBrlyVIop)) {
			dbsbrly->tblbrlyjmregion->loadRefsByReg(reg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == reg->refJ) {refs[i] = refs[0]; refs[0] = reg->refJ; break;};
			for (unsigned int i=0;i<refs.size();i++) reg->imeijmregion.nodes.push_back(new ImeitemIJMRegion(dbsbrly, refs[i]));
		};

		for (unsigned int ix1=0;ix1<reg->imeijmregion.nodes.size();ix1++) {
			regJ = reg->imeijmregion.nodes[ix1];

			if (regJ->ref != 0) {
			};
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJMREGIONTITLE, ixBrlyVIop)) {
			dbsbrly->tblbrlyjmregiontitle->loadRefsByReg(reg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == reg->refJTitle) {refs[i] = refs[0]; refs[0] = reg->refJTitle; break;};
			for (unsigned int i=0;i<refs.size();i++) reg->imeijmregiontitle.nodes.push_back(new ImeitemIJMRegionTitle(dbsbrly, refs[i]));
		};

		for (unsigned int ix1=0;ix1<reg->imeijmregiontitle.nodes.size();ix1++) {
			regJtit = reg->imeijmregiontitle.nodes[ix1];

			if (regJtit->ref != 0) {
			};
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0=0;ix0<imeimusergroup.nodes.size();ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixBrlyVIop)) {
			dbsbrly->tblbrlyamusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbsbrly, refs[i]));
		};

		for (unsigned int ix1=0;ix1<usg->imeiamusergroupaccess.nodes.size();ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIMUSER, ixBrlyVIop)) {
			dbsbrly->tblbrlymuser->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) usg->imeimuser.nodes.push_back(new ImeitemIMUser(dbsbrly, refs[i]));
		};

		for (unsigned int ix1=0;ix1<usg->imeimuser.nodes.size();ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJMUSERSTATE, ixBrlyVIop)) {
				dbsbrly->tblbrlyjmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i=0;i<refs.size();i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbsbrly, refs[i]));
			};

			for (unsigned int ix2=0;ix2<usr->imeijmuserstate.nodes.size();ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2=0;ix2<usr->imeimperson.nodes.size();ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxBrlyVIop(icsBrlyVIop, VecVIme::IMEIJMPERSONLASTNAME, ixBrlyVIop)) {
					dbsbrly->tblbrlyjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i=0;i<refs.size();i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbsbrly, refs[i]));
				};

				for (unsigned int ix3=0;ix3<prs->imeijmpersonlastname.nodes.size();ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
					};
				};
			};
		};
	};
	// IP collect.traverse --- END

	// IP collect.ppr --- INSERT

	delete stcch;
};

bool IexBrlyIni::readTxt(
			Txtrd& txtrd
		) {
	bool parseok = true;

	while (txtrd.readLine()) {
		if (txtrd.comment) {
		} else if (txtrd.header && (txtrd.il == 0)) {
			if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) {
				parseok = imeiavcontrolpar.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY) {
				parseok = imeiavkeylistkey.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) {
				parseok = imeiavvaluelistval.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMFILE) {
				parseok = imeimfile.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMLOCATION) {
				parseok = imeimlocation.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMOPERATOR) {
				parseok = imeimoperator.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMPLNTYPE) {
				parseok = imeimplntype.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMREGION) {
				parseok = imeimregion.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) {
				parseok = imeimusergroup.readTxt(txtrd); if (!parseok) break;
			} else {
				parseok = false; break;
			};
		} else {
			parseok = false; break;
		};
	};

	lineno = txtrd.linecnt;

	return parseok;
};

void IexBrlyIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	bool basefound;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "IexBrlyIni");

	if (basefound) {
		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimfile.readXML(docctx, basexpath);
		imeimlocation.readXML(docctx, basexpath);
		imeimoperator.readXML(docctx, basexpath);
		imeimplntype.readXML(docctx, basexpath);
		imeimregion.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);
	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey = ImeIAVKeylistKey();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimfile = ImeIMFile();
		imeimlocation = ImeIMLocation();
		imeimoperator = ImeIMOperator();
		imeimplntype = ImeIMPlntype();
		imeimregion = ImeIMRegion();
		imeimusergroup = ImeIMUsergroup();
	};
};

bool IexBrlyIni::readTxtFile(
			const string& fullpath
		) {
	bool retval;

	Txtrd rd(VecVIme::getIx);

	rd.openFile(fullpath);

	retval = readTxt(rd);

	rd.closeFile();

	return retval;
};

bool IexBrlyIni::readXMLFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/");

	closeParsed(doc, docctx);

	return true;
};

void IexBrlyIni::writeTxt(
			fstream& outfile
		) {
	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimfile.writeTxt(outfile);
	imeimlocation.writeTxt(outfile);
	imeimoperator.writeTxt(outfile);
	imeimplntype.writeTxt(outfile);
	imeimregion.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexBrlyIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexBrlyIni");
		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimfile.writeXML(wr, shorttags);
		imeimlocation.writeXML(wr, shorttags);
		imeimoperator.writeXML(wr, shorttags);
		imeimplntype.writeXML(wr, shorttags);
		imeimregion.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

void IexBrlyIni::writeTxtFile(
			const string& fullpath
		) {
	fstream txtfile;

	txtfile.open(fullpath.c_str(), ios::out);

	writeTxt(txtfile);
	
	txtfile.close();
};

void IexBrlyIni::writeXMLFile(
			const string& fullpath
			, const bool shorttags
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr, shorttags);
	closewriteFile(wr);
};

map<uint,uint> IexBrlyIni::icsBrlyVIopInsAll() {
	return {{(uint)VecVIme::IMEIAVCONTROLPAR,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMFILE,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMLOCATION,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMOPERATOR,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMPLNTYPE,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMREGION,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAMREGIONDSTSWITCH,VecBrlyVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJMREGION,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJMREGIONTITLE,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMUSER,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecBrlyVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecBrlyVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecBrlyVIop::INS}};
};

uint IexBrlyIni::getIxBrlyVIop(
			const map<uint,uint>& icsBrlyVIop
			, const uint ixVIme
			, uint& ixBrlyVIop
		) {
	ixBrlyVIop = 0;

	auto it = icsBrlyVIop.find(ixVIme);
	if (it != icsBrlyVIop.end()) ixBrlyVIop = it->second;

	return ixBrlyVIop;
};

void IexBrlyIni::handleRequest(
			DbsBrly* dbsbrly
			, ReqBrly* req
		) {
	if (req->ixVBasetype == ReqBrly::VecVBasetype::CMD) {
		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};
	};
};

void IexBrlyIni::handleCall(
			DbsBrly* dbsbrly
			, Call* call
		) {
};


