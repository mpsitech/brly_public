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
	const uint DPCHENGBRLYACK = 1;
	const uint DPCHENGBRLYALERT = 2;
	const uint DPCHENGBRLYCON1NRELAYDATA = 3;
	const uint DPCHENGBRLYCONCONMNEQUIPMENTDATA = 4;
	const uint DPCHENGBRLYCONDATA = 5;
	const uint DPCHENGBRLYCONDETAILDATA = 6;
	const uint DPCHENGBRLYCONFIRM = 7;
	const uint DPCHENGBRLYCONHEADBARDATA = 8;
	const uint DPCHENGBRLYCONLISTDATA = 9;
	const uint DPCHENGBRLYCONMAPDATA = 10;
	const uint DPCHENGBRLYCONMAPIMAGE = 11;
	const uint DPCHENGBRLYCONMNFLIGHTDATA = 12;
	const uint DPCHENGBRLYCONMNSEGMENTDATA = 13;
	const uint DPCHENGBRLYCONPREDATA = 14;
	const uint DPCHENGBRLYCONRECDATA = 15;
	const uint DPCHENGBRLYCONREF1NSEGMENTDATA = 16;
	const uint DPCHENGBRLYFILDATA = 17;
	const uint DPCHENGBRLYFILDETAILDATA = 18;
	const uint DPCHENGBRLYFILHEADBARDATA = 19;
	const uint DPCHENGBRLYFILLISTDATA = 20;
	const uint DPCHENGBRLYFILRECDATA = 21;
	const uint DPCHENGBRLYFLT1NCONNECTIONDATA = 22;
	const uint DPCHENGBRLYFLTDATA = 23;
	const uint DPCHENGBRLYFLTDETAILDATA = 24;
	const uint DPCHENGBRLYFLTEQP1NNODEDATA = 25;
	const uint DPCHENGBRLYFLTEQPMNCONNECTIONDATA = 26;
	const uint DPCHENGBRLYFLTFAFAWAYPOINTDATA = 27;
	const uint DPCHENGBRLYFLTHEADBARDATA = 28;
	const uint DPCHENGBRLYFLTLISTDATA = 29;
	const uint DPCHENGBRLYFLTMNCONNECTIONDATA = 30;
	const uint DPCHENGBRLYFLTMNLOCATIONDATA = 31;
	const uint DPCHENGBRLYFLTORGMNFLIGHTDATA = 32;
	const uint DPCHENGBRLYFLTPREDATA = 33;
	const uint DPCHENGBRLYFLTRECDATA = 34;
	const uint DPCHENGBRLYFLTREF1NSEGMENTDATA = 35;
	const uint DPCHENGBRLYLEG1NFLIGHTDATA = 36;
	const uint DPCHENGBRLYLEGCOR1NCONNECTIONDATA = 37;
	const uint DPCHENGBRLYLEGDATA = 38;
	const uint DPCHENGBRLYLEGDETAILDATA = 39;
	const uint DPCHENGBRLYLEGHEADBARDATA = 40;
	const uint DPCHENGBRLYLEGLISTDATA = 41;
	const uint DPCHENGBRLYLEGMAPDATA = 42;
	const uint DPCHENGBRLYLEGMAPIMAGE = 43;
	const uint DPCHENGBRLYLEGMNLOCATIONDATA = 44;
	const uint DPCHENGBRLYLEGORGMNLEGDATA = 45;
	const uint DPCHENGBRLYLEGPREDATA = 46;
	const uint DPCHENGBRLYLEGRECDATA = 47;
	const uint DPCHENGBRLYLOCBGN1NLEGDATA = 48;
	const uint DPCHENGBRLYLOCDATA = 49;
	const uint DPCHENGBRLYLOCDETAILDATA = 50;
	const uint DPCHENGBRLYLOCEND1NLEGDATA = 51;
	const uint DPCHENGBRLYLOCEQP1NNODEDATA = 52;
	const uint DPCHENGBRLYLOCEQPMNCONNECTIONDATA = 53;
	const uint DPCHENGBRLYLOCHEADBARDATA = 54;
	const uint DPCHENGBRLYLOCLISTDATA = 55;
	const uint DPCHENGBRLYLOCMAPDATA = 56;
	const uint DPCHENGBRLYLOCMAPIMAGE = 57;
	const uint DPCHENGBRLYLOCMNFLIGHTDATA = 58;
	const uint DPCHENGBRLYLOCMNLEGDATA = 59;
	const uint DPCHENGBRLYLOCMNSEGMENTDATA = 60;
	const uint DPCHENGBRLYLOCPROXORGMNLOCATIONDATA = 61;
	const uint DPCHENGBRLYLOCRECDATA = 62;
	const uint DPCHENGBRLYLOCVISORGMNLOCATIONDATA = 63;
	const uint DPCHENGBRLYNAVADMINDATA = 64;
	const uint DPCHENGBRLYNAVBASEDATA = 65;
	const uint DPCHENGBRLYNAVCONNECTDATA = 66;
	const uint DPCHENGBRLYNAVDATA = 67;
	const uint DPCHENGBRLYNAVHEADBARDATA = 68;
	const uint DPCHENGBRLYOPR1NEQUIPMENTDATA = 69;
	const uint DPCHENGBRLYOPRDATA = 70;
	const uint DPCHENGBRLYOPRDETAILDATA = 71;
	const uint DPCHENGBRLYOPRHEADBARDATA = 72;
	const uint DPCHENGBRLYOPRLISTDATA = 73;
	const uint DPCHENGBRLYOPRRECDATA = 74;
	const uint DPCHENGBRLYPRSADETAILDATA = 75;
	const uint DPCHENGBRLYPRSDATA = 76;
	const uint DPCHENGBRLYPRSDETAILDATA = 77;
	const uint DPCHENGBRLYPRSHEADBARDATA = 78;
	const uint DPCHENGBRLYPRSLISTDATA = 79;
	const uint DPCHENGBRLYPRSRECDATA = 80;
	const uint DPCHENGBRLYPTY1NEQUIPMENTDATA = 81;
	const uint DPCHENGBRLYPTYDATA = 82;
	const uint DPCHENGBRLYPTYDETAILDATA = 83;
	const uint DPCHENGBRLYPTYHEADBARDATA = 84;
	const uint DPCHENGBRLYPTYLISTDATA = 85;
	const uint DPCHENGBRLYPTYRECDATA = 86;
	const uint DPCHENGBRLYREG1NLOCATIONDATA = 87;
	const uint DPCHENGBRLYREGADSTSWITCHDATA = 88;
	const uint DPCHENGBRLYREGDATA = 89;
	const uint DPCHENGBRLYREGDETAILDATA = 90;
	const uint DPCHENGBRLYREGHEADBARDATA = 91;
	const uint DPCHENGBRLYREGLISTDATA = 92;
	const uint DPCHENGBRLYREGRECDATA = 93;
	const uint DPCHENGBRLYREGSUP1NREGIONDATA = 94;
	const uint DPCHENGBRLYRLY1NNODEDATA = 95;
	const uint DPCHENGBRLYRLYDATA = 96;
	const uint DPCHENGBRLYRLYDETAILDATA = 97;
	const uint DPCHENGBRLYRLYHEADBARDATA = 98;
	const uint DPCHENGBRLYRLYLISTDATA = 99;
	const uint DPCHENGBRLYRLYRECDATA = 100;
	const uint DPCHENGBRLYSEGDATA = 101;
	const uint DPCHENGBRLYSEGDETAILDATA = 102;
	const uint DPCHENGBRLYSEGHEADBARDATA = 103;
	const uint DPCHENGBRLYSEGLISTDATA = 104;
	const uint DPCHENGBRLYSEGMNCONNECTIONDATA = 105;
	const uint DPCHENGBRLYSEGMNLOCATIONDATA = 106;
	const uint DPCHENGBRLYSEGORGMNSEGMENTDATA = 107;
	const uint DPCHENGBRLYSEGPREDATA = 108;
	const uint DPCHENGBRLYSEGRECDATA = 109;
	const uint DPCHENGBRLYSUSPEND = 110;
	const uint DPCHENGBRLYTTB1NFLIGHTDATA = 111;
	const uint DPCHENGBRLYTTBDATA = 112;
	const uint DPCHENGBRLYTTBDETAILDATA = 113;
	const uint DPCHENGBRLYTTBHEADBARDATA = 114;
	const uint DPCHENGBRLYTTBLISTDATA = 115;
	const uint DPCHENGBRLYTTBRECDATA = 116;
	const uint DPCHENGBRLYTTBREF1NFILEDATA = 117;
	const uint DPCHENGBRLYUSGAACCESSDATA = 118;
	const uint DPCHENGBRLYUSGDATA = 119;
	const uint DPCHENGBRLYUSGDETAILDATA = 120;
	const uint DPCHENGBRLYUSGHEADBARDATA = 121;
	const uint DPCHENGBRLYUSGLISTDATA = 122;
	const uint DPCHENGBRLYUSGMNUSERDATA = 123;
	const uint DPCHENGBRLYUSGRECDATA = 124;
	const uint DPCHENGBRLYUSR1NSESSIONDATA = 125;
	const uint DPCHENGBRLYUSRAACCESSDATA = 126;
	const uint DPCHENGBRLYUSRDATA = 127;
	const uint DPCHENGBRLYUSRDETAILDATA = 128;
	const uint DPCHENGBRLYUSRHEADBARDATA = 129;
	const uint DPCHENGBRLYUSRLISTDATA = 130;
	const uint DPCHENGBRLYUSRMNUSERGROUPDATA = 131;
	const uint DPCHENGBRLYUSRRECDATA = 132;
	const uint DPCHENGDLGBRLYCONNEWDATA = 133;
	const uint DPCHENGDLGBRLYLEGNEWDATA = 134;
	const uint DPCHENGDLGBRLYNAVLOAINIDATA = 135;
	const uint DPCHENGDLGBRLYTTBIMPFLTDATA = 136;
	const uint DPCHENGDLGBRLYTTBNEWDATA = 137;
	const uint DPCHENGDLGBRLYTTBTRLORIGDATA = 138;
	const uint DPCHENGSESSBRLYDATA = 139;
	const uint DPCHAPPBRLYALERT = 140;
	const uint DPCHAPPBRLYCON1NRELAYDATA = 141;
	const uint DPCHAPPBRLYCON1NRELAYDO = 142;
	const uint DPCHAPPBRLYCONCONMNEQUIPMENTDATA = 143;
	const uint DPCHAPPBRLYCONCONMNEQUIPMENTDO = 144;
	const uint DPCHAPPBRLYCONDETAILDATA = 145;
	const uint DPCHAPPBRLYCONDETAILDO = 146;
	const uint DPCHAPPBRLYCONDO = 147;
	const uint DPCHAPPBRLYCONLISTDATA = 148;
	const uint DPCHAPPBRLYCONLISTDO = 149;
	const uint DPCHAPPBRLYCONMAPDATA = 150;
	const uint DPCHAPPBRLYCONMAPDO = 151;
	const uint DPCHAPPBRLYCONMNFLIGHTDATA = 152;
	const uint DPCHAPPBRLYCONMNFLIGHTDO = 153;
	const uint DPCHAPPBRLYCONMNSEGMENTDATA = 154;
	const uint DPCHAPPBRLYCONMNSEGMENTDO = 155;
	const uint DPCHAPPBRLYCONPREDATA = 156;
	const uint DPCHAPPBRLYCONRECDO = 157;
	const uint DPCHAPPBRLYCONREF1NSEGMENTDATA = 158;
	const uint DPCHAPPBRLYCONREF1NSEGMENTDO = 159;
	const uint DPCHAPPBRLYFILDETAILDATA = 160;
	const uint DPCHAPPBRLYFILDETAILDO = 161;
	const uint DPCHAPPBRLYFILDO = 162;
	const uint DPCHAPPBRLYFILLISTDATA = 163;
	const uint DPCHAPPBRLYFILLISTDO = 164;
	const uint DPCHAPPBRLYFILRECDO = 165;
	const uint DPCHAPPBRLYFLT1NCONNECTIONDATA = 166;
	const uint DPCHAPPBRLYFLT1NCONNECTIONDO = 167;
	const uint DPCHAPPBRLYFLTDETAILDATA = 168;
	const uint DPCHAPPBRLYFLTDETAILDO = 169;
	const uint DPCHAPPBRLYFLTDO = 170;
	const uint DPCHAPPBRLYFLTEQP1NNODEDATA = 171;
	const uint DPCHAPPBRLYFLTEQP1NNODEDO = 172;
	const uint DPCHAPPBRLYFLTEQPMNCONNECTIONDATA = 173;
	const uint DPCHAPPBRLYFLTEQPMNCONNECTIONDO = 174;
	const uint DPCHAPPBRLYFLTFAFAWAYPOINTDATA = 175;
	const uint DPCHAPPBRLYFLTFAFAWAYPOINTDO = 176;
	const uint DPCHAPPBRLYFLTLISTDATA = 177;
	const uint DPCHAPPBRLYFLTLISTDO = 178;
	const uint DPCHAPPBRLYFLTMNCONNECTIONDATA = 179;
	const uint DPCHAPPBRLYFLTMNCONNECTIONDO = 180;
	const uint DPCHAPPBRLYFLTMNLOCATIONDATA = 181;
	const uint DPCHAPPBRLYFLTMNLOCATIONDO = 182;
	const uint DPCHAPPBRLYFLTORGMNFLIGHTDATA = 183;
	const uint DPCHAPPBRLYFLTORGMNFLIGHTDO = 184;
	const uint DPCHAPPBRLYFLTPREDATA = 185;
	const uint DPCHAPPBRLYFLTRECDO = 186;
	const uint DPCHAPPBRLYFLTREF1NSEGMENTDATA = 187;
	const uint DPCHAPPBRLYFLTREF1NSEGMENTDO = 188;
	const uint DPCHAPPBRLYINIT = 189;
	const uint DPCHAPPBRLYLEG1NFLIGHTDATA = 190;
	const uint DPCHAPPBRLYLEG1NFLIGHTDO = 191;
	const uint DPCHAPPBRLYLEGCOR1NCONNECTIONDATA = 192;
	const uint DPCHAPPBRLYLEGCOR1NCONNECTIONDO = 193;
	const uint DPCHAPPBRLYLEGDETAILDATA = 194;
	const uint DPCHAPPBRLYLEGDETAILDO = 195;
	const uint DPCHAPPBRLYLEGDO = 196;
	const uint DPCHAPPBRLYLEGLISTDATA = 197;
	const uint DPCHAPPBRLYLEGLISTDO = 198;
	const uint DPCHAPPBRLYLEGMAPDATA = 199;
	const uint DPCHAPPBRLYLEGMAPDO = 200;
	const uint DPCHAPPBRLYLEGMNLOCATIONDATA = 201;
	const uint DPCHAPPBRLYLEGMNLOCATIONDO = 202;
	const uint DPCHAPPBRLYLEGORGMNLEGDATA = 203;
	const uint DPCHAPPBRLYLEGORGMNLEGDO = 204;
	const uint DPCHAPPBRLYLEGPREDATA = 205;
	const uint DPCHAPPBRLYLEGRECDO = 206;
	const uint DPCHAPPBRLYLOCBGN1NLEGDATA = 207;
	const uint DPCHAPPBRLYLOCBGN1NLEGDO = 208;
	const uint DPCHAPPBRLYLOCDETAILDATA = 209;
	const uint DPCHAPPBRLYLOCDETAILDO = 210;
	const uint DPCHAPPBRLYLOCDO = 211;
	const uint DPCHAPPBRLYLOCEND1NLEGDATA = 212;
	const uint DPCHAPPBRLYLOCEND1NLEGDO = 213;
	const uint DPCHAPPBRLYLOCEQP1NNODEDATA = 214;
	const uint DPCHAPPBRLYLOCEQP1NNODEDO = 215;
	const uint DPCHAPPBRLYLOCEQPMNCONNECTIONDATA = 216;
	const uint DPCHAPPBRLYLOCEQPMNCONNECTIONDO = 217;
	const uint DPCHAPPBRLYLOCLISTDATA = 218;
	const uint DPCHAPPBRLYLOCLISTDO = 219;
	const uint DPCHAPPBRLYLOCMAPDATA = 220;
	const uint DPCHAPPBRLYLOCMAPDO = 221;
	const uint DPCHAPPBRLYLOCMNFLIGHTDATA = 222;
	const uint DPCHAPPBRLYLOCMNFLIGHTDO = 223;
	const uint DPCHAPPBRLYLOCMNLEGDATA = 224;
	const uint DPCHAPPBRLYLOCMNLEGDO = 225;
	const uint DPCHAPPBRLYLOCMNSEGMENTDATA = 226;
	const uint DPCHAPPBRLYLOCMNSEGMENTDO = 227;
	const uint DPCHAPPBRLYLOCPROXORGMNLOCATIONDATA = 228;
	const uint DPCHAPPBRLYLOCPROXORGMNLOCATIONDO = 229;
	const uint DPCHAPPBRLYLOCRECDO = 230;
	const uint DPCHAPPBRLYLOCVISORGMNLOCATIONDATA = 231;
	const uint DPCHAPPBRLYLOCVISORGMNLOCATIONDO = 232;
	const uint DPCHAPPBRLYNAVADMINDATA = 233;
	const uint DPCHAPPBRLYNAVADMINDO = 234;
	const uint DPCHAPPBRLYNAVBASEDATA = 235;
	const uint DPCHAPPBRLYNAVBASEDO = 236;
	const uint DPCHAPPBRLYNAVCONNECTDATA = 237;
	const uint DPCHAPPBRLYNAVCONNECTDO = 238;
	const uint DPCHAPPBRLYNAVDO = 239;
	const uint DPCHAPPBRLYOPR1NEQUIPMENTDATA = 240;
	const uint DPCHAPPBRLYOPR1NEQUIPMENTDO = 241;
	const uint DPCHAPPBRLYOPRDETAILDATA = 242;
	const uint DPCHAPPBRLYOPRDETAILDO = 243;
	const uint DPCHAPPBRLYOPRDO = 244;
	const uint DPCHAPPBRLYOPRLISTDATA = 245;
	const uint DPCHAPPBRLYOPRLISTDO = 246;
	const uint DPCHAPPBRLYOPRRECDO = 247;
	const uint DPCHAPPBRLYPRSADETAILDATA = 248;
	const uint DPCHAPPBRLYPRSADETAILDO = 249;
	const uint DPCHAPPBRLYPRSDETAILDATA = 250;
	const uint DPCHAPPBRLYPRSDETAILDO = 251;
	const uint DPCHAPPBRLYPRSDO = 252;
	const uint DPCHAPPBRLYPRSLISTDATA = 253;
	const uint DPCHAPPBRLYPRSLISTDO = 254;
	const uint DPCHAPPBRLYPRSRECDO = 255;
	const uint DPCHAPPBRLYPTY1NEQUIPMENTDATA = 256;
	const uint DPCHAPPBRLYPTY1NEQUIPMENTDO = 257;
	const uint DPCHAPPBRLYPTYDETAILDATA = 258;
	const uint DPCHAPPBRLYPTYDETAILDO = 259;
	const uint DPCHAPPBRLYPTYDO = 260;
	const uint DPCHAPPBRLYPTYLISTDATA = 261;
	const uint DPCHAPPBRLYPTYLISTDO = 262;
	const uint DPCHAPPBRLYPTYRECDO = 263;
	const uint DPCHAPPBRLYREG1NLOCATIONDATA = 264;
	const uint DPCHAPPBRLYREG1NLOCATIONDO = 265;
	const uint DPCHAPPBRLYREGADSTSWITCHDATA = 266;
	const uint DPCHAPPBRLYREGADSTSWITCHDO = 267;
	const uint DPCHAPPBRLYREGDETAILDATA = 268;
	const uint DPCHAPPBRLYREGDETAILDO = 269;
	const uint DPCHAPPBRLYREGDO = 270;
	const uint DPCHAPPBRLYREGLISTDATA = 271;
	const uint DPCHAPPBRLYREGLISTDO = 272;
	const uint DPCHAPPBRLYREGRECDO = 273;
	const uint DPCHAPPBRLYREGSUP1NREGIONDATA = 274;
	const uint DPCHAPPBRLYREGSUP1NREGIONDO = 275;
	const uint DPCHAPPBRLYRESUME = 276;
	const uint DPCHAPPBRLYRLY1NNODEDATA = 277;
	const uint DPCHAPPBRLYRLY1NNODEDO = 278;
	const uint DPCHAPPBRLYRLYDETAILDATA = 279;
	const uint DPCHAPPBRLYRLYDETAILDO = 280;
	const uint DPCHAPPBRLYRLYDO = 281;
	const uint DPCHAPPBRLYRLYLISTDATA = 282;
	const uint DPCHAPPBRLYRLYLISTDO = 283;
	const uint DPCHAPPBRLYRLYRECDO = 284;
	const uint DPCHAPPBRLYSEGDETAILDATA = 285;
	const uint DPCHAPPBRLYSEGDETAILDO = 286;
	const uint DPCHAPPBRLYSEGDO = 287;
	const uint DPCHAPPBRLYSEGLISTDATA = 288;
	const uint DPCHAPPBRLYSEGLISTDO = 289;
	const uint DPCHAPPBRLYSEGMNCONNECTIONDATA = 290;
	const uint DPCHAPPBRLYSEGMNCONNECTIONDO = 291;
	const uint DPCHAPPBRLYSEGMNLOCATIONDATA = 292;
	const uint DPCHAPPBRLYSEGMNLOCATIONDO = 293;
	const uint DPCHAPPBRLYSEGORGMNSEGMENTDATA = 294;
	const uint DPCHAPPBRLYSEGORGMNSEGMENTDO = 295;
	const uint DPCHAPPBRLYSEGPREDATA = 296;
	const uint DPCHAPPBRLYSEGRECDO = 297;
	const uint DPCHAPPBRLYTTB1NFLIGHTDATA = 298;
	const uint DPCHAPPBRLYTTB1NFLIGHTDO = 299;
	const uint DPCHAPPBRLYTTBDETAILDATA = 300;
	const uint DPCHAPPBRLYTTBDETAILDO = 301;
	const uint DPCHAPPBRLYTTBDO = 302;
	const uint DPCHAPPBRLYTTBLISTDATA = 303;
	const uint DPCHAPPBRLYTTBLISTDO = 304;
	const uint DPCHAPPBRLYTTBRECDO = 305;
	const uint DPCHAPPBRLYTTBREF1NFILEDATA = 306;
	const uint DPCHAPPBRLYTTBREF1NFILEDO = 307;
	const uint DPCHAPPBRLYUSGAACCESSDATA = 308;
	const uint DPCHAPPBRLYUSGAACCESSDO = 309;
	const uint DPCHAPPBRLYUSGDETAILDATA = 310;
	const uint DPCHAPPBRLYUSGDETAILDO = 311;
	const uint DPCHAPPBRLYUSGDO = 312;
	const uint DPCHAPPBRLYUSGLISTDATA = 313;
	const uint DPCHAPPBRLYUSGLISTDO = 314;
	const uint DPCHAPPBRLYUSGMNUSERDATA = 315;
	const uint DPCHAPPBRLYUSGMNUSERDO = 316;
	const uint DPCHAPPBRLYUSGRECDO = 317;
	const uint DPCHAPPBRLYUSR1NSESSIONDATA = 318;
	const uint DPCHAPPBRLYUSR1NSESSIONDO = 319;
	const uint DPCHAPPBRLYUSRAACCESSDATA = 320;
	const uint DPCHAPPBRLYUSRAACCESSDO = 321;
	const uint DPCHAPPBRLYUSRDETAILDATA = 322;
	const uint DPCHAPPBRLYUSRDETAILDO = 323;
	const uint DPCHAPPBRLYUSRDO = 324;
	const uint DPCHAPPBRLYUSRLISTDATA = 325;
	const uint DPCHAPPBRLYUSRLISTDO = 326;
	const uint DPCHAPPBRLYUSRMNUSERGROUPDATA = 327;
	const uint DPCHAPPBRLYUSRMNUSERGROUPDO = 328;
	const uint DPCHAPPBRLYUSRRECDO = 329;
	const uint DPCHAPPDLGBRLYCONNEWDATA = 330;
	const uint DPCHAPPDLGBRLYCONNEWDO = 331;
	const uint DPCHAPPDLGBRLYLEGNEWDATA = 332;
	const uint DPCHAPPDLGBRLYLEGNEWDO = 333;
	const uint DPCHAPPDLGBRLYNAVLOAINIDATA = 334;
	const uint DPCHAPPDLGBRLYNAVLOAINIDO = 335;
	const uint DPCHAPPDLGBRLYTTBIMPFLTDATA = 336;
	const uint DPCHAPPDLGBRLYTTBIMPFLTDO = 337;
	const uint DPCHAPPDLGBRLYTTBNEWDATA = 338;
	const uint DPCHAPPDLGBRLYTTBNEWDO = 339;
	const uint DPCHAPPDLGBRLYTTBTRLORIGDATA = 340;
	const uint DPCHAPPDLGBRLYTTBTRLORIGDO = 341;
	const uint DPCHAPPROOTBRLYLOGIN = 342;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

