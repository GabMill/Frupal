#include "player.h"

struct player load(){
    struct player loader;

    char getter[10];
    char single;
    int i = 0, j =0, k = 0;

    FILE *fp = fopen("Player_Save_File.txt", "r");

    single = fgetc(fp);

    while(single != EOF){
        while(single != '\n'){
            getter[i] = single;
            single = fgetc(fp);
            ++i;
        }

        getter[i] = '\0';

        i = 0;

        if(k == 0)
            loader.max = atoi(getter);
        else if(k == 1)
            loader.x = atoi(getter);
        else if(k == 2)
            loader.y = atoi(getter);
        else if(k == 3)
            loader.energy = atoi(getter);
        else if(k == 4)
            loader.whiffles = atoi(getter);
        else if(k > 4){
            loader.tool[j] = atoi(getter);
            ++j;
        }

        single = fgetc(fp);
        ++k;
    }

    return loader;
}

void save(struct player hero){
    FILE *fp = fopen("Player_Save_File.txt", "w");

    fprintf(fp, "%d\n%d\n%d\n%d\n%d\n", hero.max, hero.x, hero.y, hero.energy, hero.whiffles);

    for(int i = 0; i < 11; ++i){
        fprintf(fp, "%d\n", hero.tool[i]);
    }

    fclose(fp);
}
