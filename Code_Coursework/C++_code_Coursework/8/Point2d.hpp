#ifndef POINT2D_HPP
#define POINT2D_HPP
#include <iostream> 
using namespace std;

class Point2d
{
	public:
    friend istream& operator >> (istream& in,Point2d& p);
    friend ostream& operator <<(ostream& out,Point2d p);
    friend double  pointDist(const Point2d& point1, const Point2d& point2);
    double getX();
    double getY();
    Point2d();
    
    private:
	double x;
	double y;
};
  
#endif
