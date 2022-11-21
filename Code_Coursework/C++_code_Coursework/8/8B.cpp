#include "Point2d.hpp"
#include "Circle.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	
     
     Circle circle[1000];
     Point2d point;
     ifstream fin;
     string fileName;
	 cout<<"Input file name : ";
	 cin>>fileName;
	 fin.open(fileName.c_str());
	 if(fin.fail())
	 {
		 cout<<"ERROR: cannot open "<<endl;
		 exit(1);
	 }
     int number=1;
     int points=0;
     int newPoints=0;
     int index=0;
     int minpos=0;
      double min=pointDist(point,circle[0].getCenter());
      double distance=0.0;
       while(!fin.eof())
		 { 
			 fin>>circle[index];
			 index++;
		 }
			
      
     while(number<=3)
     {
		 cout<<"Round : "<<number<<endl;
		 cout<<"Points : "<<points<<endl;
		 cout<<"Where do you throw the dart (x,y): ";
		 cin>>point;
		min = -1;
		for(int i=0;i<index;i++)
		 {
		  if(circle[i].contains(point))
		     { 
			    distance=pointDist(point,circle[i].getCenter());
			    if(distance<min || min == -1)
			    {
			     min=distance;
			     minpos=i;
			    }
			
		   }
		   
		}	
		 
		if(min!=-1)
		 {
		
		
		if(circle[minpos].getColor()=="Red")
		{
			newPoints=10;
		}
		else if(circle[minpos].getColor()=="Yellow")
		{
			newPoints=5;
		}
		else if(circle[minpos].getColor()=="Green")
		{
			newPoints=2;
		}
		else if(circle[minpos].getColor()=="Gray")
		{
			newPoints=-1;
		}
		
		 cout<<"Hit:"<<circle[minpos]<<endl;
		 for(int j=0;j<index;j++)
		 {
			 if(hasOverlap(circle[minpos],circle[j]))
			 {  
				 circle[j].setColor("Gray");
			 }
		 }
			
			 
			 
		
	 }
	   else
	 {
		 cout<<"Miss!"<<endl;
		 newPoints=0;
	 }
	 
	
		 points+=newPoints;
		 if(number==3)
		 {
		   cout<<"Out of darts!"<<endl;
		   cout<<"Points : "<<points<<endl;
		   
	     }
         number++;
	 }
	 
	 
	 
	 return 0;
 }
