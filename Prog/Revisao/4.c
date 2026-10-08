#include <stdio.h>
#include <stdlib.h>

int contaParImpar(int v[], int tam, int *px, int *py) {
    int impares = 0;
    int pares = 0;
    for (int i = 0; i < tam; i++) {
        if (v[i]%2 == 0) {
            pares++;
        }
        else {
            impares++;
        }
    }

    *px = impares;
    *py = pares;

    return 0;
}

int main() {

    int n;
    scanf("%d", &n);
    int *vetor = malloc(sizeof(int)*n);
    int im, pr;

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    contaParImpar(vetor, n, &im, &pr);

    printf("Pares: %d\n", pr);
    printf("Impares: %d\n", im);

    return 0;
}