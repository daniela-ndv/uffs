/*
Crie uma função que receba 2 números e retorne o maior valor entre eles (se forem iguais, retorna o segundo).
*/ 

#include <stdio.h>

float maiorValor(float, float);

int main(void){

    float a, b;

    printf("Valor 1: ");
    scanf("%f", &a);
    printf("Valor 2: ");
    scanf("%f", &b);

    printf("O maior valor é %.2f\n", maiorValor(a, b));

    return 0;
}

float maiorValor(float num1, float num2){
    float maior;

    if(num1 > num2){
        maior = num1;
    } else {
        maior = num2;
    } 

    return maior;
}