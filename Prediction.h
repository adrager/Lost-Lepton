//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct 24 09:51:04 2014 by ROOT version 5.34/04
// from TTree RA2PreSelection/RA2PreSelection
// found on file: /nfs/dust/cms/user/adraeger/CSA2014/mc/wjetHT600-Inf.root
//////////////////////////////////////////////////////////

#ifndef Prediction_h
#define Prediction_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH2F.h>
#include <TH1F.h>
#include "TVector2.h"
#include <cmath>
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TKey.h"
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
// use gen infomation to fix purityy of muon controlsample
const bool useGenInfoToMatchCSMuonToGen_=0; // changed 20 Nov from 1 to 0
const double maxDeltaRGenToRecoIsoMuon_=0.3;
const double maxDiffPtGenToRecoIsoMuon_=0.3;
const double minHT_=500;
const double minMHT_=200;
const double minNJets_=2.5;
const double deltaPhi1_=0.5;
const double deltaPhi2_=0.5;
const double deltaPhi3_=0.3;
const double minDeltaPhiN_=4.0;
const bool applyFilters_=false;
const bool applyDiLepCorrection_=true;

const UShort_t NJetsLow_=2;
const UShort_t NJetsMedium_=5;
const UShort_t NJetsMedium2_=7;
const UShort_t NJetsHigh_=8;

// uncertainties
const double MuAccUncertaintyDown_ = 9;  // pdf

// actity around lepton
const double maxDeltaRMuActivity_=1.0;
const double maxDeltaRElecActivity_=1.0;
const double maxDeltaRIsoTrackActivity_=1.0;
const unsigned int elecActivityMethod_=0;
const unsigned int muActivityMethod_=0;
const unsigned int isoTrackActivityMethod_=0;

// isolated track prediction
const double maxDeltaRRecoIsoMuToTack_ = 0.2;
const double maxDiffPtRecoIsoMuToTack_ = 0.5;

const double maxDeltaRRecoIsoElecToTack_ = 0.3;
const double maxDiffPtRecoIsoElecToTack_ = 0.5;
//using either oldschool th1/2 which have wrong error calculations or the updated tefficneices
const bool UseUpdatedTEfficiencies_=true;


class THFeff
{
public:
	THFeff(){}
	THFeff(TDirectory* inputFolder, const char* FolderName);
	THFeff(TGraphAsymmErrors* inputGraph);
	double GetEff(double xValue, double yValue);
	double GetEff(double xValue);
	~THFeff(){}
private:
	bool useTH2f_;
	const char* FolderName_;
	TH2F* refTH2F_;
	TGraphAsymmErrors* TGraphAsymmErrorsRef_;
	std::vector<TGraphAsymmErrors*> TGraphAsymmErrorsVec_;
	double xMax_, xMin_, yMax_, yMin_;
};




class Prediction : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   void resetValues();
   bool FiltersPass();
   double deltaR(double eta1, double phi1, double eta2, double phi2);
   double MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi);
   double effUp(double eff, double up);
   double effDown(double eff, double down);
   double getEff(TH2F* effTH2F, double xValue, double yValue);
   double getEff(TH1F* effTH2F, double xValue);
	 double MuActivity(double muEta, double muPhi, unsigned int method);
	 double ElecActivity( double elecEta, double elecPhi, unsigned int method);
	 double IsoTrackActivityCalc( double isoTrackEta, double isoTrackPhi, unsigned int method);
   // output variables
   TTree *tPrediction_;
   Float_t mtw;
	 Float_t muMTWEff_, elecMTWEff_, mtwCorrectedWeight_;
   Float_t muDiLepContributionMTWAppliedEff_, mtwDiLepCorrectedWeight_;
   Float_t muIsoEff_, muIsoWeight_;
   Float_t muRecoEff_, muRecoWeight_;
   Float_t muAccEff_, muAccWeight_;
   Float_t muTotalWeight_, totalMuons_;
	 Float_t elecPurityCorrection_, purityCorrectedWeight_, elecDiLepContributionMTWAppliedEff_;
   Float_t elecIsoEff_, elecIsoWeight_;
   Float_t elecRecoEff_, elecRecoWeight_;
   Float_t elecAccEff_, elecAccWeight_;
   Float_t elecTotalWeight_, totalElectrons_;
	 Float_t muDiLepEffMTWAppliedEff_, elecDiLepEffMTWAppliedEff_;
   Float_t totalWeight_, totalWeightDiLep_;
   Float_t         selectedIDIsoMuonsActivity[5];   //[selectedIDIsoMuonsNum]
   Float_t         selectedIDIsoElectronsActivity[5];   //[selectedIDIsoMuonsNum]
   
   // isolated track prediction
   bool IsolatedTracksMuMatched_, IsolatedTracksElecMatched_;
   
   // Effiecineices
   TH2F *MuMTWPTActivity_;
   TH1F *MuDiLepContributionMTWAppliedNJets_;
   TH2F *MuIsoPTActivity_;
//    TH1F *MuRecoActivitiy_;
   TH2F *MuRecoPTActivity_;
//    TH2F *MuAccHTNJets_;
// 	 TH2F *MuAccBTagNJets_;
	 TH2F *MuAccMHTNJets_;
	 TH1F *MuDiLepEffMTWAppliedNJets_;
   
   TH2F *ElecIsoPTActivity_;
//    TH1F *ElecRecoActivity_;
 	 TH2F *ElecRecoPTActivity_;
//    TH2F *ElecAccHTNJets_;
// 	 TH2F *ElecAccBTagNJets_;
	 TH2F *ElecAccMHTNJets_;
	 TH2F *ElecPurityMHTNJets_;
	 TH2F *ElecMTWPTActivity_;
	 TH1F *ElecDiLepContributionMTWAppliedNJets_;
	 TH1F *ElecDiLepEffMTWAppliedNJets_;
	 
	 UShort_t elecActivityMethod, muActivityMethod, isoTrackActivityMethod;
	 
	 // TEfficiency objects
	 THFeff *MuMTWPTActivityEff_;
	 THFeff *MuDiLepContributionMTWAppliedNJetsEff_;
	 THFeff *MuIsoPTActivityEff_;
	 THFeff *MuRecoPTActivityEff_;
	 THFeff *MuAccMHTNJetsEff_;
	 THFeff *MuDiLepEffMTWAppliedNJetsEff_;
	 
	 THFeff *ElecIsoPTActivityEff_;
	 THFeff *ElecRecoPTActivityEff_;
	 THFeff *ElecAccMHTNJetsEff_;
	 THFeff *ElecPurityMHTNJetsEff_;
	 THFeff *ElecMTWPTActivityEff_;
	 THFeff *ElecDiLepContributionMTWAppliedNJetsEff_;
	 THFeff *ElecDiLepEffMTWAppliedNJetsEff_;

	 // Declaration of leaf types
	 UInt_t          RunNum;
	 UInt_t          LumiBlockNum;
	 UInt_t          EvtNum;
	 Int_t           NVtx;
	 Int_t           isoTracks;
	 Int_t           Leptons;
	 Int_t           NJets;
	 Int_t           BTags;
	 Float_t         Weight;
	 Float_t         HT;
	 Float_t         MHT;
	 Float_t         DeltaPhi1;
	 Float_t         DeltaPhi2;
	 Float_t         DeltaPhi3;
	 Float_t         minDeltaPhiN;
	 Float_t         DeltaPhiN1;
	 Float_t         DeltaPhiN2;
	 Float_t         DeltaPhiN3;
	 Float_t         METPt;
	 Float_t         METPhi;
	 UShort_t        MuonsNum;
	 Float_t         MuonsPt[3];   //[MuonsNum]
	 Float_t         MuonsEta[3];   //[MuonsNum]
	 Float_t         MuonsPhi[3];   //[MuonsNum]
	 Float_t         MuonsE[3];   //[MuonsNum]
	 UShort_t        ElectronsNum;
	 Float_t         ElectronsPt[3];   //[ElectronsNum]
	 Float_t         ElectronsEta[3];   //[ElectronsNum]
	 Float_t         ElectronsPhi[3];   //[ElectronsNum]
	 Float_t         ElectronsE[3];   //[ElectronsNum]
	 UShort_t        IsolatedTracksNum;
	 Float_t         IsolatedTracksPt[5];   //[IsolatedTracksNum]
	 Float_t         IsolatedTracksEta[5];   //[IsolatedTracksNum]
	 Float_t         IsolatedTracksPhi[5];   //[IsolatedTracksNum]
	 Float_t         IsolatedTracksE[5];   //[IsolatedTracksNum]
	 UShort_t        selectedIDIsoMuonsNum;
	 Float_t         selectedIDIsoMuonsPt[3];   //[selectedIDIsoMuonsNum]
	 Float_t         selectedIDIsoMuonsEta[3];   //[selectedIDIsoMuonsNum]
	 Float_t         selectedIDIsoMuonsPhi[3];   //[selectedIDIsoMuonsNum]
	 Float_t         selectedIDIsoMuonsE[3];   //[selectedIDIsoMuonsNum]
	 UShort_t        selectedIDMuonsNum;
	 Float_t         selectedIDMuonsPt[4];   //[selectedIDMuonsNum]
	 Float_t         selectedIDMuonsEta[4];   //[selectedIDMuonsNum]
	 Float_t         selectedIDMuonsPhi[4];   //[selectedIDMuonsNum]
	 Float_t         selectedIDMuonsE[4];   //[selectedIDMuonsNum]
	 UShort_t        selectedIDIsoElectronsNum;
	 Float_t         selectedIDIsoElectronsPt[3];   //[selectedIDIsoElectronsNum]
	 Float_t         selectedIDIsoElectronsEta[3];   //[selectedIDIsoElectronsNum]
	 Float_t         selectedIDIsoElectronsPhi[3];   //[selectedIDIsoElectronsNum]
	 Float_t         selectedIDIsoElectronsE[3];   //[selectedIDIsoElectronsNum]
	 UShort_t        selectedIDElectronsNum;
	 Float_t         selectedIDElectronsPt[4];   //[selectedIDElectronsNum]
	 Float_t         selectedIDElectronsEta[4];   //[selectedIDElectronsNum]
	 Float_t         selectedIDElectronsPhi[4];   //[selectedIDElectronsNum]
	 Float_t         selectedIDElectronsE[4];   //[selectedIDElectronsNum]
	 UShort_t        SelectedPFCandidatesNum;
	 Float_t         SelectedPFCandidatesPt[119];   //[SelectedPFCandidatesNum]
	 Float_t         SelectedPFCandidatesEta[119];   //[SelectedPFCandidatesNum]
	 Float_t         SelectedPFCandidatesPhi[119];   //[SelectedPFCandidatesNum]
	 Float_t         SelectedPFCandidatesE[119];   //[SelectedPFCandidatesNum]
	 Int_t           SelectedPFCandidates_Charge[119];   //[SelectedPFCandidatesNum]
	 Int_t           SelectedPFCandidates_Typ[119];   //[SelectedPFCandidatesNum]
	 UShort_t        GenBosonNum;
	 Float_t         GenBosonPt[2];   //[GenBosonNum]
	 Float_t         GenBosonEta[2];   //[GenBosonNum]
	 Float_t         GenBosonPhi[2];   //[GenBosonNum]
	 Float_t         GenBosonE[2];   //[GenBosonNum]
	 Int_t           GenBoson_GenBosonPDGId[2];   //[GenBosonNum]
	 UShort_t        GenMuNum;
	 Float_t         GenMuPt[2];   //[GenMuNum]
	 Float_t         GenMuEta[2];   //[GenMuNum]
	 Float_t         GenMuPhi[2];   //[GenMuNum]
	 Float_t         GenMuE[2];   //[GenMuNum]
	 Int_t           GenMu_GenMuFromTau[2];   //[GenMuNum]
	 UShort_t        GenElecNum;
	 Float_t         GenElecPt[2];   //[GenElecNum]
	 Float_t         GenElecEta[2];   //[GenElecNum]
	 Float_t         GenElecPhi[2];   //[GenElecNum]
	 Float_t         GenElecE[2];   //[GenElecNum]
	 Int_t           GenElec_GenElecFromTau[2];   //[GenElecNum]
	 UShort_t        GenTauNum;
	 Float_t         GenTauPt[2];   //[GenTauNum]
	 Float_t         GenTauEta[2];   //[GenTauNum]
	 Float_t         GenTauPhi[2];   //[GenTauNum]
	 Float_t         GenTauE[2];   //[GenTauNum]
	 Int_t           GenTau_GenTauHad[2];   //[GenTauNum]
	 UShort_t        JetsNum;
	 Float_t         JetsPt[29];   //[JetsNum]
	 Float_t         JetsEta[29];   //[JetsNum]
	 Float_t         JetsPhi[29];   //[JetsNum]
	 Float_t         JetsE[29];   //[JetsNum]
	 Float_t         Jets_bDiscriminator[29];   //[JetsNum]
	 Float_t         Jets_chargedEmEnergyFraction[29];   //[JetsNum]
	 Float_t         Jets_chargedHadronEnergyFraction[29];   //[JetsNum]
	 Int_t           Jets_chargedHadronMultiplicity[29];   //[JetsNum]
	 Int_t           Jets_electronMultiplicity[29];   //[JetsNum]
	 Float_t         Jets_jetArea[29];   //[JetsNum]
	 Float_t         Jets_muonEnergyFraction[29];   //[JetsNum]
	 Int_t           Jets_muonMultiplicity[29];   //[JetsNum]
	 Float_t         Jets_neutralEmEnergyFraction[29];   //[JetsNum]
	 Int_t           Jets_neutralHadronMultiplicity[29];   //[JetsNum]
	 Float_t         Jets_photonEnergyFraction[29];   //[JetsNum]
	 Int_t           Jets_photonMultiplicity[29];   //[JetsNum]
	 
	 // List of branches
	 TBranch        *b_RunNum;   //!
	 TBranch        *b_LumiBlockNum;   //!
	 TBranch        *b_EvtNum;   //!
	 TBranch        *b_NVtx;   //!
	 TBranch        *b_isoTracks;   //!
	 TBranch        *b_Leptons;   //!
	 TBranch        *b_NJets;   //!
	 TBranch        *b_BTags;   //!
	 TBranch        *b_Weight;   //!
	 TBranch        *b_HT;   //!
	 TBranch        *b_MHT;   //!
	 TBranch        *b_DeltaPhi1;   //!
	 TBranch        *b_DeltaPhi2;   //!
	 TBranch        *b_DeltaPhi3;   //!
	 TBranch        *b_minDeltaPhiN;   //!
	 TBranch        *b_DeltaPhiN1;   //!
	 TBranch        *b_DeltaPhiN2;   //!
	 TBranch        *b_DeltaPhiN3;   //!
	 TBranch        *b_METPt;   //!
	 TBranch        *b_METPhi;   //!
	 TBranch        *b_MuonsNum;   //!
	 TBranch        *b_MuonsPt;   //!
	 TBranch        *b_MuonsEta;   //!
	 TBranch        *b_MuonsPhi;   //!
	 TBranch        *b_MuonsE;   //!
	 TBranch        *b_ElectronsNum;   //!
	 TBranch        *b_ElectronsPt;   //!
	 TBranch        *b_ElectronsEta;   //!
	 TBranch        *b_ElectronsPhi;   //!
	 TBranch        *b_ElectronsE;   //!
	 TBranch        *b_IsolatedTracksNum;   //!
	 TBranch        *b_IsolatedTracksPt;   //!
	 TBranch        *b_IsolatedTracksEta;   //!
	 TBranch        *b_IsolatedTracksPhi;   //!
	 TBranch        *b_IsolatedTracksE;   //!
	 TBranch        *b_selectedIDIsoMuonsNum;   //!
	 TBranch        *b_selectedIDIsoMuonsPt;   //!
	 TBranch        *b_selectedIDIsoMuonsEta;   //!
	 TBranch        *b_selectedIDIsoMuonsPhi;   //!
	 TBranch        *b_selectedIDIsoMuonsE;   //!
	 TBranch        *b_selectedIDMuonsNum;   //!
	 TBranch        *b_selectedIDMuonsPt;   //!
	 TBranch        *b_selectedIDMuonsEta;   //!
	 TBranch        *b_selectedIDMuonsPhi;   //!
	 TBranch        *b_selectedIDMuonsE;   //!
	 TBranch        *b_selectedIDIsoElectronsNum;   //!
	 TBranch        *b_selectedIDIsoElectronsPt;   //!
	 TBranch        *b_selectedIDIsoElectronsEta;   //!
	 TBranch        *b_selectedIDIsoElectronsPhi;   //!
	 TBranch        *b_selectedIDIsoElectronsE;   //!
	 TBranch        *b_selectedIDElectronsNum;   //!
	 TBranch        *b_selectedIDElectronsPt;   //!
	 TBranch        *b_selectedIDElectronsEta;   //!
	 TBranch        *b_selectedIDElectronsPhi;   //!
	 TBranch        *b_selectedIDElectronsE;   //!
	 TBranch        *b_SelectedPFCandidatesNum;   //!
	 TBranch        *b_SelectedPFCandidatesPt;   //!
	 TBranch        *b_SelectedPFCandidatesEta;   //!
	 TBranch        *b_SelectedPFCandidatesPhi;   //!
	 TBranch        *b_SelectedPFCandidatesE;   //!
	 TBranch        *b_SelectedPFCandidates_Charge;   //!
	 TBranch        *b_SelectedPFCandidates_Typ;   //!
	 TBranch        *b_GenBosonNum;   //!
	 TBranch        *b_GenBosonPt;   //!
	 TBranch        *b_GenBosonEta;   //!
	 TBranch        *b_GenBosonPhi;   //!
	 TBranch        *b_GenBosonE;   //!
	 TBranch        *b_GenBoson_GenBosonPDGId;   //!
	 TBranch        *b_GenMuNum;   //!
	 TBranch        *b_GenMuPt;   //!
	 TBranch        *b_GenMuEta;   //!
	 TBranch        *b_GenMuPhi;   //!
	 TBranch        *b_GenMuE;   //!
	 TBranch        *b_GenMu_GenMuFromTau;   //!
	 TBranch        *b_GenElecNum;   //!
	 TBranch        *b_GenElecPt;   //!
	 TBranch        *b_GenElecEta;   //!
	 TBranch        *b_GenElecPhi;   //!
	 TBranch        *b_GenElecE;   //!
	 TBranch        *b_GenElec_GenElecFromTau;   //!
	 TBranch        *b_GenTauNum;   //!
	 TBranch        *b_GenTauPt;   //!
	 TBranch        *b_GenTauEta;   //!
	 TBranch        *b_GenTauPhi;   //!
	 TBranch        *b_GenTauE;   //!
	 TBranch        *b_GenTau_GenTauHad;   //!
	 TBranch        *b_JetsNum;   //!
	 TBranch        *b_JetsPt;   //!
	 TBranch        *b_JetsEta;   //!
	 TBranch        *b_JetsPhi;   //!
	 TBranch        *b_JetsE;   //!
	 TBranch        *b_Jets_bDiscriminator;   //!
	 TBranch        *b_Jets_chargedEmEnergyFraction;   //!
	 TBranch        *b_Jets_chargedHadronEnergyFraction;   //!
	 TBranch        *b_Jets_chargedHadronMultiplicity;   //!
	 TBranch        *b_Jets_electronMultiplicity;   //!
	 TBranch        *b_Jets_jetArea;   //!
	 TBranch        *b_Jets_muonEnergyFraction;   //!
	 TBranch        *b_Jets_muonMultiplicity;   //!
	 TBranch        *b_Jets_neutralEmEnergyFraction;   //!
	 TBranch        *b_Jets_neutralHadronMultiplicity;   //!
	 TBranch        *b_Jets_photonEnergyFraction;   //!
	 TBranch        *b_Jets_photonMultiplicity;   //!
	 
	 Prediction(TTree * /*tree*/ =0) : fChain(0) { }
	 virtual ~Prediction() { }
	 virtual Int_t   Version() const { return 2; }
	 virtual void    Begin(TTree *tree);
	 virtual void    SlaveBegin(TTree *tree);
	 virtual void    Init(TTree *tree);
	 virtual Bool_t  Notify();
	 virtual Bool_t  Process(Long64_t entry);
	 virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
	 virtual void    SetOption(const char *option) { fOption = option; }
	 virtual void    SetObject(TObject *obj) { fObject = obj; }
	 virtual void    SetInputList(TList *input) { fInput = input; }
	 virtual TList  *GetOutputList() const { return fOutput; }
	 virtual void    SlaveTerminate();
	 virtual void    Terminate();
	 
	 ClassDef(Prediction,0);
};

#endif

#ifdef Prediction_cxx
void Prediction::Init(TTree *tree)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).
	
	// Set branch addresses and branch pointers
	if (!tree) return;
	fChain = tree;
	fChain->SetMakeClass(1);
	
	fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
	fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
	fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
	fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
	fChain->SetBranchAddress("isoTracks", &isoTracks, &b_isoTracks);
	fChain->SetBranchAddress("Leptons", &Leptons, &b_Leptons);
	fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
	fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
	fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
	fChain->SetBranchAddress("HT", &HT, &b_HT);
	fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
	fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
	fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
	fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
	fChain->SetBranchAddress("minDeltaPhiN", &minDeltaPhiN, &b_minDeltaPhiN);
	fChain->SetBranchAddress("DeltaPhiN1", &DeltaPhiN1, &b_DeltaPhiN1);
	fChain->SetBranchAddress("DeltaPhiN2", &DeltaPhiN2, &b_DeltaPhiN2);
	fChain->SetBranchAddress("DeltaPhiN3", &DeltaPhiN3, &b_DeltaPhiN3);
	fChain->SetBranchAddress("METPt", &METPt, &b_METPt);
	fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
	fChain->SetBranchAddress("MuonsNum", &MuonsNum, &b_MuonsNum);
	fChain->SetBranchAddress("MuonsPt", MuonsPt, &b_MuonsPt);
	fChain->SetBranchAddress("MuonsEta", MuonsEta, &b_MuonsEta);
	fChain->SetBranchAddress("MuonsPhi", MuonsPhi, &b_MuonsPhi);
	fChain->SetBranchAddress("MuonsE", MuonsE, &b_MuonsE);
	fChain->SetBranchAddress("ElectronsNum", &ElectronsNum, &b_ElectronsNum);
	fChain->SetBranchAddress("ElectronsPt", ElectronsPt, &b_ElectronsPt);
	fChain->SetBranchAddress("ElectronsEta", ElectronsEta, &b_ElectronsEta);
	fChain->SetBranchAddress("ElectronsPhi", ElectronsPhi, &b_ElectronsPhi);
	fChain->SetBranchAddress("ElectronsE", ElectronsE, &b_ElectronsE);
	fChain->SetBranchAddress("IsolatedTracksNum", &IsolatedTracksNum, &b_IsolatedTracksNum);
	fChain->SetBranchAddress("IsolatedTracksPt", IsolatedTracksPt, &b_IsolatedTracksPt);
	fChain->SetBranchAddress("IsolatedTracksEta", IsolatedTracksEta, &b_IsolatedTracksEta);
	fChain->SetBranchAddress("IsolatedTracksPhi", IsolatedTracksPhi, &b_IsolatedTracksPhi);
	fChain->SetBranchAddress("IsolatedTracksE", IsolatedTracksE, &b_IsolatedTracksE);
	fChain->SetBranchAddress("selectedIDIsoMuonsNum", &selectedIDIsoMuonsNum, &b_selectedIDIsoMuonsNum);
	fChain->SetBranchAddress("selectedIDIsoMuonsPt", selectedIDIsoMuonsPt, &b_selectedIDIsoMuonsPt);
	fChain->SetBranchAddress("selectedIDIsoMuonsEta", selectedIDIsoMuonsEta, &b_selectedIDIsoMuonsEta);
	fChain->SetBranchAddress("selectedIDIsoMuonsPhi", selectedIDIsoMuonsPhi, &b_selectedIDIsoMuonsPhi);
	fChain->SetBranchAddress("selectedIDIsoMuonsE", selectedIDIsoMuonsE, &b_selectedIDIsoMuonsE);
	fChain->SetBranchAddress("selectedIDMuonsNum", &selectedIDMuonsNum, &b_selectedIDMuonsNum);
	fChain->SetBranchAddress("selectedIDMuonsPt", selectedIDMuonsPt, &b_selectedIDMuonsPt);
	fChain->SetBranchAddress("selectedIDMuonsEta", selectedIDMuonsEta, &b_selectedIDMuonsEta);
	fChain->SetBranchAddress("selectedIDMuonsPhi", selectedIDMuonsPhi, &b_selectedIDMuonsPhi);
	fChain->SetBranchAddress("selectedIDMuonsE", selectedIDMuonsE, &b_selectedIDMuonsE);
	fChain->SetBranchAddress("selectedIDIsoElectronsNum", &selectedIDIsoElectronsNum, &b_selectedIDIsoElectronsNum);
	fChain->SetBranchAddress("selectedIDIsoElectronsPt", selectedIDIsoElectronsPt, &b_selectedIDIsoElectronsPt);
	fChain->SetBranchAddress("selectedIDIsoElectronsEta", selectedIDIsoElectronsEta, &b_selectedIDIsoElectronsEta);
	fChain->SetBranchAddress("selectedIDIsoElectronsPhi", selectedIDIsoElectronsPhi, &b_selectedIDIsoElectronsPhi);
	fChain->SetBranchAddress("selectedIDIsoElectronsE", selectedIDIsoElectronsE, &b_selectedIDIsoElectronsE);
	fChain->SetBranchAddress("selectedIDElectronsNum", &selectedIDElectronsNum, &b_selectedIDElectronsNum);
	fChain->SetBranchAddress("selectedIDElectronsPt", selectedIDElectronsPt, &b_selectedIDElectronsPt);
	fChain->SetBranchAddress("selectedIDElectronsEta", selectedIDElectronsEta, &b_selectedIDElectronsEta);
	fChain->SetBranchAddress("selectedIDElectronsPhi", selectedIDElectronsPhi, &b_selectedIDElectronsPhi);
	fChain->SetBranchAddress("selectedIDElectronsE", selectedIDElectronsE, &b_selectedIDElectronsE);
	fChain->SetBranchAddress("SelectedPFCandidatesNum", &SelectedPFCandidatesNum, &b_SelectedPFCandidatesNum);
	fChain->SetBranchAddress("SelectedPFCandidatesPt", SelectedPFCandidatesPt, &b_SelectedPFCandidatesPt);
	fChain->SetBranchAddress("SelectedPFCandidatesEta", SelectedPFCandidatesEta, &b_SelectedPFCandidatesEta);
	fChain->SetBranchAddress("SelectedPFCandidatesPhi", SelectedPFCandidatesPhi, &b_SelectedPFCandidatesPhi);
	fChain->SetBranchAddress("SelectedPFCandidatesE", SelectedPFCandidatesE, &b_SelectedPFCandidatesE);
	fChain->SetBranchAddress("SelectedPFCandidates_Charge", SelectedPFCandidates_Charge, &b_SelectedPFCandidates_Charge);
	fChain->SetBranchAddress("SelectedPFCandidates_Typ", SelectedPFCandidates_Typ, &b_SelectedPFCandidates_Typ);
	fChain->SetBranchAddress("GenBosonNum", &GenBosonNum, &b_GenBosonNum);
	fChain->SetBranchAddress("GenBosonPt", GenBosonPt, &b_GenBosonPt);
	fChain->SetBranchAddress("GenBosonEta", GenBosonEta, &b_GenBosonEta);
	fChain->SetBranchAddress("GenBosonPhi", GenBosonPhi, &b_GenBosonPhi);
	fChain->SetBranchAddress("GenBosonE", GenBosonE, &b_GenBosonE);
	fChain->SetBranchAddress("GenBoson_GenBosonPDGId", GenBoson_GenBosonPDGId, &b_GenBoson_GenBosonPDGId);
	fChain->SetBranchAddress("GenMuNum", &GenMuNum, &b_GenMuNum);
	fChain->SetBranchAddress("GenMuPt", GenMuPt, &b_GenMuPt);
	fChain->SetBranchAddress("GenMuEta", GenMuEta, &b_GenMuEta);
	fChain->SetBranchAddress("GenMuPhi", GenMuPhi, &b_GenMuPhi);
	fChain->SetBranchAddress("GenMuE", GenMuE, &b_GenMuE);
	fChain->SetBranchAddress("GenMu_GenMuFromTau", GenMu_GenMuFromTau, &b_GenMu_GenMuFromTau);
	fChain->SetBranchAddress("GenElecNum", &GenElecNum, &b_GenElecNum);
	fChain->SetBranchAddress("GenElecPt", GenElecPt, &b_GenElecPt);
	fChain->SetBranchAddress("GenElecEta", GenElecEta, &b_GenElecEta);
	fChain->SetBranchAddress("GenElecPhi", GenElecPhi, &b_GenElecPhi);
	fChain->SetBranchAddress("GenElecE", GenElecE, &b_GenElecE);
	fChain->SetBranchAddress("GenElec_GenElecFromTau", GenElec_GenElecFromTau, &b_GenElec_GenElecFromTau);
	fChain->SetBranchAddress("GenTauNum", &GenTauNum, &b_GenTauNum);
	fChain->SetBranchAddress("GenTauPt", GenTauPt, &b_GenTauPt);
	fChain->SetBranchAddress("GenTauEta", GenTauEta, &b_GenTauEta);
	fChain->SetBranchAddress("GenTauPhi", GenTauPhi, &b_GenTauPhi);
	fChain->SetBranchAddress("GenTauE", GenTauE, &b_GenTauE);
	fChain->SetBranchAddress("GenTau_GenTauHad", GenTau_GenTauHad, &b_GenTau_GenTauHad);
	fChain->SetBranchAddress("JetsNum", &JetsNum, &b_JetsNum);
	fChain->SetBranchAddress("JetsPt", JetsPt, &b_JetsPt);
	fChain->SetBranchAddress("JetsEta", JetsEta, &b_JetsEta);
	fChain->SetBranchAddress("JetsPhi", JetsPhi, &b_JetsPhi);
	fChain->SetBranchAddress("JetsE", JetsE, &b_JetsE);
	fChain->SetBranchAddress("Jets_bDiscriminator", Jets_bDiscriminator, &b_Jets_bDiscriminator);
	fChain->SetBranchAddress("Jets_chargedEmEnergyFraction", Jets_chargedEmEnergyFraction, &b_Jets_chargedEmEnergyFraction);
	fChain->SetBranchAddress("Jets_chargedHadronEnergyFraction", Jets_chargedHadronEnergyFraction, &b_Jets_chargedHadronEnergyFraction);
	fChain->SetBranchAddress("Jets_chargedHadronMultiplicity", Jets_chargedHadronMultiplicity, &b_Jets_chargedHadronMultiplicity);
	fChain->SetBranchAddress("Jets_electronMultiplicity", Jets_electronMultiplicity, &b_Jets_electronMultiplicity);
	fChain->SetBranchAddress("Jets_jetArea", Jets_jetArea, &b_Jets_jetArea);
	fChain->SetBranchAddress("Jets_muonEnergyFraction", Jets_muonEnergyFraction, &b_Jets_muonEnergyFraction);
	fChain->SetBranchAddress("Jets_muonMultiplicity", Jets_muonMultiplicity, &b_Jets_muonMultiplicity);
	fChain->SetBranchAddress("Jets_neutralEmEnergyFraction", Jets_neutralEmEnergyFraction, &b_Jets_neutralEmEnergyFraction);
	fChain->SetBranchAddress("Jets_neutralHadronMultiplicity", Jets_neutralHadronMultiplicity, &b_Jets_neutralHadronMultiplicity);
	fChain->SetBranchAddress("Jets_photonEnergyFraction", Jets_photonEnergyFraction, &b_Jets_photonEnergyFraction);
	fChain->SetBranchAddress("Jets_photonMultiplicity", Jets_photonMultiplicity, &b_Jets_photonMultiplicity);
}

Bool_t Prediction::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.
  
  return kTRUE;
}

#endif // #ifdef Prediction_cxx

