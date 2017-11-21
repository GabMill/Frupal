#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "map.h"

void dir_move(char input, int *fx, int *fy, struct player hero);

void obs_check(int x, int y, struct map q);

void item_check(int x, int y, struct map q);
