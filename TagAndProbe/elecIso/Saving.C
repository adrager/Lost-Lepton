#define Saving_cxx
// The class definition in Saving.h has been generated automatically
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
// Root > T->Process("Saving.C")
// Root > T->Process("Saving.C","some options")
// Root > T->Process("Saving.C+")
//

#include "Saving.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>


void Saving::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
//    std::cout<<"dump\n";

}

void Saving::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   tExpectation_ = new TTree("TagAndProbeElecIso","");
   tExpectation_->Branch("Eta",&eta,"Eta/F");
   tExpectation_->Branch("Pt",&pt,"Pt/F");
   tExpectation_->Branch("Activity",&activity,"Activity/F");
   tExpectation_->Branch("Pass",&passing,"Pass/I");
   tExpectation_->Branch("InvariantMass",&mass,"InvariantMass/F");
   tExpectation_->Branch("MTW",&MTW,"MTW/F");
	 tExpectation_->Branch("HT",&HT,"HT/F");
	 tExpectation_->Branch("RecomputedMET",&RecomputedMET,"RecomputedMET/F");
	 tExpectation_->Branch("NJets",&NJets_,"NJets/I");
   tExpectation_->Branch("MTWClean",&MTWClean,"MTWClean/F");
   tExpectation_->Branch("TagObjectsNum",&TagObjectsNum_,"TagObjectsNum/I");
   tExpectation_->Branch("Weight",&Weight,"Weight/F");
   tExpectation2_ = new TTree("TagAndProbeElecIsoMTWFromDiLep","");
   tExpectation2_->Branch("Eta",&eta,"Eta/F");
   tExpectation2_->Branch("Pt",&pt,"Pt/F");
   tExpectation2_->Branch("Activity",&activity,"Activity/F");
   tExpectation2_->Branch("Pass",&passing,"Pass/I");
   tExpectation2_->Branch("InvariantMass",&mass,"InvariantMass/F");
   tExpectation2_->Branch("MTW",&MTWClean,"MTW/F");
	 tExpectation2_->Branch("RecomputedMET",&RecomputedMET,"RecomputedMET/F");
	 tExpectation2_->Branch("HT",&HT,"HT/F");
	 tExpectation2_->Branch("NJets",&NJets_,"NJets/I");
   tExpectation2_->Branch("TagObjectsNum",&TagObjectsNum_,"TagObjectsNum/I");
   tExpectation2_->Branch("Weight",&Weight,"Weight/F");
   
   std::cout<<"dump\n";

}

Bool_t Saving::Process(Long64_t entry)
{
	fChain->GetTree()->GetEntry(entry);
	if(Passing<0.5) passing=false;
	else passing=true;
	NJets_=(int)NJets;
        TagObjectsNum_ = TagObjectsNum;
// 	std::cout<<"passing: "<<Passing<<std::endl;
	tExpectation_->Fill();
        tExpectation2_->Fill();

   return kTRUE;
}

void Saving::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Saving::Terminate()
{
	TFile *outPutFile = new TFile("TagAndProbeEff_ElecIso.root","RECREATE"); 
	outPutFile->cd();
	outPutFile->mkdir("ElecIso");
	TDirectory *dmuonEffs = (TDirectory*)outPutFile->Get("ElecIso");
	dmuonEffs->cd();
	tExpectation_->Write();
        tExpectation2_->Write();
	outPutFile->Close();

}
