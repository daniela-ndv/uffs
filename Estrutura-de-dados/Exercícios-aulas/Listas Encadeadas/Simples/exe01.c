/* Crie as estruturas indicadas, e crie o primeiro funcionário da lista encadeada;
Adicione um segundo funcionário mantendo o encadeamento;
Crie uma função que receba o ponteiro inicial da lista e imprima todos os elementos (funcionários) */

#include <stdio.h>
#include <string.h>

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

    for(Funcionario *i = lista; i != NULL; i = i->next){
        printf("ID: %d\n", i->id);
        printf("Nome: %s\n", i->nome);
        printf("Salário: %.2lf\n", i->salario);
        printf("Data de nascimento: %d/%d/%d\n", i->dataNascimento.dia, i->dataNascimento.mes, i->dataNascimento.ano);
        printf("\n");
    }
}

int main(void){

    Funcionario f1, f2;
    Funcionario *funcionarios;

    f1.id = 123;
    strcpy(f1.nome, "Fulano de Tal");
    f1.salario = 3500.52;
    f1.dataNascimento.dia = 6;
    f1.dataNascimento.mes = 7;
    f1.dataNascimento.ano = 2004;
    f1.next = NULL;

    f2.id = 456;
    strcpy(f2.nome, "Ciclano Beltrano");
    f2.salario = 6000;
    f2.dataNascimento.dia = 31;
    f2.dataNascimento.mes = 1;
    f2.dataNascimento.ano = 1976;
    f2.next = NULL;

    funcionarios = &f1;

    f1.next = &f2;

    imprimeLista(funcionarios);

    return 0;
}