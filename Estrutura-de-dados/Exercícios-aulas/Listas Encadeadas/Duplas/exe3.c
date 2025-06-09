/* Implemente uma função que receba um vetor de valores inteiros com N elementos e construa uma lista 
duplamente encadeada armazenando os elementos do vetor (elemento a elemento). Assim, se for recebido por parâmetro 
o vetor v[4] = {1,21,4,6} a função deve retornar uma lista encadeada em que o primeiro elemento é ‘1’, o segundo o ‘21’, 
o terceiro o ‘4’ e assim por diante. A função deve ter a seguinte assinatura: 
ListaInt *constroiLista (int n, int *v);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListaInt {
    int valor;
    struct ListaInt *prev;
    struct ListaInt *next;
} ListaInt;

ListaInt *constroiLista(int n, int *v){
    if(v == NULL){
        return NULL;
    }

    ListaInt *lista = NULL;
    ListaInt *ultimo = NULL;

    for(int i = 0; i < n; i++){
        ListaInt *novo = (ListaInt*)malloc(sizeof(ListaInt));

        novo->valor = v[i];
        novo->next = NULL;
        novo->prev = ultimo;

        if(ultimo != NULL) {
            ultimo->next = novo;
        } else {
            lista = novo; 
        }

        ultimo = novo;
    }

    return lista;
}

void imprimirLista(ListaInt *lista){
    for(ListaInt *i = lista; i != NULL; i = i->next){
        printf("%d, ", i->valor);
    }
    printf("\n");
}

int main(void) {

    int n;    

    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));

    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", &v[i]);
    } 
    printf("\n");

    ListaInt *l = constroiLista(n, v);

    printf("Elementos da lista: ");
    imprimirLista(l);

    return 0;
}