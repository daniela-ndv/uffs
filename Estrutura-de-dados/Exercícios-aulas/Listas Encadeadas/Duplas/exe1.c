/* Crie uma lista e o primeiro funcionário da lista, considerando as estruturas indicadas;
Adicione um segundo funcionário no início da lista;
Crie uma função capaz de imprimir todos os funcionários; */

#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;
 
typedef struct funcionario{
  int id;
  char nome[41];
  double salario;
  Data nascimento;
  struct funcionario *prev;
  struct funcionario *next;
} Funcionario; 

Funcionario* adicionarFunc(Funcionario *lista, Funcionario *f){
    if(lista == NULL){
        lista = f;
        return lista;
    }

    f->next = lista;
    lista->prev = f;

    return f;
}

void imprimirFuncs(Funcionario *lista){
    int cont = 1;
    for(Funcionario *i = lista; i != NULL; i = i->next){
        printf("\n##### Funcionário %d #####\n", cont);
        printf("ID: %d\n", i->id);
        printf("Nome: %s\n", i->nome);
        printf("Salário: %.2f\n", i->salario);
        printf("Data de nascimento: %d/%d/%d\n", i->nascimento.dia, i->nascimento.mes, i->nascimento.ano);
        cont++;
    }
}

int main(void){

    Funcionario f1, f2;

    f1.id = 1;
    strcpy(f1.nome, "Fulano da Silva");
    f1.salario = 2500.00;
    f1.nascimento.dia = 6;
    f1.nascimento.mes = 7;
    f1.nascimento.ano = 2004;   
    f1.next = NULL;
    f1.prev = NULL;

    f2.id = 2;
    strcpy(f2.nome, "Beltrano de tal");
    f2.salario = 3000.00;
    f2.nascimento.dia = 31;
    f2.nascimento.mes = 1;
    f2.nascimento.ano = 1976;   
    f2.next = NULL;

    Funcionario *funcionarios = &f2;

    funcionarios = adicionarFunc(funcionarios, &f1);
    imprimirFuncs(funcionarios);

    //free(funcionarios); 
    return 0;
}