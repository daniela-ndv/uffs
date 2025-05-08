/*Implemente uma função recursiva que calcule o somatório dos elementos de um vetor passado por parâmetro.
se n==0 então v[0]              		  (caso base)
caso contrário v[n] + somaV(v, n-1)    (caso recursivo)
*/

#include <stdio.h>

int somaV(int *v, int n){
    if(n == 0){
        return v[0];
    }

    return v[n] + somaV(v, n-1);
}

int main(void){

    int v[5], n = 5, resultado = 0;

    for(int i=0; i < n; i++){
        printf("Informe o valor da posição %d: ", i+1);
        scanf("%d", &v[i]);
    } 

    resultado = somaV(v, n);

    printf("Resultado = %d\n", resultado);

    return 0;
}