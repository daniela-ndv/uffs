/*  3. Implemente uma função recursiva que calcule o máximo divisor comum (mdc) entre dois números.
Por exemplo, o mdc de 12 e 18 é 6
Definição (Algoritmo de Euclides):
se n==0 então m                     (caso base)
caso contrário mdc(n,m%n)    (caso recursivo)
*/

#include <stdio.h>

int mdc(int m, int n){
    if(n == 0){
        return m;
    }

    return mdc(n, m%n);
}

int main(void){

    int a, b, resultado;

    printf("Informe o valor 1: ");
    scanf("%d", &a);

    printf("Informe o valor 2: ");
    scanf("%d", &b);

    resultado = mdc(a, b);

    printf("MDC = %d\n", resultado);

    return 0;
}