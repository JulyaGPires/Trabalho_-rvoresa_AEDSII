#ifndef SPLAY_HPP
#define SPLAY_HPP

using namespace std;

struct No_s{

  int chave;

  No_s *esquerda;
  No_s *direita;

  No_s(int chave){
 
    this -> chave = chave;

    esquerda = nullptr;
    direita = nullptr;
  }

};

class Splay{

  private:

  No_s *raiz;

  void Liberar(No_s *atual);

  public:

   Splay();
  ~Splay();

   No_s* Rotacao_Direita(No_s *atual);
   No_s* Rotacao_Esquerda(No_s *atual);
   No_s* Inserir_S(No_s *atual, int chave);
   void Inserir_Sprincipal(int chave);
   No_s* Buscar_S(No_s *atual, int chave);
   void Buscar_Sprincipal(int chave);
   No_s* Remover_S(No_s *atual, int chave);
   void  Remover_Principal(int chave);
  

};

#endif