matriz = []
jogadores = []
maior = -1
indice_maior = 0

for i in range(10):
    vetor = []
    nome = str(input("Nome do jogador:"))
    jogadores.append(nome)
    for j in range(5):
        n = int(input("Nota do jurado:"))
        vetor.append(n)
    matriz.append(vetor)

for i in range(10):
    soma = 0
    for j in range(5):
        soma += matriz[i][j]
    if soma > maior:
        maior = soma
        indice_maior = i

print("O jogador com a maior nota foi %s, de nota total %d e posição (índice) %d" % (jogadores[indice_maior], maior, indice_maior))