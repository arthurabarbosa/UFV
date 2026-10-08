#include <stdio.h>

int main() {

    int v[50];
    int soma = 0;

    for (int i = 0; i < 50; i++){
        v[i] = i + 1;
    }
    
    for (int i = 0; i < 50; i++) {
        soma += v[i];
    }

    printf("%d", soma);

    return 0;
}