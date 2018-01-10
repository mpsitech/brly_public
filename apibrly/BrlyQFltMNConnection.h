/**
  * \file BrlyQFltMNConnection.h
  * API code for table TblBrlyQFltMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTMNCONNECTION_H
#define BRLYQFLTMNCONNECTION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltMNConnection
  */
class BrlyQFltMNConnection {

public:
	BrlyQFltMNConnection(const uint jnum = 0, const string stubMref = "", const string ftmX1Start = "", const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

public:
	uint jnum;
	string stubMref;
	string ftmX1Start;
	string ftmX1Stop;
	double x2Legphi0;
	double x2Legphi1;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFltMNConnection
  */
class ListBrlyQFltMNConnection {

public:
	ListBrlyQFltMNConnection();
	ListBrlyQFltMNConnection(const ListBrlyQFltMNConnection& src);
	ListBrlyQFltMNConnection& operator=(const ListBrlyQFltMNConnection& src);
	~ListBrlyQFltMNConnection();

	void clear();

public:
	vector<BrlyQFltMNConnection*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

