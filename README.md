# NPC-Hunter
DataStructures Final Project

Original Project "Plan":
Want to make a program that uses graphs to simulate a set of NPCs wandering from city to city in a list. Would have some sort of randomization so that they could potentially got to the same city twice in a row. Program exits when the user gives the command. Edges in the graph would have weights which translate to time that the 'NPC's would have to wait at that location. Goal is to hunt down one NPC from the list, randomly selected when the program is started. Can only see what NPC's are at the city you're at and "ask around" for who was there before you arrived. 

Installation: Download zip, unzip to any folder, open NPC-HUNTER.cbp to open up codeBlocks project. You may need to add some files into the project from the zip to get it to work. (Doesn't seem to remember all of the files all of the time.)

Libraries used : iostream, vector, String, stdlib.h

Current issues or mini projects to be worked on: 
  - Right now program is being built with set "data" in main, though it would be nice to read a file in to build from. 
  - Invalid user inputs crash the program, but I'm working on this. 
  - Another part of the original plan was to have some sort of time built in. Things that would affect time:
      > Player movement ( takes longer to traverse an edge with greater weight, would be implemented as a sort of cooldown)
      > Waiting (Player chooses how long to wait)

Contact: thfr5770@colorado.edu
