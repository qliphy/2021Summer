void test2(){

// Load shared library
 gSystem->Load("/home/qliphy/Desktop/MG5_aMC/MG5_aMC_v2_4_2/ExRootAnalysis/libExRootAnalysis.so");
 gSystem->Load("/home/qliphy/Desktop/common/root/lib/root/libPhysics.so");
// Create chain of root trees
 TChain chain("LHEF");
 TChain chain2("LHEF");
 TChain chain3("LHEF");
 TChain chain4("LHEF");
 TChain chain5("LHEF");

 TCanvas *c1= new TCanvas("c1","test graph",800,800);
 float inix= 0.0;
 float finx= 30.0;
 float nbin= 12.0;

 
TString IFile1 =   "lo.root";
chain.Add(IFile1); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
 Long64_t numberOfEntries = treeReader->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent = treeReader->UseBranch("Event");
 TClonesArray *branchParticle = treeReader->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h1= new TH1F("1_Mjj","test histogram",nbin,inix,finx);
// h1->Sumw2();
 TLorentzVector J1;
for(int i=0; i<=numberOfEntries-1; i++)
{
////*****************************************************************
    J1.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader->ReadEntry(i);
    TRootLHEFEvent *event=(TRootLHEFEvent*) branchEvent->At(0);
    int np=event->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle1=(TRootLHEFParticle*) branchParticle->At(j);
      if(abs(particle1->PID)==23 ) {
          J1.SetPtEtaPhiE(particle1->PT,particle1->Eta,particle1->Phi,particle1->E);
        }
     }
    h1->Fill(J1.Pt(), 42107./10000.); 
    
////*****************************************************************
}

TString IFile2 =   "lopythia.root";
chain2.Add(IFile2); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader2 = new ExRootTreeReader(&chain2);
 Long64_t numberOfEntries2 = treeReader2->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent2 = treeReader2->UseBranch("Event");
 TClonesArray *branchParticle2 = treeReader2->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h2= new TH1F("2_Mjj","test histogram",nbin,inix,finx);
 h2->Sumw2();
 TLorentzVector J12;
for(int i=0; i<=numberOfEntries2-1; i++)
{
////*****************************************************************
    J12.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader2->ReadEntry(i);
    TRootLHEFEvent *event2=(TRootLHEFEvent*) branchEvent2->At(0);
    int np=event2->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle12=(TRootLHEFParticle*) branchParticle2->At(j);
      if(abs(particle12->PID)==23 ) {
          J12.SetPtEtaPhiE(particle12->PT,particle12->Eta,particle12->Phi,particle12->E);
        }
     }
    h2->Fill(J12.Pt(), 42107./10000.0); 
////*****************************************************************
} 
 

TString IFile3 =   "mlm.root";
chain3.Add(IFile3); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader3 = new ExRootTreeReader(&chain3);
 Long64_t numberOfEntries3 = treeReader3->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent3 = treeReader3->UseBranch("Event");
 TClonesArray *branchParticle3 = treeReader3->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h3= new TH1F("3_Mjj","test histogram",nbin,inix,finx);
 h3->Sumw2();
 TLorentzVector J13;
for(int i=0; i<=numberOfEntries3-1; i++)
{
////*****************************************************************
    J13.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader3->ReadEntry(i);
    TRootLHEFEvent *event3=(TRootLHEFEvent*) branchEvent3->At(0);
    int np=event3->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle13=(TRootLHEFParticle*) branchParticle3->At(j);
      if(abs(particle13->PID)==23 ) {
          J13.SetPtEtaPhiE(particle13->PT,particle13->Eta,particle13->Phi,particle13->E);
        }
     }
    h3->Fill(J13.Pt(), 44650./5045.0); 
////*****************************************************************
} 
 


TString IFile4 =   "mlm0123.root";
chain4.Add(IFile4); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader4 = new ExRootTreeReader(&chain4);
 Long64_t numberOfEntries4 = treeReader4->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent4 = treeReader4->UseBranch("Event");
 TClonesArray *branchParticle4 = treeReader4->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h4= new TH1F("4_Mjj","test histogram",nbin,inix,finx);
 h4->Sumw2();
 TLorentzVector J14;
for(int i=0; i<=numberOfEntries4-1; i++)
{
////*****************************************************************
    J14.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader4->ReadEntry(i);
    TRootLHEFEvent *event4=(TRootLHEFEvent*) branchEvent4->At(0);
    int np=event4->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle14=(TRootLHEFParticle*) branchParticle4->At(j);
      if(abs(particle14->PID)==23 ) {
          J14.SetPtEtaPhiE(particle14->PT,particle14->Eta,particle14->Phi,particle14->E);
        }
     }
    h4->Fill(J14.Pt(), 43380./4222.0); 
////*****************************************************************
} 


TString IFile5 =   "nlo.root";
chain5.Add(IFile5); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader5 = new ExRootTreeReader(&chain5);
 Long64_t numberOfEntries5 = treeReader5->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent5 = treeReader5->UseBranch("Event");
 TClonesArray *branchParticle5 = treeReader5->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h5= new TH1F("5_Mjj","test histogram",nbin,inix,finx);
 h5->Sumw2();
 TLorentzVector J15;
for(int i=0; i<=numberOfEntries5-1; i++)
{
////*****************************************************************
    J15.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader5->ReadEntry(i);
    TRootLHEFEvent *event5=(TRootLHEFEvent*) branchEvent5->At(0);
    int np=event5->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle15=(TRootLHEFParticle*) branchParticle5->At(j);
      if(abs(particle15->PID)==23 ) {
          J15.SetPtEtaPhiE(particle15->PT,particle15->Eta,particle15->Phi,particle15->E);
        }
     }
    cout<<J15.Pt()<<endl;
    h5->Fill(J15.Pt(), event5->Weight/10000.0); 
////*****************************************************************
} 


      c1->SetLogy();

      h2->SetTitle("ppZ at 13TeV LHC");
      h2->GetXaxis()->SetTitle("PT_{Z} [GeV] ");
      h2->GetYaxis()->SetTitle("a.u.");
      h2->GetXaxis()->CenterTitle();
      h2->GetYaxis()->CenterTitle();
      h2->SetStats(kFALSE);
      h2->SetLineColor(kBlue);
      h2->SetLineWidth(3);
      h2->SetMarkerStyle(20);
      h2->GetXaxis()->SetTitleOffset(1.4);
      h2->GetYaxis()->SetTitleOffset(1.4);
      h2->Draw("HIST e");

      //h1->SetLineColor(kRed);
      //h1->SetLineWidth(3);
      //h1->SetMarkerStyle(20);
      //h1->Draw("HIST e same");
      
      h3->SetLineColor(kGreen);
      h3->SetLineWidth(3);
      h3->SetMarkerStyle(20);
      h3->Draw("HIST e same");

      h4->SetLineColor(kYellow);
      h4->SetLineWidth(3);
      h4->SetMarkerStyle(20);
      h4->Draw("HIST e same");

      //h5->SetLineColor(kBlack);
      //h5->SetLineWidth(3);
      //h5->SetMarkerStyle(20);
      //h5->Draw("HIST e same");


     TLegend *l1 = new TLegend(0.48,0.7,0.75,0.84);
     l1->SetBorderSize(1);
     l1->SetFillColor(0);
     //l1->AddEntry(h1,"LO@Parton Level");
     l1->AddEntry(h2,"LO+Pythia");
     l1->AddEntry(h3,"MLM 012 Matching");
     l1->AddEntry(h4,"MLM 0123 Matching");
     //l1->AddEntry(h5,"NLO");
     l1->Draw();
     c1->SaveAs("PTZ.png");
 
 
}
