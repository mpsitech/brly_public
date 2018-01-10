/**
  * \file VecBrlyVTag.h
  * vector VecBrlyVTag (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVTAG_H
#define VECBRLYVTAG_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVTag
	*/
namespace VecBrlyVTag {
	const uint ABOUT = 1;
	const uint ALWAYS = 2;
	const uint CANCEL = 3;
	const uint CLOSE = 4;
	const uint CLSESS = 5;
	const uint CLUST = 6;
	const uint CREATE = 7;
	const uint DETAIL = 8;
	const uint DONE = 9;
	const uint DOWNLOAD = 10;
	const uint EMPLONG = 11;
	const uint EMPSHORT = 12;
	const uint ERROR = 13;
	const uint FILENAME = 14;
	const uint FLS = 15;
	const uint FOR = 16;
	const uint GENERAL = 17;
	const uint GOTO = 18;
	const uint GRP = 19;
	const uint HELP = 20;
	const uint IMPORT = 21;
	const uint LOAINI = 22;
	const uint NAV = 23;
	const uint NEW = 24;
	const uint NO = 25;
	const uint OK = 26;
	const uint OPSCPLLAST = 27;
	const uint OPSPREP = 28;
	const uint OWN = 29;
	const uint PROGRESS = 30;
	const uint QUEST = 31;
	const uint RUN = 32;
	const uint SESS = 33;
	const uint SHOWLONG = 34;
	const uint SHOWSHORT = 35;
	const uint STOP = 36;
	const uint TRU = 37;
	const uint UPLOAD = 38;
	const uint YES = 39;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixBrlyVLocale);

	void appendToFeed(const uint ix, const uint ixBrlyVLocale, Feed& feed);
};

#endif

