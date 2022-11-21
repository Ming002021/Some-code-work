#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>

#include "SensorReading.hpp"
using namespace std;
int main()
{ 

 SensorReading sensorReading[10];
 for(int i=0;i<10;i++)
 {   
	 sensorReading[i]=SensorReading();
 }
  ifstream fin;
  string inFile;
  cout<<"Input file : ";
  cin>>inFile;
  fin.open(inFile.c_str());
  if(fin.fail())
  {
	  cout<<"Unable to open file"<<endl;
	  exit(1);
  }
  int t=0;
  double pr=0.0;
  double wd=0.0;
  double ws=0.0;
  int j=0;
  while(!fin.eof())
  {
     fin>>t>>pr>>wd>>ws;
     sensorReading[j].set(t,pr,wd,ws);
     j++;
  }
  fin.close();
  ofstream fout;
  string outFile;
  cout<<"Output file : ";
  cin>>outFile;
  fout.open(outFile.c_str());
  if(fout.fail())
  {
	  cout<<"Unable to open file"<<endl;
	  exit(1);
  }
  
  int countNum=0;
  int count=0;
  
  for(int m=0;m<j;m++)
  {
	  sensorReading[m].adjustTime(-24);
	  if(sensorReading[m].validate())
	  {
		  sensorReading[m].printCSV(fout);
		  countNum++;
	  }
  
    else 
    {
		count++;
	}
  }
  
 
 
  cout<<"Number of invalid readings : "<<count<<endl;
  cout<<"Number of readings written to output file"<<countNum<<endl;
  
  return 0;
}
  
  
  
 
 
	 
  
