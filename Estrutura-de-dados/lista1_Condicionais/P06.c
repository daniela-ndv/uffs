/*
6. Sabendo que as faixas etárias para votação são: 18 a 70 anos voto obrigatório; 16, 17 e acima de 70 anos voto facultativo; outras idades (ou seja, menor que 16 anos) não pode votar, crie um programa que processa essa verificação. 

Exemplos de execução:
	Idade: 20			    Idade: 17			    Idade: 12
	Voto obrigatório		Voto facultativo		Não pode votar
*/

#include <stdio.h>

void verificarIdade(int idade){

    if(idade < 0){
        printf("Idade inválida!\n");
        return;
    }

    if(idade >= 18 && idade <= 70){
        printf("Voto obrigatório\n");
    } else if((idade >= 16 && idade <= 17) || (idade > 70)){
        printf("Voto facultativo\n");
    } else if(idade < 16 ){
        printf("Não pode votar\n");
    }
}

int main(void){

    int idade;

    printf("Idade: ");
    scanf("%d", &idade);

    verificarIdade(idade);

    return 0;
}