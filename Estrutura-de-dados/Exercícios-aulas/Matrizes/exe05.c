/*
5 - Leia uma matriz 4 x 4 e imprima a triangular superior.
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

    printf("\nTriangular superior da matriz:\n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            if(j > i){
                printf("%d, ", matriz[i][j]);
            } 
        }
        printf("\n");
    }

    return 0;
}