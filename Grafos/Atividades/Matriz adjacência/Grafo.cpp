#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

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

bool Grafo::tem_aresta(Aresta e){
    if (matriz_adj_[e.v1][e.v2] != 0) {
        return true;
    }
    return false;
};

void Grafo::insere_aresta(Aresta e){
    try {
        valida_aresta(e);
    }
    catch(...) {
        throw_with_nested(runtime_error("Erro na operação insere_aresta(Aresta): a aresta " + e.to_string() + " é inválida!"));
    }
    
    if(!tem_aresta(e) && (e.v1 != e.v2)){
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

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
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
};

void Grafo::imprime_grafo(){
    cout << "Grafo:\n";

    for(int v = 0; v < num_vertices_; v++){
        cout << v << ": ";
        for(int n = 0; n < num_vertices_; n++){
            if(matriz_adj_[v][n] != 0) {
                cout << " " << n;
            }
        }
        cout << "\n";
    }
};

bool Grafo::eh_passeio(vector<int> sequencia){
    if(sequencia.size() < 1){ 
        return false;
    }
    if(sequencia.size() == 1){ 
        return true; // com 1 vertice é passeio
    }

    for(int i = 0; i < (int)sequencia.size() - 1; i++){
        try {
            valida_aresta(Aresta(sequencia[i], sequencia[i + 1]));
        } catch(...) {
            return false;
        }

        if(!tem_aresta(Aresta(sequencia[i], sequencia[i + 1]))){
            return false;
        }
    }

    return true;
};

bool Grafo::eh_caminho(vector<int> sequencia){
    if(!eh_passeio(sequencia)){
        return false;
    }

    /* Vetor local usado para marcar os vértices visitados */
    vector<bool> visitado(num_vertices_, false);

    /* verifica vértices repetidos */
    /* Para cada vértice da sequência se já foi marcado (true), há repetição. Caso contrário, marca como visitado e continua */
    for(int i = 0; i < (int)sequencia.size(); i++){
        int v = sequencia[i];

        if(visitado[v]){ 
            return false;
        }
        visitado[v] = true;
    }

    return true;
};

int Grafo::grau(int v){
    try { 
        valida_vertice(v);
    }
    catch (...) {
        throw_with_nested(runtime_error("Erro na operação grau(int): o vértice é inválido!"));
    }

    int grau = 0;

    for(int i = 0; i < num_vertices_; i++){
        int temAresta = 0;
        temAresta = matriz_adj_[v][i];

        if(temAresta){
            grau++;
        }
    }

    return grau; 
};

int Grafo::grauMin(){
    int grauMin = num_arestas_; 

    for(int i = 0; i < num_vertices_; i++){
        int grau = 0;
        grau = Grafo::grau(i);

        if(grau < grauMin){
            grauMin = grau;
        } 
    }

    return grauMin;
};

int Grafo::grauMax(){
    int grauMax = 0;

    for(int i = 0; i < num_vertices_; i++){
        int grau = 0;
        grau = Grafo::grau(i);

        if(grau > grauMax){
            grauMax = grau;
        }
    }

    return grauMax;
}

void Grafo::valida_vertice(int v){
    if((v < 0) || (v >= num_vertices_)){
        throw out_of_range("Índice de vértice inválido: " + to_string(v));
    }
};

void Grafo::valida_aresta(Aresta e){
    valida_vertice(e.v1);
    valida_vertice(e.v2);
};
