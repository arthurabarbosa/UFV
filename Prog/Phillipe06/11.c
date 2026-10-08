#include <stdio.h>

int difhor(int a, int b, int c, int d) {
    int btotal = (a*60) + b;
    int dtotal = (c*60) + d;

    int diferenca;

    diferenca = (b-d);

    if (diferenca < 0) {
        diferenca = diferenca*(-1);
    }

    return diferenca;
}