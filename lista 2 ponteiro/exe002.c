#include <stdio.h>

int main(){
    int a, b;
    printf("Digite o valor de a: ");
    scanf("%i", &a);
    printf("Digite o valor de b: ");
    scanf("%i", &b);

    if (&a > &b){
        printf("maior endereco: a: %x", &a);
    }else{
        printf("maior endereco b: %x", &b);
    }
    
}