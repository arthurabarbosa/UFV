#include <stdio.h>
#include "ContaBancaria.h"

int main() {
    ContaBancaria Conta;
    char nomeAux[50];
    char tipoAux[20];

    printf("--- Inicializacao da Conta ---\n");
    inicializacao(&Conta);

    printf("\n--- Dados Cadastrados ---\n");
    imprime(&Conta);

    printf("\n--- Operacoes Financeiras ---\n");
    deposito(500.00, &Conta);
    saque(200.00, &Conta);

    getCliente(&Conta, nomeAux);
    getTipo(&Conta, tipoAux);
    printf("\nNome obtido via Get: %s\n", nomeAux);
    printf("Tipo obtido via Get: %s\n", tipoAux);

    setCliente(&Conta, "Henrique");
    setTipo(&Conta, "Poupanca");

    printf("\n--- Avaliacao de Emprestimo ---\n");
    avalia(&Conta);

    printf("\n--- Dados Atualizados ---\n");
    imprime(&Conta);

    return 0;
}