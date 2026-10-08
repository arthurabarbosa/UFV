import random

temp = [random.randint(15, 41) for i in range(121)]
soma = 0
contador_med = 0
contador_20 = 0
contador_35 = 0

for i in range(len(temp)):
    soma += temp[i]
media = soma/len(temp)

for i in range(len(temp)):
    if temp[i] < media:
        contador_med += 1
    if temp[i] < 20:
        contador_20 += 1
    if temp[i] > 35:
        contador_35 += 1

print("Temperatura média: %dºC" % media)
print("Número de dias nos quais a temperatura foi inferior à média: %d" % contador_med)
print("Número de dias que fez menos de 20ºC: %d" % contador_20)
print("Número de dias que fez mais de 35ºC: %d" % contador_35)