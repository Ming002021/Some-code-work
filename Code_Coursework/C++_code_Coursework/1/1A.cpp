//CSCI1113(010)
//Homework1 A
//Mingming Xu



#include <iostream>
#include <cmath>
using namespace std;
int main()
{ 
	double r,g,b;
	double pi=M_PI;
	char options;
	cout<<"Input r,g,b:\n";
	cin>>r>>g>>b;
	cout<<"Options:"<<endl;
	cout<<"Enhance contrast(E)"<<endl;
	cout<<"Decrease contrast (D)"<<endl;
	cout<<"Enter E or D:"<<endl;
	cin>>options;
	if (options=='E')
	{ 
		r=(127.5)*(sin((r/255.0-0.5)*pi))+127.5;
		g=(127.5)*(sin((g/255.0-0.5)*pi))+127.5;
		b=(127.5)*(sin((b/255.0-0.5)*pi))+127.5;
		cout<<"("<<rint(r) <<", "<<rint(g)<<", " <<rint(b)<<")"<<endl;
	}
	else if (options=='D')
	{
		r=(255.0)*((asin((r-127.5)/127.5))/pi+0.5);
		g=(255.0)*((asin((g-127.5)/127.5))/pi+0.5);
		b=(255.0)*((asin((b-127.5)/127.5))/pi+0.5);
		cout<<"("<<rint(r) <<", "<<rint(g)<<", " <<rint(b)<<")"<<endl;
	}
	else
	{
		cout<<"Invalid option"<<endl;
	}
	
	return 0;
}
		
