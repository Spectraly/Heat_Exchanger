#pragma once

#include <QWidget>
#include "ui_ParamsWidget.h"
#include "BuildParams.h"
#include "SceneParams.h"

#define HPG_MODEL 0;
#define KP_MODEL  1;
#define TU_MODEL  2;

class ParamsWidget : public QWidget
{
	Q_OBJECT

public:
	ParamsWidget(QWidget* parent = Q_NULLPTR);
	~ParamsWidget();

	BuildMathModel::BuildParams getParams_model();
	SceneParams getParams_scene();

private:
	Ui::ParamsWidget ui;
	BuildMathModel::BuildParams modelParams;
	SceneParams sceneParams;
	void updateParams_modelHPG();
	void updateParams_modelKP();
	void updateParams_modelTU();
	void setupForm_model();
	void updateParams_scene();
	void changeTab();

public slots:
	void toggleViewSectionSlot();
	void setupForm_scene();


private slots:
	void buildHPG();
	void buildKP();
	void buildTU();
	void reset();
	void sceneset();

signals:
	void buildSignal();
	void setupSceneSignal();
	void tabSignal(int);
};
