#include "Point2d.hpp"
#include <iostream>
#include <cmath>

Point2d::Point2d()
{
	
};

double Point2d::getX()
{
	return x;
}

double Point2d::getY()
{
	return y;
}

double pointDist(const Point2d& point1,const Point2d& point2)
{
	return (sqrt((point1.x-point2.x)*(point1.x-point2.x)+(point1.y-point2.y)*( point1.y-point2.y)));
}
istream& operator >> (istream& in,Point2d& p)
{
	in>>p.x;
	in>>p.y;
	return in;
}
ostream& operator <<(ostream& out,Point2d p)
{
	out<<"("<<p.x<<","<<p.y<<")"<<endl;
	return out;
}
