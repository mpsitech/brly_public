/**
  * \file BrlyTtimpRawstar.h
  * Brly operation processor -  (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYTTIMPRAWSTAR_H
#define BRLYTTIMPRAWSTAR_H

#include "BrlyTtimp.h"

using namespace BrlyTtimp;

// IP incl --- INSERT

namespace BrlyTtimpRawstar {
	DpchRetBrly* run(XchgBrly* xchg, DbsBrly* dbsbrly, DpchInvBrlyTtimpRawstar* dpchinv);
	// IP cust --- IBEGIN

	class Leg {

	public:
		Leg(const ubigint iref, const string& srefBgnRefBrlyMLocation, const string& srefEndRefBrlyMLocation);

		ubigint iref;
		string srefBgnRefBrlyMLocation;
		string srefEndRefBrlyMLocation;
	};

	class Flight {

	public:
		Flight(const string& hintRefBrlyMEquipment, const ubigint irefRefBrlyMLeg, const string& sref, const int hintStart, const int hintStop, const string& iDate, const string& iWeekday);

		string hintRefBrlyMEquipment;
		ubigint irefRefBrlyMLeg;
		string sref;
		int hintStart;
		int hintStop;
		string iDate;
		string iWeekday;
	};

	void parseFile(fstream& infile, vector<Leg*>& legs, vector<Flight*>& flts);
	void writeLegs(fstream& outfile, const vector<Leg*>& legs);
	void writeFlights(fstream& outfile, const vector<Flight*>& flts);
	// IP cust --- IEND
};

#endif


