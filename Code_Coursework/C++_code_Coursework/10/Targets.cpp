#include "Point2d.hpp"
#include "Circle.hpp"
#include "Targets.hpp"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


void   Target::hitTarget(int& numPoints)
{
	 
	if (getColor() == "Red")
	{
		 numPoints+=10;
		 cout<<"Hit: Red Target"<<endl;
	}
	else if (getColor() == "Yellow")
	{
		numPoints+=5;
		cout<<"Hit: Yellow Target"<<endl;
	}
	else if (getColor() == "Green")
	{
		numPoints+=2;
		cout<<"Hit: Green Target"<<endl;
	}
	 
	else
	{
		numPoints+=1;
		cout<<"Hit: "<<getColor()<<"Target"<<endl;
	}
}
