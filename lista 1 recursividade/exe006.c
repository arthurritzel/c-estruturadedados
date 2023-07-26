#include <stdio.h>

int soma(int num){
    int num_aux;
    if(num < 10){
        return num;
    }else{
        num_aux = num % 10;
        num = num / 10;
        return num_aux + soma(num);
    }
}

int main(){
    int num, n2;
    printf("Digite um numero inteiro");
    scanf("%i", &num);
    n2 = soma(num);
    printf("A soma dos digitos é %i", n2);
}