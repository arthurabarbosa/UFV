v = [i for i in range(0, 50)]
aux = 0

for i in range(len(v)//2):
    aux = v[i]
    v[i] = v[49-i]
    v[49-i] = aux

print(v)