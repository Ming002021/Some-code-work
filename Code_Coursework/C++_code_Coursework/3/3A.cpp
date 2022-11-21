//CSci1113
// Homework 3A
//Mingming Xu

#include <iostream>
using namespace std;
string shift_encrypt(string mess, int rota)
{
   string result = "";
   rota = rota%26;
  for (int i=0;i<mess.length();i++)
   { 
	   mess.at(i)= toupper(mess.at(i));
      if( !isalpha(mess.at(i)) )
      continue;
      else if(isupper (mess.at(i)))
      { result+=char(int (mess.at(i)+rota-65)%26+65);
      }
	 else
	{  result+=char(int (mess.at(i)+rota-97)%26+97);
	}
	 
		}	
	return result;		
 }
   
   string shift_decrypt(string mess, int rota)
	{
		string result="";
		rota=rota%26;
		for (int i=0;i<mess.length();i++) 
		{
			mess.at(i)=tolower(mess.at(i));
			if ( !isalpha(mess.at(i)))
			 
		    continue;
		     
			else if( isupper (mess.at(i)))
			{ result+=char(int (mess.at(i)-rota-65)%26+65);
			}
			else
			{  int a=mess.at(i)-rota-97;
			   int b=(26+(a%26))%26;
			   result=toupper (char(b+97));
			}
			
		 }	
		 
		return result;	
			
      }





int main()
{
	int rotate;
	char mode;
	string message;
	cout<<"Encrypt(e/E) or Decrypt (d/D)?\n";
	cin>>mode;
	cout<<"What is the cipher rotation value ?\n";
	cin>>rotate;
	cout<<"What is the message?\n";
	cin.ignore();
	getline(cin,message);
	string str;
	if(rotate<0||rotate>25)
	{
		cout<<"INVALID MODE... TERMINATING"<<endl;
		exit(1);
	}
	
	else
	{
		if (mode=='e'||mode=='E')
		{ 
	      str= shift_encrypt(message,rotate);
		}
		else
		{
			str= shift_decrypt(message,rotate);
		}
	}
	cout<<"Translated Message: "<<str<<endl;
	return 0;
}


	




	
