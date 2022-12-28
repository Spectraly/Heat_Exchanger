#include "ParamsWidget.h"
#include <QMessageBox>

const bool PARAMETRIZE = true;

ParamsWidget::ParamsWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.comboBox_doublesided->addItem("false", QVariant(0));
	ui.comboBox_doublesided->addItem("true", QVariant(1));
	ui.comboBox_edges->addItem("false", QVariant(0));
	ui.comboBox_edges->addItem("true", QVariant(1));
	ui.comboBox_lighttype->addItem("point", QVariant(0));
	ui.comboBox_lighttype->addItem("direction", QVariant(1));
	ui.comboBox_lighttype->addItem("spot", QVariant(2));
	ui.comboBox_section->addItem("false", QVariant(0));
	ui.comboBox_section->addItem("true", QVariant(1));
	//ui.pushButton->setText("frfrf");

	setupForm_model();
	setupForm_scene();
	ui.dSB_diam->setDisabled(!PARAMETRIZE);
	ui.dSB_pressure->setDisabled(!PARAMETRIZE);
	connect(ui.pushButton_build, &QPushButton::clicked, this, &ParamsWidget::applyAndBuild);
	connect(ui.pushButton_reset, &QPushButton::clicked, this, &ParamsWidget::reset);
	connect(ui.pushButton_sceneset, &QPushButton::clicked, this, &ParamsWidget::sceneset);
}

ParamsWidget::~ParamsWidget()
{
}

BuildMathModel::BuildParams ParamsWidget::getParams_model()
{
	//updateParams_model();
	return modelParams;
}

SceneParams ParamsWidget::getParams_scene()
{
	//updateParams_scene();
	return sceneParams;
}

void ParamsWidget::updateParams_model()
{
	modelParams.diam = ui.dSB_diam->value();
	modelParams.pressure = ui.dSB_pressure->value();
	//modelParams.colorScheme = ui.comboBox_colorScheme->currentIndex();
}

void ParamsWidget::setupForm_model()
{
	ui.dSB_diam->setValue(modelParams.diam);
	ui.dSB_pressure->setValue(modelParams.pressure);
	//ui.comboBox_colorScheme->setCurrentIndex(modelParams.colorScheme ? 1 : 0);
}

void ParamsWidget::updateParams_scene()
{
	sceneParams.doubleSided = ui.comboBox_doublesided->currentIndex();
	sceneParams.edges = ui.comboBox_edges->currentIndex();
	sceneParams.lightType = ui.comboBox_lighttype->currentIndex();
	sceneParams.section = ui.comboBox_section->currentIndex();
	sceneParams.frameTransp = ui.horizontalSlider_frameTransp->value();
}

void ParamsWidget::setupForm_scene()
{
	ui.comboBox_doublesided->setCurrentIndex(sceneParams.doubleSided ? 1 : 0);
	ui.comboBox_edges->setCurrentIndex(sceneParams.edges ? 1 : 0);
	ui.comboBox_lighttype->setCurrentIndex(sceneParams.lightType);
	ui.comboBox_section->setCurrentIndex(sceneParams.section ? 1 : 0);
	ui.horizontalSlider_frameTransp->setValue(sceneParams.frameTransp);
}

void ParamsWidget::toggleCaseTranspSlot()
{
	sceneParams.frameTransp = sceneParams.frameTransp > 50 ? 10 : 100;
	ui.horizontalSlider_frameTransp->setValue(sceneParams.frameTransp);
	emit setupSceneSignal();
}

void ParamsWidget::toggleViewSectionSlot()
{
	sceneParams.section = !sceneParams.section;
	ui.comboBox_section->setCurrentIndex(sceneParams.section ? 1 : 0);
	emit setupSceneSignal();
}

void ParamsWidget::applyAndBuild()
{
	/*QMessageBox::critical(this, "Ошибка","Проектирование модели вызвало критическую ошибку");
	QMessageBox::critical(this, "Ошибка","Расчет модели вызвал критическую ошибку");
	QMessageBox::critical(this, "Ошибка","Экспорт модели вызвал критическую ошибку");
	QMessageBox::critical(this, "Ошибка","Экспорт расчетов вызвал критическую ошибку");*/
	updateParams_model();
	emit buildSignal();
}

void ParamsWidget::reset()
{
	/*QMessageBox::warning(this, "Внимание", "Модель успешно сброшена");*/
	//modelParams = BuildMathModel::BuildParams();
	//setupForm_model();
}

void ParamsWidget::sceneset()
{
	updateParams_scene();
	emit setupSceneSignal();
}
