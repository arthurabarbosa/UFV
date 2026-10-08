#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    int *v = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        *(v+i) = 0;
    }

    free(v);
    return 0;
}