/**
 * Representação computacional de uma árvore usando lista de um vetor pai
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#define NUM_VERTICES 14

using namespace std;

void inserir_pai(int nodo_pai, int nodo_filho, vector<int> &v_pai){
    if (nodo_pai == -1){
        v_pai[nodo_filho] = nodo_pai;
        cout << "Nó raiz: " << nodo_filho << "\n";
        return;
    } 

    if(v_pai[nodo_pai] != -2){
        v_pai[nodo_filho] = nodo_pai;
        cout << "Pai " << nodo_pai << " inserido para o nó " << nodo_filho << "\n";
        return;
    }

    cout << "Não foi possível adicionar. O nodo pai não existe." << "\n";
}

int main(){

    vector<int> nodos_pai(NUM_VERTICES, -2); // Inicialização com valor inválido (-2) em todos os índices

    inserir_pai(4, 1, nodos_pai);

    inserir_pai(-1, 0, nodos_pai); // Raiz
    inserir_pai(0, 1, nodos_pai); 
    inserir_pai(0, 2, nodos_pai); 
    inserir_pai(0, 3, nodos_pai); 
    inserir_pai(1, 4, nodos_pai); 
    inserir_pai(2, 5, nodos_pai);
    inserir_pai(3, 6, nodos_pai); 
    inserir_pai(3, 7, nodos_pai); 
    inserir_pai(3, 8, nodos_pai); 
    inserir_pai(5, 9, nodos_pai); 
    inserir_pai(5, 10, nodos_pai); 
    inserir_pai(5, 11, nodos_pai); 
    inserir_pai(5, 12, nodos_pai); 
    inserir_pai(5, 13, nodos_pai); 

    cout << "\nVetor pai: " << "\n";
    for (int i = 0; i < NUM_VERTICES; i++){
        if (nodos_pai[i] == -1){
            cout << "No v" << i << " -> É a raiz\n";
        } else {
            cout << "No v" << i << " -> Pai: v" << nodos_pai[i] << "\n";
        }
    }

    return 0;
}