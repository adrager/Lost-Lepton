//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Jul  4 13:43:57 2015 by ROOT version 5.34/04
// from TTree LostLeptonExpectation/a simple Tree with simple variables
// found on file: Expectation.root
//////////////////////////////////////////////////////////

#ifndef TTTTTTTTT_h
#define TTTTTTTTT_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class TTTTTTTTT : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   UInt_t          EvtNum;
   Float_t         HT;
   Float_t         MHT;
   UShort_t        NJets;
   UShort_t        BTags;
   UShort_t        Leptons;
   UShort_t        isoTracks;
   UChar_t         DY;
   UShort_t        Bin;
   UShort_t        NVtx;
   Float_t         DeltaPhi1;
   Float_t         DeltaPhi2;
   Float_t         DeltaPhi3;
   Float_t         minDeltaPhiN;
   Float_t         DeltaPhiN1;
   Float_t         DeltaPhiN2;
   Float_t         DeltaPhiN3;
   Float_t         Weight;
   Float_t         MET;
   Float_t         METPhi;
   UShort_t        GenMuNum;
   UShort_t        GenMuFromTau[2];   //[GenMuNum]
   Float_t         GenMuDeltaRJet[2];   //[GenMuNum]
   Float_t         GenMuDeltaPTJet[2];   //[GenMuNum]
   Float_t         GenMuPt[2];   //[GenMuNum]
   Float_t         GenMuEta[2];   //[GenMuNum]
   Float_t         GenMuPhi[2];   //[GenMuNum]
   UShort_t        GenMuonIsoTrackMatched[2];   //[GenMuNum]
   Float_t         GenMuonActivity[2];   //[GenMuNum]
   UShort_t        GenElecNum;
   UShort_t        GenElecFromTau[2];   //[GenElecNum]
   Float_t         GenElecDeltaRJet[2];   //[GenElecNum]
   Float_t         GenElecDeltaPTJet[2];   //[GenElecNum]
   Float_t         GenElecPt[2];   //[GenElecNum]
   Float_t         GenElecEta[2];   //[GenElecNum]
   Float_t         GenElecPhi[2];   //[GenElecNum]
   UShort_t        GenElecIsoTrackMatched[2];   //[GenElecNum]
   Float_t         GenElecActivity[2];   //[GenElecNum]
   UShort_t        GenTauNum;
   Float_t         GenTauPt[2];   //[GenTauNum]
   Float_t         GenTauEta[2];   //[GenTauNum]
   Float_t         GenTauPhi[2];   //[GenTauNum]
   UShort_t        GenTauCharged[2];   //[GenTauNum]
   UShort_t        GenTauNeutral[2];   //[GenTauNum]
   UShort_t        GenTauLepDecay[2];   //[GenTauNum]
   UShort_t        GenTauIsoTrackMatched[2];   //[GenTauNum]
   Float_t         GenTauActivity[2];   //[GenTauNum]
   UShort_t        Expectation;
   UShort_t        ExpectationReductionIsoTrack;
   UShort_t        ExpectationReductionIsoMuTrack;
   UShort_t        ExpectationReductionIsoElecTrack;
   UShort_t        ExpectationReductionIsoPionTrack;
   UShort_t        muAcc;
   UShort_t        muReco;
   UShort_t        muIso;
   Float_t         MTW;
   Float_t         IsoTrackMTW;
   UShort_t        elecAcc;
   UShort_t        elecReco;
   UShort_t        elecIso;
   UShort_t        muIsoTrack;
   UShort_t        MuPurity;
   UShort_t        ElecPurity;
   UShort_t        muIsoTrackIso;
   UShort_t        muIsoTrackReco;
   UShort_t        elecIsoTrackIso;
   UShort_t        elecIsoTrackReco;
   UShort_t        pionIsoTrackIso;
   UShort_t        pionIsoTrackReco;
   UShort_t        muActivityMethod;
   UShort_t        elecActivityMethod;
   UShort_t        muIsoTrackActivityMethod;
   UShort_t        elecIsoTrackActivityMethod;
   UShort_t        pionIsoTrackActivityMethod;
   UShort_t        FallsVetoLep;
   UShort_t        selectedIDIsoMuonsNum;
   Float_t         selectedIDIsoMuonsPt[3];   //[selectedIDIsoMuonsNum]
   UShort_t        muIsoMatched[3];   //[selectedIDIsoMuonsNum]
   UShort_t        RecoIsoMuonPromtMatched[3];   //[selectedIDIsoMuonsNum]
   Float_t         RecoIsoMuonPromtMatchedDeltaR[3];   //[selectedIDIsoMuonsNum]
   Float_t         RecoIsoMuonPromtMatchedRelPt[3];   //[selectedIDIsoMuonsNum]
   Float_t         selectedIDIsoMuonsEta[3];   //[selectedIDIsoMuonsNum]
   Float_t         selectedIDIsoMuonsPhi[3];   //[selectedIDIsoMuonsNum]
   Float_t         selectedIDIsoMuonsE[3];   //[selectedIDIsoMuonsNum]
   Float_t         selectedIDIsoMuons_MTW[3];   //[selectedIDIsoMuonsNum]
   Float_t         RecoIsoMuonActivity[3];   //[selectedIDIsoMuonsNum]
   UShort_t        selectedIDMuonsNum;
   Float_t         selectedIDMuonsPt[5];   //[selectedIDMuonsNum]
   UShort_t        selectedIDMuonsMatched[5];   //[selectedIDMuonsNum]
   Float_t         selectedIDMuonsEta[5];   //[selectedIDMuonsNum]
   Float_t         selectedIDMuonsPhi[5];   //[selectedIDMuonsNum]
   Float_t         selectedIDMuonsE[5];   //[selectedIDMuonsNum]
   Float_t         selectedIDMuons_MTW[3];   //[selectedIDIsoMuonsNum]
   Float_t         RecoMuonActivity[5];   //[selectedIDMuonsNum]
   UShort_t        RecoIsoMuonIsoTrackMatched[3];   //[selectedIDIsoMuonsNum]
   UShort_t        selectedIDIsoElectronsNum;
   Float_t         selectedIDIsoElectronsPt[3];   //[selectedIDIsoElectronsNum]
   UShort_t        elecIsoMatched[3];   //[selectedIDIsoElectronsNum]
   UShort_t        RecoIsoElecPromtMatched[3];   //[selectedIDIsoElectronsNum]
   Float_t         RecoIsoElecPromtMatchedDeltaR[3];   //[selectedIDIsoElectronsNum]
   Float_t         RecoIsoElecPromtMatchedRelPt[3];   //[selectedIDIsoElectronsNum]
   Float_t         selectedIDIsoElectronsEta[3];   //[selectedIDIsoElectronsNum]
   Float_t         selectedIDIsoElectronsPhi[3];   //[selectedIDIsoElectronsNum]
   Float_t         selectedIDIsoElectronsE[3];   //[selectedIDIsoElectronsNum]
   Float_t         selectedIDIsoElectrons_MTW[3];   //[selectedIDIsoElectronsNum]
   Float_t         RecoIsoElectronActivity[3];   //[selectedIDIsoElectronsNum]
   UShort_t        RecoIsoElecIsoTrackMatched[3];   //[selectedIDIsoElectronsNum]
   UShort_t        selectedIDElectronsNum;
   Float_t         selectedIDElectronsPt[4];   //[selectedIDElectronsNum]
   UShort_t        selectedIDElectronsMatched[4];   //[selectedIDElectronsNum]
   Float_t         selectedIDElectronsEta[4];   //[selectedIDElectronsNum]
   Float_t         selectedIDElectronsPhi[4];   //[selectedIDElectronsNum]
   Float_t         selectedIDElectronsE[4];   //[selectedIDElectronsNum]
   Float_t         selectedIDElectrons_MTW[3];   //[selectedIDIsoElectronsNum]
   Float_t         RecoElectronActivity[4];   //[selectedIDElectronsNum]
   UShort_t        IsolatedElectronTracksVetoNum;
   Float_t         IsolatedElectronTracksVetoPt[3];   //[IsolatedElectronTracksVetoNum]
   Float_t         IsolatedElectronTracksVetoEta[3];   //[IsolatedElectronTracksVetoNum]
   Float_t         IsolatedElectronTracksVetoPhi[3];   //[IsolatedElectronTracksVetoNum]
   Float_t         IsolatedElectronTracksVetoE[3];   //[IsolatedElectronTracksVetoNum]
   Float_t         IsolatedElectronTracksVetoActivity[3];   //[IsolatedElectronTracksVetoNum]
   Float_t         IsolatedElectronTracksVetoMTW[3];   //[IsolatedElectronTracksVetoNum]
   UShort_t        muIsoTrackMatchedToGenElec[3];   //[IsolatedElectronTracksVetoNum]
   UShort_t        elecIsoTrackMatchedToGenElec[3];   //[IsolatedElectronTracksVetoNum]
   UShort_t        pionIsoTrackMatchedToGenElec[3];   //[IsolatedElectronTracksVetoNum]
   UShort_t        IsolatedMuonTracksVetoNum;
   Float_t         IsolatedMuonTracksVetoPt[3];   //[IsolatedMuonTracksVetoNum]
   Float_t         IsolatedMuonTracksVetoEta[3];   //[IsolatedMuonTracksVetoNum]
   Float_t         IsolatedMuonTracksVetoPhi[3];   //[IsolatedMuonTracksVetoNum]
   Float_t         IsolatedMuonTracksVetoE[3];   //[IsolatedMuonTracksVetoNum]
   Float_t         IsolatedMuonTracksVetoActivity[3];   //[IsolatedMuonTracksVetoNum]
   Float_t         IsolatedMuonTracksVetoMTW[3];   //[IsolatedMuonTracksVetoNum]
   UShort_t        muIsoTrackMatchedToGenMu[3];   //[IsolatedMuonTracksVetoNum]
   UShort_t        elecIsoTrackMatchedToGenMu[3];   //[IsolatedMuonTracksVetoNum]
   UShort_t        pionIsoTrackMatchedToGenMu[3];   //[IsolatedMuonTracksVetoNum]
   UShort_t        IsolatedPionTracksVetoNum;
   Float_t         IsolatedPionTracksVetoPt[3];   //[IsolatedPionTracksVetoNum]
   Float_t         IsolatedPionTracksVetoEta[3];   //[IsolatedPionTracksVetoNum]
   Float_t         IsolatedPionTracksVetoPhi[3];   //[IsolatedPionTracksVetoNum]
   Float_t         IsolatedPionTracksVetoE[3];   //[IsolatedPionTracksVetoNum]
   Float_t         IsolatedPionTracksVetoActivity[3];   //[IsolatedPionTracksVetoNum]
   Float_t         IsolatedPionTracksVetoMTW[3];   //[IsolatedPionTracksVetoNum]
   UShort_t        muIsoTrackMatchedToGenSingleProngTau[3];   //[IsolatedPionTracksVetoNum]
   UShort_t        elecIsoTrackMatchedToGenSingleProngTau[3];   //[IsolatedPionTracksVetoNum]
   UShort_t        pionIsoTrackMatchedToGenSingleProngTau[3];   //[IsolatedPionTracksVetoNum]
   UShort_t        pionIsoTrackMatchedToGenSingleProngTauCharged[3];   //[IsolatedPionTracksVetoNum]
   UShort_t        pionIsoTrackMatchedToGenSingleProngTauNeutral[3];   //[IsolatedPionTracksVetoNum]
   UShort_t        JetsNum;
   Float_t         JetsPt[14];   //[JetsNum]
   Float_t         JetsEta[14];   //[JetsNum]
   Float_t         JetsPhi[14];   //[JetsNum]
   Float_t         JetsE[14];   //[JetsNum]
   Float_t         Jets_bDiscriminator[14];   //[JetsNum]
   Float_t         Jets_chargedEmEnergyFraction[14];   //[JetsNum]
   Float_t         Jets_chargedHadronEnergyFraction[14];   //[JetsNum]
   Int_t           Jets_chargedHadronMultiplicity[14];   //[JetsNum]
   Int_t           Jets_electronMultiplicity[14];   //[JetsNum]
   Float_t         Jets_jetArea[14];   //[JetsNum]
   Float_t         Jets_muonEnergyFraction[14];   //[JetsNum]
   Int_t           Jets_muonMultiplicity[14];   //[JetsNum]
   Float_t         Jets_neutralEmEnergyFraction[14];   //[JetsNum]
   Int_t           Jets_neutralHadronMultiplicity[14];   //[JetsNum]
   Float_t         Jets_photonEnergyFraction[14];   //[JetsNum]
   Int_t           Jets_photonMultiplicity[14];   //[JetsNum]
   UShort_t        ExpectationDiLep;
   UShort_t        MuDiLepControlSample;
   UShort_t        ElecDiLepControlSample;
   UShort_t        StandAloneGenMuIsoTrackMatched;
   UShort_t        StandAloneIsoTrackToMuMatched;
   UShort_t        StandAloneGenElecIsoTrackMatched;
   UShort_t        StandAloneIsoTrackToElecMatched;
   UShort_t        StandAloneIsoTrackToRecoMuMatched;
   UShort_t        StandAloneIsoTrackToRecoElecMatched;
   UShort_t        IsoTrackDiLepControlSampleMu;
   UShort_t        IsoTrackDiLepControlSampleElec;
   UShort_t        IsoTrackDiLepMu;
   UShort_t        IsoTrackDiLepElec;
   Float_t         GenMuWPt;
   Float_t         GenMuWPhi;
   Float_t         GenElecWPt;
   Float_t         GenElecWPhi;
   UShort_t        GenBosonNum;
   Float_t         GenBosonPt[2];   //[GenBosonNum]
   Float_t         GenBosonPhi[2];   //[GenBosonNum]

   // List of branches
   TBranch        *b_EvtNum;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_BTags;   //!
   TBranch        *b_Leptons;   //!
   TBranch        *b_isoTracks;   //!
   TBranch        *b_DY;   //!
   TBranch        *b_Bin;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_DeltaPhi1;   //!
   TBranch        *b_DeltaPhi2;   //!
   TBranch        *b_DeltaPhi3;   //!
   TBranch        *b_minDeltaPhiN;   //!
   TBranch        *b_DeltaPhiN1;   //!
   TBranch        *b_DeltaPhiN2;   //!
   TBranch        *b_DeltaPhiN3;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_METPhi;   //!
   TBranch        *b_GenMuNum;   //!
   TBranch        *b_GenMuFromTau;   //!
   TBranch        *b_GenMuDeltaRJet;   //!
   TBranch        *b_GenMuDeltaPTJet;   //!
   TBranch        *b_GenMuPt;   //!
   TBranch        *b_GenMuEta;   //!
   TBranch        *b_GenMuPhi;   //!
   TBranch        *b_GenMuonIsoTrackMatched;   //!
   TBranch        *b_GenMuonActivity;   //!
   TBranch        *b_GenElecNum;   //!
   TBranch        *b_GenElecFromTau;   //!
   TBranch        *b_GenElecDeltaRJet;   //!
   TBranch        *b_GenElecDeltaPTJet;   //!
   TBranch        *b_GenElecPt;   //!
   TBranch        *b_GenElecEta;   //!
   TBranch        *b_GenElecPhi;   //!
   TBranch        *b_GenElecIsoTrackMatched;   //!
   TBranch        *b_GenElecActivity;   //!
   TBranch        *b_GenTauNum;   //!
   TBranch        *b_GenTauPt;   //!
   TBranch        *b_GenTauEta;   //!
   TBranch        *b_GenTauPhi;   //!
   TBranch        *b_GenTauCharged;   //!
   TBranch        *b_GenTauNeutral;   //!
   TBranch        *b_GenTauLepDecay;   //!
   TBranch        *b_GenTauIsoTrackMatched;   //!
   TBranch        *b_GenTauActivity;   //!
   TBranch        *b_Expectation;   //!
   TBranch        *b_ExpectationReductionIsoTrack;   //!
   TBranch        *b_ExpectationReductionIsoMuTrack;   //!
   TBranch        *b_ExpectationReductionIsoElecTrack;   //!
   TBranch        *b_ExpectationReductionIsoPionTrack;   //!
   TBranch        *b_muAcc;   //!
   TBranch        *b_muReco;   //!
   TBranch        *b_muIso;   //!
   TBranch        *b_MTW;   //!
   TBranch        *b_IsoTrackMTW;   //!
   TBranch        *b_elecAcc;   //!
   TBranch        *b_elecReco;   //!
   TBranch        *b_elecIso;   //!
   TBranch        *b_muIsoTrack;   //!
   TBranch        *b_MuPurity;   //!
   TBranch        *b_ElecPurity;   //!
   TBranch        *b_muIsoTrackIso;   //!
   TBranch        *b_muIsoTrackReco;   //!
   TBranch        *b_elecIsoTrackIso;   //!
   TBranch        *b_elecIsoTrackReco;   //!
   TBranch        *b_pionIsoTrackIso;   //!
   TBranch        *b_pionIsoTrackReco;   //!
   TBranch        *b_muActivityMethod;   //!
   TBranch        *b_elecActivityMethod;   //!
   TBranch        *b_muIsoTrackActivityMethod;   //!
   TBranch        *b_elecIsoTrackActivityMethod;   //!
   TBranch        *b_pionIsoTrackActivityMethod;   //!
   TBranch        *b_FallsVetoLep;   //!
   TBranch        *b_selectedIDIsoMuonsNum;   //!
   TBranch        *b_selectedIDIsoMuonsPt;   //!
   TBranch        *b_muIsoMatched;   //!
   TBranch        *b_RecoIsoMuonPromtMatched;   //!
   TBranch        *b_RecoIsoMuonPromtMatchedDeltaR;   //!
   TBranch        *b_RecoIsoMuonPromtMatchedRelPt;   //!
   TBranch        *b_selectedIDIsoMuonsEta;   //!
   TBranch        *b_selectedIDIsoMuonsPhi;   //!
   TBranch        *b_selectedIDIsoMuonsE;   //!
   TBranch        *b_selectedIDIsoMuons_MTW;   //!
   TBranch        *b_RecoIsoMuonActivity;   //!
   TBranch        *b_selectedIDMuonsNum;   //!
   TBranch        *b_selectedIDMuonsPt;   //!
   TBranch        *b_selectedIDMuonsMatched;   //!
   TBranch        *b_selectedIDMuonsEta;   //!
   TBranch        *b_selectedIDMuonsPhi;   //!
   TBranch        *b_selectedIDMuonsE;   //!
   TBranch        *b_selectedIDMuons_MTW;   //!
   TBranch        *b_RecoMuonActivity;   //!
   TBranch        *b_RecoIsoMuonIsoTrackMatched;   //!
   TBranch        *b_selectedIDIsoElectronsNum;   //!
   TBranch        *b_selectedIDIsoElectronsPt;   //!
   TBranch        *b_elecIsoMatched;   //!
   TBranch        *b_RecoIsoElecPromtMatched;   //!
   TBranch        *b_RecoIsoElecPromtMatchedDeltaR;   //!
   TBranch        *b_RecoIsoElecPromtMatchedRelPt;   //!
   TBranch        *b_selectedIDIsoElectronsEta;   //!
   TBranch        *b_selectedIDIsoElectronsPhi;   //!
   TBranch        *b_selectedIDIsoElectronsE;   //!
   TBranch        *b_selectedIDIsoElectrons_MTW;   //!
   TBranch        *b_RecoIsoElectronActivity;   //!
   TBranch        *b_RecoIsoElecIsoTrackMatched;   //!
   TBranch        *b_selectedIDElectronsNum;   //!
   TBranch        *b_selectedIDElectronsPt;   //!
   TBranch        *b_selectedIDElectronsMatched;   //!
   TBranch        *b_selectedIDElectronsEta;   //!
   TBranch        *b_selectedIDElectronsPhi;   //!
   TBranch        *b_selectedIDElectronsE;   //!
   TBranch        *b_selectedIDElectrons_MTW;   //!
   TBranch        *b_RecoElectronActivity;   //!
   TBranch        *b_IsolatedElectronTracksVetoNum;   //!
   TBranch        *b_IsolatedElectronTracksVetoPt;   //!
   TBranch        *b_IsolatedElectronTracksVetoEta;   //!
   TBranch        *b_IsolatedElectronTracksVetoPhi;   //!
   TBranch        *b_IsolatedElectronTracksVetoE;   //!
   TBranch        *b_IsolatedElectronTracksVetoActivity;   //!
   TBranch        *b_IsolatedElectronTracksVetoMTW;   //!
   TBranch        *b_muIsoTrackMatchedToGenElec;   //!
   TBranch        *b_elecIsoTrackMatchedToGenElec;   //!
   TBranch        *b_pionIsoTrackMatchedToGenElec;   //!
   TBranch        *b_IsolatedMuonTracksVetoNum;   //!
   TBranch        *b_IsolatedMuonTracksVetoPt;   //!
   TBranch        *b_IsolatedMuonTracksVetoEta;   //!
   TBranch        *b_IsolatedMuonTracksVetoPhi;   //!
   TBranch        *b_IsolatedMuonTracksVetoE;   //!
   TBranch        *b_IsolatedMuonTracksVetoActivity;   //!
   TBranch        *b_IsolatedMuonTracksVetoMTW;   //!
   TBranch        *b_muIsoTrackMatchedToGenMu;   //!
   TBranch        *b_elecIsoTrackMatchedToGenMu;   //!
   TBranch        *b_pionIsoTrackMatchedToGenMu;   //!
   TBranch        *b_IsolatedPionTracksVetoNum;   //!
   TBranch        *b_IsolatedPionTracksVetoPt;   //!
   TBranch        *b_IsolatedPionTracksVetoEta;   //!
   TBranch        *b_IsolatedPionTracksVetoPhi;   //!
   TBranch        *b_IsolatedPionTracksVetoE;   //!
   TBranch        *b_IsolatedPionTracksVetoActivity;   //!
   TBranch        *b_IsolatedPionTracksVetoMTW;   //!
   TBranch        *b_muIsoTrackMatchedToGenSingleProngTau;   //!
   TBranch        *b_elecIsoTrackMatchedToGenSingleProngTau;   //!
   TBranch        *b_pionIsoTrackMatchedToGenSingleProngTau;   //!
   TBranch        *b_pionIsoTrackMatchedToGenSingleProngTauCharged;   //!
   TBranch        *b_pionIsoTrackMatchedToGenSingleProngTauNeutral;   //!
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
   TBranch        *b_ExpectationDiLep;   //!
   TBranch        *b_MuDiLepControlSample;   //!
   TBranch        *b_ElecDiLepControlSample;   //!
   TBranch        *b_StandAloneGenMuIsoTrackMatched;   //!
   TBranch        *b_StandAloneIsoTrackToMuMatched;   //!
   TBranch        *b_StandAloneGenElecIsoTrackMatched;   //!
   TBranch        *b_StandAloneIsoTrackToElecMatched;   //!
   TBranch        *b_StandAloneIsoTrackToRecoMuMatched;   //!
   TBranch        *b_StandAloneIsoTrackToRecoElecMatched;   //!
   TBranch        *b_IsoTrackDiLepControlSampleMu;   //!
   TBranch        *b_IsoTrackDiLepControlSampleElec;   //!
   TBranch        *b_IsoTrackDiLepMu;   //!
   TBranch        *b_IsoTrackDiLepElec;   //!
   TBranch        *b_GenMuWPt;   //!
   TBranch        *b_GenMuWPhi;   //!
   TBranch        *b_GenElecWPt;   //!
   TBranch        *b_GenElecWPhi;   //!
   TBranch        *b_GenBosonNum;   //!
   TBranch        *b_GenBosonPt;   //!
   TBranch        *b_GenBosonPhi;   //!

   TTTTTTTTT(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~TTTTTTTTT() { }
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

   ClassDef(TTTTTTTTT,0);
};

#endif

#ifdef TTTTTTTTT_cxx
void TTTTTTTTT::Init(TTree *tree)
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

   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
   fChain->SetBranchAddress("Leptons", &Leptons, &b_Leptons);
   fChain->SetBranchAddress("isoTracks", &isoTracks, &b_isoTracks);
   fChain->SetBranchAddress("DY", &DY, &b_DY);
   fChain->SetBranchAddress("Bin", &Bin, &b_Bin);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
   fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
   fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
   fChain->SetBranchAddress("minDeltaPhiN", &minDeltaPhiN, &b_minDeltaPhiN);
   fChain->SetBranchAddress("DeltaPhiN1", &DeltaPhiN1, &b_DeltaPhiN1);
   fChain->SetBranchAddress("DeltaPhiN2", &DeltaPhiN2, &b_DeltaPhiN2);
   fChain->SetBranchAddress("DeltaPhiN3", &DeltaPhiN3, &b_DeltaPhiN3);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
   fChain->SetBranchAddress("GenMuNum", &GenMuNum, &b_GenMuNum);
   fChain->SetBranchAddress("GenMuFromTau", GenMuFromTau, &b_GenMuFromTau);
   fChain->SetBranchAddress("GenMuDeltaRJet", GenMuDeltaRJet, &b_GenMuDeltaRJet);
   fChain->SetBranchAddress("GenMuDeltaPTJet", GenMuDeltaPTJet, &b_GenMuDeltaPTJet);
   fChain->SetBranchAddress("GenMuPt", GenMuPt, &b_GenMuPt);
   fChain->SetBranchAddress("GenMuEta", GenMuEta, &b_GenMuEta);
   fChain->SetBranchAddress("GenMuPhi", GenMuPhi, &b_GenMuPhi);
   fChain->SetBranchAddress("GenMuonIsoTrackMatched", GenMuonIsoTrackMatched, &b_GenMuonIsoTrackMatched);
   fChain->SetBranchAddress("GenMuonActivity", GenMuonActivity, &b_GenMuonActivity);
   fChain->SetBranchAddress("GenElecNum", &GenElecNum, &b_GenElecNum);
   fChain->SetBranchAddress("GenElecFromTau", GenElecFromTau, &b_GenElecFromTau);
   fChain->SetBranchAddress("GenElecDeltaRJet", GenElecDeltaRJet, &b_GenElecDeltaRJet);
   fChain->SetBranchAddress("GenElecDeltaPTJet", GenElecDeltaPTJet, &b_GenElecDeltaPTJet);
   fChain->SetBranchAddress("GenElecPt", GenElecPt, &b_GenElecPt);
   fChain->SetBranchAddress("GenElecEta", GenElecEta, &b_GenElecEta);
   fChain->SetBranchAddress("GenElecPhi", GenElecPhi, &b_GenElecPhi);
   fChain->SetBranchAddress("GenElecIsoTrackMatched", GenElecIsoTrackMatched, &b_GenElecIsoTrackMatched);
   fChain->SetBranchAddress("GenElecActivity", GenElecActivity, &b_GenElecActivity);
   fChain->SetBranchAddress("GenTauNum", &GenTauNum, &b_GenTauNum);
   fChain->SetBranchAddress("GenTauPt", GenTauPt, &b_GenTauPt);
   fChain->SetBranchAddress("GenTauEta", GenTauEta, &b_GenTauEta);
   fChain->SetBranchAddress("GenTauPhi", GenTauPhi, &b_GenTauPhi);
   fChain->SetBranchAddress("GenTauCharged", GenTauCharged, &b_GenTauCharged);
   fChain->SetBranchAddress("GenTauNeutral", GenTauNeutral, &b_GenTauNeutral);
   fChain->SetBranchAddress("GenTauLepDecay", GenTauLepDecay, &b_GenTauLepDecay);
   fChain->SetBranchAddress("GenTauIsoTrackMatched", GenTauIsoTrackMatched, &b_GenTauIsoTrackMatched);
   fChain->SetBranchAddress("GenTauActivity", GenTauActivity, &b_GenTauActivity);
   fChain->SetBranchAddress("Expectation", &Expectation, &b_Expectation);
   fChain->SetBranchAddress("ExpectationReductionIsoTrack", &ExpectationReductionIsoTrack, &b_ExpectationReductionIsoTrack);
   fChain->SetBranchAddress("ExpectationReductionIsoMuTrack", &ExpectationReductionIsoMuTrack, &b_ExpectationReductionIsoMuTrack);
   fChain->SetBranchAddress("ExpectationReductionIsoElecTrack", &ExpectationReductionIsoElecTrack, &b_ExpectationReductionIsoElecTrack);
   fChain->SetBranchAddress("ExpectationReductionIsoPionTrack", &ExpectationReductionIsoPionTrack, &b_ExpectationReductionIsoPionTrack);
   fChain->SetBranchAddress("muAcc", &muAcc, &b_muAcc);
   fChain->SetBranchAddress("muReco", &muReco, &b_muReco);
   fChain->SetBranchAddress("muIso", &muIso, &b_muIso);
   fChain->SetBranchAddress("MTW", &MTW, &b_MTW);
   fChain->SetBranchAddress("IsoTrackMTW", &IsoTrackMTW, &b_IsoTrackMTW);
   fChain->SetBranchAddress("elecAcc", &elecAcc, &b_elecAcc);
   fChain->SetBranchAddress("elecReco", &elecReco, &b_elecReco);
   fChain->SetBranchAddress("elecIso", &elecIso, &b_elecIso);
   fChain->SetBranchAddress("muIsoTrack", &muIsoTrack, &b_muIsoTrack);
   fChain->SetBranchAddress("MuPurity", &MuPurity, &b_MuPurity);
   fChain->SetBranchAddress("ElecPurity", &ElecPurity, &b_ElecPurity);
   fChain->SetBranchAddress("muIsoTrackIso", &muIsoTrackIso, &b_muIsoTrackIso);
   fChain->SetBranchAddress("muIsoTrackReco", &muIsoTrackReco, &b_muIsoTrackReco);
   fChain->SetBranchAddress("elecIsoTrackIso", &elecIsoTrackIso, &b_elecIsoTrackIso);
   fChain->SetBranchAddress("elecIsoTrackReco", &elecIsoTrackReco, &b_elecIsoTrackReco);
   fChain->SetBranchAddress("pionIsoTrackIso", &pionIsoTrackIso, &b_pionIsoTrackIso);
   fChain->SetBranchAddress("pionIsoTrackReco", &pionIsoTrackReco, &b_pionIsoTrackReco);
   fChain->SetBranchAddress("muActivityMethod", &muActivityMethod, &b_muActivityMethod);
   fChain->SetBranchAddress("elecActivityMethod", &elecActivityMethod, &b_elecActivityMethod);
   fChain->SetBranchAddress("muIsoTrackActivityMethod", &muIsoTrackActivityMethod, &b_muIsoTrackActivityMethod);
   fChain->SetBranchAddress("elecIsoTrackActivityMethod", &elecIsoTrackActivityMethod, &b_elecIsoTrackActivityMethod);
   fChain->SetBranchAddress("pionIsoTrackActivityMethod", &pionIsoTrackActivityMethod, &b_pionIsoTrackActivityMethod);
   fChain->SetBranchAddress("FallsVetoLep", &FallsVetoLep, &b_FallsVetoLep);
   fChain->SetBranchAddress("selectedIDIsoMuonsNum", &selectedIDIsoMuonsNum, &b_selectedIDIsoMuonsNum);
   fChain->SetBranchAddress("selectedIDIsoMuonsPt", selectedIDIsoMuonsPt, &b_selectedIDIsoMuonsPt);
   fChain->SetBranchAddress("muIsoMatched", muIsoMatched, &b_muIsoMatched);
   fChain->SetBranchAddress("RecoIsoMuonPromtMatched", RecoIsoMuonPromtMatched, &b_RecoIsoMuonPromtMatched);
   fChain->SetBranchAddress("RecoIsoMuonPromtMatchedDeltaR", RecoIsoMuonPromtMatchedDeltaR, &b_RecoIsoMuonPromtMatchedDeltaR);
   fChain->SetBranchAddress("RecoIsoMuonPromtMatchedRelPt", RecoIsoMuonPromtMatchedRelPt, &b_RecoIsoMuonPromtMatchedRelPt);
   fChain->SetBranchAddress("selectedIDIsoMuonsEta", selectedIDIsoMuonsEta, &b_selectedIDIsoMuonsEta);
   fChain->SetBranchAddress("selectedIDIsoMuonsPhi", selectedIDIsoMuonsPhi, &b_selectedIDIsoMuonsPhi);
   fChain->SetBranchAddress("selectedIDIsoMuonsE", selectedIDIsoMuonsE, &b_selectedIDIsoMuonsE);
   fChain->SetBranchAddress("selectedIDIsoMuons_MTW", selectedIDIsoMuons_MTW, &b_selectedIDIsoMuons_MTW);
   fChain->SetBranchAddress("RecoIsoMuonActivity", RecoIsoMuonActivity, &b_RecoIsoMuonActivity);
   fChain->SetBranchAddress("selectedIDMuonsNum", &selectedIDMuonsNum, &b_selectedIDMuonsNum);
   fChain->SetBranchAddress("selectedIDMuonsPt", selectedIDMuonsPt, &b_selectedIDMuonsPt);
   fChain->SetBranchAddress("selectedIDMuonsMatched", selectedIDMuonsMatched, &b_selectedIDMuonsMatched);
   fChain->SetBranchAddress("selectedIDMuonsEta", selectedIDMuonsEta, &b_selectedIDMuonsEta);
   fChain->SetBranchAddress("selectedIDMuonsPhi", selectedIDMuonsPhi, &b_selectedIDMuonsPhi);
   fChain->SetBranchAddress("selectedIDMuonsE", selectedIDMuonsE, &b_selectedIDMuonsE);
   fChain->SetBranchAddress("selectedIDMuons_MTW", selectedIDMuons_MTW, &b_selectedIDMuons_MTW);
   fChain->SetBranchAddress("RecoMuonActivity", RecoMuonActivity, &b_RecoMuonActivity);
   fChain->SetBranchAddress("RecoIsoMuonIsoTrackMatched", RecoIsoMuonIsoTrackMatched, &b_RecoIsoMuonIsoTrackMatched);
   fChain->SetBranchAddress("selectedIDIsoElectronsNum", &selectedIDIsoElectronsNum, &b_selectedIDIsoElectronsNum);
   fChain->SetBranchAddress("selectedIDIsoElectronsPt", selectedIDIsoElectronsPt, &b_selectedIDIsoElectronsPt);
   fChain->SetBranchAddress("elecIsoMatched", elecIsoMatched, &b_elecIsoMatched);
   fChain->SetBranchAddress("RecoIsoElecPromtMatched", RecoIsoElecPromtMatched, &b_RecoIsoElecPromtMatched);
   fChain->SetBranchAddress("RecoIsoElecPromtMatchedDeltaR", RecoIsoElecPromtMatchedDeltaR, &b_RecoIsoElecPromtMatchedDeltaR);
   fChain->SetBranchAddress("RecoIsoElecPromtMatchedRelPt", RecoIsoElecPromtMatchedRelPt, &b_RecoIsoElecPromtMatchedRelPt);
   fChain->SetBranchAddress("selectedIDIsoElectronsEta", selectedIDIsoElectronsEta, &b_selectedIDIsoElectronsEta);
   fChain->SetBranchAddress("selectedIDIsoElectronsPhi", selectedIDIsoElectronsPhi, &b_selectedIDIsoElectronsPhi);
   fChain->SetBranchAddress("selectedIDIsoElectronsE", selectedIDIsoElectronsE, &b_selectedIDIsoElectronsE);
   fChain->SetBranchAddress("selectedIDIsoElectrons_MTW", selectedIDIsoElectrons_MTW, &b_selectedIDIsoElectrons_MTW);
   fChain->SetBranchAddress("RecoIsoElectronActivity", RecoIsoElectronActivity, &b_RecoIsoElectronActivity);
   fChain->SetBranchAddress("RecoIsoElecIsoTrackMatched", RecoIsoElecIsoTrackMatched, &b_RecoIsoElecIsoTrackMatched);
   fChain->SetBranchAddress("selectedIDElectronsNum", &selectedIDElectronsNum, &b_selectedIDElectronsNum);
   fChain->SetBranchAddress("selectedIDElectronsPt", selectedIDElectronsPt, &b_selectedIDElectronsPt);
   fChain->SetBranchAddress("selectedIDElectronsMatched", selectedIDElectronsMatched, &b_selectedIDElectronsMatched);
   fChain->SetBranchAddress("selectedIDElectronsEta", selectedIDElectronsEta, &b_selectedIDElectronsEta);
   fChain->SetBranchAddress("selectedIDElectronsPhi", selectedIDElectronsPhi, &b_selectedIDElectronsPhi);
   fChain->SetBranchAddress("selectedIDElectronsE", selectedIDElectronsE, &b_selectedIDElectronsE);
   fChain->SetBranchAddress("selectedIDElectrons_MTW", selectedIDElectrons_MTW, &b_selectedIDElectrons_MTW);
   fChain->SetBranchAddress("RecoElectronActivity", RecoElectronActivity, &b_RecoElectronActivity);
   fChain->SetBranchAddress("IsolatedElectronTracksVetoNum", &IsolatedElectronTracksVetoNum, &b_IsolatedElectronTracksVetoNum);
   fChain->SetBranchAddress("IsolatedElectronTracksVetoPt", IsolatedElectronTracksVetoPt, &b_IsolatedElectronTracksVetoPt);
   fChain->SetBranchAddress("IsolatedElectronTracksVetoEta", IsolatedElectronTracksVetoEta, &b_IsolatedElectronTracksVetoEta);
   fChain->SetBranchAddress("IsolatedElectronTracksVetoPhi", IsolatedElectronTracksVetoPhi, &b_IsolatedElectronTracksVetoPhi);
   fChain->SetBranchAddress("IsolatedElectronTracksVetoE", IsolatedElectronTracksVetoE, &b_IsolatedElectronTracksVetoE);
   fChain->SetBranchAddress("IsolatedElectronTracksVetoActivity", IsolatedElectronTracksVetoActivity, &b_IsolatedElectronTracksVetoActivity);
   fChain->SetBranchAddress("IsolatedElectronTracksVetoMTW", IsolatedElectronTracksVetoMTW, &b_IsolatedElectronTracksVetoMTW);
   fChain->SetBranchAddress("muIsoTrackMatchedToGenElec", muIsoTrackMatchedToGenElec, &b_muIsoTrackMatchedToGenElec);
   fChain->SetBranchAddress("elecIsoTrackMatchedToGenElec", elecIsoTrackMatchedToGenElec, &b_elecIsoTrackMatchedToGenElec);
   fChain->SetBranchAddress("pionIsoTrackMatchedToGenElec", pionIsoTrackMatchedToGenElec, &b_pionIsoTrackMatchedToGenElec);
   fChain->SetBranchAddress("IsolatedMuonTracksVetoNum", &IsolatedMuonTracksVetoNum, &b_IsolatedMuonTracksVetoNum);
   fChain->SetBranchAddress("IsolatedMuonTracksVetoPt", IsolatedMuonTracksVetoPt, &b_IsolatedMuonTracksVetoPt);
   fChain->SetBranchAddress("IsolatedMuonTracksVetoEta", IsolatedMuonTracksVetoEta, &b_IsolatedMuonTracksVetoEta);
   fChain->SetBranchAddress("IsolatedMuonTracksVetoPhi", IsolatedMuonTracksVetoPhi, &b_IsolatedMuonTracksVetoPhi);
   fChain->SetBranchAddress("IsolatedMuonTracksVetoE", IsolatedMuonTracksVetoE, &b_IsolatedMuonTracksVetoE);
   fChain->SetBranchAddress("IsolatedMuonTracksVetoActivity", IsolatedMuonTracksVetoActivity, &b_IsolatedMuonTracksVetoActivity);
   fChain->SetBranchAddress("IsolatedMuonTracksVetoMTW", IsolatedMuonTracksVetoMTW, &b_IsolatedMuonTracksVetoMTW);
   fChain->SetBranchAddress("muIsoTrackMatchedToGenMu", muIsoTrackMatchedToGenMu, &b_muIsoTrackMatchedToGenMu);
   fChain->SetBranchAddress("elecIsoTrackMatchedToGenMu", elecIsoTrackMatchedToGenMu, &b_elecIsoTrackMatchedToGenMu);
   fChain->SetBranchAddress("pionIsoTrackMatchedToGenMu", pionIsoTrackMatchedToGenMu, &b_pionIsoTrackMatchedToGenMu);
   fChain->SetBranchAddress("IsolatedPionTracksVetoNum", &IsolatedPionTracksVetoNum, &b_IsolatedPionTracksVetoNum);
   fChain->SetBranchAddress("IsolatedPionTracksVetoPt", IsolatedPionTracksVetoPt, &b_IsolatedPionTracksVetoPt);
   fChain->SetBranchAddress("IsolatedPionTracksVetoEta", IsolatedPionTracksVetoEta, &b_IsolatedPionTracksVetoEta);
   fChain->SetBranchAddress("IsolatedPionTracksVetoPhi", IsolatedPionTracksVetoPhi, &b_IsolatedPionTracksVetoPhi);
   fChain->SetBranchAddress("IsolatedPionTracksVetoE", IsolatedPionTracksVetoE, &b_IsolatedPionTracksVetoE);
   fChain->SetBranchAddress("IsolatedPionTracksVetoActivity", IsolatedPionTracksVetoActivity, &b_IsolatedPionTracksVetoActivity);
   fChain->SetBranchAddress("IsolatedPionTracksVetoMTW", IsolatedPionTracksVetoMTW, &b_IsolatedPionTracksVetoMTW);
   fChain->SetBranchAddress("muIsoTrackMatchedToGenSingleProngTau", muIsoTrackMatchedToGenSingleProngTau, &b_muIsoTrackMatchedToGenSingleProngTau);
   fChain->SetBranchAddress("elecIsoTrackMatchedToGenSingleProngTau", elecIsoTrackMatchedToGenSingleProngTau, &b_elecIsoTrackMatchedToGenSingleProngTau);
   fChain->SetBranchAddress("pionIsoTrackMatchedToGenSingleProngTau", pionIsoTrackMatchedToGenSingleProngTau, &b_pionIsoTrackMatchedToGenSingleProngTau);
   fChain->SetBranchAddress("pionIsoTrackMatchedToGenSingleProngTauCharged", pionIsoTrackMatchedToGenSingleProngTauCharged, &b_pionIsoTrackMatchedToGenSingleProngTauCharged);
   fChain->SetBranchAddress("pionIsoTrackMatchedToGenSingleProngTauNeutral", pionIsoTrackMatchedToGenSingleProngTauNeutral, &b_pionIsoTrackMatchedToGenSingleProngTauNeutral);
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
   fChain->SetBranchAddress("ExpectationDiLep", &ExpectationDiLep, &b_ExpectationDiLep);
   fChain->SetBranchAddress("MuDiLepControlSample", &MuDiLepControlSample, &b_MuDiLepControlSample);
   fChain->SetBranchAddress("ElecDiLepControlSample", &ElecDiLepControlSample, &b_ElecDiLepControlSample);
   fChain->SetBranchAddress("StandAloneGenMuIsoTrackMatched", &StandAloneGenMuIsoTrackMatched, &b_StandAloneGenMuIsoTrackMatched);
   fChain->SetBranchAddress("StandAloneIsoTrackToMuMatched", &StandAloneIsoTrackToMuMatched, &b_StandAloneIsoTrackToMuMatched);
   fChain->SetBranchAddress("StandAloneGenElecIsoTrackMatched", &StandAloneGenElecIsoTrackMatched, &b_StandAloneGenElecIsoTrackMatched);
   fChain->SetBranchAddress("StandAloneIsoTrackToElecMatched", &StandAloneIsoTrackToElecMatched, &b_StandAloneIsoTrackToElecMatched);
   fChain->SetBranchAddress("StandAloneIsoTrackToRecoMuMatched", &StandAloneIsoTrackToRecoMuMatched, &b_StandAloneIsoTrackToRecoMuMatched);
   fChain->SetBranchAddress("StandAloneIsoTrackToRecoElecMatched", &StandAloneIsoTrackToRecoElecMatched, &b_StandAloneIsoTrackToRecoElecMatched);
   fChain->SetBranchAddress("IsoTrackDiLepControlSampleMu", &IsoTrackDiLepControlSampleMu, &b_IsoTrackDiLepControlSampleMu);
   fChain->SetBranchAddress("IsoTrackDiLepControlSampleElec", &IsoTrackDiLepControlSampleElec, &b_IsoTrackDiLepControlSampleElec);
   fChain->SetBranchAddress("IsoTrackDiLepMu", &IsoTrackDiLepMu, &b_IsoTrackDiLepMu);
   fChain->SetBranchAddress("IsoTrackDiLepElec", &IsoTrackDiLepElec, &b_IsoTrackDiLepElec);
   fChain->SetBranchAddress("GenMuWPt", &GenMuWPt, &b_GenMuWPt);
   fChain->SetBranchAddress("GenMuWPhi", &GenMuWPhi, &b_GenMuWPhi);
   fChain->SetBranchAddress("GenElecWPt", &GenElecWPt, &b_GenElecWPt);
   fChain->SetBranchAddress("GenElecWPhi", &GenElecWPhi, &b_GenElecWPhi);
   fChain->SetBranchAddress("GenBosonNum", &GenBosonNum, &b_GenBosonNum);
   fChain->SetBranchAddress("GenBosonPt", GenBosonPt, &b_GenBosonPt);
   fChain->SetBranchAddress("GenBosonPhi", GenBosonPhi, &b_GenBosonPhi);
}

Bool_t TTTTTTTTT::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef TTTTTTTTT_cxx
