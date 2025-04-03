/*
2. Leia uma matriz 4 x 4 e escreva a localização (linha e coluna) do maior valor.
*/

#include <stdio.h>
#define LIN 4
#define COL 4

int main(void){

    int matriz[LIN][COL];
    int maior, linha, coluna;

    printf("Informe os valores da matriz: \n");
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            int valor = 0;
            printf("[%d][%d]: ", i, j);
            scanf("%d", &valor);

            matriz[i][j] = valor;
        }
    }

    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
                linha = i;
                coluna = j;
            }
        }
    }

    printf("\nMaior valor: %d", maior);
    printf("\nPosição: [%d][%d]\n", linha, coluna);

    return 0;
}