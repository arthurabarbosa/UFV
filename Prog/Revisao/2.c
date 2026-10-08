#include <stdio.h>

int tamanho(int num) {
    if (num == 0) {
        return 1;
    }

    int cont = 0;

    if (num < 0) {
        num = num*(-1);
    }
    while (num > 0) {
        num = num/10;
        cont++;
    }

    return cont;
}

int main() {

    int n;
    scanf("%d", &n);

    int res = tamanho(n);

    printf("%d", res);

    return 0;
}