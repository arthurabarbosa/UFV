#include <stdio.h>
#include <stdlib.h>

int recsoma(int *p, int tam) {
    if (tam == 0) {
        return 0;
    }
    int soma = *p+recsoma(p+1, tam-1);

    return soma;
}

int main() {

    int n;
    scanf("%d", &n);
    int *vetor = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    int resultado = recsoma(vetor, n);

    printf("%d", resultado);

    free(vetor);

    return 0;
}