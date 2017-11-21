#include "diamond_finder.h"

/*
returns a 1 if on the diamond, 0 if not
input from the movement.c file, hopefully
x = x value of the player
y = y value of the player
*/
int onDiamond(int x, int y, struct map inMap)
{
	if(inMap.loaded == 0) return 0; //bad map, fail
	if(x == inMap.rdX && y == inMap.rdY) return 1; //return a success if the x and y variables match with the Diamonds 
	return 0; //auto return a failure state if they do not match.
}
