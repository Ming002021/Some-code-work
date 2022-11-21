//Csci1113
//Homework 5B
//Mingming Xu
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

double computeDiff ( double newTemp [][10],double oldTemp [][10],int rows, int cols)
{
	double quantity;
	double sum=0.0;
	for(int i=0;i<=rows-1;i++)
	{
		 for(int j=0;j<=cols-1;j++)
		{
			sum += pow((newTemp[i][j]-oldTemp[i][j]),2);
			 
		}
			
	 
}
	
	 
	quantity=sqrt(sum);
	
	return quantity;
}


int main()
{ 
	
	
	double newTemp[10][10];
	double oldTemp[10][10];
	ifstream fin;
	string fileName;
	double tolerance;
	double quantity;
	cout<<"Input the data file name :";
	cin>>fileName;
	fin.open(fileName.c_str());
	if(fin.fail())
	{
		cout<<"Cannot open file ";
		exit(1);
	}
	cout<<"Input the tolerance : ";
	cin>>tolerance;
	if(tolerance<=0)
	{
		cout<<"Tolerance must be positive ";
		exit(1);
	}
	
	int rows,colus;
	fin>>rows>>colus;
	 
	while(!fin.eof())
	{
		
		for(int i=0;i<=rows-1;i++)
		{
			for(int j=0;j<=colus-1;j++)
		{
			fin>>newTemp[i][j];
		}
	  }
  }
	
	
	
	
	   do
	   {
		for(int i=0;i<=rows-1;i++)
		for(int j=0;j<=colus-1;j++)
		{
			oldTemp[i][j]=newTemp[i][j];
		}
		
		
		for(int i=1;i<=rows-2;i++)
		for(int j=1;j<=colus-2;j++)
		{
		 newTemp[i][j]=(oldTemp[i-1][j]+oldTemp[i+1][j]+oldTemp[i][j-1]+oldTemp[i][j+1])/4;
	    }
	      quantity=computeDiff (newTemp, oldTemp,rows,colus );
  
	     }while(quantity>=tolerance);  
	     
	     
	     for(int i=0;i<=rows-1;i++)
		 {
			 for(int j=0;j<=colus-1;j++)
		{
			
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			
			cout<<setprecision(3)<<newTemp[i][j]<<"  ";
		}
		cout<<endl;
	   }
		
	      fin.close();
	      return 0;
	  } 	
	    
	
	
