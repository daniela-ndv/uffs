#include "Grafo.h"
#include <iostream>

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

/* Grafo passado por referência para alterar o mesmo objeto da chamada da função (na main) */
void tenta_inserir(Grafo &g, Aresta e) {
    try {
        g.insere_aresta(e);
    } catch (const exception &ex) {
        print_exception(ex);
    }
}

int main() {
    Grafo g(6);

    tenta_inserir(g, Aresta(0, 2));

    g.imprime_grafo();

    tenta_inserir(g, Aresta(-1, -2));
    tenta_inserir(g, Aresta(5, 7));
    tenta_inserir(g, Aresta(5, 1));
    tenta_inserir(g, Aresta(0, 4));
    tenta_inserir(g, Aresta(2, 5));
    tenta_inserir(g, Aresta(1, 4));

    g.imprime_grafo();

    bool p1 = g.eh_passeio({0, 2, 3, 5, 1});
    cout << "\neh_passeio({0, 2, 5, 1}) " << p1 << "\n";

    bool p2 = g.eh_passeio({0, 2, 5, 1, 4, 0});
    cout << "eh_passeio({0, 2, 5, 1, 4, 0}): " << p2 << "\n";

    bool c1 = g.eh_caminho({0, 2, 5, 1});
    cout << "eh_caminho({0, 2, 5, 1}): " << c1 << "\n";

    bool c2 = g.eh_caminho({0, 2, 5, 1, 4, 0});
    cout << "eh_caminho({0, 2, 5, 1, 4, 0}): " << c2 << "\n";

    return 0;
}