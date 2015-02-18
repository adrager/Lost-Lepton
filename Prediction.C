#define Prediction_cxx
// The class definition in Prediction.h has been generated automatically
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
// Root > T->Process("Prediction.C")
// Root > T->Process("Prediction.C","some options")
// Root > T->Process("Prediction.C+")
//

#include "Prediction.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>


void Prediction::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();


}

void Prediction::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

  TFile *effInput = new TFile("/afs/desy.de/user/a/adraeger/xxl-af-cms/2015/2015_RA2/ll_macros/Efficiencies.root","UPDATE");
   TDirectory *EffInputFolder =   (TDirectory*)effInput->Get("Efficiencies");
   MuMTWPTActivity_ = (TH2F*) EffInputFolder->Get("MuMTWPTActivity");
   MuDiLepContributionMTWAppliedNJets_ = (TH1F*) EffInputFolder->Get("MuDiLepContributionMTWNJets1D");
	 MuDiLepEffMTWAppliedNJets_ = (TH1F*) EffInputFolder->Get("MuDiLepMTWNJets1D");
   MuIsoPTActivity_ = (TH2F*)EffInputFolder->Get("MuIsoPTActivity");
//     MuRecoActivitiy_ = (TH1F*)EffInputFolder->Get("MuRecoActivity");
  	 MuRecoPTActivity_= (TH2F*)EffInputFolder->Get("MuRecoPTActivity");
//    MuAccHTNJets_ = (TH2F*)EffInputFolder->Get("MuAccHTNJets");
// 	 MuAccBTagNJets_ = (TH2F*)EffInputFolder->Get("MuAccBTagNJets");
	 MuAccMHTNJets_ = (TH2F*)EffInputFolder->Get("MuAccMHTNJets");
   ElecIsoPTActivity_ = (TH2F*)EffInputFolder->Get("ElecIsoPTActivity");
//     ElecRecoActivity_ = (TH1F*)EffInputFolder->Get("ElecRecoActivity");
 	 ElecRecoPTActivity_= (TH2F*)EffInputFolder->Get("ElecRecoPTActivity");
//    ElecAccHTNJets_ = (TH2F*)EffInputFolder->Get("ElecAccHTNJets");
// 	 ElecAccBTagNJets_ = (TH2F*)EffInputFolder->Get("ElecAccBTagNJets");
	 ElecAccMHTNJets_ = (TH2F*)EffInputFolder->Get("ElecAccMHTNJets");
	 
	 ElecPurityMHTNJets_ = (TH2F*)EffInputFolder->Get("ElecPurity");
	 ElecMTWPTActivity_ = (TH2F*)EffInputFolder->Get("ElecMTWPTActivity");
	 ElecDiLepContributionMTWAppliedNJets_ = (TH1F*) EffInputFolder->Get("ElecDiLepContributionMTWNJets1D");
	 ElecDiLepEffMTWAppliedNJets_ = (TH1F*) EffInputFolder->Get("ElecDiLepMTWNJets1D");
	 
	 // load TEfficiencies
	 TDirectory *TEffInputFolder =   (TDirectory*)effInput->Get("TEfficiencies");
	 
	 MuIsoPTActivityEff_ = new THFeff(TEffInputFolder,"MuIsoPTActivity");
	 ElecIsoPTActivityEff_ = new THFeff(TEffInputFolder,"ElecIsoPTActivity");
	 MuDiLepContributionMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("MuDiLepContributionMTWNJets1D") );
	 
	 
	 MuMTWPTActivityEff_ =  new THFeff(TEffInputFolder,"MuMTWPTActivity");
	 MuDiLepContributionMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("MuDiLepContributionMTWNJets1D"));
	 MuDiLepEffMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("MuDiLepMTWNJets1D"));
	 MuIsoPTActivityEff_ =  new THFeff(TEffInputFolder,"MuIsoPTActivity");
	 MuRecoPTActivityEff_=  new THFeff(TEffInputFolder,"MuRecoPTActivity");
	 MuAccMHTNJetsEff_ =  new THFeff(TEffInputFolder,"MuAccMHTNJets");
	 ElecIsoPTActivityEff_ =  new THFeff(TEffInputFolder,"ElecIsoPTActivity");

	 ElecRecoPTActivityEff_=  new THFeff(TEffInputFolder,"ElecRecoPTActivity");
	 ElecAccMHTNJetsEff_ =  new THFeff(TEffInputFolder,"ElecAccMHTNJets");
	 
	 ElecPurityMHTNJetsEff_ =  new THFeff(TEffInputFolder,"ElecPurity");
	 ElecMTWPTActivityEff_ =  new THFeff(TEffInputFolder,"ElecMTWPTActivity");
	 ElecDiLepContributionMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("ElecDiLepContributionMTWNJets1D"));
	 ElecDiLepEffMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("ElecDiLepMTWNJets1D"));


  
   TString option = GetOption();
   tPrediction_ = new TTree("LostLeptonPrediction","a simple Tree with simple variables");
   tPrediction_->Branch("HT",&HT,"HT/F");
   tPrediction_->Branch("MHT",&MHT,"MHT/F");
   tPrediction_->Branch("NJets",&NJets,"NJets/s");
   tPrediction_->Branch("BTags",&BTags,"BTags/s");
   tPrediction_->Branch("NVtx",&NVtx,"NVtx/s");
   tPrediction_->Branch("DeltaPhi1",&DeltaPhi1,"DeltaPhi1/F");
   tPrediction_->Branch("DeltaPhi2",&DeltaPhi2,"DeltaPhi2/F");
   tPrediction_->Branch("DeltaPhi3",&DeltaPhi3,"DeltaPhi3/F");
	 tPrediction_->Branch("minDeltaPhiN",&minDeltaPhiN,"minDeltaPhiN/F");
	 tPrediction_->Branch("DeltaPhiN1",&DeltaPhiN1,"DeltaPhiN1/F");
	 tPrediction_->Branch("DeltaPhiN2",&DeltaPhiN2,"DeltaPhiN2/F");
	 tPrediction_->Branch("DeltaPhiN3",&DeltaPhiN3,"DeltaPhiN3/F");
   tPrediction_->Branch("Weight", &Weight, "Weight/F");
   tPrediction_->Branch("MET",&METPt,"MET/F");
   tPrediction_->Branch("METPhi",&METPhi,"METPhi/F");
	 tPrediction_->Branch("selectedIDIsoMuonsNum",&selectedIDIsoMuonsNum,"selectedIDIsoMuonsNum/s");
	 tPrediction_->Branch("selectedIDIsoMuonsPt", selectedIDIsoMuonsPt, "selectedIDIsoMuonsPt[selectedIDIsoMuonsNum]/F");
	 tPrediction_->Branch("selectedIDIsoMuonsEta", selectedIDIsoMuonsEta, "selectedIDIsoMuonsEta[selectedIDIsoMuonsNum]/F");
	 tPrediction_->Branch("selectedIDIsoMuonsPhi", selectedIDIsoMuonsPhi, "selectedIDIsoMuonsPhi[selectedIDIsoMuonsNum]/F");
	 tPrediction_->Branch("selectedIDIsoMuonsActivity", selectedIDIsoMuonsActivity, "selectedIDIsoMuonsActivity[selectedIDIsoMuonsNum]/F");
	 tPrediction_->Branch("RecoIsoMuonE", selectedIDIsoMuonsE, "RecoIsoMuonE[selectedIDIsoMuonsNum]/F");
	 tPrediction_->Branch("selectedIDIsoElectronsNum",&selectedIDIsoElectronsNum,"selectedIDIsoElectronsNum/s");
	 tPrediction_->Branch("RecoIsoElecPt", selectedIDIsoElectronsPt, "RecoIsoElecPt[selectedIDIsoElectronsNum]/F");
	 tPrediction_->Branch("RecoIsoElecEta", selectedIDIsoElectronsEta, "RecoIsoElecEta[selectedIDIsoElectronsNum]/F");
	 tPrediction_->Branch("RecoIsoElecPhi", selectedIDIsoElectronsPhi, "RecoIsoElecPhi[selectedIDIsoElectronsNum]/F");
	 tPrediction_->Branch("RecoIsoElecE", selectedIDIsoElectronsE, "RecoIsoElecE[selectedIDIsoElectronsNum]/F");
	 tPrediction_->Branch("selectedIDIsoElectronsActivity", selectedIDIsoElectronsActivity, "selectedIDIsoElectronsActivity[selectedIDIsoElectronsNum]/F");
   tPrediction_->Branch("MTW",&mtw,"MTW/F");
	 muActivityMethod=muActivityMethod_;
	 elecActivityMethod=elecActivityMethod_;
	 isoTrackActivityMethod=isoTrackActivityMethod_;
	 tPrediction_->Branch("muActivityMethod",&muActivityMethod,"muActivityMethod/s");  
	 tPrediction_->Branch("elecActivityMethod",&elecActivityMethod,"elecActivityMethod/s");  
	 tPrediction_->Branch("isoTrackActivityMethod",&isoTrackActivityMethod,"isoTrackActivityMethod/s");
   tPrediction_->Branch("muMTWEff",&muMTWEff_,"muMTWEff/F");
   tPrediction_->Branch("mtwCorrectedWeight",&mtwCorrectedWeight_,"mtwCorrectedWeight/F");
   tPrediction_->Branch("muDiLepContributionMTWAppliedEff",&muDiLepContributionMTWAppliedEff_,"muDiLepContributionMTWAppliedEff/F");
   tPrediction_->Branch("mtwDiLepCorrectedWeight",&mtwDiLepCorrectedWeight_,"mtwDiLepCorrectedWeight/F");
   tPrediction_->Branch("muIsoWeight",&muIsoWeight_,"muIsoWeight/F");
   tPrediction_->Branch("muIsoEff",&muIsoEff_,"muIsoEff/F");
   tPrediction_->Branch("muRecoWeight",&muRecoWeight_,"muRecoWeight/F");
   tPrediction_->Branch("muRecoEff",&muRecoEff_,"muRecoEff/F");
   tPrediction_->Branch("muAccWeight",&muAccWeight_,"muAccWeight/F");
   tPrediction_->Branch("muAccEff",&muAccEff_,"muAccEff/F");
   tPrediction_->Branch("muTotalWeight",&muTotalWeight_,"muTotalWeight/F");
   tPrediction_->Branch("totalMuons",&totalMuons_,"totalMuons/F");
   tPrediction_->Branch("elecAccWeight",&elecAccWeight_,"elecAccWeight/F");
   tPrediction_->Branch("elecAccEff",&elecAccEff_,"elecAccEff/F");
   tPrediction_->Branch("elecRecoWeight",&elecRecoWeight_,"elecRecoWeight/F");
   tPrediction_->Branch("elecRecoEff",&elecRecoEff_,"elecRecoEff/F");
   tPrediction_->Branch("elecIsoWeight",&elecIsoWeight_,"elecIsoWeight/F");
   tPrediction_->Branch("elecIsoEff",&elecIsoEff_,"elecIsoEff/F");
   tPrediction_->Branch("elecTotalWeight",&elecTotalWeight_,"elecTotalWeight/F");
	 tPrediction_->Branch("totalElectrons",&totalElectrons_,"totalElectrons/F");
   tPrediction_->Branch("totalWeight",&totalWeight_,"totalWeight/F");
	 tPrediction_->Branch("muDiLepEffMTWAppliedEff",&muDiLepEffMTWAppliedEff_,"muDiLepEffMTWAppliedEff/F");
	 tPrediction_->Branch("elecDiLepEffMTWAppliedEff",&elecDiLepEffMTWAppliedEff_,"elecDiLepEffMTWAppliedEff/F");
	 tPrediction_->Branch("totalWeightDiLep",&totalWeightDiLep_,"totalWeightDiLep/F");
	 // iso track control sample usage
	 tPrediction_->Branch("IsolatedTracksNum",&IsolatedTracksNum,"IsolatedTracksNum/s");
	 tPrediction_->Branch("IsolatedTracksPt", IsolatedTracksPt, "IsolatedTracksPt[IsolatedTracksNum]/F");
	 tPrediction_->Branch("IsolatedTracksEta", IsolatedTracksEta, "IsolatedTracksEta[IsolatedTracksNum]/F");
	 tPrediction_->Branch("IsolatedTracksPhi", IsolatedTracksPhi, "IsolatedTracksPhi[IsolatedTracksNum]/F");
	 tPrediction_->Branch("IsolatedTracksE", IsolatedTracksE, "IsolatedTracksE[IsolatedTracksNum]/F");
	 tPrediction_->Branch("IsolatedTracksMuMatched", &IsolatedTracksMuMatched_, "IsolatedTracksMuMatched/b");
	 tPrediction_->Branch("IsolatedTracksElecMatched", &IsolatedTracksElecMatched_, "IsolatedTracksElecMatched/b");
   GetOutputList()->Add(tPrediction_);
}

Bool_t Prediction::Process(Long64_t entry)
{
	resetValues();
	fChain->GetTree()->GetEntry(entry);
	if(HT<minHT_ || MHT< minMHT_ || NJets < minNJets_  ) return kTRUE;
	// 	if(DeltaPhi1 < deltaPhi1_ || DeltaPhi2 < deltaPhi2_ || DeltaPhi3 < deltaPhi3_ )return kTRUE;
	if(minDeltaPhiN<minDeltaPhiN_) return kTRUE;
	if(applyFilters_ &&  !FiltersPass() ) return kTRUE;
	if(applyFilters_ &&  !FiltersPass() ) return kTRUE;
// 	if((GenMuNum+GenElecNum)!=1) return kTRUE;
	if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
	{
	  mtw =  MTWCalculator(METPt,METPhi, selectedIDIsoMuonsPt[0], selectedIDIsoMuonsPhi[0]);
		selectedIDIsoMuonsActivity[0]=MuActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],muActivityMethod_);
		if(!UseUpdatedTEfficiencies_) muMTWEff_ = getEff(MuMTWPTActivity_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
		else muMTWEff_ = MuMTWPTActivityEff_->GetEff(selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
	  mtwCorrectedWeight_ = Weight / muMTWEff_;
		if(!UseUpdatedTEfficiencies_) muDiLepContributionMTWAppliedEff_ = getEff(MuDiLepContributionMTWAppliedNJets_,NJets);
		else muDiLepContributionMTWAppliedEff_ = MuDiLepContributionMTWAppliedNJetsEff_->GetEff(NJets);
	  mtwDiLepCorrectedWeight_ = mtwCorrectedWeight_ * muDiLepContributionMTWAppliedEff_;
		if(!UseUpdatedTEfficiencies_) muIsoEff_ = getEff(MuIsoPTActivity_, selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
		else muIsoEff_ = MuIsoPTActivityEff_->GetEff( selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
 	  muIsoWeight_ = mtwDiLepCorrectedWeight_* (1 - muIsoEff_)/muIsoEff_;
// 		muIsoWeight_ = Weight* (1 - muIsoEff_)/muIsoEff_;
//  	  muRecoEff_ = getEff(MuRecoActivitiy_,selectedIDIsoMuonsActivity[0]);
		if(!UseUpdatedTEfficiencies_) muRecoEff_ = getEff(MuRecoPTActivity_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
		else muRecoEff_ = MuRecoPTActivityEff_->GetEff(selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
	  muRecoWeight_ = mtwDiLepCorrectedWeight_* 1 / muIsoEff_ * (1-muRecoEff_)/muRecoEff_;
// 	  muAccEff_ = getEff(MuAccHTNJets_,HT,NJets);
// 		muAccEff_ = getEff(MuAccBTagNJets_,BTags,NJets);
		if(!UseUpdatedTEfficiencies_) muAccEff_ = getEff(MuAccMHTNJets_,MHT,NJets);
		else muAccEff_ = MuAccMHTNJetsEff_->GetEff(MHT,NJets);
	  muAccWeight_ = mtwDiLepCorrectedWeight_* 1 / muIsoEff_ * 1 / muRecoEff_ * (1-muAccEff_)/muAccEff_;
	  
	  muTotalWeight_ = muIsoWeight_ + muRecoWeight_ + muAccWeight_;
	  totalMuons_ = mtwDiLepCorrectedWeight_ / ( muIsoEff_ * muRecoEff_ * muAccEff_);
	  
// 	  elecAccEff_ = getEff(ElecAccHTNJets_,HT,NJets);
// 		elecAccEff_ = getEff(ElecAccBTagNJets_,BTags,NJets);
		if(!UseUpdatedTEfficiencies_) elecAccEff_ = getEff(ElecAccMHTNJets_,MHT,NJets);
		else elecAccEff_ = ElecAccMHTNJetsEff_->GetEff(MHT,NJets);
	  elecAccWeight_ = totalMuons_ * (1 - elecAccEff_);
		//  	  elecRecoEff_ = getEff(ElecRecoActivity_,ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
		if(!UseUpdatedTEfficiencies_) elecRecoEff_ = getEff(ElecRecoPTActivity_,selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
		else elecRecoEff_ = ElecRecoPTActivityEff_->GetEff(selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
	  elecRecoWeight_ = totalMuons_ * (elecAccEff_) * (1-elecRecoEff_);
		if(!UseUpdatedTEfficiencies_) elecIsoEff_ = getEff(ElecIsoPTActivity_,selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
		else elecIsoEff_= ElecIsoPTActivityEff_->GetEff(selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
	  elecIsoWeight_ = totalMuons_ * (elecAccEff_) * (elecRecoEff_) * (1-elecIsoEff_);
	  elecTotalWeight_ = elecIsoWeight_ + elecRecoWeight_ + elecAccWeight_;
	  totalWeight_ = elecTotalWeight_ + muTotalWeight_;
		muDiLepEffMTWAppliedEff_ = getEff(MuDiLepEffMTWAppliedNJets_,NJets);
		totalWeightDiLep_ = totalWeight_ + (1-muDiLepContributionMTWAppliedEff_) * mtwCorrectedWeight_ * (1-muDiLepEffMTWAppliedEff_)/muDiLepEffMTWAppliedEff_;
	  
	}	
	else if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
	{
	  mtw =  MTWCalculator(METPt,METPhi, selectedIDIsoElectronsPt[0], selectedIDIsoElectronsPhi[0]);
		selectedIDIsoElectronsActivity[0]=ElecActivity(selectedIDIsoElectronsEta[0], selectedIDIsoElectronsPhi[0],elecActivityMethod_);
		elecPurityCorrection_ =  getEff(ElecPurityMHTNJets_,MHT,NJets);
		if(!UseUpdatedTEfficiencies_) elecMTWEff_ = getEff(ElecMTWPTActivity_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
		else elecMTWEff_= ElecMTWPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
		if(!UseUpdatedTEfficiencies_) elecIsoEff_ =  getEff(ElecIsoPTActivity_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
		else elecIsoEff_ = ElecIsoPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
//  		elecRecoEff_ = getEff(ElecRecoActivity_,selectedIDIsoElectronsActivity[0]);
		if(!UseUpdatedTEfficiencies_) elecRecoEff_ = getEff(ElecRecoPTActivity_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
		else elecRecoEff_ = ElecRecoPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
// 		elecAccEff_ = getEff(ElecAccHTNJets_,HT,NJets);
// 		elecAccEff_ = getEff(ElecAccBTagNJets_,BTags,NJets);
		if(!UseUpdatedTEfficiencies_) elecAccEff_ = getEff(ElecAccMHTNJets_,MHT,NJets);
		else elecAccEff_ = ElecAccMHTNJetsEff_->GetEff(MHT,NJets);
		
// 		muAccEff_ = getEff(MuAccHTNJets_,HT,NJets);
// 		muAccEff_ = getEff(MuAccBTagNJets_,BTags,NJets);
		muAccEff_ = getEff(MuAccMHTNJets_,MHT,NJets);
//  		muRecoEff_ = getEff(MuRecoActivitiy_,selectedIDIsoElectronsActivity[0]);
		if(!UseUpdatedTEfficiencies_) muRecoEff_ = getEff(MuRecoPTActivity_, selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
		else muRecoEff_ = MuRecoPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
		if(!UseUpdatedTEfficiencies_) muIsoEff_ = getEff(MuIsoPTActivity_, selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
		else muIsoEff_ = MuIsoPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
		purityCorrectedWeight_ = Weight * elecPurityCorrection_;
		mtwCorrectedWeight_ =  purityCorrectedWeight_ / elecMTWEff_;
		if(!UseUpdatedTEfficiencies_) elecDiLepContributionMTWAppliedEff_ = getEff(ElecDiLepContributionMTWAppliedNJets_,NJets);
		else elecDiLepContributionMTWAppliedEff_ = ElecDiLepContributionMTWAppliedNJetsEff_->GetEff(NJets);
		mtwDiLepCorrectedWeight_ = mtwCorrectedWeight_ * elecDiLepContributionMTWAppliedEff_;
 		elecIsoWeight_= mtwDiLepCorrectedWeight_ * (1 - elecIsoEff_)/elecIsoEff_;
// 		elecIsoWeight_= Weight * (1 - elecIsoEff_)/elecIsoEff_;
		elecRecoWeight_ = mtwDiLepCorrectedWeight_* 1 / elecIsoEff_ * (1-elecRecoEff_)/elecRecoEff_;
		elecAccWeight_ = mtwDiLepCorrectedWeight_* 1 / elecIsoEff_ * 1 / elecRecoEff_ * (1-elecAccEff_)/elecAccEff_;
		elecTotalWeight_ = elecIsoWeight_ + elecRecoWeight_ + elecAccWeight_;
		totalElectrons_ = mtwDiLepCorrectedWeight_ / ( elecIsoEff_ * elecRecoEff_ * elecAccEff_);
		muAccWeight_ = totalElectrons_ * (1-muAccEff_);
		muRecoWeight_ = totalElectrons_ * (muAccEff_) * (1-muRecoEff_);
		muIsoWeight_ = totalElectrons_ * (muAccEff_) * (muRecoEff_) * (1-muIsoEff_);
		muTotalWeight_ = muIsoWeight_ + muRecoWeight_ + muAccWeight_;
		totalWeight_ = elecTotalWeight_ + muTotalWeight_;
		if(!UseUpdatedTEfficiencies_) elecDiLepEffMTWAppliedEff_ = getEff(ElecDiLepEffMTWAppliedNJets_,NJets);
		else elecDiLepEffMTWAppliedEff_ = ElecDiLepEffMTWAppliedNJetsEff_->GetEff(NJets);
		totalWeightDiLep_ = totalWeight_ + (1-elecDiLepContributionMTWAppliedEff_) * mtwCorrectedWeight_ * (1-elecDiLepEffMTWAppliedEff_)/elecDiLepEffMTWAppliedEff_;
	}

	if(IsolatedTracksNum==1)
	{		
		// try to match to isolated lepton
		for (unsigned  i=0; i<selectedIDIsoMuonsNum;i++)
		{
			if(deltaR(selectedIDIsoMuonsEta[i],selectedIDIsoMuonsPhi[i],IsolatedTracksEta[0],IsolatedTracksPhi[0])<maxDeltaRRecoIsoMuToTack_ && std::abs(selectedIDIsoMuonsPt[i]-IsolatedTracksPt[0])/selectedIDIsoMuonsPt[i] <maxDiffPtRecoIsoMuToTack_) IsolatedTracksMuMatched_=true;
		}
		// try to match to isolated lepton
		for (unsigned  i=0; i<selectedIDIsoElectronsNum;i++) 
		{
			if(deltaR(selectedIDIsoElectronsEta[i],selectedIDIsoElectronsPhi[i],IsolatedTracksEta[0],IsolatedTracksPhi[0])<maxDeltaRRecoIsoMuToTack_ && std::abs(selectedIDIsoElectronsPt[i]-IsolatedTracksPt[0])/selectedIDIsoElectronsPt[i] <maxDiffPtRecoIsoElecToTack_) IsolatedTracksElecMatched_=true;
		}
		// if matching to iso lepton fails try matching to reco lepton
		if(!IsolatedTracksElecMatched_ && !IsolatedTracksMuMatched_)
		{
			for(unsigned i=0 ; i<selectedIDMuonsNum;i++)
			{
				
			}
		}
		if(IsolatedTracksMuMatched_ && !IsolatedTracksElecMatched_)
		{
			
		}
		if(IsolatedTracksElecMatched_ && !IsolatedTracksMuMatched_)
		{
			
		}
	}
	if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && !IsolatedTracksMuMatched_ && !IsolatedTracksElecMatched_) return kTRUE;
	tPrediction_->Fill();
   return kTRUE;
}

void Prediction::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Prediction::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
  TFile *outPutFile = new TFile("Prediction.root","RECREATE"); ;
   outPutFile->cd();
   tPrediction_->Write();

}
void Prediction::resetValues()
{
	mtw=0.;
	muMTWEff_=0.;
	mtwCorrectedWeight_=0.;
	muDiLepContributionMTWAppliedEff_=0.;
	mtwDiLepCorrectedWeight_=0.;
	muIsoEff_=0;
	muIsoWeight_=0;
	muRecoEff_=0;
	muRecoWeight_=0;
	muAccEff_=0;
	muAccWeight_=0;
	muTotalWeight_=0.;
	totalMuons_=0;
	elecIsoEff_=0;
	elecIsoWeight_=0;
	elecRecoEff_=0;
	elecRecoWeight_=0;
	elecAccEff_=0;
	elecAccWeight_=0;
	elecTotalWeight_=0;
	totalElectrons_=0.;
	totalWeight_=0.;
	muDiLepEffMTWAppliedEff_=0.;
	elecDiLepEffMTWAppliedEff_=0.;
	totalWeightDiLep_=0.;
	// isolated track prediction
	IsolatedTracksMuMatched_=false;
	IsolatedTracksElecMatched_=false;

}
bool Prediction::FiltersPass()
{
	bool result=true;
	// if(Filter_HBHENoiseFilterRA2==0) result=false;
	return result;
}
double Prediction::deltaR(double eta1, double phi1, double eta2, double phi2)
{
	double deta = eta1-eta2;
	double dphi = TVector2::Phi_mpi_pi(phi1-phi2);
	return sqrt(deta * deta + dphi *dphi); 
}

double Prediction::MTWCalculator(double metPt,double  metPhi,double  lepPt,double  lepPhi)
{
	double deltaPhi =TVector2::Phi_mpi_pi(lepPhi-metPhi);
	return sqrt(2*lepPt*metPt*(1-cos(deltaPhi)) );
}
double Prediction::effUp(double eff, double up)
{
	double result = eff + up;
	if(result>0.995)result=0.995;
	return result;
}
double Prediction::effDown(double eff, double down)
{
	double result = eff - down;
	if(result<0.01)result=eff * 0.1;
	return result;
}

double Prediction::getEff(TH2F* effTH2F, double xValue, double yValue)
{
	double result = 0;
	if(xValue < effTH2F->GetXaxis()->GetXmin() )
	{
		std::cout<<"Warning xValue: "<<xValue<<" is smaller than minimum of histo: "<<effTH2F->GetName()<<std::endl;
		xValue= effTH2F->GetXaxis()->GetXmin()+0.01;
	}
	else if(xValue > effTH2F->GetXaxis()->GetXmax() )
	{
	  std::cout<<"Warning xValue: "<<xValue<<" is bigger than maximum of histo: "<<effTH2F->GetName()<<" which is: "<<effTH2F->GetXaxis()->GetXmax();
		xValue= effTH2F->GetXaxis()->GetXmax()-0.01;
		std::cout<<" Setting xValue to: "<<xValue<<std::endl;
		if(xValue > effTH2F->GetXaxis()->GetXmax() )std::cout<<"Problem persists!!!!!!!!!"<<std::endl;
	}
	
	if(yValue < effTH2F->GetYaxis()->GetXmin() )
	{
		std::cout<<"Warning yValue: "<<yValue<<" is smaller than minimum of histo: "<<effTH2F->GetName()<<std::endl;
		yValue= effTH2F->GetYaxis()->GetXmin()+0.01;
	}
	else if(yValue > effTH2F->GetYaxis()->GetXmax() )
	{
		std::cout<<"Warning yValue: "<<yValue<<" is bigger than maximum of histo: "<<effTH2F->GetName()<<std::endl;
		yValue= effTH2F->GetYaxis()->GetXmax()-0.01;
	}
	result = effTH2F->GetBinContent(effTH2F->GetXaxis()->FindBin(xValue),effTH2F->GetYaxis()->FindBin(yValue));
	if(result<0.01)
	{
		std::cout<<"Warning efficiency is: "<<result<<" is smaller than 1% for histo: "<<effTH2F->GetName()<<std::endl;
		result =0.01;
	}
	if(result>1)
	{
		std::cout<<"Warning efficiency is: "<<result<<" is bigger than 1 for histo: "<<effTH2F->GetName()<<std::endl;
		result =0.99;
	}
	return result;
}
double Prediction::getEff(TH1F* effTH1F, double xValue)
{
  double result = 0;
  if(xValue < effTH1F->GetXaxis()->GetXmin() )
  {
    std::cout<<"Warning xValue: "<<xValue<<" is smaller than minimum of histo: "<<effTH1F->GetName()<<std::endl;
    xValue= effTH1F->GetXaxis()->GetXmin()+0.01;
  }
  else if(xValue > effTH1F->GetXaxis()->GetXmax() )
  {
    std::cout<<"Warning xValue: "<<xValue<<" is bigger than maximum of histo: "<<effTH1F->GetName()<<" which is: "<<effTH1F->GetXaxis()->GetXmax();
    xValue= effTH1F->GetXaxis()->GetXmax()-0.01;
    std::cout<<" Setting xValue to: "<<xValue<<std::endl;
    if(xValue > effTH1F->GetXaxis()->GetXmax() )std::cout<<"Problem persists!!!!!!!!!"<<std::endl;
  }
  
  
  result = effTH1F->GetBinContent(effTH1F->GetXaxis()->FindBin(xValue));
  if(result<0.01)
  {
    std::cout<<"Warning efficiency is: "<<result<<" is smaller than 1% for histo: "<<effTH1F->GetName()<<std::endl;
    result =0.01;
  }
  if(result>1)
  {
    std::cout<<"Warning efficiency is: "<<result<<" is bigger than 1 for histo: "<<effTH1F->GetName()<<std::endl;
    result =0.99;
  }
  return result;
}

double Prediction::MuActivity( double muEta, double muPhi, unsigned int method)
{
	double result =0;
	if(method==0)
	{
		for (unsigned int i=0; i < JetsNum ; i++)
		{
			if(deltaR(muEta,muPhi,JetsEta[i],JetsPhi[i])>maxDeltaRMuActivity_ ) continue;
			result+=JetsPt[i] * (Jets_chargedEmEnergyFraction[i] + Jets_chargedHadronEnergyFraction[i]);
		}
	}
	if(method==1)
	{
		for (unsigned int i=0; i < JetsNum ; i++)
		{
			if(deltaR(muEta,muPhi,JetsEta[i],JetsPhi[i])>maxDeltaRMuActivity_ ) continue;
			result+=JetsPt[i] * (Jets_chargedEmEnergyFraction[i] + Jets_chargedHadronEnergyFraction[i])*(1/(deltaR(muEta,muPhi,JetsEta[i],JetsPhi[i])+0.5));
		}
	}
	if(method==2)
	{
		for(unsigned int i=0; i< SelectedPFCandidatesNum; i++)
		{
			if(deltaR(muEta,muPhi,SelectedPFCandidatesEta[i],SelectedPFCandidatesPhi[i])>maxDeltaRElecActivity_ ) continue;
			result+=SelectedPFCandidatesPt[i];
		}
	}
	return result;
	
}
double Prediction::ElecActivity( double elecEta, double elecPhi, unsigned int method)
{
	double result =0;
	if(method==0)
	{
		for (unsigned int i=0; i < JetsNum ; i++)
		{
			if(deltaR(elecEta,elecPhi,JetsEta[i],JetsPhi[i])>maxDeltaRElecActivity_ ) continue;
			result+=JetsPt[i] * (Jets_chargedHadronEnergyFraction[i]);
		}
	}
	if(method==1)
	{
		for (unsigned int i=0; i < JetsNum ; i++)
		{
			if(deltaR(elecEta,elecPhi,JetsEta[i],JetsPhi[i])>maxDeltaRElecActivity_ ) continue;
			result+=JetsPt[i] * (Jets_chargedHadronEnergyFraction[i])*(1/(deltaR(elecEta,elecPhi,JetsEta[i],JetsPhi[i])+0.5));
		}
	}
	if(method==2)
	{
		for(unsigned int i=0; i< SelectedPFCandidatesNum; i++)
		{
			if(deltaR(elecEta,elecPhi,SelectedPFCandidatesEta[i],SelectedPFCandidatesPhi[i])>maxDeltaRElecActivity_ ) continue;
			result+=SelectedPFCandidatesPt[i];
		}
	}
	return result;
	
}
double Prediction::IsoTrackActivityCalc( double isoTrackEta, double isoTrackPhi, unsigned int method)
{
	double result =0;
	if(method==0)
	{
		for (unsigned int i=0; i < JetsNum ; i++)
		{
			if(deltaR(isoTrackEta,isoTrackPhi,JetsEta[i],JetsPhi[i])>maxDeltaRElecActivity_ ) continue;
			result+=JetsPt[i] * (Jets_neutralEmEnergyFraction[i] + Jets_photonEnergyFraction[i]);
		}
	}
	if(method==1)
	{
		for (unsigned int i=0; i < JetsNum ; i++)
		{
			if(deltaR(isoTrackEta,isoTrackPhi,JetsEta[i],JetsPhi[i])>maxDeltaRElecActivity_ ) continue;
			result+=JetsPt[i] * (Jets_neutralEmEnergyFraction[i] + Jets_photonEnergyFraction[i])*(1/(deltaR(isoTrackEta,isoTrackPhi,JetsEta[i],JetsPhi[i])+0.5));
		}
	}
	if(method==2)
	{
		for(unsigned int i=0; i< SelectedPFCandidatesNum; i++)
		{
			if(deltaR(isoTrackEta,isoTrackPhi,SelectedPFCandidatesEta[i],SelectedPFCandidatesPhi[i])>maxDeltaRElecActivity_ ) continue;
			result+=SelectedPFCandidatesPt[i];
		}
	}
	return result;
	
}
THFeff::THFeff(TDirectory* inputFolder, const char* FolderName)
{
	useTH2f_=true;
	FolderName_=FolderName;
	TDirectory* EffFolder = (TDirectory*)inputFolder->Get(FolderName);
	TList* effList = (TList*)EffFolder->GetListOfKeys();
	effList->Print();
	TIter next(EffFolder->GetListOfKeys());
	TKey *key;
	int count =0;
	while ( (key = (TKey*)next()) )
	{
		TObject *object = key->ReadObj();
		if(object->IsA()->InheritsFrom( TH2::Class() ) )
		{
// 			std::cout<<"object: "<<object->GetName()<<" is a th2f\n";
			refTH2F_ = (TH2F*)object;
		}
		if(object->IsA()->InheritsFrom( TGraphAsymmErrors::Class() ) )
		{
// 			std::cout<<"object: "<<object->GetName()<<" is a TGraphAsymmErrors\n";
			TGraphAsymmErrorsVec_.push_back( (TGraphAsymmErrors*)object  );
		}
		count++;
	}
// 	for(unsigned int i=0; i<TGraphAsymmErrorsVec_.size();i++)
// 	{
// 		std::cout<<"TGraph["<<i<<"]: "<<TGraphAsymmErrorsVec_[i]->GetTitle()<<std::endl;
// 	}
	xMax_=0; xMin_=0; yMax_=0; yMin_=0;
	xMax_= refTH2F_->GetXaxis()->GetXmax();
	xMin_=refTH2F_->GetXaxis()->GetXmin();
	yMax_= refTH2F_->GetYaxis()->GetXmax();
	yMin_=refTH2F_->GetYaxis()->GetXmin();
// 	std::cout<<"Eff: "<<refTH2F_->GetName()<<" range: ["<<xMin_<<","<<xMax_<<"],["<<yMin_<<","<<yMax_<<"]\n"; 
}
THFeff::THFeff(TGraphAsymmErrors* inputGraph)
{
	useTH2f_=false; 
	TGraphAsymmErrorsRef_=inputGraph; 
	const unsigned int points = TGraphAsymmErrorsRef_->GetN();
	std::vector<Double_t> values(TGraphAsymmErrorsRef_->GetX(),TGraphAsymmErrorsRef_->GetX() + points);
	xMax_=-999;
	xMin_=99999;
	for(unsigned int i=0; i<values.size();i++)
	{
		if(xMax_<values[i]+TGraphAsymmErrorsRef_->GetErrorXhigh(i))xMax_=values[i]+TGraphAsymmErrorsRef_->GetErrorXhigh(i);
		if(xMin_>values[i]-TGraphAsymmErrorsRef_->GetErrorXlow(i))xMin_=values[i]-TGraphAsymmErrorsRef_->GetErrorXlow(i);
	}

	std::cout<<"TEff1D: xMax: "<<xMax_<<" xMin: "<<xMin_<<std::endl;
	
}
double THFeff::GetEff(double xValue, double yValue)
{
	if(!useTH2f_)
	{
		std::cout<<"THFeff::ERROR: Wrong use of THFeff trying to retrieve 2d eff from a 1d map!!!!!! crash...."<<std::endl;
		return -99999;
	}
	double result =0;
 	if(xValue>xMax_)
	{
		std::cout<<"THFeff::Warning xValue: "<<xValue<<" is bigger than maximum of histo: "<<refTH2F_->GetName()<<" which is: "<<xMax_;
		xValue= xMax_-0.001;
		std::cout<<" Setting xValue to: "<<xValue<<std::endl;
	}
	if(xValue<xMin_)
	{
		std::cout<<"THFeff::Warning xValue: "<<xValue<<" is smaller than min of histo: "<<refTH2F_->GetName()<<" which is: "<<xMin_;
		xValue= xMin_+0.001;
		std::cout<<" Setting xValue to: "<<xValue<<std::endl;
	}
	if(yValue>yMax_)
	{
		std::cout<<"THFeff::Warning yValue: "<<yValue<<" is bigger than maximum of histo: "<<refTH2F_->GetName()<<" which is: "<<yMax_;
		yValue= yMax_-0.001;
		std::cout<<" Setting xValue to: "<<yValue<<std::endl;
	}
	if(yValue<yMin_)
	{
		std::cout<<"THFeff::Warning yValue: "<<yValue<<" is smaller than min of histo: "<<refTH2F_->GetName()<<" which is: "<<yMin_;
		yValue= yMin_+0.001;
		std::cout<<" Setting yValue to: "<<yValue<<std::endl;
	}
	unsigned int yHistoIndex =refTH2F_->GetYaxis()->FindBin(yValue);
	if(yHistoIndex<1 || yHistoIndex>(TGraphAsymmErrorsVec_.size()+1))
	{
		std::cout<<"THFeff::Error selected HistoIndex for refTH2F: "<<refTH2F_->GetName()<<" is out of bounce: "<<yHistoIndex<<std::endl;
	}
	result = TGraphAsymmErrorsVec_[yHistoIndex-1]->Eval(xValue);
	if(result<0.01)
	{
		std::cout<<"THFeff::Warning efficiency is: "<<result<<" is smaller than 1% for histo: "<<refTH2F_->GetName()<<std::endl;
		result =0.01;
	}
	if(result>1)
	{
		std::cout<<"THFeff::Warning efficiency is: "<<result<<" is bigger than 1 for histo: "<<refTH2F_->GetName()<<std::endl;
		result =0.99;
	}
	
	return result;
}

double THFeff::GetEff(double xValue)
{
	if(useTH2f_)
	{
		std::cout<<"ERROR: Wrong use of THFeff trying to retrieve 1d eff from a 2d map!!!!!! crash...."<<std::endl;
		return -99999;
	}
	double result=0;
	if(xValue>xMax_)
	{
		std::cout<<"THFeff::Warning xValue: "<<xValue<<" is bigger than maximum of histo: "<<TGraphAsymmErrorsRef_->GetName()<<" which is: "<<xMax_;
		xValue= xMax_-0.001;
		std::cout<<" Setting xValue to: "<<xValue<<std::endl;
	}
	if(xValue<xMin_)
	{
		std::cout<<"THFeff::Warning xValue: "<<xValue<<" is smaller than min of histo: "<<TGraphAsymmErrorsRef_->GetName()<<" which is: "<<xMin_;
		xValue= xMin_+0.001;
		std::cout<<" Setting xValue to: "<<xValue<<std::endl;
	}
	result = TGraphAsymmErrorsRef_->Eval(xValue);
	if(result<0.01)
	{
		std::cout<<"THFeff::Warning efficiency is: "<<result<<" is smaller than 1% for histo: "<<TGraphAsymmErrorsRef_->GetName()<<std::endl;
		result =0.01;
	}
	if(result>1)
	{
		std::cout<<"THFeff::Warning efficiency is: "<<result<<" is bigger than 1 for histo: "<<TGraphAsymmErrorsRef_->GetName()<<std::endl;
		result =0.99;
	}
	return result;
}
