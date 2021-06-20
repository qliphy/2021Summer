{
#include "TAxis.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TNtupleD.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector.h>



	TFile * input1 = new TFile ("mg267nlo_hepmc.root");
        input1->cd("");
        TTree *Outtree1 = (TTree*)input1->Get("h");

	TFile * input2 = new TFile ("mg267p8mlm.root");
        input2->cd("");
        TTree *Outtree2 = (TTree*)input2->Get("t");

	TFile * input3 = new TFile ("p8.root");
        input3->cd("");
        TTree *Outtree3 = (TTree*)input3->Get("h");

       int nentries1 = (int)Outtree1->GetEntries();
       cout<<"nentries1 = "<<nentries1<<endl;
       int nentries2 = (int)Outtree2->GetEntries();
       cout<<"nentries2 = "<<nentries2<<endl;
       int nentries3 = (int)Outtree3->GetEntries();
       cout<<"nentries3 = "<<nentries3<<endl;

       TH1D *PTA1   = new TH1D("a"," ",80,0,100);
       PTA1->Sumw2();
       TH1D *PTA2   = new TH1D("b"," ",80,0,100);
       PTA2->Sumw2();
       TH1D *PTA3   = new TH1D("c"," ",80,0,100);
       PTA3->Sumw2();

       double ptz1,weight1,ptz2,ptz3,weight3;

       Outtree1->SetBranchAddress("ptz" ,&ptz1);
       Outtree1->SetBranchAddress("weight" ,&weight1);
       Outtree2->SetBranchAddress("ptz" ,&ptz2);
       Outtree3->SetBranchAddress("ptz" ,&ptz3);
       Outtree3->SetBranchAddress("weight" ,&weight3);

       for(int i=0; i<nentries1; i++)
     {
         Outtree1->GetEntry(i);
         PTA1->Fill(ptz1,fabs(weight1)/weight1/float(nentries1));
     } 

       for(int i=0; i<nentries2; i++)
     {
         Outtree2->GetEntry(i);
         PTA2->Fill(ptz2,1.0/float(nentries2));
     } 
 
       for(int i=0; i<nentries3; i++)
     {
         Outtree3->GetEntry(i);
         PTA3->Fill(ptz3,fabs(weight3)/weight3/float(nentries3));
     } 

      TCanvas *c01 = new TCanvas("c01","",700,500);
      c01->SetLogy();
      PTA3->SetTitle("pp #rightarrow z #rightarrow #mu^{+}#mu^{-} 012Jets MLM at 13TeV LHC");
      PTA3->GetXaxis()->SetTitle("Z PT [GeV] ");
      PTA3->GetYaxis()->SetTitle("a.u.");
      PTA3->GetXaxis()->CenterTitle();
      PTA3->GetYaxis()->CenterTitle();
      PTA3->SetStats(kFALSE);
      PTA3->SetLineColor(kBlack);
      PTA3->SetLineWidth(3);
      PTA3->SetMarkerStyle(20);
      PTA3->GetXaxis()->SetTitleOffset(1.4);
      PTA3->Draw("e HIST");

      PTA2->SetLineColor(kRed);
      PTA2->SetLineWidth(2);
      PTA2->Draw("e same");
 
      PTA1->SetLineColor(kGreen);
      PTA1->SetLineWidth(2);
      PTA1->Draw("e same");

     TLegend *l1 = new TLegend(0.62,0.65,0.86,0.85);
     l1->SetBorderSize(1);
     l1->SetFillColor(0);
     l1->AddEntry(PTA1,"MG267_Pythia8_HEPMC NLO");
     l1->AddEntry(PTA2,"MG267_LHE_Pythia8 MLM");
     l1->AddEntry(PTA3,"MG267_LHE_Pythia8 NLO");
     l1->Draw();


     c01->SaveAs("compare-ptll2.png");

}
