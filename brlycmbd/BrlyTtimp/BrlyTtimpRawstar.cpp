/**
  * \file BrlyTtimpRawstar.cpp
  * Brly operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef BRLYCMBD
	#include <Brlycmbd.h>
#else
	#include <Brlyopd.h>
#endif

#include "BrlyTtimpRawstar.h"

DpchRetBrly* BrlyTtimpRawstar::run(
			XchgBrly* xchg
			, DbsBrly* dbsbrly
			, DpchInvBrlyTtimpRawstar* dpchinv
		) {
	string infile = dpchinv->infile;
	string outfile = dpchinv->outfile;

	bool success;

	// IP run --- IBEGIN
	fstream infi;
	fstream outfi;

	vector<Leg*> legs;
	vector<Flight*> flts;

	string s;

	// open files
	s = xchg->tmppath + "/" + infile;
	infi.open(s.c_str(), ios::in);

	s = xchg->tmppath + "/" + outfile;
	outfi.open(s.c_str(), ios::out);

	parseFile(infi, legs, flts);
	writeLegs(outfi, legs);
	writeFlights(outfi, flts);

	infi.close();
	outfi.close();

	for (unsigned int i=0;i<legs.size();i++) delete legs[i];
	for (unsigned int i=0;i<flts.size();i++) delete flts[i];
	// IP run --- IEND

	return(new DpchRetBrly(VecBrlyVDpch::DPCHRETBRLY, "", "", success));
};

// IP cust --- IBEGIN
BrlyTtimpRawstar::Leg::Leg(
			const ubigint iref
			, const string& srefBgnRefBrlyMLocation
			, const string& srefEndRefBrlyMLocation
		) {

	this->iref = iref;
	this->srefBgnRefBrlyMLocation = srefBgnRefBrlyMLocation;
	this->srefEndRefBrlyMLocation = srefEndRefBrlyMLocation;
};

BrlyTtimpRawstar::Flight::Flight(
			const string& hintRefBrlyMEquipment
			, const ubigint irefRefBrlyMLeg
			, const string& sref
			, const int hintStart
			, const int hintStop
			, const string& iDate
			, const string& iWeekday
		) {

	this->hintRefBrlyMEquipment = hintRefBrlyMEquipment;
	this->irefRefBrlyMLeg = irefRefBrlyMLeg;
	this->sref = sref;
	this->hintStart = hintStart;
	this->hintStop = hintStop;
	this->iDate = iDate;
	this->iWeekday = iWeekday;
};

void BrlyTtimpRawstar::parseFile(
			fstream& infile
			, vector<Leg*>& legs
			, vector<Flight*>& flts
		) {
	char* buf = new char[256];
	string s;
	vector<string> ss;
	long lineno = 0;
	size_t linelen;
	size_t ptr1, ptr2;

	bool nonstop;
	ubigint iref = 0;
	string srefBgnRefBrlyMLocation;
	string srefEndRefBrlyMLocation;
	int start, stop;
	Leg* leg = NULL;
	Flight* flt = NULL;

	while (infile.good() && (!infile.eof())) {
		// read single line
		infile.getline(buf, 256, '\n');
		s = string(buf);
		lineno++;
		linelen = s.size();

		if (linelen > 0) {
			if (s.find("To ") == 0) {
				// new end location (and leg)

				if ((legs.size() > 0) && !nonstop) {
					iref--;
					delete legs[legs.size()-1];
					legs.resize(legs.size()-1);
				};

				ptr2 = s.find(')', 0); ptr1 = ptr2-3;
				if ((ptr2<linelen) && (ptr1>=0)) srefEndRefBrlyMLocation = s.substr(ptr1, 3);

				iref++;
				leg = new Leg(iref, srefBgnRefBrlyMLocation, srefEndRefBrlyMLocation);
				legs.push_back(leg);

				nonstop = false;

			} else if (s.find("Above ") == 0) {
				// validity date limitation
				// ex. "Above 12/14 - 1/8, Exc. 12/24 - 12/25, 12/31"

				if (flt) {
					s = s.substr(6);

					ptr1 = s.find(' ');
					while (ptr1 != string::npos) {
						s = s.substr(0, ptr1) + s.substr(ptr1+1);
						ptr1 = s.find(' ');
					};

					s = StrMod::replaceChar(s, ',', ';');
					flt->iDate = s;
				};

			} else if ((s[0] == '0') || (s[0] == '1') || (s[0] == '2')) {
				// new flight
				// ex. "2220 2331 UA8019 ER4 Daily 0"

				s = StrMod::replaceChar(s, ' ', ';');
				StrMod::stringToVector(s, ss);
				flt = NULL;

				if (ss.size() >= 6) {
					if (ss[5].compare("0") == 0) {
						nonstop = true;

						if (ss[4].compare("Daily") == 0) {
							ss[4] = "1234567";

						} else if (ss[4].find('X') == 0) {
							s = ss[4].substr(1);
							ss[4] = "";
							for (unsigned int i=1;i<=7;i++) if (s.find((char) (i+48)) == string::npos) ss[4] = ss[4] + ((char) (i+48));
						};

						start = atoi(ss[0].substr(0, 4).c_str());
						start = 60* (60*(start-(start%100))/100 + (start%100));

						stop = atoi(ss[1].substr(0, 4).c_str());
						stop = 60* (60*(stop-(stop%100))/100 + (stop%100));
						if (ss[1].find("-1") != string::npos) {
							stop -= 86400;
						} else if (ss[1].find("+1") != string::npos) {
							stop += 86400;
						} else if (ss[1].find("+2") != string::npos) {
							stop += 2*86400;
						};

						flt = new Flight(ss[3], iref, ss[2], start, stop, "", ss[4]);
						flts.push_back(flt);
					};
				};

			} else {
				// new begin location
				ptr2 = s.find(')', 0); ptr1 = ptr2-3;
				if ((ptr2<linelen) && (ptr1>=0)) srefBgnRefBrlyMLocation = s.substr(ptr1, 3);
			};
		};
	};

	delete[] buf;
};

void BrlyTtimpRawstar::writeLegs(
			fstream& outfile
			, const vector<Leg*>& legs
		) {
	Leg* leg = NULL;

	outfile << "- ImeIMLeg.iref\tsrefBgnRefBrlyMLocation\tsrefEndRefBrlyMLocation" << endl;

	for (unsigned int i=0;i<legs.size();i++) {
		leg = legs[i];
		outfile << "- " << leg->iref << "\t" << leg->srefBgnRefBrlyMLocation << "\t" << leg->srefEndRefBrlyMLocation << endl;
	};
};

void BrlyTtimpRawstar::writeFlights(
			fstream& outfile
			, const vector<Flight*>& flts
		) {
	Flight* flt = NULL;

	outfile << "- ImeIMFlight.hintRefBrlyMEquipment\tirefRefBrlyMLeg\tsref\thintStart\thintStop\tiDate\tiWeekday" << endl;

	for (unsigned int i=0;i<flts.size();i++) {
		flt = flts[i];
		outfile << "- " << flt->hintRefBrlyMEquipment << "\t" << flt->irefRefBrlyMLeg << "\t" << flt->sref 
			 << "\t" << flt->hintStart << "\t" << flt->hintStop << "\t" << flt->iDate << "\t" << flt->iWeekday << endl;
	};
};
// IP cust --- IEND


