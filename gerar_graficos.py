import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

ARQUIVO = "output/resultados.csv"
PASTA_SAIDA = Path("output/graficos")
PASTA_SAIDA.mkdir(parents=True, exist_ok=True)

dados = pd.read_csv(ARQUIVO)

DISTRIBUICOES = ["aleatorio", "ordenado", "decrescente"]


def filtrar(estrutura, tipo):
    return dados[(dados["estrutura"] == estrutura) & (dados["tipo"] == tipo)]


def salvar_grafico(nome):
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(PASTA_SAIDA / nome, dpi=300)
    plt.close()


for i, tipo in enumerate(DISTRIBUICOES, start=1):
    trie = filtrar("Trie", tipo)
    patricia = filtrar("Patricia", tipo)

    plt.figure(figsize=(8, 5))

    plt.plot(trie["n"], trie["busca_ms"], marker="o", label="Trie")
    plt.plot(patricia["n"], patricia["busca_ms"], marker="o", label="Patricia")

    plt.xscale("log")
    plt.yscale("log")

    plt.xlabel("Tamanho da entrada (n)")
    plt.ylabel("Tempo de busca (ms)")
    plt.title(f"Trie × Patricia — tempo de busca ({tipo})")

    salvar_grafico(f"0{i}_trie_patricia_busca_{tipo}.png")


for i, tipo in enumerate(DISTRIBUICOES, start=4):
    splay = filtrar("Splay", tipo)
    treap = filtrar("Treap", tipo)

    plt.figure(figsize=(8, 5))

    plt.plot(splay["n"], splay["insercao_ms"], marker="o", label="Splay")
    plt.plot(treap["n"], treap["insercao_ms"], marker="o", label="Treap")

    plt.xlabel("Tamanho da entrada (n)")
    plt.ylabel("Tempo de inserção (ms)")
    plt.title(f"Splay × Treap — tempo de inserção ({tipo})")

    salvar_grafico(f"0{i}_splay_treap_insercao_{tipo}.png")


kd = dados[dados["estrutura"] == "KD-Tree"].copy()

kd["n"] = pd.to_numeric(kd["n"])
kd["insercao_ms"] = pd.to_numeric(kd["insercao_ms"])
kd["busca_ms"] = pd.to_numeric(kd["busca_ms"])
kd["remocao_ms"] = pd.to_numeric(kd["remocao_ms"])
kd["nns_ms"] = pd.to_numeric(kd["nns_ms"])
kd["range_ms"] = pd.to_numeric(kd["range_ms"])

plt.figure(figsize=(8, 5))

plt.plot(kd["n"], kd["insercao_ms"], marker="o", label="Inserção")
plt.plot(kd["n"], kd["busca_ms"], marker="o", label="Busca")
plt.plot(kd["n"], kd["remocao_ms"], marker="o", label="Remoção")
plt.plot(kd["n"], kd["nns_ms"], marker="o", label="NNS")
plt.plot(kd["n"], kd["range_ms"], marker="o", label="Range Search")

plt.xscale("log")
plt.yscale("log")

plt.xlabel("Tamanho da entrada (n)")
plt.ylabel("Tempo (ms)")
plt.title("KD-Tree — tempo das operações")

salvar_grafico("07_kdtree_operacoes.png")

print("Gráficos gerados com sucesso!")