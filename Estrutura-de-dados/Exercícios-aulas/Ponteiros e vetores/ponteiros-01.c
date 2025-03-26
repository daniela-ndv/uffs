// Escreva uma função chamada troca(), que receba dois ponteiros para inteiros e troca os valores entre eles.
// Exemplo de chamada: troca(&a, &b)

#include <stdio.h>

void troca(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    int a = 5, b = 10;

    printf("a = %d, b = %d\n", a, b);

    troca(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}

