/*
01. Leia uma matriz 4 x 4 (de inteiros) e imprima a diagonal principal.
*/

#include <stdio.h>
#define LIN 4
#define COL 4

int main(void){

    int matriz[LIN][COL];

    printf("Informe os valores da matriz: \n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            int valor = 0;
            printf("[%d][%d]: ", i, j);
            scanf("%d", &valor);

            matriz[i][j] = valor;
        }
    }

    printf("\nMatriz informada:\n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            printf("%d, ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nDiagonal principal da matriz:\n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            if(i == j){
                printf("%d", matriz[i][j]);
            } else {
                printf("  ");
            } 
        }
        printf("\n");
    }

    return 0;
}