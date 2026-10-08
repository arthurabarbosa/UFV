import random

matriz = []
soma_linha = 0
produto_coluna = 1

for i in range(10):
    vetor = []
    for j in range(10):
        valor = random.randint(1, 100)
        vetor.append(valor)
    matriz.append(vetor)

print("Elementos da matriz (exceto coluna principal):")
for i in range(10):
    for j in range(10):
        if i != j:
            print(matriz[i][j], end=" ")

print("Elementos abaixo da diagonal principal:")
for i in range(10):
    for j in range(10):
        if i > j:
            print(matriz[i][j], end=" ")
        
for i in range(10):
    soma_linha = 0
    for j in range(10):
        soma_linha += matriz[i][j]
    print(soma_linha)

for j in range(10):
    produto_coluna = 1
    for i in range(10):
        produto_coluna *= matriz[i][j]
    print(produto_coluna)