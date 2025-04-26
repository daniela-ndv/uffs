#include <stdio.h>

typedef struct tdata {
    int dia;
    int mes;
    int ano;
} Data;

int main(void){

    Data data[3];

    for(int i = 0; i < 3; i++){
        printf("Informe a data %d (no formato DD/MM/AAAA): ", i+1);
        scanf("%d/%d/%d", &data[i].dia, &data[i].mes, &data[i].ano);
    }

    printf("\n****** Datas ******\n");
    for(int i = 0; i < 3; i++){
        printf("Data %d: %d/%d/%d\n", i+1, data[i].dia, data[i].mes, data[i].ano);
    }

    return 0;
}