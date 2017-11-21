/* ***********************
/  Fruple Program
/  Team G - Millen Wan
/  Save state function headers
  ************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// grab struct map
#include "map.h"

// save player and inventory information to Save_Player_TeamG.txt
// params: size = map dimension, xCoord/yCoord = current player coordinates
// 	energy = current player energy, whiffles = current player whiffles
//	bag = useful inventory array, length = size of inventory array
// return 0 if successful
int savePlayer(int size, int xCoord, int yCoord, int energy, int whiffles,int * bag, int length);

// save map cells to Save_MapCells_TeamG.txt
// params: size = map dimension, cellData = block of map cell data from original file
// return 0 if successful
int saveMap(int size, char * cellData);

// update map file with new visible cells and used items
// params: size = map dimension, xC/yC, current player coordinates
// 	vision = (1/2) binocular toggle, mapCells = map data
// return 0 if successful
int updateMap(int size, int xCoord, int yCoord, int vision, struct map * mapCells);

// load save files with original map file
// return 0 on successful load of all save files
int loadSave();
