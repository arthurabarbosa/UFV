#include <stdio.h>

double func(int v[], int tam) {
    int soma = 0;
    for (int i = 0; i < tam; i++) {
        soma += v[i];
    }
    double media = soma/tam;

    return media;
}