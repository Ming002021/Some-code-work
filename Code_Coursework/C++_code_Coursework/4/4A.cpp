//Csci 1113
//Homework4 B
//Mingming Xu


#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double arctanApprox(double x,double tol)
{
	double result=0.0;
    double a=0.0;
	double b=x;
	for(int i=2;i>=2;i++)
	{   
		
		
		a=b;
		b=a+pow(-1,(i-1))*(pow(x,(2*i-1))/(2*i-1));
         
         if(abs(b-a)<=tol)
         {
			 result=b;
			 break;
		 }
	}
     return result;
 }
 
 int main()
 {
	 double tol;
     double pi;
     char again;
    do
    {
    
    
     do
	{ 
		cout<<"Input tolerance: ";
	     cin>>tol;
	     if(tol<=0)
	     {
			 cout<<"Tolerance must be positive.  ";
		 }
	 }while(tol<=0);
	 
	 cout.setf(ios::fixed);
	 cout.setf(ios::showpoint);
	 cout.precision(13);
	
	
	 pi= 16*arctanApprox(1.0/5.0,tol)-4* arctanApprox(1.0/239.0,tol);
	 cout<<"Pi approximation : "<<pi<<endl;
	 cout<<"Do you wish to approximate pi again ?";
	 cin>>again;
 }while(again=='Y'||again=='y');
 
 return 0;
}
	 
	 
	 
	 
	 
	 
	 
	 
	 
	     
         

