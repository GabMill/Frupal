/* Author: Blaine Holbert
 * Purpose: Prototypes and initializes certain variables for implementation of loading a map into memory for FRUPAL
*/ 

#ifndef _MAP
#define _MAP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum items{ error = -1, none = 201, tree = 202, boulder = 203, bush = 204, powerBar = 205, treasure1 = 206,
	treasure2 = 207, royalDiamonds = 208, clue = 209, hatchet = 301, axe = 302, chainsaw = 303, 
	chisel = 304, sledge = 305, jackhammer = 306, machete = 307, shears = 308, binoculars = 309, boat = 310};

struct cell {
	int xCoord, yCoord;
	char terrain;
	int item;
	int isVisible;
};

//constructs a cell given the proper arguments, and returns an initialized cell struct
struct cell makeCell(int x, int y, int visibility, int land, int item);

//allows to clear the item from a cell for item removal
void clearCell(struct cell* inCell);

struct map {
	int dimensions;
	struct cell** cells;
	int rdX, rdY;
	int loaded;
};

//allocates memory for the map, then initializes all cells to be empty and invisible
void initializeMap(int size, struct map* inMap);

//VERY IMPORTANT!
//MUST BE CALLED TO PREVENT MEMORY LEAKS. DO NOT CALL MAKEMAP WITHOUT CALLING DEALLOCATE MAP BEFORE RETURNING IN MAIN.
//TECHNICALLY THE MEMORY IS FREED AFTER THE PROGRAM TERMINATES, BUT IT'S STILL BAD PRACTICE!
void deallocateMap(int size, struct map* inMap);


//debug function to validate all files end up in the right spot
void printMap(int size, struct map* inMap);


//main parsing routine to load in a map, accepts filename as argument, nothing else and returns a loaded map
struct map makeMap(char* filename);

#endif 
