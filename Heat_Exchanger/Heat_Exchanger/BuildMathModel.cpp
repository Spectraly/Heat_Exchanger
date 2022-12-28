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
	auto heatexchangerAssembly = CreateHeatExchangerAssembly(params);
	model->AddItem(*heatexchangerAssembly);
	::DeleteItem(heatexchangerAssembly);
	return model;
}