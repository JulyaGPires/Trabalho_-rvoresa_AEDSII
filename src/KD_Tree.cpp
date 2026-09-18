#include "KD_Tree.hpp"

using namespace std;

KD_Tree::KD_Tree(int k){

  raiz = nullptr;
  this->k = k;
}

void KD_Tree::Liberar(No_k *atual){

  if(atual == nullptr) {
     return;
  }

  Liberar(atual->esquerda);
  Liberar(atual->direita);
  delete atual;
}

KD_Tree::~KD_Tree() {

  Liberar(raiz);
}

No_k* KD_Tree::Inserir(No_k *atual, vector<double> &ponto, int nivel){

  if(atual == nullptr) {
    return new No_k(ponto);
  }

  int dimensao = nivel % k;

  if(atual -> ponto[dimensao] > ponto[dimensao]) {

    atual -> esquerda = Inserir(atual -> esquerda, ponto, nivel + 1);

  } else {

    atual -> direita = Inserir(atual -> direita, ponto, nivel + 1);
  }

  return atual;
}

void KD_Tree::Insert(vector<double> &ponto){

  raiz = Inserir(raiz, ponto, 0);
}

bool KD_Tree::Buscar(No_k *atual, vector<double> &ponto, int nivel){

  if(atual == nullptr) {
    return false;
  }

  if(atual->ponto == ponto) {
      return true;
  }

  int dimensao = nivel % k;

  if(atual->ponto[dimensao] > ponto[dimensao]) {

    return Buscar(atual -> esquerda, ponto, nivel + 1);

  } else {

    return Buscar(atual -> direita, ponto, nivel + 1);
  }
}

bool KD_Tree::Search(vector<double> &ponto){

  if((int)ponto.size() != k) {
    return false;
  }

  return Buscar(raiz, ponto, 0);
}

double KD_Tree::Distancia(No_k *ponto1, vector<double> &ponto2) {

  double distancia = 0;

  for(int i = 0; i < k; i++) {

    double diferenca = ponto1 -> ponto[i] - ponto2[i];
    distancia += diferenca * diferenca;
  }

  return distancia;
}

void KD_Tree::Buscar_NN(No_k *atual, vector<double> &ponto, int nivel, No_k *&melhor, double &menor_distancia){

  if(atual == nullptr) {
    return;
  }

  double distancia = Distancia(atual, ponto);

  if(melhor == nullptr || distancia < menor_distancia) {

    melhor = atual;
    menor_distancia = distancia;
  }

  int dimensao = nivel % k;

  No_k *primeiro;
  No_k *segundo;

  if(ponto[dimensao] < atual -> ponto[dimensao]) {

    primeiro = atual -> esquerda;
    segundo = atual -> direita;

  } else {

    primeiro = atual -> direita;
    segundo = atual -> esquerda;
  }

  Buscar_NN(primeiro, ponto, nivel + 1, melhor, menor_distancia);
  double diferenca = ponto[dimensao] - atual -> ponto[dimensao];

  if((diferenca * diferenca) < menor_distancia) {

    Buscar_NN(segundo, ponto, nivel + 1, melhor, menor_distancia);
  }
}

vector<double> KD_Tree::NNS(vector<double> &ponto){

  if(raiz == nullptr) {
    return {};
  }

  No_k *melhor = nullptr;
  double menor_distancia = 0;

  Buscar_NN(raiz, ponto, 0, melhor, menor_distancia);
  return melhor -> ponto;

}

void KD_Tree::Buscar_Regiao(No_k *atual, vector<double> &minimo, vector<double> &maximo, int nivel, vector<vector<double>> &resultado){

  if(atual == nullptr) {
    return;
  }

  bool dentro = true;

  for(int i = 0; i < k; i++) {

    if(atual -> ponto[i] < minimo[i] || atual -> ponto[i] > maximo[i]) {

      dentro = false;
      break;
    }
  }

  if(dentro) {
    resultado.push_back(atual -> ponto);
  }

  int dimensao = nivel % k;

  if(minimo[dimensao] <= atual -> ponto[dimensao]) {

    Buscar_Regiao(atual -> esquerda, minimo, maximo, nivel + 1, resultado);
  }

  if(maximo[dimensao] >= atual -> ponto[dimensao]) {

  Buscar_Regiao(atual->direita, minimo, maximo, nivel + 1, resultado);
  }
}

vector<vector<double>> KD_Tree::RangeSearch(vector<double> &minimo, vector<double> &maximo){

  if((int)minimo.size() != k || (int)maximo.size() != k) {
    return {};
  }  
  vector<vector<double>> resultado;
  Buscar_Regiao(raiz, minimo, maximo, 0, resultado);

  return resultado;
}

No_k* KD_Tree::Encontrar_Minimo(No_k *atual, int dimensao, int nivel){

  if(atual == nullptr) {
    return nullptr;
  }

  int dimensao_atual = nivel % k;

  if(dimensao_atual == dimensao) {

    if(atual->esquerda == nullptr) {
      return atual;
    }

    return Encontrar_Minimo(atual->esquerda, dimensao, nivel + 1);
    }

    No_k *esquerda = Encontrar_Minimo(atual->esquerda, dimensao, nivel + 1);
    No_k *direita = Encontrar_Minimo(atual->direita, dimensao, nivel + 1);

    No_k *menor = atual;

  if(esquerda != nullptr && esquerda -> ponto[dimensao] < menor -> ponto[dimensao]) {

    menor = esquerda;
  }

  if(direita != nullptr && direita->ponto[dimensao] < menor -> ponto[dimensao]) {

    menor = direita;
  }

  return menor;
}

No_k* KD_Tree::Remover(No_k *atual, vector<double> &ponto, int nivel){

  if(atual == nullptr) {
    return nullptr;
  }

  int dimensao = nivel % k;

  if(atual->ponto == ponto) {

    if(atual->direita != nullptr) {

      No_k *menor = Encontrar_Minimo(atual->direita, dimensao, nivel + 1);

      atual->ponto = menor->ponto;
      atual->direita = Remover(atual->direita, menor->ponto, nivel + 1);

    } else if(atual->esquerda != nullptr) {

        No_k *menor = Encontrar_Minimo(atual->esquerda, dimensao, nivel + 1);
        atual->ponto = menor->ponto;
        No_k *subarvore = atual->esquerda;
        atual->esquerda = nullptr;
        atual->direita = Remover(subarvore, menor->ponto, nivel + 1);

    } else {

      delete atual;
      return nullptr;
    }

  return atual;
}

  if(ponto[dimensao] < atual->ponto[dimensao]) {

    atual->esquerda = Remover(atual->esquerda, ponto, nivel + 1);

  } else {

    atual->direita = Remover(atual->direita,ponto, nivel + 1);
  }

  return atual;
}

void KD_Tree::Remove(vector<double> &ponto){

  raiz = Remover(raiz, ponto, 0);
}