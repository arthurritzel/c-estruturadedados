#include <stdio.h>

int pot(int n, int x){
    if (x == 0){
        return 1;
    }else{
        return(n * pot(n, x - 1));
    }
}

int main(){
    int n, x;
    printf("Digite o valor de n: ");
    scanf("%i", &n);
    printf("Digite o valor de x: ");
    scanf("%i", &x);
    printf("%i elevado a %i e igual a %i", n, x, pot(n, x));
}