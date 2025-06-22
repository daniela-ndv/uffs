/* Faça um programa que receba uma string, caractere por caractere. 
- Cada caractere é colocado em uma pilha
- No fim da entrada, esvazie a pilha imprimindo os caracteres armazenados */

#include <stdio.h>
#include <stdlib.h>

typedef char C;

typedef struct elemStack {
   C c;
   struct elemStack *next;
} ElemStack;

typedef struct tstack {
	ElemStack *top;
} Stack;

void initStack(Stack *s){
	s->top=NULL;
}

int isEmptyStack(Stack *s){
	return (s->top == NULL);
}

void push(Stack *s, char c){
	ElemStack *aux;
	aux = (ElemStack *)malloc(sizeof(ElemStack));
	aux->c = c;

	aux->next = s->top;
	s->top = aux;
}

void pop(Stack *s, char *c){
	ElemStack *aux;

	*c = s->top->c;

	aux = s->top;
	s->top = s->top->next;

	free(aux);
}

void freeStack(Stack *s) {
    ElemStack *aux;

    while (!isEmptyStack(s)) {
        aux = s->top;
        s->top = s->top->next;

        free(aux);
    }
}

void printStack(Stack s){
    ElemStack *current = s.top;

    while (current != NULL) {
        printf("%c ", current->c);
        current = current->next;
    }
    printf("\n");
}


int main ()
{
	Stack stack;
	C caractere;

	initStack(&stack);

    printf("Informe a string (caractere por caractere): ");
    while(1){
        printf("\nDigite o caractere [ou 0 para encerrar]: ");
        scanf(" %c", &caractere);

        if(caractere == '0') break;

        push(&stack, caractere);

        printf("=> Pilha atual: ");
        printStack(stack);
    }

    printf("\nLimpando a pilha ... \n");

    while(isEmptyStack(&stack) == 0){
        pop(&stack, &caractere);
        printf("Item '%c' removido da pilha. \n", caractere);

        printf("=> Pilha atual: ");
        printStack(stack);
    }

    freeStack(&stack);   

	return 0;
}
