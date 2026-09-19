# 🌳 Trabalho de Árvores Especializadas — AEDS II

Este projeto implementa cinco estruturas de dados em árvore — **Trie, Patricia, Splay, Treap e KD-Tree** — desenvolvido como atividade da disciplina de **Algoritmos e Estruturas de Dados II do CEFET-MG, campus Divinópolis**.

As estruturas possuem diferentes características e aplicações. **Trie e Patricia** são utilizadas para armazenamento e busca de strings, enquanto **Splay e Treap** são árvores binárias de busca utilizadas com chaves inteiras. A **KD-Tree** é empregada para organização e consulta de pontos multidimensionais.

O projeto também realiza uma análise experimental das estruturas, considerando diferentes tamanhos e distribuições de entrada. Os resultados das execuções são registrados em `output/resultados.csv` e utilizados para a geração dos gráficos disponíveis em `output/graficos/`.

---

## 📚 Estruturas Implementadas

- **Trie** — armazenamento e busca de strings por prefixo.
- **Patricia** — árvore compactada para armazenamento de strings.
- **Splay** — árvore binária de busca autoajustável.
- **Treap** — árvore que combina propriedades de BST e heap.
- **KD-Tree** — estrutura para organização e busca de pontos multidimensionais.

---

## 📁 Estrutura do Projeto

```text
Trabalho_-rvoresa_AEDSII/
├── .gitignore
├── Makefile
├── README.md
├── gerar_dados.py
├── gerar_graficos.py
├── data/
│   ├── ints_aleatorio.csv
│   ├── ints_decrescente.csv
│   ├── ints_ordenado.csv
│   ├── pontos_uniforme.csv
│   ├── strings_aleatorio.csv
│   ├── strings_decrescente.csv
│   └── strings_ordenado.csv
├── include/
│   ├── KD_Tree.hpp
│   ├── Leitura_Arquivo.hpp
│   ├── Patricia.hpp
│   ├── Splay.hpp
│   ├── Testes.hpp
│   ├── Treap.hpp
│   └── Trie.hpp
├── src/
│   ├── KD_Tree.cpp
│   ├── Leitura_Arquivo.cpp
│   ├── Main.cpp
│   ├── Patricia.cpp
│   ├── Splay.cpp
│   ├── Testes.cpp
│   ├── Treap.cpp
│   └── Trie.cpp
└── output/
    ├── resultados.csv
    └── graficos/
        ├── 01_trie_patricia_busca_aleatorio.png
        ├── 02_trie_patricia_busca_ordenado.png
        ├── 03_trie_patricia_busca_decrescente.png
        ├── 04_splay_treap_insercao_aleatorio.png
        ├── 05_splay_treap_insercao_ordenado.png
        ├── 06_splay_treap_insercao_decrescente.png
        └── 07_kdtree_operacoes.png
```

---

## 🗃️ Conjunto de Dados

Os experimentos práticos avaliaram tamanhos de entrada:

```
n ∈ {100, 1.000, 10.000, 50.000, 100.000}
```

sob três distribuições de chaves:

- **Strings** (Trie e Patricia): aleatório, ordenado e decrescente.
- **Inteiros** (Splay e Treap): aleatório, ordenado e decrescente.
- **Pontos tridimensionais** (KD-Tree): distribuição uniforme em espaço 3D, com k = 3.

Os dados utilizados nos experimentos estão disponíveis na pasta `data/`. O script `gerar_dados.py` permite reproduzir a geração dos conjuntos de dados utilizando uma seed fixa igual a `42`. Essa seed garante que os arquivos de entrada sejam sempre os mesmos entre execuções; já as prioridades aleatórias internas da Treap, geradas por `rand()` sem semente fixa, podem produzir pequenas variações nos tempos medidos entre diferentes execuções.

---

## ⚙️ Compilação e Execução

### ✅ Pré-requisitos

- Compilador C++ com suporte ao padrão C++11 (`g++ 13+` ou `clang++`)
- Utilitário `make`
- Ambiente Linux ou WSL
- Python 3.x com as bibliotecas:
  - `pandas`
  - `matplotlib`

### 🛠️ Comandos

Clone o repositório e acesse a pasta do projeto:

```bash
git clone https://github.com/JulyaGPires/Trabalho_-rvoresa_AEDSII.git
cd Trabalho_-rvoresa_AEDSII
```

Instale as dependências do Python (caso ainda não tenha):

```bash
python3 -m pip install pandas matplotlib
# ou no Ubuntu/WSL:
# sudo apt install python3-pandas python3-matplotlib
```

Compile o projeto:

```bash
make
```

Execute os experimentos:

```bash
make run
```

> Os resultados dos experimentos são salvos em `output/resultados.csv`.

Gere os gráficos a partir dos resultados obtidos:

```bash
python3 gerar_graficos.py
```

(Opcional) Regenere os conjuntos de dados:

```bash
python3 gerar_dados.py
```

Para remover os arquivos gerados pela compilação:

```bash
make clean
```

---

## 📊 Resultados Experimentais (n = 100.000)

Tempos de execução obtidos com entrada aleatória, em milissegundos (ms):

| Estrutura | Inserção (ms) | Busca (ms) | Remoção (ms) | NNS (ms) | Range Search (ms) |
|-----------|---------------:|-----------:|-------------:|---------:|-------------------:|
| Trie      | 537,11         | 47,02      | 285,31       | —        | —                   |
| Patricia  | 56,04          | 34,50      | 142,60       | —        | —                   |
| Splay     | 103,73         | 82,51      | 112,08       | —        | —                   |
| Treap     | 55,02          | 62,77      | 75,91        | —        | —                   |
| KD-Tree   | 187,15         | 221,24     | 271,85       | 261,25   | 58,52               |

> Os tempos podem variar conforme o ambiente de execução.

---

## 📈 Análise Experimental

Os experimentos foram realizados considerando diferentes tamanhos de entrada e distribuições, permitindo observar o comportamento das estruturas em cenários aleatórios, ordenados e decrescentes.

Para as estruturas de strings, foram comparadas principalmente Trie e Patricia. Para as estruturas baseadas em chaves inteiras, foram analisadas Splay e Treap. A KD-Tree foi avaliada separadamente devido à sua finalidade de organização e consulta de dados multidimensionais.

Os resultados completos dos experimentos são armazenados em `output/resultados.csv`. Os gráficos gerados a partir dos experimentos estão disponíveis na pasta `output/graficos/`.

---

## 🖼️ Correspondência entre Figuras do Artigo e Gráficos Gerados

| Figura do artigo | Conteúdo | Arquivo(s) em `output/graficos/` |
|---|---|---|
| Figura 6(a) | Trie × Patricia — busca (aleatório) | `01_trie_patricia_busca_aleatorio.png` |
| Figura 6(b) | Trie × Patricia — busca (ordenado) | `02_trie_patricia_busca_ordenado.png` |
| Figura 6(c) | Trie × Patricia — busca (decrescente) | `03_trie_patricia_busca_decrescente.png` |
| Figura 7(a) | Splay × Treap — inserção (aleatório) | `04_splay_treap_insercao_aleatorio.png` |
| Figura 7(b) | Splay × Treap — inserção (ordenado) | `05_splay_treap_insercao_ordenado.png` |
| Figura 7(c) | Splay × Treap — inserção (decrescente) | `06_splay_treap_insercao_decrescente.png` |
| Figura 8 | KD-Tree — tempo das operações | `07_kdtree_operacoes.png` |

Os gráficos são gerados automaticamente pelo script `gerar_graficos.py` a partir do arquivo `output/resultados.csv`.

---

## 🛠️ Ambiente de Desenvolvimento

O projeto foi desenvolvido e testado no seguinte ambiente:

| Item | Valor |
|---|---|
| **Sistema Operacional** | Windows 10 Home Single Language 22H2 |
| **WSL** | 2.6.3.0 |
| **Distribuição Linux** | Ubuntu 24.04.1 LTS (Noble) |
| **Compilador** | g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0 |
| **Padrão C++** | C++11 |
| **Build system** | Makefile |

---

## 📚 Referências

- MORRISON, D. R. **PATRICIA — Practical Algorithm To Retrieve Information Coded in Alphanumeric**. *Journal of the ACM*, v. 15, n. 4, p. 514–534, 1968.
- SLEATOR, D. D.; TARJAN, R. E. **Self-Adjusting Binary Search Trees**. *Journal of the ACM*, v. 32, n. 3, p. 652–686, 1985.
- BENTLEY, J. L. **Multidimensional binary search trees used for associative searching**. *Communications of the ACM*, v. 18, n. 9, p. 509–517, 1975.

---

## 👩🏽‍💻 Autora

**Julya Gonçalves Pires**
- Email: julyapires500@gmail.com