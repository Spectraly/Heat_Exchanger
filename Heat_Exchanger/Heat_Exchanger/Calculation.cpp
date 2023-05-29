#include "BuildMathModel.h"

using namespace std;

float BuildMathModel::ParametricModelCreator::ShellCalculation(BuildParams params)
{
	int TsS;
	float C, Priz,g,Pgs,S;
	g = 9.8;
	C = 1;
	Pgs = params.ro.toDouble() * g * params.length.toDouble() /10000000000;
	Priz = 0.4 + Pgs;
	S = (Priz * params.diam.toDouble()) / (2 * params.sig.toDouble() * params.fi.toDouble() - params.pressure.toDouble());

	TsS = (S + C) * 10;

	return TsS;
}

float BuildMathModel::ParametricModelCreator::EllipticalBottomCalculation(BuildParams params)
{
	int TsE;
	float C, Rk, S,H,Piz;
	C = 1;
	Piz = 0.4;
	H = 0.25 * params.diam.toDouble();
	Rk = (params.diam.toDouble() * params.diam.toDouble()) / (4 * H);
	S = (Piz*Rk)/(2 * params.sig.toDouble() * params.fi.toDouble()-(0.5*Piz));

	TsE = (S + C) * 10;

	return TsE;
}

float BuildMathModel::ParametricModelCreator::FlatBottomCalculation(BuildParams params)
{
	int TsF;
	float K, K0, C, S,Piz;
	C = 1;
	K = 0.5;
	K0 = 1.1;
	Piz = 0.4;
	S = K * K0 * params.diam.toDouble() * sqrt(Piz/ params.sig.toDouble() * params.fi.toDouble());

	TsF = (S + C);
	return TsF;
}
