#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player{
    int max;
    int x;
    int y;
    int energy;
    int whiffles;

    int tool[11];
};

struct player load();

void save(struct player hero);