#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

// Инициализирую статическую переменную класса - обязательно
int ParametricModelCreator::colorScheme = 0;



MbModel* ParametricModelCreator::CreateHeatExchangerModel(BuildParams params)
{
	MbModel* model = new MbModel();
	MbAssembly* heatexchangerAssembly;
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
