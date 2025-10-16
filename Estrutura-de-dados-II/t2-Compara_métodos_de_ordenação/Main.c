#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long trocas;

void copia(int *origem, int *destino, int size) {
    for (int i = 0; i < size; i++) {
        destino[i] = origem[i];
    }
}

// ============ BUBBLE SORT ============
void bubbleSort(int *A, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                trocas++;
            }
        }
    }
}

// ============ INSERTION SORT ============
void insertionSort(int *A, int size) {
    for (int i = 1; i < size; i++) {
        int chave = A[i];
        int j = i - 1;
        
        while (j >= 0 && A[j] > chave) {
            A[j + 1] = A[j];
            trocas++;
            j--;
        }
        A[j + 1] = chave;
    }
}

// ============ HEAP SORT ============
void heapify(int *A, int size, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    
    if (esq < size && A[esq] > A[maior])
        maior = esq;
    
    if (dir < size && A[dir] > A[maior])
        maior = dir;
    
    if (maior != i) {
        int temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        trocas++;
        heapify(A, size, maior);
    }
}

void heapSort(int *A, int size) {
    // Constrói o heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(A, size, i);
    
    // Extrai elementos do heap um por um (fase de seleção)
    for (int i = size - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        trocas++;
        heapify(A, i, 0);
    }
}

// ============ QUICK SORT ============
int partition(int *A, int baixo, int alto) {
    int pivo = A[alto];
    int i = baixo - 1;
    
    for (int j = baixo; j < alto; j++) {
        if (A[j] < pivo) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            trocas++;
        }
    }
    
    int temp = A[i + 1];
    A[i + 1] = A[alto];
    A[alto] = temp;
    trocas++;
    
    return i + 1;
}

void quickSortRec(int *A, int baixo, int alto) {
    if (baixo < alto) {
        int pi = partition(A, baixo, alto);
        quickSortRec(A, baixo, pi - 1);
        quickSortRec(A, pi + 1, alto);
    }
}

void quickSort(int *A, int size) {
    quickSortRec(A, 0, size - 1);
}


// ============ Funções auxiliares============
void gerarArrayAleatorio(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

// ============ main ============
int main() {
    srand(time(NULL));
    
    int tamanhos[] = {100, 1000, 5000, 10000, 50000, 100000}; 
    int numTamanhos = 6; 
    int numExecucoes = 3;
        
    long long trocasBubble[numTamanhos];
    long long trocasInsertion[numTamanhos];
    long long trocasHeap[numTamanhos];
    long long trocasQuick[numTamanhos];
    
    double tempoBubble[numTamanhos];
    double tempoInsertion[numTamanhos];
    double tempoHeap[numTamanhos];
    double tempoQuick[numTamanhos];
    
    for (int i = 0; i < numTamanhos; i++) {
        int size = tamanhos[i];
        int *vetor = (int*)malloc(size * sizeof(int));
        int *bubbleV = (int*)malloc(size * sizeof(int));
        int *insertionV = (int*)malloc(size * sizeof(int));
        int *heapV = (int*)malloc(size * sizeof(int));
        int *quickV = (int*)malloc(size * sizeof(int));
        
        // Médias de trocas e tempo
        long long somaB = 0, somaI = 0, somaH = 0, somaQ = 0;
        double tempoB = 0, tempoI = 0, tempoH = 0, tempoQ = 0;
        
        for (int exec = 0; exec < numExecucoes; exec++) {
            gerarArrayAleatorio(vetor, size);
            
            // Bubble Sort
            copia(vetor, bubbleV, size);
            trocas = 0;
            clock_t inicio = clock();
            bubbleSort(bubbleV, size);
            clock_t fim = clock();
            somaB += trocas;
            tempoB += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            
            // Insertion Sort
            copia(vetor, insertionV, size);
            trocas = 0;
            inicio = clock();
            insertionSort(insertionV, size);
            fim = clock();
            somaI += trocas;
            tempoI += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            
            // Heap Sort
            copia(vetor, heapV, size);
            trocas = 0;
            inicio = clock();
            heapSort(heapV, size);
            fim = clock();
            somaH += trocas;
            tempoH += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            
            // Quick Sort
            copia(vetor, quickV, size);
            trocas = 0;
            inicio = clock();
            quickSort(quickV, size);
            fim = clock();
            somaQ += trocas;
            tempoQ += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        }
        
        // Calcular médias
        trocasBubble[i] = somaB / numExecucoes;
        trocasInsertion[i] = somaI / numExecucoes;
        trocasHeap[i] = somaH / numExecucoes;
        trocasQuick[i] = somaQ / numExecucoes;
        
        tempoBubble[i] = tempoB / numExecucoes;
        tempoInsertion[i] = tempoI / numExecucoes;
        tempoHeap[i] = tempoH / numExecucoes;
        tempoQuick[i] = tempoQ / numExecucoes;
        
        free(vetor);
        free(bubbleV);
        free(insertionV);
        free(heapV);
        free(quickV);
    }
    
    printf("NUMERO DE TROCAS:\n");
    printf("%-10s %-15s %-15s %-15s %-15s\n", "Tamanho", "Bubble", "Insertion", "Heap", "Quick");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < numTamanhos; i++) {
        printf("%-10d %-15lld %-15lld %-15lld %-15lld\n", tamanhos[i], trocasBubble[i], trocasInsertion[i], trocasHeap[i], trocasQuick[i]);
    }
    
    printf("\n\nTEMPO DE EXECUÇÃO (segundos - media de 3 execuções):\n");
    printf("%-10s %-15s %-15s %-15s %-15s\n", "Tamanho", "Bubble", "Insertion", "Heap", "Quick");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < numTamanhos; i++) {
        printf("%-10d %-15.6f %-15.6f %-15.6f %-15.6f\n", tamanhos[i], tempoBubble[i], tempoInsertion[i], tempoHeap[i], tempoQuick[i]);
    }
    
    printf("\nAnálise concluida com sucesso!\n");
    
    return 0;
}
