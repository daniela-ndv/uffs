#include <stdio.h>
#include "data.h"

void print_header(tatt *atts, int count){
    for(int i = 0; i < count; i++) {
        if (i > 0) printf("  ");
        printf("%s", atts[i].atname);
    }
    printf("\n");

    for (int i = 0; i < count; i++)
        for (int j = 0; j < atts[i].atlen + 2; j++)
            printf("-");
    printf("\n");
}

void print_data(char *ptname, tatt *atts, int count){
    char path[40];
    snprintf(path, sizeof(path), "data-read/%s", ptname);
    FILE *f = fopen(path, "rb+");
    if (f == NULL) { printf("Fatal error!\n"); return; }

    print_header(atts, count);

    char buf[256];
    int  ival;
    float fval;
    int ok = 1;

    while (ok) {
        for (int i = 0; i < count && ok; i++) {
            if (atts[i].attype == 'I') {
                ok = fread(&ival, sizeof(int), 1, f);
                if (ok) printf("%-*d  ", atts[i].atlen, ival);
            } else if (atts[i].attype == 'F') {
                ok = fread(&fval, sizeof(float), 1, f);
                if (ok) printf("%-*g  ", atts[i].atlen, fval);
            } else {
                ok = fread(buf, atts[i].atlen, 1, f);
                if (ok) { buf[atts[i].atlen] = '\0'; printf("%-*s  ", atts[i].atlen, buf); }
            }
        }
        if (ok) printf("\n");
    }

    fclose(f);
}