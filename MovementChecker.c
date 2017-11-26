/****************************************************
  * Programmer: Leon Lee
  * File: movement_checker.c
  * Description: Calculate the coords / Check Terrain and respond / Check which item or obstacle and respond
  **************************************************/

#include "MovementChecker.h"

/*********************************
  *Input: char input, int *fx, int *fy, struct player hero
  *Output: void but alters the int *fx and int *fy
  *Description: reads in the user's coords and alter it through user's direction input char
                save the result into fx and fy so user can access it outside the scope
*********************************/

void dir_move(char input, int *fx, int *fy, struct player hero){

    //if user chose 'd' -> East direction
    if(input == 'd' || input == 'D'){
        //if in bound
        if(hero.y < (hero.max - 1)){
            *fx = hero.x;
            *fy = hero.y + 1;
        }

        //if going out of bound
        else if(hero.y == (hero.max - 1)){
            *fx = hero.x;
            *fy = 0;
        }
    }

    //if user chose 'a' -> West direction
    else if(input == 'a' || input == 'A'){
        //if in bound
        if(hero.y > 0){
            *fx = hero.x;
            *fy = hero.y - 1;
        }

        //if going out of bound
        else if(hero.y == 0){
            *fx = hero.x;
            *fy = (hero.max - 1);
        }
    }

    //if user chose 's' -> South direction
    else if(input == 's' || input == 'S'){
        //if in bound
        if(hero.x < (hero.max - 1)){
            *fy = hero.y;
            *fx = hero.x + 1;
        }

        //if out of bound
        else if(hero.x == (hero.max - 1)){
            *fy = hero.y;
            *fx = 0;
        }
    }

    //if user chose 'w' -> North direction
    else if(input == 'w' || input == 'W'){
        //if in bound
        if(hero.x > 0){
            *fy = hero.y;
            *fx = hero.x - 1;
        }

        //if out of bound
        else if(hero.x == 0){
            *fy = hero.y;
            *fx = (hero.max - 1);
        }
    }

    //if wrong input
    else{
        *fx = hero.x;
        *fy = hero.y;
    }
}

/*********************************
  *Input: int x, int y, struct map game_Map 
  *Output: void -> changes player's energy and moveability 
  *Description: reads in player's coord and see if that cell is a moveable cell
                if moveable -> player data will be renewed with the inputted x, y coords
                if not moveable -> player data will not be renewed with the inputted x, y coords 
*********************************/
void obs_check(int x, int y, struct map game_Map){
    //load in original coord previous to movement
    struct player hero = load();
	
	int compare = game_Map.cells[x][y].terrain;

    //if cell is meadow -> moveable
    if(compare == 0){
        printf("Walking through a Meadow<br><br>");

        //update coord
        hero.x = x;
        hero.y = y;
        --hero.energy;
        save(hero);
    }

    //if cell is forest -> moveable
    else if(compare == 1){
        printf("Walking through a Forest<br><br>");

        //update coord
        hero.x = x;
        hero.y = y;
        --hero.energy;
        save(hero);
    }

    //if cell is water -> immovable
    else if(compare == 2){
        //If already on water, which means already used boat
        if(game_Map.cells[hero.x][hero.y].terrain == 2){
            printf("Still moving through water with the boat");

            //no energy is consumed
            hero.x = x;
            hero.y = y;
        }

        //if coming from non-water terrain
        else{
            //if user has a boat
            if(hero.tool[9]){
                printf("Using the boat! No energy will be consumed!");

                //walk on water and use boat and no energy consumed
                hero.x = x;
                hero.y = y;
            }

            //no boat
            else{
                printf("Can't walk on Water<br><br>");

                //decrement energy but don't change coord
                --hero.energy;
            }

        }
        //update whatever happened to the player data
        save(hero);
    }

    //if cell is wall -> immoveable
    else if(compare == 3){
        printf("Can't walk through Walls<br><br>");
        --hero.energy;

        //do not update coord
        save(hero);
    }

    //if cell is bog -> moveable with condition
    else if(compare == 4){
        printf("Walking through a Bog, lost two energy<br><br>");

        //update coord and decrement additional energy
        hero.x = x;
        hero.y = y;
        hero.energy -= 2;
        save(hero);
    }

    //if cell is swamp -> moveable with condition
    else if(compare == 5){
        printf("Walking through a Swamp, lost two energy<br><br>");

        //update coord and decrement additional energy
        hero.x = x;
        hero.x = x;
        hero.y = y;
        hero.energy -= 2;
        save(hero);
    }
}

/*********************************
 *Input: int x, int y, struct map game_Map 
 *Output: void -> changes player's inventory data
 *Description: reads in player's coord and check with the map cell's item
 if pickable item -> pick and increment inventory
 if obstacle item -> check if tool exist in player inventory and use energy / whiffles accordingly
 *********************************/

void item_check(int x, int y, struct map game_Map){
    //load in player data
    struct player hero = load();

    //tool existence checker
    int i = 0;
	
	//Which item is picked up
    char picked[20];

	//Initialize the comparing char array
    strcpy(picked, game_Map.cells[hero.x][hero.y].item);
	
	
    //pickable item if-loop -> if item is matched then print out which one it is and the cost
    if(!strcmp(picked, "Hatchet")){
        printf("<br>Hatchet Found!<br><br>");
        printf("<br>Cost = 15 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Axe")){
        printf("<br>Axe Found!<br><br>");
        printf("<br>Cost = 30 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Chainsaw")){
        printf("<br>Chainsaw Found!<br><br>");
        printf("<br>Cost = 60 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Chisel")){
        printf("<br>Chisel Found!<br><br>");
        printf("<br>Cost = 5 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Sledge")){
        printf("<br>Sledge Found!<br><br>");
        printf("<br>Cost = 25 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Jackhammer")){
        printf("<br>Jackhammer Found!<br><br>");
        printf("<br>Cost = 100 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Machete")){
        printf("<br>Machete Found!<br><br>");
        printf("<br>Cost = 25 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Shears")){
        printf("<br>Shears Found!<br><br>");
        printf("<br>Cost = 35 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Binocular")){
        printf("<br>Binocular Found!<br><br>");
        printf("<br>Cost = 50 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Boat")){
        printf("<br>Boat Found!<br><br>");
        printf("<br>Cost = 500 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    else if(!strcmp(picked, "Power Bar")){
        printf("<br>Power Bar Found!<br>");
        printf("<br>Cost = 1 Wh<br>"); 
        printf("<br>Click the Purchase button to Purchase!<br>");
    }

    //obstacle items

    //Tree obstacle
    else if(!strcmp(picked, "Tree")){
        //if this tool exist && haven't used tool yet
        if(hero.tool[0] && !i){
            printf("<br>Used Hatchet to chop down a Tree! Used 8 energy and 15 Wh!<br><br>");

            //change whiffles / energy and decrement tool and set item used flag
            hero.energy -= 8;
            --hero.tool[0];
            ++i;
        }

        //repeating procedure for all tool usage for Tree
        else if(hero.tool[1] && !i){
            printf("<br>Used Axe to chop down a Tree! Used 6 energy and 30 Wh!<br><br>");
            hero.energy -= 6;
            --hero.tool[1];
            ++i;
        }

        else if(hero.tool[2] && !i){
            printf("<br>Used Chainsaw to chop down a Tree! Used 2 energy and 60 Wh!<br><br>");
            hero.energy -= 2;
            --hero.tool[2];
            ++i;
        }

        //if zero item then use default
        else{
            printf("<br>You broke your arm and lost 10 energy but got rid of a Tree!<br><br>");
            hero.energy -= 10;
            ++i;
        }
    }

    //Boulder obstacle -> repeat same algorithm as tree obstacle
    else if(!strcmp(picked, "Boulder")){
        if(hero.tool[3] && !i){
            printf("<br>Used Chisel to crush the Boulder! Used 15 energy and 5 Wh!<br><br>");
            hero.energy -= 15;
            --hero.tool[3];
            ++i;
        }

        else if(hero.tool[4] && !i){
            printf("<br>Used Sledge to crush the Boulder! Used 12 energy and 25 Wh!<br><br>");
            hero.energy -= 12;
            --hero.tool[4];
            ++i;
        }

        else if(hero.tool[5] && !i){
            printf("<br>Used Jackhammer to crush the Boulder! Used 4 energy and 100 Wh!<br><br>");
            hero.energy -= 4;
            --hero.tool[5];
            ++i;
        }

        else{
            printf("<br>You lost 16 energy and a finger but got rid of a Boulder!<br><br>");
            hero.energy -= 16;
            ++i;
        }

    }

    //Bush obstacle -> repeat same algorithm as above
    else if(!strcmp(picked, "Bush")){
        if(hero.tool[6] && !i){
            printf("<br>Used Machete to cut down Blackberry Bush! Used 2 energy and 25 Wh!<br><br>");
            hero.energy -= 2;
            --hero.tool[6];
            ++i;
        }

        else if(hero.tool[7] && !i){
            printf("<br>Used Shears to cut down Blackberry Bush! Used 2 energy and 35 Wh!<br><br>");
            hero.energy -= 2;
            --hero.tool[7];
            ++i;
        }

        else{
            printf("<br>You are bleeding heavily in your leg and lost 4 energy but no more blackberry bush<br><br>");
            hero.energy -= 4;
            ++i;
        }

    }

    else if(!strcmp(picked, "Treasure Chest 1")){
        //don't care about the tool, just do the thing needed
        hero.whiffles += 100;
        printf("<br>You encountered a Treasure Chest and found 100 Whiffles! Jackpot!<br><br>");
    }

    else if(!strcmp(picked, "Treasure Chest 2")){
        hero.whiffles = 0;
        printf("<br>You encountered a mimic and lost all your Whiffles!<br><br>");
    }
	
	//Clue comparison - TRUE
	else if(!strcmp(picked, "Clue_0")){
		printf("<br>****************************<br>");
        printf("<br>You find a clue on the ground! It reads this:");
		printf("<br>You are %d grovnicks away from the southern border...", y);
		printf("<br>The diamonds are %d steps from sunset...", game_Map.rdX);
		printf("<br>and %d from the southern shore...<br><br>", game_Map.rdY);
        printf("<br>****************************<br>");
	}
	
	//Clue comparison - FALSE
	else if(!strcmp(picked, "Clue_1")){
		printf("<br>****************************<br>");
        printf("<br>You find a clue on the ground! It reads this:");
		printf("<br>You are %d grovnicks away from the southern border...", y-2);
		printf("<br>The diamonds are %d steps from sunset...", game_Map.rdX+1);
		printf("<br>and %d from the southern shore...<br><br>", game_Map.rdY-1);
        printf("<br>****************************<br>");
	}

    //save all the changes
    save(hero);
}
