#ifndef ATT_H
#define ATT_H

#include "types.h"

/** Retorna a quantidade de atributos encontrados 
 * idtable: o id da tabela será buscada 
 * *atts: ponteiro para um array onde os atributos encontrados serão armazenados
 * max: tamanho máximo do array atts, para evitar escrever além da memória alocada
*/
int load_atts(int idtable, tatt *atts, int max);

#endif