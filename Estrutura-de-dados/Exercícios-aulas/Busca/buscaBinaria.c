int buscaBinaria(int *vet, int inicio, int fim, int chave) {
    if (inicio > fim) {
        return -1; // Caso base: chave não encontrada
    }

    int meio = (inicio + fim) / 2;

    if (vet[meio] == chave) {
        return meio; // Encontrou a chave
    }

    if (chave < vet[meio]) {
        return buscaBinaria(vet, inicio, meio - 1, chave); // Busca na metade esquerda
    } else {
        return buscaBinaria(vet, meio + 1, fim, chave);    // Busca na metade direita
    }
}
