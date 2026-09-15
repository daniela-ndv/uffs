#ifndef ARVORE_H

#define ARVORE_H

#include <vector>

#define NUM_VERTICES 14

/* Insere o pai de um nó no vetor pai, validando limites e ciclo trivial (nodo_pai == nodo_filho) */
void inserir_pai(int nodo_pai, int nodo_filho, std::vector<int> &v_pai);

#endif /* ARVORE_H */
