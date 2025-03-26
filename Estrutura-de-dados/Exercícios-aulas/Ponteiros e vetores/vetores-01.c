// Crie um programa que lê 5 valores inteiros, armazena-os em um vetor e, em seguida, mostre na tela os valores lidos.

#include <stdio.h>

int main(void)
{
    int vetor[5];
    
    for(int i = 0; i < (int)(sizeof(vetor)/sizeof(int)); i++){
        printf("Digite o número %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor:\n");

    for(int i = 0; i < (int)(sizeof(vetor)/sizeof(int)); i++){
        printf("%d \n", vetor[i]);
    }

    return 0;
}

