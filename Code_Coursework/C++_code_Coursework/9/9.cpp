#include "SensorReading.hpp"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	SensorReading *sensor=new SensorReading[1000];// sensor is for [readings.dat] index
	SensorReading *secSensor=new SensorReading[1000];// secSensor is the readings after romoving error   n
	SensorReading *thirdSensor=new SensorReading[1000];//thirdSensor is the  [readings.sanitized.dat]    k
	SensorReading *error=new SensorReading[1000];//[error.log]   m
	SensorReading *pressures=new SensorReading[1];//[pressure.delta.log]
	int index=0;
	int max=0;
	int m=0;
	int n=0;
	int k=0;
	double  maxPressure=0.0;
	double minPressure=0.0;
	int maxIndex=0;
	int minIndex=0;
	ifstream fin;
	ofstream  fout;
	fin.open("readings.dat");
	while (fin>>sensor[index])
	{
		
		 
		index++;
	}
     
	
	for(int i=0;i<index;i++)
	{
		if(sensor[i].validate())
		{
			
			secSensor[n]=sensor[i];
			n++;
		}
		
		
		else
		{
			
			error[m]=sensor[i];
			 m++;
	    }
		 
		
	}
			
	for(int j=0;j<n;j++)
	{
	    if(secSensor[j].getime()>=max)
		{
			max=secSensor[j].getime();
			thirdSensor[k]=secSensor[j];
			k++;
			
		}
	 }
	 
   
   maxPressure=thirdSensor[0].getPressure();
   for(int i=0;i<k;i++)	
   {
	   if(thirdSensor[i].getPressure()>=maxPressure)
	   {
		   maxPressure=thirdSensor[i].getPressure();
		   maxIndex=i;
	   }
	}
	
	
   minPressure=thirdSensor[maxIndex].getPressure();
	
	 
 
   for(int i=maxIndex;i<k;i++)
   {
	   if(thirdSensor[i].getPressure()<minPressure)
	   {
		   minPressure=thirdSensor[i].getPressure();
		   minIndex=i;
	   }
   }
   
  
  int maxTime=thirdSensor[maxIndex].getime();
  int timeDif=thirdSensor[minIndex].getime()-thirdSensor[maxIndex].getime();
  pressures[0].set(maxTime,timeDif,maxPressure,minPressure);
  cout<<"[readings.dat]"<<endl;	
for(int i=0;i<index;i++)
{
	cout<<sensor[i]<<endl;
}

	
		
  
  fout.open("error.log");
   
   
	 for(int i=0;i<m;i++)
    {
	fout<<error[i]<<endl;
     }
     cout<<"[error.log]"<<endl;
for(int i=0;i<m;i++)
{
	cout<<error[i]<<endl;
}
 
     
     
     
     fout.close();

 
 fout.open("readings.sanitized.dat");
  
  
	for(int i=0;i<k;i++)
{
	fout<<thirdSensor[i]<<endl;
}	 
	cout<<"[readings.sanitized.dat]"<<endl;
 for(int i=0;i<k;i++)
{
	cout<<thirdSensor[i]<<endl;
}	
		
     fout.close();
 
fout.open("pressure.delta.log");
	  
  
	 
	fout<<pressures[0]<<endl;
	cout<<"[pressure.delta.log]"<<endl;
    cout<<pressures[0]<<endl;
		
     fout.close();
        
 




		

			
fin.close();
delete[]  sensor;
delete[]  secSensor;
delete[] thirdSensor;
delete[]  error;
delete[] pressures;


return 0;
	
		
	}	 
		
		
		
		
		
		
		
		
