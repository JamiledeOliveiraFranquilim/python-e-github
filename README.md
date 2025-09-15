# Sistema de Controle de Estoque - Armazém Central

## Descrição
Este projeto é um **script em Python** que gerencia o estoque de produtos de papelaria de um armazém. O sistema permite:

- Visualizar o estoque atual.
- Registrar movimentações de entrada e saída de produtos.
- Adicionar novos produtos ao estoque.
- Gerar um relatório final com o estoque atualizado.
- Identificar produtos que precisam de reposição (estoque ≤ 50 unidades).

---

## Estoque Inicial
O estoque inicial é definido em um dicionário Python chamado `estoque_atual`:

```python
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

``` 
## Funcionamento

### Exibir estoque inicial
Ao iniciar, o script mostra todos os produtos com suas quantidades.

### Registrar movimentações
Digite movimentações no formato:

produto, tipo (entrada/saída), quantidade

makefile

**Exemplo:**

canetas, entrada, 50
borrachas, saída, 10

yaml

- `entrada`: adiciona quantidade ao estoque existente.  
- `saída`: subtrai quantidade do estoque (não permite valor negativo).  
- Produtos novos são adicionados automaticamente.

### Encerrar entrada de dados
Digite `fim` para encerrar o registro.

### Relatório final
Exibe o estoque atualizado e os produtos que precisam de reposição.

---

## Regras de Negócio

- Produtos novos adicionados durante a movimentação são incluídos no estoque.  
- Movimentações de saída não permitem que o estoque fique negativo.  
- Produtos com quantidade ≤ 50 unidades precisam de reposição.

---

## Como Executar

1. Certifique-se de ter **Python 3.x** instalado.  
2. Salve o arquivo como `controle_estoque.py`.  
3. Abra o terminal na pasta do arquivo e execute:

```bash
python controle_estoque.py
Siga as instruções para registrar movimentações e visualizar o relatório final.

 Exemplo de Uso
makefile

=== Estoque Inicial ===
canetas: 150 unidades
cadernos: 95 unidades
lápis: 120 unidades
borrachas: 40 unidades
marcadores: 60 unidades
grampeador: 20 unidades
agenda: 80 unidades
clips: 200 unidades

Digite as movimentações do dia no formato: produto, tipo (entrada/saída), quantidade
Digite 'fim' para encerrar.

Movimentação: canetas, entrada, 50
Movimentação: borrachas, saída, 10
Movimentação: fim

=== Estoque Atualizado ===
canetas: 200 unidades
cadernos: 95 unidades
lápis: 120 unidades
borrachas: 30 unidades
marcadores: 60 unidades
grampeador: 20 unidades
agenda: 80 unidades
clips: 200 unidades

=== Produtos que precisam de reposição ===
- borrachas
- grampeador

```
## TECNOLOGIA

1. Python 3.x

2. Dicionários e listas

3. Entrada de dados pelo terminal

4. Lógica de controle de estoque

## AUTORES

Jamile de Oliveira Franquilim e Geovanna Kaori Shimada
