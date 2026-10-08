import random

matriz = []

for i in range(15):
    vetor = []
    for j in range(15):
        valor = random.randint(1, 100)
        vetor.append(valor)
    matriz.append(vetor)

for i in range(15):
    for j in range(15):
        print("%4d" % matriz[i][j], end=" ")
    print()