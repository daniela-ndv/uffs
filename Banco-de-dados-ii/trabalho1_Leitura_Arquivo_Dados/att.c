#include <stdio.h>
#include "att.h"

#define ATT_DIC "data-read/att.dic"

int load_atts(int idtable, tatt *atts, int max){
    FILE *f = fopen(ATT_DIC, "rb");
    if (f == NULL){
        printf("Fatal error!\n");
		return 0;
    }

    int count = 0;
    tatt tmp;

    while(count < max && fread(&tmp, sizeof(tatt), 1, f)){
        if(tmp.idtable == idtable) {
            atts[count] = tmp;
            count++;
        }
    }

    fclose(f);
    return count;
};