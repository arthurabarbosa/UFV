#include <stdio.h>
#include <stdlib.h>

int estatisticas(int vetor[], int tam, int *ptrx, int *ptry, int *ptrz) {
    int menor = vetor[0];
    int maior = vetor[0];
    int soma = 0;

    for (int i = 0; i < tam; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
        soma += vetor[i];
    }

    int media = soma/tam;

    *ptrx = menor;
    *ptry = maior;
    *ptrz = media;

    return 0;
}

int main() {

    int n;
    scanf("%d", &n);
    int *v = malloc(sizeof(int)*n);
    int x, y, z;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    estatisticas(v, n, &x, &y, &z);

    printf("Menor: %d\n", x);
    printf("Maior: %d\n", y);
    printf("Media: %d\n", z);

    return 0;
}