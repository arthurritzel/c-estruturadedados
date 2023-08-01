#include <stdio.h>

int main(){
    int a;
     int *ptra;
    float b;
     float *ptrb;
    char c;
     char *ptrc;

    ptra = &a;
    ptrb = &b;
    ptrc = &c;
    
    printf("Digite o valor de a: ");
    scanf("%i", ptra);
    printf("Digite o valor de b: ");
    scanf("%f", ptrb);
    fflush(stdin);
    printf("Digite o valor de c: ");
    scanf("%c", ptrc);

    printf("a: %i\n", *ptra);
    printf("b: %f\n", *ptrb);
    printf("c: %c\n\n", *ptrc);

    *ptra += 1;
    *ptrb += 2;
    *ptrc = 'c';

    printf("a: %i\n", *ptra);
    printf("b: %f\n", *ptrb);
    printf("c: %c\n", *ptrc);

}