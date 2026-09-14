// Implementação

#include "Circulo.h"
#include <iostream>
#define PI 3.14159

Circulo::Circulo(double raio){
    this->raio_ = raio;
}

double Circulo::calcula_area(){
    return PI * raio_ * raio_;
}

void Circulo::imprime_area(){
    std::cout << "Area: " << calcula_area() << std::endl;
}

double Circulo::calcula_perimetro(){
    return 2 * PI * this->raio_;
}

void Circulo::imprime_perimetro(){
    std::cout << "Perímetro: " << calcula_perimetro() << std::endl;
}