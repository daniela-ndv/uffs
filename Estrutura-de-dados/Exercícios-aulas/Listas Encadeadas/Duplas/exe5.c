/* Implemente a função void ShowNeighbors(dl *list, int key) que imprima o elemento anterior
e o elemento posterior a posição de memória onde o valor de key esteja armazenado. A lista
apontada por list não possui valores repetidos. Cuidado: atente para os casos em que key esteja na
primeira ou na última posição (ou não exista). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tdl {
    int n;
    struct tdl *prev;
    struct tdl *next;
} dl;

void ShowNeighbors(dl *list, int key){
    bool find = false;

    dl *atual = list;
    
    while(atual != NULL){
        if(atual->n == key){
            find = true;

            if(atual->prev == NULL){
                printf("\nVizinho: %d\n", atual->next->n);
            } else if(atual->next == NULL){
                printf("\nVizinho: %d\n", atual->prev->n);
            } else{
                printf("\nVizinhos: %d e %d\n", atual->prev->n, atual->next->n);
            }  
        } 
        atual = atual->next;
    }   

    if(!find){
        printf("Valor %d não encontrado.\n", key);
    }
}

int main(void){

    int n, qtd;
    dl *list = NULL;
    dl *ultimo = NULL;

    printf("Quantidade de elementos: ");
    scanf("%d", &qtd);

    for(int i=0; i < qtd; i++){
        dl *novo = (dl*)malloc(sizeof(dl));
        
        printf("Elemento %d: ", i+1);
        scanf("%d", &novo->n);

        novo->next = NULL;
        novo->prev = ultimo;

        if(ultimo != NULL)
            ultimo->next = novo;
        else
            list = novo; 

        ultimo = novo;
    }

    printf("\n##### Busca ##### \nValor da chave: ");
    scanf("%d", &n);

    ShowNeighbors(list, n);

    return 0;
}
