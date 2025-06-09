/* Faça o que se pede: 
- Exluir um elemento ao final da lista
- Exluir um elemento no começo da lista
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 50

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct funcionario{
    int id;
    char nome[TAM_NOME+1];
    double salario;
    Data dataNascimento;
    struct funcionario *next;
} Funcionario; 

void imprimeLista(Funcionario *lista){
    if(lista == NULL){
      printf("Lista Vazia\n");
    } else {
        for(Funcionario *i = lista; i != NULL; i = i->next){
            printf("ID: %d\n", i->id);
            printf("Nome: %s\n", i->nome);
            printf("Salário: %.2lf\n", i->salario);
            printf("Data de nascimento: %d/%d/%d\n", i->dataNascimento.dia, i->dataNascimento.mes, i->dataNascimento.ano);
            printf("\n");
        }
    }
}

Funcionario* removerUltimo(Funcionario *lista){
    
    if (lista == NULL) {
        return NULL;
    }

    if (lista->next == NULL) {
        free(lista);
        return NULL;
    }

    Funcionario *anterior = NULL;
    Funcionario *atual = lista;

    // Percorre até o penúltimo nó
    while (atual->next != NULL) {
        anterior = atual;
        atual = atual->next;
    }

    anterior->next = NULL;
    free(atual);

    return lista;
}

Funcionario* removerPrimeiro(Funcionario *lista){

    if (lista == NULL) {
        return NULL;
    }

    if (lista->next == NULL) {
        free(lista);
        return NULL;
    }

    Funcionario *atual = lista;
    lista = lista->next;

    free(atual);

    return lista;
}

int main (void){

    Funcionario *lista;
    Funcionario *f1, *f2, *f3, *f4;
    
    f1 = (Funcionario *)malloc(sizeof(Funcionario));
    f1->id = 1;
    strcpy(f1->nome, "Fulano de Tal");
    f1->salario = 3800.53;
    f1->dataNascimento.dia = 1;
    f1->dataNascimento.mes = 1;
    f1->dataNascimento.ano = 1111;
    f1->next = NULL;
    
    f2 = (Funcionario *)malloc(sizeof(Funcionario));
    f2->id = 2;
    strcpy(f2->nome, "Beltrano Xxx");
    f2->salario = 2400;
    f2->dataNascimento.dia = 2;
    f2->dataNascimento.mes = 2;
    f2->dataNascimento.ano = 2222;
    f2->next = NULL;

    f3 = (Funcionario *)malloc(sizeof(Funcionario));
    f3->id = 3;
    strcpy(f3->nome, "Ciclano Zzz");
    f3->salario = 4200;
    f3->dataNascimento.dia = 3;
    f3->dataNascimento.mes = 3;
    f3->dataNascimento.ano = 3333;
    f3->next = NULL;

    // Lista com dois elementos
    lista = f1;
    f1->next = f2;
    f2->next = f3;

    printf("Imprimindo lista original ... \n");
    imprimeLista(lista);

    printf("Excluir no final da lista: \n");
    lista = removerUltimo(lista);
    printf("Imprimindo lista ... \n");
    imprimeLista(lista);

    printf("Excluir no início da lista: \n");
    lista = removerPrimeiro(lista);
    printf("Imprimindo lista ... \n");
    imprimeLista(lista);

    return 0;
}