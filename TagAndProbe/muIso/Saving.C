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

}

void Saving::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
	 
	 tExpectation_ = new TTree("TagAndProbeMuIso","");
	 tExpectation_->Branch("Eta",&eta,"Eta/F");
	 tExpectation_->Branch("Pt",&pt,"Pt/F");
	 tExpectation_->Branch("Activity",&activity,"Activity/F");
	 tExpectation_->Branch("Pass",&passing,"Pass/I");
	 tExpectation_->Branch("InvariantMass",&mass,"InvariantMass/F");


}

Bool_t Saving::Process(Long64_t entry)
{
	fChain->GetTree()->GetEntry(entry);
	if(Passing<0.5) passing=false;
	else passing=true;
// 	std::cout<<"passing: "<<Passing<<std::endl;
	tExpectation_->Fill();

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
	TFile *outPutFile = new TFile("TagAndProbeEff_MuIso.root","RECREATE"); 
	outPutFile->cd();
	outPutFile->mkdir("MuIso");
	TDirectory *dmuonEffs = (TDirectory*)outPutFile->Get("MuIso");
	dmuonEffs->cd();
	tExpectation_->Write();
	outPutFile->Close();

}
