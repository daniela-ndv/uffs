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

int main() {
    try{
        Grafo g(6);
        Grafo g2(4);

        g.insere_aresta(Aresta(0, 1));

        //g.imprime_grafo();

        //g.insere_aresta(Aresta(-1, -2));
        //g.insere_aresta(Aresta(5, 7));
        g.insere_aresta(Aresta(1, 3));
        g.insere_aresta(Aresta(0, 2));
        g.insere_aresta(Aresta(0, 4));
        g.insere_aresta(Aresta(4, 2));
        g.insere_aresta(Aresta(1, 4));
        g.insere_aresta(Aresta(3, 4));
        g.insere_aresta(Aresta(3, 5));

        cout << "Grafo g:\n";
        g.imprime_grafo();

        g2.insere_aresta(Aresta(0, 1));
        g2.insere_aresta(Aresta(2, 3));

        cout << "\nGrafo g2:\n";
        g2.imprime_grafo();

        /*bool p1 = g.eh_passeio({2, 0, 1, 4, 0});
        cout << "\neh_passeio({2, 0, 1, 4, 0}) " << p1 << "\n";

        bool p2 = g.eh_passeio({2, 4, 5});
        cout << "eh_passeio({2, 4, 5}): " << p2 << "\n";

        bool c1 = g.eh_caminho({2, 0, 1, 4, 0});
        cout << "eh_caminho({2, 0, 1, 4, 0}): " << c1 << "\n";

        bool c2 = g.eh_caminho({5, 3, 4});
        cout << "eh_caminho({5, 3, 4}): " << c2 << "\n";

        cout << "\nGraus das arestas do grafo g: \n";

        for(int i = 0; i < g.num_vertices(); i++){
            int grau_i = 0;
            grau_i = g.grau(i);

            cout << "grau v = " << i << ": " << grau_i << "\n";
        }

        int grauMin = g.grauMin();
        cout << "\nGrau mínimo de g: " << grauMin << "\n";

        int grauMax = g.grauMax();
        cout << "Grau máximo de g: " << grauMax << "\n"; */

        cout << "\n";

        int marcado[6] = {0};
        bool temCaminho = g.caminho(0, 5, marcado, 0);
        cout << "Tem caminho (0, 5) em g: " << temCaminho << "\n";

        cout << "\n";
        
        int marcado2[4] = {0};
        bool temCaminho2 = g2.caminho(0, 2, marcado2, 0);
        cout << "Tem caminho (0, 2) em g2: " << temCaminho2 << "\n";

    }
    catch(const exception &e){
        print_exception(e);
    }

    return 0;
    
}