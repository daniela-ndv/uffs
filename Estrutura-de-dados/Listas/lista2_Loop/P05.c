/*
5. ⊘ Faça um programa para calcular o fatorial de um número dado. O fatorial de um número n é n × (n − 1) × (n − 2) × . . . × 1, por definição o fatorial de 0 e 1 é 1.
 Por exemplo, o fatorial de 5 é 120, ou seja, 5 × 4 × 3 × 2 × 1 (perceba que não é necessário fazer a última multiplicação já que 1 é o elemento neutro da multiplicação). 
*/

#include <stdio.h>

int calcularFatorial(int);

int main(void)
{
    int numero, resultado;

    printf("Calcular o fatorial do número: ");
    scanf("%d", &numero);

    resultado = calcularFatorial(numero);

    printf("%d\n", resultado);
    
    return 0;
}

int calcularFatorial(int num){
    int total = 1;

    if(num == 0 || num == 1){
        total = 1;
        printf("%d! = ", total);
    } else{
        printf("%d! = ", num);
        for(int i = num; i >= 1; i--){
            if(i == 1){
                printf("%d = ", i);
            } else{
                printf("%d * ", i);
            }
            total *= i;
        }
    }
    return total;
}
