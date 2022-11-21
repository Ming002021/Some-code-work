#include "Point2d.hpp"
#include "Circle.hpp"
#include "Bubble.hpp"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


Bubble::Bubble() 
{
	setColor("Blue");
	unpopped=1;
}

void Bubble::hitBubble(int& numPoints)
{
	if(unpopped)
	{
		cout<<"Pop!"<<endl;
		numPoints+=20;
		 
		unpopped=0;
	}
	
	else if(!unpopped)
	{
		cout<<"Plunk!"<<endl;
		 
	}

}
	
istream& operator >>(istream& in,Bubble& bubble)
{
	in>>bubble.center>>bubble.radius;
	return in;
}
