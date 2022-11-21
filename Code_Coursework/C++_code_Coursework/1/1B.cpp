//CSCI1113(010)
//Homework1 B
//Mingming Xu
#include <iostream>
#include <cmath>
using namespace std;
int main()
{ 
      double distance;
      int hours, minutes;
      double seconds;
      char disUnit;
      double a,b,c;
      cout<<"Is distance in kilometers (k) or miles(m)?"<<endl;
      cin>>disUnit;
      if (disUnit=='k')
      {
		  cout<<"Input distance:"<<endl;
		  cin>>distance;
		  cout<<"Input target time in hours,minutues and seconds."<<endl;
		  cout<<"Hours:"<<endl;
		  cin>>hours;
		  cout<<"Minutes:"<<endl;
		  cin>>minutes;
		  cout<<"Seconds:"<<endl;
		  cin>>seconds;
		  a=(hours*3600+minutes*60+seconds)/(distance*0.621371192)/3600;
		  b=((hours*3600+minutes*60+seconds)/(distance*0.621371192)-floor(a)*3600)/60;
		  c=(hours*3600+minutes*60+seconds)/(distance*0.621371192)-floor(a)*3600-floor(b)*60;
		  cout.setf(ios::fixed);
		  cout.setf(ios::showpoint);
		  cout.precision(2);
		  if(floor(a)>0&&floor(b)>0)
		  {
			  cout<<"The average time per mile is "<<floor(a)<<" hours "<<floor(b)<<" minutes "<<c<<" seconds"<<endl;
		  }
		   else if(floor(a)==0&&floor(b)>0)
		  {
			  cout<<"The average time per mile is "<<floor(b)<<" minutes "<<c<<" seconds"<<endl;
		  }
		  else 
		  {
			  cout<<"The average time per mile is "<<c<<" seconds"<<endl;
		  }
	  }
	  else if (disUnit=='m')
     {
	   cout<<"Input distance"<<endl;
	   cin>>distance;
	   cout<<"Input target time in hours,minutues and seconds."<<endl;
	   cout<<"Hours:"<<endl;
	   cin>>hours;
	   cout<<"Minutes:"<<endl;
	   cin>>minutes;
	   cout<<"Seconds:"<<endl;
	   cin>>seconds;
	   a=(hours*3600+minutes*60+seconds)/(distance)/3600;
	   b=((hours*3600+minutes*60+seconds)/(distance)-floor(a)*3600)/60;
	   c=(hours*3600+minutes*60+seconds)/(distance)-floor(a)*3600-floor(b)*60;
	   cout.setf(ios::fixed);
	   cout.setf(ios::showpoint);
	   cout.precision(2);
	   
		  if(floor(a)>0&&floor(b)>0)
		  {
			  cout<<"The average time per mile is "<<floor(a)<<" hours "<<floor(b)<<" minutes "<<c<<" seconds"<<endl;
		  }
		   else if(floor(a)==0&&floor(b)>0)
		  {
			  cout<<"The average time per mile is "<<floor(b)<<" minutes "<<c<<" seconds"<<endl;
		  }
		  else 
		  {
			  cout<<"The average time per mile is "<<c<<" seconds"<<endl;
		  }
	  }
	  
	  else
	  {
		  cout<<"Invalid distance option"<<endl;
	  }
	  
	  return 0;
  }			  
		  
		  
		  
		  
      
