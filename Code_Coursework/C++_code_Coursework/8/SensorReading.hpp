#ifndef SENSOR_READING_HPP
#define SENSOR_READING_HPP
// Sensor Reading Class Declaration
#include <iostream>
#include <fstream>
using namespace std;

class SensorReading
{
public:
  SensorReading();
  SensorReading(int t, double pr, double wd, double ws);
  void getTime(int& hours, int& minutes, int& seconds) const;
  void set(int t, double pr, double wd, double ws);
  bool validate() const;
  void print() const;
  void printCSV(ostream& out) const;
  void adjustWindDirection(double change);
  void adjustTime(int change);
  friend SensorReading operator +(SensorReading s1,SensorReading s2);
  friend bool  operator ==(SensorReading s1,SensorReading s2);
  friend istream& operator >> (istream& in,SensorReading& s);
  friend ostream& operator << (ostream& out,SensorReading s);
  
  
  
private: 
  int time;
  double pressure;
  double windDirection;
  double windSpeed;
};
#endif
