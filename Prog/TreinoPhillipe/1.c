#include <stdio.h>
#include <stdlib.h>

void estatisticas(int v[], int n, int *x, int *y, int *z) {
    int maior = v[0];
    int menor = v[0];
    int soma = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
        if (v[i] < menor) {
            menor = v[i];
        }
        soma += v[i];
    }
    
    int media = soma/n;

    *x = maior;
    *y = menor;
    *z = media;
}

int main () {

    int n;
    int menor, maior, media;
    scanf("%d", &n);
    int *v = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    estatisticas(v, n, &menor, &maior, &media);

    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);
    printf("Media: %d\n", media);

    return 0;
}