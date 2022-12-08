#include <stdio.h>
#include <string.h>
#include "player.h"



player create(void)
{

	player p;
	
	strcpy(p.name, "unknomn");
	p.level =1;


	return p;
}



void say(player p, char *message)
{
	printf("%s : %s\n",p.name, message);
}































