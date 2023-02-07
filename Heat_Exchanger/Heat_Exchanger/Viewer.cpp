#include "Viewer.h"


Viewer::Viewer(QWidget* parent) : QtVision::QtOpenGLSceneWidget(parent)
{

	rootSceneSegment = this->sceneContent()->GetRootSegment();
	Q_ASSERT(rootSceneSegment != nullptr);

	QtVision::createProcessesCameraControls(this);

	prepareSceneBackground();
	prepareSectionPlane();
}

Viewer::~Viewer()
{
}



NodeKeyVector Viewer::addMathGeoms(MbModel* model, VSN::SceneSegment* sceneSegment)
{
	if (!sceneSegment) sceneSegment = rootSceneSegment;

	NodeKeyVector keys;
	RPArray<MbItem> subitems;
	SArray<MbMatrix3D> matrs;
	model->GetItems(MbeSpaceType::st_SpaceItem, subitems, matrs);

    //two ways to add model to view
	for (int i = 0; i < subitems.size(); i++) {
		NodeKeyVector subkeys = addMathGeoms(subitems[i], sceneSegment, matrs[i]);
		keys.insert(keys.cend(), subkeys.cbegin(), subkeys.cend());
	}

	updHideElements();
	return keys;
}

NodeKeyVector Viewer::addMathGeoms(MbItem * item,  VSN::SceneSegment * sceneSegment , MbMatrix3D matrix )
{

	if (!sceneSegment) sceneSegment = rootSceneSegment;

	NodeKeyVector keys;

	if (item->Type() == MbeSpaceType::st_Assembly) {
		//���������� ������ �� ��������� ��������, �� MbAssembly ������������ ����������
		RPArray<MbItem> subitems;
		SArray<MbMatrix3D> matrs;
		MbMatrix3D matrFrom;
		item->GetMatrixFrom(matrFrom);
		item->GetItems(MbeSpaceType::st_Item, matrFrom, subitems, matrs);

		for (int i = 0; i < subitems.size(); i++) {
			NodeKeyVector subkeys = addMathGeoms(subitems[i], sceneSegment, matrs[i].Transform(matrix));
			keys.insert(keys.cend(), subkeys.cbegin(), subkeys.cend());
		}
	}
	else {
		item->Transform(matrix);
		SceneSegment* segSinSurface = new SceneSegment(GeometryFactory::Instance()->CreateMathRep(item, CommandType::Synchronous), sceneSegment);
		//SceneSegment* segSinSurface = new SceneSegment(GeometryFactory::Instance()->CreateMathRep(item, CommandType::Synchronous), sceneSegment);
		segSinSurface->SetObjectName(VSN::String(item->GetItemName()));
		checkHideElement(segSinSurface);
		keys.push_back(segSinSurface->GetUniqueKey());
	}

	return keys;
}

void Viewer::clearScene()
{
	this->sceneContent()->Clear();
	this->update();
}

void Viewer::setSceneParams(SceneParams params)
{
	sceneParams = params;
	prepareSceneBackground();
	updHideElements();
	updSectionState();
	this->update();
}

void Viewer::fitSceneSlot()
{
	this->sceneContent()->GetContainer()->SetUseVertexBufferObjects(true);
	this->viewport()->GetCamera()->SetViewOrientation(orientation);
	this->ZoomToFit();
	this->update();
}

void Viewer::nextOrientationSlot()
{
	int val = int(orientation) - 1;
	if (val < 0 || val > 6) val = 6;
	orientation = VSN::Orientation(val);
	this->fitSceneSlot();
}

void Viewer::changeSectionPlaneSlot()
{
	
	if (auto tool = graphicsScene()->GetCuttingTool()) {
		if (tool->IsEnabled(m_sectionPlaneIdArr[sectionId])) {

			tool->SetEnable(m_sectionPlaneIdArr[sectionId], false);
			if (sectionId == 2)
				sectionId = 0;
			else
				sectionId++;
			tool->SetEnable(m_sectionPlaneIdArr[sectionId], true);
			sceneParams.plain = sectionId;
			this->update();
			
		}
	}
}

void Viewer::prepareSceneBackground()
{
	this->graphicsView()->SetRenderMode(sceneParams.edges ? RenderMode::rm_ShadedWithEdges : RenderMode::rm_Shaded);
	this->mainLight()->SetType((Light::LightTypes)(sceneParams.lightType));
	this->viewport()->SetGradientBackgroundColour(Color(255, 255, 255), Color(255, 255, 255));
}

void Viewer::prepareSectionPlane()
{
	if (auto tool = graphicsScene()->GetCuttingTool()) {
		m_sectionPlaneIdArr[0] = tool->AddSectionPlane(MbPlacement3D(
			MbCartPoint3D(1, 0, 0),
			MbCartPoint3D(0, 0, 1),
			MbCartPoint3D(0, 0, 0)
		));
		tool->SetEnable(m_sectionPlaneIdArr[1], false);
		m_sectionPlaneIdArr[1] = tool->AddSectionPlane(MbPlacement3D(
			MbCartPoint3D(0, 0, 1),
			MbCartPoint3D(0, 1, 0),
			MbCartPoint3D(0, 0, 0)
		));
		tool->SetEnable(m_sectionPlaneIdArr[1], false);
		m_sectionPlaneIdArr[2] = tool->AddSectionPlane(MbPlacement3D(
			MbCartPoint3D(0, 1, 0),
			MbCartPoint3D(1, 0, 0),
			MbCartPoint3D(0, 0, 0)
		));
		tool->SetEnable(m_sectionPlaneIdArr[2], false);
	}
}

void Viewer::updSectionState()
{
	if (auto tool = graphicsScene()->GetCuttingTool()) {
		if (tool->IsEnabled(m_sectionPlaneIdArr[sectionId]) != sceneParams.section) {
			tool->SetEnable(m_sectionPlaneIdArr[sectionId], sceneParams.section);
		}
		else
		{
			tool->SetEnable(m_sectionPlaneIdArr[sectionId], false);
			sectionId = sceneParams.plain;
			tool->SetEnable(m_sectionPlaneIdArr[sectionId], sceneParams.section);
		}
	}

}

void Viewer::updHideElements()
{
	auto segments = this->sceneContent()->GetSegments();
	for (auto seg : segments) {
		checkHideElement(seg);
	}
}

void Viewer::checkHideElement(VSN::SceneSegment* seg)
{
	auto sObjName = seg->GetObjectName();

	if (sObjName == VSN::String(SimpleName(sceneParams.hideIndexes[0]))) {
		std::set<Material*> set = seg->GetMaterials();
		Q_ASSERT(set.size() == 1);
		std::set<Material*>::iterator it = set.begin();
		Q_ASSERT(it != set.end());
		VSN::Material* m_pMaterial = *it;

		double value = static_cast<double>(10) / 100;
		m_pMaterial->SetOpacity(value);
	}
}
