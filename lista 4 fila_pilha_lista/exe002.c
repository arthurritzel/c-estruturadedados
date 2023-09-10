#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



int main(){
    lista* inicio = criarlista();
    int esc;
    do{
        printf("\nDefina sua acao\n1- adicionar elemento\n2-Remover elemento\n3-sair\n->");
        scanf("%i", &esc);

        switch (esc)
        {
        case 1:
            inserenoinicio(inicio);
            exibelista(inicio);
            break;
        case 2:
            removeinicio(inicio);
            exibelista(inicio);
            break;
        default:
            break;
        }
    }while(esc != 3);
    liberar(inicio);
}