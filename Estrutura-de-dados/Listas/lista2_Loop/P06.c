/*
6. ⊙ Dada uma sequência de n números (um número menor ou igual à 0 finaliza a sequência), 
apresentar o percentual de números informados que são maiores ou igual a 10 e menores ou igual a 20. Exemplo:  
Número: 5
Número: 6 
Número: 11 
Número: 21 
Número: 0 
% entre 10 e 20: 50% 
*/

#include <stdio.h>

float calcularPercentual(int, int);

int main(void)
{
    float resultado = 0;
    int cont = 0, qtdNumTotal = 0;

    for(int i = 1; i > 0; i++){
        int num;

        printf("Número %d: ", i);
        scanf("%d", &num);

        if(num <= 0){
            printf("Programa finalizado.\n");
            break;
        } else if (num >= 10 && num <= 20){
            cont += 1;
        }

        qtdNumTotal += 1;
    } 

    resultado = calcularPercentual(qtdNumTotal, cont);
    
    printf("Percentual entre 10 e 20: %.2f%%\n", resultado);
    
    return 0;
}

float calcularPercentual(int totalDeNumeros, int qtdNumerosNaFaixa){
    float total;

    total = ((float)qtdNumerosNaFaixa / totalDeNumeros) * 100;

    return total;
}