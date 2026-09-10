#include "Trie.hpp"


using namespace std;

Trie::Trie(){

 raiz = new No_t();


}


void Trie::Inserir(string &palavra){


  No_t *atual = raiz;

  for(int i = 0; i < palavra.size(); i++){

     
    char caractere = palavra[i];
    int posicao = caractere - 'a';


      if(atual -> trie[posicao] != nullptr){

        atual = atual -> trie[posicao];

      }else{

        atual->trie[posicao] = new No_t;
        atual = atual-> trie[posicao];
      }
    
    
    }


  atual->isEnd = true;
}
void Trie::Remover_palavra(string &palavra){

  if(posicao == palavra.size()){
    this -> isEnd = false;
  }else{
    int posicao_letra = palavra[posicao] - 'a';
  }


}

void Trie::Remover(string &palavra){
 


}

bool Trie::Buscar_Palavra(string &palavra){

  No_t *atual = raiz;

  for(int i = 0; i < palavra.size(); i++){

    char caractere = palavra[i];
    int posicao = caractere - 'a';

    if(atual -> trie[posicao] != nullptr){
      
      atual = atual -> trie[posicao];

    }else{
      return false;
    }
  }
  if(atual -> isEnd == true){
    return true;
  }else{
    return false;
  }

}

void Trie::Achar_Pref(No_t *atual,string &resto, vector<string> &palavra_prefixo){

    for(int i = 0; i < 26; i++){

      if(atual -> isEnd == true ){
        cout << resto << endl;// para conferir
        palavra_prefixo.push_back(resto);
      } 

      if(atual -> trie[i] != nullptr){

        char caractere = i + 'a';
        resto.push_back(caractere);
        Achar_Pref(atual -> trie[i], resto);
        resto.pop_back();

      }
      
    }

}

void Trie::Buscar_Prefixo(string &prefixo){

   No_t *atual = raiz;

  for(int i = 0; i < prefixo.size(); i++){

    char caractere = prefixo[i];
    int posicao = caractere - 'a';
    
    if(atual -> trie[posicao] != nullptr){
      
      atual = atual -> trie[posicao];

    }else{
      return;
    }
  string resto = prefixo;
  vector<string> palavra_prefixo;
  Achar_Pref(atual,resto,palavra_prefixo);
  }
}

