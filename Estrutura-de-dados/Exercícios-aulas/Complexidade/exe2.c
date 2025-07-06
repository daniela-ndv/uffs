/* Exercício: Calcule a complexidade*/

void imprime_matriz(int n, int m[n][n]) {
    for (int i = 0; i < n; i++){                                   // c1 * n
        for (int j = 0; j < n; j++){                               // c2 * n * n (for aninhado)
           printf("matriz[%d][%d] = %d\n", i, j, m[i][j]);         // c3 * n * n
        }
    }
}

// Resposta:

// T(n) = c1 * n + c2 * n * n + c3 * n * n
// T(n) = c1 * n + c2 * n² + c3 * n²
// O(n²)
