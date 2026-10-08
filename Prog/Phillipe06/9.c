#include <stdio.h>

int gato(char str[]) {
    int tamanho = 0;
    printf("String: %s\n", str);
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}