/* Faça o que se pede: 
- Incluir um elemento ao final da lista
- Incluir um elemento no começo da lista
- Incluir um elemento no meio da lista, antes da posição passada como parâmetro
- Incluir um elemento no meio da lista, depois da posição passada como parâmetro
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
    }
}

Funcionario* adicionarNoFinal(Funcionario *lista, Funcionario *f){
    Funcionario *ultimo;

    if(lista == NULL){
        lista = f;
        return lista;
    }

    for(Funcionario *i = lista; i != NULL; i = i->next){
        ultimo = i;
    }

    ultimo->next = f;

    return lista;
}

Funcionario* adicionarNoInicio(Funcionario *lista, Funcionario *f){
    Funcionario *primeiro = f;

    if(lista == NULL){
        lista = f;
        return lista;
    }

    primeiro->next = lista;

    return primeiro;
}

Funcionario* adicionarNoMeioAntes(Funcionario *lista, Funcionario *f, int posicao) {

    if (posicao <= 1 || lista == NULL) {
        f->next = lista;
        return f;
    }

    Funcionario *anterior = NULL;
    Funcionario *atual = lista;
    int cont = 1;

    while (atual != NULL && cont < posicao) {
        anterior = atual; 
        atual = atual->next; 
        cont++; 
    }

    if (anterior != NULL) {
        anterior->next = f;
        f->next = atual;
    }

    return lista;
}

Funcionario* adicionarNoMeioDepois(Funcionario *lista, Funcionario *f, int posicao){
    if (lista == NULL) {
        f->next = lista;
        return f;
    }

    Funcionario *atual = lista;
    int cont = 1;

    while (atual != NULL && cont < posicao) {
        atual = atual->next; 
        cont++; 
    }

    f->next = atual->next;
    atual->next = f;
    
    return lista;
}

int main (void){

    Funcionario *lista;
    Funcionario *f, *f1, *f2;
    int posicao;
    
    f1 = (Funcionario *)malloc(sizeof(Funcionario));
    f1->id = 1;
    strcpy(f1->nome, "Fulano de Tal");
    f1->salario = 3800.53;
    f1->dataNascimento.dia = 2;
    f1->dataNascimento.mes = 2;
    f1->dataNascimento.ano = 2002;
    f1->next = NULL;
    
    f2 = (Funcionario *)malloc(sizeof(Funcionario));
    f2->id = 2;
    strcpy(f2->nome, "Beltrano Ciclano");
    f2->salario = 2400;
    f2->dataNascimento.dia = 1;
    f2->dataNascimento.mes = 1;
    f2->dataNascimento.ano = 2001;
    f2->next = NULL;

    // Lista com dois elementos
    lista = f1;
    f1->next = f2;

    printf("Elemento para inserir no final da lista: \n");
    f = lerFuncionario();
    lista = adicionarNoFinal(lista, f);
    printf("Imprimindo lista ... \n");
    imprimeLista(lista);

    printf("Elemento para inserir no início da lista: \n");
    f = lerFuncionario();
    lista = adicionarNoInicio(lista, f);
    printf("Imprimindo lista ... \n");
    imprimeLista(lista);

    printf("Elemento para inserir no meio da lista (antes): \n");
    printf("Posição para inserir: ");
    scanf("%d", &posicao);
    f = lerFuncionario();
    lista = adicionarNoMeioAntes(lista, f, posicao);
    printf("Imprimindo lista ... \n");
    imprimeLista(lista);

    printf("Elemento para inserir no meio da lista (depois): \n");
    printf("Posição para inserir: ");
    scanf("%d", &posicao);
    f = lerFuncionario();
    lista = adicionarNoMeioDepois(lista, f, posicao);
    printf("Imprimindo lista ... \n");
    imprimeLista(lista);

    return 0;
}