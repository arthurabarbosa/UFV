#include <stdio.h>

int main() {

    int n;
    
    scanf("%d", &n);

    int contador = 0;
    int i = 0;

    while (contador < n) {
        
        printf("%d ", i + 1);
        contador++;
        if (contador == n) break;

        printf("%d ", i + 4);
        contador++;
        if (contador == n) break;

        printf("%d ", i + 4);
        contador++;
        
        i++;
    }

    return 0;
}