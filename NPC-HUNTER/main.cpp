#include <iostream>
#include <fstream>
#include "include/NPCHunter.h"

using namespace std;

int main()
{
    NPCHunter N;
    N.addLocation( "A");
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
    for(int i = 0; i<N.locations.size();i++)
    {
        if(i==0)
        N.addNPC("a",N.locations[i]);
        if(i==1)
        N.addNPC("b",N.locations[i]);
        if(i==2)
            N.addNPC("c",N.locations[i]);
        if(i==3)
            N.addNPC("d",N.locations[i]);

    }
    N.running=true;
    while(N.running)
    {
        N.displayUserMenu();
    }

    return 0;
}


