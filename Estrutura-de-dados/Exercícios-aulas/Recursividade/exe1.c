/*Implemente uma função recursiva que, dados dois números inteiros base (b) e expoente (e), 
calcula o valor de be (e≥0).
se e==0 então 1              (caso base 1)
se e==1 então b              (caso base 2)
caso contrário b x b(e-1)    (caso recursivo)
*/

#include <stdio.h>

double calculaExp(double b, double e){
    if(e == 0){
        return 1;
    } 
    if(e == 1){
        return b;
    }
    
    return b * calculaExp(b, e-1);
}

int main(void){

    double b, e, resultado;

    printf("Base: ");
    scanf("%lf", &b);
    printf("Expoente: ");
    scanf("%lf", &e);

    resultado = calculaExp(b, e);

    printf("Resultado = %.1lf\n", resultado);

    return 0;
}
