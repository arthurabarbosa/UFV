#include <stdio.h>
#include <stdlib.h>

int bubblesort(int vetor[], int tam) {
    int aux;
    for (int i = 0; i < tam-1; i++) {
        for (int j = 0; j < tam-1-i; j++) {
            if (vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    return 0;
}

int main() {

    int n;
    scanf("%d", &n);
    int *v = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    printf("Vetor antes:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    bubblesort(v, n);

    printf("Vetor depois:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}