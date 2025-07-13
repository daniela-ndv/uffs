#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "producao.h"

/**
 * Exibe o menu e retorna a opção escolhida
 */
int exibeMenu() {
    int opcao;
    printf("\n===== Menu de Produção =====\n");
    printf("1 - Incluir produção\n");
    printf("2 - Alterar produção\n");
    printf("3 - Excluir produção\n");
    printf("4 - Consultar por data\n");
    printf("5 - Consultar por cultivar\n");
    printf("6 - Listar Todos\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

/**
 * Lê o novo nó pela entrada do teclado e valida se o código é único na tabela Hash
 */
No* lerNo(No *tabelaHash[]){
    No *no = (No*)malloc(sizeof(No));
    no->next = NULL;
    no->prev = NULL;

    printf("\n##### Informe os dados do novo registro #####\n\n");

    no->dado.codigo = lerCodigoValido(tabelaHash);
    if (no->dado.codigo == 0) {
        free(no); // Operação cancelada
        return NULL;
    }

    no->dado.dataProducao = lerData();

    lerFardo(&no->dado.tipoDeFardo);
    
    printf("Quantidade de fardos: ");
    scanf("%d", &no->dado.qtDeFardos);

    printf("Tempo (em minutos): ");
    scanf("%d", &no->dado.tempoEmMin);

    return no;
}

/**
 * Lê o código do novo resgitro e valida se já existe na tabela hash
 */
int lerCodigoValido(No *tabelaHash[]){
    int codigo;

    while (1) {
        printf("Código: ");
        scanf("%d", &codigo);

        if (codigo == 0) {
            return 0;
        }

        if (codigoExisteNaTabelaHash(tabelaHash, codigo)) {
            printf("Código %d já existe na tabela. Informe um novo código ou digite 0 para cancelar.\n", codigo);
        } else {
            return codigo;  // Código é válido e único
        }
    }
}

/**
 * Lê o código do fardo e insere no novo registro
 */
void lerFardo(Fardo *fardo){
    getchar(); // limpar buffer

    printf("Cultivar da produção: ");
    fgets(fardo->cultivar, 20, stdin);
    fardo->cultivar[strcspn(fardo->cultivar, "\n")] = '\0'; // Remove a quebra de linha

    do {
        printf("Tipo de feno (A, B, C): ");
        scanf(" %c", &fardo->tipoDeFeno);
        if(fardo->tipoDeFeno != 'A' && fardo->tipoDeFeno != 'B' && fardo->tipoDeFeno != 'C') printf("Valor inválido. Tente novamente.\n");
    } while (fardo->tipoDeFeno != 'A' && fardo->tipoDeFeno != 'B' && fardo->tipoDeFeno != 'C');

    do {
        printf("Diâmetro (80 a 160): ");
        scanf("%d", &fardo->diametro);

        if (fardo->diametro < 80 || fardo->diametro > 160) printf("Valor inválido. Tente novamente.\n");
    } while (fardo->diametro < 80 || fardo->diametro > 160);
}

/**
 * Lê a data e retorna a estrutura Data
 */
Data lerData(){
    Data data;
    printf("Data [DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    return data;
}

/**
 * Retorna o valor real convertido para a tabela hash (módulo)
 */
unsigned int funcaoHash(int codigo){
    return codigo % TAM_HASH;
}

/**
 * Insere um elemento na tabela Hash
 */
int insereNaTabelaHash(No* tabela[], No* no) {
    unsigned int indice = funcaoHash(no->dado.codigo);

    if (tabela[indice] != NULL) {
        printf("\nNão inseriu código %d na posição %d - Conflito (já ocupado)\n", no->dado.codigo, indice);
        return 0; // Conflito: posição já ocupada
    }

    tabela[indice] = no;
    printf("\nInseriu código %d na posição %d - Sem conflito\n", no->dado.codigo, indice);
    return 1;
}

/**
 * Percorre a tabela e valida se o código já existe na tabela hash
 */
int codigoExisteNaTabelaHash(No* tabelaHash[], int codigo) {
    unsigned int indice = funcaoHash(codigo);
    No *atual = tabelaHash[indice];

    while (atual != NULL) {
        if (atual->dado.codigo == codigo)
            return 1; // Existe
        atual = atual->next;
    }
    return 0; // Não existe
}

/**
 * Insere o novo nó, lido em lerNo, na tabela Hash e na lista duplamente encadeada
 */
SentNo* incluirProducao(SentNo *lista, No* tabela[]) {
    No *no = lerNo(tabela);  

    if (no == NULL) {
        printf("Operação cancelada.\n");
        return lista;
    }

    // Insere na tabela Hash (a verificação já foi feita em lerNo)
    insereNaTabelaHash(tabela, no);

    // Inserção na lista duplamente encadeada
    if (lista->last == NULL) {
        // Lista vazia
        lista->first = no;
        lista->last = no;
    } else {
        no->prev = lista->last;
        no->next = NULL;
        lista->last->next = no;
        lista->last = no;
    }

    printf("\nProdução com código %d incluída com sucesso.\n", no->dado.codigo);

    return lista;
}

/**
 * Busca um nó pelo código na tabela hash e altera os dados
 */
void alterarProducao(No* tabela[]) {
    int codigo;
    printf("Informe o código da produção que deseja alterar: ");
    scanf("%d", &codigo);

    unsigned int indice = funcaoHash(codigo);
    No* no = tabela[indice];

    if (no == NULL || no->dado.codigo != codigo) {
        printf("\nProdução com código %d não encontrada.\n", codigo);
        return;
    }

    no->dado.dataProducao = lerData();

    lerFardo(&no->dado.tipoDeFardo);
    
    printf("Quantidade de fardos: ");
    scanf("%d", &no->dado.qtDeFardos);

    printf("Tempo (em minutos): ");
    scanf("%d", &no->dado.tempoEmMin);

    printf("\nProdução com código %d alterada com sucesso!\n", codigo);
}

/**
 * Busca um nó pelo código na tabela hash e exclui o registro, retornando o lista dupla após remover esse elemento
 */
SentNo* excluirProducao(SentNo *lista, No* tabelaHash[]) {
    int codigo;
    printf("Informe o código da produção a ser excluída: ");
    scanf("%d", &codigo);

    unsigned int indice = funcaoHash(codigo);
    No* no = tabelaHash[indice];

    // Verifica se o código existe na hash 
    if (no == NULL || no->dado.codigo != codigo) {
        printf("\nProdução com código %d não encontrada.\n", codigo);
        return lista;
    }

    // Remoção da lista duplamente encadeada
    if (no->prev != NULL) {
        no->prev->next = no->next;
    } else {
        // Era o primeiro
        lista->first = no->next;
    }

    if (no->next != NULL) {
        no->next->prev = no->prev;
    } else {
        // Era o último
        lista->last = no->prev;
    }

    // Remove da tabela hash
    tabelaHash[indice] = NULL;

    // Libera memória
    free(no);

    printf("\nProdução com código %d excluída com sucesso.\n", codigo);

    return lista;
}
    
/**
 * Consulta os nós pela data e imprime todos os registros nessa data 
 */
void consultarPorData(SentNo *lista) {
    int dia, mes, ano;
    int encontrados = 0;

    printf("Informe a data [DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    No *atual = lista->first;

    printf("\n");
    while (atual != NULL) {
        Producao p = atual->dado;

        if (p.dataProducao.dia == dia && p.dataProducao.mes == mes && p.dataProducao.ano == ano) {
            printf("%02d/%02d/%04d: %s - %c - %d\n", 
                dia, mes, ano, 
                p.tipoDeFardo.cultivar, 
                p.tipoDeFardo.tipoDeFeno, 
                p.qtDeFardos);
            encontrados++;
        }

        atual = atual->next;
    }

    if (!encontrados) {
        printf("Nenhum registro encontrado para a data %d/%d/%d.\n", dia, mes, ano);
    } else{
        printf("Total de resultados para a data %d/%d/%d: %d\n", dia, mes, ano, encontrados);
    }
}

/**
 * Consulta os nós pelo cultivar da produção e imprime todos os registros  
 */
void consultarPorCultivar(SentNo *lista) {
    char busca[20];
    int encontrados = 0;

    printf("Informe o cultivar: ");
    getchar(); // Limpa buffer 
    fgets(busca, 20, stdin);
    busca[strcspn(busca, "\n")] = '\0'; 

    // Armazenar resultados por tipo de feno
    int somaFardos[3] = {0, 0, 0};       // Índices: A=0, B=1, C=2
    int diametros[3] = {0, 0, 0};        // Salva o maior diâmetro por tipo
    char tipos[] = {'A', 'B', 'C'};

    No *atual = lista->first;

    while (atual != NULL) {
        Producao p = atual->dado;

        if (strcmp(p.tipoDeFardo.cultivar, busca) == 0) {
            // Usar índices para representar os tipos de feno (A, B e C)
            int i = -1; 
            if (p.tipoDeFardo.tipoDeFeno == 'A') i = 0;
            else if (p.tipoDeFardo.tipoDeFeno == 'B') i = 1;
            else if (p.tipoDeFardo.tipoDeFeno == 'C') i = 2;

            if (i >= 0) {
                somaFardos[i] += p.qtDeFardos;
                if (p.tipoDeFardo.diametro > diametros[i])
                    diametros[i] = p.tipoDeFardo.diametro;
                encontrados++;
            }
        }

        atual = atual->next;
    }

    if (!encontrados) {
        printf("Nenhum registro encontrado para o cultivar \"%s\".\n", busca);
        return;
    }

    // Exibir resultados formatados
    printf("\n");
    for (int i = 0; i < 3; i++) { // Percorre os tipos A, B e C
        if (somaFardos[i] > 0) {
            float area = calcularAreaMinimaArmazenagem(somaFardos[i], diametros[i]);
            printf("%s: %c - %d - %.2f m²\n", busca, tipos[i], somaFardos[i], area);
        }
    }
}

/**
 * Percorre a lista e imprime todos os elementos
 */
void listarTodos(SentNo *lista) {
    printf("\n##### Lista das produções #####\n\n");

    if (lista == NULL || lista->first == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *atual = lista->first;
    while (atual != NULL) {
        printf("Código: %d\n", atual->dado.codigo);
        printf("Data de produção: %d/%d/%d\n", atual->dado.dataProducao.dia, atual->dado.dataProducao.mes, atual->dado.dataProducao.ano);
        printf("Cultivar: %s\n", atual->dado.tipoDeFardo.cultivar);
        printf("Tipo de feno: %c\n", atual->dado.tipoDeFardo.tipoDeFeno);
        printf("Diâmetro por fardo: %d\n", atual->dado.tipoDeFardo.diametro);
        printf("Quantidade: %d\n", atual->dado.qtDeFardos);
        printf("Tempo (em minutos): %d\n", atual->dado.tempoEmMin);
        printf("---------------------\n");
        atual = atual->next;
    }
}

/**
 * Calcula a área mínima de armazenagem e retorna o valor obtido
 * Usada na impressão dos resultados de consultarPorCultivar
 */
float calcularAreaMinimaArmazenagem(int qtFardos, int diametroCm) {
    if (qtFardos <= 0 || diametroCm <= 0) return 0.0;

    int colunas = (qtFardos + 2) / 3;  // arredonda para cima 
    float diametro_m = diametroCm / 100.0f;
    float fatorDeFolga = 1.25f;

    float area = colunas * diametro_m * diametro_m * fatorDeFolga;

    return area;  // em m²
}
