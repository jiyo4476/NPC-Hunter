#include <iostream>
//#include <fstream>
#include "include/NPCHunter.h"
#include <stdlib.h>

using namespace std;

int main()
{
    //cout<<"1/n";
    srand(5);
    static NPCHunter N;
    N.addLocation( "A");
    //cout<<"1/n";
    N.addLocation( "B");
    N.addLocation( "C");
    N.addLocation( "D");
    N.addPath("A","B",2);
    N.addPath("A","C",3);
    N.addPath("A","D",4);
    N.addPath("B","C",5);
    N.addPath("B","D",3);
    N.addPath("C","D",5);

    //string a = "A";
    int randm=rand()%N.locations.size();
    for(int i = 0; i<N.locations.size();i++)
    {
        if(i==0)
        N.addNPC("a",N.locations[(i*randm)%N.locations.size()]);
        if(i==1)
        N.addNPC("b",N.locations[(i*randm)%N.locations.size()]);
        if(i==2)
            N.addNPC("c",N.locations[(i*randm)%N.locations.size()]);
        if(i==3)
            N.addNPC("d",N.locations[(i*randm)%N.locations.size()]);

    }

    cout<<"What is your name?"<<endl;
    cin>>N.playerName;
    N.target=N.selectTarget();
    cout<<"Your target is: "<<N.target<<endl;
    N.addPlayer();
    N.running=true;
    while(N.running)
    {
        N.displayUserMenu();
    }

    return 0;
}


