/*
7. ⊙ Faça um programa que peça o salário e o número de filhos dos habitantes de uma região. 
Quando o salário informado for menor que zero, as entradas são finalizadas e serão apresentadas 
as médias salarial e de filhos informados. 

Exemplo: 
Salário: 1500 
Filhos: 2 
Salário: 3245 
Filhos: 2 
Salário: -1 
Média salários: 2372.5 
Média filhos: 2.0 
*/

#include <stdio.h>

int main(void)
{
    float sumSalarios = 0; 
    int sumFilhos = 0, contPessoas = 0;

    while(1){
        float salario;
        int filhos;

        printf("Salário: ");
        scanf("%f", &salario);

        if(salario < 0){
            break;
        }

        printf("Filhos: ");
        scanf("%d", &filhos);

        contPessoas += 1;
        sumSalarios += salario;
        sumFilhos += filhos;
    }

    printf("\nMédia salários: %.2f", ((float)sumSalarios/contPessoas));
    printf("\nMédia filhos: %.1f\n", ((float)sumFilhos/contPessoas));

    return 0;
}