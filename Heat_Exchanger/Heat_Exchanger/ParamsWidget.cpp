#include "ParamsWidget.h"
#include <QMessageBox>


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
;

	setupForm_model();
	setupForm_scene();
	ui.comboBox_HDiam->setDisabled(!PARAMETRIZE);
	ui.comboBox_HPress->setDisabled(!PARAMETRIZE);
	connect(ui.HpushButton_build, &QPushButton::clicked, this, &ParamsWidget::buildHPG);
	connect(ui.KpushButton_build, &QPushButton::clicked, this, &ParamsWidget::buildKP);
	connect(ui.UpushButton_build, &QPushButton::clicked, this, &ParamsWidget::buildTU);
	connect(ui.HpushButton_reset, &QPushButton::clicked, this, &ParamsWidget::reset);
	connect(ui.comboBox_lighttype, &QComboBox::currentTextChanged, this, &ParamsWidget::sceneset);
	connect(ui.comboBox_plain, &QComboBox::currentTextChanged, this, &ParamsWidget::sceneset);
	connect(ui.checkBox_edges, &QCheckBox::stateChanged, this, &ParamsWidget::sceneset);
	connect(ui.checkBox_section, &QCheckBox::stateChanged, this, &ParamsWidget::sceneset);

}

ParamsWidget::~ParamsWidget()
{
}

BuildMathModel::BuildParams ParamsWidget::getParams_model()
{
	updateParams_modelHPG();
	return modelParams;
}

SceneParams ParamsWidget::getParams_scene()
{
	updateParams_scene();
	return sceneParams;
}

void ParamsWidget::updateParams_modelHPG()
{
	modelParams.type = HPG_MODEL;
	/*modelParams.diam = ui.comboBox_HDiam->value();
	modelParams.pressure = ui.comboBox_HPress->value();*/
	
}

void ParamsWidget::updateParams_modelKP()
{
	modelParams.type = KP_MODEL;

}

void ParamsWidget::updateParams_modelTU()
{
	modelParams.type = TU_MODEL;

}

void ParamsWidget::setupForm_model()
{
	/*ui.comboBox_HDiam->setValue(modelParams.diam);
	ui.comboBox_HPress->setValue(modelParams.pressure);*/
	
}

void ParamsWidget::updateParams_scene()
{
	sceneParams.edges = ui.checkBox_edges->isChecked() ? true : false;
	sceneParams.lightType = ui.comboBox_lighttype->currentIndex();
	sceneParams.plain = ui.comboBox_plain->currentIndex();
	sceneParams.section = ui.checkBox_section->isChecked() ? true : false;
	//sceneParams.frameTransp = ui.horizontalSlider_frameTransp->value();
}

void ParamsWidget::setupForm_scene()
{
	ui.checkBox_edges->setChecked(sceneParams.edges);
	ui.comboBox_lighttype->setCurrentIndex(sceneParams.lightType);
	ui.comboBox_plain->setCurrentIndex(sceneParams.plain);
	ui.checkBox_section->setChecked(sceneParams.section);
	//ui.horizontalSlider_frameTransp->setValue(sceneParams.frameTransp);
}


void ParamsWidget::toggleViewSectionSlot()
{
	sceneParams.section = !sceneParams.section;
	ui.checkBox_section->setChecked(sceneParams.section);
	emit setupSceneSignal();
}
	/*QMessageBox::critical(this, "Ошибка","Проектирование модели вызвало критическую ошибку");
	QMessageBox::critical(this, "Ошибка","Расчет модели вызвал критическую ошибку");
	QMessageBox::critical(this, "Ошибка","Экспорт модели вызвал критическую ошибку");
	QMessageBox::critical(this, "Ошибка","Экспорт расчетов вызвал критическую ошибку");*/

void ParamsWidget::buildHPG()
{
	updateParams_modelHPG();
	emit buildSignal();
}

void ParamsWidget::buildKP()
{
	updateParams_modelKP();
	emit buildSignal();
}

void ParamsWidget::buildTU()
{
	updateParams_modelTU();
	emit buildSignal();
}

void ParamsWidget::reset()
{
	/*QMessageBox::warning(this, "Внимание", "Модель успешно сброшена");*/
	modelParams = BuildMathModel::BuildParams();
	setupForm_model();
}

void ParamsWidget::sceneset()
{
	updateParams_scene();
	emit setupSceneSignal();
}
