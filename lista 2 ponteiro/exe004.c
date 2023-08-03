#include <stdio.h>

void soma(float *ptra, float *ptrb){
    *ptra = *ptra + *ptrb;
}

int main(){
    float a, b;
    
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    soma(&a, &b);

    printf("Soma : %.2f\na: %f\nb: %f", a, a, b);
}