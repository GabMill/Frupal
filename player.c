#include "player.h"

/**********************************
  * Input: none -> txt needs to be ready
  * Output: struct player
  * Description: read in line from a designated txt file -> save it into struct and return it
**********************************/

struct player load(){
    struct player loader;

    //dummy char setter
    char getter[10];
    //dummy char reader
    char single;
    //flags
    int i = 0, j =0, k = 0;

    //open from Player_Save_File.txt
    FILE *fp = fopen("Player_Save_File.txt", "r");

    //read in first char
    single = fgetc(fp);

    //loop until end of file
    while(single != EOF){
        //each line
        while(single != '\n'){
            //set the dummy setter with reader
            getter[i] = single;
            single = fgetc(fp);
            
            //increment position
            ++i;
        }

        //add end of string
        getter[i] = '\0';

        //reset positioner
        i = 0;

        //first line -> max 
        if(k == 0)
            loader.max = atoi(getter);

        //second line -> x coord
        else if(k == 1)
            loader.x = atoi(getter);

        //third line -> y coord
        else if(k == 2)
            loader.y = atoi(getter);

        //fourth line -> energy
        else if(k == 3)
            loader.energy = atoi(getter);

        //fifth line -> whiffles
        else if(k == 4)
            loader.whiffles = atoi(getter);

        //sixth line and so forth -> items
        else if(k > 4){
            loader.tool[j] = atoi(getter);
            ++j;
        }

        single = fgetc(fp);
        ++k;
    }

    //return struct itself
    return loader;
}

/**********************************
  * Input: struct player hero
  * Output: updated txt file
  * Description: write out the current player struct's data into a txt file
**********************************/

void save(struct player hero){
    //open file for writing
    FILE *fp = fopen("Player_Save_File.txt", "w");

    //write out the 5 main static data -> max, x, y, energy, whiffles
    fprintf(fp, "%d\n%d\n%d\n%d\n%d\n", hero.max, hero.x, hero.y, hero.energy, hero.whiffles);

    //write out inventory
    for(int i = 0; i < 11; ++i){
        fprintf(fp, "%d\n", hero.tool[i]);
    }

    //close
    fclose(fp);
}
