#include "FileController.h"

FileController::FileController(QWidget* parent)
{
	setParentWidget(parent);
}

FileController::~FileController()
{
}

void FileController::setParentWidget(QWidget* parent)
{
	parentWidget = parent;
}

c3d::path_string FileController::getFilePath(bool save)
{
	const QString defaultPath = "D:/C3D_files/MyModel.c3d";
	const QString fileFilter = "Geometric models (*.c3d *.stp *.step *.STEP *.IGES *.SAT *.X_T *.X_B *.STL *.VRML *.JT)";
	QString fileName = save
		? QFileDialog::getSaveFileName(parentWidget, u8"Сохранить в файл", defaultPath, fileFilter)
		: QFileDialog::getOpenFileName(parentWidget, u8"Открыть из файла", defaultPath, fileFilter);
	fileName.replace("/", "\\");
	fileName.replace(":", ":\\");
	c3d::path_string path = c3d::StdToPathstring(fileName.toStdString());
	return path;
}

void FileController::exportCurrentModel(c3d::path_string path, MbModel* ptrModel)
{
	if (ptrModel) {
		MbeConvResType exportRes = c3d::ExportIntoFile(*ptrModel, path);
		if (exportRes != MbeConvResType::cnv_Success)
			QMessageBox::information(parentWidget, u8"Предупреждение", u8"Ошибка сохранения");
	}
	else {
		QMessageBox::information(parentWidget, u8"Предупреждение", u8"Нечего сохранять");
	}
}

void FileController::saveModel(MbModel* ptrModel)
{
	c3d::path_string path = getFilePath();
	if (!path.empty()) exportCurrentModel(path, ptrModel);
}
