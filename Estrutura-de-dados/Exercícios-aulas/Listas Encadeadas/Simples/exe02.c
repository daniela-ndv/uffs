/* Considerando a estrutura proposta no exercício anterior, faça as seguintes adaptações em seu programa:
- O programa deve ler (do teclado) vários registros de funcionários (quando id for igual a 0 a entrada é finalizada).
- Use a mesma função implementada anteriormente e imprima a lista para ver se todos os elementos estão presentes
- Crie uma função para desalocar a memória de todas as instâncias de funcionário (nós da lista). 
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

Funcionario* lerFuncionario(){
    
    Funcionario *f = (Funcionario*)malloc(sizeof(Funcionario));

    printf("ID: ");
    scanf("%d", &f->id);

    if(f->id == 0){
        free(f);
        return NULL;
    }

    getchar();
    printf("Nome: ");
    fgets(f->nome, sizeof(f->nome), stdin);

    // Remova a quebra de linha
    size_t len = strlen(f->nome);
    if (len > 0 && f->nome[len - 1] == '\n') {
        f->nome[len - 1] = '\0'; // Substitua a nova linha por um caractere nulo
    }

    printf("Salário: ");
    scanf("%lf", &f->salario);

    printf("Data de nascimento: ");
    scanf("%d/%d/%d", &f->dataNascimento.dia, &f->dataNascimento.mes, &f->dataNascimento.ano);
    printf("\n");

    f->next = NULL;
    return f;
}

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
        printf("\n");
    }
}

Funcionario* desalocaLista(Funcionario *lista){

  Funcionario *aux = NULL;
  while(lista != NULL){
      aux = lista;
      lista = aux->next;
      free(aux);
  }
  return NULL; 
}

int main(void){

    Funcionario *lista = NULL;
    Funcionario *f = NULL;
    Funcionario *aux = NULL; 

    while (1) {
        f = lerFuncionario();
        if(f == NULL){
            printf("Encerrando...\n");
            break;
        } 

        if(lista == NULL){
            lista = f;
            aux = f;
        } else {
            aux->next = f;
            aux = f;
        }
    }
    
    printf("\n##### Lista de funcionários: #####\n");
    imprimeLista(lista);

    lista = desalocaLista(lista);

    imprimeLista(lista);

    return 0;
}