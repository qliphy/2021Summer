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

	TFile * input3 = new TFile ("mg267fxfx_hepmc.root");
        input3->cd("");
        TTree *Outtree3 = (TTree*)input3->Get("h");
 
	TFile * input4 = new TFile ("mg242p6zmmNLO.root");
        input4->cd("");
        TTree *Outtree4 = (TTree*)input4->Get("tree");



       int nentries1 = (int)Outtree1->GetEntries();
       cout<<"nentries1 = "<<nentries1<<endl;
       int nentries2 = (int)Outtree2->GetEntries();
       cout<<"nentries2 = "<<nentries2<<endl;
       int nentries3 = (int)Outtree3->GetEntries();
       cout<<"nentries3 = "<<nentries3<<endl;
       int nentries4 = (int)Outtree4->GetEntries();
       cout<<"nentries4 = "<<nentries4<<endl;

       TH1D *PTA1   = new TH1D("a"," ",50,0,100);
       PTA1->Sumw2();
       TH1D *PTA2   = new TH1D("b"," ",50,0,100);
       PTA2->Sumw2();
       TH1D *PTA3   = new TH1D("c"," ",50,0,100);
       PTA3->Sumw2();
       TH1D *PTA4   = new TH1D("d"," ",50,0,100);
       PTA4->Sumw2();

       double px1,py1,pz1,e1,weight1;
       double px2,py2,pz2,e2, tmp;
       double ptz2;
       double pxb1,pyb1,pzb1,eb1,weightb1;
       double pxb2,pyb2,pzb2,eb2, tmpb;
       double ptz4;

       Outtree1->SetBranchAddress("px1" ,&px1);
       Outtree1->SetBranchAddress("py1" ,&py1);
       Outtree1->SetBranchAddress("pz1" ,&pz1);
       Outtree1->SetBranchAddress("e1" ,&e1);
       Outtree1->SetBranchAddress("px2" ,&px2);
       Outtree1->SetBranchAddress("py2" ,&py2);
       Outtree1->SetBranchAddress("pz2" ,&pz2);
       Outtree1->SetBranchAddress("e2" ,&e2);
       Outtree1->SetBranchAddress("weight" ,&weight1);

       Outtree3->SetBranchAddress("px1" ,&pxb1);
       Outtree3->SetBranchAddress("py1" ,&pyb1);
       Outtree3->SetBranchAddress("pz1" ,&pzb1);
       Outtree3->SetBranchAddress("e1" ,&eb1);
       Outtree3->SetBranchAddress("px2" ,&pxb2);
       Outtree3->SetBranchAddress("py2" ,&pyb2);
       Outtree3->SetBranchAddress("pz2" ,&pzb2);
       Outtree3->SetBranchAddress("e2" ,&eb2);
       Outtree3->SetBranchAddress("weight" ,&weightb1);

       Outtree2->SetBranchAddress("ptz" ,&ptz2);
       Outtree4->SetBranchAddress("ptz" ,&ptz4);


       for(int i=0; i<nentries1; i++)
     {
         Outtree1->GetEntry(i);
         tmp=sqrt((px1+px2)*(px1+px2)+(py1+py2)*(py1+py2));
         PTA1->Fill(tmp,fabs(weight1)/weight1/float(nentries1));
     } 

       for(int i=0; i<nentries2; i++)
     {
         Outtree2->GetEntry(i);
         PTA2->Fill(ptz2,1.0/float(nentries2));
     } 
 
       for(int i=0; i<nentries3; i++)
     {
         Outtree3->GetEntry(i);
         tmpb=sqrt((pxb1+pxb2)*(pxb1+pxb2)+(pyb1+pyb2)*(pyb1+pyb2));
         PTA3->Fill(tmpb,fabs(weightb1)/weightb1/float(nentries3));
     } 

 
       for(int i=0; i<nentries4; i++)
     {
         Outtree4->GetEntry(i);
         PTA4->Fill(ptz4,1.0/float(nentries4));
     } 


      TCanvas *c01 = new TCanvas("c01","",700,500);
      c01->SetLogy();
      PTA1->SetTitle("pp #rightarrow z #rightarrow #mu^{+}#mu^{-} 012Jets MLM at 13TeV LHC");
      PTA1->GetXaxis()->SetTitle("Z PT [GeV] ");
      PTA1->GetYaxis()->SetTitle("a.u.");
      PTA1->GetXaxis()->CenterTitle();
      PTA1->GetYaxis()->CenterTitle();
      PTA1->SetStats(kFALSE);
      PTA1->SetLineColor(kBlack);
      PTA1->SetLineWidth(3);
      PTA1->SetMarkerStyle(20);
      PTA1->GetXaxis()->SetTitleOffset(1.4);
      PTA1->Draw("e HIST");

      PTA2->SetLineColor(kRed);
      PTA2->SetLineWidth(2);
      PTA2->Draw("e same");
  
      PTA3->SetLineColor(kGreen);
      PTA3->SetLineWidth(2);
      PTA3->Draw("e same");

      PTA4->SetLineColor(kBlue);
      PTA4->SetLineWidth(4);
      PTA4->Draw("e same");

     TLegend *l1 = new TLegend(0.62,0.65,0.86,0.85);
     l1->SetBorderSize(1);
     l1->SetFillColor(0);
     l1->AddEntry(PTA1,"MG267_Pythia8_HEPMC NLO");
     l1->AddEntry(PTA2,"MG267_LHE_Pythia8 MLM");
     l1->AddEntry(PTA3,"MG267_Pythia8_HEPMC FxFx");
     l1->AddEntry(PTA4,"MG242_Pythia6_Toy NLO");
     l1->Draw();


     c01->SaveAs("compare-ptll2.png");

}
