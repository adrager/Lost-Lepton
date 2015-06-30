//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jun  1 16:06:32 2015 by ROOT version 5.34/18
// from TTree fitter_tree/fitter_tree
// found on file: job_0_ReducedSelection.root
//////////////////////////////////////////////////////////

#ifndef Saving_h
#define Saving_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Saving : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   TTree					*tExpectation_,*tExpectation2_;
   // Declaration of leaf types
   Int_t        passing, TagObjectsNum_;
   Float_t         eta;
   Float_t         pt;
   Float_t         Eta;
   Float_t         MTW;
   Float_t         MTWClean;
   Float_t         Passing;
   Float_t         Pt;
   Float_t         RecomputedMET;
   Float_t         TagObjectsNum;
   Float_t         activity;
   Int_t           passingIso;
   Float_t         mass;
   Float_t         Weight;
   
   // List of branches
   TBranch        *b_eta;   //!
   TBranch        *b_pt;   //!
   TBranch        *b_Eta;   //!
   TBranch        *b_MTW;   //!
   TBranch        *b_MTWClean;   //!
   TBranch        *b_Passing;   //!
   TBranch        *b_Pt;   //!
   TBranch        *b_RecomputedMET;   //!
   TBranch        *b_TagObjectsNum;   //!
   TBranch        *b_activity;   //!
   TBranch        *b_passingIso;   //!
   TBranch        *b_mass;   //!
   TBranch        *b_Weight;   //!
   
   Saving(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~Saving() { }
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
   
   ClassDef(Saving,0);
};

#endif

#ifdef Saving_cxx
void Saving::Init(TTree *tree)
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
  
  fChain->SetBranchAddress("eta", &eta, &b_eta);
  fChain->SetBranchAddress("pt", &pt, &b_pt);
  fChain->SetBranchAddress("Eta", &Eta, &b_Eta);
  fChain->SetBranchAddress("MTW", &MTW, &b_MTW);
  fChain->SetBranchAddress("MTWClean", &MTWClean, &b_MTWClean);
  fChain->SetBranchAddress("Passing", &Passing, &b_Passing);
  fChain->SetBranchAddress("Pt", &Pt, &b_Pt);
  fChain->SetBranchAddress("RecomputedMET", &RecomputedMET, &b_RecomputedMET);
  fChain->SetBranchAddress("TagObjectsNum", &TagObjectsNum, &b_TagObjectsNum);
  fChain->SetBranchAddress("activity", &activity, &b_activity);
  fChain->SetBranchAddress("passingIso", &passingIso, &b_passingIso);
  fChain->SetBranchAddress("mass", &mass, &b_mass);
  fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
}

Bool_t Saving::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef Saving_cxx
