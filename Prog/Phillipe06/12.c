#include <stdio.h>

int testaDados() {
    int num_dados = 100;
    int total100 = 0;
    int total50 = 0;
    int total1 = 0;
    int maior;
    while (num_dados > 0) {
        int res = JogaDado(10);
        total100 += res;
        num_dados--;
    }
    num_dados = 50;
    while (num_dados > 0) {
        int res = JogaDado(20);
        total50 += res;
        num_dados--;
    }
    num_dados = 1;
    while (num_dados > 0) {
        int res = JogaDado(100);
        total1 += res;
        num_dados--;
    }
    if (total100 > total50 && total100 > total1) {
        maior = 10;
    }
    else if (total50 > total100 && total50 > total1) {
        maior = 50;
    }
    else if (total1 > total50 && total1 > total100) {
        maior = 100;
    }

    return maior;
}