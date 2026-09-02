#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>

class Grafo {
    public:
        Grafo(int num_vertices);

        int num_vertices();
        int num_arestas();
        
        bool tem_aresta(Aresta e);

        /* Insere uma aresta no grafo caso a aresta ainda não existe e não seja um laço*/
        void insere_aresta(Aresta e);

        /* Remove uma aresta do grafo caso a tarefa exista no grafo */
        void remove_aresta(Aresta e);

        void imprime_grafo();

        /* Sequência em que cada vértice do percurso é vizinho do seu antecessor */
        bool eh_passeio(std::vector<int> sequencia);

        /* Passeio onde não há vértices repetidos */
        bool eh_caminho(std::vector<int> sequencia);

        /* Retorna o grau de um vértice (número de arestas que estão ligadas a ele)*/
        int grau(int v);

        /* Retorna o grau mínimo de um vértice */
        int grauMin();

        /* Retorna o grau máximo de um vértice */
        int grauMax();

        /* Existência de um caminho entre dois vértices */
        bool caminho(int v, int w, int marcado[], int cont); 

    private:
       std::vector<std::vector<int>> matriz_adj_;
       int num_vertices_;
       int num_arestas_;

       void valida_vertice(int v);
       void valida_aresta(Aresta e);
};

#endif /* GRAFO_H */