#include <stdio.h>
#include <stdlib.h>

void func(int v[100]) {
    FILE *arquivo;
    arquivo = fopen("resultado.txt", "w");

    for (int i = 0; i < 100; i++) {
        fprintf(arquivo, "%p\n", &v[i]);
    }
    fclose(arquivo);
}