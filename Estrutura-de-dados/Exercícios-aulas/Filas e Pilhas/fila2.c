/* Faça um programa que receba uma string, caractere por caractere. 
- Cada caractere é colocado em uma fila
- No fim da entrada, esvazie a fila imprimindo os caracteres armazenados */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char C;

typedef struct squeue {
    C c;
    struct squeue *next;
} SQueue;

typedef struct {
    SQueue *head;
    SQueue *tail;
} Queue;

void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

int isEmpty(Queue *q){
    return (q->head == NULL);
}

void enQueue(Queue *q, C c){
    SQueue *aux = (SQueue *)malloc(sizeof(SQueue));
    aux->c = c;
    aux->next = NULL;

    if(q->head == NULL){
        q->head = aux;
        q->tail = aux;
    } else {
        q->tail->next = aux;
        q->tail = aux;
    }
}

void deQueue(Queue *q, C *c){
    SQueue *aux;

    *c = q->head->c;
    aux = q->head;

    if(q->head == q->tail){
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
    }

    free(aux);
}

void freeAll(Queue *q){
    SQueue *aux;

    while (q->head != NULL){
        aux = q->head;
        q->head = q->head->next;
        free(aux);
    }
    q->tail = NULL;
}

void printQueue(Queue q){
    SQueue *current = q.head;

    while (current != NULL) {
        printf("%c ", current->c);
        current = current->next;
    }
    printf("\n");
}

int main(){
    Queue queue;
    C caractere;

    initQueue(&queue);

    printf("Informe a string (caractere por caractere): ");
    while(1){
        printf("\nDigite o caractere [ou 0 para encerrar]: ");
        scanf(" %c", &caractere);

        if(caractere == '0') break;

        enQueue(&queue, caractere);

        printf("=> Fila atual: ");
        printQueue(queue);
    }

    printf("\nLimpando a fila ... \n");
    while(isEmpty(&queue) == 0){
        deQueue(&queue, &caractere);
        printf("Item '%c' removido da fila. \n", caractere);

        printf("=> Fila atual: ");
        printQueue(queue);
    }

    freeAll(&queue);    

    return 0;
}
