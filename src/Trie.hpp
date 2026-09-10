#ifndef TRIE_HPP
#define TRIE_HPP
#include <string>
#include <vector>

using namespace std;

struct No_t{

No_t *trie[26];
bool isEnd;

};

No_t(){

  for(int i = 0; i < 26; i++){

  trie[i] = nullptr;
    
  }

  isEnd = false;

};

class Trie{

private:

No_t *raiz;

public:

Trie();
void Inserir(string &palavra);
void Remover();
bool Buscar_Palavra(string &palavra);
void Achar_Pref(No_t *atual,string &resto, vector<string> &palavra_prefixo);
void Buscar_Prefixo(string &prefixo);


}

#endif