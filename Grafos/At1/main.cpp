#include "Circulo.h"
#include <iostream>

// g++ -pedantic -Wall main.cpp Circulo.cpp -o circulo 
// ./circulo

int main(){ 
    Circulo c1(5.0);
    Circulo c2(1.0);

    std::cout << "Círculo 1: " << std::endl;
    c1.imprime_area();
    c1.imprime_perimetro();

    std::cout << "\nCírculo 2: " << std::endl;
    c2.imprime_area();
    c2.imprime_perimetro();

    return 0;
}