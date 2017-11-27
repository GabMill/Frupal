#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Map.h"
#include "Save.h"

/*********************************
  *Input: char input, int *fx, int *fy, struct player hero
  *Output: void but alters the int *fx and int *fy
  *Description: reads in the user's coords and alter it through user's direction input char
                save the result into fx and fy so user can access it outside the scope
*********************************/
void dir_move(char input, int *fx, int *fy, struct player hero);


/*********************************
  *Input: int x, int y, struct map q 
  *Output: void -> changes player's energy and moveability 
  *Description: reads in player's coord and see if that cell is a moveable cell
                if moveable -> player data will be renewed with the inputted x, y coords
                if not moveable -> player data will not be renewed with the inputted x, y coords 
*********************************/
void obs_check(int x, int y, struct map q);


/*********************************
  *Input: int x, int y, struct map q 
  *Output: void -> changes player's inventory data
  *Description: reads in player's coord and check with the map cell's item
                if pickable item -> pick and increment inventory
                if obstacle item -> check if tool exist in player inventory and use energy / whiffles accordingly
*********************************/
void item_check(int x, int y, struct map q);
