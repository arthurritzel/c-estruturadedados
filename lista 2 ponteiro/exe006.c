#include <stdio.h>

void frac(float num, float *fra, int *inteiro){
    *inteiro = num;
    *fra = num - *inteiro;
}

int main(){
    float num, fra;
    int inteiro;
    printf("Digite um numero com virgula: ");
    scanf("%f", &num);

    frac(num, &fra, &inteiro);
    printf("parte inteira: %i\nparte fracionaria: %.2f", inteiro, fra);
}