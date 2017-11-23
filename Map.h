#ifndef _MAP
#define _MAP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell {
    int xCoord, yCoord;
    char terrain;
    char item[14];
    int isVisible;
};

//creates a cell, constructor essentially, but because C doesn't have constructors, i need to define it outside of the struct
struct cell makeCell(int x, int y, int visibility, int land, const char* inItem);

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

//main parsing routine to load in a map
struct map makeMap(char* filename);

#endif 
