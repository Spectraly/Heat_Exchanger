#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	unsetCurrentModel();
	fileController.setParentWidget(this);

	viewer = ui.widget_viewer;
	paramsWidget = ui.widget_params;

	//запуск создания сцены
	connect(paramsWidget, &ParamsWidget::buildSignal, this, &MainWindow::makeExchangerMathModelSlot);
	connect(paramsWidget, &ParamsWidget::setupSceneSignal, this, &MainWindow::setupViewerSceneSlot);
	connect(paramsWidget, SIGNAL(tabSignal(int i)), this, SLOT(changeTab(int i)));
	connect(ui.action_build_heatex, &QAction::triggered, this, &MainWindow::makeExchangerMathModelSlot);
	connect(ui.action_clear, &QAction::triggered, this, &MainWindow::clearModelSlot);

	connect(ui.action_about, &QAction::triggered, this, &MainWindow::aboutSlot);
	connect(ui.action_aboutqt, &QAction::triggered, this, &MainWindow::aboutQtSlot);

	connect(ui.action_centralyze, &QAction::triggered, viewer, &Viewer::fitSceneSlot);
	connect(ui.action_nextOrientation, &QAction::triggered, viewer, &Viewer::nextOrientationSlot);
	connect(ui.action_changeSectionPlane, &QAction::triggered, viewer, &Viewer::changeSectionPlaneSlot);
	connect(ui.action_changeSectionPlane, &QAction::triggered, paramsWidget, &ParamsWidget::setupForm_scene);
	connect(ui.action_section, &QAction::triggered, paramsWidget, &ParamsWidget::toggleViewSectionSlot);


	connect(ui.action_params, &QAction::triggered, this, &MainWindow::showParamsSlot);

	connect(ui.action_save, &QAction::triggered, this, &MainWindow::saveFileSlot);

}

MainWindow::~MainWindow()
{
	::DeleteMatItem(currentMathModel);
}

void MainWindow::drawMathModel(bool fit)
{
	viewer->clearScene();
	if (currentMathModel) viewer->addMathGeoms(currentMathModel);
	if (fit)viewer->fitSceneSlot();
}

void MainWindow::makeExchangerMathModelSlot()
{
	BuildMathModel::BuildParams modelParams = paramsWidget->getParams_model();
	MbModel* cylModel = BuildMathModel::ParametricModelCreator::CreateHeatExchangerModel(modelParams);
	setCurrentModel(cylModel);
}

void MainWindow::setupViewerSceneSlot()
{
	SceneParams sceneParams = paramsWidget->getParams_scene();
	viewer->setSceneParams(sceneParams);
}

void MainWindow::clearModelSlot()
{
	viewer->clearScene();
	unsetCurrentModel();
}

void MainWindow::setCurrentModel(MbModel* model)
{
	unsetCurrentModel();
	if (model) currentMathModel = model;
	drawMathModel();

}

void MainWindow::unsetCurrentModel()
{
	::DeleteMatItem(currentMathModel);
}

void MainWindow::aboutSlot()
{
	const QString GitRepo("https://github.com/Spectraly/Heat_Exchanger");
	QString str;
	str += "<h3>" + QApplication::applicationName() + "</h3>";
	str += u8"<p>Приложение-конфигуратор параметрической модели типовых теплообменных апаратов типа ХПГ КП ТУ< / p><br/>";
	str += u8"На базе <a href=\"https://c3dlabs.com/ru/products/c3d-toolkit/\">C3D Toolkit</a> , Vision 2.6.4.6<br/>";
	str += u8"Подробнее на странице GitHub <a href=\"" + GitRepo + u8"\">репозитория</a><br/>";
	str += u8"Версия: " + QApplication::applicationVersion() + "<hr/>";
	str += u8"Создано в рамках курсового проекта";
	QMessageBox::about(this, "About", str);
}

void MainWindow::aboutQtSlot()
{
	QMessageBox::aboutQt(this);
}

void MainWindow::showParamsSlot()
{
	ui.dockWidget_params->setVisible(!ui.dockWidget_params->isVisible());
}

void MainWindow::saveFileSlot()
{
	//QMessageBox::warning(this, u8"Внимание", u8"Модель не экспортирована,постройте модель");
	fileController.saveModel(currentMathModel);
	//drawMathModel();-------------------------------------
	makeExchangerMathModelSlot();
}

void MainWindow::changeTab(int tab)
{
	
	QMessageBox::warning(this, u8"Внимание", (QString)tab);

}
