#include <stdio.h>

int russa(int a, int b, int *ptsoma){
    if(a % 2 == 1){
        *ptsoma += b;
        printf(" %i %i  %i \n", a, b, *ptsoma);
        
    }else{
            printf(" %i %i  - \n", a, b);
    }

    if(a <= 1){
        return 1;
    }else{
        return (russa(a / 2, b * 2, ptsoma));
    }
}

int main(){
    int a, b, soma = 0;
    printf("Digite o valor de a: ");
    scanf("%i", &a);
    printf("Digite o valor de b: ");
    scanf("%i", &b);
    printf(" A|B| Parcelas\n");
    russa(a, b, &soma);

    printf("\nValor final: %i\n", soma);
}