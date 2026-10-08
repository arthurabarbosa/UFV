#ifndef CENTROPESQUISA_H
#define CENTROPESQUISA_H
#include "pokelista.h"
#include "pokemon.h"
#include "treinador.h"

// Estrutura que representa o Centro de Pesquisa, contendo duas listas principais
typedef struct{
    PokeLista fugitivos;   // Pokémons soltos que precisam ser recuperados
    PokeLista recuperados; // Pokémons resgatados pelos treinadores
} CentroPesquisa;

// Inicializa as listas do centro
int inicializa_centro(CentroPesquisa *cpesq);

// Adiciona um Pokémon à lista de fugitivos
int insere_fugitivos(CentroPesquisa *cpesq, Pokemon pk);

// Remove um Pokémon da lista de fugitivos pelo ID
int remove_fugitivos(CentroPesquisa *cpesq, int id);

// Exibe a lista de Pokémons ainda fugitivos
int imprime_Nrecuperados(CentroPesquisa *cpesq);

// Transfere o Pokémon resgatado para a lista de recuperados
int recebe_recuperado(CentroPesquisa *cpesq, Pokemon pk);

// Sorteia e concede novas Pokébolas para um treinador
int recarga_pokebolas(CentroPesquisa *cpesq, Treinador *tr);

#endif