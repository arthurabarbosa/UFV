#include <stdio.h>
#include <stdlib.h>

int* func(char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "r");
    int tam;
    fscanf(arquivo, "%d", &tam);

    int *array = malloc(sizeof(int)*tam);
    for (int j = 0; j < tam; j++) {
        fscanf(arquivo, "%d", &array[j]);
    }
    fclose(arquivo);

    return array;
}