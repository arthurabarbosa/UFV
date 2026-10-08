#include <stdio.h>

void ImprimeGols(char timeA, char timeB, int golsA, int golsB, char resultado[], int indice) {
    
    if (golsA == 0 && golsB == 0) {
        resultado[indice] = '\0';
        printf("%s\n", resultado);
    }

    if (golsA > 0) {
        resultado[indice] = timeA;
        ImprimeGols(timeA, timeB, golsA - 1, golsB, resultado, indice + 1);
    }

    if (golsB > 0) {
        resultado[indice] = timeB;
        ImprimeGols(timeA, timeB, golsA, golsB - 1, resultado, indice + 1);
    }
}

int main() {

    char vetor[10];
    ImprimeGols('A', 'B', 2, 1, vetor, 0);

    return 0;
}