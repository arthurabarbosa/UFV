#include <stdio.h>
#include <stdlib.h>

void segundosExtremos(int v[], int tam, int *ptrx, int *ptry) {
    int maior = v[0];
    int menor = v[0];

    for (int i = 0; i < tam; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
        if (v[i] < menor) {
            menor = v[i];
        }
    }

    int segundomaior = menor;
    int segundomenor = maior;

    for (int i = 0; i < tam; i++) {
        if (v[i] < maior && v[i] > segundomaior) {
            segundomaior = v[i];
        }
        if (v[i] > menor && v[i] < segundomenor) {
            segundomenor = v[i];
        }
    }

    *ptrx = segundomaior;
    *ptry = segundomenor;
}


int main() {

    int n;
    int smaior, smenor;
    scanf("%d", &n);
    int *vetor = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    segundosExtremos(vetor, n, &smaior, &smenor);

    printf("Segundo menor: %d\n", smenor);
    printf("Segundo maior: %d\n", smaior);

    free(vetor);

    return 0;
}