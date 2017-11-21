#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <cgi.h>
#include "moves.h"

char getting[1];
char input;

s_cgi *cgi;

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    struct map place = makeMap("map.txt"); 
    struct player hero = load();
    int fx = 0, fy = 0;

    cgi = cgiInit();

    strcpy(getting, cgiGetValue(cgi, "dir")); 

    input = getting[0];

    dir_move(input, &fx, &fy, hero);

    obs_check(fx, fy, place);

    item_check(fx, fy, place);

    hero = load();

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

    //if(!strcmp(place.cells[hero.x][hero.y].item, "Royal Diamonds")){
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


    printf("User Location: (%d, %d)<br>Energy: %d<br>Whiffles: %d<br>", hero.x, hero.y, hero.energy, hero.whiffles);
    printf("<br>Item: %s", place.cells[hero.x][hero.y].item);

    deallocateMap(hero.max, &place);

    return 0;
}
