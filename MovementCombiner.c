#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <cgi.h>
#include "MovementChecker.h"
#include "Save.h"

//variable to read in AJAX value
char getting[1];
char input;

s_cgi *cgi;

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    //Initializing map and player data
    struct map place = makeMap("Save_MapCells_TeamG.txt"); 
    struct player hero = load();

    //future x,y coordinate -> to check the cell ahead to react accordingly
    int fx = 0, fy = 0;

    //read in data from AJAX
    cgi = cgiInit();
    strcpy(getting, cgiGetValue(cgi, "dir")); 
    input = getting[0];

    //void function -> set fx, fy as the cell ahead according to the user's direction input
    dir_move(input, &fx, &fy, hero);

    //void function -> check what kind of terrain ahead 
    //-> move if moveable terrain or don't if not moveable terrain
    //-> after the decision change the player data to result. x,y coord, energy
    obs_check(fx, fy, place);

    //void function -> check what kind of item ahead (strcmp) -> pick up the item or use the item without prompt 
    //-> change the player data accordingly. inventory, whiffles, energy 
    item_check(fx, fy, place);

    //re-load the player's data after changing all the data through terrain/item check function
    hero = load();

    //check energy depletion
    if(hero.energy < 1){
        printf("<br>****************************<br>");
        printf("<br>YOU RAN OUT OF ENERGY! WE'RE SETTING YOU BACK TO ORIGINAL STATUS!<br><br>");
        printf("<br>****************************<br>");
        hero.max = hero.max;
        hero.x = 0;
        hero.y = 0;
        hero.energy = 100;
        hero.whiffles = 1000;
        
        save(hero);
    }

    //check royal diamonds
    if(place.rdX == hero.x && place.rdY == hero.y){
        printf("<br>****************************<br>");
        printf("<br>YOU FOUND ROYAL DIAMOND! YOU WON! WE'LL BE GO BACK TO YOUR HELL HOLE :( <br><br>");
        printf("<br>****************************<br>");
        
        hero.max = hero.max;
        hero.x = 0;
        hero.y = 0;
        hero.energy = 100;
        hero.whiffles = 1000;
        
        save(hero);
    }


    //print player data
    printf("User Location: (%d, %d)<br>Energy: %d<br>Whiffles: %d<br>", hero.x, hero.y, hero.energy, hero.whiffles);
    printf("<br>Item: %s", place.cells[hero.x][hero.y].item);

    //delete map
    deallocateMap(hero.max, &place);

    return 0;
}
