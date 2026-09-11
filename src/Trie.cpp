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

  No_t *atual = raiz;

  for (int i = 0; i < palavra.size(); i++) {

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

      atual->isEnd = false;

  } else {

      int posicao_letra = palavra[posicao] - 'a';

      if (atual->trie[posicao_letra] == nullptr) {

        return false;
    }
  

      bool apagar = Remover_palavra(atual->trie[posicao_letra], palavra,posicao + 1);

      if (apagar) {

        delete atual->trie[posicao_letra];
        atual->trie[posicao_letra] = nullptr;
  }
}

  for (int i = 0; i < 26; i++) {

      if (atual->trie[i] != nullptr) {

          return false;
      }
  }

  return !atual->isEnd;
}

bool Trie::Remover(string &palavra) {

  return Remover_palavra(raiz, palavra, 0);
}

bool Trie::Buscar_Palavra(string &palavra) {

  No_t *atual = raiz;

  for (int i = 0; i < palavra.size(); i++) {

      char caractere = palavra[i];
      int posicao = caractere - 'a';

      if (atual->trie[posicao] != nullptr) {

        atual = atual->trie[posicao];

      } else {

        return false;
      }
  }

  if (atual->isEnd == true) {

      return true;

    } else {

      return false;
  }
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

void Trie::Buscar_Prefixo(string &prefixo) {

  No_t *atual = raiz;

  for (int i = 0; i < prefixo.size(); i++) {

      char caractere = prefixo[i];
      int posicao = caractere - 'a';

        if (atual->trie[posicao] != nullptr) {

            atual = atual->trie[posicao];

        } else {

            return;
        }
    }
    
    string resto = prefixo;
    vector<string> palavra_prefixo;

    Achar_Pref(atual, resto, palavra_prefixo);
}
