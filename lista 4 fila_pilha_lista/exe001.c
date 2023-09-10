#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    lista* inicio = criarlista();
    int esc, removeu, num;
    do{
        printf("\nDefina sua acao\n1- adicionar elemento\n2-Remover elementos\n3-exibir lista\n4-sair\n->");
        scanf("%i", &esc);

        switch (esc)
        {
        case 1:
            inserenoinicio(inicio);
            break;
        case 2:
            printf("Digite o numero: ");
            scanf("%i", &num);
            do{
                removeu = removeElementosIguais(inicio, num);
            } while (removeu);
            break;
        case 3:
            exibelista(inicio);
            break;
        default:
            break;
        }
    }while(esc != 4);
    liberar(inicio);
}