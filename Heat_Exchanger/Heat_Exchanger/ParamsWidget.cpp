#include "ParamsWidget.h"




const bool PARAMETRIZE = true;

ParamsWidget::ParamsWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.comboBox_lighttype->addItem("Точечный", QVariant(0));
	ui.comboBox_lighttype->addItem("Направленный", QVariant(1));
	ui.comboBox_lighttype->addItem("Прожектор", QVariant(2));
	ui.comboBox_plain->addItem("XZ", QVariant(0));
	ui.comboBox_plain->addItem("YZ", QVariant(1));
	ui.comboBox_plain->addItem("XY", QVariant(2));
	ui.tabWidget->setCurrentIndex(0);


	setupForm_model();
	setupForm_scene();
	connect(ui.HpushButton_build, &QPushButton::clicked, this, &ParamsWidget::build);
	connect(ui.HpushButton_reset, &QPushButton::clicked, this, &ParamsWidget::reset);
	connect(ui.comboBox_lighttype, &QComboBox::currentTextChanged, this, &ParamsWidget::sceneset);
	connect(ui.comboBox_plain, &QComboBox::currentTextChanged, this, &ParamsWidget::sceneset);
	connect(ui.checkBox_edges, &QCheckBox::stateChanged, this, &ParamsWidget::sceneset);
	connect(ui.checkBox_section, &QCheckBox::stateChanged, this, &ParamsWidget::sceneset);
	connect(ui.radioButtonGOST, &QRadioButton::clicked, this, &ParamsWidget::onCheckChanged);
	connect(ui.radioButtonManual, &QRadioButton::clicked, this, &ParamsWidget::onCheckChanged);
	connect(ui.comboBoxExchangerType, &QComboBox::currentTextChanged, this, &ParamsWidget::onTypeChanged);
	connect(ui.comboBox_Diam, &QComboBox::currentTextChanged, this, &ParamsWidget::onDiamChanged);


	onCheckChanged();
	setValidators();
	onTypeChanged();
}

ParamsWidget::~ParamsWidget()
{
}

BuildMathModel::BuildParams ParamsWidget::getParams_model()
{
	switch (modelParams.type)
	{
	case HPG_MODEL:
		updateParams_modelHPG();
		break;
	case KP_MODEL:
		updateParams_modelKP();
		break;
	case TU_MODEL:
		updateParams_modelTU();
		break;
	default:
		break;
	}
	return modelParams;
}

SceneParams ParamsWidget::getParams_scene()
{
	updateParams_scene();
	return sceneParams;
}

void ParamsWidget::updateParams_modelHPG()
{
	if (ui.radioButtonGOST->isChecked())
		getGostData(ui.comboBox_Diam->itemText(ui.comboBox_Diam->currentIndex()).toInt(), modelParams.type);
	else
	{
		modelParams.pressure = ui.lineEdit_Preassure->text();
		modelParams.diam = ui.lineEdit_Diam->text();
		modelParams.length = ui.lineEdit_Length->text();
		modelParams.height = ui.lineEdit_Height->text();
		modelParams.A = ui.lineEdit_A->text();
		modelParams.A1 = ui.lineEdit_A1->text();
		modelParams.Dy = ui.lineEdit_Dy->text();
		modelParams.Dy1 = ui.lineEdit_Dy1->text();
		modelParams.l = ui.lineEdit_l->text();
		modelParams.l0 = ui.lineEdit_l0->text();
		modelParams.l1 = ui.lineEdit_l1->text();
		modelParams.l2 = ui.lineEdit_l2->text();
		modelParams.l3 = ui.lineEdit_l3->text();
		modelParams.l4 = ui.lineEdit_l4->text();
		modelParams.S = ui.lineEdit_S->text();
		modelParams.S1 = ui.lineEdit_S1->text();
		modelParams.h = ui.lineEdit_h->text();

		modelParams.ro = ui.lineEdit_Ro->text();
		modelParams.sig = ui.lineEdit_Sig->text();
		modelParams.fi = ui.lineEdit_Fi->text();

	}
}

void ParamsWidget::updateParams_modelKP()
{
	if (ui.radioButtonGOST->isChecked())
		getGostData(ui.comboBox_Diam->itemText(ui.comboBox_Diam->currentIndex()).toInt(), modelParams.type);
	else
	{
		modelParams.pressure = ui.lineEdit_Preassure->text();
		modelParams.diam = ui.lineEdit_Diam->text();
		modelParams.length = ui.lineEdit_Length->text();
		modelParams.height = ui.lineEdit_Height->text();
		modelParams.A = ui.lineEdit_A->text();
		modelParams.A1 = ui.lineEdit_A1->text();
		modelParams.Dy = ui.lineEdit_Dy->text();
		modelParams.Dy1 = ui.lineEdit_Dy1->text();
		modelParams.Dy2 = ui.lineEdit_Dy2->text();
		modelParams.l = ui.lineEdit_l->text();
		modelParams.l0 = ui.lineEdit_l0->text();
		modelParams.l1 = ui.lineEdit_l1->text();
		modelParams.l2 = ui.lineEdit_l2->text();
		modelParams.l3 = ui.lineEdit_l3->text();
		modelParams.l4 = ui.lineEdit_l4->text();
		modelParams.S = ui.lineEdit_S->text();
		modelParams.S1 = ui.lineEdit_S1->text();
		modelParams.h = ui.lineEdit_h->text();

		modelParams.ro = ui.lineEdit_Ro->text();
		modelParams.sig = ui.lineEdit_Sig->text();
		modelParams.fi = ui.lineEdit_Fi->text();
	}
}

void ParamsWidget::updateParams_modelTU()
{
	if (ui.radioButtonGOST->isChecked())
		getGostData(ui.comboBox_Diam->itemText(ui.comboBox_Diam->currentIndex()).toInt(), modelParams.type);
	else
	{
		modelParams.pressure = ui.lineEdit_Preassure->text();
		modelParams.diam = ui.lineEdit_Diam->text();
		modelParams.length = ui.lineEdit_Length->text();
		modelParams.height = ui.lineEdit_Height->text();
		modelParams.A = ui.lineEdit_A->text();
		modelParams.A1 = ui.lineEdit_A1->text();
		modelParams.Dy = ui.lineEdit_Dy->text();
		modelParams.l = ui.lineEdit_l->text();
		modelParams.l0 = ui.lineEdit_l0->text();
		modelParams.l1 = ui.lineEdit_l1->text();
		modelParams.l2 = ui.lineEdit_l2->text();
		modelParams.l3 = ui.lineEdit_l3->text();
		modelParams.l4 = ui.lineEdit_l4->text();
		modelParams.S = ui.lineEdit_S->text();
		modelParams.S1 = ui.lineEdit_S1->text();
		modelParams.h = ui.lineEdit_h->text();

		modelParams.ro = ui.lineEdit_Ro->text();
		modelParams.sig = ui.lineEdit_Sig->text();
		modelParams.fi = ui.lineEdit_Fi->text();
	}
}	

void ParamsWidget::setupForm_model()
{
	switch (ui.comboBoxExchangerType->currentIndex())
	{
	case HPG_MODEL:
		modelParams = BuildMathModel::BuildParams();
		ui.lineEdit_Preassure->setText(modelParams.pressure);
		ui.lineEdit_Diam->setText(modelParams.diam);
		ui.lineEdit_Length->setText(modelParams.length);
		ui.lineEdit_Height->setText(modelParams.height);
		ui.lineEdit_A->setText(modelParams.A);
		ui.lineEdit_A1->setText(modelParams.A1);
		ui.lineEdit_Dy->setText(modelParams.Dy);
		ui.lineEdit_Dy1->setText(modelParams.Dy1);
		ui.lineEdit_Dy2->setText(modelParams.Dy2);
		ui.lineEdit_l->setText(modelParams.l);
		ui.lineEdit_l0->setText(modelParams.l0);
		ui.lineEdit_l1->setText(modelParams.l1);
		ui.lineEdit_l2->setText(modelParams.l2);
		ui.lineEdit_l3->setText(modelParams.l3);
		ui.lineEdit_l4->setText(modelParams.l4);
		ui.lineEdit_S->setText(modelParams.S);
		ui.lineEdit_S1->setText(modelParams.S1);
		ui.lineEdit_h->setText(modelParams.h);

		ui.lineEdit_Ro->setText(modelParams.ro);
		ui.lineEdit_Sig->setText(modelParams.sig);
		ui.lineEdit_Fi->setText(modelParams.fi);
		break;
	case KP_MODEL:
		ui.lineEdit_Preassure->setText("1.0");
		ui.lineEdit_Diam->setText("600.0");
		ui.lineEdit_Length->setText("6800.0");
		ui.lineEdit_Height->setText("1060.0");
		ui.lineEdit_A->setText("1100.0");
		ui.lineEdit_A1->setText("4500.0");
		ui.lineEdit_Dy->setText("200.0");
		ui.lineEdit_Dy1->setText("300.0");
		ui.lineEdit_Dy2->setText("100.0");
		ui.lineEdit_l->setText("6000.0");
		ui.lineEdit_l0->setText("3000.0");
		ui.lineEdit_l1->setText("290.0");
		ui.lineEdit_l2->setText("650.0");
		ui.lineEdit_l3->setText("900.0");
		ui.lineEdit_l4->setText("3600.0");
		ui.lineEdit_S->setText("40.0");
		ui.lineEdit_S1->setText("10.0");
		ui.lineEdit_h->setText("525.0");

		ui.lineEdit_Ro->setText("1040.0");
		ui.lineEdit_Sig->setText("132.0");
		ui.lineEdit_Fi->setText("0.9");
		break;
	case TU_MODEL:
		ui.lineEdit_Preassure->setText("2.5");
		ui.lineEdit_Diam->setText("325.0");
		ui.lineEdit_Length->setText("3800.0");
		ui.lineEdit_Height->setText("600.0");
		ui.lineEdit_A->setText("450.0");
		ui.lineEdit_A1->setText("2500.0");
		ui.lineEdit_Dy->setText("100.0");
		ui.lineEdit_Dy1->setText("100.0");
		ui.lineEdit_Dy2->setText("100.0");
		ui.lineEdit_l->setText("3000.0");
		ui.lineEdit_l0->setText("1500.0");
		ui.lineEdit_l1->setText("230.0");
		ui.lineEdit_l2->setText("400.0");
		ui.lineEdit_l3->setText("150.0");
		ui.lineEdit_l4->setText("2250.0");
		ui.lineEdit_S->setText("45.0");
		ui.lineEdit_S1->setText("4.0");
		ui.lineEdit_h->setText("292.0");

		ui.lineEdit_Ro->setText("1040.0");
		ui.lineEdit_Sig->setText("132.0");
		ui.lineEdit_Fi->setText("0.9");
		break;
	default:
		break;
	}
}

void ParamsWidget::setValidators()
{
	ui.lineEdit_Preassure->setValidator(valDouble);
	ui.lineEdit_Diam->setValidator(valDouble);
	ui.lineEdit_Length->setValidator(valDouble);
	ui.lineEdit_Height->setValidator(valDouble);
	ui.lineEdit_A-> setValidator(valDouble);
	ui.lineEdit_A1->setValidator(valDouble);
	ui.lineEdit_Dy->setValidator(valDouble);
	ui.lineEdit_Dy1->setValidator(valDouble);
	ui.lineEdit_Dy2->setValidator(valDouble);
	ui.lineEdit_l->setValidator(valDouble);
	ui.lineEdit_l0->setValidator(valDouble);
	ui.lineEdit_l1->setValidator(valDouble);
	ui.lineEdit_l2->setValidator(valDouble);
	ui.lineEdit_l3->setValidator(valDouble);
	ui.lineEdit_l4->setValidator(valDouble);
	ui.lineEdit_S->setValidator(valDouble);
	ui.lineEdit_S1->setValidator(valDouble);
	ui.lineEdit_h->setValidator(valDouble);

	ui.lineEdit_Ro->setValidator(valDouble);
	ui.lineEdit_Sig->setValidator(valDouble);
	ui.lineEdit_Fi->setValidator(valDouble);

	ui.comboBoxExchangerType->addItem("Холодильник с плавающей головкой горизонтальный");
	ui.comboBoxExchangerType->addItem("Конденсатор с плавающей головкой");
	ui.comboBoxExchangerType->addItem("Теплообменный аппарат с U - образными трубами");

	ui.comboBox_Diam->addItem("325");
	ui.comboBox_Diam->addItem("400");
	ui.comboBox_Diam->addItem("500");
	ui.comboBox_Diam->addItem("600");
	ui.comboBox_Diam->addItem("700");
	ui.comboBox_Diam->addItem("800");
	ui.comboBox_Diam->addItem("900");
	ui.comboBox_Diam->addItem("1000");
	ui.comboBox_Diam->addItem("1200");
	ui.comboBox_Diam->addItem("1400");
	ui.comboBox_Diam->setMaxVisibleItems(ui.comboBox_Diam->model()->rowCount());


	ui.comboBox_Pressure->addItem("1,0");
	ui.comboBox_Pressure->addItem("1,6");
	ui.comboBox_Pressure->addItem("2,5");
	ui.comboBox_Pressure->addItem("4,0");
	ui.comboBox_Pressure->addItem("6,3");
	ui.comboBox_Pressure->setMaxVisibleItems(ui.comboBox_Pressure->model()->rowCount());

	ui.comboBox_d->addItem("20.0");
	ui.comboBox_d->addItem("25.0");
}	

bool ParamsWidget::checkValidate()
{
	bool check = true;
	if (ui.lineEdit_Preassure->text() != "" &&
		ui.lineEdit_Diam->text() != "" && 
		ui.lineEdit_Length->text() != "" &&
		ui.lineEdit_Height->text() != "" &&
		ui.lineEdit_A->text() != "" &&
		ui.lineEdit_A1->text() != "" &&
		ui.lineEdit_Dy->text() != "" &&
		ui.lineEdit_Dy1->text() != "" &&
		ui.lineEdit_Dy2->text() != "" &&
		ui.lineEdit_l->text() != "" &&
		ui.lineEdit_l0->text() != "" &&
		ui.lineEdit_l1->text() != "" &&
		ui.lineEdit_l2->text() != "" &&
		ui.lineEdit_l3->text() != "" &&
		ui.lineEdit_l4->text() != "" &&
		ui.lineEdit_S->text() != "" &&
		ui.lineEdit_S1->text() != "" &&
		ui.lineEdit_h->text() != "")//проверки на пустые поля
	{
		if (ui.lineEdit_Preassure->text().toDouble() != 0 &&
			ui.lineEdit_Diam->text().toDouble() != 0 &&
			ui.lineEdit_Length->text().toDouble() != 0 &&
			ui.lineEdit_Height->text().toDouble() != 0 &&
			ui.lineEdit_A->text().toDouble() != 0 &&
			ui.lineEdit_A1->text().toDouble() != 0 &&
			ui.lineEdit_Dy->text().toDouble() != 0 &&
			ui.lineEdit_Dy1->text().toDouble() != 0 &&
			ui.lineEdit_Dy2->text().toDouble() != 0 &&
			ui.lineEdit_l->text().toDouble() != 0 &&
			ui.lineEdit_l0->text().toDouble() != 0 &&
			ui.lineEdit_l1->text().toDouble() != 0 &&
			ui.lineEdit_l2->text().toDouble() != 0 &&
			ui.lineEdit_l3->text().toDouble() != 0 &&
			ui.lineEdit_l4->text().toDouble() != 0 &&
			ui.lineEdit_S->text().toDouble() != 0 &&
			ui.lineEdit_S1->text().toDouble() != 0 &&
			ui.lineEdit_h->text().toDouble() != 0)
		{
			if (ui.lineEdit_Diam->text().toDouble() > ui.lineEdit_Dy->text().toDouble() &&
				ui.lineEdit_Diam->text().toDouble() > ui.lineEdit_Dy1->text().toDouble() &&
				ui.lineEdit_Diam->text().toDouble() > ui.lineEdit_Dy2->text().toDouble() &&
				ui.lineEdit_Diam->text().toDouble() > ui.lineEdit_h->text().toDouble() &&
				ui.lineEdit_Diam->text().toDouble() < ui.lineEdit_Height->text().toDouble())//проверки на значение диаметра
			{
				if (ui.lineEdit_Length->text().toDouble() > ui.lineEdit_A->text().toDouble() &&
					ui.lineEdit_Length->text().toDouble() > ui.lineEdit_A1->text().toDouble() &&
					ui.lineEdit_Length->text().toDouble() > ui.lineEdit_l->text().toDouble() &&
					ui.lineEdit_Length->text().toDouble() > ui.lineEdit_l0->text().toDouble() &&
					ui.lineEdit_Length->text().toDouble() > ui.lineEdit_l1->text().toDouble() &&
					ui.lineEdit_Length->text().toDouble() > ui.lineEdit_l2->text().toDouble() &&
					ui.lineEdit_Length->text().toDouble() > ui.lineEdit_l3->text().toDouble() &&
					ui.lineEdit_Length->text().toDouble() > ui.lineEdit_l4->text().toDouble())//проверки на значение длины
				{
					if (ui.lineEdit_l3->text().toDouble() > ui.lineEdit_S->text().toDouble() &&
						ui.lineEdit_l3->text().toDouble() > ui.lineEdit_S1->text().toDouble())//проверки на толщину перегородок и решеток
						return true;
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
	
}

void ParamsWidget::updateParams_scene()
{
	sceneParams.edges = ui.checkBox_edges->isChecked() ? true : false;
	sceneParams.lightType = ui.comboBox_lighttype->currentIndex();
	sceneParams.plain = ui.comboBox_plain->currentIndex();
	sceneParams.section = ui.checkBox_section->isChecked() ? true : false;
}

void ParamsWidget::hideManualFields(bool b)
{
	ui.lineEdit_Preassure->setHidden(b);
	ui.lineEdit_Diam->setHidden(b);
	ui.lineEdit_Length->setHidden(b);
	ui.lineEdit_Height->setHidden(b);
	ui.lineEdit_A->setHidden(b);
	ui.lineEdit_A1->setHidden(b);
	ui.lineEdit_Dy->setHidden(b);
	ui.lineEdit_Dy1->setHidden(b);
	ui.lineEdit_Dy2->setHidden(b);
	ui.lineEdit_l->setHidden(b);
	ui.lineEdit_l0->setHidden(b);
	ui.lineEdit_l1->setHidden(b);
	ui.lineEdit_l2->setHidden(b);
	ui.lineEdit_l3->setHidden(b);
	ui.lineEdit_l4->setHidden(b);
	ui.lineEdit_S->setHidden(b);
	ui.lineEdit_S1->setHidden(b);
	ui.lineEdit_h->setHidden(b);

	ui.label_P->setHidden(b);
	ui.label_Dv->setHidden(b);
	ui.label_L->setHidden(b);
	ui.label_H->setHidden(b);
	ui.label_A->setHidden(b);
	ui.label_A1->setHidden(b);
	ui.label_Dy->setHidden(b);
	ui.label_Dy1->setHidden(b);
	ui.label_Dy2->setHidden(b);
	ui.label_l->setHidden(b);
	ui.label_l0->setHidden(b);
	ui.label_l1->setHidden(b);
	ui.label_l2->setHidden(b);
	ui.label_l3->setHidden(b);
	ui.label_l4->setHidden(b);
	ui.label_S->setHidden(b);
	ui.label_S1->setHidden(b);
	ui.label_h->setHidden(b);



	ui.comboBox_Diam->setHidden(!b);
	ui.comboBox_Pressure->setHidden(!b);
	ui.label_Dvg->setHidden(!b);
	ui.label_Pg->setHidden(!b);
}



void ParamsWidget::setupForm_scene()
{
	ui.checkBox_edges->setChecked(sceneParams.edges);
	ui.comboBox_lighttype->setCurrentIndex(sceneParams.lightType);
	ui.comboBox_plain->setCurrentIndex(sceneParams.plain);
	ui.checkBox_section->setChecked(sceneParams.section);
}

void ParamsWidget::toggleViewSectionSlot()
{
	sceneParams.section = !sceneParams.section;
	ui.checkBox_section->setChecked(sceneParams.section);
	emit setupSceneSignal();
}

void ParamsWidget::build()
{
	modelParams.d = ui.comboBox_d->currentText();
	if (checkValidate())
		emit buildSignal();
	else
		QMessageBox::warning(this, "Предупреждение", "Проверьте введенные данные");
}

void ParamsWidget::reset()
{
	modelParams = BuildMathModel::BuildParams();
	switch (ui.comboBoxExchangerType->currentIndex())
	{
	case HPG_MODEL:
		modelParams.type = HPG_MODEL;
		break;
	case KP_MODEL:
		modelParams.type = KP_MODEL;
		break;
	case TU_MODEL:
		modelParams.type = TU_MODEL;
		break;
	default:
		break;
	}
	setupForm_model();
}

void ParamsWidget::sceneset()
{
	updateParams_scene();
	emit setupSceneSignal();
}

void ParamsWidget::onCheckChanged()
{
	if (ui.radioButtonGOST->isChecked())
		hideManualFields(true);
	else
	{
		onTypeChanged();
	}

}

void ParamsWidget::onTypeChanged()
{
	auto combo = ui.comboBox_Diam;
	combo->clear();

	if (!ui.radioButtonGOST->isChecked())
		hideManualFields(false);
	switch (ui.comboBoxExchangerType->currentIndex())
	{
	case HPG_MODEL:
		ui.label_Header->setText("Холодильник с плавающей\n головкой горизонтальный");
		modelParams.type = HPG_MODEL;
		ui.label_Dy2->setHidden(true);
		ui.lineEdit_Dy2->setHidden(true);
		combo->addItem("325");
		combo->addItem("400");
		combo->addItem("500");
		combo->addItem("600");
		combo->addItem("700");
		combo->addItem("800");
		combo->addItem("900");
		combo->addItem("1000");
		combo->addItem("1200");
		break;
	case KP_MODEL:
		modelParams.type = KP_MODEL;
		ui.label_Header->setText("Конденсатор с плавающей головкой");
		ui.label_A->setHidden(true);
		ui.label_A1->setHidden(true);
		ui.label_l->setHidden(true);
		ui.label_l0->setHidden(true);
		ui.label_l2->setHidden(true);
		ui.label_l3->setHidden(true);
		ui.label_l4->setHidden(true);
		ui.lineEdit_A->setHidden(true);
		ui.lineEdit_A1->setHidden(true);
		ui.lineEdit_l->setHidden(true);
		ui.lineEdit_l0->setHidden(true);
		ui.lineEdit_l2->setHidden(true);
		ui.lineEdit_l3->setHidden(true);
		ui.lineEdit_l4->setHidden(true);
		combo->addItem("600");
		combo->addItem("700");
		combo->addItem("800");
		combo->addItem("900");
		combo->addItem("1000");
		combo->addItem("1200");
		break;
	case TU_MODEL:
		ui.label_Header->setText("Теплообменный аппарат с\n U - образными трубами");
		modelParams.type = TU_MODEL;
		ui.label_Dy1->setHidden(true);
		ui.label_Dy2->setHidden(true);
		ui.lineEdit_Dy1->setHidden(true);
		ui.lineEdit_Dy2->setHidden(true);
		combo->addItem("325");
		combo->addItem("400");
		combo->addItem("500");
		combo->addItem("600");
		combo->addItem("700");
		combo->addItem("800");
		combo->addItem("900");
		combo->addItem("1000");
		combo->addItem("1200");
		combo->addItem("1400");
		break;
	default:
		break;
	}
	combo->setCurrentIndex(0);
	setupForm_model();
	onDiamChanged();
}

void ParamsWidget::onDiamChanged()
{
	auto combo = ui.comboBox_Pressure;
	combo->clear();

	QString diam = ui.comboBox_Diam->itemText(ui.comboBox_Diam->currentIndex());
	switch (ui.comboBoxExchangerType->currentIndex())
	{
	case HPG_MODEL:
		if (diam == "325" || diam == "400" || diam == "500")
		{
			combo->addItem("4,0");
			combo->addItem("6,3");
		}
		else if (diam == "600" || diam == "700")
		{
			combo->addItem("2,5");
			combo->addItem("4,0");
			combo->addItem("6,3");
		}
		else if (diam == "800" || diam == "900" || diam == "1000" || diam == "1200")
		{
			combo->addItem("1,6");
			combo->addItem("2,5");
			combo->addItem("4,0");
			combo->addItem("6,3");
		}
		break;
	case KP_MODEL:
			combo->addItem("1,0");
			combo->addItem("1,6");
			combo->addItem("2,5");
		break;
	case TU_MODEL:
		if (diam == "325")
		{
			combo->addItem("2,5");
			combo->addItem("4,0");
		}
		else if (diam == "400" || diam == "500")
		{
			combo->addItem("2,5");
			combo->addItem("4,0");
			combo->addItem("6,3");
		}
		else if (diam == "600" || diam == "700" || diam == "800")
		{
			combo->addItem("1,6");
			combo->addItem("2,5");
			combo->addItem("4,0");
			combo->addItem("6,3");
		}
		else if (diam == "900" || diam == "1000" )
		{
			combo->addItem("1,6");
			combo->addItem("2,5");
			combo->addItem("4,0");
		}
		else if (diam == "600" || diam == "700" || diam == "1200" || diam == "1400")
		{
			combo->addItem("1,6");
			combo->addItem("2,5");
		}
		break;
	default:
		break;
	}
	combo->setCurrentIndex(0);
}

void ParamsWidget::getGostData(int diam, int type)
{
	switch (diam)
	{
	case 325:
		gostDiam325(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 400:
		gostDiam400(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 500:
		gostDiam500(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 600:
		gostDiam600(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 700:
		gostDiam700(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 800:
		gostDiam800(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 900:
		gostDiam900(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 1000:
		gostDiam1000(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 1200:
		gostDiam1200(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	case 1400:
		gostDiam1400(type, ui.comboBox_Pressure->itemText(ui.comboBox_Pressure->currentIndex()));
		break;
	default:
		break;
	}
	
}

