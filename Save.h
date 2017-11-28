/* ***********************
/  Fruple Program
/  Team G - Millen Wan
/  Save state function headers
  ************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// grab struct map and player
#include "Map.h"
#include "Player.h"

// save map cells to Save_MapCells_TeamG.txt
// params: size = map dimension, cellData = block of map cell data from original file
// return 0 if successful
int saveMap(int size, char * cellData);

// update map file with new visible cells and used items
// params: size = map dimension, xC/yC, current player coordinates
// 	vision = (1/2) binocular toggle, mapCells = map data
// return 0 if successful
int updateMap(int size, int xCoord, int yCoord, struct map * mapCells);

// load save files with original map file
// return 0 on successful load of all save files
int loadSave();
