#ifndef TREAP_HPP
#define TREAP_HPP
#include <iostream>

using namespace std;

struct No_h{

  int chave;
  int prioridade;

  No_h *esquerda;
  No_h *direita;

  No_h(int chave, int prioridade) {

  this-> chave = chave;
  this-> prioridade =prioridade;  

  esquerda = nullptr;
  direita = nullptr;

  }

};

class Treap{

  private:

  No_h *raiz;

  void Liberar(No_h *atual);

  public:
 
  Treap();
  ~Treap();

  No_h* Inserir_BST(No_h *atual,int chave,int prioridade);
  void Inserir_T(int chave);
  bool Buscar_T(No_h *atual,int chave);
  bool Buscar_Principal(int chave);
  No_h* Remover_T(No_h* atual, int chave);
  void Remover_Principal(int chave);

};

#endif