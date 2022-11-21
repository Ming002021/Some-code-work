#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int hours, minutes, breakH, breakM;
    char ampm;
    cout<<"Input the current time as hours minutes and A (am) or P(pm) : ";
    cin>>hours>>minutes>>ampm;
    
    cout<<"Input the break time as hours minutes ";
    cin>>breakH>>breakM;
     
    
    minutes=minutes+breakM;
    hours=hours+breakH+ floor(minutes/60);
    minutes=minutes%60;
    
    int a;
    a=floor(hours/12);
    
    
    if (ampm=='A')
   {
	   
	   
	   if( (a%2) ==0)
	   {
		  
		  if(hours%24==0)
		 {
			 
		  cout<<"Break is done at  "<< "12"<<":"<<minutes<<"AM"<<endl;
	     }
	     else
	     {
			 cout<<"Break is done at  "<<hours%12<<":"<<minutes<<"AM"<<endl;
	     }
			 
		}
	   else
	   {
		   
		     
		   cout<<"Break is done at  "<< hours%12<<":"<<minutes<<"PM"<<endl;
	   }
		   
    }
    
    else
    {
		 
		 if( (a%2) ==0)
	   {
		  
		  if(hours%12==0)
		 {
			 
		  cout<<"Break is done at  "<< "12"<<":"<<minutes<<"AM"<<endl;
	     }
	     else
	     {
		 
		  cout<<"Break is done at  "<< hours%12<<":"<<minutes<<"PM"<<endl;
		 }
	   }
	   else
	   {
		   cout<<"Break is done at  "<< hours%12<<":"<<minutes<<"AM"<<endl;
	   }
		
     }
  
  return 0;
}
