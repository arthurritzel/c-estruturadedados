#include <stdio.h>

int tet(int n, int n2, int x, int x1){
    n2 = n;
    int cont = 0;
    if(0 != n){
        while(x < n){
            while (x1 < n2){  
                printf("*");
                x1++;
                cont++;
            }
            printf("\n");
            x1 = 0;
            n2 = n2 - 1;
            x++;
        }
        printf("\n");
        return (cont + tet(n -= 1, n2 = n, x = 0, x1 = 0));
    }else{
        return 0;
    }
    
    
}

int main(){
    int n, n2, x = 0, x1 = 0;
    printf("Digite um numero inteiro: ");
    scanf("%i", &n);
    printf("%i", tet(n, n2, x, x1));
}