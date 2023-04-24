#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;



MbAssembly* ParametricModelCreator::CreateHeatExchangerHPGAssembly(BuildParams params)
{
    ParametricModelCreator a;
    MbPlacement3D lcs;
    vector<SPtr<MbInstance>> pair;


    SPtr<MbSolid> mSTubeBundles = TubeBundles(params);
    mSTubeBundles->SetColor(190, 190, 190);
    InstanceSPtr iPTubeBundles(new MbInstance(*mSTubeBundles, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPTubeBundles(new MbInstance(*iPTubeBundles, lcs));
    pair.push_back(p_IPTubeBundles);

    SPtr<MbSolid> mSHeat_Exchanger_Supports = Heat_Exchanger_Supports(params);
    mSHeat_Exchanger_Supports->SetColor(190, 190, 190);
    InstanceSPtr iPHeat_Exchanger_Supports(new MbInstance(*mSHeat_Exchanger_Supports, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPHeat_Exchanger_Supports(new MbInstance(*iPHeat_Exchanger_Supports, lcs));
    pair.push_back(p_IPHeat_Exchanger_Supports);

    SPtr<MbSolid> mSHeat_Exchanger_Supports1 = Heat_Exchanger_Supports(params);
    mSHeat_Exchanger_Supports1->SetColor(190, 190, 190);
    InstanceSPtr iPHeat_Exchanger_Supports1(new MbInstance(*mSHeat_Exchanger_Supports1, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPHeat_Exchanger_Supports1(new MbInstance(*iPHeat_Exchanger_Supports1, lcs));
    pair.push_back(p_IPHeat_Exchanger_Supports1);


    /*-------------------------------------------------------------------------*/
	SPtr<MbSolid> mSСasing = Casing(params);
	mSСasing->SetColor(190, 190, 190);
    SPtr<MbSolid> mSDistribution_Chamber = Distribution_Chamber(params);
    mSDistribution_Chamber->SetColor(190, 190, 190);
    SPtr<MbSolid> mSDistribution_Chamber_Cover = Distribution_Chamber_Cover(params);
    mSDistribution_Chamber_Cover->SetColor(190, 190, 190);
    SPtr<MbSolid> mSСasing_Cover = Casing_Cover(params);
    mSСasing_Cover->SetColor(190, 190, 190);

    SPtr<MbSolid> mSHalf_Ring = Half_Ring(params);
    mSHalf_Ring->SetColor(190, 190, 190);
    SPtr<MbSolid> mSFloating_Head_Cover = Floating_Head_Cover(params);
    mSFloating_Head_Cover->SetColor(190, 190, 190);
    SPtr<MbSolid> mSStationary_Tube_Sheet = Stationary_Tube_Sheet(params);
    mSStationary_Tube_Sheet->SetColor(190, 190, 190);

    SPtr<MbSolid> mSGasket_Casing_Cover = Gasket_Casing_Cover(params);
    mSGasket_Casing_Cover->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Chamber_Casing = Gasket_Chamber_Casing(params);
    mSGasket_Chamber_Casing->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Chamber_Casing1 = Gasket_Chamber_Casing(params);
    mSGasket_Chamber_Casing1->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Cover_Chamber = Gasket_Cover_Chamber(params);
    mSGasket_Cover_Chamber->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Floating_Head = Gasket_Floating_Head(params);
    mSGasket_Floating_Head->SetColor(0, 0, 0);



    /*-------------------------------------------------------------------------*/

    InstanceSPtr iPСasing(new MbInstance(*mSСasing, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPDistribution_Chamber(new MbInstance(*mSDistribution_Chamber, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPDistribution_Chamber_Cover(new MbInstance(*mSDistribution_Chamber_Cover, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPСasing_Cover(new MbInstance(*mSСasing_Cover, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));

    InstanceSPtr iPHalf_Ring(new MbInstance(*mSHalf_Ring, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPFloating_Head_Cover(new MbInstance(*mSFloating_Head_Cover, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPGasket_Casing_Cover(new MbInstance(*mSGasket_Casing_Cover, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPGasket_Chamber_Casing(new MbInstance(*mSGasket_Chamber_Casing, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPGasket_Chamber_Casing1(new MbInstance(*mSGasket_Chamber_Casing1, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPGasket_Cover_Chamber(new MbInstance(*mSGasket_Cover_Chamber, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPGasket_Floating_Head(new MbInstance(*mSGasket_Floating_Head, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr iPStationary_Tube_Sheet(new MbInstance(*mSStationary_Tube_Sheet, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));

    /*-------------------------------------------------------------------------*/

    SPtr<MbInstance> p_IPСasing(new MbInstance(*iPСasing, lcs));
    SPtr<MbInstance> p_IPDistribution_Chamber(new MbInstance(*iPDistribution_Chamber, lcs));
    SPtr<MbInstance> p_IPDistribution_Chamber_Cover(new MbInstance(*iPDistribution_Chamber_Cover, lcs));
    SPtr<MbInstance> p_IPСasing_Cover(new MbInstance(*iPСasing_Cover, lcs));

    SPtr<MbInstance> p_IPHalf_Ring(new MbInstance(*iPHalf_Ring, lcs));
    SPtr<MbInstance> p_IPFloating_Head_Cover(new MbInstance(*iPFloating_Head_Cover, lcs));
    SPtr<MbInstance> p_IPGasket_Casing_Cover(new MbInstance(*iPGasket_Casing_Cover, lcs));
    SPtr<MbInstance> p_IPGasket_Chamber_Casing(new MbInstance(*iPGasket_Chamber_Casing, lcs));
    SPtr<MbInstance> p_IPGasket_Chamber_Casing1(new MbInstance(*iPGasket_Chamber_Casing1, lcs));
    SPtr<MbInstance> p_IPGasket_Cover_Chamber(new MbInstance(*iPGasket_Cover_Chamber, lcs));
    SPtr<MbInstance> p_IPGasket_Floating_Head(new MbInstance(*iPGasket_Floating_Head, lcs));
    SPtr<MbInstance> p_IPStationary_Tube_Sheet(new MbInstance(*iPStationary_Tube_Sheet, lcs));

    /*-------------------------------------------------------------------------*/

    pair.push_back(p_IPСasing);
    pair.push_back(p_IPDistribution_Chamber);
    pair.push_back(p_IPDistribution_Chamber_Cover);
    pair.push_back(p_IPСasing_Cover);
    pair.push_back(p_IPGasket_Casing_Cover);
    pair.push_back(p_IPGasket_Chamber_Casing);
    pair.push_back(p_IPGasket_Chamber_Casing1);
    pair.push_back(p_IPGasket_Cover_Chamber);
    pair.push_back(p_IPStationary_Tube_Sheet);

    //pair.push_back(p_IPHalf_Ring);
    //pair.push_back(p_IPFloating_Head_Cover);
    //pair.push_back(p_IPGasket_Floating_Head);
   

    BuildMathModel::Faces f = a.getParams_model();
    MbAssembly* assm = new MbAssembly(pair);

    assm->SetPlacement(lcs);
    MtGeomArgument ChamberGa(mSDistribution_Chamber->GetFace(11), p_IPDistribution_Chamber);
    MtGeomArgument GasketCh(mSGasket_Cover_Chamber->GetFace(0), p_IPGasket_Cover_Chamber);
    assm->AddConstraint(GCM_DISTANCE, ChamberGa, GasketCh, 0);

    MtGeomArgument CoverGa(mSDistribution_Chamber_Cover->GetFace(0), p_IPDistribution_Chamber_Cover);
    MtGeomArgument GasketCo(mSGasket_Cover_Chamber->GetFace(2), p_IPGasket_Cover_Chamber);
    assm->AddConstraint(GCM_DISTANCE, CoverGa, GasketCo, 0);

    MtGeomArgument ChamberGaR(mSDistribution_Chamber->GetFace(12), p_IPDistribution_Chamber);
    MtGeomArgument GasketChR(mSGasket_Chamber_Casing->GetFace(2), p_IPGasket_Chamber_Casing);
    assm->AddConstraint(GCM_DISTANCE, ChamberGaR, GasketChR, 0);

    MtGeomArgument SheetGaCh(mSStationary_Tube_Sheet->GetFace(74), p_IPStationary_Tube_Sheet);
    MtGeomArgument GasketRCh(mSGasket_Chamber_Casing->GetFace(0), p_IPGasket_Chamber_Casing);
    assm->AddConstraint(GCM_DISTANCE, SheetGaCh, GasketRCh, 0);

    MtGeomArgument CasingGaR(mSСasing->GetFace(7), p_IPСasing);
    MtGeomArgument GasketCaR(mSGasket_Chamber_Casing1->GetFace(0), p_IPGasket_Chamber_Casing1);
    assm->AddConstraint(GCM_DISTANCE, CasingGaR, GasketCaR, 0);

    MtGeomArgument SheetGaCa(mSStationary_Tube_Sheet->GetFace(75), p_IPStationary_Tube_Sheet);
    MtGeomArgument GasketRCa(mSGasket_Chamber_Casing1->GetFace(2), p_IPGasket_Chamber_Casing1);
    assm->AddConstraint(GCM_DISTANCE, SheetGaCa, GasketRCa, 0);

    MtGeomArgument CasingGaCo(mSСasing->GetFace(6), p_IPСasing);
    MtGeomArgument GasketCaCo(mSGasket_Casing_Cover->GetFace(2), p_IPGasket_Casing_Cover);
    assm->AddConstraint(GCM_DISTANCE, CasingGaCo, GasketCaCo, 0);

    MtGeomArgument CoverGaCa(mSСasing_Cover->GetFace(6), p_IPСasing_Cover);
    MtGeomArgument GasketCoCa(mSGasket_Casing_Cover->GetFace(0), p_IPGasket_Casing_Cover);
    assm->AddConstraint(GCM_DISTANCE, CoverGaCa, GasketCoCa, 0);

    MtGeomArgument TubeG(mSTubeBundles->GetFace(273), p_IPTubeBundles);
    MtGeomArgument TubeRG(mSStationary_Tube_Sheet->GetFace(0), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, TubeG, TubeRG, -params.l.toDouble());
    assm->EvaluateConstraints();

    MtGeomArgument Tube(mSTubeBundles->GetFace(203), p_IPTubeBundles);
    MtGeomArgument TubeR(mSStationary_Tube_Sheet->GetFace(36), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_CONCENTRIC, Tube, TubeR);
    assm->EvaluateConstraints();

   /* MtGeomArgument Tube1(mSTubeBundles->GetFace(139), p_IPTubeBundles);
    MtGeomArgument TubeR1(mSStationary_Tube_Sheet->GetFace(20), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_CONCENTRIC, Tube1, TubeR1, 0);*/

    

    assm->EvaluateConstraints();
	return assm;
}

MbAssembly* ParametricModelCreator::CreateHeatExchangerKPAssembly(BuildParams params)
{
    SPtr<MbSolid> Kozh = Casing_KP(params);
    Kozh->SetColor(190, 190, 190);
    SPtr<MbSolid> Kam = Distribution_Chamber_KP(params);
    Kam->SetColor(190, 190, 190);
    SPtr<MbSolid> KKam = Distribution_Chamber_Cover_KP(params);
    KKam->SetColor(190, 190, 190);
    SPtr<MbSolid> KKozh = Casing_Cover_KP(params);
    KKozh->SetColor(190, 190, 190);


    /*-------------------------------------------------------------------------*/

    MbPlacement3D lcs;
    InstanceSPtr Kozhu(new MbInstance(*Kozh, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr Kame(new MbInstance(*Kam, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr KKozhu(new MbInstance(*KKozh, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr KKame(new MbInstance(*KKam, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));

    /*-------------------------------------------------------------------------*/

    SPtr<MbInstance> KozhuComp(new MbInstance(*Kozhu, lcs));
    SPtr<MbInstance> KameComp(new MbInstance(*Kame, lcs));
    SPtr<MbInstance> KKozhuComp(new MbInstance(*KKozhu, lcs));
    SPtr<MbInstance> KKameComp(new MbInstance(*KKame, lcs));

    /*-------------------------------------------------------------------------*/

    vector<SPtr<MbInstance>> pair;
    pair.push_back(KozhuComp);
    pair.push_back(KameComp);
    pair.push_back(KKozhuComp);
    pair.push_back(KKameComp);


    MbAssembly* assm = new MbAssembly(pair);


    MtGeomArgument Casing(Kozh->GetFace(7), KozhuComp);
    MtGeomArgument Cover(KKozh->GetFace(6), KKozhuComp);
    assm->AddConstraint(GCM_DISTANCE, Casing, Cover, 0);

    MtGeomArgument Chamber(Kam->GetFace(22), KameComp);
    MtGeomArgument Casing1(Kozh->GetFace(23), KozhuComp);
    assm->AddConstraint(GCM_DISTANCE, Chamber, Casing1, 0);

    MtGeomArgument Cover1(KKam->GetFace(6), KKameComp);
    MtGeomArgument Chamber1(Kam->GetFace(9), KameComp);
    assm->AddConstraint(GCM_DISTANCE, Chamber1, Cover1, 0);


    assm->EvaluateConstraints();
    return assm;
}

MbAssembly* ParametricModelCreator::CreateHeatExchangerTUAssembly(BuildParams params)
{
    SPtr<MbSolid> Kozh = CasingTY(params.diam.toDouble(), params.length.toDouble());
    Kozh->SetColor(190, 190, 190);
    SPtr<MbSolid> Kam = Distribution_ChamberTY(params.length.toDouble());
    Kam->SetColor(190, 190, 190);



    /*-------------------------------------------------------------------------*/

    MbPlacement3D lcs;
    InstanceSPtr Kozhu(new MbInstance(*Kozh, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr Kame(new MbInstance(*Kam, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));


    /*-------------------------------------------------------------------------*/

    SPtr<MbInstance> KozhuComp(new MbInstance(*Kozhu, lcs));
    SPtr<MbInstance> KameComp(new MbInstance(*Kame, lcs));


    /*-------------------------------------------------------------------------*/

    vector<SPtr<MbInstance>> pair;
    pair.push_back(KozhuComp);
    pair.push_back(KameComp);


    MbAssembly* assm = new MbAssembly(pair);
    return assm;
}
