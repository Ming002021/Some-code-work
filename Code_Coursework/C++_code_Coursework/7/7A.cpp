#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>

#include "SensorReading.hpp"
using namespace std;
int main()
{ 

 SensorReading sensorReading;
 sensorReading=SensorReading(6722,724.5,340.8,5.2);
  
 char option;
 
 
 while(1)
{
 cout<<"Valide (v),print(p),adjust time(t), adjust direction (d),or quit (q): "<<endl;
 cin>>option;
 if(option=='v')
 {
	 if(sensorReading.validate())
	 {
		 cout<<"Valid"<<endl;
	 }
	 else
	 {
		 cout<<"NOT valid "<<endl;
	 }
 }
 else if (option=='p')
 {
	 sensorReading.print();
 }
 
 else if(option=='t')
 {
	 int change;
     cout<<"Amount of change : ";
	 cin>>change;
     sensorReading.adjustTime(change);
 }

 else if (option=='d')
 {
	 double change;
	 cout<<"Amount of change : ";
	 cin>>change;
	 sensorReading.adjustWindDirection(change);
 }
 else if(option=='q')
 {
	 exit(1);
 }
 
 else
 {
	 cout<<"The character is not an option"<<endl;
 }
  
}

return 0;
 
}
