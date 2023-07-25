#include <stdio.h>

int soma(int n){
    if (n == 0){
        return 0;
    }else{
        return(n + soma(n - 1));
    }
    
}
int main(){
    int n;
    printf("Digite um valor: ");
    scanf("%i", &n);
    printf("O valor da soma dos numeros de 1 a %i é %i", n, soma(n));

}