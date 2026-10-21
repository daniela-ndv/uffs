#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

Grafo::Grafo(int num_vertices){
   if(num_vertices <= 0){
        throw(invalid_argument("Erro no construtor grafo(int): o número de vértices " + to_string(num_vertices) + "é inválido."));
   }

   num_vertices_ = num_vertices;
   num_arestas_ = 0;

   matriz_adj_.resize(num_vertices);
   for(int i = 0; i < num_vertices; i++){
        matriz_adj_[i].resize(num_vertices, 0);
   }
};

int Grafo::num_vertices(){
    return num_vertices_;
};

int Grafo::num_arestas(){
    return num_arestas_;
};

int Grafo::peso_aresta(Aresta e){
    valida_aresta(e);

    return matriz_adj_[e.v1][e.v2];    // 0 se não existe, peso positivo se existe
};

bool Grafo::tem_aresta(Aresta e){
    valida_aresta(e);

    return peso_aresta(e) != 0;  
};

void Grafo::insere_aresta(Aresta e){
    try {
        valida_aresta(e);
        valida_peso(e.peso);
    }
    catch(...) {
        throw_with_nested(runtime_error("Erro na operação insere_aresta(Aresta): a aresta " + e.to_string() + " é inválida!"));
    }
    
    if(!tem_aresta(e) && (e.v1 != e.v2)){
        matriz_adj_[e.v1][e.v2] = e.peso;    // peso só em v1 -> v2

        num_arestas_++;
    }
};

void Grafo::remove_aresta(Aresta e){
    try {
        valida_aresta(e);
    }
    catch(...) {
        throw_with_nested(runtime_error("Erro na operação remove_aresta(Aresta): a aresta " + e.to_string() + " é inválida!"));
    }

    if(tem_aresta(e)){
        matriz_adj_[e.v1][e.v2] = 0;   

        num_arestas_--;
    }
};

void Grafo::imprime_grafo(){

    for(int v = 0; v < num_vertices_; v++){
        cout << v << ": ";
        for(int n = 0; n < num_vertices_; n++){
            if(matriz_adj_[v][n] != 0) {   // n é vizinho de saída de v
                cout << " " << n << "(" << matriz_adj_[v][n] << ")";
            }
        }
        cout << "\n";
    }
};

int Grafo::grau_saida(int v){
    valida_vertice(v);

    int grau = 0;

    for(int i = 0; i < num_vertices_; i++){
        if(matriz_adj_[v][i] != 0){
            grau++;
        }
    }

    return grau; 
};

int Grafo::grau_entrada(int v){
    valida_vertice(v);

    int grau = 0;

    for(int i = 0; i < num_vertices_; i++){
        if(matriz_adj_[i][v] != 0){
            grau++;
        }
    }

    return grau; 
};

bool Grafo::caminho(int v, int w, int marcado[], int cont){

    for (int i = 0; i < cont * 2; i++) printf("-");    // cada nível de profundidade imprime 2 traços
    printf("caminho(%d, %d)\n", v, w);

    if (v == w){ 
        return true;
    }
    
    marcado[v] = 1;

    for (int u = 0; u < num_vertices_; u++){
        if (matriz_adj_[v][u] != 0 && marcado[u] == 0){
            if (caminho(u, w, marcado, cont + 1)){
                return true;
            }
        }
    }

    return false;
};

void Grafo::valida_vertice(int v){
    if((v < 0) || (v >= num_vertices_)){
        throw out_of_range("Índice de vértice inválido: " + to_string(v));
    }
};

void Grafo::valida_aresta(Aresta e){
    valida_vertice(e.v1);
    valida_vertice(e.v2);
};

void Grafo::valida_peso(int peso){
    if(peso <= 0){
        throw invalid_argument("Peso inválido: " + to_string(peso) + " (o peso deve ser positivo)");
    }
};