#include "Aresta.h"
#include <string>

using namespace std;

Aresta::Aresta(int v1, int v2, int peso) : v1(v1), v2(v2), peso(peso) {
   // Atributos foram construídos na inicialização da função, pois v1, v2 e peso são constantes
};

string Aresta::to_string() {
   return std::to_string(v1) + " " + std::to_string(v2) + " (peso " + std::to_string(peso) + ")";
}