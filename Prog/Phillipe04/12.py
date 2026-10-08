id = []
valor = []
soma = 0

while True:
    a = int(input())
    if a < 0:
        break
    b = float(input())
    id.append(a)
    valor.append(b)

print("\n--- LISTA DE DADOS DO LAVA JATO ---")
for i in range(len(id)):
    print("ID: %d | Valor: R$ %.2f" % (id[i], valor[i]))

for i in range(len(valor)):
    soma += valor[i]

print("-" * 35)
print("VALOR TOTAL DO CAIXA: R$ %.2f" % soma)