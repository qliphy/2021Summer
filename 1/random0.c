void random0()
{

        TCanvas *c1= new TCanvas("c1", "demo", 10,10,700,700);
        gRandom = new TRandom3(0);
        int n=200000; 
        int n2=100; 
        double ftot;
        TF1 *f1 = new TF1("f1","gaus",0.*n2,2.*n2);

        TH1F *h = new TH1F("h","demo",100,0.*n2,2.*n2);
        for (int i = 0; i < n; ++i) {
           ftot=0.0;
           for (int j = 0; j < n2; ++j) {
              double x=gRandom->Exp(1);
              ftot+=x;
           }
           h->Fill(ftot);
        }


/*        TH1F *h = new TH1F("h","demo",100,0.*n2,1.2*n2);
        for (int i = 0; i < n; ++i) {
           ftot=0.0;
           for (int j = 0; j < n2; ++j) {
              double x=gRandom->Uniform(0,1);
              ftot+=x;
           }
           h->Fill(ftot);
        }
*/
        h->Fit("gaus");
        TF1 *fit = h->GetFunction("gaus");
        Double_t chi2 = fit->GetChisquare();
        Double_t nf  = fit->GetNDF();
        cout<<chi2<<" "<<nf<<endl;

        h->Draw();

        c1->SaveAs("Exp_500.png");
}
