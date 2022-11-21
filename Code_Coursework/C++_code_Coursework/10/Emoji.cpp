#include "Point2d.hpp"
#include "Circle.hpp"
#include "Emoji.hpp"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

Emoji::Emoji() 
{
	radius=10;
	color="Yellow";
	mood="happy";
}

void Emoji::hitEmoji(int& numPoints)
{
	
	 
		 cout<<"Hit: "<<mood<<" emoji"<<endl;
		 if(mood=="happy")
		 {
		    mood="sad";
		    cout<<"Now it's sad "<<endl;
		 }
	
	     else if(mood=="sad")
	     {
			  mood="mad";
			  cout<<"Now it's mad "<<endl;
		 }
	     else if(mood=="mad")
	     {
	       cout<<"you should not have done that "<<endl;
	       numPoints-=1000;
	       mood="happy";
	       cout<<"Now it's happy "<<endl;
	     }
	  
}


istream& operator >>(istream& in,Emoji& emoji)
{
	in>>emoji.center;
	return in;
}
