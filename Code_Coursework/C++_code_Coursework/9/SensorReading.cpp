// SensorReading implementation file
#include "SensorReading.hpp"
#include <iostream>
#include <cmath>

SensorReading::SensorReading():
  time(0), pressure(0.0), windDirection(0.0), windSpeed(0.0)
{}

SensorReading::SensorReading(int t, double pr, double wd, double ws):
  time(t), pressure(pr), windDirection(wd), windSpeed(ws)
{}

void SensorReading::getTime(int& hours, int& minutes, int& seconds) const
{
  hours = time/(60*60);
  minutes = (time - hours * 60 * 60)/ 60;
  seconds = time % 60;
}

void SensorReading::set(int t, double pr, double wd, double ws)
{
   time = t;
   pressure = pr;
   windDirection = wd;
   windSpeed = ws;
}

bool SensorReading::validate() const
{
  if (time >= 0 && time < 60*60*24 && pressure >= 0.0
      && windDirection >= 0.0 && windDirection < 360.0 
      && windSpeed >= 0.0)
     return true;
  else
     return false;
}

void SensorReading::print() const
{
  int hours, minutes, seconds;
  if (time < 0 || time >= 24*60*60)
    cout << "Out of range" << endl;
  else {
    getTime(hours, minutes, seconds);
    cout << "Time: " << hours << ":";
    if (minutes < 10)
       cout << "0";
    cout << minutes << ":";
    if (seconds < 10)
    cout << "0";
    cout << seconds << endl;
  }
  if (pressure < 0.0)
    cout << "Out of range" << endl;
  else
    cout << "Pressure: " << pressure << " Pa" << endl;
  if (windDirection < 0.0)
    cout << "Out of range" << endl;
  else
    cout << "Direction: " << windDirection << " Degrees" << endl;
  if (windSpeed < 0.0)
    cout << "Out of range" << endl;
  else
    cout << "Speed: " << windSpeed << " m/s" << endl;
}

void SensorReading::printCSV(ostream& out) const
{
  out << time << ",";
  out << pressure <<  ",";
  out << windDirection << ",";
  out << windSpeed << endl;
}

void SensorReading::adjustWindDirection(double change)
{
   windDirection += change;
   // Adjust to valid range if needed
   while (windDirection >= 360.0)
     windDirection -= 360.0;
   while (windDirection < 0.0)
     windDirection += 360.0;
 }

void SensorReading::adjustTime(int change) 
{
   time += change;
}

 SensorReading operator +(SensorReading s1,SensorReading s2)
 {
	 SensorReading temp;
	 temp.time=s1.time+s2.time;
	 temp.pressure=s1.pressure+s2.pressure;
	 temp.windDirection=s1.windDirection+s2.windDirection;
     temp.windSpeed=s1.windSpeed+s2.windSpeed;
     return temp;
 }
 
 bool  operator ==(SensorReading s1,SensorReading s2)
 {
	 
	   if((s1.time==s2.time)&&(s1.pressure==s2.pressure)&&(abs(s1.windDirection-s2.windDirection)<=0.1)&&(abs(s1.windSpeed-s2.windSpeed)<=0.1))
	   {
		   return true;
	   }
	   else
	   {
		   return false;
	   }
	 
 }

istream& operator >> (istream& in,SensorReading& s)
 {
	 in>>s.time;
	 in>>s.pressure;
	 in>>s.windDirection;
	 in>>s.windSpeed;
	 return in;
 }
 
 
 ostream& operator << (ostream& out,SensorReading s)
 {
	 out<<s.time<<" "<<s.pressure<<" "<<s.windDirection<<" "<<s.windSpeed<<endl;
	 
	 return out;
 }


int SensorReading::getime()
{
	return time;
}

double SensorReading::getPressure()
{
	return pressure;
}
