#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;




MbModel* ParametricModelCreator::CreateHeatExchangerModel(BuildParams params)
{
	MbModel* model = new MbModel();
	MbAssembly* heatexchangerAssembly;

	float TsS, TsE, TsF;
	TsS = ShellCalculation(params);
	TsE = EllipticalBottomCalculation(params);
	TsF = FlatBottomCalculation(params);

	params.TsS = TsS;
	params.TsE = TsE;
	params.TsF = TsF;

	switch (params.type)
	{
	 case HPG_MODEL:
		 heatexchangerAssembly = CreateHeatExchangerHPGAssembly(params);
		break;
	 case KP_MODEL:
		 heatexchangerAssembly = CreateHeatExchangerKPAssembly(params);
		break;
	 case TU_MODEL:
		 heatexchangerAssembly = CreateHeatExchangerTUAssembly(params);
		break;
	}

	model->AddItem(*heatexchangerAssembly);
	::DeleteItem(heatexchangerAssembly);
	return model;
}
