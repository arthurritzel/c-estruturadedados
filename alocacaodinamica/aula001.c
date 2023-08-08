#include <stdio.h>

int main(){
    float x = 0;
    x = sizeof(int);
    printf("Tamanho inteiro: %f\n", x);
    x = sizeof(float);
    printf("Tamanho float: %f\n", x);
    x = sizeof(double);
    printf("Tamanho double: %f\n", x);
    x = sizeof(char);
    printf("Tamanho char: %f\n", x);

}