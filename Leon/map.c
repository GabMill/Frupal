#include "map.h"

//creates a cell, constructor essentially, but because C doesn't have constructors, i need to define it outside of the struct
struct cell makeCell(int x, int y, int visibility, int land, const char* inItem) {
    struct cell retVal;

    retVal.xCoord = x;
    retVal.yCoord = y;
    retVal.isVisible = visibility;
    retVal.terrain = land;

    strcpy(retVal.item, inItem);

    return retVal;
}

//allocates memory for the map, then initializes all cells to be empty and invisible
void initializeMap(int size, struct map* inMap) {
    inMap->dimensions = size;
    inMap->loaded = 0;

    inMap->cells = malloc(size * sizeof(struct cell*));

    for (int i = 0; i < size; ++i)
        inMap->cells[i] = malloc(size * sizeof(struct cell));

    for(int x = 0; x < size; ++x)
        for (int y = 0; y < size; ++y) {
            struct cell temp = makeCell(x, y, 0, 0 , "None");
            inMap->cells[x][y] = temp;
        }
}

//VERY IMPORTANT!
//MUST BE CALLED TO PREVENT MEMORY LEAKS. DO NOT CALL MAKEMAP WITHOUT CALLING DEALLOCATE MAP BEFORE RETURNING IN MAIN.
//TECHNICALLY THE MEMORY IS FREED AFTER THE PROGRAM TERMINATES, BUT IT'S STILL BAD PRACTICE!
void deallocateMap(int size, struct map* inMap) {
    for (int i = 0; i < size; ++i)
        free(inMap->cells[i]);

    free(inMap->cells);
}

//debug function to validate all files end up in the right spot
void printMap(int size, struct map* inMap) {
    for (int x = 0; x < size; ++x) {
        for (int y = 0; y < size; ++y){
            printf("%d,", inMap->cells[x][y].xCoord);
            printf("%d,", inMap->cells[x][y].yCoord);
            printf("%d,", inMap->cells[x][y].isVisible);
            printf("%d,", inMap->cells[x][y].terrain);
            printf("%s, ", inMap->cells[x][y].item);
        }
        printf("\n");
    }
}

//main parsing routine to load in a map
struct map makeMap(char* filename) {
    struct map retMap;
    FILE* inFile;
    inFile = fopen(filename, "r");
    char line[64];
    int lineCount = 1;

    //do operations line by line
    while (fgets(line, sizeof(line), inFile)) {
        //dimensions line
        if (lineCount == 1) {
            ++lineCount;
            //convert the cstring to its integer value, we get the map dimensions
            int dimensions = atoi(line);

            initializeMap(dimensions, &retMap);
            continue;
        }
        //all other lines are mentioned map cells
        if (lineCount >= 2) {
            char* tmp = strtok(line, ",");
            int fieldCount = 0;
            struct cell temp;

            while (tmp != NULL) {
                switch (fieldCount) {
                    case 0:
                        //xCoord
                        ++fieldCount;
                        int x = atoi(tmp);
                        if(x > retMap.dimensions - 1)
                            return retMap;
                        else
                            temp.xCoord = x;
                        tmp = strtok(NULL, ",");
                        continue;
                    case 1:
                        //yCoord
                        ++fieldCount;
                        int y = atoi(tmp);
                        if(y > retMap.dimensions - 1)
                            return retMap;
                        else
                            temp.yCoord = y;
                        tmp = strtok(NULL, ",");
                        continue;
                    case 2:
                        //visibility
                        ++fieldCount;
                        if(atoi(tmp) != 1)
                            temp.isVisible = 0;
                        else
                            temp.isVisible = 1;
                        tmp = strtok(NULL, ",");
                        continue;
                    case 3:
                        //terrain
                        ++fieldCount;
                        if(atoi(tmp) > 5)
                            temp.terrain = 0;
                        else
                            temp.terrain = atoi(tmp);
                        tmp = strtok(NULL, ",");
                        continue;
                    case 4:
                        //item
                        ++fieldCount;
                        if(strcmp(tmp, "Royal Diamonds\n") == 0){
                            retMap.rdX = temp.xCoord;
                            retMap.rdY = temp.yCoord;
                        }
                        tmp[strlen(tmp)-1] = '\0';
                        strcpy(temp.item, tmp);
                        tmp = strtok(NULL, ",");
                        continue;
                    case 5:
                        break;
                }//end switch
            }//end parsing while

            //push the newly made cell to the array
            retMap.cells[temp.xCoord][temp.yCoord] = temp;
        }//end main routine
    }
    //if we get here, the map is fully loaded with no issues
    retMap.loaded = 1;
    fclose(inFile);
    return retMap;
}
