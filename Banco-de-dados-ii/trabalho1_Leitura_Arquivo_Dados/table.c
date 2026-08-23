#include <stdio.h>
#include <string.h>
#include "table.h"

#define TABLE_DIC "data-read/table.dic"

int find_table(char *name, ttable *out){
    FILE *f = fopen(TABLE_DIC, "rb");
    if (f == NULL){
        printf("Fatal error!\n");
		return 0;
    }

    // Lê no ponteiro "out"
    // fread retorna 1 se leu com sucesso
    while (fread(out, sizeof(ttable), 1, f)) {
        if(strcmp(out->ctname, name) == 0){ // retorna 0 quando são iguais 
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;    
}