#ifndef TREAP_HPP
#define TREAP_HPP

using namespace std;

struct No_h{

  int chave;
  int prioridade;

  No_h *esquerda;
  No_h *direita;

  No_t(int chave, int prioridade) {

  this-> chave = chave;
  this-> prioridade =prioridade;  

  esquerda = nullptr;
  direita = nullptr;

  }

};

class Treap{

  private:

  No_h *raiz;

  public:
 
  Treap();
  ~Treap();

  No_h* Inserir_BST(No_h *atual,int chave,int prioridade);
  void Inserir_T(int chave, int prioridade);
  bool Buscar_T(No_h *atual,int chave);
  bool Buscar_Principal(int chave);
  No_h* Remover_T(No_h* atual, int chave);
  void Remover_Principal(int chave);
  

}

#endif