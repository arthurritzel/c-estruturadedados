#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    lista* inicio = criarlista();
    int esc, qtn_nos = 1, remove_nos;

    do{
        printf("\nDefina sua acao\n1- adicionar elemento\n2-Remover quantidade de elementos\n3-sair\n->");
        scanf("%i", &esc);

        switch (esc)
        {
        case 1:
            inserenoinicio(inicio);
            exibelista(inicio);
            qtn_nos++;
            break;
        case 2:
            printf("Digite a quanitdade de nos que quer remover: ");
            scanf("%i", &remove_nos);

            if(remove_nos < qtn_nos){
                for (int i = 0; i < remove_nos; i++){
                    removeinicio(inicio);
                    qtn_nos--;
                }
            }else{
                for (int j = 0; j <= qtn_nos; j++){
                    removeinicio(inicio);
                    qtn_nos--;
                }
            }
            exibelista(inicio);
            break;
        default:
            break;
        }
    }while(esc != 3);
    liberar(inicio);
}