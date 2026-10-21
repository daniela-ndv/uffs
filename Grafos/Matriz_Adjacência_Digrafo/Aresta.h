#ifndef ARESTA_H

#define ARESTA_H

#include <string>

/**
 * Aresta ponderada de um digrafo: par ordenado (v1, v2) com um peso.
 * v1 é a cauda da aresta (de onde sai) e v2 é a cabeça (onde entra) e peso é o custo da aresta. 
 */
class Aresta {
    public:
        Aresta(int v1, int v2, int peso = 1);

        const int v1;     // cauda
        const int v2;     // cabeça
        const int peso;   // peso (positivo) 

        std::string to_string();
};

#endif /* ARESTA_H */