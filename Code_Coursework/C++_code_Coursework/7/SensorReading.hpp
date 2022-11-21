#ifndef SENSORREADING_HPP
#define SENSORREADING_HPP
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
 
class SensorReading
{
	public:
	
	SensorReading();
	SensorReading(int t,double pr,double wd,double ws);
	void getTime(int& hours, int& minutes,int& seconds) const;
	bool validate() const;
	void print() const;
	void adjustWindDirection(double change);
	void adjustTime(int change);
	void set(int t,double pr,double wd,double ws);
	void printCSV(ostream&  out) const;
	
	
	private:
	int time;
	double pressure;
	double windDirection;
	double windSpeed;

};

#endif
	
	
	

