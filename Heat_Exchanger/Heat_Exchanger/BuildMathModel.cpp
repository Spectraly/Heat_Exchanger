#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;

// ������������� ����������� ���������� ������ - �����������
int ParametricModelCreator::colorScheme = 0;

MbModel* ParametricModelCreator::CreateHeatExchangerModel(BuildParams params)
{
	//ParametricModelCreator::colorScheme = params.colorScheme;
	MbModel* model = new MbModel();
	MbAssembly* heatexchangerAssembly;
	switch (params.type)
	{
	 case 0:
		 heatexchangerAssembly = CreateHeatExchangerHPGAssembly(params);
		break;

	 case 1:
		 heatexchangerAssembly = CreateHeatExchangerKPAssembly(params);
		break;

	 case 2:
		 heatexchangerAssembly = CreateHeatExchangerTUAssembly(params);
		break;
	}

	model->AddItem(*heatexchangerAssembly);
	::DeleteItem(heatexchangerAssembly);
	return model;
}