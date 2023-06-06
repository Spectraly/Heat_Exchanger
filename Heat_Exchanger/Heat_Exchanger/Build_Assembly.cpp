#include "BuildMathModel.h"

using namespace c3d;
using namespace std;
using namespace BuildMathModel;



MbAssembly* ParametricModelCreator::CreateHeatExchangerHPGAssembly(BuildParams params)
{
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


    bool sliceSide = true;
    vector<SPtr<MbSolid>> MbSPartition;
    vector<SPtr<MbInstance>> MbIPartition;
    int partitions = params.l4.toDouble() / params.l3.toDouble();
    for (int i = 0; i < partitions+2; i++)
    {
        SPtr<MbSolid> mSPartition_HPG = Partition(params, sliceSide);
        mSPartition_HPG->SetColor(190, 190, 190);
        InstanceSPtr iPPartition_HPG(new MbInstance(*mSPartition_HPG, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
        SPtr<MbInstance> p_IPPartition_HPG(new MbInstance(*iPPartition_HPG, lcs));
        MbSPartition.push_back(mSPartition_HPG);
        MbIPartition.push_back(iPPartition_HPG);
        sliceSide = !sliceSide;
    }

    /*-------------------------------------------------------------------------*/

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
    pair.push_back(p_IPGasket_Floating_Head);
    pair.push_back(p_IPFloating_Head_Cover);

    for (int i = 0; i < partitions + 2; i++)
    {
        pair.push_back(MbIPartition[i]);
    }


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

    MtGeomArgument Partition(MbSPartition[0]->GetFace(0), MbIPartition[0]);
    MtGeomArgument PartitionR(mSStationary_Tube_Sheet->GetFace(1), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, Partition, PartitionR, 400.0);
    assm->EvaluateConstraints();

    /*-------------------------------------------------------------------------*/

    for (size_t i = 1; i < partitions + 2; i++)
    {
        MtGeomArgument PartitionA(MbSPartition[i]->GetFace(0), MbIPartition[i]);
        MtGeomArgument PartitionA1(MbSPartition[i-1]->GetFace(1), MbIPartition[i-1]);
        assm->AddConstraint(GCM_DISTANCE, PartitionA, PartitionA1, params.l3.toDouble());
        assm->EvaluateConstraints();
    }


    /*-------------------------------------------------------------------------*/


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

    double HEIGHT;
    if (params.diam.toDouble() <= 700)
        HEIGHT = 220.0 / 2;
    else if (params.diam.toDouble() >= 700 && params.diam.toDouble() <= 1200)
        HEIGHT = 360.0 / 2;
    else if (params.diam.toDouble() > 1200)
        HEIGHT = 400.0 / 2;

    MtGeomArgument Supports1(mSHeat_Exchanger_Supports->GetFace(4), p_IPHeat_Exchanger_Supports);
    MtGeomArgument SupportsC1(mSСasing->GetFace(8), p_IPСasing);
    assm->AddConstraint(GCM_DISTANCE, Supports1, SupportsC1, -params.l2.toDouble() + params.Dy1.toDouble() - HEIGHT);
    assm->EvaluateConstraints();

    MtGeomArgument Supports2(mSHeat_Exchanger_Supports1->GetFace(5), p_IPHeat_Exchanger_Supports1);
    MtGeomArgument SupportsC2(mSСasing->GetFace(26), p_IPСasing);
    assm->AddConstraint(GCM_CONCENTRIC, Supports2, SupportsC2);
    assm->EvaluateConstraints();

    MtGeomArgument Supports31(mSHeat_Exchanger_Supports1->GetFace(4), p_IPHeat_Exchanger_Supports1);
    MtGeomArgument Supports3(mSHeat_Exchanger_Supports->GetFace(6), p_IPHeat_Exchanger_Supports);
    assm->AddConstraint(GCM_DISTANCE, Supports31, Supports3, -params.l0.toDouble());
    assm->EvaluateConstraints();   

    MbCube cube;
    assm->CalculateGabarit(cube);
    assm->Move(MbVector3D(-cube.GetLengthX()/2, 0, 0));

	return assm;
}

MbAssembly* ParametricModelCreator::CreateHeatExchangerKPAssembly(BuildParams params)
{
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

    bool sliceSide = true;
    vector<SPtr<MbSolid>> MbSPartition;
    vector<SPtr<MbInstance>> MbIPartition;
    for (int i = 0; i < 6; i++)
    {
        SPtr<MbSolid> mSPartition_HPG = Partition(params, sliceSide);
        mSPartition_HPG->SetColor(190, 190, 190);
        InstanceSPtr iPPartition_HPG(new MbInstance(*mSPartition_HPG, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
        SPtr<MbInstance> p_IPPartition_HPG(new MbInstance(*iPPartition_HPG, lcs));
        MbSPartition.push_back(mSPartition_HPG);
        MbIPartition.push_back(iPPartition_HPG);
        sliceSide = !sliceSide;
    }

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

    for (int i = 0; i < 5; i++)
    {
        pair.push_back(MbIPartition[i]);
    }

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

    if ((params.diam.toDouble() == 900 && params.pressure.toDouble() == 1.0) || (params.diam.toDouble() == 1200 && params.pressure.toDouble() == 1.0) || (params.diam.toDouble() == 1200 && params.pressure.toDouble() == 2.5))
    {
        MtGeomArgument CasingGaCo(mSСasing->GetFace(5), p_IPСasing);
        MtGeomArgument GasketCaCo(mSGasket_Casing_Cover->GetFace(2), p_IPGasket_Casing_Cover);
        assm->AddConstraint(GCM_DISTANCE, CasingGaCo, GasketCaCo, 0);
        assm->EvaluateConstraints();
    }
    else
    {
        MtGeomArgument CasingGaCo(mSСasing->GetFace(6), p_IPСasing);
        MtGeomArgument GasketCaCo(mSGasket_Casing_Cover->GetFace(2), p_IPGasket_Casing_Cover);
        assm->AddConstraint(GCM_DISTANCE, CasingGaCo, GasketCaCo, 0);
        assm->EvaluateConstraints();
    }
   

    MtGeomArgument CoverGaCa(mSСasing_Cover->GetFace(6), p_IPСasing_Cover);
    MtGeomArgument GasketCoCa(mSGasket_Casing_Cover->GetFace(0), p_IPGasket_Casing_Cover);
    assm->AddConstraint(GCM_DISTANCE, CoverGaCa, GasketCoCa, 0);
    assm->EvaluateConstraints();

    MtGeomArgument Tube(mSTubeBundles->GetFace(0), p_IPTubeBundles);
    MtGeomArgument TubeR(mSStationary_Tube_Sheet->GetFace(0), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, Tube, TubeR, -params.l.toDouble());
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

    if ((params.diam.toDouble() == 900 && params.pressure.toDouble() == 1.0)|| (params.diam.toDouble() == 1200 && params.pressure.toDouble() == 1.0) || (params.diam.toDouble() == 1200 && params.pressure.toDouble() == 2.5))
    {
        MtGeomArgument Supports(mSHeat_Exchanger_Supports->GetFace(5), p_IPHeat_Exchanger_Supports);
        MtGeomArgument SupportsC(mSСasing->GetFace(25), p_IPСasing);
        assm->AddConstraint(GCM_CONCENTRIC, Supports, SupportsC);
        assm->EvaluateConstraints();
    }
    else
    {
        MtGeomArgument Supports(mSHeat_Exchanger_Supports->GetFace(5), p_IPHeat_Exchanger_Supports);
        MtGeomArgument SupportsC(mSСasing->GetFace(26), p_IPСasing);
        assm->AddConstraint(GCM_CONCENTRIC, Supports, SupportsC);
        assm->EvaluateConstraints();
    }

    MtGeomArgument Supports1(mSHeat_Exchanger_Supports->GetFace(4), p_IPHeat_Exchanger_Supports);
    MtGeomArgument SupportsC1(mSСasing->GetFace(8), p_IPСasing);
    assm->AddConstraint(GCM_DISTANCE, Supports1, SupportsC1, params.l2.toDouble() - params.Dy1.toDouble());
    assm->EvaluateConstraints();

    if ((params.diam.toDouble() == 900 && params.pressure.toDouble() == 1.0) || (params.diam.toDouble() == 1200 && params.pressure.toDouble() == 1.0) || (params.diam.toDouble() == 1200 && params.pressure.toDouble() == 2.5))
    {
        MtGeomArgument Supports2(mSHeat_Exchanger_Supports1->GetFace(5), p_IPHeat_Exchanger_Supports1);
        MtGeomArgument SupportsC2(mSСasing->GetFace(25), p_IPСasing);
        assm->AddConstraint(GCM_CONCENTRIC, Supports2, SupportsC2);
        assm->EvaluateConstraints();
    }
    else
    {
        MtGeomArgument Supports2(mSHeat_Exchanger_Supports1->GetFace(5), p_IPHeat_Exchanger_Supports1);
        MtGeomArgument SupportsC2(mSСasing->GetFace(26), p_IPСasing);
        assm->AddConstraint(GCM_CONCENTRIC, Supports2, SupportsC2);
        assm->EvaluateConstraints();
    }
    

    MtGeomArgument Supports31(mSHeat_Exchanger_Supports1->GetFace(4), p_IPHeat_Exchanger_Supports1);
    MtGeomArgument Supports3(mSHeat_Exchanger_Supports->GetFace(6), p_IPHeat_Exchanger_Supports);
    assm->AddConstraint(GCM_DISTANCE, Supports31, Supports3, params.l0.toDouble());
    assm->EvaluateConstraints();

    MtGeomArgument Partition(MbSPartition[0]->GetFace(0), MbIPartition[0]);
    MtGeomArgument PartitionR(mSStationary_Tube_Sheet->GetFace(1), p_IPStationary_Tube_Sheet);
    assm->AddConstraint(GCM_DISTANCE, Partition, PartitionR, 900.0);
    assm->EvaluateConstraints();


   /*-------------------------------------------------------------------------*/

    for (size_t i = 1; i < 5; i++)
    {
        MtGeomArgument PartitionA(MbSPartition[i]->GetFace(0), MbIPartition[i]);
        MtGeomArgument PartitionA1(MbSPartition[i - 1]->GetFace(1), MbIPartition[i - 1]);
        assm->AddConstraint(GCM_DISTANCE, PartitionA, PartitionA1, 900.0);
        assm->EvaluateConstraints();

    }
     /*-------------------------------------------------------------------------*/

    MbCube cube;
    assm->CalculateGabarit(cube);
    assm->Move(MbVector3D(-cube.GetLengthX() / 2, 0, 0));

    return assm;
}

MbAssembly* ParametricModelCreator::CreateHeatExchangerTUAssembly(BuildParams params)
{
    float Ry = params.Dy.toDouble() / 2; //Радиус штуцера
    float l2 = params.l2.toDouble(); //Расстояние до подвижной опоры
    float l0 = params.l0.toDouble(); //Расстояние от подвижной до неподвижной опоры

    vector<SPtr<MbInstance>> pair;
    MbPlacement3D lcs;

    SPtr<MbSolid> Kozhuh = CasingTU(params);
    Kozhuh->SetColor(190, 190, 190);
    SPtr<MbSolid> Kamera = Distribution_ChamberTU(params);
    Kamera->SetColor(190, 190, 190);
    SPtr<MbSolid> PipeGrid = PipeGrideTU(params);
    PipeGrid->SetColor(190, 190, 190);
    SPtr<MbSolid> TubeBundle = TubeBundleTU(params);
    TubeBundle->SetColor(190, 190, 190);
    SPtr<MbSolid> FixedSup = SupHETU(params);
    FixedSup->SetColor(190, 190, 190);
    SPtr<MbSolid> MoveSup = SupHETU(params);
    MoveSup->SetColor(190, 190, 190);

    SPtr<MbSolid> GasketDCTY = Gasket_Distribution_ChamberTU(params);
    GasketDCTY->SetColor(0, 0, 0);
    SPtr<MbSolid> GasketCTY = Gasket_CasingTU(params);
    GasketCTY->SetColor(0, 0, 0);

    SPtr<MbSolid> Partit = PartitionTU(params);
    Partit->SetColor(190, 190, 190);


    /*----------------------------------------------*/


    InstanceSPtr KozhuhHE(new MbInstance(*Kozhuh, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr KameraHE(new MbInstance(*Kamera, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr PipeGridHE(new MbInstance(*PipeGrid, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr TubeBundleHE(new MbInstance(*TubeBundle, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr FixedSupHE(new MbInstance(*FixedSup, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr MoveSupHE(new MbInstance(*MoveSup, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));

    InstanceSPtr GasketDCTYHE(new MbInstance(*GasketDCTY, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));
    InstanceSPtr GasketCTYHE(new MbInstance(*GasketCTY, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));

    InstanceSPtr PartitHE(new MbInstance(*Partit, MbPlacement3D(MbCartPoint3D(0.0, 0.0, 0.0))));

    /*----------------------------------------------*/

    SPtr<MbInstance> KozhuhHEComp(new MbInstance(*KozhuhHE, lcs));
    SPtr<MbInstance> KameraHEComp(new MbInstance(*KameraHE, lcs));
    SPtr<MbInstance> PipeGridHEComp(new MbInstance(*PipeGridHE, lcs));
    SPtr<MbInstance> TubeBundleHEComp(new MbInstance(*TubeBundleHE, lcs));
    SPtr<MbInstance> FixedSupHEComp(new MbInstance(*FixedSupHE, lcs));
    SPtr<MbInstance> MoveSupHEComp(new MbInstance(*MoveSupHE, lcs));

    SPtr<MbInstance> GasketDCTYHEComp(new MbInstance(*GasketDCTYHE, lcs));
    SPtr<MbInstance> GasketCTYHEComp(new MbInstance(*GasketCTYHE, lcs));

    SPtr<MbInstance> PartitHEComp(new MbInstance(*PartitHE, lcs));

    /*----------------------------------------------*/

    pair.push_back(KameraHEComp);
    pair.push_back(PipeGridHEComp);
    pair.push_back(KozhuhHEComp);
    pair.push_back(TubeBundleHEComp);
    pair.push_back(FixedSupHEComp);
    pair.push_back(MoveSupHEComp);

    pair.push_back(GasketDCTYHEComp);
    pair.push_back(GasketCTYHEComp);

    pair.push_back(PartitHEComp);

    /*----------------------------------------------*/
    MbAssembly* assm = new MbAssembly(pair);
    assm->SetPlacement(lcs);

    MtGeomArgument KameraGasket(Kamera->GetFace(0), KameraHEComp);
    MtGeomArgument GasketKamera(GasketDCTY->GetFace(2), GasketDCTYHEComp);
    assm->AddConstraint(GCM_COINCIDENT, KameraGasket, GasketKamera);
    assm->EvaluateConstraints();

    MtGeomArgument GasketPG(GasketDCTY->GetFace(0), GasketDCTYHEComp);
    MtGeomArgument PipeGridGas(PipeGrid->GetFace(4), PipeGridHEComp);
    assm->AddConstraint(GCM_COINCIDENT, GasketPG, PipeGridGas);
    assm->EvaluateConstraints();

    MtGeomArgument PipeGridGas1(PipeGrid->GetFace(5), PipeGridHEComp);
    MtGeomArgument GasketPG1(GasketCTY->GetFace(2), GasketCTYHEComp);
    assm->AddConstraint(GCM_COINCIDENT, PipeGridGas1, GasketPG1);
    assm->EvaluateConstraints();

    MtGeomArgument GasketCasing(GasketCTY->GetFace(0), GasketCTYHEComp);
    MtGeomArgument CasingGasket(Kozhuh->GetFace(8), KozhuhHEComp);
    assm->AddConstraint(GCM_COINCIDENT, GasketCasing, CasingGasket);
    assm->EvaluateConstraints();

    MtGeomArgument PipeGridTB(PipeGrid->GetFace(0), PipeGridHEComp);
    MtGeomArgument TubeBundlePG(TubeBundle->GetFace(0), TubeBundleHEComp);
    assm->AddConstraint(GCM_COINCIDENT, PipeGridTB, TubeBundlePG);
    assm->EvaluateConstraints();

    MtGeomArgument MoveSupCas(MoveSup->GetFace(5), MoveSupHEComp);
    MtGeomArgument CasingMS(Kozhuh->GetFace(0), KozhuhHEComp);
    assm->AddConstraint(GCM_CONCENTRIC, MoveSupCas, CasingMS);
    assm->EvaluateConstraints();

    MtGeomArgument MoveSupCas1(MoveSup->GetFace(1), MoveSupHEComp);
    MtGeomArgument CasingMS1(Kozhuh->GetFace(9), KozhuhHEComp);
    assm->AddConstraint(GCM_DISTANCE, MoveSupCas1, CasingMS1, -90 - Ry + l2);
    assm->EvaluateConstraints();

    MtGeomArgument FixedSupCas(FixedSup->GetFace(5), FixedSupHEComp);
    MtGeomArgument CasingFS(Kozhuh->GetFace(0), KozhuhHEComp);
    assm->AddConstraint(GCM_CONCENTRIC, FixedSupCas, CasingFS);
    assm->EvaluateConstraints();

    MtGeomArgument FixedSupMS(FixedSup->GetFace(1), FixedSupHEComp);
    MtGeomArgument MoveSupFS(MoveSup->GetFace(1), MoveSupHEComp);
    assm->AddConstraint(GCM_DISTANCE, FixedSupMS, MoveSupFS, l0);
    assm->EvaluateConstraints();

    return assm;
}
