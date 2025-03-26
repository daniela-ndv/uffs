// Faça uma função que receba um vetor e o seu tamanho como parâmetro e imprima o maior e o menor elemento do vetor. 
// Esta função é do tipo void pois não retorna nenhum valor

#include <stdio.h>

void maiorEMenor(int *v, int l){
    int maior = v[0], menor = v[0];

    for(int i = 1; i < l; i++){
        if(v[i] > maior){
            maior = v[i];
        }
        if(v[i] < menor){
            menor = v[i];
        }
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
}

int main(void)
{
    int vetor[5] = {1, 4, -7, 10, 0};
    int length = (sizeof(vetor)/sizeof(int)); 

    maiorEMenor(vetor, length);

    return 0;
}