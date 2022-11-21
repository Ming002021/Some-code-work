#ifndef EMOJI_HPP
#define EMOJI_HPP
#include "Circle.hpp"
#include <iostream>
using namespace std;


class Emoji:public Circle
{
	private:
	string mood;
	
	public:
	Emoji();
	void hitEmoji(int& numPoints);
    friend istream& operator >>(istream& in,Emoji& emoji);
	
	
	
	
	
};

#endif
