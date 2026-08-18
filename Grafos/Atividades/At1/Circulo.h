// Interface

class Circulo {
    public:
        Circulo(double raio);

        double calcula_area();
        void imprime_area();
        double calcula_perimetro();
        void imprime_perimetro();
    private:
        double raio_;
};