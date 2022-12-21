#if !defined(__EXO6__)
#define __EXO6__

//-------------------------------------------------------------------------------------------

//macros pour la taille de l'espace de jeu
	#define MAX_ROWS 5
	#define MAX_COLS 12

//-------------------------------------------------------------------------------------------

	#define MAX_I MAX_ROWS * 2
	#define MAX_J MAX_COLS * 2



//-------------------------------------------------------------------------------------------


//Prototype des fonctions

	void gameManager(void);
	void initArea(char gameArea[][MAX_J],int *playerI,int *playerJ);
	void showArea(char gameArea[][MAX_J]);
	void showMenu(char *moveComand);
	void updateArea(char gameArea[][MAX_J],char *moveComand,int *playerI,int *playerJ);
	void moveUp(char gameArea[][MAX_J],int *playerI,int *playerJ);
	void moveDown(char gameArea[][MAX_J],int *playerI,int *playerJ);
	void moveLeft(char gameArea[][MAX_J],int *playerI,int *playerJ);
	void moveRight(char gameArea[][MAX_J],int *playerI,int *playerJ);

	void flushBuffer(void);




#endif