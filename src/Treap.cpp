#include "Treap.hpp"

using namespace std;

Treap::Treap(){

  raiz = nullptr; 

}

No_h* Treap::Inserir_BST(No_h *atual,int chave,int prioridade){

  if(atual == nullptr){

    No_h *novo= new No_h(chave, prioridade);
    atual = novo;
    return atual;

  }
  
  if(atual -> chave > chave){

    atual -> esquerda = Inserir_BST(atual -> esquerda, chave, prioridade);
    if(atual -> prioridade > atual-> esquerda -> prioridade){

      No_h *aux;
      No_h *novo = atual -> esquerda;

      aux = novo -> direita;
      novo -> direita = atual;
      atual -> esquerda = aux;

      return novo;
    }

   
  }else{
   
    atual -> direita = Inserir_BST(atual -> direita, chave, prioridade);
    if(atual -> prioridade > atual -> direita -> prioridade){

      No_h *aux;
      No_h *novo = atual -> direita;

      aux = novo ->  esquerda;
      novo -> esquerda = atual;
      atual -> direita = aux;

      return novo;
    }
  }
  return atual;
}

void Treap::Inserir_T(int chave, int prioridade){

  raiz = Inserir_BST(raiz, chave, prioridade);

}

bool Treap::Buscar_T(No_h *atual,int chave){


  if(atual == nullptr){
    return false;
  }
  if(atual -> chave == chave){
    return true;
  }
  if(atual -> chave > chave){

    return Buscar_T(atual -> esquerda, chave);

  }else{
    return Buscar_T(atual -> direita, chave);
  }
}

bool Treap::Buscar_Principal(int chave){
  bool Existe = Buscar_T(raiz,chave);
  return Existe;
}

No_h* Treap::Remover_T(No_h* atual, int chave){

  if(atual == nullptr){
    return nullptr;
  }
  if(atual-> chave > chave){

    atual -> esquerda = Remover_T(atual->esquerda, chave);

  }else if(atual-> chave < chave){

    atual -> direita = Remover_T(atual -> direita, chave);

  }else{
    
    if(atual -> esquerda == nullptr && atual -> direita == nullptr){
      delete atual;
      return nullptr;
    }else if(atual -> esquerda == nullptr){

      No_h *novo = atual -> direita;

      atual -> direita = novo -> esquerda;
      novo -> esquerda = atual;

      return Remover_T(novo, chave);

    }else if(atual -> direita == nullptr){

      No_h *novo = atual -> esquerda;

      atual -> esquerda = novo -> direita;
      novo -> direita = atual;

      return Remover_T(novo, chave);

    }else{
      if(atual -> esquerda -> prioridade < atual -> direita -> prioridade){
        No_h *novo = atual -> esquerda;

        
        atual -> esquerda = novo -> direita;
        novo -> direita = atual;

      return Remover_T(novo, chave);
      }else{
       
      No_h *novo = atual -> direita;

        
      atual -> direita= novo -> esquerda;
      novo -> esquerda = atual;

      return Remover_T(novo, chave);
      
    }
  }
}
  return atual;

}
void Treap::Remover_Principal(int chave){
  raiz = Remover_T(raiz,chave);
}