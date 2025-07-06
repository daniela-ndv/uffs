/* A função abaixo (Xmen) recebe um vetor v de tamanho n e realiza um determinado processamento.
Analise as instruções e apresente a equação que represente o número de vezes que cada instrução vai ser
executada e depois, usando a notação O, o pior caso. Coloque c1 x o número de vezes que a instrução
executa, somando todos os cálculos. */
/*
void Xmen(int *v, int n){
    int i=n;
    while (i >= 1){
        v[i] = converte(n); // Função converte é O(1)
        i=i/2;
    }
}*/

// Resposta:

void Xmen(int *v, int n){
    int i=n;                        // c1 * 1    
    while (i >= 1){                 // c2 * (log2 n)
        v[i] = converte(n);         // c3 * (log2 n)
        i=i/2;                      // c4 * 1
    }
}

/**
 * T(n) = c1 * 1 + (c2 * (log2 n )) + (c3 * (log2 n) + c4 * 1
 * T(n) = (c1 + c4) + (c2 + c3) * log2 n
 * O(log2 n) 
 */