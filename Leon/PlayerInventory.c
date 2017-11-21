#include <stdio.h>
#include <cgi.h>
#include <string.h>
#include "player.h"

int main(void)
{
    printf("Content-Type: text/html;charset=us-ascii\n\n");

    struct player hero = load();

    if(hero.tool[0]) 
        printf("Hatchets - 15Wh   (%d)</br>", hero.tool[0]);
    if(hero.tool[1])
        printf("Axes - 30Wh   (%d)</br>", hero.tool[1]);
    if(hero.tool[2])
        printf("Chainsaws - 60Wh   (%d)</br>", hero.tool[2]);
    if(hero.tool[3])
        printf("Chisels - 5Wh   (%d)</br>", hero.tool[3]);
    if(hero.tool[4])
        printf("Sledges - 25Wh   (%d)</br>", hero.tool[4]);
    if(hero.tool[5])
        printf("Jackhammers - 100Wh   (%d)</br>", hero.tool[5]);
    if(hero.tool[6])
        printf("Machetes - 25Wh   (%d)</br>", hero.tool[6]);
    if(hero.tool[7])
        printf("Shears - 35Wh   (%d)</br>", hero.tool[7]);
    if(hero.tool[8])
        printf("Biconulars - ?Wh   (%d)</br>", hero.tool[8]);
    if(hero.tool[9])
        printf("Boats - ?Wh   (%d)</br>", hero.tool[9]);
    if(hero.tool[10])
        printf("Power Bar - 1Wh   (%d)</br>", hero.tool[10]);

    return 0;
}
