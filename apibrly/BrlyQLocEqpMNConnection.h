/**
  * \file BrlyQLocEqpMNConnection.h
  * API code for table TblBrlyQLocEqpMNConnection (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYQLOCEQPMNCONNECTION_H
#define BRLYQLOCEQPMNCONNECTION_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
  * BrlyQLocEqpMNConnection
  */
class BrlyQLocEqpMNConnection {

public:
	BrlyQLocEqpMNConnection(const uint jnum = 0, const string stubMref = "", const string srefConIxBrlyVLat = "");

public:
	uint jnum;
	string stubMref;
	string srefConIxBrlyVLat;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * ListBrlyQLocEqpMNConnection
  */
class ListBrlyQLocEqpMNConnection {

public:
	ListBrlyQLocEqpMNConnection();
	ListBrlyQLocEqpMNConnection(const ListBrlyQLocEqpMNConnection& src);
	ListBrlyQLocEqpMNConnection& operator=(const ListBrlyQLocEqpMNConnection& src);
	~ListBrlyQLocEqpMNConnection();

	void clear();

public:
	vector<BrlyQLocEqpMNConnection*> nodes;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

#endif

