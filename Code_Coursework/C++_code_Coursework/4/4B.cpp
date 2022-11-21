//Csci 1113
//Homework4 B
//Mingming Xu




#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double vectorLength(double u, double v, double w);

void vectorNormalize(double& u, double& v, double& w);

void interpolateVectors(double a, double u1, double v1, double w1, double u2, double v2, double w2, double& u, double& v, double &w);

 

int main()
{
double u1, v1, w1, u2, v2, w2, n;
cout<<"Enter the first vector u1 v1 w1: ";
cin>>u1>>v1>>w1;
if(u1==0.0 && v1==0.0 && w1==0.0)
{
   cout<<"Vectors must be non-zero.";
   exit(1);
}

cout<<"Enter the second vector u2 v2 w2: ";
cin>>u2>>v2>>w2;
if(u2==0.0 && v2==0.0 && w2==0.0)
{
   cout<<"Vectors must be non-zero.";
   exit(1);
}

vectorNormalize(u1,v1,w1);

vectorNormalize(u2,v2,w2);

cout<<"Enter the number of interpolate vectors to compute: ";
cin>>n;

double u,v,w, m= 1/(n-1), a=0.0;
while(a<=1.0)
{
interpolateVectors(a, u1, v1, w1, u2, v2, w2, u, v, w);

a+=m;

vectorNormalize(u,v,w);
 cout.setf(ios::fixed);
	    cout.setf(ios::showpoint);
	    cout.precision(4);
		cout<<u<<"  "<<v<<"  "<<w;
		cout<<endl;
}
return 0;
}


double vectorLength(double u, double v, double w)
{
   return sqrt(u*u+v*v+w*w);
}

void vectorNormalize(double& u, double& v, double& w)
{
double divide = vectorLength(u,v,w);
u = u/divide;
v = v/divide;
w = w/divide;
}

void interpolateVectors(double a, double u1, double v1, double w1, double u2, double v2, double w2, double& u, double& v, double &w)
{

u = (1-a)*u1 + a*u2;
v = (1-a)*v1 + a*v2;
w = (1-a)*w1 + a*w2;

}

