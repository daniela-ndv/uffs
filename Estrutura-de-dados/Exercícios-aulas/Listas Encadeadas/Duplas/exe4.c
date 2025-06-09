/* Crie uma função de busca que apresenta (imprime na tela) as informações de um funcionário. 
A busca deve ser feita utilizando o id.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

Funcionario lerFuncionario(){
    Funcionario f;

    printf("ID: ");
    scanf("%d", &f.id);

    getchar();
    printf("Nome: ");
    fgets(f.nome, sizeof(f.nome), stdin);

    // Remova a quebra de linha
    size_t len = strlen(f.nome);
    if (len > 0 && f.nome[len - 1] == '\n') {
        f.nome[len - 1] = '\0'; // Substitua a nova linha por um caractere nulo
    }

    printf("Salário: ");
    scanf("%lf", &f.salario);

    printf("Data de nascimento: ");
    scanf("%d/%d/%d", &f.nascimento.dia, &f.nascimento.mes, &f.nascimento.ano);
    printf("\n");

    f.next = NULL;
    return f;
}

Funcionario* adicionarFunc(Funcionario *lista, Funcionario *novo){
    novo->next = NULL;
    novo->prev = NULL;

    if(lista == NULL){
        return novo;
    }

    Funcionario *ultimo = lista;

    while(ultimo->next != NULL){
        ultimo = ultimo->next;
    }

    ultimo->next = novo;
    novo->prev = ultimo;

    return lista;
}

Funcionario* buscarById(Funcionario *lista, int id){
    Funcionario *atual = lista;

    while(atual != NULL) {
        if(atual->id == id) {
          return atual;
        }
        atual = atual->next;
    }
    printf("\nID não encontrado!\n");
    return NULL;
}

void imprimirFuncionario(Funcionario *f){
    printf("***************************************\n");
    printf("ID: %d\n", f->id);
    printf("Nome: %s\n", f->nome);
    printf("Salário: %.2f\n", f->salario);
    printf("Data de nascimento: %d/%d/%d\n", f->nascimento.dia, f->nascimento.mes, f->nascimento.ano);
    printf("***************************************\n");
}

void imprimirLista(Funcionario *lista){
    if(lista == NULL){
        printf("Lista vazia\n");
    }

    int cont = 1;
    for(Funcionario *i = lista; i != NULL; i = i->next){
        printf("\n-> Funcionário %d\n", cont);
        printf("ID: %d\n", i->id);
        printf("Nome: %s\n", i->nome);
        printf("Salário: %.2f\n", i->salario);
        printf("Data de nascimento: %d/%d/%d\n", i->nascimento.dia, i->nascimento.mes, i->nascimento.ano);
        cont++;
    }
}

int main(void){

    int op, id;

    printf("Números de registros: ");
    scanf("%d", &op);

    Funcionario *funcionarios = NULL;

    for(int i = 0; i < op; i++){
        Funcionario *f = (Funcionario*)malloc(sizeof(Funcionario));
        *f = lerFuncionario();

        funcionarios = adicionarFunc(funcionarios, f);
    }

    printf("##### Imprimindo lista ... #####\n");
    imprimirLista(funcionarios);

    printf("\nID para buscar: ");
    scanf("%d", &id);

    printf("\nResultado da busca: \n");

    Funcionario *func = buscarById(funcionarios, id);

    if(func != NULL){
        imprimirFuncionario(func);
    }

    return 0;
}