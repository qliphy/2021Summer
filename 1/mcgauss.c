#include "TH1.h"
#include "TF1.h"
void mcgauss()
{
  int Ntry;
  cout << "Ntry=";
  cin >> Ntry;
  int n;
  n=100000;
  double crude_mc, x, sum_sigma, fx, variance;
  gRandom = new TRandom2(0);

  TH1F *h = new TH1F("h","bin3",50,2.9,3.4); 

//-------Ntry------------------

  for(int j=1; j<Ntry; j++) {

     crude_mc = sum_sigma=0. ;
     variance =0.;
     for (int i = 1; i <= n; i++){
        x=gRandom->Uniform(0,1);
        fx=4/(1.+x*x);
        crude_mc += fx;
        sum_sigma += fx*fx;
     }
     crude_mc = crude_mc/((double) n );
     sum_sigma = sum_sigma/((double) n );
     variance=sum_sigma-crude_mc*crude_mc;
     variance=variance/double(n);
     cout<<sqrt(variance)<<endl;
  h->Fill(crude_mc,1.0/double(Ntry));
 }
//-------Ntry------------------
     h->Fit("gaus");
     TF1 *fit = h->GetFunction("gaus");
     Double_t k2 = fit->GetChisquare();
     Double_t nf  = fit->GetNDF();
     cout<<"fit quality "<<k2<<" "<<nf<<endl;
     h->Draw();

}
  
