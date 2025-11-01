#include <stdio.h> 
#include <stdlib.h>
#include <time.h>


//Questões para serem entregues. 

//1- Rode o código e verifique se está funcionando corretamente a partir do debug. 

//2- Crie uma variável para indicar quantas operações de comparação foram executadas pelo algortimo de bublle e pelo Insertion. Para a mesma entrada de 10000 elementos quantas comparações foram realizadas? 

//3- Quais são as diferenças entre os métodos bubble e insertion sort? 

//4- Existe algum caso em que o buble é melhor que o sort em número de comparações?

//5 - Compute o tempo para fazer o ordenamento de um mesmo vetor randômico com 100000 valores usando o bubble e o insertion. 

void insertionSort(int n, int* ptr){

    int i,j, min;
    long long int contador=0;
    for (i = 1; i < n; i++) {   
        
        min=ptr[i];
        for (j=i; j>=1 && min< ptr[j-1];j--){
            ptr[j]=ptr[j-1];
            contador += 1;
        }   
        ptr[j]=min;
    }

    printf("sort vector\n");
    for (int i=0;i<n;i++){
        printf("%d ", ptr[i]);
    }

    printf("\nComparações insertion: %i", contador);
}

void bubbleSort(int n, int* ptr){
    long long int contador = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            contador++; // conta a comparação
            if (ptr[j] > ptr[j+1]){
                int temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
    }
    printf("\nComparações bubble: %d\n", contador);
}

int main() 
{ 
    // vector size
    long int n = 100000; 
    // memory allocation
    int *vet1 = (int*)malloc(n * sizeof(int));
    int *vet2 = (int*)malloc(n * sizeof(int));
    srand(time(NULL));

   
    for (int i=0; i< n; i++){
        int valor = rand()%100000;
        vet1[i] = valor;
        vet2[i] = valor;
    }    
    
    clock_t begin1 = clock();    
    insertionSort(n, vet1); 
    clock_t end1 = clock();
    double time_spent_insertion = (double)(end1 - begin1) / CLOCKS_PER_SEC;

    clock_t begin2 = clock();  
    bubbleSort(n, vet2); 
    clock_t end2 = clock();
    double time_spent_bubble = (double)(end2 - begin2) / CLOCKS_PER_SEC;

    printf("Insertion: end time: %f\n", time_spent_insertion);
    printf("Bubble: end time: %f\n", time_spent_bubble);

    free(vet1);
    free(vet2);
    return 0; 
} 




