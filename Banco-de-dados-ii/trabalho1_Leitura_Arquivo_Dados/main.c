/**
 * Esta atividade consiste em ler arquivos de metadados e dados para simular um select * from table.
 * Para tal, serão fornecidos três arquivos: um contendo o metadado da tabela (table.dic), 
 * outro o metadado dos atributos (att.dic) e 
 * um outro com os dados de uma das tabelas presentes no table.dic (11.dat).
 * 
 * Compilar: gcc -o select main.c table.c att.c data.c
 */

#include <stdio.h>
#include "table.h"
#include "att.h"
#include "data.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: ./select <nome_tabela>\n");
        return 1;
    }

    ttable t;

    if (!find_table(argv[1], &t)) {
        printf("Tabela '%s' não encontrada.\n", argv[1]);
        return 1;
    }

    tatt atts[50];

    int count = load_atts(t.idtable, atts, 50);

    if (count == 0) {
        printf("Nenhum atributo encontrado para a tabela '%s'.\n", argv[1]);
        return 1;
    }

    print_data(t.ptname, atts, count);
    
    return 0;
}