/*
Crie um aplicativo de conversão entre as temperaturas Celsius e Fahrenheit.
Primeiro o usuário deve escolher se vai entrar com a temperatura em Celsius ou Fahrenheit, depois a conversão escolhida é realizada.
Se C é a temperatura em Celsius e F em Fahrenheit, as fórmulas de conversão são:
C = 5*(F-32)/9
F = (9*C/5) + 32
*/

float celsiusParaFahrenheit(float);
float FahrenheitParaCelsius(float);

#include <stdio.h>

int main(void){
    int unidade;
    float temperatura;
    float resultado;

    do{
        printf("******** Conversor de temperatura ********\n");
        printf("Informe a unidade de medida da entrada [1 ou 2] ou 0 (zero) para sair");
        printf("\n1 - Celsius ");
        printf("\n2 - Fahrenheit ");
        printf("\n0 - Sair \n=> ");
        scanf("%d", &unidade);

        if(unidade == 1){
            printf("\nInforme a temperatura em Celsius: ");
            scanf("%f", &temperatura);
    
            resultado = celsiusParaFahrenheit(temperatura);
            printf("\n#### Resultado: ####\n%.2f Celsius = %.2f Fahrenheit\n\n", temperatura, resultado);

        } else if(unidade == 2){
            printf("\nInforme a temperatura em Fahrenheit: ");
            scanf("%f", &temperatura);
    
            resultado = FahrenheitParaCelsius(temperatura);
            printf("\n#### Resultado: ####\n=> %.2f Fahrenheit = %.2f Celsius\n\n", temperatura, resultado);

        } else if(unidade != 1 && unidade != 2 && unidade != 0){
            printf("\nOpção de unidade de temperatura inválida!\n");
            continue;
        }

    } while(unidade != 0);

    return 0;
}

float celsiusParaFahrenheit(float celsius){
    float F;
    F = (9*celsius/5) + 32;
    return F;
}

float FahrenheitParaCelsius(float fahrenheit){
    float C;
    C = 5*(fahrenheit-32)/9;
    return C;
}