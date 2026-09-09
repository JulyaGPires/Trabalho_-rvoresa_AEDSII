#ifndef TRIE_HPP
#define TRIE_HPP
#include <string>

using namespace std;

Struct No_t{

No_t *no[26];
bool isEnd;

}

void Inicializar_t();

Class Trie{

private:

No_t *no;

public:

void Inserir(string &palavra);
void Remover();
void Buscar_Palavra();
void Buscar_Prefixo();


}

#endif