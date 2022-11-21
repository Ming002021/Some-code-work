#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <iostream> 
#include "Point2d.hpp"
using namespace std;
class Circle
{
	private:
	Point2d center;
	double radius;
	string color;
	
	public:
	Point2d getCenter();
	double getRadius() ;
	string getColor() ;
	void setColor(string col)  ;
	bool contains(const Point2d& point);
	friend bool hasOverlap(Circle& circle1,Circle& circle2);
    friend ostream& operator <<(ostream& out,Circle circle);
	friend istream& operator >> (istream& in,Circle& circle);
	Circle();
	
};
#endif
	
