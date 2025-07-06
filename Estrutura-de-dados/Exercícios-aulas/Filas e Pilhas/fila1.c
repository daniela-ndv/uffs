#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct TQueue {
    Item item;
    struct TQueue *next;
} EQueue;

typedef struct {
    EQueue *head;
    EQueue *tail;
} Queue;

void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

int isEmpty(Queue *q){
    return (q->head == NULL);
}

void enQueue(Queue *q, Item item){
    EQueue *aux;

    aux = (EQueue *)malloc(sizeof(EQueue));
    aux->item = item;
    aux->next = NULL;

    if(q->head == NULL){
        q->head = aux;
        q->tail = aux;
    } else {
        q->tail->next = aux;
        q->tail = aux;
    }
}

void deQueue(Queue *q, Item *item){
    EQueue *aux;

    *item = q->head->item;
    aux = q->head;

    if(q->head == q->tail){
        q->head = NULL;
        q->tail = NULL;
    } else{
        q->head = q->head->next;
    }

    free(aux);
}

void freeAll(Queue *q){
    EQueue *aux;

    while (!isEmpty){
        aux = q->head;
        q->head = q->head->next;
        free(aux);
    }
    q->tail = NULL;
}

void printQueue(Queue q){
    EQueue *current = q.head;

    printf("Fila: ");
    while (current != NULL) {
        printf("%d ", current->item);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue queue;
    Item item;

    initQueue(&queue);

    for(int i = 0; i < 10; i++){
        item = i;

        printf("Inserindo na fila o item %d. \n", item);
        enQueue(&queue, item);
    }

    printf("\nImprimindo fila ...\n");
    printQueue(queue);
    printf("\n");

    while(isEmpty(&queue) == 0){
        deQueue(&queue, &item);
        printf("Item %d removido da fila. \n", item);
    }

    freeAll(&queue);    

    printf("\nImprimindo fila ...\n");
    printQueue(queue);

    return 0;
}