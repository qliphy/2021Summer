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
	double ptz, ez, weight;
	TTree *h = new TTree("h","h");
 	h->Branch("ptz",&ptz);
 	h->Branch("ez",&ez);
 	h->Branch("weight",&weight);
  	// specify an input file
	HepMC::IO_GenEvent ascii_in("mg267nlo.hepmc",std::ios::in);

  	// get the first event
  	HepMC::GenEvent* evt = ascii_in.read_next_event();
	int EveN=0, vbarcode=-1;
        while ( evt ) {
  		EveN++;
                          cout<<"------"<<endl;
		          for ( HepMC::GenEvent::particle_iterator p = evt->particles_begin(); p!=evt->particles_end(); ++p ){
				if((*p)->pdg_id()==23){
                                        vbarcode	=	(*p)->end_vertex()->barcode();                             
                                        cout<<" "<<vbarcode<<" "<<(*p)->status()<<" "<<evt->weights()[0]<<endl;
					if((*p)->status()==62)	{
						ptz      =       (*p)->momentum().perp();
						ez	=	(*p)->momentum().e();
                                                weight=evt->weights()[0];
    						h->Fill();               
                		
					 }	
		                 }
                      }
  		

  	delete evt;
  	ascii_in >> evt;
	}

  	h->Write();
  	//delete outFile;
  	return 0;
}

