#pragma once
#define CASE_ITEMNAME std::uint32_t("Heat_Exchanger case")

#define HPG_MODEL 0
#define KP_MODEL  1
#define TU_MODEL  2
#include"qstring.h"


namespace BuildMathModel {
	struct BuildParams
	{
		int type = HPG_MODEL;
		QString pressure = "4.0";//HKT
		QString diam = "325.0";//HKT
		QString length = "3700.0";//HKT
		QString height = "600.0";//HKT
		QString A = "490.0";//HT
		QString A1 = "2330.0";//HT
		QString Dy = "100.0";//HKT
		QString Dy1 = "100.0";//HK
		QString Dy2 = "100.0";//K
		QString l = "3000.0";//HT
		QString l0 = "1500.0";//HT
		QString l1 = "235.0";//HKT
		QString l2 = "400.0";//HT
		QString l3 = "140.0";//HT //todo
		QString l4 = "140.0";//HT //todo
		QString S = "140.0";//HT //todo
		QString S1 = "140.0";//HT //todo
		QString h = "292.0";//HKT
		QString d = "20.0";//HKT

		QString ro = "1040.0";
		QString sig = "132.0";
		QString fi = "0.9";

		float TsS = 0;//HKT
		float TsE = 0;//HKT
		float TsF = 0;//HKT
	};
}