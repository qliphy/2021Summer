#include <iostream>
#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC2.h"
#include "TTree.h"
#include "TVirtualPad.h"
#include "TApplication.h"
#include "TFile.h"

using namespace Pythia8;

int main() {

	// Create file
	TFile* outFile = new TFile("mg267nlo_hepmc.root", "RECREATE");

	// Book Tree.
	double px1,py1,pz1,e1;
	double px2,py2,pz2,e2;
        double weight;
	TTree *h = new TTree("h","h");
 	h->Branch("px1",&px1);
 	h->Branch("py1",&py1);
 	h->Branch("pz1",&pz1);
 	h->Branch("e1",&e1);
 	h->Branch("px2",&px2);
 	h->Branch("py2",&py2);
 	h->Branch("pz2",&pz2);
 	h->Branch("e2",&e2);
 	h->Branch("weight",&weight);
  	// specify an input file
	HepMC::IO_GenEvent ascii_in("mg267nlo.hepmc",std::ios::in);

  	// get the first event
  	HepMC::GenEvent* evt = ascii_in.read_next_event();
	int EveN=0, vbarcode=-1;

        while ( evt ) {
  		      EveN++;
                      weight=evt->weights()[0];

		          for ( HepMC::GenEvent::particle_iterator p = evt->particles_begin(); p!=evt->particles_end(); ++p ){
				//if((*p)->pdg_id()==23){
                                //        cout<<"***"<<(*p)->status()<<endl;
                                //} 
				if((*p)->pdg_id()==13){
                                //      cout<<(*p)->status()<<" "<<(*p)->momentum().e()<<endl;
					if((*p)->status()==1)	{
						px1      =       (*p)->momentum().px();
						py1      =       (*p)->momentum().py();
						pz1      =       (*p)->momentum().pz();
						e1      =        (*p)->momentum().e();
 					 }	

		                 }
				if((*p)->pdg_id()==-13){
                                //      cout<<(*p)->status()<<" "<<(*p)->momentum().e()<<endl;
					if((*p)->status()==1)	{
						px2      =       (*p)->momentum().px();
						py2      =       (*p)->momentum().py();
						pz2      =       (*p)->momentum().pz();
						e2      =        (*p)->momentum().e();
 					 }	

		                 }

                      }
        cout<<EveN<<endl;
        h->Fill();  
  	delete evt;
  	ascii_in >> evt;
	}

  	h->Write();
  	//delete outFile;
  	return 0;
}

