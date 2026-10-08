altura = []
atleta = []
soma = 0
media = 0

for i in range(10):
    a = float(input())
    b = str(input())
    altura.append(a)
    atleta.append(b)

for i in range(len(altura)):
    soma += altura[i]

media = soma/(len(altura))

for i in range(len(altura)):
    if altura[i] > media:
        print("O atleta %s, com altura %.2f, é maior que a média de %.2f" % (atleta[i], altura[i], media))