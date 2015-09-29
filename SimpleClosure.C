#include <TChain.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTree.h>
#include <TH2F.h>
#include <TH1F.h>
#include "TVector2.h"
#include <cmath>
#include "TCanvas.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include <iostream>
#include <iomanip> 
#include "THStack.h"
#include "TLegend.h"
using namespace std;
TH1F* ratioCalculator(TH1F* passTH1, TH1F* failTH1)
{
  passTH1->Sumw2();
  TH1F *sum = (TH1F*)passTH1->Clone();
  failTH1->Sumw2();
  
  sum->Add(failTH1);
  passTH1->Divide(passTH1,sum,1,1,"B");
  return passTH1;
}

void SaveClosure(TH1F* prediction, TH1F* expectation, TDirectory* Folder) // prediction durch expectation
{
  TH1F* Closure = (TH1F*) prediction->Clone();
  Closure->Divide(prediction,expectation,1,1,"B");
  TString title = prediction->GetTitle();
  title +="_closure";
  //      title = "#mu & e Control-Sample Ratio in Search Bins; Search bins; #mu / e CS";
  Closure->SetTitle(title);
  title = prediction->GetName();
  title+="_closure";
  Closure->SetName(title);
  Folder->cd();
  Closure->Write();
  // plotting
  gROOT->SetBatch(true);
  const TString th2Name = Closure->GetName();
  const TString th2Title = Closure->GetTitle();
  TCanvas *c1 = new TCanvas(th2Name,th2Title,650,500);
  c1->cd();
//   Closure->GetYaxis()->SetRangeUser(.0,2);
//   Closure->GetYaxis()->SetRangeUser(0.5,1.5);
  Closure->SetMarkerSize(2.0);
  Closure->UseCurrentStyle();
   Closure->SetMinimum(0.5);
  Closure->SetMaximum(1.5);
//   Closure->GetZaxis()->SetLimits(0.,100.);
  Closure->SetStats(0);
  Closure->Draw("E");
  c1->Update();
  c1->SaveAs(th2Name+".pdf");
}


void SaveClosure(TH1F* prediction, TH1F* expectation, TDirectory* Folder, TString Title) // prediction durch expectation
{
  TH1F* Closure = (TH1F*) prediction->Clone();
//   Closure->Divide(prediction,expectation,1,1,"B");
  Closure->Divide(expectation,prediction,1,1,"B");
  TString title = prediction->GetTitle();
  title +="_closure";
  //      title = "#mu & e Control-Sample Ratio in Search Bins; Search bins; #mu / e CS";
  Closure->SetTitle(Title);
  title = prediction->GetName();
  title+="_closure";
  Closure->SetName(title);
  Folder->cd();
  Closure->Write();
  // plotting
  gROOT->SetBatch(true);
  const TString th2Name = Closure->GetName();
  const TString th2Title = Closure->GetTitle();
  TCanvas *c1 = new TCanvas(th2Name,th2Title,900,500);
  c1->cd();
  //   Closure->GetYaxis()->SetRangeUser(.0,2);
  //   Closure->GetYaxis()->SetRangeUser(0.5,1.5);
  Closure->SetMarkerSize(2.0);
  Closure->UseCurrentStyle();
  Closure->SetMinimum(0.5);
  Closure->SetMaximum(1.5);
  //   Closure->GetZaxis()->SetLimits(0.,100.);
  Closure->SetStats(0);
  Closure->Draw("E");
  c1->Update();
  c1->SaveAs(th2Name+".pdf");
}

void SaveStack(std::vector<TH1F*> input, TDirectory* Folder, TString Name, TString Title, std::vector<TString> labels,TString axislables)
{
  THStack *hs = new THStack(Name,Title+axislables);
  TH1F* Sum = (TH1F*) input[0]->Clone();
  TLegend *lLeg = new TLegend(0.13,0.17,0.26,0.39);
  lLeg->SetFillColor(0);
  for(unsigned int i=1; i<input.size();i++)
  {
    Sum->Add(input[i]);
  }
  for(unsigned int i=0; i<input.size();i++)
  {
    input[i]->SetFillColor(i+2);
     input[i]->SetMarkerStyle(21);
     input[i]->SetMarkerColor(i+2);
     input[i]->SetLineColor(i+2);
    input[i]->Divide(input[i],Sum);
    hs->Add(input[i]);
    lLeg->AddEntry(input[input.size()-1-i],labels[input.size()-1-i],"f");
  }
  gROOT->SetBatch(true);
  TCanvas *cst = new TCanvas(Name,Title,10,10,900,500);
  cst->SetFillColor(0);
//   cst->Divide(2,2);
  // in top left pad, draw the stack with defaults
//   cst->cd(1);
//   hs->Draw();
//   // in top right pad, draw the stack in non-stack mode
//   // and errors option
//   cst->cd(2);
//   gPad->SetGrid();
//   hs->Draw("nostack,e1p");
//   //in bottom left, draw in stack mode with "lego1" option
//   cst->cd(3);
//   gPad->SetFrameFillColor(0);
//   gPad->SetTheta(9000);
//   gPad->SetPhi(9000);
  hs->Draw("HIST");
  lLeg->Draw();
  cst->Update();
  cst->SaveAs(Name+".pdf");
  Folder->cd();
  hs->Write();
}

class Bin
{
public:
  Bin(){}
  Bin(double HTmin, double HTmax, double MHTmin, double MHTmax, int NJetsmin, int NJetsmax, int BTagsmin, int BTagsmax)
  {
    HTmin_=HTmin;
    HTmax_=HTmax;
    MHTmin_=MHTmin;
    MHTmax_=MHTmax;
    NJetsmin_=NJetsmin;
    NJetsmax_=NJetsmax;
    BTagsmin_=BTagsmin;
    BTagsmax_=BTagsmax;
  }
  double HTmin_, HTmax_, MHTmin_, MHTmax_;
  int NJetsmin_, NJetsmax_, BTagsmin_, BTagsmax_;
  ~Bin(){}
private:
};
class SearchBins
{
public:
  SearchBins();
  unsigned int GetBinNumber(double HT, double MHT, int NJets, int BTags);
  std::string GetBinBounds(unsigned int bin)
  {
    return "hello";
    
  }
  
  ~SearchBins(){}
protected:
  std::vector<Bin> bins_;
  unsigned int binning;
};

class SearchBinEventCount : public SearchBins
{
public:
  SearchBinEventCount(){}
  SearchBinEventCount(const char*);
  void Fill(double HT, double MHT, int NJets, int BTags, double Weight);
  void saveResults(TDirectory* MainDirectory);
  std::vector<TH1F*> getSearchVariables();
  TH1F* getFullTH1F(){return fullTH1F_;}
  ~SearchBinEventCount(){}
private:
  TH1F* fullTH1F_;
  TH1F *TH1FHT_, *TH1FMHT_,*TH1FNJets_,*TH1FBTags_;
  std::vector<TH1F*> splitTH1F_;
  unsigned int splitAfter_;
  const char* name_;
};

class AverageWeight : public SearchBins
{
public:
  AverageWeight()
  {
    for(unsigned int i=0; i< bins_.size();i++)
    {
      TString temp2 (Form ("Bin_%d",(int)i+1));
      searchBinsTh1Fs_.push_back(new TH1F(temp2,temp2,400,0,4));
    }
  }
  void Fill(double HT, double MHT, int NJets, int BTags, double Weight);
  void saveResults(TDirectory* MainDirectory);
private:
  std::vector<TH1F*> searchBinsTh1Fs_;
  
};
void AverageWeight::Fill(double HT, double MHT, int NJets, int BTags, double Weight)
{
  unsigned int bin = GetBinNumber(HT,MHT,NJets,BTags);
  
  if(bin<bins_.size()+2) 
  {
    searchBinsTh1Fs_[bin]->Fill(Weight);
  }
}
void AverageWeight::saveResults(TDirectory* MainDirectory)
{
  MainDirectory->mkdir("AvargeWeights");
  //      std::cout<<"name: "<<name_<<std::endl;
  TDirectory *dir = (TDirectory*)MainDirectory->Get("AvargeWeights");
  dir->cd();
  std::cout<<"Prining the mean and the meanerror of each search region for the prediction weight:\n";
  const char separator    = ' ';
  const int nameWidth     = 12;
  const int numWidth      = 8;
  cout << setw(3) << setfill(separator) << "Bin";
  cout << setw(nameWidth) << setfill(separator) << "Mean";
  cout << setw(nameWidth) << setfill(separator) << "RMS";
  cout << setw(nameWidth) << setfill(separator) << "Lowest";
  cout << setw(nameWidth) << setfill(separator) << "Highest";
  cout<<endl;
  for(unsigned int i=1; i<searchBinsTh1Fs_.size();i++) 
  {
    
    cout << setw(3) << setfill(separator) << i;
    cout << setw(nameWidth) << setfill(separator) <<searchBinsTh1Fs_[i]->GetMean(1);
    cout << setw(nameWidth) << setfill(separator) <<searchBinsTh1Fs_[i]->GetRMS(1);
    cout << setw(nameWidth) << setfill(separator) <<searchBinsTh1Fs_[i]->GetBinCenter(searchBinsTh1Fs_[i]->FindFirstBinAbove(0.01) );
    cout << setw(nameWidth) << setfill(separator) <<searchBinsTh1Fs_[i]->GetBinCenter(searchBinsTh1Fs_[i]->FindLastBinAbove(0.01) );
    cout<<endl;
    searchBinsTh1Fs_[i]->Write();
    //              std::cout<<"Bin    |     Mean     |    RMS       |    Lowest Weight      | Highest Weight\n";
    /*
     *                std::cout<<i+1<<"|";
     *                std::cout<<searchBinsTh1Fs_[i]->GetMean(1)<<"|";
     *                std::cout<<searchBinsTh1Fs_[i]->GetRMS(1)<<"|";
     *                std::cout<<searchBinsTh1Fs_[i]->GetBinCenter(searchBinsTh1Fs_[i]->FindFirstBinAbove(0.01) )<<"|";
     *                std::cout<<searchBinsTh1Fs_[i]->GetBinCenter(searchBinsTh1Fs_[i]->FindLastBinAbove(0.01) )<<"|";*/
    //              std::cout<<std::endl;
    //              std::cout<<"["<<i+1<<"]: "<<searchBinsTh1Fs_[i]->GetMean(1)<<" | "<<searchBinsTh1Fs_[i]->GetRMS(1)<<" |    "<<searchBinsTh1Fs_[i]->GetBinCenter(searchBinsTh1Fs_[i]->FindFirstBinAbove(0.01) )<<" |      "<<searchBinsTh1Fs_[i]->GetBinCenter(searchBinsTh1Fs_[i]->FindLastBinAbove(0.01) )<<"\n";
  }
  std::cout<<"--------------------------------------------------------\n";
}

void SimpleClosure()
{
  
  
  //Reset ROOT and connect tree file
  gROOT->Reset();
  TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Expectation.root");
  if (!f) {
    f = new TFile("Expectation.root");
  }
  // output tree
  TFile *outPutFile = new TFile("Closure.root","RECREATE"); 
  outPutFile->cd();
  TTree* OutPutTreeExp_ = new TTree("ResultExp","Result Lost-Lepton Tree for plotting tool");
  TTree* OutPutTreePre_ = new TTree("ResultPre","Result Lost-Lepton Tree for plotting tool");
  UShort_t Bin=0;
  Float_t Weight_=0, PredictionWeight_=0; 
  
  OutPutTreeExp_->Branch("Weight", &Weight_, "Weight/F");
  OutPutTreePre_->Branch("Weight", &Weight_, "Weight/F");
  OutPutTreePre_->Branch("totalWeightDiLep", &PredictionWeight_, "totalWeightDiLep/F");
  OutPutTreeExp_->Branch("Bin",&Bin,"Bin/s");
  OutPutTreePre_->Branch("Bin",&Bin,"Bin/s");
  //
  UShort_t muAcc_=0, muIso_=0, muReco_=0;
  OutPutTreeExp_->Branch("muAcc",&muAcc_,"muAcc/s");
  OutPutTreeExp_->Branch("muReco",&muReco_,"muReco/s");
  OutPutTreeExp_->Branch("muIso",&muIso_,"muIso/s");
  
  UShort_t elecAcc_=0, elecIso_=0, elecReco_=0;
  OutPutTreeExp_->Branch("elecAcc",&elecAcc_,"elecAcc/s");
  OutPutTreeExp_->Branch("elecReco",&elecReco_,"elecReco/s");
  OutPutTreeExp_->Branch("elecIso",&elecIso_,"elecIso/s");
  //
  Float_t muIsoWeight_=0, muRecoWeight_=0, muAccWeight_=0;
  OutPutTreePre_->Branch("muIsoWeight", &muIsoWeight_, "muIsoWeight/F");
  OutPutTreePre_->Branch("muRecoWeight", &muRecoWeight_, "muRecoWeight/F");
  OutPutTreePre_->Branch("muAccWeight", &muAccWeight_, "muAccWeight/F");
  
  Float_t elecIsoWeight_=0, elecRecoWeight_=0, elecAccWeight_=0;
  OutPutTreePre_->Branch("elecIsoWeight", &elecIsoWeight_, "elecIsoWeight/F");
  OutPutTreePre_->Branch("elecRecoWeight", &elecRecoWeight_, "elecRecoWeight/F");
  OutPutTreePre_->Branch("elecAccWeight", &elecAccWeight_, "elecAccWeight/F");
  
  UShort_t selectedIDIsoMuonsNum_=0, selectedIDIsoElectronsNum_=0;
  OutPutTreePre_->Branch("selectedIDIsoMuonsNum",&selectedIDIsoMuonsNum_,"selectedIDIsoMuonsNum/s");
  OutPutTreePre_->Branch("selectedIDIsoElectronsNum",&selectedIDIsoElectronsNum_,"selectedIDIsoElectronsNum/s");
  
  TTree* LostLeptonExpectation = (TTree*) f->Get("LostLeptonExpectation");
  
  
  SearchBinEventCount * ControlSampleMu_ = new SearchBinEventCount("ControlSampleMu");
  SearchBinEventCount * ControlSampleElec_ = new SearchBinEventCount("ControlSampleElec");
  
  SearchBinEventCount * totalExpectation_ = new SearchBinEventCount("TotalLostLeptonExpecation");
  SearchBinEventCount * totalPrediction_ = new SearchBinEventCount("TotalLostLeptonPrediction");
  SearchBinEventCount * totalPredictionMu_ = new SearchBinEventCount("TotalLostLeptonPredictionMu");
  SearchBinEventCount * totalPredictionElec_ = new SearchBinEventCount("TotalLostLeptonPredictionElec");
  
  SearchBinEventCount * totalExpectationIsoTrackReduction_ = new SearchBinEventCount("TotalLostLeptonExpecationIsoTrackReduction");
  SearchBinEventCount * totalPredictionIsoTrackReduction_ = new SearchBinEventCount("TotalLostLeptonPredictionIsoTrackReduction");
  SearchBinEventCount * totalPredictionMuIsoTrackReduction_ = new SearchBinEventCount("TotalLostLeptonPredictionMuIsoTrackReduction");
  SearchBinEventCount * totalPredictionElecIsoTrackReduction_ = new SearchBinEventCount("TotalLostLeptonPredictionElecIsoTrackReduction");
  
  // separted closure
  SearchBinEventCount * totalExpectationMuAcc_ = new SearchBinEventCount("TotalLostLeptonExpecationMuAcc");
  SearchBinEventCount * totalPredictionMuCSMuAcc_ = new SearchBinEventCount("TotalLostLeptonPredictionMuCSMuAcc");
  SearchBinEventCount * totalPredictionElecCSMuAcc_ = new SearchBinEventCount("TotalLostLeptonPredictionElecCSMuAcc");
  
  SearchBinEventCount * totalExpectationMuReco_ = new SearchBinEventCount("TotalLostLeptonExpecationMuReco");
  SearchBinEventCount * totalPredictionMuCSMuReco_ = new SearchBinEventCount("TotalLostLeptonPredictionMuCSMuReco");
  SearchBinEventCount * totalPredictionElecCSMuReco_ = new SearchBinEventCount("TotalLostLeptonPredictionElecCSMuReco");
  
  SearchBinEventCount * totalExpectationMuIso_ = new SearchBinEventCount("TotalLostLeptonExpecationMuIso");
  SearchBinEventCount * totalPredictionMuCSMuIso_ = new SearchBinEventCount("TotalLostLeptonPredictionMuCSMuIso");
  SearchBinEventCount * totalPredictionElecCSMuIso_ = new SearchBinEventCount("TotalLostLeptonPredictionElecCSMuIso");
  
  
  
  SearchBinEventCount * totalExpectationElecAcc_ = new SearchBinEventCount("TotalLostLeptonExpecationElecAcc");
  SearchBinEventCount * totalPredictionMuCSElecAcc_ = new SearchBinEventCount("TotalLostLeptonPredictionMuCSElecAcc");
  SearchBinEventCount * totalPredictionElecCSElecAcc_ = new SearchBinEventCount("TotalLostLeptonPredictionElecCSElecAcc");
  
  SearchBinEventCount * totalExpectationElecReco_ = new SearchBinEventCount("TotalLostLeptonExpecationElecReco");
  SearchBinEventCount * totalPredictionMuCSElecReco_ = new SearchBinEventCount("TotalLostLeptonPredictionMuCSElecReco");
  SearchBinEventCount * totalPredictionElecCSElecReco_ = new SearchBinEventCount("TotalLostLeptonPredictionElecCSElecReco");
  
  SearchBinEventCount * totalExpectationElecIso_ = new SearchBinEventCount("TotalLostLeptonExpecationElecIso");
  SearchBinEventCount * totalPredictionMuCSElecIso_ = new SearchBinEventCount("TotalLostLeptonPredictionMuCSElecIso");
  SearchBinEventCount * totalPredictionElecCSElecIso_ = new SearchBinEventCount("TotalLostLeptonPredictionElecCSElecIso");
  
  double totalExp=0, totalPre=0;
  double totalExpError=0, totalPreError=0;
  double totalPreMu=0, totalPreMuError=0;
  double totalPreElec=0, totalPreElecError=0;
  
  double totalExpMuAcc=0, totalExpMuReco=0, totalExpMuIso=0;
  
  double totalPreMuAcc=0, totalPreMuReco=0, totalPreMuIso=0;
  
  
  double totalExpElecAcc=0, totalExpElecReco=0, totalExpElecIso=0;
  
  double totalPreElecAcc=0, totalPreElecReco=0, totalPreElecIso=0;
  
  //Declaration of leaves types
  Float_t         HT;
  Float_t         MHT;
  UShort_t        NJets;
  UShort_t        BTags;
  Float_t         Weight;
  
  UShort_t        Expectation;
  UShort_t        muAcc;
  UShort_t        muReco;
  UShort_t        muIso;
  UShort_t        elecAcc;
  UShort_t        elecReco;
  UShort_t        elecIso;
  UShort_t        IsolatedTracksNum;
  UShort_t        ExpectationDiLep;
  UShort_t        ExpectationReductionIsoTrack;
  
  // Set branch addresses.
  LostLeptonExpectation->SetBranchAddress("HT",&HT);
  LostLeptonExpectation->SetBranchAddress("MHT",&MHT);
  LostLeptonExpectation->SetBranchAddress("NJets",&NJets);
  LostLeptonExpectation->SetBranchAddress("BTags",&BTags);
  LostLeptonExpectation->SetBranchAddress("Weight",&Weight);
  
  LostLeptonExpectation->SetBranchAddress("Expectation",&Expectation);
  LostLeptonExpectation->SetBranchAddress("ExpectationReductionIsoTrack",&ExpectationReductionIsoTrack);
  LostLeptonExpectation->SetBranchAddress("muAcc",&muAcc);
  LostLeptonExpectation->SetBranchAddress("muReco",&muReco);
  LostLeptonExpectation->SetBranchAddress("muIso",&muIso);
  
  LostLeptonExpectation->SetBranchAddress("elecAcc",&elecAcc);
  LostLeptonExpectation->SetBranchAddress("elecReco",&elecReco);
  LostLeptonExpectation->SetBranchAddress("elecIso",&elecIso);
  
  LostLeptonExpectation->SetBranchAddress("IsolatedTracksNum",&IsolatedTracksNum);
  LostLeptonExpectation->SetBranchAddress("ExpectationDiLep",&ExpectationDiLep);
  
  
  Long64_t nentries = LostLeptonExpectation->GetEntries();
  
  SearchBins *SearchBins_ = new SearchBins();
  
  // average weight for each search bin
  AverageWeight *averageWeight = new AverageWeight();
  
  
  Long64_t nbytes = 0;
  for (Long64_t i=0; i<nentries;i++) {
    nbytes += LostLeptonExpectation->GetEntry(i);
    // total expectation
    if(NJets<3.6) continue;
    if(Expectation==1 && NJets>3.1)
    {
      totalExpectation_->Fill(HT,MHT,NJets,BTags,Weight);
      totalExp+=Weight;
      totalExpError+= Weight*Weight;
      Bin = SearchBins_->GetBinNumber(HT,MHT,NJets,BTags);
      Weight_=Weight;
      muAcc_=muAcc; muReco_=muReco; muIso_=muIso; elecAcc_=elecAcc; elecReco_=elecReco; elecIso_=elecIso;
      OutPutTreeExp_->Fill();
    }
    if(Expectation==1 && ExpectationReductionIsoTrack==0)
    {
      totalExpectationIsoTrackReduction_->Fill(HT,MHT,NJets,BTags,Weight);
    }
    if(muAcc==0)
    {
      totalExpectationMuAcc_->Fill(HT,MHT,NJets,BTags,Weight);
      totalExpMuAcc+=Weight;
    }
    if(muReco==0)
    {
      totalExpectationMuReco_->Fill(HT,MHT,NJets,BTags,Weight);
      totalExpMuReco+=Weight;
    }
    if(muIso==0)
    {
      totalExpectationMuIso_->Fill(HT,MHT,NJets,BTags,Weight);
      totalExpMuIso+=Weight;
    }
    
    if(elecAcc==0)
    {
      totalExpectationElecAcc_->Fill(HT,MHT,NJets,BTags,Weight);
      totalExpElecAcc+=Weight;
    }
    if(elecReco==0)
    {
      totalExpectationElecReco_->Fill(HT,MHT,NJets,BTags,Weight);
      totalExpElecReco+=Weight;
    }
    if(elecIso==0)
    {
      totalExpectationElecIso_->Fill(HT,MHT,NJets,BTags,Weight);
      totalExpElecIso+=Weight;
    }
  }
  
  // loop on prediction
  gROOT->Reset();
  TFile *f1 = (TFile*)gROOT->GetListOfFiles()->FindObject("Prediction.root");
  if (!f1) {
    f1 = new TFile("Prediction.root");
  }
  TTree* LostLeptonPrediction = (TTree*) f1->Get("LostLeptonPrediction");
  
  Float_t         MTW;
  UShort_t        selectedIDIsoMuonsNum;
  UShort_t        selectedIDIsoElectronsNum;
  
  Float_t         totalWeightDiLep;
  Float_t         totalWeightDiLepIsoTrackReduced;
  
  Float_t         muIsoWeight;
  Float_t         muRecoWeight;
  Float_t         muAccWeight;
  
  Float_t         elecAccWeight;
  Float_t         elecRecoWeight;
  Float_t         elecIsoWeight;
  
  
  
  LostLeptonPrediction->SetBranchAddress("HT",&HT);
  LostLeptonPrediction->SetBranchAddress("MHT",&MHT);
  LostLeptonPrediction->SetBranchAddress("NJets",&NJets);
  LostLeptonPrediction->SetBranchAddress("BTags",&BTags);
  LostLeptonPrediction->SetBranchAddress("Weight",&Weight);
  
  LostLeptonPrediction->SetBranchAddress("MTW",&MTW);
  LostLeptonPrediction->SetBranchAddress("selectedIDIsoMuonsNum",&selectedIDIsoMuonsNum);
  LostLeptonPrediction->SetBranchAddress("selectedIDIsoElectronsNum",&selectedIDIsoElectronsNum);
  LostLeptonPrediction->SetBranchAddress("totalWeightDiLep",&totalWeightDiLep);
  LostLeptonPrediction->SetBranchAddress("totalWeightDiLepIsoTrackReduced",&totalWeightDiLepIsoTrackReduced);
  
  LostLeptonPrediction->SetBranchAddress("muIsoWeight",&muIsoWeight);
  LostLeptonPrediction->SetBranchAddress("muRecoWeight",&muRecoWeight);
  LostLeptonPrediction->SetBranchAddress("muAccWeight",&muAccWeight);
  
  LostLeptonPrediction->SetBranchAddress("elecAccWeight",&elecAccWeight);
  LostLeptonPrediction->SetBranchAddress("elecRecoWeight",&elecRecoWeight);
  LostLeptonPrediction->SetBranchAddress("elecIsoWeight",&elecIsoWeight);
  
  
  
  
  
  nentries = LostLeptonPrediction->GetEntries();
  nbytes = 0;
  for (Long64_t i=0; i<nentries;i++) {
    nbytes += LostLeptonPrediction->GetEntry(i);
    // total expectation
    if(MTW>100 || NJets<3.7)continue;
    Bin = SearchBins_->GetBinNumber(HT,MHT,NJets,BTags);
    Weight_=Weight;
    selectedIDIsoMuonsNum_=selectedIDIsoMuonsNum;
    selectedIDIsoElectronsNum_=selectedIDIsoElectronsNum;
    if(selectedIDIsoMuonsNum==1 && selectedIDIsoElectronsNum==0)
    {
      averageWeight->Fill(HT,MHT,NJets,BTags,totalWeightDiLepIsoTrackReduced/Weight);
      ControlSampleMu_->Fill(HT,MHT,NJets,BTags,Weight);
      
      totalPrediction_->Fill(HT,MHT,NJets,BTags,totalWeightDiLep/2);
      totalPredictionMu_->Fill(HT,MHT,NJets,BTags,totalWeightDiLep);
      totalPre+=totalWeightDiLep;
      totalPreError+= totalWeightDiLep*totalWeightDiLep;
      totalPreMu+=totalWeightDiLep;
      totalPreMuError+= totalWeightDiLep*totalWeightDiLep;
      // isotrackveto applied
      totalPredictionIsoTrackReduction_->Fill(HT,MHT,NJets,BTags,totalWeightDiLepIsoTrackReduced/2);
      totalPredictionMuIsoTrackReduction_->Fill(HT,MHT,NJets,BTags,totalWeightDiLepIsoTrackReduced);
      // separted closure
      totalPredictionMuCSMuAcc_->Fill(HT,MHT,NJets,BTags,muAccWeight);
      totalPreMuAcc+=muAccWeight;
      totalPredictionMuCSMuReco_->Fill(HT,MHT,NJets,BTags,muRecoWeight);
      totalPreMuReco+=muRecoWeight;
      totalPredictionMuCSMuIso_->Fill(HT,MHT,NJets,BTags,muIsoWeight);
      totalPreMuIso+=muIsoWeight;
      
      totalPredictionMuCSElecAcc_->Fill(HT,MHT,NJets,BTags,elecAccWeight);
      totalPreElecAcc+=elecAccWeight;
      totalPredictionMuCSElecReco_->Fill(HT,MHT,NJets,BTags,elecRecoWeight);
      totalPreElecReco+=elecRecoWeight;
      totalPredictionMuCSElecIso_->Fill(HT,MHT,NJets,BTags,elecIsoWeight);
      totalPreElecIso+=elecIsoWeight;
      muIsoWeight_=muIsoWeight; muRecoWeight_=muRecoWeight; muAccWeight_=muAccWeight;  elecIsoWeight_=elecIsoWeight; elecRecoWeight_=elecRecoWeight; elecAccWeight_=elecAccWeight; 
      PredictionWeight_= totalWeightDiLep;
      OutPutTreePre_->Fill();
    }
    if(selectedIDIsoMuonsNum==0 && selectedIDIsoElectronsNum==1)
    {
      averageWeight->Fill(HT,MHT,NJets,BTags,totalWeightDiLepIsoTrackReduced/Weight);
      ControlSampleElec_->Fill(HT,MHT,NJets,BTags,Weight);
      
      totalPrediction_->Fill(HT,MHT,NJets,BTags,totalWeightDiLep/2);
      totalPredictionElec_->Fill(HT,MHT,NJets,BTags,totalWeightDiLep);
      totalPre+=totalWeightDiLep;
      totalPreError+= totalWeightDiLep*totalWeightDiLep;
      totalPreElec+=totalWeightDiLep;
      totalPreElecError+= totalWeightDiLep*totalWeightDiLep;
      // isotrackveto applied
      totalPredictionIsoTrackReduction_->Fill(HT,MHT,NJets,BTags,totalWeightDiLepIsoTrackReduced/2);
      totalPredictionElecIsoTrackReduction_->Fill(HT,MHT,NJets,BTags,totalWeightDiLepIsoTrackReduced);
      // separted closure
      totalPredictionElecCSMuAcc_->Fill(HT,MHT,NJets,BTags,muAccWeight);
      totalPredictionElecCSMuReco_->Fill(HT,MHT,NJets,BTags,muRecoWeight);
      totalPredictionElecCSMuIso_->Fill(HT,MHT,NJets,BTags,muIsoWeight);
      
      totalPredictionElecCSElecAcc_->Fill(HT,MHT,NJets,BTags,elecAccWeight);
      totalPredictionElecCSElecReco_->Fill(HT,MHT,NJets,BTags,elecRecoWeight);
      totalPredictionElecCSElecIso_->Fill(HT,MHT,NJets,BTags,elecIsoWeight);
      PredictionWeight_= totalWeightDiLep;
      OutPutTreePre_->Fill();
    }
  }
  
  TH1F* expectationTH1 = (TH1F*) totalExpectation_->getFullTH1F();
  TH1F* predictionTH1 = (TH1F*) totalPrediction_->getFullTH1F();
  TH1F* FullClosure = (TH1F*) expectationTH1->Clone();
  FullClosure->Divide(predictionTH1,expectationTH1,1,1,"B");
  FullClosure->SetName("LostLeptonClosure");
  FullClosure->SetTitle("Closure of lost-lepton method");
  
  TH1F* predictionTH1Mu = (TH1F*) totalPredictionMu_->getFullTH1F();
  TH1F* FullClosureMu = (TH1F*) expectationTH1->Clone();
  FullClosureMu->Divide(predictionTH1Mu,expectationTH1,1,1,"B");
  FullClosureMu->SetName("LostLeptonClosureMuCS");
  FullClosureMu->SetTitle("Closure of lost-lepton method #mu control-sample");
  
  TH1F* predictionTH1Elec = (TH1F*) totalPredictionElec_->getFullTH1F();
  TH1F* FullClosureElec = (TH1F*) expectationTH1->Clone();
  FullClosureElec->Divide(predictionTH1Elec,expectationTH1,1,1,"B");
  FullClosureElec->SetName("LostLeptonClosureElecCS");
  FullClosureElec->SetTitle("Closure of lost-lepton method elec control-sample");
  
  std::cout<<"Result:\n TotalExpectation: "<<totalExp<<" +- " << sqrt(totalExpError)<<"\n TotalPrediction: "<<totalPre/2<<" +- "<<sqrt(totalPreError)/2<<std::endl;
  std::cout<<"TotalExpectation: "<<totalExp<<" +- " << sqrt(totalExpError)<<"\n TotalPredictionMu: "<<totalPreMu<<" +- "<<sqrt(totalPreMuError)<<std::endl;
  std::cout<<"TotalExpectation: "<<totalExp<<" +- " << sqrt(totalExpError)<<"\n TotalPredictionElec: "<<totalPreElec<<" +- "<<sqrt(totalPreElecError)<<std::endl;
  std::cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
  std::cout<<"MuAccExp: "<<totalExpMuAcc<<"\n MuAccPre: "<<totalPreMuAcc<<std::endl;
  std::cout<<"MuRecoExp: "<<totalExpMuReco<<"\n MuRecoPre: "<<totalPreMuReco<<std::endl;
  std::cout<<"MuIsoExp: "<<totalExpMuIso<<"\n MuIsoPre: "<<totalPreMuIso<<std::endl;
  std::cout<<"ElecAccExp: "<<totalExpElecAcc<<"\n ElecAccPre: "<<totalPreElecAcc<<std::endl;
  std::cout<<"ElecRecoExp: "<<totalExpElecReco<<"\n ElecRecoPre: "<<totalPreElecReco<<std::endl;
  std::cout<<"ElecIsoExp: "<<totalExpElecIso<<"\n ElecIsoPre: "<<totalPreElecIso<<std::endl;
  
  outPutFile->cd();
  OutPutTreeExp_->Write();
  OutPutTreePre_->Write();
  FullClosure->Write();
  FullClosureMu->Write();
  FullClosureElec->Write();
  outPutFile->mkdir("Closures");
  TDirectory *dClosures = (TDirectory*)outPutFile->Get("Closures");
  
  // produce stack plots
  std::vector<TH1F*> mu, elec;
  mu.push_back(totalExpectationMuAcc_->getFullTH1F());
  mu.push_back(totalExpectationMuReco_->getFullTH1F());
  mu.push_back(totalExpectationMuIso_->getFullTH1F());
  std::vector<TString> labels;
  labels.push_back("Out of acceptance");
  labels.push_back("Not reconstructed");
  labels.push_back("Not isolated");
  elec.push_back(totalExpectationElecAcc_->getFullTH1F());
  elec.push_back(totalExpectationElecReco_->getFullTH1F());
  elec.push_back(totalExpectationElecIso_->getFullTH1F());
  
  SaveStack(mu, dClosures, (TString)"MuStack", (TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, #mu expectation",labels,(TString)";Bin;Fraction");
  SaveStack(elec, dClosures, (TString)"ElecStack", (TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, e expectation",labels,(TString)";Bin;Fraction");
  // search variables
  std::vector<TString> searchvariables;
  searchvariables.push_back("H_{T} GeV");
  searchvariables.push_back("#slash{H}_{T} GeV");
  searchvariables.push_back("N_{jets}");
  searchvariables.push_back("B_{tags}");
  std::vector<TString> sv;
  sv.push_back("HT"); sv.push_back("MHT"); sv.push_back("NJets"); sv.push_back("BTags");
  
  for(unsigned int i=0; i<searchvariables.size();i++)
  {
    mu.clear(); elec.clear();
    mu.push_back(totalExpectationMuAcc_->getSearchVariables()[i]);
    mu.push_back(totalExpectationMuReco_->getSearchVariables()[i]);
    mu.push_back(totalExpectationMuIso_->getSearchVariables()[i]);
    elec.push_back(totalExpectationElecAcc_->getSearchVariables()[i]);
    elec.push_back(totalExpectationElecReco_->getSearchVariables()[i]);
    elec.push_back(totalExpectationElecIso_->getSearchVariables()[i]);
    SaveStack(mu, dClosures, (TString)("MuStack"+sv[i]), (TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, #mu expectation",labels,(TString)";"+searchvariables[i]+";Fraction");
    SaveStack(elec, dClosures, (TString)("ElecStack"+sv[i]), (TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, e expectation",labels,(TString)";"+searchvariables[i]+";Fraction");
  }
  SaveClosure(totalPredictionMuCSMuAcc_->getFullTH1F(), totalExpectationMuAcc_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu} Closure Test: #mu_{acc};Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionMuCSMuReco_->getFullTH1F(), totalExpectationMuReco_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu} Closure Test: #mu_{reco};Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionMuCSMuIso_->getFullTH1F(), totalExpectationMuIso_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu} Closure Test: #mu_{iso};Bin;#frac{Exp.}{Pred.}");
  
  SaveClosure(totalPredictionMuCSElecAcc_->getFullTH1F(), totalExpectationElecAcc_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu} Closure Test: e_{acc};Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionMuCSElecReco_->getFullTH1F(), totalExpectationElecReco_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu} Closure Test: e_{reco};Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionMuCSElecIso_->getFullTH1F(), totalExpectationElecIso_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu} Closure Test: e_{iso};Bin;#frac{Exp.}{Pred.}");
  
  SaveClosure(totalPredictionElecCSMuAcc_->getFullTH1F(), totalExpectationMuAcc_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{e} Closure Test: #mu_{acc};Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionElecCSMuReco_->getFullTH1F(), totalExpectationMuReco_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{e} Closure Test: #mu_{reco};Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionElecCSMuIso_->getFullTH1F(), totalExpectationMuIso_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{e} Closure Test: #mu_{iso};Bin;#frac{Exp.}{Pred.}");
  
  SaveClosure(totalPredictionElecCSElecAcc_->getFullTH1F(), totalExpectationElecAcc_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{e} Closure Test: e_{acc};Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionElecCSElecReco_->getFullTH1F(), totalExpectationElecReco_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{e} Closure Test: e_{reco};Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionElecCSElecIso_->getFullTH1F(), totalExpectationElecIso_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{e} Closure Test: e_{iso};Bin;#frac{Exp.}{Pred.}");
  
  
  SaveClosure(totalPrediction_->getFullTH1F(), totalExpectation_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu&e} Closure Test (no trk.);Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionMu_->getFullTH1F(), totalExpectation_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu} Closure Test (no trk.);Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionElec_->getFullTH1F(), totalExpectation_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{e} Closure Test (no trk.);Bin;#frac{Exp.}{Pred.}");
  
  
  SaveClosure(totalPredictionIsoTrackReduction_->getFullTH1F(), totalExpectationIsoTrackReduction_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu&e} Closure Test;Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionMuIsoTrackReduction_->getFullTH1F(), totalExpectationIsoTrackReduction_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{#mu} Closure Test ;Bin;#frac{Exp.}{Pred.}");
  SaveClosure(totalPredictionElecIsoTrackReduction_->getFullTH1F(), totalExpectationIsoTrackReduction_->getFullTH1F(), dClosures,(TString)"Simulation, L=4 fb^{-1}, #sqrt{s}=13 TeV, CS_{e} Closure Test ;Bin;#frac{Exp.}{Pred.}");
  
  
  outPutFile->mkdir("Expectation");
  TDirectory *dExpectation = (TDirectory*)outPutFile->Get("Expectation");
  dExpectation->cd();
  totalExpectation_->saveResults(dExpectation);
  outPutFile->mkdir("Prediction");
  TDirectory *dPrediction = (TDirectory*)outPutFile->Get("Prediction");
  dPrediction->cd();
  totalPrediction_->saveResults(dPrediction);
  totalPredictionMu_->saveResults(dPrediction);
  totalPredictionElec_->saveResults(dPrediction);
  
  outPutFile->mkdir("ControlSample");
  TDirectory *dControlSample = (TDirectory*)outPutFile->Get("ControlSample");
  SaveClosure(ControlSampleElec_->getFullTH1F(), ControlSampleMu_->getFullTH1F(), dControlSample);
  dControlSample->cd();
  ControlSampleMu_->saveResults(dControlSample);
  ControlSampleElec_->saveResults(dControlSample);
  averageWeight->saveResults(dPrediction);
  
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
    std::cout<<"Error event fits in no bin!!! HT: "<<HT<<", MHT: "<<MHT<<", NJets: "<<NJets<<", BTags: "<<BTags<<std::endl;
    result=999;
  }
  //      if(result<18 && result>16)
  //      {
  //              std::cout<<"ResultBin: "<<result+1<<" HT: "<<HT<<", MHT: "<<MHT<<", NJets: "<<NJets<<", BTags: "<<BTags<<std::endl;
  //      }
  if(match>0)
  {
    std::cout<<"Error event fits in more than one bin!!!! HT: "<<HT<<", MHT: "<<MHT<<", NJets: "<<NJets<<", BTags: "<<BTags<<std::endl;
  }
  return result+1; // to not use the 0 bin but start counting at 1
}


SearchBinEventCount::SearchBinEventCount(const char* name)
{
  // search variables th1f
  TH1FHT_ = new TH1F(name+(TString)"_HT",name+(TString)"_HT",25,500,3000);
  TH1FHT_->Sumw2();
  TH1FMHT_ = new TH1F(name+(TString)"_MHT",name+(TString)"_MHT",22,200,1300);
  TH1FMHT_->Sumw2();
  TH1FNJets_ = new TH1F(name+(TString)"_NJets",name+(TString)"_NJets",9,4,13);
  TH1FNJets_->Sumw2();
  TH1FBTags_ = new TH1F(name+(TString)"_BTags",name+(TString)"_BTags",5,0,5);
  TH1FBTags_->Sumw2();
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
  TH1FHT_->Fill(HT,Weight);
  TH1FMHT_->Fill(MHT,Weight);
  TH1FNJets_->Fill(NJets,Weight);
  TH1FBTags_->Fill(BTags,Weight);
  
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
  TH1FHT_->Write();
  TH1FMHT_->Write();
  TH1FNJets_->Write();
  TH1FBTags_->Write();
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


std::vector<TH1F*> SearchBinEventCount::getSearchVariables()
{
  std::vector<TH1F*> results;
  results.push_back(TH1FHT_);
  results.push_back(TH1FMHT_);
  results.push_back(TH1FNJets_);
  results.push_back(TH1FBTags_);
  return results;       
}
