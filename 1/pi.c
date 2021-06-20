void pi()
{
//TRandom3, is based on the "Mersenne Twister generator", and is the recommended one, since it has good random proprieties (period of about 10**6000 ) and it is fast
        // create random number generator
        gRandom = new TRandom3(0);
        gRandom2 = new TRandom3(1);
        int n=1000; 
        int ftot=0;
        for (int i = 0; i < n; ++i) {
          double x=gRandom->Uniform(-1,1);
          double y=gRandom2->Uniform(-1,1);
          double r=sqrt(x*x+y*y);  
          if(r<1.0) {ftot++;}
        }

       cout<<4*float(ftot)/float(n)<<endl;

}
