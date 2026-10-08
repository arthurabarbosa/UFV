#include <stdio.h>

void troca(float *x, float *y) {
    float aux;
    aux = *x;
    *x = *y;
    *y = aux;
}