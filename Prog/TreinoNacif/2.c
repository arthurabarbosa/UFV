#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int matriz[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int total_elementos = n*m;
    int *aux = malloc(sizeof(int)*total_elementos);
    
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            aux[k] = matriz[i][j];
            k++;
        }
    }

    for (int i = 0; i < total_elementos-1; i++) {
        for (int j = 0; j < total_elementos-i-1; j++) {
            if (aux[j] > aux[j + 1]) {
                int temp = aux[j];
                aux[j] = aux[j + 1];
                aux[j + 1] = temp;
            }
        }
    }

    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = aux[k];
            k++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    free(aux);
    return 0;
}