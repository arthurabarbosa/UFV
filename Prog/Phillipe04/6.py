v = []
quadrado = 0

for i in range (1, 21):
    if i%2 != 0:
        quadrado = i**2
        v.append(quadrado)

print(v)