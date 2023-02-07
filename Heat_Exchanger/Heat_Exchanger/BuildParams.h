#pragma once
#define CASE_ITEMNAME std::uint32_t("Heat_Exchanger case")

#define HPG_MODEL 0;



namespace BuildMathModel {
	struct BuildParams
	{
		int type = HPG_MODEL;
		double diam = 325.0;
		double pressure = 4.0;
	};
}