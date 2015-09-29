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
	
	TFile *effInput = new TFile("/afs/desy.de/user/a/adraeger/2015/Efficiencies.root","UPDATE");
	TDirectory *EffInputFolder =   (TDirectory*)effInput->Get("Efficiencies");
	if(UseTagAndProbeEffIso_)
	{
		TDirectory *EffTagAndProbeInputFolder =   (TDirectory*)effInput->Get("TagAndProbe");
		MuIsoPTActivityTAPMC_ = (TH2F*)EffTagAndProbeInputFolder->Get("MuIsoTagAndProbeMC");
		
		ElecIsoPTActivityTAPMC_ = (TH2F*)EffTagAndProbeInputFolder->Get("ElecIsoTagAndProbeMC");
		
	}
	if(UseTagAndProbeEffReco_)
	{
		TDirectory *EffTagAndProbeInputFolder =   (TDirectory*)effInput->Get("TagAndProbe");
		MuRecoPTActivityTAPMC_ = (TH2F*)EffTagAndProbeInputFolder->Get("MuRecoTagAndProbeMC");
		ElecRecoPTActivityTAPMC_ = (TH2F*)EffTagAndProbeInputFolder->Get("ElecRecoTagAndProbeMC");
		
	}
	//    MuMTWPTActivity_ = (TH2F*) EffInputFolder->Get("MuMTWPTActivity");
	MuMTWNJets_ = (TH1F*) EffInputFolder->Get("MuMTWNJets1D");
	MuDiLepContributionMTWAppliedNJets_ = (TH1F*) EffInputFolder->Get("MuDiLepContributionMTWNJets1D");
	MuDiLepEffMTWAppliedNJets_ = (TH1F*) EffInputFolder->Get("MuDiLepMTWNJets1D");
	MuIsoPTActivity_ = (TH2F*)EffInputFolder->Get("MuIsoPTActivity");
	MuIsoDeltaRRelPTJet_ = (TH2F*)EffInputFolder->Get("MuIsoDeltaRRelPTJet_");
	MuIsoHT_ = (TH1F*) EffInputFolder->Get("MuIsoHT1D");
	MuIsoNJets_ = (TH1F*) EffInputFolder->Get("MuIsoNJets1D");
	ElecIsoHT_ = (TH1F*) EffInputFolder->Get("ElecIsoHT1D");
	ElecIsoNJets_ = (TH1F*) EffInputFolder->Get("ElecIsoNJets1D");
	//     MuRecoActivitiy_ = (TH1F*)EffInputFolder->Get("MuRecoActivity");
	MuRecoPTActivity_= (TH2F*)EffInputFolder->Get("MuRecoPTActivity");
	//    MuAccHTNJets_ = (TH2F*)EffInputFolder->Get("MuAccHTNJets");
	//       MuAccBTagNJets_ = (TH2F*)EffInputFolder->Get("MuAccBTagNJets");
	//   MuAccMHTNJets_ = (TH2F*)EffInputFolder->Get("MuAccMHTNJets");
	MuAccHTMHT_NJets46_ = (TH2F*)EffInputFolder->Get("MuAccHTMHT_NJets46");
	MuAccHTMHT_NJets7Inf_ = (TH2F*)EffInputFolder->Get("MuAccHTMHT_NJets7Inf");
	MuPurityMHTNJets_ = (TH2F*)EffInputFolder->Get("MuonPurity");
	
	ElecIsoPTActivity_ = (TH2F*)EffInputFolder->Get("ElecIsoPTActivity");
	ElecIsoDeltaRRelPTJet_ = (TH2F*)EffInputFolder->Get("ElecIsoDeltaRRelPTJet_");
	//     ElecRecoActivity_ = (TH1F*)EffInputFolder->Get("ElecRecoActivity");
	ElecRecoPTActivity_= (TH2F*)EffInputFolder->Get("ElecRecoPTActivity");
	//    ElecAccHTNJets_ = (TH2F*)EffInputFolder->Get("ElecAccHTNJets");
	//       ElecAccBTagNJets_ = (TH2F*)EffInputFolder->Get("ElecAccBTagNJets");
	//   ElecAccMHTNJets_ = (TH2F*)EffInputFolder->Get("ElecAccMHTNJets");
	ElecAccHTMHT_NJets46_ = (TH2F*)EffInputFolder->Get("ElecAccHTMHT_NJets46");
	ElecAccHTMHT_NJets7Inf_ = (TH2F*)EffInputFolder->Get("ElecAccHTMHT_NJets7Inf");
	
	ElecPurityMHTNJets_ = (TH2F*)EffInputFolder->Get("ElecPurity");
	//       ElecMTWPTActivity_ = (TH2F*)EffInputFolder->Get("ElecMTWPTActivity");
	ElecMTWNJets_ = (TH1F*) EffInputFolder->Get("ElecMTWNJets1D");
	ElecDiLepContributionMTWAppliedNJets_ = (TH1F*) EffInputFolder->Get("ElecDiLepContributionMTWNJets1D");
	ElecDiLepEffMTWAppliedNJets_ = (TH1F*) EffInputFolder->Get("ElecDiLepMTWNJets1D");
	
	// load TEfficiencies
	TDirectory *TEffInputFolder =   (TDirectory*)effInput->Get("TEfficiencies");
	
	MuIsoPTActivityEff_ = new THFeff(TEffInputFolder,"MuIsoPTActivity");
	ElecIsoPTActivityEff_ = new THFeff(TEffInputFolder,"ElecIsoPTActivity");
	MuDiLepContributionMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("MuDiLepContributionMTWNJets1D") );
	
	
	//       MuMTWPTActivityEff_ =  new THFeff(TEffInputFolder,"MuMTWPTActivity");
	MuMTWNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("MuMTWNJets1D"));
	MuDiLepContributionMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("MuDiLepContributionMTWNJets1D"));
	MuDiLepEffMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("MuDiLepMTWNJets1D"));
	MuIsoPTActivityEff_ =  new THFeff(TEffInputFolder,"MuIsoPTActivity");
	MuRecoPTActivityEff_=  new THFeff(TEffInputFolder,"MuRecoPTActivity");
	MuAccMHTNJetsEff_ =  new THFeff(TEffInputFolder,"MuAccMHTNJets");
	ElecIsoPTActivityEff_ =  new THFeff(TEffInputFolder,"ElecIsoPTActivity");
	
	ElecRecoPTActivityEff_=  new THFeff(TEffInputFolder,"ElecRecoPTActivity");
	ElecAccMHTNJetsEff_ =  new THFeff(TEffInputFolder,"ElecAccMHTNJets");
	
	ElecPurityMHTNJetsEff_ =  new THFeff(TEffInputFolder,"ElecPurity");
	ElecPurityNJets_ = (TH1F*) EffInputFolder->Get("ElecPurityNJets1D");
	//       ElecMTWPTActivityEff_ =  new THFeff(TEffInputFolder,"ElecMTWPTActivity");
	ElecMTWNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("ElecMTWNJets1D"));
	ElecDiLepContributionMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("ElecDiLepContributionMTWNJets1D"));
	ElecDiLepEffMTWAppliedNJetsEff_ = new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("ElecDiLepMTWNJets1D"));
	
	//       ExpectationReductionIsoTrackNJetsEff_ =  new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("ExpectationReductionIsoTrackNJets1D"));
	//       ExpectationReductionIsoTrackMHTEff_ =  new THFeff( (TGraphAsymmErrors*) TEffInputFolder->Get("ExpectationReductionIsoTrackMHT1D"));
	ExpectationReductionIsoTrackNJetsEff_ =  (TH1F*)EffInputFolder->Get("ExpectationReductionIsoTrackNJetsEff");
	ExpectationReductionIsoTrackBTagsNJetsEff_= (TH2F*)EffInputFolder->Get("IsoTrackReductionBTagNJets");
	// 	ExpectationReductionMuIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("MuIsoTrackReductionPTActivity");
	// 	ExpectationReductionElecIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("ElecIsoTrackReductionPTActivity");
	
	ExpectationReductionMuIsoTrackBTagsNJetsEff_= (TH2F*)EffInputFolder->Get("MuIsoTrackReductionBTagNJets");
	ExpectationReductionElecIsoTrackBTagsNJetsEff_= (TH2F*)EffInputFolder->Get("ElecIsoTrackReductionBTagNJets");
	ExpectationReductionPionIsoTrackBTagsNJetsEff_= (TH2F*)EffInputFolder->Get("PionIsoTrackReductionBTagNJets");
	
	ExpectationReductionMuIsoMuIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("MuIsoTrackGenMuReductionPTActivity");
	ExpectationReductionMuIsoPionIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("PionIsoTrackGenMuReductionPTActivity");
	
	ExpectationReductionMuRecoMuIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("MuRecoTrackGenMuReductionPTActivity");
	ExpectationReductionMuRecoPionIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("PionRecoTrackGenMuReductionPTActivity");
	
	ExpectationReductionElecIsoElecIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("ElecIsoTrackGenElecReductionPTActivity");
	ExpectationReductionElecIsoPionIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("PionIsoTrackGenElecReductionPTActivity");
	
	ExpectationReductionElecRecoElecIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("ElecRecoTrackGenElecReductionPTActivity");
	ExpectationReductionElecRecoPionIsoTrackPTActivityEff_= (TH2F*)EffInputFolder->Get("PionRecoTrackGenElecReductionPTActivity");
	
	
	ExpectationReductionMuIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("MuIsoTrackReductionMHTNJets");
	ExpectationReductionElecIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("ElecIsoTrackReductionMHTNJets");
	// 	ExpectationReductionPionIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("PionIsoTrackReductionMHTNJets");
	
	ExpectationReductionMuIsoMuIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("MuIsoTrackGenMuReductionMHTNJets");
	ExpectationReductionMuIsoPionIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("PionIsoTrackGenMuReductionMHTNJets");
	
	ExpectationReductionMuRecoMuIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("MuRecoTrackGenMuReductionMHTNJets");
	ExpectationReductionMuRecoPionIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("PionRecoTrackGenMuReductionMHTNJets");
	
	ExpectationReductionElecIsoElecIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("ElecIsoTrackGenElecReductionMHTNJets");
	ExpectationReductionElecIsoPionIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("PionIsoTrackGenElecReductionMHTNJets");
	
	ExpectationReductionElecRecoElecIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("ElecRecoTrackGenElecReductionMHTNJets");
	ExpectationReductionElecRecoPionIsoTrackMHTNJetsEff_= (TH2F*)EffInputFolder->Get("PionRecoTrackGenElecReductionMHTNJets");
	
	
	// load search variables bined efficiencies
	searchBinsRef_ = new SearchBins();
	TDirectory *TEffSearchBinsInputFolder =   (TDirectory*)effInput->Get("TEfficienciesSearchBins");
	MuMTWSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("MuMTWSearchBinEff") )->Get("MuMTWSearchBinEff") );
	MuDiLepContributionMTWAppliedSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("MuDiLepContributionMTWAppliedSearchBinEff") )->Get("MuDiLepContributionMTWAppliedSearchBinEff") );
	MuIsoSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("MuIsoSearchBinEff") )->Get("MuIsoSearchBinEff") );
	MuRecoSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("MuRecoSearchBinEff") )->Get("MuRecoSearchBinEff") );
	MuAccSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("MuAccSearchBinEff") )->Get("MuAccSearchBinEff") );
	MuDiLepEffMTWAppliedSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("MuDiLepEffMTWAppliedSearchBinEff") )->Get("MuDiLepEffMTWAppliedSearchBinEff") );
	
	ElecIsoSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("ElecIsoSearchBinEff") )->Get("ElecIsoSearchBinEff") );
	ElecRecoSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("ElecRecoSearchBinEff") )->Get("ElecRecoSearchBinEff") );
	ElecAccSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("ElecAccSearchBinEff") )->Get("ElecAccSearchBinEff") );
	ElecPuritySearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("ElecPuritySearchBinEff") )->Get("ElecPuritySearchBinEff") );
	ElecMTWSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("ElecMTWSearchBinEff") )->Get("ElecMTWSearchBinEff") );
	ElecDiLepContributionMTWAppliedSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("ElecDiLepContributionMTWAppliedSearchBinEff") )->Get("ElecDiLepContributionMTWAppliedSearchBinEff") );
	ElecDiLepEffMTWAppliedSearchBinEff_ = new THFeff( (TGraphAsymmErrors*) ( (TDirectory*) TEffSearchBinsInputFolder->Get("ElecDiLepEffMTWAppliedSearchBinEff") )->Get("ElecDiLepEffMTWAppliedSearchBinEff") );
	
	
	
	TString option = GetOption();
	tPrediction_ = new TTree("LostLeptonPrediction","a simple Tree with simple variables");
	tPrediction_->Branch("HT",&HT,"HT/F");
	tPrediction_->Branch("MHT",&MHT,"MHT/F");
	tPrediction_->Branch("NJets",&NJets,"NJets/s");
	tPrediction_->Branch("BTags",&BTags,"BTags/s");
	tPrediction_->Branch("NVtx",&NVtx,"NVtx/s");
	tPrediction_->Branch("Bin",&Bin_,"Bin/s");
	tPrediction_->Branch("isoTracks",&isoTracks,"isoTracks/s");
	tPrediction_->Branch("Leptons",&Leptons,"Leptons/s");
	tPrediction_->Branch("DeltaPhi1",&DeltaPhi1,"DeltaPhi1/F");
	tPrediction_->Branch("DeltaPhi2",&DeltaPhi2,"DeltaPhi2/F");
	tPrediction_->Branch("DeltaPhi3",&DeltaPhi3,"DeltaPhi3/F");
	tPrediction_->Branch("minDeltaPhiN",&minDeltaPhiN,"minDeltaPhiN/F");
	tPrediction_->Branch("DeltaPhiN1",&DeltaPhiN1,"DeltaPhiN1/F");
	tPrediction_->Branch("DeltaPhiN2",&DeltaPhiN2,"DeltaPhiN2/F");
	tPrediction_->Branch("DeltaPhiN3",&DeltaPhiN3,"DeltaPhiN3/F");
	tPrediction_->Branch("Weight", &Weight, "Weight/F");
	tPrediction_->Branch("searchBin",&searchBin_,"searchBin/s");
	tPrediction_->Branch("MET",&METPt,"MET/F");
	tPrediction_->Branch("METPhi",&METPhi,"METPhi/F");
	tPrediction_->Branch("GenDeltaR",&GenDeltaR_,"GenDeltaR/F");
	tPrediction_->Branch("GenRelJetPT",&GenRelJetPT_,"GenRelJetPT/F");
	tPrediction_->Branch("AdditionalTracks",&AdditionalTracks_,"AdditionalTracks/s");
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
	tPrediction_->Branch("totalWeightDiLepIsoTrackReduced",&totalWeightDiLepIsoTrackReduced_,"totalWeightDiLepIsoTrackReduced/F");
	tPrediction_->Branch("totalWeightDiLepIsoMuTrackReduced",&totalWeightDiLepIsoMuTrackReduced_,"totalWeightDiLepIsoMuTrackReduced/F");
	tPrediction_->Branch("totalWeightDiLepIsoElecTrackReduced",&totalWeightDiLepIsoElecTrackReduced_,"totalWeightDiLepIsoElecTrackReduced/F");
	tPrediction_->Branch("totalWeightDiLepIsoPionTrackReduced",&totalWeightDiLepIsoPionTrackReduced_,"totalWeightDiLepIsoPionTrackReduced/F");
	tPrediction_->Branch("totalWeightDiLepIsoTrackReducedCombined",&totalWeightDiLepIsoTrackReducedCombined_,"totalWeightDiLepIsoTrackReducedCombined/F");
	tPrediction_->Branch("totalWeightDiLepIsoTrackReducedCombined2",&totalWeightDiLepIsoTrackReducedCombined2_,"totalWeightDiLepIsoTrackReducedCombined2/F");
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
	tPrediction_->Branch("IsoTrackReduction",&IsoTrackReduction_,"IsoTrackReduction/F");
	tPrediction_->Branch("IsoMuTrackReduction",&IsoMuTrackReduction_,"IsoMuTrackReduction/F");
	tPrediction_->Branch("IsoElecTrackReduction",&IsoElecTrackReduction_,"IsoElecTrackReduction/F");
	tPrediction_->Branch("IsoPionTrackReduction",&IsoPionTrackReduction_,"IsoPionTrackReduction/F");
	tPrediction_->Branch("IsoTrackReductionCombined",&IsoTrackReductionCombined_,"IsoTrackReductionCombined/F");
	tPrediction_->Branch("IsoTrackReductionCombined2",&IsoTrackReductionCombined2_,"IsoTrackReductionCombined2/F");
	tPrediction_->Branch("expectationReductionIsoTrackEff",&expectationReductionIsoTrackEff_,"expectationReductionIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionMuIsoTrackEff",&expectationReductionMuIsoTrackEff_,"expectationReductionMuIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionElecIsoTrackEff",&expectationReductionElecIsoTrackEff_,"expectationReductionElecIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionPionIsoTrackEff",&expectationReductionPionIsoTrackEff_,"expectationReductionPionIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionIsoTrackEffCombined",&expectationReductionIsoTrackEffCombined_,"expectationReductionIsoTrackEffCombined/F");
	tPrediction_->Branch("expectationReductionIsoTrackEffCombined2",&expectationReductionIsoTrackEffCombined2_,"expectationReductionIsoTrackEffCombined2/F");
	tPrediction_->Branch("totalWeight",&totalWeight_,"totalWeight/F");
	tPrediction_->Branch("muDiLepEffMTWAppliedEff",&muDiLepEffMTWAppliedEff_,"muDiLepEffMTWAppliedEff/F");
	tPrediction_->Branch("elecDiLepEffMTWAppliedEff",&elecDiLepEffMTWAppliedEff_,"elecDiLepEffMTWAppliedEff/F");
	tPrediction_->Branch("totalWeightDiLep",&totalWeightDiLep_,"totalWeightDiLep/F");
	// iso track control sample usage
	tPrediction_->Branch("IsolatedMuonTracksVetoNum",&IsolatedMuonTracksVetoNum,"IsolatedMuonTracksVetoNum/s");
	tPrediction_->Branch("IsolatedMuonTracksVetoPt", IsolatedMuonTracksVetoPt, "IsolatedMuonTracksVetoPt[IsolatedMuonTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedMuonTracksVetoEta", IsolatedMuonTracksVetoEta, "IsolatedMuonTracksVetoEta[IsolatedMuonTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedMuonTracksVetoPhi", IsolatedMuonTracksVetoPhi, "IsolatedMuonTracksVetoPhi[IsolatedMuonTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedMuonTracksVetoE", IsolatedMuonTracksVetoE, "IsolatedMuonTracksVetoE[IsolatedMuonTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedMuonTracksVeto_MT", IsolatedMuonTracksVeto_MT, "IsolatedMuonTracksVeto_MT[IsolatedMuonTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedElectronTracksVetoNum",&IsolatedElectronTracksVetoNum,"IsolatedElectronTracksVetoNum/s");
	tPrediction_->Branch("IsolatedElectronTracksVetoPt", IsolatedElectronTracksVetoPt, "IsolatedElectronTracksVetoPt[IsolatedElectronTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedElectronTracksVetoEta", IsolatedElectronTracksVetoEta, "IsolatedElectronTracksVetoEta[IsolatedElectronTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedElectronTracksVetoPhi", IsolatedElectronTracksVetoPhi, "IsolatedElectronTracksVetoPhi[IsolatedElectronTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedElectronTracksVetoE", IsolatedElectronTracksVetoE, "IsolatedElectronTracksVetoE[IsolatedElectronTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedElectronTracksVeto_MT", IsolatedElectronTracksVeto_MT, "IsolatedElectronTracksVeto_MT[IsolatedElectronTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedPionTracksVetoNum",&IsolatedPionTracksVetoNum,"IsolatedPionTracksVetoNum/s");
	tPrediction_->Branch("IsolatedPionTracksVetoPt", IsolatedPionTracksVetoPt, "IsolatedPionTracksVetoPt[IsolatedPionTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedPionTracksVetoEta", IsolatedPionTracksVetoEta, "IsolatedPionTracksVetoEta[IsolatedPionTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedPionTracksVetoPhi", IsolatedPionTracksVetoPhi, "IsolatedPionTracksVetoPhi[IsolatedPionTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedPionTracksVetoE", IsolatedPionTracksVetoE, "IsolatedPionTracksVetoE[IsolatedPionTracksVetoNum]/F");
	tPrediction_->Branch("IsolatedPionTracksVeto_MT", IsolatedPionTracksVeto_MT, "IsolatedPionTracksVeto_MT[IsolatedPionTracksVetoNum]/F");
	
	tPrediction_->Branch("expectationReductionMuRecoMuIsoTrackReductionWeight",&expectationReductionMuRecoMuIsoTrackReductionWeight_,"expectationReductionMuRecoMuIsoTrackReductionWeight/F");
	tPrediction_->Branch("expectationReductionMuRecoPionIsoTrackReductionWeight",&expectationReductionMuRecoPionIsoTrackReductionWeight_,"expectationReductionMuRecoPionIsoTrackReductionWeight/F");
	tPrediction_->Branch("expectationReductionMuIsoMuIsoTrackReductionWeight",&expectationReductionMuIsoMuIsoTrackReductionWeight_,"expectationReductionMuIsoMuIsoTrackReductionWeight/F");
	tPrediction_->Branch("expectationReductionMuIsoPionIsoTrackReductionWeight",&expectationReductionMuIsoPionIsoTrackReductionWeight_,"expectationReductionMuIsoPionIsoTrackReductionWeight/F");
	tPrediction_->Branch("expectationReductionElecRecoElecIsoTrackReductionWeight",&expectationReductionElecRecoElecIsoTrackReductionWeight_,"expectationReductionElecRecoElecIsoTrackReductionWeight/F");
	tPrediction_->Branch("expectationReductionElecRecoPionIsoTrackReductionWeight",&expectationReductionElecRecoPionIsoTrackReductionWeight_,"expectationReductionElecRecoPionIsoTrackReductionWeight/F");
	tPrediction_->Branch("expectationReductionElecIsoElecIsoTrackReductionWeight",&expectationReductionElecIsoElecIsoTrackReductionWeight_,"expectationReductionElecIsoElecIsoTrackReductionWeight/F");
	tPrediction_->Branch("expectationReductionElecIsoPionIsoTrackReductionWeight",&expectationReductionElecIsoPionIsoTrackReductionWeight_,"expectationReductionElecIsoPionIsoTrackReductionWeight/F");
	
	tPrediction_->Branch("expectationReductionMuRecoMuIsoTrackEff",&expectationReductionMuRecoMuIsoTrackEff_,"expectationReductionMuRecoMuIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionMuRecoPionIsoTrackEff",&expectationReductionMuRecoPionIsoTrackEff_,"expectationReductionMuRecoPionIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionMuIsoMuIsoTrackEff",&expectationReductionMuIsoMuIsoTrackEff_,"expectationReductionMuIsoMuIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionMuIsoPionIsoTrackEff",&expectationReductionMuIsoPionIsoTrackEff_,"expectationReductionMuIsoPionIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionElecRecoElecIsoTrackEff",&expectationReductionElecRecoElecIsoTrackEff_,"expectationReductionElecRecoElecIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionElecRecoPionIsoTrackEff",&expectationReductionElecRecoPionIsoTrackEff_,"expectationReductionElecRecoPionIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionElecIsoElecIsoTrackEff",&expectationReductionElecIsoElecIsoTrackEff_,"expectationReductionElecIsoElecIsoTrackEff/F");
	tPrediction_->Branch("expectationReductionElecIsoPionIsoTrackEff",&expectationReductionElecIsoPionIsoTrackEff_,"expectationReductionElecIsoPionIsoTrackEff/F");
	if(genClosure_)
	{
		tPrediction_->Branch("GenMuNum",&GenMuNum,"GenMuNum/s");
		tPrediction_->Branch("GenElecNum",&GenElecNum,"GenElecNum/s");
	}
	// Uncertainties
	tPrediction_->Branch("muIsoWeightUp",&muIsoWeightUp_,"muIsoWeightUp/F");
	tPrediction_->Branch("muIsoWeightDown",&muIsoWeightDown_,"muIsoWeightDown/F");
	tPrediction_->Branch("muRecoWeightUp",&muRecoWeightUp_,"muRecoWeightUp/F");
	tPrediction_->Branch("muRecoWeightDown",&muRecoWeightDown_,"muRecoWeightDown/F");
	tPrediction_->Branch("muAccWeightUp",&muAccWeightUp_,"muAccWeightUp/F");
	tPrediction_->Branch("muAccWeightDown",&muAccWeightDown_,"muAccWeightDown/F");  
	
	tPrediction_->Branch("elecIsoWeightUp",&elecIsoWeightUp_,"elecIsoWeightUp/F");
	tPrediction_->Branch("elecIsoWeightDown",&elecIsoWeightDown_,"elecIsoWeightDown/F");
	tPrediction_->Branch("elecRecoWeightUp",&elecRecoWeightUp_,"elecRecoWeightUp/F");
	tPrediction_->Branch("elecRecoWeightDown",&elecRecoWeightDown_,"elecRecoWeightDown/F");
	tPrediction_->Branch("elecAccWeightUp",&elecAccWeightUp_,"elecAccWeightUp/F");
	tPrediction_->Branch("elecAccWeightDown",&elecAccWeightDown_,"elecAccWeightDown/F");  
	
	tPrediction_->Branch("mtwDown",&mtwDown_,"mtwDown/F"); 
	tPrediction_->Branch("mtwUp",&mtwUp_,"mtwUp/F"); 
	tPrediction_->Branch("diLepDown",&diLepDown_,"diLepDown/F");
	tPrediction_->Branch("diLepUp",&diLepUp_,"diLepUp/F");
	tPrediction_->Branch("nonClosureUp",&nonClosureUp_,"nonClosureUp/F");
	tPrediction_->Branch("nonClosureDown",&nonClosureDown_,"nonClosureDown/F");
	
	GetOutputList()->Add(tPrediction_);
	SearchBins_ = new SearchBins();
	std::cout<<"Applying filters: "<<applyFilters_<<std::endl;
	std::cout<<"----------------"<<std::endl;
	std::cout<<"UseUpdatedTEfficiencies: "<<UseUpdatedTEfficiencies_<<std::endl;
	std::cout<<"UseTagAndProbeEffIso: "<<UseTagAndProbeEffIso_<<std::endl;
	std::cout<<"UseTagAndProbeEffReco: "<<UseTagAndProbeEffReco_<<std::endl;
	
}

Bool_t Prediction::Process(Long64_t entry)
{
	resetValues();
	fChain->GetTree()->GetEntry(entry);
	isoTracks= isoElectronTracks + isoMuonTracks + isoPionTracks;
	if(HT<minHT_ || MHT< minMHT_ || NJets < minNJets_  ) return kTRUE;
	if(DeltaPhi1 < deltaPhi1_ || DeltaPhi2 < deltaPhi2_ || DeltaPhi3 < deltaPhi3_ )return kTRUE;
	//if(minDeltaPhiN<minDeltaPhiN_) return kTRUE;
	if(applyFilters_ &&  !FiltersPass() ) return kTRUE;
			 Bin_ = SearchBins_->GetBinNumber(HT,MHT,NJets,BTags);
	//      if((GenMuNum+GenElecNum)!=1) return kTRUE;
			 searchBin_ = searchBinsRef_->GetBinNumber(HT,MHT,NJets,BTags);
			 //      expectationReductionIsoTrackEff_= ExpectationReductionIsoTrackMHTEff_->GetEff(MHT);
			 //      expectationReductionIsoTrackEff_= ExpectationReductionIsoTrackNJetsEff_->GetEff(NJets);
			 
			 //      expectationReductionIsoTrackEff_= getEff(ExpectationReductionIsoTrackNJetsEff_,NJets);
			 expectationReductionIsoTrackEff_= getEff(ExpectationReductionIsoTrackBTagsNJetsEff_,BTags,NJets);
			 if(UseBTagsNJets_)
			 {
				 expectationReductionMuIsoTrackEff_ = getEff(ExpectationReductionMuIsoTrackBTagsNJetsEff_,BTags,NJets);
				 expectationReductionElecIsoTrackEff_ = getEff(ExpectationReductionElecIsoTrackBTagsNJetsEff_,BTags,NJets);
				 expectationReductionPionIsoTrackEff_ = getEff(ExpectationReductionPionIsoTrackBTagsNJetsEff_,BTags,NJets);
				 // 		expectationReductionIsoTrackEffCombined_ = 1 - (1-expectationReductionMuIsoTrackEff_) * (1-expectationReductionElecIsoTrackEff_) * (1-expectationReductionPionIsoTrackEff_);
				 // 		expectationReductionIsoTrackEffCombined_ = 1-expectationReductionIsoTrackEffCombined_;
				 expectationReductionIsoTrackEffCombined_ = expectationReductionMuIsoTrackEff_ + expectationReductionElecIsoTrackEff_ + expectationReductionPionIsoTrackEff_;
			 }
			 if(genClosure_)
			 {
				 totalWeightDiLepIsoTrackReduced_ = Weight * (1 - expectationReductionIsoTrackEff_);
				 IsoTrackReduction_ = Weight *expectationReductionIsoTrackEff_;
				 IsoMuTrackReduction_ = Weight *expectationReductionMuIsoTrackEff_;
				 totalWeightDiLepIsoElecTrackReduced_ = Weight * (1 - expectationReductionElecIsoTrackEff_);
				 IsoElecTrackReduction_ = Weight *expectationReductionElecIsoTrackEff_;
				 totalWeightDiLepIsoPionTrackReduced_ = Weight * (1 - expectationReductionPionIsoTrackEff_);
				 IsoPionTrackReduction_ = Weight *expectationReductionPionIsoTrackEff_;
				 totalWeightDiLepIsoTrackReducedCombined_ = Weight * (1 - expectationReductionIsoTrackEffCombined_);
				 IsoTrackReductionCombined_ = Weight *expectationReductionIsoTrackEffCombined_;
			 }
			 if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
			 {
				 std::pair<double, double> temp = deltaRClosestJet(selectedIDIsoMuonsEta[0],selectedIDIsoMuonsPhi[0],selectedIDIsoMuonsPt[0]);
				 GenDeltaR_=temp.first;
				 GenRelJetPT_=selectedIDIsoMuonsPt[0]/temp.second;
				 // 		std::cout<<"Single Mu Control, pt: "<<selectedIDIsoMuonsPt[0]<<" DeltaR: "<<GenDeltaR_<<" RelJetPT: "<<GenRelJetPT_<<"\n";
				 AdditionalTracks_ = UnMatchedIsoTracks(selectedIDIsoMuonsEta[0],selectedIDIsoMuonsPhi[0],selectedIDIsoMuonsPt[0]);
				 mtw =  MTWCalculator(METPt,METPhi, selectedIDIsoMuonsPt[0], selectedIDIsoMuonsPhi[0]);
				 selectedIDIsoMuonsActivity[0]=MuActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],muActivityMethod_);
				 // 		std::cout<<"MuActivity: "<< selectedIDIsoMuonsActivity[0]<<"\n";
				 muPurityCorrection_ =  getEff(MuPurityMHTNJets_,MHT,NJets);
				 double elecActivity = ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_);
				 if(!UseBTagsNJets_)
				 {
					 std::cout<<"UseBTagsNJets_ is false\n";
					 // 		expectationReductionMuIsoTrackEff_ = getEff(ExpectationReductionMuIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
					 // 		expectationReductionElecIsoTrackEff_ = getEff(ExpectationReductionElecIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],elecActivity);
					 // 		expectationReductionPionIsoTrackEff_ = getEff(ExpectationReductionPionIsoTrackBTagsNJetsEff_,BTags,NJets);
					 // 		expectationReductionIsoTrackEffCombined_ = (1-expectationReductionMuIsoTrackEff_) * (1-expectationReductionElecIsoTrackEff_) * (1-expectationReductionPionIsoTrackEff_);
					 // 		expectationReductionIsoTrackEffCombined_ = 1-expectationReductionIsoTrackEffCombined_;
					 // 		expectationReductionIsoTrackEffCombined_ = expectationReductionMuIsoTrackEff_ + expectationReductionElecIsoTrackEff_ + expectationReductionPionIsoTrackEff_;
				 }
				 // derive expectation reduction for separated reco iso tracks
				 if(UseMHTNJets_)
				 {
					 expectationReductionMuRecoMuIsoTrackEff_ = getEff(ExpectationReductionMuRecoMuIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionMuRecoPionIsoTrackEff_= getEff(ExpectationReductionMuRecoPionIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionMuIsoMuIsoTrackEff_= getEff(ExpectationReductionMuIsoMuIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionMuIsoPionIsoTrackEff_= getEff(ExpectationReductionMuIsoPionIsoTrackMHTNJetsEff_,MHT,NJets);
					 
					 expectationReductionElecRecoElecIsoTrackEff_ = getEff(ExpectationReductionElecRecoElecIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionElecRecoPionIsoTrackEff_= getEff(ExpectationReductionElecRecoPionIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionElecIsoElecIsoTrackEff_= getEff(ExpectationReductionElecIsoElecIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionElecIsoPionIsoTrackEff_= getEff(ExpectationReductionElecIsoPionIsoTrackMHTNJetsEff_,MHT,NJets);
				 }
				 if(!UseMHTNJets_)
				 {
					 expectationReductionMuRecoMuIsoTrackEff_ = getEff(ExpectationReductionMuRecoMuIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
					 expectationReductionMuRecoPionIsoTrackEff_= getEff(ExpectationReductionMuRecoPionIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
					 expectationReductionMuIsoMuIsoTrackEff_= getEff(ExpectationReductionMuIsoMuIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
					 expectationReductionMuIsoPionIsoTrackEff_= getEff(ExpectationReductionMuIsoPionIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
					 
					 expectationReductionElecRecoElecIsoTrackEff_ = getEff(ExpectationReductionElecRecoElecIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],elecActivity);
					 expectationReductionElecRecoPionIsoTrackEff_= getEff(ExpectationReductionElecRecoPionIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],elecActivity);
					 expectationReductionElecIsoElecIsoTrackEff_= getEff(ExpectationReductionElecIsoElecIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],elecActivity);
					 expectationReductionElecIsoPionIsoTrackEff_= getEff(ExpectationReductionElecIsoPionIsoTrackPTActivityEff_,selectedIDIsoMuonsPt[0],elecActivity);
				 }
				 
				 
				 //              if(!UseUpdatedTEfficiencies_) muMTWEff_ = getEff(MuMTWPTActivity_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
				 if(!UseUpdatedTEfficiencies_) muMTWEff_ = getEff(MuMTWNJets_,NJets);
			 //              else muMTWEff_ = MuMTWPTActivityEff_->GetEff(selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
				 else muMTWEff_ = MuMTWNJetsEff_->GetEff(NJets);
			 if(MuMTWSearchBinUse_)muMTWEff_=MuMTWSearchBinEff_->GetEff(searchBin_+0.01);
			 purityCorrectedWeight_ = Weight * muPurityCorrection_;
			 mtwCorrectedWeight_ = purityCorrectedWeight_ / muMTWEff_;
			 if(!UseUpdatedTEfficiencies_) muDiLepContributionMTWAppliedEff_ = getEff(MuDiLepContributionMTWAppliedNJets_,NJets);
			 else muDiLepContributionMTWAppliedEff_ = MuDiLepContributionMTWAppliedNJetsEff_->GetEff(NJets);
			 if(MuDiLepContributionMTWAppliedEffSearchBinUse_)muDiLepContributionMTWAppliedEff_=MuDiLepContributionMTWAppliedSearchBinEff_->GetEff(searchBin_+0.01);
			 mtwDiLepCorrectedWeight_ = mtwCorrectedWeight_ * muDiLepContributionMTWAppliedEff_;
			 if(!UseUpdatedTEfficiencies_) 
			 {
				 muIsoEff_ = getEff(MuIsoPTActivity_, selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
				 if(UseDeltaRRelPT ) muIsoEff_ = getEff(MuIsoDeltaRRelPTJet_, GenDeltaR_,GenRelJetPT_);
			 }
			 //     else
			 //     {
				 //       muIsoEff_ = MuIsoPTActivityEff_->GetEff( selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
				 
				 
				 //     }
				 if(MuIsoSearchBinUse_)muIsoEff_=MuIsoSearchBinEff_->GetEff(searchBin_+0.01);
			 // //     if(UseTagAndProbeEffIso_)muIsoEff_ = getEff(MuIsoPTActivityTAPMC_, selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
				 //     if(UseHTIsoEff_) muIsoEff_ = getEff(MuIsoHT_,HT);
				 //     if(UseNJetsIsoEff_) muIsoEff_ = getEff(MuIsoNJets_,NJets+0.1);
				 //              mtwDiLepCorrectedWeight_=Weight;
				 muIsoWeight_ = mtwDiLepCorrectedWeight_* (1 - muIsoEff_)/muIsoEff_; 
				 //              muIsoWeight_ = Weight* (1 - muIsoEff_)/muIsoEff_;
				 //        muRecoEff_ = getEff(MuRecoActivitiy_,selectedIDIsoMuonsActivity[0]);
				 if(!UseUpdatedTEfficiencies_) muRecoEff_ = getEff(MuRecoPTActivity_,selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
			 else muRecoEff_ = MuRecoPTActivityEff_->GetEff(selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]);
			 if(MuRecoSearchBinUse_)muRecoEff_=MuRecoSearchBinEff_->GetEff(searchBin_+0.01);
			 if(UseTagAndProbeEffReco_)muRecoEff_ = getEff(MuRecoPTActivityTAPMC_, selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]); 
			 muRecoWeight_ = mtwDiLepCorrectedWeight_* 1 / muIsoEff_ * (1-muRecoEff_)/muRecoEff_;
			 //        muAccEff_ = getEff(MuAccHTNJets_,HT,NJets);
			 //              muAccEff_ = getEff(MuAccBTagNJets_,BTags,NJets);
			 if(!UseUpdatedTEfficiencies_) 
			 {
				 //       muAccEff_ = getEff(MuAccMHTNJets_,MHT,NJets);
				 if(NJets<6.5) muAccEff_ = getEff(MuAccHTMHT_NJets46_,HT,MHT);
			 else muAccEff_ =  getEff(MuAccHTMHT_NJets7Inf_,HT,MHT);
			 
			 }
			 else muAccEff_ = MuAccMHTNJetsEff_->GetEff(MHT,NJets);
			 if(MuAccSearchBinUse_)muAccEff_=MuAccSearchBinEff_->GetEff(searchBin_+0.01);
			 muAccWeight_ = mtwDiLepCorrectedWeight_* 1 / muIsoEff_ * 1 / muRecoEff_ * (1-muAccEff_)/muAccEff_;
			 
			 muTotalWeight_ = muIsoWeight_ + muRecoWeight_ + muAccWeight_;
			 totalMuons_ = mtwDiLepCorrectedWeight_ / ( muIsoEff_ * muRecoEff_ * muAccEff_);
			 
			 //        elecAccEff_ = getEff(ElecAccHTNJets_,HT,NJets);
			 //              elecAccEff_ = getEff(ElecAccBTagNJets_,BTags,NJets);
			 if(!UseUpdatedTEfficiencies_) 
			 {
				 //       elecAccEff_ = getEff(ElecAccMHTNJets_,MHT,NJets);
				 if(NJets<6.5) elecAccEff_ = getEff(ElecAccHTMHT_NJets46_,HT,MHT);
			 else elecAccEff_ =  getEff(ElecAccHTMHT_NJets7Inf_,HT,MHT);
			 
			 }
			 else elecAccEff_ = ElecAccMHTNJetsEff_->GetEff(MHT,NJets);
			 if(ElecAccSearchBinUse_)elecAccEff_=ElecAccSearchBinEff_->GetEff(searchBin_+0.01);
			 elecAccWeight_ = totalMuons_ * (1 - elecAccEff_);
			 //        elecRecoEff_ = getEff(ElecRecoActivity_,ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
			 if(!UseUpdatedTEfficiencies_) elecRecoEff_ = getEff(ElecRecoPTActivity_,selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
			 else elecRecoEff_ = ElecRecoPTActivityEff_->GetEff(selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
			 if(ElecRecoSearchBinUse_)elecRecoEff_=ElecRecoSearchBinEff_->GetEff(searchBin_+0.01);
			 if(UseTagAndProbeEffReco_)elecRecoEff_ = getEff(ElecRecoPTActivityTAPMC_, selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_)); 
			 elecRecoWeight_ = totalMuons_ * (elecAccEff_) * (1-elecRecoEff_);
			 if(!UseUpdatedTEfficiencies_) 
			 {
				 elecIsoEff_ = getEff(ElecIsoPTActivity_,selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
				 if(UseDeltaRRelPT ) elecIsoEff_ = getEff(ElecIsoDeltaRRelPTJet_, GenDeltaR_,GenRelJetPT_);
			 }
			 //     else 
			 // 		{
				 // 			elecIsoEff_= ElecIsoPTActivityEff_->GetEff(selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_));
				 // 			if(UseDeltaRRelPT ) elecIsoEff_ = ElecIsoDeltaRRelPTJet_->GetEff( GenDeltaR_,GenRelJetPT_);
				 // 		}
				 //     if(ElecIsoSearchBinUse_)elecIsoEff_=ElecIsoSearchBinEff_->GetEff(searchBin_+0.01);
				 //     if(UseTagAndProbeEffIso_)elecIsoEff_ = getEff(ElecIsoPTActivityTAPMC_, selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_)); 
				 //     if(UseHTIsoEff_) elecIsoEff_ = getEff(ElecIsoHT_,HT);
				 //     if(UseNJetsIsoEff_) elecIsoEff_ = getEff(ElecIsoNJets_,NJets+0.1);
				 elecIsoWeight_ = totalMuons_ * (elecAccEff_) * (elecRecoEff_) * (1-elecIsoEff_);
				 elecTotalWeight_ = elecIsoWeight_ + elecRecoWeight_ + elecAccWeight_;
				 totalWeight_ = elecTotalWeight_ + muTotalWeight_;
				 if(!UseUpdatedTEfficiencies_) muDiLepEffMTWAppliedEff_ = getEff(MuDiLepEffMTWAppliedNJets_,NJets);
			 else muDiLepEffMTWAppliedEff_= MuDiLepContributionMTWAppliedNJetsEff_->GetEff(NJets);
			 if(MuDiLepContributionMTWAppliedEffSearchBinUse_)muDiLepEffMTWAppliedEff_=MuDiLepEffMTWAppliedSearchBinEff_->GetEff(searchBin_+0.01);
			 totalWeightDiLep_ = totalWeight_ + (1-muDiLepContributionMTWAppliedEff_) * mtwCorrectedWeight_ * (1-muDiLepEffMTWAppliedEff_)/muDiLepEffMTWAppliedEff_;
			 totalWeightDiLepIsoTrackReduced_ = totalWeightDiLep_ * (1 - expectationReductionIsoTrackEff_);
			 IsoTrackReduction_ = totalWeightDiLep_ *expectationReductionIsoTrackEff_;
			 totalWeightDiLepIsoMuTrackReduced_ = totalWeightDiLep_ * (1 - expectationReductionMuIsoTrackEff_);
			 IsoMuTrackReduction_ = totalWeightDiLep_ *expectationReductionMuIsoTrackEff_;
			 totalWeightDiLepIsoElecTrackReduced_ = totalWeightDiLep_ * (1 - expectationReductionElecIsoTrackEff_);
			 IsoElecTrackReduction_ = totalWeightDiLep_ *expectationReductionElecIsoTrackEff_;
			 totalWeightDiLepIsoPionTrackReduced_ = totalWeightDiLep_ * (1 - expectationReductionPionIsoTrackEff_);
			 IsoPionTrackReduction_ = totalWeightDiLep_ *expectationReductionPionIsoTrackEff_;
			 totalWeightDiLepIsoTrackReducedCombined_ = totalWeightDiLep_ * (1 - expectationReductionIsoTrackEffCombined_);
			 IsoTrackReductionCombined_ = totalWeightDiLep_ *expectationReductionIsoTrackEffCombined_;
			 
			 expectationReductionMuRecoMuIsoTrackReductionWeight_ = totalWeightDiLep_ *expectationReductionMuRecoMuIsoTrackEff_;
			 expectationReductionMuRecoPionIsoTrackReductionWeight_ = totalWeightDiLep_ *expectationReductionMuRecoPionIsoTrackEff_;
			 expectationReductionMuIsoMuIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionMuIsoMuIsoTrackEff_;
			 expectationReductionMuIsoPionIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionMuIsoPionIsoTrackEff_;
			 expectationReductionElecRecoElecIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionElecRecoElecIsoTrackEff_;
			 expectationReductionElecRecoPionIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionElecRecoPionIsoTrackEff_;
			 expectationReductionElecIsoElecIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionElecIsoElecIsoTrackEff_;
			 expectationReductionElecIsoPionIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionElecIsoPionIsoTrackEff_;
			 double expectationReductionMuIsoTrackEff2 = expectationReductionMuRecoMuIsoTrackEff_* expectationReductionMuIsoMuIsoTrackEff_;
			 double expectationReductionElecIsoTrackEff2 = expectationReductionElecRecoElecIsoTrackEff_ * expectationReductionElecIsoElecIsoTrackEff_;
			 double expectationReductionPionIsoTrackEff2 = expectationReductionMuRecoPionIsoTrackEff_ * expectationReductionMuIsoPionIsoTrackEff_ + expectationReductionElecRecoPionIsoTrackEff_ * expectationReductionElecIsoPionIsoTrackEff_;
			 expectationReductionPionIsoTrackEff2 = expectationReductionPionIsoTrackEff_; // this is a work around since the separated pion track from ele mu split up in recoacc and iso does not work right now 26 June 2015
			 expectationReductionIsoTrackEffCombined2_ = (1-expectationReductionMuIsoTrackEff2 ) * (1-expectationReductionElecIsoTrackEff2) * (1-expectationReductionPionIsoTrackEff2);
			 expectationReductionIsoTrackEffCombined2_ = 1-expectationReductionIsoTrackEffCombined2_;
			 
			 totalWeightDiLepIsoTrackReducedCombined2_ = totalWeightDiLep_ * (1 - expectationReductionIsoTrackEffCombined2_);
			 IsoTrackReductionCombined2_ = totalWeightDiLep_ *expectationReductionIsoTrackEffCombined2_;
			 
			 // 		std::cout<<"mu weight: standard1: "<<IsoTrackReduction_ <<"\nmu weight: standard2: "<<IsoTrackReductionCombined_<<"\nmu weight: standard3: "<<IsoTrackReductionCombined2_<<"\n eff1: "<< expectationReductionIsoTrackEff_<<"\n eff2: "<<expectationReductionIsoTrackEffCombined_<<"\n eff3: "<<expectationReductionIsoTrackEffCombined2_<<"\n";
			 
			 // 		std::cout<<"  Mu eff1: "<<expectationReductionMuIsoTrackEff_<<"\nElec eff1: "<<expectationReductionElecIsoTrackEff_<<"\nPion eff1: "<<expectationReductionPionIsoTrackEff_<<"\n";
			 // 		std::cout<<"NJets: "<<NJets<<" BTag: "<<BTags<<"\n";
			 // 		std::cout<<"\n--------------------------------------\n";
			 }       
			 else if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
			 {
				 std::pair<double, double> temp = deltaRClosestJet(selectedIDIsoElectronsEta[0],selectedIDIsoElectronsPhi[0],selectedIDIsoElectronsPt[0]);
				 GenDeltaR_=temp.first;
				 GenRelJetPT_=selectedIDIsoElectronsPt[0]/temp.second;
				 // 		std::cout<<"Single Elec Control, pt: "<<selectedIDIsoElectronsPt[0]<<" DeltaR: "<<GenDeltaR_<<" RelJetPT: "<<GenRelJetPT_<<"\n";
				 
				 AdditionalTracks_ = UnMatchedIsoTracks(selectedIDIsoElectronsEta[0],selectedIDIsoElectronsPhi[0],selectedIDIsoElectronsPt[0]);
				 mtw =  MTWCalculator(METPt,METPhi, selectedIDIsoElectronsPt[0], selectedIDIsoElectronsPhi[0]);
				 selectedIDIsoElectronsActivity[0]=ElecActivity(selectedIDIsoElectronsEta[0], selectedIDIsoElectronsPhi[0],elecActivityMethod_);
				 // 		std::cout<<"SingleElec::ElecActivity: "<< selectedIDIsoMuonsActivity[0]<<"\n";
				 
				 double muActivity = MuActivity(selectedIDIsoElectronsEta[0], selectedIDIsoElectronsPhi[0],muActivityMethod_)-selectedIDIsoElectronsPt[0];
				 // 		std::cout<<"SingleElec::MuActivity: "<< muActivity<<"\n";
				 if(muActivity<0)
				 {
					 muActivity=0.501;
				 }
				 if(!UseBTagsNJets_)
				 {
					 std::cout<<"dont be true\n";
					 // 			expectationReductionMuIsoTrackEff_ = getEff(ExpectationReductionMuIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],muActivity);
					 // 			expectationReductionElecIsoTrackEff_ = getEff(ExpectationReductionElecIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
					 // 			expectationReductionPionIsoTrackEff_ = getEff(ExpectationReductionPionIsoTrackBTagsNJetsEff_,BTags,NJets);
					 // 			expectationReductionIsoTrackEffCombined_ = (1-expectationReductionMuIsoTrackEff_) * (1-expectationReductionElecIsoTrackEff_) * (1-expectationReductionPionIsoTrackEff_);
					 // 			expectationReductionIsoTrackEffCombined_ = 1-expectationReductionIsoTrackEffCombined_;
					 // 			expectationReductionIsoTrackEffCombined_ = expectationReductionMuIsoTrackEff_ + expectationReductionElecIsoTrackEff_ + expectationReductionPionIsoTrackEff_;
				 }
				 
				 
				 if(UseMHTNJets_)
				 {
					 expectationReductionMuRecoMuIsoTrackEff_ = getEff(ExpectationReductionMuRecoMuIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionMuRecoPionIsoTrackEff_= getEff(ExpectationReductionMuRecoPionIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionMuIsoMuIsoTrackEff_= getEff(ExpectationReductionMuIsoMuIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionMuIsoPionIsoTrackEff_= getEff(ExpectationReductionMuIsoPionIsoTrackMHTNJetsEff_,MHT,NJets);
					 
					 expectationReductionElecRecoElecIsoTrackEff_ = getEff(ExpectationReductionElecRecoElecIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionElecRecoPionIsoTrackEff_= getEff(ExpectationReductionElecRecoPionIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionElecIsoElecIsoTrackEff_= getEff(ExpectationReductionElecIsoElecIsoTrackMHTNJetsEff_,MHT,NJets);
					 expectationReductionElecIsoPionIsoTrackEff_= getEff(ExpectationReductionElecIsoPionIsoTrackMHTNJetsEff_,MHT,NJets);
				 }
				 if(!UseMHTNJets_)
				 {
					 // derive expectation reduction for separated reco iso tracks
					 expectationReductionMuRecoMuIsoTrackReductionWeight_ = getEff(ExpectationReductionMuRecoMuIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],muActivity);
					 expectationReductionMuRecoPionIsoTrackReductionWeight_= getEff(ExpectationReductionMuRecoPionIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],muActivity);
					 expectationReductionMuIsoMuIsoTrackReductionWeight_= getEff(ExpectationReductionMuIsoMuIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],muActivity);
					 expectationReductionMuIsoPionIsoTrackReductionWeight_= getEff(ExpectationReductionMuIsoPionIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],muActivity);
					 expectationReductionElecRecoElecIsoTrackReductionWeight_ = getEff(ExpectationReductionElecRecoElecIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
					 expectationReductionElecRecoPionIsoTrackReductionWeight_= getEff(ExpectationReductionElecRecoPionIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
					 expectationReductionElecIsoElecIsoTrackReductionWeight_= getEff(ExpectationReductionElecIsoElecIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
					 expectationReductionElecIsoPionIsoTrackReductionWeight_= getEff(ExpectationReductionElecIsoPionIsoTrackPTActivityEff_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
				 }
				 
				 if(!UseUpdatedTEfficiencies_) elecPurityCorrection_ =  getEff(ElecPurityMHTNJets_,MHT,NJets);
			 else elecPurityCorrection_ = getEff(ElecPurityNJets_,NJets+0.1);
			 if(ElecPuritySearchBinEffBool_) elecPurityCorrection_ = ElecPuritySearchBinEff_->GetEff(searchBin_+0.01);
			 //              if(!UseUpdatedTEfficiencies_) elecMTWEff_ = getEff(ElecMTWPTActivity_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
			 if(!UseUpdatedTEfficiencies_) elecMTWEff_ = getEff(ElecMTWNJets_,NJets);
			 //              else elecMTWEff_= ElecMTWPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
			 else elecMTWEff_ = ElecMTWNJetsEff_->GetEff(NJets);
			 if(ElecMTWSearchBinUse_)elecMTWEff_=ElecMTWSearchBinEff_->GetEff(searchBin_+0.01);
			 if(!UseUpdatedTEfficiencies_) 
			 {
				 elecIsoEff_ =  getEff(ElecIsoPTActivity_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
				 if(UseDeltaRRelPT ) elecIsoEff_ = getEff(ElecIsoDeltaRRelPTJet_, GenDeltaR_,GenRelJetPT_);
			 }
			 //     else elecIsoEff_ = ElecIsoPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
			 //     if(ElecIsoSearchBinUse_)elecIsoEff_=ElecIsoSearchBinEff_->GetEff(searchBin_+0.01);
			 //     if(UseTagAndProbeEffIso_)elecIsoEff_ = getEff(ElecIsoPTActivityTAPMC_, selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_)); 
			 //              elecRecoEff_ = getEff(ElecRecoActivity_,selectedIDIsoElectronsActivity[0]);
			 //     if(UseHTIsoEff_) elecIsoEff_ = getEff(ElecIsoHT_,HT);
			 //     if(UseNJetsIsoEff_) elecIsoEff_ = getEff(ElecIsoNJets_,NJets+0.1);
			 if(!UseUpdatedTEfficiencies_) elecRecoEff_ = getEff(ElecRecoPTActivity_,selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
			 else elecRecoEff_ = ElecRecoPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
			 if(ElecRecoSearchBinUse_)elecRecoEff_=ElecRecoSearchBinEff_->GetEff(searchBin_+0.01);
			 if(UseTagAndProbeEffReco_)elecRecoEff_ = getEff(ElecRecoPTActivityTAPMC_, selectedIDIsoMuonsPt[0],ElecActivity(selectedIDIsoMuonsEta[0], selectedIDIsoMuonsPhi[0],elecActivityMethod_)); 
			 //              elecAccEff_ = getEff(ElecAccHTNJets_,HT,NJets);
			 //              elecAccEff_ = getEff(ElecAccBTagNJets_,BTags,NJets);
			 if(!UseUpdatedTEfficiencies_) 
			 {
				 //       elecAccEff_ = getEff(ElecAccMHTNJets_,MHT,NJets);
				 if(NJets<6.5) elecAccEff_ = getEff(ElecAccHTMHT_NJets46_,HT,MHT);
			 else elecAccEff_ =  getEff(ElecAccHTMHT_NJets7Inf_,HT,MHT);
			 
			 }
			 else elecAccEff_ = ElecAccMHTNJetsEff_->GetEff(MHT,NJets);
			 if(ElecAccSearchBinUse_)elecAccEff_=ElecAccSearchBinEff_->GetEff(searchBin_+0.01);
			 
			 //              muAccEff_ = getEff(MuAccHTNJets_,HT,NJets);
			 //              muAccEff_ = getEff(MuAccBTagNJets_,BTags,NJets);
			 if(!UseUpdatedTEfficiencies_) 
			 {
				 //       muAccEff_ = getEff(MuAccMHTNJets_,MHT,NJets);
				 if(NJets<6.5) muAccEff_ = getEff(MuAccHTMHT_NJets46_,HT,MHT);
			 else muAccEff_ =  getEff(MuAccHTMHT_NJets7Inf_,HT,MHT);
			 
			 }
			 else muAccEff_ = MuAccMHTNJetsEff_->GetEff(MHT,NJets);
			 if(MuAccSearchBinUse_)muAccEff_=MuAccSearchBinEff_->GetEff(searchBin_+0.01);
			 //              muRecoEff_ = getEff(MuRecoActivitiy_,selectedIDIsoElectronsActivity[0]);
			 if(!UseUpdatedTEfficiencies_) muRecoEff_ = getEff(MuRecoPTActivity_, selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
			 else muRecoEff_ = MuRecoPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
			 if(MuRecoSearchBinUse_)muRecoEff_=MuRecoSearchBinEff_->GetEff(searchBin_+0.01);
			 if(UseTagAndProbeEffReco_)muRecoEff_ = getEff(MuRecoPTActivityTAPMC_, selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]); 
			 if(!UseUpdatedTEfficiencies_)
			 {
				 muIsoEff_ = getEff(MuIsoPTActivity_, selectedIDIsoElectronsPt[0],muActivity);
				 if(UseDeltaRRelPT ) muIsoEff_ = getEff(MuIsoDeltaRRelPTJet_, GenDeltaR_,GenRelJetPT_);
			 }
			 //     else
			 // 		{
				 // 			muIsoEff_ = MuIsoPTActivityEff_->GetEff(selectedIDIsoElectronsPt[0],selectedIDIsoElectronsActivity[0]);
				 // 			if(UseDeltaRRelPT ) muIsoEff_ = MuIsoDeltaRRelPTJet_->GetEff( GenDeltaR_,GenRelJetPT_);
				 // 		}
				 //     if(MuIsoSearchBinUse_)muIsoEff_=MuIsoSearchBinEff_->GetEff(searchBin_+0.01);
				 //     if(UseTagAndProbeEffIso_)muIsoEff_ = getEff(MuIsoPTActivityTAPMC_, selectedIDIsoMuonsPt[0],selectedIDIsoMuonsActivity[0]); 
				 //     if(UseHTIsoEff_) muIsoEff_ = getEff(MuIsoHT_,HT);
				 //     if(UseNJetsIsoEff_) muIsoEff_ = getEff(MuIsoNJets_,NJets+0.1);
				 purityCorrectedWeight_ = Weight * elecPurityCorrection_;
				 mtwCorrectedWeight_ =  purityCorrectedWeight_ / elecMTWEff_;
				 if(!UseUpdatedTEfficiencies_) elecDiLepContributionMTWAppliedEff_ = getEff(ElecDiLepContributionMTWAppliedNJets_,NJets);
			 else elecDiLepContributionMTWAppliedEff_ = ElecDiLepContributionMTWAppliedNJetsEff_->GetEff(NJets);
			 if(ElecDiLepContributionMTWAppliedEffSearchBinUse_)elecDiLepContributionMTWAppliedEff_=ElecDiLepContributionMTWAppliedSearchBinEff_->GetEff(searchBin_+0.01);
			 mtwDiLepCorrectedWeight_ = mtwCorrectedWeight_ * elecDiLepContributionMTWAppliedEff_;
			 elecIsoWeight_= mtwDiLepCorrectedWeight_ * (1 - elecIsoEff_)/elecIsoEff_;
			 //              elecIsoWeight_= Weight * (1 - elecIsoEff_)/elecIsoEff_;
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
			 if(ElecDiLepContributionMTWAppliedEffSearchBinUse_)elecDiLepEffMTWAppliedEff_=ElecDiLepContributionMTWAppliedSearchBinEff_->GetEff(searchBin_+0.01);
			 totalWeightDiLep_ = totalWeight_ + (1-elecDiLepContributionMTWAppliedEff_) * mtwCorrectedWeight_ * (1-elecDiLepEffMTWAppliedEff_)/elecDiLepEffMTWAppliedEff_;
			 totalWeightDiLepIsoTrackReduced_ = totalWeightDiLep_ * (1 - expectationReductionIsoTrackEff_);
			 IsoTrackReduction_ = totalWeightDiLep_ *expectationReductionIsoTrackEff_;
			 totalWeightDiLepIsoMuTrackReduced_ = totalWeightDiLep_ * (1 - expectationReductionMuIsoTrackEff_);
			 IsoMuTrackReduction_ = totalWeightDiLep_ *expectationReductionMuIsoTrackEff_;
			 totalWeightDiLepIsoElecTrackReduced_ = totalWeightDiLep_ * (1 - expectationReductionElecIsoTrackEff_);
			 IsoElecTrackReduction_ = totalWeightDiLep_ *expectationReductionElecIsoTrackEff_;
			 totalWeightDiLepIsoPionTrackReduced_ = totalWeightDiLep_ * (1 - expectationReductionPionIsoTrackEff_);
			 IsoPionTrackReduction_ = totalWeightDiLep_ *expectationReductionPionIsoTrackEff_;
			 totalWeightDiLepIsoTrackReducedCombined_ = totalWeightDiLep_ * (1 - expectationReductionIsoTrackEffCombined_);
			 IsoTrackReductionCombined_ = totalWeightDiLep_ *expectationReductionIsoTrackEffCombined_;
			 
			 expectationReductionMuRecoMuIsoTrackReductionWeight_ = totalWeightDiLep_ *expectationReductionMuRecoMuIsoTrackEff_;
			 expectationReductionMuRecoPionIsoTrackReductionWeight_ = totalWeightDiLep_ *expectationReductionMuRecoPionIsoTrackEff_;
			 expectationReductionMuIsoMuIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionMuIsoMuIsoTrackEff_;
			 expectationReductionMuIsoPionIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionMuIsoPionIsoTrackEff_;
			 expectationReductionElecRecoElecIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionElecRecoElecIsoTrackEff_;
			 expectationReductionElecRecoPionIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionElecRecoPionIsoTrackEff_;
			 expectationReductionElecIsoElecIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionElecIsoElecIsoTrackEff_;
			 expectationReductionElecIsoPionIsoTrackReductionWeight_= totalWeightDiLep_ *expectationReductionElecIsoPionIsoTrackEff_;
			 double expectationReductionMuIsoTrackEff2 = expectationReductionMuRecoMuIsoTrackEff_* expectationReductionMuIsoMuIsoTrackEff_;
			 double expectationReductionElecIsoTrackEff2 = expectationReductionElecRecoElecIsoTrackEff_ * expectationReductionElecIsoElecIsoTrackEff_;
			 double expectationReductionPionIsoTrackEff2 = expectationReductionMuRecoPionIsoTrackEff_ * expectationReductionMuIsoPionIsoTrackEff_ + expectationReductionElecRecoPionIsoTrackEff_ * expectationReductionElecIsoPionIsoTrackEff_;
			 expectationReductionPionIsoTrackEff2 = expectationReductionPionIsoTrackEff_; // this is a work around since the separated pion track from ele mu split up in recoacc and iso does not work right now 26 June 2015
			 // 		std::cout<<"MuIsoEffRef: "<<expectationReductionMuIsoTrackEff_<<"\n";
			 // 		std::cout<<"Combined1   : "<<expectationReductionMuIsoTrackEff2<<"\n";
			 // 		std::cout<<"MuIsoReco1 : "<<expectationReductionMuRecoMuIsoTrackEff_<<"\n";
			 // 		std::cout<<"MuIsoIso1  : "<<expectationReductionMuIsoMuIsoTrackEff_<<"\n";
			 // 		std::cout<<"ElecIsoEffRef: "<<expectationReductionElecIsoTrackEff_<<"\n";
			 // 		std::cout<<"Combined1   : "<<expectationReductionElecIsoTrackEff2<<"\n";
			 // 		std::cout<<"ElecIsoReco1 : "<<expectationReductionElecRecoElecIsoTrackEff_<<"\n";
			 // 		std::cout<<"ElecIsoIso1  : "<<expectationReductionElecIsoElecIsoTrackEff_<<"\n";
			 // 		std::cout<<"PionIsoEffRef: "<<expectationReductionPionIsoTrackEff_<<"\n";
			 // 		std::cout<<"Combined1   : "<<expectationReductionPionIsoTrackEff2<<"\n";
			 // 		std::cout<<"PionMuReco1 : "<<expectationReductionMuRecoPionIsoTrackEff_<<"\n";
			 // 		std::cout<<"PionMuIso1  : "<<expectationReductionMuIsoPionIsoTrackEff_<<"\n";
			 // 		std::cout<<"PionMuComb1  : "<<expectationReductionMuRecoPionIsoTrackEff_ *expectationReductionMuIsoPionIsoTrackEff_ <<"\n";
			 // 		std::cout<<"PionElecReco1 : "<<expectationReductionElecRecoPionIsoTrackEff_<<"\n";
			 // 		std::cout<<"PionElecIso1  : "<<expectationReductionElecIsoPionIsoTrackEff_<<"\n";
			 // 		std::cout<<"PionElecComb1  : "<<expectationReductionElecRecoPionIsoTrackEff_ *expectationReductionElecIsoPionIsoTrackEff_ <<"\n";
			 // 		std::cout<<"\n--------------------------------------------------------------------\n";
			 
			 expectationReductionIsoTrackEffCombined2_ = (1-expectationReductionMuIsoTrackEff2 ) * (1-expectationReductionElecIsoTrackEff2) * (1-expectationReductionPionIsoTrackEff2);
			 expectationReductionIsoTrackEffCombined2_ = 1-expectationReductionIsoTrackEffCombined2_;
			 
			 totalWeightDiLepIsoTrackReducedCombined2_ = totalWeightDiLep_ * (1 - expectationReductionIsoTrackEffCombined2_);
			 IsoTrackReductionCombined2_ = totalWeightDiLep_ *expectationReductionIsoTrackEffCombined2_;
			 
			 }
			 if(DoUncertainties_)
			 {
				 nonClosureUp_ = IsoTrackReductionCombined_ * (1+NonClosure_/100);
				 nonClosureDown_ = IsoTrackReductionCombined_ * (1-NonClosure_/100);
				 
			 }
			 
			 //      if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==0 && !IsolatedTracksMuMatched_ && !IsolatedTracksElecMatched_) return kTRUE;
			 tPrediction_->Fill();
			 // 	std::cout<<"--------------------------------------------------------------\n";
			 return kTRUE;
}

void Prediction::SlaveTerminate()
{
	// The SlaveTerminate() function is called after all entries or objects
	// have been processed. When running with PROOF SlaveTerminate() is called
	// on each slave server.
	SearchBins_->PrintUsed();
	
}

void Prediction::Terminate()
{
	// The Terminate() function is the last function to be called during
	// a query. It always runs on the client, it can be used to present
	// the results graphically or save the results to file.
	TFile *outPutFile = new TFile("Prediction.root","RECREATE"); ;
	outPutFile->cd();
	tPrediction_->Write();
	outPutFile->Close();
	
}
void Prediction::resetValues()
{
	AdditionalTracks_=0;
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
	totalWeightDiLepIsoTrackReduced_=0.;
	// isolated track prediction
	IsolatedTracksMuMatched_=false;
	IsolatedTracksElecMatched_=false;
	IsoTrackReduction_=0.;
	IsoMuTrackReduction_=0.;
	IsoElecTrackReduction_=0.;
	IsoPionTrackReduction_=0.;
	IsoTrackReductionCombined_=0.;
	
	expectationReductionMuRecoMuIsoTrackReductionWeight_=0.;
	expectationReductionMuRecoPionIsoTrackReductionWeight_=0.;
	expectationReductionMuIsoMuIsoTrackReductionWeight_ =0.;
	expectationReductionMuIsoPionIsoTrackReductionWeight_ =0.;
	expectationReductionElecRecoElecIsoTrackReductionWeight_ =0.;
	expectationReductionElecRecoPionIsoTrackReductionWeight_ =0.;
	expectationReductionElecIsoElecIsoTrackReductionWeight_ =0.;
	expectationReductionElecIsoPionIsoTrackReductionWeight_=0.;
	expectationReductionMuRecoMuIsoTrackEff_ =0.;
	expectationReductionMuRecoPionIsoTrackEff_=0.;
	expectationReductionMuIsoMuIsoTrackEff_=0.;
	expectationReductionMuIsoPionIsoTrackEff_=0.;
	expectationReductionElecRecoElecIsoTrackEff_ =0.;
	expectationReductionElecRecoPionIsoTrackEff_=0.;
	expectationReductionElecIsoElecIsoTrackEff_=0.;
	totalWeightDiLepIsoTrackReducedCombined_=0.;
	totalWeightDiLepIsoTrackReducedCombined2_=0.;
	IsoTrackReductionCombined2_=0.;
	
	muIsoWeightUp_=0.;
	muIsoWeightDown_=0.;
	muRecoWeightUp_=0.;
	muRecoWeightDown_=0.;
	muAccWeightUp_=0.;
	muAccWeightDown_=0.;
	elecIsoWeightUp_=0.;
	elecIsoWeightDown_ =0.;
	elecRecoWeightUp_=0.;
	elecRecoWeightDown_=0.;
	elecAccWeightUp_=0.;
	elecAccWeightDown_=0.;
	
	muIsoEffUp_=0.;
	muIsoEffDown_=0.;
	muRecoEffUp_=0.;
	muRecoEffDown_=0.;
	muAccEffUp_=0.;
	muAccEffDown_=0.;
	elecIsoEffUp_=0.;
	elecIsoEffDown_ =0.;
	elecRecoEffUp_=0.;
	elecRecoEffDown_=0.;
	elecAccEffUp_=0.;
	elecAccEffDown_=0.;
	
	muIsoRel_=0.;
	muRecoRel_=0.;
	muAccRel_=0.;
	elecIsoRel_=0.;
	elecRecoRel_=0.;
	elecAccRel_=0.;
	
	mtwDown_=0.;
	mtwUp_=0.;
	diLepDown_=0.;
	diLepUp_=0.;
	nonClosureUp_=0.;
	nonClosureDown_=0.;
}
bool Prediction::FiltersPass()
{
	bool result=true;
	// if(Filter_HBHENoiseFilterRA2==0) result=false;
	if(!JetID) result=false;
			 return result;
}
double Prediction::deltaR(double eta1, double phi1, double eta2, double phi2)
{
	double deta = eta1-eta2;
	double dphi = TVector2::Phi_mpi_pi(phi1-phi2);
	return sqrt(deta * deta + dphi *dphi); 
}

unsigned int Prediction::UnMatchedIsoTracks(double eta, double phi, double pt)
{
	unsigned int Isotracks=0;
	for(unsigned int i=0; i<IsolatedElectronTracksVetoNum;i++)
	{
		if(deltaR(eta,phi,IsolatedElectronTracksVetoEta[i],IsolatedElectronTracksVetoPhi[i])<0.1 && std::abs(pt-IsolatedElectronTracksVetoPt[i])/pt<0.2) continue;
			 Isotracks++;
	}
	for(unsigned int i=0; i<IsolatedMuonTracksVetoNum;i++)
	{
		if(deltaR(eta,phi,IsolatedMuonTracksVetoEta[i],IsolatedMuonTracksVetoPhi[i])<0.1 && std::abs(pt-IsolatedMuonTracksVetoPt[i])/pt<0.2) continue;
			 Isotracks++;
	}
	for(unsigned int i=0; i<IsolatedPionTracksVetoNum;i++)
	{
		if(deltaR(eta,phi,IsolatedPionTracksVetoEta[i],IsolatedPionTracksVetoPhi[i])<0.1 && std::abs(pt-IsolatedPionTracksVetoPt[i])/pt<0.2) continue;
			 Isotracks++;
	}
	
	return Isotracks; 
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
	xValue = xValue+0.01;
	yValue = yValue+0.01;
	if(xValue < effTH2F->GetXaxis()->GetXmin() )
	{
		//              std::cout<<"Warning xValue: "<<xValue<<" is smaller than minimum of histo: "<<effTH2F->GetName()<<std::endl;
		xValue= effTH2F->GetXaxis()->GetXmin()+0.01;
	}
	else if(xValue > effTH2F->GetXaxis()->GetXmax() )
	{
		//        std::cout<<"Warning xValue: "<<xValue<<" is bigger than maximum of histo: "<<effTH2F->GetName()<<" which is: "<<effTH2F->GetXaxis()->GetXmax();
		xValue= effTH2F->GetXaxis()->GetXmax()-0.01;
		//              std::cout<<" Setting xValue to: "<<xValue<<std::endl;
		if(xValue > effTH2F->GetXaxis()->GetXmax() )std::cout<<"Problem persists!!!!!!!!!"<<std::endl;
	}
	
	if(yValue < effTH2F->GetYaxis()->GetXmin() )
	{
		//              std::cout<<"Warning yValue: "<<yValue<<" is smaller than minimum of histo: "<<effTH2F->GetName()<<std::endl;
		yValue= effTH2F->GetYaxis()->GetXmin()+0.01;
	}
	else if(yValue > effTH2F->GetYaxis()->GetXmax() )
	{
		//              std::cout<<"Warning yValue: "<<yValue<<" is bigger than maximum of histo: "<<effTH2F->GetName()<<std::endl;
		yValue= effTH2F->GetYaxis()->GetXmax()-0.01;
	}
	result = effTH2F->GetBinContent(effTH2F->GetXaxis()->FindBin(xValue),effTH2F->GetYaxis()->FindBin(yValue));
	if(result<0.0001)
	{
		//     std::cout<<"Warning efficiency is: "<<result<<" is smaller than 1% for histo: "<<effTH2F->GetName()<<std::endl;
		result =0.0001;
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
		//     std::cout<<"Warning efficiency is: "<<result<<" is smaller than 1% for histo: "<<effTH1F->GetName()<<std::endl;
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
	if(method==3)
	{
		for(unsigned int i=0; i< SelectedPFCandidatesNum; i++)
		{
			if(SelectedPFCandidates_Charge[i]!=0) continue;
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
			//                      result+=JetsPt[i] * (Jets_chargedEmEnergyFraction[i] + Jets_chargedHadronEnergyFraction[i]);
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
	if(method==3)
	{
		for(unsigned int i=0; i< SelectedPFCandidatesNum; i++)
		{
			if(SelectedPFCandidates_Charge[i]!=0) continue;
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
			//                      std::cout<<"object: "<<object->GetName()<<" is a th2f\n";
			refTH2F_ = (TH2F*)object;
		}
		if(object->IsA()->InheritsFrom( TGraphAsymmErrors::Class() ) )
		{
			//                      std::cout<<"object: "<<object->GetName()<<" is a TGraphAsymmErrors\n";
			TGraphAsymmErrorsVec_.push_back( (TGraphAsymmErrors*)object  );
		}
		count++;
	}
	//      for(unsigned int i=0; i<TGraphAsymmErrorsVec_.size();i++)
	//      {
		//              std::cout<<"TGraph["<<i<<"]: "<<TGraphAsymmErrorsVec_[i]->GetTitle()<<std::endl;
		//      }
		xMax_=0; xMin_=0; yMax_=0; yMin_=0;
		xMax_= refTH2F_->GetXaxis()->GetXmax();
		xMin_=refTH2F_->GetXaxis()->GetXmin();
		yMax_= refTH2F_->GetYaxis()->GetXmax();
		yMin_=refTH2F_->GetYaxis()->GetXmin();
		//      std::cout<<"Eff: "<<refTH2F_->GetName()<<" range: ["<<xMin_<<","<<xMax_<<"],["<<yMin_<<","<<yMax_<<"]\n"; 
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
	if(result<0.001)
	{
		//     std::cout<<"THFeff::Warning efficiency is: "<<result<<" is smaller than 1% for histo: "<<refTH2F_->GetName()<<std::endl;
		result =0.001;
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
		//     std::cout<<"THFeff::Warning efficiency is: "<<result<<" is smaller than 1% for histo: "<<TGraphAsymmErrorsRef_->GetName()<<std::endl;
		result =0.01;
	}
	if(result>1)
	{
		std::cout<<"THFeff::Warning efficiency is: "<<result<<" is bigger than 1 for histo: "<<TGraphAsymmErrorsRef_->GetName()<<std::endl;
		result =0.99;
	}
	return result;
}
SearchBins::SearchBins()
{
	
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
	for(unsigned int i=0; i<bins_.size();i++)
	{
		usedBin_.push_back(0); 
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
			usedBin_[i]=usedBin_[i]+1;
		}
	}
	if(match==-1)
	{
		//     std::cout<<"Error event fits in no bin!!! HT: "<<HT<<", MHT: "<<MHT<<", NJets: "<<NJets<<", BTags: "<<BTags<<std::endl;
		result=999;
	}
	if(match>0)
	{
		std::cout<<"Error event fits in more than one bin!!!! HT: "<<HT<<", MHT: "<<MHT<<", NJets: "<<NJets<<", BTags: "<<BTags<<std::endl;
	}
	return result+1; // to not use the 0 bin but start counting at 1
}
void SearchBins::PrintUsed()
{
	for(unsigned int i=0; i< usedBin_.size();i++) std::cout<<"Bin["<<i<<"] has been used: "<<usedBin_[i]<<std::endl; 
}


std::pair <double,double> Prediction::deltaRClosestJet(double lepEta,double lepPhi, double lepPT)
{
	std::pair <double,double> result = std::make_pair(999,0);
	double closestJet=9999;
	for (unsigned int i=0; i < JetsNum ; i++)
	{
		if(deltaR(lepEta,lepPhi,JetsEta[i],JetsPhi[i])>closestJet) continue;
			 if(deltaR(lepEta,lepPhi,JetsEta[i],JetsPhi[i]) < jetCone_ && JetsPt[i]>lepPT)
			 {
				 if((JetsPt[i]-lepPT)>jetMinPt_)
				 {
					 result = std::make_pair(deltaR(lepEta,lepPhi,JetsEta[i],JetsPhi[i]) ,(JetsPt[i]-lepPT));   	
					 closestJet = deltaR(lepEta,lepPhi,JetsEta[i],JetsPhi[i]);
					 continue;
				 }
				 else 
					 continue;
				 
			 }
			 result = std::make_pair(deltaR(lepEta,lepPhi,JetsEta[i],JetsPhi[i]) ,JetsPt[i]);
			 closestJet = deltaR(lepEta,lepPhi,JetsEta[i],JetsPhi[i]);
			 //  			result+=JetsPt[i] * (Jets_chargedEmEnergyFraction[i] + Jets_chargedHadronEnergyFraction[i]);
	}
	// 	std::cout<<"DeltaR: "<<result.first<<" PT rel: "<<result.second/lepPT<<std::endl;
	return result;
}