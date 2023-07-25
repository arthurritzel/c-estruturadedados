#include <stdio.h>
int mult(int n1, int n2){
    if (n2 == 0){
        return 0;
    }else{
        return(n1 + mult(n1, n2 - 1));
    }
    
}
int main(){
    int n1, n2;
    printf("Digite o primeiro valor: ");
    scanf("%i", &n1);
    printf("Digite o segundo valor: ");
    scanf("%i", &n2);
    printf("%i X %i = %i", n1, n2, mult(n1, n2));
}