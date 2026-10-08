nota = []
nome = []

for i in range(10):
    n = str(input())
    x = float(input())
    nome.append(n)
    nota.append(x)

maior = nota[0]
aluno_maior = nome[0]
menor = nota[0]
aluno_menor = nome[0]

for i in range(1, len(nota)):
    if nota[i] > maior:
        maior = nota[i]
        aluno_maior = nome[i]
    
    if nota[i] < menor:
        menor = nota[i]
        aluno_menor = nome[i]

print("A maior nota é %.1f, e foi obtida pelo aluno %s" % (maior, aluno_maior))
print("A menor nota é %.1f, e foi obtida pelo aluno %s" % (menor, aluno_menor))