#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    
    int matriz[100][100];
    int valor = 1;
    int cima = 0, baixo = m-1;
    int esquerda = 0, direita = m-1;

    while (esquerda <= direita && cima <= baixo) {
        for (int i = esquerda; i <= direita; i++) {
            matriz[cima][i] = valor;
        }
        cima++;
        for (int i = cima; i <= baixo; i++) {
            matriz[i][direita] = valor;
        }
        direita--;
        if (cima <= baixo) {
            for (int i = direita; i >= esquerda; i--) {
                matriz[baixo][i] = valor;
            }
            baixo--;
        }
        if (esquerda <= direita) {
            for (int i = baixo; i >= cima; i--) {
                matriz[i][esquerda] = valor;
            }
            esquerda++;
        }
        valor++;
    }

    for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                printf("%3d", matriz[i][j]);
                if (j < m - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    return 0;
}