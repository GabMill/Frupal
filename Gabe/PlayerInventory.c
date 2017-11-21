#include <stdio.h>
#include <cgi.h>
#include <string.h>

enum item{hatchet = 0, axe = 1, chainsaw = 2, chisel = 3, sledge = 4,
  jackhammer = 5, machete = 6, shears = 7, binoculars = 8};

int inventory[9];

int main(void)
{
  printf("Content-Type: text/html;charset=us-ascii\n\n");

  printf("Hatchets - 15Wh   (%d)</br>", inventory[hatchet]);
  printf("Axes - 30Wh   (%d)</br>", inventory[axe]);
  printf("Chainsaws - 60Wh   (%d)</br>", inventory[chainsaw]);
  printf("Chisels - 5Wh   (%d)</br>", inventory[chisel]);
  printf("Sledges - 25Wh   (%d)</br>", inventory[sledge]);
  printf("Jackhammers - 100Wh   (%d)</br>", inventory[jackhammer]);
  printf("Machetes - 25Wh   (%d)</br>", inventory[machete]);
  printf("Shears - 35Wh   (%d)</br>", inventory[shears]);
  printf("Biconulars - ?Wh   (%d)</br>", inventory[binoculars]);
  return 0;
}
