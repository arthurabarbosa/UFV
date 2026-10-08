#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pokelista.h"
#include "centropesquisa.h"
#include "treinador.h"
#include "pokemon.h"

int main() {
    // Configura o console para codificação UTF-8
    system("chcp 65001 > nul");

    // Abre o arquivo de entrada
    FILE *arquivo = fopen("arquivo.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Declaração dos treinadores e dados temporários
    Treinador treinador1, treinador2;
    char nome_treinador1[50], nome_treinador2[50];
    int pokebolas_treinador1, pokebolas_treinador2;

    // Leitura das informações dos treinadores
    fscanf(arquivo, "%s %d", nome_treinador1, &pokebolas_treinador1);
    fscanf(arquivo, "%s %d", nome_treinador2, &pokebolas_treinador2);

    // Inicialização dos dois treinadores
    inicializa_treinador(&treinador1, 1, nome_treinador1, pokebolas_treinador1);
    inicializa_treinador(&treinador2, 2, nome_treinador2, pokebolas_treinador2);

    // Inicialização do Centro de Pesquisa
    CentroPesquisa centro;
    inicializa_centro(&centro);

    // Leitura do número de Pokémons fugitivos
    int num_fugitivos;
    fscanf(arquivo, "%d", &num_fugitivos);

    // Leitura e inserção dos Pokémons na lista de fugitivos do centro
    Pokemon pokemon_entrada;
    for(int i = 0; i < num_fugitivos; i++) {
        int numero_pokedex, x, y;
        char nome[50], tipo[50];

        fscanf(arquivo, "%d %s %s %d %d", &numero_pokedex, nome, tipo, &x, &y);
        set(&pokemon_entrada, i+1, numero_pokedex, nome, tipo, x, y);
        insere_fugitivos(&centro, pokemon_entrada);
    }

    // Exibição do relatório de início da missão
    printf("=======================================\n");
    printf("            INÍCIO DA MISSÃO           \n");
    printf("=======================================\n");
    printf("\n");
    imprime_treinador(&treinador1);
    imprime_treinador(&treinador2);
    
    printf("\nPokémons fugitivos a serem resgatados: %d\n", num_fugitivos);
    printf("---------------------------------------\n");

    // Loop principal: executa enquanto houver Pokémons na lista de fugitivos
    while (centro.fugitivos.primeiro->prox != NULL) {
        // Pega o primeiro Pokémon fugitivo da lista
        int id_alvo = get_id(&centro.fugitivos.primeiro->prox->poke);
        Pokemon alvo = busca_lista(&centro.fugitivos, id_alvo);

        char nome_alvo[50];
        get_nome(&alvo, nome_alvo);

        imprime_pokemon(&alvo);

        // Calcula qual treinador está mais próximo do alvo
        double distancia1, distancia2;
        Treinador *escolhido = NULL;
        escolhido = calculo_distancia(&treinador1, &treinador2, &alvo, &distancia1, &distancia2);

        printf("Distância Treinador(a) %s: %.2f\n", treinador1.nome, distancia1);
        printf("Distância Treinador(a) %s: %.2f\n", treinador2.nome, distancia2);

        printf("\nMissão atribuída ao Treinador(a) %s.\n", escolhido->nome);

        // Treinador se desloca e captura o Pokémon
        move_treinador(escolhido, get_x(&alvo), get_y(&alvo));
        printf("\n");
        printf("Treinador(a) %s se movimentou para (%d,%d).\n", escolhido->nome, get_x(&alvo), get_y(&alvo));
    
        captura_treinador(escolhido, alvo);
        printf("%s capturado com sucesso!\n", nome_alvo);

        printf("\n");
        printf("Pokébolas restantes para o Treinador(a) %s: %d\n", escolhido->nome, escolhido->pokebolas);

        // Remove o Pokémon capturado da lista de fugitivos
        remove_fugitivos(&centro, get_id(&alvo));

        // Se as Pokébolas do treinador acabaram e ainda restam fugitivos, ele deve retornar ao Centro
        if (escolhido->pokebolas == 0 && centro.fugitivos.primeiro->prox != NULL) {
            printf("\n=======================================\n");
            printf("Treinador(a) %s SEM POKÉBOLAS\n", escolhido->nome);
            printf("=======================================\n");
            printf("\n");
            printf("Treinador(a) %s retorna ao Centro de Pesquisa.\n", escolhido->nome);
            printf("\nEntregando Pokémon ao Centro de Pesquisa.\n");

            // Move treinador de volta ao centro (0,0)
            move_treinador(escolhido, 0, 0);

            // Descarrega os Pokémons capturados, transferindo-os para o centro
            while (escolhido->capturados.primeiro->prox != NULL) {
                Pokemon pk_transferencia = escolhido->capturados.primeiro->prox->poke;
                recebe_recuperado(&centro, pk_transferencia);
                retira_treinador(escolhido, get_id(&pk_transferencia));
            }

            // Recarrega novas Pokébolas para o treinador
            recarga_pokebolas(&centro, escolhido);
            printf("\nTreinador(a) %s recebeu %d Pokébolas.\n", escolhido->nome, escolhido->pokebolas);
        }
    }

    // Devolução final de Pokémons resgatados
    printf("\n");
    printf("=========================================\n");
    printf("     Todos Pokemons foram resgatados     \n");
    printf("=========================================\n");
    printf("\n");
    printf("Ambos treinadores retornam ao Centro de Pesquisa.\n");
    printf("\nTreinador(a) %s devolve os Pokémon.\n", treinador1.nome);
    printf("Treinador(a) %s devolve os Pokémon.\n", treinador2.nome);

    // Retorno ao centro
    move_treinador(&treinador1, 0, 0);
    move_treinador(&treinador2, 0, 0);

    // Esvazia os Pokémons capturados pelo Treinador 1
    while (treinador1.capturados.primeiro->prox != NULL) {
        Pokemon pk_transferencia = treinador1.capturados.primeiro->prox->poke;
        recebe_recuperado(&centro, pk_transferencia);
        retira_treinador(&treinador1, get_id(&pk_transferencia));
    }

    // Esvazia os Pokémons capturados pelo Treinador 2
    while (treinador2.capturados.primeiro->prox != NULL) {
        Pokemon pk_transferencia = treinador2.capturados.primeiro->prox->poke;
        recebe_recuperado(&centro, pk_transferencia);
        retira_treinador(&treinador2, get_id(&pk_transferencia));
    }

    printf("\n");
    printf("=======================================\n");
    printf("           MISSÃO CONCLUÍDA            \n");
    printf("=======================================\n");

    // Escreve os Pokémons recuperados no arquivo final de relatório
    FILE *relatorio = fopen("relatorio.txt", "w");
    if (relatorio != NULL) {
        fprintf(relatorio, "Pokemon recuperados:\n");
        
        Celula *recuperado = centro.recuperados.primeiro->prox;
        while (recuperado != NULL) {
            char nome_p[50];
            get_nome(&recuperado->poke, nome_p);
            fprintf(relatorio, "%d %s\n", get_numeropokedex(&recuperado->poke), nome_p);
            recuperado = recuperado->prox;
        }
        fclose(relatorio);
    } 
    else {
        printf("Erro ao criar o relatorio.txt\n");
    }

    fclose(arquivo);

    return 0;
}