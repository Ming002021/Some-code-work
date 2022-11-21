#include "Point2d.hpp"
#include "Circle.hpp"
#include "Targets.hpp"
#include "Bubble.hpp"
#include "Emoji.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	
     ifstream fin;
     string fileName;
	 cout<<"Enter target file : ";
	 cin>>fileName;
	 fin.open(fileName.c_str());
	 if(fin.fail())
	 {
		 cout<<"Cannot open "<<endl;
		 exit(1);
	 }
     int numTar=0;
     int numBub=0;
     int numEmo=0;
     string  type;
     fin>>numTar>>numBub>>numEmo;
     Target *t=new Target[1000];
     int tIndex=0;
     int bIndex=0;
     int eIndex=0;
     Bubble *b=new Bubble[1000];
     Emoji *e=new Emoji[1000];
     while(!fin.eof())
	{ 
		fin>>type;
		if(type=="target")
		{
			fin>>t[tIndex];
			tIndex++;
		}
		else if(type=="bubble")
		{
			fin>>b[bIndex];
			bIndex++;
		}
		else if(type=="emoji")
		{
			fin>>e[eIndex];
			eIndex++;
		}
					
    }
    Point2d point;
    int number=1;
    int numPoints=0;
    bool miss=1;
    while(number<=3)
   {
	   cout<<"Dart: "<<number<<endl;
	   cout<<"insert dart (x,y): ";
	   cin>>point;
	   
	   for(int i=0;i<tIndex;i++)
	   { if(t[i].contains(point))
		   {
			   t[i].hitTarget(numPoints);
			   miss=0;
		   }
	   }
	   
	   for(int i=0;i<bIndex;i++)
	   { if(b[i].contains(point))
		   {
			   b[i].hitBubble(numPoints);
			   miss=0;
		   }
	   }
	   
	   for(int i=0;i<eIndex;i++)
	   { if(e[i].contains(point))
		   {
			   e[i].hitEmoji(numPoints);
			   miss=0;
		   }
	   }
	   
	   if(miss==1)
	   {
		   cout<<"Miss!"<<endl;
	   }
	  
	   cout<<"Points: "<<numPoints<<endl;
	   if(number==3)
		 {
		   cout<<"Game Over!"<<endl;
		   
		  }
         number++; 
         miss=1;
    }
    
    
      
    
    
    
   fin.close();
   delete[] t;
   delete[] b;
   delete[] e;  
	 return 0;
 }
