#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *v = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int pares = 0;
    int impares = 0;

    for (int i = 0; i < n; i++) {
        if (v[i]%2 == 0) {
            pares++;
        }
        else {
            impares++;
        }
    }

    if (impares == pares) {
        printf("S");
    }
    else {
        printf("N");
    }
    return 0;
}