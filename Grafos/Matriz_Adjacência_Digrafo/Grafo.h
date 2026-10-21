#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>

/**
 * Digrafo (simples) ponderado, com pesos positivos, representado por matriz de adjacência.
 * 
 * matriz_adj_[i][j] == 1 significa que existe a aresta (vi, vj), ou seja,
 * a aresta sai de vi (cauda) e entra em vj (cabeça).
 * Como os pesos são sempre positivos, o 0 nunca é um peso válido e pode indicar "sem aresta".
 * 
 * Digrafo simples: sem arestas paralelas (a matriz guarda 0 ou 1 por posição) e sem laços.
 */
class Grafo {
    public:
        Grafo(int num_vertices);

        /* Ordem do digrafo: |V| */
        int num_vertices();

        /* Tamanho do digrafo: |E| */
        int num_arestas();
        
        /* Verifica se a aresta (v1, v2) existe, isto é, se v2 é vizinho de saída de v1 */
        bool tem_aresta(Aresta e);

        /* Retorna o peso da aresta (v1, v2), ou 0 se ela não existe (o peso de e é ignorado) */
        int peso_aresta(Aresta e);

        /* Insere uma aresta no grafo caso a aresta ainda não existe e não seja um laço */
        void insere_aresta(Aresta e);

        /* Remove uma aresta do grafo caso a tarefa exista no grafo */
        void remove_aresta(Aresta e);

        void imprime_grafo();

        /* Retorna o grau de saída [d+(v)] de um vértice */
        int grau_saida(int v);

        /* Retorna o grau de entrada [d-(v)] de um vértice */
        int grau_entrada(int v);

        /* Existência de um caminho de v até w (percorrendo as arestas no seu sentido) */
        bool caminho(int v, int w, int marcado[], int cont); 

    private:
       std::vector<std::vector<int>> matriz_adj_;
       int num_vertices_;
       int num_arestas_;

       void valida_vertice(int v);
       void valida_aresta(Aresta e);
       void valida_peso(int peso);
};

#endif /* GRAFO_H */