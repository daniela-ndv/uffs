// Crie uma função chamada maior(), que receba dois inteiros e um ponteiro para um inteiro. A função deve armazenar o valor do maior no endereço do ponteiro.
// Exemplo de chamada: maior(a, b, &c)

#include <stdio.h>

void maior(int a, int b, int *c){
    int maior = a;
    if(b > maior){
        maior = b;
        *c = b;
    } else {
        *c = a;
    }
}

int main(void)
{
    int a = 1, b = 1, m;

    printf("a = %d, b = %d\n", a, b);

    maior(a, b, &m);

    printf("Maior = %d\n", m);

    return 0;
}