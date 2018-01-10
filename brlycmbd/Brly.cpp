/**
  * \file Brly.cpp
  * Brly global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#include "Brly.h"

/******************************************************************************
 namespace Acv
 ******************************************************************************/

ubigint Acv::addfile(
			DbsBrly* dbsbrly
			, const string& acvpath
			, const string& path
			, const uint refIxVTbl
			, const ubigint refUref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) {
	ubigint retval = 0;

	BrlyMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	fil = new BrlyMFile(0, 0, 0, 0, refIxVTbl, refUref, osrefKContent, Archived, Filename, "", srefKMimetype, Size, Comment);
	dbsbrly->tblbrlymfile->insertRec(fil);
	
	// adjust archive name in record
	str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
	if (Filename.rfind('.') != string::npos) str << Filename.substr(Filename.rfind('.'));

	fil->Archivename = str.str();
	dbsbrly->tblbrlymfile->updateRec(fil);

	// create folder if required
	str.str(""); str << acvpath << "/";
	str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	// copy file
	s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

	res = system(s.c_str());
	if (res != 0) cout << "Acv::addfile() error copying file (" << res << ")" << endl;

	retval = fil->ref;
	delete fil;

	return retval;
};

void Acv::alterfile(
			DbsBrly* dbsbrly
			, const string& acvpath
			, const string& path
			, const ubigint ref
		) {
	BrlyMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	// load record
	dbsbrly->tblbrlymfile->loadRecByRef(ref, &fil);

	if (fil) {
		// update record
		fil->Archived = Archived;

		str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
		if (fil->Filename.rfind('.') != string::npos) str << fil->Filename.substr(fil->Filename.rfind('.'));
		fil->Archivename = str.str();

		fil->Size = Size;

		dbsbrly->tblbrlymfile->updateRec(fil);

		// create folder if required
		str.str(""); str << acvpath << "/";
		str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

		// copy file
		s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

		res = system(s.c_str());
		if (res != 0) cout << "Acv::alterfile() error copying file (" << res << ")" << endl;

		delete fil;
	};
};

string Acv::getfile(
			DbsBrly* dbsbrly
			, const ubigint refBrlyMFile
		) {
	BrlyMFile* fil = NULL;

	ostringstream str;

	dbsbrly->tblbrlymfile->loadRecByRef(refBrlyMFile, &fil);

	if (fil) {
		str.fill('0');
		str.width(5);
		str << right << ((fil->ref-(fil->ref%1000)) / 1000);
		
		str.width(0);
		str << "/" << fil->Archivename;

		delete fil;
	};

	return(str.str());
};

/******************************************************************************
 namespace Lop
 ******************************************************************************/

void Lop::apply(
			const uint ixBrlyVLop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	if (ixBrlyVLop == VecBrlyVLop::INS) insert(refsList, refsPool, ref);
	else if (ixBrlyVLop == VecBrlyVLop::RMV) remove(refsList, refsPool, ref);
};

void Lop::insert(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i=0;i<refsPool.size();i++) {
		if (refsPool[i] == ref) {
			refsList[i] = ref;
			refsPool[i] = 0;
			break;
		};
	};
};

void Lop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref) {
			refsPool[i] = ref;
			refsList[i] = 0;
			break;
		};
	};
};

/******************************************************************************
 namespace Oolop
 ******************************************************************************/

void Oolop::apply(
			const uint ixBrlyVOolop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	if (ixBrlyVOolop == VecBrlyVOolop::INB) insertBefore(refsList, refsPool, ref1, ref2);
	else if (ixBrlyVOolop == VecBrlyVOolop::INA) insertAfter(refsList, refsPool, ref1, ref2);
	else if (ixBrlyVOolop == VecBrlyVOolop::RMV) remove(refsList, refsPool, ref1);
	else if (ixBrlyVOolop == VecBrlyVOolop::TOB) toBefore(refsList, ref1, ref2);
	else if (ixBrlyVOolop == VecBrlyVOolop::TOA) toAfter(refsList, ref1, ref2);
	else if (ixBrlyVOolop == VecBrlyVOolop::SWP) swap(refsList, ref1, ref2);
};

void Oolop::insertBefore(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool=refsPool.begin();itPool!=refsPool.end();itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.insert(refsList.begin(), ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
					if (*itList == ref2) {
						refsList.insert(itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::insertAfter(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool=refsPool.begin();itPool!=refsPool.end();itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.push_back(ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
					if (*itList == ref2) {
						refsList.insert(++itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
		if (*itList == ref) {
			refsList.erase(itList);
			refsPool.push_back(ref);
		};
	};
};

void Oolop::toBefore(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******2*****1****
	// *******12*********
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref2) {
			for (unsigned int j=i+1;j<refsList.size();j++) {
				if (refsList[j] == ref1) {
					for (unsigned int k=i+1;k<j;k++) refsList[k+1] = refsList[k];
					refsList[i] = ref1;
					refsList[i+1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::toAfter(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******1*****2****
	// ************21****
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref1) {
			for (unsigned int j=i+1;j<refsList.size();j++) {
				if (refsList[j] == ref2) {
					for (unsigned int k=i+1;k<j;k++) refsList[k-1] = refsList[k];
					refsList[j] = ref1;
					refsList[j-1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::swap(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
		if (*itList == ref1) {
			for (auto itList2=refsList.begin();itList2!=refsList.end();itList2++) {
				if (*itList2 == ref2) {
					*itList = ref2;
					*itList2 = ref1;
					break;
				};
			};
			break;
		};
	};
};

/******************************************************************************
 namespace Tmp
 ******************************************************************************/

string Tmp::newfile(
			const string& tmppath
			, const string& ext
		) {
	string filename;
	fstream tmpfile;

	unsigned int pathlen = tmppath.length() + 1;

	FILE* file;

	bool valid = false;

	while (!valid) {
		filename = tmppath + "/" + random();
		if (ext.length() > 0) filename += "." + ext;

		file = fopen(filename.c_str(), "w+x");

		if (file) {
			fclose(file);
			valid = true;
		} else if (errno != EEXIST) break;
	};

	return(filename.substr(pathlen));
};

string Tmp::newfolder(
			const string& tmppath
		) {
	string foldername;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		foldername = tmppath + "/" + random();

		// mkdir() fails if folder exists
#ifdef _WIN32
		valid = (mkdir(foldername.c_str()) == 0);
#else
		valid = (mkdir(foldername.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0);
#endif

		if (!valid) if (errno != EEXIST) break;
	};

	return(foldername.substr(pathlen));
};

string Tmp::random() {
	string retval;

	int digit;

	// random seed is done in engine initialization

	// fetch digits and make sure their ASCII code is in the range 0..9/a..z
	for (unsigned int i=0;i<8;i++) {
		digit = rand() % 36 + 48;
		if (digit > 57) digit += (97-48-10);

		retval = retval + ((char) digit);
	};

	return retval;
};

// IP cust --- IBEGIN
/******************************************************************************
 namespace Cdf
 ******************************************************************************/

void Cdf::putBoolVec(
			const int ncid
			, const int varid
			, const vector<bool>& vec
		) {
	unsigned char* boolbuf = NULL;

	boolbuf = new unsigned char[vec.size()];
	for (unsigned int i=0;i<vec.size();i++) boolbuf[i] = ((vec[i]) ? 1 : 0);

	nc_put_var_uchar(ncid, varid, boolbuf);

	delete[] boolbuf;
};

void Cdf::putUintVec(
			const int ncid
			, const int varid
			, const vector<uint>& vec
		) {
	uint* uintbuf = NULL;

	uintbuf = new uint[vec.size()];
	for (unsigned int i=0;i<vec.size();i++) uintbuf[i] = vec[i];

	nc_put_var_uint(ncid, varid, uintbuf);

	delete[] uintbuf;
};

void Cdf::putUbigintVec(
			const int ncid
			, const int varid
			, const vector<ubigint>& vec
		) {
	ubigint* ubigintbuf = NULL;

	ubigintbuf = new ubigint[vec.size()];
	for (unsigned int i=0;i<vec.size();i++) ubigintbuf[i] = vec[i];

	nc_put_var_ulonglong(ncid, varid, ubigintbuf);

	delete[] ubigintbuf;
};

void Cdf::putDoubleVec(
			const int ncid
			, const int varid
			, const vector<double>& vec
		) {
	double* dblbuf = NULL;

	dblbuf = new double[vec.size()];
	for (unsigned int i=0;i<vec.size();i++) dblbuf[i] = vec[i];

	nc_put_var_double(ncid, varid, dblbuf);

	delete[] dblbuf;
};

bool Cdf::getGroup(
			const int ncid
			, const string& path
			, int& pathid
		) {
	bool retval = true;

	vector<string> pathvec;
	pathid = ncid;

	// find group
	StrMod::stringToVector(path, pathvec);
	for (unsigned int i=0;i<pathvec.size();i++) {
		if (nc_inq_ncid(pathid, pathvec[i].c_str(), &pathid) != NC_NOERR) {
			retval = false;
			break;
		};
	};

	return retval;
};

bool Cdf::getBoolVec(
			const int ncid
			, const string& path
			, const string& varsref
			, vector<bool>& vec
		) {
	int pathid;
	int varid;

	int dimid;
	size_t N;

	unsigned char* boolbuf = NULL;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find and adjust vector dimension
			nc_inq_vardimid(pathid, varid, &dimid);
			nc_inq_dimlen(pathid, dimid, &N);
			boolbuf = new unsigned char[N];

			// fetch variable
			nc_get_var_uchar(pathid, varid, boolbuf);
			
			vec.resize(0); vec.resize(N);
			for (unsigned int i=0;i<N;i++) vec[i] = (boolbuf[i] == 1);

			// clean up
			delete[] boolbuf;

			return true;
		};
	};

	return false;
};

bool Cdf::getUintVec(
			const int ncid
			, const string& path
			, const string& varsref
			, vector<uint>& vec
		) {
	int pathid;
	int varid;

	int dimid;
	size_t N;

	uint* uintbuf = NULL;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find and adjust vector dimension
			nc_inq_vardimid(pathid, varid, &dimid);
			nc_inq_dimlen(pathid, dimid, &N);
			uintbuf = new uint[N];

			// fetch variable
			nc_get_var_uint(pathid, varid, uintbuf);
			
			vec.resize(0); vec.resize(N);
			for (unsigned int i=0;i<N;i++) vec[i] = uintbuf[i];

			// clean up
			delete[] uintbuf;

			return true;
		};
	};

	return false;
};

bool Cdf::getUbigintVec(
			const int ncid
			, const string& path
			, const string& varsref
			, vector<ubigint>& vec
		) {
	int pathid;
	int varid;

	int dimid;
	size_t N;

	ubigint* ubigintbuf = NULL;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find and adjust vector dimension
			nc_inq_vardimid(pathid, varid, &dimid);
			nc_inq_dimlen(pathid, dimid, &N);
			ubigintbuf = new ubigint[N];

			// fetch variable
			nc_get_var_ulonglong(pathid, varid, ubigintbuf);
			
			vec.resize(0); vec.resize(N);
			for (unsigned int i=0;i<N;i++) vec[i] = ubigintbuf[i];

			// clean up
			delete[] ubigintbuf;

			return true;
		};
	};

	return false;
};

bool Cdf::getDoubleVec(
			const int ncid
			, const string& path
			, const string& varsref
			, vector<double>& vec
		) {
	int pathid;
	int varid;

	int dimid;
	size_t N;

	double* dblbuf = NULL;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find and adjust vector dimension
			nc_inq_vardimid(pathid, varid, &dimid);
			nc_inq_dimlen(pathid, dimid, &N);
			dblbuf = new double[N];

			// fetch variable
			nc_get_var_double(pathid, varid, dblbuf);
			
			vec.resize(0); vec.resize(N);
			for (unsigned int i=0;i<N;i++) vec[i] = dblbuf[i];

			// clean up
			delete[] dblbuf;

			return true;
		};
	};

	return false;
};

bool Cdf::getDoubleVecSlc(
			const int ncid
			, const string& path
			, const string& varsref
			, const vector<string>& slcDims
			, const vector<int>& slcIcs
			, const unsigned int Ntarget
			, vector<double>& vec
		) {
	int pathid, varid;
	char* dimname = NULL;

	int ndims;
	int* dimids = NULL;
	size_t* start = NULL;
	size_t* count = NULL;

	size_t N;
	double* dblbuf = NULL;

	if (Cdf::getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {

			// retrieve variable dimension information
			nc_inq_varndims(pathid, varid, &ndims);
			dimids = new int[ndims];
			nc_inq_vardimid(pathid, varid, dimids);

			// prepare array read start/counts
			start = new size_t[ndims];
			count = new size_t[ndims];

			dimname = new char[NC_MAX_NAME+1];

			for (int i=0;i<ndims;i++) {
				// initialize with full dimension lengths
				start[i] = 0;
				nc_inq_dimlen(pathid, dimids[i], &(count[i]));

				// override with yslc information where needed
				nc_inq_dimname(pathid, dimids[i], dimname);

				for (unsigned int j=0;j<slcDims.size();j++) {
cout << "slcDim = '" << slcDims[j] << "' vs. dimname = '" << dimname << "'" << endl;
					if (slcDims[j].compare(dimname) == 0) {
						// count[i] holds the dimension length

						if (slcIcs[j] < 0) {
							// negative index: substract from count[i] unless out of range => center
							if ( ((size_t) -slcIcs[j]) <= count[i] ) {
								start[i] = count[i] + slcIcs[j];
							} else {
								start[i] = count[i]/2;
							};

						} else {
							// positive index: actual index unless out of range => center
							if ( ((size_t) slcIcs[j]) < count[i] ) {
								start[i] = slcIcs[j];
							} else {
								start[i] = count[i]/2;
							};
						};

						count[i] = 1;
						
						break;
					};
				};
			};

			// calculate total array size, needs to equal targetted size
			N = 1;
			for (int i=0;i<ndims;i++) N *= count[i];

cout << "N = " << N << ", Ntarget = " << Ntarget << endl;

			// load y data
			if (N == Ntarget) {
				dblbuf = new double[N];

				// fetch variable
				nc_get_vara_double(pathid, varid, start, count, dblbuf);

				vec.resize(0); vec.resize(N);
				for (unsigned int i=0;i<N;i++) vec[i] = dblbuf[i];
				
				// clean up
				delete[] dblbuf;
			};

			delete[] dimids;
			delete[] start;
			delete[] count;
			delete[] dimname;
			
			return true;
		};
	};

	return false;
};

bool Cdf::getUint(
			const int ncid
			, const string& path
			, const string& varsref
			, uint& val
		) {
	int pathid;
	int varid;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// fetch variable
			nc_get_var_uint(pathid, varid, &val);
			return true;
		};
	};

	return false;
};

bool Cdf::getDouble(
			const int ncid
			, const string& path
			, const string& varsref
			, double& val
		) {
	int pathid;
	int varid;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// fetch variable
			nc_get_var_double(pathid, varid, &val);
			return true;
		};
	};

	return false;
};

bool Cdf::getDim(
			const int ncid
			, const string& path
			, const string& dimsref
			, int& dimid
			, unsigned int& dimlen
		) {
	int pathid;

	size_t N;

	if (getGroup(ncid, path, pathid)) {
		// find dimension
		if (nc_inq_dimid(pathid, dimsref.c_str(), &dimid) == NC_NOERR) {
			nc_inq_dimlen(pathid, dimid, &N);
			dimlen = N;

			return true;
		};
	};

	return false;
};

bool Cdf::getAttr(
			const int ncid
			, const string& path
			, const string& varsref
			, const string& attrsref
			, string& attr
		) {
	int pathid;
	int varid;

	char* attrbuf = NULL;
	size_t attrlen;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find attribute
			if (nc_inq_attlen(pathid, varid, attrsref.c_str(), &attrlen) == NC_NOERR) {
				attrbuf = new char[attrlen];

				nc_get_att_text(pathid, varid, attrsref.c_str(), attrbuf);
				attr = attrbuf;

				delete[] attrbuf;

				return true;
			};
		};
	};

	return false;
};

/******************************************************************************
 class Rlychunk
 ******************************************************************************/

Rlychunk::Rlychunk() {
	start = 0;
	stop = 0;
	
	refRlyBwd = 0;
	refRlyFwd = 0;

	bwd = true;

	ctdBwd = false;
	ctdFwd = false;
	
	Nhop = 0;
};

Rlychunk::Rlychunk(
			BrlyMRelay* rly
		) {
	start = rly->x1Start;
	stop = rly->x1Stop;

	if (rly->ixVDir == VecBrlyVMRelayDir::BWD) {
		refRlyBwd = rly->ref;
		refRlyFwd = 0;

		bwd = true;

		ctdBwd = rly->Connected;
		ctdFwd = false;

		Nhop = rly->Nhop;

	} else {
		refRlyBwd = 0;
		refRlyFwd = rly->ref;

		bwd = false;

		ctdBwd = false;
		ctdFwd = rly->Connected;

		Nhop = rly->Nhop;
	};
};

void Rlychunk::dump() {
	cout << "\t\t" << start << "-" << stop << ": ";

	if (!ctdBwd && !ctdFwd) {
		if (Nhop == 0) cout << "alone"; // doesn't exist
		else cout << "isolated with " << Nhop << " hops";
	} else if (!ctdBwd && ctdFwd) cout << "connected forward";
	else if (ctdBwd && !ctdBwd) cout << "connected backward";
	else cout << "connected both ways";

	cout << endl;
};

/******************************************************************************
 class Rlystat
 ******************************************************************************/

Rlystat::Rlystat(
			DbsBrly* dbsbrly
			, BrlyMConnection* con
		) {
	start = con->start;
	stop = con->stop;

	dbsbrly->tblbrlymrelay->loadRstByCon(con->ref, false, rlys);
	for (unsigned int i=0;i<rlys.nodes.size();i++) listRly.push_back(Rlychunk(rlys.nodes[i]));

	statsBwdFwd();

	boilDown();

	statsCombined();

	itLast = listRly.end();
};

void Rlystat::boilDown() {
	list<Rlychunk>::iterator it2;
	Rlychunk rc;

	bool usebwd;

	// --- discard all non-connected chunks
//	for (list<Rlychunk>::iterator it=listRly.begin() ; it!=listRly.end() ; it++) {
//		while (!(*it).ctdBwd && !(*it).ctdFwd) {
//			it = listRly.erase(it);
//			if (it == listRly.end()) break;
//		};
//	};

	// --- discard all non-connected chunks that do no even have connections to other flights
	for (list<Rlychunk>::iterator it=listRly.begin() ; it!=listRly.end() ; it++) {
		while (!(*it).ctdBwd && !(*it).ctdFwd && ((*it).Nhop == 0)) {
			it = listRly.erase(it);
			if (it == listRly.end()) break;
		};
	};

	// --- split-join chunks in case of overlaps (chunks are in time-linear order, same start of subsequent chunks can occur)
	for (list<Rlychunk>::iterator it=listRly.begin() ; it!=listRly.end() ; ) {
		// -- compare with next chunk
		it2 = it;
		it2++;
		if (it2 == listRly.end()) break;

		if ((*it).start == (*it2).start) {
			if ((*it).stop == (*it2).stop) {
				// - full overlap, keep *it, discard *it2, continue at new it.next
				if ((*it).bwd == true) {
					// it2 is fwd
					(*it).refRlyFwd = (*it2).refRlyFwd;
					(*it).ctdFwd = (*it2).ctdFwd;

					usebwd = ( ((*it).ctdBwd && !(*it2).ctdFwd) || ((*it).ctdBwd && (*it2).ctdFwd && ((*it2).Nhop >= (*it).Nhop)) );

					if (!usebwd) {
						(*it).bwd = false;
						(*it).Nhop = (*it2).Nhop;
					};

				} else {
					// it2 is bwd
					(*it).refRlyBwd = (*it2).refRlyBwd;
					(*it).ctdBwd = (*it2).ctdBwd;

					usebwd = ( ((*it2).ctdBwd && !(*it).ctdFwd) || ((*it2).ctdBwd && (*it).ctdFwd && ((*it).Nhop >= (*it2).Nhop)) );

					if (usebwd) {
						(*it).bwd = true;
						(*it).Nhop = (*it2).Nhop;
					};
				};

				listRly.erase(it2);
				it++;

			} else {
				// - partial overlap, same start
				if ((*it).stop > (*it2).stop) {
					// make sure *it2 ends after *it
					rc = (*it2);
					(*it2) = (*it);
					(*it) = rc;
				};

				// *it shorter than *it2, modify *it, delay *it2, continue at it2
				if ((*it).bwd == true) {
					// it2 is fwd
					(*it).refRlyFwd = (*it2).refRlyFwd;
					(*it).ctdFwd = (*it2).ctdFwd;

					usebwd = ( ((*it).ctdBwd && !(*it2).ctdFwd) || ((*it).ctdBwd && (*it2).ctdFwd && ((*it2).Nhop >= (*it).Nhop)) );

					if (!usebwd) {
						(*it).bwd = false;
						(*it).Nhop = (*it2).Nhop;
					};

				} else {
					// it2 is bwd
					(*it).refRlyBwd = (*it2).refRlyBwd;
					(*it).ctdBwd = (*it2).ctdBwd;

					usebwd = ( ((*it2).ctdBwd && !(*it).ctdFwd) || ((*it2).ctdBwd && (*it).ctdFwd && ((*it).Nhop >= (*it2).Nhop)) );

					if (usebwd) {
						(*it).bwd = true;
						(*it).Nhop = (*it2).Nhop;
					};
				};

				(*it2).start = (*it).stop + 1;

				it = it2; // equivalent to it++
			};

		} else if ((*it2).start <= (*it).stop) {
			// - partial overlap, non-same start, split *it, contunue at new it.next
			rc = (*it);

			(*it).stop = (*it2).start - 1;
			rc.start = (*it2).start;

			listRly.insert(it2, rc);

			it++;

		} else {
			// - no overlap
			it++;
		};
	};
};

void Rlystat::statsBwdFwd() {
	// determine values of pCtdBwd, pCtdFwd, avgNhopBwd, avgNhopFwd ; notably, pCtd = pCtdBwd + pCtdFwd
	double d;

	pCtdBwd = 0.0;
	pCtdFwd = 0.0;
	avgNhopBwd = 0.0;
	avgNhopFwd = 0.0;

	for (list<Rlychunk>::iterator it=listRly.begin() ; it!=listRly.end() ; it++) {
		if ((*it).ctdBwd || (*it).ctdFwd) {
			d = ((double) ((*it).stop-(*it).start+1));

			if ((*it).bwd) {
				pCtdBwd += d;
				avgNhopBwd += d * ((double) (*it).Nhop);
			} else {
				pCtdFwd += d;
				avgNhopFwd += d * ((double) (*it).Nhop);
			};
		};
	};

	// normalize average hop count to connected time span
	avgNhopBwd /= pCtdBwd;
	avgNhopFwd /= pCtdFwd;

	// normalize to entire time span
	pCtdBwd /= ((double) (stop-start));
	pCtdFwd /= ((double) (stop-start));
};

void Rlystat::statsCombined() {
	// determine values of pCtd, pCtdBoth, avgNhop
	double d;

	pCtd = 0.0;
	pCtdBoth = 0.0;
	avgNhop = 0.0;

	for (list<Rlychunk>::iterator it=listRly.begin() ; it!=listRly.end() ; it++) {
		d = ((double) ((*it).stop-(*it).start+1));

		if ((*it).ctdBwd || (*it).ctdFwd) {
			pCtd += d;
			avgNhop += d * ((double) (*it).Nhop);
		};

		if ((*it).ctdBwd && (*it).ctdFwd) pCtdBoth += d;
	};

	// normalize average hop count to connected time span
	avgNhop /= pCtd;

	// normalize to entire time span
	pCtd /= ((double) (stop-start));
	pCtdBoth /= ((double) (stop-start));
};

bool Rlystat::getCtd(
			const unsigned int t
		) {
	bool retval = false;

	if (listRly.size() != 0) {
		if (itLast == listRly.end()) itLast = listRly.begin();

		if ((t >= (*itLast).start) && (t <= (*itLast).stop)) {
			// first guess: chunk of last call
			retval = ((*itLast).ctdBwd || (*itLast).ctdFwd);

		} else if ((t < (*itLast).start) && (itLast != listRly.begin())) {
			// next guesses: surroundings of last call
			do {
				itLast--;

				if ((t >= (*itLast).start) && (t <= (*itLast).stop)) {
					retval = ((*itLast).ctdBwd || (*itLast).ctdFwd);
					break;
				};
			} while (itLast != listRly.begin());

		} else if ((t > (*itLast).stop)) {
			for (itLast++ ; itLast!=listRly.end() ; itLast++) {
				if ((t >= (*itLast).start) && (t <= (*itLast).stop)) {
					retval = ((*itLast).ctdBwd || (*itLast).ctdFwd);
					break;
				};
			};
		};
	};

	return retval;
};
// IP cust --- IEND

/******************************************************************************
 namespace Brly
 ******************************************************************************/

// IP gbl --- IBEGIN
void Brly::loadLegsByArena(
			DbsBrly* dbsbrly
			, const string arena
			, const bool go
			, const bool back
			, const bool corr
			, vector<ubigint>& refsLeg1
			, vector<ubigint>& refsLeg2
		) {
	vector<ubigint> refs;
	ubigint ref, ref2;

	vector<ubigint> refsLoc1;
	vector<ubigint> refsLoc2;

	uint ixVBasetype;

	// --- load relevant begin/end locations
	refsLoc1.resize(0);
	refsLoc2.resize(0);

	if (arena.compare("to1") == 0) {
		// -- trans-oceanic arenas "to"

		// - North Atlantic arena (eu <-> am;n)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "eu", ref)) {
			dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

			for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
		};

		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "am", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "n", ref)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
			};
		};

	} else if (arena.compare("to2") == 0) {
		// - South Atlantic arena (eu <-> am;s;ar, am;s;br, am;s;cl, am;s;uy)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "eu", ref)) {
			dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

			for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
		};

		refs.resize(0);
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "am", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "s", ref)) {

				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "ar", ref2)) {
					dbsbrly->tblbrlymregion->loadHrefsdown(ref2, false, refs);
					for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
				};
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "br", ref2)) {
					dbsbrly->tblbrlymregion->loadHrefsdown(ref2, false, refs);
					for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
				};
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "cl", ref2)) {
					dbsbrly->tblbrlymregion->loadHrefsdown(ref2, false, refs);
					for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
				};
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "uy", ref2)) {
					dbsbrly->tblbrlymregion->loadHrefsdown(ref2, false, refs);
					for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
				};
			};
		};

	} else if (arena.compare("to3") == 0) {
		// - North Pacific arena (am;n <-> as;e, as;se)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "am", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "n", ref)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
			};
		};

		refs.resize(0);
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "as", ref)) {

			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "e", ref2)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref2, false, refs);
				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
			};
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "se", ref2)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref2, false, refs);
				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
			};
		};

	} else if (arena.compare("to4") == 0) {
		// - Continental U.S. - Hawaii arena (am;n;us ex. hi <-> am;n;us;hi)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "am", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "n", ref)) {
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "us", ref)) {
					dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

					if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "hi", ref2)) for (unsigned int i=0;i<refs.size();i++) if (refs[i] == ref2) refs[i] = 0;

					for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
				};
			};
		};

		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "am", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "n", ref)) {
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "us", ref)) {
					if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "hi", ref)) {
						dbsbrly->tblbrlymlocation->loadRefsByReg(ref, false, refsLoc2);
					};
				};
			};
		};

	} else if (arena.compare("ico1") == 0) {
		// -- other inter-continental arenas (ico)

		// - Trans African arena (eu <-> af;s;za)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "eu", ref)) {
			dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

			for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
		};

		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "af", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "s", ref)) {
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "za", ref)) {
					dbsbrly->tblbrlymlocation->loadRefsByReg(ref, false, refsLoc2);
				};
			};
		};

	} else if (arena.compare("ico2") == 0) {
		// - Trans Siberian arena (eu <-> as;e)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "eu", ref)) {
			dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

			for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
		};

		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "as", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "e", ref)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
			};
		};

	} else if (arena.compare("ico3") == 0) {
		// - Pan American arena (am;n <-> am;s)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "am", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "n", ref)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
			};
		};

		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "am", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "s", ref)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
			};
		};

	} else if (arena.compare("ico4") == 0) {
		// - New Zealand - Asian arena (oc;aa;nz <-> as;e, as;se)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "oc", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "aa", ref)) {
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "nz", ref)) {
					dbsbrly->tblbrlymlocation->loadRefsByReg(ref, false, refsLoc1);
				};
			};
		};

		refs.resize(0);
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "as", ref)) {

			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "e", ref2)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref2, false, refs);
				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
			};
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "se", ref2)) {
				dbsbrly->tblbrlymregion->loadHrefsdown(ref2, false, refs);
				for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc2);
			};
		};

	} else if (arena.compare("co1") == 0) {
		// - European arena (eu)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "eu", ref)) {
			dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

			for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
		};

		refsLoc2 = refsLoc1;

	} else if (arena.compare("co2") == 0) {
		// - Contiguous U.S. arena (am;n;us ex. hi, ak)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "am", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "n", ref)) {
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "us", ref)) {
					dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

					if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "hi", ref2)) for (unsigned int i=0;i<refs.size();i++) if (refs[i] == ref2) refs[i] = 0;
					if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "ak", ref2)) for (unsigned int i=0;i<refs.size();i++) if (refs[i] == ref2) refs[i] = 0;

					for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
				};
			};
		};

		refsLoc2 = refsLoc1;

	} else if (arena.compare("co3") == 0) {
		// - Chinese arena (as;se;cn)
		if (dbsbrly->tblbrlymregion->loadRefBySupSrf(0, "as", ref)) {
			if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "se", ref)) {
				if (dbsbrly->tblbrlymregion->loadRefBySupSrf(ref, "cn", ref)) {
					dbsbrly->tblbrlymregion->loadHrefsdown(ref, false, refs);

					for (unsigned int i=0;i<refs.size();i++) dbsbrly->tblbrlymlocation->loadRefsByReg(refs[i], true, refsLoc1);
				};
			};
		};

		refsLoc2 = refsLoc1;
	};

	// --- load relevant routes/corridors
	ixVBasetype = ((corr) ? VecBrlyVMLegBasetype::CORR : VecBrlyVMLegBasetype::RTE);

	if (go) {
		refsLeg1.resize(0);
		for (unsigned int i=0;i<refsLoc1.size();i++) {
			for (unsigned int j=0;j<refsLoc2.size();j++) {
				if (dbsbrly->tblbrlymleg->loadRefByTypBloElo(ixVBasetype, refsLoc1[i], refsLoc2[j], ref)) refsLeg1.push_back(ref);
			};
		};
	};

	if (back) {
		refsLeg2.resize(0);
		for (unsigned int i=0;i<refsLoc1.size();i++) {
			for (unsigned int j=0;j<refsLoc2.size();j++) {
				if (dbsbrly->tblbrlymleg->loadRefByTypBloElo(ixVBasetype, refsLoc2[j], refsLoc1[i], ref)) refsLeg2.push_back(ref);
			};
		};
	};
};

bool Brly::isInArena(
			const vector<ubigint>& refsLeg
			, const ubigint refLeg
		) {
	for (unsigned int i=0;i<refsLeg.size();i++) if (refsLeg[i] == refLeg) return true;

	return false;
};

void Brly::initEqplineup(
			DbsBrly* dbsbrly
			, const ubigint refBrlyMConnection
			,	list<ubigint>& lineup
			, ListBrlyORMConnectionMEquipment& ops
		) {
	// return initial equipment line-up, for both ops and lineup: replace refLR by refEqp

	ListBrlyLRMConnectionMEquipment conLReqps;
	BrlyLRMConnectionMEquipment* conLReqp = NULL;

	map<ubigint,ubigint> eqprefs;

	BrlyORMConnectionMEquipment* op = NULL;

	ops.clear();
	lineup.resize(0);

	dbsbrly->tblbrlylrmconnectionmequipment->loadRstByCon(refBrlyMConnection, false, conLReqps);

	for (unsigned int i=0;i<conLReqps.nodes.size();i++) {
		conLReqp = conLReqps.nodes[i];

		eqprefs[conLReqp->ref] = conLReqp->refBrlyMEquipment;
		if (conLReqp->conIxBrlyVLat == VecBrlyVLat::INI) lineup.push_back(conLReqp->refBrlyMEquipment);
	};

	dbsbrly->tblbrlyormconnectionmequipment->loadRstByCon(refBrlyMConnection, false, ops);

	for (unsigned int i=0;i<ops.nodes.size();i++) {
		op = ops.nodes[i];

		op->pr1RefLR = eqprefs[op->pr1RefLR];
		if (op->pr2RefLR != 0) op->pr2RefLR = eqprefs[op->pr2RefLR];
	};
};

ubigint Brly::advanceEqplineup(
			list<ubigint>& lineup
			, ListBrlyORMConnectionMEquipment& ops
			, ubigint opix
			, uint t
		) {
	BrlyORMConnectionMEquipment* op = NULL;

	list<ubigint>::iterator it;
	list<ubigint>::iterator it2;

	// apply operators sequentially
	for (;opix<ops.nodes.size();opix++) {
		op = ops.nodes[opix];

		if (op->x1Start > t) break;

		if (op->ixBrlyVOolop == VecBrlyVOolop::INA) {
			// insert in list
			for (it=lineup.begin() ; it!=lineup.end() ; it++) if ((*it) == op->pr2RefLR) break;
			if (it==lineup.end())
				lineup.insert(lineup.begin(), op->pr1RefLR);
			else
				lineup.insert(++it, op->pr1RefLR);

		} else if (op->ixBrlyVOolop == VecBrlyVOolop::TOB) {
			// move element pr1RefLR to position before pr2RefLR
			for (it=lineup.begin() ; it!=lineup.end() ; it++) if ((*it) == op->pr1RefLR) break;
			for (it2=lineup.begin() ; it2!=lineup.end() ; it2++) if ((*it2) == op->pr2RefLR) break;

			if ((it!=lineup.end()) && (it2!=lineup.end())) {
				lineup.insert(it2, (*it));
				lineup.erase(it);

			} else {
				//cout << "swap error!" << endl;
			};

		} else if (op->ixBrlyVOolop == VecBrlyVOolop::TOA) {
			// move element pr1RefLR to position after pr2RefLR
			for (it=lineup.begin() ; it!=lineup.end() ; it++) if ((*it) == op->pr1RefLR) break;
			for (it2=lineup.begin() ; it2!=lineup.end() ; it2++) if ((*it2) == op->pr2RefLR) break;

			if ((it!=lineup.end()) && (it2!=lineup.end())) {
				lineup.insert(++it2, (*it));
				lineup.erase(it);

			} else {
				//cout << "swap error!" << endl;
			};

		} else if (op->ixBrlyVOolop == VecBrlyVOolop::RMV) {
			// remove
			lineup.remove(op->pr1RefLR);
		};
	};

	return opix;
};
// IP gbl --- IEND

/******************************************************************************
 namespace OpengBrly
 ******************************************************************************/

void OpengBrly::getIcsBrlyVOppackByIxBrlyVOpengtype(
			const uint ixBrlyVOpengtype
			, vector<uint>& icsBrlyVOppack
		) {
	icsBrlyVOppack.clear();

	if (ixBrlyVOpengtype == VecBrlyVOpengtype::BRLYOPD) {
		push_back(icsBrlyVOppack, VecBrlyVOppack::BRLYBASE);
		push_back(icsBrlyVOppack, VecBrlyVOppack::BRLYDNSMAP);
		push_back(icsBrlyVOppack, VecBrlyVOppack::BRLYDYN);
		push_back(icsBrlyVOppack, VecBrlyVOppack::BRLYMAPGEN);
		push_back(icsBrlyVOppack, VecBrlyVOppack::BRLYTTIMP);
	};
};

void OpengBrly::getIcsBrlyVDpchByIxBrlyVOppack(
			const uint ixBrlyVOppack
			, set<uint>& icsBrlyVDpch
		) {
	if (ixBrlyVOppack == VecBrlyVOppack::BRLYBASE) {
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYBASELEGLEG);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYBASELEGLOC);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYBASELOCLOC);
	} else if (ixBrlyVOppack == VecBrlyVOppack::BRLYDNSMAP) {
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDNSMAPCOLLECT);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDNSMAPFRAME);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDNSMAPVIDEO);
	} else if (ixBrlyVOppack == VecBrlyVOppack::BRLYDYN) {
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDYNCONFLT);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDYNCONSEG);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDYNEQPLIST);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDYNFLTFLTLOC);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDYNFLTSEG);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDYNRLY);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYDYNSEGLOCSEG);
	} else if (ixBrlyVOppack == VecBrlyVOppack::BRLYMAPGEN) {
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYMAPGENCONMAP);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYMAPGENLEGMAP);
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYMAPGENLOCMAP);
	} else if (ixBrlyVOppack == VecBrlyVOppack::BRLYTTIMP) {
		insert(icsBrlyVDpch, VecBrlyVDpch::DPCHINVBRLYTTIMPRAWSTAR);
	};
};

/******************************************************************************
 namespace StubBrly
 ******************************************************************************/

string StubBrly::getStub(
			DbsBrly* dbsbrly
			, const uint ixBrlyVStub
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	if (ixBrlyVStub == VecBrlyVStub::STUBBRLYCONSTD) return getStubConStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYEQPSHORT) return getStubEqpShort(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYEQPSTD) return getStubEqpStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYFAFSTD) return getStubFafStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYFILSTD) return getStubFilStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYFLTSREF) return getStubFltSref(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYFLTSTD) return getStubFltStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYGRP) return getStubGrp(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYLEGSHORT) return getStubLegShort(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYLEGSTD) return getStubLegStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYLOCSREF) return getStubLocSref(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYLOCSTD) return getStubLocStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYLOCTITLE) return getStubLocTitle(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYNDELONG) return getStubNdeLong(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYNDESTD) return getStubNdeStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYOPRSREF) return getStubOprSref(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYOPRSTD) return getStubOprStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYOWN) return getStubOwn(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYPRSSTD) return getStubPrsStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYPTYSREF) return getStubPtySref(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYPTYSTD) return getStubPtyStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYREGHSREF) return getStubRegHsref(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYREGLONG) return getStubRegLong(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYREGSTD) return getStubRegStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYRLYLONG) return getStubRlyLong(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYRLYSTD) return getStubRlyStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYSEGSTD) return getStubSegStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYSESMENU) return getStubSesMenu(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYSESSTD) return getStubSesStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYTTBSTD) return getStubTtbStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYTTBTITLE) return getStubTtbTitle(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYUSGSTD) return getStubUsgStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixBrlyVStub == VecBrlyVStub::STUBBRLYUSRSTD) return getStubUsrStd(dbsbrly, ref, ixBrlyVLocale, ixVNonetype, stcch, strefSub, refresh);

	return("");
};

string StubBrly::getStubConStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "SK1228 2006-12-1 FRA-JFK simplified"
	string stub;

	BrlyMConnection* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYCONSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no connection)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Verbindung)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymconnection->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubConStd --- IBEGIN
			stub = getStubFltStd(dbsbrly, rec->refBrlyMFlight, ixBrlyVLocale, ixVNonetype, stcch, &stref) + " " + VecBrlyVMConnectionModel::getTitle(rec->ixVModel, ixBrlyVLocale);
			// IP getStubConStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubEqpShort(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "SK1228 2006-12-1 A346"
	string stub;

	BrlyMEquipment* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYEQPSHORT, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keines)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no equipment)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Ger\\u00e4t)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymequipment->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubEqpShort --- IBEGIN
			if (rec->hkIxVTbl == VecBrlyVMEquipmentHkTbl::FLT) {
				stub = getStubFltSref(dbsbrly, rec->hkUref, ixBrlyVLocale, ixVNonetype, stcch, &stref) + " " + getStubPtySref(dbsbrly, rec->hkUref, ixBrlyVLocale, ixVNonetype, stcch, &stref);
			} else if (rec->hkIxVTbl == VecBrlyVMEquipmentHkTbl::LOC) {
				stub = getStubLocSref(dbsbrly, rec->hkUref, ixBrlyVLocale, ixVNonetype, stcch, &stref) + " " + getStubOprSref(dbsbrly, rec->refBrlyMOperator, ixBrlyVLocale, ixVNonetype, stcch, &stref) + " " + rec->srefBrlyKEqptype;
			};
			// IP getStubEqpShort --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubEqpStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Lufthansa Airbus A340-600"
	string stub;

	BrlyMEquipment* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYEQPSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keines)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no equipment)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Ger\\u00e4t)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymequipment->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubEqpStd --- IBEGIN
			stub = getStubOprStd(dbsbrly, rec->refBrlyMOperator, ixBrlyVLocale, ixVNonetype, stcch, &stref) + " ";
			if (rec->hkIxVTbl == VecBrlyVMEquipmentHkTbl::FLT) {
				stub += getStubPtyStd(dbsbrly, rec->refBrlyMPlntype, ixBrlyVLocale, ixVNonetype, stcch, &stref);
			} else {
				stub += dbsbrly->getKlstTitleBySref(VecBrlyVKeylist::KLSTBRLYKEQPTYPE, rec->srefBrlyKEqptype, ixBrlyVLocale);
			};
			// IP getStubEqpStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubFafStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "AAL1-1394087399-airline-0116"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYFAFSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no FlightAware flight)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein FlightAware Flug)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymfaflight->loadFidByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubFilStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "StarFlugplan.txt"
	string stub;

	BrlyMFile* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYFILSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no file)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Datei)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymfile->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubFilStd --- IBEGIN
			stub = rec->Filename;
			if (rec->osrefKContent.length() > 0) stub += + " (" + rec->osrefKContent + ")";
			// IP getStubFilStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubFltSref(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "SK1228 2006-12-1"
	string stub;

	BrlyMFlight* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYFLTSREF, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no flight)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Flug)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymflight->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubFltSref --- IBEGIN
			stub = rec->sref;
			// IP getStubFltSref --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubFltStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "SK1228 2006-12-1 FRA-JFK"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYFLTSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no flight)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Flug)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymflight->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubGrp(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "agroup"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYGRP, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no user group)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Benutzergruppe)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubLegShort(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "FRA-JFK"
	string stub;

	BrlyMLeg* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYLEGSHORT, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no leg)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Strecke)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymleg->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubLegShort --- IBEGIN
			stub = getStubLocSref(dbsbrly, rec->bgnRefBrlyMLocation, ixBrlyVLocale, ixVNonetype, stcch, &stref) + "-" + getStubLocSref(dbsbrly, rec->endRefBrlyMLocation, ixBrlyVLocale, ixVNonetype, stcch, &stref);
			// IP getStubLegShort --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubLegStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "(route) Frankfurt - New York JFK"
	string stub;

	BrlyMLeg* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYLEGSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no leg)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Strecke)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymleg->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubLegStd --- IBEGIN
			stub = "(" + VecBrlyVMLegBasetype::getTitle(rec->ixVBasetype, ixBrlyVLocale) + ") ";
			stub += getStubLocTitle(dbsbrly, rec->bgnRefBrlyMLocation, ixBrlyVLocale, ixVNonetype, stcch, &stref) + " - " + getStubLocTitle(dbsbrly, rec->endRefBrlyMLocation, ixBrlyVLocale, ixVNonetype, stcch, &stref);
			// IP getStubLegStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubLocSref(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "FRA"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYLOCSREF, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no location)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Ort)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymlocation->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubLocStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "(airport) Frankfurt"
	string stub;

	BrlyMLocation* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYLOCSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no location)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Ort)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymlocation->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubLocStd --- IBEGIN
			stub = "(" + VecBrlyVMLocationBasetype::getTitle(rec->ixVBasetype, ixBrlyVLocale, ixVNonetype, stcch, &stref) + ") " + rec->Title;
			// IP getStubLocStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubLocTitle(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Frankfurt"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYLOCTITLE, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no location)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Ort)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymlocation->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubNdeLong(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "#5, 0:0:0-0:10:23 for conn. SK1228 2006-12-1 FRA-JFK simplified"
	string stub;

	BrlyMNode* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYNDELONG, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no node)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Knotenpunkt)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymnode->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubNdeLong --- IBEGIN
			ostringstream str;

			str.str(""); str << "#" << rec->supLvl << ", ";
			str << getStubRlyLong(dbsbrly, rec->refBrlyMRelay, ixBrlyVLocale, ixVNonetype, stcch, &stref);

			stub = str.str();
			// IP getStubNdeLong --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubNdeStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "SK1228 2006-12-1 LH A346"
	string stub;

	BrlyMNode* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYNDESTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no node)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Knotenpunkt)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymnode->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubNdeStd --- IBEGIN
			stub = getStubEqpShort(dbsbrly, rec->refBrlyMEquipment, ixBrlyVLocale, ixVNonetype, stcch, &stref);
			// IP getStubNdeStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubOprSref(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "LH"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYOPRSREF, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no operator)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Betreiber)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymoperator->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubOprStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Lufthansa"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYOPRSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no operator)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Betreiber)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymoperator->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubOwn(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "auser"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYOWN, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no user)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Benutzer)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymuser->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubPrsStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Franz Kuntz"
	string stub;

	BrlyMPerson* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYPRSSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no person)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Person)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubBrlyPrsStd --- BEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
			// IP getStubBrlyPrsStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubPtySref(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "A346"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYPTYSREF, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no plane type)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Flugzeugtyp)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymplntype->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubPtyStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Airbus A340-600"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYPTYSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no plane type)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Flugzeugtyp)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymplntype->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubRegHsref(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "eu;c"
	string stub;

	BrlyMRegion* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYREGHSREF, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no region)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Region)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymregion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefBrlyMRegion != 0) stub = getStubRegHsref(dbsbrly, rec->supRefBrlyMRegion, ixBrlyVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubRegLong(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Europe;Central"
	string stub;

	BrlyMRegion* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYREGLONG, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no region)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Region)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymregion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubRegLong --- IBEGIN
			// override title (locale-dependent)
			BrlyJMRegionTitle* regJtit = NULL;

			if (dbsbrly->tblbrlyjmregiontitle->loadRecByRegLcl(rec->ref, ixBrlyVLocale, &regJtit)) {
				rec->Title = regJtit->Title;
				delete regJtit;
			};
			
			stub = rec->Title;

			// super region
			if (rec->supRefBrlyMRegion != 0) stub = getStubRegLong(dbsbrly, rec->supRefBrlyMRegion, ixBrlyVLocale, ixVNonetype, stcch, &stref) + " - " + stub;
			// IP getStubRegLong --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubRegStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Germany"
	string stub;

	BrlyMRegion* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYREGSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no region)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Region)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymregion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubRegStd --- IBEGIN
			BrlyJMRegionTitle* regJtit = NULL;

			if (dbsbrly->tblbrlyjmregiontitle->loadRecByRegLcl(rec->ref, ixBrlyVLocale, &regJtit)) {
				stub = regJtit->Title;
				delete regJtit;
			} else {
				stub = rec->Title;
			};
			// IP getStubRegStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubRlyLong(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "0:0:0-0:10:23 for conn. SK1228 2006-12-1 FRA-JFK simplified"
	string stub;

	BrlyMRelay* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYRLYLONG, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no relay)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Verbindungskette)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymrelay->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubRlyLong --- IBEGIN
			stub = Ftm::timeOfDay(rec->x1Start) + "-" + Ftm::timeOfDay(rec->x1Stop);

			if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub += " f&#252;r Verb. ";
			else if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub += " for conn. ";

			stub += getStubConStd(dbsbrly, rec->refBrlyMConnection, ixBrlyVLocale, ixVNonetype, stcch, &stref);
			// IP getStubRlyLong --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubRlyStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "forward, conn., 5 hops"
	string stub;

	BrlyMRelay* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYRLYSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no relay)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Verbindungskette)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymrelay->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubRlyStd --- IBEGIN
			stub = VecBrlyVMRelayDir::getTitle(rec->ixVDir, ixBrlyVLocale) + ", ";

			if (ixBrlyVLocale == VecBrlyVLocale::DECH) {
				if (!rec->Connected) stub += "nicht ";
				stub += "verb., " + to_string(rec->Nhop) + " Schritte";
			} else if (ixBrlyVLocale == VecBrlyVLocale::ENUS) {
				if (!rec->Connected) stub += "not ";
				stub += "conn., " + to_string(rec->Nhop) + " hops";
			};
			// IP getStubRlyStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubSegStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "#4, 12:30:55-13:20:20"
	string stub;

	BrlyMSegment* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYSEGSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keines)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no segment)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Segment)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymsegment->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubSegStd --- IBEGIN
			stub = "#" + to_string(rec->refNum) + ", " + Ftm::timeOfDay(rec->start) + "-" + Ftm::timeOfDay(rec->stop);
			// IP getStubSegStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubSesMenu(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Session by Franz Kuntz (fkuntz);logged in from 127.0.0.1;since 01-01-2010 10:34"
	string stub;

	BrlyMSession* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYSESMENU, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no session)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Siztung)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubBrlySesMenu --- BEGIN
			if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "user " + getStubUsrStd(dbsbrly, rec->refBrlyMUser, ixBrlyVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
			else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "Benutzer " + getStubUsrStd(dbsbrly, rec->refBrlyMUser, ixBrlyVLocale, ixVNonetype, stcch, &stref) + ";eingeloggt von " + rec->Ip + ";seit " + Ftm::stamp(rec->start);
			// IP getStubBrlySesMenu --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubSesStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "7-2-2013 22:29:41 von 192.168.0.12"
	string stub;

	BrlyMSession* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYSESSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no session)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Siztung)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubBrlySesStd --- BEGIN
			if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
			else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = Ftm::stamp(rec->start) + " von " + rec->Ip;
			// IP getStubBrlySesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubTtbStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Star Alliance 2006/07 1-12-2006 - 16-2-2007"
	string stub;

	BrlyMTimetable* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYTTBSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no timetable)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Flugplan)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymtimetable->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubTtbStd --- IBEGIN
			stub = rec->Title + " " + Ftm::date(rec->startd) + " - " + Ftm::date(rec->stopd);
			// IP getStubTtbStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubBrly::getStubTtbTitle(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Star Alliance 2006/07"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYTTBTITLE, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no timetable)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Flugplan)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymtimetable->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubUsgStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "super"
	string stub;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYUSGSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no user group)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keine Benutzergruppe)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubBrly::getStubUsrStd(
			DbsBrly* dbsbrly
			, const ubigint ref
			, const uint ixBrlyVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Franz Kuntz (fkuntz)"
	string stub;

	BrlyMUser* rec = NULL;

	stcchitemref_t stref(VecBrlyVStub::STUBBRLYUSRSTD, ref, ixBrlyVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(none)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixBrlyVLocale == VecBrlyVLocale::ENUS) stub = "(no user)";
		else if (ixBrlyVLocale == VecBrlyVLocale::DECH) stub = "(kein Benutzer)";
	};

	if (ref != 0) {
		if (dbsbrly->tblbrlymuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubBrlyUsrStd --- BEGIN
			stub = rec->sref + " / " + getStubPrsStd(dbsbrly, rec->refBrlyMPerson, ixBrlyVLocale, ixVNonetype, stcch, &stref);
			// IP getStubBrlyUsrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

/******************************************************************************
 class ContInfBrlyAlert
 ******************************************************************************/

ContInfBrlyAlert::ContInfBrlyAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
			, const string& TxtMsg11
			, const string& TxtMsg12
		) : Block() {
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;
	this->TxtMsg11 = TxtMsg11;
	this->TxtMsg12 = TxtMsg12;

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10, TXTMSG11, TXTMSG12};
};

bool ContInfBrlyAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;
	if (!find(items, TXTMSG11)) return false;
	if (!find(items, TXTMSG12)) return false;

	return true;
};

void ContInfBrlyAlert::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfBrlyAlert";

	string itemtag;
	if (shorttags)
		itemtag = "Ci";
	else
		itemtag = "ContitemInfBrlyAlert";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpt", TxtCpt);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg1", TxtMsg1);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg2", TxtMsg2);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg3", TxtMsg3);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg4", TxtMsg4);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg5", TxtMsg5);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg6", TxtMsg6);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg7", TxtMsg7);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg8", TxtMsg8);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg9", TxtMsg9);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg10", TxtMsg10);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg11", TxtMsg11);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg12", TxtMsg12);
	xmlTextWriterEndElement(wr);
};

set<uint> ContInfBrlyAlert::compare(
			const ContInfBrlyAlert* comp
		) {
	set<uint> items;

	if (TxtCpt == comp->TxtCpt) insert(items, TXTCPT);
	if (TxtMsg1 == comp->TxtMsg1) insert(items, TXTMSG1);
	if (TxtMsg2 == comp->TxtMsg2) insert(items, TXTMSG2);
	if (TxtMsg3 == comp->TxtMsg3) insert(items, TXTMSG3);
	if (TxtMsg4 == comp->TxtMsg4) insert(items, TXTMSG4);
	if (TxtMsg5 == comp->TxtMsg5) insert(items, TXTMSG5);
	if (TxtMsg6 == comp->TxtMsg6) insert(items, TXTMSG6);
	if (TxtMsg7 == comp->TxtMsg7) insert(items, TXTMSG7);
	if (TxtMsg8 == comp->TxtMsg8) insert(items, TXTMSG8);
	if (TxtMsg9 == comp->TxtMsg9) insert(items, TXTMSG9);
	if (TxtMsg10 == comp->TxtMsg10) insert(items, TXTMSG10);
	if (TxtMsg11 == comp->TxtMsg11) insert(items, TXTMSG11);
	if (TxtMsg12 == comp->TxtMsg12) insert(items, TXTMSG12);

	return(items);
};

/******************************************************************************
 class DpchBrly
 ******************************************************************************/

DpchBrly::DpchBrly(
			const uint ixBrlyVDpch
		) {
	this->ixBrlyVDpch = ixBrlyVDpch;
};

DpchBrly::~DpchBrly() {
};

/******************************************************************************
 class DpchInvBrly
 ******************************************************************************/

DpchInvBrly::DpchInvBrly(
			const uint ixBrlyVDpch
			, const ubigint oref
			, const ubigint jref
			, const set<uint>& mask
		) : DpchBrly(ixBrlyVDpch) {
	this->oref = oref;
	this->jref = jref;

	if (find(mask, ALL)) this->mask = {OREF, JREF};
	else this->mask = mask;
};

DpchInvBrly::~DpchInvBrly() {
};

bool DpchInvBrly::all(
			const set<uint>& items
		) {
	if (!find(items, OREF)) return false;
	if (!find(items, JREF)) return false;

	return true;
};

void DpchInvBrly::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvBrly");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvBrly::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetBrly");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(OREF)) writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetBrly
 ******************************************************************************/

DpchRetBrly::DpchRetBrly(
			const uint ixBrlyVDpch
			, const string& scrOref
			, const string& scrJref
			, const bool success
			, const set<uint>& mask
		) : DpchBrly(ixBrlyVDpch) {
	this->scrOref = scrOref;
	this->scrJref = scrJref;
	this->success = success;

	if (find(mask, ALL)) this->mask = {SCROREF, SCRJREF, SUCCESS};
	else this->mask = mask;
};

DpchRetBrly::~DpchRetBrly() {
};

bool DpchRetBrly::all(
			const set<uint>& items
		) {
	if (!find(items, OREF)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SUCCESS)) return false;

	return true;
};

void DpchRetBrly::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetBrly");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
	};
};

void DpchRetBrly::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetBrly");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCROREF)) writeString(wr, "scrOref", scrOref);
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(SUCCESS)) writeBool(wr, "success", success);
	xmlTextWriterEndElement(wr);
};


