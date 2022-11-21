#include "SensorReading.hpp"

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

SensorReading::SensorReading()
{
	time=0;
	pressure=0.0;
	windDirection=0.0;
	windSpeed=0.0;
}

SensorReading::SensorReading(int t,double pr,double wd,double ws)
{
	time=t;
	pressure=pr;
	windDirection=wd;
	windSpeed=ws;
}

void  SensorReading::getTime(int& hours, int& minutes,int& seconds) const
{
	hours=time/3600;
	minutes=(time-hours*3600)/60;
	seconds=time-hours*3600-minutes*60;
}

bool  SensorReading::validate() const
{
	if ((time>=0)&&(time<86400)&&(pressure>=0)&&(windDirection>=0.0)&&(windDirection<360.0)&&(windSpeed>=0.0))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void SensorReading::print() const
{
	if((time>=0)&&(time<86400))
	{
	  int hours, minutes, seconds;
      getTime(hours, minutes, seconds);
      cout << "Time:  " << hours<<":";
      if (minutes <= 9) 
      {
        cout << "0" << minutes<<":";
       }
      else 
      { 
		  cout <<minutes<<":";
       }
     if (seconds <= 9) 
     {
       cout << "0" << seconds;
     }
    else 
    {
        cout <<seconds;
     }
     cout << endl;
       }
 
    else
    {
		cout<<"Out of Range"<<endl;
	}
	if (pressure>=0)
	{
	cout<<"Pressure: "<<pressure<<"Pa"<<endl;
    }
     else
    {
		cout<<"Out of Range"<<endl;
	}
	
	if((windDirection>=0.0)&&(windDirection<360.0))
	{
		cout<<"Direction: "<<windDirection<<"Degrees"<<endl;
	}
	else
    {
		cout<<"Out of Range"<<endl;
	}
	if((windSpeed>=0.0))
	{
	cout<<"Speed: "<<windSpeed<<"m/s"<<endl;
    }
   else
    {
		cout<<"Out of Range"<<endl;
	}
}
void SensorReading::adjustWindDirection(double change)
{
	windDirection=windDirection+change;
	windDirection=windDirection-(int)(windDirection/360.0)*360.0;
	if(windDirection<0.0)
	{
		windDirection=windDirection+360;
	}
}

void SensorReading:: adjustTime(int change)
{
	time=time+change;
}

void SensorReading::set(int t,double pr,double wd,double ws)
{
	time=t;
	pressure=pr;
	windDirection=wd;
	windSpeed=ws;
}

void SensorReading::printCSV(ostream& out) const
{
	out<<time<<","<<pressure<<","<<windDirection<<","<<windSpeed<<endl;
}


