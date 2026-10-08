#include <stdio.h>
#include <stdlib.h>

void contaParImpar(int v[], int tam, int *x, int *y) {
    int pares = 0;
    int impares = 0;
    for (int i = 0; i < tam; i++) {
        if (*(v+i)%2 == 0) {
            pares++;
        }
        else {
            impares++;
        }
    }

    *x = pares;
    *y = impares;
}



int main () {

    int n;
    int pr, im;
    scanf("%d", &n);
    int *vetor = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &*(vetor+i));
    }

    contaParImpar(vetor, n, &pr, &im);

    printf("Pares: %d\n", pr);
    printf("Impares: %d\n", im);

    free(vetor);        

    return 0;
}