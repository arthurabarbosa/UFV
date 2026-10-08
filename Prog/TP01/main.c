#include <stdio.h>
#include <string.h>

// Estrutura criada para armazenar os dados das selecoes
struct DadosSelecoes {
    char nome[50];
    int gols;
    int pontuacao;
};

// Funcao para comparar os pontos dos times
int criterio_pontos(struct DadosSelecoes timeX, struct DadosSelecoes timeY) { 
    if (timeY.pontuacao > timeX.pontuacao) {
        return 1;
    }
    return 0;
}

// Funcao para comparar os gols dos times
int criterio_gols(struct DadosSelecoes timeX, struct DadosSelecoes timeY) {
    if (timeY.gols > timeX.gols) {
        return 1;
    }
    return 0;
}

// Funcao para comparar os nomes dos times em ordem alfabetica (letra por letra)
int criterio_alfabetico(struct DadosSelecoes timeX, struct DadosSelecoes timeY) {
    if (strcmp(timeY.nome, timeX.nome) < 0) {
        return 1;
    }
    return 0;
}

// Funcao para verificar se os times estao empatados em pontos
int criterio_empate_pontos(struct DadosSelecoes timeX, struct DadosSelecoes timeY) {
    if (timeX.pontuacao == timeY.pontuacao){
        return 1;
    }
    return 0;
}

// Funcao para verificar se os times estao empatados em gols
int criterio_empate_gols(struct DadosSelecoes timeX, struct DadosSelecoes timeY) {
    if (timeX.gols == timeY.gols){
        return 1;
    }
    return 0;
}

int main() {

    struct DadosSelecoes selecoes[100]; // Vetor que armazena os dados das selecoes
    int i = 0;

    FILE *arquivo;

    arquivo = fopen("selecoes.txt", "r"); // Abre o arquivo de selecoes para leitura

    // Verifica se o arquivo foi aberto sem problemas
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo selecoes.txt\n");
        return 1;
    }

    // Le linha por linha do arquivo e armazena os dados das selecoes no vetor
    while (fscanf(arquivo, "%49s", selecoes[i].nome) != EOF) {
        selecoes[i].gols = 0;
        selecoes[i].pontuacao = 0;
        i++;
    }
    
    fclose(arquivo); // Fecha o arquivo

    arquivo = fopen("jogos.txt", "r"); // Abre o arquivo de jogos para leitura

    // Verifica se o arquivo foi aberto sem problemas
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo jogos.txt\n");
        return 1;
    }

    // Conjunto de variaveris para armazenar os dados gerais do jogos
    char timeA[50], timeB[50]; 
    int golsA, golsB;
    int totalselecoes = i;

    // Realiza a leitura do arquivo de jogos, atualizando os dados das selecoes de acordo com os resultados dos jogos
    while(fscanf(arquivo, "%s %d x %d %s", timeA, &golsA, &golsB, timeB) == 4) {
        int indiceA = -1; // Flag usada pra manipular o indíce do time A
        int indiceB = -1; // Flag usada pra manipular o indíce do time B
        for(int j = 0; j < totalselecoes; j++) {
            if(strcmp(selecoes[j].nome, timeA) == 0) {
                indiceA = j;
            }
            if(strcmp(selecoes[j].nome, timeB) == 0) {
                indiceB = j;
            }
        }
        
        // Serve pra verificar se o time lido no arquivo jogos.txt realmente estava presente no arquivo original de selecoes.txt (apenas para os times do lado esquerdo do placar)
        if (indiceA == -1) {
            printf("A selecao '%s' nao consta no arquivo original. Jogo ignorado.\n", timeA);
            continue;
        }
        // Faz o mesmo, mas pros times que estao a direita do placar
        if (indiceB == -1) {
            printf("A selecao '%s' nao consta no arquivo original. Jogo ignorado.\n", timeB);
            continue;
        }

        // Atualiza os gols e pontuação do time A
        selecoes[indiceA].gols += golsA;
        if(golsA > golsB) {
            selecoes[indiceA].pontuacao += 3;
        }
        else if(golsA == golsB) {
            selecoes[indiceA].pontuacao += 1;
        }

        // Atualiza os gols e pontuação do Time B
        selecoes[indiceB].gols += golsB;
        if(golsB > golsA) {
            selecoes[indiceB].pontuacao += 3;
        }
        else if(golsB == golsA) {
            selecoes[indiceB].pontuacao += 1;
        }
    }

    fclose(arquivo); // Fecha o arquivo

    // Ordena as selecoes de acordo com os criterios estabelecidos pelas funcoes e pelo documento dado
    for(int x = 0; x < totalselecoes; x++) {
        for(int y = x + 1; y < totalselecoes; y++) {
            if (criterio_pontos(selecoes[x], selecoes[y])) {
                struct DadosSelecoes aux = selecoes[x];
                selecoes[x] = selecoes[y];
                selecoes[y] = aux;
            }
            else if (criterio_empate_pontos(selecoes[x], selecoes[y]) && criterio_gols(selecoes[x], selecoes[y])) {
                struct DadosSelecoes aux = selecoes[x];
                selecoes[x] = selecoes[y];
                selecoes[y] = aux;
            }
            else if (criterio_empate_pontos(selecoes[x], selecoes[y]) && criterio_empate_gols(selecoes[x], selecoes[y]) && criterio_alfabetico(selecoes[x], selecoes[y])) {
                struct DadosSelecoes aux = selecoes[x];
                selecoes[x] = selecoes[y];
                selecoes[y] = aux;
            }
        }   
    }

    FILE *tonini;

    tonini = fopen("classificacao.txt", "w"); // Abre o arquivo de classificacao, dessa vez no modo escrita

    // Imprime o layout do pódio
    fprintf(tonini, "================================================\n");
    fprintf(tonini, "     CLASSIFICACAO FINAL DA COPA DO MUNDO\n");
    fprintf(tonini, "================================================\n");
    fprintf(tonini, "\n");
    fprintf(tonini, "PODIO DOS CAMPEOES:\n");
    
    // Imprime os 3 primeiros colocados no arquivo de classificacao, de acordo com os dados armazenados anteriormente
    for(int k = 0; k < 3; k++) {
        fprintf(tonini, "%do Lugar: %s - %d pontos (%d gols)\n", k+1, selecoes[k].nome, selecoes[k].pontuacao, selecoes[k].gols);
    }

    fprintf(tonini, "\n");
    fprintf(tonini, "================================================\n");

    fclose(tonini);

    // Imprime o layout do pódio de novo, mas dessa vez no terminal
    printf("================================================\n");
    printf("     CLASSIFICACAO FINAL DA COPA DO MUNDO\n");
    printf("================================================\n");
    printf("\n");
    printf("PODIO DOS CAMPEOES:\n");
    
    // Por fim, mprime os 3 primeiros colocados no terminal
    for(int k = 0; k < 3; k++) {
        printf("%do Lugar: %s - %d pontos (%d gols)\n", k+1, selecoes[k].nome, selecoes[k].pontuacao, selecoes[k].gols);
    }

    return 0;
}