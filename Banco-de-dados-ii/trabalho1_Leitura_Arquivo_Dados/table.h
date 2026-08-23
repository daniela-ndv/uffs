#ifndef TABLE_H
#define TABLE_H

#include "types.h"

/** Retorna 1 se encontrou, 0 caso contrário 
 * *name: nome lógico da tabela a ser buscada
 * *out: ponteiro para a struct onde o registro encontrado será gravado
*/
int find_table(char *name, ttable *out);

#endif