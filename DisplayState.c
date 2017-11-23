/****************************************************
  * Programmer: Leon Lee
  * File: DisplayState.c
  * Description: Print all the data of player struct
  **************************************************/

#include "Player.h"

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    //load in player data
    struct player hero = load();

    printf("<br>-----------------------------------");

    printf("<br>Player Status<br><br>");

    printf("User Location: (%d, %d)<br>Energy: %d<br>Whiffles: %d<br>", hero.x, hero.y, hero.energy, hero.whiffles);
    
    printf("<br>-----------------------------------");

    return 0;
}
