#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet = NULL, esc, cont = 0;
    while (1){
        printf("Deseja acrescntar um numero ao vetor?\n1-sim\n2-nao\n-> ");
        scanf("%i", &esc);
        if (esc == 1){
            if (cont == 0){
                vet = (int*) malloc(sizeof(int));
            }else{
                vet = (int*)realloc(vet, sizeof(int));
            }
            printf("Digite o novo valor\n->");
            scanf("%i", &vet[cont]);
            cont++;
        }else{
            break;
        }
    }

    for (int i = 0; i < cont; i++){
        printf("%i\n", vet[i]);
    }
    
    
}