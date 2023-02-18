papaku@mailfence.com
je voudrais dix exercisse d'entrainement aux pointeurs dans le langage c
Bien sûr, je peux vous donner dix exercices d'entraînement pour les pointeurs en C :

Écrivez un programme qui alloue un bloc de mémoire pour un entier et affiche la valeur de l'entier avant et après l'avoir modifié à l'aide d'un pointeur.

Écrivez un programme qui alloue de la mémoire pour un tableau d'entiers et utilise des pointeurs pour itérer à travers le tableau et afficher chaque élément.

Écrivez un programme qui utilise des pointeurs pour échanger les valeurs de deux variables.

Écrivez un programme qui alloue de la mémoire pour une structure et utilise des pointeurs pour accéder et modifier les champs de la structure.

Écrivez un programme qui alloue de la mémoire pour une chaîne de caractères et utilise des pointeurs pour concaténer deux chaînes de caractères.

Écrivez un programme qui alloue de la mémoire pour une matrice de nombres réels et utilise des pointeurs pour itérer à travers la matrice et afficher chaque élément.

Écrivez un programme qui alloue de la mémoire pour une liste chaînée et utilise des pointeurs pour ajouter et supprimer des éléments de la liste.

Écrivez un programme qui utilise des pointeurs pour inverser l'ordre des éléments d'un tableau d'entiers.

Écrivez un programme qui utilise des pointeurs pour trouver le minimum et le maximum d'un tableau d'entiers.

Écrivez un programme qui alloue de la mémoire pour une arborescence et utilise des pointeurs pour parcourir l'arborescence en profondeur et en largeur pour afficher les valeurs de chaque nœud.

J'espère que ces exercices vous aideront à améliorer vos compétences en pointeurs en C.



 solutions de ces exercices :


#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int value = 10;
  int *ptr = &value;

  printf("Value before modification: %d\n", value);
  *ptr = 20;
  printf("Value after modification: %d\n", value);

  return 0;
}







c
Copy code
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int array[5] = {1, 2, 3, 4, 5};
  int *ptr;
  int i;

  ptr = array;

  for (i = 0; i < 5; i++) {
    printf("Array element: %d\n", *ptr);
    ptr++;
  }

  return 0;
}




cpp
Copy code
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int a = 5, b = 10;

  printf("Before swap: a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("After swap: a = %d, b = %d\n", a, b);

  return 0;
}








c
Copy code
#include <stdio.h>
#include <stdlib.h>

struct Person {
  char name[50];
  int age;
};

int main(void) {
  struct Person *ptr;

  ptr = (struct Person *)malloc(sizeof(struct Person));

  printf("Enter name: ");
  scanf("%s", ptr->name);
  printf("Enter age: ");
  scanf("%d", &ptr->age);

  printf("\nDisplaying information:\n");
  printf("Name: %s\n", ptr->name);
  printf("Age: %d\n", ptr->age);

  free(ptr);

  return 0;
}




c
Copy code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char str1[50], str2[50], *str3;
  int length1, length2;

  printf("Enter first string: ");
  scanf("%s", str1);

  printf("Enter second string: ");
  scanf("%s", str2);

  length1 = strlen(str1);
  length2 = strlen(str2);

  str3 = (char *)malloc(length1 + length2 + 1);

  strcpy(str3, str1);
  strcat(str3, str2);

  printf("\nConcatenated string: %s\n", str3);

  free(str3);

  return 0;
}


