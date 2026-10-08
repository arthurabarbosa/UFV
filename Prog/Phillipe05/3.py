v = []

for i in range(15):
    n = int(input())
    v.append(n)
             
maior = v[0]
menor = v[0]
pos_maior = 0
pos_menor = 0

for i in range(len(v)):
    if v[i] > maior:
        maior = v[i]
        pos_maior = i
    if v[i] < menor:
        menor = v[i]
        pos_menor = i
    
print("Maior: %d. Posição: %d." % (maior, pos_maior))
print("Menor: %d. Posição: %d." % (menor, pos_menor))