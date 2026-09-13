#include "Splay.hpp"
#include <iostream>

using namespace std;

Splay::Splay(){

  raiz = nullptr; 

}

void Splay::Liberar(No_s *atual){

  if (atual == nullptr) {
    return;
  } 
  Liberar(atual -> esquerda);
  Liberar(atual -> direita);
  delete atual;
}

Splay::~Splay(){

  Liberar(raiz);
}

No_s* Splay::Rotacao_Direita(No_s *atual){

  No_s *aux;
  No_s *novo;

  novo = atual -> esquerda;
  aux = novo -> direita;
  novo -> direita = atual;
  atual -> esquerda = aux;

  return novo;
}

No_s* Splay::Rotacao_Esquerda(No_s *atual){

  No_s *aux;
  No_s *novo;

  novo = atual -> direita;
  aux = novo -> esquerda;
  novo -> esquerda = atual;
  atual -> direita = aux;

  return novo;

}

No_s* Splay::Inserir_S(No_s *atual, int chave){

  if(atual == nullptr){

    No_s *novo = new No_s(chave);
    atual = novo;
    return atual;
  }
  if(atual -> chave == chave){
    return atual;
  }
  if(atual -> chave > chave){

    atual -> esquerda = Inserir_S(atual -> esquerda, chave);

    if(atual -> esquerda -> chave > chave){

      atual = Rotacao_Direita(atual);
      return Rotacao_Direita(atual);

    }if(atual -> esquerda -> chave < chave){

      atual -> esquerda = Rotacao_Esquerda(atual -> esquerda);
      return Rotacao_Direita(atual);
    }

  }else{ 
    atual -> direita = Inserir_S(atual -> direita, chave);

    if(atual -> direita -> chave < chave){

      atual = Rotacao_Esquerda(atual);
      return Rotacao_Esquerda(atual);

    }if(atual -> direita -> chave > chave){

      atual -> direita = Rotacao_Direita(atual -> direita);
      return Rotacao_Esquerda(atual);
    }
  }
  return atual;
}


void Splay::Inserir_Sprincipal(int chave){
    raiz = Inserir_S(raiz, chave);
}

No_s* Splay::Buscar_S(No_s *atual, int chave){

  if(atual == nullptr || atual->chave == chave){
    return atual;
  }

  if(chave < atual->chave){

    if(atual->esquerda == nullptr){
      return atual;
    }
    if(chave < atual->esquerda->chave){

      atual->esquerda->esquerda = Buscar_S(atual->esquerda->esquerda, chave);

      atual = Rotacao_Direita(atual);
    }
    
    else if(chave > atual->esquerda->chave){

      atual->esquerda->direita = Buscar_S(atual->esquerda->direita, chave);

      if(atual->esquerda->direita != nullptr){
        atual->esquerda =Rotacao_Esquerda(atual->esquerda);
      }
    }
    if(atual->esquerda == nullptr){
      return atual;
    }

    return Rotacao_Direita(atual);

  }else{

    if(atual->direita == nullptr){
      return atual;
    }
    if(chave > atual->direita->chave){

      atual->direita->direita = Buscar_S(atual->direita->direita, chave);

      atual = Rotacao_Esquerda(atual);
    }

    
    else if(chave < atual->direita->chave){

      atual->direita->esquerda = Buscar_S(atual->direita->esquerda, chave);

      if(atual->direita->esquerda != nullptr){
        atual->direita = Rotacao_Direita(atual->direita);
      }
    }
    if(atual->direita == nullptr){
      return atual;
    }
    return Rotacao_Esquerda(atual);
  }
}

void Splay::Buscar_Sprincipal(int chave){

  raiz = Buscar_S(raiz, chave);
}

No_s* Splay::Remover_S(No_s *atual, int chave){
    
  if(atual == nullptr){
    return nullptr;
  }
  atual = Buscar_S(atual,chave);

  if(atual -> chave != chave){
    return atual;
  }

  No_s *esquerda = atual -> esquerda;
  No_s *direita = atual -> direita;

  atual -> esquerda = nullptr;
  atual -> direita = nullptr;
  delete atual;

  if(esquerda == nullptr){
    return direita;
  }
  No_s *maior = esquerda;

  while(maior -> direita != nullptr){
    maior = maior -> direita;
  }

  esquerda = Buscar_S(esquerda, maior -> chave);
  esquerda -> direita = direita;
  return esquerda;
}

void Splay::Remover_Principal(int chave){
    raiz = Remover_S(raiz, chave);
}