//Csci1113
//Homework4 C
//Mingming Xu



#include <iostream>
#include <fstream>
using namespace std;
void print_results(string team1, string team2, int win1, int win2);

int main() 
{
 ifstream fin ;  
 string team1, team2, inTeam1, inTeam2;
 int season_no, score1, score2;
 int win1 = 0,win2 = 0;
 fin.open("sports.dat") ;
  
    cout<<" Please input the two teams you are interested in: ";
      cin>>inTeam1>>inTeam2;
     while(!fin.eof())
    {
       fin>>season_no>>team1>>team2>>score1>>score2;  
        if((team1==inTeam1) && (team2==inTeam2))
       { 
		    if(score1 > score2)
             win1++;
           else
            win2++;
       }
      else if((team1==inTeam2) && (team2==inTeam1))
     {
        if(score1 > score2)
        win2++;
      else
    win1++;
     }
    }
 fin.close();  
 print_results(inTeam1,inTeam2,win1,win2);
   
    return 0;

}

 

void print_results(string team1, string team2, int team1_wins, int team2_wins)

{ 
	cout<<" The "<<team1<<" and "<<team2<<" played "<<(team1_wins+team2_wins)<<" times."<<endl;
    cout<<" The "<<team1<<" won "<<team1_wins<<" times."<<endl;
    cout<<" The "<<team2<<" won "<<team2_wins<<" times."<<endl;
    if(team1_wins > team2_wins)
    cout<<" The "<<team1<<" are the better team ! "<<endl;
    else if(team1_wins < team2_wins)
    cout<<" The "<<team2<<" are the better team ! "<<endl;
   else
    cout<<" The teams are equally matched ! "<<endl;

}

