/*
2. ⊙ Faça um programa que simule a multiplicação por meio de adições. Para tal serão pedidos os dois operandos. Por exemplo se for informado 3 e 4, 
deverá ser calculado, usando a soma, 3∗4, ou seja, 12. Este cálculo é feito somando o primeiro valor informado por ele mesmo o número de vezes 
representada pelo segundo número. Nesse exemplo, o três seria somado quatro vezes: 3+3+3+3, resultando 12. 
*/

#include <stdio.h>

int multiplicarPorAdicao(int, int);

int main(void)
{
    int fator1, fator2, total;

    printf("Fator 1 (multiplicando): ");
    scanf("%d", &fator1);
    printf("Fator 2 (multiplicador): ");
    scanf("%d", &fator2);

    total = multiplicarPorAdicao(fator1, fator2);

    printf("%d\n", total);
    
    return 0;
}

int multiplicarPorAdicao(int fator1, int fator2){
    int soma = 0;
    for(int i = 1; i <= fator2; i++){
        if(i == fator2){
            printf("%d = ", fator1);
        } else{
            printf("%d + ", fator1);
        }
        soma += fator1;
    }
    return soma;
}
