#include "include/NPCHunter.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

NPCHunter::NPCHunter()
{


}

NPCHunter::~NPCHunter()
{
    //dtor
}
/*NPCHunter::buildMap(string filename)//~~~~~~UNFINISHED
{
    ifstream instream; //make a instream variable for file io
    instream.open(filename);//open driver file
    string cities[5];// build array for known number of cities
    getline(instream, cities, ",");//read the first line of the file for all of the city names;
    for(int i=0;i<=5;i++) //add cities in with names from file
    {
        addLocation(cities[i]);
    }

}*/

void NPCHunter::addLocation(string name)
{

    for(int i=0;i<locations.size();i++) //steps through all locations
    {
        if(locations[i]->name == name) return; //if there already exists a location with the passed in name, method exits
    }
    location* l; //if not create new location l
    l->name=name;//with the name that was passed in
    locations.push_back(l); //and put it in the vector of all locations
}

void NPCHunter::addNPC(string name, location *city)
{
    marker* NPC= new marker;
    NPC->name=name;
    city->atLocation.push_back(NPC);
}

void NPCHunter::addPath(string name1, string name2, int pathdist)
{
    for(int i=0;i<locations.size();i++) // steps through locations
    {
        if(locations[i]->name==name1) //finds location with firs name. if this fails, the method exits.
        {


            for(int j=0;j<locations.size();j++) //steps through locations
                {
                    if(locations[j]->name==name2 && j != i) //finds location with second name. if this fails or if the passed in names are the same, method exits
                    {
                        adjLocation al; //creates first adj location
                        al.l==locations[j]; //sets it equal to the found location with name2
                        al.distance=pathdist; //gives it the appropriate distance;
                        locations[i]->adj.push_back(al); // puts the adjacent location into location with name1's vector of adjlocations
                        adjLocation al2; //creates second adj location
                        al2.l==locations[i]; //sets it equal to the found location with name1
                        al2.distance=pathdist;//gives it the appropriate distance
                        locations[j]->adj.push_back(al2);// puts the adjacent location into location with name2's vector of adjlocations
                    }
                }
        }

    }

}

void NPCHunter::displayAvailablePaths()
{
    for(int i=0; i<locations.size(); i++) //steps through all locations
    {
        for(int j=0; j< locations[i]->atLocation.size();j++) //steps through list of entities at each location
        {
            if(locations[i]->atLocation[j]->name == "User") // stops when it finds the user
            {
                cout<<"Paths available at "<<locations[i]->name<<" are:"<<endl; // prints out "Paths available at (location name) are:"
                for(int n=0; n<locations[i]->adj.size();n++) //steps through all of the adjacent locations for the location which the user is at;
                    {

                        cout<<locations[i]->adj[n].l->name<<endl; // prints out all of the adjacent locations for the location which the user is at;
                    }
                return; //exits after printing to save time;
            }
        }
    }

}

void NPCHunter::displayNearbyNPCS()
{

    for(int i=0; i<locations.size(); i++) //steps through all locations
    {
        for(int j=0; j< locations[i]->atLocation.size();j++) //steps through list of entities at each location
        {
            if(locations[i]->atLocation[j]->name == "User") // stops when it finds the user
            {
                cout<<"Entities at "<<locations[i]->name<<" are:"<<endl; // prints out "Entities at (location name) are:"
                for(int n=0; n<locations[i]->atLocation.size();n++) //steps through vector of markers for the location which the user is at;
                    {

                        cout<<locations[i]->atLocation[n]->name<<endl; // prints out all of the marker names the location which the user is at;
                    }
                return; //exits after printing to save time;
            }
        }
    }

}

void NPCHunter::displayPathLengths() //NOT FINISHED  Wondering if this should be absorbed by another method
{

    for(int i=0; i<locations.size(); i++) //steps through all locations
    {
        for(int j=0; j< locations[i]->atLocation.size();j++) //steps through list of entities at each location
        {
            if(locations[i]->atLocation[j]->name == "User") // stops when it finds the user
            {
                cout<<"Lengths of available paths from "<<locations[i]->name<<" are:"<<endl; // prints out "Paths available at (location name) are:"
                for(int n=0; n<locations[i]->adj.size();n++) //steps through all of the adjacent locations for the location which the user is at;
                    {

                        cout<<locations[i]->adj[n].distance<<endl; // prints out all of the adjacent locations for the location which the user is at;
                    }
                return; //exits after printing to save time;
            }
        }
    }

}

void NPCHunter::movePlayer() //take user input to decide where to go // figure out how to set wait timer and time loop for that matter;
{
    displayAvailablePaths();
    cout<<"Where would you like to go? (please enter location name as displayed)";
    string choice;
    cin>>choice;
    location* temp;
    for(int i=0;i<locations.size();i++)
    {
        if(locations[i]->name==choice) temp = locations[i];

    }
    int pathdist;
    if(temp!=NULL)
    {



        for(int i=0; i<locations.size();i++)
        {
            for(int j=0; j<locations[i]->atLocation.size();j++)
            {
                if(locations[i]->atLocation[j]->name=="User")
                {
                    locations[i]->atLocation.erase(locations[i]->atLocation.begin()+(j-1));
                }
            }
        }
        marker* user= new marker;
        user->name = "User";

        temp->atLocation.push_back(user);


        }
    }


/*for every City, each NPC moves to a randomly chosen city*/
void NPCHunter::moveNPC()// only works when cities are all connected.
{
    /* initialize random seed: */
    srand(time(0));
    for(int i=0;i<locations.size();i++){
        for(int j=0;j<locations[i]->atLocation.size();j++){
            if(locations[i]->atLocation[j]->name!="User"){
                marker* name = locations[i]->atLocation[j];
                locations[i]->atLocation.erase(locations[i]->atLocation.begin()+(j-1));
                int ran = rand()% locations.size();
                locations[ran]->atLocation.push_back(name);

            }
        }
    }
}

void NPCHunter::displayUserMenu()
{
   // displayNearbyNPCS();
    cout<<"What would you like to do next?"<<endl;
    cout<<"Options are: 1) to move, 2) to display available paths"<<endl<<"3) to quit"<<endl;
    int option;
    cin>>option;
    if(option==1)
        {
            movePlayer();
            moveNPC();
        }

    if(option==2) displayAvailablePaths();
    if(option==3) running=false;

    //moveNPC();

}
