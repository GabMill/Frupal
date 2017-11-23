/*
 * CS300: Frupal Project
 * Team G
 * Written by: Alexander Mason
 * File: Map_Display.h
 */
#ifndef _MAP_DISPLAY
#define _MAP_DISPLAY

#include <cgi.h>
#include <stdbool.h>
#include "map.h"
#include "player.h"

//Update the visibility squares
void setVisible(int pX, int pY, struct map updateMap);

//Draw the html displaying the map
void drawMap(int pX, int pY, struct map updatedMap);

//Draw the objects on z-index 2
void drawObjects(int xCoor, int yCoor, struct map updatedMap);

//Compare player location with passed in coordinates
bool comparePlayerToCoor(int cellX, int cellY, int pX, int pY);
#endif
