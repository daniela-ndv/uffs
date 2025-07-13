/**
 * Trabalho Final: Sistema de Acompanhamento de Produção Agrícola
 * 
 * Disciplina: Estrutura de Dados
 * Semestre: 2025/1
 * Discente: Daniela do Nascimento Dalla Vecchia
 */

#include <stdio.h>
#include <stdlib.h>
#include "producao.h"

int main(void){

    No *tabelaHash[TAM_HASH]; 
    for (int i = 0; i < TAM_HASH; i++) {
        tabelaHash[i] = NULL;
    }

    SentNo *lista = (SentNo*) malloc(sizeof(SentNo));
    lista->first = NULL;
    lista->last = NULL;

    int opcao;

    while (1){
        opcao = exibeMenu();

        switch (opcao){
            case 0:
                printf("Encerrando ...\n");
                return 0;
            case 1:
                lista = incluirProducao(lista, tabelaHash);
                break;
            case 2:
                alterarProducao(tabelaHash);
                break;
            case 3:
                lista = excluirProducao(lista, tabelaHash);
                break;
            case 4:
                consultarPorData(lista);
                break;
            case 5:
                consultarPorCultivar(lista);
                break;
            case 6:
                listarTodos(lista);
                break;
            default:
                printf("Opção inválida. Digite outra opção.");
                break;
        }
    }

    return 1;
}

