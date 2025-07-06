/**
 * Implementação sem tratamento de conflitos na tabela Hash
*/

#include <stdio.h>
#define TAM_HASH 10

typedef struct estudante{
    int matricula;
    char nome[50];
    char curso[100];
} Estudante;

unsigned int funcaoHash(int mat){
    return mat % TAM_HASH;
}

void imprimeTabela(Estudante* tabela[], int tam){
    for(int i = 0; i < tam; i++){
        if(tabela[i] == NULL){
            printf("Posição %d: -\n", i);
        } else{
            printf("Posição %d: %s\n", i, tabela[i]->nome);
        }
    }
}

int insereNaTabela(Estudante* tabela[], Estudante* e){
    unsigned int indice = funcaoHash(e->matricula);

    if(tabela[indice] == NULL){
        tabela[indice] = e;
        printf("Inseriu %s na posição %d - Sem conflito\n", e->nome, indice);
    } else{
        printf("Não inseriu %s na posição %d - Com conflito\n", e->nome, indice);
        return 1;
    }
    return 0;
}

Estudante* buscaPorMatricula(Estudante* tabela[], int matricula){
    unsigned int indice = funcaoHash(matricula);
    return tabela[indice];
}

int main(void){

    Estudante e1 = {19, "Fulano", "CC"};
    Estudante e2 = {15, "Ciclano", "CC"};
    Estudante e3 = {25, "Beltrano", "CC"};
    Estudante e4 = {17, "Maria", "CC"};
    Estudante e5 = {8, "Dani", "CC"};

    // Calcular o hash de cada estudante
    printf("Nome: %s, hash: %d\n", e1.nome, funcaoHash(e1.matricula)); 
    printf("Nome: %s, hash: %d\n", e2.nome, funcaoHash(e2.matricula)); 
    printf("Nome: %s, hash: %d\n", e3.nome, funcaoHash(e3.matricula)); 
    printf("Nome: %s, hash: %d\n", e4.nome, funcaoHash(e4.matricula)); 
    printf("Nome: %s, hash: %d\n", e5.nome, funcaoHash(e5.matricula)); 

    Estudante* tabelaHash[TAM_HASH];
    for(int i = 0; i < TAM_HASH; i++){
        tabelaHash[i] = NULL;
    }

    printf("\nImprimindo tabela ...\n");
    imprimeTabela(tabelaHash, TAM_HASH);

    insereNaTabela(tabelaHash, &e1);
    insereNaTabela(tabelaHash, &e2);
    insereNaTabela(tabelaHash, &e3);
    insereNaTabela(tabelaHash, &e4);
    insereNaTabela(tabelaHash, &e5);

    printf("\nImprimindo tabela ...\n");
    imprimeTabela(tabelaHash, TAM_HASH);

    printf("\n********** Busca **********\n");

    Estudante* estudanteBuscado = buscaPorMatricula(tabelaHash, 19);

    printf("Matricula: %d, Nome: %s, Curso: %s\n", estudanteBuscado->matricula, estudanteBuscado->nome, estudanteBuscado->curso);

    return 0;
}