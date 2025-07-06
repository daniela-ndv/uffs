/* Um sistema produziu uma lista duplamente encadeada com números únicos, ordenados em ordem
crescente (veja estrutura da lista abaixo - 1d).
Faça: (a) uma função que receba o sentinela da lista dupla e devolva a estrutura de uma fila (queue)
em que os valores na fila sejam os mesmos na ordem da lista: queue getQueue(sent st); e
(b) outra função que receba o sentinela da lista dupla e devolva a estrutura de uma pilha (stack) em
que os valores na pilha sejam armazenados na ordem inversa deles na lista: stack getStack(sent
st).
*/

#include <stdio.h>
#include <stdlib.h>

// Lista dupla
typedef struct tld {
    int n;
    struct tld *next, *prev;
} ld;
typedef struct {
    ld *head;
    ld *tail;
} sent;

// Fila
typedef struct tq {
    int n;
    struct tq *next;
} q;
typedef struct {
    q *head;
    q *tail;
} queue;

// Pilha
typedef struct ts {
    int n;
    struct ts *next;
} s;
typedef struct {
    s *top;
} stack;

void inserirNaLista(sent *st, int n){
    ld *novo = (ld*)malloc(sizeof(ld));

    novo->n = n;
    novo->next = NULL;
    novo->prev = NULL;

     if (st->head == NULL) {
        st->head = novo;
        st->tail = novo;
    } else {
        st->tail->next = novo;
        novo->prev = st->tail;
        st->tail = st->tail->next;
    }
}

/**
 * Função que recebe o sentinela da lista dupla e retorna uma fila (queue) na mesma ordem
 */
queue getQueue(sent st){
    queue qu;
    qu.head = NULL;
    qu.tail = NULL;

    ld *aux = st.head;

    while(aux != NULL){
        q *novo = (q*)malloc(sizeof(q));
        novo->n = aux->n;
        novo->next = NULL;

        if(qu.head  == NULL){
            qu.head = novo;
            qu.tail = novo;
        } else{
            qu.tail->next = novo;
            qu.tail = qu.tail->next;
        }  
        aux = aux->next;      
    }
    return qu;
}

/**
 * Função que recebe o sentinela da lista dupla e retorna uma pilha (stack) na ordem inversa deles na lista
 */
stack getStack(sent st){
    stack sk;
    sk.top = NULL;

    ld *aux = st.head;

    while(aux != NULL){
        s *novo = (s*)malloc(sizeof(s));
        novo->n = aux->n;
        novo->next = NULL;

        if(sk.top == NULL){
            sk.top = novo;
        } else{
            novo->next = sk.top;
            sk.top = novo;
        }
        aux = aux->next;
    }
    return sk;

}

void imprimeLista(sent st){
    while(st.head != NULL){
        printf("%d", st.head->n);
        if(st.head->next != NULL) printf(", "); else printf("\n"); 
        st.head = st.head->next;
    }
}

void imprimeFila(queue q){
    while(q.head != NULL){
        printf("%d", q.head->n);
        if(q.head->next != NULL) printf(", "); else printf("\n"); 
        q.head = q.head->next;
    }
}

void imprimePilha(stack s){
    while(s.top != NULL){
        printf("%d", s.top->n);
        if(s.top->next != NULL) printf(", "); else printf("\n"); 
        s.top = s.top->next;
    }
}

int main(void){

    sent sDupla;
    sDupla.head = NULL;
    sDupla.tail = NULL;

    queue q;
    q.head = NULL;
    q.tail = NULL;

    stack s;
    s.top = NULL;

    for(int i = 0; i < 10; i++){
        inserirNaLista(&sDupla, i);
        printf("Valor %d inserido na lista.\n", i);
    }

    printf("\n");
    printf("Lista atual: ");
    imprimeLista(sDupla);

    q = getQueue(sDupla);

    printf("Fila: ");
    imprimeFila(q);

    s = getStack(sDupla);

    printf("Pilha: ");
    imprimePilha(s);

    return 0;
}