/**
  * \file VecBrlyVDpch.h
  * vector VecBrlyVDpch (declarations)
  * \author Alexander Wirthmueller
  * \date created: 8 Jan 2018
  * \date modified: 8 Jan 2018
  */

#ifndef VECBRLYVDPCH_H
#define VECBRLYVDPCH_H

#include <sbecore/Xmlio.h>

using namespace Xmlio;

/**
	* VecBrlyVDpch
	*/
namespace VecBrlyVDpch {
	const uint DPCHAPPBRLYALERT = 1;
	const uint DPCHAPPBRLYCON1NRELAYDATA = 2;
	const uint DPCHAPPBRLYCON1NRELAYDO = 3;
	const uint DPCHAPPBRLYCONCONMNEQUIPMENTDATA = 4;
	const uint DPCHAPPBRLYCONCONMNEQUIPMENTDO = 5;
	const uint DPCHAPPBRLYCONDETAILDATA = 6;
	const uint DPCHAPPBRLYCONDETAILDO = 7;
	const uint DPCHAPPBRLYCONDO = 8;
	const uint DPCHAPPBRLYCONLISTDATA = 9;
	const uint DPCHAPPBRLYCONLISTDO = 10;
	const uint DPCHAPPBRLYCONMAPDATA = 11;
	const uint DPCHAPPBRLYCONMAPDO = 12;
	const uint DPCHAPPBRLYCONMNFLIGHTDATA = 13;
	const uint DPCHAPPBRLYCONMNFLIGHTDO = 14;
	const uint DPCHAPPBRLYCONMNSEGMENTDATA = 15;
	const uint DPCHAPPBRLYCONMNSEGMENTDO = 16;
	const uint DPCHAPPBRLYCONPREDATA = 17;
	const uint DPCHAPPBRLYCONRECDO = 18;
	const uint DPCHAPPBRLYCONREF1NSEGMENTDATA = 19;
	const uint DPCHAPPBRLYCONREF1NSEGMENTDO = 20;
	const uint DPCHAPPBRLYFILDETAILDATA = 21;
	const uint DPCHAPPBRLYFILDETAILDO = 22;
	const uint DPCHAPPBRLYFILDO = 23;
	const uint DPCHAPPBRLYFILLISTDATA = 24;
	const uint DPCHAPPBRLYFILLISTDO = 25;
	const uint DPCHAPPBRLYFILRECDO = 26;
	const uint DPCHAPPBRLYFLT1NCONNECTIONDATA = 27;
	const uint DPCHAPPBRLYFLT1NCONNECTIONDO = 28;
	const uint DPCHAPPBRLYFLTDETAILDATA = 29;
	const uint DPCHAPPBRLYFLTDETAILDO = 30;
	const uint DPCHAPPBRLYFLTDO = 31;
	const uint DPCHAPPBRLYFLTEQP1NNODEDATA = 32;
	const uint DPCHAPPBRLYFLTEQP1NNODEDO = 33;
	const uint DPCHAPPBRLYFLTEQPMNCONNECTIONDATA = 34;
	const uint DPCHAPPBRLYFLTEQPMNCONNECTIONDO = 35;
	const uint DPCHAPPBRLYFLTFAFAWAYPOINTDATA = 36;
	const uint DPCHAPPBRLYFLTFAFAWAYPOINTDO = 37;
	const uint DPCHAPPBRLYFLTLISTDATA = 38;
	const uint DPCHAPPBRLYFLTLISTDO = 39;
	const uint DPCHAPPBRLYFLTMNCONNECTIONDATA = 40;
	const uint DPCHAPPBRLYFLTMNCONNECTIONDO = 41;
	const uint DPCHAPPBRLYFLTMNLOCATIONDATA = 42;
	const uint DPCHAPPBRLYFLTMNLOCATIONDO = 43;
	const uint DPCHAPPBRLYFLTORGMNFLIGHTDATA = 44;
	const uint DPCHAPPBRLYFLTORGMNFLIGHTDO = 45;
	const uint DPCHAPPBRLYFLTPREDATA = 46;
	const uint DPCHAPPBRLYFLTRECDO = 47;
	const uint DPCHAPPBRLYFLTREF1NSEGMENTDATA = 48;
	const uint DPCHAPPBRLYFLTREF1NSEGMENTDO = 49;
	const uint DPCHAPPBRLYINIT = 50;
	const uint DPCHAPPBRLYLEG1NFLIGHTDATA = 51;
	const uint DPCHAPPBRLYLEG1NFLIGHTDO = 52;
	const uint DPCHAPPBRLYLEGCOR1NCONNECTIONDATA = 53;
	const uint DPCHAPPBRLYLEGCOR1NCONNECTIONDO = 54;
	const uint DPCHAPPBRLYLEGDETAILDATA = 55;
	const uint DPCHAPPBRLYLEGDETAILDO = 56;
	const uint DPCHAPPBRLYLEGDO = 57;
	const uint DPCHAPPBRLYLEGLISTDATA = 58;
	const uint DPCHAPPBRLYLEGLISTDO = 59;
	const uint DPCHAPPBRLYLEGMAPDATA = 60;
	const uint DPCHAPPBRLYLEGMAPDO = 61;
	const uint DPCHAPPBRLYLEGMNLOCATIONDATA = 62;
	const uint DPCHAPPBRLYLEGMNLOCATIONDO = 63;
	const uint DPCHAPPBRLYLEGORGMNLEGDATA = 64;
	const uint DPCHAPPBRLYLEGORGMNLEGDO = 65;
	const uint DPCHAPPBRLYLEGPREDATA = 66;
	const uint DPCHAPPBRLYLEGRECDO = 67;
	const uint DPCHAPPBRLYLOCBGN1NLEGDATA = 68;
	const uint DPCHAPPBRLYLOCBGN1NLEGDO = 69;
	const uint DPCHAPPBRLYLOCDETAILDATA = 70;
	const uint DPCHAPPBRLYLOCDETAILDO = 71;
	const uint DPCHAPPBRLYLOCDO = 72;
	const uint DPCHAPPBRLYLOCEND1NLEGDATA = 73;
	const uint DPCHAPPBRLYLOCEND1NLEGDO = 74;
	const uint DPCHAPPBRLYLOCEQP1NNODEDATA = 75;
	const uint DPCHAPPBRLYLOCEQP1NNODEDO = 76;
	const uint DPCHAPPBRLYLOCEQPMNCONNECTIONDATA = 77;
	const uint DPCHAPPBRLYLOCEQPMNCONNECTIONDO = 78;
	const uint DPCHAPPBRLYLOCLISTDATA = 79;
	const uint DPCHAPPBRLYLOCLISTDO = 80;
	const uint DPCHAPPBRLYLOCMAPDATA = 81;
	const uint DPCHAPPBRLYLOCMAPDO = 82;
	const uint DPCHAPPBRLYLOCMNFLIGHTDATA = 83;
	const uint DPCHAPPBRLYLOCMNFLIGHTDO = 84;
	const uint DPCHAPPBRLYLOCMNLEGDATA = 85;
	const uint DPCHAPPBRLYLOCMNLEGDO = 86;
	const uint DPCHAPPBRLYLOCMNSEGMENTDATA = 87;
	const uint DPCHAPPBRLYLOCMNSEGMENTDO = 88;
	const uint DPCHAPPBRLYLOCPROXORGMNLOCATIONDATA = 89;
	const uint DPCHAPPBRLYLOCPROXORGMNLOCATIONDO = 90;
	const uint DPCHAPPBRLYLOCRECDO = 91;
	const uint DPCHAPPBRLYLOCVISORGMNLOCATIONDATA = 92;
	const uint DPCHAPPBRLYLOCVISORGMNLOCATIONDO = 93;
	const uint DPCHAPPBRLYNAVADMINDATA = 94;
	const uint DPCHAPPBRLYNAVADMINDO = 95;
	const uint DPCHAPPBRLYNAVBASEDATA = 96;
	const uint DPCHAPPBRLYNAVBASEDO = 97;
	const uint DPCHAPPBRLYNAVCONNECTDATA = 98;
	const uint DPCHAPPBRLYNAVCONNECTDO = 99;
	const uint DPCHAPPBRLYNAVDO = 100;
	const uint DPCHAPPBRLYOPR1NEQUIPMENTDATA = 101;
	const uint DPCHAPPBRLYOPR1NEQUIPMENTDO = 102;
	const uint DPCHAPPBRLYOPRDETAILDATA = 103;
	const uint DPCHAPPBRLYOPRDETAILDO = 104;
	const uint DPCHAPPBRLYOPRDO = 105;
	const uint DPCHAPPBRLYOPRLISTDATA = 106;
	const uint DPCHAPPBRLYOPRLISTDO = 107;
	const uint DPCHAPPBRLYOPRRECDO = 108;
	const uint DPCHAPPBRLYPRSADETAILDATA = 109;
	const uint DPCHAPPBRLYPRSADETAILDO = 110;
	const uint DPCHAPPBRLYPRSDETAILDATA = 111;
	const uint DPCHAPPBRLYPRSDETAILDO = 112;
	const uint DPCHAPPBRLYPRSDO = 113;
	const uint DPCHAPPBRLYPRSLISTDATA = 114;
	const uint DPCHAPPBRLYPRSLISTDO = 115;
	const uint DPCHAPPBRLYPRSRECDO = 116;
	const uint DPCHAPPBRLYPTY1NEQUIPMENTDATA = 117;
	const uint DPCHAPPBRLYPTY1NEQUIPMENTDO = 118;
	const uint DPCHAPPBRLYPTYDETAILDATA = 119;
	const uint DPCHAPPBRLYPTYDETAILDO = 120;
	const uint DPCHAPPBRLYPTYDO = 121;
	const uint DPCHAPPBRLYPTYLISTDATA = 122;
	const uint DPCHAPPBRLYPTYLISTDO = 123;
	const uint DPCHAPPBRLYPTYRECDO = 124;
	const uint DPCHAPPBRLYREG1NLOCATIONDATA = 125;
	const uint DPCHAPPBRLYREG1NLOCATIONDO = 126;
	const uint DPCHAPPBRLYREGADSTSWITCHDATA = 127;
	const uint DPCHAPPBRLYREGADSTSWITCHDO = 128;
	const uint DPCHAPPBRLYREGDETAILDATA = 129;
	const uint DPCHAPPBRLYREGDETAILDO = 130;
	const uint DPCHAPPBRLYREGDO = 131;
	const uint DPCHAPPBRLYREGLISTDATA = 132;
	const uint DPCHAPPBRLYREGLISTDO = 133;
	const uint DPCHAPPBRLYREGRECDO = 134;
	const uint DPCHAPPBRLYREGSUP1NREGIONDATA = 135;
	const uint DPCHAPPBRLYREGSUP1NREGIONDO = 136;
	const uint DPCHAPPBRLYRESUME = 137;
	const uint DPCHAPPBRLYRLY1NNODEDATA = 138;
	const uint DPCHAPPBRLYRLY1NNODEDO = 139;
	const uint DPCHAPPBRLYRLYDETAILDATA = 140;
	const uint DPCHAPPBRLYRLYDETAILDO = 141;
	const uint DPCHAPPBRLYRLYDO = 142;
	const uint DPCHAPPBRLYRLYLISTDATA = 143;
	const uint DPCHAPPBRLYRLYLISTDO = 144;
	const uint DPCHAPPBRLYRLYRECDO = 145;
	const uint DPCHAPPBRLYSEGDETAILDATA = 146;
	const uint DPCHAPPBRLYSEGDETAILDO = 147;
	const uint DPCHAPPBRLYSEGDO = 148;
	const uint DPCHAPPBRLYSEGLISTDATA = 149;
	const uint DPCHAPPBRLYSEGLISTDO = 150;
	const uint DPCHAPPBRLYSEGMNCONNECTIONDATA = 151;
	const uint DPCHAPPBRLYSEGMNCONNECTIONDO = 152;
	const uint DPCHAPPBRLYSEGMNLOCATIONDATA = 153;
	const uint DPCHAPPBRLYSEGMNLOCATIONDO = 154;
	const uint DPCHAPPBRLYSEGORGMNSEGMENTDATA = 155;
	const uint DPCHAPPBRLYSEGORGMNSEGMENTDO = 156;
	const uint DPCHAPPBRLYSEGPREDATA = 157;
	const uint DPCHAPPBRLYSEGRECDO = 158;
	const uint DPCHAPPBRLYTTB1NFLIGHTDATA = 159;
	const uint DPCHAPPBRLYTTB1NFLIGHTDO = 160;
	const uint DPCHAPPBRLYTTBDETAILDATA = 161;
	const uint DPCHAPPBRLYTTBDETAILDO = 162;
	const uint DPCHAPPBRLYTTBDO = 163;
	const uint DPCHAPPBRLYTTBLISTDATA = 164;
	const uint DPCHAPPBRLYTTBLISTDO = 165;
	const uint DPCHAPPBRLYTTBRECDO = 166;
	const uint DPCHAPPBRLYTTBREF1NFILEDATA = 167;
	const uint DPCHAPPBRLYTTBREF1NFILEDO = 168;
	const uint DPCHAPPBRLYUSGAACCESSDATA = 169;
	const uint DPCHAPPBRLYUSGAACCESSDO = 170;
	const uint DPCHAPPBRLYUSGDETAILDATA = 171;
	const uint DPCHAPPBRLYUSGDETAILDO = 172;
	const uint DPCHAPPBRLYUSGDO = 173;
	const uint DPCHAPPBRLYUSGLISTDATA = 174;
	const uint DPCHAPPBRLYUSGLISTDO = 175;
	const uint DPCHAPPBRLYUSGMNUSERDATA = 176;
	const uint DPCHAPPBRLYUSGMNUSERDO = 177;
	const uint DPCHAPPBRLYUSGRECDO = 178;
	const uint DPCHAPPBRLYUSR1NSESSIONDATA = 179;
	const uint DPCHAPPBRLYUSR1NSESSIONDO = 180;
	const uint DPCHAPPBRLYUSRAACCESSDATA = 181;
	const uint DPCHAPPBRLYUSRAACCESSDO = 182;
	const uint DPCHAPPBRLYUSRDETAILDATA = 183;
	const uint DPCHAPPBRLYUSRDETAILDO = 184;
	const uint DPCHAPPBRLYUSRDO = 185;
	const uint DPCHAPPBRLYUSRLISTDATA = 186;
	const uint DPCHAPPBRLYUSRLISTDO = 187;
	const uint DPCHAPPBRLYUSRMNUSERGROUPDATA = 188;
	const uint DPCHAPPBRLYUSRMNUSERGROUPDO = 189;
	const uint DPCHAPPBRLYUSRRECDO = 190;
	const uint DPCHAPPDLGBRLYCONNEWDATA = 191;
	const uint DPCHAPPDLGBRLYCONNEWDO = 192;
	const uint DPCHAPPDLGBRLYLEGNEWDATA = 193;
	const uint DPCHAPPDLGBRLYLEGNEWDO = 194;
	const uint DPCHAPPDLGBRLYNAVLOAINIDATA = 195;
	const uint DPCHAPPDLGBRLYNAVLOAINIDO = 196;
	const uint DPCHAPPDLGBRLYTTBIMPFLTDATA = 197;
	const uint DPCHAPPDLGBRLYTTBIMPFLTDO = 198;
	const uint DPCHAPPDLGBRLYTTBNEWDATA = 199;
	const uint DPCHAPPDLGBRLYTTBNEWDO = 200;
	const uint DPCHAPPDLGBRLYTTBTRLORIGDATA = 201;
	const uint DPCHAPPDLGBRLYTTBTRLORIGDO = 202;
	const uint DPCHAPPROOTBRLYLOGIN = 203;
	const uint DPCHBRLYDACK = 204;
	const uint DPCHBRLYDQUIT = 205;
	const uint DPCHBRLYDREG = 206;
	const uint DPCHBRLYOPDREG = 207;
	const uint DPCHBRLYOPDUNREG = 208;
	const uint DPCHENGBRLYACK = 209;
	const uint DPCHENGBRLYALERT = 210;
	const uint DPCHENGBRLYCON1NRELAYDATA = 211;
	const uint DPCHENGBRLYCONCONMNEQUIPMENTDATA = 212;
	const uint DPCHENGBRLYCONDATA = 213;
	const uint DPCHENGBRLYCONDETAILDATA = 214;
	const uint DPCHENGBRLYCONFIRM = 215;
	const uint DPCHENGBRLYCONHEADBARDATA = 216;
	const uint DPCHENGBRLYCONLISTDATA = 217;
	const uint DPCHENGBRLYCONMAPDATA = 218;
	const uint DPCHENGBRLYCONMAPIMAGE = 219;
	const uint DPCHENGBRLYCONMNFLIGHTDATA = 220;
	const uint DPCHENGBRLYCONMNSEGMENTDATA = 221;
	const uint DPCHENGBRLYCONPREDATA = 222;
	const uint DPCHENGBRLYCONRECDATA = 223;
	const uint DPCHENGBRLYCONREF1NSEGMENTDATA = 224;
	const uint DPCHENGBRLYFILDATA = 225;
	const uint DPCHENGBRLYFILDETAILDATA = 226;
	const uint DPCHENGBRLYFILHEADBARDATA = 227;
	const uint DPCHENGBRLYFILLISTDATA = 228;
	const uint DPCHENGBRLYFILRECDATA = 229;
	const uint DPCHENGBRLYFLT1NCONNECTIONDATA = 230;
	const uint DPCHENGBRLYFLTDATA = 231;
	const uint DPCHENGBRLYFLTDETAILDATA = 232;
	const uint DPCHENGBRLYFLTEQP1NNODEDATA = 233;
	const uint DPCHENGBRLYFLTEQPMNCONNECTIONDATA = 234;
	const uint DPCHENGBRLYFLTFAFAWAYPOINTDATA = 235;
	const uint DPCHENGBRLYFLTHEADBARDATA = 236;
	const uint DPCHENGBRLYFLTLISTDATA = 237;
	const uint DPCHENGBRLYFLTMNCONNECTIONDATA = 238;
	const uint DPCHENGBRLYFLTMNLOCATIONDATA = 239;
	const uint DPCHENGBRLYFLTORGMNFLIGHTDATA = 240;
	const uint DPCHENGBRLYFLTPREDATA = 241;
	const uint DPCHENGBRLYFLTRECDATA = 242;
	const uint DPCHENGBRLYFLTREF1NSEGMENTDATA = 243;
	const uint DPCHENGBRLYLEG1NFLIGHTDATA = 244;
	const uint DPCHENGBRLYLEGCOR1NCONNECTIONDATA = 245;
	const uint DPCHENGBRLYLEGDATA = 246;
	const uint DPCHENGBRLYLEGDETAILDATA = 247;
	const uint DPCHENGBRLYLEGHEADBARDATA = 248;
	const uint DPCHENGBRLYLEGLISTDATA = 249;
	const uint DPCHENGBRLYLEGMAPDATA = 250;
	const uint DPCHENGBRLYLEGMAPIMAGE = 251;
	const uint DPCHENGBRLYLEGMNLOCATIONDATA = 252;
	const uint DPCHENGBRLYLEGORGMNLEGDATA = 253;
	const uint DPCHENGBRLYLEGPREDATA = 254;
	const uint DPCHENGBRLYLEGRECDATA = 255;
	const uint DPCHENGBRLYLOCBGN1NLEGDATA = 256;
	const uint DPCHENGBRLYLOCDATA = 257;
	const uint DPCHENGBRLYLOCDETAILDATA = 258;
	const uint DPCHENGBRLYLOCEND1NLEGDATA = 259;
	const uint DPCHENGBRLYLOCEQP1NNODEDATA = 260;
	const uint DPCHENGBRLYLOCEQPMNCONNECTIONDATA = 261;
	const uint DPCHENGBRLYLOCHEADBARDATA = 262;
	const uint DPCHENGBRLYLOCLISTDATA = 263;
	const uint DPCHENGBRLYLOCMAPDATA = 264;
	const uint DPCHENGBRLYLOCMAPIMAGE = 265;
	const uint DPCHENGBRLYLOCMNFLIGHTDATA = 266;
	const uint DPCHENGBRLYLOCMNLEGDATA = 267;
	const uint DPCHENGBRLYLOCMNSEGMENTDATA = 268;
	const uint DPCHENGBRLYLOCPROXORGMNLOCATIONDATA = 269;
	const uint DPCHENGBRLYLOCRECDATA = 270;
	const uint DPCHENGBRLYLOCVISORGMNLOCATIONDATA = 271;
	const uint DPCHENGBRLYNAVADMINDATA = 272;
	const uint DPCHENGBRLYNAVBASEDATA = 273;
	const uint DPCHENGBRLYNAVCONNECTDATA = 274;
	const uint DPCHENGBRLYNAVDATA = 275;
	const uint DPCHENGBRLYNAVHEADBARDATA = 276;
	const uint DPCHENGBRLYOPR1NEQUIPMENTDATA = 277;
	const uint DPCHENGBRLYOPRDATA = 278;
	const uint DPCHENGBRLYOPRDETAILDATA = 279;
	const uint DPCHENGBRLYOPRHEADBARDATA = 280;
	const uint DPCHENGBRLYOPRLISTDATA = 281;
	const uint DPCHENGBRLYOPRRECDATA = 282;
	const uint DPCHENGBRLYPRSADETAILDATA = 283;
	const uint DPCHENGBRLYPRSDATA = 284;
	const uint DPCHENGBRLYPRSDETAILDATA = 285;
	const uint DPCHENGBRLYPRSHEADBARDATA = 286;
	const uint DPCHENGBRLYPRSLISTDATA = 287;
	const uint DPCHENGBRLYPRSRECDATA = 288;
	const uint DPCHENGBRLYPTY1NEQUIPMENTDATA = 289;
	const uint DPCHENGBRLYPTYDATA = 290;
	const uint DPCHENGBRLYPTYDETAILDATA = 291;
	const uint DPCHENGBRLYPTYHEADBARDATA = 292;
	const uint DPCHENGBRLYPTYLISTDATA = 293;
	const uint DPCHENGBRLYPTYRECDATA = 294;
	const uint DPCHENGBRLYREG1NLOCATIONDATA = 295;
	const uint DPCHENGBRLYREGADSTSWITCHDATA = 296;
	const uint DPCHENGBRLYREGDATA = 297;
	const uint DPCHENGBRLYREGDETAILDATA = 298;
	const uint DPCHENGBRLYREGHEADBARDATA = 299;
	const uint DPCHENGBRLYREGLISTDATA = 300;
	const uint DPCHENGBRLYREGRECDATA = 301;
	const uint DPCHENGBRLYREGSUP1NREGIONDATA = 302;
	const uint DPCHENGBRLYRLY1NNODEDATA = 303;
	const uint DPCHENGBRLYRLYDATA = 304;
	const uint DPCHENGBRLYRLYDETAILDATA = 305;
	const uint DPCHENGBRLYRLYHEADBARDATA = 306;
	const uint DPCHENGBRLYRLYLISTDATA = 307;
	const uint DPCHENGBRLYRLYRECDATA = 308;
	const uint DPCHENGBRLYSEGDATA = 309;
	const uint DPCHENGBRLYSEGDETAILDATA = 310;
	const uint DPCHENGBRLYSEGHEADBARDATA = 311;
	const uint DPCHENGBRLYSEGLISTDATA = 312;
	const uint DPCHENGBRLYSEGMNCONNECTIONDATA = 313;
	const uint DPCHENGBRLYSEGMNLOCATIONDATA = 314;
	const uint DPCHENGBRLYSEGORGMNSEGMENTDATA = 315;
	const uint DPCHENGBRLYSEGPREDATA = 316;
	const uint DPCHENGBRLYSEGRECDATA = 317;
	const uint DPCHENGBRLYSUSPEND = 318;
	const uint DPCHENGBRLYTTB1NFLIGHTDATA = 319;
	const uint DPCHENGBRLYTTBDATA = 320;
	const uint DPCHENGBRLYTTBDETAILDATA = 321;
	const uint DPCHENGBRLYTTBHEADBARDATA = 322;
	const uint DPCHENGBRLYTTBLISTDATA = 323;
	const uint DPCHENGBRLYTTBRECDATA = 324;
	const uint DPCHENGBRLYTTBREF1NFILEDATA = 325;
	const uint DPCHENGBRLYUSGAACCESSDATA = 326;
	const uint DPCHENGBRLYUSGDATA = 327;
	const uint DPCHENGBRLYUSGDETAILDATA = 328;
	const uint DPCHENGBRLYUSGHEADBARDATA = 329;
	const uint DPCHENGBRLYUSGLISTDATA = 330;
	const uint DPCHENGBRLYUSGMNUSERDATA = 331;
	const uint DPCHENGBRLYUSGRECDATA = 332;
	const uint DPCHENGBRLYUSR1NSESSIONDATA = 333;
	const uint DPCHENGBRLYUSRAACCESSDATA = 334;
	const uint DPCHENGBRLYUSRDATA = 335;
	const uint DPCHENGBRLYUSRDETAILDATA = 336;
	const uint DPCHENGBRLYUSRHEADBARDATA = 337;
	const uint DPCHENGBRLYUSRLISTDATA = 338;
	const uint DPCHENGBRLYUSRMNUSERGROUPDATA = 339;
	const uint DPCHENGBRLYUSRRECDATA = 340;
	const uint DPCHENGDLGBRLYCONNEWDATA = 341;
	const uint DPCHENGDLGBRLYLEGNEWDATA = 342;
	const uint DPCHENGDLGBRLYNAVLOAINIDATA = 343;
	const uint DPCHENGDLGBRLYTTBIMPFLTDATA = 344;
	const uint DPCHENGDLGBRLYTTBNEWDATA = 345;
	const uint DPCHENGDLGBRLYTTBTRLORIGDATA = 346;
	const uint DPCHENGSESSBRLYDATA = 347;
	const uint DPCHINVBRLY = 348;
	const uint DPCHINVBRLYBASELEGLEG = 349;
	const uint DPCHINVBRLYBASELEGLOC = 350;
	const uint DPCHINVBRLYBASELOCLOC = 351;
	const uint DPCHINVBRLYDNSMAPCOLLECT = 352;
	const uint DPCHINVBRLYDNSMAPFRAME = 353;
	const uint DPCHINVBRLYDNSMAPVIDEO = 354;
	const uint DPCHINVBRLYDYNCONFLT = 355;
	const uint DPCHINVBRLYDYNCONSEG = 356;
	const uint DPCHINVBRLYDYNEQPLIST = 357;
	const uint DPCHINVBRLYDYNFLTFLTLOC = 358;
	const uint DPCHINVBRLYDYNFLTSEG = 359;
	const uint DPCHINVBRLYDYNRLY = 360;
	const uint DPCHINVBRLYDYNSEGLOCSEG = 361;
	const uint DPCHINVBRLYMAPGENCONMAP = 362;
	const uint DPCHINVBRLYMAPGENLEGMAP = 363;
	const uint DPCHINVBRLYMAPGENLOCMAP = 364;
	const uint DPCHINVBRLYTTIMPRAWSTAR = 365;
	const uint DPCHRETBRLY = 366;
	const uint DPCHRETBRLYDNSMAPCOLLECT = 367;
	const uint DPCHRETBRLYDNSMAPFRAME = 368;
	const uint DPCHRETBRLYDNSMAPVIDEO = 369;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif
