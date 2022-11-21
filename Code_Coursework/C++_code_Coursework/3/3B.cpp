//CSci1113
//Homework 3B
//Mingming Xu



#include <iostream>
using namespace std;
int main()
{
	int post,feet,sign;
	int count=0,ts=0;
	cout<<"How many posts do you want to see?\n";
	cin>>post;
	cout<<"How many feet between posts?\n";
	cin>>feet;
	cout<<"What is the minimum distance between signs (in feet)?\n";
	cin>>sign;
	for(int i=0;i<post;i++)
	{
		cout<<"|";
		for(int j=0;j<feet;j++)
		{
			if (i==post-1)
			break;
			else if(count>=sign&&j!=feet-1)
			{
				cout<<"S";
				count=0;
				ts++;
			}
			else
			{
				cout<<"-";
				count++;
			}
		}
	}
	
	
	cout<<endl;
	cout<<"Total signs: "<<ts;
	
	return 0;
}
