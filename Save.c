/* ***********************
/  Fruple Program
/  Team G - Millen Wan
/  Save state functions
  ************************/
#include "Save.h"

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

int updateMap(int size, int xC, int yC, struct map * mapCells)
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
			if(i >= (xC-1) && i <= (xC+1) && j >= (yC-1) && j <=(yC+1))
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

int resetMap()
{
	int MAX = 31; 		// file line read length
	int COUNT = 11;		// inventory size & smaller input length
	char line[MAX];		// file read line - reads map name before player info
	// Get map file name
	FILE * fileMapName = fopen("Map_Name.txt");
	fgets(line, MAX, fileMapName);	// grab map name
	fclose(fileMapName);
	// Open map file
	FILE * fileMap = fopen(line,"r");
	// check if file can be read
	if(fileMap == NULL)
	{
		printf("Error opening map file.");
		return 1;
	}
	struct player hero;
	// initialize hero.tool
	for(int i = 0; i<COUNT; ++i)
	{
		hero.tool[i] = 0;
	}
	// parse file assuming correct formatting followed - no error checking
	// savePlayer file
	fgets(line, MAX, fileMap); 				// Map file title
	hero.max = atoi(fgets(line, COUNT, fileMap)); 		// Map dimension
	// use a strcat to hold the bottom half of original file to save as map file
	char cellInfo[MAX*hero.max*hero.max];	// buffer to hold all map cells information
	fgets(line, MAX, fileMap); 		// Map file format break
	fgets(line, MAX, fileMap); 		// Player coordinates - split below
	hero.x = atoi(strtok(line, ","));
	hero.y = atoi(strtok(NULL, ","));
	hero.energy = atoi(fgets(line, COUNT, fileMap));	// Player energy
	hero.whiffles = atoi(fgets(line, COUNT, fileMap));	// Player whiffles
	// end savePlayer file
	// saveInventory file - hardcode switch statement using strcmp
	fgets(line, MAX, fileMap);
	// count the number of imes an item appears in hero.tool
	while(strchr(line,'#') == NULL)
	{
		if(strcmp(line,"Hatchet\n") == 0)
		{
			++hero.tool[0];
		}
		else if(strcmp(line,"Axe\n") == 0)
		{
			++hero.tool[1];
		}
		else if(strcmp(line,"Chainsaw\n") == 0)
		{
			++hero.tool[2];
		}
		else if(strcmp(line,"Chisel\n") == 0)
		{
			++hero.tool[3];
		}
		else if(strcmp(line,"Sledge\n") == 0)
		{
			++hero.tool[4];
		}
		else if(strcmp(line,"Jackhammer\n") == 0)
		{
			++hero.tool[5];
		}
		else if(strcmp(line,"Machete\n") == 0)
		{
			++hero.tool[6];
		}
		else if(strcmp(line,"Shears\n") == 0)
		{
			++hero.tool[7];
		}
		else if(strcmp(line,"Binoculars\n") == 0)
		{
			++hero.tool[8];
		}
		else if(strcmp(line,"Boat\n") == 0)
		{
			++hero.tool[9];
		}
		else // Power Bar
		{
			++hero.tool[10];
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
       
        save(hero);
	saveMap(hero.max,cellInfo);
	return 0;
}
