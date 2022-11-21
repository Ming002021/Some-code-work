#include "Point2d.hpp"

#include "Circle.hpp"
#include <iostream>
#include <cmath>
#include <string>

 
	
Point2d Circle::getCenter()	 
{
	return center;
}
double Circle::getRadius()  
{
	return radius;
}
string Circle::getColor() 
{
	return color;
}
void Circle::setColor(string col)  
{
	color=col;
}

bool Circle:: contains( const Point2d&point)
{
	
	if (pointDist(point,center)<=radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool  hasOverlap(Circle& circle1,Circle& circle2)
{
	if(pointDist(circle1.center,circle2.center)<(circle1.radius+circle2.radius))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator <<(ostream& out,Circle circle)
{
	out<<"["<<circle.color<<" "<<"c=("<<circle.center<<" r="<<circle.radius<<"]."<<endl;
	return out;
}

istream& operator >> (istream& in,Circle& circle)
{
	in>>circle.center;
	
	in>>circle.radius;
	in>>circle.color;
	return in;
}

Circle::Circle()
{
	
}
