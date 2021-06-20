void test2tree(){

// Load shared library
 gSystem->Load("/home/qliphy/Desktop/MG5_aMC/MG5_aMC_v2_4_2/ExRootAnalysis/libExRootAnalysis.so");
 gSystem->Load("/home/qliphy/Desktop/common/root/lib/root/libPhysics.so");
// Create chain of root trees
 TChain chain("LHEF");
  
 TString IFile1 =   "lopythia.root";
 chain.Add(IFile1); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
 Long64_t numberOfEntries = treeReader->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent = treeReader->UseBranch("Event");
 TClonesArray *branchParticle = treeReader->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TLorentzVector J1;

  TFile file("p6.root", "recreate");
  TTree *tree = new TTree("tree", "tree");
  double ptz,ez;
  tree->Branch("ptz", &ptz, "ptz/D");
  tree->Branch("ez", &ez, "ez/D");

for(int i=0; i<=numberOfEntries-1; i++)
{
////*****************************************************************
    treeReader->ReadEntry(i);
    TRootLHEFEvent *event=(TRootLHEFEvent*) branchEvent->At(0);
    int np=event->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle1=(TRootLHEFParticle*) branchParticle->At(j);
      if(abs(particle1->PID)==23 ) {
          J1.SetPtEtaPhiE(particle1->PT,particle1->Eta,particle1->Phi,particle1->E);
          ptz=particle1->PT;
          ez=particle1->E;
          tree->Fill();
        }
     }

////*****************************************************************
}
  tree->Write();
  
}
