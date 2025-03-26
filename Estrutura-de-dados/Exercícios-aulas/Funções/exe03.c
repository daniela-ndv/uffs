/*
Crie uma função que receba 3 números e retorne o maior valor, utilizando uma chamada para a função anterior.
*/ 

#include <stdio.h>

float maiorValorEntreDois(int, int);
float maiorValorEntreTres(int, int, int);

int main(void){
    int a, b, c;
    
    printf("Digite três números, separados por espaço [ex.: a b c]: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a == b && a == c){
        printf("Os três valores são iguais\n");
    } else {
        printf("O maior valor é: %.2f\n", maiorValorEntreTres(a, b, c));
    }
    
    return 0;
}

float maiorValorEntreDois(int num1, int num2){
    if(num1 > num2){ 
        return num1;
    } else {
        return num2;
    } 
}

float maiorValorEntreTres(int num1, int num2, int num3) {
    return maiorValorEntreDois(maiorValorEntreDois(num1, num2), num3);
}