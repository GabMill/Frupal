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
  *Input: int x, int y, struct map q 
  *Output: void -> changes player's energy and moveability 
  *Description: reads in player's coord and see if that cell is a moveable cell
                if moveable -> player data will be renewed with the inputted x, y coords
                if not moveable -> player data will not be renewed with the inputted x, y coords 
*********************************/
void obs_check(int x, int y, struct map q){
    //load in original coord previous to movement
    struct player z = load();

    //decrement energy whether or not moved
    --z.energy;

    //if cell is meadow -> moveable
    if(q.cells[x][y].terrain == 0){
        printf("Walking through a Meadow<br><br>");

        //update coord
        z.x = x;
        z.y = y;
        save(z);
    }

    //if cell is forest -> moveable
    else if(q.cells[x][y].terrain == 1){
        printf("Walking through a Forest<br><br>");

        //update coord
        z.x = x;
        z.y = y;
        save(z);
    }

    //if cell is water -> immovable
    else if(game_Map.cells[x][y].terrain == 2){
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
    else if(q.cells[x][y].terrain == 3){
        printf("Can't walk through Walls<br><br>");

        //do not update coord
        save(z);
    }

    //if cell is bog -> moveable with condition
    else if(q.cells[x][y].terrain == 4){
        printf("Walking through a Bog, lost two energy<br><br>");

        //update coord and decrement additional energy
        z.x = x;
        z.y = y;
        --z.energy;
        save(z);
    }

    //if cell is swamp -> moveable with condition
    else if(q.cells[x][y].terrain == 5){
        printf("Walking through a Swamp, lost two energy<br><br>");
        
        //update coord and decrement additional energy
        z.x = x;
        z.x = x;
        z.y = y;
        --z.energy;
        save(z);
    }
}

/*********************************
  *Input: int x, int y, struct map q 
  *Output: void -> changes player's inventory data
  *Description: reads in player's coord and check with the map cell's item
                if pickable item -> pick and increment inventory
                if obstacle item -> check if tool exist in player inventory and use energy / whiffles accordingly
*********************************/

void item_check(int x, int y, struct map q){
    //load in player data
    struct player z = load();

    //tool existence checker
    int i = 0;

    //pickable item if-loop -> increment corresponding inventory slot
    if(!strcmp(q.cells[x][y].item, "Hatchet")){
        printf("<br>Hatchet Found!<br><br>");
        ++z.tool[0];
    }

    else if(!strcmp(q.cells[x][y].item, "Axe")){
        printf("<br>Axe Found!<br><br>");
        ++z.tool[1];
    }

    else if(!strcmp(q.cells[x][y].item, "Chainsaw")){
        printf("<br>Chainsaw Found!<br><br>");
        ++z.tool[2];
    }

    else if(!strcmp(q.cells[x][y].item, "Chisel")){
        printf("<br>Chisel Found!<br><br>");
        ++z.tool[3];
    }

    else if(!strcmp(q.cells[x][y].item, "Sledge")){
        printf("<br>Sledge Found!<br><br>");
        ++z.tool[4];
    }

    else if(!strcmp(q.cells[x][y].item, "Jackhammer")){
        printf("<br>Jackhammer Found!<br><br>");
        ++z.tool[5];
    }

    else if(!strcmp(q.cells[x][y].item, "Machete")){
        printf("<br>Machete Found!<br><br>");
        ++z.tool[6];
    }

    else if(!strcmp(q.cells[x][y].item, "Shears")){
        printf("<br>Shears Found!<br><br>");
        ++z.tool[7];
    }

    else if(!strcmp(q.cells[x][y].item, "Binocular")){
        printf("<br>Binocular Found!<br><br>");
        ++z.tool[8];
    }

    else if(!strcmp(q.cells[x][y].item, "Boat")){
        printf("<br>Boat Found!<br><br>");
        ++z.tool[9];
    }

    else if(!strcmp(q.cells[x][y].item, "Power Bar")){
        printf("<br>Power Bar Found!<br>");
        printf("<br>Used 1Wh and restored 20 energy!<br><br>");
        ++z.tool[10];

        //use whiffles and gain energy
        --z.whiffles;
        z.energy += 20;
    }

    //obstacle items

    //Tree obstacle
    else if(!strcmp(q.cells[x][y].item, "Tree")){
        //if this tool exist && haven't used tool yet
        if(z.tool[0] && !i){
            printf("<br>Used Hatchet to chop down a Tree! Used 8 energy and 15 Wh!<br><br>");

            //change whiffles / energy and decrement tool and set item used flag
            z.energy -= 8;
            z.whiffles -= 15;
            --z.tool[0];
            ++i;
        }

        //repeating procedure for all tool usage for Tree
        else if(z.tool[1] && !i){
            printf("<br>Used Axe to chop down a Tree! Used 6 energy and 30 Wh!<br><br>");
            z.energy -= 6;
            z.whiffles -= 30;
            --z.tool[1];
            ++i;
        }

        else if(z.tool[2] && !i){
            printf("<br>Used Chainsaw to chop down a Tree! Used 2 energy and 60 Wh!<br><br>");
            z.energy -= 2;
            z.whiffles -= 60;
            --z.tool[2];
            ++i;
        }

        //if zero item then use default
        else{
            printf("<br>You broke your arm and lost 10 energy but got rid of a Tree!<br><br>");
            z.energy -= 10;
            ++i;
        }
    }

    //Boulder obstacle -> repeat same algorithm as tree obstacle
    else if(!strcmp(q.cells[x][y].item, "Boulder")){
        if(z.tool[3] && !i){
            printf("<br>Used Chisel to crush the Boulder! Used 15 energy and 5 Wh!<br><br>");
            z.energy -= 15;
            z.whiffles -= 5;
            --z.tool[3];
            ++i;
        }

        else if(z.tool[4] && !i){
            printf("<br>Used Sledge to crush the Boulder! Used 12 energy and 25 Wh!<br><br>");
            z.energy -= 12;
            z.whiffles -= 25;
            --z.tool[4];
            ++i;
        }

        else if(z.tool[5] && !i){
            printf("<br>Used Jackhammer to crush the Boulder! Used 4 energy and 100 Wh!<br><br>");
            z.energy -= 4;
            z.whiffles -= 100;
            --z.tool[5];
            ++i;
        }

        else{
            printf("<br>You lost 16 energy and a finger but got rid of a Boulder!<br><br>");
            z.energy -= 16;
            ++i;
        }

    }

    //Bush obstacle -> repeat same algorithm as above
    else if(!strcmp(q.cells[x][y].item, "Bush")){
        if(z.tool[6] && !i){
            printf("<br>Used Machete to cut down Blackberry Bush! Used 2 energy and 25 Wh!<br><br>");
            z.energy -= 2;
            z.whiffles -= 25;
            --z.tool[6];
            ++i;
        }

        else if(z.tool[7] && !i){
            printf("<br>Used Shears to cut down Blackberry Bush! Used 2 energy and 35 Wh!<br><br>");
            z.energy -= 2;
            z.whiffles -= 35;
            --z.tool[7];
            ++i;
        }

        else{
            printf("<br>You are bleeding heavily in your leg and lost 4 energy but no more blackberry bush<br><br>");
            z.energy -= 4;
            ++i;
        }

    }

    //save all the changes
    save(z);
}
