# 🌳 Trabalho de Árvores Especializadas — AEDS II 
 
Implementação e análise experimental de estruturas de dados em árvore desenvolvida para a disciplina de **Algoritmos e Estruturas de Dados II (AEDS II)** do **CEFET-MG — Campus Divinópolis**. 
 
O projeto implementa e compara diferentes estruturas especializadas, considerando operações de inserção, busca e remoção, além de consultas espaciais na KD-Tree. 
 
## 📚 Estruturas Implementadas 
 
- **Trie** — armazenamento e busca de strings por prefixo. 
- **Patricia** — árvore compactada para armazenamento de strings. 
- **Splay** — árvore binária de busca autoajustável. 
- **Treap** — árvore que combina propriedades de BST e heap. 
- **KD-Tree** — estrutura para organização e busca de pontos multidimensionais. 
 
## 📁 Estrutura do Projeto 
 
```text 
Trabalho_-rvoesa_AEDSII/ 
├── .gitignore 
├── Makefile 
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
│   ├── Patricia.hpp 
│   ├── Splay.hpp 
│   ├── Treap.hpp 
│   └── Trie.hpp 
├── src/ 
│   ├── KD_Tree.cpp 
│   ├── Main.cpp 
│   ├── Patricia.cpp 
│   ├── Splay.cpp 
│   ├── Treap.cpp 
│   └── Trie.cpp 
└── output/ 
    └── resultados.csv 

🗃️ Conjunto de Dados

Os experimentos práticos avaliaram tamanhos de entrada:

n ∈ {100, 1.000, 10.000, 50.000, 100.000}

sob três distribuições de chaves:

Strings (Trie e Patricia): aleatorio, ordenado e decrescente.
Inteiros (Splay e Treap): aleatorio, ordenado e decrescente.
Pontos Tridimensionais (KD-Tree): distribuição uniforme em espaço 3D, com k = 3.

Os dados utilizados nos experimentos estão disponíveis na pasta data/. O script gerar_dados.py permite reproduzir a geração dos conjuntos de dados.

⚙️ Compilação e Execução
✅ Pré-requisitos
Compilador C++ com suporte ao padrão C++17 (g++ 13+ ou clang++).
Utilitário make.
Ambiente Linux ou WSL.
🛠️ Comandos

Clone o repositório:

git clone https://github.com/JulyaGPires/Trabalho_-rvoesa_AEDSII.git
cd Trabalho_-rvoesa_AEDSII

Compile o projeto:

make

Execute a suíte de testes:

make run

Os resultados são salvos em:

output/resultados.csv

Para remover os arquivos gerados pela compilação:

make clean
📊 Resultados Experimentais (n = 100.000)

Tempos médios de execução obtidos com entrada aleatória, em milissegundos:

Estrutura	Inserção (ms)	Busca (ms)	Remoção (ms)	NNS (ms)	Range Search (ms)
Trie	428,80	81,03	257,21	—	—
Patricia	96,69	58,22	102,44	—	—
Splay	122,62	83,51	79,63	—	—
Treap	57,97	52,41	48,56	—	—
KD-Tree	119,10	184,11	241,38	189,13	51,87

Os tempos podem variar conforme o ambiente de execução.

📈 Análise Experimental

Os experimentos foram realizados considerando diferentes tamanhos de entrada e distribuições, permitindo observar o comportamento das estruturas em cenários aleatórios, ordenados e decrescentes.

Para as estruturas de strings, foram comparadas principalmente Trie e Patricia. Para as estruturas baseadas em chaves inteiras, foram analisadas Splay e Treap. A KD-Tree foi avaliada separadamente devido à sua finalidade de organização e consulta de dados multidimensionais.

Os resultados completos dos experimentos são armazenados em:

output/resultados.csv
🛠️ Ambiente de Desenvolvimento
Linguagem: C++17
Sistema operacional: Ubuntu 24.04 (WSL2)
Compilador: g++ 13.3.0
Hardware: Intel Core i5-7200U
Memória RAM: 8 GB
👩🏽‍💻 Autora

Julya Gonçalves Pires

Engenharia de Computação — CEFET-MG Campus Divinópolis

GitHub: @JulyaGPires
E-mail: julyapires500@gmail.com