#include <stdio.h>


int main (void)
{


//ceci est un commentaire
	
/*le commentaire sur plusieur ligne */

//la variable ne peut commencer par un chiffre ,pas de caractere speciaux ,elle peut commencer par un " _ "

float pixDeReservation = 125.99;
int intPrixDeReservation =(int)pixDeReservation;
int aireDuCarre=0;
signed char a = 65;	
signed char b = 'A';
//j'ai declarer ma variable et je l'ai affecte a zero

/*
%d :nombre entier (int)
%f :nombre flottant (float)
%c :caractere (char)
%s :chaine de caracteres (texte)
*/


printf("le nombre est %d ou %.3f.\n",aireDuCarre,pixDeReservation);

const float PI =3.14;
const float TVA = 22.0;
printf("PI = %.2f\n",PI);






return 0;
}

