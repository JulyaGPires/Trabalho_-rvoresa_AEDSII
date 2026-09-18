#include "Testes.hpp"
#include "Trie.hpp"
#include "Patricia.hpp"
#include "Splay.hpp"
#include "Treap.hpp"
#include "KD_Tree.hpp"
#include <chrono>

using namespace std;
using namespace chrono;


void TestarTrie(vector<string> &dados, string tipo, int n,ofstream &saida){

  Trie arvore;

  auto inicio = high_resolution_clock::now();

  for(string &valor : dados){
    arvore.Inserir(valor);
  }

  auto fim = high_resolution_clock::now();
  double insercao = duration<double, milli>(fim - inicio).count();
  inicio = high_resolution_clock::now();

  for(string &valor : dados){
    arvore.Buscar_Palavra(valor);
  }

  fim = high_resolution_clock::now();
  double busca = duration<double, milli>(fim - inicio).count();
  inicio = high_resolution_clock::now();

  for(string &valor : dados){
    arvore.Remover(valor);
  }

  fim = high_resolution_clock::now();

  double remocao = duration<double, milli>(fim - inicio).count();

  saida << "Trie," << tipo << "," << n << ","
        << insercao << "," << busca << "," << remocao
        << ",-,-" << endl;
}


void TestarPatricia(vector<string> &dados, string tipo, int n, ofstream &saida){

  Patricia arvore;

  auto inicio = high_resolution_clock::now();

  for(string &valor : dados){
    arvore.Inserir_P(valor);
  }

  auto fim = high_resolution_clock::now();
  double insercao = duration<double, milli>(fim - inicio).count();
  inicio = high_resolution_clock::now();

  for(string &valor : dados){
    arvore.Buscar_P(valor);
  }

  fim = high_resolution_clock::now();
  double busca = duration<double, milli>(fim - inicio).count();
  inicio = high_resolution_clock::now();

  for(string &valor : dados){
    arvore.Remover_P_principal(valor);
  }

  fim = high_resolution_clock::now();

  double remocao = duration<double, milli>(fim - inicio).count();

  saida << "Patricia," << tipo << "," << n << ","
        << insercao << "," << busca << "," << remocao
        << ",-,-" << endl;
}


void TestarSplay(vector<int> &dados, string tipo, int n, ofstream &saida){

  Splay arvore;

  auto inicio = high_resolution_clock::now();

  for(int valor : dados){
    arvore.Inserir_Sprincipal(valor);
  }

  auto fim = high_resolution_clock::now();
  double insercao = duration<double, milli>(fim - inicio).count();
  inicio = high_resolution_clock::now();

  for(int valor : dados){
    arvore.Buscar_Sprincipal(valor);
  }

  fim = high_resolution_clock::now();
  double busca = duration<double, milli>(fim - inicio).count();
  inicio = high_resolution_clock::now();

  for(int valor : dados){
    arvore.Remover_Principal(valor);
  }

  fim = high_resolution_clock::now();

  double remocao = duration<double, milli>(fim - inicio).count();

  saida << "Splay," << tipo << "," << n << ","
        << insercao << "," << busca << "," << remocao
        << ",-,-" << endl;
}


void TestarTreap(vector<int> &dados, string tipo, int n, ofstream &saida){

  Treap arvore;

  auto inicio = high_resolution_clock::now();

  for(int valor : dados){
    arvore.Inserir_T(valor);
  }

  auto fim = high_resolution_clock::now();
  double insercao = duration<double, milli>(fim - inicio).count();
  inicio = high_resolution_clock::now();

  for(int valor : dados){
    arvore.Buscar_Principal(valor);
  }

  fim = high_resolution_clock::now();
  double busca = duration<double, milli>(fim - inicio).count();
  inicio = high_resolution_clock::now();

  for(int valor : dados){
    arvore.Remover_Principal(valor);
  }

  fim = high_resolution_clock::now();

  double remocao = duration<double, milli>(fim - inicio).count();

  saida << "Treap," << tipo << "," << n << ","
        << insercao << "," << busca << "," << remocao
        << ",-,-" << endl;
}


void TestarKDTree(vector<vector<double>> &dados, string tipo, int n, ofstream &saida){

  KD_Tree arvore(3);

  auto inicio = high_resolution_clock::now();

  for(vector<double> &ponto : dados){
    arvore.Insert(ponto);
  }

  auto fim = high_resolution_clock::now();
  double insercao = duration<double, milli>(fim - inicio).count();

  inicio = high_resolution_clock::now();

  for(vector<double> &ponto : dados){
    arvore.Search(ponto);
  }

  fim = high_resolution_clock::now();
  double busca = duration<double, milli>(fim - inicio).count();

  inicio = high_resolution_clock::now();

  for(vector<double> &ponto : dados){
    arvore.NNS(ponto);
  }

  fim = high_resolution_clock::now();
  double nns = duration<double, milli>(fim - inicio).count();

  inicio = high_resolution_clock::now();

  for(int i = 0; i < 10; i++){

    vector<double> minimo = {0, 0, 0};
    vector<double> maximo = {50000, 50000, 50000};

    arvore.RangeSearch(minimo, maximo);
  }

  fim = high_resolution_clock::now();
  double range = duration<double, milli>(fim - inicio).count();

  inicio = high_resolution_clock::now();

  for(vector<double> &ponto : dados){
    arvore.Remove(ponto);
  }

  fim = high_resolution_clock::now();
  double remocao = duration<double, milli>(fim - inicio).count();

  saida << "KD-Tree," << tipo << "," << n << ","
        << insercao << "," << busca << "," << remocao
        << "," << nns << "," << range << endl;
}

