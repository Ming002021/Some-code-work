#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int tolerance;
	cout<<"Input tolerance : ";
	cin>>tolerance;
	while(tolerance<0)
	{
		cout<<"Tolerance must be nonnegative."<<endl;
		cout<<"Input tolerance : ";
	    cin>>tolerance;
	}
	
	int red, green, blue;
	cout<<"Input red,green,and blue components : ";
	cin>>red>>green>>blue;
	while((red>255)||(red<0)||(green>255)||(green<0)||(blue>255)||(blue<0))
	{
		cout<<"All components must be between 0 and 255, inclusive."<<endl;
	    cout<<"Input red,green,and blue components : ";
	    cin>>red>>green>>blue;
	}
	if (abs(red-green)<=tolerance&&abs(blue-green)<=tolerance&&abs(red-blue)<=tolerance)
	{
		cout<<"The color is a near gray.";
		string max;
		if(red>green)
		{
			if(red>blue)
			{
				max="The red component is largest .";
			}
			else if(red==blue)
			{
				max="The red and blue components are largest .";
			}
			else
			{
				max="The blue component is largest.";
			}
		}
		else if(red==green)
		{
			if(red>blue)
			{
				max="The red and green components are largest";
			}
			else if(red==blue)
			{
				max="All components are equal. ";
			}
			else
			{
				max="The blue component is largest ";
			}
		}
	    if(red<green)
		{
			if(green>blue)
			{
				max="The green component is largest .";
			}
			else if(green==blue)
			{
				max="The green and blue components are largest .";
			}
			else
			{
				max="The blue component is largest.";
			}
		}
	 cout<<max<<endl;
 }
	else
	{
		cout<<"The color is not a near gray."<<endl;
	}
	
	
	return 0;
}

		
