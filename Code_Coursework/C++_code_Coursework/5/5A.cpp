//Csci1113
//Homework 5A
//Mingming Xu
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

double leftHeight( double heightsArray[],int index)
{
	 
	double max=heightsArray[0];
	
	if (index==0)
	{
		max=0.0;
	}
	else
	{
		for(int i=1;i<index;i++)
		{ 
			if( heightsArray[i]> max)
			{
				max=heightsArray[i];
			}
		}
	}
	return max;
}

double rightHeight(const double heightsArray[],int index)
{
	double max=0.0;
	if(index==9)
	{
		max=0.0;
	}
	
	else
	{
		for(int i=index;i<10;i++)
		{ 
			if( heightsArray[i]> max)
			{
				max=heightsArray[i];
			}
		}
	}
	
	return max;
}

double waterHeight (double heightsArray[],int index)
{
	double min;
    if((rightHeight(heightsArray,index))<(leftHeight (heightsArray,index)))
    min=rightHeight(heightsArray,index);
    else
    min=leftHeight (heightsArray,index);
    
    
    return min;
}

int main()
{
	double heightsArray[10];
	double heights;
	double AmoutWater=0.0;
	double sum=0.0;
	cout<<"Input 10 heights: ";
	for(int i=0;i<10;i++)
	{
		cin>>heights;
		if(heights<=0.0)
		{
			cout<<"Invalid heights!"<<endl;
			exit(1);
		}
		heightsArray[i]=heights;
	}
	
	cout<<endl;
	
	for(int i=0;i<10;i++)
	{
		double c=waterHeight(heightsArray,i);
		if (c<=heightsArray[i])
		AmoutWater=0.0;
		else
		{AmoutWater=c-heightsArray[i];
		}
		sum=sum+AmoutWater;
		
	}
	
	cout<<"Amount of Water : "<<sum<<endl;
	
	
	return 0;
}
		
	
	
	
    
    

	
