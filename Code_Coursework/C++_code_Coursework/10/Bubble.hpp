#ifndef BUBBLE_HPP
#define BUBBLE_HPP
#include "Circle.hpp"
#include <iostream>
using namespace std;

class Bubble:public Circle
{
	private:
	bool unpopped;
	
	public:
	Bubble();
	void hitBubble(int& numPoints);
	friend istream& operator >>(istream& in,Bubble& bubble);
	
	
	
};
#endif
