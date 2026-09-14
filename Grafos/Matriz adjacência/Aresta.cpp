#include "Aresta.h"
#include <string>

using namespace std;

Aresta::Aresta(int v1, int v2) : v1(v1), v2(v2) {
   // Atributos foram construídos na inicialização da função, por v1 e v2 são constantes   
};

string Aresta::to_string() {
   return std::to_string(v1) + " " + std::to_string(v2);
}