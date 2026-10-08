quant = int(input())
valor_total = float(input())
peso = []
preco = []
total_preco = 0
total_peso = 0

for i in range(quant):
    pesos = float(input())
    precos = float(input())
    peso.append(pesos)
    preco.append(precos)

for i in range(len(preco)):
    total_preco += preco[i]
    total_peso += peso[i]

print("Peso total: %.1f" % total_peso)
print("Valor total: %.1f" % total_preco)

if total_preco == valor_total:
    print("Não há conflito entre o valor monetário total da carga informado e o calculado")
else:
    print("Há conflito entre o valor monetário total da carga informado e o calculado")