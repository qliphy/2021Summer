// main02.cc is a part of the PYTHIA event generator.
// Copyright (C) 2019 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// This is a simple test program. It fits on one slide in a talk.
// It studies the pT_Z spectrum at the Tevatron.

#include "Pythia8/Pythia.h"
#include "TTree.h"
#include "TFile.h"
using namespace Pythia8;
int main() {

  // Create file
  TFile* outFile = new TFile("p8.root", "RECREATE");
  double ptz, ez; 
  TTree *t = new TTree("t","t");
  t->Branch("ptz",&ptz);
  t->Branch("ez",&ez);
  // Generator. Process selection. Tevatron initialization. Histogram.
  Pythia pythia;
  pythia.readString("Beams:idB = 2212");
  pythia.readString("Beams:eCM = 14000.");
  pythia.readString("WeakSingleBoson:ffbar2gmZ = on");
  pythia.readString("PhaseSpace:mHatMin = 80.");
  pythia.readString("PhaseSpace:mHatMax = 120.");
  pythia.init();
  Hist pTZ("dN/dpTZ", 100, 0., 100.);
  // Begin event loop. Generate event. Skip if error. List first one.
  for (int iEvent = 0; iEvent < 1000; ++iEvent) {
    if (!pythia.next()) continue;
    // Loop over particles in event. Find last Z0 copy. Fill its pT.
    int iZ = 0;
    for (int i = 0; i < pythia.event.size(); ++i)
      if (pythia.event[i].id() == 23) iZ = i;
    pTZ.fill( pythia.event[iZ].pT() );
    ptz=pythia.event[iZ].pT();
    ez=pythia.event[iZ].e();
  // End of event loop. Statistics. Histogram. Done.
    t->Fill();
  }
  pythia.stat();
  cout << pTZ;
  t->Write();
  return 0;
}
