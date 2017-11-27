/****************************************************
 * Programmer: Leon Lee
 * File: Purchase.c
 * Description: Purchase the item that I'm on. If not enough money then don't buy
 **************************************************/

#include "Map.h"
#include "Save.h"
#include "Player.h"

int main(){
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    //Initialize the map and player data
    struct map game_Map = makeMap("Save_MapCells_TeamG.txt");
    struct player hero = load();

    //Which item is picked up
    char picked[20];

    //Initialize the comparing char array
    strcpy(picked, game_Map.cells[hero.x][hero.y].item);

    //if the player is on the Hatchet item
    if(!strcmp(picked, "Hatchet")){
        //not enough money
        if(hero.whiffles > 14){
            printf("<br>Hatchet Purchased!<br>");

            //increase the inventory of Hatchet slot
            ++hero.tool[0];

            //use money
            hero.whiffles -= 15;

            //when purchased then remove it from map file
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }

        //not enough money
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Axe item
    else if(!strcmp(picked, "Axe")){
        if(hero.whiffles > 29){
            printf("<br>Axe Purchased!<br>");
            ++hero.tool[1];
            hero.whiffles -= 30;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Chainsaw item
    else if(!strcmp(picked, "Chainsaw")){
        if(hero.whiffles > 59){
            printf("<br>Chainsaw Purchased!<br>");
            ++hero.tool[2];
            hero.whiffles -= 60;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Chisel item
    else if(!strcmp(picked, "Chisel")){
        if(hero.whiffles > 4){
            printf("<br>Chisel Purchased!<br>");
            ++hero.tool[3];
            hero.whiffles -= 5;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Sledge item
    else if(!strcmp(picked, "Sledge")){
        if(hero.whiffles > 24){
            printf("<br>Sledge Purchased!<br>");
            ++hero.tool[4];
            hero.whiffles -= 25;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Jackhammer item
    else if(!strcmp(picked, "Jackhammer")){
        if(hero.whiffles > 99){
            printf("<br>Jackhammer Purchased!<br>");
            ++hero.tool[5];
            hero.whiffles -= 100;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Machete item
    else if(!strcmp(picked, "Machete")){
        if(hero.whiffles > 24){
            printf("<br>Machete Purchased!<br>");
            ++hero.tool[6];
            hero.whiffles -= 25;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Shears item
    else if(!strcmp(picked, "Shears")){
        if(hero.whiffles > 34){
            printf("<br>Shears Purchased!<br>");
            ++hero.tool[7];
            hero.whiffles -= 35;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Binocular item
    else if(!strcmp(picked, "Binocular")){
        if(hero.whiffles > 49){
            printf("<br>Binocular Purchased!<br>");
            ++hero.tool[8];
            hero.whiffles -= 50;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Boat item
    else if(!strcmp(picked, "Boat")){
        if(hero.whiffles > 499){
            printf("<br>Boat Purchased!<br>");
            ++hero.tool[9];
            hero.whiffles -= 500;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if the player is on the Power Bar item
    else if(!strcmp(picked, "Power Bar")){
        if(hero.whiffles > 1){
            printf("<br>Power Bar Purchased!<br>");
            ++hero.tool[10];

            --hero.whiffles;
            hero.energy += 20;
            strcpy(game_Map.cells[hero.x][hero.y].item, "None");
        }
        else{
            printf("<br>Not Enough Money!<br>");
        }
    }

    //if there were no item on the cell
    else
        printf("<br>Nothing to be purchased... Go look around more!<br>");

    //save the changed map file
    updateMap(hero.max, hero.x, hero.y, 1, &game_Map);
    //Save all the change
    save(hero);
}
