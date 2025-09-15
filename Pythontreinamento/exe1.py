# Estoque inicial
estoque_atual = {
    "canetas": 150,
    "cadernos": 95,
    "lápis": 120,
    "borrachas": 40,
    "marcadores": 60,
    "grampeador": 20,
    "agenda": 80,
    "clips": 200
}

print("=== Estoque Inicial ===")
for produto, qtd in estoque_atual.items():
    print(f"{produto}: {qtd} unidades")

print("\nDigite as movimentações do dia no formato: produto, tipo (entrada/saída), quantidade")
print("Digite 'fim' para encerrar.\n")

while True:
    entrada = input("Movimentação: ").strip()
    if entrada.lower() == "fim":
        break

    partes = [x.strip() for x in entrada.split(",")]

    if len(partes) != 3:
        print("Erro: digite no formato correto: produto, tipo, quantidade")
        continue

    produto, tipo, quantidade = partes
    tipo = tipo.lower()
    
    try:
        quantidade = int(quantidade)
    except ValueError:
        print("Erro: quantidade deve ser um número inteiro")
        continue

    if tipo not in ["entrada", "saída"]:
        print("Erro: tipo deve ser 'entrada' ou 'saída'")
        continue

    # Atualizar estoque
    if tipo == "entrada":
        if produto in estoque_atual:
            estoque_atual[produto] += quantidade
        else:
            estoque_atual[produto] = quantidade
    else:  # saída
        if produto in estoque_atual:
            estoque_atual[produto] -= quantidade
            if estoque_atual[produto] < 0:
                estoque_atual[produto] = 0
        else:
            print(f"Produto '{produto}' não existe no estoque. Criando com quantidade 0.")
            estoque_atual[produto] = 0

# Relatório final
print("\n=== Estoque Atualizado ===")
for produto, qtd in estoque_atual.items():
    print(f"{produto}: {qtd} unidades")

# Produtos com estoque baixo
produtos_baixo = [p for p, q in estoque_atual.items() if q <= 50]
if produtos_baixo:
    print("\n=== Produtos que precisam de reposição ===")
    for p in produtos_baixo:
        print(f"- {p}")
else:
    print("\nTodos os produtos estão em nível adequado.")
