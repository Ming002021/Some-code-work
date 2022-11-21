//Csci 1113
//Homework 6A
//Mingming xU

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

int  findOverlap(string s1,string s2)
{
	int result=0;
	int len1=s1.length();
	int len2=s2.length();
	string news1;
	string news2; 
	if (len1==len2)
	{ 
		for(int i=0;i<len1;i++)
		{
			news1=s1.substr(i,len1-i);
			news2=s2.substr(0,len2-i);
			if (news1==news2)
			{
				result= news2.length();
				break;
			}
		}
	   
	}
		 
	else if (len1<len2)
	{ 
		for(int i=0;i<len1;i++)
		{
			news1=s1.substr(i,len1-i);
			news2=s2.substr(0,len1-i);
			if (news1==news2)
			{
				result=news2.length();
				break;
			}
		}
	  
   }
   else if (len1>len2)
   {
	   for (int i=0;i<len2;i++)
	   {
		   news1=s1.substr((len1-len2+i),len2-i);
		   news2=s2.substr(0,len2-i);
		   if (news1==news2)
			{
				result=news2.length();
				break;
			}
		}

        
   }
 
   return result;
   
}
	
int main()
{
	
   string filename;
   ifstream fin;
   string array[30];
   string str;
   int i=0;
   int max=0;
   int lap=0;
   int  a=0;
   
   cout<<"Input filename : ";
   cin>>filename;
   fin.open(filename.c_str());
   if(fin.fail())
	{
		cout<<"Uable to open file ";
		exit(1);
	}
	
    while(getline(fin,str))
   {
	    
		array[i]=str;
		i++;
   }
	 
	for(int m=0;m<i;m++)
	{
          a=m+1;
         for(int n=m+1;n<i;n++)
		{
			lap=findOverlap(array[m], array[n]);
			if (lap>max)
			{
				max=lap;
				a=n;
			}
		}
			// temp = array[ << value >> ]
          //array[ << value you're  checking>> ] = array[a]
          //array[a] = temp  // For this part, TA Carson helped me .
          
      string temp;
      temp= array[m+1];
      array[m+1]=array[a];
      array[a]=temp;
  }
  
	for(int index=0;index<i;index++)
	{
		cout<<array[index]<<endl;
	}
	fin.close();
	return 0;
}
	
	
	 
	 
	 
	 
	 
	 
	
	
	
	
	
	
	
	
	
	 
	
	
