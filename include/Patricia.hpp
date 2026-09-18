#ifndef PATRICIA_HPP
#define PATRICIA_HPP
#include <string>

using namespace std;

struct No_p{

  string prefixo;
  bool isEnd;
  No_p *Pat[26];


  No_p(string prefixo){
    this -> prefixo = prefixo;
    this -> isEnd = false;

    for (int i = 0; i < 26; i++) {

      Pat[i] = nullptr;
    }
  }
};

class Patricia{

  private:

  No_p *raiz;

  void Liberar(No_p *atual);

  public:

  Patricia();
  ~Patricia();

  void Inserir_P(string palavra);
  bool Buscar_P(string palavra);
  bool Remover_P(No_p *atual, string palavra, size_t posicao);
  bool Remover_P_principal(string palavra);


};

#endif