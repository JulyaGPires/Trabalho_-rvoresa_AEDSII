#ifndef KD_TREE_HPP
#define KD_TREE_HPP

#include <vector>

using namespace std;

struct No_k{

  vector<double> ponto;

  No_k *esquerda;
  No_k *direita;

  No_k(vector<double> ponto){

    this->ponto = ponto;

    esquerda = nullptr;
    direita = nullptr;
  }
};

class KD_Tree{

private:

  No_k *raiz;
  int k;

  No_k* Inserir(No_k *atual, vector<double> &ponto, int nivel);

public:

  KD_Tree(int k);
  ~KD_Tree();

  void Insert(vector<double> &ponto);
  bool Search(vector<double> &ponto);
  vector<double> NNS(vector<double> &ponto);
  vector<vector<double>> RangeSearch(vector<double> &minimo, vector<double> &maximo);
  void Remove(vector<double> &ponto);

  void Liberar(No_k *atual);
  bool Buscar(No_k *atual, vector<double> &ponto, int nivel);
  double Distancia(No_k *ponto1, vector<double> &ponto2);

  void Buscar_NN(No_k *atual, vector<double> &ponto, int nivel, No_k *&melhor, double &menor_distancia);
  void Buscar_Regiao(No_k *atual, vector<double> &minimo,  vector<double> &maximo, int nivel, vector<vector<double>> &resultado);

  No_k* Encontrar_Minimo(No_k *atual, int dimensao, int nivel);
  No_k* Remover(No_k *atual, vector<double> &ponto, int nivel);
};

#endif