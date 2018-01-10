/**
  * \file RootBrly.cpp
  * API code for job RootBrly (implementation)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifdef _WIN32
	#include "stdafx.h"
#endif

#include "RootBrly.h"

/******************************************************************************
 class RootBrly::DpchAppLogin
 ******************************************************************************/

RootBrly::DpchAppLogin::DpchAppLogin(
			const string& scrJref
			, const string& password
			, const string& username
			, const set<uint>& mask
		) : DpchAppBrly(VecBrlyVDpch::DPCHAPPROOTBRLYLOGIN, scrJref) {
	if (find(mask, ALL)) this->mask = {SCRJREF, PASSWORD, USERNAME};
	else this->mask = mask;

	this->password = password;
	this->username = username;
};

string RootBrly::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(USERNAME)) ss.push_back("username");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootBrly::DpchAppLogin::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppRootBrlyLogin");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/brly");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(PASSWORD)) writeString(wr, "password", password);
		if (has(USERNAME)) writeString(wr, "username", username);
	xmlTextWriterEndElement(wr);
};

