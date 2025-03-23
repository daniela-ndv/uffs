/*
4. ⊘ Construa um programa que simule uma calculadora simples. Primeiro é solicitada a operação desejada +, -, / ou *, em seguida os dois operandos. 
Como resultado, o programa mostra o resultado da operação. O Programa é finalizado quando a operação desejada for igual à @. 
*/

#include <stdio.h>
#include <math.h>

float soma(float, float);
float sub(float, float);
float div(float, float);
float mult(float, float);

int main(void)
{
    while(1){
        float num1, num2, resultado;
        char op = ' ';

        printf("************ Calculadora ************\n");
        printf("Informe a operação desejada (+, -, /, * ou @ para sair): ");
        // Usando " %c" para ignorar qualquer caractere extra como \n ou espaço antes da leitura
        scanf(" %c", &op);

        if (op == '@') {
            printf("\nPrograma finalizado.\n");
            break; 
        } else if(op != '+' && op != '-' && op != '*' && op != '/'){
            printf("\nOpção inválida.\n\n");
            continue; 
        }

        printf("\nInforme os valores da operação\nValor 1: ");
        scanf("%f", &num1);
        printf("Valor 2: ");
        scanf("%f", &num2);

        if(op == '+'){
            resultado = soma(num1, num2);
            printf("\nTotal = %.2f\n\n", resultado);
        } else if(op == '-'){
            resultado = sub(num1, num2);
            printf("\nTotal = %.2f\n\n", resultado);
        } else if(op == '*'){
            resultado = mult(num1, num2);
            printf("\nTotal = %.2f\n\n", resultado);
        } else if(op == '/'){
            resultado = div(num1, num2);
            printf("\nTotal = %.2f\n\n", resultado);
        }
    } 
    return 0;
}

float soma(float num1, float num2){
    return num1 + num2;
}

float sub(float num1, float num2){
    return num1 - num2;
}

float div(float num1, float num2){
    if(num2 <= 0){
        printf("\nO denominador não pode ser negativo ou nulo.");
        return NAN; //Not A Number
    } else{
        return num1 / num2;
    }
}
 
float mult(float num1, float num2){
    return num1 * num2;
}