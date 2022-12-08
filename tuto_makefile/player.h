#ifndef _PLAYER_H_
#define _PLAYER_H_




	typedef struct player
	{
		char name[26];
		int level;
	}player;






	player create(void);
	void say(player p, char *message);

	

#endif










































