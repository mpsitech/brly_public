/**
  * \file BrlyQSegMNConnection.h
  * API code for table TblBrlyQSegMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQSEGMNCONNECTION_H
#define BRLYQSEGMNCONNECTION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQSegMNConnection
  */
class BrlyQSegMNConnection {

public:
	BrlyQSegMNConnection(const uint jnum = 0, const string stubMref = "", const string ftmX1Start = "", const string ftmX1Stop = "", const double x2Legphi0 = 0.0, const double x2Legphi1 = 0.0);

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
  * ListBrlyQSegMNConnection
  */
class ListBrlyQSegMNConnection {

public:
	ListBrlyQSegMNConnection();
	ListBrlyQSegMNConnection(const ListBrlyQSegMNConnection& src);
	ListBrlyQSegMNConnection& operator=(const ListBrlyQSegMNConnection& src);
	~ListBrlyQSegMNConnection();

	void clear();

public:
	vector<BrlyQSegMNConnection*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

