/**
  * \file RootBrly.h
  * API code for job RootBrly (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef ROOTBRLY_H
#define ROOTBRLY_H

#include "ApiBrly_blks.h"

#define DpchAppRootBrlyLogin RootBrly::DpchAppLogin

/**
  * RootBrly
  */
namespace RootBrly {
	/**
		* DpchAppLogin (full: DpchAppRootBrlyLogin)
		*/
	class DpchAppLogin : public DpchAppBrly {

	public:
		static const uint SCRJREF = 1;
		static const uint PASSWORD = 2;
		static const uint USERNAME = 3;
		static const uint ALL = 4;

	public:
		DpchAppLogin(const string& scrJref = "", const string& password = "", const string& username = "", const set<uint>& mask = {NONE});

	public:
		string password;
		string username;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

};

#endif

