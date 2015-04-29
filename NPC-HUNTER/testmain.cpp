#include <iostream>
#include <fstream>
#indlude "NPC-Hunter.h"

using namespace std;

int main()
{
    NPC-Hunter N;
    N.addLocation( A);
    N.addLocation( B);
    N.addLocation( C);
    N.addLocation( D);
    N.addPath(A,B,2);
    N.addPath(A,C,3);
    N.addPath(A,D,4);
    N.addPath(B,C,5);
    N.addPath(B,D,3);
    N.addPath(C,D,5);

    string a = "a"
    for(int i = 0; i<N.locations.size();i++)
    {

        addNPC(a,N.locations[i]);
        a++;

    }
    N.running=true;
    while(N.running)
    {
        N.displayUserMenu();
    }

    return 0;
}


