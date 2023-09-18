#include <stdio.h>

void somar(int *n1, int *n2, int *soma){
    *n1 += 5;
    *n2 += 5;
    *soma = *n1 + *n2;
}

int main(){
    int n1, n2, soma = 0;
    printf("Digite o valor de n1 ");
    scanf("%i", &n1);
    printf("Digite o valor de n2 ");
    scanf("%i", &n2);

    somar(&n1, &n2, &soma);

    printf("%i", soma);
}