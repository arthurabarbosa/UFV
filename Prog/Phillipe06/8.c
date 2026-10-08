float calcmedia(int vetor[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    return (float)soma / tamanho;
}