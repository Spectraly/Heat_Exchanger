#include "ParamsWidget.h"


int ParamsWidget::checkPreassure(QString pres)
{
	if (pres == "1,0")
		return 0;
	if (pres == "1,6")
		return 1;
	if (pres == "2,5")
		return 2;
	if (pres == "4,0")
		return 3;
	if (pres == "6,3")
		return 4;
}

void ParamsWidget::gostDiam325(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 3:
			modelParams.diam = "325";
			modelParams.length = "3700";
			modelParams.height = "600";
			modelParams.A = "490";
			modelParams.A1 = "2330";
			modelParams.Dy = "100";
			modelParams.Dy1 = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "235";
			modelParams.l2 = "400";
			modelParams.h = "292";
			break;
		case 4:
			modelParams.diam = "325";
			modelParams.length = "3720";
			modelParams.height = "784";
			modelParams.A = "500";
			modelParams.A1 = "2170";
			modelParams.Dy = "100";
			modelParams.Dy1 = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "235";
			modelParams.l2 = "350";
			modelParams.h = "292";
			break;
		default:
			break;
		}

	}
	else
	{
		switch (preasure)
		{
		case 2:
			modelParams.diam = "325";
			modelParams.length = "3800";
			modelParams.height = "600";
			modelParams.A = "450";
			modelParams.A1 = "2500";
			modelParams.Dy = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "230";
			modelParams.l2 = "400";
			modelParams.h = "292";
			break;
		case 3:
			modelParams.diam = "325";
			modelParams.length = "3800";
			modelParams.height = "600";
			modelParams.A = "490";
			modelParams.A1 = "2460";
			modelParams.Dy = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "230";
			modelParams.l2 = "400";
			modelParams.h = "292";
			break;
		default:
			break;
		}
	}
	
}

void ParamsWidget::gostDiam400(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 3:
			modelParams.diam = "400";
			modelParams.length = "3730";
			modelParams.height = "714";
			modelParams.A = "500";
			modelParams.A1 = "2250";
			modelParams.Dy = "100";
			modelParams.Dy1 = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "250";
			modelParams.l2 = "400";
			modelParams.h = "352";
			break;
		case 4:
			modelParams.diam = "400";
			modelParams.length = "3760";
			modelParams.height = "810";
			modelParams.A = "550";
			modelParams.A1 = "2150";
			modelParams.Dy = "100";
			modelParams.Dy1 = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "250";
			modelParams.l2 = "400";
			modelParams.h = "352";
			break;
		default:
			break;
		}

	}
	else if(type == TU_MODEL)
	{
		switch (preasure)
		{
		case 2:
			modelParams.diam = "400";
			modelParams.length = "3940";
			modelParams.height = "714";
			modelParams.A = "500";
			modelParams.A1 = "2500";
			modelParams.Dy = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "270";
			modelParams.l2 = "400";
			modelParams.h = "352";
			break;
		case 3:
			modelParams.diam = "400";
			modelParams.length = "4120";
			modelParams.height = "714";
			modelParams.A = "500";
			modelParams.A1 = "2500";
			modelParams.Dy = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "270";
			modelParams.l2 = "400";
			modelParams.h = "352";
			break;
		case 4:
			modelParams.diam = "400";
			modelParams.length = "4010";
			modelParams.height = "810";
			modelParams.A = "550";
			modelParams.A1 = "2460";
			modelParams.Dy = "100";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "280";
			modelParams.l2 = "400";
			modelParams.h = "352";
			break;
		default:
			break;
		}
	}

}

void ParamsWidget::gostDiam500(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 3:
			modelParams.diam = "500";
			modelParams.length = "3930";
			modelParams.height = "954";
			modelParams.A = "550";
			modelParams.A1 = "2200";
			modelParams.Dy = "150";
			modelParams.Dy1 = "150";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "310";
			modelParams.l2 = "400";
			modelParams.h = "472";
			break;
		case 4:
			modelParams.diam = "500";
			modelParams.length = "3980";
			modelParams.height = "954";
			modelParams.A = "650";
			modelParams.A1 = "2060";
			modelParams.Dy = "150";
			modelParams.Dy1 = "150";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "310";
			modelParams.l2 = "350";
			modelParams.h = "472";
			break;
		default:
			break;
		}

	}
	else if (type == TU_MODEL)
	{
		switch (preasure)
		{
		case 2:
			modelParams.diam = "500";
			modelParams.length = "4070";
			modelParams.height = "954";
			modelParams.A = "550";
			modelParams.A1 = "2500";
			modelParams.Dy = "150";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "325";
			modelParams.l2 = "400";
			modelParams.h = "472";
			break;
		case 3:
			modelParams.diam = "500";
			modelParams.length = "4095";
			modelParams.height = "954";
			modelParams.A = "550";
			modelParams.A1 = "2500";
			modelParams.Dy = "150";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "325";
			modelParams.l2 = "400";
			modelParams.h = "472";
			break;
		case 4:
			modelParams.diam = "500";
			modelParams.length = "4170";
			modelParams.height = "954";
			modelParams.A = "650";
			modelParams.A1 = "2460";
			modelParams.Dy = "150";
			modelParams.l = "3000";
			modelParams.l0 = "1500";
			modelParams.l1 = "345";
			modelParams.l2 = "400";
			modelParams.h = "472";
			break;
		default:
			break;
		}
	}

}

void ParamsWidget::gostDiam600(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 2:
			modelParams.diam = "600";
			modelParams.length = "6930";
			modelParams.height = "1060";
			modelParams.A = "600";
			modelParams.A1 = "5100";
			modelParams.Dy = "200";
			modelParams.Dy1 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "310";
			modelParams.l2 = "1100";
			modelParams.h = "525";
			break;
		case 3:
			modelParams.diam = "600";
			modelParams.length = "7070";
			modelParams.height = "1060";
			modelParams.A = "640";
			modelParams.A1 = "5060";
			modelParams.Dy = "200";
			modelParams.Dy1 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "310";
			modelParams.l2 = "1100";
			modelParams.h = "525";
			break;
		case 4:
			modelParams.diam = "600";
			modelParams.length = "7160";
			modelParams.height = "1106";
			modelParams.A = "770";
			modelParams.A1 = "4760";
			modelParams.Dy = "200";
			modelParams.Dy1 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "340";
			modelParams.l2 = "900";
			modelParams.h = "532";
			break;
		default:
			break;
		}

	}
	else if (type == KP_MODEL)
	{
		switch (preasure)
		{
		case 0:
			modelParams.diam = "600";
			modelParams.length = "6800";
			modelParams.height = "1060";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "200";
			modelParams.Dy1 = "300";
			modelParams.Dy2 = "100";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "290";
			modelParams.l2 = "650";
			modelParams.h = "525";
			break;
		case 1:
			modelParams.diam = "600";
			modelParams.length = "6800";
			modelParams.height = "1060";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "200";
			modelParams.Dy1 = "250";
			modelParams.Dy2 = "100";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "290";
			modelParams.l2 = "650";
			modelParams.h = "525";
			break;
		case 2:
			modelParams.diam = "600";
			modelParams.length = "6850";
			modelParams.height = "1060";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "200";
			modelParams.Dy1 = "200";
			modelParams.Dy2 = "100";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "310";
			modelParams.l2 = "650";
			modelParams.h = "525";
			break;
		default:
			break;
		}
	}
	else if (type == TU_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "600";
			modelParams.length = "7200";
			modelParams.height = "1060";
			modelParams.A = "600";
			modelParams.A1 = "5400";
			modelParams.Dy = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "370";
			modelParams.l2 = "1100";
			modelParams.h = "525";
			break;
		case 2:
			modelParams.diam = "600";
			modelParams.length = "7240";
			modelParams.height = "1060";
			modelParams.A = "600";
			modelParams.A1 = "5400";
			modelParams.Dy = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "400";
			modelParams.l2 = "1100";
			modelParams.h = "525";
			break;
		case 3:
			modelParams.diam = "600";
			modelParams.length = "7260";
			modelParams.height = "1060";
			modelParams.A = "640";
			modelParams.A1 = "5360";
			modelParams.Dy = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "400";
			modelParams.l2 = "1100";
			modelParams.h = "525";
			break;
		case 4:
			modelParams.diam = "600";
			modelParams.length = "7370";
			modelParams.height = "1106";
			modelParams.A = "770";
			modelParams.A1 = "5360";
			modelParams.Dy = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "440";
			modelParams.l2 = "900";
			modelParams.h = "532";
			break;
		default:
			break;
		}
	}
}

void ParamsWidget::gostDiam700(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 2:
			modelParams.diam = "700";
			modelParams.length = "7060";
			modelParams.height = "1196";
			modelParams.A = "640";
			modelParams.A1 = "5100";
			modelParams.Dy = "200";
			modelParams.Dy1 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "310";
			modelParams.l2 = "1000";
			modelParams.h = "562";
			break;
		case 3:
			modelParams.diam = "700";
			modelParams.length = "7190";
			modelParams.height = "1262";
			modelParams.A = "720";
			modelParams.A1 = "5000";
			modelParams.Dy = "200";
			modelParams.Dy1 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "340";
			modelParams.l2 = "1000";
			modelParams.h = "568";
			break;
		case 4:
			modelParams.diam = "700";
			modelParams.length = "7350";
			modelParams.height = "1324";
			modelParams.A = "850";
			modelParams.A1 = "4750";
			modelParams.Dy = "200";
			modelParams.Dy1 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "380";
			modelParams.l2 = "850";
			modelParams.h = "576";
			break;
		default:
			break;
		}

	}
	else if (type == KP_MODEL)
	{
		switch (preasure)
		{
		case 0:
			modelParams.diam = "700";
			modelParams.length = "6930";
			modelParams.height = "1156";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "200";
			modelParams.Dy1 = "350";
			modelParams.Dy2 = "100";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "320";
			modelParams.l2 = "650";
			modelParams.h = "562";
			break;
		case 1:
			modelParams.diam = "700";
			modelParams.length = "6930";
			modelParams.height = "1156";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "200";
			modelParams.Dy1 = "250";
			modelParams.Dy2 = "100";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "320";
			modelParams.l2 = "650";
			modelParams.h = "562";
			break;
		case 2:
			modelParams.diam = "700";
			modelParams.length = "7000";
			modelParams.height = "1198";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "200";
			modelParams.Dy1 = "200";
			modelParams.Dy2 = "100";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "340";
			modelParams.l2 = "650";
			modelParams.h = "562";
			break;
		default:
			break;
		}
	}
	else if (type == TU_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "700";
			modelParams.length = "7260";
			modelParams.height = "1156";
			modelParams.A = "600";
			modelParams.A1 = "5400";
			modelParams.Dy = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "410";
			modelParams.l2 = "1100";
			modelParams.h = "562";
			break;
		case 2:
			modelParams.diam = "700";
			modelParams.length = "7300";
			modelParams.height = "1198";
			modelParams.A = "640";
			modelParams.A1 = "5400";
			modelParams.Dy = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "430";
			modelParams.l2 = "1000";
			modelParams.h = "562";
			break;
		case 3:
			modelParams.diam = "700";
			modelParams.length = "7320";
			modelParams.height = "1262";
			modelParams.A = "720";
			modelParams.A1 = "5360";
			modelParams.Dy = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "460";
			modelParams.l2 = "1000";
			modelParams.h = "568";
			break;
		case 4:
			modelParams.diam = "700";
			modelParams.length = "7450";
			modelParams.height = "1324";
			modelParams.A = "850";
			modelParams.A1 = "5360";
			modelParams.Dy = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "490";
			modelParams.l2 = "850";
			modelParams.h = "576";
			break;
		default:
			break;
		}
	}

}

void ParamsWidget::gostDiam800(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "800";
			modelParams.length = "7130";
			modelParams.height = "1354";
			modelParams.A = "700";
			modelParams.A1 = "5100";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "330";
			modelParams.l2 = "1100";
			modelParams.h = "677";
			break;
		case 2:
			modelParams.diam = "800";
			modelParams.length = "7180";
			modelParams.height = "1354";
			modelParams.A = "700";
			modelParams.A1 = "5100";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "360";
			modelParams.l2 = "950";
			modelParams.h = "677";
			break;
		case 3:
			modelParams.diam = "800";
			modelParams.length = "7220";
			modelParams.height = "1354";
			modelParams.A = "750";
			modelParams.A1 = "4900";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "380";
			modelParams.l2 = "950";
			modelParams.h = "677";
			break;
		case 4:
			modelParams.diam = "800";
			modelParams.length = "7400";
			modelParams.height = "1430";
			modelParams.A = "890";
			modelParams.A1 = "4670";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "450";
			modelParams.l2 = "715";
			break;
		default:
			break;
		}

	}
	else if (type == KP_MODEL)
	{
		switch (preasure)
		{
		case 0:
			modelParams.diam = "800";
			modelParams.length = "7050";
			modelParams.height = "1354";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "250";
			modelParams.Dy1 = "400";
			modelParams.Dy2 = "150";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "340";
			modelParams.l2 = "650";
			modelParams.h = "612";
			break;
		case 1:
			modelParams.diam = "800";
			modelParams.length = "7050";
			modelParams.height = "1354";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "250";
			modelParams.Dy1 = "300";
			modelParams.Dy2 = "150";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "340";
			modelParams.l2 = "650";
			modelParams.h = "612";
			break;
		case 2:
			modelParams.diam = "800";
			modelParams.length = "7130";
			modelParams.height = "1354";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.Dy2 = "150";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "370";
			modelParams.l2 = "650";
			modelParams.h = "616";
			break;
		default:
			break;
		}
	}
	else if (type == TU_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "800";
			modelParams.length = "7300";
			modelParams.height = "1354";
			modelParams.A = "700";
			modelParams.A1 = "5400";
			modelParams.Dy = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "460";
			modelParams.l2 = "1450";
			modelParams.h = "612";
			break;
		case 2:
			modelParams.diam = "800";
			modelParams.length = "7315";
			modelParams.height = "1354";
			modelParams.A = "700";
			modelParams.A1 = "5400";
			modelParams.Dy = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "490";
			modelParams.l2 = "1450";
			modelParams.h = "616";
			break;
		case 3:
			modelParams.diam = "800";
			modelParams.length = "7360";
			modelParams.height = "1354";
			modelParams.A = "750";
			modelParams.A1 = "5360";
			modelParams.Dy = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "530";
			modelParams.l2 = "1450";
			modelParams.h = "616";
			break;
		case 4:
			modelParams.diam = "800";
			modelParams.length = "7550";
			modelParams.height = "1430";
			modelParams.A = "910";
			modelParams.A1 = "5360";
			modelParams.Dy = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "550";
			modelParams.l2 = "1450";
			modelParams.h = "622";
			break;
		default:
			break;
		}
	}

}

void ParamsWidget::gostDiam900(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "900";
			modelParams.length = "7230";
			modelParams.height = "1374";
			modelParams.A = "720";
			modelParams.A1 = "5000";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "360";
			modelParams.l2 = "950";
			modelParams.h = "666";
			break;
		case 2:
			modelParams.diam = "900";
			modelParams.length = "7310";
			modelParams.height = "1398";
			modelParams.A = "720";
			modelParams.A1 = "4950";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "390";
			modelParams.l2 = "950";
			modelParams.h = "666";
			break;
		case 3:
			modelParams.diam = "900";
			modelParams.length = "7420";
			modelParams.height = "1492";
			modelParams.A = "840";
			modelParams.A1 = "4750";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "420";
			modelParams.l2 = "850";
			modelParams.h = "672";
			break;
		case 4:
			modelParams.diam = "900";
			modelParams.length = "7550";
			modelParams.height = "1542";
			modelParams.A = "1100";
			modelParams.A1 = "4400";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "450";
			modelParams.l2 = "700";
			modelParams.h = "680";
			break;
		default:
			break;
		}

	}
	else if (type == KP_MODEL)
	{
		switch (preasure)
		{
		case 0:
			modelParams.diam = "900";
			modelParams.length = "7140";
			modelParams.height = "1374";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "250";
			modelParams.Dy1 = "400";
			modelParams.Dy2 = "150";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "360";
			modelParams.l2 = "650";
			modelParams.h = "666";
			break;
		case 1:
			modelParams.diam = "900";
			modelParams.length = "7140";
			modelParams.height = "1374";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "250";
			modelParams.Dy1 = "300";
			modelParams.Dy2 = "150";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "360";
			modelParams.l2 = "650";
			modelParams.h = "666";
			break;
		case 2:
			modelParams.diam = "900";
			modelParams.length = "7250";
			modelParams.height = "1398";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "250";
			modelParams.Dy1 = "250";
			modelParams.Dy2 = "150";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "400";
			modelParams.l2 = "650";
			modelParams.h = "666";
			break;
		default:
			break;
		}
	}
	else if (type == TU_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "900";
			modelParams.length = "7450";
			modelParams.height = "1374";
			modelParams.A = "720";
			modelParams.A1 = "5400";
			modelParams.Dy = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "490";
			modelParams.l2 = "1450";
			modelParams.h = "666";
			break;
		case 2:
			modelParams.diam = "900";
			modelParams.length = "7450";
			modelParams.height = "1398";
			modelParams.A = "750";
			modelParams.A1 = "5400";
			modelParams.Dy = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "540";
			modelParams.l2 = "1450";
			modelParams.h = "666";
			break;
		case 3:
			modelParams.diam = "900";
			modelParams.length = "7540";
			modelParams.height = "1492";
			modelParams.A = "840";
			modelParams.A1 = "5360";
			modelParams.Dy = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "560";
			modelParams.l2 = "1450";
			modelParams.h = "672";
			break;
		default:
			break;
		}
	}
}

void ParamsWidget::gostDiam1000(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "1000";
			modelParams.length = "7300";
			modelParams.height = "1558";
			modelParams.A = "750";
			modelParams.A1 = "5000";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "410";
			modelParams.l2 = "950";
			modelParams.h = "712";
			break;
		case 2:
			modelParams.diam = "1000";
			modelParams.length = "7350";
			modelParams.height = "1558";
			modelParams.A = "750";
			modelParams.A1 = "5000";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "430";
			modelParams.l2 = "950";
			modelParams.h = "716";
			break;
		case 3:
			modelParams.diam = "1000";
			modelParams.length = "7470";
			modelParams.height = "1558";
			modelParams.A = "840";
			modelParams.A1 = "4800";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "460";
			modelParams.l2 = "750";
			modelParams.h = "716";
			break;
		case 4:
			modelParams.diam = "1000";
			modelParams.length = "7580";
			modelParams.height = "1860";
			modelParams.A = "1330";
			modelParams.A1 = "4200";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "480";
			modelParams.l2 = "600";
			modelParams.h = "726";
			break;
		default:
			break;
		}

	}
	else if (type == KP_MODEL)
	{
		switch (preasure)
		{
		case 0:
			modelParams.diam = "1000";
			modelParams.length = "7290";
			modelParams.height = "1558";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "300";
			modelParams.Dy1 = "400";
			modelParams.Dy2 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "410";
			modelParams.l2 = "650";
			modelParams.h = "712";
			break;
		case 1:
			modelParams.diam = "1000";
			modelParams.length = "7290";
			modelParams.height = "1558";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.Dy2 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "410";
			modelParams.l2 = "650";
			modelParams.h = "712";
			break;
		case 2:
			modelParams.diam = "1000";
			modelParams.length = "7390";
			modelParams.height = "1558";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.Dy2 = "200";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "430";
			modelParams.l2 = "650";
			modelParams.h = "716";
			break;
		default:
			break;
		}
		}
	else if (type == TU_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "1000";
			modelParams.length = "7625";
			modelParams.height = "1558";
			modelParams.A = "750";
			modelParams.A1 = "5400";
			modelParams.Dy = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "570";
			modelParams.l2 = "1450";
			modelParams.h = "712";
			break;
		case 2:
			modelParams.diam = "1000";
			modelParams.length = "7625";
			modelParams.height = "1558";
			modelParams.A = "750";
			modelParams.A1 = "5400";
			modelParams.Dy = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "610";
			modelParams.l2 = "1450";
			modelParams.h = "716";
			break;
		case 3:
			modelParams.diam = "1000";
			modelParams.length = "7660";
			modelParams.height = "1558";
			modelParams.A = "880";
			modelParams.A1 = "5360";
			modelParams.Dy = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "630";
			modelParams.l2 = "1450";
			modelParams.h = "716";
			break;
		default:
			break;
		}
	}
}

void ParamsWidget::gostDiam1200(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == HPG_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "1200";
			modelParams.length = "7480";
			modelParams.height = "1780";
			modelParams.A = "820";
			modelParams.A1 = "4760";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "450";
			modelParams.l2 = "800";
			modelParams.h = "822";
			break;
		case 2:
			modelParams.diam = "1200";
			modelParams.length = "7500";
			modelParams.height = "1780";
			modelParams.A = "870";
			modelParams.A1 = "4760";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "470";
			modelParams.l2 = "800";
			modelParams.h = "822";
			break;
		case 3:
			modelParams.diam = "1200";
			modelParams.length = "7550";
			modelParams.height = "1780";
			modelParams.A = "1130";
			modelParams.A1 = "4350";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "500";
			modelParams.l2 = "700";
			modelParams.h = "824";
			break;
		case 4:
			modelParams.diam = "1200";
			modelParams.length = "7700";
			modelParams.height = "1900";
			modelParams.A = "1400";
			modelParams.A1 = "3800";
			modelParams.Dy = "300";
			modelParams.Dy1 = "300";
			modelParams.l = "6000";
			modelParams.l0 = "2550";
			modelParams.l1 = "530";
			modelParams.l2 = "700";
			modelParams.h = "836";
			break;

		default:
			break;
		}

	}
	else if (type == KP_MODEL)
	{
		switch (preasure)
		{
		case 0:
			modelParams.diam = "1200";
			modelParams.length = "7550";
			modelParams.height = "1780";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "300";
			modelParams.Dy1 = "500";
			modelParams.Dy2 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "430";
			modelParams.l2 = "650";
			modelParams.h = "822";
			break;
		case 1:
			modelParams.diam = "1200";
			modelParams.length = "7550";
			modelParams.height = "1780";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "300";
			modelParams.Dy1 = "400";
			modelParams.Dy2 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "430";
			modelParams.l2 = "650";
			modelParams.h = "822";
			break;
		case 2:
			modelParams.diam = "1200";
			modelParams.length = "7720";
			modelParams.height = "1780";
			modelParams.A = "1100";
			modelParams.A1 = "4500";
			modelParams.Dy = "300";
			modelParams.Dy1 = "350";
			modelParams.Dy2 = "250";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "470";
			modelParams.l2 = "650";
			modelParams.h = "822";
			break;
		default:
			break;
		}
		}
	else if (type == TU_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "1200";
			modelParams.length = "7720";
			modelParams.height = "1780";
			modelParams.A = "820";
			modelParams.A1 = "5400";
			modelParams.Dy = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "630";
			modelParams.l2 = "1400";
			modelParams.h = "822";
			break;
		case 2:
			modelParams.diam = "1200";
			modelParams.length = "7800";
			modelParams.height = "1780";
			modelParams.A = "870";
			modelParams.A1 = "5360";
			modelParams.Dy = "300";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "680";
			modelParams.l2 = "1400";
			modelParams.h = "822";
			break;
		default:
			break;
		}
	}
}

void ParamsWidget::gostDiam1400(int type, QString pres)
{
	int preasure;
	preasure = checkPreassure(pres);

	if (type == TU_MODEL)
	{
		switch (preasure)
		{
		case 1:
			modelParams.diam = "1400";
			modelParams.length = "8055";
			modelParams.height = "1980";
			modelParams.A = "1000";
			modelParams.A1 = "5200";
			modelParams.Dy = "350";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "750";
			modelParams.l2 = "1300";
			modelParams.h = "922";
			break;
		case 2:
			modelParams.diam = "1400";
			modelParams.length = "8075";
			modelParams.height = "1980";
			modelParams.A = "1000";
			modelParams.A1 = "5200";
			modelParams.Dy = "350";
			modelParams.l = "6000";
			modelParams.l0 = "3000";
			modelParams.l1 = "790";
			modelParams.l2 = "1300";
			modelParams.h = "922";
			break;
		default:
			break;
		}

	}
}