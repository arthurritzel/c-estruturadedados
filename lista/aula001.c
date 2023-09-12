#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node;
typedef node *lista;


lista* criarlistta(){
    lista *inicio = (lista*) malloc(sizeof(lista));
    if (inicio != NULL){
        *inicio = NULL;
    }else{
        printf("Erro na alocaçãooo");
    }
    return inicio;
}

int inserenoinicio(lista *inicio){
    node *novo = (node*) malloc(sizeof(node));
    if(novo == NULL){
        printf("Erro na alocação");
        return 0;
    }else{
        printf("Digite o valor: ");
        scanf("%i", &novo->num);
        novo->prox = (*inicio);
        *inicio = novo;

    }
}

int inserenofinal(lista *inicio){
    node *novo = (node*)malloc(sizeof(node));
    if(novo == NULL){
        printf("Erro na alocacao");
        return 0;
    }else{
        if((*inicio) == NULL){
            *inicio = novo;
        }else{
            node *temp;
            temp = (*inicio);
            while (temp->prox != NULL){
                temp = temp->prox;
            }
            temp->prox = novo;
            novo->prox = NULL;
        }
        printf("Digite o valor: ");
        scanf("%i", &novo->num);
    }
}

void exibelista(lista*inicio){
    
    if(*inicio == NULL){
        printf("Lista vazia");
    }else{
        node *temp;
        temp = (*inicio);

        while (temp != NULL){
            printf("%i\n", temp->num);
            temp = temp->prox;
        }
    }
}

void liberar(lista* inicio){
    if ((*inicio) == NULL){
        printf("Lista vazia");
    }else{
        node *temp;
        while ((*inicio) == NULL){
            temp = *inicio;
            *inicio = (*inicio)->prox;
            free(temp);
        }
    }
    
}

void removeinicio(lista* inicio){
    if ((*inicio) != NULL){
        node *temp;
        temp = (*inicio);
        *inicio = temp -> prox;
        free(temp);
        printf("Elemento removio\n");
    }else{
        printf("Lista vazia");
    }
}

void removeFinal(lista* inicio){
    node *antTemp, *temp;
    temp = (*inicio);
    if (((*inicio) != NULL) && (temp -> prox) == NULL){
        *inicio = NULL;
        free(temp);
    }else if((*inicio) != NULL){
        while (temp->prox != NULL){
            antTemp = temp;
            temp = temp->prox;
        }
        antTemp->prox = NULL;
        free(temp);
        printf("Elemento removido\n");
    }else{
        printf("Lista vazia");
    }
    
}

void ordenar(lista *inicio){
    node *temp;

    int flag = 0, aux;

    if (((*inicio) != NULL) && (temp -> prox) == NULL){

        printf("Nao a nada a ordenar");
    }else if((*inicio) != NULL){

        do{
            flag = 0;
            temp = (*inicio);
            while (temp->prox != NULL){

                if (temp->num > temp->prox->num){

                    aux = temp->prox->num;
                    temp->prox->num = temp->num;
                    temp->num = aux;
                    flag = 1;
                    
                }
                temp = temp->prox;
            }
        }while (flag == 1);
        
    }else{
        printf("Lista vazia");
    }
    
}

void removeElemento(lista* inicio){
    int num, flag = 0;
    node *ant, *temp;
    if ((*inicio) == NULL){
        printf("\nLista vazia\n");
    }else {
        printf("Digite o numero: ");
        scanf("%i", &num);
        if((*inicio)->num == num){
            temp = (*inicio);
            *inicio = (*inicio)->prox;
            free(temp);
            flag = 1;
        }else{
            temp = (*inicio);
            ant = temp;
            while (temp != NULL){
                if (num == temp->num){
                    ant->prox = temp->prox;
                    free(temp);
                    flag = 1;
                    break;
                }
                ant = temp;
                temp = temp->prox;
            }
        }
        if (flag == 0){
            printf("\nNumero nao encontrado na lista\n");
        }
        
    }
    
}

void insereOrdenado(lista *inicio){
    int flag = 0;
    node *temp;
    node *novo = (node*)malloc(sizeof(node));
    printf("Digite o novo valor: ");
    scanf("%i", &novo->num);

    temp = (*inicio);

    if ((*inicio) == NULL || (*inicio)->num > novo->num){
        novo->prox = (*inicio);
        *inicio = novo;
    }else{
        while (temp->prox != NULL){
            
            if (temp->prox->num > novo->num){
                
                novo->prox = temp->prox;
                temp->prox = novo;
                flag = 1;
                break;
            }
            temp = temp->prox;
        }
        
        if(flag == 0){
            
            temp->prox = novo;
            novo->prox = NULL;
        }   
    }
}

int main(){
    lista* inicio = criarlistta();
    int esc;
    int very = 0;
    
    do{
        
        printf("escolha sua acao\n1-inserir inicio\n2-insere final\n3-remove inicio\n4-remove final\n5-exibe lista\n6-ordenar\n7-Insere ordenado\n8-Remover elemento\n->");
        scanf("%i", &esc);
        switch (esc){
        case 1:
            system("clear");
            inserenoinicio(inicio);
            break;
        case 2:
            system("clear");
            inserenofinal(inicio);
            break;
        case 3:
            system("clear");
            removeinicio(inicio);
            break;
        case 4:
            system("clear");
            removeFinal(inicio);
            break;
        case 5:
            system("clear");
            exibelista(inicio);
            break;
        case 6:
        system("clear");
            ordenar(inicio);
            break;
        case 7:
            system("clear");
            insereOrdenado(inicio);
            break;
        case 8:
            system("clear");
            removeElemento(inicio);
        }
    }while (very != 1);
    liberar(inicio);
}