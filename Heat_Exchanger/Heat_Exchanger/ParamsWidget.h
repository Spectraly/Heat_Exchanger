#pragma once

#include <QWidget>
#include "ui_ParamsWidget.h"
#include "BuildParams.h"
#include "SceneParams.h"
#include <QMessageBox>


class ParamsWidget : public QWidget
{
	Q_OBJECT

public:
	ParamsWidget(QWidget* parent = Q_NULLPTR);
	~ParamsWidget();

	BuildMathModel::BuildParams getParams_model();
	SceneParams getParams_scene();

private:
	QRegularExpression r = QRegularExpression("(\\d+)(\\.)(\\d{1,1})");
	QRegularExpressionValidator* valDouble = new QRegularExpressionValidator(r, this);
	Ui::ParamsWidget ui;
	BuildMathModel::BuildParams modelParams;
	SceneParams sceneParams;
	void updateParams_modelHPG();
	void updateParams_modelKP();
	void updateParams_modelTU();
	void setupForm_model();
	void setValidators();
	bool checkValidate();
	void updateParams_scene();
	void hideManualFields(bool);
	void getGostData(int, int);
	int checkPreassure(QString);
	void gostDiam325(int, QString);
	void gostDiam400(int, QString);
	void gostDiam500(int, QString);
	void gostDiam600(int, QString);
	void gostDiam700(int, QString);
	void gostDiam800(int, QString);
	void gostDiam900(int, QString);
	void gostDiam1000(int, QString);
	void gostDiam1200(int, QString);
	void gostDiam1400(int, QString);

public slots:
	void toggleViewSectionSlot();
	void setupForm_scene();


private slots:
	void build();
	void reset();
	void sceneset();
	void onCheckChanged();
	void onTypeChanged();

signals:
	void buildSignal();
	void setupSceneSignal();
	void tabSignal(int);
};
