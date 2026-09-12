#include "Trie.hpp"
#include <iostream>

using namespace std;

Trie::Trie() {
  raiz = new No_t();
}

void Trie::Liberar(No_t *atual) {

  if (atual == nullptr) {
    return;
  }

  for (int i = 0; i < 26; i++) {
    Liberar(atual->trie[i]);
  }

  delete atual;
}

Trie::~Trie() {

  Liberar(raiz);
}

void Trie::Inserir(string &palavra) {

  for(char c : palavra){

    int pos = c - 'a';

    if(pos < 0 || pos >= 26){
      return;
    }
  }

  No_t *atual = raiz;

  for (size_t i = 0; i < palavra.size(); i++) {

      char caractere = palavra[i];
      int posicao = caractere - 'a';

      if (atual->trie[posicao] != nullptr) {

          atual = atual->trie[posicao];

      } else {

          atual->trie[posicao] = new No_t;
          atual = atual->trie[posicao];
      }
  }

  atual->isEnd = true;
}

bool Trie::Remover_palavra(No_t *atual, string &palavra, int posicao) {

  if (posicao == palavra.size()) {
    if(!atual -> isEnd){
      return false;
    }
      atual->isEnd = false;

  } else {

      int posicao_letra = palavra[posicao] - 'a';

      if(posicao_letra < 0 || posicao_letra >= 26){
        return false;
      }

      if (atual->trie[posicao_letra] == nullptr) {

        return false;
    }
  

      bool apagar = Remover_palavra(atual->trie[posicao_letra], palavra,posicao + 1);

      if (apagar) {

        delete atual->trie[posicao_letra];
        atual->trie[posicao_letra] = nullptr;
  }
}
  if(atual == raiz){
    return false;
  }

  for (int i = 0; i < 26; i++) {

      if (atual->trie[i] != nullptr) {

          return false;
      }
  }

  return !atual->isEnd;
}

bool Trie::Remover(string &palavra) {

  if(!Buscar_Palavra(palavra)){
    return false;
  }

  Remover_palavra(raiz, palavra, 0);

  return true;
}

bool Trie::Buscar_Palavra(string &palavra) {

  No_t *atual = raiz;

  for (size_t i = 0; i < palavra.size(); i++) {

      char caractere = palavra[i];
      int posicao = caractere - 'a';

      if(posicao < 0 || posicao >= 26){

      return false;

      }
      if (atual->trie[posicao] != nullptr) {

        atual = atual->trie[posicao];

      } else {

        return false;
      }
  }

  return atual -> isEnd;
}

void Trie::Achar_Pref( No_t *atual,string &resto,vector<string> &palavra_prefixo) {

  if (atual->isEnd == true) {

    //cout << resto << endl; 
    palavra_prefixo.push_back(resto);
  }  
  
  for (int i = 0; i < 26; i++) {

    if (atual->trie[i] != nullptr) {

        char caractere = i + 'a';
        resto.push_back(caractere);
        Achar_Pref(atual->trie[i], resto,palavra_prefixo);
        resto.pop_back();
        }
    }
}

vector<string> Trie::Buscar_Prefixo(string &prefixo) {

  No_t *atual = raiz;

  for (size_t i = 0; i < prefixo.size(); i++) {

      char caractere = prefixo[i];
      int posicao = caractere - 'a';

      if(posicao < 0  || posicao >= 26){

          return {};
      }

      if (atual->trie[posicao] == nullptr) {

          return {};
      }

    atual = atual->trie[posicao];
  }
    string resto = prefixo;
    vector<string> palavra_prefixo;

    Achar_Pref(atual, resto, palavra_prefixo);

    return palavra_prefixo;
}
