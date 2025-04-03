/*
4 - Faça um programa que preenche uma matriz 5 x 5 com o produto da posição da linha e da coluna de cada elemento. Em seguida, imprima.
*/

#include <stdio.h>
#define LIN 5
#define COL 5

int main(void){

    int matriz[LIN][COL];

    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            matriz[i][j] = i * j;
        }
    }

    printf("\nMatriz com valores igual ao produto das posições (linha * coluna):\n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            printf("%d, ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}