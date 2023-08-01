#include <stdio.h>

int main(){
    int a, b;
    printf("Digite o valor de a: ");
    scanf("%i", &a);
    printf("Digite o valor de b: ");
    scanf("%i", &b);

    if (&a > &b){
        printf("variavel com maior endereco: a: %i", a);
    }else{
        printf("variavel com maior endereco b: %i", b);
    }
    
}