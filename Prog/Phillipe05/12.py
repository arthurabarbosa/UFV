produtos = ["Shampoo", "Condicionador", "Celular", "Máscara", "Detergente", "Perfume", "Hidratante", "Caneca", "Garrafa", "Computador", "Carregador", "Caderno", "Caneta", "Adesivos", "Livro"]
produtos_lower = []
valores = [40, 40, 1800, 70, 4, 150, 30, 40, 70, 3000, 20, 10, 2, 15, 40]
maior_nome = produtos[0]
maior = valores[0]
menor_nome = produtos[0]
menor = valores[0]

for i in range(len(produtos)):
    if valores[i] > maior:
        maior_nome = produtos[i]
        maior = valores[i]
    if valores[i] < menor:
        menor_nome = produtos[i]
        menor = valores[i]
    produtos_lower.append(produtos[i].lower())

print("Produto mais caro: %s - R$%d" % (maior_nome, maior))
print("Produto mais barato: %s - R$%d" % (menor_nome, menor))

n = str(input("Insira o nome de um produto:")).lower()

encontrado = False

for i in range(len(produtos_lower)):
    if n == produtos_lower[i]:
        print(valores[i])
        encontrado = True
        break

if not encontrado:
    print("Produto não encontrado no sistema")