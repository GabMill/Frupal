#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player{
    int max;
    int x;
    int y;
    int energy;
    int whiffles;

    int tool[11];
};

/**********************************
  * Input: none -> txt needs to be ready
  * Output: struct player
  * Description: read in line from a designated txt file -> save it into struct and return it
**********************************/

struct player load();


/**********************************
  * Input: struct player hero
  * Output: updated txt file
  * Description: write out the current player struct's data into a txt file
**********************************/

void save(struct player hero);
