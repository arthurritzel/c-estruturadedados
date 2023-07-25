#include <stdio.h>

int fatorial(int n){
    if (n == 1){
        return 1;
    }else{
        return (n * fatorial(n-1));
    }
}

int main(){
    int n;
    printf("Digite um valor: ");
    scanf("%i", &n);
    printf("%i! = %i", n, fatorial(n));
}