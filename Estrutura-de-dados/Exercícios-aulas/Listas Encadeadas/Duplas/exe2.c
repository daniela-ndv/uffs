/* Considerando a estrutura proposta no exercício anterior, faça as seguintes adaptações em seu programa:
O programa deve ler (do teclado) um inteiro N que representará o número de registros que o usuário irá inserir. 
Após a leitura seu programa deve ler os dados dos N registros e os inserir no final na lista encadeada. 
Imprima a lista para ver se todos os elementos estão presentes
Faça uma função que deleta um funcionário. A função deve receber como parâmetro a lista, 
e o id do funcionário a ser deletado, e deve retornar o first elemento da lista*/

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

Funcionario* deletarById(Funcionario *lista, int id){
    Funcionario *atual = lista;

    while(atual != NULL) {
        if (atual->id == id) {
            // Se for o primeiro nó
            if (atual->prev == NULL) {
                lista = atual->next;
                if (lista != NULL)
                    lista->prev = NULL;
            } else {
                atual->prev->next = atual->next;
                if (atual->next != NULL)
                    atual->next->prev = atual->prev;
            }
            free(atual);
            return lista;
        }
        atual = atual->next;
    }
    printf("ID não encontrado!\n");
    return lista;
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

    printf("\nID para deletar: ");
    scanf("%d", &id);

    funcionarios = deletarById(funcionarios, id);
    printf("##### Imprimindo lista ... #####\n");
    imprimirLista(funcionarios);

    return 0;
}