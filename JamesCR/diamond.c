#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cgi.h>
#include "diamond_finder.h"

//This code is to display the alert for finding the royal diamonds.
//needs to be added to the movement.c file to run properly
//Remember to change <MAP_NAME> to whatever the map's name is!

int main(void)
{
	printf("Content-Type: text/plain;charset=us-ascii\n\n");
	if(OnDiamond(fx, fy, <MAP_NAME>) == 1) printf("You have found the Royal Diamonds!");
	return 0;
}