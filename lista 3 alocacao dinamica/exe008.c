#include <stdio.h>
#include <stdlib.h>
// Crie um programa que declare uma estrutura (struct) para o cadastro de alunos.
// a) Deverão ser armazenados, para cada aluno: matrícula, sobrenome (apenas um) e ano de
// nascimento;
// b) Ao início do programa, o usuário deverá informar o número de alunos que serão armazenados;
// c) O programa deverá alocar dinamicamente a quantidade necessária de memória para armazenar
// os registros dos alunos;
// d) O programa deverá pedir ao usuário que entre com as informações dos alunos;
// e) Ao final, mostrar os dados armazenados e liberar a memória alocada.
int main(){
    struct dados{
        int matricula, ano;
        char nome[30], sobrenome[30];
    }*alunos;
    int n;
    printf("Digite a quantidade de alunos que serao cadastrados: ");
    scanf("%i", &n);
    alunos = (struct dados *)malloc(n * sizeof(struct dados));

    for (int i = 0; i < n; i++){
        fflush(stdin);
        printf("Aluno %i\n", i+1);
        printf("Digite o nome: ");
        gets(alunos[i].nome);
        fflush(stdin);
        printf("Digite o sobrenome: ");
        gets(alunos[i].sobrenome);
        fflush(stdin);
        printf("Digite a matricula: ");
        scanf("%i", &alunos[i].matricula);
        printf("Digite o ano de nascimento: ");
        scanf("%i", &alunos[i].ano);
        printf("\n-----------------\n\n");
    }
    for (int i = 0; i < n; i++){
        printf("Aluno %i\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Sobrenome: %s\n", alunos[i].sobrenome);
        printf("Matricula: %i\n", alunos[i].matricula);
        printf("Ano nascimento: %i\n", alunos[i].ano);
        printf("\n-----------------\n\n");
    }
    free(alunos);

}