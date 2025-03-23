/*
1. • Faça um programa que peça um número e imprima os números de 1 até o número informado. Sendo que, quando chegar na metade da impressão, mostrar 
a mensagem Metade (a metade não precisa ser exata). 
Exemplos: 
Número: 6				Número: 7		ou	Número: 7
1 						1				1
2 						2				2
3 						3				3
Metade 					4				Metade
4 						Metade			4	
5 						5				5
6 						6				6							
				        7
*/

#include <stdio.h>

void mostrarSequencia(int);

int main(void){
    int num = 0;

    do{
        printf("Informe um número inteiro maior que 1: ");
        scanf("%d", &num);
    } while(num <= 1);

    printf("Número: %d", num);

    mostrarSequencia(num);
    
    return 0;
}

void mostrarSequencia(int num){
    printf("\nSequência de 1 até %d", num);

    for(int i=1; i <= num + 1; i++){
        if (i == num / 2) {  
            printf("\n%d", i);
            printf("\nMetade");
        } else {
            printf("\n%d", i);
        }
    } 
}
