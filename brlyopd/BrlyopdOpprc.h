/**
  * \file BrlyopdOpprc.h
  * operation processor for Brly operation daemon brlyopd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef BRLYOPDOPPRC_H
#define BRLYOPDOPPRC_H

#include "BrlyBaseLegleg.h"
#include "BrlyBaseLegloc.h"
#include "BrlyBaseLocloc.h"
#include "BrlyDnsmapCollect.h"
#include "BrlyDnsmapFrame.h"
#include "BrlyDnsmapVideo.h"
#include "BrlyDynConflt.h"
#include "BrlyDynConseg.h"
#include "BrlyDynEqplist.h"
#include "BrlyDynFltfltloc.h"
#include "BrlyDynFltseg.h"
#include "BrlyDynRly.h"
#include "BrlyDynSeglocseg.h"
#include "BrlyMapgenConmap.h"
#include "BrlyMapgenLegmap.h"
#include "BrlyMapgenLocmap.h"
#include "BrlyTtimpRawstar.h"

/**
  * BrlyopdOpprc
  */
namespace BrlyopdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif

