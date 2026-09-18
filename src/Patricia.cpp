#include "Patricia.hpp"

using namespace std;

Patricia::Patricia(){

  raiz = new No_p("");
  raiz -> isEnd = false;
  return;
}

void Patricia::Liberar(No_p *atual){

  if (atual == nullptr) {
    return;
  } 
  for(int i = 0; i < 26; i++){
    Liberar(atual -> Pat[i]);
  }
  delete atual;
}

Patricia::~Patricia(){

  Liberar(raiz);
}

void Patricia::Inserir_P(string palavra){

  if(raiz == nullptr){

    raiz = new No_p(palavra);
    raiz -> isEnd = true;
    return;
  }

  No_p *atual = raiz;
  size_t posicao = 0;

  while(posicao < palavra.size()){

    int indice = palavra[posicao] - 'a';

    if(indice < 0 || indice >= 26){
      return;
    }
    if(atual -> Pat[indice] == nullptr){

      atual -> Pat[indice] = new No_p(palavra.substr(posicao));
      atual -> Pat[indice] -> isEnd = true;
      return;
    }
    No_p *Pat = atual -> Pat[indice];
    size_t i = 0;

    while((Pat -> prefixo.size() > i) && (palavra.size() > posicao + i) && (Pat -> prefixo[i] == palavra[posicao+i])){
  
      i++;
    }
    if(i == Pat -> prefixo.size()){
      posicao += i;
      atual = Pat;

    }else{
      string prefixo_comum = Pat -> prefixo.substr(0,i);
      string resto_filho = Pat -> prefixo.substr(i);
      string resto_palavra = palavra.substr(posicao+i);

      No_p *novo = new No_p(prefixo_comum);

      atual -> Pat[indice] = novo;
      Pat -> prefixo = resto_filho;
      int indice_Pat = Pat-> prefixo[0] - 'a';
      novo -> Pat[indice_Pat] = Pat;

      if(resto_palavra.empty()){

        novo -> isEnd = true;

      }else{

        int indice_palavra = resto_palavra[0] - 'a';

        novo -> Pat[indice_palavra] = new No_p(resto_palavra);
        novo -> Pat[indice_palavra] -> isEnd = true;

      }
      return;
    }
  }
  atual -> isEnd = true;
}

bool Patricia::Buscar_P(string palavra){

  if(raiz == nullptr){
    return false;
  }

  No_p *atual = raiz;
  size_t posicao = 0;

  while(palavra.size() > posicao){

    int indice = palavra[posicao] - 'a';

    if(indice < 0 || indice >= 26){
      return false;
    }

    if(atual -> Pat[indice] == nullptr){
      return false;
    }
    No_p *Pat = atual -> Pat[indice];
    size_t i = 0;
 
    while((Pat -> prefixo.size() > i) && (palavra.size() > posicao + i) && (Pat -> prefixo[i] == palavra[posicao+i])){
  
      i++;
    }
    if(Pat -> prefixo.size() > i){
      return false;
    }
    posicao += i;
    atual = Pat;
  }

  return atual -> isEnd;
}

bool Patricia::Remover_P(No_p *atual, string palavra, size_t posicao){

  if(posicao == palavra.size()){
    return false;
  }

  int indice = palavra[posicao] - 'a';

    if(indice < 0 || indice >= 26){
      return false;
    }

    if(atual -> Pat[indice] == nullptr){
      return false;
    }

    No_p *Pat = atual -> Pat[indice];
    size_t i = 0;
 
    while((Pat -> prefixo.size() > i) && (palavra.size() > posicao + i) && (Pat -> prefixo[i] == palavra[posicao+i])){
  
      i++;
    }
    if(Pat -> prefixo.size() > i){
      return false;
    }
    posicao += i;

    if(posicao == palavra.size()){

    if(Pat -> isEnd == false){
        return false;
    }
    Pat -> isEnd = false;

    bool temFilho = false;
    int quantidade = 0;
    int indice_filho = 0;

    for(int i = 0; i < 26; i++){

      if(Pat -> Pat[i] != nullptr){

        temFilho = true;
        quantidade++;
        indice_filho = i;
      }
    }
    if(!temFilho){

      delete Pat;
      atual -> Pat[indice] = nullptr;

    }else if(quantidade == 1 && Pat -> isEnd == false){
      
      No_p *filho = Pat -> Pat[indice_filho];

      Pat -> prefixo += filho -> prefixo;
      Pat -> isEnd = filho -> isEnd;

      for(int i = 0; i < 26; i++){
        Pat -> Pat[i] = filho -> Pat[i];
      
      }
      delete filho;
    }
    return true;

  } 

  bool removeu = Remover_P(Pat, palavra, posicao);

  if(removeu){

    int quantidade = 0;
    int indice_filho = 0;

    for(int i = 0; i < 26; i++){

      if(Pat -> Pat[i] != nullptr){
        quantidade++;
        indice_filho = i;
      }
    }

    if(Pat -> isEnd == false && quantidade == 0){

      delete Pat;
      atual -> Pat[indice] = nullptr;

    }else if(Pat -> isEnd == false && quantidade == 1){

      No_p *filho = Pat -> Pat[indice_filho];

      Pat -> prefixo += filho -> prefixo;
      Pat -> isEnd = filho -> isEnd;

      for(int i = 0; i < 26; i++){
        Pat -> Pat[i] = filho -> Pat[i];
      }

      delete filho;
    }
  }

  return removeu;
}

bool Patricia::Remover_P_principal(string palavra){

  if(raiz == nullptr){
    return false;
  }

  return Remover_P(raiz, palavra, 0);
}


