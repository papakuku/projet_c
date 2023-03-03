#include <stdio.h>
#include <stdlib.h>




int main (void)
{


    float a,b,c,d ;
   

    printf("entre a:");
    scanf("%f",&a);
    printf("entre b:");
    scanf("%f",&b);
    printf("entre c:");
    scanf("%f",&c);


    d =( a + b + c )/3;

    printf("%.2f",d);

    if ( d >10)
    {
       printf("Bravo !\n");
    }
    else 
    {
        printf("peut mieux faire");
    }
















    return 0;
}
