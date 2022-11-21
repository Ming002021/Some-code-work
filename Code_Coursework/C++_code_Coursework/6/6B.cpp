//Csci1113
//Homework 6B
//Mingming Xu

  

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

char  change (char letter)
{
	 if ((letter>='A')&&(letter<='Z'))
	{
	    letter=letter+32;
	    
	     return letter;
    }
    
    else
    {
		return letter;
	}
 }
 
 
string bigletter(string str1,string str2)
{
	 
	if((str1.at(0)>='A')&&(str1.at(0)<='Z')&&(str2.at(0)>='a')&&(str2.at(0)<='z'))
	{
	     
	     str2.at(0)=str2.at(0)-32 ;
	 }
	 
	 return str2;
 }
		
		

  int main()
{
   string punc=" .!?;,";
   string line;
   string word;
   string neword;
   
    
   ifstream fin;
   ofstream fout;
   fin.open("input.txt");
   if (fin.fail())
   {
	  cout<<"Uable to open file ";
		exit(1);
	}
	fout.open("output.txt");
	 if (fout.fail())
   {
	  cout<<"Uable to open file ";
		exit(1);
	}
	
	while(getline(fin,line))
	{
		
		 char finaletetr=line.at(line.length()-1);
		 
		 while(line.length()>=0)
		 {
			 
			  word=line.substr(0,line.find_first_of(punc,0)+1);
			  
   
			 line=line.substr(word.length(),line.length()-word.length());
			  
			 bool true1=(word.at(0)!='y')&&(word.at(0)!='a')&&(word.at(0)!='e')&&(word.at(0)!='i')&&(word.at(0)!='o')&&(word.at(0)!='u');
             bool true2=(word.at(0)=='y')||(word.at(0)=='a')||(word.at(0)=='e')||(word.at(0)=='i')||(word.at(0)=='o')||(word.at(0)=='u');
             bool true3=(word.at(1)=='y')||(word.at(1)=='a')||(word.at(1)=='e')||(word.at(1)=='i')||(word.at(1)=='o')||(word.at(1)=='u');
             bool true4=(word.at(1)!='y')&&(word.at(1)!='a')&&(word.at(1)!='e')&&(word.at(1)!='i')&&(word.at(1)!='o')&&(word.at(1)!='u');
	 
			 
			 if ((true1)&&(true3))
			 {   neword=word.substr(1,word.length()-2)+change(word.at(0))+"oi"+word.substr(word.length()-1,1);
				  
			 }
			 else if ((true1)&&(true4))
			 {
				  neword=word.substr(2,word.length()-3)+change(word.at(0))+word.at(1)+"ah"+word.substr(word.length()-1,1);
				  
			  }
			  else if(true2)
			  {
				  neword=word.substr(0,word.length()-1)+"eeh"+word.substr(word.length()-1,1);
			  }
			  bigletter(word,neword);
			  
			  //if(line.length()>0)
			  //{ 
			 
			        // else
			        //{  break;
			        //} This part, TA Yuyang helped me.
			 
			 
			  if(line.length()>0)
			  {
			  if(line.at(0)==' ')
			  {
				  line=line.substr(1,line.length()-1);
				  neword=neword+" ";
			  }
				}
				else
				{
				  break;}
				  
			  
		   fout<<neword;
		  }
		   
		fout<<finaletetr<<endl;
	  }
	  
	  fin.close();
	  fout.close();
	  
	  return 0;
  }
			  
			
			 
			
	
	
	
	
	
   
   
