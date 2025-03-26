/*
Faça uma função que lê dois inteiros e apresenta a diferença entre os dois.
*/ 

#include <stdio.h>
#include <stdlib.h>

int diferenca(int, int);

int main(void){

    int a, b = 0;
    int resultado;

    printf("Valor A: ");
    scanf("%d", &a);
    printf("Valor B: ");
    scanf("%d", &b);

    resultado = diferenca(a, b);

    printf("Resultado: %d\n", resultado);

    return 0;
}

int diferenca(int num1, int num2){
    return abs(num1 - num2);
}