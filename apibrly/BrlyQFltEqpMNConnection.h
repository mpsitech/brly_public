/**
  * \file BrlyQFltEqpMNConnection.h
  * API code for table TblBrlyQFltEqpMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQFLTEQPMNCONNECTION_H
#define BRLYQFLTEQPMNCONNECTION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQFltEqpMNConnection
  */
class BrlyQFltEqpMNConnection {

public:
	BrlyQFltEqpMNConnection(const uint jnum = 0, const string stubMref = "", const string srefConIxBrlyVLat = "");

public:
	uint jnum;
	string stubMref;
	string srefConIxBrlyVLat;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQFltEqpMNConnection
  */
class ListBrlyQFltEqpMNConnection {

public:
	ListBrlyQFltEqpMNConnection();
	ListBrlyQFltEqpMNConnection(const ListBrlyQFltEqpMNConnection& src);
	ListBrlyQFltEqpMNConnection& operator=(const ListBrlyQFltEqpMNConnection& src);
	~ListBrlyQFltEqpMNConnection();

	void clear();

public:
	vector<BrlyQFltEqpMNConnection*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

