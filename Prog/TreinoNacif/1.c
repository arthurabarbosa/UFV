#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *v = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int organizado = 1;
    int encontrou_nao_zero = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] != 0) {
            encontrou_nao_zero = 1;
        } else {
            if (encontrou_nao_zero == 1) {
                organizado = 0;
                break;
            }
        }
    }

    if (organizado == 1) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    free(v);
    return 0;
}