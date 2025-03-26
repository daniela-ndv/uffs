// Crie uma função somaImpares(), que receba dois inteiros (inicio, fim) e um ponteiro. A função deve somar os ímpares do intervalo.
// O código ao lado deve imprimir 21.

#include <stdio.h>

void somaImpares(int inicio, int fim, int *soma){
    for(int i = inicio; i <= fim; i++){
        if(i % 2 != 0){
            *soma += i;
        }
    }
}

int main(void)
{
    int inicio = 5, fim = 9, soma = 0;

    printf("Início: %d \nFim: %d\n", inicio, fim);

    somaImpares(inicio, fim, &soma);

    printf("Soma dos ímpares = %d\n", soma);

    return 0;
}