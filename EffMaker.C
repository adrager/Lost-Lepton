#define EffMaker_cxx
// The class definition in EffMaker.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("EffMaker.C")
// Root > T->Process("EffMaker.C","some options")
// Root > T->Process("EffMaker.C+")
//

#include "EffMaker.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include "TSystem.h"

void EffMaker::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
}
void EffMaker::SlaveBegin(TTree * /*tree*/)
{
  TString option = GetOption();
  
  // total event count for expecation
  
  totalExpectation_ = new SearchBinEventCount("TotalLostLeptonExpecation");
  // purity
  // muon
  //1D
  MuPurityBTag_ = new TH1F("MuPurityBTag1D","MuPurityBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuPurityBTag_);
  MuPurityBTagFail_ = (TH1F*)MuPurityBTag_->Clone();
  MuPurityBTagFail_->SetName("MuPurityBTag1DFail");
  //GetOutputList()->Add(MuPurityBTagFail_); 
  
  MuPurityNJets_ = new TH1F("MuPurityNJets1D","MuPurityNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuPurityNJets_);
  MuPurityNJetsFail_ = (TH1F*)MuPurityNJets_->Clone();
  MuPurityNJetsFail_->SetName("MuPurityNJets1DFail");
  //GetOutputList()->Add(MuPurityNJetsFail_); 
  
  MuPurityHT_ = new TH1F("MuPurityHT1D","MuPurityHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuPurityHT_);
  MuPurityHTFail_ = (TH1F*)MuPurityHT_->Clone();
  MuPurityHTFail_->SetName("MuPurityHT1DFail");
  //GetOutputList()->Add(MuPurityHTFail_); 
  
  MuPurityMHT_ = new TH1F("MuPurityMHT1D","MuPurityMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuPurityMHT_);
  MuPurityMHTFail_ = (TH1F*)MuPurityMHT_->Clone();
  MuPurityMHTFail_->SetName("MuPurityMHT1DFail");
  //GetOutputList()->Add(MuPurityMHTFail_); 
  //2D
  MuonPurityMHTNJet = new TH2F("MuonPurity","MuonPurity",mupurityMHT_-1,muPurityMHT_,mupurityNJet_-1,muPurityNJet_);
  //GetOutputList()->Add(MuonPurityMHTNJet);
  MuonPurityMHTNJetFail = (TH2F*)MuonPurityMHTNJet->Clone();
  MuonPurityMHTNJetFail->SetName("MuonPurityFail");
  MuonPurityMHTNJetEff_ = new TH2Feff("MuonPurity","MuonPurity",mupurityMHT_-1,muPurityMHT_,mupurityNJet_-1,muPurityNJet_);
  //GetOutputList()->Add(MuonPurityMHTNJetFail);  
  // electron
  //1D
  ElecPurityBTag_ = new TH1F("ElecPurityBTag1D","ElecPurityBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecPurityBTag_);
  ElecPurityBTagFail_ = (TH1F*)ElecPurityBTag_->Clone();
  ElecPurityBTagFail_->SetName("ElecPurityBTag1DFail");
  //GetOutputList()->Add(ElecPurityBTagFail_); 
  
  ElecPurityNJets_ = new TH1F("ElecPurityNJets1D","ElecPurityNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecPurityNJets_);
  ElecPurityNJetsFail_ = (TH1F*)ElecPurityNJets_->Clone();
  ElecPurityNJetsFail_->SetName("ElecPurityNJets1DFail");
  //GetOutputList()->Add(ElecPurityNJetsFail_); 
  
  ElecPurityHT_ = new TH1F("ElecPurityHT1D","ElecPurityHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecPurityHT_);
  ElecPurityHTFail_ = (TH1F*)ElecPurityHT_->Clone();
  ElecPurityHTFail_->SetName("ElecPurityHT1DFail");
  //GetOutputList()->Add(ElecPurityHTFail_); 
  
  ElecPurityMHT_ = new TH1F("ElecPurityMHT1D","ElecPurityMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecPurityMHT_);
  ElecPurityMHTFail_ = (TH1F*)ElecPurityMHT_->Clone();
  ElecPurityMHTFail_->SetName("ElecPurityMHT1DFail");
  //GetOutputList()->Add(ElecPurityMHTFail_); 
  //2D
  std::cout<<"POin5"<<std::endl;
  ElecPurityMHTNJet = new TH2F("ElecPurity","ElecPurity",mupurityMHT_-1,muPurityMHT_,mupurityNJet_-1,muPurityNJet_);
  //GetOutputList()->Add(ElecPurityMHTNJet);
  ElecPurityMHTNJetFail = (TH2F*)ElecPurityMHTNJet->Clone();
  ElecPurityMHTNJetFail->SetName("ElecPurityFail");
  //GetOutputList()->Add(ElecPurityMHTNJetFail); 
  
  //
  
  MuPurityCheckBTag_ = new TH1F("MuPurityCheckBTag1D","MuPurityCheckBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuPurityCheckBTag_);
  MuPurityCheckBTagFail_ = (TH1F*)MuPurityCheckBTag_->Clone();
  MuPurityCheckBTagFail_->SetName("MuPurityCheckBTag1DFail");
  //GetOutputList()->Add(MuPurityCheckBTagFail_); 
  
  MuPurityCheckNJets_ = new TH1F("MuPurityCheckNJets1D","MuPurityCheckNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuPurityCheckNJets_);
  MuPurityCheckNJetsFail_ = (TH1F*)MuPurityCheckNJets_->Clone();
  MuPurityCheckNJetsFail_->SetName("MuPurityCheckNJets1DFail");
  //GetOutputList()->Add(MuPurityCheckNJetsFail_); 
  
  MuPurityCheckHT_ = new TH1F("MuPurityCheckHT1D","MuPurityCheckHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuPurityCheckHT_);
  MuPurityCheckHTFail_ = (TH1F*)MuPurityCheckHT_->Clone();
  MuPurityCheckHTFail_->SetName("MuPurityCheckHT1DFail");
  //GetOutputList()->Add(MuPurityCheckHTFail_); 
  
  MuPurityCheckMHT_ = new TH1F("MuPurityCheckMHT1D","MuPurityCheckMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuPurityCheckMHT_);
  MuPurityCheckMHTFail_ = (TH1F*)MuPurityCheckMHT_->Clone();
  MuPurityCheckMHTFail_->SetName("MuPurityCheckMHT1DFail");
  //GetOutputList()->Add(MuPurityCheckMHTFail_); 
  //2D
  MuonPurityCheckMHTNJet = new TH2F("MuonPurityCheck","MuonPurityCheck",mupurityMHT_-1,muPurityMHT_,mupurityNJet_-1,muPurityNJet_);
  //GetOutputList()->Add(MuonPurityCheckMHTNJet);
  MuonPurityCheckMHTNJetFail = (TH2F*)MuonPurityCheckMHTNJet->Clone();
  MuonPurityCheckMHTNJetFail->SetName("MuonPurityCheckFail");
  //GetOutputList()->Add(MuonPurityCheckMHTNJetFail);  
  // electron
  //1D
  ElecPurityCheckBTag_ = new TH1F("ElecPurityCheckBTag1D","ElecPurityCheckBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecPurityCheckBTag_);
  ElecPurityCheckBTagFail_ = (TH1F*)ElecPurityCheckBTag_->Clone();
  ElecPurityCheckBTagFail_->SetName("ElecPurityCheckBTag1DFail");
  //GetOutputList()->Add(ElecPurityCheckBTagFail_); 
  
  ElecPurityCheckNJets_ = new TH1F("ElecPurityCheckNJets1D","ElecPurityCheckNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecPurityCheckNJets_);
  ElecPurityCheckNJetsFail_ = (TH1F*)ElecPurityCheckNJets_->Clone();
  ElecPurityCheckNJetsFail_->SetName("ElecPurityCheckNJets1DFail");
  //GetOutputList()->Add(ElecPurityCheckNJetsFail_); 
  
  ElecPurityCheckHT_ = new TH1F("ElecPurityCheckHT1D","ElecPurityCheckHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecPurityCheckHT_);
  ElecPurityCheckHTFail_ = (TH1F*)ElecPurityCheckHT_->Clone();
  ElecPurityCheckHTFail_->SetName("ElecPurityCheckHT1DFail");
  //GetOutputList()->Add(ElecPurityCheckHTFail_); 
  
  ElecPurityCheckMHT_ = new TH1F("ElecPurityCheckMHT1D","ElecPurityCheckMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecPurityCheckMHT_);
  ElecPurityCheckMHTFail_ = (TH1F*)ElecPurityCheckMHT_->Clone();
  ElecPurityCheckMHTFail_->SetName("ElecPurityCheckMHT1DFail");
  //GetOutputList()->Add(ElecPurityCheckMHTFail_); 
  //2D
  std::cout<<"POin5"<<std::endl;
  ElecPurityCheckMHTNJet = new TH2F("ElecPurityCheck","ElecPurityCheck",mupurityMHT_-1,muPurityMHT_,mupurityNJet_-1,muPurityNJet_);
  //GetOutputList()->Add(ElecPurityCheckMHTNJet);
  ElecPurityCheckMHTNJetFail = (TH2F*)ElecPurityCheckMHTNJet->Clone();
  ElecPurityCheckMHTNJetFail->SetName("ElecPurityCheckFail");
  //GetOutputList()->Add(ElecPurityCheckMHTNJetFail); 
  
  
  // acceptance
  //muon
  //1D
  MuAccBTag_ = new TH1F("MuAccBTag1D","MuAccBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuAccBTag_);
  MuAccBTagFail_ = (TH1F*)MuAccBTag_->Clone();
  MuAccBTagFail_->SetName("MuAccBTag1DFail");
  //GetOutputList()->Add(MuAccBTagFail_); 
  
  MuAccNJets_ = new TH1F("MuAccNJets1D","MuAccNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuAccNJets_);
  MuAccNJetsFail_ = (TH1F*)MuAccNJets_->Clone();
  MuAccNJetsFail_->SetName("MuAccNJets1DFail");
  //GetOutputList()->Add(MuAccNJetsFail_); 
  
  MuAccHT_ = new TH1F("MuAccHT1D","MuAccHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuAccHT_);
  MuAccHTFail_ = (TH1F*)MuAccHT_->Clone();
  MuAccHTFail_->SetName("MuAccHT1DFail");
  //GetOutputList()->Add(MuAccHTFail_); 
  
  MuAccMHT_ = new TH1F("MuAccMHT1D","MuAccMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuAccMHT_);
  MuAccMHTFail_ = (TH1F*)MuAccMHT_->Clone();
  MuAccMHTFail_->SetName("MuAccMHT1DFail");
  //GetOutputList()->Add(MuAccMHTFail_); 
  
  //2D
  MuAccHTNJets_ = new TH2F("MuAccHTNJets","MuAccHTNJets",muaccHT_-1,muAccHT_, muaccNJets_-1, muAccNJets_);
  //GetOutputList()->Add(MuAccHTNJets_);
  MuAccHTNJetsFail_ = (TH2F*)MuAccHTNJets_->Clone();
  MuAccHTNJetsFail_->SetName("MuAccHTNJetsFail");
  //GetOutputList()->Add(MuAccHTNJetsFail_); 
  
  MuAccMHTNJets_ = new TH2F("MuAccMHTNJets","MuAccMHTNJets",muaccMHT_-1,muAccMHT_, muaccNJets_-1, muAccNJets_);
  //GetOutputList()->Add(MuAccMHTNJets_);
  MuAccMHTNJetsFail_ = (TH2F*)MuAccMHTNJets_->Clone();
  MuAccMHTNJetsFail_->SetName("MuAccMHTNJetsFail");
  //GetOutputList()->Add(MuAccMHTNJetsFail_); 
  MuAccMHTNJetsEff_ = new TH2Feff("MuAccMHTNJets","MuAccMHTNJets",muaccMHT_-1,muAccMHT_, muaccNJets_-1, muAccNJets_);
  
  MuAccBTagNJets_ = new TH2F("MuAccBTagNJets","MuAccBTagNJets",muaccBTags_-1,muAccBTags_, muaccNJets_-1, muAccNJets_);
  //GetOutputList()->Add(MuAccBTagNJets_);
  MuAccBTagNJetsFail_ = (TH2F*)MuAccBTagNJets_->Clone();
  MuAccBTagNJetsFail_->SetName("MuAccBTagNJetsFail");
  
  MuAccBTagNJetsEff_= new TH2Feff("MuAccBTagNJets","MuAccBTagNJets",muaccBTags_-1,muAccBTags_, muaccNJets_-1, muAccNJets_);
  //GetOutputList()->Add(MuAccBTagNJetsFail_); 
  
  MuAccMHTNJetsB0_ = new TH2F("MuAccMHTNJetsB0","MuAccMHTNJetsB0",muaccMHT_-1,muAccMHT_, muaccNJets_-1, muAccNJets_);
  //GetOutputList()->Add(MuAccMHTNJets_);
  MuAccMHTNJetsB0Fail_ = (TH2F*)MuAccMHTNJetsB0_->Clone();
  MuAccMHTNJetsB0Fail_->SetName("MuAccMHTNJetsB0Fail");
  
  MuAccMHTNJetsB1_Inf_ = new TH2F("MuAccMHTNJetsB1_Inf","MuAccMHTNJetsB1_Inf",muaccMHT_-1,muAccMHT_, muaccNJets_-1, muAccNJets_);
  //GetOutputList()->Add(MuAccMHTNJets_);
  MuAccMHTNJetsB1_InfFail_ = (TH2F*)MuAccMHTNJetsB1_Inf_->Clone();
  MuAccMHTNJetsB1_InfFail_->SetName("MuAccMHTNJetsB1_InfFail");
  
  //muon
  //1D
  ElecAccBTag_ = new TH1F("ElecAccBTag1D","ElecAccBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecAccBTag_);
  ElecAccBTagFail_ = (TH1F*)ElecAccBTag_->Clone();
  ElecAccBTagFail_->SetName("ElecAccBTag1DFail");
  //GetOutputList()->Add(ElecAccBTagFail_); 
  
  ElecAccNJets_ = new TH1F("ElecAccNJets1D","ElecAccNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecAccNJets_);
  ElecAccNJetsFail_ = (TH1F*)ElecAccNJets_->Clone();
  ElecAccNJetsFail_->SetName("ElecAccNJets1DFail");
  //GetOutputList()->Add(ElecAccNJetsFail_); 
  
  ElecAccHT_ = new TH1F("ElecAccHT1D","ElecAccHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecAccHT_);
  ElecAccHTFail_ = (TH1F*)ElecAccHT_->Clone();
  ElecAccHTFail_->SetName("ElecAccHT1DFail");
  //GetOutputList()->Add(ElecAccHTFail_); 
  
  ElecAccMHT_ = new TH1F("ElecAccMHT1D","ElecAccMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecAccMHT_);
  ElecAccMHTFail_ = (TH1F*)ElecAccMHT_->Clone();
  ElecAccMHTFail_->SetName("ElecAccMHT1DFail");
  //GetOutputList()->Add(ElecAccMHTFail_); 
  
  //2D
  ElecAccHTNJets_ = new TH2F("ElecAccHTNJets","ElecAccHTNJets",elecaccHT_-1,elecAccHT_, elecaccNJets_-1, elecAccNJets_);
  //GetOutputList()->Add(ElecAccHTNJets_);
  ElecAccHTNJetsFail_ = (TH2F*)ElecAccHTNJets_->Clone();
  ElecAccHTNJetsFail_->SetName("ElecAccHTNJetsFail");
  //GetOutputList()->Add(ElecAccHTNJetsFail_); 
  
  ElecAccMHTNJets_ = new TH2F("ElecAccMHTNJets","ElecAccMHTNJets",elecaccMHT_-1,elecAccMHT_, elecaccNJets_-1, elecAccNJets_);
  //GetOutputList()->Add(ElecAccMHTNJets_);
  ElecAccMHTNJetsFail_ = (TH2F*)ElecAccMHTNJets_->Clone();
  ElecAccMHTNJetsFail_->SetName("ElecAccMHTNJetsFail");
  //GetOutputList()->Add(ElecAccMHTNJetsFail_); 
  
  ElecAccBTagNJets_ = new TH2F("ElecAccBTagNJets","ElecAccBTagNJets",elecaccBTags_-1,elecAccBTags_, elecaccNJets_-1, elecAccNJets_);
  //GetOutputList()->Add(ElecAccBTagNJets_);
  ElecAccBTagNJetsFail_ = (TH2F*)ElecAccBTagNJets_->Clone();
  ElecAccBTagNJetsFail_->SetName("ElecAccBTagNJetsFail");
  //GetOutputList()->Add(ElecAccBTagNJetsFail_); 
  
  ElecAccMHTNJetsB0_ = new TH2F("ElecAccMHTNJetsB0","ElecAccMHTNJetsB0",elecaccMHT_-1,elecAccMHT_, elecaccNJets_-1, elecAccNJets_);
  //GetOutputList()->Add(ElecAccMHTNJets_);
  ElecAccMHTNJetsB0Fail_ = (TH2F*)ElecAccMHTNJetsB0_->Clone();
  ElecAccMHTNJetsB0Fail_->SetName("ElecAccMHTNJetsB0Fail");
  
  ElecAccMHTNJetsB1_Inf_ = new TH2F("ElecAccMHTNJetsB1_Inf","ElecAccMHTNJetsB1_Inf",elecaccMHT_-1,elecAccMHT_, elecaccNJets_-1, elecAccNJets_);
  //GetOutputList()->Add(ElecAccMHTNJets_);
  ElecAccMHTNJetsB1_InfFail_ = (TH2F*)ElecAccMHTNJetsB1_Inf_->Clone();
  ElecAccMHTNJetsB1_InfFail_->SetName("ElecAccMHTNJetsB1_InfFail");
  
  // reconstruction
  //muon
  //1D
  MuRecoBTag_ = new TH1F("MuRecoBTag1D","MuRecoBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuRecoBTag_);
  MuRecoBTagFail_ = (TH1F*)MuRecoBTag_->Clone();
  MuRecoBTagFail_->SetName("MuRecoBTag1DFail");
  //GetOutputList()->Add(MuRecoBTagFail_); 
  
  MuRecoNJets_ = new TH1F("MuRecoNJets1D","MuRecoNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuRecoNJets_);
  MuRecoNJetsFail_ = (TH1F*)MuRecoNJets_->Clone();
  MuRecoNJetsFail_->SetName("MuRecoNJets1DFail");
  //GetOutputList()->Add(MuRecoNJetsFail_); 
  
  MuRecoHT_ = new TH1F("MuRecoHT1D","MuRecoHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuRecoHT_);
  MuRecoHTFail_ = (TH1F*)MuRecoHT_->Clone();
  MuRecoHTFail_->SetName("MuRecoHT1DFail");
  //GetOutputList()->Add(MuRecoHTFail_); 
  
  MuRecoMHT_ = new TH1F("MuRecoMHT1D","MuRecoMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuRecoMHT_);
  MuRecoMHTFail_ = (TH1F*)MuRecoMHT_->Clone();
  MuRecoMHTFail_->SetName("MuRecoMHT1DFail");
  //GetOutputList()->Add(MuRecoMHTFail_); 
  
  //elec
  //1D
  ElecRecoBTag_ = new TH1F("ElecRecoBTag1D","ElecRecoBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecRecoBTag_);
  ElecRecoBTagFail_ = (TH1F*)ElecRecoBTag_->Clone();
  ElecRecoBTagFail_->SetName("ElecRecoBTag1DFail");
  //GetOutputList()->Add(ElecRecoBTagFail_); 
  
  ElecRecoNJets_ = new TH1F("ElecRecoNJets1D","ElecRecoNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecRecoNJets_);
  ElecRecoNJetsFail_ = (TH1F*)ElecRecoNJets_->Clone();
  ElecRecoNJetsFail_->SetName("ElecRecoNJets1DFail");
  //GetOutputList()->Add(ElecRecoNJetsFail_); 
  
  ElecRecoHT_ = new TH1F("ElecRecoHT1D","ElecRecoHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecRecoHT_);
  ElecRecoHTFail_ = (TH1F*)ElecRecoHT_->Clone();
  ElecRecoHTFail_->SetName("ElecRecoHT1DFail");
  //GetOutputList()->Add(ElecRecoHTFail_); 
  
  ElecRecoMHT_ = new TH1F("ElecRecoMHT1D","ElecRecoMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecRecoMHT_);
  ElecRecoMHTFail_ = (TH1F*)ElecRecoMHT_->Clone();
  ElecRecoMHTFail_->SetName("ElecRecoMHT1DFail");
  //GetOutputList()->Add(ElecRecoMHTFail_); 
  
  // isolation
  //muon
  //1D
  MuIsoBTag_ = new TH1F("MuIsoBTag1D","MuIsoBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuIsoBTag_);
  MuIsoBTagFail_ = (TH1F*)MuIsoBTag_->Clone();
  MuIsoBTagFail_->SetName("MuIsoBTag1DFail");
  //GetOutputList()->Add(MuIsoBTagFail_); 
  
  MuIsoNJets_ = new TH1F("MuIsoNJets1D","MuIsoNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuIsoNJets_);
  MuIsoNJetsFail_ = (TH1F*)MuIsoNJets_->Clone();
  MuIsoNJetsFail_->SetName("MuIsoNJets1DFail");
  //GetOutputList()->Add(MuIsoNJetsFail_); 
  
  MuIsoHT_ = new TH1F("MuIsoHT1D","MuIsoHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuIsoHT_);
  MuIsoHTFail_ = (TH1F*)MuIsoHT_->Clone();
  MuIsoHTFail_->SetName("MuIsoHT1DFail");
  //GetOutputList()->Add(MuIsoHTFail_); 
  
  MuIsoMHT_ = new TH1F("MuIsoMHT1D","MuIsoMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuIsoMHT_);
  MuIsoMHTFail_ = (TH1F*)MuIsoMHT_->Clone();
  MuIsoMHTFail_->SetName("MuIsoMHT1DFail");
  //GetOutputList()->Add(MuIsoMHTFail_); 
  
  //elec
  //1D
  ElecIsoBTag_ = new TH1F("ElecIsoBTag1D","ElecIsoBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecIsoBTag_);
  ElecIsoBTagFail_ = (TH1F*)ElecIsoBTag_->Clone();
  ElecIsoBTagFail_->SetName("ElecIsoBTag1DFail");
  //GetOutputList()->Add(ElecIsoBTagFail_); 
  
  ElecIsoNJets_ = new TH1F("ElecIsoNJets1D","ElecIsoNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecIsoNJets_);
  ElecIsoNJetsFail_ = (TH1F*)ElecIsoNJets_->Clone();
  ElecIsoNJetsFail_->SetName("ElecIsoNJets1DFail");
  //GetOutputList()->Add(ElecIsoNJetsFail_); 
  
  ElecIsoHT_ = new TH1F("ElecIsoHT1D","ElecIsoHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecIsoHT_);
  ElecIsoHTFail_ = (TH1F*)ElecIsoHT_->Clone();
  ElecIsoHTFail_->SetName("ElecIsoHT1DFail");
  //GetOutputList()->Add(ElecIsoHTFail_); 
  
  ElecIsoMHT_ = new TH1F("ElecIsoMHT1D","ElecIsoMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecIsoMHT_);
  ElecIsoMHTFail_ = (TH1F*)ElecIsoMHT_->Clone();
  ElecIsoMHTFail_->SetName("ElecIsoMHT1DFail");
  //GetOutputList()->Add(ElecIsoMHTFail_); 
  
  // mtw
  //muon
  //1D
  MuMTWBTag_ = new TH1F("MuMTWBTag1D","MuMTWBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuMTWBTag_);
  MuMTWBTagFail_ = (TH1F*)MuMTWBTag_->Clone();
  MuMTWBTagFail_->SetName("MuMTWBTag1DFail");
  //GetOutputList()->Add(MuMTWBTagFail_); 
  
  MuMTWNJets_ = new TH1F("MuMTWNJets1D","MuMTWNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuMTWNJets_);
  MuMTWNJetsFail_ = (TH1F*)MuMTWNJets_->Clone();
  MuMTWNJetsFail_->SetName("MuMTWNJets1DFail");
  //GetOutputList()->Add(MuMTWNJetsFail_); 
  
  MuMTWHT_ = new TH1F("MuMTWHT1D","MuMTWHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuMTWHT_);
  MuMTWHTFail_ = (TH1F*)MuMTWHT_->Clone();
  MuMTWHTFail_->SetName("MuMTWHT1DFail");
  //GetOutputList()->Add(MuMTWHTFail_); 
  
  MuMTWMHT_ = new TH1F("MuMTWMHT1D","MuMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuMTWMHT_);
  MuMTWMHTFail_ = (TH1F*)MuMTWMHT_->Clone();
  MuMTWMHTFail_->SetName("MuMTWMHT1DFail");
  //GetOutputList()->Add(MuMTWMHTFail_); 
  
  //muon
  //1D
  ElecMTWBTag_ = new TH1F("ElecMTWBTag1D","ElecMTWBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecMTWBTag_);
  ElecMTWBTagFail_ = (TH1F*)ElecMTWBTag_->Clone();
  ElecMTWBTagFail_->SetName("ElecMTWBTag1DFail");
  //GetOutputList()->Add(ElecMTWBTagFail_); 
  
  ElecMTWNJets_ = new TH1F("ElecMTWNJets1D","ElecMTWNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecMTWNJets_);
  ElecMTWNJetsFail_ = (TH1F*)ElecMTWNJets_->Clone();
  ElecMTWNJetsFail_->SetName("ElecMTWNJets1DFail");
  //GetOutputList()->Add(ElecMTWNJetsFail_); 
  
  ElecMTWHT_ = new TH1F("ElecMTWHT1D","ElecMTWHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecMTWHT_);
  ElecMTWHTFail_ = (TH1F*)ElecMTWHT_->Clone();
  ElecMTWHTFail_->SetName("ElecMTWHT1DFail");
  //GetOutputList()->Add(ElecMTWHTFail_); 
  
  ElecMTWMHT_ = new TH1F("ElecMTWMHT1D","ElecMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecMTWMHT_);
  ElecMTWMHTFail_ = (TH1F*)ElecMTWMHT_->Clone();
  ElecMTWMHTFail_->SetName("ElecMTWMHT1DFail");
  //GetOutputList()->Add(ElecMTWMHTFail_); 
  
  // di-lep
  
  // mtw
  //muon
  //1D
  MuDiLepBTag_ = new TH1F("MuDiLepBTag1D","MuDiLepBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuDiLepBTag_);
  MuDiLepBTagFail_ = (TH1F*)MuDiLepBTag_->Clone();
  MuDiLepBTagFail_->SetName("MuDiLepBTag1DFail");
  //GetOutputList()->Add(MuDiLepBTagFail_); 
  
  MuDiLepNJets_ = new TH1F("MuDiLepNJets1D","MuDiLepNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuDiLepNJets_);
  MuDiLepNJetsFail_ = (TH1F*)MuDiLepNJets_->Clone();
  MuDiLepNJetsFail_->SetName("MuDiLepNJets1DFail");
  //GetOutputList()->Add(MuDiLepNJetsFail_); 
  
  MuDiLepHT_ = new TH1F("MuDiLepHT1D","MuDiLepHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuDiLepHT_);
  MuDiLepHTFail_ = (TH1F*)MuDiLepHT_->Clone();
  MuDiLepHTFail_->SetName("MuDiLepHT1DFail");
  //GetOutputList()->Add(MuDiLepHTFail_); 
  
  MuDiLepMHT_ = new TH1F("MuDiLepMHT1D","MuDiLepMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuDiLepMHT_);
  MuDiLepMHTFail_ = (TH1F*)MuDiLepMHT_->Clone();
  MuDiLepMHTFail_->SetName("MuDiLepMHT1DFail");
  //GetOutputList()->Add(MuDiLepMHTFail_); 
  
  //muon
  //1D
  ElecDiLepBTag_ = new TH1F("ElecDiLepBTag1D","ElecDiLepBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecDiLepBTag_);
  ElecDiLepBTagFail_ = (TH1F*)ElecDiLepBTag_->Clone();
  ElecDiLepBTagFail_->SetName("ElecDiLepBTag1DFail");
  //GetOutputList()->Add(ElecDiLepBTagFail_); 
  
  ElecDiLepNJets_ = new TH1F("ElecDiLepNJets1D","ElecDiLepNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecDiLepNJets_);
  ElecDiLepNJetsFail_ = (TH1F*)ElecDiLepNJets_->Clone();
  ElecDiLepNJetsFail_->SetName("ElecDiLepNJets1DFail");
  //GetOutputList()->Add(ElecDiLepNJetsFail_); 
  
  ElecDiLepHT_ = new TH1F("ElecDiLepHT1D","ElecDiLepHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecDiLepHT_);
  ElecDiLepHTFail_ = (TH1F*)ElecDiLepHT_->Clone();
  ElecDiLepHTFail_->SetName("ElecDiLepHT1DFail");
  //GetOutputList()->Add(ElecDiLepHTFail_); 
  
  ElecDiLepMHT_ = new TH1F("ElecDiLepMHT1D","ElecDiLepMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecDiLepMHT_);
  ElecDiLepMHTFail_ = (TH1F*)ElecDiLepMHT_->Clone();
  ElecDiLepMHTFail_->SetName("ElecDiLepMHT1DFail");
  //GetOutputList()->Add(ElecDiLepMHTFail_); 
  
  
  // combined di lep eff
  
  DiLepBTag_ = new TH1F("DiLepBTag1D","DiLepBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(DiLepBTag_);
  DiLepBTagFail_ = (TH1F*)DiLepBTag_->Clone();
  DiLepBTagFail_->SetName("DiLepBTag1DFail");
  //GetOutputList()->Add(DiLepBTagFail_); 
  
  DiLepNJets_ = new TH1F("DiLepNJets1D","DiLepNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(DiLepNJets_);
  DiLepNJetsFail_ = (TH1F*)DiLepNJets_->Clone();
  DiLepNJetsFail_->SetName("DiLepNJets1DFail");
  //GetOutputList()->Add(DiLepNJetsFail_); 
  
  DiLepHT_ = new TH1F("DiLepHT1D","DiLepHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(DiLepHT_);
  DiLepHTFail_ = (TH1F*)DiLepHT_->Clone();
  DiLepHTFail_->SetName("DiLepHT1DFail");
  //GetOutputList()->Add(DiLepHTFail_); 
  
  DiLepMHT_ = new TH1F("DiLepMHT1D","DiLepMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(DiLepMHT_);
  DiLepMHTFail_ = (TH1F*)DiLepMHT_->Clone();
  DiLepMHTFail_->SetName("DiLepMHT1DFail");
  //GetOutputList()->Add(DiLepMHTFail_); 
  
  
  // mtw
  //muon
  //1D
  MuDiLepMTWBTag_ = new TH1F("MuDiLepMTWBTag1D","MuDiLepMTWBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuDiLepMTWBTag_);
  MuDiLepMTWBTagFail_ = (TH1F*)MuDiLepMTWBTag_->Clone();
  MuDiLepMTWBTagFail_->SetName("MuDiLepMTWBTag1DFail");
  //GetOutputList()->Add(MuDiLepMTWBTagFail_); 
  
  MuDiLepMTWNJets_ = new TH1F("MuDiLepMTWNJets1D","MuDiLepMTWNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuDiLepMTWNJets_);
  MuDiLepMTWNJetsFail_ = (TH1F*)MuDiLepMTWNJets_->Clone();
  MuDiLepMTWNJetsFail_->SetName("MuDiLepMTWNJets1DFail");
  //GetOutputList()->Add(MuDiLepMTWNJetsFail_); 
  
  MuDiLepMTWHT_ = new TH1F("MuDiLepMTWHT1D","MuDiLepMTWHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuDiLepMTWHT_);
  MuDiLepMTWHTFail_ = (TH1F*)MuDiLepMTWHT_->Clone();
  MuDiLepMTWHTFail_->SetName("MuDiLepMTWHT1DFail");
  //GetOutputList()->Add(MuDiLepMTWHTFail_); 
  
  MuDiLepMTWMHT_ = new TH1F("MuDiLepMTWMHT1D","MuDiLepMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuDiLepMTWMHT_);
  MuDiLepMTWMHTFail_ = (TH1F*)MuDiLepMTWMHT_->Clone();
  MuDiLepMTWMHTFail_->SetName("MuDiLepMTWMHT1DFail");
  //GetOutputList()->Add(MuDiLepMTWMHTFail_); 
  
  //muon
  //1D
  ElecDiLepMTWBTag_ = new TH1F("ElecDiLepMTWBTag1D","ElecDiLepMTWBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecDiLepMTWBTag_);
  ElecDiLepMTWBTagFail_ = (TH1F*)ElecDiLepMTWBTag_->Clone();
  ElecDiLepMTWBTagFail_->SetName("ElecDiLepMTWBTag1DFail");
  //GetOutputList()->Add(ElecDiLepMTWBTagFail_); 
  
  ElecDiLepMTWNJets_ = new TH1F("ElecDiLepMTWNJets1D","ElecDiLepMTWNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecDiLepMTWNJets_);
  ElecDiLepMTWNJetsFail_ = (TH1F*)ElecDiLepMTWNJets_->Clone();
  ElecDiLepMTWNJetsFail_->SetName("ElecDiLepMTWNJets1DFail");
  //GetOutputList()->Add(ElecDiLepMTWNJetsFail_); 
  
  ElecDiLepMTWHT_ = new TH1F("ElecDiLepMTWHT1D","ElecDiLepMTWHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecDiLepMTWHT_);
  ElecDiLepMTWHTFail_ = (TH1F*)ElecDiLepMTWHT_->Clone();
  ElecDiLepMTWHTFail_->SetName("ElecDiLepMTWHT1DFail");
  //GetOutputList()->Add(ElecDiLepMTWHTFail_); 
  
  ElecDiLepMTWMHT_ = new TH1F("ElecDiLepMTWMHT1D","ElecDiLepMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecDiLepMTWMHT_);
  ElecDiLepMTWMHTFail_ = (TH1F*)ElecDiLepMTWMHT_->Clone();
  ElecDiLepMTWMHTFail_->SetName("ElecDiLepMTWMHT1DFail");
  //GetOutputList()->Add(ElecDiLepMTWMHTFail_); 
  
  
  // mtw
  //muon
  //1D
  MuDiLepContributionBTag_ = new TH1F("MuDiLepContributionBTag1D","MuDiLepContributionBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuDiLepContributionBTag_);
  MuDiLepContributionBTagFail_ = (TH1F*)MuDiLepContributionBTag_->Clone();
  MuDiLepContributionBTagFail_->SetName("MuDiLepContributionBTag1DFail");
  //GetOutputList()->Add(MuDiLepContributionBTagFail_); 
  
  MuDiLepContributionNJets_ = new TH1F("MuDiLepContributionNJets1D","MuDiLepContributionNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuDiLepContributionNJets_);
  MuDiLepContributionNJetsFail_ = (TH1F*)MuDiLepContributionNJets_->Clone();
  MuDiLepContributionNJetsFail_->SetName("MuDiLepContributionNJets1DFail");
  //GetOutputList()->Add(MuDiLepContributionNJetsFail_); 
  
  MuDiLepContributionHT_ = new TH1F("MuDiLepContributionHT1D","MuDiLepContributionHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuDiLepContributionHT_);
  MuDiLepContributionHTFail_ = (TH1F*)MuDiLepContributionHT_->Clone();
  MuDiLepContributionHTFail_->SetName("MuDiLepContributionHT1DFail");
  //GetOutputList()->Add(MuDiLepContributionHTFail_); 
  
  MuDiLepContributionMHT_ = new TH1F("MuDiLepContributionMHT1D","MuDiLepContributionMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuDiLepContributionMHT_);
  MuDiLepContributionMHTFail_ = (TH1F*)MuDiLepContributionMHT_->Clone();
  MuDiLepContributionMHTFail_->SetName("MuDiLepContributionMHT1DFail");
  //GetOutputList()->Add(MuDiLepContributionMHTFail_); 
  
  //muon
  //1D
  ElecDiLepContributionBTag_ = new TH1F("ElecDiLepContributionBTag1D","ElecDiLepContributionBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecDiLepContributionBTag_);
  ElecDiLepContributionBTagFail_ = (TH1F*)ElecDiLepContributionBTag_->Clone();
  ElecDiLepContributionBTagFail_->SetName("ElecDiLepContributionBTag1DFail");
  //GetOutputList()->Add(ElecDiLepContributionBTagFail_); 
  
  ElecDiLepContributionNJets_ = new TH1F("ElecDiLepContributionNJets1D","ElecDiLepContributionNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecDiLepContributionNJets_);
  ElecDiLepContributionNJetsFail_ = (TH1F*)ElecDiLepContributionNJets_->Clone();
  ElecDiLepContributionNJetsFail_->SetName("ElecDiLepContributionNJets1DFail");
  //GetOutputList()->Add(ElecDiLepContributionNJetsFail_); 
  
  ElecDiLepContributionHT_ = new TH1F("ElecDiLepContributionHT1D","ElecDiLepContributionHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecDiLepContributionHT_);
  ElecDiLepContributionHTFail_ = (TH1F*)ElecDiLepContributionHT_->Clone();
  ElecDiLepContributionHTFail_->SetName("ElecDiLepContributionHT1DFail");
  //GetOutputList()->Add(ElecDiLepContributionHTFail_); 
  
  ElecDiLepContributionMHT_ = new TH1F("ElecDiLepContributionMHT1D","ElecDiLepContributionMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecDiLepContributionMHT_);
  ElecDiLepContributionMHTFail_ = (TH1F*)ElecDiLepContributionMHT_->Clone();
  ElecDiLepContributionMHTFail_->SetName("ElecDiLepContributionMHT1DFail");
  //GetOutputList()->Add(ElecDiLepContributionMHTFail_); 
  
  
  // mtw
  //muon
  //1D
  MuDiLepContributionMTWBTag_ = new TH1F("MuDiLepContributionMTWBTag1D","MuDiLepContributionMTWBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(MuDiLepContributionMTWBTag_);
  MuDiLepContributionMTWBTagFail_ = (TH1F*)MuDiLepContributionMTWBTag_->Clone();
  MuDiLepContributionMTWBTagFail_->SetName("MuDiLepContributionMTWBTag1DFail");
  //GetOutputList()->Add(MuDiLepContributionMTWBTagFail_); 
  
  MuDiLepContributionMTWNJets_ = new TH1F("MuDiLepContributionMTWNJets1D","MuDiLepContributionMTWNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(MuDiLepContributionMTWNJets_);
  MuDiLepContributionMTWNJetsFail_ = (TH1F*)MuDiLepContributionMTWNJets_->Clone();
  MuDiLepContributionMTWNJetsFail_->SetName("MuDiLepContributionMTWNJets1DFail");
  //GetOutputList()->Add(MuDiLepContributionMTWNJetsFail_); 
  
  MuDiLepContributionMTWHT_ = new TH1F("MuDiLepContributionMTWHT1D","MuDiLepContributionMTWHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(MuDiLepContributionMTWHT_);
  MuDiLepContributionMTWHTFail_ = (TH1F*)MuDiLepContributionMTWHT_->Clone();
  MuDiLepContributionMTWHTFail_->SetName("MuDiLepContributionMTWHT1DFail");
  //GetOutputList()->Add(MuDiLepContributionMTWHTFail_); 
  
  MuDiLepContributionMTWMHT_ = new TH1F("MuDiLepContributionMTWMHT1D","MuDiLepContributionMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(MuDiLepContributionMTWMHT_);
  MuDiLepContributionMTWMHTFail_ = (TH1F*)MuDiLepContributionMTWMHT_->Clone();
  MuDiLepContributionMTWMHTFail_->SetName("MuDiLepContributionMTWMHT1DFail");
  //GetOutputList()->Add(MuDiLepContributionMTWMHTFail_); 
  
  //muon
  //1D
  ElecDiLepContributionMTWBTag_ = new TH1F("ElecDiLepContributionMTWBTag1D","ElecDiLepContributionMTWBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(ElecDiLepContributionMTWBTag_);
  ElecDiLepContributionMTWBTagFail_ = (TH1F*)ElecDiLepContributionMTWBTag_->Clone();
  ElecDiLepContributionMTWBTagFail_->SetName("ElecDiLepContributionMTWBTag1DFail");
  //GetOutputList()->Add(ElecDiLepContributionMTWBTagFail_); 
  
  ElecDiLepContributionMTWNJets_ = new TH1F("ElecDiLepContributionMTWNJets1D","ElecDiLepContributionMTWNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecDiLepContributionMTWNJets_);
  ElecDiLepContributionMTWNJetsFail_ = (TH1F*)ElecDiLepContributionMTWNJets_->Clone();
  ElecDiLepContributionMTWNJetsFail_->SetName("ElecDiLepContributionMTWNJets1DFail");
  //GetOutputList()->Add(ElecDiLepContributionMTWNJetsFail_); 
  
  ElecDiLepContributionMTWHT_ = new TH1F("ElecDiLepContributionMTWHT1D","ElecDiLepContributionMTWHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecDiLepContributionMTWHT_);
  ElecDiLepContributionMTWHTFail_ = (TH1F*)ElecDiLepContributionMTWHT_->Clone();
  ElecDiLepContributionMTWHTFail_->SetName("ElecDiLepContributionMTWHT1DFail");
  //GetOutputList()->Add(ElecDiLepContributionMTWHTFail_); 
  
  ElecDiLepContributionMTWMHT_ = new TH1F("ElecDiLepContributionMTWMHT1D","ElecDiLepContributionMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecDiLepContributionMTWMHT_);
  ElecDiLepContributionMTWMHTFail_ = (TH1F*)ElecDiLepContributionMTWMHT_->Clone();
  ElecDiLepContributionMTWMHTFail_->SetName("ElecDiLepContributionMTWMHT1DFail");
  //GetOutputList()->Add(ElecDiLepContributionMTWMHTFail_); 
  
  // Isolated Track
  
  //Mu
  
  IsoTrackMuBTag_ = new TH1F("IsoTrackMuBTag1D","IsoTrackMuBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(IsoTrackMuBTag_);
  IsoTrackMuBTagFail_ = (TH1F*)IsoTrackMuBTag_->Clone();
  IsoTrackMuBTagFail_->SetName("IsoTrackMuBTag1DFail");
  //GetOutputList()->Add(IsoTrackMuBTagFail_); 
  
  IsoTrackMuNJets_ = new TH1F("IsoTrackMuNJets1D","IsoTrackMuNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(IsoTrackMuNJets_);
  IsoTrackMuNJetsFail_ = (TH1F*)IsoTrackMuNJets_->Clone();
  IsoTrackMuNJetsFail_->SetName("IsoTrackMuNJets1DFail");
  //GetOutputList()->Add(IsoTrackMuNJetsFail_); 
  
  IsoTrackMuHT_ = new TH1F("IsoTrackMuHT1D","IsoTrackMuHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(IsoTrackMuHT_);
  IsoTrackMuHTFail_ = (TH1F*)IsoTrackMuHT_->Clone();
  IsoTrackMuHTFail_->SetName("IsoTrackMuHT1DFail");
  //GetOutputList()->Add(IsoTrackMuHTFail_); 
  
  IsoTrackMuMHT_ = new TH1F("IsoTrackMuMHT1D","IsoTrackMuMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(IsoTrackMuMHT_);
  IsoTrackMuMHTFail_ = (TH1F*)IsoTrackMuMHT_->Clone();
  IsoTrackMuMHTFail_->SetName("IsoTrackMuMHT1DFail");
  //GetOutputList()->Add(IsoTrackMuMHTFail_); 
  // 2D
  IsoTrackMuPTActivity_ = new TH2F("IsoTrackMuPTActivity","IsoTrackMuPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecRecoPTActivity_);
  IsoTrackMuPTActivityFail_ = (TH2F*)IsoTrackMuPTActivity_->Clone();
  IsoTrackMuPTActivityFail_->SetName("IsoTrackMuPTActivityFail");
  //GetOutputList()->Add(ElecRecoPTActivityFail_); 
  
  // match to isolated muon
  IsoTrackMuMatchedToIsoMuBTag_ = new TH1F("IsoTrackMuMatchedToIsoMuBTag1D","IsoTrackMuMatchedToIsoMuBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(IsoTrackMuMatchedToIsoMuBTag_);
  IsoTrackMuMatchedToIsoMuBTagFail_ = (TH1F*)IsoTrackMuMatchedToIsoMuBTag_->Clone();
  IsoTrackMuMatchedToIsoMuBTagFail_->SetName("IsoTrackMuMatchedToIsoMuBTag1DFail");
  //GetOutputList()->Add(IsoTrackMuMatchedToIsoMuBTagFail_); 
  
  IsoTrackMuMatchedToIsoMuNJets_ = new TH1F("IsoTrackMuMatchedToIsoMuNJets1D","IsoTrackMuMatchedToIsoMuNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(IsoTrackMuMatchedToIsoMuNJets_);
  IsoTrackMuMatchedToIsoMuNJetsFail_ = (TH1F*)IsoTrackMuMatchedToIsoMuNJets_->Clone();
  IsoTrackMuMatchedToIsoMuNJetsFail_->SetName("IsoTrackMuMatchedToIsoMuNJets1DFail");
  //GetOutputList()->Add(IsoTrackMuMatchedToIsoMuNJetsFail_); 
  
  IsoTrackMuMatchedToIsoMuHT_ = new TH1F("IsoTrackMuMatchedToIsoMuHT1D","IsoTrackMuMatchedToIsoMuHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(IsoTrackMuMatchedToIsoMuHT_);
  IsoTrackMuMatchedToIsoMuHTFail_ = (TH1F*)IsoTrackMuMatchedToIsoMuHT_->Clone();
  IsoTrackMuMatchedToIsoMuHTFail_->SetName("IsoTrackMuMatchedToIsoMuHT1DFail");
  //GetOutputList()->Add(IsoTrackMuMatchedToIsoMuHTFail_); 
  
  IsoTrackMuMatchedToIsoMuMHT_ = new TH1F("IsoTrackMuMatchedToIsoMuMHT1D","IsoTrackMuMatchedToIsoMuMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(IsoTrackMuMatchedToIsoMuMHT_);
  IsoTrackMuMatchedToIsoMuMHTFail_ = (TH1F*)IsoTrackMuMatchedToIsoMuMHT_->Clone();
  IsoTrackMuMatchedToIsoMuMHTFail_->SetName("IsoTrackMuMatchedToIsoMuMHT1DFail");
  //GetOutputList()->Add(IsoTrackMuMatchedToIsoMuMHTFail_); 
  
  
  
  IsoTrackMuMTWBTag_ = new TH1F("IsoTrackMuMTWBTag1D","IsoTrackMuMTWBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(IsoTrackMuMTWBTag_);
  IsoTrackMuMTWBTagFail_ = (TH1F*)IsoTrackMuMTWBTag_->Clone();
  IsoTrackMuMTWBTagFail_->SetName("IsoTrackMuMTWBTag1DFail");
  //GetOutputList()->Add(IsoTrackMuMTWBTagFail_); 
  
  IsoTrackMuMTWNJets_ = new TH1F("IsoTrackMuMTWNJets1D","IsoTrackMuMTWNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(IsoTrackMuMTWNJets_);
  IsoTrackMuMTWNJetsFail_ = (TH1F*)IsoTrackMuMTWNJets_->Clone();
  IsoTrackMuMTWNJetsFail_->SetName("IsoTrackMuMTWNJets1DFail");
  //GetOutputList()->Add(IsoTrackMuMTWNJetsFail_); 
  
  IsoTrackMuMTWHT_ = new TH1F("IsoTrackMuMTWHT1D","IsoTrackMuMTWHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(IsoTrackMuMTWHT_);
  IsoTrackMuMTWHTFail_ = (TH1F*)IsoTrackMuMTWHT_->Clone();
  IsoTrackMuMTWHTFail_->SetName("IsoTrackMuMTWHT1DFail");
  //GetOutputList()->Add(IsoTrackMuMTWHTFail_); 
  
  IsoTrackMuMTWMHT_ = new TH1F("IsoTrackMuMTWMHT1D","IsoTrackMuMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(IsoTrackMuMTWMHT_);
  IsoTrackMuMTWMHTFail_ = (TH1F*)IsoTrackMuMTWMHT_->Clone();
  IsoTrackMuMTWMHTFail_->SetName("IsoTrackMuMTWMHT1DFail");
  //GetOutputList()->Add(IsoTrackMuMTWMHTFail_); 
  
  //Elec
  
  IsoTrackElecBTag_ = new TH1F("IsoTrackElecBTag1D","IsoTrackElecBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(IsoTrackElecBTag_);
  IsoTrackElecBTagFail_ = (TH1F*)IsoTrackElecBTag_->Clone();
  IsoTrackElecBTagFail_->SetName("IsoTrackElecBTag1DFail");
  //GetOutputList()->Add(IsoTrackElecBTagFail_); 
  
  IsoTrackElecNJets_ = new TH1F("IsoTrackElecNJets1D","IsoTrackElecNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(IsoTrackElecNJets_);
  IsoTrackElecNJetsFail_ = (TH1F*)IsoTrackElecNJets_->Clone();
  IsoTrackElecNJetsFail_->SetName("IsoTrackElecNJets1DFail");
  //GetOutputList()->Add(IsoTrackElecNJetsFail_); 
  
  IsoTrackElecHT_ = new TH1F("IsoTrackElecHT1D","IsoTrackElecHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(IsoTrackElecHT_);
  IsoTrackElecHTFail_ = (TH1F*)IsoTrackElecHT_->Clone();
  IsoTrackElecHTFail_->SetName("IsoTrackElecHT1DFail");
  //GetOutputList()->Add(IsoTrackElecHTFail_); 
  
  IsoTrackElecMHT_ = new TH1F("IsoTrackElecMHT1D","IsoTrackElecMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(IsoTrackElecMHT_);
  IsoTrackElecMHTFail_ = (TH1F*)IsoTrackElecMHT_->Clone();
  IsoTrackElecMHTFail_->SetName("IsoTrackElecMHT1DFail");
  //GetOutputList()->Add(IsoTrackElecMHTFail_); 
  
  //2D
  IsoTrackElecPTActivity_ = new TH2F("IsoTrackElecPTActivity","IsoTrackElecPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecRecoPTActivity_);
  IsoTrackElecPTActivityFail_ = (TH2F*)IsoTrackElecPTActivity_->Clone();
  IsoTrackElecPTActivityFail_->SetName("IsoTrackElecPTActivityFail");
  
  
  IsoTrackElecMTWBTag_ = new TH1F("IsoTrackElecMTWBTag1D","IsoTrackElecMTWBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(IsoTrackElecMTWBTag_);
  IsoTrackElecMTWBTagFail_ = (TH1F*)IsoTrackElecMTWBTag_->Clone();
  IsoTrackElecMTWBTagFail_->SetName("IsoTrackElecMTWBTag1DFail");
  //GetOutputList()->Add(IsoTrackElecMTWBTagFail_); 
  
  IsoTrackElecMTWNJets_ = new TH1F("IsoTrackElecMTWNJets1D","IsoTrackElecMTWNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(IsoTrackElecMTWNJets_);
  IsoTrackElecMTWNJetsFail_ = (TH1F*)IsoTrackElecMTWNJets_->Clone();
  IsoTrackElecMTWNJetsFail_->SetName("IsoTrackElecMTWNJets1DFail");
  //GetOutputList()->Add(IsoTrackElecMTWNJetsFail_); 
  
  IsoTrackElecMTWHT_ = new TH1F("IsoTrackElecMTWHT1D","IsoTrackElecMTWHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(IsoTrackElecMTWHT_);
  IsoTrackElecMTWHTFail_ = (TH1F*)IsoTrackElecMTWHT_->Clone();
  IsoTrackElecMTWHTFail_->SetName("IsoTrackElecMTWHT1DFail");
  //GetOutputList()->Add(IsoTrackElecMTWHTFail_); 
  
  IsoTrackElecMTWMHT_ = new TH1F("IsoTrackElecMTWMHT1D","IsoTrackElecMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(IsoTrackElecMTWMHT_);
  IsoTrackElecMTWMHTFail_ = (TH1F*)IsoTrackElecMTWMHT_->Clone();
  IsoTrackElecMTWMHTFail_->SetName("IsoTrackElecMTWMHT1DFail");
  //GetOutputList()->Add(IsoTrackElecMTWMHTFail_); 
  
  
  // match to isolated muon
  IsoTrackElecMatchedToIsoElecBTag_ = new TH1F("IsoTrackElecMatchedToIsoElecBTag1D","IsoTrackElecMatchedToIsoElecBTag1D",oneDBJets_-1,OneDBJets_);
  //GetOutputList()->Add(IsoTrackElecMatchedToIsoElecBTag_);
  IsoTrackElecMatchedToIsoElecBTagFail_ = (TH1F*)IsoTrackElecMatchedToIsoElecBTag_->Clone();
  IsoTrackElecMatchedToIsoElecBTagFail_->SetName("IsoTrackElecMatchedToIsoElecBTag1DFail");
  //GetOutputList()->Add(IsoTrackElecMatchedToIsoElecBTagFail_); 
  
  IsoTrackElecMatchedToIsoElecNJets_ = new TH1F("IsoTrackElecMatchedToIsoElecNJets1D","IsoTrackElecMatchedToIsoElecNJets1D",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(IsoTrackElecMatchedToIsoElecNJets_);
  IsoTrackElecMatchedToIsoElecNJetsFail_ = (TH1F*)IsoTrackElecMatchedToIsoElecNJets_->Clone();
  IsoTrackElecMatchedToIsoElecNJetsFail_->SetName("IsoTrackElecMatchedToIsoElecNJets1DFail");
  //GetOutputList()->Add(IsoTrackElecMatchedToIsoElecNJetsFail_); 
  
  IsoTrackElecMatchedToIsoElecHT_ = new TH1F("IsoTrackElecMatchedToIsoElecHT1D","IsoTrackElecMatchedToIsoElecHT1D",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(IsoTrackElecMatchedToIsoElecHT_);
  IsoTrackElecMatchedToIsoElecHTFail_ = (TH1F*)IsoTrackElecMatchedToIsoElecHT_->Clone();
  IsoTrackElecMatchedToIsoElecHTFail_->SetName("IsoTrackElecMatchedToIsoElecHT1DFail");
  //GetOutputList()->Add(IsoTrackElecMatchedToIsoElecHTFail_); 
  
  IsoTrackElecMatchedToIsoElecMHT_ = new TH1F("IsoTrackElecMatchedToIsoElecMHT1D","IsoTrackElecMatchedToIsoElecMHT1D",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(IsoTrackElecMatchedToIsoElecMHT_);
  IsoTrackElecMatchedToIsoElecMHTFail_ = (TH1F*)IsoTrackElecMatchedToIsoElecMHT_->Clone();
  IsoTrackElecMatchedToIsoElecMHTFail_->SetName("IsoTrackElecMatchedToIsoElecMHT1DFail");
  //GetOutputList()->Add(IsoTrackElecMatchedToIsoElecMHTFail_); 
  
  // acitivity and pt
  
  MuPurityPT_ = new TH1F("MuPurityPT","MuPurityPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuPurityPT_);
  MuPurityPTFail_ = (TH1F*)MuPurityPT_->Clone();
  MuPurityPTFail_->SetName("MuPurityPTFail");
  //GetOutputList()->Add(MuPurityPTFail_); 
  
  MuPurityActivity_ = new TH1F("MuPurityActivity","MuPurityActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuPurityActivity_);
  MuPurityActivityFail_ = (TH1F*)MuPurityActivity_->Clone();
  MuPurityActivityFail_->SetName("MuPurityActivityFail");
  //GetOutputList()->Add(MuPurityActivityFail_); 
  
  MuAccPT_ = new TH1F("MuAccPT","MuAccPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuAccPT_);
  MuAccPTFail_ = (TH1F*)MuAccPT_->Clone();
  MuAccPTFail_->SetName("MuAccPTFail");
  //GetOutputList()->Add(MuAccPTFail_); 
  
  MuAccActivity_ = new TH1F("MuAccActivity","MuAccActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuAccActivity_);
  MuAccActivityFail_ = (TH1F*)MuAccActivity_->Clone();
  MuAccActivityFail_->SetName("MuAccActivityFail");
  //GetOutputList()->Add(MuAccActivityFail_); 
  
  
  MuRecoPT_ = new TH1F("MuRecoPT","MuRecoPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuRecoPT_);
  MuRecoPTFail_ = (TH1F*)MuRecoPT_->Clone();
  MuRecoPTFail_->SetName("MuRecoPTFail");
  //GetOutputList()->Add(MuRecoPTFail_); 
  
  MuRecoActivity_ = new TH1F("MuRecoActivity","MuRecoActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuRecoActivity_);
  MuRecoActivityFail_ = (TH1F*)MuRecoActivity_->Clone();
  MuRecoActivityFail_->SetName("MuRecoActivityFail");
  //GetOutputList()->Add(MuRecoActivityFail_); 
  
  MuIsoPT_ = new TH1F("MuIsoPT","MuIsoPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuIsoPT_);
  MuIsoPTFail_ = (TH1F*)MuIsoPT_->Clone();
  MuIsoPTFail_->SetName("MuIsoPTFail");
  //GetOutputList()->Add(MuIsoPTFail_); 
  
  
  
  MuIsoActivity_ = new TH1F("MuIsoActivity","MuIsoActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuIsoActivity_);
  MuIsoActivityFail_ = (TH1F*)MuIsoActivity_->Clone();
  MuIsoActivityFail_->SetName("MuIsoActivityFail");
  //GetOutputList()->Add(MuIsoActivityFail_); 
  
  MuMTWPT_ = new TH1F("MuMTWPT","MuMTWPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuMTWPT_);
  MuMTWPTFail_ = (TH1F*)MuMTWPT_->Clone();
  MuMTWPTFail_->SetName("MuMTWPTFail");
  //GetOutputList()->Add(MuMTWPTFail_); 
  
  MuMTWActivity_ = new TH1F("MuMTWActivity","MuMTWActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuMTWActivity_);
  MuMTWActivityFail_ = (TH1F*)MuMTWActivity_->Clone();
  MuMTWActivityFail_->SetName("MuMTWActivityFail");
  //GetOutputList()->Add(MuMTWActivityFail_); 
  
  MuDiLepPT_ = new TH1F("MuDiLepPT","MuDiLepPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuDiLepPT_);
  MuDiLepPTFail_ = (TH1F*)MuDiLepPT_->Clone();
  MuDiLepPTFail_->SetName("MuDiLepPTFail");
  //GetOutputList()->Add(MuDiLepPTFail_); 
  
  MuDiLepActivity_ = new TH1F("MuDiLepActivity","MuDiLepActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuDiLepActivity_);
  MuDiLepActivityFail_ = (TH1F*)MuDiLepActivity_->Clone();
  MuDiLepActivityFail_->SetName("MuDiLepActivityFail");
  //GetOutputList()->Add(MuDiLepActivityFail_); 
  
  
  MuDiLepMTWPT_ = new TH1F("MuDiLepMTWPT","MuDiLepMTWPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuDiLepMTWPT_);
  MuDiLepMTWPTFail_ = (TH1F*)MuDiLepMTWPT_->Clone();
  MuDiLepMTWPTFail_->SetName("MuDiLepMTWPTFail");
  //GetOutputList()->Add(MuDiLepMTWPTFail_); 
  
  MuDiLepMTWActivity_ = new TH1F("MuDiLepMTWActivity","MuDiLepMTWActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuDiLepMTWActivity_);
  MuDiLepMTWActivityFail_ = (TH1F*)MuDiLepMTWActivity_->Clone();
  MuDiLepMTWActivityFail_->SetName("MuDiLepMTWActivityFail");
  //GetOutputList()->Add(MuDiLepMTWActivityFail_); 
  
  
  // elec
  
  ElecPurityPT_ = new TH1F("ElecPurityPT","ElecPurityPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecPurityPT_);
  ElecPurityPTFail_ = (TH1F*)ElecPurityPT_->Clone();
  ElecPurityPTFail_->SetName("ElecPurityPTFail");
  //GetOutputList()->Add(ElecPurityPTFail_); 
  
  ElecPurityActivity_ = new TH1F("ElecPurityActivity","ElecPurityActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecPurityActivity_);
  ElecPurityActivityFail_ = (TH1F*)ElecPurityActivity_->Clone();
  ElecPurityActivityFail_->SetName("ElecPurityActivityFail");
  //GetOutputList()->Add(ElecPurityActivityFail_); 
  
  ElecAccPT_ = new TH1F("ElecAccPT","ElecAccPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecAccPT_);
  ElecAccPTFail_ = (TH1F*)ElecAccPT_->Clone();
  ElecAccPTFail_->SetName("ElecAccPTFail");
  //GetOutputList()->Add(ElecAccPTFail_); 
  
  ElecAccActivity_ = new TH1F("ElecAccActivity","ElecAccActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecAccActivity_);
  ElecAccActivityFail_ = (TH1F*)ElecAccActivity_->Clone();
  ElecAccActivityFail_->SetName("ElecAccActivityFail");
  //GetOutputList()->Add(ElecAccActivityFail_); 
  
  
  ElecRecoPT_ = new TH1F("ElecRecoPT","ElecRecoPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElecRecoPTFail_ = (TH1F*)ElecRecoPT_->Clone();
  ElecRecoPTFail_->SetName("ElecRecoPTFail");
  //GetOutputList()->Add(ElecRecoPTFail_); 
  
  ElecRecoActivity_ = new TH1F("ElecRecoActivity","ElecRecoActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecRecoActivity_);
  ElecRecoActivityFail_ = (TH1F*)ElecRecoActivity_->Clone();
  ElecRecoActivityFail_->SetName("ElecRecoActivityFail");
  //GetOutputList()->Add(ElecRecoActivityFail_); 
  
  ElecIsoPT_ = new TH1F("ElecIsoPT","ElecIsoPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecIsoPT_);
  ElecIsoPTFail_ = (TH1F*)ElecIsoPT_->Clone();
  ElecIsoPTFail_->SetName("ElecIsoPTFail");
  //GetOutputList()->Add(ElecIsoPTFail_); 
  
  ElecIsoActivity_ = new TH1F("ElecIsoActivity","ElecIsoActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecIsoActivity_);
  ElecIsoActivityFail_ = (TH1F*)ElecIsoActivity_->Clone();
  ElecIsoActivityFail_->SetName("ElecIsoActivityFail");
  //GetOutputList()->Add(ElecIsoActivityFail_); 
  
  ElecMTWPT_ = new TH1F("ElecMTWPT","ElecMTWPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecMTWPT_);
  ElecMTWPTFail_ = (TH1F*)ElecMTWPT_->Clone();
  ElecMTWPTFail_->SetName("ElecMTWPTFail");
  //GetOutputList()->Add(ElecMTWPTFail_); 
  
  ElecMTWActivity_ = new TH1F("ElecMTWActivity","ElecMTWActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecMTWActivity_);
  ElecMTWActivityFail_ = (TH1F*)ElecMTWActivity_->Clone();
  ElecMTWActivityFail_->SetName("ElecMTWActivityFail");
  //GetOutputList()->Add(ElecMTWActivityFail_); 
  
  ElecDiLepPT_ = new TH1F("ElecDiLepPT","ElecDiLepPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecDiLepPT_);
  ElecDiLepPTFail_ = (TH1F*)ElecDiLepPT_->Clone();
  ElecDiLepPTFail_->SetName("ElecDiLepPTFail");
  //GetOutputList()->Add(ElecDiLepPTFail_); 
  
  ElecDiLepActivity_ = new TH1F("ElecDiLepActivity","ElecDiLepActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecDiLepActivity_);
  ElecDiLepActivityFail_ = (TH1F*)ElecDiLepActivity_->Clone();
  ElecDiLepActivityFail_->SetName("ElecDiLepActivityFail");
  //GetOutputList()->Add(ElecDiLepActivityFail_); 
  
  
  ElecDiLepMTWPT_ = new TH1F("ElecDiLepMTWPT","ElecDiLepMTWPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecDiLepMTWPT_);
  ElecDiLepMTWPTFail_ = (TH1F*)ElecDiLepMTWPT_->Clone();
  ElecDiLepMTWPTFail_->SetName("ElecDiLepMTWPTFail");
  //GetOutputList()->Add(ElecDiLepMTWPTFail_); 
  
  ElecDiLepMTWActivity_ = new TH1F("ElecDiLepMTWActivity","ElecDiLepMTWActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecDiLepMTWActivity_);
  ElecDiLepMTWActivityFail_ = (TH1F*)ElecDiLepMTWActivity_->Clone();
  ElecDiLepMTWActivityFail_->SetName("ElecDiLepMTWActivityFail");
  //GetOutputList()->Add(ElecDiLepMTWActivityFail_); 
  
  // 2D
  MuIsoPTActivity_ = new TH2F("MuIsoPTActivity","MuIsoPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuIsoPTActivity_);
  MuIsoPTActivityFail_ = (TH2F*)MuIsoPTActivity_->Clone();
  MuIsoPTActivityFail_->SetName("MuIsoPTActivityFail");
  //GetOutputList()->Add(MuIsoPTActivityFail_); 
  
  ElecIsoPTActivity_ = new TH2F("ElecIsoPTActivity","ElecIsoPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecIsoPTActivity_);
  ElecIsoPTActivityFail_ = (TH2F*)ElecIsoPTActivity_->Clone();
  ElecIsoPTActivityFail_->SetName("ElecIsoPTActivityFail");
  //GetOutputList()->Add(ElecIsoPTActivityFail_); 
  
  
  MuRecoPTActivity_ = new TH2F("MuRecoPTActivity","MuRecoPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(MuRecoPTActivity_);
  MuRecoPTActivityFail_ = (TH2F*)MuRecoPTActivity_->Clone();
  MuRecoPTActivityFail_->SetName("MuRecoPTActivityFail");
  //GetOutputList()->Add(MuRecoPTActivityFail_); 
  
  ElecRecoPTActivity_ = new TH2F("ElecRecoPTActivity","ElecRecoPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecRecoPTActivity_);
  ElecRecoPTActivityFail_ = (TH2F*)ElecRecoPTActivity_->Clone();
  ElecRecoPTActivityFail_->SetName("ElecRecoPTActivityFail");
  //GetOutputList()->Add(ElecRecoPTActivityFail_); 
  
  // mtw 2d
  MuMTWPTActivity_ = new TH2F("MuMTWPTActivity","MuMTWPTActivity",muMTWPT2D_-1,MuMTWPT2D_,muMTWActivity2D_-1,MuMTWActivity2D_);
  //GetOutputList()->Add(MuMTWPTActivity_);
  MuMTWPTActivityFail_ = (TH2F*)MuMTWPTActivity_->Clone();
  MuMTWPTActivityFail_->SetName("MuMTWPTActivityFail");
  //GetOutputList()->Add(MuMTWPTActivityFail_);
  
  ElecMTWPTActivity_ = new TH2F("ElecMTWPTActivity","ElecMTWPTActivity",elecMTWPT2D_-1,ElecMTWPT2D_,elecMTWActivity2D_-1,ElecMTWActivity2D_);
  //GetOutputList()->Add(ElecMTWPTActivity_);
  ElecMTWPTActivityFail_ = (TH2F*)ElecMTWPTActivity_->Clone();
  ElecMTWPTActivityFail_->SetName("ElecMTWPTActivityFail");
  //GetOutputList()->Add(ElecMTWPTActivityFail_);
  
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // TEfficiencies used efficiencies
  MuPurityBTagEff_ = new TH1Feff("MuPurityBTag1D","MuPurityBTag1D",oneDBJets_-1,OneDBJets_);
  MuPurityNJetsEff_ = new TH1Feff("MuPurityNJets1D","MuPurityNJets1D",oneDNJets_-1,OneDNJets_);
  MuPurityHTEff_ = new TH1Feff("MuPurityHT1D","MuPurityHT1D",oneDHT_-1,OneDHT_);
  MuPurityMHTEff_ = new TH1Feff("MuPurityMHT1D","MuPurityMHT1D",oneDMHT_-1,OneDMHT_);
  MuPurityPTEff_ = new TH1Feff("MuPurityPT","MuPurityPT",oneDPT_-1,OneDPT_);
  MuPurityActivityEff_ = new TH1Feff("MuPurityActivity","MuPurityActivity",oneDActivity_-1,OneDActivity_);
  
  MuonPurityMHTNJetEff_ = new TH2Feff("MuonPurity","MuonPurity",mupurityMHT_-1,muPurityMHT_,mupurityNJet_-1,muPurityNJet_);
  
  
  ElecPurityBTagEff_ = new TH1Feff("ElecPurityBTag1D","ElecPurityBTag1D",oneDBJets_-1,OneDBJets_);
  ElecPurityNJetsEff_ = new TH1Feff("ElecPurityNJets1D","ElecPurityNJets1D",oneDNJets_-1,OneDNJets_);
  ElecPurityHTEff_ = new TH1Feff("ElecPurityHT1D","ElecPurityHT1D",oneDHT_-1,OneDHT_);
  ElecPurityMHTEff_ = new TH1Feff("ElecPurityMHT1D","ElecPurityMHT1D",oneDMHT_-1,OneDMHT_);
  ElecPurityPTEff_ = new TH1Feff("ElecPurityPT","ElecPurityPT",oneDPT_-1,OneDPT_);
  ElecPurityActivityEff_ = new TH1Feff("ElecPurityActivity","ElecPurityActivity",oneDActivity_-1,OneDActivity_);
  
  ElecPurityMHTNJetEff_ = new TH2Feff("ElecPurity","ElecPurity",mupurityMHT_-1,muPurityMHT_,mupurityNJet_-1,muPurityNJet_);
  
  MuAccBTagEff_ = new TH1Feff("MuAccBTag1D","MuAccBTag1D",oneDBJets_-1,OneDBJets_);
  MuAccNJetsEff_ = new TH1Feff("MuAccNJets1D","MuAccNJets1D",oneDNJets_-1,OneDNJets_);
  MuAccHTEff_ = new TH1Feff("MuAccHT1D","MuAccHT1D",oneDHT_-1,OneDHT_);
  MuAccMHTEff_ = new TH1Feff("MuAccMHT1D","MuAccMHT1D",oneDMHT_-1,OneDMHT_);
  MuAccPTEff_ = new TH1Feff("MuAccPT","MuAccPT",oneDPT_-1,OneDPT_);
  MuAccActivityEff_ = new TH1Feff("MuAccActivity","MuAccActivity",oneDActivity_-1,OneDActivity_);
  
  MuAccHTNJetsEff_ = new TH2Feff("MuAccHTNJets","MuAccHTNJets",muaccHT_-1,muAccHT_, muaccNJets_-1, muAccNJets_);
  MuAccMHTNJetsEff_ = new TH2Feff("MuAccMHTNJets","MuAccMHTNJets",muaccMHT_-1,muAccMHT_, muaccNJets_-1, muAccNJets_);
  MuAccBTagNJetsEff_ = new TH2Feff("MuAccBTagNJets","MuAccBTagNJets",muaccBTags_-1,muAccBTags_, muaccNJets_-1, muAccNJets_);
  
  
  ElecAccBTagEff_ = new TH1Feff("ElecAccBTag1D","ElecAccBTag1D",oneDBJets_-1,OneDBJets_);
  ElecAccNJetsEff_ = new TH1Feff("ElecAccNJets1D","ElecAccNJets1D",oneDNJets_-1,OneDNJets_);
  ElecAccHTEff_ = new TH1Feff("ElecAccHT1D","ElecAccHT1D",oneDHT_-1,OneDHT_);
  ElecAccMHTEff_ = new TH1Feff("ElecAccMHT1D","ElecAccMHT1D",oneDMHT_-1,OneDMHT_);
  ElecAccPTEff_ = new TH1Feff("ElecAccPT","ElecAccPT",oneDPT_-1,OneDPT_);
  ElecAccActivityEff_ = new TH1Feff("ElecAccActivity","ElecAccActivity",oneDActivity_-1,OneDActivity_);
  
  ElecAccHTNJetsEff_ = new TH2Feff("ElecAccHTNJets","ElecAccHTNJets",elecaccHT_-1,elecAccHT_, elecaccNJets_-1, elecAccNJets_);
  ElecAccMHTNJetsEff_ = new TH2Feff("ElecAccMHTNJets","ElecAccMHTNJets",elecaccMHT_-1,elecAccMHT_, elecaccNJets_-1, elecAccNJets_);
  ElecAccBTagNJetsEff_ = new TH2Feff("ElecAccBTagNJets","ElecAccBTagNJets",elecaccBTags_-1,elecAccBTags_, elecaccNJets_-1, elecAccNJets_);
  
  
  MuRecoBTagEff_ = new TH1Feff("MuRecoBTag1D","MuRecoBTag1D",oneDBJets_-1,OneDBJets_);
  MuRecoNJetsEff_ = new TH1Feff("MuRecoNJets1D","MuRecoNJets1D",oneDNJets_-1,OneDNJets_);
  MuRecoHTEff_ = new TH1Feff("MuRecoHT1D","MuRecoHT1D",oneDHT_-1,OneDHT_);
  MuRecoMHTEff_ = new TH1Feff("MuRecoMHT1D","MuRecoMHT1D",oneDMHT_-1,OneDMHT_);
  MuRecoPTEff_ = new TH1Feff("MuRecoPT","MuRecoPT",oneDPT_-1,OneDPT_);
  MuRecoActivityEff_ = new TH1Feff("MuRecoActivity","MuRecoActivity",oneDActivity_-1,OneDActivity_);
  
  MuRecoPTActivityEff_ = new TH2Feff("MuRecoPTActivity","MuRecoPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);      
  
  
  ElecRecoBTagEff_ = new TH1Feff("ElecRecoBTag1D","ElecRecoBTag1D",oneDBJets_-1,OneDBJets_);
  ElecRecoNJetsEff_ = new TH1Feff("ElecRecoNJets1D","ElecRecoNJets1D",oneDNJets_-1,OneDNJets_);
  ElecRecoHTEff_ = new TH1Feff("ElecRecoHT1D","ElecRecoHT1D",oneDHT_-1,OneDHT_);
  ElecRecoMHTEff_ = new TH1Feff("ElecRecoMHT1D","ElecRecoMHT1D",oneDMHT_-1,OneDMHT_);
  ElecRecoPTEff_ = new TH1Feff("ElecRecoPT","ElecRecoPT",oneDPT_-1,OneDPT_);
  ElecRecoActivityEff_ = new TH1Feff("ElecRecoActivity","ElecRecoActivity",oneDActivity_-1,OneDActivity_);
  
  ElecRecoPTActivityEff_ = new TH2Feff("ElecRecoPTActivity","ElecRecoPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  
  
  MuIsoBTagEff_ = new TH1Feff("MuIsoBTag1D","MuIsoBTag1D",oneDBJets_-1,OneDBJets_);
  MuIsoNJetsEff_ = new TH1Feff("MuIsoNJets1D","MuIsoNJets1D",oneDNJets_-1,OneDNJets_);
  MuIsoHTEff_ = new TH1Feff("MuIsoHT1D","MuIsoHT1D",oneDHT_-1,OneDHT_);
  MuIsoMHTEff_ = new TH1Feff("MuIsoMHT1D","MuIsoMHT1D",oneDMHT_-1,OneDMHT_);
  MuIsoPTEff_ = new TH1Feff("MuIsoPT","MuIsoPT",oneDPT_-1,OneDPT_);
  MuIsoActivityEff_ = new TH1Feff("MuIsoActivity","MuIsoActivity",oneDActivity_-1,OneDActivity_);
  
  MuIsoPTActivityEff_ = new TH2Feff("MuIsoPTActivity","MuIsoPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  
  
  ElecIsoBTagEff_ = new TH1Feff("ElecIsoBTag1D","ElecIsoBTag1D",oneDBJets_-1,OneDBJets_);
  ElecIsoNJetsEff_ = new TH1Feff("ElecIsoNJets1D","ElecIsoNJets1D",oneDNJets_-1,OneDNJets_);
  ElecIsoHTEff_ = new TH1Feff("ElecIsoHT1D","ElecIsoHT1D",oneDHT_-1,OneDHT_);
  ElecIsoMHTEff_ = new TH1Feff("ElecIsoMHT1D","ElecIsoMHT1D",oneDMHT_-1,OneDMHT_);
  ElecIsoPTEff_ = new TH1Feff("ElecIsoPT","ElecIsoPT",oneDPT_-1,OneDPT_);
  ElecIsoActivityEff_ = new TH1Feff("ElecIsoActivity","ElecIsoActivity",oneDActivity_-1,OneDActivity_);
  
  ElecIsoPTActivityEff_ = new TH2Feff("ElecIsoPTActivity","ElecIsoPTActivity",oneDPT_-1,OneDPT_,oneDActivity_-1,OneDActivity_);
  
  
  MuMTWBTagEff_ = new TH1Feff("MuMTWBTag1D","MuMTWBTag1D",oneDBJets_-1,OneDBJets_);
  MuMTWNJetsEff_ = new TH1Feff("MuMTWNJets1D","MuMTWNJets1D",oneDNJets_-1,OneDNJets_);
  MuMTWHTEff_ = new TH1Feff("MuMTWHT1D","MuMTWHT1D",oneDHT_-1,OneDHT_);
  MuMTWMHTEff_ = new TH1Feff("MuMTWMHT1D","MuMTWMHT1D",oneDMHT_-1,OneDMHT_);
  MuMTWPTEff_ = new TH1Feff("MuMTWPT","MuMTWPT",oneDPT_-1,OneDPT_);
  MuMTWActivityEff_ = new TH1Feff("MuMTWActivity","MuMTWActivity",oneDActivity_-1,OneDActivity_);
  
  MuMTWPTActivityEff_ = new TH2Feff("MuMTWPTActivity","MuMTWPTActivity",muMTWPT2D_-1,MuMTWPT2D_,muMTWActivity2D_-1,MuMTWActivity2D_);
  
  
  
  ElecMTWBTagEff_ = new TH1Feff("ElecMTWBTag1D","ElecMTWBTag1D",oneDBJets_-1,OneDBJets_);
  ElecMTWNJetsEff_ = new TH1Feff("ElecMTWNJets1D","ElecMTWNJets1D",oneDNJets_-1,OneDNJets_);
  ElecMTWHTEff_ = new TH1Feff("ElecMTWHT1D","ElecMTWHT1D",oneDHT_-1,OneDHT_);
  ElecMTWMHTEff_ = new TH1Feff("ElecMTWMHT1D","ElecMTWMHT1D",oneDMHT_-1,OneDMHT_);
  ElecMTWPTEff_ = new TH1Feff("ElecMTWPT","ElecMTWPT",oneDPT_-1,OneDPT_);
  ElecMTWActivityEff_ = new TH1Feff("ElecMTWActivity","ElecMTWActivity",oneDActivity_-1,OneDActivity_);
  
  ElecMTWPTActivityEff_ = new TH2Feff("ElecMTWPTActivity","ElecMTWPTActivity",elecMTWPT2D_-1,ElecMTWPT2D_,elecMTWActivity2D_-1,ElecMTWActivity2D_);
  
  
  
  MuDiLepBTagEff_ = new TH1Feff("MuDiLepBTag1D","MuDiLepBTag1D",oneDBJets_-1,OneDBJets_);
  MuDiLepNJetsEff_ = new TH1Feff("MuDiLepNJets1D","MuDiLepNJets1D",oneDNJets_-1,OneDNJets_);
  MuDiLepHTEff_ = new TH1Feff("MuDiLepHT1D","MuDiLepHT1D",oneDHT_-1,OneDHT_);
  MuDiLepMHTEff_ = new TH1Feff("MuDiLepMHT1D","MuDiLepMHT1D",oneDMHT_-1,OneDMHT_);
  //      MuDiLepPTEff_ = new TH1Feff("MuDiLepPT","MuDiLepPT",oneDPT_-1,OneDPT_);
  //      MuDiLepActivityEff_ = new TH1Feff("MuDiLepActivity","MuDiLepActivity",oneDActivity_-1,OneDActivity_);
  
  
  ElecDiLepBTagEff_ = new TH1Feff("ElecDiLepBTag1D","ElecDiLepBTag1D",oneDBJets_-1,OneDBJets_);
  ElecDiLepNJetsEff_ = new TH1Feff("ElecDiLepNJets1D","ElecDiLepNJets1D",oneDNJets_-1,OneDNJets_);
  ElecDiLepHTEff_ = new TH1Feff("ElecDiLepHT1D","ElecDiLepHT1D",oneDHT_-1,OneDHT_);
  ElecDiLepMHTEff_ = new TH1Feff("ElecDiLepMHT1D","ElecDiLepMHT1D",oneDMHT_-1,OneDMHT_);
  //      ElecDiLepPTEff_ = new TH1Feff("ElecDiLepPT","ElecDiLepPT",oneDPT_-1,OneDPT_);
  //      ElecDiLepActivityEff_ = new TH1Feff("ElecDiLepActivity","ElecDiLepActivity",oneDActivity_-1,OneDActivity_);
  
  
  MuDiLepMTWBTagEff_ = new TH1Feff("MuDiLepMTWBTag1D","MuDiLepMTWBTag1D",oneDBJets_-1,OneDBJets_);
  MuDiLepMTWNJetsEff_ = new TH1Feff("MuDiLepMTWNJets1D","MuDiLepMTWNJets1D",oneDNJets_-1,OneDNJets_);
  MuDiLepMTWHTEff_ = new TH1Feff("MuDiLepMTWHT1D","MuDiLepMTWHT1D",oneDHT_-1,OneDHT_);
  MuDiLepMTWMHTEff_ = new TH1Feff("MuDiLepMTWMHT1D","MuDiLepMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //      MuDiLepMTWPTEff_ = new TH1Feff("MuDiLepMTWPT","MuDiLepMTWPT",oneDPT_-1,OneDPT_);
  //      MuDiLepMTWActivityEff_ = new TH1Feff("MuDiLepMTWActivity","MuDiLepMTWActivity",oneDActivity_-1,OneDActivity_);
  
  
  ElecDiLepMTWBTagEff_ = new TH1Feff("ElecDiLepMTWBTag1D","ElecDiLepMTWBTag1D",oneDBJets_-1,OneDBJets_);
  ElecDiLepMTWNJetsEff_ = new TH1Feff("ElecDiLepMTWNJets1D","ElecDiLepMTWNJets1D",oneDNJets_-1,OneDNJets_);
  ElecDiLepMTWHTEff_ = new TH1Feff("ElecDiLepMTWHT1D","ElecDiLepMTWHT1D",oneDHT_-1,OneDHT_);
  ElecDiLepMTWMHTEff_ = new TH1Feff("ElecDiLepMTWMHT1D","ElecDiLepMTWMHT1D",oneDMHT_-1,OneDMHT_);
  //      ElecDiLepMTWPTEff_ = new TH1Feff("ElecDiLepMTWPT","ElecDiLepMTWPT",oneDPT_-1,OneDPT_);
  //      ElecDiLepMTWActivityEff_ = new TH1Feff("ElecDiLepMTWActivity","ElecDiLepMTWActivity",oneDActivity_-1,OneDActivity_);
  
  
  MuDiLepContributionBTagEff_ = new TH1Feff("MuDiLepContributionBTag1D","MuDiLepContributionBTag1D",oneDBJets_-1,OneDBJets_);
  MuDiLepContributionNJetsEff_ = new TH1Feff("MuDiLepContributionNJets1D","MuDiLepContributionNJets1D",oneDNJets_-1,OneDNJets_);
  MuDiLepContributionHTEff_ = new TH1Feff("MuDiLepContributionHT1D","MuDiLepContributionHT1D",oneDHT_-1,OneDHT_);
  MuDiLepContributionMHTEff_ = new TH1Feff("MuDiLepContributionMHT1D","MuDiLepContributionMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  ElecDiLepContributionBTagEff_ = new TH1Feff("ElecDiLepContributionBTag1D","ElecDiLepContributionBTag1D",oneDBJets_-1,OneDBJets_);
  ElecDiLepContributionNJetsEff_ = new TH1Feff("ElecDiLepContributionNJets1D","ElecDiLepContributionNJets1D",oneDNJets_-1,OneDNJets_);
  ElecDiLepContributionHTEff_ = new TH1Feff("ElecDiLepContributionHT1D","ElecDiLepContributionHT1D",oneDHT_-1,OneDHT_);
  ElecDiLepContributionMHTEff_ = new TH1Feff("ElecDiLepContributionMHT1D","ElecDiLepContributionMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  MuDiLepContributionMTWBTagEff_ = new TH1Feff("MuDiLepContributionMTWBTag1D","MuDiLepContributionMTWBTag1D",oneDBJets_-1,OneDBJets_);
  MuDiLepContributionMTWNJetsEff_ = new TH1Feff("MuDiLepContributionMTWNJets1D","MuDiLepContributionMTWNJets1D",oneDNJets_-1,OneDNJets_);
  MuDiLepContributionMTWHTEff_ = new TH1Feff("MuDiLepContributionMTWHT1D","MuDiLepContributionMTWHT1D",oneDHT_-1,OneDHT_);
  MuDiLepContributionMTWMHTEff_ = new TH1Feff("MuDiLepContributionMTWMHT1D","MuDiLepContributionMTWMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  ElecDiLepContributionMTWBTagEff_ = new TH1Feff("ElecDiLepContributionMTWBTag1D","ElecDiLepContributionMTWBTag1D",oneDBJets_-1,OneDBJets_);
  ElecDiLepContributionMTWNJetsEff_ = new TH1Feff("ElecDiLepContributionMTWNJets1D","ElecDiLepContributionMTWNJets1D",oneDNJets_-1,OneDNJets_);
  ElecDiLepContributionMTWHTEff_ = new TH1Feff("ElecDiLepContributionMTWHT1D","ElecDiLepContributionMTWHT1D",oneDHT_-1,OneDHT_);
  ElecDiLepContributionMTWMHTEff_ = new TH1Feff("ElecDiLepContributionMTWMHT1D","ElecDiLepContributionMTWMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  IsoTrackMuBTagEff_ = new TH1Feff("IsoTrackMuBTag1D","IsoTrackMuBTag1D",oneDBJets_-1,OneDBJets_);
  IsoTrackMuNJetsEff_ = new TH1Feff("IsoTrackMuNJets1D","IsoTrackMuNJets1D",oneDNJets_-1,OneDNJets_);
  IsoTrackMuHTEff_ = new TH1Feff("IsoTrackMuHT1D","IsoTrackMuHT1D",oneDHT_-1,OneDHT_);
  IsoTrackMuMHTEff_ = new TH1Feff("IsoTrackMuMHT1D","IsoTrackMuMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  IsoTrackMuMatchedToIsoMuBTagEff_ = new TH1Feff("IsoTrackMuMatchedToIsoMuBTag1D","IsoTrackMuMatchedToIsoMuBTag1D",oneDBJets_-1,OneDBJets_);
  IsoTrackMuMatchedToIsoMuNJetsEff_ = new TH1Feff("IsoTrackMuMatchedToIsoMuNJets1D","IsoTrackMuMatchedToIsoMuNJets1D",oneDNJets_-1,OneDNJets_);
  IsoTrackMuMatchedToIsoMuHTEff_ = new TH1Feff("IsoTrackMuMatchedToIsoMuHT1D","IsoTrackMuMatchedToIsoMuHT1D",oneDHT_-1,OneDHT_);
  IsoTrackMuMatchedToIsoMuMHTEff_ = new TH1Feff("IsoTrackMuMatchedToIsoMuMHT1D","IsoTrackMuMatchedToIsoMuMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  IsoTrackMuMTWBTagEff_ = new TH1Feff("IsoTrackMuMTWBTag1D","IsoTrackMuMTWBTag1D",oneDBJets_-1,OneDBJets_);
  IsoTrackMuMTWNJetsEff_ = new TH1Feff("IsoTrackMuMTWNJets1D","IsoTrackMuMTWNJets1D",oneDNJets_-1,OneDNJets_);
  IsoTrackMuMTWHTEff_ = new TH1Feff("IsoTrackMuMTWHT1D","IsoTrackMuMTWHT1D",oneDHT_-1,OneDHT_);
  IsoTrackMuMTWMHTEff_ = new TH1Feff("IsoTrackMuMTWMHT1D","IsoTrackMuMTWMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  IsoTrackElecBTagEff_ = new TH1Feff("IsoTrackElecBTag1D","IsoTrackElecBTag1D",oneDBJets_-1,OneDBJets_);
  IsoTrackElecNJetsEff_ = new TH1Feff("IsoTrackElecNJets1D","IsoTrackElecNJets1D",oneDNJets_-1,OneDNJets_);
  IsoTrackElecHTEff_ = new TH1Feff("IsoTrackElecHT1D","IsoTrackElecHT1D",oneDHT_-1,OneDHT_);
  IsoTrackElecMHTEff_ = new TH1Feff("IsoTrackElecMHT1D","IsoTrackElecMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  IsoTrackElecMTWBTagEff_ = new TH1Feff("IsoTrackElecMTWBTag1D","IsoTrackElecMTWBTag1D",oneDBJets_-1,OneDBJets_);
  IsoTrackElecMTWNJetsEff_ = new TH1Feff("IsoTrackElecMTWNJets1D","IsoTrackElecMTWNJets1D",oneDNJets_-1,OneDNJets_);
  IsoTrackElecMTWHTEff_ = new TH1Feff("IsoTrackElecMTWHT1D","IsoTrackElecMTWHT1D",oneDHT_-1,OneDHT_);
  IsoTrackElecMTWMHTEff_ = new TH1Feff("IsoTrackElecMTWMHT1D","IsoTrackElecMTWMHT1D",oneDMHT_-1,OneDMHT_);
  
  
  IsoTrackElecMatchedToIsoElecBTagEff_ = new TH1Feff("IsoTrackElecMatchedToIsoElecBTag1D","IsoTrackElecMatchedToIsoElecBTag1D",oneDBJets_-1,OneDBJets_);
  IsoTrackElecMatchedToIsoElecNJetsEff_ = new TH1Feff("IsoTrackElecMatchedToIsoElecNJets1D","IsoTrackElecMatchedToIsoElecNJets1D",oneDNJets_-1,OneDNJets_);
  IsoTrackElecMatchedToIsoElecHTEff_ = new TH1Feff("IsoTrackElecMatchedToIsoElecHT1D","IsoTrackElecMatchedToIsoElecHT1D",oneDHT_-1,OneDHT_);
  IsoTrackElecMatchedToIsoElecMHTEff_ = new TH1Feff("IsoTrackElecMatchedToIsoElecMHT1D","IsoTrackElecMatchedToIsoElecMHT1D",oneDMHT_-1,OneDMHT_);
  
  // search bin efficiencies
  MuAccSearchBinEff_ = new Efficiency("MuAccSearchBinEff","MuAccSearchBinEff");
  MuRecoSearchBinEff_ = new Efficiency("MuRecoSearchBinEff","MuRecoSearchBinEff");
  MuIsoSearchBinEff_ = new Efficiency("MuIsoSearchBinEff","MuIsoSearchBinEff");
  MuMTWSearchBinEff_ = new Efficiency("MuMTWSearchBinEff","MuMTWSearchBinEff");
  MuDiLepContributionMTWAppliedSearchBinEff_ = new Efficiency("MuDiLepContributionMTWAppliedSearchBinEff","MuDiLepContributionMTWAppliedSearchBinEff");
  MuDiLepEffMTWAppliedSearchBinEff_ = new Efficiency("MuDiLepEffMTWAppliedSearchBinEff","MuDiLepEffMTWAppliedSearchBinEff");
  MuPuritySearchBinEff_ = new Efficiency("MuPuritySearchBinEff","MuPuritySearchBinEff");
  
  ElecAccSearchBinEff_ = new Efficiency("ElecAccSearchBinEff","ElecAccSearchBinEff");
  ElecRecoSearchBinEff_ = new Efficiency("ElecRecoSearchBinEff","ElecRecoSearchBinEff");
  ElecIsoSearchBinEff_ = new Efficiency("ElecIsoSearchBinEff","ElecIsoSearchBinEff");
  ElecMTWSearchBinEff_ = new Efficiency("ElecMTWSearchBinEff","ElecMTWSearchBinEff");
  ElecDiLepContributionMTWAppliedSearchBinEff_ = new Efficiency("ElecDiLepContributionMTWAppliedSearchBinEff","ElecDiLepContributionMTWAppliedSearchBinEff");
  ElecDiLepEffMTWAppliedSearchBinEff_ = new Efficiency("ElecDiLepEffMTWAppliedSearchBinEff","ElecDiLepEffMTWAppliedSearchBinEff");
  ElecPuritySearchBinEff_ = new Efficiency("ElecPuritySearchBinEff","ElecPuritySearchBinEff");
  
  // ExpectationReductionIsoTrack
  ExpectationReductionIsoTrackBTagEff_ = new TH1Feff("ExpectationReductionIsoTrackBTag1D","ExpectationReductionIsoTrackBTag1D",oneDBJets_-1,OneDBJets_);
  ExpectationReductionIsoTrackNJetsEff_ = new TH1Feff("ExpectationReductionIsoTrackNJets1D","ExpectationReductionIsoTrackNJets1D",oneDNJets_-1,OneDNJets_);
  ExpectationReductionIsoTrackHTEff_ = new TH1Feff("ExpectationReductionIsoTrackHT1D","ExpectationReductionIsoTrackHT1D",oneDHT_-1,OneDHT_);
  ExpectationReductionIsoTrackMHTEff_ = new TH1Feff("ExpectationReductionIsoTrackMHT1D","ExpectationReductionIsoTrackMHT1D",oneDMHT_-1,OneDMHT_);
  
  ExpectationReductionIsoTrack_ = new Efficiency("ExpectationReductionIsoTrack","ExpectationReductionIsoTrack");
  
  //1D
  ExpectationReductionIsoTrackBTagEff = new TH1F("ExpectationReductionIsoTrackBTagEff","ExpectationReductionIsoTrackBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(IsoTrackReductionHTNJets_);
  ExpectationReductionIsoTrackBTagEffFail = (TH1F*)ExpectationReductionIsoTrackBTagEff->Clone();
  ExpectationReductionIsoTrackBTagEffFail->SetName("ExpectationReductionIsoTrackBTagEffFail");
  //GetOutputList()->Add(IsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionIsoTrackNJetsEff = new TH1F("ExpectationReductionIsoTrackNJetsEff","ExpectationReductionIsoTrackNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(IsoTrackReductionHTNJets_);
  ExpectationReductionIsoTrackNJetsEffFail = (TH1F*)ExpectationReductionIsoTrackNJetsEff->Clone();
  ExpectationReductionIsoTrackNJetsEffFail->SetName("ExpectationReductionIsoTrackNJetsEffFail");
  //GetOutputList()->Add(IsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionIsoTrackHTEff = new TH1F("ExpectationReductionIsoTrackHTEff","ExpectationReductionIsoTrackHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(IsoTrackReductionHTNJets_);
  ExpectationReductionIsoTrackHTEffFail = (TH1F*)ExpectationReductionIsoTrackHTEff->Clone();
  ExpectationReductionIsoTrackHTEffFail->SetName("ExpectationReductionIsoTrackHTEffFail");
  //GetOutputList()->Add(IsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionIsoTrackMHTEff = new TH1F("ExpectationReductionIsoTrackMHTEff","ExpectationReductionIsoTrackMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(IsoTrackReductionHTNJets_);
  ExpectationReductionIsoTrackMHTEffFail = (TH1F*)ExpectationReductionIsoTrackMHTEff->Clone();
  ExpectationReductionIsoTrackMHTEffFail->SetName("ExpectationReductionIsoTrackMHTEffFail");
  //GetOutputList()->Add(IsoTrackReductionHTNJetsFail_); 
  ExpectationReductionIsoTrackPTEff = new TH1F("ExpectationReductionIsoTrackPTEff","ExpectationReductionIsoTrackPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(IsoTrackReductionHTNJets_);
  ExpectationReductionIsoTrackPTEffFail = (TH1F*)ExpectationReductionIsoTrackPTEff->Clone();
  ExpectationReductionIsoTrackPTEffFail->SetName("ExpectationReductionIsoTrackPTEffFail");
  ExpectationReductionIsoTrackActivityEff = new TH1F("ExpectationReductionIsoTrackActivityEff","ExpectationReductionIsoTrackActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(IsoTrackReductionHTNJets_);
  ExpectationReductionIsoTrackActivityEffFail = (TH1F*)ExpectationReductionIsoTrackActivityEff->Clone();
  ExpectationReductionIsoTrackActivityEffFail->SetName("ExpectationReductionIsoTrackActivityEffFail");
  
  //2D
  IsoTrackReductionHTNJets_ = new TH2F("IsoTrackReductionHTNJets","IsoTrackReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(IsoTrackReductionHTNJets_);
  IsoTrackReductionHTNJetsFail_ = (TH2F*)IsoTrackReductionHTNJets_->Clone();
  IsoTrackReductionHTNJetsFail_->SetName("IsoTrackReductionHTNJetsFail");
  //GetOutputList()->Add(IsoTrackReductionHTNJetsFail_); 
  
  IsoTrackReductionMHTNJets_ = new TH2F("IsoTrackReductionMHTNJets","IsoTrackReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(IsoTrackReductionMHTNJets_);
  IsoTrackReductionMHTNJetsFail_ = (TH2F*)IsoTrackReductionMHTNJets_->Clone();
  IsoTrackReductionMHTNJetsFail_->SetName("IsoTrackReductionMHTNJetsFail");
  //GetOutputList()->Add(IsoTrackReductionMHTNJetsFail_); 
  
  IsoTrackReductionBTagNJets_ = new TH2F("IsoTrackReductionBTagNJets","IsoTrackReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(IsoTrackReductionBTagNJets_);
  IsoTrackReductionBTagNJetsFail_ = (TH2F*)IsoTrackReductionBTagNJets_->Clone();
  IsoTrackReductionBTagNJetsFail_->SetName("IsoTrackReductionBTagNJetsFail");
  
  IsoTrackReductionPTActivity_ = new TH2F("IsoTrackReductionPTActivity","IsoTrackReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(IsoTrackReductionPTActivity_);
  IsoTrackReductionPTActivityFail_ = (TH2F*)IsoTrackReductionPTActivity_->Clone();
  IsoTrackReductionPTActivityFail_->SetName("IsoTrackReductionPTActivityFail");
  
  
  // ************************************************************************************************************* 22 June 2015 ****************************************************
  //1D
  
  // muon iso track
  ExpectationReductionMuIsoTrackBTagEff = new TH1F("ExpectationReductionMuIsoTrackBTagEff","ExpectationReductionMuIsoTrackBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(MuIsoTrackReductionHTNJets_);
  ExpectationReductionMuIsoTrackBTagEffFail = (TH1F*)ExpectationReductionMuIsoTrackBTagEff->Clone();
  ExpectationReductionMuIsoTrackBTagEffFail->SetName("ExpectationReductionMuIsoTrackBTagEffFail");
  //GetOutputList()->Add(MuIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionMuIsoTrackNJetsEff = new TH1F("ExpectationReductionMuIsoTrackNJetsEff","ExpectationReductionMuIsoTrackNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(MuIsoTrackReductionHTNJets_);
  ExpectationReductionMuIsoTrackNJetsEffFail = (TH1F*)ExpectationReductionMuIsoTrackNJetsEff->Clone();
  ExpectationReductionMuIsoTrackNJetsEffFail->SetName("ExpectationReductionMuIsoTrackNJetsEffFail");
  //GetOutputList()->Add(MuIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionMuIsoTrackHTEff = new TH1F("ExpectationReductionMuIsoTrackHTEff","ExpectationReductionMuIsoTrackHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(MuIsoTrackReductionHTNJets_);
  ExpectationReductionMuIsoTrackHTEffFail = (TH1F*)ExpectationReductionMuIsoTrackHTEff->Clone();
  ExpectationReductionMuIsoTrackHTEffFail->SetName("ExpectationReductionMuIsoTrackHTEffFail");
  //GetOutputList()->Add(MuIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionMuIsoTrackMHTEff = new TH1F("ExpectationReductionMuIsoTrackMHTEff","ExpectationReductionMuIsoTrackMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(MuIsoTrackReductionHTNJets_);
  ExpectationReductionMuIsoTrackMHTEffFail = (TH1F*)ExpectationReductionMuIsoTrackMHTEff->Clone();
  ExpectationReductionMuIsoTrackMHTEffFail->SetName("ExpectationReductionMuIsoTrackMHTEffFail");
  //GetOutputList()->Add(MuIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionMuIsoTrackPTEff = new TH1F("ExpectationReductionMuIsoTrackPTEff","ExpectationReductionMuIsoTrackPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(MuIsoTrackReductionHTNJets_);
  ExpectationReductionMuIsoTrackPTEffFail = (TH1F*)ExpectationReductionMuIsoTrackPTEff->Clone();
  ExpectationReductionMuIsoTrackPTEffFail->SetName("ExpectationReductionMuIsoTrackPTEffFail");
  //GetOutputList()->Add(MuIsoTrackReductionHTNJetsFail_); 
  ExpectationReductionMuIsoTrackActivityEff = new TH1F("ExpectationReductionMuIsoTrackActivityEff","ExpectationReductionMuIsoTrackActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(MuIsoTrackReductionHTNJets_);
  ExpectationReductionMuIsoTrackActivityEffFail = (TH1F*)ExpectationReductionMuIsoTrackActivityEff->Clone();
  ExpectationReductionMuIsoTrackActivityEffFail->SetName("ExpectationReductionMuIsoTrackActivityEffFail");
  //GetOutputList()->Add(MuIsoTrackReductionHTNJetsFail_); 
  
  //2D
  MuIsoTrackReductionHTNJets_ = new TH2F("MuIsoTrackReductionHTNJets","MuIsoTrackReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(MuIsoTrackReductionHTNJets_);
  MuIsoTrackReductionHTNJetsFail_ = (TH2F*)MuIsoTrackReductionHTNJets_->Clone();
  MuIsoTrackReductionHTNJetsFail_->SetName("MuIsoTrackReductionHTNJetsFail");
  //GetOutputList()->Add(MuIsoTrackReductionHTNJetsFail_); 
  
  MuIsoTrackReductionMHTNJets_ = new TH2F("MuIsoTrackReductionMHTNJets","MuIsoTrackReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(MuIsoTrackReductionMHTNJets_);
  MuIsoTrackReductionMHTNJetsFail_ = (TH2F*)MuIsoTrackReductionMHTNJets_->Clone();
  MuIsoTrackReductionMHTNJetsFail_->SetName("MuIsoTrackReductionMHTNJetsFail");
  //GetOutputList()->Add(MuIsoTrackReductionMHTNJetsFail_); 
  
  MuIsoTrackReductionBTagNJets_ = new TH2F("MuIsoTrackReductionBTagNJets","MuIsoTrackReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(MuIsoTrackReductionBTagNJets_);
  MuIsoTrackReductionBTagNJetsFail_ = (TH2F*)MuIsoTrackReductionBTagNJets_->Clone();
  MuIsoTrackReductionBTagNJetsFail_->SetName("MuIsoTrackReductionBTagNJetsFail");
  
  MuIsoTrackReductionPTActivity_ = new TH2F("MuIsoTrackReductionPTActivity","MuIsoTrackReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(MuIsoTrackReductionPTActivity_);
  MuIsoTrackReductionPTActivityFail_ = (TH2F*)MuIsoTrackReductionPTActivity_->Clone();
  MuIsoTrackReductionPTActivityFail_->SetName("MuIsoTrackReductionPTActivityFail");
  
  // elec iso track
  //1D
  ExpectationReductionElecIsoTrackBTagEff = new TH1F("ExpectationReductionElecIsoTrackBTagEff","ExpectationReductionElecIsoTrackBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJets_);
  ExpectationReductionElecIsoTrackBTagEffFail = (TH1F*)ExpectationReductionElecIsoTrackBTagEff->Clone();
  ExpectationReductionElecIsoTrackBTagEffFail->SetName("ExpectationReductionElecIsoTrackBTagEffFail");
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionElecIsoTrackNJetsEff = new TH1F("ExpectationReductionElecIsoTrackNJetsEff","ExpectationReductionElecIsoTrackNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJets_);
  ExpectationReductionElecIsoTrackNJetsEffFail = (TH1F*)ExpectationReductionElecIsoTrackNJetsEff->Clone();
  ExpectationReductionElecIsoTrackNJetsEffFail->SetName("ExpectationReductionElecIsoTrackNJetsEffFail");
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionElecIsoTrackHTEff = new TH1F("ExpectationReductionElecIsoTrackHTEff","ExpectationReductionElecIsoTrackHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJets_);
  ExpectationReductionElecIsoTrackHTEffFail = (TH1F*)ExpectationReductionElecIsoTrackHTEff->Clone();
  ExpectationReductionElecIsoTrackHTEffFail->SetName("ExpectationReductionElecIsoTrackHTEffFail");
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionElecIsoTrackMHTEff = new TH1F("ExpectationReductionElecIsoTrackMHTEff","ExpectationReductionElecIsoTrackMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJets_);
  ExpectationReductionElecIsoTrackMHTEffFail = (TH1F*)ExpectationReductionElecIsoTrackMHTEff->Clone();
  ExpectationReductionElecIsoTrackMHTEffFail->SetName("ExpectationReductionElecIsoTrackMHTEffFail");
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionElecIsoTrackPTEff = new TH1F("ExpectationReductionElecIsoTrackPTEff","ExpectationReductionElecIsoTrackPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJets_);
  ExpectationReductionElecIsoTrackPTEffFail = (TH1F*)ExpectationReductionElecIsoTrackPTEff->Clone();
  ExpectationReductionElecIsoTrackPTEffFail->SetName("ExpectationReductionElecIsoTrackPTEffFail");
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJetsFail_); 
  ExpectationReductionElecIsoTrackActivityEff = new TH1F("ExpectationReductionElecIsoTrackActivityEff","ExpectationReductionElecIsoTrackActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJets_);
  ExpectationReductionElecIsoTrackActivityEffFail = (TH1F*)ExpectationReductionElecIsoTrackActivityEff->Clone();
  ExpectationReductionElecIsoTrackActivityEffFail->SetName("ExpectationReductionElecIsoTrackActivityEffFail");
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJetsFail_); 
  
  //2D
  ElecIsoTrackReductionHTNJets_ = new TH2F("ElecIsoTrackReductionHTNJets","ElecIsoTrackReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJets_);
  ElecIsoTrackReductionHTNJetsFail_ = (TH2F*)ElecIsoTrackReductionHTNJets_->Clone();
  ElecIsoTrackReductionHTNJetsFail_->SetName("ElecIsoTrackReductionHTNJetsFail");
  //GetOutputList()->Add(ElecIsoTrackReductionHTNJetsFail_); 
  
  ElecIsoTrackReductionMHTNJets_ = new TH2F("ElecIsoTrackReductionMHTNJets","ElecIsoTrackReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecIsoTrackReductionMHTNJets_);
  ElecIsoTrackReductionMHTNJetsFail_ = (TH2F*)ElecIsoTrackReductionMHTNJets_->Clone();
  ElecIsoTrackReductionMHTNJetsFail_->SetName("ElecIsoTrackReductionMHTNJetsFail");
  //GetOutputList()->Add(ElecIsoTrackReductionMHTNJetsFail_); 
  
  ElecIsoTrackReductionBTagNJets_ = new TH2F("ElecIsoTrackReductionBTagNJets","ElecIsoTrackReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(ElecIsoTrackReductionBTagNJets_);
  ElecIsoTrackReductionBTagNJetsFail_ = (TH2F*)ElecIsoTrackReductionBTagNJets_->Clone();
  ElecIsoTrackReductionBTagNJetsFail_->SetName("ElecIsoTrackReductionBTagNJetsFail");
  
  ElecIsoTrackReductionPTActivity_ = new TH2F("ElecIsoTrackReductionPTActivity","ElecIsoTrackReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(ElecIsoTrackReductionPTActivity_);
  ElecIsoTrackReductionPTActivityFail_ = (TH2F*)ElecIsoTrackReductionPTActivity_->Clone();
  ElecIsoTrackReductionPTActivityFail_->SetName("ElecIsoTrackReductionPTActivityFail");
  
  // pion iso track
  //1D
  ExpectationReductionPionIsoTrackBTagEff = new TH1F("ExpectationReductionPionIsoTrackBTagEff","ExpectationReductionPionIsoTrackBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(PionIsoTrackReductionHTNJets_);
  ExpectationReductionPionIsoTrackBTagEffFail = (TH1F*)ExpectationReductionPionIsoTrackBTagEff->Clone();
  ExpectationReductionPionIsoTrackBTagEffFail->SetName("ExpectationReductionPionIsoTrackBTagEffFail");
  //GetOutputList()->Add(PionIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackNJetsEff = new TH1F("ExpectationReductionPionIsoTrackNJetsEff","ExpectationReductionPionIsoTrackNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackReductionHTNJets_);
  ExpectationReductionPionIsoTrackNJetsEffFail = (TH1F*)ExpectationReductionPionIsoTrackNJetsEff->Clone();
  ExpectationReductionPionIsoTrackNJetsEffFail->SetName("ExpectationReductionPionIsoTrackNJetsEffFail");
  //GetOutputList()->Add(PionIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackHTEff = new TH1F("ExpectationReductionPionIsoTrackHTEff","ExpectationReductionPionIsoTrackHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(PionIsoTrackReductionHTNJets_);
  ExpectationReductionPionIsoTrackHTEffFail = (TH1F*)ExpectationReductionPionIsoTrackHTEff->Clone();
  ExpectationReductionPionIsoTrackHTEffFail->SetName("ExpectationReductionPionIsoTrackHTEffFail");
  //GetOutputList()->Add(PionIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackMHTEff = new TH1F("ExpectationReductionPionIsoTrackMHTEff","ExpectationReductionPionIsoTrackMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(PionIsoTrackReductionHTNJets_);
  ExpectationReductionPionIsoTrackMHTEffFail = (TH1F*)ExpectationReductionPionIsoTrackMHTEff->Clone();
  ExpectationReductionPionIsoTrackMHTEffFail->SetName("ExpectationReductionPionIsoTrackMHTEffFail");
  //GetOutputList()->Add(PionIsoTrackReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackPTEff = new TH1F("ExpectationReductionPionIsoTrackPTEff","ExpectationReductionPionIsoTrackPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(PionIsoTrackReductionHTNJets_);
  ExpectationReductionPionIsoTrackPTEffFail = (TH1F*)ExpectationReductionPionIsoTrackPTEff->Clone();
  ExpectationReductionPionIsoTrackPTEffFail->SetName("ExpectationReductionPionIsoTrackPTEffFail");
  //GetOutputList()->Add(PionIsoTrackReductionHTNJetsFail_); 
  ExpectationReductionPionIsoTrackActivityEff = new TH1F("ExpectationReductionPionIsoTrackActivityEff","ExpectationReductionPionIsoTrackActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(PionIsoTrackReductionHTNJets_);
  ExpectationReductionPionIsoTrackActivityEffFail = (TH1F*)ExpectationReductionPionIsoTrackActivityEff->Clone();
  ExpectationReductionPionIsoTrackActivityEffFail->SetName("ExpectationReductionPionIsoTrackActivityEffFail");
  //GetOutputList()->Add(PionIsoTrackReductionHTNJetsFail_); 
  
  //2D
  PionIsoTrackReductionHTNJets_ = new TH2F("PionIsoTrackReductionHTNJets","PionIsoTrackReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackReductionHTNJets_);
  PionIsoTrackReductionHTNJetsFail_ = (TH2F*)PionIsoTrackReductionHTNJets_->Clone();
  PionIsoTrackReductionHTNJetsFail_->SetName("PionIsoTrackReductionHTNJetsFail");
  //GetOutputList()->Add(PionIsoTrackReductionHTNJetsFail_); 
  
  PionIsoTrackReductionMHTNJets_ = new TH2F("PionIsoTrackReductionMHTNJets","PionIsoTrackReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackReductionMHTNJets_);
  PionIsoTrackReductionMHTNJetsFail_ = (TH2F*)PionIsoTrackReductionMHTNJets_->Clone();
  PionIsoTrackReductionMHTNJetsFail_->SetName("PionIsoTrackReductionMHTNJetsFail");
  //GetOutputList()->Add(PionIsoTrackReductionMHTNJetsFail_); 
  
  PionIsoTrackReductionBTagNJets_ = new TH2F("PionIsoTrackReductionBTagNJets","PionIsoTrackReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(PionIsoTrackReductionBTagNJets_);
  PionIsoTrackReductionBTagNJetsFail_ = (TH2F*)PionIsoTrackReductionBTagNJets_->Clone();
  PionIsoTrackReductionBTagNJetsFail_->SetName("PionIsoTrackReductionBTagNJetsFail");
  
  PionIsoTrackReductionPTActivity_ = new TH2F("PionIsoTrackReductionPTActivity","PionIsoTrackReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(PionIsoTrackReductionPTActivity_);
  PionIsoTrackReductionPTActivityFail_ = (TH2F*)PionIsoTrackReductionPTActivity_->Clone();
  PionIsoTrackReductionPTActivityFail_->SetName("PionIsoTrackReductionPTActivityFail");
  
  
  // ************************************************************************************************************* 22 June 2015 end****************************************************
  
  // ************************************************************************************************************* 24 June 2015 end****************************************************
  
  MuAccHTMHT_NJets46_ = new TH2F("MuAccHTMHT_NJets46","MuAccHTMHT_NJets46",muaccHT_-1,muAccHT_, muaccMHT_-1,muAccMHT_);
  //GetOutputList()->Add(MuAccMHTNJets_);
  MuAccHTMHT_NJets46Fail_ = (TH2F*)MuAccHTMHT_NJets46_->Clone();
  MuAccHTMHT_NJets46Fail_->SetName("MuAccHTMHT_NJets46Fail");
  
  MuAccHTMHT_NJets7Inf_ = new TH2F("MuAccHTMHT_NJets7Inf"," MuAccHTMHT_NJets7Inf",muaccHT_-1,muAccHT_, muaccMHT_-1,muAccMHT_);
  //GetOutputList()->Add(MuAccMHTNJets_);
  MuAccHTMHT_NJets7InfFail_ = (TH2F*)MuAccHTMHT_NJets7Inf_->Clone();
  MuAccHTMHT_NJets7InfFail_->SetName("MuAccHTMHT_NJets7InfFail");
  
  
  ElecAccHTMHT_NJets46_ = new TH2F("ElecAccHTMHT_NJets46","ElecAccHTMHT_NJets46",elecaccHT_-1,elecAccHT_, elecaccMHT_-1,elecAccMHT_);
  //GetOutputList()->Add(ElecAccMHTNJets_);
  ElecAccHTMHT_NJets46Fail_ = (TH2F*)ElecAccHTMHT_NJets46_->Clone();
  ElecAccHTMHT_NJets46Fail_->SetName("ElecAccHTMHT_NJets46Fail");
  
  ElecAccHTMHT_NJets7Inf_ = new TH2F("ElecAccHTMHT_NJets7Inf"," ElecAccHTMHT_NJets7Inf",elecaccHT_-1,elecAccHT_, elecaccMHT_-1,elecAccMHT_);
  //GetOutputList()->Add(ElecAccMHTNJets_);
  ElecAccHTMHT_NJets7InfFail_ = (TH2F*)ElecAccHTMHT_NJets7Inf_->Clone();
  ElecAccHTMHT_NJets7InfFail_->SetName("ElecAccHTMHT_NJets7InfFail");
  
  
  
  // ************************************************************************************************************* 24 June 2015 end****************************************************
  
  
  // ************************************************************************************************************* 25 June 2015 ****************************************************
  
  //1D
  // MU ISO ////////////////////////////////////////////////////////////////////////////
  // muon iso track
  ExpectationReductionMuIsoTrackGenMuBTagEff = new TH1F("ExpectationReductionMuIsoTrackGenMuBTagEff","ExpectationReductionMuIsoTrackGenMuBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuIsoTrackGenMuBTagEffFail = (TH1F*)ExpectationReductionMuIsoTrackGenMuBTagEff->Clone();
  ExpectationReductionMuIsoTrackGenMuBTagEffFail->SetName("ExpectationReductionMuIsoTrackGenMuBTagEffFail");
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionMuIsoTrackGenMuNJetsEff = new TH1F("ExpectationReductionMuIsoTrackGenMuNJetsEff","ExpectationReductionMuIsoTrackGenMuNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuIsoTrackGenMuNJetsEffFail = (TH1F*)ExpectationReductionMuIsoTrackGenMuNJetsEff->Clone();
  ExpectationReductionMuIsoTrackGenMuNJetsEffFail->SetName("ExpectationReductionMuIsoTrackGenMuNJetsEffFail");
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionMuIsoTrackGenMuHTEff = new TH1F("ExpectationReductionMuIsoTrackGenMuHTEff","ExpectationReductionMuIsoTrackGenMuHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuIsoTrackGenMuHTEffFail = (TH1F*)ExpectationReductionMuIsoTrackGenMuHTEff->Clone();
  ExpectationReductionMuIsoTrackGenMuHTEffFail->SetName("ExpectationReductionMuIsoTrackGenMuHTEffFail");
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionMuIsoTrackGenMuMHTEff = new TH1F("ExpectationReductionMuIsoTrackGenMuMHTEff","ExpectationReductionMuIsoTrackGenMuMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuIsoTrackGenMuMHTEffFail = (TH1F*)ExpectationReductionMuIsoTrackGenMuMHTEff->Clone();
  ExpectationReductionMuIsoTrackGenMuMHTEffFail->SetName("ExpectationReductionMuIsoTrackGenMuMHTEffFail");
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionMuIsoTrackGenMuPTEff = new TH1F("ExpectationReductionMuIsoTrackGenMuPTEff","ExpectationReductionMuIsoTrackGenMuPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuIsoTrackGenMuPTEffFail = (TH1F*)ExpectationReductionMuIsoTrackGenMuPTEff->Clone();
  ExpectationReductionMuIsoTrackGenMuPTEffFail->SetName("ExpectationReductionMuIsoTrackGenMuPTEffFail");
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJetsFail_); 
  ExpectationReductionMuIsoTrackGenMuActivityEff = new TH1F("ExpectationReductionMuIsoTrackGenMuActivityEff","ExpectationReductionMuIsoTrackGenMuActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuIsoTrackGenMuActivityEffFail = (TH1F*)ExpectationReductionMuIsoTrackGenMuActivityEff->Clone();
  ExpectationReductionMuIsoTrackGenMuActivityEffFail->SetName("ExpectationReductionMuIsoTrackGenMuActivityEffFail");
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJetsFail_); 
  
  //2D
  MuIsoTrackGenMuReductionHTNJets_ = new TH2F("MuIsoTrackGenMuReductionHTNJets","MuIsoTrackGenMuReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJets_);
  MuIsoTrackGenMuReductionHTNJetsFail_ = (TH2F*)MuIsoTrackGenMuReductionHTNJets_->Clone();
  MuIsoTrackGenMuReductionHTNJetsFail_->SetName("MuIsoTrackGenMuReductionHTNJetsFail");
  //GetOutputList()->Add(MuIsoTrackGenMuReductionHTNJetsFail_); 
  
  MuIsoTrackGenMuReductionMHTNJets_ = new TH2F("MuIsoTrackGenMuReductionMHTNJets","MuIsoTrackGenMuReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionMHTNJets_);
  MuIsoTrackGenMuReductionMHTNJetsFail_ = (TH2F*)MuIsoTrackGenMuReductionMHTNJets_->Clone();
  MuIsoTrackGenMuReductionMHTNJetsFail_->SetName("MuIsoTrackGenMuReductionMHTNJetsFail");
  //GetOutputList()->Add(MuIsoTrackGenMuReductionMHTNJetsFail_); 
  
  MuIsoTrackGenMuReductionBTagNJets_ = new TH2F("MuIsoTrackGenMuReductionBTagNJets","MuIsoTrackGenMuReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionBTagNJets_);
  MuIsoTrackGenMuReductionBTagNJetsFail_ = (TH2F*)MuIsoTrackGenMuReductionBTagNJets_->Clone();
  MuIsoTrackGenMuReductionBTagNJetsFail_->SetName("MuIsoTrackGenMuReductionBTagNJetsFail");
  
  MuIsoTrackGenMuReductionPTActivity_ = new TH2F("MuIsoTrackGenMuReductionPTActivity","MuIsoTrackGenMuReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(MuIsoTrackGenMuReductionPTActivity_);
  MuIsoTrackGenMuReductionPTActivityFail_ = (TH2F*)MuIsoTrackGenMuReductionPTActivity_->Clone();
  MuIsoTrackGenMuReductionPTActivityFail_->SetName("MuIsoTrackGenMuReductionPTActivityFail");
  
  
  // pion iso track
  //1D
  ExpectationReductionPionIsoTrackGenMuBTagEff = new TH1F("ExpectationReductionPionIsoTrackGenMuBTagEff","ExpectationReductionPionIsoTrackGenMuBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenMuBTagEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenMuBTagEff->Clone();
  ExpectationReductionPionIsoTrackGenMuBTagEffFail->SetName("ExpectationReductionPionIsoTrackGenMuBTagEffFail");
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenMuNJetsEff = new TH1F("ExpectationReductionPionIsoTrackGenMuNJetsEff","ExpectationReductionPionIsoTrackGenMuNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenMuNJetsEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenMuNJetsEff->Clone();
  ExpectationReductionPionIsoTrackGenMuNJetsEffFail->SetName("ExpectationReductionPionIsoTrackGenMuNJetsEffFail");
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenMuHTEff = new TH1F("ExpectationReductionPionIsoTrackGenMuHTEff","ExpectationReductionPionIsoTrackGenMuHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenMuHTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenMuHTEff->Clone();
  ExpectationReductionPionIsoTrackGenMuHTEffFail->SetName("ExpectationReductionPionIsoTrackGenMuHTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenMuMHTEff = new TH1F("ExpectationReductionPionIsoTrackGenMuMHTEff","ExpectationReductionPionIsoTrackGenMuMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenMuMHTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenMuMHTEff->Clone();
  ExpectationReductionPionIsoTrackGenMuMHTEffFail->SetName("ExpectationReductionPionIsoTrackGenMuMHTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenMuPTEff = new TH1F("ExpectationReductionPionIsoTrackGenMuPTEff","ExpectationReductionPionIsoTrackGenMuPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenMuPTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenMuPTEff->Clone();
  ExpectationReductionPionIsoTrackGenMuPTEffFail->SetName("ExpectationReductionPionIsoTrackGenMuPTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJetsFail_); 
  ExpectationReductionPionIsoTrackGenMuActivityEff = new TH1F("ExpectationReductionPionIsoTrackGenMuActivityEff","ExpectationReductionPionIsoTrackGenMuActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenMuActivityEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenMuActivityEff->Clone();
  ExpectationReductionPionIsoTrackGenMuActivityEffFail->SetName("ExpectationReductionPionIsoTrackGenMuActivityEffFail");
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJetsFail_); 
  
  //2D
  PionIsoTrackGenMuReductionHTNJets_ = new TH2F("PionIsoTrackGenMuReductionHTNJets","PionIsoTrackGenMuReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJets_);
  PionIsoTrackGenMuReductionHTNJetsFail_ = (TH2F*)PionIsoTrackGenMuReductionHTNJets_->Clone();
  PionIsoTrackGenMuReductionHTNJetsFail_->SetName("PionIsoTrackGenMuReductionHTNJetsFail");
  //GetOutputList()->Add(PionIsoTrackGenMuReductionHTNJetsFail_); 
  
  PionIsoTrackGenMuReductionMHTNJets_ = new TH2F("PionIsoTrackGenMuReductionMHTNJets","PionIsoTrackGenMuReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionMHTNJets_);
  PionIsoTrackGenMuReductionMHTNJetsFail_ = (TH2F*)PionIsoTrackGenMuReductionMHTNJets_->Clone();
  PionIsoTrackGenMuReductionMHTNJetsFail_->SetName("PionIsoTrackGenMuReductionMHTNJetsFail");
  //GetOutputList()->Add(PionIsoTrackGenMuReductionMHTNJetsFail_); 
  
  PionIsoTrackGenMuReductionBTagNJets_ = new TH2F("PionIsoTrackGenMuReductionBTagNJets","PionIsoTrackGenMuReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionBTagNJets_);
  PionIsoTrackGenMuReductionBTagNJetsFail_ = (TH2F*)PionIsoTrackGenMuReductionBTagNJets_->Clone();
  PionIsoTrackGenMuReductionBTagNJetsFail_->SetName("PionIsoTrackGenMuReductionBTagNJetsFail");
  
  PionIsoTrackGenMuReductionPTActivity_ = new TH2F("PionIsoTrackGenMuReductionPTActivity","PionIsoTrackGenMuReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(PionIsoTrackGenMuReductionPTActivity_);
  PionIsoTrackGenMuReductionPTActivityFail_ = (TH2F*)PionIsoTrackGenMuReductionPTActivity_->Clone();
  PionIsoTrackGenMuReductionPTActivityFail_->SetName("PionIsoTrackGenMuReductionPTActivityFail");
  
  
  
  ////////////////////////////////////////////// gen elec 
  
  // elec iso track
  //1D
  ExpectationReductionElecIsoTrackGenElecBTagEff = new TH1F("ExpectationReductionElecIsoTrackGenElecBTagEff","ExpectationReductionElecIsoTrackGenElecBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecIsoTrackGenElecBTagEffFail = (TH1F*)ExpectationReductionElecIsoTrackGenElecBTagEff->Clone();
  ExpectationReductionElecIsoTrackGenElecBTagEffFail->SetName("ExpectationReductionElecIsoTrackGenElecBTagEffFail");
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionElecIsoTrackGenElecNJetsEff = new TH1F("ExpectationReductionElecIsoTrackGenElecNJetsEff","ExpectationReductionElecIsoTrackGenElecNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecIsoTrackGenElecNJetsEffFail = (TH1F*)ExpectationReductionElecIsoTrackGenElecNJetsEff->Clone();
  ExpectationReductionElecIsoTrackGenElecNJetsEffFail->SetName("ExpectationReductionElecIsoTrackGenElecNJetsEffFail");
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionElecIsoTrackGenElecHTEff = new TH1F("ExpectationReductionElecIsoTrackGenElecHTEff","ExpectationReductionElecIsoTrackGenElecHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecIsoTrackGenElecHTEffFail = (TH1F*)ExpectationReductionElecIsoTrackGenElecHTEff->Clone();
  ExpectationReductionElecIsoTrackGenElecHTEffFail->SetName("ExpectationReductionElecIsoTrackGenElecHTEffFail");
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionElecIsoTrackGenElecMHTEff = new TH1F("ExpectationReductionElecIsoTrackGenElecMHTEff","ExpectationReductionElecIsoTrackGenElecMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecIsoTrackGenElecMHTEffFail = (TH1F*)ExpectationReductionElecIsoTrackGenElecMHTEff->Clone();
  ExpectationReductionElecIsoTrackGenElecMHTEffFail->SetName("ExpectationReductionElecIsoTrackGenElecMHTEffFail");
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionElecIsoTrackGenElecPTEff = new TH1F("ExpectationReductionElecIsoTrackGenElecPTEff","ExpectationReductionElecIsoTrackGenElecPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecIsoTrackGenElecPTEffFail = (TH1F*)ExpectationReductionElecIsoTrackGenElecPTEff->Clone();
  ExpectationReductionElecIsoTrackGenElecPTEffFail->SetName("ExpectationReductionElecIsoTrackGenElecPTEffFail");
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJetsFail_); 
  ExpectationReductionElecIsoTrackGenElecActivityEff = new TH1F("ExpectationReductionElecIsoTrackGenElecActivityEff","ExpectationReductionElecIsoTrackGenElecActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecIsoTrackGenElecActivityEffFail = (TH1F*)ExpectationReductionElecIsoTrackGenElecActivityEff->Clone();
  ExpectationReductionElecIsoTrackGenElecActivityEffFail->SetName("ExpectationReductionElecIsoTrackGenElecActivityEffFail");
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJetsFail_); 
  
  //2D
  ElecIsoTrackGenElecReductionHTNJets_ = new TH2F("ElecIsoTrackGenElecReductionHTNJets","ElecIsoTrackGenElecReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJets_);
  ElecIsoTrackGenElecReductionHTNJetsFail_ = (TH2F*)ElecIsoTrackGenElecReductionHTNJets_->Clone();
  ElecIsoTrackGenElecReductionHTNJetsFail_->SetName("ElecIsoTrackGenElecReductionHTNJetsFail");
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionHTNJetsFail_); 
  
  ElecIsoTrackGenElecReductionMHTNJets_ = new TH2F("ElecIsoTrackGenElecReductionMHTNJets","ElecIsoTrackGenElecReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionMHTNJets_);
  ElecIsoTrackGenElecReductionMHTNJetsFail_ = (TH2F*)ElecIsoTrackGenElecReductionMHTNJets_->Clone();
  ElecIsoTrackGenElecReductionMHTNJetsFail_->SetName("ElecIsoTrackGenElecReductionMHTNJetsFail");
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionMHTNJetsFail_); 
  
  ElecIsoTrackGenElecReductionBTagNJets_ = new TH2F("ElecIsoTrackGenElecReductionBTagNJets","ElecIsoTrackGenElecReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionBTagNJets_);
  ElecIsoTrackGenElecReductionBTagNJetsFail_ = (TH2F*)ElecIsoTrackGenElecReductionBTagNJets_->Clone();
  ElecIsoTrackGenElecReductionBTagNJetsFail_->SetName("ElecIsoTrackGenElecReductionBTagNJetsFail");
  
  ElecIsoTrackGenElecReductionPTActivity_ = new TH2F("ElecIsoTrackGenElecReductionPTActivity","ElecIsoTrackGenElecReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(ElecIsoTrackGenElecReductionPTActivity_);
  ElecIsoTrackGenElecReductionPTActivityFail_ = (TH2F*)ElecIsoTrackGenElecReductionPTActivity_->Clone();
  ElecIsoTrackGenElecReductionPTActivityFail_->SetName("ElecIsoTrackGenElecReductionPTActivityFail");
  
  // pion iso track
  //1D
  ExpectationReductionPionIsoTrackGenElecBTagEff = new TH1F("ExpectationReductionPionIsoTrackGenElecBTagEff","ExpectationReductionPionIsoTrackGenElecBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenElecBTagEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenElecBTagEff->Clone();
  ExpectationReductionPionIsoTrackGenElecBTagEffFail->SetName("ExpectationReductionPionIsoTrackGenElecBTagEffFail");
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenElecNJetsEff = new TH1F("ExpectationReductionPionIsoTrackGenElecNJetsEff","ExpectationReductionPionIsoTrackGenElecNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenElecNJetsEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenElecNJetsEff->Clone();
  ExpectationReductionPionIsoTrackGenElecNJetsEffFail->SetName("ExpectationReductionPionIsoTrackGenElecNJetsEffFail");
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenElecHTEff = new TH1F("ExpectationReductionPionIsoTrackGenElecHTEff","ExpectationReductionPionIsoTrackGenElecHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenElecHTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenElecHTEff->Clone();
  ExpectationReductionPionIsoTrackGenElecHTEffFail->SetName("ExpectationReductionPionIsoTrackGenElecHTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenElecMHTEff = new TH1F("ExpectationReductionPionIsoTrackGenElecMHTEff","ExpectationReductionPionIsoTrackGenElecMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenElecMHTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenElecMHTEff->Clone();
  ExpectationReductionPionIsoTrackGenElecMHTEffFail->SetName("ExpectationReductionPionIsoTrackGenElecMHTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenElecPTEff = new TH1F("ExpectationReductionPionIsoTrackGenElecPTEff","ExpectationReductionPionIsoTrackGenElecPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenElecPTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenElecPTEff->Clone();
  ExpectationReductionPionIsoTrackGenElecPTEffFail->SetName("ExpectationReductionPionIsoTrackGenElecPTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJetsFail_); 
  ExpectationReductionPionIsoTrackGenElecActivityEff = new TH1F("ExpectationReductionPionIsoTrackGenElecActivityEff","ExpectationReductionPionIsoTrackGenElecActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenElecActivityEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenElecActivityEff->Clone();
  ExpectationReductionPionIsoTrackGenElecActivityEffFail->SetName("ExpectationReductionPionIsoTrackGenElecActivityEffFail");
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJetsFail_); 
  
  //2D
  PionIsoTrackGenElecReductionHTNJets_ = new TH2F("PionIsoTrackGenElecReductionHTNJets","PionIsoTrackGenElecReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJets_);
  PionIsoTrackGenElecReductionHTNJetsFail_ = (TH2F*)PionIsoTrackGenElecReductionHTNJets_->Clone();
  PionIsoTrackGenElecReductionHTNJetsFail_->SetName("PionIsoTrackGenElecReductionHTNJetsFail");
  //GetOutputList()->Add(PionIsoTrackGenElecReductionHTNJetsFail_); 
  
  PionIsoTrackGenElecReductionMHTNJets_ = new TH2F("PionIsoTrackGenElecReductionMHTNJets","PionIsoTrackGenElecReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionMHTNJets_);
  PionIsoTrackGenElecReductionMHTNJetsFail_ = (TH2F*)PionIsoTrackGenElecReductionMHTNJets_->Clone();
  PionIsoTrackGenElecReductionMHTNJetsFail_->SetName("PionIsoTrackGenElecReductionMHTNJetsFail");
  //GetOutputList()->Add(PionIsoTrackGenElecReductionMHTNJetsFail_); 
  
  PionIsoTrackGenElecReductionBTagNJets_ = new TH2F("PionIsoTrackGenElecReductionBTagNJets","PionIsoTrackGenElecReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionBTagNJets_);
  PionIsoTrackGenElecReductionBTagNJetsFail_ = (TH2F*)PionIsoTrackGenElecReductionBTagNJets_->Clone();
  PionIsoTrackGenElecReductionBTagNJetsFail_->SetName("PionIsoTrackGenElecReductionBTagNJetsFail");
  
  PionIsoTrackGenElecReductionPTActivity_ = new TH2F("PionIsoTrackGenElecReductionPTActivity","PionIsoTrackGenElecReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(PionIsoTrackGenElecReductionPTActivity_);
  PionIsoTrackGenElecReductionPTActivityFail_ = (TH2F*)PionIsoTrackGenElecReductionPTActivity_->Clone();
  PionIsoTrackGenElecReductionPTActivityFail_->SetName("PionIsoTrackGenElecReductionPTActivityFail");
  
  
  ///////////////////////////////// gen had tau
  // pion iso track
  //1D
  ExpectationReductionPionIsoTrackGenHadTauBTagEff = new TH1F("ExpectationReductionPionIsoTrackGenHadTauBTagEff","ExpectationReductionPionIsoTrackGenHadTauBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenHadTauBTagEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenHadTauBTagEff->Clone();
  ExpectationReductionPionIsoTrackGenHadTauBTagEffFail->SetName("ExpectationReductionPionIsoTrackGenHadTauBTagEffFail");
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenHadTauNJetsEff = new TH1F("ExpectationReductionPionIsoTrackGenHadTauNJetsEff","ExpectationReductionPionIsoTrackGenHadTauNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenHadTauNJetsEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenHadTauNJetsEff->Clone();
  ExpectationReductionPionIsoTrackGenHadTauNJetsEffFail->SetName("ExpectationReductionPionIsoTrackGenHadTauNJetsEffFail");
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenHadTauHTEff = new TH1F("ExpectationReductionPionIsoTrackGenHadTauHTEff","ExpectationReductionPionIsoTrackGenHadTauHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenHadTauHTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenHadTauHTEff->Clone();
  ExpectationReductionPionIsoTrackGenHadTauHTEffFail->SetName("ExpectationReductionPionIsoTrackGenHadTauHTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenHadTauMHTEff = new TH1F("ExpectationReductionPionIsoTrackGenHadTauMHTEff","ExpectationReductionPionIsoTrackGenHadTauMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenHadTauMHTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenHadTauMHTEff->Clone();
  ExpectationReductionPionIsoTrackGenHadTauMHTEffFail->SetName("ExpectationReductionPionIsoTrackGenHadTauMHTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJetsFail_); 
  
  ExpectationReductionPionIsoTrackGenHadTauPTEff = new TH1F("ExpectationReductionPionIsoTrackGenHadTauPTEff","ExpectationReductionPionIsoTrackGenHadTauPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenHadTauPTEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenHadTauPTEff->Clone();
  ExpectationReductionPionIsoTrackGenHadTauPTEffFail->SetName("ExpectationReductionPionIsoTrackGenHadTauPTEffFail");
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJetsFail_); 
  ExpectationReductionPionIsoTrackGenHadTauActivityEff = new TH1F("ExpectationReductionPionIsoTrackGenHadTauActivityEff","ExpectationReductionPionIsoTrackGenHadTauActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionIsoTrackGenHadTauActivityEffFail = (TH1F*)ExpectationReductionPionIsoTrackGenHadTauActivityEff->Clone();
  ExpectationReductionPionIsoTrackGenHadTauActivityEffFail->SetName("ExpectationReductionPionIsoTrackGenHadTauActivityEffFail");
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJetsFail_); 
  
  //2D
  PionIsoTrackGenHadTauReductionHTNJets_ = new TH2F("PionIsoTrackGenHadTauReductionHTNJets","PionIsoTrackGenHadTauReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJets_);
  PionIsoTrackGenHadTauReductionHTNJetsFail_ = (TH2F*)PionIsoTrackGenHadTauReductionHTNJets_->Clone();
  PionIsoTrackGenHadTauReductionHTNJetsFail_->SetName("PionIsoTrackGenHadTauReductionHTNJetsFail");
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionHTNJetsFail_); 
  
  PionIsoTrackGenHadTauReductionMHTNJets_ = new TH2F("PionIsoTrackGenHadTauReductionMHTNJets","PionIsoTrackGenHadTauReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionMHTNJets_);
  PionIsoTrackGenHadTauReductionMHTNJetsFail_ = (TH2F*)PionIsoTrackGenHadTauReductionMHTNJets_->Clone();
  PionIsoTrackGenHadTauReductionMHTNJetsFail_->SetName("PionIsoTrackGenHadTauReductionMHTNJetsFail");
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionMHTNJetsFail_); 
  
  PionIsoTrackGenHadTauReductionBTagNJets_ = new TH2F("PionIsoTrackGenHadTauReductionBTagNJets","PionIsoTrackGenHadTauReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionBTagNJets_);
  PionIsoTrackGenHadTauReductionBTagNJetsFail_ = (TH2F*)PionIsoTrackGenHadTauReductionBTagNJets_->Clone();
  PionIsoTrackGenHadTauReductionBTagNJetsFail_->SetName("PionIsoTrackGenHadTauReductionBTagNJetsFail");
  
  PionIsoTrackGenHadTauReductionPTActivity_ = new TH2F("PionIsoTrackGenHadTauReductionPTActivity","PionIsoTrackGenHadTauReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(PionIsoTrackGenHadTauReductionPTActivity_);
  PionIsoTrackGenHadTauReductionPTActivityFail_ = (TH2F*)PionIsoTrackGenHadTauReductionPTActivity_->Clone();
  PionIsoTrackGenHadTauReductionPTActivityFail_->SetName("PionIsoTrackGenHadTauReductionPTActivityFail");
  
  
  // RECO //////////////////////////////////////////////////////////////////////////
  
  // muon iso track
  ExpectationReductionMuRecoTrackGenMuBTagEff = new TH1F("ExpectationReductionMuRecoTrackGenMuBTagEff","ExpectationReductionMuRecoTrackGenMuBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuRecoTrackGenMuBTagEffFail = (TH1F*)ExpectationReductionMuRecoTrackGenMuBTagEff->Clone();
  ExpectationReductionMuRecoTrackGenMuBTagEffFail->SetName("ExpectationReductionMuRecoTrackGenMuBTagEffFail");
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionMuRecoTrackGenMuNJetsEff = new TH1F("ExpectationReductionMuRecoTrackGenMuNJetsEff","ExpectationReductionMuRecoTrackGenMuNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuRecoTrackGenMuNJetsEffFail = (TH1F*)ExpectationReductionMuRecoTrackGenMuNJetsEff->Clone();
  ExpectationReductionMuRecoTrackGenMuNJetsEffFail->SetName("ExpectationReductionMuRecoTrackGenMuNJetsEffFail");
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionMuRecoTrackGenMuHTEff = new TH1F("ExpectationReductionMuRecoTrackGenMuHTEff","ExpectationReductionMuRecoTrackGenMuHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuRecoTrackGenMuHTEffFail = (TH1F*)ExpectationReductionMuRecoTrackGenMuHTEff->Clone();
  ExpectationReductionMuRecoTrackGenMuHTEffFail->SetName("ExpectationReductionMuRecoTrackGenMuHTEffFail");
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionMuRecoTrackGenMuMHTEff = new TH1F("ExpectationReductionMuRecoTrackGenMuMHTEff","ExpectationReductionMuRecoTrackGenMuMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuRecoTrackGenMuMHTEffFail = (TH1F*)ExpectationReductionMuRecoTrackGenMuMHTEff->Clone();
  ExpectationReductionMuRecoTrackGenMuMHTEffFail->SetName("ExpectationReductionMuRecoTrackGenMuMHTEffFail");
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionMuRecoTrackGenMuPTEff = new TH1F("ExpectationReductionMuRecoTrackGenMuPTEff","ExpectationReductionMuRecoTrackGenMuPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuRecoTrackGenMuPTEffFail = (TH1F*)ExpectationReductionMuRecoTrackGenMuPTEff->Clone();
  ExpectationReductionMuRecoTrackGenMuPTEffFail->SetName("ExpectationReductionMuRecoTrackGenMuPTEffFail");
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJetsFail_); 
  ExpectationReductionMuRecoTrackGenMuActivityEff = new TH1F("ExpectationReductionMuRecoTrackGenMuActivityEff","ExpectationReductionMuRecoTrackGenMuActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionMuRecoTrackGenMuActivityEffFail = (TH1F*)ExpectationReductionMuRecoTrackGenMuActivityEff->Clone();
  ExpectationReductionMuRecoTrackGenMuActivityEffFail->SetName("ExpectationReductionMuRecoTrackGenMuActivityEffFail");
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJetsFail_); 
  
  //2D
  MuRecoTrackGenMuReductionHTNJets_ = new TH2F("MuRecoTrackGenMuReductionHTNJets","MuRecoTrackGenMuReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJets_);
  MuRecoTrackGenMuReductionHTNJetsFail_ = (TH2F*)MuRecoTrackGenMuReductionHTNJets_->Clone();
  MuRecoTrackGenMuReductionHTNJetsFail_->SetName("MuRecoTrackGenMuReductionHTNJetsFail");
  //GetOutputList()->Add(MuRecoTrackGenMuReductionHTNJetsFail_); 
  
  MuRecoTrackGenMuReductionMHTNJets_ = new TH2F("MuRecoTrackGenMuReductionMHTNJets","MuRecoTrackGenMuReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionMHTNJets_);
  MuRecoTrackGenMuReductionMHTNJetsFail_ = (TH2F*)MuRecoTrackGenMuReductionMHTNJets_->Clone();
  MuRecoTrackGenMuReductionMHTNJetsFail_->SetName("MuRecoTrackGenMuReductionMHTNJetsFail");
  //GetOutputList()->Add(MuRecoTrackGenMuReductionMHTNJetsFail_); 
  
  MuRecoTrackGenMuReductionBTagNJets_ = new TH2F("MuRecoTrackGenMuReductionBTagNJets","MuRecoTrackGenMuReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionBTagNJets_);
  MuRecoTrackGenMuReductionBTagNJetsFail_ = (TH2F*)MuRecoTrackGenMuReductionBTagNJets_->Clone();
  MuRecoTrackGenMuReductionBTagNJetsFail_->SetName("MuRecoTrackGenMuReductionBTagNJetsFail");
  
  MuRecoTrackGenMuReductionPTActivity_ = new TH2F("MuRecoTrackGenMuReductionPTActivity","MuRecoTrackGenMuReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(MuRecoTrackGenMuReductionPTActivity_);
  MuRecoTrackGenMuReductionPTActivityFail_ = (TH2F*)MuRecoTrackGenMuReductionPTActivity_->Clone();
  MuRecoTrackGenMuReductionPTActivityFail_->SetName("MuRecoTrackGenMuReductionPTActivityFail");
  
  
  // pion iso track
  //1D
  ExpectationReductionPionRecoTrackGenMuBTagEff = new TH1F("ExpectationReductionPionRecoTrackGenMuBTagEff","ExpectationReductionPionRecoTrackGenMuBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenMuBTagEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenMuBTagEff->Clone();
  ExpectationReductionPionRecoTrackGenMuBTagEffFail->SetName("ExpectationReductionPionRecoTrackGenMuBTagEffFail");
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenMuNJetsEff = new TH1F("ExpectationReductionPionRecoTrackGenMuNJetsEff","ExpectationReductionPionRecoTrackGenMuNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenMuNJetsEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenMuNJetsEff->Clone();
  ExpectationReductionPionRecoTrackGenMuNJetsEffFail->SetName("ExpectationReductionPionRecoTrackGenMuNJetsEffFail");
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenMuHTEff = new TH1F("ExpectationReductionPionRecoTrackGenMuHTEff","ExpectationReductionPionRecoTrackGenMuHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenMuHTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenMuHTEff->Clone();
  ExpectationReductionPionRecoTrackGenMuHTEffFail->SetName("ExpectationReductionPionRecoTrackGenMuHTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenMuMHTEff = new TH1F("ExpectationReductionPionRecoTrackGenMuMHTEff","ExpectationReductionPionRecoTrackGenMuMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenMuMHTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenMuMHTEff->Clone();
  ExpectationReductionPionRecoTrackGenMuMHTEffFail->SetName("ExpectationReductionPionRecoTrackGenMuMHTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenMuPTEff = new TH1F("ExpectationReductionPionRecoTrackGenMuPTEff","ExpectationReductionPionRecoTrackGenMuPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenMuPTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenMuPTEff->Clone();
  ExpectationReductionPionRecoTrackGenMuPTEffFail->SetName("ExpectationReductionPionRecoTrackGenMuPTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJetsFail_); 
  ExpectationReductionPionRecoTrackGenMuActivityEff = new TH1F("ExpectationReductionPionRecoTrackGenMuActivityEff","ExpectationReductionPionRecoTrackGenMuActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenMuActivityEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenMuActivityEff->Clone();
  ExpectationReductionPionRecoTrackGenMuActivityEffFail->SetName("ExpectationReductionPionRecoTrackGenMuActivityEffFail");
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJetsFail_); 
  
  //2D
  PionRecoTrackGenMuReductionHTNJets_ = new TH2F("PionRecoTrackGenMuReductionHTNJets","PionRecoTrackGenMuReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJets_);
  PionRecoTrackGenMuReductionHTNJetsFail_ = (TH2F*)PionRecoTrackGenMuReductionHTNJets_->Clone();
  PionRecoTrackGenMuReductionHTNJetsFail_->SetName("PionRecoTrackGenMuReductionHTNJetsFail");
  //GetOutputList()->Add(PionRecoTrackGenMuReductionHTNJetsFail_); 
  
  PionRecoTrackGenMuReductionMHTNJets_ = new TH2F("PionRecoTrackGenMuReductionMHTNJets","PionRecoTrackGenMuReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionMHTNJets_);
  PionRecoTrackGenMuReductionMHTNJetsFail_ = (TH2F*)PionRecoTrackGenMuReductionMHTNJets_->Clone();
  PionRecoTrackGenMuReductionMHTNJetsFail_->SetName("PionRecoTrackGenMuReductionMHTNJetsFail");
  //GetOutputList()->Add(PionRecoTrackGenMuReductionMHTNJetsFail_); 
  
  PionRecoTrackGenMuReductionBTagNJets_ = new TH2F("PionRecoTrackGenMuReductionBTagNJets","PionRecoTrackGenMuReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionBTagNJets_);
  PionRecoTrackGenMuReductionBTagNJetsFail_ = (TH2F*)PionRecoTrackGenMuReductionBTagNJets_->Clone();
  PionRecoTrackGenMuReductionBTagNJetsFail_->SetName("PionRecoTrackGenMuReductionBTagNJetsFail");
  
  PionRecoTrackGenMuReductionPTActivity_ = new TH2F("PionRecoTrackGenMuReductionPTActivity","PionRecoTrackGenMuReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(PionRecoTrackGenMuReductionPTActivity_);
  PionRecoTrackGenMuReductionPTActivityFail_ = (TH2F*)PionRecoTrackGenMuReductionPTActivity_->Clone();
  PionRecoTrackGenMuReductionPTActivityFail_->SetName("PionRecoTrackGenMuReductionPTActivityFail");
  
  
  
  ////////////////////////////////////////////// gen elec 
  
  // elec iso track
  //1D
  ExpectationReductionElecRecoTrackGenElecBTagEff = new TH1F("ExpectationReductionElecRecoTrackGenElecBTagEff","ExpectationReductionElecRecoTrackGenElecBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecRecoTrackGenElecBTagEffFail = (TH1F*)ExpectationReductionElecRecoTrackGenElecBTagEff->Clone();
  ExpectationReductionElecRecoTrackGenElecBTagEffFail->SetName("ExpectationReductionElecRecoTrackGenElecBTagEffFail");
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionElecRecoTrackGenElecNJetsEff = new TH1F("ExpectationReductionElecRecoTrackGenElecNJetsEff","ExpectationReductionElecRecoTrackGenElecNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecRecoTrackGenElecNJetsEffFail = (TH1F*)ExpectationReductionElecRecoTrackGenElecNJetsEff->Clone();
  ExpectationReductionElecRecoTrackGenElecNJetsEffFail->SetName("ExpectationReductionElecRecoTrackGenElecNJetsEffFail");
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionElecRecoTrackGenElecHTEff = new TH1F("ExpectationReductionElecRecoTrackGenElecHTEff","ExpectationReductionElecRecoTrackGenElecHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecRecoTrackGenElecHTEffFail = (TH1F*)ExpectationReductionElecRecoTrackGenElecHTEff->Clone();
  ExpectationReductionElecRecoTrackGenElecHTEffFail->SetName("ExpectationReductionElecRecoTrackGenElecHTEffFail");
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionElecRecoTrackGenElecMHTEff = new TH1F("ExpectationReductionElecRecoTrackGenElecMHTEff","ExpectationReductionElecRecoTrackGenElecMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecRecoTrackGenElecMHTEffFail = (TH1F*)ExpectationReductionElecRecoTrackGenElecMHTEff->Clone();
  ExpectationReductionElecRecoTrackGenElecMHTEffFail->SetName("ExpectationReductionElecRecoTrackGenElecMHTEffFail");
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionElecRecoTrackGenElecPTEff = new TH1F("ExpectationReductionElecRecoTrackGenElecPTEff","ExpectationReductionElecRecoTrackGenElecPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecRecoTrackGenElecPTEffFail = (TH1F*)ExpectationReductionElecRecoTrackGenElecPTEff->Clone();
  ExpectationReductionElecRecoTrackGenElecPTEffFail->SetName("ExpectationReductionElecRecoTrackGenElecPTEffFail");
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJetsFail_); 
  ExpectationReductionElecRecoTrackGenElecActivityEff = new TH1F("ExpectationReductionElecRecoTrackGenElecActivityEff","ExpectationReductionElecRecoTrackGenElecActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionElecRecoTrackGenElecActivityEffFail = (TH1F*)ExpectationReductionElecRecoTrackGenElecActivityEff->Clone();
  ExpectationReductionElecRecoTrackGenElecActivityEffFail->SetName("ExpectationReductionElecRecoTrackGenElecActivityEffFail");
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJetsFail_); 
  
  //2D
  ElecRecoTrackGenElecReductionHTNJets_ = new TH2F("ElecRecoTrackGenElecReductionHTNJets","ElecRecoTrackGenElecReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJets_);
  ElecRecoTrackGenElecReductionHTNJetsFail_ = (TH2F*)ElecRecoTrackGenElecReductionHTNJets_->Clone();
  ElecRecoTrackGenElecReductionHTNJetsFail_->SetName("ElecRecoTrackGenElecReductionHTNJetsFail");
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionHTNJetsFail_); 
  
  ElecRecoTrackGenElecReductionMHTNJets_ = new TH2F("ElecRecoTrackGenElecReductionMHTNJets","ElecRecoTrackGenElecReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionMHTNJets_);
  ElecRecoTrackGenElecReductionMHTNJetsFail_ = (TH2F*)ElecRecoTrackGenElecReductionMHTNJets_->Clone();
  ElecRecoTrackGenElecReductionMHTNJetsFail_->SetName("ElecRecoTrackGenElecReductionMHTNJetsFail");
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionMHTNJetsFail_); 
  
  ElecRecoTrackGenElecReductionBTagNJets_ = new TH2F("ElecRecoTrackGenElecReductionBTagNJets","ElecRecoTrackGenElecReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionBTagNJets_);
  ElecRecoTrackGenElecReductionBTagNJetsFail_ = (TH2F*)ElecRecoTrackGenElecReductionBTagNJets_->Clone();
  ElecRecoTrackGenElecReductionBTagNJetsFail_->SetName("ElecRecoTrackGenElecReductionBTagNJetsFail");
  
  ElecRecoTrackGenElecReductionPTActivity_ = new TH2F("ElecRecoTrackGenElecReductionPTActivity","ElecRecoTrackGenElecReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(ElecRecoTrackGenElecReductionPTActivity_);
  ElecRecoTrackGenElecReductionPTActivityFail_ = (TH2F*)ElecRecoTrackGenElecReductionPTActivity_->Clone();
  ElecRecoTrackGenElecReductionPTActivityFail_->SetName("ElecRecoTrackGenElecReductionPTActivityFail");
  
  // pion iso track
  //1D
  ExpectationReductionPionRecoTrackGenElecBTagEff = new TH1F("ExpectationReductionPionRecoTrackGenElecBTagEff","ExpectationReductionPionRecoTrackGenElecBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenElecBTagEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenElecBTagEff->Clone();
  ExpectationReductionPionRecoTrackGenElecBTagEffFail->SetName("ExpectationReductionPionRecoTrackGenElecBTagEffFail");
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenElecNJetsEff = new TH1F("ExpectationReductionPionRecoTrackGenElecNJetsEff","ExpectationReductionPionRecoTrackGenElecNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenElecNJetsEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenElecNJetsEff->Clone();
  ExpectationReductionPionRecoTrackGenElecNJetsEffFail->SetName("ExpectationReductionPionRecoTrackGenElecNJetsEffFail");
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenElecHTEff = new TH1F("ExpectationReductionPionRecoTrackGenElecHTEff","ExpectationReductionPionRecoTrackGenElecHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenElecHTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenElecHTEff->Clone();
  ExpectationReductionPionRecoTrackGenElecHTEffFail->SetName("ExpectationReductionPionRecoTrackGenElecHTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenElecMHTEff = new TH1F("ExpectationReductionPionRecoTrackGenElecMHTEff","ExpectationReductionPionRecoTrackGenElecMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenElecMHTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenElecMHTEff->Clone();
  ExpectationReductionPionRecoTrackGenElecMHTEffFail->SetName("ExpectationReductionPionRecoTrackGenElecMHTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenElecPTEff = new TH1F("ExpectationReductionPionRecoTrackGenElecPTEff","ExpectationReductionPionRecoTrackGenElecPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenElecPTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenElecPTEff->Clone();
  ExpectationReductionPionRecoTrackGenElecPTEffFail->SetName("ExpectationReductionPionRecoTrackGenElecPTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJetsFail_); 
  ExpectationReductionPionRecoTrackGenElecActivityEff = new TH1F("ExpectationReductionPionRecoTrackGenElecActivityEff","ExpectationReductionPionRecoTrackGenElecActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenElecActivityEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenElecActivityEff->Clone();
  ExpectationReductionPionRecoTrackGenElecActivityEffFail->SetName("ExpectationReductionPionRecoTrackGenElecActivityEffFail");
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJetsFail_); 
  
  //2D
  PionRecoTrackGenElecReductionHTNJets_ = new TH2F("PionRecoTrackGenElecReductionHTNJets","PionRecoTrackGenElecReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJets_);
  PionRecoTrackGenElecReductionHTNJetsFail_ = (TH2F*)PionRecoTrackGenElecReductionHTNJets_->Clone();
  PionRecoTrackGenElecReductionHTNJetsFail_->SetName("PionRecoTrackGenElecReductionHTNJetsFail");
  //GetOutputList()->Add(PionRecoTrackGenElecReductionHTNJetsFail_); 
  
  PionRecoTrackGenElecReductionMHTNJets_ = new TH2F("PionRecoTrackGenElecReductionMHTNJets","PionRecoTrackGenElecReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionMHTNJets_);
  PionRecoTrackGenElecReductionMHTNJetsFail_ = (TH2F*)PionRecoTrackGenElecReductionMHTNJets_->Clone();
  PionRecoTrackGenElecReductionMHTNJetsFail_->SetName("PionRecoTrackGenElecReductionMHTNJetsFail");
  //GetOutputList()->Add(PionRecoTrackGenElecReductionMHTNJetsFail_); 
  
  PionRecoTrackGenElecReductionBTagNJets_ = new TH2F("PionRecoTrackGenElecReductionBTagNJets","PionRecoTrackGenElecReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionBTagNJets_);
  PionRecoTrackGenElecReductionBTagNJetsFail_ = (TH2F*)PionRecoTrackGenElecReductionBTagNJets_->Clone();
  PionRecoTrackGenElecReductionBTagNJetsFail_->SetName("PionRecoTrackGenElecReductionBTagNJetsFail");
  
  PionRecoTrackGenElecReductionPTActivity_ = new TH2F("PionRecoTrackGenElecReductionPTActivity","PionRecoTrackGenElecReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(PionRecoTrackGenElecReductionPTActivity_);
  PionRecoTrackGenElecReductionPTActivityFail_ = (TH2F*)PionRecoTrackGenElecReductionPTActivity_->Clone();
  PionRecoTrackGenElecReductionPTActivityFail_->SetName("PionRecoTrackGenElecReductionPTActivityFail");
  
  
  ///////////////////////////////// gen had tau
  // pion iso track
  //1D
  ExpectationReductionPionRecoTrackGenHadTauBTagEff = new TH1F("ExpectationReductionPionRecoTrackGenHadTauBTagEff","ExpectationReductionPionRecoTrackGenHadTauBTagEff",isotrackreductionBTags_-1,isoTrackReductionBTags_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenHadTauBTagEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenHadTauBTagEff->Clone();
  ExpectationReductionPionRecoTrackGenHadTauBTagEffFail->SetName("ExpectationReductionPionRecoTrackGenHadTauBTagEffFail");
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenHadTauNJetsEff = new TH1F("ExpectationReductionPionRecoTrackGenHadTauNJetsEff","ExpectationReductionPionRecoTrackGenHadTauNJetsEff",isotrackreductionNJets_-1,isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenHadTauNJetsEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenHadTauNJetsEff->Clone();
  ExpectationReductionPionRecoTrackGenHadTauNJetsEffFail->SetName("ExpectationReductionPionRecoTrackGenHadTauNJetsEffFail");
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenHadTauHTEff = new TH1F("ExpectationReductionPionRecoTrackGenHadTauHTEff","ExpectationReductionPionRecoTrackGenHadTauHTEff",isotrackreductionHT_-1,isoTrackReductionHT_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenHadTauHTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenHadTauHTEff->Clone();
  ExpectationReductionPionRecoTrackGenHadTauHTEffFail->SetName("ExpectationReductionPionRecoTrackGenHadTauHTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenHadTauMHTEff = new TH1F("ExpectationReductionPionRecoTrackGenHadTauMHTEff","ExpectationReductionPionRecoTrackGenHadTauMHTEff",isotrackreductionMHT_-1,isoTrackReductionMHT_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenHadTauMHTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenHadTauMHTEff->Clone();
  ExpectationReductionPionRecoTrackGenHadTauMHTEffFail->SetName("ExpectationReductionPionRecoTrackGenHadTauMHTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJetsFail_); 
  
  ExpectationReductionPionRecoTrackGenHadTauPTEff = new TH1F("ExpectationReductionPionRecoTrackGenHadTauPTEff","ExpectationReductionPionRecoTrackGenHadTauPTEff",isotrackreductionPT_-1,isoTrackReductionPT_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenHadTauPTEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenHadTauPTEff->Clone();
  ExpectationReductionPionRecoTrackGenHadTauPTEffFail->SetName("ExpectationReductionPionRecoTrackGenHadTauPTEffFail");
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJetsFail_); 
  ExpectationReductionPionRecoTrackGenHadTauActivityEff = new TH1F("ExpectationReductionPionRecoTrackGenHadTauActivityEff","ExpectationReductionPionRecoTrackGenHadTauActivityEff",isotrackreductionActivity_-1,isoTrackReductionActivity_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJets_);
  ExpectationReductionPionRecoTrackGenHadTauActivityEffFail = (TH1F*)ExpectationReductionPionRecoTrackGenHadTauActivityEff->Clone();
  ExpectationReductionPionRecoTrackGenHadTauActivityEffFail->SetName("ExpectationReductionPionRecoTrackGenHadTauActivityEffFail");
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJetsFail_); 
  
  //2D
  PionRecoTrackGenHadTauReductionHTNJets_ = new TH2F("PionRecoTrackGenHadTauReductionHTNJets","PionRecoTrackGenHadTauReductionHTNJets",isotrackreductionHT_-1,isoTrackReductionHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJets_);
  PionRecoTrackGenHadTauReductionHTNJetsFail_ = (TH2F*)PionRecoTrackGenHadTauReductionHTNJets_->Clone();
  PionRecoTrackGenHadTauReductionHTNJetsFail_->SetName("PionRecoTrackGenHadTauReductionHTNJetsFail");
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionHTNJetsFail_); 
  
  PionRecoTrackGenHadTauReductionMHTNJets_ = new TH2F("PionRecoTrackGenHadTauReductionMHTNJets","PionRecoTrackGenHadTauReductionMHTNJets",isotrackreductionMHT_-1,isoTrackReductionMHT_, isotrackreductionNJets_-1, isoTrackReductionNJets_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionMHTNJets_);
  PionRecoTrackGenHadTauReductionMHTNJetsFail_ = (TH2F*)PionRecoTrackGenHadTauReductionMHTNJets_->Clone();
  PionRecoTrackGenHadTauReductionMHTNJetsFail_->SetName("PionRecoTrackGenHadTauReductionMHTNJetsFail");
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionMHTNJetsFail_); 
  
  PionRecoTrackGenHadTauReductionBTagNJets_ = new TH2F("PionRecoTrackGenHadTauReductionBTagNJets","PionRecoTrackGenHadTauReductionBTagNJets",isotrackreductionBTags2D_-1,isoTrackReductionBTags2D_, isotrackreductionNJets2D_-1, isoTrackReductionNJets2D_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionBTagNJets_);
  PionRecoTrackGenHadTauReductionBTagNJetsFail_ = (TH2F*)PionRecoTrackGenHadTauReductionBTagNJets_->Clone();
  PionRecoTrackGenHadTauReductionBTagNJetsFail_->SetName("PionRecoTrackGenHadTauReductionBTagNJetsFail");
  
  PionRecoTrackGenHadTauReductionPTActivity_ = new TH2F("PionRecoTrackGenHadTauReductionPTActivity","PionRecoTrackGenHadTauReductionPTActivity",isotrackreductionPT2D_-1,isoTrackReductionPT2D_, isotrackreductionActivity2D_-1, isoTrackReductionActivity2D_);
  //GetOutputList()->Add(PionRecoTrackGenHadTauReductionPTActivity_);
  PionRecoTrackGenHadTauReductionPTActivityFail_ = (TH2F*)PionRecoTrackGenHadTauReductionPTActivity_->Clone();
  PionRecoTrackGenHadTauReductionPTActivityFail_->SetName("PionRecoTrackGenHadTauReductionPTActivityFail");
  
  
  // ************************************************************************************************************* 25 June 2015 ****************************************************
  // delta R jet and pT jet
  
  MuIsoPTJetRel_ = new TH1F("MuIsoPTJetRel","MuIsoPTJetRel",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuIsoPT_);
  MuIsoPTJetRelFail_ = (TH1F*)MuIsoPTJetRel_->Clone();
  MuIsoPTJetRelFail_->SetName("MuIsoPTJetRelFail");
  
  MuIsoDeltaRJet_ = new TH1F("MuIsoDeltaRJet","MuIsoDeltaRJet",oneDDeltaR_-1,OneDDeltaR_);
  //GetOutputList()->Add(MuIsoPT_);
  MuIsoDeltaRJetFail_ = (TH1F*)MuIsoDeltaRJet_->Clone();
  MuIsoDeltaRJetFail_->SetName("MuIsoDeltaRJetFail");
  
  MuIsoDeltaRRelPTJet_ = new TH2F("MuIsoDeltaRRelPTJet_","MuIsoDeltaRRelPTJet_",oneDDeltaR_-1,OneDDeltaR_,oneDPTRel_-1,OneDPTRel_);
  //GetOutputList()->Add(MuIsoPT_);
  MuIsoDeltaRRelPTJetFail_ = (TH2F*)MuIsoDeltaRRelPTJet_->Clone();
  MuIsoDeltaRRelPTJetFail_->SetName("MuIsoDeltaRRelPTJetFail");
  
  
  MuRecoPTJetRel_ = new TH1F("MuRecoPTJetRel","MuRecoPTJetRel",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(MuRecoPT_);
  MuRecoPTJetRelFail_ = (TH1F*)MuRecoPTJetRel_->Clone();
  MuRecoPTJetRelFail_->SetName("MuRecoPTJetRelFail");
  
  MuRecoDeltaRJet_ = new TH1F("MuRecoDeltaRJet","MuRecoDeltaRJet",oneDDeltaR_-1,OneDDeltaR_);
  //GetOutputList()->Add(MuRecoPT_);
  MuRecoDeltaRJetFail_ = (TH1F*)MuRecoDeltaRJet_->Clone();
  MuRecoDeltaRJetFail_->SetName("MuRecoDeltaRJetFail");
  
  MuRecoDeltaRRelPTJet_ = new TH2F("MuRecoDeltaRRelPTJet_","MuRecoDeltaRRelPTJet_",oneDDeltaR_-1,OneDDeltaR_,oneDPTRel_-1,OneDPTRel_);
  //GetOutputList()->Add(MuRecoPT_);
  MuRecoDeltaRRelPTJetFail_ = (TH2F*)MuRecoDeltaRRelPTJet_->Clone();
  MuRecoDeltaRRelPTJetFail_->SetName("MuRecoDeltaRRelPTJetFail");
  
  
  ElecIsoPTJetRel_ = new TH1F("ElecIsoPTJetRel","ElecIsoPTJetRel",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecIsoPT_);
  ElecIsoPTJetRelFail_ = (TH1F*)ElecIsoPTJetRel_->Clone();
  ElecIsoPTJetRelFail_->SetName("ElecIsoPTJetRelFail");
  
  ElecIsoDeltaRJet_ = new TH1F("ElecIsoDeltaRJet","ElecIsoDeltaRJet",oneDDeltaR_-1,OneDDeltaR_);
  //GetOutputList()->Add(ElecIsoPT_);
  ElecIsoDeltaRJetFail_ = (TH1F*)ElecIsoDeltaRJet_->Clone();
  ElecIsoDeltaRJetFail_->SetName("ElecIsoDeltaRJetFail");
  
  ElecIsoDeltaRRelPTJet_ = new TH2F("ElecIsoDeltaRRelPTJet_","ElecIsoDeltaRRelPTJet_",oneDDeltaR_-1,OneDDeltaR_,oneDPTRel_-1,OneDPTRel_);
  //GetOutputList()->Add(ElecIsoPT_);
  ElecIsoDeltaRRelPTJetFail_ = (TH2F*)ElecIsoDeltaRRelPTJet_->Clone();
  ElecIsoDeltaRRelPTJetFail_->SetName("ElecIsoDeltaRRelPTJetFail");
  
  
  ElecRecoPTJetRel_ = new TH1F("ElecRecoPTJetRel","ElecRecoPTJetRel",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElecRecoPTJetRelFail_ = (TH1F*)ElecRecoPTJetRel_->Clone();
  ElecRecoPTJetRelFail_->SetName("ElecRecoPTJetRelFail");
  
  ElecRecoDeltaRJet_ = new TH1F("ElecRecoDeltaRJet","ElecRecoDeltaRJet",oneDDeltaR_-1,OneDDeltaR_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElecRecoDeltaRJetFail_ = (TH1F*)ElecRecoDeltaRJet_->Clone();
  ElecRecoDeltaRJetFail_->SetName("ElecRecoDeltaRJetFail");
  
  ElecRecoDeltaRRelPTJet_ = new TH2F("ElecRecoDeltaRRelPTJet_","ElecRecoDeltaRRelPTJet_",oneDDeltaR_-1,OneDDeltaR_,oneDPTRel_-1,OneDPTRel_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElecRecoDeltaRRelPTJetFail_ = (TH2F*)ElecRecoDeltaRRelPTJet_->Clone();
  ElecRecoDeltaRRelPTJetFail_->SetName("ElecRecoDeltaRRelPTJetFail");
  
  // ************************************************************************************************************* 04 July 2015 ****************************************************
  HadTauTrackSingleProngPT = new TH1F("HadTauTrackSingleProngPT","HadTauTrackSingleProngPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackSingleProngPTFail = (TH1F*)HadTauTrackSingleProngPT->Clone();
  HadTauTrackSingleProngPTFail->SetName("HadTauTrackSingleProngPTFail");
  HadTauTrackSingleProngEta = new TH1F("HadTauTrackSingleProngEta","HadTauTrackSingleProngEta",oneDEta_-1,OneDEta_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackSingleProngEtaFail = (TH1F*)HadTauTrackSingleProngEta->Clone();
  HadTauTrackSingleProngEtaFail->SetName("HadTauTrackSingleProngEtaFail");       
  HadTauTrackSingleProngPhi = new TH1F("HadTauTrackSingleProngPhi","HadTauTrackSingleProngPhi",oneDPhi_-1,OneDPhi_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackSingleProngPhiFail = (TH1F*)HadTauTrackSingleProngPhi->Clone();
  HadTauTrackSingleProngPhiFail->SetName("HadTauTrackSingleProngPhiFail");        
  HadTauTrackSingleProngActivity = new TH1F("HadTauTrackSingleProngActivity","HadTauTrackSingleProngActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackSingleProngActivityFail = (TH1F*)HadTauTrackSingleProngActivity->Clone();
  HadTauTrackSingleProngActivityFail->SetName("HadTauTrackSingleProngActivityFail");        
  HadTauTrackSingleProngHT = new TH1F("HadTauTrackSingleProngHT","HadTauTrackSingleProngHT",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackSingleProngHTFail = (TH1F*)HadTauTrackSingleProngHT->Clone();
  HadTauTrackSingleProngHTFail->SetName("HadTauTrackSingleProngHTFail");        
  HadTauTrackSingleProngMHT = new TH1F("HadTauTrackSingleProngMHT","HadTauTrackSingleProngMHT",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackSingleProngMHTFail = (TH1F*)HadTauTrackSingleProngMHT->Clone();
  HadTauTrackSingleProngMHTFail->SetName("HadTauTrackSingleProngMHTFail");        
  HadTauTrackSingleProngNJets = new TH1F("HadTauTrackSingleProngNJets","HadTauTrackSingleProngNJets",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackSingleProngNJetsFail = (TH1F*)HadTauTrackSingleProngNJets->Clone();
  HadTauTrackSingleProngNJetsFail->SetName("HadTauTrackSingleProngNJetsFail");
  HadTauTrackSingleProngBTags = new TH1F("HadTauTrackSingleProngBTags","HadTauTrackSingleProngBTags",oneDBTags_-1,OneDBTags_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackSingleProngBTagsFail = (TH1F*)HadTauTrackSingleProngBTags->Clone();
  HadTauTrackSingleProngBTagsFail->SetName("HadTauTrackSingleProngBTagsFail");
  
  
  HadTauTrackOneChargedAndNeutralsPT = new TH1F("HadTauTrackOneChargedAndNeutralsPT","HadTauTrackOneChargedAndNeutralsPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackOneChargedAndNeutralsPTFail = (TH1F*)HadTauTrackOneChargedAndNeutralsPT->Clone();
  HadTauTrackOneChargedAndNeutralsPTFail->SetName("HadTauTrackOneChargedAndNeutralsPTFail");
  HadTauTrackOneChargedAndNeutralsEta = new TH1F("HadTauTrackOneChargedAndNeutralsEta","HadTauTrackOneChargedAndNeutralsEta",oneDEta_-1,OneDEta_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackOneChargedAndNeutralsEtaFail = (TH1F*)HadTauTrackOneChargedAndNeutralsEta->Clone();
  HadTauTrackOneChargedAndNeutralsEtaFail->SetName("HadTauTrackOneChargedAndNeutralsEtaFail");       
  HadTauTrackOneChargedAndNeutralsPhi = new TH1F("HadTauTrackOneChargedAndNeutralsPhi","HadTauTrackOneChargedAndNeutralsPhi",oneDPhi_-1,OneDPhi_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackOneChargedAndNeutralsPhiFail = (TH1F*)HadTauTrackOneChargedAndNeutralsPhi->Clone();
  HadTauTrackOneChargedAndNeutralsPhiFail->SetName("HadTauTrackOneChargedAndNeutralsPhiFail");        
  HadTauTrackOneChargedAndNeutralsActivity = new TH1F("HadTauTrackOneChargedAndNeutralsActivity","HadTauTrackOneChargedAndNeutralsActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackOneChargedAndNeutralsActivityFail = (TH1F*)HadTauTrackOneChargedAndNeutralsActivity->Clone();
  HadTauTrackOneChargedAndNeutralsActivityFail->SetName("HadTauTrackOneChargedAndNeutralsActivityFail");        
  HadTauTrackOneChargedAndNeutralsHT = new TH1F("HadTauTrackOneChargedAndNeutralsHT","HadTauTrackOneChargedAndNeutralsHT",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackOneChargedAndNeutralsHTFail = (TH1F*)HadTauTrackOneChargedAndNeutralsHT->Clone();
  HadTauTrackOneChargedAndNeutralsHTFail->SetName("HadTauTrackOneChargedAndNeutralsHTFail");        
  HadTauTrackOneChargedAndNeutralsMHT = new TH1F("HadTauTrackOneChargedAndNeutralsMHT","HadTauTrackOneChargedAndNeutralsMHT",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackOneChargedAndNeutralsMHTFail = (TH1F*)HadTauTrackOneChargedAndNeutralsMHT->Clone();
  HadTauTrackOneChargedAndNeutralsMHTFail->SetName("HadTauTrackOneChargedAndNeutralsMHTFail");        
  HadTauTrackOneChargedAndNeutralsNJets = new TH1F("HadTauTrackOneChargedAndNeutralsNJets","HadTauTrackOneChargedAndNeutralsNJets",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackOneChargedAndNeutralsNJetsFail = (TH1F*)HadTauTrackOneChargedAndNeutralsNJets->Clone();
  HadTauTrackOneChargedAndNeutralsNJetsFail->SetName("HadTauTrackOneChargedAndNeutralsNJetsFail");
  HadTauTrackOneChargedAndNeutralsBTags = new TH1F("HadTauTrackOneChargedAndNeutralsBTags","HadTauTrackOneChargedAndNeutralsBTags",oneDBTags_-1,OneDBTags_);
  //GetOutputList()->Add(ElecRecoPT_);
  HadTauTrackOneChargedAndNeutralsBTagsFail = (TH1F*)HadTauTrackOneChargedAndNeutralsBTags->Clone();
  HadTauTrackOneChargedAndNeutralsBTagsFail->SetName("HadTauTrackOneChargedAndNeutralsBTagsFail");
  
  
  
  MuonTrackPT = new TH1F("MuonTrackPT","MuonTrackPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecRecoPT_);
  MuonTrackPTFail = (TH1F*)MuonTrackPT->Clone();
  MuonTrackPTFail->SetName("MuonTrackPTFail");
  MuonTrackEta = new TH1F("MuonTrackEta","MuonTrackEta",oneDEta_-1,OneDEta_);
  //GetOutputList()->Add(ElecRecoPT_);
  MuonTrackEtaFail = (TH1F*)MuonTrackEta->Clone();
  MuonTrackEtaFail->SetName("MuonTrackEtaFail");       
  MuonTrackPhi = new TH1F("MuonTrackPhi","MuonTrackPhi",oneDPhi_-1,OneDPhi_);
  //GetOutputList()->Add(ElecRecoPT_);
  MuonTrackPhiFail = (TH1F*)MuonTrackPhi->Clone();
  MuonTrackPhiFail->SetName("MuonTrackPhiFail");        
  MuonTrackActivity = new TH1F("MuonTrackActivity","MuonTrackActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecRecoPT_);
  MuonTrackActivityFail = (TH1F*)MuonTrackActivity->Clone();
  MuonTrackActivityFail->SetName("MuonTrackActivityFail");        
  MuonTrackHT = new TH1F("MuonTrackHT","MuonTrackHT",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecRecoPT_);
  MuonTrackHTFail = (TH1F*)MuonTrackHT->Clone();
  MuonTrackHTFail->SetName("MuonTrackHTFail");        
  MuonTrackMHT = new TH1F("MuonTrackMHT","MuonTrackMHT",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecRecoPT_);
  MuonTrackMHTFail = (TH1F*)MuonTrackMHT->Clone();
  MuonTrackMHTFail->SetName("MuonTrackMHTFail");        
  MuonTrackNJets = new TH1F("MuonTrackNJets","MuonTrackNJets",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecRecoPT_);
  MuonTrackNJetsFail = (TH1F*)MuonTrackNJets->Clone();
  MuonTrackNJetsFail->SetName("MuonTrackNJetsFail");
  MuonTrackBTags = new TH1F("MuonTrackBTags","MuonTrackBTags",oneDBTags_-1,OneDBTags_);
  //GetOutputList()->Add(ElecRecoPT_);
  MuonTrackBTagsFail = (TH1F*)MuonTrackBTags->Clone();
  MuonTrackBTagsFail->SetName("MuonTrackBTagsFail");
  
  
  ElectronTrackPT = new TH1F("ElectronTrackPT","ElectronTrackPT",oneDPT_-1,OneDPT_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElectronTrackPTFail = (TH1F*)ElectronTrackPT->Clone();
  ElectronTrackPTFail->SetName("ElectronTrackPTFail");
  ElectronTrackEta = new TH1F("ElectronTrackEta","ElectronTrackEta",oneDEta_-1,OneDEta_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElectronTrackEtaFail = (TH1F*)ElectronTrackEta->Clone();
  ElectronTrackEtaFail->SetName("ElectronTrackEtaFail");       
  ElectronTrackPhi = new TH1F("ElectronTrackPhi","ElectronTrackPhi",oneDPhi_-1,OneDPhi_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElectronTrackPhiFail = (TH1F*)ElectronTrackPhi->Clone();
  ElectronTrackPhiFail->SetName("ElectronTrackPhiFail");        
  ElectronTrackActivity = new TH1F("ElectronTrackActivity","ElectronTrackActivity",oneDActivity_-1,OneDActivity_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElectronTrackActivityFail = (TH1F*)ElectronTrackActivity->Clone();
  ElectronTrackActivityFail->SetName("ElectronTrackActivityFail");        
  ElectronTrackHT = new TH1F("ElectronTrackHT","ElectronTrackHT",oneDHT_-1,OneDHT_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElectronTrackHTFail = (TH1F*)ElectronTrackHT->Clone();
  ElectronTrackHTFail->SetName("ElectronTrackHTFail");        
  ElectronTrackMHT = new TH1F("ElectronTrackMHT","ElectronTrackMHT",oneDMHT_-1,OneDMHT_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElectronTrackMHTFail = (TH1F*)ElectronTrackMHT->Clone();
  ElectronTrackMHTFail->SetName("ElectronTrackMHTFail");        
  ElectronTrackNJets = new TH1F("ElectronTrackNJets","ElectronTrackNJets",oneDNJets_-1,OneDNJets_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElectronTrackNJetsFail = (TH1F*)ElectronTrackNJets->Clone();
  ElectronTrackNJetsFail->SetName("ElectronTrackNJetsFail");
  ElectronTrackBTags = new TH1F("ElectronTrackBTags","ElectronTrackBTags",oneDBTags_-1,OneDBTags_);
  //GetOutputList()->Add(ElecRecoPT_);
  ElectronTrackBTagsFail = (TH1F*)ElectronTrackBTags->Clone();
  ElectronTrackBTagsFail->SetName("ElectronTrackBTagsFail");
  // ************************************************************************************************************* 04 July 2015 end ****************************************************
  IsoTrackPass=0;
  IsoTrackPassMu=0;
  IsoTrackPassElec=0;
  IsoTrackPassPion=0;
  IsoTrackFail=0;
  IsoTrackFailMu=0;
  IsoTrackFailElec=0;
  IsoTrackFailPion=0;
}

Bool_t EffMaker::Process(Long64_t entry)
{
  fChain->GetTree()->GetEntry(entry);
  // total expectation
  if(Expectation==1)totalExpectation_->Fill(HT,MHT,NJets,BTags,Weight);
  
  // purity
  // single muon control sample
  // x-check
  if(MuPurity==2)
  {
    //1D
    MuPurityCheckBTag_->Fill(BTags,Weight);
    MuPurityCheckNJets_->Fill(NJets,Weight);
    MuPurityCheckHT_->Fill(HT,Weight);
    MuPurityCheckMHT_->Fill(MHT,Weight);
    //2D
    MuonPurityCheckMHTNJet->Fill(MHT,NJets,Weight);
  }
  if(MuPurity==0)
  {
    //1D
    MuPurityCheckBTagFail_->Fill(BTags,Weight);
    MuPurityCheckNJetsFail_->Fill(NJets,Weight);
    MuPurityCheckHTFail_->Fill(HT,Weight);
    MuPurityCheckMHTFail_->Fill(MHT,Weight);
    //2D
    MuonPurityCheckMHTNJetFail->Fill(MHT,NJets,Weight);
  }
  if(ElecPurity==2)
  {
    //1D
    ElecPurityCheckBTag_->Fill(BTags,Weight);
    ElecPurityCheckNJets_->Fill(NJets,Weight);
    ElecPurityCheckHT_->Fill(HT,Weight);
    ElecPurityCheckMHT_->Fill(MHT,Weight);
    //2D
    ElecPurityCheckMHTNJet->Fill(MHT,NJets,Weight);
  }
  if(ElecPurity==0)
  {
    //1D
    ElecPurityCheckBTagFail_->Fill(BTags,Weight);
    ElecPurityCheckNJetsFail_->Fill(NJets,Weight);
    ElecPurityCheckHTFail_->Fill(HT,Weight);
    ElecPurityCheckMHTFail_->Fill(MHT,Weight);
    //2D
    ElecPurityCheckMHTNJetFail->Fill(MHT,NJets,Weight);
  }
  if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
  {
    if(RecoIsoMuonPromtMatched[0]==1)
    {
      //1D
      MuPurityBTag_->Fill(BTags,Weight);
      MuPurityNJets_->Fill(NJets,Weight);
      MuPurityHT_->Fill(HT,Weight);
      MuPurityMHT_->Fill(MHT,Weight);
      MuPurityPT_->Fill(selectedIDIsoMuonsPt[0],Weight);
      MuPurityActivity_->Fill(RecoIsoMuonActivity[0],Weight);
      //2D
      MuonPurityMHTNJet->Fill(MHT,NJets,Weight);
    }
    if(RecoIsoMuonPromtMatched[0]==0)
    {
      //1D
      MuPurityBTagFail_->Fill(BTags,Weight);
      MuPurityBTagEff_->Fill(BTags,Weight,false);
      MuPurityNJetsFail_->Fill(NJets,Weight);
      MuPurityHTFail_->Fill(HT,Weight);
      MuPurityMHTFail_->Fill(MHT,Weight);
      MuPurityPTFail_->Fill(selectedIDIsoMuonsPt[0],Weight);
      MuPurityActivityFail_->Fill(RecoIsoMuonActivity[0],Weight);
      //2D
      MuonPurityMHTNJetFail->Fill(MHT,NJets,Weight);
      MuonPurityMHTNJetEff_->Fill(MHT,NJets,Weight,false);
    }
  }
  // single elec control sample
  if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
  {
    if(RecoIsoElecPromtMatched[0]==1)
    {
      //1D
      ElecPurityBTag_->Fill(BTags,Weight);
      ElecPurityNJets_->Fill(NJets,Weight);
      ElecPurityHT_->Fill(HT,Weight);
      ElecPurityMHT_->Fill(MHT,Weight);
      ElecPurityPT_->Fill(selectedIDIsoElectronsPt[0],Weight);
      ElecPurityActivity_->Fill(RecoIsoElectronActivity[0],Weight);
      //2D
      ElecPurityMHTNJet->Fill(MHT,NJets,Weight);
    }
    if(RecoIsoElecPromtMatched[0]==0)
    {
      //1D
      ElecPurityBTagFail_->Fill(BTags,Weight);
      ElecPurityNJetsFail_->Fill(NJets,Weight);
      ElecPurityHTFail_->Fill(HT,Weight);
      ElecPurityMHTFail_->Fill(MHT,Weight);
      ElecPurityPTFail_->Fill(selectedIDIsoElectronsPt[0],Weight);
      ElecPurityActivityFail_->Fill(RecoIsoElectronActivity[0],Weight);
      //2D
      ElecPurityMHTNJetFail->Fill(MHT,NJets,Weight);
    }
  }
  // acceptance
  // single muon control sample
  if(muAcc==2)
  {
    //1D
    MuAccBTag_->Fill(BTags,Weight);
    MuAccNJets_->Fill(NJets,Weight);
    MuAccHT_->Fill(HT,Weight);
    MuAccMHT_->Fill(MHT,Weight);
    MuAccPT_->Fill(GenMuPt[0],Weight);
    MuAccActivity_->Fill(GenMuonActivity[0],Weight);
    //2D
    MuAccHTNJets_->Fill(HT,NJets,Weight);
    MuAccMHTNJets_->Fill(MHT,NJets,Weight);
    MuAccBTagNJets_->Fill(BTags,NJets,Weight);
    MuAccMHTNJetsEff_->Fill(MHT,NJets,Weight,true);
    MuAccBTagNJetsEff_->Fill(BTags,NJets,Weight,true);
    if(BTags==0)
    {
      MuAccMHTNJetsB0_->Fill(MHT,NJets,Weight);
    }
    else
    {
      MuAccMHTNJetsB1_Inf_->Fill(MHT,NJets,Weight);
    }
  }
  if(muAcc==0)
  {
    //1D
    MuAccBTagFail_->Fill(BTags,Weight);
    MuAccNJetsFail_->Fill(NJets,Weight);
    MuAccHTFail_->Fill(HT,Weight);
    MuAccMHTFail_->Fill(MHT,Weight);
    MuAccPTFail_->Fill(GenMuPt[0],Weight);
    MuAccActivityFail_->Fill(GenMuonActivity[0],Weight);
    //2D
    MuAccHTNJetsFail_->Fill(HT,NJets,Weight);
    MuAccMHTNJetsFail_->Fill(MHT,NJets,Weight);
    MuAccBTagNJetsFail_->Fill(BTags,NJets,Weight);
    MuAccMHTNJetsEff_->Fill(MHT,NJets,Weight,false);
    MuAccBTagNJetsEff_->Fill(BTags,NJets,Weight,false);
    if(BTags==0)
    {
      MuAccMHTNJetsB0Fail_->Fill(MHT,NJets,Weight);
    }
    else
    {
      MuAccMHTNJetsB1_InfFail_->Fill(MHT,NJets,Weight);
    }
  }
  
  // single elecon control sample
  if(elecAcc==2)
  {
    //1D
    ElecAccBTag_->Fill(BTags,Weight);
    ElecAccNJets_->Fill(NJets,Weight);
    ElecAccHT_->Fill(HT,Weight);
    ElecAccMHT_->Fill(MHT,Weight);
    ElecAccPT_->Fill(GenElecPt[0],Weight);
    ElecAccActivity_->Fill(GenElecActivity[0],Weight);
    //2D
    ElecAccHTNJets_->Fill(HT,NJets,Weight);
    ElecAccMHTNJets_->Fill(MHT,NJets,Weight);
    ElecAccBTagNJets_->Fill(BTags,NJets,Weight);
    if(BTags==0)
    {
      ElecAccMHTNJetsB0_->Fill(MHT,NJets,Weight);
    }
    else
    {
      ElecAccMHTNJetsB1_Inf_->Fill(MHT,NJets,Weight);
    }
  }
  if(elecAcc==0)
  {
    //1D
    ElecAccBTagFail_->Fill(BTags,Weight);
    ElecAccNJetsFail_->Fill(NJets,Weight);
    ElecAccHTFail_->Fill(HT,Weight);
    ElecAccMHTFail_->Fill(MHT,Weight);
    ElecAccPTFail_->Fill(GenElecPt[0],Weight);
    ElecAccActivityFail_->Fill(GenElecActivity[0],Weight);
    //2D
    ElecAccHTNJetsFail_->Fill(HT,NJets,Weight);
    ElecAccMHTNJetsFail_->Fill(MHT,NJets,Weight);
    ElecAccBTagNJetsFail_->Fill(BTags,NJets,Weight);
    if(BTags==0)
    {
      ElecAccMHTNJetsB0Fail_->Fill(MHT,NJets,Weight);
    }
    else
    {
      ElecAccMHTNJetsB1_InfFail_->Fill(MHT,NJets,Weight);
    }
  }
  
  // reconstruction
  // single muon control sample
  if(muReco==2)
  {
    //1D
    MuRecoBTag_->Fill(BTags,Weight);
    MuRecoNJets_->Fill(NJets,Weight);
    MuRecoHT_->Fill(HT,Weight);
    MuRecoMHT_->Fill(MHT,Weight);
    MuRecoPT_->Fill(GenMuPt[0],Weight);
    MuRecoActivity_->Fill(GenMuonActivity[0],Weight);
    MuRecoPTJetRel_->Fill(GenMuDeltaPTJet[0],Weight);
    MuRecoDeltaRJet_->Fill(GenMuDeltaRJet[0],Weight);
    //2D
    MuRecoPTActivity_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    MuRecoDeltaRRelPTJet_->Fill(GenMuDeltaRJet[0],GenMuDeltaPTJet[0],Weight);
  }
  if(muReco==0)
  {
    //1D
    MuRecoBTagFail_->Fill(BTags,Weight);
    MuRecoNJetsFail_->Fill(NJets,Weight);
    MuRecoHTFail_->Fill(HT,Weight);
    MuRecoMHTFail_->Fill(MHT,Weight);
    MuRecoPTFail_->Fill(GenMuPt[0],Weight);
    MuRecoActivityFail_->Fill(GenMuonActivity[0],Weight);
    MuRecoPTJetRelFail_->Fill(GenMuDeltaPTJet[0],Weight);
    MuRecoDeltaRJetFail_->Fill(GenMuDeltaRJet[0],Weight);
    //2D
    MuRecoPTActivityFail_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    MuRecoDeltaRRelPTJetFail_->Fill(GenMuDeltaRJet[0],GenMuDeltaPTJet[0],Weight);
  }
  
  // single elecon control sample
  if(elecReco==2)
  {
    //1D
    ElecRecoBTag_->Fill(BTags,Weight);
    ElecRecoNJets_->Fill(NJets,Weight);
    ElecRecoHT_->Fill(HT,Weight);
    ElecRecoMHT_->Fill(MHT,Weight);
    ElecRecoPT_->Fill(GenElecPt[0],Weight);
    ElecRecoActivity_->Fill(GenElecActivity[0],Weight);
    ElecRecoPTJetRel_->Fill(GenElecDeltaPTJet[0],Weight);
    ElecRecoDeltaRJet_->Fill(GenElecDeltaRJet[0],Weight);
    //2D
    ElecRecoPTActivity_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
    ElecRecoDeltaRRelPTJet_->Fill(GenElecDeltaRJet[0],GenElecDeltaPTJet[0],Weight);
  }
  if(elecReco==0)
  {
    //1D
    ElecRecoBTagFail_->Fill(BTags,Weight);
    ElecRecoNJetsFail_->Fill(NJets,Weight);
    ElecRecoHTFail_->Fill(HT,Weight);
    ElecRecoMHTFail_->Fill(MHT,Weight);
    ElecRecoPTFail_->Fill(GenElecPt[0],Weight);
    ElecRecoActivityFail_->Fill(GenElecActivity[0],Weight);
    ElecRecoPTJetRelFail_->Fill(GenElecDeltaPTJet[0],Weight);
    ElecRecoDeltaRJetFail_->Fill(GenElecDeltaRJet[0],Weight);
    //2D
    ElecRecoPTActivityFail_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
    ElecRecoDeltaRRelPTJetFail_->Fill(GenElecDeltaRJet[0],GenElecDeltaPTJet[0],Weight);
  }
  
  // isolation
  // single muon control sample
  if(muIso==2)
  {
    //1D
    MuIsoBTag_->Fill(BTags,Weight);
    MuIsoNJets_->Fill(NJets,Weight);
    MuIsoHT_->Fill(HT,Weight);
    MuIsoMHT_->Fill(MHT,Weight);
    MuIsoPT_->Fill(GenMuPt[0],Weight);
    MuIsoActivity_->Fill(GenMuonActivity[0],Weight);
    MuIsoPTJetRel_->Fill(GenMuDeltaPTJet[0],Weight);
    MuIsoDeltaRJet_->Fill(GenMuDeltaRJet[0],Weight);
    //2D
    MuIsoPTActivity_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    MuIsoDeltaRRelPTJet_->Fill(GenMuDeltaRJet[0],GenMuDeltaPTJet[0],Weight);
  }
  if(muIso==0)
  {
    //1D
    MuIsoBTagFail_->Fill(BTags,Weight);
    MuIsoNJetsFail_->Fill(NJets,Weight);
    MuIsoHTFail_->Fill(HT,Weight);
    MuIsoMHTFail_->Fill(MHT,Weight);
    MuIsoPTFail_->Fill(GenMuPt[0],Weight);
    MuIsoActivityFail_->Fill(GenMuonActivity[0],Weight);
    MuIsoPTJetRelFail_->Fill(GenMuDeltaPTJet[0],Weight);
    MuIsoDeltaRJetFail_->Fill(GenMuDeltaRJet[0],Weight);
    //2D
    MuIsoPTActivityFail_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    MuIsoDeltaRRelPTJetFail_->Fill(GenMuDeltaRJet[0],GenMuDeltaPTJet[0],Weight);
  }
  
  // single elecon control sample
  if(elecIso==2)
  {
    //1D
    ElecIsoBTag_->Fill(BTags,Weight);
    ElecIsoNJets_->Fill(NJets,Weight);
    ElecIsoHT_->Fill(HT,Weight);
    ElecIsoMHT_->Fill(MHT,Weight);
    ElecIsoPT_->Fill(GenElecPt[0],Weight);
    ElecIsoActivity_->Fill(GenElecActivity[0],Weight);
    ElecIsoPTJetRel_->Fill(GenElecDeltaPTJet[0],Weight);
    ElecIsoDeltaRJet_->Fill(GenElecDeltaRJet[0],Weight);
    //2D
    ElecIsoPTActivity_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
    ElecIsoDeltaRRelPTJet_->Fill(GenElecDeltaRJet[0],GenElecDeltaPTJet[0],Weight);
  }
  if(elecIso==0)
  {
    //1D
    ElecIsoBTagFail_->Fill(BTags,Weight);
    ElecIsoNJetsFail_->Fill(NJets,Weight);
    ElecIsoHTFail_->Fill(HT,Weight);
    ElecIsoMHTFail_->Fill(MHT,Weight);
    ElecIsoPTFail_->Fill(GenElecPt[0],Weight);
    ElecIsoActivityFail_->Fill(GenElecActivity[0],Weight);
    ElecIsoPTJetRelFail_->Fill(GenElecDeltaRJet[0],Weight);
    ElecIsoDeltaRJetFail_->Fill(GenElecDeltaPTJet[0],Weight);
    //2D
    ElecIsoPTActivityFail_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
    ElecIsoDeltaRRelPTJetFail_->Fill(GenElecDeltaRJet[0],GenElecDeltaPTJet[0],Weight);
  }
  // mtw
  // single muon control sample
//   if(selectedIDMuonsNum==1 && selectedIDElectronsNum==0 && MTW < mtwCut_) // added until **** on Aug 17 2015
   if(muIso==2 && MTW < mtwCut_)
  {
    // 1D
    MuMTWBTag_->Fill(BTags,Weight);
    MuMTWNJets_->Fill(NJets,Weight);
    MuMTWHT_->Fill(HT,Weight);
    MuMTWMHT_->Fill(MHT,Weight);
    MuMTWPT_->Fill(selectedIDIsoMuonsPt[0],Weight);
    MuMTWActivity_->Fill(RecoIsoMuonActivity[0],Weight);
    MuMTWPTActivity_->Fill(selectedIDIsoMuonsPt[0],RecoIsoMuonActivity[0],Weight );
  }
//   else if(selectedIDMuonsNum==1 && selectedIDElectronsNum==0 && MTW > mtwCut_) // added until **** on Aug 17 2015
   if(muIso==2 && MTW > mtwCut_)
  {
    // 1D
    MuMTWBTagFail_->Fill(BTags,Weight);
    MuMTWNJetsFail_->Fill(NJets,Weight);
    MuMTWHTFail_->Fill(HT,Weight);
    MuMTWMHTFail_->Fill(MHT,Weight);
    MuMTWPTFail_->Fill(selectedIDIsoMuonsPt[0],Weight);
    MuMTWActivityFail_->Fill(RecoIsoMuonActivity[0],Weight);
    MuMTWPTActivityFail_->Fill(selectedIDIsoMuonsPt[0],RecoIsoMuonActivity[0],Weight );
  }
  
  // single elec control sample
//   if(selectedIDMuonsNum==0 && selectedIDElectronsNum==1 && MTW < mtwCut_) // added until **** on Aug 17 2015
   if(elecIso==2 && MTW < mtwCut_)
  {
    // 1D
    ElecMTWBTag_->Fill(BTags,Weight);
    ElecMTWNJets_->Fill(NJets,Weight);
    ElecMTWHT_->Fill(HT,Weight);
    ElecMTWMHT_->Fill(MHT,Weight);
    ElecMTWPT_->Fill(selectedIDIsoElectronsPt[0],Weight);
    ElecMTWActivity_->Fill(RecoIsoElectronActivity[0],Weight);
    ElecMTWPTActivity_->Fill(selectedIDIsoElectronsPt[0],RecoIsoElectronActivity[0],Weight );
  }
//   if(selectedIDMuonsNum==0 && selectedIDElectronsNum==1 && MTW > mtwCut_) // added until **** on Aug 17 2015
   if(elecIso==2 && MTW > mtwCut_)
  {
    // 1D
    ElecMTWBTagFail_->Fill(BTags,Weight);
    ElecMTWNJetsFail_->Fill(NJets,Weight);
    ElecMTWHTFail_->Fill(HT,Weight);
    ElecMTWMHTFail_->Fill(MHT,Weight);
    ElecMTWPTFail_->Fill(selectedIDIsoElectronsPt[0],Weight);
    ElecMTWActivityFail_->Fill(RecoIsoElectronActivity[0],Weight);
    ElecMTWPTActivityFail_->Fill(selectedIDIsoElectronsPt[0],RecoIsoElectronActivity[0],Weight );
  }
  // di-lep contribution
  if(MuDiLepControlSample==2)
  {
    // 1D

    if(MTW <mtwCut_)
    {
      // 1D
      MuDiLepMTWBTag_->Fill(BTags,Weight);
      MuDiLepMTWNJets_->Fill(NJets,Weight);
      MuDiLepMTWHT_->Fill(HT,Weight);
      MuDiLepMTWMHT_->Fill(MHT,Weight);
    }
    // 1D
    MuDiLepContributionBTag_->Fill(BTags,Weight);
    MuDiLepContributionNJets_->Fill(NJets,Weight);
    MuDiLepContributionHT_->Fill(HT,Weight);
    MuDiLepContributionMHT_->Fill(MHT,Weight);
    if(MTW <mtwCut_)
    {
      // 1D
      MuDiLepContributionMTWBTag_->Fill(BTags,Weight);
      MuDiLepContributionMTWNJets_->Fill(NJets,Weight);
      MuDiLepContributionMTWHT_->Fill(HT,Weight);
      MuDiLepContributionMTWMHT_->Fill(MHT,Weight);
    }
    
  }
  if(MuDiLepControlSample==0)
  {
    
    // 1D
    MuDiLepContributionBTagFail_->Fill(BTags,Weight);
    MuDiLepContributionNJetsFail_->Fill(NJets,Weight);
    MuDiLepContributionHTFail_->Fill(HT,Weight);
    MuDiLepContributionMHTFail_->Fill(MHT,Weight);
    if(MTW <mtwCut_)
    {
      // 1D
      MuDiLepContributionMTWBTagFail_->Fill(BTags,Weight);
      MuDiLepContributionMTWNJetsFail_->Fill(NJets,Weight);
      MuDiLepContributionMTWHTFail_->Fill(HT,Weight);
      MuDiLepContributionMTWMHTFail_->Fill(MHT,Weight);
    }
  }
  if(MuDiLepControlSample==0)
  {
    // 1D
//     MuDiLepBTagFail_->Fill(BTags,Weight);
//     MuDiLepNJetsFail_->Fill(NJets,Weight);
//     MuDiLepHTFail_->Fill(HT,Weight);
//     MuDiLepMHTFail_->Fill(MHT,Weight);
    
    // 1D
    MuDiLepMTWBTagFail_->Fill(BTags,Weight);
    MuDiLepMTWNJetsFail_->Fill(NJets,Weight);
    MuDiLepMTWHTFail_->Fill(HT,Weight);
    MuDiLepMTWMHTFail_->Fill(MHT,Weight);
  }
  
  if(ElecDiLepControlSample==2)
  {
    // 1D
    ElecDiLepBTag_->Fill(BTags,Weight);
    ElecDiLepNJets_->Fill(NJets,Weight);
    ElecDiLepHT_->Fill(HT,Weight);
    ElecDiLepMHT_->Fill(MHT,Weight);
    if(MTW <mtwCut_)
    {
      // 1D
      ElecDiLepMTWBTag_->Fill(BTags,Weight);
      ElecDiLepMTWNJets_->Fill(NJets,Weight);
      ElecDiLepMTWHT_->Fill(HT,Weight);
      ElecDiLepMTWMHT_->Fill(MHT,Weight);
    }
    // 1D
    ElecDiLepContributionBTag_->Fill(BTags,Weight);
    ElecDiLepContributionNJets_->Fill(NJets,Weight);
    ElecDiLepContributionHT_->Fill(HT,Weight);
    ElecDiLepContributionMHT_->Fill(MHT,Weight);
    if(MTW <mtwCut_)
    {
      // 1D
      ElecDiLepContributionMTWBTag_->Fill(BTags,Weight);
      ElecDiLepContributionMTWNJets_->Fill(NJets,Weight);
      ElecDiLepContributionMTWHT_->Fill(HT,Weight);
      ElecDiLepContributionMTWMHT_->Fill(MHT,Weight);
    }
    
  }
  if(ElecDiLepControlSample==0)
  {
    
    // 1D
    ElecDiLepContributionBTagFail_->Fill(BTags,Weight);
    ElecDiLepContributionNJetsFail_->Fill(NJets,Weight);
    ElecDiLepContributionHTFail_->Fill(HT,Weight);
    ElecDiLepContributionMHTFail_->Fill(MHT,Weight);
    if(MTW <mtwCut_)
    {
      // 1D
      ElecDiLepContributionMTWBTagFail_->Fill(BTags,Weight);
      ElecDiLepContributionMTWNJetsFail_->Fill(NJets,Weight);
      ElecDiLepContributionMTWHTFail_->Fill(HT,Weight);
      ElecDiLepContributionMTWMHTFail_->Fill(MHT,Weight);
    }
  }
  
  if(ElecDiLepControlSample==0)
  {
//     // 1D
//     ElecDiLepBTagFail_->Fill(BTags,Weight);
//     ElecDiLepNJetsFail_->Fill(NJets,Weight);
//     ElecDiLepHTFail_->Fill(HT,Weight);
//     ElecDiLepMHTFail_->Fill(MHT,Weight);
//     
    // 1D
    ElecDiLepMTWBTagFail_->Fill(BTags,Weight);
    ElecDiLepMTWNJetsFail_->Fill(NJets,Weight);
    ElecDiLepMTWHTFail_->Fill(HT,Weight);
    ElecDiLepMTWMHTFail_->Fill(MHT,Weight);
  }
  // Aug 18 2015 added beginning
  // di-lep efficiencies overall
//   if((GenMuNum+GenElecNum)==2) 
//   {
//     if(ExpectationDiLep==1) // background
//     {
//       DiLepBTagFail_->Fill(BTags,Weight);
//       DiLepNJetsFail_->Fill(NJets,Weight);
//       DiLepHTFail_->Fill(HT,Weight);
//       DiLepMHTFail_->Fill(MHT,Weight);
//     }
//     else if(MTW<100)// isolated at least one of them
//     {
//       DiLepBTag_->Fill(BTags,Weight);
//       DiLepNJets_->Fill(NJets,Weight);
//       DiLepHT_->Fill(HT,Weight);
//       DiLepMHT_->Fill(MHT,Weight);
//     }
//   }
  // 29 Sep 2015 di lep estimation
  if((GenMuNum+GenElecNum)==2)
  {
    if(selectedIDIsoElectronsNum==0 && selectedIDIsoMuonsNum==0)
    {
      DiLepBTagFail_->Fill(BTags,Weight);
      DiLepNJetsFail_->Fill(NJets,Weight);
      DiLepHTFail_->Fill(HT,Weight);
      DiLepMHTFail_->Fill(MHT,Weight);
      
      MuDiLepBTagFail_->Fill(BTags,Weight);
      MuDiLepNJetsFail_->Fill(NJets,Weight);
      MuDiLepHTFail_->Fill(HT,Weight);
      MuDiLepMHTFail_->Fill(MHT,Weight);
      
      ElecDiLepBTagFail_->Fill(BTags,Weight);
      ElecDiLepNJetsFail_->Fill(NJets,Weight);
      ElecDiLepHTFail_->Fill(HT,Weight);
      ElecDiLepMHTFail_->Fill(MHT,Weight);
      
    }
  }
  if((selectedIDIsoElectronsNum + selectedIDIsoMuonsNum)==1)
  {
    DiLepBTag_->Fill(BTags,Weight/2);
    DiLepNJets_->Fill(NJets,Weight/2);
    DiLepHT_->Fill(HT,Weight/2);
    DiLepMHT_->Fill(MHT,Weight/2);
  }
  if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
  {
    MuDiLepBTag_->Fill(BTags,Weight);
    MuDiLepNJets_->Fill(NJets,Weight);
    MuDiLepHT_->Fill(HT,Weight);
    MuDiLepMHT_->Fill(MHT,Weight);
  }
  if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
  {
    ElecDiLepBTag_->Fill(BTags,Weight);
    ElecDiLepNJets_->Fill(NJets,Weight);
    ElecDiLepHT_->Fill(HT,Weight);
    ElecDiLepMHT_->Fill(MHT,Weight);
  }
  // Aug 18 2015 added end
  // isoalted track
  // muon
  if(GenMuNum==1 && GenElecNum==0)
  {
    if(muIsoTrack==2)
    {
      // 1D
      IsoTrackMuBTag_->Fill(BTags,Weight);
      IsoTrackMuNJets_->Fill(NJets,Weight);
      IsoTrackMuHT_->Fill(HT,Weight);
      IsoTrackMuMHT_->Fill(MHT,Weight);
      //2d
      IsoTrackMuPTActivity_->Fill(GenMuPt[0],GenMuonActivity[0]);
      
    }
    if (muIsoTrack==0)
    {
      // 1D
      IsoTrackMuBTagFail_->Fill(BTags,Weight);
      IsoTrackMuNJetsFail_->Fill(NJets,Weight);
      IsoTrackMuHTFail_->Fill(HT,Weight);
      IsoTrackMuMHTFail_->Fill(MHT,Weight);
      //2d
      IsoTrackMuPTActivityFail_->Fill(GenMuPt[0],GenMuonActivity[0]);
    }
  }
  //   // mtw cut
  //   if(GenMuNum==1 && GenElecNum==0)
  //   {
  //     if(muIsoTrack==2)
  //     {
  //       if(MTWCalculator(MET,METPhi, IsolatedTracksPt[0], IsolatedTracksPhi[0])<mtwCut_)
  //       {
  //      // 1D
  //      IsoTrackMuMTWBTag_->Fill(BTags,Weight);
  //      IsoTrackMuMTWNJets_->Fill(NJets,Weight);
  //      IsoTrackMuMTWHT_->Fill(HT,Weight);
  //      IsoTrackMuMTWMHT_->Fill(MHT,Weight);
  //      // matching efficiency to reco or iso muon
  //      if(StandAloneIsoTrackToMuMatched==2 || StandAloneIsoTrackToRecoMuMatched==2)
  //      {
  //        IsoTrackMuMatchedToIsoMuBTag_->Fill(BTags,Weight);
  //        IsoTrackMuMatchedToIsoMuNJets_->Fill(NJets,Weight);
  //        IsoTrackMuMatchedToIsoMuHT_->Fill(HT,Weight);
  //        IsoTrackMuMatchedToIsoMuMHT_->Fill(MHT,Weight);
  //      }
  //      else
  //      {
  //        IsoTrackMuMatchedToIsoMuBTagFail_->Fill(BTags,Weight);
  //        IsoTrackMuMatchedToIsoMuNJetsFail_->Fill(NJets,Weight);
  //        IsoTrackMuMatchedToIsoMuHTFail_->Fill(HT,Weight);
  //        IsoTrackMuMatchedToIsoMuMHTFail_->Fill(MHT,Weight);
  //      }
  //       }
  //       if(MTWCalculator(MET,METPhi, IsolatedTracksPt[0], IsolatedTracksPhi[0])>mtwCut_)
  //       {
  //      // 1D
  //      IsoTrackMuMTWBTagFail_->Fill(BTags,Weight);
  //      IsoTrackMuMTWNJetsFail_->Fill(NJets,Weight);
  //      IsoTrackMuMTWHTFail_->Fill(HT,Weight);
  //      IsoTrackMuMTWMHTFail_->Fill(MHT,Weight);
  //       }
  //       
  //     }
  //   }
  //   
  //   // elec
  //   
  //   if(GenElecNum==1 && GenMuNum==0 )
  //   {
  //     if(elecIsoTrack==2)
  //     {
  //       // 1D
  //       IsoTrackElecBTag_->Fill(BTags,Weight);
  //       IsoTrackElecNJets_->Fill(NJets,Weight);
  //       IsoTrackElecHT_->Fill(HT,Weight);
  //       IsoTrackElecMHT_->Fill(MHT,Weight);
  //       //2d
  //       IsoTrackElecPTActivity_->Fill(GenElecPt[0],GenElecActivity[0]);
  //     }
  //     if (elecIsoTrack==0)
  //     {
  //       // 1D
  //       IsoTrackElecBTagFail_->Fill(BTags,Weight);
  //       IsoTrackElecNJetsFail_->Fill(NJets,Weight);
  //       IsoTrackElecHTFail_->Fill(HT,Weight);
  //       IsoTrackElecMHTFail_->Fill(MHT,Weight);
  //       //2d
  //       IsoTrackElecPTActivityFail_->Fill(GenElecPt[0],GenElecActivity[0]);
  //     }
  //   }
  //   // mtw cut
  //   if(GenElecNum==1 && GenMuNum==0)
  //   {
  //     if(elecIsoTrack==2)
  //     {
  //       if(MTWCalculator(MET,METPhi, IsolatedTracksPt[0], IsolatedTracksPhi[0])<mtwCut_)
  //       {
  //      // 1D
  //      IsoTrackElecMTWBTag_->Fill(BTags,Weight);
  //      IsoTrackElecMTWNJets_->Fill(NJets,Weight);
  //      IsoTrackElecMTWHT_->Fill(HT,Weight);
  //      IsoTrackElecMTWMHT_->Fill(MHT,Weight);
  //      if(StandAloneIsoTrackToElecMatched==2 || StandAloneIsoTrackToRecoElecMatched==2)
  //      {
  //        IsoTrackElecMatchedToIsoElecBTag_->Fill(BTags,Weight);
  //        IsoTrackElecMatchedToIsoElecNJets_->Fill(NJets,Weight);
  //        IsoTrackElecMatchedToIsoElecHT_->Fill(HT,Weight);
  //        IsoTrackElecMatchedToIsoElecMHT_->Fill(MHT,Weight);
  //      }
  //      else
  //      {
  //        IsoTrackElecMatchedToIsoElecBTagFail_->Fill(BTags,Weight);
  //        IsoTrackElecMatchedToIsoElecNJetsFail_->Fill(NJets,Weight);
  //        IsoTrackElecMatchedToIsoElecHTFail_->Fill(HT,Weight);
  //        IsoTrackElecMatchedToIsoElecMHTFail_->Fill(MHT,Weight);
  //      }
  //       }
  //       if( MTWCalculator(MET,METPhi, IsolatedTracksPt[0], IsolatedTracksPhi[0])>mtwCut_)
  //       {
  //      // 1D
  //      IsoTrackElecMTWBTagFail_->Fill(BTags,Weight);
  //      IsoTrackElecMTWNJetsFail_->Fill(NJets,Weight);
  //      IsoTrackElecMTWHTFail_->Fill(HT,Weight);
  //      IsoTrackElecMTWMHTFail_->Fill(MHT,Weight);
  //       }
  //       
  //     }
  //   }
  // di-leptonic contribution
  if((GenMuNum+GenElecNum)==2)
  {
    // single muon control sample correction due to di-lep contribution
    if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
    {
      // fill here for events that enter in the single muon control sample from di-lep failing: POINT1
      // passing: point 4
    }
    // single elec control sample correction due to di-lep contribution
    if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
    {
      // fill here for events that enter in the single muon control sample from di-lep failing: POINT2
      // passing: point 4
    }
    // single isotrack control sample correction due to di-lep contribution
    //     if(IsolatedTracksNum==1)
    //     {
    //       // fill here for events that enter in the single muon control sample from di-lep failing: POINT3
    //       // passing: point 4
    //     }
    // for efficiency for di-leptonic decays check if non are isolated
    if((selectedIDIsoMuonsNum+selectedIDIsoElectronsNum)==0)
    {
      // failing: point 4
    }
  }
  if(GenMuNum==1 && GenElecNum==0)
  {
    if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
    {
      // passing: POINT1
    }
  }
  if(GenMuNum==0 && GenElecNum==1)
  {
    if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
    {
      //passing: POINT2
    }
  }
  //   if((GenMuNum+GenElecNum)==1)
  //   {
  //     if( IsolatedTracksNum==1)
  //     {
  //      // passing: POINT3
  //     }
  //   }
  //
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  // TEfficiencies
  
  // purity
  // single muon control sample
  if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
  {
    if(RecoIsoMuonPromtMatched[0]==1)
    {
      //1D
      MuPurityBTagEff_->Fill(BTags,Weight,true);
      MuPurityNJetsEff_->Fill(NJets,Weight,true);
      MuPurityHTEff_->Fill(HT,Weight,true);
      MuPurityMHTEff_->Fill(MHT,Weight,true);
      MuPurityPTEff_->Fill(selectedIDIsoMuonsPt[0],Weight,true);
      MuPurityActivityEff_->Fill(RecoIsoMuonActivity[0],Weight,true);
      //2D
      MuonPurityMHTNJetEff_->Fill(MHT,NJets,Weight,true);
      // search bin efficiencies
      MuPuritySearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
      //                      if(MHT>750)std::cout<<"push_back("<<EvtNum<<"); // passing"<<std::endl;
    }
    if(RecoIsoMuonPromtMatched[0]==0)
    {
      //1D
      MuPurityBTagEff_->Fill(BTags,Weight,false);
      MuPurityNJetsEff_->Fill(NJets,Weight,false);
      MuPurityHTEff_->Fill(HT,Weight,false);
      MuPurityMHTEff_->Fill(MHT,Weight,false);
      MuPurityPTEff_->Fill(selectedIDIsoMuonsPt[0],Weight,false);
      MuPurityActivityEff_->Fill(RecoIsoMuonActivity[0],Weight,false);
      //2D
      MuonPurityMHTNJetEff_->Fill(MHT,NJets,Weight,false);
      // search bin efficiencies
      MuPuritySearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
      //                      if(MHT>750)std::cout<<"push_back("<<EvtNum<<"); // failing"<<std::endl;
    }
  }
  // single elec control sample
  if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
  {
    if(RecoIsoElecPromtMatched[0]==1)
    {
      //1D
      ElecPurityBTagEff_->Fill(BTags,Weight,true);
      ElecPurityNJetsEff_->Fill(NJets,Weight,true);
      ElecPurityHTEff_->Fill(HT,Weight,true);
      ElecPurityMHTEff_->Fill(MHT,Weight,true);
      ElecPurityPTEff_->Fill(selectedIDIsoMuonsPt[0],Weight,true);
      ElecPurityActivityEff_->Fill(RecoIsoElectronActivity[0],Weight,true);
      //2D
      ElecPurityMHTNJetEff_->Fill(MHT,NJets,Weight,true);
      // search bin efficiencies
      ElecPuritySearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
    }
    if(RecoIsoElecPromtMatched[0]==0)
    {
      //1D
      ElecPurityBTagEff_->Fill(BTags,Weight,false);
      ElecPurityNJetsEff_->Fill(NJets,Weight,false);
      ElecPurityHTEff_->Fill(HT,Weight,false);
      ElecPurityMHTEff_->Fill(MHT,Weight,false);
      ElecPurityPTEff_->Fill(selectedIDIsoMuonsPt[0],Weight,false);
      ElecPurityActivityEff_->Fill(RecoIsoElectronActivity[0],Weight,false);
      //2D
      ElecPurityMHTNJetEff_->Fill(MHT,NJets,Weight,false);
      // search bin efficiencies
      ElecPuritySearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
    }
  }
  // acceptance
  // single muon control sample
  if(muAcc==2)
  {
    //1D
    MuAccBTagEff_->Fill(BTags,Weight,true);
    MuAccNJetsEff_->Fill(NJets,Weight,true);
    MuAccHTEff_->Fill(HT,Weight,true);
    MuAccMHTEff_->Fill(MHT,Weight,true);
    MuAccPTEff_->Fill(GenMuPt[0],Weight,true);
    MuAccActivityEff_->Fill(GenMuonActivity[0],Weight,true);
    //2D
    MuAccHTNJetsEff_->Fill(HT,NJets,Weight,true);
    MuAccMHTNJetsEff_->Fill(MHT,NJets,Weight,true);
    MuAccBTagNJetsEff_->Fill(BTags,NJets,Weight,true);
    // search bin efficiencies
    MuAccSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
    
    if(NJets<6.5)
    {
      MuAccHTMHT_NJets46_->Fill(HT,MHT,Weight);
    }
    else
    {
      MuAccHTMHT_NJets7Inf_->Fill(HT,MHT,Weight);
    }
  }
  if(muAcc==0)
  {
    //1D
    MuAccBTagEff_->Fill(BTags,Weight,false);
    MuAccNJetsEff_->Fill(NJets,Weight,false);
    MuAccHTEff_->Fill(HT,Weight,false);
    MuAccMHTEff_->Fill(MHT,Weight,false);
    MuAccPTEff_->Fill(GenMuPt[0],Weight,false);
    MuAccActivityEff_->Fill(GenMuonActivity[0],Weight,false);
    //2D
    MuAccHTNJetsEff_->Fill(HT,NJets,Weight,false);
    MuAccMHTNJetsEff_->Fill(MHT,NJets,Weight,false);
    MuAccBTagNJetsEff_->Fill(BTags,NJets,Weight,false);
    // search bin efficiencies
    MuAccSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
    
    if(NJets<6.5)
    {
      MuAccHTMHT_NJets46Fail_->Fill(HT,MHT,Weight);
    }
    else
    {
      MuAccHTMHT_NJets7InfFail_->Fill(HT,MHT,Weight);
    }
  }
  
  // single elecon control sample
  if(elecAcc==2)
  {
    //1D
    ElecAccBTagEff_->Fill(BTags,Weight,true);
    ElecAccNJetsEff_->Fill(NJets,Weight,true);
    ElecAccHTEff_->Fill(HT,Weight,true);
    ElecAccMHTEff_->Fill(MHT,Weight,true);
    ElecAccPTEff_->Fill(GenElecPt[0],Weight,true);
    ElecAccActivityEff_->Fill(GenElecActivity[0],Weight,true);
    //2D
    ElecAccHTNJetsEff_->Fill(HT,NJets,Weight,true);
    ElecAccMHTNJetsEff_->Fill(MHT,NJets,Weight,true);
    ElecAccBTagNJetsEff_->Fill(BTags,NJets,Weight,true);
    // search bin efficiencies
    ElecAccSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
    
    if(NJets<6.5)
    {
      ElecAccHTMHT_NJets46_->Fill(HT,MHT,Weight);
    }
    else
    {
      ElecAccHTMHT_NJets7Inf_->Fill(HT,MHT,Weight);
    }
  }
  if(elecAcc==0)
  {
    //1D
    ElecAccBTagEff_->Fill(BTags,Weight,false);
    ElecAccNJetsEff_->Fill(NJets,Weight,false);
    ElecAccHTEff_->Fill(HT,Weight,false);
    ElecAccMHTEff_->Fill(MHT,Weight,false);
    ElecAccPTEff_->Fill(GenElecPt[0],Weight,false);
    ElecAccActivityEff_->Fill(GenElecActivity[0],Weight,false);
    //2D
    ElecAccHTNJetsEff_->Fill(HT,NJets,Weight,false);
    ElecAccMHTNJetsEff_->Fill(MHT,NJets,Weight,false);
    ElecAccBTagNJetsEff_->Fill(BTags,NJets,Weight,false);
    // search bin efficiencies
    ElecAccSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
    
    if(NJets<6.5)
    {
      ElecAccHTMHT_NJets46Fail_->Fill(HT,MHT,Weight);
    }
    else
    {
      ElecAccHTMHT_NJets7InfFail_->Fill(HT,MHT,Weight);
    }
  }
  
  // reconstruction
  // single muon control sample
  if(muReco==2)
  {
    //1D
    MuRecoBTagEff_->Fill(BTags,Weight,true);
    MuRecoNJetsEff_->Fill(NJets,Weight,true);
    MuRecoHTEff_->Fill(HT,Weight,true);
    MuRecoMHTEff_->Fill(MHT,Weight,true);
    MuRecoPTEff_->Fill(GenMuPt[0],Weight,true);
    MuRecoActivityEff_->Fill(GenMuonActivity[0],Weight,true);
    //2D
    MuRecoPTActivityEff_->Fill(GenMuPt[0],GenMuonActivity[0],Weight,true);
    // search bin efficiencies
    MuRecoSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
  }
  if(muReco==0)
  {
    //1D
    MuRecoBTagEff_->Fill(BTags,Weight,false);
    MuRecoNJetsEff_->Fill(NJets,Weight,false);
    MuRecoHTEff_->Fill(HT,Weight,false);
    MuRecoMHTEff_->Fill(MHT,Weight,false);
    MuRecoPTEff_->Fill(GenMuPt[0],Weight,false);
    MuRecoActivityEff_->Fill(GenMuonActivity[0],Weight,false);
    //2D
    MuRecoPTActivityEff_->Fill(GenMuPt[0],GenMuonActivity[0],Weight,false);
    // search bin efficiencies
    MuRecoSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
  }
  
  // single elecon control sample
  if(elecReco==2)
  {
    //1D
    ElecRecoBTagEff_->Fill(BTags,Weight,true);
    ElecRecoNJetsEff_->Fill(NJets,Weight,true);
    ElecRecoHTEff_->Fill(HT,Weight,true);
    ElecRecoMHTEff_->Fill(MHT,Weight,true);
    ElecRecoPTEff_->Fill(GenElecPt[0],Weight,true);
    ElecRecoActivityEff_->Fill(GenElecActivity[0],Weight,true);
    //2D
    ElecRecoPTActivityEff_->Fill(GenElecPt[0],GenElecActivity[0],Weight,true);
    // search bin efficiencies
    ElecRecoSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
  }
  if(elecReco==0)
  {
    //1D
    ElecRecoBTagEff_->Fill(BTags,Weight,false);
    ElecRecoNJetsEff_->Fill(NJets,Weight,false);
    ElecRecoHTEff_->Fill(HT,Weight,false);
    ElecRecoMHTEff_->Fill(MHT,Weight,false);
    ElecRecoPTEff_->Fill(GenElecPt[0],Weight,false);
    ElecRecoActivityEff_->Fill(GenElecActivity[0],Weight,false);
    //2D
    ElecRecoPTActivityEff_->Fill(GenElecPt[0],GenElecActivity[0],Weight,false);
    // search bin efficiencies
    ElecRecoSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
  }
  
  // isolation
  // single muon control sample
  if(muIso==2)
  {
    //1D
    MuIsoBTagEff_->Fill(BTags,Weight,true);
    MuIsoNJetsEff_->Fill(NJets,Weight,true);
    MuIsoHTEff_->Fill(HT,Weight,true);
    MuIsoMHTEff_->Fill(MHT,Weight,true);
    MuIsoPTEff_->Fill(GenMuPt[0],Weight,true);
    MuIsoActivityEff_->Fill(GenMuonActivity[0],Weight,true);
    //2D
    MuIsoPTActivityEff_->Fill(GenMuPt[0],GenMuonActivity[0],Weight,true);
    // search bin efficiencies
    MuIsoSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
  }
  if(muIso==0)
  {
    //1D
    MuIsoBTagEff_->Fill(BTags,Weight,false);
    MuIsoNJetsEff_->Fill(NJets,Weight,false);
    MuIsoHTEff_->Fill(HT,Weight,false);
    MuIsoMHTEff_->Fill(MHT,Weight,false);
    MuIsoPTEff_->Fill(GenMuPt[0],Weight,false);
    MuIsoActivityEff_->Fill(GenMuonActivity[0],Weight,false);
    //2D
    MuIsoPTActivityEff_->Fill(GenMuPt[0],GenMuonActivity[0],Weight,false);
    // search bin efficiencies
    MuIsoSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
  }
  
  // single elecon control sample
  if(elecIso==2)
  {
    //1D
    ElecIsoBTagEff_->Fill(BTags,Weight,true);
    ElecIsoNJetsEff_->Fill(NJets,Weight,true);
    ElecIsoHTEff_->Fill(HT,Weight,true);
    ElecIsoMHTEff_->Fill(MHT,Weight,true);
    ElecIsoPTEff_->Fill(GenElecPt[0],Weight,true);
    ElecIsoActivityEff_->Fill(GenElecActivity[0],Weight,true);
    //2D
    ElecIsoPTActivityEff_->Fill(GenElecPt[0],GenElecActivity[0],Weight,true);
    // search bin efficiencies
    ElecIsoSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
  }
  if(elecIso==0)
  {
    //1D
    ElecIsoBTagEff_->Fill(BTags,Weight,false);
    ElecIsoNJetsEff_->Fill(NJets,Weight,false);
    ElecIsoHTEff_->Fill(HT,Weight,false);
    ElecIsoMHTEff_->Fill(MHT,Weight,false);
    ElecIsoPTEff_->Fill(GenElecPt[0],Weight,false);
    ElecIsoActivityEff_->Fill(GenElecActivity[0],Weight,false);
    //2D
    ElecIsoPTActivityEff_->Fill(GenElecPt[0],GenElecActivity[0],Weight,false);
    // search bin efficiencies
    ElecIsoSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
  }
  // mtw
  // single muon control sample
  if(muIso==2 && MTW < mtwCut_)
  {
    // 1D
    MuMTWBTagEff_->Fill(BTags,Weight,true);
    MuMTWNJetsEff_->Fill(NJets,Weight,true);
    MuMTWHTEff_->Fill(HT,Weight,true);
    MuMTWMHTEff_->Fill(MHT,Weight,true);
    MuMTWPTEff_->Fill(selectedIDIsoMuonsPt[0],Weight,true);
    MuMTWActivityEff_->Fill(RecoIsoMuonActivity[0],Weight,true);
    MuMTWPTActivityEff_->Fill(selectedIDIsoMuonsPt[0],RecoIsoMuonActivity[0],Weight,true);
    // search bin efficiencies
    MuMTWSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
  }
  if(muIso==2 && MTW > mtwCut_)
  {
    // 1D
    MuMTWBTagEff_->Fill(BTags,Weight,false);
    MuMTWNJetsEff_->Fill(NJets,Weight,false);
    MuMTWHTEff_->Fill(HT,Weight,false);
    MuMTWMHTEff_->Fill(MHT,Weight,false);
    MuMTWPTEff_->Fill(selectedIDIsoMuonsPt[0],Weight,false);
    MuMTWActivityEff_->Fill(RecoIsoMuonActivity[0],Weight,false);
    MuMTWPTActivityEff_->Fill(selectedIDIsoMuonsPt[0],RecoIsoMuonActivity[0],Weight,false);
    // search bin efficiencies
    MuMTWSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
  }
  
  // single elec control sample
  if(elecIso==2 && MTW < mtwCut_)
  {
    // 1D
    ElecMTWBTagEff_->Fill(BTags,Weight,true);
    ElecMTWNJetsEff_->Fill(NJets,Weight,true);
    ElecMTWHTEff_->Fill(HT,Weight,true);
    ElecMTWMHTEff_->Fill(MHT,Weight,true);
    ElecMTWPTEff_->Fill(selectedIDIsoElectronsPt[0],Weight,true);
    ElecMTWActivityEff_->Fill(RecoIsoElectronActivity[0],Weight,true);
    ElecMTWPTActivityEff_->Fill(selectedIDIsoElectronsPt[0],RecoIsoElectronActivity[0],Weight,true);
    // search bin efficiencies
    ElecMTWSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
  }
  if(elecIso==2 && MTW > mtwCut_)
  {
    // 1D
    ElecMTWBTagEff_->Fill(BTags,Weight,false);
    ElecMTWNJetsEff_->Fill(NJets,Weight,false);
    ElecMTWHTEff_->Fill(HT,Weight,false);
    ElecMTWMHTEff_->Fill(MHT,Weight,false);
    ElecMTWPTEff_->Fill(selectedIDIsoElectronsPt[0],Weight,false);
    ElecMTWActivityEff_->Fill(RecoIsoElectronActivity[0],Weight,false);
    ElecMTWPTActivityEff_->Fill(selectedIDIsoElectronsPt[0],RecoIsoElectronActivity[0],Weight,false);
    // search bin efficiencies
    ElecMTWSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
  }
  // di-lep contribution
  if(MuDiLepControlSample==2)
  {
    // 1D
    MuDiLepBTagEff_->Fill(BTags,Weight,true);
    MuDiLepNJetsEff_->Fill(NJets,Weight,true);
    MuDiLepHTEff_->Fill(HT,Weight,true);
    MuDiLepMHTEff_->Fill(MHT,Weight,true);
    // search bin efficiencies
    MuDiLepEffMTWAppliedSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
    if(MTW <mtwCut_)
    {
      // 1D
      MuDiLepMTWBTagEff_->Fill(BTags,Weight,true);
      MuDiLepMTWNJetsEff_->Fill(NJets,Weight,true);
      MuDiLepMTWHTEff_->Fill(HT,Weight,true);
      MuDiLepMTWMHTEff_->Fill(MHT,Weight,true);
    }
    // 1D
    MuDiLepContributionBTagEff_->Fill(BTags,Weight,true);
    MuDiLepContributionNJetsEff_->Fill(NJets,Weight,true);
    MuDiLepContributionHTEff_->Fill(HT,Weight,true);
    MuDiLepContributionMHTEff_->Fill(MHT,Weight,true);
    if(MTW <mtwCut_)
    {
      // 1D
      MuDiLepContributionMTWBTagEff_->Fill(BTags,Weight,true);
      MuDiLepContributionMTWNJetsEff_->Fill(NJets,Weight,true);
      MuDiLepContributionMTWHTEff_->Fill(HT,Weight,true);
      MuDiLepContributionMTWMHTEff_->Fill(MHT,Weight,true);
      // search bin efficiencies
      MuDiLepContributionMTWAppliedSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
    }
    
  }
  if(MuDiLepControlSample==0)
  {
    
    // 1D
    MuDiLepContributionBTagEff_->Fill(BTags,Weight,false);
    MuDiLepContributionNJetsEff_->Fill(NJets,Weight,false);
    MuDiLepContributionHTEff_->Fill(HT,Weight,false);
    MuDiLepContributionMHTEff_->Fill(MHT,Weight,false);
    if(MTW <mtwCut_)
    {
      // 1D
      MuDiLepContributionMTWBTagEff_->Fill(BTags,Weight,false);
      MuDiLepContributionMTWNJetsEff_->Fill(NJets,Weight,false);
      MuDiLepContributionMTWHTEff_->Fill(HT,Weight,false);
      MuDiLepContributionMTWMHTEff_->Fill(MHT,Weight,false);
      // search bin efficiencies
      MuDiLepContributionMTWAppliedSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
    }
  }
  if(MuDiLepControlSample==0)
  {
    // 1D
    MuDiLepBTagEff_->Fill(BTags,Weight,false);
    MuDiLepNJetsEff_->Fill(NJets,Weight,false);
    MuDiLepHTEff_->Fill(HT,Weight,false);
    MuDiLepMHTEff_->Fill(MHT,Weight,false);
    
    // 1D
    MuDiLepMTWBTagEff_->Fill(BTags,Weight,false);
    MuDiLepMTWNJetsEff_->Fill(NJets,Weight,false);
    MuDiLepMTWHTEff_->Fill(HT,Weight,false);
    MuDiLepMTWMHTEff_->Fill(MHT,Weight,false);
    // search bin efficiencies
    MuDiLepEffMTWAppliedSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
  }
  if(ElecDiLepControlSample==2)
  {
    // 1D
    ElecDiLepBTagEff_->Fill(BTags,Weight,true);
    ElecDiLepNJetsEff_->Fill(NJets,Weight,true);
    ElecDiLepHTEff_->Fill(HT,Weight,true);
    ElecDiLepMHTEff_->Fill(MHT,Weight,true);
    // search bin efficiencies
    ElecDiLepEffMTWAppliedSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
    if(MTW <mtwCut_)
    {
      // 1D
      ElecDiLepMTWBTagEff_->Fill(BTags,Weight,true);
      ElecDiLepMTWNJetsEff_->Fill(NJets,Weight,true);
      ElecDiLepMTWHTEff_->Fill(HT,Weight,true);
      ElecDiLepMTWMHTEff_->Fill(MHT,Weight,true);
    }
    // 1D
    ElecDiLepContributionBTagEff_->Fill(BTags,Weight,true);
    ElecDiLepContributionNJetsEff_->Fill(NJets,Weight,true);
    ElecDiLepContributionHTEff_->Fill(HT,Weight,true);
    ElecDiLepContributionMHTEff_->Fill(MHT,Weight,true);
    if(MTW <mtwCut_)
    {
      // 1D
      ElecDiLepContributionMTWBTagEff_->Fill(BTags,Weight,true);
      ElecDiLepContributionMTWNJetsEff_->Fill(NJets,Weight,true);
      ElecDiLepContributionMTWHTEff_->Fill(HT,Weight,true);
      ElecDiLepContributionMTWMHTEff_->Fill(MHT,Weight,true);
      // search bin efficiencies
      ElecDiLepContributionMTWAppliedSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,true);
    }
    
  }
  if(ElecDiLepControlSample==0)
  {
    
    // 1D
    ElecDiLepContributionBTagEff_->Fill(BTags,Weight,false);
    ElecDiLepContributionNJetsEff_->Fill(NJets,Weight,false);
    ElecDiLepContributionHTEff_->Fill(HT,Weight,false);
    ElecDiLepContributionMHTEff_->Fill(MHT,Weight,false);
    if(MTW <mtwCut_)
    {
      // 1D
      ElecDiLepContributionMTWBTagEff_->Fill(BTags,Weight,false);
      ElecDiLepContributionMTWNJetsEff_->Fill(NJets,Weight,false);
      ElecDiLepContributionMTWHTEff_->Fill(HT,Weight,false);
      ElecDiLepContributionMTWMHTEff_->Fill(MHT,Weight,false);
      // search bin efficiencies
      ElecDiLepContributionMTWAppliedSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
    }
  }
  
  if(ElecDiLepControlSample==0)
  {
    // 1D
    ElecDiLepBTagEff_->Fill(BTags,Weight,false);
    ElecDiLepNJetsEff_->Fill(NJets,Weight,false);
    ElecDiLepHTEff_->Fill(HT,Weight,false);
    ElecDiLepMHTEff_->Fill(MHT,Weight,false);
    
    // 1D
    ElecDiLepMTWBTagEff_->Fill(BTags,Weight,false);
    ElecDiLepMTWNJetsEff_->Fill(NJets,Weight,false);
    ElecDiLepMTWHTEff_->Fill(HT,Weight,false);
    ElecDiLepMTWMHTEff_->Fill(MHT,Weight,false);
    // search bin efficiencies
    ElecDiLepEffMTWAppliedSearchBinEff_->Fill(HT,MHT,NJets,BTags,Weight,false);
  }
  
  // isoalted track
  // muon
  
  if(GenMuNum==1 && GenElecNum==0)
  {
    if(muIsoTrack==2)
    {
      // 1D
      IsoTrackMuBTagEff_->Fill(BTags,Weight,true);
      IsoTrackMuNJetsEff_->Fill(NJets,Weight,true);
      IsoTrackMuHTEff_->Fill(HT,Weight,true);
      IsoTrackMuMHTEff_->Fill(MHT,Weight,true);
      
    }
    if (muIsoTrack==0)
    {
      // 1D
      IsoTrackMuBTagEff_->Fill(BTags,Weight,false);
      IsoTrackMuNJetsEff_->Fill(NJets,Weight,false);
      IsoTrackMuHTEff_->Fill(HT,Weight,false);
      IsoTrackMuMHTEff_->Fill(MHT,Weight,false);
    }
  }
  // mtw cut
  //      if(GenMuNum==1 && GenElecNum==0)
  //      {
  //              if(muIsoTrack==2)
  //              {
  //                      if(MTWCalculator(MET,METPhi, IsolatedTracksPt[0], IsolatedTracksPhi[0])<mtwCut_)
  //                      {
  //                              // 1D
  //                              IsoTrackMuMTWBTagEff_->Fill(BTags,Weight,true);
  //                              IsoTrackMuMTWNJetsEff_->Fill(NJets,Weight,true);
  //                              IsoTrackMuMTWHTEff_->Fill(HT,Weight,true);
  //                              IsoTrackMuMTWMHTEff_->Fill(MHT,Weight,true);
  //                              // matching efficiency to reco or iso muon
  //                              if(StandAloneIsoTrackToMuMatched==2 || StandAloneIsoTrackToRecoMuMatched==2)
  //                              {
  //                                      IsoTrackMuMatchedToIsoMuBTagEff_->Fill(BTags,Weight,true);
  //                                      IsoTrackMuMatchedToIsoMuNJetsEff_->Fill(NJets,Weight,true);
  //                                      IsoTrackMuMatchedToIsoMuHTEff_->Fill(HT,Weight,true);
  //                                      IsoTrackMuMatchedToIsoMuMHTEff_->Fill(MHT,Weight,true);
  //                              }
  //                              else
  //                              {
  //                                      IsoTrackMuMatchedToIsoMuBTagEff_->Fill(BTags,Weight,false);
  //                                      IsoTrackMuMatchedToIsoMuNJetsEff_->Fill(NJets,Weight,false);
  //                                      IsoTrackMuMatchedToIsoMuHTEff_->Fill(HT,Weight,false);
  //                                      IsoTrackMuMatchedToIsoMuMHTEff_->Fill(MHT,Weight,false);
  //                              }
  //                      }
  //                      if(MTWCalculator(MET,METPhi, IsolatedTracksPt[0], IsolatedTracksPhi[0])>mtwCut_)
  //                      {
  //                              // 1D
  //                              IsoTrackMuMTWBTagEff_->Fill(BTags,Weight,false);
  //                              IsoTrackMuMTWNJetsEff_->Fill(NJets,Weight,false);
  //                              IsoTrackMuMTWHTEff_->Fill(HT,Weight,false);
  //                              IsoTrackMuMTWMHTEff_->Fill(MHT,Weight,false);
  //                      }
  //                      
  //              }
  //      }
  //      // elec
  //      
  //      if(GenElecNum==1 && GenMuNum==0 )
  //      {
  //              if(elecIsoTrack==2)
  //              {
  //                      // 1D
  //                      IsoTrackElecBTagEff_->Fill(BTags,Weight,true);
  //                      IsoTrackElecNJetsEff_->Fill(NJets,Weight,true);
  //                      IsoTrackElecHTEff_->Fill(HT,Weight,true);
  //                      IsoTrackElecMHTEff_->Fill(MHT,Weight,true);
  //              }
  //              if (elecIsoTrack==0)
  //              {
  //                      // 1D
  //                      IsoTrackElecBTagEff_->Fill(BTags,Weight,false);
  //                      IsoTrackElecNJetsEff_->Fill(NJets,Weight,false);
  //                      IsoTrackElecHTEff_->Fill(HT,Weight,false);
  //                      IsoTrackElecMHTEff_->Fill(MHT,Weight,false);
  //              }
  //      }
  //      // mtw cut
  //      if(GenElecNum==1 && GenMuNum==0)
  //      {
  //              if(elecIsoTrack==2)
  //              {
  //                      if(MTWCalculator(MET,METPhi, IsolatedTracksPt[0], IsolatedTracksPhi[0])<mtwCut_)
  //                      {
  //                              // 1D
  //                              IsoTrackElecMTWBTagEff_->Fill(BTags,Weight,true);
  //                              IsoTrackElecMTWNJetsEff_->Fill(NJets,Weight,true);
  //                              IsoTrackElecMTWHTEff_->Fill(HT,Weight,true);
  //                              IsoTrackElecMTWMHTEff_->Fill(MHT,Weight,true);
  //                              if(StandAloneIsoTrackToElecMatched==2 || StandAloneIsoTrackToRecoElecMatched==2)
  //                              {
  //                                      IsoTrackElecMatchedToIsoElecBTagEff_->Fill(BTags,Weight,true);
  //                                      IsoTrackElecMatchedToIsoElecNJetsEff_->Fill(NJets,Weight,true);
  //                                      IsoTrackElecMatchedToIsoElecHTEff_->Fill(HT,Weight,true);
  //                                      IsoTrackElecMatchedToIsoElecMHTEff_->Fill(MHT,Weight,true);
  //                              }
  //                              else
  //                              {
  //                                      IsoTrackElecMatchedToIsoElecBTagEff_->Fill(BTags,Weight,false);
  //                                      IsoTrackElecMatchedToIsoElecNJetsEff_->Fill(NJets,Weight,false);
  //                                      IsoTrackElecMatchedToIsoElecHTEff_->Fill(HT,Weight,false);
  //                                      IsoTrackElecMatchedToIsoElecMHTEff_->Fill(MHT,Weight,false);
  //                              }
  //                      }
  //                      if( MTWCalculator(MET,METPhi, IsolatedTracksPt[0], IsolatedTracksPhi[0])>mtwCut_)
  //                      {
  //                              // 1D
  //                              IsoTrackElecMTWBTagEff_->Fill(BTags,Weight,false);
  //                              IsoTrackElecMTWNJetsEff_->Fill(NJets,Weight,false);
  //                              IsoTrackElecMTWHTEff_->Fill(HT,Weight,false);
  //                              IsoTrackElecMTWMHTEff_->Fill(MHT,Weight,false);
  //                      }
  //                      
  //              }
  //      }
  // di-leptonic contribution
  if((GenMuNum+GenElecNum)==2)
  {
    // single muon control sample correction due to di-lep contribution
    if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
    {
      // fill here for events that enter in the single muon control sample from di-lep failing: POINT1
      // passing: point 4
    }
    // single elec control sample correction due to di-lep contribution
    if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
    {
      // fill here for events that enter in the single muon control sample from di-lep failing: POINT2
      // passing: point 4
    }
    // single isotrack control sample correction due to di-lep contribution
    //              if(IsolatedTracksNum==1)
    //              {
    //                      // fill here for events that enter in the single muon control sample from di-lep failing: POINT3
    //                      // passing: point 4
    //              }
    // for efficiency for di-leptonic decays check if non are isolated
    if((selectedIDIsoMuonsNum+selectedIDIsoElectronsNum)==0)
    {
      // failing: point 4
    }
  }
  if(GenMuNum==1 && GenElecNum==0)
  {
    if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
    {
      // passing: POINT1
    }
  }
  if(GenMuNum==0 && GenElecNum==1)
  {
    if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
    {
      //passing: POINT2
    }
  }
  //      if((GenMuNum+GenElecNum)==1)
  //      {
  //              if( IsolatedTracksNum==1)
  //              {
  //                      // passing: POINT3
  //              }
  //      }
  // ExpectationReductionIsoTrack
  if(Expectation==1 && ExpectationReductionIsoTrack==0)
  {
    ExpectationReductionIsoTrackBTagEff_->Fill(BTags,Weight,false);
    ExpectationReductionIsoTrackNJetsEff_->Fill(NJets,Weight,false);
    ExpectationReductionIsoTrackHTEff_->Fill(HT,Weight,false);
    ExpectationReductionIsoTrackMHTEff_->Fill(MHT,Weight,false);
    // search bin efficiencies
    ExpectationReductionIsoTrack_->Fill(HT,MHT,NJets,BTags,Weight,false);
    
    ExpectationReductionIsoTrackBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionIsoTrackNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionIsoTrackHTEffFail->Fill(HT,Weight);
    ExpectationReductionIsoTrackMHTEffFail->Fill(MHT,Weight);
    if(GenMuNum>0)
    {
      ExpectationReductionIsoTrackPTEffFail->Fill(GenMuPt[0],Weight);
      ExpectationReductionIsoTrackActivityEffFail->Fill(GenMuonActivity[0],Weight);
    }
    else if(GenElecNum>0)
    {
      ExpectationReductionIsoTrackPTEffFail->Fill(GenMuPt[0],Weight);
      ExpectationReductionIsoTrackActivityEffFail->Fill(GenElecActivity[0],Weight);
    }
    else if(GenTauNum>0)
    {
      ExpectationReductionIsoTrackPTEffFail->Fill(GenTauPt[0],Weight);
      ExpectationReductionIsoTrackActivityEffFail->Fill(GenTauActivity[0],Weight);
    }
    else std::cout<<"No gen lepton found to fail..."<<std::endl;
    
    //2D
    IsoTrackReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    IsoTrackReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    IsoTrackReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    if(GenMuNum>0)
    {
      IsoTrackReductionPTActivityFail_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    }
    else if(GenElecNum>0)
    {
      IsoTrackReductionPTActivityFail_->Fill(GenMuPt[0],GenElecActivity[0],Weight);
    }
    else if(GenTauNum>0)
    {
      IsoTrackReductionPTActivityFail_->Fill(GenTauPt[0],GenTauActivity[0],Weight);
    }
    
  }
  
  if(Expectation==1 && ExpectationReductionIsoTrack==1)
  {
    ExpectationReductionIsoTrackBTagEff_->Fill(BTags,Weight,true);
    ExpectationReductionIsoTrackNJetsEff_->Fill(NJets,Weight,true);
    ExpectationReductionIsoTrackHTEff_->Fill(HT,Weight,true);
    ExpectationReductionIsoTrackMHTEff_->Fill(MHT,Weight,true);
    // search bin efficiencies
    ExpectationReductionIsoTrack_->Fill(HT,MHT,NJets,BTags,Weight,true);
    
    ExpectationReductionIsoTrackBTagEff->Fill(BTags,Weight);
    ExpectationReductionIsoTrackNJetsEff->Fill(NJets,Weight);
    ExpectationReductionIsoTrackHTEff->Fill(HT,Weight);
    ExpectationReductionIsoTrackMHTEff->Fill(MHT,Weight);
    if(IsolatedMuonTracksVetoNum>0)
    {
      ExpectationReductionIsoTrackPTEff->Fill(IsolatedMuonTracksVetoPt[0],Weight);
      ExpectationReductionIsoTrackActivityEff->Fill(IsolatedMuonTracksVetoActivity[0],Weight);
    }
    else if(IsolatedElectronTracksVetoNum>0)
    {
      ExpectationReductionIsoTrackPTEff->Fill(IsolatedElectronTracksVetoPt[0],Weight);
      ExpectationReductionIsoTrackActivityEff->Fill(IsolatedElectronTracksVetoActivity[0],Weight);
    }
    else if(IsolatedPionTracksVetoNum>0)
    {
      ExpectationReductionIsoTrackPTEff->Fill(IsolatedPionTracksVetoPt[0],Weight);
      ExpectationReductionIsoTrackActivityEff->Fill(IsolatedPionTracksVetoActivity[0],Weight);
    }
    //2D
    IsoTrackReductionHTNJets_->Fill(HT,NJets,Weight);
    IsoTrackReductionMHTNJets_->Fill(MHT,NJets,Weight);
    IsoTrackReductionBTagNJets_->Fill(BTags,NJets,Weight);
    if(IsolatedMuonTracksVetoNum>0)
    {
      IsoTrackReductionPTActivity_->Fill(IsolatedMuonTracksVetoPt[0],IsolatedMuonTracksVetoActivity[0],Weight);
    } 
    else if(IsolatedElectronTracksVetoNum>0)
    {
      IsoTrackReductionPTActivity_->Fill(IsolatedElectronTracksVetoPt[0],IsolatedElectronTracksVetoActivity[0],Weight);
    }
    else if(IsolatedPionTracksVetoNum>0)
    {
      IsoTrackReductionPTActivity_->Fill(IsolatedPionTracksVetoPt[0],IsolatedPionTracksVetoActivity[0],Weight);
    }
    
  }
  // ************************************************************************************************************* 07 June 2015 **********************************
  if(Expectation==1 && ExpectationReductionIsoTrack==1)
  {
    IsoTrackPass+=Weight;
    if(IsolatedMuonTracksVetoNum>0 && IsolatedElectronTracksVetoNum==0 && IsolatedPionTracksVetoNum==0 && GenMuNum>0)
    {
      IsoTrackPassMu+=Weight;
      ExpectationReductionMuIsoTrackBTagEff->Fill(BTags,Weight);
      ExpectationReductionMuIsoTrackNJetsEff->Fill(NJets,Weight);
      ExpectationReductionMuIsoTrackHTEff->Fill(HT,Weight);
      ExpectationReductionMuIsoTrackMHTEff->Fill(MHT,Weight);
      ExpectationReductionMuIsoTrackPTEff->Fill(IsolatedMuonTracksVetoPt[0],Weight);
      ExpectationReductionMuIsoTrackActivityEff->Fill(IsolatedMuonTracksVetoActivity[0],Weight);
      
      //2D
      MuIsoTrackReductionHTNJets_->Fill(HT,NJets,Weight);
      MuIsoTrackReductionMHTNJets_->Fill(MHT,NJets,Weight);
      MuIsoTrackReductionBTagNJets_->Fill(BTags,NJets,Weight);
      MuIsoTrackReductionPTActivity_->Fill(IsolatedMuonTracksVetoPt[0],IsolatedMuonTracksVetoActivity[0],Weight);
    }
    else if(IsolatedMuonTracksVetoNum==0 && IsolatedElectronTracksVetoNum>0 && IsolatedPionTracksVetoNum==0 && GenElecNum>0)
    {
      IsoTrackPassElec+=Weight;
      ExpectationReductionElecIsoTrackBTagEff->Fill(BTags,Weight);
      ExpectationReductionElecIsoTrackNJetsEff->Fill(NJets,Weight);
      ExpectationReductionElecIsoTrackHTEff->Fill(HT,Weight);
      ExpectationReductionElecIsoTrackMHTEff->Fill(MHT,Weight);
      ExpectationReductionElecIsoTrackPTEff->Fill(IsolatedElectronTracksVetoPt[0],Weight);
      ExpectationReductionElecIsoTrackActivityEff->Fill(IsolatedElectronTracksVetoActivity[0],Weight);
      
      //2D
      ElecIsoTrackReductionHTNJets_->Fill(HT,NJets,Weight);
      ElecIsoTrackReductionMHTNJets_->Fill(MHT,NJets,Weight);
      ElecIsoTrackReductionBTagNJets_->Fill(BTags,NJets,Weight);
      ElecIsoTrackReductionPTActivity_->Fill(IsolatedElectronTracksVetoPt[0],IsolatedElectronTracksVetoActivity[0],Weight);
    }
    else if( IsolatedPionTracksVetoNum>0 && (GenElecNum>0|| GenMuNum>0))
    {
      IsoTrackPassPion+=Weight;
      ExpectationReductionPionIsoTrackBTagEff->Fill(BTags,Weight);
      ExpectationReductionPionIsoTrackNJetsEff->Fill(NJets,Weight);
      ExpectationReductionPionIsoTrackHTEff->Fill(HT,Weight);
      ExpectationReductionPionIsoTrackMHTEff->Fill(MHT,Weight);
      ExpectationReductionPionIsoTrackPTEff->Fill(IsolatedPionTracksVetoPt[0],Weight);
      ExpectationReductionPionIsoTrackActivityEff->Fill(IsolatedPionTracksVetoActivity[0],Weight);
      
      //2D
      PionIsoTrackReductionHTNJets_->Fill(HT,NJets,Weight);
      PionIsoTrackReductionMHTNJets_->Fill(MHT,NJets,Weight);
      PionIsoTrackReductionBTagNJets_->Fill(BTags,NJets,Weight);
      PionIsoTrackReductionPTActivity_->Fill(IsolatedPionTracksVetoPt[0],IsolatedPionTracksVetoActivity[0],Weight);
    }
    else if(IsolatedMuonTracksVetoNum==0 && IsolatedElectronTracksVetoNum==0 && IsolatedPionTracksVetoNum==0)
    {
      std::cout<<"No Tracks found should not happen!\n";
    }
    else 
    {
      std::cout<<"should not happen...\n";
      std::cout<<"IsolatedMuonTracksVetoNum: "<<IsolatedMuonTracksVetoNum<<" IsolatedElectronTracksVetoNum: "<<IsolatedElectronTracksVetoNum << " IsolatedPionTracksVetoNum: "<<IsolatedPionTracksVetoNum<<std::endl;
    }
  }
  if(Expectation==1 && ExpectationReductionIsoTrack==0)
  {
    IsoTrackFail+=Weight;
  }
  if(Expectation==1)
  {
    //           if(GenMuNum>0){
    // mu
    ExpectationReductionMuIsoTrackBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionMuIsoTrackNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionMuIsoTrackHTEffFail->Fill(HT,Weight);
    ExpectationReductionMuIsoTrackMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionMuIsoTrackPTEffFail->Fill(IsolatedMuonTracksVetoPt[0],Weight);
    ExpectationReductionMuIsoTrackActivityEffFail->Fill(IsolatedMuonTracksVetoActivity[0],Weight);
    //2D
    MuIsoTrackReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    MuIsoTrackReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    MuIsoTrackReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    MuIsoTrackReductionPTActivityFail_->Fill(IsolatedMuonTracksVetoPt[0],IsolatedMuonTracksVetoActivity[0],Weight);
    IsoTrackFailMu+=Weight;
    //                                      }
    // electron
    //           if(GenElecNum>0)
    //                                      {
    ExpectationReductionElecIsoTrackBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionElecIsoTrackNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionElecIsoTrackHTEffFail->Fill(HT,Weight);
    ExpectationReductionElecIsoTrackMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionElecIsoTrackPTEffFail->Fill(IsolatedElectronTracksVetoPt[0],Weight);
    ExpectationReductionElecIsoTrackActivityEffFail->Fill(IsolatedElectronTracksVetoActivity[0],Weight);
    //2D
    ElecIsoTrackReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    ElecIsoTrackReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    ElecIsoTrackReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    ElecIsoTrackReductionPTActivityFail_->Fill(IsolatedElectronTracksVetoPt[0],IsolatedElectronTracksVetoActivity[0],Weight);
    IsoTrackFailElec+=Weight;
    //                                      }
    //pion track
    //           if(GenElecNum>0 || GenMuNum>0)
    //                                      {
    ExpectationReductionPionIsoTrackBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionPionIsoTrackNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionPionIsoTrackHTEffFail->Fill(HT,Weight);
    ExpectationReductionPionIsoTrackMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionPionIsoTrackPTEffFail->Fill(IsolatedPionTracksVetoPt[0],Weight);
    ExpectationReductionPionIsoTrackActivityEffFail->Fill(IsolatedPionTracksVetoActivity[0],Weight);
    //2D
    PionIsoTrackReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    PionIsoTrackReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    PionIsoTrackReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    PionIsoTrackReductionPTActivityFail_->Fill(IsolatedPionTracksVetoPt[0],IsolatedPionTracksVetoActivity[0],Weight);
    IsoTrackFailPion+=Weight;
    //                                      }
  }
  // ************************************************************************************************************* 22 June 2015 ****************************************************
  // muon iso tracks
  /*
   *        int genLeptons= GenElecNum + GenMuNum ;
   *        if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (genLeptons)>0 && IsolatedMuonTracksVetoNum==0 && IsolatedPionTracksVetoNum==0 && IsolatedElectronTracksVetoNum==0 )
   * //          if(Expectation==1 && IsolatedMuonTracksVetoNum==0 && IsolatedPionTracksVetoNum==0 && IsolatedElectronTracksVetoNum==0)
   *        {
   *                ExpectationReductionMuIsoTrackBTagEffFail->Fill(BTags,Weight);
   *                ExpectationReductionMuIsoTrackNJetsEffFail->Fill(NJets,Weight);
   *                ExpectationReductionMuIsoTrackHTEffFail->Fill(HT,Weight);
   *                ExpectationReductionMuIsoTrackMHTEffFail->Fill(MHT,Weight);
   *                ExpectationReductionMuIsoTrackPTEffFail->Fill(IsolatedMuonTracksVetoPt[0],Weight);
   *                ExpectationReductionMuIsoTrackActivityEffFail->Fill(IsolatedMuonTracksVetoActivity[0],Weight);
   *                //2D
   *                MuIsoTrackReductionHTNJetsFail_->Fill(HT,NJets,Weight);
   *                MuIsoTrackReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
   *                MuIsoTrackReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
   *                MuIsoTrackReductionPTActivityFail_->Fill(IsolatedMuonTracksVetoPt[0],IsolatedMuonTracksVetoActivity[0],Weight);
   *                
}
//      if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (GenMuNum)>0 && IsolatedMuonTracksVetoNum>0)
// if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (genLeptons)>0 && IsolatedMuonTracksVetoNum>0 && IsolatedPionTracksVetoNum==0 && IsolatedElectronTracksVetoNum==0 )

//          if(Expectation==1 && IsolatedMuonTracksVetoNum>0 && IsolatedPionTracksVetoNum==0 && IsolatedElectronTracksVetoNum==0)
{
for(unsigned int i=0; i<IsolatedMuonTracksVetoNum;i++)
{
if(muIsoTrackMatchedToGenMu[i]==1)
{
ExpectationReductionMuIsoTrackBTagEff->Fill(BTags,Weight);
ExpectationReductionMuIsoTrackNJetsEff->Fill(NJets,Weight);
ExpectationReductionMuIsoTrackHTEff->Fill(HT,Weight);
ExpectationReductionMuIsoTrackMHTEff->Fill(MHT,Weight);
ExpectationReductionMuIsoTrackPTEff->Fill(IsolatedMuonTracksVetoPt[0],Weight);
ExpectationReductionMuIsoTrackActivityEff->Fill(IsolatedMuonTracksVetoActivity[0],Weight);

//2D
MuIsoTrackReductionHTNJets_->Fill(HT,NJets,Weight);
MuIsoTrackReductionMHTNJets_->Fill(MHT,NJets,Weight);
MuIsoTrackReductionBTagNJets_->Fill(BTags,NJets,Weight);
MuIsoTrackReductionPTActivity_->Fill(IsolatedMuonTracksVetoPt[0],IsolatedMuonTracksVetoActivity[0],Weight);
break;
}
}

}


// elec iso tracks
if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (genLeptons)>0 && IsolatedMuonTracksVetoNum==0 && IsolatedPionTracksVetoNum==0 && IsolatedElectronTracksVetoNum==0 )
  //    if(Expectation==1 && IsolatedElectronTracksVetoNum==0 && IsolatedPionTracksVetoNum==0 && IsolatedMuonTracksVetoNum==0)
{
ExpectationReductionElecIsoTrackBTagEffFail->Fill(BTags,Weight);
ExpectationReductionElecIsoTrackNJetsEffFail->Fill(NJets,Weight);
ExpectationReductionElecIsoTrackHTEffFail->Fill(HT,Weight);
ExpectationReductionElecIsoTrackMHTEffFail->Fill(MHT,Weight);
ExpectationReductionElecIsoTrackPTEffFail->Fill(IsolatedElectronTracksVetoPt[0],Weight);
ExpectationReductionElecIsoTrackActivityEffFail->Fill(IsolatedElectronTracksVetoActivity[0],Weight);
//2D
ElecIsoTrackReductionHTNJetsFail_->Fill(HT,NJets,Weight);
ElecIsoTrackReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
ElecIsoTrackReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
ElecIsoTrackReductionPTActivityFail_->Fill(IsolatedElectronTracksVetoPt[0],IsolatedElectronTracksVetoActivity[0],Weight);

}
if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (genLeptons)>0 && IsolatedMuonTracksVetoNum==0 && IsolatedPionTracksVetoNum==0 && IsolatedElectronTracksVetoNum>0 )
  
  //      if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (GenElecNum)>0 && IsolatedElectronTracksVetoNum>0)
  //         if(Expectation==1 && IsolatedElectronTracksVetoNum>0 && IsolatedPionTracksVetoNum==0 && IsolatedMuonTracksVetoNum==0)
{
for(unsigned int i=0; i<IsolatedElectronTracksVetoNum;i++)
{
if(elecIsoTrackMatchedToGenElec[i]==1)
{
ExpectationReductionElecIsoTrackBTagEff->Fill(BTags,Weight);
ExpectationReductionElecIsoTrackNJetsEff->Fill(NJets,Weight);
ExpectationReductionElecIsoTrackHTEff->Fill(HT,Weight);
ExpectationReductionElecIsoTrackMHTEff->Fill(MHT,Weight);
ExpectationReductionElecIsoTrackPTEff->Fill(IsolatedElectronTracksVetoPt[0],Weight);
ExpectationReductionElecIsoTrackActivityEff->Fill(IsolatedElectronTracksVetoActivity[0],Weight);

//2D
ElecIsoTrackReductionHTNJets_->Fill(HT,NJets,Weight);
ElecIsoTrackReductionMHTNJets_->Fill(MHT,NJets,Weight);
ElecIsoTrackReductionBTagNJets_->Fill(BTags,NJets,Weight);
ElecIsoTrackReductionPTActivity_->Fill(IsolatedElectronTracksVetoPt[0],IsolatedElectronTracksVetoActivity[0],Weight);
break;
}
}

}
// pion iso tracks
if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (genLeptons)>0 && IsolatedMuonTracksVetoNum==0 && IsolatedPionTracksVetoNum==0 && IsolatedElectronTracksVetoNum==0 )//         if(Expectation==1 && IsolatedPionTracksVetoNum==0 && IsolatedElectronTracksVetoNum==0 && IsolatedMuonTracksVetoNum==0)
{
ExpectationReductionPionIsoTrackBTagEffFail->Fill(BTags,Weight);
ExpectationReductionPionIsoTrackNJetsEffFail->Fill(NJets,Weight);
ExpectationReductionPionIsoTrackHTEffFail->Fill(HT,Weight);
ExpectationReductionPionIsoTrackMHTEffFail->Fill(MHT,Weight);
ExpectationReductionPionIsoTrackPTEffFail->Fill(IsolatedPionTracksVetoPt[0],Weight);
ExpectationReductionPionIsoTrackActivityEffFail->Fill(IsolatedPionTracksVetoActivity[0],Weight);
//2D
PionIsoTrackReductionHTNJetsFail_->Fill(HT,NJets,Weight);
PionIsoTrackReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
PionIsoTrackReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
PionIsoTrackReductionPTActivityFail_->Fill(IsolatedPionTracksVetoPt[0],IsolatedPionTracksVetoActivity[0],Weight);

}
if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (genLeptons)>0 && IsolatedPionTracksVetoNum>0 )
  
  //      if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && (GenElecNum + GenMuNum)>0 && IsolatedPionTracksVetoNum>0)
  //if(Expectation==1 && IsolatedPionTracksVetoNum>0 )
{
//              for(unsigned int i=0; i<IsolatedPionTracksVetoNum;i++)
//              {
//                      if(pionIsoTrackMatchedToGenMu[i]==1 || pionIsoTrackMatchedToGenElec[i]==1)
//                      {
ExpectationReductionPionIsoTrackBTagEff->Fill(BTags,Weight);
ExpectationReductionPionIsoTrackNJetsEff->Fill(NJets,Weight);
ExpectationReductionPionIsoTrackHTEff->Fill(HT,Weight);
ExpectationReductionPionIsoTrackMHTEff->Fill(MHT,Weight);
ExpectationReductionPionIsoTrackPTEff->Fill(IsolatedPionTracksVetoPt[0],Weight);
ExpectationReductionPionIsoTrackActivityEff->Fill(IsolatedPionTracksVetoActivity[0],Weight);

//2D
PionIsoTrackReductionHTNJets_->Fill(HT,NJets,Weight);
PionIsoTrackReductionMHTNJets_->Fill(MHT,NJets,Weight);
PionIsoTrackReductionBTagNJets_->Fill(BTags,NJets,Weight);
PionIsoTrackReductionPTActivity_->Fill(IsolatedPionTracksVetoPt[0],IsolatedPionTracksVetoActivity[0],Weight);
//                      }
//              }

}
*/
  
  
  
  
  // ************************************************************************************************************* 22 June 2015 end****************************************************
  
  
  ///////// ISO //////////////////////
  
  // gen mu tracks
  if(Expectation==1 && muIsoTrackIso==2)
  {
    ExpectationReductionMuIsoTrackGenMuBTagEff->Fill(BTags,Weight);
    ExpectationReductionMuIsoTrackGenMuNJetsEff->Fill(NJets,Weight);
    ExpectationReductionMuIsoTrackGenMuHTEff->Fill(HT,Weight);
    ExpectationReductionMuIsoTrackGenMuMHTEff->Fill(MHT,Weight);
    ExpectationReductionMuIsoTrackGenMuPTEff->Fill(GenMuPt[0],Weight);
    ExpectationReductionMuIsoTrackGenMuActivityEff->Fill(GenMuonActivity[0],Weight);
    
    //2D
    MuIsoTrackGenMuReductionHTNJets_->Fill(HT,NJets,Weight);
    MuIsoTrackGenMuReductionMHTNJets_->Fill(MHT,NJets,Weight);
    MuIsoTrackGenMuReductionBTagNJets_->Fill(BTags,NJets,Weight);
    MuIsoTrackGenMuReductionPTActivity_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    
    
    
  }
  if(Expectation==1 && pionIsoTrackIso==2 && GenMuNum==1)
  {
    ExpectationReductionPionIsoTrackGenMuBTagEff->Fill(BTags,Weight);
    ExpectationReductionPionIsoTrackGenMuNJetsEff->Fill(NJets,Weight);
    ExpectationReductionPionIsoTrackGenMuHTEff->Fill(HT,Weight);
    ExpectationReductionPionIsoTrackGenMuMHTEff->Fill(MHT,Weight);
    ExpectationReductionPionIsoTrackGenMuPTEff->Fill(GenMuPt[0],Weight);
    ExpectationReductionPionIsoTrackGenMuActivityEff->Fill(GenMuonActivity[0],Weight);
    
    //2D
    PionIsoTrackGenMuReductionHTNJets_->Fill(HT,NJets,Weight);
    PionIsoTrackGenMuReductionMHTNJets_->Fill(MHT,NJets,Weight);
    PionIsoTrackGenMuReductionBTagNJets_->Fill(BTags,NJets,Weight);
    PionIsoTrackGenMuReductionPTActivity_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
  }
  if(Expectation==1 && muIsoTrackIso==0)
  {
    ExpectationReductionMuIsoTrackGenMuBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionMuIsoTrackGenMuNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionMuIsoTrackGenMuHTEffFail->Fill(HT,Weight);
    ExpectationReductionMuIsoTrackGenMuMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionMuIsoTrackGenMuPTEffFail->Fill(GenMuPt[0],Weight);
    ExpectationReductionMuIsoTrackGenMuActivityEffFail->Fill(GenMuonActivity[0],Weight);
    //2D
    MuIsoTrackGenMuReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    MuIsoTrackGenMuReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    MuIsoTrackGenMuReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    MuIsoTrackGenMuReductionPTActivityFail_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    
  }
  if(Expectation==1 && pionIsoTrackReco==2 && pionIsoTrackIso==0 && GenMuNum==1)
  {
    ExpectationReductionPionIsoTrackGenMuBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionPionIsoTrackGenMuNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionPionIsoTrackGenMuHTEffFail->Fill(HT,Weight);
    ExpectationReductionPionIsoTrackGenMuMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionPionIsoTrackGenMuPTEffFail->Fill(GenMuPt[0],Weight);
    ExpectationReductionPionIsoTrackGenMuActivityEffFail->Fill(GenMuonActivity[0],Weight);
    
    //2D
    PionIsoTrackGenMuReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    PionIsoTrackGenMuReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    PionIsoTrackGenMuReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    PionIsoTrackGenMuReductionPTActivityFail_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
  }
  
  // gen elec tracks
  
  if(Expectation==1 && elecIsoTrackIso==2)
  {
    ExpectationReductionElecIsoTrackGenElecBTagEff->Fill(BTags,Weight);
    ExpectationReductionElecIsoTrackGenElecNJetsEff->Fill(NJets,Weight);
    ExpectationReductionElecIsoTrackGenElecHTEff->Fill(HT,Weight);
    ExpectationReductionElecIsoTrackGenElecMHTEff->Fill(MHT,Weight);
    ExpectationReductionElecIsoTrackGenElecPTEff->Fill(GenElecPt[0],Weight);
    ExpectationReductionElecIsoTrackGenElecActivityEff->Fill(GenElecActivity[0],Weight);
    
    //2D
    ElecIsoTrackGenElecReductionHTNJets_->Fill(HT,NJets,Weight);
    ElecIsoTrackGenElecReductionMHTNJets_->Fill(MHT,NJets,Weight);
    ElecIsoTrackGenElecReductionBTagNJets_->Fill(BTags,NJets,Weight);
    ElecIsoTrackGenElecReductionPTActivity_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
    
    
    
  }
  if(Expectation==1 && pionIsoTrackIso==2 && GenElecNum==1)
  {
    ExpectationReductionPionIsoTrackGenElecBTagEff->Fill(BTags,Weight);
    ExpectationReductionPionIsoTrackGenElecNJetsEff->Fill(NJets,Weight);
    ExpectationReductionPionIsoTrackGenElecHTEff->Fill(HT,Weight);
    ExpectationReductionPionIsoTrackGenElecMHTEff->Fill(MHT,Weight);
    ExpectationReductionPionIsoTrackGenElecPTEff->Fill(GenElecPt[0],Weight);
    ExpectationReductionPionIsoTrackGenElecActivityEff->Fill(GenElecActivity[0],Weight);
    
    //2D
    PionIsoTrackGenElecReductionHTNJets_->Fill(HT,NJets,Weight);
    PionIsoTrackGenElecReductionMHTNJets_->Fill(MHT,NJets,Weight);
    PionIsoTrackGenElecReductionBTagNJets_->Fill(BTags,NJets,Weight);
    PionIsoTrackGenElecReductionPTActivity_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
  }
  if(Expectation==1 && elecIsoTrackIso==0)
  {
    ExpectationReductionElecIsoTrackGenElecBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionElecIsoTrackGenElecNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionElecIsoTrackGenElecHTEffFail->Fill(HT,Weight);
    ExpectationReductionElecIsoTrackGenElecMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionElecIsoTrackGenElecPTEffFail->Fill(GenElecPt[0],Weight);
    ExpectationReductionElecIsoTrackGenElecActivityEffFail->Fill(GenElecActivity[0],Weight);
    //2D
    ElecIsoTrackGenElecReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    ElecIsoTrackGenElecReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    ElecIsoTrackGenElecReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    ElecIsoTrackGenElecReductionPTActivityFail_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
    
  }
  
  if(Expectation==1 && pionIsoTrackIso==0 && pionIsoTrackReco==2 && GenElecNum==1)
  {
    ExpectationReductionPionIsoTrackGenElecBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionPionIsoTrackGenElecNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionPionIsoTrackGenElecHTEffFail->Fill(HT,Weight);
    ExpectationReductionPionIsoTrackGenElecMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionPionIsoTrackGenElecPTEffFail->Fill(GenElecPt[0],Weight);
    ExpectationReductionPionIsoTrackGenElecActivityEffFail->Fill(GenElecActivity[0],Weight);
    
    //2D
    PionIsoTrackGenElecReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    PionIsoTrackGenElecReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    PionIsoTrackGenElecReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    PionIsoTrackGenElecReductionPTActivityFail_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
  }
  
  
  // had tau tracks
  
  if(Expectation==1 && pionIsoTrackIso==2 && GenElecNum==0 && GenMuNum==0 && GenTauNum==1)
  {
    ExpectationReductionPionIsoTrackGenHadTauBTagEff->Fill(BTags,Weight);
    ExpectationReductionPionIsoTrackGenHadTauNJetsEff->Fill(NJets,Weight);
    ExpectationReductionPionIsoTrackGenHadTauHTEff->Fill(HT,Weight);
    ExpectationReductionPionIsoTrackGenHadTauMHTEff->Fill(MHT,Weight);
    ExpectationReductionPionIsoTrackGenHadTauPTEff->Fill(GenTauPt[0],Weight);
    ExpectationReductionPionIsoTrackGenHadTauActivityEff->Fill(GenTauActivity[0],Weight);
    
    //2D
    PionIsoTrackGenHadTauReductionHTNJets_->Fill(HT,NJets,Weight);
    PionIsoTrackGenHadTauReductionMHTNJets_->Fill(MHT,NJets,Weight);
    PionIsoTrackGenHadTauReductionBTagNJets_->Fill(BTags,NJets,Weight);
    PionIsoTrackGenHadTauReductionPTActivity_->Fill(GenTauPt[0],GenTauActivity[0],Weight);
  }
  
  if(Expectation==1 && pionIsoTrackIso==0 && GenElecNum==0 && GenMuNum==0 && GenTauNum==1)
  {
    ExpectationReductionPionIsoTrackGenHadTauBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionPionIsoTrackGenHadTauNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionPionIsoTrackGenHadTauHTEffFail->Fill(HT,Weight);
    ExpectationReductionPionIsoTrackGenHadTauMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionPionIsoTrackGenHadTauPTEffFail->Fill(GenTauPt[0],Weight);
    ExpectationReductionPionIsoTrackGenHadTauActivityEffFail->Fill(GenTauActivity[0],Weight);
    
    //2D
    PionIsoTrackGenHadTauReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    PionIsoTrackGenHadTauReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    PionIsoTrackGenHadTauReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    PionIsoTrackGenHadTauReductionPTActivityFail_->Fill(GenTauPt[0],GenTauActivity[0],Weight);
  }
  
  
  //////////////////// RECO //////////////////////
  // gen mu tracks
  if(Expectation==1 && muIsoTrackReco==2)
  {
    ExpectationReductionMuRecoTrackGenMuBTagEff->Fill(BTags,Weight);
    ExpectationReductionMuRecoTrackGenMuNJetsEff->Fill(NJets,Weight);
    ExpectationReductionMuRecoTrackGenMuHTEff->Fill(HT,Weight);
    ExpectationReductionMuRecoTrackGenMuMHTEff->Fill(MHT,Weight);
    ExpectationReductionMuRecoTrackGenMuPTEff->Fill(GenMuPt[0],Weight);
    ExpectationReductionMuRecoTrackGenMuActivityEff->Fill(GenMuonActivity[0],Weight);
    
    //2D
    MuRecoTrackGenMuReductionHTNJets_->Fill(HT,NJets,Weight);
    MuRecoTrackGenMuReductionMHTNJets_->Fill(MHT,NJets,Weight);
    MuRecoTrackGenMuReductionBTagNJets_->Fill(BTags,NJets,Weight);
    MuRecoTrackGenMuReductionPTActivity_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    
    
    
  }
  if(Expectation==1 && pionIsoTrackReco==2 && GenMuNum==1)
  {
    ExpectationReductionPionRecoTrackGenMuBTagEff->Fill(BTags,Weight);
    ExpectationReductionPionRecoTrackGenMuNJetsEff->Fill(NJets,Weight);
    ExpectationReductionPionRecoTrackGenMuHTEff->Fill(HT,Weight);
    ExpectationReductionPionRecoTrackGenMuMHTEff->Fill(MHT,Weight);
    ExpectationReductionPionRecoTrackGenMuPTEff->Fill(GenMuPt[0],Weight);
    ExpectationReductionPionRecoTrackGenMuActivityEff->Fill(GenMuonActivity[0],Weight);
    
    //2D
    PionRecoTrackGenMuReductionHTNJets_->Fill(HT,NJets,Weight);
    PionRecoTrackGenMuReductionMHTNJets_->Fill(MHT,NJets,Weight);
    PionRecoTrackGenMuReductionBTagNJets_->Fill(BTags,NJets,Weight);
    PionRecoTrackGenMuReductionPTActivity_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
  }
  if(Expectation==1 && muIsoTrackReco!=2)
  {
    ExpectationReductionMuRecoTrackGenMuBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionMuRecoTrackGenMuNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionMuRecoTrackGenMuHTEffFail->Fill(HT,Weight);
    ExpectationReductionMuRecoTrackGenMuMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionMuRecoTrackGenMuPTEffFail->Fill(GenMuPt[0],Weight);
    ExpectationReductionMuRecoTrackGenMuActivityEffFail->Fill(GenMuonActivity[0],Weight);
    //2D
    MuRecoTrackGenMuReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    MuRecoTrackGenMuReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    MuRecoTrackGenMuReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    MuRecoTrackGenMuReductionPTActivityFail_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
    
  }
  
  if(Expectation==1 && pionIsoTrackReco!=2 && GenMuNum==1)
  {
    ExpectationReductionPionRecoTrackGenMuBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionPionRecoTrackGenMuNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionPionRecoTrackGenMuHTEffFail->Fill(HT,Weight);
    ExpectationReductionPionRecoTrackGenMuMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionPionRecoTrackGenMuPTEffFail->Fill(GenMuPt[0],Weight);
    ExpectationReductionPionRecoTrackGenMuActivityEffFail->Fill(GenMuonActivity[0],Weight);
    
    //2D
    PionRecoTrackGenMuReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    PionRecoTrackGenMuReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    PionRecoTrackGenMuReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    PionRecoTrackGenMuReductionPTActivityFail_->Fill(GenMuPt[0],GenMuonActivity[0],Weight);
  }
  
  // gen elec tracks
  
  if(Expectation==1 && elecIsoTrackReco==2)
  {
    ExpectationReductionElecRecoTrackGenElecBTagEff->Fill(BTags,Weight);
    ExpectationReductionElecRecoTrackGenElecNJetsEff->Fill(NJets,Weight);
    ExpectationReductionElecRecoTrackGenElecHTEff->Fill(HT,Weight);
    ExpectationReductionElecRecoTrackGenElecMHTEff->Fill(MHT,Weight);
    ExpectationReductionElecRecoTrackGenElecPTEff->Fill(GenElecPt[0],Weight);
    ExpectationReductionElecRecoTrackGenElecActivityEff->Fill(GenElecActivity[0],Weight);
    
    //2D
    ElecRecoTrackGenElecReductionHTNJets_->Fill(HT,NJets,Weight);
    ElecRecoTrackGenElecReductionMHTNJets_->Fill(MHT,NJets,Weight);
    ElecRecoTrackGenElecReductionBTagNJets_->Fill(BTags,NJets,Weight);
    ElecRecoTrackGenElecReductionPTActivity_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
    
    
    
  }
  if(Expectation==1 && pionIsoTrackReco==2 && GenElecNum==1)
  {
    ExpectationReductionPionRecoTrackGenElecBTagEff->Fill(BTags,Weight);
    ExpectationReductionPionRecoTrackGenElecNJetsEff->Fill(NJets,Weight);
    ExpectationReductionPionRecoTrackGenElecHTEff->Fill(HT,Weight);
    ExpectationReductionPionRecoTrackGenElecMHTEff->Fill(MHT,Weight);
    ExpectationReductionPionRecoTrackGenElecPTEff->Fill(GenElecPt[0],Weight);
    ExpectationReductionPionRecoTrackGenElecActivityEff->Fill(GenElecActivity[0],Weight);
    
    //2D
    PionRecoTrackGenElecReductionHTNJets_->Fill(HT,NJets,Weight);
    PionRecoTrackGenElecReductionMHTNJets_->Fill(MHT,NJets,Weight);
    PionRecoTrackGenElecReductionBTagNJets_->Fill(BTags,NJets,Weight);
    PionRecoTrackGenElecReductionPTActivity_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
  }
  if(Expectation==1 && elecIsoTrackReco!=2)
  {
    ExpectationReductionElecRecoTrackGenElecBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionElecRecoTrackGenElecNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionElecRecoTrackGenElecHTEffFail->Fill(HT,Weight);
    ExpectationReductionElecRecoTrackGenElecMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionElecRecoTrackGenElecPTEffFail->Fill(GenElecPt[0],Weight);
    ExpectationReductionElecRecoTrackGenElecActivityEffFail->Fill(GenElecActivity[0],Weight);
    //2D
    ElecRecoTrackGenElecReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    ElecRecoTrackGenElecReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    ElecRecoTrackGenElecReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    ElecRecoTrackGenElecReductionPTActivityFail_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
    
  }
  
  if(Expectation==1 && pionIsoTrackReco!=2 && GenElecNum==1)
  {
    ExpectationReductionPionRecoTrackGenElecBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionPionRecoTrackGenElecNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionPionRecoTrackGenElecHTEffFail->Fill(HT,Weight);
    ExpectationReductionPionRecoTrackGenElecMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionPionRecoTrackGenElecPTEffFail->Fill(GenElecPt[0],Weight);
    ExpectationReductionPionRecoTrackGenElecActivityEffFail->Fill(GenElecActivity[0],Weight);
    
    //2D
    PionRecoTrackGenElecReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    PionRecoTrackGenElecReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    PionRecoTrackGenElecReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    PionRecoTrackGenElecReductionPTActivityFail_->Fill(GenElecPt[0],GenElecActivity[0],Weight);
  }
  
  
  // had tau tracks
  
  if(Expectation==1 && pionIsoTrackReco==2 && GenElecNum==0 && GenMuNum==0 && GenTauNum==1)
  {
    ExpectationReductionPionRecoTrackGenHadTauBTagEff->Fill(BTags,Weight);
    ExpectationReductionPionRecoTrackGenHadTauNJetsEff->Fill(NJets,Weight);
    ExpectationReductionPionRecoTrackGenHadTauHTEff->Fill(HT,Weight);
    ExpectationReductionPionRecoTrackGenHadTauMHTEff->Fill(MHT,Weight);
    ExpectationReductionPionRecoTrackGenHadTauPTEff->Fill(GenTauPt[0],Weight);
    ExpectationReductionPionRecoTrackGenHadTauActivityEff->Fill(GenTauActivity[0],Weight);
    
    //2D
    PionRecoTrackGenHadTauReductionHTNJets_->Fill(HT,NJets,Weight);
    PionRecoTrackGenHadTauReductionMHTNJets_->Fill(MHT,NJets,Weight);
    PionRecoTrackGenHadTauReductionBTagNJets_->Fill(BTags,NJets,Weight);
    PionRecoTrackGenHadTauReductionPTActivity_->Fill(GenTauPt[0],GenTauActivity[0],Weight);
  }
  
  if(Expectation==1 && pionIsoTrackReco!=2 && GenElecNum==0 && GenMuNum==0 && GenTauNum==1)
  {
    ExpectationReductionPionRecoTrackGenHadTauBTagEffFail->Fill(BTags,Weight);
    ExpectationReductionPionRecoTrackGenHadTauNJetsEffFail->Fill(NJets,Weight);
    ExpectationReductionPionRecoTrackGenHadTauHTEffFail->Fill(HT,Weight);
    ExpectationReductionPionRecoTrackGenHadTauMHTEffFail->Fill(MHT,Weight);
    ExpectationReductionPionRecoTrackGenHadTauPTEffFail->Fill(GenTauPt[0],Weight);
    ExpectationReductionPionRecoTrackGenHadTauActivityEffFail->Fill(GenTauActivity[0],Weight);
    
    //2D
    PionRecoTrackGenHadTauReductionHTNJetsFail_->Fill(HT,NJets,Weight);
    PionRecoTrackGenHadTauReductionMHTNJetsFail_->Fill(MHT,NJets,Weight);
    PionRecoTrackGenHadTauReductionBTagNJetsFail_->Fill(BTags,NJets,Weight);
    PionRecoTrackGenHadTauReductionPTActivityFail_->Fill(GenTauPt[0],GenTauActivity[0],Weight);
  }
  // ************************************************************************************************************* 04 July 2015 ****************************************************
  if(GenTauNum==1)
  {
    if(GenTauLepDecay[0]==0)
    {
      // single prong decay
      if(GenTauCharged[0]==1 && GenTauNeutral[0]==0)
      {
        if(GenTauIsoTrackMatched[0]==2)
        {
          //                 std::cout<<"hitme\n";
          HadTauTrackSingleProngPT->Fill(GenTauPt[0],Weight);
          HadTauTrackSingleProngEta->Fill(GenTauEta[0],Weight);
          HadTauTrackSingleProngPhi->Fill(GenTauPhi[0],Weight);
          HadTauTrackSingleProngActivity->Fill(GenTauActivity[0],Weight);
          HadTauTrackSingleProngHT->Fill(HT,Weight);
          HadTauTrackSingleProngMHT->Fill(MHT,Weight);
          HadTauTrackSingleProngNJets->Fill(NJets,Weight);
          HadTauTrackSingleProngBTags->Fill(BTags,Weight);
        }
        else
        {
          HadTauTrackSingleProngPTFail->Fill(GenTauPt[0],Weight);
          HadTauTrackSingleProngEtaFail->Fill(GenTauEta[0],Weight);
          HadTauTrackSingleProngPhiFail->Fill(GenTauPhi[0],Weight);
          HadTauTrackSingleProngActivityFail->Fill(GenTauActivity[0],Weight);
          HadTauTrackSingleProngHTFail->Fill(HT,Weight);
          HadTauTrackSingleProngMHTFail->Fill(MHT,Weight);
          HadTauTrackSingleProngNJetsFail->Fill(NJets,Weight);
          HadTauTrackSingleProngBTagsFail->Fill(BTags,Weight);
        }
      }
      // single charged but additonal neutral decays
      if(GenTauCharged[0]==1 && GenTauNeutral[0]!=0)
      {
        if(GenTauIsoTrackMatched[0]==2)
        {
          HadTauTrackOneChargedAndNeutralsPT->Fill(GenTauPt[0],Weight);
          HadTauTrackOneChargedAndNeutralsEta->Fill(GenTauEta[0],Weight);
          HadTauTrackOneChargedAndNeutralsPhi->Fill(GenTauPhi[0],Weight);
          HadTauTrackOneChargedAndNeutralsActivity->Fill(GenTauActivity[0],Weight);
          HadTauTrackOneChargedAndNeutralsHT->Fill(HT,Weight);
          HadTauTrackOneChargedAndNeutralsMHT->Fill(MHT,Weight);
          HadTauTrackOneChargedAndNeutralsNJets->Fill(NJets,Weight);
          HadTauTrackOneChargedAndNeutralsBTags->Fill(BTags,Weight);
        }
        else
        {
          HadTauTrackOneChargedAndNeutralsPTFail->Fill(GenTauPt[0],Weight);
          HadTauTrackOneChargedAndNeutralsEtaFail->Fill(GenTauEta[0],Weight);
          HadTauTrackOneChargedAndNeutralsPhiFail->Fill(GenTauPhi[0],Weight);
          HadTauTrackOneChargedAndNeutralsActivityFail->Fill(GenTauActivity[0],Weight);
          HadTauTrackOneChargedAndNeutralsHTFail->Fill(HT,Weight);
          HadTauTrackOneChargedAndNeutralsMHTFail->Fill(MHT,Weight);
          HadTauTrackOneChargedAndNeutralsNJetsFail->Fill(NJets,Weight);
          HadTauTrackOneChargedAndNeutralsBTagsFail->Fill(BTags,Weight);
        }
      }
    }
  }
  // single muon decays muon iso track
  if(GenMuNum==1)
  {
    if(muIsoTrackMatchedToGenMu[0]==1 || pionIsoTrackMatchedToGenMu[0]==1)
    {
      MuonTrackPT->Fill(GenMuPt[0],Weight);
      MuonTrackEta->Fill(GenMuEta[0],Weight);
      MuonTrackPhi->Fill(GenMuPhi[0],Weight);
      MuonTrackActivity->Fill(GenMuonActivity[0],Weight);
      MuonTrackHT->Fill(HT,Weight);
      MuonTrackMHT->Fill(MHT,Weight);
      MuonTrackNJets->Fill(NJets,Weight);
      MuonTrackBTags->Fill(BTags,Weight);
    }
    else
    {
      MuonTrackPTFail->Fill(GenMuPt[0],Weight);
      MuonTrackEtaFail->Fill(GenMuEta[0],Weight);
      MuonTrackPhiFail->Fill(GenMuPhi[0],Weight);
      MuonTrackActivityFail->Fill(GenMuonActivity[0],Weight);
      MuonTrackHTFail->Fill(HT,Weight);
      MuonTrackMHTFail->Fill(MHT,Weight);
      MuonTrackNJetsFail->Fill(NJets,Weight);
      MuonTrackBTagsFail->Fill(BTags,Weight);
    }
  }
  
  
  if(GenElecNum==1)
  {
    if(elecIsoTrackMatchedToGenElec[0]==1 || pionIsoTrackMatchedToGenElec[0]==1)
    {
      ElectronTrackPT->Fill(GenElecPt[0],Weight);
      ElectronTrackEta->Fill(GenElecEta[0],Weight);
      ElectronTrackPhi->Fill(GenElecPhi[0],Weight);
      ElectronTrackActivity->Fill(GenElecActivity[0],Weight);
      ElectronTrackHT->Fill(HT,Weight);
      ElectronTrackMHT->Fill(MHT,Weight);
      ElectronTrackNJets->Fill(NJets,Weight);
      ElectronTrackBTags->Fill(BTags,Weight);
    }
    else
    {
      ElectronTrackPTFail->Fill(GenElecPt[0],Weight);
      ElectronTrackEtaFail->Fill(GenElecEta[0],Weight);
      ElectronTrackPhiFail->Fill(GenElecPhi[0],Weight);
      ElectronTrackActivityFail->Fill(GenElecActivity[0],Weight);
      ElectronTrackHTFail->Fill(HT,Weight);
      ElectronTrackMHTFail->Fill(MHT,Weight);
      ElectronTrackNJetsFail->Fill(NJets,Weight);
      ElectronTrackBTagsFail->Fill(BTags,Weight);
    }
  }
  // ************************************************************************************************************* 04 July 2015 end ****************************************************
  
  return kTRUE;
}
void EffMaker::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
  
}
void EffMaker::Terminate()
{
  TFile *outPutFile = new TFile("Efficiencies.root","RECREATE"); 
  outPutFile->cd();
  outPutFile->mkdir("Efficiencies");
  TDirectory *dEfficiencies = (TDirectory*)outPutFile->Get("Efficiencies");
  dEfficiencies->cd();
  gStyle->SetPaintTextFormat("5.2f");
  gStyle->SetStatW(0.1);
  gStyle->SetStatH(0.1);
  gStyle->SetStatY(202);
  gStyle->SetTitleYOffset(1.3);
  
  // MuMTWMHTNJetFail->Delete("all");
  // compute and save efficiencies
  // purity
  //muon
  //1D
  MuPurityBTag_ = ratioCalculator(MuPurityBTag_,MuPurityBTagFail_);   
  MuPurityBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; B_{Tags}");
  MuPurityBTag_->SetMarkerSize(2.0);
  MuPurityBTag_->UseCurrentStyle();
  MuPurityBTag_->Write();
  SaveEfficiency(MuPurityBTag_);
  
  MuPurityNJets_ = ratioCalculator(MuPurityNJets_,MuPurityNJetsFail_);   
  MuPurityNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; N_{Jets}");
  MuPurityNJets_->SetMarkerSize(2.0);
  MuPurityNJets_->UseCurrentStyle();
  MuPurityNJets_->Write();
  SaveEfficiency(MuPurityNJets_);
  
  MuPurityHT_ = ratioCalculator(MuPurityHT_,MuPurityHTFail_);   
  MuPurityHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; H_{T} [GeV]");
  MuPurityHT_->SetMarkerSize(2.0);
  MuPurityHT_->UseCurrentStyle();
  MuPurityHT_->Write();
  SaveEfficiency(MuPurityHT_);
  
  MuPurityMHT_ = ratioCalculator(MuPurityMHT_,MuPurityMHTFail_);   
  MuPurityMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; #slash{H}_{T} [GeV]");
  MuPurityMHT_->SetMarkerSize(2.0);
  MuPurityMHT_->UseCurrentStyle();
  MuPurityMHT_->Write();
  SaveEfficiency(MuPurityMHT_);
  //2D
  MuonPurityMHTNJet = ratioCalculator(MuonPurityMHTNJet,MuonPurityMHTNJetFail);   
  MuonPurityMHTNJet->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; #slash{H}_{T} [GeV]; N_{Jets}");
  MuonPurityMHTNJet->SetMarkerSize(2.0);
  MuonPurityMHTNJet->UseCurrentStyle();
  MuonPurityMHTNJet->Write();
  SaveEfficiency(MuonPurityMHTNJet);
  
  //elec
  //1D
  ElecPurityBTag_ = ratioCalculator(ElecPurityBTag_,ElecPurityBTagFail_);   
  ElecPurityBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; B_{Tags}");
  ElecPurityBTag_->SetMarkerSize(2.0);
  ElecPurityBTag_->UseCurrentStyle();
  ElecPurityBTag_->Write();
  SaveEfficiency(ElecPurityBTag_);
  
  ElecPurityNJets_ = ratioCalculator(ElecPurityNJets_,ElecPurityNJetsFail_);   
  ElecPurityNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; N_{Jets}");
  ElecPurityNJets_->SetMarkerSize(2.0);
  ElecPurityNJets_->UseCurrentStyle();
  ElecPurityNJets_->Write();
  SaveEfficiency(ElecPurityNJets_);
  
  ElecPurityHT_ = ratioCalculator(ElecPurityHT_,ElecPurityHTFail_);   
  ElecPurityHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; H_{T} [GeV]");
  ElecPurityHT_->SetMarkerSize(2.0);
  ElecPurityHT_->UseCurrentStyle();
  ElecPurityHT_->Write();
  SaveEfficiency(ElecPurityHT_);
  
  ElecPurityMHT_ = ratioCalculator(ElecPurityMHT_,ElecPurityMHTFail_);   
  ElecPurityMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; #slash{H}_{T} [GeV]");
  ElecPurityMHT_->SetMarkerSize(2.0);
  ElecPurityMHT_->UseCurrentStyle();
  ElecPurityMHT_->Write();
  SaveEfficiency(ElecPurityMHT_);
  //2D
  ElecPurityMHTNJet = ratioCalculator(ElecPurityMHTNJet,ElecPurityMHTNJetFail);   
  ElecPurityMHTNJet->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; #slash{H}_{T} [GeV]; N_{Jets}");
  ElecPurityMHTNJet->SetMarkerSize(2.0);
  ElecPurityMHTNJet->UseCurrentStyle();
  ElecPurityMHTNJet->Write();
  SaveEfficiency(ElecPurityMHTNJet);
  
  MuPurityBTag_ = ratioCalculator(MuPurityBTag_,MuPurityBTagFail_);   
  MuPurityBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; B_{Tags}");
  MuPurityBTag_->SetMarkerSize(2.0);
  MuPurityBTag_->UseCurrentStyle();
  MuPurityBTag_->Write();
  SaveEfficiency(MuPurityBTag_);
  
  MuPurityCheckNJets_ = ratioCalculator(MuPurityCheckNJets_,MuPurityCheckNJetsFail_);   
  MuPurityCheckNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; N_{Jets}");
  MuPurityCheckNJets_->SetMarkerSize(2.0);
  MuPurityCheckNJets_->UseCurrentStyle();
  MuPurityCheckNJets_->Write();
  SaveEfficiency(MuPurityCheckNJets_);
  
  MuPurityCheckHT_ = ratioCalculator(MuPurityCheckHT_,MuPurityCheckHTFail_);   
  MuPurityCheckHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; H_{T} [GeV]");
  MuPurityCheckHT_->SetMarkerSize(2.0);
  MuPurityCheckHT_->UseCurrentStyle();
  MuPurityCheckHT_->Write();
  SaveEfficiency(MuPurityCheckHT_);
  
  MuPurityCheckMHT_ = ratioCalculator(MuPurityCheckMHT_,MuPurityCheckMHTFail_);   
  MuPurityCheckMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; #slash{H}_{T} [GeV]");
  MuPurityCheckMHT_->SetMarkerSize(2.0);
  MuPurityCheckMHT_->UseCurrentStyle();
  MuPurityCheckMHT_->Write();
  SaveEfficiency(MuPurityCheckMHT_);
  //2D
  MuonPurityCheckMHTNJet = ratioCalculator(MuonPurityCheckMHTNJet,MuonPurityCheckMHTNJetFail);   
  MuonPurityCheckMHTNJet->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; #slash{H}_{T} [GeV]; N_{Jets}");
  MuonPurityCheckMHTNJet->SetMarkerSize(2.0);
  MuonPurityCheckMHTNJet->UseCurrentStyle();
  MuonPurityCheckMHTNJet->Write();
  SaveEfficiency(MuonPurityCheckMHTNJet);
  
  //elec
  //1D
  ElecPurityCheckBTag_ = ratioCalculator(ElecPurityCheckBTag_,ElecPurityCheckBTagFail_);   
  ElecPurityCheckBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; B_{Tags}");
  ElecPurityCheckBTag_->SetMarkerSize(2.0);
  ElecPurityCheckBTag_->UseCurrentStyle();
  ElecPurityCheckBTag_->Write();
  SaveEfficiency(ElecPurityCheckBTag_);
  
  ElecPurityCheckNJets_ = ratioCalculator(ElecPurityCheckNJets_,ElecPurityCheckNJetsFail_);   
  ElecPurityCheckNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; N_{Jets}");
  ElecPurityCheckNJets_->SetMarkerSize(2.0);
  ElecPurityCheckNJets_->UseCurrentStyle();
  ElecPurityCheckNJets_->Write();
  SaveEfficiency(ElecPurityCheckNJets_);
  
  ElecPurityCheckHT_ = ratioCalculator(ElecPurityCheckHT_,ElecPurityCheckHTFail_);   
  ElecPurityCheckHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; H_{T} [GeV]");
  ElecPurityCheckHT_->SetMarkerSize(2.0);
  ElecPurityCheckHT_->UseCurrentStyle();
  ElecPurityCheckHT_->Write();
  SaveEfficiency(ElecPurityCheckHT_);
  
  ElecPurityCheckMHT_ = ratioCalculator(ElecPurityCheckMHT_,ElecPurityCheckMHTFail_);   
  ElecPurityCheckMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; #slash{H}_{T} [GeV]");
  ElecPurityCheckMHT_->SetMarkerSize(2.0);
  ElecPurityCheckMHT_->UseCurrentStyle();
  ElecPurityCheckMHT_->Write();
  SaveEfficiency(ElecPurityCheckMHT_);
  //2D
  ElecPurityCheckMHTNJet = ratioCalculator(ElecPurityCheckMHTNJet,ElecPurityCheckMHTNJetFail);   
  ElecPurityCheckMHTNJet->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; #slash{H}_{T} [GeV]; N_{Jets}");
  ElecPurityCheckMHTNJet->SetMarkerSize(2.0);
  ElecPurityCheckMHTNJet->UseCurrentStyle();
  ElecPurityCheckMHTNJet->Write();
  SaveEfficiency(ElecPurityCheckMHTNJet);
  
  
  
  // acc
  //muon
  //1D
  MuAccBTag_ = ratioCalculator(MuAccBTag_,MuAccBTagFail_);   
  MuAccBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; B_{Tags}");
  MuAccBTag_->SetMarkerSize(2.0);
  MuAccBTag_->UseCurrentStyle();
  MuAccBTag_->Write();
  SaveEfficiency(MuAccBTag_);
  
  MuAccNJets_ = ratioCalculator(MuAccNJets_,MuAccNJetsFail_);   
  MuAccNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; N_{Jets}");
  MuAccNJets_->SetMarkerSize(2.0);
  MuAccNJets_->UseCurrentStyle();
  MuAccNJets_->Write();
  SaveEfficiency(MuAccNJets_);
  
  MuAccHT_ = ratioCalculator(MuAccHT_,MuAccHTFail_);   
  MuAccHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; H_{T} [GeV]");
  MuAccHT_->SetMarkerSize(2.0);
  MuAccHT_->UseCurrentStyle();
  MuAccHT_->Write();
  SaveEfficiency(MuAccHT_);
  
  MuAccMHT_ = ratioCalculator(MuAccMHT_,MuAccMHTFail_);   
  MuAccMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; #slash{H}_{T} [GeV]");
  MuAccMHT_->SetMarkerSize(2.0);
  MuAccMHT_->UseCurrentStyle();
  MuAccMHT_->Write();
  SaveEfficiency(MuAccMHT_);
  
  // 2D 
  MuAccHTNJets_ = ratioCalculator(MuAccHTNJets_,MuAccHTNJetsFail_);   
  MuAccHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; H_{T} [GeV]; N_{Jets}");
  MuAccHTNJets_->SetMarkerSize(2.0);
  MuAccHTNJets_->UseCurrentStyle();
  MuAccHTNJets_->Write();
  SaveEfficiency(MuAccHTNJets_);
  
  MuAccMHTNJets_ = ratioCalculator(MuAccMHTNJets_,MuAccMHTNJetsFail_);   
  MuAccMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; #slash{H}_{T} [GeV]; N_{Jets}");
  MuAccMHTNJets_->SetMarkerSize(2.0);
  MuAccMHTNJets_->UseCurrentStyle();
  MuAccMHTNJets_->Write();
  SaveEfficiency(MuAccMHTNJets_);
  
  MuAccBTagNJets_ = ratioCalculator(MuAccBTagNJets_,MuAccBTagNJetsFail_);   
  MuAccBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; B_{Tags}; N_{Jets}");
  MuAccBTagNJets_->SetMarkerSize(2.0);
  MuAccBTagNJets_->UseCurrentStyle();
  MuAccBTagNJets_->Write();
  SaveEfficiency(MuAccBTagNJets_);
  
  MuAccMHTNJetsB0_ = ratioCalculator(MuAccMHTNJetsB0_,MuAccMHTNJetsB0Fail_);   
  MuAccMHTNJetsB0_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc B_{Tags}=0; #slash{H}_{T} [GeV]; N_{Jets}");
  MuAccMHTNJetsB0_->SetMarkerSize(2.0);
  MuAccMHTNJetsB0_->UseCurrentStyle();
  MuAccMHTNJetsB0_->Write();
  SaveEfficiency(MuAccMHTNJetsB0_);
  
  MuAccMHTNJetsB1_Inf_ = ratioCalculator(MuAccMHTNJetsB1_Inf_,MuAccMHTNJetsB1_InfFail_);   
  MuAccMHTNJetsB1_Inf_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc B_{Tags}#geq1; #slash{H}_{T} [GeV]; N_{Jets}");
  MuAccMHTNJetsB1_Inf_->SetMarkerSize(2.0);
  MuAccMHTNJetsB1_Inf_->UseCurrentStyle();
  MuAccMHTNJetsB1_Inf_->Write();
  SaveEfficiency(MuAccMHTNJetsB1_Inf_);
  
  MuAccHTMHT_NJets46_ = ratioCalculator(MuAccHTMHT_NJets46_,MuAccHTMHT_NJets46Fail_);   
  MuAccHTMHT_NJets46_->SetTitle("Simulation, L=4 fb-1, #sqrt{s}=13 TeV #mu acc 4#geqN_{Jets}#geq6; H_{T} [GeV]; #slash{H}_{T} [GeV]");
  MuAccHTMHT_NJets46_->SetMarkerSize(2.0);
  MuAccHTMHT_NJets46_->UseCurrentStyle();
  MuAccHTMHT_NJets46_->Write();
  SaveEfficiency(MuAccHTMHT_NJets46_);
  
  MuAccHTMHT_NJets7Inf_ = ratioCalculator(MuAccHTMHT_NJets7Inf_,MuAccHTMHT_NJets7InfFail_);   
  MuAccHTMHT_NJets7Inf_->SetTitle("Simulation, L=4 fb-1, #sqrt{s}=13 TeV #mu acc 7#geqN_{Jets}; H_{T} [GeV]; #slash{H}_{T} [GeV]");
  MuAccHTMHT_NJets7Inf_->SetMarkerSize(2.0);
  MuAccHTMHT_NJets7Inf_->UseCurrentStyle();
  MuAccHTMHT_NJets7Inf_->Write();
  SaveEfficiency(MuAccHTMHT_NJets7Inf_);
  
  //elec
  //1D
  ElecAccBTag_ = ratioCalculator(ElecAccBTag_,ElecAccBTagFail_);   
  ElecAccBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; B_{Tags}");
  ElecAccBTag_->SetMarkerSize(2.0);
  ElecAccBTag_->UseCurrentStyle();
  ElecAccBTag_->Write();
  SaveEfficiency(ElecAccBTag_);
  
  ElecAccNJets_ = ratioCalculator(ElecAccNJets_,ElecAccNJetsFail_);   
  ElecAccNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; N_{Jets}");
  ElecAccNJets_->SetMarkerSize(2.0);
  ElecAccNJets_->UseCurrentStyle();
  ElecAccNJets_->Write();
  SaveEfficiency(ElecAccNJets_);
  
  ElecAccHT_ = ratioCalculator(ElecAccHT_,ElecAccHTFail_);   
  ElecAccHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; H_{T} [GeV]");
  ElecAccHT_->SetMarkerSize(2.0);
  ElecAccHT_->UseCurrentStyle();
  ElecAccHT_->Write();
  SaveEfficiency(ElecAccHT_);
  
  ElecAccMHT_ = ratioCalculator(ElecAccMHT_,ElecAccMHTFail_);   
  ElecAccMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; #slash{H}_{T} [GeV]");
  ElecAccMHT_->SetMarkerSize(2.0);
  ElecAccMHT_->UseCurrentStyle();
  ElecAccMHT_->Write();
  SaveEfficiency(ElecAccMHT_);
  
  // 2D 
  ElecAccHTNJets_ = ratioCalculator(ElecAccHTNJets_,ElecAccHTNJetsFail_);   
  ElecAccHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; H_{T} [GeV]; N_{Jets}");
  ElecAccHTNJets_->SetMarkerSize(2.0);
  ElecAccHTNJets_->UseCurrentStyle();
  ElecAccHTNJets_->Write();
  SaveEfficiency(ElecAccHTNJets_);
  
  ElecAccMHTNJets_ = ratioCalculator(ElecAccMHTNJets_,ElecAccMHTNJetsFail_);   
  ElecAccMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; #slash{H}_{T} [GeV]; N_{Jets}");
  ElecAccMHTNJets_->SetMarkerSize(2.0);
  ElecAccMHTNJets_->UseCurrentStyle();
  ElecAccMHTNJets_->Write();
  SaveEfficiency(ElecAccMHTNJets_);
  
  ElecAccBTagNJets_ = ratioCalculator(ElecAccBTagNJets_,ElecAccBTagNJetsFail_);   
  ElecAccBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; B_{Tags}; N_{Jets}");
  ElecAccBTagNJets_->SetMarkerSize(2.0);
  ElecAccBTagNJets_->UseCurrentStyle();
  ElecAccBTagNJets_->Write();
  SaveEfficiency(ElecAccBTagNJets_);
  
  ElecAccMHTNJetsB0_ = ratioCalculator(ElecAccMHTNJetsB0_,ElecAccMHTNJetsB0Fail_);   
  ElecAccMHTNJetsB0_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc B_{Tags}=0; #slash{H}_{T} [GeV]; N_{Jets}");
  ElecAccMHTNJetsB0_->SetMarkerSize(2.0);
  ElecAccMHTNJetsB0_->UseCurrentStyle();
  ElecAccMHTNJetsB0_->Write();
  SaveEfficiency(ElecAccMHTNJetsB0_);
  
  ElecAccMHTNJetsB1_Inf_ = ratioCalculator(ElecAccMHTNJetsB1_Inf_,ElecAccMHTNJetsB1_InfFail_);   
  ElecAccMHTNJetsB1_Inf_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc B_{Tags}#geq1; #slash{H}_{T} [GeV]; N_{Jets}");
  ElecAccMHTNJetsB1_Inf_->SetMarkerSize(2.0);
  ElecAccMHTNJetsB1_Inf_->UseCurrentStyle();
  ElecAccMHTNJetsB1_Inf_->Write();
  SaveEfficiency(ElecAccMHTNJetsB1_Inf_);
  
  ElecAccHTMHT_NJets46_ = ratioCalculator(ElecAccHTMHT_NJets46_,ElecAccHTMHT_NJets46Fail_);   
  ElecAccHTMHT_NJets46_->SetTitle("Simulation, L=4 fb-1, #sqrt{s}=13 TeV e acc 4#geqN_{Jets}#geq6; H_{T} [GeV]; #slash{H}_{T} [GeV]");
  ElecAccHTMHT_NJets46_->SetMarkerSize(2.0);
  ElecAccHTMHT_NJets46_->UseCurrentStyle();
  ElecAccHTMHT_NJets46_->Write();
  SaveEfficiency(ElecAccHTMHT_NJets46_);
  
  ElecAccHTMHT_NJets7Inf_ = ratioCalculator(ElecAccHTMHT_NJets7Inf_,ElecAccHTMHT_NJets7InfFail_);   
  ElecAccHTMHT_NJets7Inf_->SetTitle("Simulation, L=4 fb-1, #sqrt{s}=13 TeV e acc 7#geqN_{Jets}; H_{T}  [GeV]; #slash{H}_{T} [GeV]");
  ElecAccHTMHT_NJets7Inf_->SetMarkerSize(2.0);
  ElecAccHTMHT_NJets7Inf_->UseCurrentStyle();
  ElecAccHTMHT_NJets7Inf_->Write();
  SaveEfficiency(ElecAccHTMHT_NJets7Inf_);
  
  
  
  // reco
  //muon
  //1D
  MuRecoBTag_ = ratioCalculator(MuRecoBTag_,MuRecoBTagFail_);   
  MuRecoBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; B_{Tags}");
  MuRecoBTag_->SetMarkerSize(2.0);
  MuRecoBTag_->UseCurrentStyle();
  MuRecoBTag_->Write();
  SaveEfficiency(MuRecoBTag_);
  
  MuRecoNJets_ = ratioCalculator(MuRecoNJets_,MuRecoNJetsFail_);   
  MuRecoNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; N_{Jets}");
  MuRecoNJets_->SetMarkerSize(2.0);
  MuRecoNJets_->UseCurrentStyle();
  MuRecoNJets_->Write();
  SaveEfficiency(MuRecoNJets_);
  
  MuRecoHT_ = ratioCalculator(MuRecoHT_,MuRecoHTFail_);   
  MuRecoHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; H_{T} [GeV]");
  MuRecoHT_->SetMarkerSize(2.0);
  MuRecoHT_->UseCurrentStyle();
  MuRecoHT_->Write();
  SaveEfficiency(MuRecoHT_);
  
  MuRecoMHT_ = ratioCalculator(MuRecoMHT_,MuRecoMHTFail_);   
  MuRecoMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; #slash{H}_{T} [GeV]");
  MuRecoMHT_->SetMarkerSize(2.0);
  MuRecoMHT_->UseCurrentStyle();
  MuRecoMHT_->Write();
  SaveEfficiency(MuRecoMHT_);
  
  MuRecoPTJetRel_ = ratioCalculator(MuRecoPTJetRel_,MuRecoPTJetRelFail_);   
  MuRecoPTJetRel_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; #mu p_{T}/Jet p_{T}");
  MuRecoPTJetRel_->SetMarkerSize(2.0);
  MuRecoPTJetRel_->UseCurrentStyle();
  MuRecoPTJetRel_->Write();
  SaveEfficiency(MuRecoPTJetRel_);
  
  MuRecoDeltaRJet_ = ratioCalculator(MuRecoDeltaRJet_,MuRecoDeltaRJetFail_);   
  MuRecoDeltaRJet_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; #DeltaR");
  MuRecoDeltaRJet_->SetMarkerSize(2.0);
  MuRecoDeltaRJet_->UseCurrentStyle();
  MuRecoDeltaRJet_->Write();
  SaveEfficiency(MuRecoDeltaRJet_);
  
  MuRecoDeltaRRelPTJet_ = ratioCalculator(MuRecoDeltaRRelPTJet_,MuRecoDeltaRRelPTJetFail_);   
  MuRecoDeltaRRelPTJet_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; #DeltaR; #mu p_{T}/Jet p_{T}");
  MuRecoDeltaRRelPTJet_->SetMarkerSize(2.0);
  MuRecoDeltaRRelPTJet_->UseCurrentStyle();
  MuRecoDeltaRRelPTJet_->Write();
  SaveEfficiency(MuRecoDeltaRRelPTJet_);
  
  //elec
  //1D
  ElecRecoBTag_ = ratioCalculator(ElecRecoBTag_,ElecRecoBTagFail_);   
  ElecRecoBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; B_{Tags}");
  ElecRecoBTag_->SetMarkerSize(2.0);
  ElecRecoBTag_->UseCurrentStyle();
  ElecRecoBTag_->Write();
  SaveEfficiency(ElecRecoBTag_);
  
  ElecRecoNJets_ = ratioCalculator(ElecRecoNJets_,ElecRecoNJetsFail_);   
  ElecRecoNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; N_{Jets}");
  ElecRecoNJets_->SetMarkerSize(2.0);
  ElecRecoNJets_->UseCurrentStyle();
  ElecRecoNJets_->Write();
  SaveEfficiency(ElecRecoNJets_);
  
  ElecRecoHT_ = ratioCalculator(ElecRecoHT_,ElecRecoHTFail_);   
  ElecRecoHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; H_{T} [GeV]");
  ElecRecoHT_->SetMarkerSize(2.0);
  ElecRecoHT_->UseCurrentStyle();
  ElecRecoHT_->Write();
  SaveEfficiency(ElecRecoHT_);
  
  ElecRecoMHT_ = ratioCalculator(ElecRecoMHT_,ElecRecoMHTFail_);   
  ElecRecoMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; #slash{H}_{T} [GeV]");
  ElecRecoMHT_->SetMarkerSize(2.0);
  ElecRecoMHT_->UseCurrentStyle();
  ElecRecoMHT_->Write();
  SaveEfficiency(ElecRecoMHT_);
  
  
  ElecRecoPTJetRel_ = ratioCalculator(ElecRecoPTJetRel_,ElecRecoPTJetRelFail_);   
  ElecRecoPTJetRel_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; e p_{T}/Jet p_{T}");
  ElecRecoPTJetRel_->SetMarkerSize(2.0);
  ElecRecoPTJetRel_->UseCurrentStyle();
  ElecRecoPTJetRel_->Write();
  SaveEfficiency(ElecRecoPTJetRel_);
  
  ElecRecoDeltaRJet_ = ratioCalculator(ElecRecoDeltaRJet_,ElecRecoDeltaRJetFail_);   
  ElecRecoDeltaRJet_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; #DeltaR");
  ElecRecoDeltaRJet_->SetMarkerSize(2.0);
  ElecRecoDeltaRJet_->UseCurrentStyle();
  ElecRecoDeltaRJet_->Write();
  SaveEfficiency(ElecRecoDeltaRJet_);
  
  ElecRecoDeltaRRelPTJet_ = ratioCalculator(ElecRecoDeltaRRelPTJet_,ElecRecoDeltaRRelPTJetFail_);   
  ElecRecoDeltaRRelPTJet_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; #DeltaR; e p_{T}/Jet p_{T}");
  ElecRecoDeltaRRelPTJet_->SetMarkerSize(2.0);
  ElecRecoDeltaRRelPTJet_->UseCurrentStyle();
  ElecRecoDeltaRRelPTJet_->Write();
  SaveEfficiency(ElecRecoDeltaRRelPTJet_);
  
  
  
  // iso
  //muon
  //1D
  MuIsoBTag_ = ratioCalculator(MuIsoBTag_,MuIsoBTagFail_);   
  MuIsoBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; B_{Tags}");
  MuIsoBTag_->SetMarkerSize(2.0);
  MuIsoBTag_->UseCurrentStyle();
  MuIsoBTag_->Write();
  SaveEfficiency(MuIsoBTag_);
  
  MuIsoNJets_ = ratioCalculator(MuIsoNJets_,MuIsoNJetsFail_);   
  MuIsoNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; N_{Jets}");
  MuIsoNJets_->SetMarkerSize(2.0);
  MuIsoNJets_->UseCurrentStyle();
  MuIsoNJets_->Write();
  SaveEfficiency(MuIsoNJets_);
  
  MuIsoHT_ = ratioCalculator(MuIsoHT_,MuIsoHTFail_);   
  MuIsoHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; H_{T} [GeV]");
  MuIsoHT_->SetMarkerSize(2.0);
  MuIsoHT_->UseCurrentStyle();
  MuIsoHT_->Write();
  SaveEfficiency(MuIsoHT_);
  
  MuIsoMHT_ = ratioCalculator(MuIsoMHT_,MuIsoMHTFail_);   
  MuIsoMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; #slash{H}_{T} [GeV]");
  MuIsoMHT_->SetMarkerSize(2.0);
  MuIsoMHT_->UseCurrentStyle();
  MuIsoMHT_->Write();
  SaveEfficiency(MuIsoMHT_);
  
  MuIsoPTJetRel_ = ratioCalculator(MuIsoPTJetRel_,MuIsoPTJetRelFail_);   
  MuIsoPTJetRel_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; #mu p_{T}/Jet p_{T}");
  MuIsoPTJetRel_->SetMarkerSize(2.0);
  MuIsoPTJetRel_->UseCurrentStyle();
  MuIsoPTJetRel_->Write();
  SaveEfficiency(MuIsoPTJetRel_);
  
  MuIsoDeltaRJet_ = ratioCalculator(MuIsoDeltaRJet_,MuIsoDeltaRJetFail_);   
  MuIsoDeltaRJet_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; #DeltaR");
  MuIsoDeltaRJet_->SetMarkerSize(2.0);
  MuIsoDeltaRJet_->UseCurrentStyle();
  MuIsoDeltaRJet_->Write();
  SaveEfficiency(MuIsoDeltaRJet_);
  
  MuIsoDeltaRRelPTJet_ = ratioCalculator(MuIsoDeltaRRelPTJet_,MuIsoDeltaRRelPTJetFail_);   
  MuIsoDeltaRRelPTJet_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; #DeltaR; #mu p_{T}/Jet p_{T}");
  MuIsoDeltaRRelPTJet_->SetMarkerSize(2.0);
  MuIsoDeltaRRelPTJet_->UseCurrentStyle();
  MuIsoDeltaRRelPTJet_->Write();
  SaveEfficiency(MuIsoDeltaRRelPTJet_);
  
  //elec
  //1D
  ElecIsoBTag_ = ratioCalculator(ElecIsoBTag_,ElecIsoBTagFail_);   
  ElecIsoBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; B_{Tags}");
  ElecIsoBTag_->SetMarkerSize(2.0);
  ElecIsoBTag_->UseCurrentStyle();
  ElecIsoBTag_->Write();
  SaveEfficiency(ElecIsoBTag_);
  
  ElecIsoNJets_ = ratioCalculator(ElecIsoNJets_,ElecIsoNJetsFail_);   
  ElecIsoNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; N_{Jets}");
  ElecIsoNJets_->SetMarkerSize(2.0);
  ElecIsoNJets_->UseCurrentStyle();
  ElecIsoNJets_->Write();
  SaveEfficiency(ElecIsoNJets_);
  
  ElecIsoHT_ = ratioCalculator(ElecIsoHT_,ElecIsoHTFail_);   
  ElecIsoHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; H_{T} [GeV]");
  ElecIsoHT_->SetMarkerSize(2.0);
  ElecIsoHT_->UseCurrentStyle();
  ElecIsoHT_->Write();
  SaveEfficiency(ElecIsoHT_);
  
  ElecIsoMHT_ = ratioCalculator(ElecIsoMHT_,ElecIsoMHTFail_);   
  ElecIsoMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; #slash{H}_{T} [GeV]");
  ElecIsoMHT_->SetMarkerSize(2.0);
  ElecIsoMHT_->UseCurrentStyle();
  ElecIsoMHT_->Write();
  SaveEfficiency(ElecIsoMHT_);
  
  ElecIsoPTJetRel_ = ratioCalculator(ElecIsoPTJetRel_,ElecIsoPTJetRelFail_);   
  ElecIsoPTJetRel_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; e p_{T}/Jet p_{T}");
  ElecIsoPTJetRel_->SetMarkerSize(2.0);
  ElecIsoPTJetRel_->UseCurrentStyle();
  ElecIsoPTJetRel_->Write();
  SaveEfficiency(ElecIsoPTJetRel_);
  
  ElecIsoDeltaRJet_ = ratioCalculator(ElecIsoDeltaRJet_,ElecIsoDeltaRJetFail_);   
  ElecIsoDeltaRJet_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; #DeltaR");
  ElecIsoDeltaRJet_->SetMarkerSize(2.0);
  ElecIsoDeltaRJet_->UseCurrentStyle();
  ElecIsoDeltaRJet_->Write();
  SaveEfficiency(ElecIsoDeltaRJet_);
  
  ElecIsoDeltaRRelPTJet_ = ratioCalculator(ElecIsoDeltaRRelPTJet_,ElecIsoDeltaRRelPTJetFail_);   
  ElecIsoDeltaRRelPTJet_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; #DeltaR; e p_{T}/Jet p_{T}");
  ElecIsoDeltaRRelPTJet_->SetMarkerSize(2.0);
  ElecIsoDeltaRRelPTJet_->UseCurrentStyle();
  ElecIsoDeltaRRelPTJet_->Write();
  SaveEfficiency(ElecIsoDeltaRRelPTJet_);
  
  
  // m_{T}(w)
  //muon
  //1D
  MuMTWBTag_ = ratioCalculator(MuMTWBTag_,MuMTWBTagFail_);   
  MuMTWBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu m_{T}(w); B_{Tags}");
  MuMTWBTag_->SetMarkerSize(2.0);
  MuMTWBTag_->UseCurrentStyle();
  MuMTWBTag_->Write();
  SaveEfficiency(MuMTWBTag_);
  
  MuMTWNJets_ = ratioCalculator(MuMTWNJets_,MuMTWNJetsFail_);   
  MuMTWNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu m_{T}(w); N_{Jets}");
  MuMTWNJets_->SetMarkerSize(2.0);
  MuMTWNJets_->UseCurrentStyle();
  MuMTWNJets_->Write();
  SaveEfficiency(MuMTWNJets_);
  
  MuMTWHT_ = ratioCalculator(MuMTWHT_,MuMTWHTFail_);   
  MuMTWHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu m_{T}(w); H_{T} [GeV]");
  MuMTWHT_->SetMarkerSize(2.0);
  MuMTWHT_->UseCurrentStyle();
  MuMTWHT_->Write();
  SaveEfficiency(MuMTWHT_);
  
  MuMTWMHT_ = ratioCalculator(MuMTWMHT_,MuMTWMHTFail_);   
  MuMTWMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu m_{T}(w); #slash{H}_{T} [GeV]");
  MuMTWMHT_->SetMarkerSize(2.0);
  MuMTWMHT_->UseCurrentStyle();
  MuMTWMHT_->Write();
  SaveEfficiency(MuMTWMHT_);
  
  MuMTWPTActivity_ = ratioCalculator(MuMTWPTActivity_,MuMTWPTActivityFail_);   
  MuMTWPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu m_{T}(w); #mu p_{T} [GeV]; Activity [GeV]");
  MuMTWPTActivity_->SetMarkerSize(2.0);
  MuMTWPTActivity_->UseCurrentStyle();
  MuMTWPTActivity_->Write();
  SaveEfficiency(MuMTWPTActivity_);
  
  //muon
  //1D
  MuDiLepBTag_ = ratioCalculator(MuDiLepBTag_,MuDiLepBTagFail_);   
  MuDiLepBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep; B_{Tags}");
  MuDiLepBTag_->SetMarkerSize(2.0);
  MuDiLepBTag_->UseCurrentStyle();
  MuDiLepBTag_->Write();
  SaveEfficiency(MuDiLepBTag_);
  
  MuDiLepNJets_ = ratioCalculator(MuDiLepNJets_,MuDiLepNJetsFail_);   
  MuDiLepNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep; N_{Jets}");
  MuDiLepNJets_->SetMarkerSize(2.0);
  MuDiLepNJets_->UseCurrentStyle();
  MuDiLepNJets_->Write();
  SaveEfficiency(MuDiLepNJets_);
  
  MuDiLepHT_ = ratioCalculator(MuDiLepHT_,MuDiLepHTFail_);   
  MuDiLepHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep; H_{T} [GeV]");
  MuDiLepHT_->SetMarkerSize(2.0);
  MuDiLepHT_->UseCurrentStyle();
  MuDiLepHT_->Write();
  SaveEfficiency(MuDiLepHT_);
  
  MuDiLepMHT_ = ratioCalculator(MuDiLepMHT_,MuDiLepMHTFail_);   
  MuDiLepMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep; #slash{H}_{T} [GeV]");
  MuDiLepMHT_->SetMarkerSize(2.0);
  MuDiLepMHT_->UseCurrentStyle();
  MuDiLepMHT_->Write();
  SaveEfficiency(MuDiLepMHT_);
  
  MuDiLepMTWBTag_ = ratioCalculator(MuDiLepMTWBTag_,MuDiLepMTWBTagFail_);   
  MuDiLepMTWBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep; B_{Tags}");
  MuDiLepMTWBTag_->SetMarkerSize(2.0);
  MuDiLepMTWBTag_->UseCurrentStyle();
  MuDiLepMTWBTag_->Write();
  SaveEfficiency(MuDiLepMTWBTag_);
  
  MuDiLepMTWNJets_ = ratioCalculator(MuDiLepMTWNJets_,MuDiLepMTWNJetsFail_);   
  MuDiLepMTWNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep; N_{Jets}");
  MuDiLepMTWNJets_->SetMarkerSize(2.0);
  MuDiLepMTWNJets_->UseCurrentStyle();
  MuDiLepMTWNJets_->Write();
  SaveEfficiency(MuDiLepMTWNJets_);
  
  MuDiLepMTWHT_ = ratioCalculator(MuDiLepMTWHT_,MuDiLepMTWHTFail_);   
  MuDiLepMTWHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep; H_{T} [GeV]");
  MuDiLepMTWHT_->SetMarkerSize(2.0);
  MuDiLepMTWHT_->UseCurrentStyle();
  MuDiLepMTWHT_->Write();
  SaveEfficiency(MuDiLepMTWHT_);
  
  MuDiLepMTWMHT_ = ratioCalculator(MuDiLepMTWMHT_,MuDiLepMTWMHTFail_);   
  MuDiLepMTWMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep; #slash{H}_{T} [GeV]");
  MuDiLepMTWMHT_->SetMarkerSize(2.0);
  MuDiLepMTWMHT_->UseCurrentStyle();
  MuDiLepMTWMHT_->Write();
  SaveEfficiency(MuDiLepMTWMHT_);
  
  //muon
  //1D
  MuDiLepContributionBTag_ = ratioCalculator(MuDiLepContributionBTag_,MuDiLepContributionBTagFail_);   
  MuDiLepContributionBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep contri contri; B_{Tags}");
  MuDiLepContributionBTag_->SetMarkerSize(2.0);
  MuDiLepContributionBTag_->UseCurrentStyle();
  MuDiLepContributionBTag_->Write();
  SaveEfficiency(MuDiLepContributionBTag_);
  
  MuDiLepContributionNJets_ = ratioCalculator(MuDiLepContributionNJets_,MuDiLepContributionNJetsFail_);   
  MuDiLepContributionNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep contri contri; N_{Jets}");
  MuDiLepContributionNJets_->SetMarkerSize(2.0);
  MuDiLepContributionNJets_->UseCurrentStyle();
  MuDiLepContributionNJets_->Write();
  SaveEfficiency(MuDiLepContributionNJets_);
  
  MuDiLepContributionHT_ = ratioCalculator(MuDiLepContributionHT_,MuDiLepContributionHTFail_);   
  MuDiLepContributionHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep contri contri; H_{T} [GeV]");
  MuDiLepContributionHT_->SetMarkerSize(2.0);
  MuDiLepContributionHT_->UseCurrentStyle();
  MuDiLepContributionHT_->Write();
  SaveEfficiency(MuDiLepContributionHT_);
  
  MuDiLepContributionMHT_ = ratioCalculator(MuDiLepContributionMHT_,MuDiLepContributionMHTFail_);   
  MuDiLepContributionMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep contri contri; #slash{H}_{T} [GeV]");
  MuDiLepContributionMHT_->SetMarkerSize(2.0);
  MuDiLepContributionMHT_->UseCurrentStyle();
  MuDiLepContributionMHT_->Write();
  SaveEfficiency(MuDiLepContributionMHT_);
  
  MuDiLepContributionMTWBTag_ = ratioCalculator(MuDiLepContributionMTWBTag_,MuDiLepContributionMTWBTagFail_);   
  MuDiLepContributionMTWBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep contri contri; B_{Tags}");
  MuDiLepContributionMTWBTag_->SetMarkerSize(2.0);
  MuDiLepContributionMTWBTag_->UseCurrentStyle();
  MuDiLepContributionMTWBTag_->Write();
  SaveEfficiency(MuDiLepContributionMTWBTag_);
  
  MuDiLepContributionMTWNJets_ = ratioCalculator(MuDiLepContributionMTWNJets_,MuDiLepContributionMTWNJetsFail_);   
  MuDiLepContributionMTWNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep contri contri; N_{Jets}");
  MuDiLepContributionMTWNJets_->SetMarkerSize(2.0);
  MuDiLepContributionMTWNJets_->UseCurrentStyle();
  MuDiLepContributionMTWNJets_->Write();
  SaveEfficiency(MuDiLepContributionMTWNJets_);
  
  MuDiLepContributionMTWHT_ = ratioCalculator(MuDiLepContributionMTWHT_,MuDiLepContributionMTWHTFail_);   
  MuDiLepContributionMTWHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep contri contri; H_{T} [GeV]");
  MuDiLepContributionMTWHT_->SetMarkerSize(2.0);
  MuDiLepContributionMTWHT_->UseCurrentStyle();
  MuDiLepContributionMTWHT_->Write();
  SaveEfficiency(MuDiLepContributionMTWHT_);
  
  MuDiLepContributionMTWMHT_ = ratioCalculator(MuDiLepContributionMTWMHT_,MuDiLepContributionMTWMHTFail_);   
  MuDiLepContributionMTWMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu di-lep contri contri; #slash{H}_{T} [GeV]");
  MuDiLepContributionMTWMHT_->SetMarkerSize(2.0);
  MuDiLepContributionMTWMHT_->UseCurrentStyle();
  MuDiLepContributionMTWMHT_->Write();
  SaveEfficiency(MuDiLepContributionMTWMHT_);
  
  
  
  //elec
  //1D
  ElecMTWBTag_ = ratioCalculator(ElecMTWBTag_,ElecMTWBTagFail_);   
  ElecMTWBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e m_{T}(w); B_{Tags}");
  ElecMTWBTag_->SetMarkerSize(2.0);
  ElecMTWBTag_->UseCurrentStyle();
  ElecMTWBTag_->Write();
  SaveEfficiency(ElecMTWBTag_);
  
  ElecMTWNJets_ = ratioCalculator(ElecMTWNJets_,ElecMTWNJetsFail_);   
  ElecMTWNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e m_{T}(w); N_{Jets}");
  ElecMTWNJets_->SetMarkerSize(2.0);
  ElecMTWNJets_->UseCurrentStyle();
  ElecMTWNJets_->Write();
  SaveEfficiency(ElecMTWNJets_);
  
  ElecMTWHT_ = ratioCalculator(ElecMTWHT_,ElecMTWHTFail_);   
  ElecMTWHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e m_{T}(w); H_{T} [GeV]");
  ElecMTWHT_->SetMarkerSize(2.0);
  ElecMTWHT_->UseCurrentStyle();
  ElecMTWHT_->Write();
  SaveEfficiency(ElecMTWHT_);
  
  ElecMTWMHT_ = ratioCalculator(ElecMTWMHT_,ElecMTWMHTFail_);   
  ElecMTWMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e m_{T}(w); #slash{H}_{T} [GeV]");
  ElecMTWMHT_->SetMarkerSize(2.0);
  ElecMTWMHT_->UseCurrentStyle();
  ElecMTWMHT_->Write();
  SaveEfficiency(ElecMTWMHT_);
  
  ElecDiLepBTag_ = ratioCalculator(ElecDiLepBTag_,ElecDiLepBTagFail_);   
  ElecDiLepBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep; B_{Tags}");
  ElecDiLepBTag_->SetMarkerSize(2.0);
  ElecDiLepBTag_->UseCurrentStyle();
  ElecDiLepBTag_->Write();
  SaveEfficiency(ElecDiLepBTag_);
  
  ElecDiLepNJets_ = ratioCalculator(ElecDiLepNJets_,ElecDiLepNJetsFail_);   
  ElecDiLepNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep; N_{Jets}");
  ElecDiLepNJets_->SetMarkerSize(2.0);
  ElecDiLepNJets_->UseCurrentStyle();
  ElecDiLepNJets_->Write();
  SaveEfficiency(ElecDiLepNJets_);
  
  ElecDiLepHT_ = ratioCalculator(ElecDiLepHT_,ElecDiLepHTFail_);   
  ElecDiLepHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep; H_{T} [GeV]");
  ElecDiLepHT_->SetMarkerSize(2.0);
  ElecDiLepHT_->UseCurrentStyle();
  ElecDiLepHT_->Write();
  SaveEfficiency(ElecDiLepHT_);
  
  ElecDiLepMHT_ = ratioCalculator(ElecDiLepMHT_,ElecDiLepMHTFail_);   
  ElecDiLepMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep; #slash{H}_{T} [GeV]");
  ElecDiLepMHT_->SetMarkerSize(2.0);
  ElecDiLepMHT_->UseCurrentStyle();
  ElecDiLepMHT_->Write();
  SaveEfficiency(ElecDiLepMHT_);
  
  ElecDiLepMTWBTag_ = ratioCalculator(ElecDiLepMTWBTag_,ElecDiLepMTWBTagFail_);   
  ElecDiLepMTWBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep; B_{Tags}");
  ElecDiLepMTWBTag_->SetMarkerSize(2.0);
  ElecDiLepMTWBTag_->UseCurrentStyle();
  ElecDiLepMTWBTag_->Write();
  SaveEfficiency(ElecDiLepMTWBTag_);
  
  ElecDiLepMTWNJets_ = ratioCalculator(ElecDiLepMTWNJets_,ElecDiLepMTWNJetsFail_);   
  ElecDiLepMTWNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep; N_{Jets}");
  ElecDiLepMTWNJets_->SetMarkerSize(2.0);
  ElecDiLepMTWNJets_->UseCurrentStyle();
  ElecDiLepMTWNJets_->Write();
  SaveEfficiency(ElecDiLepMTWNJets_);
  
  ElecDiLepMTWHT_ = ratioCalculator(ElecDiLepMTWHT_,ElecDiLepMTWHTFail_);   
  ElecDiLepMTWHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep; H_{T} [GeV]");
  ElecDiLepMTWHT_->SetMarkerSize(2.0);
  ElecDiLepMTWHT_->UseCurrentStyle();
  ElecDiLepMTWHT_->Write();
  SaveEfficiency(ElecDiLepMTWHT_);
  
  ElecDiLepMTWMHT_ = ratioCalculator(ElecDiLepMTWMHT_,ElecDiLepMTWMHTFail_);   
  ElecDiLepMTWMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep; #slash{H}_{T} [GeV]");
  ElecDiLepMTWMHT_->SetMarkerSize(2.0);
  ElecDiLepMTWMHT_->UseCurrentStyle();
  ElecDiLepMTWMHT_->Write();
  SaveEfficiency(ElecDiLepMTWMHT_);
  
  ElecMTWPTActivity_ = ratioCalculator(ElecMTWPTActivity_,ElecMTWPTActivityFail_);   
  ElecMTWPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e m_{T}(w); e p_{T} [GeV]; Activity [GeV]");
  ElecMTWPTActivity_->SetMarkerSize(2.0);
  ElecMTWPTActivity_->UseCurrentStyle();
  ElecMTWPTActivity_->Write();
  SaveEfficiency(ElecMTWPTActivity_);
  
  //muon
  //1D
  ElecDiLepContributionBTag_ = ratioCalculator(ElecDiLepContributionBTag_,ElecDiLepContributionBTagFail_);   
  ElecDiLepContributionBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep contri contri; B_{Tags}");
  ElecDiLepContributionBTag_->SetMarkerSize(2.0);
  ElecDiLepContributionBTag_->UseCurrentStyle();
  ElecDiLepContributionBTag_->Write();
  SaveEfficiency(ElecDiLepContributionBTag_);
  
  ElecDiLepContributionNJets_ = ratioCalculator(ElecDiLepContributionNJets_,ElecDiLepContributionNJetsFail_);   
  ElecDiLepContributionNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep contri contri; N_{Jets}");
  ElecDiLepContributionNJets_->SetMarkerSize(2.0);
  ElecDiLepContributionNJets_->UseCurrentStyle();
  ElecDiLepContributionNJets_->Write();
  SaveEfficiency(ElecDiLepContributionNJets_);
  
  ElecDiLepContributionHT_ = ratioCalculator(ElecDiLepContributionHT_,ElecDiLepContributionHTFail_);   
  ElecDiLepContributionHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep contri contri; H_{T} [GeV]");
  ElecDiLepContributionHT_->SetMarkerSize(2.0);
  ElecDiLepContributionHT_->UseCurrentStyle();
  ElecDiLepContributionHT_->Write();
  SaveEfficiency(ElecDiLepContributionHT_);
  
  ElecDiLepContributionMHT_ = ratioCalculator(ElecDiLepContributionMHT_,ElecDiLepContributionMHTFail_);   
  ElecDiLepContributionMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep contri contri; #slash{H}_{T} [GeV]");
  ElecDiLepContributionMHT_->SetMarkerSize(2.0);
  ElecDiLepContributionMHT_->UseCurrentStyle();
  ElecDiLepContributionMHT_->Write();
  SaveEfficiency(ElecDiLepContributionMHT_);
  
  ElecDiLepContributionMTWBTag_ = ratioCalculator(ElecDiLepContributionMTWBTag_,ElecDiLepContributionMTWBTagFail_);   
  ElecDiLepContributionMTWBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep contri contri; B_{Tags}");
  ElecDiLepContributionMTWBTag_->SetMarkerSize(2.0);
  ElecDiLepContributionMTWBTag_->UseCurrentStyle();
  ElecDiLepContributionMTWBTag_->Write();
  SaveEfficiency(ElecDiLepContributionMTWBTag_);
  
  ElecDiLepContributionMTWNJets_ = ratioCalculator(ElecDiLepContributionMTWNJets_,ElecDiLepContributionMTWNJetsFail_);   
  ElecDiLepContributionMTWNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep contri contri; N_{Jets}");
  ElecDiLepContributionMTWNJets_->SetMarkerSize(2.0);
  ElecDiLepContributionMTWNJets_->UseCurrentStyle();
  ElecDiLepContributionMTWNJets_->Write();
  SaveEfficiency(ElecDiLepContributionMTWNJets_);
  
  ElecDiLepContributionMTWHT_ = ratioCalculator(ElecDiLepContributionMTWHT_,ElecDiLepContributionMTWHTFail_);   
  ElecDiLepContributionMTWHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep contri contri; H_{T} [GeV]");
  ElecDiLepContributionMTWHT_->SetMarkerSize(2.0);
  ElecDiLepContributionMTWHT_->UseCurrentStyle();
  ElecDiLepContributionMTWHT_->Write();
  SaveEfficiency(ElecDiLepContributionMTWHT_);
  
  ElecDiLepContributionMTWMHT_ = ratioCalculator(ElecDiLepContributionMTWMHT_,ElecDiLepContributionMTWMHTFail_);   
  ElecDiLepContributionMTWMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e di-lep contri contri; #slash{H}_{T} [GeV]");
  ElecDiLepContributionMTWMHT_->SetMarkerSize(2.0);
  ElecDiLepContributionMTWMHT_->UseCurrentStyle();
  ElecDiLepContributionMTWMHT_->Write();
  SaveEfficiency(ElecDiLepContributionMTWMHT_);
  
  
  
  // isoalted track
  //muon
  //1D
  //   IsoTrackMuBTag_ = ratioCalculator(IsoTrackMuBTag_,IsoTrackMuBTagFail_);   
  //   IsoTrackMuBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; B_{Tags}");
  //   IsoTrackMuBTag_->SetMarkerSize(2.0);
  //   IsoTrackMuBTag_->UseCurrentStyle();
  //   IsoTrackMuBTag_->Write();
  //   SaveEfficiency(IsoTrackMuBTag_);
  //   
  //   IsoTrackMuNJets_ = ratioCalculator(IsoTrackMuNJets_,IsoTrackMuNJetsFail_);   
  //   IsoTrackMuNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; N_{Jets}");
  //   IsoTrackMuNJets_->SetMarkerSize(2.0);
  //   IsoTrackMuNJets_->UseCurrentStyle();
  //   IsoTrackMuNJets_->Write();
  //   SaveEfficiency(IsoTrackMuNJets_);
  //   
  //   IsoTrackMuHT_ = ratioCalculator(IsoTrackMuHT_,IsoTrackMuHTFail_);   
  //   IsoTrackMuHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; H_{T} [GeV]");
  //   IsoTrackMuHT_->SetMarkerSize(2.0);
  //   IsoTrackMuHT_->UseCurrentStyle();
  //   IsoTrackMuHT_->Write();
  //   SaveEfficiency(IsoTrackMuHT_);
  //   
  //   IsoTrackMuMHT_ = ratioCalculator(IsoTrackMuMHT_,IsoTrackMuMHTFail_);   
  //   IsoTrackMuMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; #slash{H}_{T} [GeV]");
  //   IsoTrackMuMHT_->SetMarkerSize(2.0);
  //   IsoTrackMuMHT_->UseCurrentStyle();
  //   IsoTrackMuMHT_->Write();
  //   SaveEfficiency(IsoTrackMuMHT_);
  //   //2d
  //   IsoTrackMuPTActivity_ = ratioCalculator(IsoTrackMuPTActivity_,IsoTrackMuPTActivityFail_);   
  //   IsoTrackMuPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; p_{T}; Activity");
  //   IsoTrackMuPTActivity_->SetMarkerSize(2.0);
  //   IsoTrackMuPTActivity_->UseCurrentStyle();
  //   IsoTrackMuPTActivity_->Write();
  //   SaveEfficiency(IsoTrackMuPTActivity_);
  //   
  //   
  //   IsoTrackMuMatchedToIsoMuBTag_ = ratioCalculator(IsoTrackMuMatchedToIsoMuBTag_,IsoTrackMuMatchedToIsoMuBTagFail_);   
  //   IsoTrackMuMatchedToIsoMuBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMuMatchedToIsoMu; B_{Tags}");
  //   IsoTrackMuMatchedToIsoMuBTag_->SetMarkerSize(2.0);
  //   IsoTrackMuMatchedToIsoMuBTag_->UseCurrentStyle();
  //   IsoTrackMuMatchedToIsoMuBTag_->Write();
  //   SaveEfficiency(IsoTrackMuMatchedToIsoMuBTag_);
  //   
  //   IsoTrackMuMatchedToIsoMuNJets_ = ratioCalculator(IsoTrackMuMatchedToIsoMuNJets_,IsoTrackMuMatchedToIsoMuNJetsFail_);   
  //   IsoTrackMuMatchedToIsoMuNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMuMatchedToIsoMu; N_{Jets}");
  //   IsoTrackMuMatchedToIsoMuNJets_->SetMarkerSize(2.0);
  //   IsoTrackMuMatchedToIsoMuNJets_->UseCurrentStyle();
  //   IsoTrackMuMatchedToIsoMuNJets_->Write();
  //   SaveEfficiency(IsoTrackMuMatchedToIsoMuNJets_);
  //   
  //   IsoTrackMuMatchedToIsoMuHT_ = ratioCalculator(IsoTrackMuMatchedToIsoMuHT_,IsoTrackMuMatchedToIsoMuHTFail_);   
  //   IsoTrackMuMatchedToIsoMuHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMuMatchedToIsoMu; H_{T} [GeV]");
  //   IsoTrackMuMatchedToIsoMuHT_->SetMarkerSize(2.0);
  //   IsoTrackMuMatchedToIsoMuHT_->UseCurrentStyle();
  //   IsoTrackMuMatchedToIsoMuHT_->Write();
  //   SaveEfficiency(IsoTrackMuMatchedToIsoMuHT_);
  //   
  //   IsoTrackMuMatchedToIsoMuMHT_ = ratioCalculator(IsoTrackMuMatchedToIsoMuMHT_,IsoTrackMuMatchedToIsoMuMHTFail_);   
  //   IsoTrackMuMatchedToIsoMuMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMuMatchedToIsoMu; #slash{H}_{T} [GeV]");
  //   IsoTrackMuMatchedToIsoMuMHT_->SetMarkerSize(2.0);
  //   IsoTrackMuMatchedToIsoMuMHT_->UseCurrentStyle();
  //   IsoTrackMuMatchedToIsoMuMHT_->Write();
  //   SaveEfficiency(IsoTrackMuMatchedToIsoMuMHT_);
  //   
  //   //elec
  //   //1D
  //   IsoTrackElecBTag_ = ratioCalculator(IsoTrackElecBTag_,IsoTrackElecBTagFail_);   
  //   IsoTrackElecBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; B_{Tags}");
  //   IsoTrackElecBTag_->SetMarkerSize(2.0);
  //   IsoTrackElecBTag_->UseCurrentStyle();
  //   IsoTrackElecBTag_->Write();
  //   SaveEfficiency(IsoTrackElecBTag_);
  //   
  //   IsoTrackElecNJets_ = ratioCalculator(IsoTrackElecNJets_,IsoTrackElecNJetsFail_);   
  //   IsoTrackElecNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; N_{Jets}");
  //   IsoTrackElecNJets_->SetMarkerSize(2.0);
  //   IsoTrackElecNJets_->UseCurrentStyle();
  //   IsoTrackElecNJets_->Write();
  //   SaveEfficiency(IsoTrackElecNJets_);
  //   
  //   IsoTrackElecHT_ = ratioCalculator(IsoTrackElecHT_,IsoTrackElecHTFail_);   
  //   IsoTrackElecHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; H_{T} [GeV]");
  //   IsoTrackElecHT_->SetMarkerSize(2.0);
  //   IsoTrackElecHT_->UseCurrentStyle();
  //   IsoTrackElecHT_->Write();
  //   SaveEfficiency(IsoTrackElecHT_);
  //   
  //   IsoTrackElecMHT_ = ratioCalculator(IsoTrackElecMHT_,IsoTrackElecMHTFail_);   
  //   IsoTrackElecMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; #slash{H}_{T} [GeV]");
  //   IsoTrackElecMHT_->SetMarkerSize(2.0);
  //   IsoTrackElecMHT_->UseCurrentStyle();
  //   IsoTrackElecMHT_->Write();
  //   SaveEfficiency(IsoTrackElecMHT_);
  //   
  //   
  //   IsoTrackElecPTActivity_ = ratioCalculator(IsoTrackElecPTActivity_,IsoTrackElecPTActivityFail_);   
  //   IsoTrackElecPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; p_{T}; Activity");
  //   IsoTrackElecPTActivity_->SetMarkerSize(2.0);
  //   IsoTrackElecPTActivity_->UseCurrentStyle();
  //   IsoTrackElecPTActivity_->Write();
  //   SaveEfficiency(IsoTrackElecPTActivity_);
  //   
  //   IsoTrackElecMatchedToIsoElecBTag_ = ratioCalculator(IsoTrackElecMatchedToIsoElecBTag_,IsoTrackElecMatchedToIsoElecBTagFail_);   
  //   IsoTrackElecMatchedToIsoElecBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElecMatchedToIsoElec; B_{Tags}");
  //   IsoTrackElecMatchedToIsoElecBTag_->SetMarkerSize(2.0);
  //   IsoTrackElecMatchedToIsoElecBTag_->UseCurrentStyle();
  //   IsoTrackElecMatchedToIsoElecBTag_->Write();
  //   SaveEfficiency(IsoTrackElecMatchedToIsoElecBTag_);
  //   
  //   IsoTrackElecMatchedToIsoElecNJets_ = ratioCalculator(IsoTrackElecMatchedToIsoElecNJets_,IsoTrackElecMatchedToIsoElecNJetsFail_);   
  //   IsoTrackElecMatchedToIsoElecNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElecMatchedToIsoElec; N_{Jets}");
  //   IsoTrackElecMatchedToIsoElecNJets_->SetMarkerSize(2.0);
  //   IsoTrackElecMatchedToIsoElecNJets_->UseCurrentStyle();
  //   IsoTrackElecMatchedToIsoElecNJets_->Write();
  //   SaveEfficiency(IsoTrackElecMatchedToIsoElecNJets_);
  //   
  //   IsoTrackElecMatchedToIsoElecHT_ = ratioCalculator(IsoTrackElecMatchedToIsoElecHT_,IsoTrackElecMatchedToIsoElecHTFail_);   
  //   IsoTrackElecMatchedToIsoElecHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElecMatchedToIsoElec; H_{T} [GeV]");
  //   IsoTrackElecMatchedToIsoElecHT_->SetMarkerSize(2.0);
  //   IsoTrackElecMatchedToIsoElecHT_->UseCurrentStyle();
  //   IsoTrackElecMatchedToIsoElecHT_->Write();
  //   SaveEfficiency(IsoTrackElecMatchedToIsoElecHT_);
  //   
  //   IsoTrackElecMatchedToIsoElecMHT_ = ratioCalculator(IsoTrackElecMatchedToIsoElecMHT_,IsoTrackElecMatchedToIsoElecMHTFail_);   
  //   IsoTrackElecMatchedToIsoElecMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElecMatchedToIsoElec; #slash{H}_{T} [GeV]");
  //   IsoTrackElecMatchedToIsoElecMHT_->SetMarkerSize(2.0);
  //   IsoTrackElecMatchedToIsoElecMHT_->UseCurrentStyle();
  //   IsoTrackElecMatchedToIsoElecMHT_->Write();
  //   SaveEfficiency(IsoTrackElecMatchedToIsoElecMHT_);
  //   
  //   //muon
  //   //1D
  //   IsoTrackMuMTWBTag_ = ratioCalculator(IsoTrackMuMTWBTag_,IsoTrackMuMTWBTagFail_);   
  //   IsoTrackMuMTWBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; B_{Tags}");
  //   IsoTrackMuMTWBTag_->SetMarkerSize(2.0);
  //   IsoTrackMuMTWBTag_->UseCurrentStyle();
  //   IsoTrackMuMTWBTag_->Write();
  //   SaveEfficiency(IsoTrackMuMTWBTag_);
  //   
  //   IsoTrackMuMTWNJets_ = ratioCalculator(IsoTrackMuMTWNJets_,IsoTrackMuMTWNJetsFail_);   
  //   IsoTrackMuMTWNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; N_{Jets}");
  //   IsoTrackMuMTWNJets_->SetMarkerSize(2.0);
  //   IsoTrackMuMTWNJets_->UseCurrentStyle();
  //   IsoTrackMuMTWNJets_->Write();
  //   SaveEfficiency(IsoTrackMuMTWNJets_);
  //   
  //   IsoTrackMuMTWHT_ = ratioCalculator(IsoTrackMuMTWHT_,IsoTrackMuMTWHTFail_);   
  //   IsoTrackMuMTWHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; H_{T} [GeV]");
  //   IsoTrackMuMTWHT_->SetMarkerSize(2.0);
  //   IsoTrackMuMTWHT_->UseCurrentStyle();
  //   IsoTrackMuMTWHT_->Write();
  //   SaveEfficiency(IsoTrackMuMTWHT_);
  //   
  //   IsoTrackMuMTWMHT_ = ratioCalculator(IsoTrackMuMTWMHT_,IsoTrackMuMTWMHTFail_);   
  //   IsoTrackMuMTWMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenMu; #slash{H}_{T} [GeV]");
  //   IsoTrackMuMTWMHT_->SetMarkerSize(2.0);
  //   IsoTrackMuMTWMHT_->UseCurrentStyle();
  //   IsoTrackMuMTWMHT_->Write();
  //   SaveEfficiency(IsoTrackMuMTWMHT_);
  //   
  //   //elec
  //   //1D
  //   IsoTrackElecMTWBTag_ = ratioCalculator(IsoTrackElecMTWBTag_,IsoTrackElecMTWBTagFail_);   
  //   IsoTrackElecMTWBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; B_{Tags}");
  //   IsoTrackElecMTWBTag_->SetMarkerSize(2.0);
  //   IsoTrackElecMTWBTag_->UseCurrentStyle();
  //   IsoTrackElecMTWBTag_->Write();
  //   SaveEfficiency(IsoTrackElecMTWBTag_);
  //   
  //   IsoTrackElecMTWNJets_ = ratioCalculator(IsoTrackElecMTWNJets_,IsoTrackElecMTWNJetsFail_);   
  //   IsoTrackElecMTWNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; N_{Jets}");
  //   IsoTrackElecMTWNJets_->SetMarkerSize(2.0);
  //   IsoTrackElecMTWNJets_->UseCurrentStyle();
  //   IsoTrackElecMTWNJets_->Write();
  //   SaveEfficiency(IsoTrackElecMTWNJets_);
  //   
  //   IsoTrackElecMTWHT_ = ratioCalculator(IsoTrackElecMTWHT_,IsoTrackElecMTWHTFail_);   
  //   IsoTrackElecMTWHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; H_{T} [GeV]");
  //   IsoTrackElecMTWHT_->SetMarkerSize(2.0);
  //   IsoTrackElecMTWHT_->UseCurrentStyle();
  //   IsoTrackElecMTWHT_->Write();
  //   SaveEfficiency(IsoTrackElecMTWHT_);
  //   
  //   IsoTrackElecMTWMHT_ = ratioCalculator(IsoTrackElecMTWMHT_,IsoTrackElecMTWMHTFail_);   
  //   IsoTrackElecMTWMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV isotrack GenElec; #slash{H}_{T} [GeV]");
  //   IsoTrackElecMTWMHT_->SetMarkerSize(2.0);
  //   IsoTrackElecMTWMHT_->UseCurrentStyle();
  //   IsoTrackElecMTWMHT_->Write();
  //   SaveEfficiency(IsoTrackElecMTWMHT_);
  
  // pt and activity
  
  MuPurityPT_ = ratioCalculator(MuPurityPT_,MuPurityPTFail_);   
  MuPurityPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; #mu p_{T} [GeV]");
  MuPurityPT_->SetMarkerSize(2.0);
  MuPurityPT_->UseCurrentStyle();
  MuPurityPT_->Write();
  SaveEfficiency(MuPurityPT_);
  
  MuPurityActivity_ = ratioCalculator(MuPurityActivity_,MuPurityActivityFail_);   
  MuPurityActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu purity; Activity [GeV]");
  MuPurityActivity_->SetMarkerSize(2.0);
  MuPurityActivity_->UseCurrentStyle();
  MuPurityActivity_->Write();
  SaveEfficiency(MuPurityActivity_);
  
  
  MuAccPT_ = ratioCalculator(MuAccPT_,MuAccPTFail_);   
  MuAccPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; #mu p_{T} [GeV]");
  MuAccPT_->SetMarkerSize(2.0);
  MuAccPT_->UseCurrentStyle();
  MuAccPT_->Write();
  SaveEfficiency(MuAccPT_);
  
  MuAccActivity_ = ratioCalculator(MuAccActivity_,MuAccActivityFail_);   
  MuAccActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu acc; Activity [GeV]");
  MuAccActivity_->SetMarkerSize(2.0);
  MuAccActivity_->UseCurrentStyle();
  MuAccActivity_->Write();
  SaveEfficiency(MuAccActivity_);
  
  
  MuRecoPT_ = ratioCalculator(MuRecoPT_,MuRecoPTFail_);   
  MuRecoPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; #mu p_{T} [GeV]");
  MuRecoPT_->SetMarkerSize(2.0);
  MuRecoPT_->UseCurrentStyle();
  MuRecoPT_->Write();
  SaveEfficiency(MuRecoPT_);
  
  MuRecoActivity_ = ratioCalculator(MuRecoActivity_,MuRecoActivityFail_);   
  MuRecoActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; Activity [GeV]");
  MuRecoActivity_->SetMarkerSize(2.0);
  MuRecoActivity_->UseCurrentStyle();
  MuRecoActivity_->Write();
  SaveEfficiency(MuRecoActivity_);
  
  MuRecoPTActivity_ = ratioCalculator(MuRecoPTActivity_,MuRecoPTActivityFail_);   
  MuRecoPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco; #mu p_{T} [GeV];Activity [GeV]");
  MuRecoPTActivity_->SetMarkerSize(2.0);
  MuRecoPTActivity_->UseCurrentStyle();
  MuRecoPTActivity_->Write();
  SaveEfficiency(MuRecoPTActivity_);
  
  
  MuIsoPT_ = ratioCalculator(MuIsoPT_,MuIsoPTFail_);   
  MuIsoPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; #mu p_{T} [GeV]");
  MuIsoPT_->SetMarkerSize(2.0);
  MuIsoPT_->UseCurrentStyle();
  MuIsoPT_->Write();
  SaveEfficiency(MuIsoPT_);
  
  MuIsoActivity_ = ratioCalculator(MuIsoActivity_,MuIsoActivityFail_);   
  MuIsoActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso; Activity [GeV]");
  MuIsoActivity_->SetMarkerSize(2.0);
  MuIsoActivity_->UseCurrentStyle();
  MuIsoActivity_->Write();
  SaveEfficiency(MuIsoActivity_);
  
  
  MuMTWPT_ = ratioCalculator(MuMTWPT_,MuMTWPTFail_);   
  MuMTWPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu m_{T}(w); #mu p_{T} [GeV]");
  MuMTWPT_->SetMarkerSize(2.0);
  MuMTWPT_->UseCurrentStyle();
  MuMTWPT_->Write();
  SaveEfficiency(MuMTWPT_);
  
  MuMTWActivity_ = ratioCalculator(MuMTWActivity_,MuMTWActivityFail_);   
  MuMTWActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu m_{T}(w); Activity [GeV]");
  MuMTWActivity_->SetMarkerSize(2.0);
  MuMTWActivity_->UseCurrentStyle();
  MuMTWActivity_->Write();
  SaveEfficiency(MuMTWActivity_);
  
  MuIsoPTActivity_ = ratioCalculator(MuIsoPTActivity_,MuIsoPTActivityFail_);   
  MuIsoPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu Iso; #mu p_{T}[GeV]; Activity [GeV]");
  MuIsoPTActivity_->SetMarkerSize(2.0);
  MuIsoPTActivity_->UseCurrentStyle();
  MuIsoPTActivity_->Write();
  SaveEfficiency(MuIsoPTActivity_);
  
  
  
  ElecPurityPT_ = ratioCalculator(ElecPurityPT_,ElecPurityPTFail_);   
  ElecPurityPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; e p_{T} [GeV]");
  ElecPurityPT_->SetMarkerSize(2.0);
  ElecPurityPT_->UseCurrentStyle();
  ElecPurityPT_->Write();
  SaveEfficiency(ElecPurityPT_);
  
  ElecPurityActivity_ = ratioCalculator(ElecPurityActivity_,ElecPurityActivityFail_);   
  ElecPurityActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e purity; Activity [GeV]");
  ElecPurityActivity_->SetMarkerSize(2.0);
  ElecPurityActivity_->UseCurrentStyle();
  ElecPurityActivity_->Write();
  SaveEfficiency(ElecPurityActivity_);
  
  
  ElecAccPT_ = ratioCalculator(ElecAccPT_,ElecAccPTFail_);   
  ElecAccPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; e p_{T} [GeV]");
  ElecAccPT_->SetMarkerSize(2.0);
  ElecAccPT_->UseCurrentStyle();
  ElecAccPT_->Write();
  SaveEfficiency(ElecAccPT_);
  
  ElecAccActivity_ = ratioCalculator(ElecAccActivity_,ElecAccActivityFail_);   
  ElecAccActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e acc; Activity [GeV]");
  ElecAccActivity_->SetMarkerSize(2.0);
  ElecAccActivity_->UseCurrentStyle();
  ElecAccActivity_->Write();
  SaveEfficiency(ElecAccActivity_);
  
  
  ElecRecoPT_ = ratioCalculator(ElecRecoPT_,ElecRecoPTFail_);   
  ElecRecoPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; e p_{T} [GeV]");
  ElecRecoPT_->SetMarkerSize(2.0);
  ElecRecoPT_->UseCurrentStyle();
  ElecRecoPT_->Write();
  SaveEfficiency(ElecRecoPT_);
  
  ElecRecoActivity_ = ratioCalculator(ElecRecoActivity_,ElecRecoActivityFail_);   
  ElecRecoActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; Activity [GeV]");
  ElecRecoActivity_->SetMarkerSize(2.0);
  ElecRecoActivity_->UseCurrentStyle();
  ElecRecoActivity_->Write();
  SaveEfficiency(ElecRecoActivity_);
  
  ElecRecoPTActivity_ = ratioCalculator(ElecRecoPTActivity_,ElecRecoPTActivityFail_);   
  ElecRecoPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco; e p_{T} [GeV];Activity [GeV]");
  ElecRecoPTActivity_->SetMarkerSize(2.0);
  ElecRecoPTActivity_->UseCurrentStyle();
  ElecRecoPTActivity_->Write();
  SaveEfficiency(ElecRecoPTActivity_);
  
  
  ElecIsoPT_ = ratioCalculator(ElecIsoPT_,ElecIsoPTFail_);   
  ElecIsoPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; e p_{T} [GeV]");
  ElecIsoPT_->SetMarkerSize(2.0);
  ElecIsoPT_->UseCurrentStyle();
  ElecIsoPT_->Write();
  SaveEfficiency(ElecIsoPT_);
  TEfficiency* tempTeff =  ratioCalculatorTEff(ElecIsoPT_,ElecIsoPTFail_);
  tempTeff->SetName("ElecIsoPTTEff");
  tempTeff->Write();
  
  ElecIsoActivity_ = ratioCalculator(ElecIsoActivity_,ElecIsoActivityFail_);   
  ElecIsoActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso; Activity [GeV]");
  ElecIsoActivity_->SetMarkerSize(2.0);
  ElecIsoActivity_->UseCurrentStyle();
  ElecIsoActivity_->Write();
  SaveEfficiency(ElecIsoActivity_);
  
  
  ElecMTWPT_ = ratioCalculator(ElecMTWPT_,ElecMTWPTFail_);   
  ElecMTWPT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e m_{T}(w); e p_{T} [GeV]");
  ElecMTWPT_->SetMarkerSize(2.0);
  ElecMTWPT_->UseCurrentStyle();
  ElecMTWPT_->Write();
  SaveEfficiency(ElecMTWPT_);
  
  ElecMTWActivity_ = ratioCalculator(ElecMTWActivity_,ElecMTWActivityFail_);   
  ElecMTWActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e m_{T}(w); Activity [GeV]");
  ElecMTWActivity_->SetMarkerSize(2.0);
  ElecMTWActivity_->UseCurrentStyle();
  ElecMTWActivity_->Write();
  SaveEfficiency(ElecMTWActivity_);
  
  ElecIsoPTActivity_ = ratioCalculator(ElecIsoPTActivity_,ElecIsoPTActivityFail_);   
  ElecIsoPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e Iso; e p_{T}[GeV]; Activity [GeV]");
  ElecIsoPTActivity_->SetMarkerSize(2.0);
  ElecIsoPTActivity_->UseCurrentStyle();
  ElecIsoPTActivity_->Write();
  SaveEfficiency(ElecIsoPTActivity_);
  
  // Aug 18 2015 added start
  DiLepBTag_ = ratioCalculator(DiLepBTag_,DiLepBTagFail_);   
  DiLepBTag_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV di-lep eff.; B_{Tags}");
  DiLepBTag_->SetMarkerSize(2.0);
  DiLepBTag_->UseCurrentStyle();
  DiLepBTag_->Write();
  SaveEfficiency(DiLepBTag_);
  
  DiLepNJets_ = ratioCalculator(DiLepNJets_,DiLepNJetsFail_);   
  DiLepNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV di-lep eff.; N_{Jets}");
  DiLepNJets_->SetMarkerSize(2.0);
  DiLepNJets_->UseCurrentStyle();
  DiLepNJets_->Write();
  SaveEfficiency(DiLepNJets_);
  
  DiLepHT_ = ratioCalculator(DiLepHT_,DiLepHTFail_);   
  DiLepHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV di-lep eff.; H_{T} [GeV]");
  DiLepHT_->SetMarkerSize(2.0);
  DiLepHT_->UseCurrentStyle();
  DiLepHT_->Write();
  SaveEfficiency(DiLepHT_);
  
  DiLepMHT_ = ratioCalculator(DiLepMHT_,DiLepMHTFail_);   
  DiLepMHT_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV di-lep eff.; #slash{H}_{T} [GeV]");
  DiLepMHT_->SetMarkerSize(2.0);
  DiLepMHT_->UseCurrentStyle();
  DiLepMHT_->Write();
  SaveEfficiency(DiLepMHT_);
  // Aug 18 2015 added end
  
  //1D
  ExpectationReductionIsoTrackBTagEff = ratioCalculator(ExpectationReductionIsoTrackBTagEff,ExpectationReductionIsoTrackBTagEffFail);   
  ExpectationReductionIsoTrackBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; B_{Tags}");
  ExpectationReductionIsoTrackBTagEff->SetMarkerSize(2.0);
  ExpectationReductionIsoTrackBTagEff->UseCurrentStyle();
  ExpectationReductionIsoTrackBTagEff->Write();
  SaveEfficiency(ExpectationReductionIsoTrackBTagEff);
  
  ExpectationReductionIsoTrackNJetsEff = ratioCalculator(ExpectationReductionIsoTrackNJetsEff,ExpectationReductionIsoTrackNJetsEffFail);   
  ExpectationReductionIsoTrackNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; N_{Jets}");
  ExpectationReductionIsoTrackNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionIsoTrackNJetsEff->UseCurrentStyle();
  ExpectationReductionIsoTrackNJetsEff->Write();
  SaveEfficiency(ExpectationReductionIsoTrackNJetsEff);
  
  ExpectationReductionIsoTrackHTEff = ratioCalculator(ExpectationReductionIsoTrackHTEff,ExpectationReductionIsoTrackHTEffFail);   
  ExpectationReductionIsoTrackHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; H_{T}");
  ExpectationReductionIsoTrackHTEff->SetMarkerSize(2.0);
  ExpectationReductionIsoTrackHTEff->UseCurrentStyle();
  ExpectationReductionIsoTrackHTEff->Write();
  SaveEfficiency(ExpectationReductionIsoTrackHTEff);
  
  ExpectationReductionIsoTrackMHTEff = ratioCalculator(ExpectationReductionIsoTrackMHTEff,ExpectationReductionIsoTrackMHTEffFail);   
  ExpectationReductionIsoTrackMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; #slash{H}_{T} [GeV]");
  ExpectationReductionIsoTrackMHTEff->SetMarkerSize(2.0);
  ExpectationReductionIsoTrackMHTEff->UseCurrentStyle();
  ExpectationReductionIsoTrackMHTEff->Write();
  SaveEfficiency(ExpectationReductionIsoTrackMHTEff);
  
  ExpectationReductionIsoTrackPTEff = ratioCalculator(ExpectationReductionIsoTrackPTEff,ExpectationReductionIsoTrackPTEffFail);   
  ExpectationReductionIsoTrackPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; p_{T} [GeV]");
  ExpectationReductionIsoTrackPTEff->SetMarkerSize(2.0);
  ExpectationReductionIsoTrackPTEff->UseCurrentStyle();
  ExpectationReductionIsoTrackPTEff->Write();
  SaveEfficiency(ExpectationReductionIsoTrackPTEff);
  
  ExpectationReductionIsoTrackActivityEff = ratioCalculator(ExpectationReductionIsoTrackActivityEff,ExpectationReductionIsoTrackActivityEffFail);   
  ExpectationReductionIsoTrackActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; Activity [GeV]");
  ExpectationReductionIsoTrackActivityEff->SetMarkerSize(2.0);
  ExpectationReductionIsoTrackActivityEff->UseCurrentStyle();
  ExpectationReductionIsoTrackActivityEff->Write();
  SaveEfficiency(ExpectationReductionIsoTrackActivityEff);
  
  //2D
  IsoTrackReductionHTNJets_ = ratioCalculator(IsoTrackReductionHTNJets_,IsoTrackReductionHTNJetsFail_);   
  IsoTrackReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; H_{T} [GeV]; N_{Jets}");
  IsoTrackReductionHTNJets_->SetMarkerSize(2.0);
  IsoTrackReductionHTNJets_->UseCurrentStyle();
  IsoTrackReductionHTNJets_->Write();
  SaveEfficiency(IsoTrackReductionHTNJets_);
  
  IsoTrackReductionMHTNJets_ = ratioCalculator(IsoTrackReductionMHTNJets_,IsoTrackReductionMHTNJetsFail_);   
  IsoTrackReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; #slash{H}_{T} [GeV]; N_{Jets}");
  IsoTrackReductionMHTNJets_->SetMarkerSize(2.0);
  IsoTrackReductionMHTNJets_->UseCurrentStyle();
  IsoTrackReductionMHTNJets_->Write();
  SaveEfficiency(IsoTrackReductionMHTNJets_);
  
  
  IsoTrackReductionBTagNJets_ = ratioCalculator(IsoTrackReductionBTagNJets_,IsoTrackReductionBTagNJetsFail_);   
  IsoTrackReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; B_{Tags}; N_{Jets}");
  IsoTrackReductionBTagNJets_->SetMarkerSize(2.0);
  IsoTrackReductionBTagNJets_->UseCurrentStyle();
  IsoTrackReductionBTagNJets_->Write();
  SaveEfficiency(IsoTrackReductionBTagNJets_);
  
  IsoTrackReductionPTActivity_ = ratioCalculator(IsoTrackReductionPTActivity_,IsoTrackReductionPTActivityFail_);   
  IsoTrackReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV iso track expec. reduction; p_{T} [GeV]; Activity [GeV]");
  IsoTrackReductionPTActivity_->SetMarkerSize(2.0);
  IsoTrackReductionPTActivity_->UseCurrentStyle();
  IsoTrackReductionPTActivity_->Write();
  SaveEfficiency(IsoTrackReductionPTActivity_);
  // ************************************************************************************************************* 22 June 2015 ****************************************************
  
  // mu iso tracks
  //1D
  //1D
  ExpectationReductionMuIsoTrackBTagEff = ratioCalculatorSimple(ExpectationReductionMuIsoTrackBTagEff,ExpectationReductionMuIsoTrackBTagEffFail);   
  ExpectationReductionMuIsoTrackBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; B_{Tags}");
  ExpectationReductionMuIsoTrackBTagEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackBTagEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackBTagEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackBTagEff);
  
  ExpectationReductionMuIsoTrackNJetsEff = ratioCalculatorSimple(ExpectationReductionMuIsoTrackNJetsEff,ExpectationReductionMuIsoTrackNJetsEffFail);   
  ExpectationReductionMuIsoTrackNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; N_{Jets}");
  ExpectationReductionMuIsoTrackNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackNJetsEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackNJetsEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackNJetsEff);
  
  ExpectationReductionMuIsoTrackHTEff = ratioCalculatorSimple(ExpectationReductionMuIsoTrackHTEff,ExpectationReductionMuIsoTrackHTEffFail);   
  ExpectationReductionMuIsoTrackHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; H_{T}");
  ExpectationReductionMuIsoTrackHTEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackHTEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackHTEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackHTEff);
  
  ExpectationReductionMuIsoTrackMHTEff = ratioCalculatorSimple(ExpectationReductionMuIsoTrackMHTEff,ExpectationReductionMuIsoTrackMHTEffFail);   
  ExpectationReductionMuIsoTrackMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; #slash{H}_{T} [GeV]");
  ExpectationReductionMuIsoTrackMHTEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackMHTEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackMHTEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackMHTEff);
  
  ExpectationReductionMuIsoTrackPTEff = ratioCalculatorSimple(ExpectationReductionMuIsoTrackPTEff,ExpectationReductionMuIsoTrackPTEffFail);   
  ExpectationReductionMuIsoTrackPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; p_{T} [GeV]");
  ExpectationReductionMuIsoTrackPTEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackPTEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackPTEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackPTEff);
  
  ExpectationReductionMuIsoTrackActivityEff = ratioCalculatorSimple(ExpectationReductionMuIsoTrackActivityEff,ExpectationReductionMuIsoTrackActivityEffFail);   
  ExpectationReductionMuIsoTrackActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; Activity [GeV]");
  ExpectationReductionMuIsoTrackActivityEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackActivityEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackActivityEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackActivityEff);
  
  //2D
  MuIsoTrackReductionHTNJets_ = ratioCalculatorSimple(MuIsoTrackReductionHTNJets_,MuIsoTrackReductionHTNJetsFail_);   
  MuIsoTrackReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; H_{T} [GeV]; N_{Jets}");
  MuIsoTrackReductionHTNJets_->SetMarkerSize(2.0);
  MuIsoTrackReductionHTNJets_->UseCurrentStyle();
  MuIsoTrackReductionHTNJets_->Write();
  SaveEfficiency(MuIsoTrackReductionHTNJets_);
  
  MuIsoTrackReductionMHTNJets_ = ratioCalculatorSimple(MuIsoTrackReductionMHTNJets_,MuIsoTrackReductionMHTNJetsFail_);   
  MuIsoTrackReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; #slash{H}_{T} [GeV]; N_{Jets}");
  MuIsoTrackReductionMHTNJets_->SetMarkerSize(2.0);
  MuIsoTrackReductionMHTNJets_->UseCurrentStyle();
  MuIsoTrackReductionMHTNJets_->Write();
  SaveEfficiency(MuIsoTrackReductionMHTNJets_);
  
  
  MuIsoTrackReductionBTagNJets_ = ratioCalculatorSimple(MuIsoTrackReductionBTagNJets_,MuIsoTrackReductionBTagNJetsFail_);   
  MuIsoTrackReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; B_{Tags}; N_{Jets}");
  MuIsoTrackReductionBTagNJets_->SetMarkerSize(2.0);
  MuIsoTrackReductionBTagNJets_->UseCurrentStyle();
  MuIsoTrackReductionBTagNJets_->Write();
  SaveEfficiency(MuIsoTrackReductionBTagNJets_);
  
  MuIsoTrackReductionPTActivity_ = ratioCalculatorSimple(MuIsoTrackReductionPTActivity_,MuIsoTrackReductionPTActivityFail_);   
  MuIsoTrackReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction; p_{T} [GeV]; Activity [GeV]");
  MuIsoTrackReductionPTActivity_->SetMarkerSize(2.0);
  MuIsoTrackReductionPTActivity_->UseCurrentStyle();
  MuIsoTrackReductionPTActivity_->Write();
  SaveEfficiency(MuIsoTrackReductionPTActivity_);
  
  // elec iso tracks
  //1D
  ExpectationReductionElecIsoTrackBTagEff = ratioCalculatorSimple(ExpectationReductionElecIsoTrackBTagEff,ExpectationReductionElecIsoTrackBTagEffFail);   
  ExpectationReductionElecIsoTrackBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; B_{Tags}");
  ExpectationReductionElecIsoTrackBTagEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackBTagEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackBTagEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackBTagEff);
  
  ExpectationReductionElecIsoTrackNJetsEff = ratioCalculatorSimple(ExpectationReductionElecIsoTrackNJetsEff,ExpectationReductionElecIsoTrackNJetsEffFail);   
  ExpectationReductionElecIsoTrackNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; N_{Jets}");
  ExpectationReductionElecIsoTrackNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackNJetsEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackNJetsEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackNJetsEff);
  
  ExpectationReductionElecIsoTrackHTEff = ratioCalculatorSimple(ExpectationReductionElecIsoTrackHTEff,ExpectationReductionElecIsoTrackHTEffFail);   
  ExpectationReductionElecIsoTrackHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; H_{T}");
  ExpectationReductionElecIsoTrackHTEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackHTEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackHTEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackHTEff);
  
  ExpectationReductionElecIsoTrackMHTEff = ratioCalculatorSimple(ExpectationReductionElecIsoTrackMHTEff,ExpectationReductionElecIsoTrackMHTEffFail);   
  ExpectationReductionElecIsoTrackMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; #slash{H}_{T} [GeV]");
  ExpectationReductionElecIsoTrackMHTEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackMHTEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackMHTEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackMHTEff);
  
  ExpectationReductionElecIsoTrackPTEff = ratioCalculatorSimple(ExpectationReductionElecIsoTrackPTEff,ExpectationReductionElecIsoTrackPTEffFail);   
  ExpectationReductionElecIsoTrackPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; p_{T} [GeV]");
  ExpectationReductionElecIsoTrackPTEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackPTEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackPTEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackPTEff);
  
  ExpectationReductionElecIsoTrackActivityEff = ratioCalculatorSimple(ExpectationReductionElecIsoTrackActivityEff,ExpectationReductionElecIsoTrackActivityEffFail);   
  ExpectationReductionElecIsoTrackActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; Activity [GeV]");
  ExpectationReductionElecIsoTrackActivityEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackActivityEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackActivityEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackActivityEff);
  
  //2D
  ElecIsoTrackReductionHTNJets_ = ratioCalculatorSimple(ElecIsoTrackReductionHTNJets_,ElecIsoTrackReductionHTNJetsFail_);   
  ElecIsoTrackReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; H_{T} [GeV]; N_{Jets}");
  ElecIsoTrackReductionHTNJets_->SetMarkerSize(2.0);
  ElecIsoTrackReductionHTNJets_->UseCurrentStyle();
  ElecIsoTrackReductionHTNJets_->Write();
  SaveEfficiency(ElecIsoTrackReductionHTNJets_);
  
  ElecIsoTrackReductionMHTNJets_ = ratioCalculatorSimple(ElecIsoTrackReductionMHTNJets_,ElecIsoTrackReductionMHTNJetsFail_);   
  ElecIsoTrackReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; #slash{H}_{T} [GeV]; N_{Jets}");
  ElecIsoTrackReductionMHTNJets_->SetMarkerSize(2.0);
  ElecIsoTrackReductionMHTNJets_->UseCurrentStyle();
  ElecIsoTrackReductionMHTNJets_->Write();
  SaveEfficiency(ElecIsoTrackReductionMHTNJets_);
  
  
  ElecIsoTrackReductionBTagNJets_ = ratioCalculatorSimple(ElecIsoTrackReductionBTagNJets_,ElecIsoTrackReductionBTagNJetsFail_);   
  ElecIsoTrackReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; B_{Tags}; N_{Jets}");
  ElecIsoTrackReductionBTagNJets_->SetMarkerSize(2.0);
  ElecIsoTrackReductionBTagNJets_->UseCurrentStyle();
  ElecIsoTrackReductionBTagNJets_->Write();
  SaveEfficiency(ElecIsoTrackReductionBTagNJets_);
  
  ElecIsoTrackReductionPTActivity_ = ratioCalculatorSimple(ElecIsoTrackReductionPTActivity_,ElecIsoTrackReductionPTActivityFail_);   
  ElecIsoTrackReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction; p_{T} [GeV]; Activity [GeV]");
  ElecIsoTrackReductionPTActivity_->SetMarkerSize(2.0);
  ElecIsoTrackReductionPTActivity_->UseCurrentStyle();
  ElecIsoTrackReductionPTActivity_->Write();
  SaveEfficiency(ElecIsoTrackReductionPTActivity_);
  
  
  // pion iso tracks
  //1D
  ExpectationReductionPionIsoTrackBTagEff = ratioCalculatorSimple(ExpectationReductionPionIsoTrackBTagEff,ExpectationReductionPionIsoTrackBTagEffFail);   
  ExpectationReductionPionIsoTrackBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; B_{Tags}");
  ExpectationReductionPionIsoTrackBTagEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackBTagEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackBTagEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackBTagEff);
  
  ExpectationReductionPionIsoTrackNJetsEff = ratioCalculatorSimple(ExpectationReductionPionIsoTrackNJetsEff,ExpectationReductionPionIsoTrackNJetsEffFail);   
  ExpectationReductionPionIsoTrackNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; N_{Jets}");
  ExpectationReductionPionIsoTrackNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackNJetsEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackNJetsEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackNJetsEff);
  
  ExpectationReductionPionIsoTrackHTEff = ratioCalculatorSimple(ExpectationReductionPionIsoTrackHTEff,ExpectationReductionPionIsoTrackHTEffFail);   
  ExpectationReductionPionIsoTrackHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; H_{T}");
  ExpectationReductionPionIsoTrackHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackHTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackHTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackHTEff);
  
  ExpectationReductionPionIsoTrackMHTEff = ratioCalculatorSimple(ExpectationReductionPionIsoTrackMHTEff,ExpectationReductionPionIsoTrackMHTEffFail);   
  ExpectationReductionPionIsoTrackMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; #slash{H}_{T} [GeV]");
  ExpectationReductionPionIsoTrackMHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackMHTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackMHTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackMHTEff);
  
  ExpectationReductionPionIsoTrackPTEff = ratioCalculatorSimple(ExpectationReductionPionIsoTrackPTEff,ExpectationReductionPionIsoTrackPTEffFail);   
  ExpectationReductionPionIsoTrackPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; p_{T} [GeV]");
  ExpectationReductionPionIsoTrackPTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackPTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackPTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackPTEff);
  
  ExpectationReductionPionIsoTrackActivityEff = ratioCalculatorSimple(ExpectationReductionPionIsoTrackActivityEff,ExpectationReductionPionIsoTrackActivityEffFail);   
  ExpectationReductionPionIsoTrackActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; Activity [GeV]");
  ExpectationReductionPionIsoTrackActivityEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackActivityEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackActivityEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackActivityEff);
  
  //2D
  PionIsoTrackReductionHTNJets_ = ratioCalculatorSimple(PionIsoTrackReductionHTNJets_,PionIsoTrackReductionHTNJetsFail_);   
  PionIsoTrackReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; H_{T} [GeV]; N_{Jets}");
  PionIsoTrackReductionHTNJets_->SetMarkerSize(2.0);
  PionIsoTrackReductionHTNJets_->UseCurrentStyle();
  PionIsoTrackReductionHTNJets_->Write();
  SaveEfficiency(PionIsoTrackReductionHTNJets_);
  
  PionIsoTrackReductionMHTNJets_ = ratioCalculatorSimple(PionIsoTrackReductionMHTNJets_,PionIsoTrackReductionMHTNJetsFail_);   
  PionIsoTrackReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; #slash{H}_{T} [GeV]; N_{Jets}");
  PionIsoTrackReductionMHTNJets_->SetMarkerSize(2.0);
  PionIsoTrackReductionMHTNJets_->UseCurrentStyle();
  PionIsoTrackReductionMHTNJets_->Write();
  SaveEfficiency(PionIsoTrackReductionMHTNJets_);
  
  //      PionIsoTrackReductionBTagNJetsFail_->Add(PionIsoTrackReductionBTagNJets_);
  PionIsoTrackReductionBTagNJets_ = ratioCalculatorSimple(PionIsoTrackReductionBTagNJets_,PionIsoTrackReductionBTagNJetsFail_);   
  PionIsoTrackReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; B_{Tags}; N_{Jets}");
  PionIsoTrackReductionBTagNJets_->SetMarkerSize(2.0);
  PionIsoTrackReductionBTagNJets_->UseCurrentStyle();
  PionIsoTrackReductionBTagNJets_->Write();
  SaveEfficiency(PionIsoTrackReductionBTagNJets_);
  
  PionIsoTrackReductionPTActivity_ = ratioCalculatorSimple(PionIsoTrackReductionPTActivity_,PionIsoTrackReductionPTActivityFail_);   
  PionIsoTrackReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction; p_{T} [GeV]; Activity [GeV]");
  PionIsoTrackReductionPTActivity_->SetMarkerSize(2.0);
  PionIsoTrackReductionPTActivity_->UseCurrentStyle();
  PionIsoTrackReductionPTActivity_->Write();
  SaveEfficiency(PionIsoTrackReductionPTActivity_);
  
  
  // separated for iso and recoacc combined for the tracks
  /////////////////////////////////////////////////////////////////////////////////////////////////
  
  // iso
  
  // mu iso tracks
  //1D
  //1D
  ExpectationReductionMuIsoTrackGenMuBTagEff = ratioCalculator(ExpectationReductionMuIsoTrackGenMuBTagEff,ExpectationReductionMuIsoTrackGenMuBTagEffFail);   
  ExpectationReductionMuIsoTrackGenMuBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; B_{Tags}");
  ExpectationReductionMuIsoTrackGenMuBTagEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackGenMuBTagEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackGenMuBTagEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackGenMuBTagEff);
  
  ExpectationReductionMuIsoTrackGenMuNJetsEff = ratioCalculator(ExpectationReductionMuIsoTrackGenMuNJetsEff,ExpectationReductionMuIsoTrackGenMuNJetsEffFail);   
  ExpectationReductionMuIsoTrackGenMuNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; N_{Jets}");
  ExpectationReductionMuIsoTrackGenMuNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackGenMuNJetsEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackGenMuNJetsEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackGenMuNJetsEff);
  
  ExpectationReductionMuIsoTrackGenMuHTEff = ratioCalculator(ExpectationReductionMuIsoTrackGenMuHTEff,ExpectationReductionMuIsoTrackGenMuHTEffFail);   
  ExpectationReductionMuIsoTrackGenMuHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; H_{T}");
  ExpectationReductionMuIsoTrackGenMuHTEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackGenMuHTEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackGenMuHTEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackGenMuHTEff);
  
  ExpectationReductionMuIsoTrackGenMuMHTEff = ratioCalculator(ExpectationReductionMuIsoTrackGenMuMHTEff,ExpectationReductionMuIsoTrackGenMuMHTEffFail);   
  ExpectationReductionMuIsoTrackGenMuMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; #slash{H}_{T} [GeV]");
  ExpectationReductionMuIsoTrackGenMuMHTEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackGenMuMHTEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackGenMuMHTEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackGenMuMHTEff);
  
  ExpectationReductionMuIsoTrackGenMuPTEff = ratioCalculator(ExpectationReductionMuIsoTrackGenMuPTEff,ExpectationReductionMuIsoTrackGenMuPTEffFail);   
  ExpectationReductionMuIsoTrackGenMuPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; p_{T} [GeV]");
  ExpectationReductionMuIsoTrackGenMuPTEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackGenMuPTEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackGenMuPTEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackGenMuPTEff);
  
  ExpectationReductionMuIsoTrackGenMuActivityEff = ratioCalculator(ExpectationReductionMuIsoTrackGenMuActivityEff,ExpectationReductionMuIsoTrackGenMuActivityEffFail);   
  ExpectationReductionMuIsoTrackGenMuActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; Activity [GeV]");
  ExpectationReductionMuIsoTrackGenMuActivityEff->SetMarkerSize(2.0);
  ExpectationReductionMuIsoTrackGenMuActivityEff->UseCurrentStyle();
  ExpectationReductionMuIsoTrackGenMuActivityEff->Write();
  SaveEfficiency(ExpectationReductionMuIsoTrackGenMuActivityEff);
  
  //2D
  MuIsoTrackGenMuReductionHTNJets_ = ratioCalculator(MuIsoTrackGenMuReductionHTNJets_,MuIsoTrackGenMuReductionHTNJetsFail_);   
  MuIsoTrackGenMuReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; H_{T} [GeV]; N_{Jets}");
  MuIsoTrackGenMuReductionHTNJets_->SetMarkerSize(2.0);
  MuIsoTrackGenMuReductionHTNJets_->UseCurrentStyle();
  MuIsoTrackGenMuReductionHTNJets_->Write();
  SaveEfficiency(MuIsoTrackGenMuReductionHTNJets_);
  
  MuIsoTrackGenMuReductionMHTNJets_ = ratioCalculator(MuIsoTrackGenMuReductionMHTNJets_,MuIsoTrackGenMuReductionMHTNJetsFail_);   
  MuIsoTrackGenMuReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; #slash{H}_{T} [GeV]; N_{Jets}");
  MuIsoTrackGenMuReductionMHTNJets_->SetMarkerSize(2.0);
  MuIsoTrackGenMuReductionMHTNJets_->UseCurrentStyle();
  MuIsoTrackGenMuReductionMHTNJets_->Write();
  SaveEfficiency(MuIsoTrackGenMuReductionMHTNJets_);
  
  
  MuIsoTrackGenMuReductionBTagNJets_ = ratioCalculator(MuIsoTrackGenMuReductionBTagNJets_,MuIsoTrackGenMuReductionBTagNJetsFail_);   
  MuIsoTrackGenMuReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; B_{Tags}; N_{Jets}");
  MuIsoTrackGenMuReductionBTagNJets_->SetMarkerSize(2.0);
  MuIsoTrackGenMuReductionBTagNJets_->UseCurrentStyle();
  MuIsoTrackGenMuReductionBTagNJets_->Write();
  SaveEfficiency(MuIsoTrackGenMuReductionBTagNJets_);
  
  MuIsoTrackGenMuReductionPTActivity_ = ratioCalculator(MuIsoTrackGenMuReductionPTActivity_,MuIsoTrackGenMuReductionPTActivityFail_);   
  MuIsoTrackGenMuReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu iso track expec. reduction iso only; p_{T} [GeV]; Activity [GeV]");
  MuIsoTrackGenMuReductionPTActivity_->SetMarkerSize(2.0);
  MuIsoTrackGenMuReductionPTActivity_->UseCurrentStyle();
  MuIsoTrackGenMuReductionPTActivity_->Write();
  SaveEfficiency(MuIsoTrackGenMuReductionPTActivity_);
  
  
  
  
  //1D
  ExpectationReductionPionIsoTrackGenMuBTagEff = ratioCalculator(ExpectationReductionPionIsoTrackGenMuBTagEff,ExpectationReductionPionIsoTrackGenMuBTagEffFail);   
  ExpectationReductionPionIsoTrackGenMuBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); B_{Tags}");
  ExpectationReductionPionIsoTrackGenMuBTagEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenMuBTagEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenMuBTagEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenMuBTagEff);
  
  ExpectationReductionPionIsoTrackGenMuNJetsEff = ratioCalculator(ExpectationReductionPionIsoTrackGenMuNJetsEff,ExpectationReductionPionIsoTrackGenMuNJetsEffFail);   
  ExpectationReductionPionIsoTrackGenMuNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); N_{Jets}");
  ExpectationReductionPionIsoTrackGenMuNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenMuNJetsEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenMuNJetsEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenMuNJetsEff);
  
  ExpectationReductionPionIsoTrackGenMuHTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenMuHTEff,ExpectationReductionPionIsoTrackGenMuHTEffFail);   
  ExpectationReductionPionIsoTrackGenMuHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); H_{T}");
  ExpectationReductionPionIsoTrackGenMuHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenMuHTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenMuHTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenMuHTEff);
  
  ExpectationReductionPionIsoTrackGenMuMHTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenMuMHTEff,ExpectationReductionPionIsoTrackGenMuMHTEffFail);   
  ExpectationReductionPionIsoTrackGenMuMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); #slash{H}_{T} [GeV]");
  ExpectationReductionPionIsoTrackGenMuMHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenMuMHTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenMuMHTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenMuMHTEff);
  
  ExpectationReductionPionIsoTrackGenMuPTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenMuPTEff,ExpectationReductionPionIsoTrackGenMuPTEffFail);   
  ExpectationReductionPionIsoTrackGenMuPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); p_{T} [GeV]");
  ExpectationReductionPionIsoTrackGenMuPTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenMuPTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenMuPTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenMuPTEff);
  
  ExpectationReductionPionIsoTrackGenMuActivityEff = ratioCalculator(ExpectationReductionPionIsoTrackGenMuActivityEff,ExpectationReductionPionIsoTrackGenMuActivityEffFail);   
  ExpectationReductionPionIsoTrackGenMuActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); Activity [GeV]");
  ExpectationReductionPionIsoTrackGenMuActivityEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenMuActivityEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenMuActivityEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenMuActivityEff);
  
  //2D
  PionIsoTrackGenMuReductionHTNJets_ = ratioCalculator(PionIsoTrackGenMuReductionHTNJets_,PionIsoTrackGenMuReductionHTNJetsFail_);   
  PionIsoTrackGenMuReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); H_{T} [GeV]; N_{Jets}");
  PionIsoTrackGenMuReductionHTNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenMuReductionHTNJets_->UseCurrentStyle();
  PionIsoTrackGenMuReductionHTNJets_->Write();
  SaveEfficiency(PionIsoTrackGenMuReductionHTNJets_);
  
  PionIsoTrackGenMuReductionMHTNJets_ = ratioCalculator(PionIsoTrackGenMuReductionMHTNJets_,PionIsoTrackGenMuReductionMHTNJetsFail_);   
  PionIsoTrackGenMuReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); #slash{H}_{T} [GeV]; N_{Jets}");
  PionIsoTrackGenMuReductionMHTNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenMuReductionMHTNJets_->UseCurrentStyle();
  PionIsoTrackGenMuReductionMHTNJets_->Write();
  SaveEfficiency(PionIsoTrackGenMuReductionMHTNJets_);
  
  
  PionIsoTrackGenMuReductionBTagNJets_ = ratioCalculator(PionIsoTrackGenMuReductionBTagNJets_,PionIsoTrackGenMuReductionBTagNJetsFail_);   
  PionIsoTrackGenMuReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); B_{Tags}; N_{Jets}");
  PionIsoTrackGenMuReductionBTagNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenMuReductionBTagNJets_->UseCurrentStyle();
  PionIsoTrackGenMuReductionBTagNJets_->Write();
  SaveEfficiency(PionIsoTrackGenMuReductionBTagNJets_);
  
  PionIsoTrackGenMuReductionPTActivity_ = ratioCalculator(PionIsoTrackGenMuReductionPTActivity_,PionIsoTrackGenMuReductionPTActivityFail_);   
  PionIsoTrackGenMuReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genMu); p_{T} [GeV]; Activity [GeV]");
  PionIsoTrackGenMuReductionPTActivity_->SetMarkerSize(2.0);
  PionIsoTrackGenMuReductionPTActivity_->UseCurrentStyle();
  PionIsoTrackGenMuReductionPTActivity_->Write();
  SaveEfficiency(PionIsoTrackGenMuReductionPTActivity_);
  
  
  
  // elec iso track
  
  
  // elec iso tracks
  //1D
  //1D
  ExpectationReductionElecIsoTrackGenElecBTagEff = ratioCalculator(ExpectationReductionElecIsoTrackGenElecBTagEff,ExpectationReductionElecIsoTrackGenElecBTagEffFail);   
  ExpectationReductionElecIsoTrackGenElecBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; B_{Tags}");
  ExpectationReductionElecIsoTrackGenElecBTagEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackGenElecBTagEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackGenElecBTagEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackGenElecBTagEff);
  
  ExpectationReductionElecIsoTrackGenElecNJetsEff = ratioCalculator(ExpectationReductionElecIsoTrackGenElecNJetsEff,ExpectationReductionElecIsoTrackGenElecNJetsEffFail);   
  ExpectationReductionElecIsoTrackGenElecNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; N_{Jets}");
  ExpectationReductionElecIsoTrackGenElecNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackGenElecNJetsEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackGenElecNJetsEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackGenElecNJetsEff);
  
  ExpectationReductionElecIsoTrackGenElecHTEff = ratioCalculator(ExpectationReductionElecIsoTrackGenElecHTEff,ExpectationReductionElecIsoTrackGenElecHTEffFail);   
  ExpectationReductionElecIsoTrackGenElecHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; H_{T}");
  ExpectationReductionElecIsoTrackGenElecHTEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackGenElecHTEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackGenElecHTEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackGenElecHTEff);
  
  ExpectationReductionElecIsoTrackGenElecMHTEff = ratioCalculator(ExpectationReductionElecIsoTrackGenElecMHTEff,ExpectationReductionElecIsoTrackGenElecMHTEffFail);   
  ExpectationReductionElecIsoTrackGenElecMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; #slash{H}_{T} [GeV]");
  ExpectationReductionElecIsoTrackGenElecMHTEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackGenElecMHTEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackGenElecMHTEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackGenElecMHTEff);
  
  ExpectationReductionElecIsoTrackGenElecPTEff = ratioCalculator(ExpectationReductionElecIsoTrackGenElecPTEff,ExpectationReductionElecIsoTrackGenElecPTEffFail);   
  ExpectationReductionElecIsoTrackGenElecPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; p_{T} [GeV]");
  ExpectationReductionElecIsoTrackGenElecPTEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackGenElecPTEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackGenElecPTEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackGenElecPTEff);
  
  ExpectationReductionElecIsoTrackGenElecActivityEff = ratioCalculator(ExpectationReductionElecIsoTrackGenElecActivityEff,ExpectationReductionElecIsoTrackGenElecActivityEffFail);   
  ExpectationReductionElecIsoTrackGenElecActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; Activity [GeV]");
  ExpectationReductionElecIsoTrackGenElecActivityEff->SetMarkerSize(2.0);
  ExpectationReductionElecIsoTrackGenElecActivityEff->UseCurrentStyle();
  ExpectationReductionElecIsoTrackGenElecActivityEff->Write();
  SaveEfficiency(ExpectationReductionElecIsoTrackGenElecActivityEff);
  
  //2D
  ElecIsoTrackGenElecReductionHTNJets_ = ratioCalculator(ElecIsoTrackGenElecReductionHTNJets_,ElecIsoTrackGenElecReductionHTNJetsFail_);   
  ElecIsoTrackGenElecReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; H_{T} [GeV]; N_{Jets}");
  ElecIsoTrackGenElecReductionHTNJets_->SetMarkerSize(2.0);
  ElecIsoTrackGenElecReductionHTNJets_->UseCurrentStyle();
  ElecIsoTrackGenElecReductionHTNJets_->Write();
  SaveEfficiency(ElecIsoTrackGenElecReductionHTNJets_);
  
  ElecIsoTrackGenElecReductionMHTNJets_ = ratioCalculator(ElecIsoTrackGenElecReductionMHTNJets_,ElecIsoTrackGenElecReductionMHTNJetsFail_);   
  ElecIsoTrackGenElecReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; #slash{H}_{T} [GeV]; N_{Jets}");
  ElecIsoTrackGenElecReductionMHTNJets_->SetMarkerSize(2.0);
  ElecIsoTrackGenElecReductionMHTNJets_->UseCurrentStyle();
  ElecIsoTrackGenElecReductionMHTNJets_->Write();
  SaveEfficiency(ElecIsoTrackGenElecReductionMHTNJets_);
  
  
  ElecIsoTrackGenElecReductionBTagNJets_ = ratioCalculator(ElecIsoTrackGenElecReductionBTagNJets_,ElecIsoTrackGenElecReductionBTagNJetsFail_);   
  ElecIsoTrackGenElecReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; B_{Tags}; N_{Jets}");
  ElecIsoTrackGenElecReductionBTagNJets_->SetMarkerSize(2.0);
  ElecIsoTrackGenElecReductionBTagNJets_->UseCurrentStyle();
  ElecIsoTrackGenElecReductionBTagNJets_->Write();
  SaveEfficiency(ElecIsoTrackGenElecReductionBTagNJets_);
  
  ElecIsoTrackGenElecReductionPTActivity_ = ratioCalculator(ElecIsoTrackGenElecReductionPTActivity_,ElecIsoTrackGenElecReductionPTActivityFail_);   
  ElecIsoTrackGenElecReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e iso track expec. reduction iso only; p_{T} [GeV]; Activity [GeV]");
  ElecIsoTrackGenElecReductionPTActivity_->SetMarkerSize(2.0);
  ElecIsoTrackGenElecReductionPTActivity_->UseCurrentStyle();
  ElecIsoTrackGenElecReductionPTActivity_->Write();
  SaveEfficiency(ElecIsoTrackGenElecReductionPTActivity_);
  
  
  
  
  //1D
  ExpectationReductionPionIsoTrackGenElecBTagEff = ratioCalculator(ExpectationReductionPionIsoTrackGenElecBTagEff,ExpectationReductionPionIsoTrackGenElecBTagEffFail);   
  ExpectationReductionPionIsoTrackGenElecBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); B_{Tags}");
  ExpectationReductionPionIsoTrackGenElecBTagEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenElecBTagEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenElecBTagEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenElecBTagEff);
  
  ExpectationReductionPionIsoTrackGenElecNJetsEff = ratioCalculator(ExpectationReductionPionIsoTrackGenElecNJetsEff,ExpectationReductionPionIsoTrackGenElecNJetsEffFail);   
  ExpectationReductionPionIsoTrackGenElecNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); N_{Jets}");
  ExpectationReductionPionIsoTrackGenElecNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenElecNJetsEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenElecNJetsEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenElecNJetsEff);
  
  ExpectationReductionPionIsoTrackGenElecHTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenElecHTEff,ExpectationReductionPionIsoTrackGenElecHTEffFail);   
  ExpectationReductionPionIsoTrackGenElecHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); H_{T}");
  ExpectationReductionPionIsoTrackGenElecHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenElecHTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenElecHTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenElecHTEff);
  
  ExpectationReductionPionIsoTrackGenElecMHTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenElecMHTEff,ExpectationReductionPionIsoTrackGenElecMHTEffFail);   
  ExpectationReductionPionIsoTrackGenElecMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); #slash{H}_{T} [GeV]");
  ExpectationReductionPionIsoTrackGenElecMHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenElecMHTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenElecMHTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenElecMHTEff);
  
  ExpectationReductionPionIsoTrackGenElecPTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenElecPTEff,ExpectationReductionPionIsoTrackGenElecPTEffFail);   
  ExpectationReductionPionIsoTrackGenElecPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); p_{T} [GeV]");
  ExpectationReductionPionIsoTrackGenElecPTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenElecPTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenElecPTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenElecPTEff);
  
  ExpectationReductionPionIsoTrackGenElecActivityEff = ratioCalculator(ExpectationReductionPionIsoTrackGenElecActivityEff,ExpectationReductionPionIsoTrackGenElecActivityEffFail);   
  ExpectationReductionPionIsoTrackGenElecActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); Activity [GeV]");
  ExpectationReductionPionIsoTrackGenElecActivityEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenElecActivityEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenElecActivityEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenElecActivityEff);
  
  //2D
  PionIsoTrackGenElecReductionHTNJets_ = ratioCalculator(PionIsoTrackGenElecReductionHTNJets_,PionIsoTrackGenElecReductionHTNJetsFail_);   
  PionIsoTrackGenElecReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); H_{T} [GeV]; N_{Jets}");
  PionIsoTrackGenElecReductionHTNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenElecReductionHTNJets_->UseCurrentStyle();
  PionIsoTrackGenElecReductionHTNJets_->Write();
  SaveEfficiency(PionIsoTrackGenElecReductionHTNJets_);
  
  PionIsoTrackGenElecReductionMHTNJets_ = ratioCalculator(PionIsoTrackGenElecReductionMHTNJets_,PionIsoTrackGenElecReductionMHTNJetsFail_);   
  PionIsoTrackGenElecReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); #slash{H}_{T} [GeV]; N_{Jets}");
  PionIsoTrackGenElecReductionMHTNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenElecReductionMHTNJets_->UseCurrentStyle();
  PionIsoTrackGenElecReductionMHTNJets_->Write();
  SaveEfficiency(PionIsoTrackGenElecReductionMHTNJets_);
  
  
  PionIsoTrackGenElecReductionBTagNJets_ = ratioCalculator(PionIsoTrackGenElecReductionBTagNJets_,PionIsoTrackGenElecReductionBTagNJetsFail_);   
  PionIsoTrackGenElecReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); B_{Tags}; N_{Jets}");
  PionIsoTrackGenElecReductionBTagNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenElecReductionBTagNJets_->UseCurrentStyle();
  PionIsoTrackGenElecReductionBTagNJets_->Write();
  SaveEfficiency(PionIsoTrackGenElecReductionBTagNJets_);
  
  PionIsoTrackGenElecReductionPTActivity_ = ratioCalculator(PionIsoTrackGenElecReductionPTActivity_,PionIsoTrackGenElecReductionPTActivityFail_);   
  PionIsoTrackGenElecReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genElec); p_{T} [GeV]; Activity [GeV]");
  PionIsoTrackGenElecReductionPTActivity_->SetMarkerSize(2.0);
  PionIsoTrackGenElecReductionPTActivity_->UseCurrentStyle();
  PionIsoTrackGenElecReductionPTActivity_->Write();
  SaveEfficiency(PionIsoTrackGenElecReductionPTActivity_);
  
  
  
  
  // had tau
  
  //1D
  ExpectationReductionPionIsoTrackGenHadTauBTagEff = ratioCalculator(ExpectationReductionPionIsoTrackGenHadTauBTagEff,ExpectationReductionPionIsoTrackGenHadTauBTagEffFail);   
  ExpectationReductionPionIsoTrackGenHadTauBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); B_{Tags}");
  ExpectationReductionPionIsoTrackGenHadTauBTagEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenHadTauBTagEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenHadTauBTagEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenHadTauBTagEff);
  
  ExpectationReductionPionIsoTrackGenHadTauNJetsEff = ratioCalculator(ExpectationReductionPionIsoTrackGenHadTauNJetsEff,ExpectationReductionPionIsoTrackGenHadTauNJetsEffFail);   
  ExpectationReductionPionIsoTrackGenHadTauNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); N_{Jets}");
  ExpectationReductionPionIsoTrackGenHadTauNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenHadTauNJetsEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenHadTauNJetsEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenHadTauNJetsEff);
  
  ExpectationReductionPionIsoTrackGenHadTauHTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenHadTauHTEff,ExpectationReductionPionIsoTrackGenHadTauHTEffFail);   
  ExpectationReductionPionIsoTrackGenHadTauHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); H_{T}");
  ExpectationReductionPionIsoTrackGenHadTauHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenHadTauHTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenHadTauHTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenHadTauHTEff);
  
  ExpectationReductionPionIsoTrackGenHadTauMHTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenHadTauMHTEff,ExpectationReductionPionIsoTrackGenHadTauMHTEffFail);   
  ExpectationReductionPionIsoTrackGenHadTauMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); #slash{H}_{T} [GeV]");
  ExpectationReductionPionIsoTrackGenHadTauMHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenHadTauMHTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenHadTauMHTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenHadTauMHTEff);
  
  ExpectationReductionPionIsoTrackGenHadTauPTEff = ratioCalculator(ExpectationReductionPionIsoTrackGenHadTauPTEff,ExpectationReductionPionIsoTrackGenHadTauPTEffFail);   
  ExpectationReductionPionIsoTrackGenHadTauPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); p_{T} [GeV]");
  ExpectationReductionPionIsoTrackGenHadTauPTEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenHadTauPTEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenHadTauPTEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenHadTauPTEff);
  
  ExpectationReductionPionIsoTrackGenHadTauActivityEff = ratioCalculator(ExpectationReductionPionIsoTrackGenHadTauActivityEff,ExpectationReductionPionIsoTrackGenHadTauActivityEffFail);   
  ExpectationReductionPionIsoTrackGenHadTauActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); Activity [GeV]");
  ExpectationReductionPionIsoTrackGenHadTauActivityEff->SetMarkerSize(2.0);
  ExpectationReductionPionIsoTrackGenHadTauActivityEff->UseCurrentStyle();
  ExpectationReductionPionIsoTrackGenHadTauActivityEff->Write();
  SaveEfficiency(ExpectationReductionPionIsoTrackGenHadTauActivityEff);
  
  //2D
  PionIsoTrackGenHadTauReductionHTNJets_ = ratioCalculator(PionIsoTrackGenHadTauReductionHTNJets_,PionIsoTrackGenHadTauReductionHTNJetsFail_);   
  PionIsoTrackGenHadTauReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); H_{T} [GeV]; N_{Jets}");
  PionIsoTrackGenHadTauReductionHTNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenHadTauReductionHTNJets_->UseCurrentStyle();
  PionIsoTrackGenHadTauReductionHTNJets_->Write();
  SaveEfficiency(PionIsoTrackGenHadTauReductionHTNJets_);
  
  PionIsoTrackGenHadTauReductionMHTNJets_ = ratioCalculator(PionIsoTrackGenHadTauReductionMHTNJets_,PionIsoTrackGenHadTauReductionMHTNJetsFail_);   
  PionIsoTrackGenHadTauReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); #slash{H}_{T} [GeV]; N_{Jets}");
  PionIsoTrackGenHadTauReductionMHTNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenHadTauReductionMHTNJets_->UseCurrentStyle();
  PionIsoTrackGenHadTauReductionMHTNJets_->Write();
  SaveEfficiency(PionIsoTrackGenHadTauReductionMHTNJets_);
  
  
  PionIsoTrackGenHadTauReductionBTagNJets_ = ratioCalculator(PionIsoTrackGenHadTauReductionBTagNJets_,PionIsoTrackGenHadTauReductionBTagNJetsFail_);   
  PionIsoTrackGenHadTauReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); B_{Tags}; N_{Jets}");
  PionIsoTrackGenHadTauReductionBTagNJets_->SetMarkerSize(2.0);
  PionIsoTrackGenHadTauReductionBTagNJets_->UseCurrentStyle();
  PionIsoTrackGenHadTauReductionBTagNJets_->Write();
  SaveEfficiency(PionIsoTrackGenHadTauReductionBTagNJets_);
  
  PionIsoTrackGenHadTauReductionPTActivity_ = ratioCalculator(PionIsoTrackGenHadTauReductionPTActivity_,PionIsoTrackGenHadTauReductionPTActivityFail_);   
  PionIsoTrackGenHadTauReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi iso track expec. reduction iso only (genHadTau); p_{T} [GeV]; Activity [GeV]");
  PionIsoTrackGenHadTauReductionPTActivity_->SetMarkerSize(2.0);
  PionIsoTrackGenHadTauReductionPTActivity_->UseCurrentStyle();
  PionIsoTrackGenHadTauReductionPTActivity_->Write();
  SaveEfficiency(PionIsoTrackGenHadTauReductionPTActivity_);
  
  // reco acc combined
  
  
  // reco/acc
  
  // mu reco/acc tracks
  //1D
  //1D
  ExpectationReductionMuRecoTrackGenMuBTagEff = ratioCalculator(ExpectationReductionMuRecoTrackGenMuBTagEff,ExpectationReductionMuRecoTrackGenMuBTagEffFail);   
  ExpectationReductionMuRecoTrackGenMuBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; B_{Tags}");
  ExpectationReductionMuRecoTrackGenMuBTagEff->SetMarkerSize(2.0);
  ExpectationReductionMuRecoTrackGenMuBTagEff->UseCurrentStyle();
  ExpectationReductionMuRecoTrackGenMuBTagEff->Write();
  SaveEfficiency(ExpectationReductionMuRecoTrackGenMuBTagEff);
  
  ExpectationReductionMuRecoTrackGenMuNJetsEff = ratioCalculator(ExpectationReductionMuRecoTrackGenMuNJetsEff,ExpectationReductionMuRecoTrackGenMuNJetsEffFail);   
  ExpectationReductionMuRecoTrackGenMuNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; N_{Jets}");
  ExpectationReductionMuRecoTrackGenMuNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionMuRecoTrackGenMuNJetsEff->UseCurrentStyle();
  ExpectationReductionMuRecoTrackGenMuNJetsEff->Write();
  SaveEfficiency(ExpectationReductionMuRecoTrackGenMuNJetsEff);
  
  ExpectationReductionMuRecoTrackGenMuHTEff = ratioCalculator(ExpectationReductionMuRecoTrackGenMuHTEff,ExpectationReductionMuRecoTrackGenMuHTEffFail);   
  ExpectationReductionMuRecoTrackGenMuHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; H_{T}");
  ExpectationReductionMuRecoTrackGenMuHTEff->SetMarkerSize(2.0);
  ExpectationReductionMuRecoTrackGenMuHTEff->UseCurrentStyle();
  ExpectationReductionMuRecoTrackGenMuHTEff->Write();
  SaveEfficiency(ExpectationReductionMuRecoTrackGenMuHTEff);
  
  ExpectationReductionMuRecoTrackGenMuMHTEff = ratioCalculator(ExpectationReductionMuRecoTrackGenMuMHTEff,ExpectationReductionMuRecoTrackGenMuMHTEffFail);   
  ExpectationReductionMuRecoTrackGenMuMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; #slash{H}_{T} [GeV]");
  ExpectationReductionMuRecoTrackGenMuMHTEff->SetMarkerSize(2.0);
  ExpectationReductionMuRecoTrackGenMuMHTEff->UseCurrentStyle();
  ExpectationReductionMuRecoTrackGenMuMHTEff->Write();
  SaveEfficiency(ExpectationReductionMuRecoTrackGenMuMHTEff);
  
  ExpectationReductionMuRecoTrackGenMuPTEff = ratioCalculator(ExpectationReductionMuRecoTrackGenMuPTEff,ExpectationReductionMuRecoTrackGenMuPTEffFail);   
  ExpectationReductionMuRecoTrackGenMuPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; p_{T} [GeV]");
  ExpectationReductionMuRecoTrackGenMuPTEff->SetMarkerSize(2.0);
  ExpectationReductionMuRecoTrackGenMuPTEff->UseCurrentStyle();
  ExpectationReductionMuRecoTrackGenMuPTEff->Write();
  SaveEfficiency(ExpectationReductionMuRecoTrackGenMuPTEff);
  
  ExpectationReductionMuRecoTrackGenMuActivityEff = ratioCalculator(ExpectationReductionMuRecoTrackGenMuActivityEff,ExpectationReductionMuRecoTrackGenMuActivityEffFail);   
  ExpectationReductionMuRecoTrackGenMuActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; Activity [GeV]");
  ExpectationReductionMuRecoTrackGenMuActivityEff->SetMarkerSize(2.0);
  ExpectationReductionMuRecoTrackGenMuActivityEff->UseCurrentStyle();
  ExpectationReductionMuRecoTrackGenMuActivityEff->Write();
  SaveEfficiency(ExpectationReductionMuRecoTrackGenMuActivityEff);
  
  //2D
  MuRecoTrackGenMuReductionHTNJets_ = ratioCalculator(MuRecoTrackGenMuReductionHTNJets_,MuRecoTrackGenMuReductionHTNJetsFail_);   
  MuRecoTrackGenMuReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; H_{T} [GeV]; N_{Jets}");
  MuRecoTrackGenMuReductionHTNJets_->SetMarkerSize(2.0);
  MuRecoTrackGenMuReductionHTNJets_->UseCurrentStyle();
  MuRecoTrackGenMuReductionHTNJets_->Write();
  SaveEfficiency(MuRecoTrackGenMuReductionHTNJets_);
  
  MuRecoTrackGenMuReductionMHTNJets_ = ratioCalculator(MuRecoTrackGenMuReductionMHTNJets_,MuRecoTrackGenMuReductionMHTNJetsFail_);   
  MuRecoTrackGenMuReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; #slash{H}_{T} [GeV]; N_{Jets}");
  MuRecoTrackGenMuReductionMHTNJets_->SetMarkerSize(2.0);
  MuRecoTrackGenMuReductionMHTNJets_->UseCurrentStyle();
  MuRecoTrackGenMuReductionMHTNJets_->Write();
  SaveEfficiency(MuRecoTrackGenMuReductionMHTNJets_);
  
  
  MuRecoTrackGenMuReductionBTagNJets_ = ratioCalculator(MuRecoTrackGenMuReductionBTagNJets_,MuRecoTrackGenMuReductionBTagNJetsFail_);   
  MuRecoTrackGenMuReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; B_{Tags}; N_{Jets}");
  MuRecoTrackGenMuReductionBTagNJets_->SetMarkerSize(2.0);
  MuRecoTrackGenMuReductionBTagNJets_->UseCurrentStyle();
  MuRecoTrackGenMuReductionBTagNJets_->Write();
  SaveEfficiency(MuRecoTrackGenMuReductionBTagNJets_);
  
  MuRecoTrackGenMuReductionPTActivity_ = ratioCalculator(MuRecoTrackGenMuReductionPTActivity_,MuRecoTrackGenMuReductionPTActivityFail_);   
  MuRecoTrackGenMuReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu reco/acc track expec. reduction reco/acc only; p_{T} [GeV]; Activity [GeV]");
  MuRecoTrackGenMuReductionPTActivity_->SetMarkerSize(2.0);
  MuRecoTrackGenMuReductionPTActivity_->UseCurrentStyle();
  MuRecoTrackGenMuReductionPTActivity_->Write();
  SaveEfficiency(MuRecoTrackGenMuReductionPTActivity_);
  
  
  
  
  //1D
  ExpectationReductionPionRecoTrackGenMuBTagEff = ratioCalculator(ExpectationReductionPionRecoTrackGenMuBTagEff,ExpectationReductionPionRecoTrackGenMuBTagEffFail);   
  ExpectationReductionPionRecoTrackGenMuBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); B_{Tags}");
  ExpectationReductionPionRecoTrackGenMuBTagEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenMuBTagEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenMuBTagEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenMuBTagEff);
  
  ExpectationReductionPionRecoTrackGenMuNJetsEff = ratioCalculator(ExpectationReductionPionRecoTrackGenMuNJetsEff,ExpectationReductionPionRecoTrackGenMuNJetsEffFail);   
  ExpectationReductionPionRecoTrackGenMuNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); N_{Jets}");
  ExpectationReductionPionRecoTrackGenMuNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenMuNJetsEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenMuNJetsEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenMuNJetsEff);
  
  ExpectationReductionPionRecoTrackGenMuHTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenMuHTEff,ExpectationReductionPionRecoTrackGenMuHTEffFail);   
  ExpectationReductionPionRecoTrackGenMuHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); H_{T}");
  ExpectationReductionPionRecoTrackGenMuHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenMuHTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenMuHTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenMuHTEff);
  
  ExpectationReductionPionRecoTrackGenMuMHTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenMuMHTEff,ExpectationReductionPionRecoTrackGenMuMHTEffFail);   
  ExpectationReductionPionRecoTrackGenMuMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); #slash{H}_{T} [GeV]");
  ExpectationReductionPionRecoTrackGenMuMHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenMuMHTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenMuMHTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenMuMHTEff);
  
  ExpectationReductionPionRecoTrackGenMuPTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenMuPTEff,ExpectationReductionPionRecoTrackGenMuPTEffFail);   
  ExpectationReductionPionRecoTrackGenMuPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); p_{T} [GeV]");
  ExpectationReductionPionRecoTrackGenMuPTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenMuPTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenMuPTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenMuPTEff);
  
  ExpectationReductionPionRecoTrackGenMuActivityEff = ratioCalculator(ExpectationReductionPionRecoTrackGenMuActivityEff,ExpectationReductionPionRecoTrackGenMuActivityEffFail);   
  ExpectationReductionPionRecoTrackGenMuActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); Activity [GeV]");
  ExpectationReductionPionRecoTrackGenMuActivityEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenMuActivityEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenMuActivityEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenMuActivityEff);
  
  //2D
  PionRecoTrackGenMuReductionHTNJets_ = ratioCalculator(PionRecoTrackGenMuReductionHTNJets_,PionRecoTrackGenMuReductionHTNJetsFail_);   
  PionRecoTrackGenMuReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); H_{T} [GeV]; N_{Jets}");
  PionRecoTrackGenMuReductionHTNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenMuReductionHTNJets_->UseCurrentStyle();
  PionRecoTrackGenMuReductionHTNJets_->Write();
  SaveEfficiency(PionRecoTrackGenMuReductionHTNJets_);
  
  PionRecoTrackGenMuReductionMHTNJets_ = ratioCalculator(PionRecoTrackGenMuReductionMHTNJets_,PionRecoTrackGenMuReductionMHTNJetsFail_);   
  PionRecoTrackGenMuReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); #slash{H}_{T} [GeV]; N_{Jets}");
  PionRecoTrackGenMuReductionMHTNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenMuReductionMHTNJets_->UseCurrentStyle();
  PionRecoTrackGenMuReductionMHTNJets_->Write();
  SaveEfficiency(PionRecoTrackGenMuReductionMHTNJets_);
  
  
  PionRecoTrackGenMuReductionBTagNJets_ = ratioCalculator(PionRecoTrackGenMuReductionBTagNJets_,PionRecoTrackGenMuReductionBTagNJetsFail_);   
  PionRecoTrackGenMuReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); B_{Tags}; N_{Jets}");
  PionRecoTrackGenMuReductionBTagNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenMuReductionBTagNJets_->UseCurrentStyle();
  PionRecoTrackGenMuReductionBTagNJets_->Write();
  SaveEfficiency(PionRecoTrackGenMuReductionBTagNJets_);
  
  PionRecoTrackGenMuReductionPTActivity_ = ratioCalculator(PionRecoTrackGenMuReductionPTActivity_,PionRecoTrackGenMuReductionPTActivityFail_);   
  PionRecoTrackGenMuReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genMu); p_{T} [GeV]; Activity [GeV]");
  PionRecoTrackGenMuReductionPTActivity_->SetMarkerSize(2.0);
  PionRecoTrackGenMuReductionPTActivity_->UseCurrentStyle();
  PionRecoTrackGenMuReductionPTActivity_->Write();
  SaveEfficiency(PionRecoTrackGenMuReductionPTActivity_);
  
  
  
  // elec reco/acc track
  
  
  // elec reco/acc tracks
  //1D
  //1D
  ExpectationReductionElecRecoTrackGenElecBTagEff = ratioCalculator(ExpectationReductionElecRecoTrackGenElecBTagEff,ExpectationReductionElecRecoTrackGenElecBTagEffFail);   
  ExpectationReductionElecRecoTrackGenElecBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; B_{Tags}");
  ExpectationReductionElecRecoTrackGenElecBTagEff->SetMarkerSize(2.0);
  ExpectationReductionElecRecoTrackGenElecBTagEff->UseCurrentStyle();
  ExpectationReductionElecRecoTrackGenElecBTagEff->Write();
  SaveEfficiency(ExpectationReductionElecRecoTrackGenElecBTagEff);
  
  ExpectationReductionElecRecoTrackGenElecNJetsEff = ratioCalculator(ExpectationReductionElecRecoTrackGenElecNJetsEff,ExpectationReductionElecRecoTrackGenElecNJetsEffFail);   
  ExpectationReductionElecRecoTrackGenElecNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; N_{Jets}");
  ExpectationReductionElecRecoTrackGenElecNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionElecRecoTrackGenElecNJetsEff->UseCurrentStyle();
  ExpectationReductionElecRecoTrackGenElecNJetsEff->Write();
  SaveEfficiency(ExpectationReductionElecRecoTrackGenElecNJetsEff);
  
  ExpectationReductionElecRecoTrackGenElecHTEff = ratioCalculator(ExpectationReductionElecRecoTrackGenElecHTEff,ExpectationReductionElecRecoTrackGenElecHTEffFail);   
  ExpectationReductionElecRecoTrackGenElecHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; H_{T}");
  ExpectationReductionElecRecoTrackGenElecHTEff->SetMarkerSize(2.0);
  ExpectationReductionElecRecoTrackGenElecHTEff->UseCurrentStyle();
  ExpectationReductionElecRecoTrackGenElecHTEff->Write();
  SaveEfficiency(ExpectationReductionElecRecoTrackGenElecHTEff);
  
  ExpectationReductionElecRecoTrackGenElecMHTEff = ratioCalculator(ExpectationReductionElecRecoTrackGenElecMHTEff,ExpectationReductionElecRecoTrackGenElecMHTEffFail);   
  ExpectationReductionElecRecoTrackGenElecMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; #slash{H}_{T} [GeV]");
  ExpectationReductionElecRecoTrackGenElecMHTEff->SetMarkerSize(2.0);
  ExpectationReductionElecRecoTrackGenElecMHTEff->UseCurrentStyle();
  ExpectationReductionElecRecoTrackGenElecMHTEff->Write();
  SaveEfficiency(ExpectationReductionElecRecoTrackGenElecMHTEff);
  
  ExpectationReductionElecRecoTrackGenElecPTEff = ratioCalculator(ExpectationReductionElecRecoTrackGenElecPTEff,ExpectationReductionElecRecoTrackGenElecPTEffFail);   
  ExpectationReductionElecRecoTrackGenElecPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; p_{T} [GeV]");
  ExpectationReductionElecRecoTrackGenElecPTEff->SetMarkerSize(2.0);
  ExpectationReductionElecRecoTrackGenElecPTEff->UseCurrentStyle();
  ExpectationReductionElecRecoTrackGenElecPTEff->Write();
  SaveEfficiency(ExpectationReductionElecRecoTrackGenElecPTEff);
  
  ExpectationReductionElecRecoTrackGenElecActivityEff = ratioCalculator(ExpectationReductionElecRecoTrackGenElecActivityEff,ExpectationReductionElecRecoTrackGenElecActivityEffFail);   
  ExpectationReductionElecRecoTrackGenElecActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; Activity [GeV]");
  ExpectationReductionElecRecoTrackGenElecActivityEff->SetMarkerSize(2.0);
  ExpectationReductionElecRecoTrackGenElecActivityEff->UseCurrentStyle();
  ExpectationReductionElecRecoTrackGenElecActivityEff->Write();
  SaveEfficiency(ExpectationReductionElecRecoTrackGenElecActivityEff);
  
  //2D
  ElecRecoTrackGenElecReductionHTNJets_ = ratioCalculator(ElecRecoTrackGenElecReductionHTNJets_,ElecRecoTrackGenElecReductionHTNJetsFail_);   
  ElecRecoTrackGenElecReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; H_{T} [GeV]; N_{Jets}");
  ElecRecoTrackGenElecReductionHTNJets_->SetMarkerSize(2.0);
  ElecRecoTrackGenElecReductionHTNJets_->UseCurrentStyle();
  ElecRecoTrackGenElecReductionHTNJets_->Write();
  SaveEfficiency(ElecRecoTrackGenElecReductionHTNJets_);
  
  ElecRecoTrackGenElecReductionMHTNJets_ = ratioCalculator(ElecRecoTrackGenElecReductionMHTNJets_,ElecRecoTrackGenElecReductionMHTNJetsFail_);   
  ElecRecoTrackGenElecReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; #slash{H}_{T} [GeV]; N_{Jets}");
  ElecRecoTrackGenElecReductionMHTNJets_->SetMarkerSize(2.0);
  ElecRecoTrackGenElecReductionMHTNJets_->UseCurrentStyle();
  ElecRecoTrackGenElecReductionMHTNJets_->Write();
  SaveEfficiency(ElecRecoTrackGenElecReductionMHTNJets_);
  
  
  ElecRecoTrackGenElecReductionBTagNJets_ = ratioCalculator(ElecRecoTrackGenElecReductionBTagNJets_,ElecRecoTrackGenElecReductionBTagNJetsFail_);   
  ElecRecoTrackGenElecReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; B_{Tags}; N_{Jets}");
  ElecRecoTrackGenElecReductionBTagNJets_->SetMarkerSize(2.0);
  ElecRecoTrackGenElecReductionBTagNJets_->UseCurrentStyle();
  ElecRecoTrackGenElecReductionBTagNJets_->Write();
  SaveEfficiency(ElecRecoTrackGenElecReductionBTagNJets_);
  
  ElecRecoTrackGenElecReductionPTActivity_ = ratioCalculator(ElecRecoTrackGenElecReductionPTActivity_,ElecRecoTrackGenElecReductionPTActivityFail_);   
  ElecRecoTrackGenElecReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e reco/acc track expec. reduction reco/acc only; p_{T} [GeV]; Activity [GeV]");
  ElecRecoTrackGenElecReductionPTActivity_->SetMarkerSize(2.0);
  ElecRecoTrackGenElecReductionPTActivity_->UseCurrentStyle();
  ElecRecoTrackGenElecReductionPTActivity_->Write();
  SaveEfficiency(ElecRecoTrackGenElecReductionPTActivity_);
  
  
  
  
  //1D
  ExpectationReductionPionRecoTrackGenElecBTagEff = ratioCalculator(ExpectationReductionPionRecoTrackGenElecBTagEff,ExpectationReductionPionRecoTrackGenElecBTagEffFail);   
  ExpectationReductionPionRecoTrackGenElecBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); B_{Tags}");
  ExpectationReductionPionRecoTrackGenElecBTagEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenElecBTagEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenElecBTagEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenElecBTagEff);
  
  ExpectationReductionPionRecoTrackGenElecNJetsEff = ratioCalculator(ExpectationReductionPionRecoTrackGenElecNJetsEff,ExpectationReductionPionRecoTrackGenElecNJetsEffFail);   
  ExpectationReductionPionRecoTrackGenElecNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); N_{Jets}");
  ExpectationReductionPionRecoTrackGenElecNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenElecNJetsEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenElecNJetsEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenElecNJetsEff);
  
  ExpectationReductionPionRecoTrackGenElecHTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenElecHTEff,ExpectationReductionPionRecoTrackGenElecHTEffFail);   
  ExpectationReductionPionRecoTrackGenElecHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); H_{T}");
  ExpectationReductionPionRecoTrackGenElecHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenElecHTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenElecHTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenElecHTEff);
  
  ExpectationReductionPionRecoTrackGenElecMHTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenElecMHTEff,ExpectationReductionPionRecoTrackGenElecMHTEffFail);   
  ExpectationReductionPionRecoTrackGenElecMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); #slash{H}_{T} [GeV]");
  ExpectationReductionPionRecoTrackGenElecMHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenElecMHTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenElecMHTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenElecMHTEff);
  
  ExpectationReductionPionRecoTrackGenElecPTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenElecPTEff,ExpectationReductionPionRecoTrackGenElecPTEffFail);   
  ExpectationReductionPionRecoTrackGenElecPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); p_{T} [GeV]");
  ExpectationReductionPionRecoTrackGenElecPTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenElecPTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenElecPTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenElecPTEff);
  
  ExpectationReductionPionRecoTrackGenElecActivityEff = ratioCalculator(ExpectationReductionPionRecoTrackGenElecActivityEff,ExpectationReductionPionRecoTrackGenElecActivityEffFail);   
  ExpectationReductionPionRecoTrackGenElecActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); Activity [GeV]");
  ExpectationReductionPionRecoTrackGenElecActivityEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenElecActivityEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenElecActivityEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenElecActivityEff);
  
  //2D
  PionRecoTrackGenElecReductionHTNJets_ = ratioCalculator(PionRecoTrackGenElecReductionHTNJets_,PionRecoTrackGenElecReductionHTNJetsFail_);   
  PionRecoTrackGenElecReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); H_{T} [GeV]; N_{Jets}");
  PionRecoTrackGenElecReductionHTNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenElecReductionHTNJets_->UseCurrentStyle();
  PionRecoTrackGenElecReductionHTNJets_->Write();
  SaveEfficiency(PionRecoTrackGenElecReductionHTNJets_);
  
  PionRecoTrackGenElecReductionMHTNJets_ = ratioCalculator(PionRecoTrackGenElecReductionMHTNJets_,PionRecoTrackGenElecReductionMHTNJetsFail_);   
  PionRecoTrackGenElecReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); #slash{H}_{T} [GeV]; N_{Jets}");
  PionRecoTrackGenElecReductionMHTNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenElecReductionMHTNJets_->UseCurrentStyle();
  PionRecoTrackGenElecReductionMHTNJets_->Write();
  SaveEfficiency(PionRecoTrackGenElecReductionMHTNJets_);
  
  
  PionRecoTrackGenElecReductionBTagNJets_ = ratioCalculator(PionRecoTrackGenElecReductionBTagNJets_,PionRecoTrackGenElecReductionBTagNJetsFail_);   
  PionRecoTrackGenElecReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); B_{Tags}; N_{Jets}");
  PionRecoTrackGenElecReductionBTagNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenElecReductionBTagNJets_->UseCurrentStyle();
  PionRecoTrackGenElecReductionBTagNJets_->Write();
  SaveEfficiency(PionRecoTrackGenElecReductionBTagNJets_);
  
  PionRecoTrackGenElecReductionPTActivity_ = ratioCalculator(PionRecoTrackGenElecReductionPTActivity_,PionRecoTrackGenElecReductionPTActivityFail_);   
  PionRecoTrackGenElecReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genElec); p_{T} [GeV]; Activity [GeV]");
  PionRecoTrackGenElecReductionPTActivity_->SetMarkerSize(2.0);
  PionRecoTrackGenElecReductionPTActivity_->UseCurrentStyle();
  PionRecoTrackGenElecReductionPTActivity_->Write();
  SaveEfficiency(PionRecoTrackGenElecReductionPTActivity_);
  
  
  
  
  // had tau
  
  //1D
  ExpectationReductionPionRecoTrackGenHadTauBTagEff = ratioCalculator(ExpectationReductionPionRecoTrackGenHadTauBTagEff,ExpectationReductionPionRecoTrackGenHadTauBTagEffFail);   
  ExpectationReductionPionRecoTrackGenHadTauBTagEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); B_{Tags}");
  ExpectationReductionPionRecoTrackGenHadTauBTagEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenHadTauBTagEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenHadTauBTagEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenHadTauBTagEff);
  
  ExpectationReductionPionRecoTrackGenHadTauNJetsEff = ratioCalculator(ExpectationReductionPionRecoTrackGenHadTauNJetsEff,ExpectationReductionPionRecoTrackGenHadTauNJetsEffFail);   
  ExpectationReductionPionRecoTrackGenHadTauNJetsEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); N_{Jets}");
  ExpectationReductionPionRecoTrackGenHadTauNJetsEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenHadTauNJetsEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenHadTauNJetsEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenHadTauNJetsEff);
  
  ExpectationReductionPionRecoTrackGenHadTauHTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenHadTauHTEff,ExpectationReductionPionRecoTrackGenHadTauHTEffFail);   
  ExpectationReductionPionRecoTrackGenHadTauHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); H_{T}");
  ExpectationReductionPionRecoTrackGenHadTauHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenHadTauHTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenHadTauHTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenHadTauHTEff);
  
  ExpectationReductionPionRecoTrackGenHadTauMHTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenHadTauMHTEff,ExpectationReductionPionRecoTrackGenHadTauMHTEffFail);   
  ExpectationReductionPionRecoTrackGenHadTauMHTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); #slash{H}_{T} [GeV]");
  ExpectationReductionPionRecoTrackGenHadTauMHTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenHadTauMHTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenHadTauMHTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenHadTauMHTEff);
  
  ExpectationReductionPionRecoTrackGenHadTauPTEff = ratioCalculator(ExpectationReductionPionRecoTrackGenHadTauPTEff,ExpectationReductionPionRecoTrackGenHadTauPTEffFail);   
  ExpectationReductionPionRecoTrackGenHadTauPTEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); p_{T} [GeV]");
  ExpectationReductionPionRecoTrackGenHadTauPTEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenHadTauPTEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenHadTauPTEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenHadTauPTEff);
  
  ExpectationReductionPionRecoTrackGenHadTauActivityEff = ratioCalculator(ExpectationReductionPionRecoTrackGenHadTauActivityEff,ExpectationReductionPionRecoTrackGenHadTauActivityEffFail);   
  ExpectationReductionPionRecoTrackGenHadTauActivityEff->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); Activity [GeV]");
  ExpectationReductionPionRecoTrackGenHadTauActivityEff->SetMarkerSize(2.0);
  ExpectationReductionPionRecoTrackGenHadTauActivityEff->UseCurrentStyle();
  ExpectationReductionPionRecoTrackGenHadTauActivityEff->Write();
  SaveEfficiency(ExpectationReductionPionRecoTrackGenHadTauActivityEff);
  
  //2D
  PionRecoTrackGenHadTauReductionHTNJets_ = ratioCalculator(PionRecoTrackGenHadTauReductionHTNJets_,PionRecoTrackGenHadTauReductionHTNJetsFail_);   
  PionRecoTrackGenHadTauReductionHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); H_{T} [GeV]; N_{Jets}");
  PionRecoTrackGenHadTauReductionHTNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenHadTauReductionHTNJets_->UseCurrentStyle();
  PionRecoTrackGenHadTauReductionHTNJets_->Write();
  SaveEfficiency(PionRecoTrackGenHadTauReductionHTNJets_);
  
  PionRecoTrackGenHadTauReductionMHTNJets_ = ratioCalculator(PionRecoTrackGenHadTauReductionMHTNJets_,PionRecoTrackGenHadTauReductionMHTNJetsFail_);   
  PionRecoTrackGenHadTauReductionMHTNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); #slash{H}_{T} [GeV]; N_{Jets}");
  PionRecoTrackGenHadTauReductionMHTNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenHadTauReductionMHTNJets_->UseCurrentStyle();
  PionRecoTrackGenHadTauReductionMHTNJets_->Write();
  SaveEfficiency(PionRecoTrackGenHadTauReductionMHTNJets_);
  
  
  PionRecoTrackGenHadTauReductionBTagNJets_ = ratioCalculator(PionRecoTrackGenHadTauReductionBTagNJets_,PionRecoTrackGenHadTauReductionBTagNJetsFail_);   
  PionRecoTrackGenHadTauReductionBTagNJets_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); B_{Tags}; N_{Jets}");
  PionRecoTrackGenHadTauReductionBTagNJets_->SetMarkerSize(2.0);
  PionRecoTrackGenHadTauReductionBTagNJets_->UseCurrentStyle();
  PionRecoTrackGenHadTauReductionBTagNJets_->Write();
  SaveEfficiency(PionRecoTrackGenHadTauReductionBTagNJets_);
  
  PionRecoTrackGenHadTauReductionPTActivity_ = ratioCalculator(PionRecoTrackGenHadTauReductionPTActivity_,PionRecoTrackGenHadTauReductionPTActivityFail_);   
  PionRecoTrackGenHadTauReductionPTActivity_->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi reco/acc track expec. reduction reco/acc only (genHadTau); p_{T} [GeV]; Activity [GeV]");
  PionRecoTrackGenHadTauReductionPTActivity_->SetMarkerSize(2.0);
  PionRecoTrackGenHadTauReductionPTActivity_->UseCurrentStyle();
  PionRecoTrackGenHadTauReductionPTActivity_->Write();
  SaveEfficiency(PionRecoTrackGenHadTauReductionPTActivity_);
  
  // ************************************************************************************************************* 22 June 2015 end****************************************************
  
  
  // ************************************************************************************************************* 04 July 2015****************************************************
  HadTauTrackSingleProngPT = ratioCalculator(HadTauTrackSingleProngPT,HadTauTrackSingleProngPTFail);   
  HadTauTrackSingleProngPT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (singleProng #tau); p_{T} [GeV]");
  HadTauTrackSingleProngPT->SetMarkerSize(2.0);
  HadTauTrackSingleProngPT->UseCurrentStyle();
  HadTauTrackSingleProngPT->Write();
  SaveEfficiency(HadTauTrackSingleProngPT);        
  HadTauTrackSingleProngEta = ratioCalculator(HadTauTrackSingleProngEta,HadTauTrackSingleProngEtaFail);   
  HadTauTrackSingleProngEta->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (singleProng #tau); #eta");
  HadTauTrackSingleProngEta->SetMarkerSize(2.0);
  HadTauTrackSingleProngEta->UseCurrentStyle();
  HadTauTrackSingleProngEta->Write();
  SaveEfficiency(HadTauTrackSingleProngEta);        
  HadTauTrackSingleProngPhi = ratioCalculator(HadTauTrackSingleProngPhi,HadTauTrackSingleProngPhiFail);   
  HadTauTrackSingleProngPhi->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (singleProng #tau); #phi");
  HadTauTrackSingleProngPhi->SetMarkerSize(2.0);
  HadTauTrackSingleProngPhi->UseCurrentStyle();
  HadTauTrackSingleProngPhi->Write();
  SaveEfficiency(HadTauTrackSingleProngPhi);        
  HadTauTrackSingleProngActivity = ratioCalculator(HadTauTrackSingleProngActivity,HadTauTrackSingleProngActivityFail);   
  HadTauTrackSingleProngActivity->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (singleProng #tau); Activity [GeV]");
  HadTauTrackSingleProngActivity->SetMarkerSize(2.0);
  HadTauTrackSingleProngActivity->UseCurrentStyle();
  HadTauTrackSingleProngActivity->Write();
  SaveEfficiency(HadTauTrackSingleProngActivity);        
  HadTauTrackSingleProngHT = ratioCalculator(HadTauTrackSingleProngHT,HadTauTrackSingleProngHTFail);   
  HadTauTrackSingleProngHT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (singleProng #tau); H_{T} [GeV]");
  HadTauTrackSingleProngHT->SetMarkerSize(2.0);
  HadTauTrackSingleProngHT->UseCurrentStyle();
  HadTauTrackSingleProngHT->Write();
  SaveEfficiency(HadTauTrackSingleProngHT);        
  HadTauTrackSingleProngMHT = ratioCalculator(HadTauTrackSingleProngMHT,HadTauTrackSingleProngMHTFail);   
  HadTauTrackSingleProngMHT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (singleProng #tau); #slash{H}_{T} [GeV]");
  HadTauTrackSingleProngMHT->SetMarkerSize(2.0);
  HadTauTrackSingleProngMHT->UseCurrentStyle();
  HadTauTrackSingleProngMHT->Write();
  SaveEfficiency(HadTauTrackSingleProngMHT);        
  HadTauTrackSingleProngNJets = ratioCalculator(HadTauTrackSingleProngNJets,HadTauTrackSingleProngNJetsFail);   
  HadTauTrackSingleProngNJets->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (singleProng #tau); N_{Jets}");
  HadTauTrackSingleProngNJets->SetMarkerSize(2.0);
  HadTauTrackSingleProngNJets->UseCurrentStyle();
  HadTauTrackSingleProngNJets->Write();
  SaveEfficiency(HadTauTrackSingleProngNJets);
  HadTauTrackSingleProngBTags = ratioCalculator(HadTauTrackSingleProngBTags,HadTauTrackSingleProngBTagsFail);   
  HadTauTrackSingleProngBTags->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (singleProng #tau); B_{Tags}");
  HadTauTrackSingleProngBTags->SetMarkerSize(2.0);
  HadTauTrackSingleProngBTags->UseCurrentStyle();
  HadTauTrackSingleProngBTags->Write();
  SaveEfficiency(HadTauTrackSingleProngBTags);
  
  
  
  HadTauTrackOneChargedAndNeutralsPT = ratioCalculator(HadTauTrackOneChargedAndNeutralsPT,HadTauTrackOneChargedAndNeutralsPTFail);   
  HadTauTrackOneChargedAndNeutralsPT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (1charged + neutral #tau); p_{T} [GeV]");
  HadTauTrackOneChargedAndNeutralsPT->SetMarkerSize(2.0);
  HadTauTrackOneChargedAndNeutralsPT->UseCurrentStyle();
  HadTauTrackOneChargedAndNeutralsPT->Write();
  SaveEfficiency(HadTauTrackOneChargedAndNeutralsPT);        
  HadTauTrackOneChargedAndNeutralsEta = ratioCalculator(HadTauTrackOneChargedAndNeutralsEta,HadTauTrackOneChargedAndNeutralsEtaFail);   
  HadTauTrackOneChargedAndNeutralsEta->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (1charged + neutral #tau); #eta");
  HadTauTrackOneChargedAndNeutralsEta->SetMarkerSize(2.0);
  HadTauTrackOneChargedAndNeutralsEta->UseCurrentStyle();
  HadTauTrackOneChargedAndNeutralsEta->Write();
  SaveEfficiency(HadTauTrackOneChargedAndNeutralsEta);        
  HadTauTrackOneChargedAndNeutralsPhi = ratioCalculator(HadTauTrackOneChargedAndNeutralsPhi,HadTauTrackOneChargedAndNeutralsPhiFail);   
  HadTauTrackOneChargedAndNeutralsPhi->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (1charged + neutral #tau); #phi");
  HadTauTrackOneChargedAndNeutralsPhi->SetMarkerSize(2.0);
  HadTauTrackOneChargedAndNeutralsPhi->UseCurrentStyle();
  HadTauTrackOneChargedAndNeutralsPhi->Write();
  SaveEfficiency(HadTauTrackOneChargedAndNeutralsPhi);        
  HadTauTrackOneChargedAndNeutralsActivity = ratioCalculator(HadTauTrackOneChargedAndNeutralsActivity,HadTauTrackOneChargedAndNeutralsActivityFail);   
  HadTauTrackOneChargedAndNeutralsActivity->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (1charged + neutral #tau); Activity [GeV]");
  HadTauTrackOneChargedAndNeutralsActivity->SetMarkerSize(2.0);
  HadTauTrackOneChargedAndNeutralsActivity->UseCurrentStyle();
  HadTauTrackOneChargedAndNeutralsActivity->Write();
  SaveEfficiency(HadTauTrackOneChargedAndNeutralsActivity);        
  HadTauTrackOneChargedAndNeutralsHT = ratioCalculator(HadTauTrackOneChargedAndNeutralsHT,HadTauTrackOneChargedAndNeutralsHTFail);   
  HadTauTrackOneChargedAndNeutralsHT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (1charged + neutral #tau); H_{T} [GeV]");
  HadTauTrackOneChargedAndNeutralsHT->SetMarkerSize(2.0);
  HadTauTrackOneChargedAndNeutralsHT->UseCurrentStyle();
  HadTauTrackOneChargedAndNeutralsHT->Write();
  SaveEfficiency(HadTauTrackOneChargedAndNeutralsHT);        
  HadTauTrackOneChargedAndNeutralsMHT = ratioCalculator(HadTauTrackOneChargedAndNeutralsMHT,HadTauTrackOneChargedAndNeutralsMHTFail);   
  HadTauTrackOneChargedAndNeutralsMHT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (1charged + neutral #tau); #slash{H}_{T} [GeV]");
  HadTauTrackOneChargedAndNeutralsMHT->SetMarkerSize(2.0);
  HadTauTrackOneChargedAndNeutralsMHT->UseCurrentStyle();
  HadTauTrackOneChargedAndNeutralsMHT->Write();
  SaveEfficiency(HadTauTrackOneChargedAndNeutralsMHT);        
  HadTauTrackOneChargedAndNeutralsNJets = ratioCalculator(HadTauTrackOneChargedAndNeutralsNJets,HadTauTrackOneChargedAndNeutralsNJetsFail);   
  HadTauTrackOneChargedAndNeutralsNJets->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (1charged + neutral #tau); N_{Jets}");
  HadTauTrackOneChargedAndNeutralsNJets->SetMarkerSize(2.0);
  HadTauTrackOneChargedAndNeutralsNJets->UseCurrentStyle();
  HadTauTrackOneChargedAndNeutralsNJets->Write();
  SaveEfficiency(HadTauTrackOneChargedAndNeutralsNJets);
  HadTauTrackOneChargedAndNeutralsBTags = ratioCalculator(HadTauTrackOneChargedAndNeutralsBTags,HadTauTrackOneChargedAndNeutralsBTagsFail);   
  HadTauTrackOneChargedAndNeutralsBTags->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #pi track eff. (1charged + neutral #tau); B_{Tags}");
  HadTauTrackOneChargedAndNeutralsBTags->SetMarkerSize(2.0);
  HadTauTrackOneChargedAndNeutralsBTags->UseCurrentStyle();
  HadTauTrackOneChargedAndNeutralsBTags->Write();
  SaveEfficiency(HadTauTrackOneChargedAndNeutralsBTags);
  
  
  MuonTrackPT = ratioCalculator(MuonTrackPT,MuonTrackPTFail);   
  MuonTrackPT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu track eff. all tracks; p_{T} [GeV]");
  MuonTrackPT->SetMarkerSize(2.0);
  MuonTrackPT->UseCurrentStyle();
  MuonTrackPT->Write();
  SaveEfficiency(MuonTrackPT);        
  MuonTrackEta = ratioCalculator(MuonTrackEta,MuonTrackEtaFail);   
  MuonTrackEta->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu track eff. all tracks; #eta");
  MuonTrackEta->SetMarkerSize(2.0);
  MuonTrackEta->UseCurrentStyle();
  MuonTrackEta->Write();
  SaveEfficiency(MuonTrackEta);        
  MuonTrackPhi = ratioCalculator(MuonTrackPhi,MuonTrackPhiFail);   
  MuonTrackPhi->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu track eff. all tracks; #phi");
  MuonTrackPhi->SetMarkerSize(2.0);
  MuonTrackPhi->UseCurrentStyle();
  MuonTrackPhi->Write();
  SaveEfficiency(MuonTrackPhi);        
  MuonTrackActivity = ratioCalculator(MuonTrackActivity,MuonTrackActivityFail);   
  MuonTrackActivity->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu track eff. all tracks; Activity [GeV]");
  MuonTrackActivity->SetMarkerSize(2.0);
  MuonTrackActivity->UseCurrentStyle();
  MuonTrackActivity->Write();
  SaveEfficiency(MuonTrackActivity);        
  MuonTrackHT = ratioCalculator(MuonTrackHT,MuonTrackHTFail);   
  MuonTrackHT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu track eff. all tracks; H_{T} [GeV]");
  MuonTrackHT->SetMarkerSize(2.0);
  MuonTrackHT->UseCurrentStyle();
  MuonTrackHT->Write();
  SaveEfficiency(MuonTrackHT);        
  MuonTrackMHT = ratioCalculator(MuonTrackMHT,MuonTrackMHTFail);   
  MuonTrackMHT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu track eff. all tracks; #slash{H}_{T} [GeV]");
  MuonTrackMHT->SetMarkerSize(2.0);
  MuonTrackMHT->UseCurrentStyle();
  MuonTrackMHT->Write();
  SaveEfficiency(MuonTrackMHT);        
  MuonTrackNJets = ratioCalculator(MuonTrackNJets,MuonTrackNJetsFail);   
  MuonTrackNJets->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu track eff. all tracks; N_{Jets}");
  MuonTrackNJets->SetMarkerSize(2.0);
  MuonTrackNJets->UseCurrentStyle();
  MuonTrackNJets->Write();
  SaveEfficiency(MuonTrackNJets);
  MuonTrackBTags = ratioCalculator(MuonTrackBTags,MuonTrackBTagsFail);   
  MuonTrackBTags->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV #mu track eff. all tracks; B_{Tags}");
  MuonTrackBTags->SetMarkerSize(2.0);
  MuonTrackBTags->UseCurrentStyle();
  MuonTrackBTags->Write();
  SaveEfficiency(MuonTrackBTags);
  
  
  ElectronTrackPT = ratioCalculator(ElectronTrackPT,ElectronTrackPTFail);   
  ElectronTrackPT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e track eff. (all tracks); p_{T} [GeV]");
  ElectronTrackPT->SetMarkerSize(2.0);
  ElectronTrackPT->UseCurrentStyle();
  ElectronTrackPT->Write();
  SaveEfficiency(ElectronTrackPT);        
  ElectronTrackEta = ratioCalculator(ElectronTrackEta,ElectronTrackEtaFail);   
  ElectronTrackEta->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e track eff. (all tracks); #eta");
  ElectronTrackEta->SetMarkerSize(2.0);
  ElectronTrackEta->UseCurrentStyle();
  ElectronTrackEta->Write();
  SaveEfficiency(ElectronTrackEta);        
  ElectronTrackPhi = ratioCalculator(ElectronTrackPhi,ElectronTrackPhiFail);   
  ElectronTrackPhi->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e track eff. (all tracks); #phi");
  ElectronTrackPhi->SetMarkerSize(2.0);
  ElectronTrackPhi->UseCurrentStyle();
  ElectronTrackPhi->Write();
  SaveEfficiency(ElectronTrackPhi);        
  ElectronTrackActivity = ratioCalculator(ElectronTrackActivity,ElectronTrackActivityFail);   
  ElectronTrackActivity->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e track eff. (all tracks); Activity [GeV]");
  ElectronTrackActivity->SetMarkerSize(2.0);
  ElectronTrackActivity->UseCurrentStyle();
  ElectronTrackActivity->Write();
  SaveEfficiency(ElectronTrackActivity);        
  ElectronTrackHT = ratioCalculator(ElectronTrackHT,ElectronTrackHTFail);   
  ElectronTrackHT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e track eff. (all tracks); H_{T} [GeV]");
  ElectronTrackHT->SetMarkerSize(2.0);
  ElectronTrackHT->UseCurrentStyle();
  ElectronTrackHT->Write();
  SaveEfficiency(ElectronTrackHT);        
  ElectronTrackMHT = ratioCalculator(ElectronTrackMHT,ElectronTrackMHTFail);   
  ElectronTrackMHT->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e track eff. (all tracks); #slash{H}_{T} [GeV]");
  ElectronTrackMHT->SetMarkerSize(2.0);
  ElectronTrackMHT->UseCurrentStyle();
  ElectronTrackMHT->Write();
  SaveEfficiency(ElectronTrackMHT);        
  ElectronTrackNJets = ratioCalculator(ElectronTrackNJets,ElectronTrackNJetsFail);   
  ElectronTrackNJets->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e track eff. (all tracks); N_{Jets}");
  ElectronTrackNJets->SetMarkerSize(2.0);
  ElectronTrackNJets->UseCurrentStyle();
  ElectronTrackNJets->Write();
  SaveEfficiency(ElectronTrackNJets);
  ElectronTrackBTags = ratioCalculator(ElectronTrackBTags,ElectronTrackBTagsFail);   
  ElectronTrackBTags->SetTitle("Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV e track eff. (all tracks); B_{Tags}");
  ElectronTrackBTags->SetMarkerSize(2.0);
  ElectronTrackBTags->UseCurrentStyle();
  ElectronTrackBTags->Write();
  SaveEfficiency(ElectronTrackBTags);
  // ************************************************************************************************************* 04 July 2015 end****************************************************
  
  std::cout<<"Done part one...."<<std::endl;
  
  
  
  
  // storing TEfficiency objectes in the file these ones should compute the efficiencies and also the errors correctly
  
  outPutFile->cd();
  outPutFile->mkdir("TEfficiencies");
  TDirectory *dTEfficiencies = (TDirectory*)outPutFile->Get("TEfficiencies");
  dTEfficiencies->cd();
  
  // TEfficiencies used efficiencies
  MuPurityBTagEff_->saveResults(dTEfficiencies);
  MuPurityNJetsEff_->saveResults(dTEfficiencies);
  MuPurityHTEff_->saveResults(dTEfficiencies);
  MuPurityMHTEff_->saveResults(dTEfficiencies);
  MuPurityPTEff_->saveResults(dTEfficiencies);
  MuPurityActivityEff_->saveResults(dTEfficiencies);
  
  MuonPurityMHTNJetEff_->saveResults(dTEfficiencies);
  
  
  ElecPurityBTagEff_->saveResults(dTEfficiencies);
  ElecPurityNJetsEff_->saveResults(dTEfficiencies);
  ElecPurityHTEff_->saveResults(dTEfficiencies);
  ElecPurityMHTEff_->saveResults(dTEfficiencies);
  ElecPurityPTEff_->saveResults(dTEfficiencies);
  ElecPurityActivityEff_->saveResults(dTEfficiencies);
  
  ElecPurityMHTNJetEff_->saveResults(dTEfficiencies);
  
  MuAccBTagEff_->saveResults(dTEfficiencies);
  MuAccNJetsEff_->saveResults(dTEfficiencies);
  MuAccHTEff_->saveResults(dTEfficiencies);
  MuAccMHTEff_->saveResults(dTEfficiencies);
  MuAccPTEff_->saveResults(dTEfficiencies);
  MuAccActivityEff_->saveResults(dTEfficiencies);
  
  MuAccHTNJetsEff_->saveResults(dTEfficiencies);
  MuAccMHTNJetsEff_->saveResults(dTEfficiencies);
  MuAccBTagNJetsEff_->saveResults(dTEfficiencies);
  
  
  ElecAccBTagEff_->saveResults(dTEfficiencies);
  ElecAccNJetsEff_->saveResults(dTEfficiencies);
  ElecAccHTEff_->saveResults(dTEfficiencies);
  ElecAccMHTEff_->saveResults(dTEfficiencies);
  ElecAccPTEff_->saveResults(dTEfficiencies);
  ElecAccActivityEff_->saveResults(dTEfficiencies);
  
  ElecAccHTNJetsEff_->saveResults(dTEfficiencies);
  ElecAccMHTNJetsEff_->saveResults(dTEfficiencies);
  ElecAccBTagNJetsEff_->saveResults(dTEfficiencies);
  
  
  MuRecoBTagEff_->saveResults(dTEfficiencies);
  MuRecoNJetsEff_->saveResults(dTEfficiencies);
  MuRecoHTEff_->saveResults(dTEfficiencies);
  MuRecoMHTEff_->saveResults(dTEfficiencies);
  MuRecoPTEff_->saveResults(dTEfficiencies);
  MuRecoActivityEff_->saveResults(dTEfficiencies);
  
  MuRecoPTActivityEff_->saveResults(dTEfficiencies);
  
  
  ElecRecoBTagEff_->saveResults(dTEfficiencies);
  ElecRecoNJetsEff_->saveResults(dTEfficiencies);
  ElecRecoHTEff_->saveResults(dTEfficiencies);
  ElecRecoMHTEff_->saveResults(dTEfficiencies);
  ElecRecoPTEff_->saveResults(dTEfficiencies);
  ElecRecoActivityEff_->saveResults(dTEfficiencies);
  
  ElecRecoPTActivityEff_->saveResults(dTEfficiencies);
  
  
  MuIsoBTagEff_->saveResults(dTEfficiencies);
  MuIsoNJetsEff_->saveResults(dTEfficiencies);
  MuIsoHTEff_->saveResults(dTEfficiencies);
  MuIsoMHTEff_->saveResults(dTEfficiencies);
  MuIsoPTEff_->saveResults(dTEfficiencies);
  MuIsoActivityEff_->saveResults(dTEfficiencies);
  
  MuIsoPTActivityEff_->saveResults(dTEfficiencies);
  
  
  ElecIsoBTagEff_->saveResults(dTEfficiencies);
  ElecIsoNJetsEff_->saveResults(dTEfficiencies);
  ElecIsoHTEff_->saveResults(dTEfficiencies);
  ElecIsoMHTEff_->saveResults(dTEfficiencies);
  ElecIsoPTEff_->saveResults(dTEfficiencies);
  ElecIsoActivityEff_->saveResults(dTEfficiencies);
  
  ElecIsoPTActivityEff_->saveResults(dTEfficiencies);
  
  
  MuMTWBTagEff_->saveResults(dTEfficiencies);
  MuMTWNJetsEff_->saveResults(dTEfficiencies);
  MuMTWHTEff_->saveResults(dTEfficiencies);
  MuMTWMHTEff_->saveResults(dTEfficiencies);
  MuMTWPTEff_->saveResults(dTEfficiencies);
  MuMTWActivityEff_->saveResults(dTEfficiencies);
  
  MuMTWPTActivityEff_->saveResults(dTEfficiencies);
  
  
  
  ElecMTWBTagEff_->saveResults(dTEfficiencies);
  ElecMTWNJetsEff_->saveResults(dTEfficiencies);
  ElecMTWHTEff_->saveResults(dTEfficiencies);
  ElecMTWMHTEff_->saveResults(dTEfficiencies);
  ElecMTWPTEff_->saveResults(dTEfficiencies);
  ElecMTWActivityEff_->saveResults(dTEfficiencies);
  
  ElecMTWPTActivityEff_->saveResults(dTEfficiencies);
  
  
  
  MuDiLepBTagEff_->saveResults(dTEfficiencies);
  MuDiLepNJetsEff_->saveResults(dTEfficiencies);
  MuDiLepHTEff_->saveResults(dTEfficiencies);
  MuDiLepMHTEff_->saveResults(dTEfficiencies);
  //      MuDiLepPTEff_->saveResults(dTEfficiencies);
  //      MuDiLepActivityEff_->saveResults(dTEfficiencies);
  
  
  ElecDiLepBTagEff_->saveResults(dTEfficiencies);
  ElecDiLepNJetsEff_->saveResults(dTEfficiencies);
  ElecDiLepHTEff_->saveResults(dTEfficiencies);
  ElecDiLepMHTEff_->saveResults(dTEfficiencies);
  //      ElecDiLepPTEff_->saveResults(dTEfficiencies);
  //      ElecDiLepActivityEff_->saveResults(dTEfficiencies);
  
  
  MuDiLepMTWBTagEff_->saveResults(dTEfficiencies);
  MuDiLepMTWNJetsEff_->saveResults(dTEfficiencies);
  MuDiLepMTWHTEff_->saveResults(dTEfficiencies);
  MuDiLepMTWMHTEff_->saveResults(dTEfficiencies);
  //      MuDiLepMTWPTEff_->saveResults(dTEfficiencies);
  //      MuDiLepMTWActivityEff_->saveResults(dTEfficiencies);
  
  
  ElecDiLepMTWBTagEff_->saveResults(dTEfficiencies);
  ElecDiLepMTWNJetsEff_->saveResults(dTEfficiencies);
  ElecDiLepMTWHTEff_->saveResults(dTEfficiencies);
  ElecDiLepMTWMHTEff_->saveResults(dTEfficiencies);
  //      ElecDiLepMTWPTEff_->saveResults(dTEfficiencies);
  //      ElecDiLepMTWActivityEff_->saveResults(dTEfficiencies);
  
  
  MuDiLepContributionBTagEff_->saveResults(dTEfficiencies);
  MuDiLepContributionNJetsEff_->saveResults(dTEfficiencies);
  MuDiLepContributionHTEff_->saveResults(dTEfficiencies);
  MuDiLepContributionMHTEff_->saveResults(dTEfficiencies);
  
  
  ElecDiLepContributionBTagEff_->saveResults(dTEfficiencies);
  ElecDiLepContributionNJetsEff_->saveResults(dTEfficiencies);
  ElecDiLepContributionHTEff_->saveResults(dTEfficiencies);
  ElecDiLepContributionMHTEff_->saveResults(dTEfficiencies);
  
  
  MuDiLepContributionMTWBTagEff_->saveResults(dTEfficiencies);
  MuDiLepContributionMTWNJetsEff_->saveResults(dTEfficiencies);
  MuDiLepContributionMTWHTEff_->saveResults(dTEfficiencies);
  MuDiLepContributionMTWMHTEff_->saveResults(dTEfficiencies);
  
  
  ElecDiLepContributionMTWBTagEff_->saveResults(dTEfficiencies);
  ElecDiLepContributionMTWNJetsEff_->saveResults(dTEfficiencies);
  ElecDiLepContributionMTWHTEff_->saveResults(dTEfficiencies);
  ElecDiLepContributionMTWMHTEff_->saveResults(dTEfficiencies);
  
  
  //      IsoTrackMuBTagEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuNJetsEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuHTEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuMHTEff_->saveResults(dTEfficiencies);
  //      
  //      
  //      IsoTrackMuMatchedToIsoMuBTagEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuMatchedToIsoMuNJetsEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuMatchedToIsoMuHTEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuMatchedToIsoMuMHTEff_->saveResults(dTEfficiencies);
  //      
  //      
  //      IsoTrackMuMTWBTagEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuMTWNJetsEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuMTWHTEff_->saveResults(dTEfficiencies);
  //      IsoTrackMuMTWMHTEff_->saveResults(dTEfficiencies);
  //      
  //      
  //      IsoTrackElecBTagEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecNJetsEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecHTEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecMHTEff_->saveResults(dTEfficiencies);
  //      
  //      
  //      IsoTrackElecMTWBTagEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecMTWNJetsEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecMTWHTEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecMTWMHTEff_->saveResults(dTEfficiencies);
  //      
  //      
  //      IsoTrackElecMatchedToIsoElecBTagEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecMatchedToIsoElecNJetsEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecMatchedToIsoElecHTEff_->saveResults(dTEfficiencies);
  //      IsoTrackElecMatchedToIsoElecMHTEff_->saveResults(dTEfficiencies);
  
  // ExpectationReductionIsoTrack
  ExpectationReductionIsoTrackBTagEff_->saveResults(dTEfficiencies);
  ExpectationReductionIsoTrackNJetsEff_->saveResults(dTEfficiencies);
  ExpectationReductionIsoTrackHTEff_->saveResults(dTEfficiencies);
  ExpectationReductionIsoTrackMHTEff_->saveResults(dTEfficiencies);
  
  
  
  outPutFile->cd();
  outPutFile->mkdir("TEfficienciesSearchBins");
  TDirectory *dTEfficienciesSearchBins = (TDirectory*)outPutFile->Get("TEfficienciesSearchBins");
  dTEfficienciesSearchBins->cd();
  MuAccSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  MuRecoSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  MuIsoSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  MuMTWSearchBinEff_->saveResults(dTEfficienciesSearchBins); 
  MuDiLepContributionMTWAppliedSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  MuDiLepEffMTWAppliedSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  MuPuritySearchBinEff_->saveResults(dTEfficienciesSearchBins);
  
  ElecAccSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  ElecRecoSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  ElecIsoSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  ElecMTWSearchBinEff_->saveResults(dTEfficienciesSearchBins); 
  ElecDiLepContributionMTWAppliedSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  ElecDiLepEffMTWAppliedSearchBinEff_->saveResults(dTEfficienciesSearchBins);
  ElecPuritySearchBinEff_->saveResults(dTEfficienciesSearchBins);
  
  ExpectationReductionIsoTrack_->saveResults(dTEfficienciesSearchBins);
  
  
  
  //      MuonPurityMHTNJetEff_->GetEfficiency()->Write();
  outPutFile->cd();
  outPutFile->mkdir("Expectation");
  TDirectory *dExpectation = (TDirectory*)outPutFile->Get("Expectation");
  dExpectation->cd();
  totalExpectation_->saveResults(dExpectation);
  
  outPutFile->Close();
  std::cout<<"IsoTrack pass: "<<IsoTrackPass<<" fail: "<<IsoTrackFail<<" eff: "<<IsoTrackPass/(IsoTrackPass+IsoTrackFail)<<std::endl;
  std::cout<<"IsoTrackMu pass: "<<IsoTrackPassMu<<" fail: "<<IsoTrackFailMu<<" eff: "<<IsoTrackPassMu/(IsoTrackFailMu)<<std::endl;
  std::cout<<"IsoTrackElec pass: "<<IsoTrackPassElec<<" fail: "<<IsoTrackFailElec<<" eff: "<<IsoTrackPassElec/(IsoTrackFailElec)<<std::endl;
  std::cout<<"IsoTrackPion pass: "<<IsoTrackPassPion<<" fail: "<<IsoTrackFailPion<<" eff: "<<IsoTrackPassPion/(IsoTrackFailPion)<<std::endl;
  std::cout<<"simple combined 1: "<<IsoTrackPassPion+IsoTrackPassElec+IsoTrackPassMu<<"Failing: "<< IsoTrackPassMu/(IsoTrackFailMu) + IsoTrackPassElec/(IsoTrackFailElec) + IsoTrackPassPion/(IsoTrackFailPion)<<std::endl;
  std::cout<<"IsoTrackCombined simple: "<<IsoTrackPassPion+IsoTrackPassElec+IsoTrackPassMu<<" fail: "<<IsoTrackFailMu+IsoTrackFailElec+IsoTrackFailPion<<" eff: "<< (IsoTrackPassPion+IsoTrackPassElec+IsoTrackPassMu)/(IsoTrackPassPion+IsoTrackPassElec+IsoTrackPassMu+IsoTrackFailMu)<<"\n";
  std::cout<<"IsoTrackCombined pass: "<<IsoTrackPassElec + IsoTrackPassMu + IsoTrackPassPion<<" fail: "<<IsoTrackFailElec + IsoTrackFailPion + IsoTrackFailMu<<" eff: "<<(IsoTrackPassElec + IsoTrackPassMu + IsoTrackPassPion )/(IsoTrackPassElec + IsoTrackPassMu + IsoTrackPassPion+IsoTrackFailElec)<<std::endl;
  std::cout<<"Test: "<< 1- (1-IsoTrackPassMu/(IsoTrackPassMu+IsoTrackFailMu) ) * (1-IsoTrackPassMu/(IsoTrackPassMu+IsoTrackFailMu) ) * (1-IsoTrackPassPion/(IsoTrackPassPion+IsoTrackFailPion) )<<"\n";
  
  IsoTrackPassMu=0;
  IsoTrackPassElec=0;
  IsoTrackPassPion=0;
  IsoTrackFail=0;
  IsoTrackFailMu=0;
  IsoTrackFailElec=0;
  IsoTrackFailPion=0;
}
TH2F* EffMaker::ratioCalculator(TH2F* passTH2, TH2F* failTH2)
{
  passTH2->Sumw2();
  TH2F *sum = (TH2F*)passTH2->Clone();
  failTH2->Sumw2();
  
  sum->Add(failTH2);
  passTH2->Divide(passTH2,sum,1,1,"B");
  return passTH2;
}
TH1F* EffMaker::ratioCalculator(TH1F* passTH1, TH1F* failTH1)
{
  passTH1->Sumw2();
  TH1F *sum = (TH1F*)passTH1->Clone();
  failTH1->Sumw2();
  
  sum->Add(failTH1);
  passTH1->Divide(passTH1,sum,1,1,"B");
  return passTH1;
}
TEfficiency* EffMaker::ratioCalculatorTEff(TH1F* passTH1, TH1F* failTH1)
{
  TEfficiency* pEff = 0;
  //      passTH1->Sumw2();
  TH1F *sum = (TH1F*)passTH1->Clone();
  //      failTH1->Sumw2();
  
  sum->Add(failTH1);
  if(TEfficiency::CheckConsistency(*passTH1,*sum, "w"))
  {
    pEff = new TEfficiency(*passTH1,*sum);
  }
  else std::cout<<"Error in ratioCalculatorTEff TH1F passing and sum not consistend!"<<std::endl;
  return pEff;
}

TEfficiency* EffMaker::ratioCalculatorTEff(TH2F* passTH2, TH2F* failTH2)
{
  TEfficiency* pEff = 0;
  //      passTH2->Sumw2();
  TH2F *sum = (TH2F*)passTH2->Clone();
  //      failTH2->Sumw2();
  
  sum->Add(failTH2);
  passTH2->Divide(passTH2,sum,1,1,"B");
  return pEff;
}
TH1F* EffMaker::ratioCalculatorSimple(TH1F* passTH1, TH1F* failTH1)
{
  passTH1->Sumw2();
  failTH1->Sumw2();
  TH1F *sum = (TH1F*)failTH1->Clone();
  
  
  //      sum->Add(failTH1);
  passTH1->Divide(passTH1,sum,1,1,"B");
  return passTH1;
}
TH2F* EffMaker::ratioCalculatorSimple(TH2F* passTH2, TH2F* failTH2)
{
  //      passTH2->Sumw2();
  TH2F *sum = (TH2F*)failTH2->Clone();
  //      failTH2->Sumw2();
  
  //      sum->Add(failTH2);
  passTH2->Divide(passTH2,sum,1,1,"B");
  return passTH2;
}

void EffMaker::SaveEfficiency(TH2F *input)
{
  gROOT->SetBatch(true);
  const TString th2Name = input->GetName();
  const TString th2Title = input->GetTitle();
  TCanvas *c1 = new TCanvas(th2Name,th2Title,650,500);
  c1->cd();
  
  std::cout<<"EffMaker::SaveEfficiency(TH2F): Name: "<<input->GetName()<<" xMin: "<<input->GetXaxis()->GetXmin()<<" xMax: "<<input->GetXaxis()->GetXmax()<<" diff: "<<(input->GetXaxis()->GetXmax() - input->GetXaxis()->GetXmin() )<<"\n";
  if(0.000001 < input->GetXaxis()->GetXmin() )
  {
    
//     if( (input->GetXaxis()->GetXmax() - input->GetXaxis()->GetXmin() ) >100)                      c1->SetLogx();
		if( (input->GetXaxis()->GetXmax() - input->GetXaxis()->GetXmin() )/input->GetXaxis()->GetXmax() >0.5) c1->SetLogx();
    
  }
  //      std::cout<<"EffMaker::SaveEfficiency(TH2F): Name: "<<input->GetName()<<" yMin: "<<input->GetYaxis()->GetXmin()<<" yMax: "<<input->GetYaxis()->GetXmax()<<" diff: "<<(input->GetYaxis()->GetXmax() - input->GetYaxis()->GetXmin() )<<"\n";
  if(0.000001 < input->GetYaxis()->GetXmin() )
  {
    
//     if( (input->GetYaxis()->GetXmax() - input->GetYaxis()->GetXmin() ) >100)                      c1->SetLogy();
if( (input->GetYaxis()->GetXmax() - input->GetYaxis()->GetXmin() )/input->GetYaxis()->GetXmax() >0.5) c1->SetLogy();
    
  }
//   if(0.0001 < input->GetXaxis()->GetXmin() )  c1->SetLogx();
//   if(0.0001 < input->GetYaxis()->GetXmin() )  c1->SetLogy();
//   if(true) c1->SetLogx();
//   c1->SetLogx();
//   c1->SetLogy();
  //      c1->SetLogx();
  //      c1->SetLogy();
  input->SetMarkerSize(2.0);
  input->UseCurrentStyle();
  input->SetMinimum(0.);
  input->SetMaximum(1.);
  input->GetZaxis()->SetLimits(0.,100.);
  input->Draw("ColZ,Text,E");
  c1->Update();
  if(saveEffToPDF_) c1->SaveAs(th2Name+".pdf");
  if(saveEffToPNG_) c1->SaveAs(th2Name+".png");
  
  // c1->SaveAs(s+"MuonAccEff3"+".png");
  //   if(saveEffToPDF_) c1->SaveAs(th2Name+".pdf");
  //   if(saveEffToPNG_) c1->SaveAs(th2Name+".png");
  
  delete c1;
  gROOT->SetBatch(false);
  
}

void EffMaker::SaveEfficiency(TH1F *input)
{
  gROOT->SetBatch(true);
  const TString th2Name = input->GetName();
  const TString th2Title = (TString)input->GetTitle();
  
  
  TCanvas *c1 = new TCanvas(th2Name,th2Title,650,500);
  c1->cd();
//   c1->SetLogx();
  //c1->SetLogy();
  
  //      std::cout<<"EffMaker::SaveEfficiency(TH1F): Name: "<<input->GetName()<<" xMin: "<<input->GetXaxis()->GetXmin()<<" xMax: "<<input->GetXaxis()->GetXmax()<<" diff: "<<(input->GetXaxis()->GetXmax() - input->GetXaxis()->GetXmin() )<<"\n";
  if(0.000001 < input->GetXaxis()->GetXmin() )
  {
//     if( (input->GetXaxis()->GetXmax() - input->GetXaxis()->GetXmin() ) >100)      c1->SetLogx();
		if( (input->GetXaxis()->GetXmax() - input->GetXaxis()->GetXmin() )/input->GetXaxis()->GetXmax() >0.5) c1->SetLogx();
    
  }
  input->SetMarkerSize(2.0);
  input->UseCurrentStyle();
  input->Draw("ColZ,Text,E");
  c1->Update();
  // c1->SaveAs(s+"MuonAccEff3"+".png");
  if(saveEffToPDF_) c1->SaveAs(th2Name+".pdf");
  if(saveEffToPNG_) c1->SaveAs(th2Name+".png");
  delete c1;
  gROOT->SetBatch(false);
  
}
double EffMaker::MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi)
{
  double deltaPhi =TVector2::Phi_mpi_pi(lepPhi-metPhi);
  return sqrt(2*lepPt*metPt*(1-cos(deltaPhi)) );
}

void TH1Feff::Fill(Double_t x,Double_t Weight, bool passOrFail)
{
  int matched=-1;
  for(unsigned int i=0; i < weights_.size();i++)
  {
    if(std::abs(weights_[i]-Weight)/Weight<0.0001 ) matched=i;
  }
  if(matched==-1)
  {
    TH1F* tempPass = (TH1F*) RefTH1F_->Clone();
    TH1F* tempFail = (TH1F*) RefTH1F_->Clone();
    TH1FPass_.push_back(tempPass );
    TH1FFail_.push_back(tempFail );
    
    if(passOrFail)
    {
      TH1FPass_[weights_.size()]->Fill(x);
    }
    else TH1FFail_[weights_.size()]->Fill(x);
    weights_.push_back(Weight);
    //              std::cout<<"Weight: "<<Weight<<"added"<<std::endl;
  }
  else
  {
    if(passOrFail) TH1FPass_[matched]->Fill(x);
    else TH1FFail_[matched]->Fill(x);
  }
}
TGraphAsymmErrors* TH1Feff::GetEfficiency()
{
  TList* myList = new TList(); 
  // compute th1 for sanity check
  TH1F* sumRef = (TH1F*) RefTH1F_->Clone();
  //      sumRef->Sumw2();
  for(unsigned int i=0; i< TH1FFail_.size();i++)
  {
    sumRef->Add(TH1FPass_[i],weights_[i]);
    RefTH1F_->Add(TH1FPass_[i],weights_[i]);
    sumRef->Add(TH1FFail_[i],weights_[i]);
  }
  RefTH1F_->Divide(RefTH1F_,sumRef,1,1,"B");
  for(unsigned int i=0; i<weights_.size();i++)
  {
    //              TH1FFail_[i]->Sumw2();
    TH1F *sum = (TH1F*)TH1FFail_[i]->Clone();
    //              TH1FPass_[i]->Sumw2();
    
    sum->Add(TH1FPass_[i]);
    TEfficiency* myEff = new TEfficiency(*TH1FPass_[i],*sum);
    //              std::cout<<"Eff["<<i<<"]: "<<myEff->GetEfficiency(14)<<" +"<<myEff->GetEfficiencyErrorUp(14)<<" - "<<myEff->GetEfficiencyErrorLow(14)<<" passed: "<<myEff->GetPassedHistogram()->GetBinContent(14)<<" totalN: "<<myEff->GetTotalHistogram()->GetBinContent(14)<<" Weight: "<<weights_[i]<<" xCenter: "<<myEff->GetPassedHistogram()->GetBinCenter(14)<<"\n";
    //              myEff->SetWeight(weights_[i]);
    myList->Add(myEff);
  }
  const Int_t size=weights_.size();
  Double_t weightArray[size];
  for(int i=0; i<size;i++)weightArray[i]=weights_[i];
  
  TGraphAsymmErrors* result= TEfficiency::Combine ((TCollection*)&*myList,(Option_t*)"kBUniform",(Int_t)weights_.size(),weightArray);
  //      std::cout<<"Total Eff: "<<result->GetY()[13]<<" + "<<result->GetEYhigh()[13]<<" - "<<result->GetErrorYlow(13)<<" x value: "<<result->GetX()[13]<<"\n";
  //      std::cout<<"-----------------------------------------------------------------Name: "<<name_ <<"\n";
  result->SetName(name_);
  result->SetTitle(title_);
  return result;
}

void TH1Feff::saveResults(TDirectory* MainDirectory)
{
  //      MainDirectory->mkdir(name_);
  //      std::cout<<"name: "<<name_<<std::endl;
  //      TDirectory *dir = (TDirectory*)MainDirectory->Get(name_);
  //      dir->cd();
  MainDirectory->cd();
  TGraphAsymmErrors* result = GetEfficiency();
  result->SetName(RefTH1F_->GetName());
  result->SetTitle(RefTH1F_->GetTitle());
  result->Write();
  TString tempName = RefTH1F_->GetName();
  tempName+="_SanityCheck";
  MainDirectory->mkdir(tempName);
  //      std::cout<<"name: "<<name_<<std::endl;
  TDirectory *sanityDir = (TDirectory*)MainDirectory->Get(tempName);
  sanityDir->cd();
  RefTH1F_->Write();
  
}


void TH2Feff::Fill(Double_t x, Double_t y, Double_t Weight, bool passOrFail)
{
  int matched=-1;
  for(unsigned int i=0; i < weights_.size();i++)
  {
    if(std::abs(weights_[i]-Weight)/Weight<0.0001 ) matched=i;
  }
  if(matched==-1)
  {
    TH2F* tempPass = (TH2F*) RefTH2F_->Clone();
    tempPass->Sumw2();
    TH2F* tempFail = (TH2F*) RefTH2F_->Clone();
    tempFail->Sumw2();
    TH2FPass_.push_back(tempPass );
    TH2FFail_.push_back(tempFail );
    
    if(passOrFail)  TH2FPass_[weights_.size()]->Fill(x,y);
    else TH2FFail_[weights_.size()]->Fill(x,y);
    weights_.push_back(Weight);
    //              std::cout<<"Weight: "<<Weight<<" added"<<std::endl;
  }
  else
  {
    if(passOrFail) TH2FPass_[matched]->Fill(x,y);
    else TH2FFail_[matched]->Fill(x,y);
  }
}
std::vector<TGraphAsymmErrors*> TH2Feff::GetEfficiency()
{ 
  const Int_t nBinsY = RefTH2F_->GetNbinsY();
  std::cout<<"Number of binsY: "<<nBinsY<<std::endl;
  std::vector<std::vector<TH1F*> > th1PassVec, th1FailVec;
  std::vector<TList*> myLists;
  // reference sum th2f
  TH2F* sumTH2ftemp = (TH2F*) RefTH2F_->Clone();
  sumTH2ftemp->Sumw2();
  
  for(unsigned int i=0; i < TH2FPass_.size();i++)
  {
    RefTH2F_->Add(TH2FPass_[i],weights_[i]);
    sumTH2ftemp->Add(TH2FPass_[i],weights_[i]);
    sumTH2ftemp->Add(TH2FFail_[i],weights_[i]);
  }
  RefTH2F_->Divide(RefTH2F_,sumTH2ftemp,1,1,"B");
  for(int i=0; i<nBinsY;i++)
  {
    myLists.push_back(new TList());
    TString temp1 ( Form ("%d", i));
    temp1= (TString)name_+"Bin"+temp1;
    TString temp2 (Form ("_%f.0-%f.0",ybins_[i],ybins_[i+1]));
    temp2= (TString)title_+temp2;
    std::vector<TH1F*> tt;
    th1PassVec.push_back(tt);
    th1FailVec.push_back(tt);
    for(unsigned int ii=0; ii<weights_.size();ii++)
    {
      TString temp3 ( Form ("%d", ii));
      temp1= temp1+"_"+temp3;
      temp3=temp1+"pass";
      th1PassVec[i].push_back(new TH1F(temp3,temp2,nbinsx_, xbins_));
      temp3=temp1+"fail";
      th1FailVec[i].push_back(new TH1F(temp3,temp2,nbinsx_, xbins_));
      for(int iii=0; iii<nbinsx_+1;iii++)
      {
        th1PassVec[i][ii]->SetBinContent(iii,TH2FPass_[ii]->GetBinContent(iii,i+1) );
        //                      std::cout<<"P:BinContent["<<i<<"]["<<ii<<"]["<<iii<<"]: "<<TH2FPass_[ii]->GetBinContent(iii,i+1)<<" +- "<<TH2FPass_[ii]->GetBinError(iii,i+1)<<std::endl;
        th1PassVec[i][ii]->SetBinError(iii,TH2FPass_[ii]->GetBinError(iii,i+1) );
        th1FailVec[i][ii]->SetBinContent(iii,TH2FFail_[ii]->GetBinContent(iii,i+1) );
        //                      std::cout<<"F:BinContent["<<i<<"]["<<ii<<"]["<<iii<<"]: "<<TH2FFail_[ii]->GetBinContent(iii,i)<<" +- "<<TH2FFail_[ii]->GetBinError(iii,i+1)<<std::endl;
        th1FailVec[i][ii]->SetBinError(iii,TH2FFail_[ii]->GetBinError(iii,i+1) );
      }
      TH1F *sum = (TH1F*)th1FailVec[i][ii]->Clone();
      //              sum->SetTitle()
      sum->Add(th1PassVec[i][ii]);
      TEfficiency* myEff = new TEfficiency(*th1PassVec[i][ii],*sum);
      //              myEff->SetWeight(weights_[i]);
      myLists[i]->Add(myEff);
    }
  }
  const Int_t size=weights_.size();
  Double_t weightArray[size];
  for(int i=0; i<size;i++)weightArray[i]=weights_[i];
  std::vector<TGraphAsymmErrors*> result; //= TEfficiency::Combine ((TCollection*)&*myList,(Option_t*)"kFCP",(Int_t)weights_.size(),weightArray);
  for(int i=0; i<nBinsY;i++)
  {
    result.push_back(TEfficiency::Combine ((TCollection*)&*myLists[i],(Option_t*)"kBUniform",(Int_t)weights_.size(),weightArray) );
  }
  
  return result;
}

void TH2Feff::saveResults(TDirectory* MainDirectory)
{
  MainDirectory->mkdir(name_);
  //      std::cout<<"name: "<<name_<<std::endl;
  TDirectory *dir = (TDirectory*)MainDirectory->Get(name_);
  dir->cd();
  RefTH2F_->SetName(name_);
  RefTH2F_->Write();
  std::vector<TGraphAsymmErrors*> result = GetEfficiency();
  for(unsigned int i=0; i<result.size();i++) 
  {
    TString temp2 (Form ("_%d-%d",(int)ybins_[i],(int)ybins_[i+1]));
    temp2= (TString)title_+temp2;
    TString temp3 ( Form ("%d", i));
    temp3= (TString)name_+temp3;
    result[i]->SetName(temp3);
    result[i]->SetTitle(temp2);
    result[i]->Write();
  }
  dir->mkdir("SanityCheck");
  //      std::cout<<"name: "<<name_<<std::endl;
  TDirectory *sanityDir = (TDirectory*)dir->Get("SanityCheck");
  sanityDir->cd();
  RefTH2F_->Write();
}
SearchBins::SearchBins()
{
  
  // HTmin,HTmax,MHTmin,MHTmax,NJetsmin,NJetsmax,BTagsmin,BTagsmax
  // NJets 4,6 BTags=0
  // fixed ht Njets btags all MHT bins
  binning=1;
  // HTmin,HTmax,MHTmin,MHTmax,NJetsmin,NJetsmax,BTagsmin,BTagsmax
  // NJets 4,6 BTags=0
  // fixed ht Njets btags all MHT bins
  if(binning==0)
  {
    bins_.push_back( Bin(500,800,200,500,4,6,-1,0) );
    bins_.push_back( Bin(800,1200,200,500,4,6,-1,0) );
    bins_.push_back( Bin(1200,99999,200,500,4,6,-1,0) );
    
    bins_.push_back( Bin(500,1200,500,750,4,6,-1,0) );
    bins_.push_back( Bin(1200,99999,500,750,4,6,-1,0) );
    
    bins_.push_back( Bin(800,99999,750,9999,4,6,-1,0) );
    
    // NJewts 7,8 BTags=0
    bins_.push_back( Bin(500,800,200,500,7,8,-1,0) );
    bins_.push_back( Bin(800,1200,200,500,7,8,-1,0) );
    bins_.push_back( Bin(1200,99999,200,500,7,8,-1,0) );
    
    bins_.push_back( Bin(500,1200,500,750,7,8,-1,0) );
    bins_.push_back( Bin(1200,99999,500,750,7,8,-1,0) );
    
    bins_.push_back( Bin(800,99999,750,9999,7,8,-1,0) );
    
    
    // NJewts 9,9999 BTags=0
    bins_.push_back( Bin(500,800,200,500,9,9999,-1,0) );
    bins_.push_back( Bin(800,1200,200,500,9,9999,-1,0) );
    bins_.push_back( Bin(1200,99999,200,500,9,9999,-1,0) );
    
    bins_.push_back( Bin(500,1200,500,750,9,9999,-1,0) );
    bins_.push_back( Bin(1200,99999,500,750,9,9999,-1,0) );
    
    bins_.push_back( Bin(800,99999,750,9999,9,9999,-1,0) );
    
    
    
    // NJets 4,6 BTags=1
    // fixed ht Njets btags all MHT bins
    bins_.push_back( Bin(500,800,200,500,4,6,1,1) );
    bins_.push_back( Bin(800,1200,200,500,4,6,1,1) );
    bins_.push_back( Bin(1200,99999,200,500,4,6,1,1) );
    
    bins_.push_back( Bin(500,1200,500,750,4,6,1,1) );
    bins_.push_back( Bin(1200,99999,500,750,4,6,1,1) );
    
    bins_.push_back( Bin(800,99999,750,9999,4,6,1,1) );
    
    // NJewts 7,8 BTags=0
    bins_.push_back( Bin(500,800,200,500,7,8,1,1) );
    bins_.push_back( Bin(800,1200,200,500,7,8,1,1) );
    bins_.push_back( Bin(1200,99999,200,500,7,8,1,1) );
    
    bins_.push_back( Bin(500,1200,500,750,7,8,1,1) );
    bins_.push_back( Bin(1200,99999,500,750,7,8,1,1) );
    
    bins_.push_back( Bin(800,99999,750,9999,7,8,1,1) );
    
    
    // NJewts 9,9999 BTags=1
    bins_.push_back( Bin(500,800,200,500,9,9999,1,1) );
    bins_.push_back( Bin(800,1200,200,500,9,9999,1,1) );
    bins_.push_back( Bin(1200,99999,200,500,9,9999,1,1) );
    
    bins_.push_back( Bin(500,1200,500,750,9,9999,1,1) );
    bins_.push_back( Bin(1200,99999,500,750,9,9999,1,1) );
    
    bins_.push_back( Bin(800,99999,750,9999,9,9999,1,1) );
    
    
    
    // NJets 4,6 BTags=2
    // fixed ht Njets btags all MHT bins
    bins_.push_back( Bin(500,800,200,500,4,6,2,2) );
    bins_.push_back( Bin(800,1200,200,500,4,6,2,2) );
    bins_.push_back( Bin(1200,99999,200,500,4,6,2,2) );
    
    bins_.push_back( Bin(500,1200,500,750,4,6,2,2) );
    bins_.push_back( Bin(1200,99999,500,750,4,6,2,2) );
    
    bins_.push_back( Bin(800,99999,750,9999,4,6,2,2) );
    
    // NJewts 7,8 BTags=2
    bins_.push_back( Bin(500,800,200,500,7,8,2,2) );
    bins_.push_back( Bin(800,1200,200,500,7,8,2,2) );
    bins_.push_back( Bin(1200,99999,200,500,7,8,2,2) );
    
    bins_.push_back( Bin(500,1200,500,750,7,8,2,2) );
    bins_.push_back( Bin(1200,99999,500,750,7,8,2,2) );
    
    bins_.push_back( Bin(800,99999,750,9999,7,8,2,2) );
    
    
    // NJewts 9,9999 BTags=2
    bins_.push_back( Bin(500,800,200,500,9,9999,2,2) );
    bins_.push_back( Bin(800,1200,200,500,9,9999,2,2) );
    bins_.push_back( Bin(1200,99999,200,500,9,9999,2,2) );
    
    bins_.push_back( Bin(500,1200,500,750,9,9999,2,2) );
    bins_.push_back( Bin(1200,99999,500,750,9,9999,2,2) );
    
    bins_.push_back( Bin(800,99999,750,9999,9,9999,2,2) );
    
    
    // NJets 4,6 BTags=>3
    // fixed ht Njets btags all MHT bins
    bins_.push_back( Bin(500,800,200,500,4,6,3,9999) );
    bins_.push_back( Bin(800,1200,200,500,4,6,3,9999) );
    bins_.push_back( Bin(1200,99999,200,500,4,6,3,9999) );
    
    bins_.push_back( Bin(500,1200,500,750,4,6,3,9999) );
    bins_.push_back( Bin(1200,99999,500,750,4,6,3,9999) );
    
    bins_.push_back( Bin(800,99999,750,9999,4,6,3,9999) );
    
    // NJewts 7,8 BTags=>3
    bins_.push_back( Bin(500,800,200,500,7,8,3,9999) );
    bins_.push_back( Bin(800,1200,200,500,7,8,3,9999) );
    bins_.push_back( Bin(1200,99999,200,500,7,8,3,9999) );
    
    bins_.push_back( Bin(500,1200,500,750,7,8,3,9999) );
    bins_.push_back( Bin(1200,99999,500,750,7,8,3,9999) );
    
    bins_.push_back( Bin(800,99999,750,9999,7,8,3,9999) );
    
    
    // NJewts 9,9999 BTags=>3
    bins_.push_back( Bin(500,800,200,500,9,9999,3,9999) );
    bins_.push_back( Bin(800,1200,200,500,9,9999,3,9999) );
    bins_.push_back( Bin(1200,99999,200,500,9,9999,3,9999) );
    
    bins_.push_back( Bin(500,1200,500,750,9,9999,3,9999) );
    bins_.push_back( Bin(1200,99999,500,750,9,9999,3,9999) );
    
    bins_.push_back( Bin(800,99999,750,9999,9,9999,3,9999) );
  }
  else if(binning==1)
  {
    bins_.push_back( Bin(500,800,200,500,4,6,-1,0) );
    bins_.push_back( Bin(800,1200,200,500,4,6,-1,0) );
    bins_.push_back( Bin(1200,99999,200,500,4,6,-1,0) );
    
    bins_.push_back( Bin(500,1200,500,750,4,6,-1,0) );
    bins_.push_back( Bin(1200,99999,500,750,4,6,-1,0) );
    
    bins_.push_back( Bin(800,99999,750,9999,4,6,-1,0) );
    
    // NJets 4,6 BTags=1
    // fixed ht Njets btags all MHT bins
    bins_.push_back( Bin(500,800,200,500,4,6,1,1) );
    bins_.push_back( Bin(800,1200,200,500,4,6,1,1) );
    bins_.push_back( Bin(1200,99999,200,500,4,6,1,1) );
    
    bins_.push_back( Bin(500,1200,500,750,4,6,1,1) );
    bins_.push_back( Bin(1200,99999,500,750,4,6,1,1) );
    
    bins_.push_back( Bin(800,99999,750,9999,4,6,1,1) );
    
    // NJets 4,6 BTags=2
    // fixed ht Njets btags all MHT bins
    bins_.push_back( Bin(500,800,200,500,4,6,2,2) );
    bins_.push_back( Bin(800,1200,200,500,4,6,2,2) );
    bins_.push_back( Bin(1200,99999,200,500,4,6,2,2) );
    
    bins_.push_back( Bin(500,1200,500,750,4,6,2,2) );
    bins_.push_back( Bin(1200,99999,500,750,4,6,2,2) );
    
    bins_.push_back( Bin(800,99999,750,9999,4,6,2,2) );
    
    // NJets 4,6 BTags=>3
    // fixed ht Njets btags all MHT bins
    bins_.push_back( Bin(500,800,200,500,4,6,3,9999) );
    bins_.push_back( Bin(800,1200,200,500,4,6,3,9999) );
    bins_.push_back( Bin(1200,99999,200,500,4,6,3,9999) );
    
    bins_.push_back( Bin(500,1200,500,750,4,6,3,9999) );
    bins_.push_back( Bin(1200,99999,500,750,4,6,3,9999) );
    
    bins_.push_back( Bin(800,99999,750,9999,4,6,3,9999) );
    
    // NJewts 7,8 BTags=0
    bins_.push_back( Bin(500,800,200,500,7,8,-1,0) );
    bins_.push_back( Bin(800,1200,200,500,7,8,-1,0) );
    bins_.push_back( Bin(1200,99999,200,500,7,8,-1,0) );
    
    bins_.push_back( Bin(500,1200,500,750,7,8,-1,0) );
    bins_.push_back( Bin(1200,99999,500,750,7,8,-1,0) );
    
    bins_.push_back( Bin(800,99999,750,9999,7,8,-1,0) );
    
    // NJewts 7,8 BTags=1
    bins_.push_back( Bin(500,800,200,500,7,8,1,1) );
    bins_.push_back( Bin(800,1200,200,500,7,8,1,1) );
    bins_.push_back( Bin(1200,99999,200,500,7,8,1,1) );
    
    bins_.push_back( Bin(500,1200,500,750,7,8,1,1) );
    bins_.push_back( Bin(1200,99999,500,750,7,8,1,1) );
    
    bins_.push_back( Bin(800,99999,750,9999,7,8,1,1) );
    
    // NJewts 7,8 BTags=2
    bins_.push_back( Bin(500,800,200,500,7,8,2,2) );
    bins_.push_back( Bin(800,1200,200,500,7,8,2,2) );
    bins_.push_back( Bin(1200,99999,200,500,7,8,2,2) );
    
    bins_.push_back( Bin(500,1200,500,750,7,8,2,2) );
    bins_.push_back( Bin(1200,99999,500,750,7,8,2,2) );
    
    bins_.push_back( Bin(800,99999,750,9999,7,8,2,2) );
    
    // NJewts 7,8 BTags=>3
    bins_.push_back( Bin(500,800,200,500,7,8,3,9999) );
    bins_.push_back( Bin(800,1200,200,500,7,8,3,9999) );
    bins_.push_back( Bin(1200,99999,200,500,7,8,3,9999) );
    
    bins_.push_back( Bin(500,1200,500,750,7,8,3,9999) );
    bins_.push_back( Bin(1200,99999,500,750,7,8,3,9999) );
    
    bins_.push_back( Bin(800,99999,750,9999,7,8,3,9999) );
    
    
    // NJewts 9,9999 BTags=0
    bins_.push_back( Bin(500,800,200,500,9,9999,-1,0) );
    bins_.push_back( Bin(800,1200,200,500,9,9999,-1,0) );
    bins_.push_back( Bin(1200,99999,200,500,9,9999,-1,0) );
    
    bins_.push_back( Bin(500,1200,500,750,9,9999,-1,0) );
    bins_.push_back( Bin(1200,99999,500,750,9,9999,-1,0) );
    
    bins_.push_back( Bin(800,99999,750,9999,9,9999,-1,0) );
    
    
    // NJewts 9,9999 BTags=1
    bins_.push_back( Bin(500,800,200,500,9,9999,1,1) );
    bins_.push_back( Bin(800,1200,200,500,9,9999,1,1) );
    bins_.push_back( Bin(1200,99999,200,500,9,9999,1,1) );
    
    bins_.push_back( Bin(500,1200,500,750,9,9999,1,1) );
    bins_.push_back( Bin(1200,99999,500,750,9,9999,1,1) );
    
    bins_.push_back( Bin(800,99999,750,9999,9,9999,1,1) );
    
    
    // NJewts 9,9999 BTags=2
    bins_.push_back( Bin(500,800,200,500,9,9999,2,2) );
    bins_.push_back( Bin(800,1200,200,500,9,9999,2,2) );
    bins_.push_back( Bin(1200,99999,200,500,9,9999,2,2) );
    
    bins_.push_back( Bin(500,1200,500,750,9,9999,2,2) );
    bins_.push_back( Bin(1200,99999,500,750,9,9999,2,2) );
    
    bins_.push_back( Bin(800,99999,750,9999,9,9999,2,2) );
    
    
    // NJewts 9,9999 BTags=>3
    bins_.push_back( Bin(500,800,200,500,9,9999,3,9999) );
    bins_.push_back( Bin(800,1200,200,500,9,9999,3,9999) );
    bins_.push_back( Bin(1200,99999,200,500,9,9999,3,9999) );
    
    bins_.push_back( Bin(500,1200,500,750,9,9999,3,9999) );
    bins_.push_back( Bin(1200,99999,500,750,9,9999,3,9999) );
    
    bins_.push_back( Bin(800,99999,750,9999,9,9999,3,9999) );
    
  }
}

unsigned int SearchBins::GetBinNumber(double HT, double MHT, int NJets, int BTags)
{
  unsigned int result =999;
  int match =-1;
  for(unsigned int i=0; i<bins_.size();i++)
  {
    //              std::cout<<"Bin["<<i<<"]: HT["<<bins_[i].HTmin_<<","<<bins_[i].HTmax_<<"] MHT["<<bins_[i].MHTmin_<<","<<bins_[i].MHTmax_<<"] NJets["<<bins_[i].NJetsmin_<<","<<bins_[i].NJetsmax_<<"] BTags["<<bins_[i].BTagsmin_<<","<<bins_[i].BTagsmax_<<"]\n";
    if(HT>bins_[i].HTmin_ && 
      HT<bins_[i].HTmax_ &&
      MHT>bins_[i].MHTmin_ && 
      MHT<bins_[i].MHTmax_ &&
      NJets+0.1>bins_[i].NJetsmin_ && 
      NJets-0.1<bins_[i].NJetsmax_ &&
      BTags+0.1>bins_[i].BTagsmin_ && 
      BTags-0.1<bins_[i].BTagsmax_
    )
    {
      result=i;
      match++;
    }
  }
  if(match==-1)
  {
    //              std::cout<<"Error event fits in no bin!!! HT: "<<HT<<", MHT: "<<MHT<<", NJets: "<<NJets<<", BTags: "<<BTags<<std::endl;
    result=999;
  }
  if(match>0)
  {
    std::cout<<"Error event fits in more than one bin!!!! HT: "<<HT<<", MHT: "<<MHT<<", NJets: "<<NJets<<", BTags: "<<BTags<<std::endl;
  }
  return result+1; // to not use the 0 bin but start counting at 1
}

Efficiency::Efficiency(const char* name, const char* title)
{
  TH1FSearchBins_= new TH1Feff (name,title,bins_.size(),0,bins_.size()+1);
  name_=name;
  title_=title;
  splitAfter_=18;
  unsigned int plotsNumber= bins_.size()/splitAfter_;
  //      std::cout<<"Efficiency::Efficiency plotsNumber="<<plotsNumber<<" number of bins: "<<bins_.size()<<std::endl;
  if(plotsNumber * splitAfter_<bins_.size() )
  {
    
    plotsNumber++;
    for(unsigned int i=0; i < plotsNumber;i++)
    {
      
      TString temp2 (Form ("_%d",(int)i+1));
      TString temp1 = name;
      temp1+=temp2;
      temp2 = title + temp2;
      const char* name1=temp1;
      const char* title1=temp2;
      
      if(i+1==plotsNumber)
      {
        //                              std::cout<<"titlelast["<<i<<"]: "<<temp1<<std::endl;
        unsigned int tempBins = bins_.size() - plotsNumber * splitAfter_;
        TH1FSearchBinsSplit_.push_back( new TH1Feff (name1,title1,tempBins,0,tempBins+1) );
        continue;
      }
      //                      std::cout<<"title["<<i<<"]: "<<temp1<<std::endl;
      TH1FSearchBinsSplit_.push_back( new TH1Feff (name1,title1,splitAfter_,0,splitAfter_+1) );
    }
  }
  else
  {
    for(unsigned int i=0; i < plotsNumber;i++)
    {
      
      TString temp2 (Form ("_%d",(int)i+1));
      TString temp1 = name;
      temp1+=temp2;
      temp2 = title + temp2;
      const char* name1=temp1;
      const char* title1=temp2;
      TH1Feff* tempeff2 = new  TH1Feff (name1,title1,splitAfter_,0,splitAfter_+1);
      TH1FSearchBinsSplit_.push_back( tempeff2 );
    }
  }
}

void Efficiency::saveResults(TDirectory* MainDirectory)
{
  MainDirectory->mkdir(name_);
  //      std::cout<<"name: "<<name_<<std::endl;
  TDirectory *dir = (TDirectory*)MainDirectory->Get(name_);
  dir->cd();
  TH1FSearchBins_->saveResults(dir);
  //      std::cout<<"TH1FSearchBinsSplit_.size(): "<<TH1FSearchBinsSplit_.size()<<std::endl;
  for(unsigned int i=0; i<TH1FSearchBinsSplit_.size();i++) 
  {
    TString temp2 (Form ("_%d",(int)i+1));
    TString temp1 = name_;
    temp1+=temp2;
    temp2 = title_ + temp2;
    const char* name1=temp1;
    const char* title1=temp2;
    TH1FSearchBinsSplit_[i]->SetTitle(title1);
    TH1FSearchBinsSplit_[i]->SetName(name1);
    TH1FSearchBinsSplit_[i]->saveResults(dir);
  }
}


void Efficiency::Fill(double HT, double MHT, int NJets, int BTags, double Weight, bool passOrFail)
{
  double bin = GetBinNumber(HT,MHT,NJets,BTags);
  
  if(bin<bins_.size()+2) 
  {
    TH1FSearchBins_->Fill(bin+0.01, Weight,passOrFail);
    unsigned int splitHist=0;
    //      std::cout<<"bin before split: "<<bin<<std::endl;
    for(int ii=0;bin>splitAfter_;ii++)
    {
      splitHist++;
      bin = bin-splitAfter_;
    }
    //              if(splitHist==3)std::cout<<"BinForSplit: "<<bin<<" with splitHistNumber "<<splitHist<<" and TH1FSearchBinsSplit_.size(): "<<TH1FSearchBinsSplit_.size()<<std::endl;
    
    TH1FSearchBinsSplit_[splitHist]->Fill(bin+0.01, Weight,passOrFail);
  }
}
SearchBinEventCount::SearchBinEventCount(const char* name)
{
  fullTH1F_ = new         TH1F(name, name, bins_.size(),0,bins_.size()+1);
  fullTH1F_->Sumw2();
  name_=name;
  splitAfter_=18;
  unsigned int plotsNumber= bins_.size()/splitAfter_;
  //      std::cout<<"Efficiency::Efficiency plotsNumber="<<plotsNumber<<" number of bins: "<<bins_.size()<<std::endl;
  if(plotsNumber * splitAfter_<bins_.size() )
  {
    
    plotsNumber++;
    for(unsigned int i=0; i < plotsNumber;i++)
    {
      
      TString temp2 (Form ("_%d",(int)i+1));
      TString temp1 = name;
      temp1+=temp2;
      temp2 = name + temp2;
      const char* name1=temp1;
      const char* title1=temp2;
      
      if(i+1==plotsNumber)
      {
        //                              std::cout<<"titlelast["<<i<<"]: "<<temp1<<std::endl;
        unsigned int tempBins = bins_.size() - plotsNumber * splitAfter_;
        splitTH1F_.push_back( new TH1F (name1,title1,tempBins,0,tempBins+1) );
        splitTH1F_[i]->Sumw2();
        continue;
      }
      //                      std::cout<<"title["<<i<<"]: "<<temp1<<std::endl;
      splitTH1F_.push_back( new TH1F (name1,title1,splitAfter_,0,splitAfter_+1) );
      splitTH1F_[i]->Sumw2();
    }
  }
  else
  {
    for(unsigned int i=0; i < plotsNumber;i++)
    {
      
      TString temp2 (Form ("_%d",(int)i+1));
      TString temp1 = name;
      temp1+=temp2;
      
      const char* name1=temp1;
      TH1F* tempeff2 = new  TH1F (name1,name1,splitAfter_,0,splitAfter_+1);
      splitTH1F_.push_back( tempeff2 );
      splitTH1F_[i]->Sumw2();
    }
  }
}


void SearchBinEventCount::Fill(double HT, double MHT, int NJets, int BTags, double Weight)
{
  double bin = GetBinNumber(HT,MHT,NJets,BTags);
  
  if(bin<bins_.size()+2) 
  {
    fullTH1F_->Fill(bin-0.01, Weight);
    unsigned int splitHist=0;
    //      std::cout<<"bin before split: "<<bin<<std::endl;
    for(int ii=0;bin>splitAfter_;ii++)
    {
      splitHist++;
      bin = bin-splitAfter_;
    }
    //              if(splitHist==3)std::cout<<"BinForSplit: "<<bin<<" with splitHistNumber "<<splitHist<<" and TH1FSearchBinsSplit_.size(): "<<TH1FSearchBinsSplit_.size()<<std::endl;
    
    splitTH1F_[splitHist]->Fill(bin-0.1, Weight);
  }
}
void SearchBinEventCount::saveResults(TDirectory* MainDirectory)
{
  MainDirectory->mkdir(name_);
  //      std::cout<<"name: "<<name_<<std::endl;
  TDirectory *dir = (TDirectory*)MainDirectory->Get(name_);
  dir->cd();
  fullTH1F_->Write();
  for(unsigned int i=0; i<splitTH1F_.size();i++) 
  {
    TString temp2 (Form ("_%d",(int)i+1));
    TString temp1 = name_;
    temp1+=temp2;
    temp2 = name_ + temp2;
    const char* name1=temp1;
    const char* title1=temp2;
    splitTH1F_[i]->SetTitle(title1);
    splitTH1F_[i]->SetName(name1);
    splitTH1F_[i]->Write();
  }
}
