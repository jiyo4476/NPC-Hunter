#ifndef NPC-HUNTER_H
#define NPC-HUNTER_H


class NPC-Hunter
{
    public:
        NPC-Hunter(); //init
        virtual ~NPC-Hunter(); //destruct
        void addLocation(string name); //add vertex
        void addPath(string name1, string name2, int pathdist) //add edge
        void displayAvailablePaths(); //show paths from player current vertex
        void movePlayer() //moves player along a chosen path from current vertex
        void displayNearbyNPCS(); //displays NPCs sharing vertex with Player after each move
        void displayUserMenu(); //displays options available to player. (quit, move, check nearby npcs, check path lengths)
        void displayPathLengths(); //displays available path lengths
        void moveNPC(); // when player move is called NPC wait time goes to zero and they move, gaining a new wait time depending on the length of the path.
        void buildMap(string fliename);//constructs map
        bool running;
    protected:
    private:
        vector<location> locations;
};

struct location{ //my version of a vertex
    string name; //location name
    vector<adjLocation> adj; //locations to be connected to this location
    vector<marker> atLocation;//NPCs and users at this location
};
struct marker{ //Struct for NPCs and User
    string name; //have a name
    int waitTimer;// and a wait timer which gets "filled up" when the marker travels a certain distance.
};

struct adjLocation{
    location *l;
    int distance;
    };
#endif // NPC-HUNTER_H
