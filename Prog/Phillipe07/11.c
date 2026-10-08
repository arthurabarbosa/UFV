#include <stdio.h>
#include <stdlib.h>

int pont(int *vetor[], int tam) {
    int soma = 0;
    for (int i = 0; i < tam; i++) {
        soma += *vetor[i];
    }
    return soma;
}

int main() {

    int *v[10];
    for (int i = 0; i < 10; i++) {
        v[i] = (int *) malloc(sizeof(int));
        *(v[i]) = i + 1;
    }
    int x = pont(v, 10);
    for (int i = 0; i < 10; i++) {
        free(v[i]);
    }

    return 0;
}