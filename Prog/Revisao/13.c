#include <stdio.h>

int recursivo(int n) {

    if (n == 0) {
        return 1;
    }

    int resultado = n*recursivo(n-1);

    return resultado;
}