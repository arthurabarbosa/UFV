#include <stdio.h>
#include <stdlib.h>
#include "centropesquisa.h"
#include "pokelista.h"
#include "treinador.h"

// Inicializa ambas as listas mantidas pelo centro
int inicializa_centro(CentroPesquisa *cpesq) {
    inicializa_lista(&cpesq->fugitivos);
    inicializa_lista(&cpesq->recuperados);
    
    return 0;
}

// Cadastra um Pokémon fugitivo no centro
int insere_fugitivos(CentroPesquisa *cpesq, Pokemon pk) {
    insere_lista(&cpesq->fugitivos, pk);

    return 0;
}

// Remove um Pokémon da lista de fugitivos
int remove_fugitivos(CentroPesquisa *cpesq, int id) {
    remove_lista(&cpesq->fugitivos, id);

    return 0;
}

// Imprime Pokémons ainda soltos
int imprime_Nrecuperados(CentroPesquisa *cpesq) {
    imprime_lista(&cpesq->fugitivos);
    
    return 0;
}

// Registra um Pokémon resgatado na lista do centro
int recebe_recuperado(CentroPesquisa *cpesq, Pokemon pk) {
    insere_lista(&cpesq->recuperados, pk);

    return 0;
}

// Sorteia de 1 a 20 Pokébolas para recarregar o treinador
int recarga_pokebolas(CentroPesquisa *cpesq, Treinador *tr) {
    int random = (rand() % 20) + 1; 
    tr->pokebolas = random;

    return 0;
}