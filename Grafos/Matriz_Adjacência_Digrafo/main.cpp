#include "Grafo.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

// g++ -pedantic -Wall main.cpp Grafo.cpp Aresta.cpp -o grafo

void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
    try{
        Grafo g(4);

        // insere_aresta: Aresta(cauda, cabeça, peso)
        g.insere_aresta(Aresta(0, 1, 4));
        g.insere_aresta(Aresta(0, 2, 7));
        g.insere_aresta(Aresta(3, 0, 2));

        // imprime_grafo: vizinho(peso)
        cout << "Grafo g (vertice: vizinho(peso)):\n";
        g.imprime_grafo();

        // peso_aresta: 0 indica que a aresta não existe
        cout << "\npeso_aresta(0, 1): " << g.peso_aresta(Aresta(0, 1)) << "\n";
        cout << "peso_aresta(1, 0): " << g.peso_aresta(Aresta(1, 0)) << " (0 = sem aresta)\n";

        // remove_aresta: volta a "sem aresta"
        g.remove_aresta(Aresta(0, 1));
        cout << "\nApos remover (0, 1):\n";
        cout << "tem_aresta(0, 1): " << g.tem_aresta(Aresta(0, 1)) << "\n";

        // peso não positivo é rejeitado
        cout << "\nTentando inserir (1, 2) com peso -5:\n";
        try {
            g.insere_aresta(Aresta(1, 2, -5));
        } catch(const exception &e){
            print_exception(e);
        }
    }
    catch(const exception &e){
        print_exception(e);
    }

    return 0;
}