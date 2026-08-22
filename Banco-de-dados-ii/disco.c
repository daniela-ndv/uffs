/**
 * Struct e funções para reproduzir um acesso simples ao disco, salvando os dados em arquivo, utilizando fseek para posicionar o cursor.
 * Compilar: gcc -Wall -o disco disco.c
 */

#include <stdio.h>
#include <string.h>

#define TRUE 1

struct trec {
	int id;
	char name[31];
};
typedef struct trec rec;

int saveRec(rec r, FILE *f){
	if(fwrite(&r, sizeof(rec), 1, f)) return 1; 	// fwrite(ptr, size em bytes, count unidades a serem gravadas, fp)
	else return 0;
}

int readRec(rec *r, FILE *f){
	if(fread(r, sizeof(rec), 1, f)) return 1;
	else return 0;
}

int main(){
	FILE *f;
	rec myr;
	
	f=fopen("teste.dat","rb+");
	if(f == NULL){ 
		f=fopen("teste.dat","wb+");
		if(f == NULL) {
			printf("Fatal error!\n");
			return 1;
		}
	}
	fseek(f,0,SEEK_END);
	
	while(TRUE){
		printf("ID: ");
		scanf("%d", &myr.id);
		
		if(myr.id == 0){ break; }
		
		printf("Name: ");
		scanf("%s", myr.name);
		
		if(!saveRec(myr, f)){
			printf("Error in saving record. Aborting\n");
			return 1;
		}
	}
	
	fseek(f,0,SEEK_SET); 
	
	while(readRec(&myr, f)){
		printf("ID: %d | Name: %s \n", myr.id, myr.name);
	}
	
	fclose(f);
	return 0;
}
