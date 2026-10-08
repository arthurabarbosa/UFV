v = []
soma = 0
media = 0

for i in range(15):
    nota = float(input())
    v.append(nota)

for i in range(len(v)):
    soma += v[i]

media = soma/(len(v))

print("A média geral da turma é: %.2f" % media)