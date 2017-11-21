#include "moves.h"

void dir_move(char input, int *fx, int *fy, struct player hero){

    if(input == 'd' || input == 'D'){
        if(hero.y < (hero.max - 1)){
            *fx = hero.x;
            *fy = hero.y + 1;
            --hero.energy;
        }
        else if(hero.y == (hero.max - 1)){
            *fx = hero.x;
            *fy = 0;
            --hero.energy;
        }
    }

    else if(input == 'a' || input == 'A'){
        if(hero.y > 0){
            *fx = hero.x;
            *fy = hero.y - 1;
            --hero.energy;
        }
        else if(hero.y == 0){
            *fx = hero.x;
            *fy = (hero.max - 1);
            --hero.energy;
        }
    }

    else if(input == 's' || input == 'S'){
        if(hero.x < (hero.max - 1)){
            *fy = hero.y;
            *fx = hero.x + 1;
            --hero.energy;
        }
        else if(hero.x == (hero.max - 1)){
            *fy = hero.y;
            *fx = 0;
            --hero.energy;
        }
    }

    else if(input == 'w' || input == 'W'){
        if(hero.x > 0){
            *fy = hero.y;
            *fx = hero.x - 1;
            --hero.energy;
        }
        else if(hero.x == 0){
            *fy = hero.y;
            *fx = (hero.max - 1);
            --hero.energy;
        }
    }

    else{
        *fx = hero.x;
        *fy = hero.y;
        --hero.energy;
    }
}

void obs_check(int x, int y, struct map q){
    struct player z = load();

    --z.energy;

    if(q.cells[x][y].terrain == 0){
        printf("Walking through a Meadow<br><br>");
        z.x = x;
        z.y = y;
        save(z);
    }

    else if(q.cells[x][y].terrain == 1){
        printf("Walking through a Forest<br><br>");
        z.x = x;
        z.y = y;
        save(z);
    }

    else if(q.cells[x][y].terrain == 2){
        printf("Can't walk on Water<br><br>");
        save(z);
    }

    else if(q.cells[x][y].terrain == 3){
        printf("Can't walk through Walls<br><br>");
        save(z);
    }

    else if(q.cells[x][y].terrain == 4){
        printf("Walking through a Bog, lost two energy<br><br>");
        z.x = x;
        z.y = y;
        --z.energy;
        save(z);
    }

    else if(q.cells[x][y].terrain == 5){
        printf("Walking through a Swamp, lost two energy<br><br>");
        z.x = x;
        z.y = y;
        --z.energy;
        save(z);
    }
}

void item_check(int x, int y, struct map q){
    struct player z = load();
    int i = 0;

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
        --z.whiffles;
        z.energy += 20;
    }

    else if(!strcmp(q.cells[x][y].item, "Tree")){
        if(z.tool[0] && !i){
            printf("<br>Used Hatchet to chop down a Tree! Used 8 energy and 15 Wh!<br><br>");
            z.energy -= 8;
            z.whiffles -= 15;
            --z.tool[0];
            ++i;
        }

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

        else{
            printf("<br>You broke your arm and lost 10 energy but got rid of a Tree!<br><br>");
            z.energy -= 10;
            ++i;
        }
    }

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

    save(z);
}
