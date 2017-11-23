/* ***********************
/  Fruple Program
/  Team G - Millen Wan
/  Save state functions
  ************************/
#include "Save.h"

// params: size = map dimension, xCoord/yCoord = current player coordinates
// 	energy = current player energy, whiffles = current player whiffles
// return 0 if successful
int savePlayer(int size, int xCoord, int yCoord, int energy, int whiffles)
{
	// file variables
	char * USER = "Save_Player_TeamG.txt";
	FILE * fileUser = fopen(USER,"w");
	// check if file can be opened
	if(fileUser == NULL)
	{
		printf("Error opening %s\n", USER);
		return 1;
	}
	// write player data to file
	fprintf(fileUser, "%d\n%d\n%d\n", size, xCoord, yCoord);
	fprintf(fileUser, "%d\n%d\n", energy, whiffles);
	
	return fclose(fileUser);
}

// params: bag = useful inventory array, length = size of inventory array
// return 0 if successful
int saveInventory(int * bag, int length)
{
	// file variables
	char * BAG = "Save_Inventory_TeamG.txt";
	FILE * fileBag = fopen(BAG,"w");
	// check if file can be opened
	if(fileBag == NULL)
	{
		printf("Error opening %s\n", BAG);
		return 1;
	}
	// write items in inventory to file
	for(int i = 0; i < length; ++i)
	{
		fprintf(fileBag, "%d\n", bag[i]);
	}

	return fclose(fileBag);
}

// params: size = map dimension, cellData = block of map cell data from original file
// return 0 if successful
int saveMap(int size, char * cellData)
{
	// file variables
	char * MAP = "Save_MapCells_TeamG.txt";
	FILE * fileMap = fopen(MAP,"w");
	// check if file can be opened
	if(fileMap == NULL)
	{
		printf("Error opening %s\n", MAP);
		return 1;
	}
	// write cell data block to map save file
	fprintf(fileMap, "%d\n%s", size, cellData);
	
	return fclose(fileMap);
}

// update map file with new visible cells and used items
// params: size = map dimension, xC/yC, current player coordinates
// 	vision = (1/2) binocular toggle, mapCells = map data
// return 0 if successful
int updateMap(int size, int xC, int yC, int vision, struct map * mapCells)
{
	// file variables
	char * MAP = "Save_MapCells_TeamG.txt";
	FILE * fileMap = fopen(MAP,"w");
	// check if file can be opened
	if(fileMap == NULL)
	{
		printf("Error opening %s\n", MAP);
		return 1;
	}
	// write the map dimension to the save file
	fprintf(fileMap, "%d\n", size);
	// loop through map cells with nested for
	for(int i = 0; i < mapCells->dimensions; ++i)
	{
		for(int j = 0; j < mapCells->dimensions; ++j)
		{
			struct cell current = mapCells->cells[i][j];
			// update cell visibility if within vision
			if(i >= (xC-vision) && i <= (xC+vision) && j >= (yC-vision) && j <=(yC+vision))
			{
				current.isVisible = 1;
			}
			// print cell to file if not "blank" cell
			if(current.isVisible == 0 && current.terrain == 0 && strcmp(current.item,"None") == 0)
			{
				// ordinary cell
			}
			else
			{
				fprintf(fileMap, "%d,%d,%d,%d,%s\n", current.xCoord,current.yCoord,current.isVisible,current.terrain,current.item);
			}
		}
	}
	
	return fclose(fileMap);
}

// load save files with original map file
// return 0 on successful load of all save files
int loadSave()
{
	// hardcode mape file name
	FILE * fileMap = fopen("map.txt","r");
	int MAX = 31; 		// file line read length
	int COUNT = 11;		// inventory size & smaller input length
	char line[MAX];		// file read line
	char size[COUNT];	// map dimension
	int xC;			// current player coordinates
	int yC;
	char energy[COUNT];	// current player energy
	char whiffles[COUNT];	// current player whiffles
	int inventory[COUNT];	// current inventory count
	// initialize inventory
	for(int i = 0; i<COUNT; ++i)
	{
		inventory[i] = 0;
	}
	// use a strcat to hold the bottom half of original file to save as map file
	char cellInfo[MAX*sizeof(size)];	// buffer to hold all map cells information
	// check if file can be read
	if(fileMap == NULL)
	{
		printf("Error opening map file.");
		return 1;
	}
	// parse file assuming correct formatting followed - no error checking
	// savePlayer file
	fgets(line, MAX, fileMap); 		// Map file title
	fgets(size, COUNT, fileMap); 		// Map dimension
	fgets(line, MAX, fileMap); 		// Map file format break
	fgets(line, MAX, fileMap); 		// Player coordinates - split below
	xC = atoi(strtok(line, ","));
	yC = atoi(strtok(NULL, ","));
	fgets(energy, COUNT, fileMap);		// Player energy
	fgets(whiffles, COUNT, fileMap);	// Player whiffles
	// end savePlayer file
	// saveInventory file - hardcode switch statement using strcmp
	fgets(line, MAX, fileMap);
	while(strchr(line,'#') == NULL)
	{
		if(strcmp(line,"Hatchet\n") == 0)
		{
			++inventory[0];
		}
		else if(strcmp(line,"Axe\n") == 0)
		{
			++inventory[1];
		}
		else if(strcmp(line,"Chainsaw\n") == 0)
		{
			++inventory[2];
		}
		else if(strcmp(line,"Chisel\n") == 0)
		{
			++inventory[3];
		}
		else if(strcmp(line,"Sledge\n") == 0)
		{
			++inventory[4];
		}
		else if(strcmp(line,"Jackhammer\n") == 0)
		{
			++inventory[5];
		}
		else if(strcmp(line,"Machete\n") == 0)
		{
			++inventory[6];
		}
		else if(strcmp(line,"Shears\n") == 0)
		{
			++inventory[7];
		}
		else if(strcmp(line,"Binoculars\n") == 0)
		{
			++inventory[8];
		}
		else if(strcmp(line,"Pretty Rock\n") == 0)
		{
			++inventory[9];
		}
		else // group all unknown items
		{
			++inventory[10];
		}
		fgets(line, MAX, fileMap);	// grab next item or delimiter
	}
	// end saveInventory - line contains '#'
	// saveMap file
	fgets(cellInfo, MAX, fileMap); // hold first cell's properties
	while(fgets(line, MAX, fileMap))
	{
		strcat(cellInfo,line);
	}
	fclose(fileMap);
	// finish reading from original file
	// write to save files
	savePlayer(atoi(size),xC,yC,atoi(energy),atoi(whiffles));
	saveInventory(inventory,COUNT);
	saveMap(atoi(size),cellInfo);
	return 0;
}
