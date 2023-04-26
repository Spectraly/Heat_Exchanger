#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;



MbAssembly* ParametricModelCreator::CreateHeatExchangerHPGAssembly(BuildParams params)
{
    ParametricModelCreator objFaces;
    MbPlacement3D lcs;
    vector<SPtr<MbInstance>> pair;


    SPtr<MbSolid> mSStationary_Tube_Sheet = Stationary_Tube_Sheet_HPG(params);
    mSStationary_Tube_Sheet->SetColor(190, 190, 190);
    InstanceSPtr iPStationary_Tube_Sheet(new MbInstance(*mSStationary_Tube_Sheet, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPStationary_Tube_Sheet(new MbInstance(*iPStationary_Tube_Sheet, lcs));

    SPtr<MbSolid> mSMovable_Tube_Sheet = Movable_Tube_Sheet_HPG(params);
    mSMovable_Tube_Sheet->SetColor(190, 190, 190);
    InstanceSPtr iPMovable_Tube_Sheet(new MbInstance(*mSMovable_Tube_Sheet, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPMovable_Tube_Sheet(new MbInstance(*iPMovable_Tube_Sheet, lcs));

    BuildMathModel::Faces faces = objFaces.getParamsStationary_model();


    SPtr<MbSolid> mSTubeBundles = TubeBundles(params);
    mSTubeBundles->SetColor(190, 190, 190);
    InstanceSPtr iPTubeBundles(new MbInstance(*mSTubeBundles, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPTubeBundles(new MbInstance(*iPTubeBundles, lcs));

    SPtr<MbSolid> mSHeat_Exchanger_Supports = Heat_Exchanger_Supports(params);
    mSHeat_Exchanger_Supports->SetColor(190, 190, 190);
    InstanceSPtr iPHeat_Exchanger_Supports(new MbInstance(*mSHeat_Exchanger_Supports, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPHeat_Exchanger_Supports(new MbInstance(*iPHeat_Exchanger_Supports, lcs));

    SPtr<MbSolid> mSHeat_Exchanger_Supports1 = Heat_Exchanger_Supports(params);
    mSHeat_Exchanger_Supports1->SetColor(190, 190, 190);
    InstanceSPtr iPHeat_Exchanger_Supports1(new MbInstance(*mSHeat_Exchanger_Supports1, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPHeat_Exchanger_Supports1(new MbInstance(*iPHeat_Exchanger_Supports1, lcs));


    /*-------------------------------------------------------------------------*/
	SPtr<MbSolid> mSСasing = Casing_HPG(params);
	mSСasing->SetColor(190, 190, 190);
    SPtr<MbSolid> mSDistribution_Chamber = Distribution_Chamber_HPG(params);
    mSDistribution_Chamber->SetColor(190, 190, 190);
    SPtr<MbSolid> mSDistribution_Chamber_Cover = Distribution_Chamber_Cover_HPG(params);
    mSDistribution_Chamber_Cover->SetColor(190, 190, 190);
    SPtr<MbSolid> mSСasing_Cover = Casing_Cover_HPG(params);
    mSСasing_Cover->SetColor(190, 190, 190);


    SPtr<MbSolid> mSHalf_Ring = Half_Ring_HPG(params);
    mSHalf_Ring->SetColor(190, 190, 190);
    SPtr<MbSolid> mSFloating_Head_Cover = Floating_Head_Cover_HPG(params);
    mSFloating_Head_Cover->SetColor(190, 190, 190);


    SPtr<MbSolid> mSGasket_Casing_Cover = Gasket_Casing_Cover_HPG(params);
    mSGasket_Casing_Cover->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Chamber_Casing = Gasket_Chamber_Casing_HPG(params);
    mSGasket_Chamber_Casing->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Chamber_Casing1 = Gasket_Chamber_Casing_HPG(params);
    mSGasket_Chamber_Casing1->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Cover_Chamber = Gasket_Cover_Chamber_HPG(params);
    mSGasket_Cover_Chamber->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Floating_Head = Gasket_Floating_Head_HPG(params);
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


    /*-------------------------------------------------------------------------*/

    pair.push_back(p_IPTubeBundles);
    pair.push_back(p_IPHeat_Exchanger_Supports);
    pair.push_back(p_IPHeat_Exchanger_Supports1);

    pair.push_back(p_IPСasing);
    pair.push_back(p_IPDistribution_Chamber);
    pair.push_back(p_IPDistribution_Chamber_Cover);
    pair.push_back(p_IPСasing_Cover);
    pair.push_back(p_IPGasket_Casing_Cover);
    pair.push_back(p_IPGasket_Chamber_Casing);
    pair.push_back(p_IPGasket_Chamber_Casing1);
    pair.push_back(p_IPGasket_Cover_Chamber);
    pair.push_back(p_IPStationary_Tube_Sheet);

    pair.push_back(p_IPMovable_Tube_Sheet);
    pair.push_back(p_IPHalf_Ring);
    pair.push_back(p_IPFloating_Head_Cover);
    pair.push_back(p_IPGasket_Floating_Head);
   



    MbAssembly* assm = new MbAssembly(pair);
    assm->SetPlacement(lcs);    

    MtGeomArgument ChamberGa(mSDistribution_Chamber->GetFace(11), p_IPDistribution_Chamber);
    MtGeomArgument GasketCh(mSGasket_Cover_Chamber->GetFace(0), p_IPGasket_Cover_Chamber);
    assm->AddConstraint(GCM_DISTANCE, ChamberGa, GasketCh, 0);
    assm->EvaluateConstraints();

    MtGeomArgument CoverGa(mSDistribution_Chamber_Cover->GetFace(0), p_IPDistribution_Chamber_Cover);
    MtGeomArgument GasketCo(mSGasket_Cover_Chamber->GetFace(2), p_IPGasket_Cover_Chamber);
    assm->AddConstraint(GCM_DISTANCE, CoverGa, GasketCo, 0);
    assm->EvaluateConstraints();

    MtGeomArgument ChamberGaR(mSDistribution_Chamber->GetFace(12), p_IPDistribution_Chamber);
    MtGeomArgument GasketChR(mSGasket_Chamber_Casing->GetFace(2), p_IPGasket_Chamber_Casing);
    assm->AddConstraint(GCM_DISTANCE, ChamberGaR, GasketChR, 0);
    assm->EvaluateConstraints();

    MtGeomArgument SheetGaCh(mSStationary_Tube_Sheet->GetFace(4), p_IPStationary_Tube_Sheet);
    MtGeomArgument GasketRCh(mSGasket_Chamber_Casing->GetFace(0), p_IPGasket_Chamber_Casing);
    assm->AddConstraint(GCM_DISTANCE, SheetGaCh, GasketRCh, 0);
    assm->EvaluateConstraints();

    MtGeomArgument CasingGaR(mSСasing->GetFace(7), p_IPСasing);
    MtGeomArgument GasketCaR(mSGasket_Chamber_Casing1->GetFace(0), p_IPGasket_Chamber_Casing1);
    assm->AddConstraint(GCM_DISTANCE, CasingGaR, GasketCaR, 0);
    assm->EvaluateConstraints();

    MtGeomArgument SheetGaCa(mSStationary_Tube_Sheet->GetFace(5), p_IPStationary_Tube_Sheet);
    MtGeomArgument GasketRCa(mSGasket_Chamber_Casing1->GetFace(2), p_IPGasket_Chamber_Casing1);
    assm->AddConstraint(GCM_DISTANCE, SheetGaCa, GasketRCa, 0);
    assm->EvaluateConstraints();

    MtGeomArgument CasingGaCo(mSСasing->GetFace(6), p_IPСasing);
    MtGeomArgument GasketCaCo(mSGasket_Casing_Cover->GetFace(2), p_IPGasket_Casing_Cover);
    assm->AddConstraint(GCM_DISTANCE, CasingGaCo, GasketCaCo, 0);
    assm->EvaluateConstraints();

    MtGeomArgument CoverGaCa(mSСasing_Cover->GetFace(6), p_IPСasing_Cover);
    MtGeomArgument GasketCoCa(mSGasket_Casing_Cover->GetFace(0), p_IPGasket_Casing_Cover);
    assm->AddConstraint(GCM_DISTANCE, CoverGaCa, GasketCoCa, 0);
    assm->EvaluateConstraints();

    MtGeomArgument Tube(mSTubeBundles->GetFace(0), p_IPTubeBundles);
    MtGeomArgument TubeR(mSStationary_Tube_Sheet->GetFace(0), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, Tube, TubeR, -params.l.toDouble());
    assm->EvaluateConstraints();

    MtGeomArgument Tube1(mSTubeBundles->GetFace(7), p_IPTubeBundles);
    MtGeomArgument TubeR1(mSStationary_Tube_Sheet->GetFace(11), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_CONCENTRIC, Tube1, TubeR1);
    assm->EvaluateConstraints();

    MtGeomArgument TubeM1(mSTubeBundles->GetFace(1), p_IPTubeBundles);
    MtGeomArgument TubeMR1(mSMovable_Tube_Sheet->GetFace(1), p_IPMovable_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, TubeM1, TubeMR1, -params.l.toDouble());
    assm->EvaluateConstraints();

    MtGeomArgument FloatR(mSHalf_Ring->GetFace(1), p_IPHalf_Ring);
    MtGeomArgument FloatM(mSMovable_Tube_Sheet->GetFace(4), p_IPMovable_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, FloatR, FloatM, 0);
    assm->EvaluateConstraints();

    MtGeomArgument FloatM1(mSMovable_Tube_Sheet->GetFace(5), p_IPMovable_Tube_Sheet);
    MtGeomArgument FloatGa(mSGasket_Floating_Head->GetFace(2), p_IPGasket_Floating_Head);
    assm->AddConstraint(GCM_DISTANCE, FloatM1, FloatGa, 0);
    assm->EvaluateConstraints();

    MtGeomArgument FloatGa1(mSGasket_Floating_Head->GetFace(0), p_IPGasket_Floating_Head);
    MtGeomArgument FloatC(mSFloating_Head_Cover->GetFace(5), p_IPFloating_Head_Cover);
    assm->AddConstraint(GCM_DISTANCE, FloatGa1, FloatC,0);
    assm->EvaluateConstraints();

    MtGeomArgument Supports(mSHeat_Exchanger_Supports->GetFace(5), p_IPHeat_Exchanger_Supports);
    MtGeomArgument SupportsC(mSСasing->GetFace(26), p_IPСasing);
    assm->AddConstraint(GCM_CONCENTRIC, Supports, SupportsC);
    assm->EvaluateConstraints();

    MtGeomArgument Supports1(mSHeat_Exchanger_Supports->GetFace(4), p_IPHeat_Exchanger_Supports);
    MtGeomArgument SupportsC1(mSСasing->GetFace(8), p_IPСasing);
    assm->AddConstraint(GCM_DISTANCE, Supports1, SupportsC1, -params.l2.toDouble() + params.Dy1.toDouble());
    assm->EvaluateConstraints();

    MtGeomArgument Supports2(mSHeat_Exchanger_Supports1->GetFace(5), p_IPHeat_Exchanger_Supports1);
    MtGeomArgument SupportsC2(mSСasing->GetFace(26), p_IPСasing);
    assm->AddConstraint(GCM_CONCENTRIC, Supports2, SupportsC2);
    assm->EvaluateConstraints();

    MtGeomArgument Supports31(mSHeat_Exchanger_Supports1->GetFace(4), p_IPHeat_Exchanger_Supports1);
    MtGeomArgument Supports3(mSHeat_Exchanger_Supports->GetFace(6), p_IPHeat_Exchanger_Supports);
    assm->AddConstraint(GCM_DISTANCE, Supports31, Supports3, -params.l0.toDouble());
    assm->EvaluateConstraints();   

	return assm;
}

MbAssembly* ParametricModelCreator::CreateHeatExchangerKPAssembly(BuildParams params)
{
    ParametricModelCreator objFaces;
    MbPlacement3D lcs;
    vector<SPtr<MbInstance>> pair;


    SPtr<MbSolid> mSStationary_Tube_Sheet = Stationary_Tube_Sheet_KP(params);
    mSStationary_Tube_Sheet->SetColor(190, 190, 190);
    InstanceSPtr iPStationary_Tube_Sheet(new MbInstance(*mSStationary_Tube_Sheet, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPStationary_Tube_Sheet(new MbInstance(*iPStationary_Tube_Sheet, lcs));

    SPtr<MbSolid> mSMovable_Tube_Sheet = Movable_Tube_Sheet_KP(params);
    mSMovable_Tube_Sheet->SetColor(190, 190, 190);
    InstanceSPtr iPMovable_Tube_Sheet(new MbInstance(*mSMovable_Tube_Sheet, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPMovable_Tube_Sheet(new MbInstance(*iPMovable_Tube_Sheet, lcs));

    //BuildMathModel::Faces faces = objFaces.getParamsStationary_model();


    SPtr<MbSolid> mSTubeBundles = TubeBundles(params);
    mSTubeBundles->SetColor(190, 190, 190);
    InstanceSPtr iPTubeBundles(new MbInstance(*mSTubeBundles, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPTubeBundles(new MbInstance(*iPTubeBundles, lcs));

    SPtr<MbSolid> mSHeat_Exchanger_Supports = Heat_Exchanger_Supports(params);
    mSHeat_Exchanger_Supports->SetColor(190, 190, 190);
    InstanceSPtr iPHeat_Exchanger_Supports(new MbInstance(*mSHeat_Exchanger_Supports, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPHeat_Exchanger_Supports(new MbInstance(*iPHeat_Exchanger_Supports, lcs));

    SPtr<MbSolid> mSHeat_Exchanger_Supports1 = Heat_Exchanger_Supports(params);
    mSHeat_Exchanger_Supports1->SetColor(190, 190, 190);
    InstanceSPtr iPHeat_Exchanger_Supports1(new MbInstance(*mSHeat_Exchanger_Supports1, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    SPtr<MbInstance> p_IPHeat_Exchanger_Supports1(new MbInstance(*iPHeat_Exchanger_Supports1, lcs));


    /*-------------------------------------------------------------------------*/
    SPtr<MbSolid> mSСasing = Casing_KP(params);
    mSСasing->SetColor(190, 190, 190);
    SPtr<MbSolid> mSDistribution_Chamber = Distribution_Chamber_KP(params);
    mSDistribution_Chamber->SetColor(190, 190, 190);
    SPtr<MbSolid> mSDistribution_Chamber_Cover = Distribution_Chamber_Cover_KP(params);
    mSDistribution_Chamber_Cover->SetColor(190, 190, 190);
    SPtr<MbSolid> mSСasing_Cover = Casing_Cover_KP(params);
    mSСasing_Cover->SetColor(190, 190, 190);

    SPtr<MbSolid> mSHalf_Ring = Half_Ring_KP(params);
    mSHalf_Ring->SetColor(190, 190, 190);
    SPtr<MbSolid> mSFloating_Head_Cover = Floating_Head_Cover_KP(params);
    mSFloating_Head_Cover->SetColor(190, 190, 190);


    SPtr<MbSolid> mSGasket_Casing_Cover = Gasket_Casing_Cover_KP(params);
    mSGasket_Casing_Cover->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Chamber_Casing = Gasket_Chamber_Casing_KP(params);
    mSGasket_Chamber_Casing->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Chamber_Casing1 = Gasket_Chamber_Casing_KP(params);
    mSGasket_Chamber_Casing1->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Cover_Chamber = Gasket_Cover_Chamber_KP(params);
    mSGasket_Cover_Chamber->SetColor(0, 0, 0);
    SPtr<MbSolid> mSGasket_Floating_Head = Gasket_Floating_Head_KP(params);
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


    /*-------------------------------------------------------------------------*/

    pair.push_back(p_IPTubeBundles);
    pair.push_back(p_IPHeat_Exchanger_Supports);
    pair.push_back(p_IPHeat_Exchanger_Supports1);

    pair.push_back(p_IPСasing);
    pair.push_back(p_IPDistribution_Chamber);
    pair.push_back(p_IPDistribution_Chamber_Cover);
    pair.push_back(p_IPСasing_Cover);
    pair.push_back(p_IPGasket_Casing_Cover);
    pair.push_back(p_IPGasket_Chamber_Casing);
    pair.push_back(p_IPGasket_Chamber_Casing1);
    pair.push_back(p_IPGasket_Cover_Chamber);
    pair.push_back(p_IPStationary_Tube_Sheet);
    pair.push_back(p_IPMovable_Tube_Sheet);
    pair.push_back(p_IPHalf_Ring);
    pair.push_back(p_IPFloating_Head_Cover);
    pair.push_back(p_IPGasket_Floating_Head);




    MbAssembly* assm = new MbAssembly(pair);
    assm->SetPlacement(lcs);

    MtGeomArgument ChamberGa(mSDistribution_Chamber->GetFace(11), p_IPDistribution_Chamber);
    MtGeomArgument GasketCh(mSGasket_Cover_Chamber->GetFace(0), p_IPGasket_Cover_Chamber);
    assm->AddConstraint(GCM_DISTANCE, ChamberGa, GasketCh, 0);
    assm->EvaluateConstraints();

    MtGeomArgument CoverGa(mSDistribution_Chamber_Cover->GetFace(0), p_IPDistribution_Chamber_Cover);
    MtGeomArgument GasketCo(mSGasket_Cover_Chamber->GetFace(2), p_IPGasket_Cover_Chamber);
    assm->AddConstraint(GCM_DISTANCE, CoverGa, GasketCo, 0);
    assm->EvaluateConstraints();

    MtGeomArgument ChamberGaR(mSDistribution_Chamber->GetFace(13), p_IPDistribution_Chamber);
    MtGeomArgument GasketChR(mSGasket_Chamber_Casing->GetFace(2), p_IPGasket_Chamber_Casing);
    assm->AddConstraint(GCM_DISTANCE, ChamberGaR, GasketChR, 0);
    assm->EvaluateConstraints();

    MtGeomArgument SheetGaCh(mSStationary_Tube_Sheet->GetFace(4), p_IPStationary_Tube_Sheet);
    MtGeomArgument GasketRCh(mSGasket_Chamber_Casing->GetFace(0), p_IPGasket_Chamber_Casing);
    assm->AddConstraint(GCM_DISTANCE, SheetGaCh, GasketRCh, 0);
    assm->EvaluateConstraints();

    MtGeomArgument CasingGaR(mSСasing->GetFace(7), p_IPСasing);
    MtGeomArgument GasketCaR(mSGasket_Chamber_Casing1->GetFace(0), p_IPGasket_Chamber_Casing1);
    assm->AddConstraint(GCM_DISTANCE, CasingGaR, GasketCaR, 0);
    assm->EvaluateConstraints();

    MtGeomArgument SheetGaCa(mSStationary_Tube_Sheet->GetFace(5), p_IPStationary_Tube_Sheet);
    MtGeomArgument GasketRCa(mSGasket_Chamber_Casing1->GetFace(2), p_IPGasket_Chamber_Casing1);
    assm->AddConstraint(GCM_DISTANCE, SheetGaCa, GasketRCa, 0);
    assm->EvaluateConstraints();

    MtGeomArgument CasingGaCo(mSСasing->GetFace(6), p_IPСasing);
    MtGeomArgument GasketCaCo(mSGasket_Casing_Cover->GetFace(2), p_IPGasket_Casing_Cover);
    assm->AddConstraint(GCM_DISTANCE, CasingGaCo, GasketCaCo, 0);
    assm->EvaluateConstraints();

    MtGeomArgument CoverGaCa(mSСasing_Cover->GetFace(6), p_IPСasing_Cover);
    MtGeomArgument GasketCoCa(mSGasket_Casing_Cover->GetFace(0), p_IPGasket_Casing_Cover);
    assm->AddConstraint(GCM_DISTANCE, CoverGaCa, GasketCoCa, 0);
    assm->EvaluateConstraints();

    MtGeomArgument Tube(mSTubeBundles->GetFace(0), p_IPTubeBundles);
    MtGeomArgument TubeR(mSStationary_Tube_Sheet->GetFace(0), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, Tube, TubeR, -params.l.toDouble());
    assm->EvaluateConstraints();

    MtGeomArgument Tube1(mSTubeBundles->GetFace(7), p_IPTubeBundles);
    MtGeomArgument TubeR1(mSStationary_Tube_Sheet->GetFace(11), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_CONCENTRIC, Tube1, TubeR1);
    assm->EvaluateConstraints();

    MtGeomArgument TubeM1(mSTubeBundles->GetFace(1), p_IPTubeBundles);
    MtGeomArgument TubeMR1(mSMovable_Tube_Sheet->GetFace(1), p_IPMovable_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, TubeM1, TubeMR1, -params.l.toDouble());
    assm->EvaluateConstraints();

    MtGeomArgument FloatR(mSHalf_Ring->GetFace(1), p_IPHalf_Ring);
    MtGeomArgument FloatM(mSMovable_Tube_Sheet->GetFace(4), p_IPMovable_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, FloatR, FloatM, 0);
    assm->EvaluateConstraints();

    MtGeomArgument FloatM1(mSMovable_Tube_Sheet->GetFace(5), p_IPMovable_Tube_Sheet);
    MtGeomArgument FloatGa(mSGasket_Floating_Head->GetFace(2), p_IPGasket_Floating_Head);
    assm->AddConstraint(GCM_DISTANCE, FloatM1, FloatGa, 0);
    assm->EvaluateConstraints();

    MtGeomArgument FloatGa1(mSGasket_Floating_Head->GetFace(0), p_IPGasket_Floating_Head);
    MtGeomArgument FloatC(mSFloating_Head_Cover->GetFace(5), p_IPFloating_Head_Cover);
    assm->AddConstraint(GCM_DISTANCE, FloatGa1, FloatC, 0);
    assm->EvaluateConstraints();

    MtGeomArgument Supports(mSHeat_Exchanger_Supports->GetFace(5), p_IPHeat_Exchanger_Supports);
    MtGeomArgument SupportsC(mSСasing->GetFace(26), p_IPСasing);
    assm->AddConstraint(GCM_CONCENTRIC, Supports, SupportsC);
    assm->EvaluateConstraints();

    MtGeomArgument Supports1(mSHeat_Exchanger_Supports->GetFace(4), p_IPHeat_Exchanger_Supports);
    MtGeomArgument SupportsC1(mSСasing->GetFace(8), p_IPСasing);
    assm->AddConstraint(GCM_DISTANCE, Supports1, SupportsC1, params.l2.toDouble() - params.Dy1.toDouble());
    assm->EvaluateConstraints();

    MtGeomArgument Supports2(mSHeat_Exchanger_Supports1->GetFace(5), p_IPHeat_Exchanger_Supports1);
    MtGeomArgument SupportsC2(mSСasing->GetFace(26), p_IPСasing);
    assm->AddConstraint(GCM_CONCENTRIC, Supports2, SupportsC2);
    assm->EvaluateConstraints();

    MtGeomArgument Supports31(mSHeat_Exchanger_Supports1->GetFace(4), p_IPHeat_Exchanger_Supports1);
    MtGeomArgument Supports3(mSHeat_Exchanger_Supports->GetFace(6), p_IPHeat_Exchanger_Supports);
    assm->AddConstraint(GCM_DISTANCE, Supports31, Supports3, params.l0.toDouble());
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
