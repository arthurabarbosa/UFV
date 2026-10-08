import random

matriz = []
soma_coluna5 = 0

for i in range(5):
    valor_atual = []
    for j in range(25):
        valor = random.randint(1, 100)
        valor_atual.append(valor)
    matriz.append(valor_atual)

print("Elementos da primeira coluna:")
for i in range(5):
    print(matriz[i][0])

for i in range(5):
    soma_coluna5 += matriz[i][5]

print("Soma da coluna de índice 5: %d" % soma_coluna5)