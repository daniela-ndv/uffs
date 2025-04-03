/*
03 - Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais elementos. Imprima, ao final, a matriz obtida.
*/

#include <stdio.h>
#define LIN 5
#define COL 5

int main(void){

    int matriz[LIN][COL];

    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            if(i == j){
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }     
        }
    }

    printf("\nMatriz com diagonal principal de valores iguais a 1:\n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            printf("%d, ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}