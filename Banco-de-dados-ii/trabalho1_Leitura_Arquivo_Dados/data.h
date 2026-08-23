#ifndef DATA_H
#define DATA_H

#include "types.h"

/** Lê o arquivo físico *ptname e imprime todos os registros formatados
 * *ptname: nome do arquivo de dados (ex: "11.dat")
 * *atts: array com os atributos da tabela
 * count: número de atributos
 */
void print_data(char *ptname, tatt *atts, int count);

#endif