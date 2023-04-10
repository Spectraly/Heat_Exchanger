#pragma once
#define CASE_ITEMNAME std::uint32_t("Heat_Exchanger case")

#define HPG_MODEL 0;
#include"qstring.h"


namespace BuildMathModel {
	struct BuildParams
	{
		int type = HPG_MODEL;
		QString pressure = "4.0";
		QString diam = "325.0";
		QString length = "2775.0";
		QString height = "600.0";
		QString A = "2330.0";
		QString Dy = "100.0";
		QString Dy1 = "100.0";
	};
}