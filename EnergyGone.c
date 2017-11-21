//Aaron Dawson
//function for determining when we have run out of energy

#include "energy_gone.h"

//returns 0 if out of energy
//returns 1 otherwise
int check_energy(int energy)
{
	if (energy < 1){
		printf("Content-Type: text/plain;charset=us-ascii\n\n");
		printf("You stumble and fall as your energy is depleted. GAME OVER");
		return 0;
	}

	return 1;
}


int main(void)
{
	printf("Content-Type: text/plain;charset=us-ascii\n\n");	
	check_energy(0);

	/*
	if(check_energy()==0)
	{
		printf("You stumble and fall as your energy is depleted. GAME OVER");
	}*/
	return 0;
}
