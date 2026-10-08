#include <stdio.h>

int main() {

    int v[20];

    for (int i = 0; i < 20; i++) {
        scanf("%d", &v[i]);
    }

    int indice_maior = 0;
    int maior = v[0];

    for (int i = 0; i < 20; i++) {
        if (v[i] > maior) {
            maior = v[i];
            indice_maior = i;
        }
    }

    printf("Maior: %d. Posição: %d.", maior, (indice_maior+1));

    return 0;
}