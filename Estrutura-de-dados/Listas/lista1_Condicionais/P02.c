/*
2. Uma loja vende produtos à vista e a prazo (pagamento 30 dias depois da compra). À vista tem um desconto de 5% e a prazo um acréscimo de 10%. 
Faça um programa em C que peça o preço do produto e a forma de pagamento: 1 para à vista e 2 para a prazo. Depois apresente o preço final do produto. 

Exemplos de execução:
    Preço do produto: 120.00			Preço do produto: 200.00
    Forma de pagamento: 1				Forma de pagamento: 2
    Preço a vista: 114.00				Preço a prazo: 220.00
*/

#include <stdio.h>

float calcularPrecoFinal(float preco, int formaPagamento){

    float precoFinal;

    if(formaPagamento == 1){
        precoFinal = preco - (0.05 * preco);
    } else if (formaPagamento == 2){
        precoFinal = preco + (0.10 * preco);
    } 

    return precoFinal;
}

void tipoPagamento(int formaPagamento, char pagamentoEmString[10]){

    if(formaPagamento == 1){
        sprintf(pagamentoEmString, "à vista"); // Função sprintf é usada para copiar a string
    } else if(formaPagamento == 2){
        sprintf(pagamentoEmString, "a prazo");
    }
}

int main(void){

    float valor;
    int pagamento;
    float valorFinal;
    char pagamentoEmString[10]; 

    printf("Preço do produto: ");
    scanf("%f", &valor);

    do {
        printf("Forma de pagamento \n1 - à vista \n2 - a prazo \n-> R$ ");
        scanf("%d", &pagamento);

        if (pagamento != 1 && pagamento != 2) {
            printf("Opção inválida! Por favor, escolha 1 para à vista ou 2 para a prazo.\n");
        }

    } while (pagamento != 1 && pagamento != 2);    

    valorFinal = calcularPrecoFinal(valor, pagamento);

    tipoPagamento(pagamento, pagamentoEmString);

    printf("Preço %s: %.2f\n", pagamentoEmString, valorFinal);

    return 0;
}