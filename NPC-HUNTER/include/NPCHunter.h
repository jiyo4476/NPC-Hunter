#ifndef NPCHUNTER_H
#define NPCHUNTER_H
#include <string>
#include <vector>
using namespace std;

struct marker{ //Struct for NPCs and User
    string name; //have a name
    int waitTimer;// and a wait timer which gets "filled up" when the marker travels a certain distance.
};
struct adjLocation;
struct location{ //my version of a vertex
    string name; //location name
    vector<adjLocation> adj; //locations to be connected to this location
    vector<marker*> atLocation;//NPCs and users at this location
};

struct adjLocation{
    location *l;
    int distance;
    };

class NPCHunter
{
    public:

        NPCHunter(); //init
        virtual ~NPCHunter(); //destruct
        void addLocation(string name); //add vertex
        void addPath(string name1, string name2, int pathdist); //add edge
        void addNPC(string name, location* city);
        void displayAvailablePaths(); //show paths from player current vertex
        void movePlayer(); //moves player along a chosen path from current vertex
        void displayNearbyNPCS(); //displays NPCs sharing vertex with Player after each move
        void displayUserMenu(); //displays options available to player. (quit, move, check nearby npcs, check path lengths)
        void displayPathLengths(); //displays available path lengths
        void moveNPC(); // when player move is called NPC wait time goes to zero and they move, gaining a new wait time depending on the length of the path.
      //  void buildMap(string fliename);//constructs map
        bool running;
        vector<location*> locations;

    protected:
    private:
};



#endif // NPCHunter_H
