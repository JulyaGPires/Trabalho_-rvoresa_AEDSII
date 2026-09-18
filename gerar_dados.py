import csv
import random
import string

N = 100000

random.seed(42)


def gerar_string(tamanho=10):
    return ''.join(random.choices(string.ascii_lowercase, k=tamanho))


# =========================
# STRINGS
# =========================

strings = [gerar_string() for _ in range(N)]

strings_aleatorio = strings.copy()
random.shuffle(strings_aleatorio)

strings_ordenado = sorted(strings)
strings_decrescente = sorted(strings, reverse=True)


def salvar_strings(nome, dados):
    with open("data/" + nome, "w", newline="") as arquivo:
        escritor = csv.writer(arquivo)
        escritor.writerow(["palavra"])

        for palavra in dados:
            escritor.writerow([palavra])


salvar_strings("strings_aleatorio.csv", strings_aleatorio)
salvar_strings("strings_ordenado.csv", strings_ordenado)
salvar_strings("strings_decrescente.csv", strings_decrescente)


# =========================
# INTEIROS
# =========================

inteiros = list(range(1, N + 1))

inteiros_aleatorio = inteiros.copy()
random.shuffle(inteiros_aleatorio)

inteiros_ordenado = inteiros.copy()
inteiros_decrescente = sorted(inteiros, reverse=True)


def salvar_inteiros(nome, dados):
    with open("data/" + nome, "w", newline="") as arquivo:
        escritor = csv.writer(arquivo)
        escritor.writerow(["valor"])

        for valor in dados:
            escritor.writerow([valor])


salvar_inteiros("ints_aleatorio.csv", inteiros_aleatorio)
salvar_inteiros("ints_ordenado.csv", inteiros_ordenado)
salvar_inteiros("ints_decrescente.csv", inteiros_decrescente)


# =========================
# PONTOS 3D PARA KD-TREE
# =========================

with open("data/pontos_uniforme.csv", "w", newline="") as arquivo:

    escritor = csv.writer(arquivo)
    escritor.writerow(["x", "y", "z"])

    for i in range(N):

        x = random.uniform(0, 100000)
        y = random.uniform(0, 100000)
        z = random.uniform(0, 100000)

        escritor.writerow([x, y, z])


print("Dados gerados com sucesso!")