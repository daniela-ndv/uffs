/*
1. Faça um programa que peça o número de horas trabalhadas e o valor da hora de um determinado funcionário. 
Em seguida, calcule o salário do funcionário. Caso o funcionário tenha trabalhado mais de 200 horas, o salário final é acrescido de 5%. 

Exemplos de execução:
    Horas trabalhadas: 120				Horas trabalhadas: 210
    Valor da hora: 100.00				Valor da hora: 50.00
	Salário: 12000.00					Salário: 11025.00
*/

#include <stdio.h>

float calcularSalario(int horas, float valorHora){
    float salario;

    if(horas > 200){
        int salInicial = horas * valorHora;
        salario = salInicial + (0.05 * salInicial);
    } else {
        salario = horas * valorHora;
    }

    return salario;
}

int main(void){
    
    int horas;
    float valorHora;
    float salario;
    
    printf("Horas trabalhadas: ");
    scanf("%d", &horas);
    printf("Valor da hora: ");
    scanf("%f", &valorHora);

    salario = calcularSalario(horas, valorHora);

    printf("Salário: %.2f\n", salario);

    return 0;
}

