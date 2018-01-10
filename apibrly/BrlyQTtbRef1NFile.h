/**
  * \file BrlyQTtbRef1NFile.h
  * API code for table TblBrlyQTtbRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQTTBREF1NFILE_H
#define BRLYQTTBREF1NFILE_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQTtbRef1NFile
  */
class BrlyQTtbRef1NFile {

public:
	BrlyQTtbRef1NFile(const uint jnum = 0, const string stubRef = "");

public:
	uint jnum;
	string stubRef;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQTtbRef1NFile
  */
class ListBrlyQTtbRef1NFile {

public:
	ListBrlyQTtbRef1NFile();
	ListBrlyQTtbRef1NFile(const ListBrlyQTtbRef1NFile& src);
	ListBrlyQTtbRef1NFile& operator=(const ListBrlyQTtbRef1NFile& src);
	~ListBrlyQTtbRef1NFile();

	void clear();

public:
	vector<BrlyQTtbRef1NFile*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

