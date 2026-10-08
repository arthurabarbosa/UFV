v = []

for i in range(20):
    n = int(input())
    v.append(n)
             
maior = v[0]
menor = v[0]

for i in range(len(v)):
    if v[i] > maior:
        maior = v[i]
    if v[i] < menor:
        menor = v[i]
    
print(maior)
print(menor)