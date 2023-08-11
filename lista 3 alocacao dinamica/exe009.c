#include <stdio.h>
#include <stdlib.h>
// Considere um cadastro de produtos de um estoque, com as seguintes informações para cada produto:
// Código de identificação do produto: representado por um valor inteiro Nome do produto: com até 50 caracteres
// Quantidade disponível no estoque: representado por um número inteiro Preço de venda: representado por um valor real
// Defina uma estrutura, denominada produto, que tenha os campos apropriados para guardar as informações de um produto;
// Aloque inicialmente memória para 1 produto e deixe a critério do usuário (realloc) a inserção de mais unidades do mesmo;
// Encontre o produto com o maior preço de venda;
// Encontre o produto com a maior quantidade disponível no estoque.
int main(){
    struct dados{
        int id, estoque;
        float preco;
        char nome[50]
    }*prod;

    prod = (struct dados *)malloc(1 * sizeof(struct dados));

    int cont = 1, esc, maiore;
    float maiorp;
    printf("Cadastre o primerio produto!\n\n");
    printf("ID: ");
    scanf("%i", &prod[0].id);
    printf("Nome: ");
    fflush(stdin);
    gets(prod[0].nome);
    printf("Preco: ");
    scanf("%f", &prod[0].preco);
    printf("Quantidade no estoque: ");
    scanf("%i", & prod[0].estoque);
    while (1){
        printf("Deseja cadastrar outro produto?\n[1]-Sim\n[2]-Nao\n->");
        scanf("%i", &esc);
        if (esc == 1){
            prod = (struct dados *)realloc(prod, (cont+1) * sizeof(struct dados));
            printf("\nID: ");
            scanf("%i", &prod[cont].id);
            printf("Nome: ");
            fflush(stdin);
            gets(prod[cont].nome);
            fflush(stdin);
            printf("Preco: ");
            scanf("%f", &prod[cont].preco);
            printf("Quantidade no estoque: ");
            scanf("%i", &prod[cont].estoque);
            cont++;
            printf("--------------------\n");
        }else{
            break;
        }
    }
    for (int i = 0; i < cont; i++){
        if (i == 0){
            maiorp = prod[i].preco;
            maiore = prod[i].estoque;
        }
        if (prod[i].preco > maiorp){
            maiorp = prod[i].preco;
        }
        if (prod[i].estoque > maiore){
            maiore = prod[i].estoque;
        }
            
        printf("id: %i\n", prod[i].id);
        printf("nome: %s\n", prod[i].nome);
        printf("preco: %.2f\n", prod[i].preco);
        printf("qtn estoque: %i\n", prod[i].estoque);
        printf("----------------------\n");
    }

    printf("Maior Preco registrado: %.2f\n", maiorp);
    printf("Maior quantidade de estoque registrado: %i", maiore);
}