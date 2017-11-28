/****************************************************
  * Programmer: Leon Lee
  * File: movement_combiner.c
  * Description: 
    1. Read in Environment value from client-side
    2. Initialize the char env_Extract with the direction input
    3. call dir_move to get the possible coord after moving
    4. call obs_check to see if the possible coord will be finalized or be dumped
    5. call item_check to gain or use item
    6. check for energy depletion
    7. check for royal diamond win state

  **************************************************/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <cgi.h>
#include "MovementChecker.h"
#include "Save.h"

//variable to read in AJAX value
char get_Env[1];
char env_Extract;

s_cgi *cgi;

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    //Initializing map and player data
    struct map game_Map = makeMap("Save_MapCells_TeamG.txt"); 
    struct player hero = load();

    //future x,y coordinate -> to check the cell ahead to react accordingly
    int fx = 0, fy = 0;

    //read in data from AJAX
    cgi = cgiInit();
    strcpy(get_Env, cgiGetValue(cgi, "dir")); 
    env_Extract = get_Env[0];

    //void function -> set fx, fy as the cell ahead according to the user's direction env_Extract
    dir_move(env_Extract, &fx, &fy, hero);

    //void function -> check what kind of terrain ahead 
    //-> move if moveable terrain or don't if not moveable terrain
    //-> after the decision change the player data to result. x,y coord, energy
    obs_check(fx, fy, game_Map);

    //void function -> check what kind of item ahead (strcmp) -> pick up the item or use the item without prompt 
    //-> change the player data accordingly. inventory, whiffles, energy 
    item_check(fx, fy, game_Map);

    //re-load the player's data after changing all the data through terrain/item check function
    hero = load();

    //check energy depletion
    if(hero.energy < 1){
        printf("<br>****************************<br>");
        printf("<br>YOU RAN OUT OF ENERGY! WE'RE SETTING YOU BACK TO ORIGINAL STATUS!<br><br>");
        printf("<br>****************************<br>");

        resetMap();
    }

    //check royal diamonds
    if(game_Map.rdX == hero.x && game_Map.rdY == hero.y){
        printf("<br>****************************<br>");
        printf("<br>YOU FOUND ROYAL DIAMOND! YOU WON! WE'LL BE GO BACK TO YOUR HELL HOLE :( <br><br>");
        printf("<br>****************************<br>");
        
        resetMap();    
    }

    //delete map
    deallocateMap(hero.max, &game_Map);

    return 0;
}
