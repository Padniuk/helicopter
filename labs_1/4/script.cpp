#define alpha 0.3
#define beta 0.9
#define b1 0.04
#define b2 0.2
#define c1 1
#define c3 -1
#define sigmaX 0.04
#define sigmaY 0.17
#define epsilon 0.05
#define N0 1

#include <iostream>
#include <cmath> 
#include <vector>
#include <random>
#include <fstream>


std::default_random_engine generator;
std::normal_distribution<double> distribution(0,1.0);

double Dx = sigmaX*sigmaX;
double x0 =  sigmaX;
double dx0 = 0;
double b = sqrt(alpha*alpha+beta*beta);
double dt = 0.025;

double Y0 =  sigmaY;
double dY0 = 0;
vector<double> T = {};
vector<double> X1 = {};
vector<double> X2 = {};
vector<double> Y1 = {};
vector<double> Y2 = {};
vector<double> n = {};

double gaussian(double x, double mu=0, double sig=1)
{
    return 1/sqrt(2*M_PI*sig*sig)*exp(-1*(x-mu)*(x-mu)/2/sig/sig);
}

double mean(vector<double> A) 
{
    if(A.size() != 0)
    {
        double mean=0;
        for (double a : A)
        {
            mean+=a;
        }
        return mean=mean/A.size();
    }
    else
    {
        return 0;
    }
}

double stdDev(vector<double> A)
{
    if(A.size() != 0)
    {
        double stdDev=0;
        double m = mean(A);
        for (double a : A)
        {
            stdDev+=(a-m)*(a-m);
        }
        return sqrt(stdDev/(A.size()-1));
    }
    else
    {
        return 0;
    }
}

void script() {      
    do
    {
        double t=0;
        T.clear();
        X1.clear();
        X2.clear();
        n.clear();
        n.push_back(gaussian(distribution(generator),0,1)*sqrt(N0/dt));
        T.push_back(0);
        X1.push_back(x0);
        X2.push_back(dx0-sqrt(2*Dx*alpha)*n.back());
        Y1.push_back(Y0);
        Y2.push_back(dY0);
        while(t<=300)
        {
            double X1prev = X1.back();
            double X2prev = X2.back();
            double ni = gaussian(distribution(generator),0,1)*sqrt(N0/dt);
            double Y1prev = Y1.back();
            double Y2prev = Y2.back();
            t+=dt;
            n.push_back(ni);
            T.push_back(t);
            X1.push_back(X1prev+(X2prev+sqrt(2*Dx*alpha)*ni)*dt);
            X2.push_back(X2prev+(sqrt(2*Dx*alpha)*(b-2*alpha)*ni-2*alpha*X2prev-b*b*X1prev)*dt);
            Y1.push_back(Y1prev+Y2prev*dt);
            Y2.push_back(Y2prev+(X1prev-b1*Y2prev-b2*fabs(Y2prev)*Y2prev-c1*Y1prev-c3*Y1prev*Y1prev*Y1prev)*dt);
        }
        dt*=0.95;
        if(fabs(sigmaX-stdDev(X1)/sigmaX)+fabs(sigmaY-stdDev(Y1)/sigmaY)<epsilon) break;
    }
    while(true);

    ofstream file("file.txt");
    for(int i=0; i<T.size(); i++)
    {
        file<<T[i]<<"   "<<Y1[i]<<" "<<Y2[i]<<endl;
    }
} 
