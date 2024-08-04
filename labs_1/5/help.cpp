//b1
// #define p0 0.0401

// #define sig1 0.0001
// #define sig2 0.00001

//b2
// #define p0 0.207

// #define sig1 0.001
// #define sig2 0.0001

//c1
// #define p0 1.05

// #define sig1 0.1
// #define sig2 0.01


//c3
#define p0 -1.03

#define sig1 0.1
#define sig2 0.01



std::default_random_engine generator1;
std::default_random_engine generator2;
std::normal_distribution<double> distribution1(0,sig1);
std::normal_distribution<double> distribution2(p0,sig2);

double gaussian(double x, double mu=0, double sig=1)
{
    return 1/sqrt(2*M_PI*sig*sig)*exp(-1*(x-mu)*(x-mu)/2/sig/sig);
}

void help() {
    double b1 = p0;
    vector<double> T = {};
    ifstream file("data.txt");
    double l1,l2,l3;
    T.clear();
    while(!file.eof()) {
        file>>l1>>l2>>l3;
        T.push_back(l1);
    }
    ofstream output("result.txt");

    TCanvas* canv = new TCanvas("c","");
    TGraph* g = new TGraph();
//b1

    // for(int i=T.size(); i>=0; i--) {
    //     if(T[i]<187){b1+=distribution1(generator1);}
    //     else{b1=distribution2(generator2);}
    //     g->AddPoint(T[i-1],b1);
    // }
    // g->GetYaxis()->SetTitle("b_{1}");
//b2
    // for(int i=T.size(); i>=0; i--) {
    //     if(T[i]<137){b1-=4.5*distribution1(generator1);}
    //     else{b1=distribution2(generator2);}
    //     g->AddPoint(T[i-1],b1);
    // }
    // g->GetYaxis()->SetTitle("b_{2}");
//c1
    // for(int i=T.size(); i>=0; i--) {
    //     if(T[i]<20){b1+=distribution1(generator1);}
    //     else{b1=distribution2(generator2);}
    //     g->AddPoint(T[i-1],b1);
    // }
    // g->GetYaxis()->SetTitle("c_{1}");
//c3
    // for(int i=T.size(); i>=0; i--) {
    //     if(T[i]<45){b1-=distribution1(generator1);}

    //     else{b1=distribution2(generator2);}
    //     g->AddPoint(T[i-1],b1);
    // }
    // g->GetYaxis()->SetTitle("c_{3}");
    g->GetXaxis()->SetTitle("t");
    g->SetLineColor(kRed);
    g->SetLineWidth(2);
    g->SetMarkerStyle(20);
    g->SetMarkerSize(0.1);
    g->Draw();
} 
